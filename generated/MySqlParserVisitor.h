
// Generated from MySqlParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "MySqlParser.h"


namespace antlrcpptest {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by MySqlParser.
 */
class  MySqlParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by MySqlParser.
   */
    virtual std::any visitRoot(MySqlParser::RootContext *context) = 0;

    virtual std::any visitSqlStatements(MySqlParser::SqlStatementsContext *context) = 0;

    virtual std::any visitSqlStatement(MySqlParser::SqlStatementContext *context) = 0;

    virtual std::any visitEmptyStatement_(MySqlParser::EmptyStatement_Context *context) = 0;

    virtual std::any visitDdlStatement(MySqlParser::DdlStatementContext *context) = 0;

    virtual std::any visitDmlStatement(MySqlParser::DmlStatementContext *context) = 0;

    virtual std::any visitTransactionStatement(MySqlParser::TransactionStatementContext *context) = 0;

    virtual std::any visitReplicationStatement(MySqlParser::ReplicationStatementContext *context) = 0;

    virtual std::any visitPreparedStatement(MySqlParser::PreparedStatementContext *context) = 0;

    virtual std::any visitCompoundStatement(MySqlParser::CompoundStatementContext *context) = 0;

    virtual std::any visitAdministrationStatement(MySqlParser::AdministrationStatementContext *context) = 0;

    virtual std::any visitUtilityStatement(MySqlParser::UtilityStatementContext *context) = 0;

    virtual std::any visitCreateDatabase(MySqlParser::CreateDatabaseContext *context) = 0;

    virtual std::any visitCreateEvent(MySqlParser::CreateEventContext *context) = 0;

    virtual std::any visitCreateIndex(MySqlParser::CreateIndexContext *context) = 0;

    virtual std::any visitCreateLogfileGroup(MySqlParser::CreateLogfileGroupContext *context) = 0;

    virtual std::any visitCreateProcedure(MySqlParser::CreateProcedureContext *context) = 0;

    virtual std::any visitCreateFunction(MySqlParser::CreateFunctionContext *context) = 0;

    virtual std::any visitCreateRole(MySqlParser::CreateRoleContext *context) = 0;

    virtual std::any visitCreateServer(MySqlParser::CreateServerContext *context) = 0;

    virtual std::any visitCopyCreateTable(MySqlParser::CopyCreateTableContext *context) = 0;

    virtual std::any visitQueryCreateTable(MySqlParser::QueryCreateTableContext *context) = 0;

    virtual std::any visitColumnCreateTable(MySqlParser::ColumnCreateTableContext *context) = 0;

    virtual std::any visitCreateTablespaceInnodb(MySqlParser::CreateTablespaceInnodbContext *context) = 0;

    virtual std::any visitCreateTablespaceNdb(MySqlParser::CreateTablespaceNdbContext *context) = 0;

    virtual std::any visitCreateTrigger(MySqlParser::CreateTriggerContext *context) = 0;

    virtual std::any visitWithClause(MySqlParser::WithClauseContext *context) = 0;

    virtual std::any visitCommonTableExpressions(MySqlParser::CommonTableExpressionsContext *context) = 0;

    virtual std::any visitCteName(MySqlParser::CteNameContext *context) = 0;

    virtual std::any visitCteColumnName(MySqlParser::CteColumnNameContext *context) = 0;

    virtual std::any visitCreateView(MySqlParser::CreateViewContext *context) = 0;

    virtual std::any visitCreateDatabaseOption(MySqlParser::CreateDatabaseOptionContext *context) = 0;

    virtual std::any visitCharSet(MySqlParser::CharSetContext *context) = 0;

    virtual std::any visitOwnerStatement(MySqlParser::OwnerStatementContext *context) = 0;

    virtual std::any visitPreciseSchedule(MySqlParser::PreciseScheduleContext *context) = 0;

    virtual std::any visitIntervalSchedule(MySqlParser::IntervalScheduleContext *context) = 0;

    virtual std::any visitTimestampValue(MySqlParser::TimestampValueContext *context) = 0;

    virtual std::any visitIntervalExpr(MySqlParser::IntervalExprContext *context) = 0;

    virtual std::any visitIntervalType(MySqlParser::IntervalTypeContext *context) = 0;

    virtual std::any visitEnableType(MySqlParser::EnableTypeContext *context) = 0;

    virtual std::any visitIndexType(MySqlParser::IndexTypeContext *context) = 0;

    virtual std::any visitIndexOption(MySqlParser::IndexOptionContext *context) = 0;

    virtual std::any visitProcedureParameter(MySqlParser::ProcedureParameterContext *context) = 0;

    virtual std::any visitFunctionParameter(MySqlParser::FunctionParameterContext *context) = 0;

    virtual std::any visitRoutineComment(MySqlParser::RoutineCommentContext *context) = 0;

    virtual std::any visitRoutineLanguage(MySqlParser::RoutineLanguageContext *context) = 0;

    virtual std::any visitRoutineBehavior(MySqlParser::RoutineBehaviorContext *context) = 0;

    virtual std::any visitRoutineData(MySqlParser::RoutineDataContext *context) = 0;

    virtual std::any visitRoutineSecurity(MySqlParser::RoutineSecurityContext *context) = 0;

    virtual std::any visitServerOption(MySqlParser::ServerOptionContext *context) = 0;

    virtual std::any visitCreateDefinitions(MySqlParser::CreateDefinitionsContext *context) = 0;

    virtual std::any visitColumnDeclaration(MySqlParser::ColumnDeclarationContext *context) = 0;

    virtual std::any visitConstraintDeclaration(MySqlParser::ConstraintDeclarationContext *context) = 0;

    virtual std::any visitIndexDeclaration(MySqlParser::IndexDeclarationContext *context) = 0;

    virtual std::any visitColumnDefinition(MySqlParser::ColumnDefinitionContext *context) = 0;

    virtual std::any visitNullColumnConstraint(MySqlParser::NullColumnConstraintContext *context) = 0;

    virtual std::any visitDefaultColumnConstraint(MySqlParser::DefaultColumnConstraintContext *context) = 0;

    virtual std::any visitVisibilityColumnConstraint(MySqlParser::VisibilityColumnConstraintContext *context) = 0;

    virtual std::any visitInvisibilityColumnConstraint(MySqlParser::InvisibilityColumnConstraintContext *context) = 0;

    virtual std::any visitAutoIncrementColumnConstraint(MySqlParser::AutoIncrementColumnConstraintContext *context) = 0;

    virtual std::any visitPrimaryKeyColumnConstraint(MySqlParser::PrimaryKeyColumnConstraintContext *context) = 0;

    virtual std::any visitUniqueKeyColumnConstraint(MySqlParser::UniqueKeyColumnConstraintContext *context) = 0;

    virtual std::any visitCommentColumnConstraint(MySqlParser::CommentColumnConstraintContext *context) = 0;

    virtual std::any visitFormatColumnConstraint(MySqlParser::FormatColumnConstraintContext *context) = 0;

    virtual std::any visitStorageColumnConstraint(MySqlParser::StorageColumnConstraintContext *context) = 0;

    virtual std::any visitReferenceColumnConstraint(MySqlParser::ReferenceColumnConstraintContext *context) = 0;

    virtual std::any visitCollateColumnConstraint(MySqlParser::CollateColumnConstraintContext *context) = 0;

    virtual std::any visitGeneratedColumnConstraint(MySqlParser::GeneratedColumnConstraintContext *context) = 0;

    virtual std::any visitSerialDefaultColumnConstraint(MySqlParser::SerialDefaultColumnConstraintContext *context) = 0;

    virtual std::any visitCheckColumnConstraint(MySqlParser::CheckColumnConstraintContext *context) = 0;

    virtual std::any visitPrimaryKeyTableConstraint(MySqlParser::PrimaryKeyTableConstraintContext *context) = 0;

    virtual std::any visitUniqueKeyTableConstraint(MySqlParser::UniqueKeyTableConstraintContext *context) = 0;

    virtual std::any visitForeignKeyTableConstraint(MySqlParser::ForeignKeyTableConstraintContext *context) = 0;

    virtual std::any visitCheckTableConstraint(MySqlParser::CheckTableConstraintContext *context) = 0;

    virtual std::any visitReferenceDefinition(MySqlParser::ReferenceDefinitionContext *context) = 0;

    virtual std::any visitReferenceAction(MySqlParser::ReferenceActionContext *context) = 0;

    virtual std::any visitReferenceControlType(MySqlParser::ReferenceControlTypeContext *context) = 0;

    virtual std::any visitSimpleIndexDeclaration(MySqlParser::SimpleIndexDeclarationContext *context) = 0;

    virtual std::any visitSpecialIndexDeclaration(MySqlParser::SpecialIndexDeclarationContext *context) = 0;

    virtual std::any visitTableOptionEngine(MySqlParser::TableOptionEngineContext *context) = 0;

    virtual std::any visitTableOptionEngineAttribute(MySqlParser::TableOptionEngineAttributeContext *context) = 0;

    virtual std::any visitTableOptionAutoextendSize(MySqlParser::TableOptionAutoextendSizeContext *context) = 0;

    virtual std::any visitTableOptionAutoIncrement(MySqlParser::TableOptionAutoIncrementContext *context) = 0;

    virtual std::any visitTableOptionAverage(MySqlParser::TableOptionAverageContext *context) = 0;

    virtual std::any visitTableOptionCharset(MySqlParser::TableOptionCharsetContext *context) = 0;

    virtual std::any visitTableOptionChecksum(MySqlParser::TableOptionChecksumContext *context) = 0;

    virtual std::any visitTableOptionCollate(MySqlParser::TableOptionCollateContext *context) = 0;

    virtual std::any visitTableOptionComment(MySqlParser::TableOptionCommentContext *context) = 0;

    virtual std::any visitTableOptionCompression(MySqlParser::TableOptionCompressionContext *context) = 0;

    virtual std::any visitTableOptionConnection(MySqlParser::TableOptionConnectionContext *context) = 0;

    virtual std::any visitTableOptionDataDirectory(MySqlParser::TableOptionDataDirectoryContext *context) = 0;

    virtual std::any visitTableOptionDelay(MySqlParser::TableOptionDelayContext *context) = 0;

    virtual std::any visitTableOptionEncryption(MySqlParser::TableOptionEncryptionContext *context) = 0;

    virtual std::any visitTableOptionPageCompressed(MySqlParser::TableOptionPageCompressedContext *context) = 0;

    virtual std::any visitTableOptionPageCompressionLevel(MySqlParser::TableOptionPageCompressionLevelContext *context) = 0;

    virtual std::any visitTableOptionEncryptionKeyId(MySqlParser::TableOptionEncryptionKeyIdContext *context) = 0;

    virtual std::any visitTableOptionIndexDirectory(MySqlParser::TableOptionIndexDirectoryContext *context) = 0;

    virtual std::any visitTableOptionInsertMethod(MySqlParser::TableOptionInsertMethodContext *context) = 0;

    virtual std::any visitTableOptionKeyBlockSize(MySqlParser::TableOptionKeyBlockSizeContext *context) = 0;

    virtual std::any visitTableOptionMaxRows(MySqlParser::TableOptionMaxRowsContext *context) = 0;

    virtual std::any visitTableOptionMinRows(MySqlParser::TableOptionMinRowsContext *context) = 0;

    virtual std::any visitTableOptionPackKeys(MySqlParser::TableOptionPackKeysContext *context) = 0;

    virtual std::any visitTableOptionPassword(MySqlParser::TableOptionPasswordContext *context) = 0;

    virtual std::any visitTableOptionRowFormat(MySqlParser::TableOptionRowFormatContext *context) = 0;

    virtual std::any visitTableOptionStartTransaction(MySqlParser::TableOptionStartTransactionContext *context) = 0;

    virtual std::any visitTableOptionSecondaryEngineAttribute(MySqlParser::TableOptionSecondaryEngineAttributeContext *context) = 0;

    virtual std::any visitTableOptionRecalculation(MySqlParser::TableOptionRecalculationContext *context) = 0;

    virtual std::any visitTableOptionPersistent(MySqlParser::TableOptionPersistentContext *context) = 0;

    virtual std::any visitTableOptionSamplePage(MySqlParser::TableOptionSamplePageContext *context) = 0;

    virtual std::any visitTableOptionTablespace(MySqlParser::TableOptionTablespaceContext *context) = 0;

    virtual std::any visitTableOptionTableType(MySqlParser::TableOptionTableTypeContext *context) = 0;

    virtual std::any visitTableOptionTransactional(MySqlParser::TableOptionTransactionalContext *context) = 0;

    virtual std::any visitTableOptionUnion(MySqlParser::TableOptionUnionContext *context) = 0;

    virtual std::any visitTableType(MySqlParser::TableTypeContext *context) = 0;

    virtual std::any visitTablespaceStorage(MySqlParser::TablespaceStorageContext *context) = 0;

    virtual std::any visitPartitionDefinitions(MySqlParser::PartitionDefinitionsContext *context) = 0;

    virtual std::any visitPartitionFunctionHash(MySqlParser::PartitionFunctionHashContext *context) = 0;

    virtual std::any visitPartitionFunctionKey(MySqlParser::PartitionFunctionKeyContext *context) = 0;

    virtual std::any visitPartitionFunctionRange(MySqlParser::PartitionFunctionRangeContext *context) = 0;

    virtual std::any visitPartitionFunctionList(MySqlParser::PartitionFunctionListContext *context) = 0;

    virtual std::any visitSubPartitionFunctionHash(MySqlParser::SubPartitionFunctionHashContext *context) = 0;

    virtual std::any visitSubPartitionFunctionKey(MySqlParser::SubPartitionFunctionKeyContext *context) = 0;

    virtual std::any visitPartitionComparison(MySqlParser::PartitionComparisonContext *context) = 0;

    virtual std::any visitPartitionListAtom(MySqlParser::PartitionListAtomContext *context) = 0;

    virtual std::any visitPartitionListVector(MySqlParser::PartitionListVectorContext *context) = 0;

    virtual std::any visitPartitionSimple(MySqlParser::PartitionSimpleContext *context) = 0;

    virtual std::any visitPartitionDefinerAtom(MySqlParser::PartitionDefinerAtomContext *context) = 0;

    virtual std::any visitPartitionDefinerVector(MySqlParser::PartitionDefinerVectorContext *context) = 0;

    virtual std::any visitSubpartitionDefinition(MySqlParser::SubpartitionDefinitionContext *context) = 0;

    virtual std::any visitPartitionOptionEngine(MySqlParser::PartitionOptionEngineContext *context) = 0;

    virtual std::any visitPartitionOptionComment(MySqlParser::PartitionOptionCommentContext *context) = 0;

    virtual std::any visitPartitionOptionDataDirectory(MySqlParser::PartitionOptionDataDirectoryContext *context) = 0;

    virtual std::any visitPartitionOptionIndexDirectory(MySqlParser::PartitionOptionIndexDirectoryContext *context) = 0;

    virtual std::any visitPartitionOptionMaxRows(MySqlParser::PartitionOptionMaxRowsContext *context) = 0;

    virtual std::any visitPartitionOptionMinRows(MySqlParser::PartitionOptionMinRowsContext *context) = 0;

    virtual std::any visitPartitionOptionTablespace(MySqlParser::PartitionOptionTablespaceContext *context) = 0;

    virtual std::any visitPartitionOptionNodeGroup(MySqlParser::PartitionOptionNodeGroupContext *context) = 0;

    virtual std::any visitAlterSimpleDatabase(MySqlParser::AlterSimpleDatabaseContext *context) = 0;

    virtual std::any visitAlterUpgradeName(MySqlParser::AlterUpgradeNameContext *context) = 0;

    virtual std::any visitAlterEvent(MySqlParser::AlterEventContext *context) = 0;

    virtual std::any visitAlterFunction(MySqlParser::AlterFunctionContext *context) = 0;

    virtual std::any visitAlterInstance(MySqlParser::AlterInstanceContext *context) = 0;

    virtual std::any visitAlterLogfileGroup(MySqlParser::AlterLogfileGroupContext *context) = 0;

    virtual std::any visitAlterProcedure(MySqlParser::AlterProcedureContext *context) = 0;

    virtual std::any visitAlterServer(MySqlParser::AlterServerContext *context) = 0;

    virtual std::any visitAlterTable(MySqlParser::AlterTableContext *context) = 0;

    virtual std::any visitAlterTablespace(MySqlParser::AlterTablespaceContext *context) = 0;

    virtual std::any visitAlterView(MySqlParser::AlterViewContext *context) = 0;

    virtual std::any visitAlterByTableOption(MySqlParser::AlterByTableOptionContext *context) = 0;

    virtual std::any visitAlterByAddColumn(MySqlParser::AlterByAddColumnContext *context) = 0;

    virtual std::any visitAlterByAddColumns(MySqlParser::AlterByAddColumnsContext *context) = 0;

    virtual std::any visitAlterByAddIndex(MySqlParser::AlterByAddIndexContext *context) = 0;

    virtual std::any visitAlterByAddPrimaryKey(MySqlParser::AlterByAddPrimaryKeyContext *context) = 0;

    virtual std::any visitAlterByAddUniqueKey(MySqlParser::AlterByAddUniqueKeyContext *context) = 0;

    virtual std::any visitAlterByAddSpecialIndex(MySqlParser::AlterByAddSpecialIndexContext *context) = 0;

    virtual std::any visitAlterByAddForeignKey(MySqlParser::AlterByAddForeignKeyContext *context) = 0;

    virtual std::any visitAlterByAddCheckTableConstraint(MySqlParser::AlterByAddCheckTableConstraintContext *context) = 0;

    virtual std::any visitAlterByAlterCheckTableConstraint(MySqlParser::AlterByAlterCheckTableConstraintContext *context) = 0;

    virtual std::any visitAlterBySetAlgorithm(MySqlParser::AlterBySetAlgorithmContext *context) = 0;

    virtual std::any visitAlterByChangeDefault(MySqlParser::AlterByChangeDefaultContext *context) = 0;

    virtual std::any visitAlterByChangeColumn(MySqlParser::AlterByChangeColumnContext *context) = 0;

    virtual std::any visitAlterByRenameColumn(MySqlParser::AlterByRenameColumnContext *context) = 0;

    virtual std::any visitAlterByLock(MySqlParser::AlterByLockContext *context) = 0;

    virtual std::any visitAlterByModifyColumn(MySqlParser::AlterByModifyColumnContext *context) = 0;

    virtual std::any visitAlterByDropColumn(MySqlParser::AlterByDropColumnContext *context) = 0;

    virtual std::any visitAlterByDropConstraintCheck(MySqlParser::AlterByDropConstraintCheckContext *context) = 0;

    virtual std::any visitAlterByDropPrimaryKey(MySqlParser::AlterByDropPrimaryKeyContext *context) = 0;

    virtual std::any visitAlterByDropIndex(MySqlParser::AlterByDropIndexContext *context) = 0;

    virtual std::any visitAlterByRenameIndex(MySqlParser::AlterByRenameIndexContext *context) = 0;

    virtual std::any visitAlterByAlterColumnDefault(MySqlParser::AlterByAlterColumnDefaultContext *context) = 0;

    virtual std::any visitAlterByAlterIndexVisibility(MySqlParser::AlterByAlterIndexVisibilityContext *context) = 0;

    virtual std::any visitAlterByDropForeignKey(MySqlParser::AlterByDropForeignKeyContext *context) = 0;

    virtual std::any visitAlterByDisableKeys(MySqlParser::AlterByDisableKeysContext *context) = 0;

    virtual std::any visitAlterByEnableKeys(MySqlParser::AlterByEnableKeysContext *context) = 0;

    virtual std::any visitAlterByRename(MySqlParser::AlterByRenameContext *context) = 0;

    virtual std::any visitAlterByOrder(MySqlParser::AlterByOrderContext *context) = 0;

    virtual std::any visitAlterByConvertCharset(MySqlParser::AlterByConvertCharsetContext *context) = 0;

    virtual std::any visitAlterByDefaultCharset(MySqlParser::AlterByDefaultCharsetContext *context) = 0;

    virtual std::any visitAlterByDiscardTablespace(MySqlParser::AlterByDiscardTablespaceContext *context) = 0;

    virtual std::any visitAlterByImportTablespace(MySqlParser::AlterByImportTablespaceContext *context) = 0;

    virtual std::any visitAlterByForce(MySqlParser::AlterByForceContext *context) = 0;

    virtual std::any visitAlterByValidate(MySqlParser::AlterByValidateContext *context) = 0;

    virtual std::any visitAlterByAddDefinitions(MySqlParser::AlterByAddDefinitionsContext *context) = 0;

    virtual std::any visitAlterPartition(MySqlParser::AlterPartitionContext *context) = 0;

    virtual std::any visitAlterByAddPartition(MySqlParser::AlterByAddPartitionContext *context) = 0;

    virtual std::any visitAlterByDropPartition(MySqlParser::AlterByDropPartitionContext *context) = 0;

    virtual std::any visitAlterByDiscardPartition(MySqlParser::AlterByDiscardPartitionContext *context) = 0;

    virtual std::any visitAlterByImportPartition(MySqlParser::AlterByImportPartitionContext *context) = 0;

    virtual std::any visitAlterByTruncatePartition(MySqlParser::AlterByTruncatePartitionContext *context) = 0;

    virtual std::any visitAlterByCoalescePartition(MySqlParser::AlterByCoalescePartitionContext *context) = 0;

    virtual std::any visitAlterByReorganizePartition(MySqlParser::AlterByReorganizePartitionContext *context) = 0;

    virtual std::any visitAlterByExchangePartition(MySqlParser::AlterByExchangePartitionContext *context) = 0;

    virtual std::any visitAlterByAnalyzePartition(MySqlParser::AlterByAnalyzePartitionContext *context) = 0;

    virtual std::any visitAlterByCheckPartition(MySqlParser::AlterByCheckPartitionContext *context) = 0;

    virtual std::any visitAlterByOptimizePartition(MySqlParser::AlterByOptimizePartitionContext *context) = 0;

    virtual std::any visitAlterByRebuildPartition(MySqlParser::AlterByRebuildPartitionContext *context) = 0;

    virtual std::any visitAlterByRepairPartition(MySqlParser::AlterByRepairPartitionContext *context) = 0;

    virtual std::any visitAlterByRemovePartitioning(MySqlParser::AlterByRemovePartitioningContext *context) = 0;

    virtual std::any visitAlterByUpgradePartitioning(MySqlParser::AlterByUpgradePartitioningContext *context) = 0;

    virtual std::any visitDropDatabase(MySqlParser::DropDatabaseContext *context) = 0;

    virtual std::any visitDropEvent(MySqlParser::DropEventContext *context) = 0;

    virtual std::any visitDropIndex(MySqlParser::DropIndexContext *context) = 0;

    virtual std::any visitDropLogfileGroup(MySqlParser::DropLogfileGroupContext *context) = 0;

    virtual std::any visitDropProcedure(MySqlParser::DropProcedureContext *context) = 0;

    virtual std::any visitDropFunction(MySqlParser::DropFunctionContext *context) = 0;

    virtual std::any visitDropServer(MySqlParser::DropServerContext *context) = 0;

    virtual std::any visitDropTable(MySqlParser::DropTableContext *context) = 0;

    virtual std::any visitDropTablespace(MySqlParser::DropTablespaceContext *context) = 0;

    virtual std::any visitDropTrigger(MySqlParser::DropTriggerContext *context) = 0;

    virtual std::any visitDropView(MySqlParser::DropViewContext *context) = 0;

    virtual std::any visitDropRole(MySqlParser::DropRoleContext *context) = 0;

    virtual std::any visitSetRole(MySqlParser::SetRoleContext *context) = 0;

    virtual std::any visitRenameTable(MySqlParser::RenameTableContext *context) = 0;

    virtual std::any visitRenameTableClause(MySqlParser::RenameTableClauseContext *context) = 0;

    virtual std::any visitTruncateTable(MySqlParser::TruncateTableContext *context) = 0;

    virtual std::any visitCallStatement(MySqlParser::CallStatementContext *context) = 0;

    virtual std::any visitDeleteStatement(MySqlParser::DeleteStatementContext *context) = 0;

    virtual std::any visitDoStatement(MySqlParser::DoStatementContext *context) = 0;

    virtual std::any visitHandlerStatement(MySqlParser::HandlerStatementContext *context) = 0;

    virtual std::any visitInsertStatement(MySqlParser::InsertStatementContext *context) = 0;

    virtual std::any visitLoadDataStatement(MySqlParser::LoadDataStatementContext *context) = 0;

    virtual std::any visitLoadXmlStatement(MySqlParser::LoadXmlStatementContext *context) = 0;

    virtual std::any visitReplaceStatement(MySqlParser::ReplaceStatementContext *context) = 0;

    virtual std::any visitSimpleSelect(MySqlParser::SimpleSelectContext *context) = 0;

    virtual std::any visitParenthesisSelect(MySqlParser::ParenthesisSelectContext *context) = 0;

    virtual std::any visitUnionSelect(MySqlParser::UnionSelectContext *context) = 0;

    virtual std::any visitUnionParenthesisSelect(MySqlParser::UnionParenthesisSelectContext *context) = 0;

    virtual std::any visitWithLateralStatement(MySqlParser::WithLateralStatementContext *context) = 0;

    virtual std::any visitUpdateStatement(MySqlParser::UpdateStatementContext *context) = 0;

    virtual std::any visitValuesStatement(MySqlParser::ValuesStatementContext *context) = 0;

    virtual std::any visitInsertStatementValue(MySqlParser::InsertStatementValueContext *context) = 0;

    virtual std::any visitUpdatedElement(MySqlParser::UpdatedElementContext *context) = 0;

    virtual std::any visitAssignmentField(MySqlParser::AssignmentFieldContext *context) = 0;

    virtual std::any visitLockClause(MySqlParser::LockClauseContext *context) = 0;

    virtual std::any visitSingleDeleteStatement(MySqlParser::SingleDeleteStatementContext *context) = 0;

    virtual std::any visitMultipleDeleteStatement(MySqlParser::MultipleDeleteStatementContext *context) = 0;

    virtual std::any visitHandlerOpenStatement(MySqlParser::HandlerOpenStatementContext *context) = 0;

    virtual std::any visitHandlerReadIndexStatement(MySqlParser::HandlerReadIndexStatementContext *context) = 0;

    virtual std::any visitHandlerReadStatement(MySqlParser::HandlerReadStatementContext *context) = 0;

    virtual std::any visitHandlerCloseStatement(MySqlParser::HandlerCloseStatementContext *context) = 0;

    virtual std::any visitSingleUpdateStatement(MySqlParser::SingleUpdateStatementContext *context) = 0;

    virtual std::any visitMultipleUpdateStatement(MySqlParser::MultipleUpdateStatementContext *context) = 0;

    virtual std::any visitOrderByClause(MySqlParser::OrderByClauseContext *context) = 0;

    virtual std::any visitOrderByExpression(MySqlParser::OrderByExpressionContext *context) = 0;

    virtual std::any visitTableSources(MySqlParser::TableSourcesContext *context) = 0;

    virtual std::any visitTableSourceBase(MySqlParser::TableSourceBaseContext *context) = 0;

    virtual std::any visitTableSourceNested(MySqlParser::TableSourceNestedContext *context) = 0;

    virtual std::any visitTableJson(MySqlParser::TableJsonContext *context) = 0;

    virtual std::any visitAtomTableItem(MySqlParser::AtomTableItemContext *context) = 0;

    virtual std::any visitSubqueryTableItem(MySqlParser::SubqueryTableItemContext *context) = 0;

    virtual std::any visitTableSourcesItem(MySqlParser::TableSourcesItemContext *context) = 0;

    virtual std::any visitIndexHint(MySqlParser::IndexHintContext *context) = 0;

    virtual std::any visitIndexHintType(MySqlParser::IndexHintTypeContext *context) = 0;

    virtual std::any visitInnerJoin(MySqlParser::InnerJoinContext *context) = 0;

    virtual std::any visitStraightJoin(MySqlParser::StraightJoinContext *context) = 0;

    virtual std::any visitOuterJoin(MySqlParser::OuterJoinContext *context) = 0;

    virtual std::any visitNaturalJoin(MySqlParser::NaturalJoinContext *context) = 0;

    virtual std::any visitQueryExpression(MySqlParser::QueryExpressionContext *context) = 0;

    virtual std::any visitQueryExpressionNointo(MySqlParser::QueryExpressionNointoContext *context) = 0;

    virtual std::any visitQuerySpecification(MySqlParser::QuerySpecificationContext *context) = 0;

    virtual std::any visitQuerySpecificationNointo(MySqlParser::QuerySpecificationNointoContext *context) = 0;

    virtual std::any visitUnionParenthesis(MySqlParser::UnionParenthesisContext *context) = 0;

    virtual std::any visitUnionStatement(MySqlParser::UnionStatementContext *context) = 0;

    virtual std::any visitLateralStatement(MySqlParser::LateralStatementContext *context) = 0;

    virtual std::any visitJsonTable(MySqlParser::JsonTableContext *context) = 0;

    virtual std::any visitJsonColumnList(MySqlParser::JsonColumnListContext *context) = 0;

    virtual std::any visitJsonColumn(MySqlParser::JsonColumnContext *context) = 0;

    virtual std::any visitJsonOnEmpty(MySqlParser::JsonOnEmptyContext *context) = 0;

    virtual std::any visitJsonOnError(MySqlParser::JsonOnErrorContext *context) = 0;

    virtual std::any visitSelectSpec(MySqlParser::SelectSpecContext *context) = 0;

    virtual std::any visitSelectElements(MySqlParser::SelectElementsContext *context) = 0;

    virtual std::any visitSelectStarElement(MySqlParser::SelectStarElementContext *context) = 0;

    virtual std::any visitSelectColumnElement(MySqlParser::SelectColumnElementContext *context) = 0;

    virtual std::any visitSelectFunctionElement(MySqlParser::SelectFunctionElementContext *context) = 0;

    virtual std::any visitSelectExpressionElement(MySqlParser::SelectExpressionElementContext *context) = 0;

    virtual std::any visitSelectIntoVariables(MySqlParser::SelectIntoVariablesContext *context) = 0;

    virtual std::any visitSelectIntoDumpFile(MySqlParser::SelectIntoDumpFileContext *context) = 0;

    virtual std::any visitSelectIntoTextFile(MySqlParser::SelectIntoTextFileContext *context) = 0;

    virtual std::any visitSelectFieldsInto(MySqlParser::SelectFieldsIntoContext *context) = 0;

    virtual std::any visitSelectLinesInto(MySqlParser::SelectLinesIntoContext *context) = 0;

    virtual std::any visitFromClause(MySqlParser::FromClauseContext *context) = 0;

    virtual std::any visitGroupByClause(MySqlParser::GroupByClauseContext *context) = 0;

    virtual std::any visitHavingClause(MySqlParser::HavingClauseContext *context) = 0;

    virtual std::any visitWindowClause(MySqlParser::WindowClauseContext *context) = 0;

    virtual std::any visitGroupByItem(MySqlParser::GroupByItemContext *context) = 0;

    virtual std::any visitLimitClause(MySqlParser::LimitClauseContext *context) = 0;

    virtual std::any visitLimitClauseAtom(MySqlParser::LimitClauseAtomContext *context) = 0;

    virtual std::any visitStartTransaction(MySqlParser::StartTransactionContext *context) = 0;

    virtual std::any visitBeginWork(MySqlParser::BeginWorkContext *context) = 0;

    virtual std::any visitCommitWork(MySqlParser::CommitWorkContext *context) = 0;

    virtual std::any visitRollbackWork(MySqlParser::RollbackWorkContext *context) = 0;

    virtual std::any visitSavepointStatement(MySqlParser::SavepointStatementContext *context) = 0;

    virtual std::any visitRollbackStatement(MySqlParser::RollbackStatementContext *context) = 0;

    virtual std::any visitReleaseStatement(MySqlParser::ReleaseStatementContext *context) = 0;

    virtual std::any visitLockTables(MySqlParser::LockTablesContext *context) = 0;

    virtual std::any visitUnlockTables(MySqlParser::UnlockTablesContext *context) = 0;

    virtual std::any visitSetAutocommitStatement(MySqlParser::SetAutocommitStatementContext *context) = 0;

    virtual std::any visitSetTransactionStatement(MySqlParser::SetTransactionStatementContext *context) = 0;

    virtual std::any visitTransactionMode(MySqlParser::TransactionModeContext *context) = 0;

    virtual std::any visitLockTableElement(MySqlParser::LockTableElementContext *context) = 0;

    virtual std::any visitLockAction(MySqlParser::LockActionContext *context) = 0;

    virtual std::any visitTransactionOption(MySqlParser::TransactionOptionContext *context) = 0;

    virtual std::any visitTransactionLevel(MySqlParser::TransactionLevelContext *context) = 0;

    virtual std::any visitChangeMaster(MySqlParser::ChangeMasterContext *context) = 0;

    virtual std::any visitChangeReplicationFilter(MySqlParser::ChangeReplicationFilterContext *context) = 0;

    virtual std::any visitPurgeBinaryLogs(MySqlParser::PurgeBinaryLogsContext *context) = 0;

    virtual std::any visitResetMaster(MySqlParser::ResetMasterContext *context) = 0;

    virtual std::any visitResetSlave(MySqlParser::ResetSlaveContext *context) = 0;

    virtual std::any visitStartSlave(MySqlParser::StartSlaveContext *context) = 0;

    virtual std::any visitStopSlave(MySqlParser::StopSlaveContext *context) = 0;

    virtual std::any visitStartGroupReplication(MySqlParser::StartGroupReplicationContext *context) = 0;

    virtual std::any visitStopGroupReplication(MySqlParser::StopGroupReplicationContext *context) = 0;

    virtual std::any visitMasterStringOption(MySqlParser::MasterStringOptionContext *context) = 0;

    virtual std::any visitMasterDecimalOption(MySqlParser::MasterDecimalOptionContext *context) = 0;

    virtual std::any visitMasterBoolOption(MySqlParser::MasterBoolOptionContext *context) = 0;

    virtual std::any visitMasterRealOption(MySqlParser::MasterRealOptionContext *context) = 0;

    virtual std::any visitMasterUidListOption(MySqlParser::MasterUidListOptionContext *context) = 0;

    virtual std::any visitStringMasterOption(MySqlParser::StringMasterOptionContext *context) = 0;

    virtual std::any visitDecimalMasterOption(MySqlParser::DecimalMasterOptionContext *context) = 0;

    virtual std::any visitBoolMasterOption(MySqlParser::BoolMasterOptionContext *context) = 0;

    virtual std::any visitChannelOption(MySqlParser::ChannelOptionContext *context) = 0;

    virtual std::any visitDoDbReplication(MySqlParser::DoDbReplicationContext *context) = 0;

    virtual std::any visitIgnoreDbReplication(MySqlParser::IgnoreDbReplicationContext *context) = 0;

    virtual std::any visitDoTableReplication(MySqlParser::DoTableReplicationContext *context) = 0;

    virtual std::any visitIgnoreTableReplication(MySqlParser::IgnoreTableReplicationContext *context) = 0;

    virtual std::any visitWildDoTableReplication(MySqlParser::WildDoTableReplicationContext *context) = 0;

    virtual std::any visitWildIgnoreTableReplication(MySqlParser::WildIgnoreTableReplicationContext *context) = 0;

    virtual std::any visitRewriteDbReplication(MySqlParser::RewriteDbReplicationContext *context) = 0;

    virtual std::any visitTablePair(MySqlParser::TablePairContext *context) = 0;

    virtual std::any visitThreadType(MySqlParser::ThreadTypeContext *context) = 0;

    virtual std::any visitGtidsUntilOption(MySqlParser::GtidsUntilOptionContext *context) = 0;

    virtual std::any visitMasterLogUntilOption(MySqlParser::MasterLogUntilOptionContext *context) = 0;

    virtual std::any visitRelayLogUntilOption(MySqlParser::RelayLogUntilOptionContext *context) = 0;

    virtual std::any visitSqlGapsUntilOption(MySqlParser::SqlGapsUntilOptionContext *context) = 0;

    virtual std::any visitUserConnectionOption(MySqlParser::UserConnectionOptionContext *context) = 0;

    virtual std::any visitPasswordConnectionOption(MySqlParser::PasswordConnectionOptionContext *context) = 0;

    virtual std::any visitDefaultAuthConnectionOption(MySqlParser::DefaultAuthConnectionOptionContext *context) = 0;

    virtual std::any visitPluginDirConnectionOption(MySqlParser::PluginDirConnectionOptionContext *context) = 0;

    virtual std::any visitGtuidSet(MySqlParser::GtuidSetContext *context) = 0;

    virtual std::any visitXaStartTransaction(MySqlParser::XaStartTransactionContext *context) = 0;

    virtual std::any visitXaEndTransaction(MySqlParser::XaEndTransactionContext *context) = 0;

    virtual std::any visitXaPrepareStatement(MySqlParser::XaPrepareStatementContext *context) = 0;

    virtual std::any visitXaCommitWork(MySqlParser::XaCommitWorkContext *context) = 0;

    virtual std::any visitXaRollbackWork(MySqlParser::XaRollbackWorkContext *context) = 0;

    virtual std::any visitXaRecoverWork(MySqlParser::XaRecoverWorkContext *context) = 0;

    virtual std::any visitPrepareStatement(MySqlParser::PrepareStatementContext *context) = 0;

    virtual std::any visitExecuteStatement(MySqlParser::ExecuteStatementContext *context) = 0;

    virtual std::any visitDeallocatePrepare(MySqlParser::DeallocatePrepareContext *context) = 0;

    virtual std::any visitRoutineBody(MySqlParser::RoutineBodyContext *context) = 0;

    virtual std::any visitBlockStatement(MySqlParser::BlockStatementContext *context) = 0;

    virtual std::any visitCaseStatement(MySqlParser::CaseStatementContext *context) = 0;

    virtual std::any visitIfStatement(MySqlParser::IfStatementContext *context) = 0;

    virtual std::any visitIterateStatement(MySqlParser::IterateStatementContext *context) = 0;

    virtual std::any visitLeaveStatement(MySqlParser::LeaveStatementContext *context) = 0;

    virtual std::any visitLoopStatement(MySqlParser::LoopStatementContext *context) = 0;

    virtual std::any visitRepeatStatement(MySqlParser::RepeatStatementContext *context) = 0;

    virtual std::any visitReturnStatement(MySqlParser::ReturnStatementContext *context) = 0;

    virtual std::any visitWhileStatement(MySqlParser::WhileStatementContext *context) = 0;

    virtual std::any visitCloseCursor(MySqlParser::CloseCursorContext *context) = 0;

    virtual std::any visitFetchCursor(MySqlParser::FetchCursorContext *context) = 0;

    virtual std::any visitOpenCursor(MySqlParser::OpenCursorContext *context) = 0;

    virtual std::any visitDeclareVariable(MySqlParser::DeclareVariableContext *context) = 0;

    virtual std::any visitDeclareCondition(MySqlParser::DeclareConditionContext *context) = 0;

    virtual std::any visitDeclareCursor(MySqlParser::DeclareCursorContext *context) = 0;

    virtual std::any visitDeclareHandler(MySqlParser::DeclareHandlerContext *context) = 0;

    virtual std::any visitHandlerConditionCode(MySqlParser::HandlerConditionCodeContext *context) = 0;

    virtual std::any visitHandlerConditionState(MySqlParser::HandlerConditionStateContext *context) = 0;

    virtual std::any visitHandlerConditionName(MySqlParser::HandlerConditionNameContext *context) = 0;

    virtual std::any visitHandlerConditionWarning(MySqlParser::HandlerConditionWarningContext *context) = 0;

    virtual std::any visitHandlerConditionNotfound(MySqlParser::HandlerConditionNotfoundContext *context) = 0;

    virtual std::any visitHandlerConditionException(MySqlParser::HandlerConditionExceptionContext *context) = 0;

    virtual std::any visitProcedureSqlStatement(MySqlParser::ProcedureSqlStatementContext *context) = 0;

    virtual std::any visitCaseAlternative(MySqlParser::CaseAlternativeContext *context) = 0;

    virtual std::any visitElifAlternative(MySqlParser::ElifAlternativeContext *context) = 0;

    virtual std::any visitAlterUserMysqlV56(MySqlParser::AlterUserMysqlV56Context *context) = 0;

    virtual std::any visitAlterUserMysqlV80(MySqlParser::AlterUserMysqlV80Context *context) = 0;

    virtual std::any visitCreateUserMysqlV56(MySqlParser::CreateUserMysqlV56Context *context) = 0;

    virtual std::any visitCreateUserMysqlV80(MySqlParser::CreateUserMysqlV80Context *context) = 0;

    virtual std::any visitDropUser(MySqlParser::DropUserContext *context) = 0;

    virtual std::any visitGrantStatement(MySqlParser::GrantStatementContext *context) = 0;

    virtual std::any visitRoleOption(MySqlParser::RoleOptionContext *context) = 0;

    virtual std::any visitGrantProxy(MySqlParser::GrantProxyContext *context) = 0;

    virtual std::any visitRenameUser(MySqlParser::RenameUserContext *context) = 0;

    virtual std::any visitDetailRevoke(MySqlParser::DetailRevokeContext *context) = 0;

    virtual std::any visitShortRevoke(MySqlParser::ShortRevokeContext *context) = 0;

    virtual std::any visitRoleRevoke(MySqlParser::RoleRevokeContext *context) = 0;

    virtual std::any visitRevokeProxy(MySqlParser::RevokeProxyContext *context) = 0;

    virtual std::any visitSetPasswordStatement(MySqlParser::SetPasswordStatementContext *context) = 0;

    virtual std::any visitUserSpecification(MySqlParser::UserSpecificationContext *context) = 0;

    virtual std::any visitHashAuthOption(MySqlParser::HashAuthOptionContext *context) = 0;

    virtual std::any visitStringAuthOption(MySqlParser::StringAuthOptionContext *context) = 0;

    virtual std::any visitModuleAuthOption(MySqlParser::ModuleAuthOptionContext *context) = 0;

    virtual std::any visitSimpleAuthOption(MySqlParser::SimpleAuthOptionContext *context) = 0;

    virtual std::any visitModule(MySqlParser::ModuleContext *context) = 0;

    virtual std::any visitPasswordModuleOption(MySqlParser::PasswordModuleOptionContext *context) = 0;

    virtual std::any visitTlsOption(MySqlParser::TlsOptionContext *context) = 0;

    virtual std::any visitUserResourceOption(MySqlParser::UserResourceOptionContext *context) = 0;

    virtual std::any visitUserPasswordOption(MySqlParser::UserPasswordOptionContext *context) = 0;

    virtual std::any visitUserLockOption(MySqlParser::UserLockOptionContext *context) = 0;

    virtual std::any visitPrivelegeClause(MySqlParser::PrivelegeClauseContext *context) = 0;

    virtual std::any visitPrivilege(MySqlParser::PrivilegeContext *context) = 0;

    virtual std::any visitCurrentSchemaPriviLevel(MySqlParser::CurrentSchemaPriviLevelContext *context) = 0;

    virtual std::any visitGlobalPrivLevel(MySqlParser::GlobalPrivLevelContext *context) = 0;

    virtual std::any visitDefiniteSchemaPrivLevel(MySqlParser::DefiniteSchemaPrivLevelContext *context) = 0;

    virtual std::any visitDefiniteFullTablePrivLevel(MySqlParser::DefiniteFullTablePrivLevelContext *context) = 0;

    virtual std::any visitDefiniteFullTablePrivLevel2(MySqlParser::DefiniteFullTablePrivLevel2Context *context) = 0;

    virtual std::any visitDefiniteTablePrivLevel(MySqlParser::DefiniteTablePrivLevelContext *context) = 0;

    virtual std::any visitRenameUserClause(MySqlParser::RenameUserClauseContext *context) = 0;

    virtual std::any visitAnalyzeTable(MySqlParser::AnalyzeTableContext *context) = 0;

    virtual std::any visitCheckTable(MySqlParser::CheckTableContext *context) = 0;

    virtual std::any visitChecksumTable(MySqlParser::ChecksumTableContext *context) = 0;

    virtual std::any visitOptimizeTable(MySqlParser::OptimizeTableContext *context) = 0;

    virtual std::any visitRepairTable(MySqlParser::RepairTableContext *context) = 0;

    virtual std::any visitCheckTableOption(MySqlParser::CheckTableOptionContext *context) = 0;

    virtual std::any visitCreateUdfunction(MySqlParser::CreateUdfunctionContext *context) = 0;

    virtual std::any visitInstallPlugin(MySqlParser::InstallPluginContext *context) = 0;

    virtual std::any visitUninstallPlugin(MySqlParser::UninstallPluginContext *context) = 0;

    virtual std::any visitSetVariable(MySqlParser::SetVariableContext *context) = 0;

    virtual std::any visitSetCharset(MySqlParser::SetCharsetContext *context) = 0;

    virtual std::any visitSetNames(MySqlParser::SetNamesContext *context) = 0;

    virtual std::any visitSetPassword(MySqlParser::SetPasswordContext *context) = 0;

    virtual std::any visitSetTransaction(MySqlParser::SetTransactionContext *context) = 0;

    virtual std::any visitSetAutocommit(MySqlParser::SetAutocommitContext *context) = 0;

    virtual std::any visitSetNewValueInsideTrigger(MySqlParser::SetNewValueInsideTriggerContext *context) = 0;

    virtual std::any visitShowMasterLogs(MySqlParser::ShowMasterLogsContext *context) = 0;

    virtual std::any visitShowLogEvents(MySqlParser::ShowLogEventsContext *context) = 0;

    virtual std::any visitShowObjectFilter(MySqlParser::ShowObjectFilterContext *context) = 0;

    virtual std::any visitShowColumns(MySqlParser::ShowColumnsContext *context) = 0;

    virtual std::any visitShowCreateDb(MySqlParser::ShowCreateDbContext *context) = 0;

    virtual std::any visitShowCreateFullIdObject(MySqlParser::ShowCreateFullIdObjectContext *context) = 0;

    virtual std::any visitShowCreateUser(MySqlParser::ShowCreateUserContext *context) = 0;

    virtual std::any visitShowEngine(MySqlParser::ShowEngineContext *context) = 0;

    virtual std::any visitShowGlobalInfo(MySqlParser::ShowGlobalInfoContext *context) = 0;

    virtual std::any visitShowErrors(MySqlParser::ShowErrorsContext *context) = 0;

    virtual std::any visitShowCountErrors(MySqlParser::ShowCountErrorsContext *context) = 0;

    virtual std::any visitShowSchemaFilter(MySqlParser::ShowSchemaFilterContext *context) = 0;

    virtual std::any visitShowRoutine(MySqlParser::ShowRoutineContext *context) = 0;

    virtual std::any visitShowGrants(MySqlParser::ShowGrantsContext *context) = 0;

    virtual std::any visitShowIndexes(MySqlParser::ShowIndexesContext *context) = 0;

    virtual std::any visitShowOpenTables(MySqlParser::ShowOpenTablesContext *context) = 0;

    virtual std::any visitShowProfile(MySqlParser::ShowProfileContext *context) = 0;

    virtual std::any visitShowSlaveStatus(MySqlParser::ShowSlaveStatusContext *context) = 0;

    virtual std::any visitVariableClause(MySqlParser::VariableClauseContext *context) = 0;

    virtual std::any visitShowCommonEntity(MySqlParser::ShowCommonEntityContext *context) = 0;

    virtual std::any visitShowFilter(MySqlParser::ShowFilterContext *context) = 0;

    virtual std::any visitShowGlobalInfoClause(MySqlParser::ShowGlobalInfoClauseContext *context) = 0;

    virtual std::any visitShowSchemaEntity(MySqlParser::ShowSchemaEntityContext *context) = 0;

    virtual std::any visitShowProfileType(MySqlParser::ShowProfileTypeContext *context) = 0;

    virtual std::any visitBinlogStatement(MySqlParser::BinlogStatementContext *context) = 0;

    virtual std::any visitCacheIndexStatement(MySqlParser::CacheIndexStatementContext *context) = 0;

    virtual std::any visitFlushStatement(MySqlParser::FlushStatementContext *context) = 0;

    virtual std::any visitKillStatement(MySqlParser::KillStatementContext *context) = 0;

    virtual std::any visitLoadIndexIntoCache(MySqlParser::LoadIndexIntoCacheContext *context) = 0;

    virtual std::any visitResetStatement(MySqlParser::ResetStatementContext *context) = 0;

    virtual std::any visitShutdownStatement(MySqlParser::ShutdownStatementContext *context) = 0;

    virtual std::any visitTableIndexes(MySqlParser::TableIndexesContext *context) = 0;

    virtual std::any visitSimpleFlushOption(MySqlParser::SimpleFlushOptionContext *context) = 0;

    virtual std::any visitChannelFlushOption(MySqlParser::ChannelFlushOptionContext *context) = 0;

    virtual std::any visitTableFlushOption(MySqlParser::TableFlushOptionContext *context) = 0;

    virtual std::any visitFlushTableOption(MySqlParser::FlushTableOptionContext *context) = 0;

    virtual std::any visitLoadedTableIndexes(MySqlParser::LoadedTableIndexesContext *context) = 0;

    virtual std::any visitSimpleDescribeStatement(MySqlParser::SimpleDescribeStatementContext *context) = 0;

    virtual std::any visitFullDescribeStatement(MySqlParser::FullDescribeStatementContext *context) = 0;

    virtual std::any visitHelpStatement(MySqlParser::HelpStatementContext *context) = 0;

    virtual std::any visitUseStatement(MySqlParser::UseStatementContext *context) = 0;

    virtual std::any visitSignalStatement(MySqlParser::SignalStatementContext *context) = 0;

    virtual std::any visitResignalStatement(MySqlParser::ResignalStatementContext *context) = 0;

    virtual std::any visitSignalConditionInformation(MySqlParser::SignalConditionInformationContext *context) = 0;

    virtual std::any visitWithStatement(MySqlParser::WithStatementContext *context) = 0;

    virtual std::any visitTableStatement(MySqlParser::TableStatementContext *context) = 0;

    virtual std::any visitDiagnosticsStatement(MySqlParser::DiagnosticsStatementContext *context) = 0;

    virtual std::any visitDiagnosticsConditionInformationName(MySqlParser::DiagnosticsConditionInformationNameContext *context) = 0;

    virtual std::any visitDescribeStatements(MySqlParser::DescribeStatementsContext *context) = 0;

    virtual std::any visitDescribeConnection(MySqlParser::DescribeConnectionContext *context) = 0;

    virtual std::any visitFullId(MySqlParser::FullIdContext *context) = 0;

    virtual std::any visitTableName(MySqlParser::TableNameContext *context) = 0;

    virtual std::any visitRoleName(MySqlParser::RoleNameContext *context) = 0;

    virtual std::any visitFullColumnName(MySqlParser::FullColumnNameContext *context) = 0;

    virtual std::any visitIndexColumnName(MySqlParser::IndexColumnNameContext *context) = 0;

    virtual std::any visitUserName(MySqlParser::UserNameContext *context) = 0;

    virtual std::any visitMysqlVariable(MySqlParser::MysqlVariableContext *context) = 0;

    virtual std::any visitCharsetName(MySqlParser::CharsetNameContext *context) = 0;

    virtual std::any visitCollationName(MySqlParser::CollationNameContext *context) = 0;

    virtual std::any visitEngineName(MySqlParser::EngineNameContext *context) = 0;

    virtual std::any visitEngineNameBase(MySqlParser::EngineNameBaseContext *context) = 0;

    virtual std::any visitUuidSet(MySqlParser::UuidSetContext *context) = 0;

    virtual std::any visitXid(MySqlParser::XidContext *context) = 0;

    virtual std::any visitXuidStringId(MySqlParser::XuidStringIdContext *context) = 0;

    virtual std::any visitAuthPlugin(MySqlParser::AuthPluginContext *context) = 0;

    virtual std::any visitUid(MySqlParser::UidContext *context) = 0;

    virtual std::any visitSimpleId(MySqlParser::SimpleIdContext *context) = 0;

    virtual std::any visitDottedId(MySqlParser::DottedIdContext *context) = 0;

    virtual std::any visitDecimalLiteral(MySqlParser::DecimalLiteralContext *context) = 0;

    virtual std::any visitFileSizeLiteral(MySqlParser::FileSizeLiteralContext *context) = 0;

    virtual std::any visitStringLiteral(MySqlParser::StringLiteralContext *context) = 0;

    virtual std::any visitBooleanLiteral(MySqlParser::BooleanLiteralContext *context) = 0;

    virtual std::any visitHexadecimalLiteral(MySqlParser::HexadecimalLiteralContext *context) = 0;

    virtual std::any visitNullNotnull(MySqlParser::NullNotnullContext *context) = 0;

    virtual std::any visitConstant(MySqlParser::ConstantContext *context) = 0;

    virtual std::any visitStringDataType(MySqlParser::StringDataTypeContext *context) = 0;

    virtual std::any visitNationalVaryingStringDataType(MySqlParser::NationalVaryingStringDataTypeContext *context) = 0;

    virtual std::any visitNationalStringDataType(MySqlParser::NationalStringDataTypeContext *context) = 0;

    virtual std::any visitDimensionDataType(MySqlParser::DimensionDataTypeContext *context) = 0;

    virtual std::any visitSimpleDataType(MySqlParser::SimpleDataTypeContext *context) = 0;

    virtual std::any visitCollectionDataType(MySqlParser::CollectionDataTypeContext *context) = 0;

    virtual std::any visitSpatialDataType(MySqlParser::SpatialDataTypeContext *context) = 0;

    virtual std::any visitLongVarcharDataType(MySqlParser::LongVarcharDataTypeContext *context) = 0;

    virtual std::any visitLongVarbinaryDataType(MySqlParser::LongVarbinaryDataTypeContext *context) = 0;

    virtual std::any visitCollectionOptions(MySqlParser::CollectionOptionsContext *context) = 0;

    virtual std::any visitConvertedDataType(MySqlParser::ConvertedDataTypeContext *context) = 0;

    virtual std::any visitLengthOneDimension(MySqlParser::LengthOneDimensionContext *context) = 0;

    virtual std::any visitLengthTwoDimension(MySqlParser::LengthTwoDimensionContext *context) = 0;

    virtual std::any visitLengthTwoOptionalDimension(MySqlParser::LengthTwoOptionalDimensionContext *context) = 0;

    virtual std::any visitUidList(MySqlParser::UidListContext *context) = 0;

    virtual std::any visitFullColumnNameList(MySqlParser::FullColumnNameListContext *context) = 0;

    virtual std::any visitTables(MySqlParser::TablesContext *context) = 0;

    virtual std::any visitIndexColumnNames(MySqlParser::IndexColumnNamesContext *context) = 0;

    virtual std::any visitExpressions(MySqlParser::ExpressionsContext *context) = 0;

    virtual std::any visitExpressionsWithDefaults(MySqlParser::ExpressionsWithDefaultsContext *context) = 0;

    virtual std::any visitConstants(MySqlParser::ConstantsContext *context) = 0;

    virtual std::any visitSimpleStrings(MySqlParser::SimpleStringsContext *context) = 0;

    virtual std::any visitUserVariables(MySqlParser::UserVariablesContext *context) = 0;

    virtual std::any visitDefaultValue(MySqlParser::DefaultValueContext *context) = 0;

    virtual std::any visitCurrentTimestamp(MySqlParser::CurrentTimestampContext *context) = 0;

    virtual std::any visitExpressionOrDefault(MySqlParser::ExpressionOrDefaultContext *context) = 0;

    virtual std::any visitIfExists(MySqlParser::IfExistsContext *context) = 0;

    virtual std::any visitIfNotExists(MySqlParser::IfNotExistsContext *context) = 0;

    virtual std::any visitOrReplace(MySqlParser::OrReplaceContext *context) = 0;

    virtual std::any visitWaitNowaitClause(MySqlParser::WaitNowaitClauseContext *context) = 0;

    virtual std::any visitSpecificFunctionCall(MySqlParser::SpecificFunctionCallContext *context) = 0;

    virtual std::any visitAggregateFunctionCall(MySqlParser::AggregateFunctionCallContext *context) = 0;

    virtual std::any visitNonAggregateFunctionCall(MySqlParser::NonAggregateFunctionCallContext *context) = 0;

    virtual std::any visitScalarFunctionCall(MySqlParser::ScalarFunctionCallContext *context) = 0;

    virtual std::any visitUdfFunctionCall(MySqlParser::UdfFunctionCallContext *context) = 0;

    virtual std::any visitPasswordFunctionCall(MySqlParser::PasswordFunctionCallContext *context) = 0;

    virtual std::any visitSimpleFunctionCall(MySqlParser::SimpleFunctionCallContext *context) = 0;

    virtual std::any visitDataTypeFunctionCall(MySqlParser::DataTypeFunctionCallContext *context) = 0;

    virtual std::any visitValuesFunctionCall(MySqlParser::ValuesFunctionCallContext *context) = 0;

    virtual std::any visitCaseExpressionFunctionCall(MySqlParser::CaseExpressionFunctionCallContext *context) = 0;

    virtual std::any visitCaseFunctionCall(MySqlParser::CaseFunctionCallContext *context) = 0;

    virtual std::any visitCharFunctionCall(MySqlParser::CharFunctionCallContext *context) = 0;

    virtual std::any visitPositionFunctionCall(MySqlParser::PositionFunctionCallContext *context) = 0;

    virtual std::any visitSubstrFunctionCall(MySqlParser::SubstrFunctionCallContext *context) = 0;

    virtual std::any visitTrimFunctionCall(MySqlParser::TrimFunctionCallContext *context) = 0;

    virtual std::any visitWeightFunctionCall(MySqlParser::WeightFunctionCallContext *context) = 0;

    virtual std::any visitExtractFunctionCall(MySqlParser::ExtractFunctionCallContext *context) = 0;

    virtual std::any visitGetFormatFunctionCall(MySqlParser::GetFormatFunctionCallContext *context) = 0;

    virtual std::any visitJsonValueFunctionCall(MySqlParser::JsonValueFunctionCallContext *context) = 0;

    virtual std::any visitCaseFuncAlternative(MySqlParser::CaseFuncAlternativeContext *context) = 0;

    virtual std::any visitLevelWeightList(MySqlParser::LevelWeightListContext *context) = 0;

    virtual std::any visitLevelWeightRange(MySqlParser::LevelWeightRangeContext *context) = 0;

    virtual std::any visitLevelInWeightListElement(MySqlParser::LevelInWeightListElementContext *context) = 0;

    virtual std::any visitAggregateWindowedFunction(MySqlParser::AggregateWindowedFunctionContext *context) = 0;

    virtual std::any visitNonAggregateWindowedFunction(MySqlParser::NonAggregateWindowedFunctionContext *context) = 0;

    virtual std::any visitOverClause(MySqlParser::OverClauseContext *context) = 0;

    virtual std::any visitWindowSpec(MySqlParser::WindowSpecContext *context) = 0;

    virtual std::any visitWindowName(MySqlParser::WindowNameContext *context) = 0;

    virtual std::any visitFrameClause(MySqlParser::FrameClauseContext *context) = 0;

    virtual std::any visitFrameUnits(MySqlParser::FrameUnitsContext *context) = 0;

    virtual std::any visitFrameExtent(MySqlParser::FrameExtentContext *context) = 0;

    virtual std::any visitFrameBetween(MySqlParser::FrameBetweenContext *context) = 0;

    virtual std::any visitFrameRange(MySqlParser::FrameRangeContext *context) = 0;

    virtual std::any visitPartitionClause(MySqlParser::PartitionClauseContext *context) = 0;

    virtual std::any visitScalarFunctionName(MySqlParser::ScalarFunctionNameContext *context) = 0;

    virtual std::any visitPasswordFunctionClause(MySqlParser::PasswordFunctionClauseContext *context) = 0;

    virtual std::any visitFunctionArgs(MySqlParser::FunctionArgsContext *context) = 0;

    virtual std::any visitFunctionArg(MySqlParser::FunctionArgContext *context) = 0;

    virtual std::any visitIsExpression(MySqlParser::IsExpressionContext *context) = 0;

    virtual std::any visitNotExpression(MySqlParser::NotExpressionContext *context) = 0;

    virtual std::any visitLogicalExpression(MySqlParser::LogicalExpressionContext *context) = 0;

    virtual std::any visitPredicateExpression(MySqlParser::PredicateExpressionContext *context) = 0;

    virtual std::any visitSoundsLikePredicate(MySqlParser::SoundsLikePredicateContext *context) = 0;

    virtual std::any visitExpressionAtomPredicate(MySqlParser::ExpressionAtomPredicateContext *context) = 0;

    virtual std::any visitSubqueryComparisonPredicate(MySqlParser::SubqueryComparisonPredicateContext *context) = 0;

    virtual std::any visitJsonMemberOfPredicate(MySqlParser::JsonMemberOfPredicateContext *context) = 0;

    virtual std::any visitBinaryComparisonPredicate(MySqlParser::BinaryComparisonPredicateContext *context) = 0;

    virtual std::any visitInPredicate(MySqlParser::InPredicateContext *context) = 0;

    virtual std::any visitBetweenPredicate(MySqlParser::BetweenPredicateContext *context) = 0;

    virtual std::any visitIsNullPredicate(MySqlParser::IsNullPredicateContext *context) = 0;

    virtual std::any visitLikePredicate(MySqlParser::LikePredicateContext *context) = 0;

    virtual std::any visitRegexpPredicate(MySqlParser::RegexpPredicateContext *context) = 0;

    virtual std::any visitUnaryExpressionAtom(MySqlParser::UnaryExpressionAtomContext *context) = 0;

    virtual std::any visitCollateExpressionAtom(MySqlParser::CollateExpressionAtomContext *context) = 0;

    virtual std::any visitMysqlVariableExpressionAtom(MySqlParser::MysqlVariableExpressionAtomContext *context) = 0;

    virtual std::any visitNestedExpressionAtom(MySqlParser::NestedExpressionAtomContext *context) = 0;

    virtual std::any visitNestedRowExpressionAtom(MySqlParser::NestedRowExpressionAtomContext *context) = 0;

    virtual std::any visitMathExpressionAtom(MySqlParser::MathExpressionAtomContext *context) = 0;

    virtual std::any visitExistsExpressionAtom(MySqlParser::ExistsExpressionAtomContext *context) = 0;

    virtual std::any visitIntervalExpressionAtom(MySqlParser::IntervalExpressionAtomContext *context) = 0;

    virtual std::any visitJsonExpressionAtom(MySqlParser::JsonExpressionAtomContext *context) = 0;

    virtual std::any visitSubqueryExpressionAtom(MySqlParser::SubqueryExpressionAtomContext *context) = 0;

    virtual std::any visitConstantExpressionAtom(MySqlParser::ConstantExpressionAtomContext *context) = 0;

    virtual std::any visitFunctionCallExpressionAtom(MySqlParser::FunctionCallExpressionAtomContext *context) = 0;

    virtual std::any visitBinaryExpressionAtom(MySqlParser::BinaryExpressionAtomContext *context) = 0;

    virtual std::any visitFullColumnNameExpressionAtom(MySqlParser::FullColumnNameExpressionAtomContext *context) = 0;

    virtual std::any visitBitExpressionAtom(MySqlParser::BitExpressionAtomContext *context) = 0;

    virtual std::any visitUnaryOperator(MySqlParser::UnaryOperatorContext *context) = 0;

    virtual std::any visitComparisonOperator(MySqlParser::ComparisonOperatorContext *context) = 0;

    virtual std::any visitLogicalOperator(MySqlParser::LogicalOperatorContext *context) = 0;

    virtual std::any visitBitOperator(MySqlParser::BitOperatorContext *context) = 0;

    virtual std::any visitMathOperator(MySqlParser::MathOperatorContext *context) = 0;

    virtual std::any visitJsonOperator(MySqlParser::JsonOperatorContext *context) = 0;

    virtual std::any visitCharsetNameBase(MySqlParser::CharsetNameBaseContext *context) = 0;

    virtual std::any visitTransactionLevelBase(MySqlParser::TransactionLevelBaseContext *context) = 0;

    virtual std::any visitPrivilegesBase(MySqlParser::PrivilegesBaseContext *context) = 0;

    virtual std::any visitIntervalTypeBase(MySqlParser::IntervalTypeBaseContext *context) = 0;

    virtual std::any visitDataTypeBase(MySqlParser::DataTypeBaseContext *context) = 0;

    virtual std::any visitKeywordsCanBeId(MySqlParser::KeywordsCanBeIdContext *context) = 0;

    virtual std::any visitFunctionNameBase(MySqlParser::FunctionNameBaseContext *context) = 0;


};

}  // namespace antlrcpptest
