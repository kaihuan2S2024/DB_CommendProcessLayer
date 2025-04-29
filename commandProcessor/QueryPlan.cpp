//
// Created by Kai Huang on 4/29/25.
//

#include "QueryPlan.h"
#include <algorithm> // For std::transform

QueryPlan analyzeQuery(const std::string& statement) {
    QueryPlan plan;

    // Convert statement to uppercase for case-insensitive comparisons
    std::string upperStmt = statement;
    std::transform(upperStmt.begin(), upperStmt.end(), upperStmt.begin(), ::toupper);

    // Check if query is a SELECT
    bool isSelect = upperStmt.find("SELECT") != std::string::npos;

    // Basic condition check for WHERE clause with equality
    bool hasEquality = statement.find(" = ") != std::string::npos;

    // Check for range queries
    bool hasRangeQuery = statement.find(" > ") != std::string::npos ||
                          statement.find(" < ") != std::string::npos ||
                          upperStmt.find("BETWEEN") != std::string::npos;

    // Look for table name (simplified approach)
    size_t fromPos = upperStmt.find(" FROM ");
    std::string tableName = "";
    if (fromPos != std::string::npos) {
        size_t tableNameStart = fromPos + 6; // length of " FROM "
        size_t tableNameEnd = upperStmt.find(" ", tableNameStart);
        if (tableNameEnd == std::string::npos) {
            tableNameEnd = upperStmt.find(";", tableNameStart);
            if (tableNameEnd == std::string::npos) {
                tableNameEnd = upperStmt.length();
            }
        }
        tableName = statement.substr(tableNameStart, tableNameEnd - tableNameStart);
    }

    // Logic to identify column names in WHERE clause
    std::string columnName = "";
    size_t wherePos = upperStmt.find(" WHERE ");

    if (wherePos != std::string::npos) {
        size_t conditionStart = wherePos + 7; // length of " WHERE "
        size_t equalPos = statement.find(" = ", conditionStart);
        size_t gtPos = statement.find(" > ", conditionStart);
        size_t ltPos = statement.find(" < ", conditionStart);
        size_t betweenPos = upperStmt.find(" BETWEEN ", conditionStart);

        size_t opPos = std::string::npos;
        int opLength = 0;

        if (equalPos != std::string::npos) {
            opPos = equalPos;
            opLength = 3; // " = "
        } else if (gtPos != std::string::npos) {
            opPos = gtPos;
            opLength = 3; // " > "
        } else if (ltPos != std::string::npos) {
            opPos = ltPos;
            opLength = 3; // " < "
        } else if (betweenPos != std::string::npos) {
            opPos = betweenPos;
            opLength = 9; // " BETWEEN "
        }

        if (opPos != std::string::npos) {
            columnName = statement.substr(conditionStart, opPos - conditionStart);
            // Trim spaces
            columnName.erase(0, columnName.find_first_not_of(" \t"));
            columnName.erase(columnName.find_last_not_of(" \t") + 1);
        }
    }

    // Access the metadata manager to check if the column is indexed
    // This is a simplified approach - in a real implementation you would check
    // the database metadata to see if the column has an index
    bool isIndexed = false;
    std::string indexName = "";

    // For demonstration purposes, we'll assume primary keys and columns with "id" or "ID" are indexed
    if (!columnName.empty() &&
        (columnName == "ID" || columnName == "id" ||
         columnName.find("_id") != std::string::npos ||
         columnName.find("_ID") != std::string::npos)) {
        isIndexed = true;
        indexName = tableName + "_" + columnName + "_index (B+ Tree)";
    }

    // Now set the query plan based on our analysis
    if (isSelect) {
        if (!tableName.empty()) {
            if (hasEquality && isIndexed) {
                // Point query with index
                plan.operation = "Index Lookup";
                plan.indexUsed = indexName;
                plan.estimatedCost = 5; // Estimated milliseconds
                plan.rowsScanned = 1;
            } else if (hasRangeQuery && isIndexed) {
                // Range query with index
                plan.operation = "Index Range Scan";
                plan.indexUsed = indexName;
                plan.estimatedCost = 30; // Estimated milliseconds
                plan.rowsScanned = 100; // Estimated matching rows
            } else {
                // Full table scan
                plan.operation = "Full Table Scan";
                plan.indexUsed = "";
                plan.estimatedCost = 150; // Estimated milliseconds
                plan.rowsScanned = 10000; // Assuming 10,000 rows in the table
            }
        }
    }

    return plan;
}
