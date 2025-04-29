#pragma once
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#include "SQLStatement/DMLStatement/include/SelectStatement.h"

struct ColumnMetadata;

class Optimizer {
 public:
  static std::unordered_map<std::string, std::string> aliasesTable;
  static std::unordered_map<std::string, std::string> oppositeOperators;

  static SelectStatement *optimizer(SelectStatement *statement) {
    auto temp = aliasesTable;

    std::string tableName = statement->GetTableSource()->GetValue();

    statement = idempotentLawOptimizer(statement);
    statement = absorptionLawOptimizer(statement);
    statement = inverseLawOptimizer(statement);
    statement = eliminateRedundantJoinConditions(statement);

    return statement;
  }

  /**
   * Applies the Inverse Law from Boolean Algebra to optimize the given select
   * statement.
   *
   * The Inverse Law states that for any Boolean variable A:
   * <pre>
   * --------------------------------
   * | Boolean Expression | Result  |
   * |--------------------|---------|
   * | A OR NOT A         | TRUE    |
   * | A AND NOT A        | FALSE   |
   * --------------------------------
   * </pre>
   * This function identifies patterns in the select statement where the inverse
   * law can be applied and optimizes the expression accordingly.
   *
   * @param statement The select statement to be optimized. It contains
   *                  Boolean conditions that may be simplified using the
   * inverse law.
   * @return An optimized select statement with redundant expressions
   *         eliminated. Returns `nullptr` if the statement is `nullptr` or
   * cannot be optimized.
   */
  static SelectStatement *inverseLawOptimizer(SelectStatement *statement);

  /**
   * Applies the Absorption Law from Boolean Algebra to optimize the given
   * select statement.
   *
   * The Absorption Law states that for any Boolean variables A and B:
   * <pre>
   * ------------------------------------
   * | Boolean Expression   | Result    |
   * |----------------------|-----------|
   * | A OR (A AND B)       | A         |
   * | A AND (A OR B)       | A         |
   * ------------------------------------
   * </pre>
   * This function identifies patterns in the select statement where the
   * absorption law can be applied and optimizes the expression accordingly.
   *
   * @param statement The select statement to be optimized. It contains Boolean
   * conditions that may be simplified using the absorption law.
   * @return An optimized select statement with redundant expressions
   * eliminated.
   */
  static SelectStatement *absorptionLawOptimizer(SelectStatement *statement);

  /**
   * Applies the Idempotent Law from Boolean Algebra to optimize the given
   * select statement.
   *
   * The Idempotent Law states that for any Boolean variable A:
   * <pre>
   * --------------------------------
   * | Boolean Expression | Result  |
   * |--------------------|---------|
   * | A OR A             | A       |
   * | A AND A            | A       |
   * --------------------------------
   * </pre>
   * This function identifies patterns in the select statement where the
   * idempotent law can be applied and optimizes the expression accordingly.
   *
   * @param statement The select statement to be optimized. It contains Boolean
   * conditions that may be simplified using the idempotent law.
   * @return An optimized select statement with redundant expressions
   * eliminated.
   */
  static SelectStatement *idempotentLawOptimizer(SelectStatement *statement);

  /**
   * Applies the Distributive Law from Boolean algebra to optimize the given
   * select statement.
   *
   * The Distributive Law states that for any Boolean variables A, B, and C:
   * <pre>
   * -------------------------------------------------------
   * | Boolean Expression         | Equivalent Form        |
   * |----------------------------|------------------------|
   * | A AND (B OR C)             | (A AND B) OR (A AND C) |
   * | A OR (B AND C)             | (A OR B) AND (A OR C)  |
   * -------------------------------------------------------
   * </pre>
   * This law allows logical operations to be distributed over others,
   * potentially simplifying complex Boolean conditions in a select statement.
   *
   * This function identifies patterns in the select statement where the
   * distributive law can be applied and optimizes the expression accordingly.
   *
   * @param statement The select statement to be optimized. It contains
   *                  Boolean conditions that may be simplified using the
   * distributive law.
   * @return An optimized select statement with redundant expressions
   *         eliminated.
   */
  static SelectStatement *distributiveOptimizer(SelectStatement *statement);

  /**
   * Applies De Morgan's laws from Boolean Algebra to optimize the given select
   * statement.
   *
   * De Morgan's laws state that for any Boolean variables A and B:
   * <pre>
   * -------------------------------------------
   * | Boolean Expression    | Equivalent      |
   * |-----------------------|-----------------|
   * | NOT (A AND B)         | NOT A OR NOT B  |
   * | NOT (A OR B)          | NOT A AND NOT B |
   * -------------------------------------------
   * </pre>
   *
   * These laws allow negations to be distributed over logical operators,
   * potentially simplifying complex Boolean conditions in a select statement.
   *
   * This function identifies patterns in the select statement where De Morgan's
   * laws can be applied and optimizes the expression accordingly.
   *
   * @param statement The select statement to be optimized. It contains
   *                  Boolean conditions that may be simplified using De
   * Morgan's laws.
   * @return An optimized select statement with redundant expressions
   *         eliminated.
   */
  static SelectStatement *deMorganLawOptimizer(SelectStatement *statement);

  /**
   * Optimizes SQL queries by removing redundant conditions in the JOIN or WHERE
   * clauses.
   *
   * This function analyzes the given `SelectStatement` and detects redundant
   * conditions that appear both in the JOIN clauses and the WHERE clause. If a
   * condition does not impact the query result, it is eliminated to simplify
   * the query and improve execution efficiency.
   *
   * Before Optimization:
   * - SELECT r.rating FROM REVIEWED AS r
   * - JOIN movie AS m ON r.person_id = m.person_id
   * - WHERE m.person_id = r.person_id AND m.released = 2019;
   *
   *
   * After Optimization:
   * - SELECT r.rating FROM REVIEWED AS r
   * - JOIN movie AS m ON r.person_id = m.person_id
   * - WHERE m.released = 2019;
   *
   * @param statement The select statement containing potential redundant
   * conditions in the JOIN and WHERE clauses.
   * @return An optimized select statement with redundant conditions removed.
   *
   * @note The function ensures that removing a condition does not alter the
   * semantics of the query.
   *
   */
  static SelectStatement *eliminateRedundantJoinConditions(
      SelectStatement *statement);

  /**
   * @brief Optimizes a given SQL Select statement by applying De Morgan's laws
   * based on selection selectivity.
   *
   * This function analyzes the given `SelectStatement` and determines whether
   * applying De Morgan's laws will yield a more efficient query execution plan.
   * The optimization is guided by the selectivity of the selection predicates,
   * leveraging the provided column metadata.
   *
   * De Morgan's laws in relational algebra allow transformations such as:
   * - Pushing negations inside disjunctions and conjunctions to simplify
   * conditions.
   * - Transforming `NOT (A AND B)` into `NOT A OR NOT B` or `NOT (A OR B)` into
   * `NOT A AND NOT B`.
   *
   * @param statement A pointer to the `SelectStatement` representing the SQL
   * query to optimize.
   * @param columnMetadata A vector containing metadata about the columns
   * involved in the statement, including information such as data type and
   * indexing.
   *
   * @return A pointer to an optimized `SelectStatement` if an optimization is
   * applied; otherwise, returns the original statement.
   *
   * @note The function assumes that students will calculate the selectivity of
   * the selection predicates using the column metadata before optimization is
   * performed. Selectivity values should be used to decide whether De Morgan's
   * transformation leads to a more efficient execution plan.
   */
  static SelectStatement *costBasedDeMorgansLawOptimizer(
      SelectStatement *statement,
      const std::vector<ColumnMetadata> &columnMetadata);

  /**
   * @brief Retrieves the opposite operator for a given comparison operator.
   *
   * This function looks up the provided operator in a predefined mapping of
   * opposite comparison operators and returns the corresponding opposite.
   *
   * @param op The comparison operator as a string (e.g., "=", "!=", "<", ">").
   * @return The opposite operator as a string (e.g., "=" → "!=", "<" → ">=").
   *
   * @throws std::invalid_argument if the operator is not found in the mapping.
   *
   * @note This function assumes `op` is a valid comparison operator. If `op`
   *       is not found, an exception is thrown.
   *
   * Example
   *
   * std::string opposite = Optimizer::getOppositeOperators("<");
   *
   * std::cout << opposite;  // Output: ">="
   */
  static std::string getOppositeOperators(std::string &op);
};
