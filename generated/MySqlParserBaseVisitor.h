
// Generated from MySqlParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "MySqlParserVisitor.h"


namespace antlrcpptest {

/**
 * This class provides an empty implementation of MySqlParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  MySqlParserBaseVisitor : public MySqlParserVisitor {
public:

  virtual std::any visitRoot(MySqlParser::RootContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSqlStatements(MySqlParser::SqlStatementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSqlStatement(MySqlParser::SqlStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEmptyStatement_(MySqlParser::EmptyStatement_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDdlStatement(MySqlParser::DdlStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDmlStatement(MySqlParser::DmlStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTransactionStatement(MySqlParser::TransactionStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReplicationStatement(MySqlParser::ReplicationStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPreparedStatement(MySqlParser::PreparedStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompoundStatement(MySqlParser::CompoundStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAdministrationStatement(MySqlParser::AdministrationStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUtilityStatement(MySqlParser::UtilityStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCreateDatabase(MySqlParser::CreateDatabaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCreateEvent(MySqlParser::CreateEventContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCreateIndex(MySqlParser::CreateIndexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCreateLogfileGroup(MySqlParser::CreateLogfileGroupContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCreateProcedure(MySqlParser::CreateProcedureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCreateFunction(MySqlParser::CreateFunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCreateRole(MySqlParser::CreateRoleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCreateServer(MySqlParser::CreateServerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCopyCreateTable(MySqlParser::CopyCreateTableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQueryCreateTable(MySqlParser::QueryCreateTableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitColumnCreateTable(MySqlParser::ColumnCreateTableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCreateTablespaceInnodb(MySqlParser::CreateTablespaceInnodbContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCreateTablespaceNdb(MySqlParser::CreateTablespaceNdbContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCreateTrigger(MySqlParser::CreateTriggerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWithClause(MySqlParser::WithClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCommonTableExpressions(MySqlParser::CommonTableExpressionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCteName(MySqlParser::CteNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCteColumnName(MySqlParser::CteColumnNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCreateView(MySqlParser::CreateViewContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCreateDatabaseOption(MySqlParser::CreateDatabaseOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCharSet(MySqlParser::CharSetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOwnerStatement(MySqlParser::OwnerStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPreciseSchedule(MySqlParser::PreciseScheduleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntervalSchedule(MySqlParser::IntervalScheduleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTimestampValue(MySqlParser::TimestampValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntervalExpr(MySqlParser::IntervalExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntervalType(MySqlParser::IntervalTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEnableType(MySqlParser::EnableTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIndexType(MySqlParser::IndexTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIndexOption(MySqlParser::IndexOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProcedureParameter(MySqlParser::ProcedureParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionParameter(MySqlParser::FunctionParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRoutineComment(MySqlParser::RoutineCommentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRoutineLanguage(MySqlParser::RoutineLanguageContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRoutineBehavior(MySqlParser::RoutineBehaviorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRoutineData(MySqlParser::RoutineDataContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRoutineSecurity(MySqlParser::RoutineSecurityContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitServerOption(MySqlParser::ServerOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCreateDefinitions(MySqlParser::CreateDefinitionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitColumnDeclaration(MySqlParser::ColumnDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstraintDeclaration(MySqlParser::ConstraintDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIndexDeclaration(MySqlParser::IndexDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitColumnDefinition(MySqlParser::ColumnDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNullColumnConstraint(MySqlParser::NullColumnConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDefaultColumnConstraint(MySqlParser::DefaultColumnConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVisibilityColumnConstraint(MySqlParser::VisibilityColumnConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInvisibilityColumnConstraint(MySqlParser::InvisibilityColumnConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAutoIncrementColumnConstraint(MySqlParser::AutoIncrementColumnConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimaryKeyColumnConstraint(MySqlParser::PrimaryKeyColumnConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUniqueKeyColumnConstraint(MySqlParser::UniqueKeyColumnConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCommentColumnConstraint(MySqlParser::CommentColumnConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFormatColumnConstraint(MySqlParser::FormatColumnConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStorageColumnConstraint(MySqlParser::StorageColumnConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReferenceColumnConstraint(MySqlParser::ReferenceColumnConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCollateColumnConstraint(MySqlParser::CollateColumnConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGeneratedColumnConstraint(MySqlParser::GeneratedColumnConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSerialDefaultColumnConstraint(MySqlParser::SerialDefaultColumnConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCheckColumnConstraint(MySqlParser::CheckColumnConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimaryKeyTableConstraint(MySqlParser::PrimaryKeyTableConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUniqueKeyTableConstraint(MySqlParser::UniqueKeyTableConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForeignKeyTableConstraint(MySqlParser::ForeignKeyTableConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCheckTableConstraint(MySqlParser::CheckTableConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReferenceDefinition(MySqlParser::ReferenceDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReferenceAction(MySqlParser::ReferenceActionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReferenceControlType(MySqlParser::ReferenceControlTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleIndexDeclaration(MySqlParser::SimpleIndexDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSpecialIndexDeclaration(MySqlParser::SpecialIndexDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableOptionEngine(MySqlParser::TableOptionEngineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableOptionEngineAttribute(MySqlParser::TableOptionEngineAttributeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableOptionAutoextendSize(MySqlParser::TableOptionAutoextendSizeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableOptionAutoIncrement(MySqlParser::TableOptionAutoIncrementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableOptionAverage(MySqlParser::TableOptionAverageContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableOptionCharset(MySqlParser::TableOptionCharsetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableOptionChecksum(MySqlParser::TableOptionChecksumContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableOptionCollate(MySqlParser::TableOptionCollateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableOptionComment(MySqlParser::TableOptionCommentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableOptionCompression(MySqlParser::TableOptionCompressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableOptionConnection(MySqlParser::TableOptionConnectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableOptionDataDirectory(MySqlParser::TableOptionDataDirectoryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableOptionDelay(MySqlParser::TableOptionDelayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableOptionEncryption(MySqlParser::TableOptionEncryptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableOptionPageCompressed(MySqlParser::TableOptionPageCompressedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableOptionPageCompressionLevel(MySqlParser::TableOptionPageCompressionLevelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableOptionEncryptionKeyId(MySqlParser::TableOptionEncryptionKeyIdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableOptionIndexDirectory(MySqlParser::TableOptionIndexDirectoryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableOptionInsertMethod(MySqlParser::TableOptionInsertMethodContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableOptionKeyBlockSize(MySqlParser::TableOptionKeyBlockSizeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableOptionMaxRows(MySqlParser::TableOptionMaxRowsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableOptionMinRows(MySqlParser::TableOptionMinRowsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableOptionPackKeys(MySqlParser::TableOptionPackKeysContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableOptionPassword(MySqlParser::TableOptionPasswordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableOptionRowFormat(MySqlParser::TableOptionRowFormatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableOptionStartTransaction(MySqlParser::TableOptionStartTransactionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableOptionSecondaryEngineAttribute(MySqlParser::TableOptionSecondaryEngineAttributeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableOptionRecalculation(MySqlParser::TableOptionRecalculationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableOptionPersistent(MySqlParser::TableOptionPersistentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableOptionSamplePage(MySqlParser::TableOptionSamplePageContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableOptionTablespace(MySqlParser::TableOptionTablespaceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableOptionTableType(MySqlParser::TableOptionTableTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableOptionTransactional(MySqlParser::TableOptionTransactionalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableOptionUnion(MySqlParser::TableOptionUnionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableType(MySqlParser::TableTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTablespaceStorage(MySqlParser::TablespaceStorageContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPartitionDefinitions(MySqlParser::PartitionDefinitionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPartitionFunctionHash(MySqlParser::PartitionFunctionHashContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPartitionFunctionKey(MySqlParser::PartitionFunctionKeyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPartitionFunctionRange(MySqlParser::PartitionFunctionRangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPartitionFunctionList(MySqlParser::PartitionFunctionListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubPartitionFunctionHash(MySqlParser::SubPartitionFunctionHashContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubPartitionFunctionKey(MySqlParser::SubPartitionFunctionKeyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPartitionComparison(MySqlParser::PartitionComparisonContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPartitionListAtom(MySqlParser::PartitionListAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPartitionListVector(MySqlParser::PartitionListVectorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPartitionSimple(MySqlParser::PartitionSimpleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPartitionDefinerAtom(MySqlParser::PartitionDefinerAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPartitionDefinerVector(MySqlParser::PartitionDefinerVectorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubpartitionDefinition(MySqlParser::SubpartitionDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPartitionOptionEngine(MySqlParser::PartitionOptionEngineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPartitionOptionComment(MySqlParser::PartitionOptionCommentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPartitionOptionDataDirectory(MySqlParser::PartitionOptionDataDirectoryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPartitionOptionIndexDirectory(MySqlParser::PartitionOptionIndexDirectoryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPartitionOptionMaxRows(MySqlParser::PartitionOptionMaxRowsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPartitionOptionMinRows(MySqlParser::PartitionOptionMinRowsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPartitionOptionTablespace(MySqlParser::PartitionOptionTablespaceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPartitionOptionNodeGroup(MySqlParser::PartitionOptionNodeGroupContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterSimpleDatabase(MySqlParser::AlterSimpleDatabaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterUpgradeName(MySqlParser::AlterUpgradeNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterEvent(MySqlParser::AlterEventContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterFunction(MySqlParser::AlterFunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterInstance(MySqlParser::AlterInstanceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterLogfileGroup(MySqlParser::AlterLogfileGroupContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterProcedure(MySqlParser::AlterProcedureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterServer(MySqlParser::AlterServerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterTable(MySqlParser::AlterTableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterTablespace(MySqlParser::AlterTablespaceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterView(MySqlParser::AlterViewContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByTableOption(MySqlParser::AlterByTableOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByAddColumn(MySqlParser::AlterByAddColumnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByAddColumns(MySqlParser::AlterByAddColumnsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByAddIndex(MySqlParser::AlterByAddIndexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByAddPrimaryKey(MySqlParser::AlterByAddPrimaryKeyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByAddUniqueKey(MySqlParser::AlterByAddUniqueKeyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByAddSpecialIndex(MySqlParser::AlterByAddSpecialIndexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByAddForeignKey(MySqlParser::AlterByAddForeignKeyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByAddCheckTableConstraint(MySqlParser::AlterByAddCheckTableConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByAlterCheckTableConstraint(MySqlParser::AlterByAlterCheckTableConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterBySetAlgorithm(MySqlParser::AlterBySetAlgorithmContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByChangeDefault(MySqlParser::AlterByChangeDefaultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByChangeColumn(MySqlParser::AlterByChangeColumnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByRenameColumn(MySqlParser::AlterByRenameColumnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByLock(MySqlParser::AlterByLockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByModifyColumn(MySqlParser::AlterByModifyColumnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByDropColumn(MySqlParser::AlterByDropColumnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByDropConstraintCheck(MySqlParser::AlterByDropConstraintCheckContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByDropPrimaryKey(MySqlParser::AlterByDropPrimaryKeyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByDropIndex(MySqlParser::AlterByDropIndexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByRenameIndex(MySqlParser::AlterByRenameIndexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByAlterColumnDefault(MySqlParser::AlterByAlterColumnDefaultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByAlterIndexVisibility(MySqlParser::AlterByAlterIndexVisibilityContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByDropForeignKey(MySqlParser::AlterByDropForeignKeyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByDisableKeys(MySqlParser::AlterByDisableKeysContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByEnableKeys(MySqlParser::AlterByEnableKeysContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByRename(MySqlParser::AlterByRenameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByOrder(MySqlParser::AlterByOrderContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByConvertCharset(MySqlParser::AlterByConvertCharsetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByDefaultCharset(MySqlParser::AlterByDefaultCharsetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByDiscardTablespace(MySqlParser::AlterByDiscardTablespaceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByImportTablespace(MySqlParser::AlterByImportTablespaceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByForce(MySqlParser::AlterByForceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByValidate(MySqlParser::AlterByValidateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByAddDefinitions(MySqlParser::AlterByAddDefinitionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterPartition(MySqlParser::AlterPartitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByAddPartition(MySqlParser::AlterByAddPartitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByDropPartition(MySqlParser::AlterByDropPartitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByDiscardPartition(MySqlParser::AlterByDiscardPartitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByImportPartition(MySqlParser::AlterByImportPartitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByTruncatePartition(MySqlParser::AlterByTruncatePartitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByCoalescePartition(MySqlParser::AlterByCoalescePartitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByReorganizePartition(MySqlParser::AlterByReorganizePartitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByExchangePartition(MySqlParser::AlterByExchangePartitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByAnalyzePartition(MySqlParser::AlterByAnalyzePartitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByCheckPartition(MySqlParser::AlterByCheckPartitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByOptimizePartition(MySqlParser::AlterByOptimizePartitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByRebuildPartition(MySqlParser::AlterByRebuildPartitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByRepairPartition(MySqlParser::AlterByRepairPartitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByRemovePartitioning(MySqlParser::AlterByRemovePartitioningContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterByUpgradePartitioning(MySqlParser::AlterByUpgradePartitioningContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDropDatabase(MySqlParser::DropDatabaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDropEvent(MySqlParser::DropEventContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDropIndex(MySqlParser::DropIndexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDropLogfileGroup(MySqlParser::DropLogfileGroupContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDropProcedure(MySqlParser::DropProcedureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDropFunction(MySqlParser::DropFunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDropServer(MySqlParser::DropServerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDropTable(MySqlParser::DropTableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDropTablespace(MySqlParser::DropTablespaceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDropTrigger(MySqlParser::DropTriggerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDropView(MySqlParser::DropViewContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDropRole(MySqlParser::DropRoleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSetRole(MySqlParser::SetRoleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRenameTable(MySqlParser::RenameTableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRenameTableClause(MySqlParser::RenameTableClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTruncateTable(MySqlParser::TruncateTableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCallStatement(MySqlParser::CallStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeleteStatement(MySqlParser::DeleteStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDoStatement(MySqlParser::DoStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitHandlerStatement(MySqlParser::HandlerStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInsertStatement(MySqlParser::InsertStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLoadDataStatement(MySqlParser::LoadDataStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLoadXmlStatement(MySqlParser::LoadXmlStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReplaceStatement(MySqlParser::ReplaceStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleSelect(MySqlParser::SimpleSelectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParenthesisSelect(MySqlParser::ParenthesisSelectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnionSelect(MySqlParser::UnionSelectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnionParenthesisSelect(MySqlParser::UnionParenthesisSelectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWithLateralStatement(MySqlParser::WithLateralStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUpdateStatement(MySqlParser::UpdateStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValuesStatement(MySqlParser::ValuesStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInsertStatementValue(MySqlParser::InsertStatementValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUpdatedElement(MySqlParser::UpdatedElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignmentField(MySqlParser::AssignmentFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLockClause(MySqlParser::LockClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSingleDeleteStatement(MySqlParser::SingleDeleteStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMultipleDeleteStatement(MySqlParser::MultipleDeleteStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitHandlerOpenStatement(MySqlParser::HandlerOpenStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitHandlerReadIndexStatement(MySqlParser::HandlerReadIndexStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitHandlerReadStatement(MySqlParser::HandlerReadStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitHandlerCloseStatement(MySqlParser::HandlerCloseStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSingleUpdateStatement(MySqlParser::SingleUpdateStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMultipleUpdateStatement(MySqlParser::MultipleUpdateStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrderByClause(MySqlParser::OrderByClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrderByExpression(MySqlParser::OrderByExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableSources(MySqlParser::TableSourcesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableSourceBase(MySqlParser::TableSourceBaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableSourceNested(MySqlParser::TableSourceNestedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableJson(MySqlParser::TableJsonContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtomTableItem(MySqlParser::AtomTableItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubqueryTableItem(MySqlParser::SubqueryTableItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableSourcesItem(MySqlParser::TableSourcesItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIndexHint(MySqlParser::IndexHintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIndexHintType(MySqlParser::IndexHintTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInnerJoin(MySqlParser::InnerJoinContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStraightJoin(MySqlParser::StraightJoinContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOuterJoin(MySqlParser::OuterJoinContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNaturalJoin(MySqlParser::NaturalJoinContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQueryExpression(MySqlParser::QueryExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQueryExpressionNointo(MySqlParser::QueryExpressionNointoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQuerySpecification(MySqlParser::QuerySpecificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQuerySpecificationNointo(MySqlParser::QuerySpecificationNointoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnionParenthesis(MySqlParser::UnionParenthesisContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnionStatement(MySqlParser::UnionStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLateralStatement(MySqlParser::LateralStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitJsonTable(MySqlParser::JsonTableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitJsonColumnList(MySqlParser::JsonColumnListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitJsonColumn(MySqlParser::JsonColumnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitJsonOnEmpty(MySqlParser::JsonOnEmptyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitJsonOnError(MySqlParser::JsonOnErrorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelectSpec(MySqlParser::SelectSpecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelectElements(MySqlParser::SelectElementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelectStarElement(MySqlParser::SelectStarElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelectColumnElement(MySqlParser::SelectColumnElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelectFunctionElement(MySqlParser::SelectFunctionElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelectExpressionElement(MySqlParser::SelectExpressionElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelectIntoVariables(MySqlParser::SelectIntoVariablesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelectIntoDumpFile(MySqlParser::SelectIntoDumpFileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelectIntoTextFile(MySqlParser::SelectIntoTextFileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelectFieldsInto(MySqlParser::SelectFieldsIntoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelectLinesInto(MySqlParser::SelectLinesIntoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFromClause(MySqlParser::FromClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGroupByClause(MySqlParser::GroupByClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitHavingClause(MySqlParser::HavingClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWindowClause(MySqlParser::WindowClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGroupByItem(MySqlParser::GroupByItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLimitClause(MySqlParser::LimitClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLimitClauseAtom(MySqlParser::LimitClauseAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStartTransaction(MySqlParser::StartTransactionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBeginWork(MySqlParser::BeginWorkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCommitWork(MySqlParser::CommitWorkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRollbackWork(MySqlParser::RollbackWorkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSavepointStatement(MySqlParser::SavepointStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRollbackStatement(MySqlParser::RollbackStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReleaseStatement(MySqlParser::ReleaseStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLockTables(MySqlParser::LockTablesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnlockTables(MySqlParser::UnlockTablesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSetAutocommitStatement(MySqlParser::SetAutocommitStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSetTransactionStatement(MySqlParser::SetTransactionStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTransactionMode(MySqlParser::TransactionModeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLockTableElement(MySqlParser::LockTableElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLockAction(MySqlParser::LockActionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTransactionOption(MySqlParser::TransactionOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTransactionLevel(MySqlParser::TransactionLevelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitChangeMaster(MySqlParser::ChangeMasterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitChangeReplicationFilter(MySqlParser::ChangeReplicationFilterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPurgeBinaryLogs(MySqlParser::PurgeBinaryLogsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitResetMaster(MySqlParser::ResetMasterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitResetSlave(MySqlParser::ResetSlaveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStartSlave(MySqlParser::StartSlaveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStopSlave(MySqlParser::StopSlaveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStartGroupReplication(MySqlParser::StartGroupReplicationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStopGroupReplication(MySqlParser::StopGroupReplicationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMasterStringOption(MySqlParser::MasterStringOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMasterDecimalOption(MySqlParser::MasterDecimalOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMasterBoolOption(MySqlParser::MasterBoolOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMasterRealOption(MySqlParser::MasterRealOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMasterUidListOption(MySqlParser::MasterUidListOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStringMasterOption(MySqlParser::StringMasterOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecimalMasterOption(MySqlParser::DecimalMasterOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBoolMasterOption(MySqlParser::BoolMasterOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitChannelOption(MySqlParser::ChannelOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDoDbReplication(MySqlParser::DoDbReplicationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIgnoreDbReplication(MySqlParser::IgnoreDbReplicationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDoTableReplication(MySqlParser::DoTableReplicationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIgnoreTableReplication(MySqlParser::IgnoreTableReplicationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWildDoTableReplication(MySqlParser::WildDoTableReplicationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWildIgnoreTableReplication(MySqlParser::WildIgnoreTableReplicationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRewriteDbReplication(MySqlParser::RewriteDbReplicationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTablePair(MySqlParser::TablePairContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitThreadType(MySqlParser::ThreadTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGtidsUntilOption(MySqlParser::GtidsUntilOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMasterLogUntilOption(MySqlParser::MasterLogUntilOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelayLogUntilOption(MySqlParser::RelayLogUntilOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSqlGapsUntilOption(MySqlParser::SqlGapsUntilOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUserConnectionOption(MySqlParser::UserConnectionOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPasswordConnectionOption(MySqlParser::PasswordConnectionOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDefaultAuthConnectionOption(MySqlParser::DefaultAuthConnectionOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPluginDirConnectionOption(MySqlParser::PluginDirConnectionOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGtuidSet(MySqlParser::GtuidSetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitXaStartTransaction(MySqlParser::XaStartTransactionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitXaEndTransaction(MySqlParser::XaEndTransactionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitXaPrepareStatement(MySqlParser::XaPrepareStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitXaCommitWork(MySqlParser::XaCommitWorkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitXaRollbackWork(MySqlParser::XaRollbackWorkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitXaRecoverWork(MySqlParser::XaRecoverWorkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrepareStatement(MySqlParser::PrepareStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExecuteStatement(MySqlParser::ExecuteStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeallocatePrepare(MySqlParser::DeallocatePrepareContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRoutineBody(MySqlParser::RoutineBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlockStatement(MySqlParser::BlockStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCaseStatement(MySqlParser::CaseStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStatement(MySqlParser::IfStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIterateStatement(MySqlParser::IterateStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLeaveStatement(MySqlParser::LeaveStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLoopStatement(MySqlParser::LoopStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRepeatStatement(MySqlParser::RepeatStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStatement(MySqlParser::ReturnStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileStatement(MySqlParser::WhileStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCloseCursor(MySqlParser::CloseCursorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFetchCursor(MySqlParser::FetchCursorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOpenCursor(MySqlParser::OpenCursorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclareVariable(MySqlParser::DeclareVariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclareCondition(MySqlParser::DeclareConditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclareCursor(MySqlParser::DeclareCursorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclareHandler(MySqlParser::DeclareHandlerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitHandlerConditionCode(MySqlParser::HandlerConditionCodeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitHandlerConditionState(MySqlParser::HandlerConditionStateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitHandlerConditionName(MySqlParser::HandlerConditionNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitHandlerConditionWarning(MySqlParser::HandlerConditionWarningContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitHandlerConditionNotfound(MySqlParser::HandlerConditionNotfoundContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitHandlerConditionException(MySqlParser::HandlerConditionExceptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProcedureSqlStatement(MySqlParser::ProcedureSqlStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCaseAlternative(MySqlParser::CaseAlternativeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElifAlternative(MySqlParser::ElifAlternativeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterUserMysqlV56(MySqlParser::AlterUserMysqlV56Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlterUserMysqlV80(MySqlParser::AlterUserMysqlV80Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCreateUserMysqlV56(MySqlParser::CreateUserMysqlV56Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCreateUserMysqlV80(MySqlParser::CreateUserMysqlV80Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDropUser(MySqlParser::DropUserContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGrantStatement(MySqlParser::GrantStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRoleOption(MySqlParser::RoleOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGrantProxy(MySqlParser::GrantProxyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRenameUser(MySqlParser::RenameUserContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDetailRevoke(MySqlParser::DetailRevokeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShortRevoke(MySqlParser::ShortRevokeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRoleRevoke(MySqlParser::RoleRevokeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRevokeProxy(MySqlParser::RevokeProxyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSetPasswordStatement(MySqlParser::SetPasswordStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUserSpecification(MySqlParser::UserSpecificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitHashAuthOption(MySqlParser::HashAuthOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStringAuthOption(MySqlParser::StringAuthOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModuleAuthOption(MySqlParser::ModuleAuthOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleAuthOption(MySqlParser::SimpleAuthOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModule(MySqlParser::ModuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPasswordModuleOption(MySqlParser::PasswordModuleOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTlsOption(MySqlParser::TlsOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUserResourceOption(MySqlParser::UserResourceOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUserPasswordOption(MySqlParser::UserPasswordOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUserLockOption(MySqlParser::UserLockOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrivelegeClause(MySqlParser::PrivelegeClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrivilege(MySqlParser::PrivilegeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCurrentSchemaPriviLevel(MySqlParser::CurrentSchemaPriviLevelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGlobalPrivLevel(MySqlParser::GlobalPrivLevelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDefiniteSchemaPrivLevel(MySqlParser::DefiniteSchemaPrivLevelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDefiniteFullTablePrivLevel(MySqlParser::DefiniteFullTablePrivLevelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDefiniteFullTablePrivLevel2(MySqlParser::DefiniteFullTablePrivLevel2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDefiniteTablePrivLevel(MySqlParser::DefiniteTablePrivLevelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRenameUserClause(MySqlParser::RenameUserClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAnalyzeTable(MySqlParser::AnalyzeTableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCheckTable(MySqlParser::CheckTableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitChecksumTable(MySqlParser::ChecksumTableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptimizeTable(MySqlParser::OptimizeTableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRepairTable(MySqlParser::RepairTableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCheckTableOption(MySqlParser::CheckTableOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCreateUdfunction(MySqlParser::CreateUdfunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInstallPlugin(MySqlParser::InstallPluginContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUninstallPlugin(MySqlParser::UninstallPluginContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSetVariable(MySqlParser::SetVariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSetCharset(MySqlParser::SetCharsetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSetNames(MySqlParser::SetNamesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSetPassword(MySqlParser::SetPasswordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSetTransaction(MySqlParser::SetTransactionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSetAutocommit(MySqlParser::SetAutocommitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSetNewValueInsideTrigger(MySqlParser::SetNewValueInsideTriggerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShowMasterLogs(MySqlParser::ShowMasterLogsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShowLogEvents(MySqlParser::ShowLogEventsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShowObjectFilter(MySqlParser::ShowObjectFilterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShowColumns(MySqlParser::ShowColumnsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShowCreateDb(MySqlParser::ShowCreateDbContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShowCreateFullIdObject(MySqlParser::ShowCreateFullIdObjectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShowCreateUser(MySqlParser::ShowCreateUserContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShowEngine(MySqlParser::ShowEngineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShowGlobalInfo(MySqlParser::ShowGlobalInfoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShowErrors(MySqlParser::ShowErrorsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShowCountErrors(MySqlParser::ShowCountErrorsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShowSchemaFilter(MySqlParser::ShowSchemaFilterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShowRoutine(MySqlParser::ShowRoutineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShowGrants(MySqlParser::ShowGrantsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShowIndexes(MySqlParser::ShowIndexesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShowOpenTables(MySqlParser::ShowOpenTablesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShowProfile(MySqlParser::ShowProfileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShowSlaveStatus(MySqlParser::ShowSlaveStatusContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableClause(MySqlParser::VariableClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShowCommonEntity(MySqlParser::ShowCommonEntityContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShowFilter(MySqlParser::ShowFilterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShowGlobalInfoClause(MySqlParser::ShowGlobalInfoClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShowSchemaEntity(MySqlParser::ShowSchemaEntityContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShowProfileType(MySqlParser::ShowProfileTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBinlogStatement(MySqlParser::BinlogStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCacheIndexStatement(MySqlParser::CacheIndexStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFlushStatement(MySqlParser::FlushStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKillStatement(MySqlParser::KillStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLoadIndexIntoCache(MySqlParser::LoadIndexIntoCacheContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitResetStatement(MySqlParser::ResetStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShutdownStatement(MySqlParser::ShutdownStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableIndexes(MySqlParser::TableIndexesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleFlushOption(MySqlParser::SimpleFlushOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitChannelFlushOption(MySqlParser::ChannelFlushOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableFlushOption(MySqlParser::TableFlushOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFlushTableOption(MySqlParser::FlushTableOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLoadedTableIndexes(MySqlParser::LoadedTableIndexesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleDescribeStatement(MySqlParser::SimpleDescribeStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFullDescribeStatement(MySqlParser::FullDescribeStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitHelpStatement(MySqlParser::HelpStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUseStatement(MySqlParser::UseStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSignalStatement(MySqlParser::SignalStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitResignalStatement(MySqlParser::ResignalStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSignalConditionInformation(MySqlParser::SignalConditionInformationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWithStatement(MySqlParser::WithStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableStatement(MySqlParser::TableStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiagnosticsStatement(MySqlParser::DiagnosticsStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiagnosticsConditionInformationName(MySqlParser::DiagnosticsConditionInformationNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDescribeStatements(MySqlParser::DescribeStatementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDescribeConnection(MySqlParser::DescribeConnectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFullId(MySqlParser::FullIdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableName(MySqlParser::TableNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRoleName(MySqlParser::RoleNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFullColumnName(MySqlParser::FullColumnNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIndexColumnName(MySqlParser::IndexColumnNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUserName(MySqlParser::UserNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMysqlVariable(MySqlParser::MysqlVariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCharsetName(MySqlParser::CharsetNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCollationName(MySqlParser::CollationNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEngineName(MySqlParser::EngineNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEngineNameBase(MySqlParser::EngineNameBaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUuidSet(MySqlParser::UuidSetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitXid(MySqlParser::XidContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitXuidStringId(MySqlParser::XuidStringIdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAuthPlugin(MySqlParser::AuthPluginContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUid(MySqlParser::UidContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleId(MySqlParser::SimpleIdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDottedId(MySqlParser::DottedIdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecimalLiteral(MySqlParser::DecimalLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFileSizeLiteral(MySqlParser::FileSizeLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStringLiteral(MySqlParser::StringLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBooleanLiteral(MySqlParser::BooleanLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitHexadecimalLiteral(MySqlParser::HexadecimalLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNullNotnull(MySqlParser::NullNotnullContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstant(MySqlParser::ConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStringDataType(MySqlParser::StringDataTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNationalVaryingStringDataType(MySqlParser::NationalVaryingStringDataTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNationalStringDataType(MySqlParser::NationalStringDataTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDimensionDataType(MySqlParser::DimensionDataTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleDataType(MySqlParser::SimpleDataTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCollectionDataType(MySqlParser::CollectionDataTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSpatialDataType(MySqlParser::SpatialDataTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLongVarcharDataType(MySqlParser::LongVarcharDataTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLongVarbinaryDataType(MySqlParser::LongVarbinaryDataTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCollectionOptions(MySqlParser::CollectionOptionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConvertedDataType(MySqlParser::ConvertedDataTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLengthOneDimension(MySqlParser::LengthOneDimensionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLengthTwoDimension(MySqlParser::LengthTwoDimensionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLengthTwoOptionalDimension(MySqlParser::LengthTwoOptionalDimensionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUidList(MySqlParser::UidListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFullColumnNameList(MySqlParser::FullColumnNameListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTables(MySqlParser::TablesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIndexColumnNames(MySqlParser::IndexColumnNamesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressions(MySqlParser::ExpressionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionsWithDefaults(MySqlParser::ExpressionsWithDefaultsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstants(MySqlParser::ConstantsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleStrings(MySqlParser::SimpleStringsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUserVariables(MySqlParser::UserVariablesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDefaultValue(MySqlParser::DefaultValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCurrentTimestamp(MySqlParser::CurrentTimestampContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionOrDefault(MySqlParser::ExpressionOrDefaultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfExists(MySqlParser::IfExistsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfNotExists(MySqlParser::IfNotExistsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrReplace(MySqlParser::OrReplaceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWaitNowaitClause(MySqlParser::WaitNowaitClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSpecificFunctionCall(MySqlParser::SpecificFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAggregateFunctionCall(MySqlParser::AggregateFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNonAggregateFunctionCall(MySqlParser::NonAggregateFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitScalarFunctionCall(MySqlParser::ScalarFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUdfFunctionCall(MySqlParser::UdfFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPasswordFunctionCall(MySqlParser::PasswordFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleFunctionCall(MySqlParser::SimpleFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDataTypeFunctionCall(MySqlParser::DataTypeFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValuesFunctionCall(MySqlParser::ValuesFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCaseExpressionFunctionCall(MySqlParser::CaseExpressionFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCaseFunctionCall(MySqlParser::CaseFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCharFunctionCall(MySqlParser::CharFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPositionFunctionCall(MySqlParser::PositionFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubstrFunctionCall(MySqlParser::SubstrFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTrimFunctionCall(MySqlParser::TrimFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWeightFunctionCall(MySqlParser::WeightFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExtractFunctionCall(MySqlParser::ExtractFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGetFormatFunctionCall(MySqlParser::GetFormatFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitJsonValueFunctionCall(MySqlParser::JsonValueFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCaseFuncAlternative(MySqlParser::CaseFuncAlternativeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLevelWeightList(MySqlParser::LevelWeightListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLevelWeightRange(MySqlParser::LevelWeightRangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLevelInWeightListElement(MySqlParser::LevelInWeightListElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAggregateWindowedFunction(MySqlParser::AggregateWindowedFunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNonAggregateWindowedFunction(MySqlParser::NonAggregateWindowedFunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOverClause(MySqlParser::OverClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWindowSpec(MySqlParser::WindowSpecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWindowName(MySqlParser::WindowNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFrameClause(MySqlParser::FrameClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFrameUnits(MySqlParser::FrameUnitsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFrameExtent(MySqlParser::FrameExtentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFrameBetween(MySqlParser::FrameBetweenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFrameRange(MySqlParser::FrameRangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPartitionClause(MySqlParser::PartitionClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitScalarFunctionName(MySqlParser::ScalarFunctionNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPasswordFunctionClause(MySqlParser::PasswordFunctionClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionArgs(MySqlParser::FunctionArgsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionArg(MySqlParser::FunctionArgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIsExpression(MySqlParser::IsExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNotExpression(MySqlParser::NotExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogicalExpression(MySqlParser::LogicalExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPredicateExpression(MySqlParser::PredicateExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSoundsLikePredicate(MySqlParser::SoundsLikePredicateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionAtomPredicate(MySqlParser::ExpressionAtomPredicateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubqueryComparisonPredicate(MySqlParser::SubqueryComparisonPredicateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitJsonMemberOfPredicate(MySqlParser::JsonMemberOfPredicateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBinaryComparisonPredicate(MySqlParser::BinaryComparisonPredicateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInPredicate(MySqlParser::InPredicateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBetweenPredicate(MySqlParser::BetweenPredicateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIsNullPredicate(MySqlParser::IsNullPredicateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLikePredicate(MySqlParser::LikePredicateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRegexpPredicate(MySqlParser::RegexpPredicateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryExpressionAtom(MySqlParser::UnaryExpressionAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCollateExpressionAtom(MySqlParser::CollateExpressionAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMysqlVariableExpressionAtom(MySqlParser::MysqlVariableExpressionAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNestedExpressionAtom(MySqlParser::NestedExpressionAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNestedRowExpressionAtom(MySqlParser::NestedRowExpressionAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMathExpressionAtom(MySqlParser::MathExpressionAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExistsExpressionAtom(MySqlParser::ExistsExpressionAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntervalExpressionAtom(MySqlParser::IntervalExpressionAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitJsonExpressionAtom(MySqlParser::JsonExpressionAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubqueryExpressionAtom(MySqlParser::SubqueryExpressionAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstantExpressionAtom(MySqlParser::ConstantExpressionAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionCallExpressionAtom(MySqlParser::FunctionCallExpressionAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBinaryExpressionAtom(MySqlParser::BinaryExpressionAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFullColumnNameExpressionAtom(MySqlParser::FullColumnNameExpressionAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitExpressionAtom(MySqlParser::BitExpressionAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryOperator(MySqlParser::UnaryOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComparisonOperator(MySqlParser::ComparisonOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogicalOperator(MySqlParser::LogicalOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitOperator(MySqlParser::BitOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMathOperator(MySqlParser::MathOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitJsonOperator(MySqlParser::JsonOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCharsetNameBase(MySqlParser::CharsetNameBaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTransactionLevelBase(MySqlParser::TransactionLevelBaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrivilegesBase(MySqlParser::PrivilegesBaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntervalTypeBase(MySqlParser::IntervalTypeBaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDataTypeBase(MySqlParser::DataTypeBaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKeywordsCanBeId(MySqlParser::KeywordsCanBeIdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionNameBase(MySqlParser::FunctionNameBaseContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace antlrcpptest
