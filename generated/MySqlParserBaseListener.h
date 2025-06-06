
// Generated from MySqlParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "MySqlParserListener.h"


namespace antlrcpptest {

/**
 * This class provides an empty implementation of MySqlParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  MySqlParserBaseListener : public MySqlParserListener {
public:

  virtual void enterRoot(MySqlParser::RootContext * /*ctx*/) override { }
  virtual void exitRoot(MySqlParser::RootContext * /*ctx*/) override { }

  virtual void enterSqlStatements(MySqlParser::SqlStatementsContext * /*ctx*/) override { }
  virtual void exitSqlStatements(MySqlParser::SqlStatementsContext * /*ctx*/) override { }

  virtual void enterSqlStatement(MySqlParser::SqlStatementContext * /*ctx*/) override { }
  virtual void exitSqlStatement(MySqlParser::SqlStatementContext * /*ctx*/) override { }

  virtual void enterEmptyStatement_(MySqlParser::EmptyStatement_Context * /*ctx*/) override { }
  virtual void exitEmptyStatement_(MySqlParser::EmptyStatement_Context * /*ctx*/) override { }

  virtual void enterDdlStatement(MySqlParser::DdlStatementContext * /*ctx*/) override { }
  virtual void exitDdlStatement(MySqlParser::DdlStatementContext * /*ctx*/) override { }

  virtual void enterDmlStatement(MySqlParser::DmlStatementContext * /*ctx*/) override { }
  virtual void exitDmlStatement(MySqlParser::DmlStatementContext * /*ctx*/) override { }

  virtual void enterTransactionStatement(MySqlParser::TransactionStatementContext * /*ctx*/) override { }
  virtual void exitTransactionStatement(MySqlParser::TransactionStatementContext * /*ctx*/) override { }

  virtual void enterReplicationStatement(MySqlParser::ReplicationStatementContext * /*ctx*/) override { }
  virtual void exitReplicationStatement(MySqlParser::ReplicationStatementContext * /*ctx*/) override { }

  virtual void enterPreparedStatement(MySqlParser::PreparedStatementContext * /*ctx*/) override { }
  virtual void exitPreparedStatement(MySqlParser::PreparedStatementContext * /*ctx*/) override { }

  virtual void enterCompoundStatement(MySqlParser::CompoundStatementContext * /*ctx*/) override { }
  virtual void exitCompoundStatement(MySqlParser::CompoundStatementContext * /*ctx*/) override { }

  virtual void enterAdministrationStatement(MySqlParser::AdministrationStatementContext * /*ctx*/) override { }
  virtual void exitAdministrationStatement(MySqlParser::AdministrationStatementContext * /*ctx*/) override { }

  virtual void enterUtilityStatement(MySqlParser::UtilityStatementContext * /*ctx*/) override { }
  virtual void exitUtilityStatement(MySqlParser::UtilityStatementContext * /*ctx*/) override { }

  virtual void enterCreateDatabase(MySqlParser::CreateDatabaseContext * /*ctx*/) override { }
  virtual void exitCreateDatabase(MySqlParser::CreateDatabaseContext * /*ctx*/) override { }

  virtual void enterCreateEvent(MySqlParser::CreateEventContext * /*ctx*/) override { }
  virtual void exitCreateEvent(MySqlParser::CreateEventContext * /*ctx*/) override { }

  virtual void enterCreateIndex(MySqlParser::CreateIndexContext * /*ctx*/) override { }
  virtual void exitCreateIndex(MySqlParser::CreateIndexContext * /*ctx*/) override { }

  virtual void enterCreateLogfileGroup(MySqlParser::CreateLogfileGroupContext * /*ctx*/) override { }
  virtual void exitCreateLogfileGroup(MySqlParser::CreateLogfileGroupContext * /*ctx*/) override { }

  virtual void enterCreateProcedure(MySqlParser::CreateProcedureContext * /*ctx*/) override { }
  virtual void exitCreateProcedure(MySqlParser::CreateProcedureContext * /*ctx*/) override { }

  virtual void enterCreateFunction(MySqlParser::CreateFunctionContext * /*ctx*/) override { }
  virtual void exitCreateFunction(MySqlParser::CreateFunctionContext * /*ctx*/) override { }

  virtual void enterCreateRole(MySqlParser::CreateRoleContext * /*ctx*/) override { }
  virtual void exitCreateRole(MySqlParser::CreateRoleContext * /*ctx*/) override { }

  virtual void enterCreateServer(MySqlParser::CreateServerContext * /*ctx*/) override { }
  virtual void exitCreateServer(MySqlParser::CreateServerContext * /*ctx*/) override { }

  virtual void enterCopyCreateTable(MySqlParser::CopyCreateTableContext * /*ctx*/) override { }
  virtual void exitCopyCreateTable(MySqlParser::CopyCreateTableContext * /*ctx*/) override { }

  virtual void enterQueryCreateTable(MySqlParser::QueryCreateTableContext * /*ctx*/) override { }
  virtual void exitQueryCreateTable(MySqlParser::QueryCreateTableContext * /*ctx*/) override { }

  virtual void enterColumnCreateTable(MySqlParser::ColumnCreateTableContext * /*ctx*/) override { }
  virtual void exitColumnCreateTable(MySqlParser::ColumnCreateTableContext * /*ctx*/) override { }

  virtual void enterCreateTablespaceInnodb(MySqlParser::CreateTablespaceInnodbContext * /*ctx*/) override { }
  virtual void exitCreateTablespaceInnodb(MySqlParser::CreateTablespaceInnodbContext * /*ctx*/) override { }

  virtual void enterCreateTablespaceNdb(MySqlParser::CreateTablespaceNdbContext * /*ctx*/) override { }
  virtual void exitCreateTablespaceNdb(MySqlParser::CreateTablespaceNdbContext * /*ctx*/) override { }

  virtual void enterCreateTrigger(MySqlParser::CreateTriggerContext * /*ctx*/) override { }
  virtual void exitCreateTrigger(MySqlParser::CreateTriggerContext * /*ctx*/) override { }

  virtual void enterWithClause(MySqlParser::WithClauseContext * /*ctx*/) override { }
  virtual void exitWithClause(MySqlParser::WithClauseContext * /*ctx*/) override { }

  virtual void enterCommonTableExpressions(MySqlParser::CommonTableExpressionsContext * /*ctx*/) override { }
  virtual void exitCommonTableExpressions(MySqlParser::CommonTableExpressionsContext * /*ctx*/) override { }

  virtual void enterCteName(MySqlParser::CteNameContext * /*ctx*/) override { }
  virtual void exitCteName(MySqlParser::CteNameContext * /*ctx*/) override { }

  virtual void enterCteColumnName(MySqlParser::CteColumnNameContext * /*ctx*/) override { }
  virtual void exitCteColumnName(MySqlParser::CteColumnNameContext * /*ctx*/) override { }

  virtual void enterCreateView(MySqlParser::CreateViewContext * /*ctx*/) override { }
  virtual void exitCreateView(MySqlParser::CreateViewContext * /*ctx*/) override { }

  virtual void enterCreateDatabaseOption(MySqlParser::CreateDatabaseOptionContext * /*ctx*/) override { }
  virtual void exitCreateDatabaseOption(MySqlParser::CreateDatabaseOptionContext * /*ctx*/) override { }

  virtual void enterCharSet(MySqlParser::CharSetContext * /*ctx*/) override { }
  virtual void exitCharSet(MySqlParser::CharSetContext * /*ctx*/) override { }

  virtual void enterOwnerStatement(MySqlParser::OwnerStatementContext * /*ctx*/) override { }
  virtual void exitOwnerStatement(MySqlParser::OwnerStatementContext * /*ctx*/) override { }

  virtual void enterPreciseSchedule(MySqlParser::PreciseScheduleContext * /*ctx*/) override { }
  virtual void exitPreciseSchedule(MySqlParser::PreciseScheduleContext * /*ctx*/) override { }

  virtual void enterIntervalSchedule(MySqlParser::IntervalScheduleContext * /*ctx*/) override { }
  virtual void exitIntervalSchedule(MySqlParser::IntervalScheduleContext * /*ctx*/) override { }

  virtual void enterTimestampValue(MySqlParser::TimestampValueContext * /*ctx*/) override { }
  virtual void exitTimestampValue(MySqlParser::TimestampValueContext * /*ctx*/) override { }

  virtual void enterIntervalExpr(MySqlParser::IntervalExprContext * /*ctx*/) override { }
  virtual void exitIntervalExpr(MySqlParser::IntervalExprContext * /*ctx*/) override { }

  virtual void enterIntervalType(MySqlParser::IntervalTypeContext * /*ctx*/) override { }
  virtual void exitIntervalType(MySqlParser::IntervalTypeContext * /*ctx*/) override { }

  virtual void enterEnableType(MySqlParser::EnableTypeContext * /*ctx*/) override { }
  virtual void exitEnableType(MySqlParser::EnableTypeContext * /*ctx*/) override { }

  virtual void enterIndexType(MySqlParser::IndexTypeContext * /*ctx*/) override { }
  virtual void exitIndexType(MySqlParser::IndexTypeContext * /*ctx*/) override { }

  virtual void enterIndexOption(MySqlParser::IndexOptionContext * /*ctx*/) override { }
  virtual void exitIndexOption(MySqlParser::IndexOptionContext * /*ctx*/) override { }

  virtual void enterProcedureParameter(MySqlParser::ProcedureParameterContext * /*ctx*/) override { }
  virtual void exitProcedureParameter(MySqlParser::ProcedureParameterContext * /*ctx*/) override { }

  virtual void enterFunctionParameter(MySqlParser::FunctionParameterContext * /*ctx*/) override { }
  virtual void exitFunctionParameter(MySqlParser::FunctionParameterContext * /*ctx*/) override { }

  virtual void enterRoutineComment(MySqlParser::RoutineCommentContext * /*ctx*/) override { }
  virtual void exitRoutineComment(MySqlParser::RoutineCommentContext * /*ctx*/) override { }

  virtual void enterRoutineLanguage(MySqlParser::RoutineLanguageContext * /*ctx*/) override { }
  virtual void exitRoutineLanguage(MySqlParser::RoutineLanguageContext * /*ctx*/) override { }

  virtual void enterRoutineBehavior(MySqlParser::RoutineBehaviorContext * /*ctx*/) override { }
  virtual void exitRoutineBehavior(MySqlParser::RoutineBehaviorContext * /*ctx*/) override { }

  virtual void enterRoutineData(MySqlParser::RoutineDataContext * /*ctx*/) override { }
  virtual void exitRoutineData(MySqlParser::RoutineDataContext * /*ctx*/) override { }

  virtual void enterRoutineSecurity(MySqlParser::RoutineSecurityContext * /*ctx*/) override { }
  virtual void exitRoutineSecurity(MySqlParser::RoutineSecurityContext * /*ctx*/) override { }

  virtual void enterServerOption(MySqlParser::ServerOptionContext * /*ctx*/) override { }
  virtual void exitServerOption(MySqlParser::ServerOptionContext * /*ctx*/) override { }

  virtual void enterCreateDefinitions(MySqlParser::CreateDefinitionsContext * /*ctx*/) override { }
  virtual void exitCreateDefinitions(MySqlParser::CreateDefinitionsContext * /*ctx*/) override { }

  virtual void enterColumnDeclaration(MySqlParser::ColumnDeclarationContext * /*ctx*/) override { }
  virtual void exitColumnDeclaration(MySqlParser::ColumnDeclarationContext * /*ctx*/) override { }

  virtual void enterConstraintDeclaration(MySqlParser::ConstraintDeclarationContext * /*ctx*/) override { }
  virtual void exitConstraintDeclaration(MySqlParser::ConstraintDeclarationContext * /*ctx*/) override { }

  virtual void enterIndexDeclaration(MySqlParser::IndexDeclarationContext * /*ctx*/) override { }
  virtual void exitIndexDeclaration(MySqlParser::IndexDeclarationContext * /*ctx*/) override { }

  virtual void enterColumnDefinition(MySqlParser::ColumnDefinitionContext * /*ctx*/) override { }
  virtual void exitColumnDefinition(MySqlParser::ColumnDefinitionContext * /*ctx*/) override { }

  virtual void enterNullColumnConstraint(MySqlParser::NullColumnConstraintContext * /*ctx*/) override { }
  virtual void exitNullColumnConstraint(MySqlParser::NullColumnConstraintContext * /*ctx*/) override { }

  virtual void enterDefaultColumnConstraint(MySqlParser::DefaultColumnConstraintContext * /*ctx*/) override { }
  virtual void exitDefaultColumnConstraint(MySqlParser::DefaultColumnConstraintContext * /*ctx*/) override { }

  virtual void enterVisibilityColumnConstraint(MySqlParser::VisibilityColumnConstraintContext * /*ctx*/) override { }
  virtual void exitVisibilityColumnConstraint(MySqlParser::VisibilityColumnConstraintContext * /*ctx*/) override { }

  virtual void enterInvisibilityColumnConstraint(MySqlParser::InvisibilityColumnConstraintContext * /*ctx*/) override { }
  virtual void exitInvisibilityColumnConstraint(MySqlParser::InvisibilityColumnConstraintContext * /*ctx*/) override { }

  virtual void enterAutoIncrementColumnConstraint(MySqlParser::AutoIncrementColumnConstraintContext * /*ctx*/) override { }
  virtual void exitAutoIncrementColumnConstraint(MySqlParser::AutoIncrementColumnConstraintContext * /*ctx*/) override { }

  virtual void enterPrimaryKeyColumnConstraint(MySqlParser::PrimaryKeyColumnConstraintContext * /*ctx*/) override { }
  virtual void exitPrimaryKeyColumnConstraint(MySqlParser::PrimaryKeyColumnConstraintContext * /*ctx*/) override { }

  virtual void enterUniqueKeyColumnConstraint(MySqlParser::UniqueKeyColumnConstraintContext * /*ctx*/) override { }
  virtual void exitUniqueKeyColumnConstraint(MySqlParser::UniqueKeyColumnConstraintContext * /*ctx*/) override { }

  virtual void enterCommentColumnConstraint(MySqlParser::CommentColumnConstraintContext * /*ctx*/) override { }
  virtual void exitCommentColumnConstraint(MySqlParser::CommentColumnConstraintContext * /*ctx*/) override { }

  virtual void enterFormatColumnConstraint(MySqlParser::FormatColumnConstraintContext * /*ctx*/) override { }
  virtual void exitFormatColumnConstraint(MySqlParser::FormatColumnConstraintContext * /*ctx*/) override { }

  virtual void enterStorageColumnConstraint(MySqlParser::StorageColumnConstraintContext * /*ctx*/) override { }
  virtual void exitStorageColumnConstraint(MySqlParser::StorageColumnConstraintContext * /*ctx*/) override { }

  virtual void enterReferenceColumnConstraint(MySqlParser::ReferenceColumnConstraintContext * /*ctx*/) override { }
  virtual void exitReferenceColumnConstraint(MySqlParser::ReferenceColumnConstraintContext * /*ctx*/) override { }

  virtual void enterCollateColumnConstraint(MySqlParser::CollateColumnConstraintContext * /*ctx*/) override { }
  virtual void exitCollateColumnConstraint(MySqlParser::CollateColumnConstraintContext * /*ctx*/) override { }

  virtual void enterGeneratedColumnConstraint(MySqlParser::GeneratedColumnConstraintContext * /*ctx*/) override { }
  virtual void exitGeneratedColumnConstraint(MySqlParser::GeneratedColumnConstraintContext * /*ctx*/) override { }

  virtual void enterSerialDefaultColumnConstraint(MySqlParser::SerialDefaultColumnConstraintContext * /*ctx*/) override { }
  virtual void exitSerialDefaultColumnConstraint(MySqlParser::SerialDefaultColumnConstraintContext * /*ctx*/) override { }

  virtual void enterCheckColumnConstraint(MySqlParser::CheckColumnConstraintContext * /*ctx*/) override { }
  virtual void exitCheckColumnConstraint(MySqlParser::CheckColumnConstraintContext * /*ctx*/) override { }

  virtual void enterPrimaryKeyTableConstraint(MySqlParser::PrimaryKeyTableConstraintContext * /*ctx*/) override { }
  virtual void exitPrimaryKeyTableConstraint(MySqlParser::PrimaryKeyTableConstraintContext * /*ctx*/) override { }

  virtual void enterUniqueKeyTableConstraint(MySqlParser::UniqueKeyTableConstraintContext * /*ctx*/) override { }
  virtual void exitUniqueKeyTableConstraint(MySqlParser::UniqueKeyTableConstraintContext * /*ctx*/) override { }

  virtual void enterForeignKeyTableConstraint(MySqlParser::ForeignKeyTableConstraintContext * /*ctx*/) override { }
  virtual void exitForeignKeyTableConstraint(MySqlParser::ForeignKeyTableConstraintContext * /*ctx*/) override { }

  virtual void enterCheckTableConstraint(MySqlParser::CheckTableConstraintContext * /*ctx*/) override { }
  virtual void exitCheckTableConstraint(MySqlParser::CheckTableConstraintContext * /*ctx*/) override { }

  virtual void enterReferenceDefinition(MySqlParser::ReferenceDefinitionContext * /*ctx*/) override { }
  virtual void exitReferenceDefinition(MySqlParser::ReferenceDefinitionContext * /*ctx*/) override { }

  virtual void enterReferenceAction(MySqlParser::ReferenceActionContext * /*ctx*/) override { }
  virtual void exitReferenceAction(MySqlParser::ReferenceActionContext * /*ctx*/) override { }

  virtual void enterReferenceControlType(MySqlParser::ReferenceControlTypeContext * /*ctx*/) override { }
  virtual void exitReferenceControlType(MySqlParser::ReferenceControlTypeContext * /*ctx*/) override { }

  virtual void enterSimpleIndexDeclaration(MySqlParser::SimpleIndexDeclarationContext * /*ctx*/) override { }
  virtual void exitSimpleIndexDeclaration(MySqlParser::SimpleIndexDeclarationContext * /*ctx*/) override { }

  virtual void enterSpecialIndexDeclaration(MySqlParser::SpecialIndexDeclarationContext * /*ctx*/) override { }
  virtual void exitSpecialIndexDeclaration(MySqlParser::SpecialIndexDeclarationContext * /*ctx*/) override { }

  virtual void enterTableOptionEngine(MySqlParser::TableOptionEngineContext * /*ctx*/) override { }
  virtual void exitTableOptionEngine(MySqlParser::TableOptionEngineContext * /*ctx*/) override { }

  virtual void enterTableOptionEngineAttribute(MySqlParser::TableOptionEngineAttributeContext * /*ctx*/) override { }
  virtual void exitTableOptionEngineAttribute(MySqlParser::TableOptionEngineAttributeContext * /*ctx*/) override { }

  virtual void enterTableOptionAutoextendSize(MySqlParser::TableOptionAutoextendSizeContext * /*ctx*/) override { }
  virtual void exitTableOptionAutoextendSize(MySqlParser::TableOptionAutoextendSizeContext * /*ctx*/) override { }

  virtual void enterTableOptionAutoIncrement(MySqlParser::TableOptionAutoIncrementContext * /*ctx*/) override { }
  virtual void exitTableOptionAutoIncrement(MySqlParser::TableOptionAutoIncrementContext * /*ctx*/) override { }

  virtual void enterTableOptionAverage(MySqlParser::TableOptionAverageContext * /*ctx*/) override { }
  virtual void exitTableOptionAverage(MySqlParser::TableOptionAverageContext * /*ctx*/) override { }

  virtual void enterTableOptionCharset(MySqlParser::TableOptionCharsetContext * /*ctx*/) override { }
  virtual void exitTableOptionCharset(MySqlParser::TableOptionCharsetContext * /*ctx*/) override { }

  virtual void enterTableOptionChecksum(MySqlParser::TableOptionChecksumContext * /*ctx*/) override { }
  virtual void exitTableOptionChecksum(MySqlParser::TableOptionChecksumContext * /*ctx*/) override { }

  virtual void enterTableOptionCollate(MySqlParser::TableOptionCollateContext * /*ctx*/) override { }
  virtual void exitTableOptionCollate(MySqlParser::TableOptionCollateContext * /*ctx*/) override { }

  virtual void enterTableOptionComment(MySqlParser::TableOptionCommentContext * /*ctx*/) override { }
  virtual void exitTableOptionComment(MySqlParser::TableOptionCommentContext * /*ctx*/) override { }

  virtual void enterTableOptionCompression(MySqlParser::TableOptionCompressionContext * /*ctx*/) override { }
  virtual void exitTableOptionCompression(MySqlParser::TableOptionCompressionContext * /*ctx*/) override { }

  virtual void enterTableOptionConnection(MySqlParser::TableOptionConnectionContext * /*ctx*/) override { }
  virtual void exitTableOptionConnection(MySqlParser::TableOptionConnectionContext * /*ctx*/) override { }

  virtual void enterTableOptionDataDirectory(MySqlParser::TableOptionDataDirectoryContext * /*ctx*/) override { }
  virtual void exitTableOptionDataDirectory(MySqlParser::TableOptionDataDirectoryContext * /*ctx*/) override { }

  virtual void enterTableOptionDelay(MySqlParser::TableOptionDelayContext * /*ctx*/) override { }
  virtual void exitTableOptionDelay(MySqlParser::TableOptionDelayContext * /*ctx*/) override { }

  virtual void enterTableOptionEncryption(MySqlParser::TableOptionEncryptionContext * /*ctx*/) override { }
  virtual void exitTableOptionEncryption(MySqlParser::TableOptionEncryptionContext * /*ctx*/) override { }

  virtual void enterTableOptionPageCompressed(MySqlParser::TableOptionPageCompressedContext * /*ctx*/) override { }
  virtual void exitTableOptionPageCompressed(MySqlParser::TableOptionPageCompressedContext * /*ctx*/) override { }

  virtual void enterTableOptionPageCompressionLevel(MySqlParser::TableOptionPageCompressionLevelContext * /*ctx*/) override { }
  virtual void exitTableOptionPageCompressionLevel(MySqlParser::TableOptionPageCompressionLevelContext * /*ctx*/) override { }

  virtual void enterTableOptionEncryptionKeyId(MySqlParser::TableOptionEncryptionKeyIdContext * /*ctx*/) override { }
  virtual void exitTableOptionEncryptionKeyId(MySqlParser::TableOptionEncryptionKeyIdContext * /*ctx*/) override { }

  virtual void enterTableOptionIndexDirectory(MySqlParser::TableOptionIndexDirectoryContext * /*ctx*/) override { }
  virtual void exitTableOptionIndexDirectory(MySqlParser::TableOptionIndexDirectoryContext * /*ctx*/) override { }

  virtual void enterTableOptionInsertMethod(MySqlParser::TableOptionInsertMethodContext * /*ctx*/) override { }
  virtual void exitTableOptionInsertMethod(MySqlParser::TableOptionInsertMethodContext * /*ctx*/) override { }

  virtual void enterTableOptionKeyBlockSize(MySqlParser::TableOptionKeyBlockSizeContext * /*ctx*/) override { }
  virtual void exitTableOptionKeyBlockSize(MySqlParser::TableOptionKeyBlockSizeContext * /*ctx*/) override { }

  virtual void enterTableOptionMaxRows(MySqlParser::TableOptionMaxRowsContext * /*ctx*/) override { }
  virtual void exitTableOptionMaxRows(MySqlParser::TableOptionMaxRowsContext * /*ctx*/) override { }

  virtual void enterTableOptionMinRows(MySqlParser::TableOptionMinRowsContext * /*ctx*/) override { }
  virtual void exitTableOptionMinRows(MySqlParser::TableOptionMinRowsContext * /*ctx*/) override { }

  virtual void enterTableOptionPackKeys(MySqlParser::TableOptionPackKeysContext * /*ctx*/) override { }
  virtual void exitTableOptionPackKeys(MySqlParser::TableOptionPackKeysContext * /*ctx*/) override { }

  virtual void enterTableOptionPassword(MySqlParser::TableOptionPasswordContext * /*ctx*/) override { }
  virtual void exitTableOptionPassword(MySqlParser::TableOptionPasswordContext * /*ctx*/) override { }

  virtual void enterTableOptionRowFormat(MySqlParser::TableOptionRowFormatContext * /*ctx*/) override { }
  virtual void exitTableOptionRowFormat(MySqlParser::TableOptionRowFormatContext * /*ctx*/) override { }

  virtual void enterTableOptionStartTransaction(MySqlParser::TableOptionStartTransactionContext * /*ctx*/) override { }
  virtual void exitTableOptionStartTransaction(MySqlParser::TableOptionStartTransactionContext * /*ctx*/) override { }

  virtual void enterTableOptionSecondaryEngineAttribute(MySqlParser::TableOptionSecondaryEngineAttributeContext * /*ctx*/) override { }
  virtual void exitTableOptionSecondaryEngineAttribute(MySqlParser::TableOptionSecondaryEngineAttributeContext * /*ctx*/) override { }

  virtual void enterTableOptionRecalculation(MySqlParser::TableOptionRecalculationContext * /*ctx*/) override { }
  virtual void exitTableOptionRecalculation(MySqlParser::TableOptionRecalculationContext * /*ctx*/) override { }

  virtual void enterTableOptionPersistent(MySqlParser::TableOptionPersistentContext * /*ctx*/) override { }
  virtual void exitTableOptionPersistent(MySqlParser::TableOptionPersistentContext * /*ctx*/) override { }

  virtual void enterTableOptionSamplePage(MySqlParser::TableOptionSamplePageContext * /*ctx*/) override { }
  virtual void exitTableOptionSamplePage(MySqlParser::TableOptionSamplePageContext * /*ctx*/) override { }

  virtual void enterTableOptionTablespace(MySqlParser::TableOptionTablespaceContext * /*ctx*/) override { }
  virtual void exitTableOptionTablespace(MySqlParser::TableOptionTablespaceContext * /*ctx*/) override { }

  virtual void enterTableOptionTableType(MySqlParser::TableOptionTableTypeContext * /*ctx*/) override { }
  virtual void exitTableOptionTableType(MySqlParser::TableOptionTableTypeContext * /*ctx*/) override { }

  virtual void enterTableOptionTransactional(MySqlParser::TableOptionTransactionalContext * /*ctx*/) override { }
  virtual void exitTableOptionTransactional(MySqlParser::TableOptionTransactionalContext * /*ctx*/) override { }

  virtual void enterTableOptionUnion(MySqlParser::TableOptionUnionContext * /*ctx*/) override { }
  virtual void exitTableOptionUnion(MySqlParser::TableOptionUnionContext * /*ctx*/) override { }

  virtual void enterTableType(MySqlParser::TableTypeContext * /*ctx*/) override { }
  virtual void exitTableType(MySqlParser::TableTypeContext * /*ctx*/) override { }

  virtual void enterTablespaceStorage(MySqlParser::TablespaceStorageContext * /*ctx*/) override { }
  virtual void exitTablespaceStorage(MySqlParser::TablespaceStorageContext * /*ctx*/) override { }

  virtual void enterPartitionDefinitions(MySqlParser::PartitionDefinitionsContext * /*ctx*/) override { }
  virtual void exitPartitionDefinitions(MySqlParser::PartitionDefinitionsContext * /*ctx*/) override { }

  virtual void enterPartitionFunctionHash(MySqlParser::PartitionFunctionHashContext * /*ctx*/) override { }
  virtual void exitPartitionFunctionHash(MySqlParser::PartitionFunctionHashContext * /*ctx*/) override { }

  virtual void enterPartitionFunctionKey(MySqlParser::PartitionFunctionKeyContext * /*ctx*/) override { }
  virtual void exitPartitionFunctionKey(MySqlParser::PartitionFunctionKeyContext * /*ctx*/) override { }

  virtual void enterPartitionFunctionRange(MySqlParser::PartitionFunctionRangeContext * /*ctx*/) override { }
  virtual void exitPartitionFunctionRange(MySqlParser::PartitionFunctionRangeContext * /*ctx*/) override { }

  virtual void enterPartitionFunctionList(MySqlParser::PartitionFunctionListContext * /*ctx*/) override { }
  virtual void exitPartitionFunctionList(MySqlParser::PartitionFunctionListContext * /*ctx*/) override { }

  virtual void enterSubPartitionFunctionHash(MySqlParser::SubPartitionFunctionHashContext * /*ctx*/) override { }
  virtual void exitSubPartitionFunctionHash(MySqlParser::SubPartitionFunctionHashContext * /*ctx*/) override { }

  virtual void enterSubPartitionFunctionKey(MySqlParser::SubPartitionFunctionKeyContext * /*ctx*/) override { }
  virtual void exitSubPartitionFunctionKey(MySqlParser::SubPartitionFunctionKeyContext * /*ctx*/) override { }

  virtual void enterPartitionComparison(MySqlParser::PartitionComparisonContext * /*ctx*/) override { }
  virtual void exitPartitionComparison(MySqlParser::PartitionComparisonContext * /*ctx*/) override { }

  virtual void enterPartitionListAtom(MySqlParser::PartitionListAtomContext * /*ctx*/) override { }
  virtual void exitPartitionListAtom(MySqlParser::PartitionListAtomContext * /*ctx*/) override { }

  virtual void enterPartitionListVector(MySqlParser::PartitionListVectorContext * /*ctx*/) override { }
  virtual void exitPartitionListVector(MySqlParser::PartitionListVectorContext * /*ctx*/) override { }

  virtual void enterPartitionSimple(MySqlParser::PartitionSimpleContext * /*ctx*/) override { }
  virtual void exitPartitionSimple(MySqlParser::PartitionSimpleContext * /*ctx*/) override { }

  virtual void enterPartitionDefinerAtom(MySqlParser::PartitionDefinerAtomContext * /*ctx*/) override { }
  virtual void exitPartitionDefinerAtom(MySqlParser::PartitionDefinerAtomContext * /*ctx*/) override { }

  virtual void enterPartitionDefinerVector(MySqlParser::PartitionDefinerVectorContext * /*ctx*/) override { }
  virtual void exitPartitionDefinerVector(MySqlParser::PartitionDefinerVectorContext * /*ctx*/) override { }

  virtual void enterSubpartitionDefinition(MySqlParser::SubpartitionDefinitionContext * /*ctx*/) override { }
  virtual void exitSubpartitionDefinition(MySqlParser::SubpartitionDefinitionContext * /*ctx*/) override { }

  virtual void enterPartitionOptionEngine(MySqlParser::PartitionOptionEngineContext * /*ctx*/) override { }
  virtual void exitPartitionOptionEngine(MySqlParser::PartitionOptionEngineContext * /*ctx*/) override { }

  virtual void enterPartitionOptionComment(MySqlParser::PartitionOptionCommentContext * /*ctx*/) override { }
  virtual void exitPartitionOptionComment(MySqlParser::PartitionOptionCommentContext * /*ctx*/) override { }

  virtual void enterPartitionOptionDataDirectory(MySqlParser::PartitionOptionDataDirectoryContext * /*ctx*/) override { }
  virtual void exitPartitionOptionDataDirectory(MySqlParser::PartitionOptionDataDirectoryContext * /*ctx*/) override { }

  virtual void enterPartitionOptionIndexDirectory(MySqlParser::PartitionOptionIndexDirectoryContext * /*ctx*/) override { }
  virtual void exitPartitionOptionIndexDirectory(MySqlParser::PartitionOptionIndexDirectoryContext * /*ctx*/) override { }

  virtual void enterPartitionOptionMaxRows(MySqlParser::PartitionOptionMaxRowsContext * /*ctx*/) override { }
  virtual void exitPartitionOptionMaxRows(MySqlParser::PartitionOptionMaxRowsContext * /*ctx*/) override { }

  virtual void enterPartitionOptionMinRows(MySqlParser::PartitionOptionMinRowsContext * /*ctx*/) override { }
  virtual void exitPartitionOptionMinRows(MySqlParser::PartitionOptionMinRowsContext * /*ctx*/) override { }

  virtual void enterPartitionOptionTablespace(MySqlParser::PartitionOptionTablespaceContext * /*ctx*/) override { }
  virtual void exitPartitionOptionTablespace(MySqlParser::PartitionOptionTablespaceContext * /*ctx*/) override { }

  virtual void enterPartitionOptionNodeGroup(MySqlParser::PartitionOptionNodeGroupContext * /*ctx*/) override { }
  virtual void exitPartitionOptionNodeGroup(MySqlParser::PartitionOptionNodeGroupContext * /*ctx*/) override { }

  virtual void enterAlterSimpleDatabase(MySqlParser::AlterSimpleDatabaseContext * /*ctx*/) override { }
  virtual void exitAlterSimpleDatabase(MySqlParser::AlterSimpleDatabaseContext * /*ctx*/) override { }

  virtual void enterAlterUpgradeName(MySqlParser::AlterUpgradeNameContext * /*ctx*/) override { }
  virtual void exitAlterUpgradeName(MySqlParser::AlterUpgradeNameContext * /*ctx*/) override { }

  virtual void enterAlterEvent(MySqlParser::AlterEventContext * /*ctx*/) override { }
  virtual void exitAlterEvent(MySqlParser::AlterEventContext * /*ctx*/) override { }

  virtual void enterAlterFunction(MySqlParser::AlterFunctionContext * /*ctx*/) override { }
  virtual void exitAlterFunction(MySqlParser::AlterFunctionContext * /*ctx*/) override { }

  virtual void enterAlterInstance(MySqlParser::AlterInstanceContext * /*ctx*/) override { }
  virtual void exitAlterInstance(MySqlParser::AlterInstanceContext * /*ctx*/) override { }

  virtual void enterAlterLogfileGroup(MySqlParser::AlterLogfileGroupContext * /*ctx*/) override { }
  virtual void exitAlterLogfileGroup(MySqlParser::AlterLogfileGroupContext * /*ctx*/) override { }

  virtual void enterAlterProcedure(MySqlParser::AlterProcedureContext * /*ctx*/) override { }
  virtual void exitAlterProcedure(MySqlParser::AlterProcedureContext * /*ctx*/) override { }

  virtual void enterAlterServer(MySqlParser::AlterServerContext * /*ctx*/) override { }
  virtual void exitAlterServer(MySqlParser::AlterServerContext * /*ctx*/) override { }

  virtual void enterAlterTable(MySqlParser::AlterTableContext * /*ctx*/) override { }
  virtual void exitAlterTable(MySqlParser::AlterTableContext * /*ctx*/) override { }

  virtual void enterAlterTablespace(MySqlParser::AlterTablespaceContext * /*ctx*/) override { }
  virtual void exitAlterTablespace(MySqlParser::AlterTablespaceContext * /*ctx*/) override { }

  virtual void enterAlterView(MySqlParser::AlterViewContext * /*ctx*/) override { }
  virtual void exitAlterView(MySqlParser::AlterViewContext * /*ctx*/) override { }

  virtual void enterAlterByTableOption(MySqlParser::AlterByTableOptionContext * /*ctx*/) override { }
  virtual void exitAlterByTableOption(MySqlParser::AlterByTableOptionContext * /*ctx*/) override { }

  virtual void enterAlterByAddColumn(MySqlParser::AlterByAddColumnContext * /*ctx*/) override { }
  virtual void exitAlterByAddColumn(MySqlParser::AlterByAddColumnContext * /*ctx*/) override { }

  virtual void enterAlterByAddColumns(MySqlParser::AlterByAddColumnsContext * /*ctx*/) override { }
  virtual void exitAlterByAddColumns(MySqlParser::AlterByAddColumnsContext * /*ctx*/) override { }

  virtual void enterAlterByAddIndex(MySqlParser::AlterByAddIndexContext * /*ctx*/) override { }
  virtual void exitAlterByAddIndex(MySqlParser::AlterByAddIndexContext * /*ctx*/) override { }

  virtual void enterAlterByAddPrimaryKey(MySqlParser::AlterByAddPrimaryKeyContext * /*ctx*/) override { }
  virtual void exitAlterByAddPrimaryKey(MySqlParser::AlterByAddPrimaryKeyContext * /*ctx*/) override { }

  virtual void enterAlterByAddUniqueKey(MySqlParser::AlterByAddUniqueKeyContext * /*ctx*/) override { }
  virtual void exitAlterByAddUniqueKey(MySqlParser::AlterByAddUniqueKeyContext * /*ctx*/) override { }

  virtual void enterAlterByAddSpecialIndex(MySqlParser::AlterByAddSpecialIndexContext * /*ctx*/) override { }
  virtual void exitAlterByAddSpecialIndex(MySqlParser::AlterByAddSpecialIndexContext * /*ctx*/) override { }

  virtual void enterAlterByAddForeignKey(MySqlParser::AlterByAddForeignKeyContext * /*ctx*/) override { }
  virtual void exitAlterByAddForeignKey(MySqlParser::AlterByAddForeignKeyContext * /*ctx*/) override { }

  virtual void enterAlterByAddCheckTableConstraint(MySqlParser::AlterByAddCheckTableConstraintContext * /*ctx*/) override { }
  virtual void exitAlterByAddCheckTableConstraint(MySqlParser::AlterByAddCheckTableConstraintContext * /*ctx*/) override { }

  virtual void enterAlterByAlterCheckTableConstraint(MySqlParser::AlterByAlterCheckTableConstraintContext * /*ctx*/) override { }
  virtual void exitAlterByAlterCheckTableConstraint(MySqlParser::AlterByAlterCheckTableConstraintContext * /*ctx*/) override { }

  virtual void enterAlterBySetAlgorithm(MySqlParser::AlterBySetAlgorithmContext * /*ctx*/) override { }
  virtual void exitAlterBySetAlgorithm(MySqlParser::AlterBySetAlgorithmContext * /*ctx*/) override { }

  virtual void enterAlterByChangeDefault(MySqlParser::AlterByChangeDefaultContext * /*ctx*/) override { }
  virtual void exitAlterByChangeDefault(MySqlParser::AlterByChangeDefaultContext * /*ctx*/) override { }

  virtual void enterAlterByChangeColumn(MySqlParser::AlterByChangeColumnContext * /*ctx*/) override { }
  virtual void exitAlterByChangeColumn(MySqlParser::AlterByChangeColumnContext * /*ctx*/) override { }

  virtual void enterAlterByRenameColumn(MySqlParser::AlterByRenameColumnContext * /*ctx*/) override { }
  virtual void exitAlterByRenameColumn(MySqlParser::AlterByRenameColumnContext * /*ctx*/) override { }

  virtual void enterAlterByLock(MySqlParser::AlterByLockContext * /*ctx*/) override { }
  virtual void exitAlterByLock(MySqlParser::AlterByLockContext * /*ctx*/) override { }

  virtual void enterAlterByModifyColumn(MySqlParser::AlterByModifyColumnContext * /*ctx*/) override { }
  virtual void exitAlterByModifyColumn(MySqlParser::AlterByModifyColumnContext * /*ctx*/) override { }

  virtual void enterAlterByDropColumn(MySqlParser::AlterByDropColumnContext * /*ctx*/) override { }
  virtual void exitAlterByDropColumn(MySqlParser::AlterByDropColumnContext * /*ctx*/) override { }

  virtual void enterAlterByDropConstraintCheck(MySqlParser::AlterByDropConstraintCheckContext * /*ctx*/) override { }
  virtual void exitAlterByDropConstraintCheck(MySqlParser::AlterByDropConstraintCheckContext * /*ctx*/) override { }

  virtual void enterAlterByDropPrimaryKey(MySqlParser::AlterByDropPrimaryKeyContext * /*ctx*/) override { }
  virtual void exitAlterByDropPrimaryKey(MySqlParser::AlterByDropPrimaryKeyContext * /*ctx*/) override { }

  virtual void enterAlterByDropIndex(MySqlParser::AlterByDropIndexContext * /*ctx*/) override { }
  virtual void exitAlterByDropIndex(MySqlParser::AlterByDropIndexContext * /*ctx*/) override { }

  virtual void enterAlterByRenameIndex(MySqlParser::AlterByRenameIndexContext * /*ctx*/) override { }
  virtual void exitAlterByRenameIndex(MySqlParser::AlterByRenameIndexContext * /*ctx*/) override { }

  virtual void enterAlterByAlterColumnDefault(MySqlParser::AlterByAlterColumnDefaultContext * /*ctx*/) override { }
  virtual void exitAlterByAlterColumnDefault(MySqlParser::AlterByAlterColumnDefaultContext * /*ctx*/) override { }

  virtual void enterAlterByAlterIndexVisibility(MySqlParser::AlterByAlterIndexVisibilityContext * /*ctx*/) override { }
  virtual void exitAlterByAlterIndexVisibility(MySqlParser::AlterByAlterIndexVisibilityContext * /*ctx*/) override { }

  virtual void enterAlterByDropForeignKey(MySqlParser::AlterByDropForeignKeyContext * /*ctx*/) override { }
  virtual void exitAlterByDropForeignKey(MySqlParser::AlterByDropForeignKeyContext * /*ctx*/) override { }

  virtual void enterAlterByDisableKeys(MySqlParser::AlterByDisableKeysContext * /*ctx*/) override { }
  virtual void exitAlterByDisableKeys(MySqlParser::AlterByDisableKeysContext * /*ctx*/) override { }

  virtual void enterAlterByEnableKeys(MySqlParser::AlterByEnableKeysContext * /*ctx*/) override { }
  virtual void exitAlterByEnableKeys(MySqlParser::AlterByEnableKeysContext * /*ctx*/) override { }

  virtual void enterAlterByRename(MySqlParser::AlterByRenameContext * /*ctx*/) override { }
  virtual void exitAlterByRename(MySqlParser::AlterByRenameContext * /*ctx*/) override { }

  virtual void enterAlterByOrder(MySqlParser::AlterByOrderContext * /*ctx*/) override { }
  virtual void exitAlterByOrder(MySqlParser::AlterByOrderContext * /*ctx*/) override { }

  virtual void enterAlterByConvertCharset(MySqlParser::AlterByConvertCharsetContext * /*ctx*/) override { }
  virtual void exitAlterByConvertCharset(MySqlParser::AlterByConvertCharsetContext * /*ctx*/) override { }

  virtual void enterAlterByDefaultCharset(MySqlParser::AlterByDefaultCharsetContext * /*ctx*/) override { }
  virtual void exitAlterByDefaultCharset(MySqlParser::AlterByDefaultCharsetContext * /*ctx*/) override { }

  virtual void enterAlterByDiscardTablespace(MySqlParser::AlterByDiscardTablespaceContext * /*ctx*/) override { }
  virtual void exitAlterByDiscardTablespace(MySqlParser::AlterByDiscardTablespaceContext * /*ctx*/) override { }

  virtual void enterAlterByImportTablespace(MySqlParser::AlterByImportTablespaceContext * /*ctx*/) override { }
  virtual void exitAlterByImportTablespace(MySqlParser::AlterByImportTablespaceContext * /*ctx*/) override { }

  virtual void enterAlterByForce(MySqlParser::AlterByForceContext * /*ctx*/) override { }
  virtual void exitAlterByForce(MySqlParser::AlterByForceContext * /*ctx*/) override { }

  virtual void enterAlterByValidate(MySqlParser::AlterByValidateContext * /*ctx*/) override { }
  virtual void exitAlterByValidate(MySqlParser::AlterByValidateContext * /*ctx*/) override { }

  virtual void enterAlterByAddDefinitions(MySqlParser::AlterByAddDefinitionsContext * /*ctx*/) override { }
  virtual void exitAlterByAddDefinitions(MySqlParser::AlterByAddDefinitionsContext * /*ctx*/) override { }

  virtual void enterAlterPartition(MySqlParser::AlterPartitionContext * /*ctx*/) override { }
  virtual void exitAlterPartition(MySqlParser::AlterPartitionContext * /*ctx*/) override { }

  virtual void enterAlterByAddPartition(MySqlParser::AlterByAddPartitionContext * /*ctx*/) override { }
  virtual void exitAlterByAddPartition(MySqlParser::AlterByAddPartitionContext * /*ctx*/) override { }

  virtual void enterAlterByDropPartition(MySqlParser::AlterByDropPartitionContext * /*ctx*/) override { }
  virtual void exitAlterByDropPartition(MySqlParser::AlterByDropPartitionContext * /*ctx*/) override { }

  virtual void enterAlterByDiscardPartition(MySqlParser::AlterByDiscardPartitionContext * /*ctx*/) override { }
  virtual void exitAlterByDiscardPartition(MySqlParser::AlterByDiscardPartitionContext * /*ctx*/) override { }

  virtual void enterAlterByImportPartition(MySqlParser::AlterByImportPartitionContext * /*ctx*/) override { }
  virtual void exitAlterByImportPartition(MySqlParser::AlterByImportPartitionContext * /*ctx*/) override { }

  virtual void enterAlterByTruncatePartition(MySqlParser::AlterByTruncatePartitionContext * /*ctx*/) override { }
  virtual void exitAlterByTruncatePartition(MySqlParser::AlterByTruncatePartitionContext * /*ctx*/) override { }

  virtual void enterAlterByCoalescePartition(MySqlParser::AlterByCoalescePartitionContext * /*ctx*/) override { }
  virtual void exitAlterByCoalescePartition(MySqlParser::AlterByCoalescePartitionContext * /*ctx*/) override { }

  virtual void enterAlterByReorganizePartition(MySqlParser::AlterByReorganizePartitionContext * /*ctx*/) override { }
  virtual void exitAlterByReorganizePartition(MySqlParser::AlterByReorganizePartitionContext * /*ctx*/) override { }

  virtual void enterAlterByExchangePartition(MySqlParser::AlterByExchangePartitionContext * /*ctx*/) override { }
  virtual void exitAlterByExchangePartition(MySqlParser::AlterByExchangePartitionContext * /*ctx*/) override { }

  virtual void enterAlterByAnalyzePartition(MySqlParser::AlterByAnalyzePartitionContext * /*ctx*/) override { }
  virtual void exitAlterByAnalyzePartition(MySqlParser::AlterByAnalyzePartitionContext * /*ctx*/) override { }

  virtual void enterAlterByCheckPartition(MySqlParser::AlterByCheckPartitionContext * /*ctx*/) override { }
  virtual void exitAlterByCheckPartition(MySqlParser::AlterByCheckPartitionContext * /*ctx*/) override { }

  virtual void enterAlterByOptimizePartition(MySqlParser::AlterByOptimizePartitionContext * /*ctx*/) override { }
  virtual void exitAlterByOptimizePartition(MySqlParser::AlterByOptimizePartitionContext * /*ctx*/) override { }

  virtual void enterAlterByRebuildPartition(MySqlParser::AlterByRebuildPartitionContext * /*ctx*/) override { }
  virtual void exitAlterByRebuildPartition(MySqlParser::AlterByRebuildPartitionContext * /*ctx*/) override { }

  virtual void enterAlterByRepairPartition(MySqlParser::AlterByRepairPartitionContext * /*ctx*/) override { }
  virtual void exitAlterByRepairPartition(MySqlParser::AlterByRepairPartitionContext * /*ctx*/) override { }

  virtual void enterAlterByRemovePartitioning(MySqlParser::AlterByRemovePartitioningContext * /*ctx*/) override { }
  virtual void exitAlterByRemovePartitioning(MySqlParser::AlterByRemovePartitioningContext * /*ctx*/) override { }

  virtual void enterAlterByUpgradePartitioning(MySqlParser::AlterByUpgradePartitioningContext * /*ctx*/) override { }
  virtual void exitAlterByUpgradePartitioning(MySqlParser::AlterByUpgradePartitioningContext * /*ctx*/) override { }

  virtual void enterDropDatabase(MySqlParser::DropDatabaseContext * /*ctx*/) override { }
  virtual void exitDropDatabase(MySqlParser::DropDatabaseContext * /*ctx*/) override { }

  virtual void enterDropEvent(MySqlParser::DropEventContext * /*ctx*/) override { }
  virtual void exitDropEvent(MySqlParser::DropEventContext * /*ctx*/) override { }

  virtual void enterDropIndex(MySqlParser::DropIndexContext * /*ctx*/) override { }
  virtual void exitDropIndex(MySqlParser::DropIndexContext * /*ctx*/) override { }

  virtual void enterDropLogfileGroup(MySqlParser::DropLogfileGroupContext * /*ctx*/) override { }
  virtual void exitDropLogfileGroup(MySqlParser::DropLogfileGroupContext * /*ctx*/) override { }

  virtual void enterDropProcedure(MySqlParser::DropProcedureContext * /*ctx*/) override { }
  virtual void exitDropProcedure(MySqlParser::DropProcedureContext * /*ctx*/) override { }

  virtual void enterDropFunction(MySqlParser::DropFunctionContext * /*ctx*/) override { }
  virtual void exitDropFunction(MySqlParser::DropFunctionContext * /*ctx*/) override { }

  virtual void enterDropServer(MySqlParser::DropServerContext * /*ctx*/) override { }
  virtual void exitDropServer(MySqlParser::DropServerContext * /*ctx*/) override { }

  virtual void enterDropTable(MySqlParser::DropTableContext * /*ctx*/) override { }
  virtual void exitDropTable(MySqlParser::DropTableContext * /*ctx*/) override { }

  virtual void enterDropTablespace(MySqlParser::DropTablespaceContext * /*ctx*/) override { }
  virtual void exitDropTablespace(MySqlParser::DropTablespaceContext * /*ctx*/) override { }

  virtual void enterDropTrigger(MySqlParser::DropTriggerContext * /*ctx*/) override { }
  virtual void exitDropTrigger(MySqlParser::DropTriggerContext * /*ctx*/) override { }

  virtual void enterDropView(MySqlParser::DropViewContext * /*ctx*/) override { }
  virtual void exitDropView(MySqlParser::DropViewContext * /*ctx*/) override { }

  virtual void enterDropRole(MySqlParser::DropRoleContext * /*ctx*/) override { }
  virtual void exitDropRole(MySqlParser::DropRoleContext * /*ctx*/) override { }

  virtual void enterSetRole(MySqlParser::SetRoleContext * /*ctx*/) override { }
  virtual void exitSetRole(MySqlParser::SetRoleContext * /*ctx*/) override { }

  virtual void enterRenameTable(MySqlParser::RenameTableContext * /*ctx*/) override { }
  virtual void exitRenameTable(MySqlParser::RenameTableContext * /*ctx*/) override { }

  virtual void enterRenameTableClause(MySqlParser::RenameTableClauseContext * /*ctx*/) override { }
  virtual void exitRenameTableClause(MySqlParser::RenameTableClauseContext * /*ctx*/) override { }

  virtual void enterTruncateTable(MySqlParser::TruncateTableContext * /*ctx*/) override { }
  virtual void exitTruncateTable(MySqlParser::TruncateTableContext * /*ctx*/) override { }

  virtual void enterCallStatement(MySqlParser::CallStatementContext * /*ctx*/) override { }
  virtual void exitCallStatement(MySqlParser::CallStatementContext * /*ctx*/) override { }

  virtual void enterDeleteStatement(MySqlParser::DeleteStatementContext * /*ctx*/) override { }
  virtual void exitDeleteStatement(MySqlParser::DeleteStatementContext * /*ctx*/) override { }

  virtual void enterDoStatement(MySqlParser::DoStatementContext * /*ctx*/) override { }
  virtual void exitDoStatement(MySqlParser::DoStatementContext * /*ctx*/) override { }

  virtual void enterHandlerStatement(MySqlParser::HandlerStatementContext * /*ctx*/) override { }
  virtual void exitHandlerStatement(MySqlParser::HandlerStatementContext * /*ctx*/) override { }

  virtual void enterInsertStatement(MySqlParser::InsertStatementContext * /*ctx*/) override { }
  virtual void exitInsertStatement(MySqlParser::InsertStatementContext * /*ctx*/) override { }

  virtual void enterLoadDataStatement(MySqlParser::LoadDataStatementContext * /*ctx*/) override { }
  virtual void exitLoadDataStatement(MySqlParser::LoadDataStatementContext * /*ctx*/) override { }

  virtual void enterLoadXmlStatement(MySqlParser::LoadXmlStatementContext * /*ctx*/) override { }
  virtual void exitLoadXmlStatement(MySqlParser::LoadXmlStatementContext * /*ctx*/) override { }

  virtual void enterReplaceStatement(MySqlParser::ReplaceStatementContext * /*ctx*/) override { }
  virtual void exitReplaceStatement(MySqlParser::ReplaceStatementContext * /*ctx*/) override { }

  virtual void enterSimpleSelect(MySqlParser::SimpleSelectContext * /*ctx*/) override { }
  virtual void exitSimpleSelect(MySqlParser::SimpleSelectContext * /*ctx*/) override { }

  virtual void enterParenthesisSelect(MySqlParser::ParenthesisSelectContext * /*ctx*/) override { }
  virtual void exitParenthesisSelect(MySqlParser::ParenthesisSelectContext * /*ctx*/) override { }

  virtual void enterUnionSelect(MySqlParser::UnionSelectContext * /*ctx*/) override { }
  virtual void exitUnionSelect(MySqlParser::UnionSelectContext * /*ctx*/) override { }

  virtual void enterUnionParenthesisSelect(MySqlParser::UnionParenthesisSelectContext * /*ctx*/) override { }
  virtual void exitUnionParenthesisSelect(MySqlParser::UnionParenthesisSelectContext * /*ctx*/) override { }

  virtual void enterWithLateralStatement(MySqlParser::WithLateralStatementContext * /*ctx*/) override { }
  virtual void exitWithLateralStatement(MySqlParser::WithLateralStatementContext * /*ctx*/) override { }

  virtual void enterUpdateStatement(MySqlParser::UpdateStatementContext * /*ctx*/) override { }
  virtual void exitUpdateStatement(MySqlParser::UpdateStatementContext * /*ctx*/) override { }

  virtual void enterValuesStatement(MySqlParser::ValuesStatementContext * /*ctx*/) override { }
  virtual void exitValuesStatement(MySqlParser::ValuesStatementContext * /*ctx*/) override { }

  virtual void enterInsertStatementValue(MySqlParser::InsertStatementValueContext * /*ctx*/) override { }
  virtual void exitInsertStatementValue(MySqlParser::InsertStatementValueContext * /*ctx*/) override { }

  virtual void enterUpdatedElement(MySqlParser::UpdatedElementContext * /*ctx*/) override { }
  virtual void exitUpdatedElement(MySqlParser::UpdatedElementContext * /*ctx*/) override { }

  virtual void enterAssignmentField(MySqlParser::AssignmentFieldContext * /*ctx*/) override { }
  virtual void exitAssignmentField(MySqlParser::AssignmentFieldContext * /*ctx*/) override { }

  virtual void enterLockClause(MySqlParser::LockClauseContext * /*ctx*/) override { }
  virtual void exitLockClause(MySqlParser::LockClauseContext * /*ctx*/) override { }

  virtual void enterSingleDeleteStatement(MySqlParser::SingleDeleteStatementContext * /*ctx*/) override { }
  virtual void exitSingleDeleteStatement(MySqlParser::SingleDeleteStatementContext * /*ctx*/) override { }

  virtual void enterMultipleDeleteStatement(MySqlParser::MultipleDeleteStatementContext * /*ctx*/) override { }
  virtual void exitMultipleDeleteStatement(MySqlParser::MultipleDeleteStatementContext * /*ctx*/) override { }

  virtual void enterHandlerOpenStatement(MySqlParser::HandlerOpenStatementContext * /*ctx*/) override { }
  virtual void exitHandlerOpenStatement(MySqlParser::HandlerOpenStatementContext * /*ctx*/) override { }

  virtual void enterHandlerReadIndexStatement(MySqlParser::HandlerReadIndexStatementContext * /*ctx*/) override { }
  virtual void exitHandlerReadIndexStatement(MySqlParser::HandlerReadIndexStatementContext * /*ctx*/) override { }

  virtual void enterHandlerReadStatement(MySqlParser::HandlerReadStatementContext * /*ctx*/) override { }
  virtual void exitHandlerReadStatement(MySqlParser::HandlerReadStatementContext * /*ctx*/) override { }

  virtual void enterHandlerCloseStatement(MySqlParser::HandlerCloseStatementContext * /*ctx*/) override { }
  virtual void exitHandlerCloseStatement(MySqlParser::HandlerCloseStatementContext * /*ctx*/) override { }

  virtual void enterSingleUpdateStatement(MySqlParser::SingleUpdateStatementContext * /*ctx*/) override { }
  virtual void exitSingleUpdateStatement(MySqlParser::SingleUpdateStatementContext * /*ctx*/) override { }

  virtual void enterMultipleUpdateStatement(MySqlParser::MultipleUpdateStatementContext * /*ctx*/) override { }
  virtual void exitMultipleUpdateStatement(MySqlParser::MultipleUpdateStatementContext * /*ctx*/) override { }

  virtual void enterOrderByClause(MySqlParser::OrderByClauseContext * /*ctx*/) override { }
  virtual void exitOrderByClause(MySqlParser::OrderByClauseContext * /*ctx*/) override { }

  virtual void enterOrderByExpression(MySqlParser::OrderByExpressionContext * /*ctx*/) override { }
  virtual void exitOrderByExpression(MySqlParser::OrderByExpressionContext * /*ctx*/) override { }

  virtual void enterTableSources(MySqlParser::TableSourcesContext * /*ctx*/) override { }
  virtual void exitTableSources(MySqlParser::TableSourcesContext * /*ctx*/) override { }

  virtual void enterTableSourceBase(MySqlParser::TableSourceBaseContext * /*ctx*/) override { }
  virtual void exitTableSourceBase(MySqlParser::TableSourceBaseContext * /*ctx*/) override { }

  virtual void enterTableSourceNested(MySqlParser::TableSourceNestedContext * /*ctx*/) override { }
  virtual void exitTableSourceNested(MySqlParser::TableSourceNestedContext * /*ctx*/) override { }

  virtual void enterTableJson(MySqlParser::TableJsonContext * /*ctx*/) override { }
  virtual void exitTableJson(MySqlParser::TableJsonContext * /*ctx*/) override { }

  virtual void enterAtomTableItem(MySqlParser::AtomTableItemContext * /*ctx*/) override { }
  virtual void exitAtomTableItem(MySqlParser::AtomTableItemContext * /*ctx*/) override { }

  virtual void enterSubqueryTableItem(MySqlParser::SubqueryTableItemContext * /*ctx*/) override { }
  virtual void exitSubqueryTableItem(MySqlParser::SubqueryTableItemContext * /*ctx*/) override { }

  virtual void enterTableSourcesItem(MySqlParser::TableSourcesItemContext * /*ctx*/) override { }
  virtual void exitTableSourcesItem(MySqlParser::TableSourcesItemContext * /*ctx*/) override { }

  virtual void enterIndexHint(MySqlParser::IndexHintContext * /*ctx*/) override { }
  virtual void exitIndexHint(MySqlParser::IndexHintContext * /*ctx*/) override { }

  virtual void enterIndexHintType(MySqlParser::IndexHintTypeContext * /*ctx*/) override { }
  virtual void exitIndexHintType(MySqlParser::IndexHintTypeContext * /*ctx*/) override { }

  virtual void enterInnerJoin(MySqlParser::InnerJoinContext * /*ctx*/) override { }
  virtual void exitInnerJoin(MySqlParser::InnerJoinContext * /*ctx*/) override { }

  virtual void enterStraightJoin(MySqlParser::StraightJoinContext * /*ctx*/) override { }
  virtual void exitStraightJoin(MySqlParser::StraightJoinContext * /*ctx*/) override { }

  virtual void enterOuterJoin(MySqlParser::OuterJoinContext * /*ctx*/) override { }
  virtual void exitOuterJoin(MySqlParser::OuterJoinContext * /*ctx*/) override { }

  virtual void enterNaturalJoin(MySqlParser::NaturalJoinContext * /*ctx*/) override { }
  virtual void exitNaturalJoin(MySqlParser::NaturalJoinContext * /*ctx*/) override { }

  virtual void enterQueryExpression(MySqlParser::QueryExpressionContext * /*ctx*/) override { }
  virtual void exitQueryExpression(MySqlParser::QueryExpressionContext * /*ctx*/) override { }

  virtual void enterQueryExpressionNointo(MySqlParser::QueryExpressionNointoContext * /*ctx*/) override { }
  virtual void exitQueryExpressionNointo(MySqlParser::QueryExpressionNointoContext * /*ctx*/) override { }

  virtual void enterQuerySpecification(MySqlParser::QuerySpecificationContext * /*ctx*/) override { }
  virtual void exitQuerySpecification(MySqlParser::QuerySpecificationContext * /*ctx*/) override { }

  virtual void enterQuerySpecificationNointo(MySqlParser::QuerySpecificationNointoContext * /*ctx*/) override { }
  virtual void exitQuerySpecificationNointo(MySqlParser::QuerySpecificationNointoContext * /*ctx*/) override { }

  virtual void enterUnionParenthesis(MySqlParser::UnionParenthesisContext * /*ctx*/) override { }
  virtual void exitUnionParenthesis(MySqlParser::UnionParenthesisContext * /*ctx*/) override { }

  virtual void enterUnionStatement(MySqlParser::UnionStatementContext * /*ctx*/) override { }
  virtual void exitUnionStatement(MySqlParser::UnionStatementContext * /*ctx*/) override { }

  virtual void enterLateralStatement(MySqlParser::LateralStatementContext * /*ctx*/) override { }
  virtual void exitLateralStatement(MySqlParser::LateralStatementContext * /*ctx*/) override { }

  virtual void enterJsonTable(MySqlParser::JsonTableContext * /*ctx*/) override { }
  virtual void exitJsonTable(MySqlParser::JsonTableContext * /*ctx*/) override { }

  virtual void enterJsonColumnList(MySqlParser::JsonColumnListContext * /*ctx*/) override { }
  virtual void exitJsonColumnList(MySqlParser::JsonColumnListContext * /*ctx*/) override { }

  virtual void enterJsonColumn(MySqlParser::JsonColumnContext * /*ctx*/) override { }
  virtual void exitJsonColumn(MySqlParser::JsonColumnContext * /*ctx*/) override { }

  virtual void enterJsonOnEmpty(MySqlParser::JsonOnEmptyContext * /*ctx*/) override { }
  virtual void exitJsonOnEmpty(MySqlParser::JsonOnEmptyContext * /*ctx*/) override { }

  virtual void enterJsonOnError(MySqlParser::JsonOnErrorContext * /*ctx*/) override { }
  virtual void exitJsonOnError(MySqlParser::JsonOnErrorContext * /*ctx*/) override { }

  virtual void enterSelectSpec(MySqlParser::SelectSpecContext * /*ctx*/) override { }
  virtual void exitSelectSpec(MySqlParser::SelectSpecContext * /*ctx*/) override { }

  virtual void enterSelectElements(MySqlParser::SelectElementsContext * /*ctx*/) override { }
  virtual void exitSelectElements(MySqlParser::SelectElementsContext * /*ctx*/) override { }

  virtual void enterSelectStarElement(MySqlParser::SelectStarElementContext * /*ctx*/) override { }
  virtual void exitSelectStarElement(MySqlParser::SelectStarElementContext * /*ctx*/) override { }

  virtual void enterSelectColumnElement(MySqlParser::SelectColumnElementContext * /*ctx*/) override { }
  virtual void exitSelectColumnElement(MySqlParser::SelectColumnElementContext * /*ctx*/) override { }

  virtual void enterSelectFunctionElement(MySqlParser::SelectFunctionElementContext * /*ctx*/) override { }
  virtual void exitSelectFunctionElement(MySqlParser::SelectFunctionElementContext * /*ctx*/) override { }

  virtual void enterSelectExpressionElement(MySqlParser::SelectExpressionElementContext * /*ctx*/) override { }
  virtual void exitSelectExpressionElement(MySqlParser::SelectExpressionElementContext * /*ctx*/) override { }

  virtual void enterSelectIntoVariables(MySqlParser::SelectIntoVariablesContext * /*ctx*/) override { }
  virtual void exitSelectIntoVariables(MySqlParser::SelectIntoVariablesContext * /*ctx*/) override { }

  virtual void enterSelectIntoDumpFile(MySqlParser::SelectIntoDumpFileContext * /*ctx*/) override { }
  virtual void exitSelectIntoDumpFile(MySqlParser::SelectIntoDumpFileContext * /*ctx*/) override { }

  virtual void enterSelectIntoTextFile(MySqlParser::SelectIntoTextFileContext * /*ctx*/) override { }
  virtual void exitSelectIntoTextFile(MySqlParser::SelectIntoTextFileContext * /*ctx*/) override { }

  virtual void enterSelectFieldsInto(MySqlParser::SelectFieldsIntoContext * /*ctx*/) override { }
  virtual void exitSelectFieldsInto(MySqlParser::SelectFieldsIntoContext * /*ctx*/) override { }

  virtual void enterSelectLinesInto(MySqlParser::SelectLinesIntoContext * /*ctx*/) override { }
  virtual void exitSelectLinesInto(MySqlParser::SelectLinesIntoContext * /*ctx*/) override { }

  virtual void enterFromClause(MySqlParser::FromClauseContext * /*ctx*/) override { }
  virtual void exitFromClause(MySqlParser::FromClauseContext * /*ctx*/) override { }

  virtual void enterGroupByClause(MySqlParser::GroupByClauseContext * /*ctx*/) override { }
  virtual void exitGroupByClause(MySqlParser::GroupByClauseContext * /*ctx*/) override { }

  virtual void enterHavingClause(MySqlParser::HavingClauseContext * /*ctx*/) override { }
  virtual void exitHavingClause(MySqlParser::HavingClauseContext * /*ctx*/) override { }

  virtual void enterWindowClause(MySqlParser::WindowClauseContext * /*ctx*/) override { }
  virtual void exitWindowClause(MySqlParser::WindowClauseContext * /*ctx*/) override { }

  virtual void enterGroupByItem(MySqlParser::GroupByItemContext * /*ctx*/) override { }
  virtual void exitGroupByItem(MySqlParser::GroupByItemContext * /*ctx*/) override { }

  virtual void enterLimitClause(MySqlParser::LimitClauseContext * /*ctx*/) override { }
  virtual void exitLimitClause(MySqlParser::LimitClauseContext * /*ctx*/) override { }

  virtual void enterLimitClauseAtom(MySqlParser::LimitClauseAtomContext * /*ctx*/) override { }
  virtual void exitLimitClauseAtom(MySqlParser::LimitClauseAtomContext * /*ctx*/) override { }

  virtual void enterStartTransaction(MySqlParser::StartTransactionContext * /*ctx*/) override { }
  virtual void exitStartTransaction(MySqlParser::StartTransactionContext * /*ctx*/) override { }

  virtual void enterBeginWork(MySqlParser::BeginWorkContext * /*ctx*/) override { }
  virtual void exitBeginWork(MySqlParser::BeginWorkContext * /*ctx*/) override { }

  virtual void enterCommitWork(MySqlParser::CommitWorkContext * /*ctx*/) override { }
  virtual void exitCommitWork(MySqlParser::CommitWorkContext * /*ctx*/) override { }

  virtual void enterRollbackWork(MySqlParser::RollbackWorkContext * /*ctx*/) override { }
  virtual void exitRollbackWork(MySqlParser::RollbackWorkContext * /*ctx*/) override { }

  virtual void enterSavepointStatement(MySqlParser::SavepointStatementContext * /*ctx*/) override { }
  virtual void exitSavepointStatement(MySqlParser::SavepointStatementContext * /*ctx*/) override { }

  virtual void enterRollbackStatement(MySqlParser::RollbackStatementContext * /*ctx*/) override { }
  virtual void exitRollbackStatement(MySqlParser::RollbackStatementContext * /*ctx*/) override { }

  virtual void enterReleaseStatement(MySqlParser::ReleaseStatementContext * /*ctx*/) override { }
  virtual void exitReleaseStatement(MySqlParser::ReleaseStatementContext * /*ctx*/) override { }

  virtual void enterLockTables(MySqlParser::LockTablesContext * /*ctx*/) override { }
  virtual void exitLockTables(MySqlParser::LockTablesContext * /*ctx*/) override { }

  virtual void enterUnlockTables(MySqlParser::UnlockTablesContext * /*ctx*/) override { }
  virtual void exitUnlockTables(MySqlParser::UnlockTablesContext * /*ctx*/) override { }

  virtual void enterSetAutocommitStatement(MySqlParser::SetAutocommitStatementContext * /*ctx*/) override { }
  virtual void exitSetAutocommitStatement(MySqlParser::SetAutocommitStatementContext * /*ctx*/) override { }

  virtual void enterSetTransactionStatement(MySqlParser::SetTransactionStatementContext * /*ctx*/) override { }
  virtual void exitSetTransactionStatement(MySqlParser::SetTransactionStatementContext * /*ctx*/) override { }

  virtual void enterTransactionMode(MySqlParser::TransactionModeContext * /*ctx*/) override { }
  virtual void exitTransactionMode(MySqlParser::TransactionModeContext * /*ctx*/) override { }

  virtual void enterLockTableElement(MySqlParser::LockTableElementContext * /*ctx*/) override { }
  virtual void exitLockTableElement(MySqlParser::LockTableElementContext * /*ctx*/) override { }

  virtual void enterLockAction(MySqlParser::LockActionContext * /*ctx*/) override { }
  virtual void exitLockAction(MySqlParser::LockActionContext * /*ctx*/) override { }

  virtual void enterTransactionOption(MySqlParser::TransactionOptionContext * /*ctx*/) override { }
  virtual void exitTransactionOption(MySqlParser::TransactionOptionContext * /*ctx*/) override { }

  virtual void enterTransactionLevel(MySqlParser::TransactionLevelContext * /*ctx*/) override { }
  virtual void exitTransactionLevel(MySqlParser::TransactionLevelContext * /*ctx*/) override { }

  virtual void enterChangeMaster(MySqlParser::ChangeMasterContext * /*ctx*/) override { }
  virtual void exitChangeMaster(MySqlParser::ChangeMasterContext * /*ctx*/) override { }

  virtual void enterChangeReplicationFilter(MySqlParser::ChangeReplicationFilterContext * /*ctx*/) override { }
  virtual void exitChangeReplicationFilter(MySqlParser::ChangeReplicationFilterContext * /*ctx*/) override { }

  virtual void enterPurgeBinaryLogs(MySqlParser::PurgeBinaryLogsContext * /*ctx*/) override { }
  virtual void exitPurgeBinaryLogs(MySqlParser::PurgeBinaryLogsContext * /*ctx*/) override { }

  virtual void enterResetMaster(MySqlParser::ResetMasterContext * /*ctx*/) override { }
  virtual void exitResetMaster(MySqlParser::ResetMasterContext * /*ctx*/) override { }

  virtual void enterResetSlave(MySqlParser::ResetSlaveContext * /*ctx*/) override { }
  virtual void exitResetSlave(MySqlParser::ResetSlaveContext * /*ctx*/) override { }

  virtual void enterStartSlave(MySqlParser::StartSlaveContext * /*ctx*/) override { }
  virtual void exitStartSlave(MySqlParser::StartSlaveContext * /*ctx*/) override { }

  virtual void enterStopSlave(MySqlParser::StopSlaveContext * /*ctx*/) override { }
  virtual void exitStopSlave(MySqlParser::StopSlaveContext * /*ctx*/) override { }

  virtual void enterStartGroupReplication(MySqlParser::StartGroupReplicationContext * /*ctx*/) override { }
  virtual void exitStartGroupReplication(MySqlParser::StartGroupReplicationContext * /*ctx*/) override { }

  virtual void enterStopGroupReplication(MySqlParser::StopGroupReplicationContext * /*ctx*/) override { }
  virtual void exitStopGroupReplication(MySqlParser::StopGroupReplicationContext * /*ctx*/) override { }

  virtual void enterMasterStringOption(MySqlParser::MasterStringOptionContext * /*ctx*/) override { }
  virtual void exitMasterStringOption(MySqlParser::MasterStringOptionContext * /*ctx*/) override { }

  virtual void enterMasterDecimalOption(MySqlParser::MasterDecimalOptionContext * /*ctx*/) override { }
  virtual void exitMasterDecimalOption(MySqlParser::MasterDecimalOptionContext * /*ctx*/) override { }

  virtual void enterMasterBoolOption(MySqlParser::MasterBoolOptionContext * /*ctx*/) override { }
  virtual void exitMasterBoolOption(MySqlParser::MasterBoolOptionContext * /*ctx*/) override { }

  virtual void enterMasterRealOption(MySqlParser::MasterRealOptionContext * /*ctx*/) override { }
  virtual void exitMasterRealOption(MySqlParser::MasterRealOptionContext * /*ctx*/) override { }

  virtual void enterMasterUidListOption(MySqlParser::MasterUidListOptionContext * /*ctx*/) override { }
  virtual void exitMasterUidListOption(MySqlParser::MasterUidListOptionContext * /*ctx*/) override { }

  virtual void enterStringMasterOption(MySqlParser::StringMasterOptionContext * /*ctx*/) override { }
  virtual void exitStringMasterOption(MySqlParser::StringMasterOptionContext * /*ctx*/) override { }

  virtual void enterDecimalMasterOption(MySqlParser::DecimalMasterOptionContext * /*ctx*/) override { }
  virtual void exitDecimalMasterOption(MySqlParser::DecimalMasterOptionContext * /*ctx*/) override { }

  virtual void enterBoolMasterOption(MySqlParser::BoolMasterOptionContext * /*ctx*/) override { }
  virtual void exitBoolMasterOption(MySqlParser::BoolMasterOptionContext * /*ctx*/) override { }

  virtual void enterChannelOption(MySqlParser::ChannelOptionContext * /*ctx*/) override { }
  virtual void exitChannelOption(MySqlParser::ChannelOptionContext * /*ctx*/) override { }

  virtual void enterDoDbReplication(MySqlParser::DoDbReplicationContext * /*ctx*/) override { }
  virtual void exitDoDbReplication(MySqlParser::DoDbReplicationContext * /*ctx*/) override { }

  virtual void enterIgnoreDbReplication(MySqlParser::IgnoreDbReplicationContext * /*ctx*/) override { }
  virtual void exitIgnoreDbReplication(MySqlParser::IgnoreDbReplicationContext * /*ctx*/) override { }

  virtual void enterDoTableReplication(MySqlParser::DoTableReplicationContext * /*ctx*/) override { }
  virtual void exitDoTableReplication(MySqlParser::DoTableReplicationContext * /*ctx*/) override { }

  virtual void enterIgnoreTableReplication(MySqlParser::IgnoreTableReplicationContext * /*ctx*/) override { }
  virtual void exitIgnoreTableReplication(MySqlParser::IgnoreTableReplicationContext * /*ctx*/) override { }

  virtual void enterWildDoTableReplication(MySqlParser::WildDoTableReplicationContext * /*ctx*/) override { }
  virtual void exitWildDoTableReplication(MySqlParser::WildDoTableReplicationContext * /*ctx*/) override { }

  virtual void enterWildIgnoreTableReplication(MySqlParser::WildIgnoreTableReplicationContext * /*ctx*/) override { }
  virtual void exitWildIgnoreTableReplication(MySqlParser::WildIgnoreTableReplicationContext * /*ctx*/) override { }

  virtual void enterRewriteDbReplication(MySqlParser::RewriteDbReplicationContext * /*ctx*/) override { }
  virtual void exitRewriteDbReplication(MySqlParser::RewriteDbReplicationContext * /*ctx*/) override { }

  virtual void enterTablePair(MySqlParser::TablePairContext * /*ctx*/) override { }
  virtual void exitTablePair(MySqlParser::TablePairContext * /*ctx*/) override { }

  virtual void enterThreadType(MySqlParser::ThreadTypeContext * /*ctx*/) override { }
  virtual void exitThreadType(MySqlParser::ThreadTypeContext * /*ctx*/) override { }

  virtual void enterGtidsUntilOption(MySqlParser::GtidsUntilOptionContext * /*ctx*/) override { }
  virtual void exitGtidsUntilOption(MySqlParser::GtidsUntilOptionContext * /*ctx*/) override { }

  virtual void enterMasterLogUntilOption(MySqlParser::MasterLogUntilOptionContext * /*ctx*/) override { }
  virtual void exitMasterLogUntilOption(MySqlParser::MasterLogUntilOptionContext * /*ctx*/) override { }

  virtual void enterRelayLogUntilOption(MySqlParser::RelayLogUntilOptionContext * /*ctx*/) override { }
  virtual void exitRelayLogUntilOption(MySqlParser::RelayLogUntilOptionContext * /*ctx*/) override { }

  virtual void enterSqlGapsUntilOption(MySqlParser::SqlGapsUntilOptionContext * /*ctx*/) override { }
  virtual void exitSqlGapsUntilOption(MySqlParser::SqlGapsUntilOptionContext * /*ctx*/) override { }

  virtual void enterUserConnectionOption(MySqlParser::UserConnectionOptionContext * /*ctx*/) override { }
  virtual void exitUserConnectionOption(MySqlParser::UserConnectionOptionContext * /*ctx*/) override { }

  virtual void enterPasswordConnectionOption(MySqlParser::PasswordConnectionOptionContext * /*ctx*/) override { }
  virtual void exitPasswordConnectionOption(MySqlParser::PasswordConnectionOptionContext * /*ctx*/) override { }

  virtual void enterDefaultAuthConnectionOption(MySqlParser::DefaultAuthConnectionOptionContext * /*ctx*/) override { }
  virtual void exitDefaultAuthConnectionOption(MySqlParser::DefaultAuthConnectionOptionContext * /*ctx*/) override { }

  virtual void enterPluginDirConnectionOption(MySqlParser::PluginDirConnectionOptionContext * /*ctx*/) override { }
  virtual void exitPluginDirConnectionOption(MySqlParser::PluginDirConnectionOptionContext * /*ctx*/) override { }

  virtual void enterGtuidSet(MySqlParser::GtuidSetContext * /*ctx*/) override { }
  virtual void exitGtuidSet(MySqlParser::GtuidSetContext * /*ctx*/) override { }

  virtual void enterXaStartTransaction(MySqlParser::XaStartTransactionContext * /*ctx*/) override { }
  virtual void exitXaStartTransaction(MySqlParser::XaStartTransactionContext * /*ctx*/) override { }

  virtual void enterXaEndTransaction(MySqlParser::XaEndTransactionContext * /*ctx*/) override { }
  virtual void exitXaEndTransaction(MySqlParser::XaEndTransactionContext * /*ctx*/) override { }

  virtual void enterXaPrepareStatement(MySqlParser::XaPrepareStatementContext * /*ctx*/) override { }
  virtual void exitXaPrepareStatement(MySqlParser::XaPrepareStatementContext * /*ctx*/) override { }

  virtual void enterXaCommitWork(MySqlParser::XaCommitWorkContext * /*ctx*/) override { }
  virtual void exitXaCommitWork(MySqlParser::XaCommitWorkContext * /*ctx*/) override { }

  virtual void enterXaRollbackWork(MySqlParser::XaRollbackWorkContext * /*ctx*/) override { }
  virtual void exitXaRollbackWork(MySqlParser::XaRollbackWorkContext * /*ctx*/) override { }

  virtual void enterXaRecoverWork(MySqlParser::XaRecoverWorkContext * /*ctx*/) override { }
  virtual void exitXaRecoverWork(MySqlParser::XaRecoverWorkContext * /*ctx*/) override { }

  virtual void enterPrepareStatement(MySqlParser::PrepareStatementContext * /*ctx*/) override { }
  virtual void exitPrepareStatement(MySqlParser::PrepareStatementContext * /*ctx*/) override { }

  virtual void enterExecuteStatement(MySqlParser::ExecuteStatementContext * /*ctx*/) override { }
  virtual void exitExecuteStatement(MySqlParser::ExecuteStatementContext * /*ctx*/) override { }

  virtual void enterDeallocatePrepare(MySqlParser::DeallocatePrepareContext * /*ctx*/) override { }
  virtual void exitDeallocatePrepare(MySqlParser::DeallocatePrepareContext * /*ctx*/) override { }

  virtual void enterRoutineBody(MySqlParser::RoutineBodyContext * /*ctx*/) override { }
  virtual void exitRoutineBody(MySqlParser::RoutineBodyContext * /*ctx*/) override { }

  virtual void enterBlockStatement(MySqlParser::BlockStatementContext * /*ctx*/) override { }
  virtual void exitBlockStatement(MySqlParser::BlockStatementContext * /*ctx*/) override { }

  virtual void enterCaseStatement(MySqlParser::CaseStatementContext * /*ctx*/) override { }
  virtual void exitCaseStatement(MySqlParser::CaseStatementContext * /*ctx*/) override { }

  virtual void enterIfStatement(MySqlParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(MySqlParser::IfStatementContext * /*ctx*/) override { }

  virtual void enterIterateStatement(MySqlParser::IterateStatementContext * /*ctx*/) override { }
  virtual void exitIterateStatement(MySqlParser::IterateStatementContext * /*ctx*/) override { }

  virtual void enterLeaveStatement(MySqlParser::LeaveStatementContext * /*ctx*/) override { }
  virtual void exitLeaveStatement(MySqlParser::LeaveStatementContext * /*ctx*/) override { }

  virtual void enterLoopStatement(MySqlParser::LoopStatementContext * /*ctx*/) override { }
  virtual void exitLoopStatement(MySqlParser::LoopStatementContext * /*ctx*/) override { }

  virtual void enterRepeatStatement(MySqlParser::RepeatStatementContext * /*ctx*/) override { }
  virtual void exitRepeatStatement(MySqlParser::RepeatStatementContext * /*ctx*/) override { }

  virtual void enterReturnStatement(MySqlParser::ReturnStatementContext * /*ctx*/) override { }
  virtual void exitReturnStatement(MySqlParser::ReturnStatementContext * /*ctx*/) override { }

  virtual void enterWhileStatement(MySqlParser::WhileStatementContext * /*ctx*/) override { }
  virtual void exitWhileStatement(MySqlParser::WhileStatementContext * /*ctx*/) override { }

  virtual void enterCloseCursor(MySqlParser::CloseCursorContext * /*ctx*/) override { }
  virtual void exitCloseCursor(MySqlParser::CloseCursorContext * /*ctx*/) override { }

  virtual void enterFetchCursor(MySqlParser::FetchCursorContext * /*ctx*/) override { }
  virtual void exitFetchCursor(MySqlParser::FetchCursorContext * /*ctx*/) override { }

  virtual void enterOpenCursor(MySqlParser::OpenCursorContext * /*ctx*/) override { }
  virtual void exitOpenCursor(MySqlParser::OpenCursorContext * /*ctx*/) override { }

  virtual void enterDeclareVariable(MySqlParser::DeclareVariableContext * /*ctx*/) override { }
  virtual void exitDeclareVariable(MySqlParser::DeclareVariableContext * /*ctx*/) override { }

  virtual void enterDeclareCondition(MySqlParser::DeclareConditionContext * /*ctx*/) override { }
  virtual void exitDeclareCondition(MySqlParser::DeclareConditionContext * /*ctx*/) override { }

  virtual void enterDeclareCursor(MySqlParser::DeclareCursorContext * /*ctx*/) override { }
  virtual void exitDeclareCursor(MySqlParser::DeclareCursorContext * /*ctx*/) override { }

  virtual void enterDeclareHandler(MySqlParser::DeclareHandlerContext * /*ctx*/) override { }
  virtual void exitDeclareHandler(MySqlParser::DeclareHandlerContext * /*ctx*/) override { }

  virtual void enterHandlerConditionCode(MySqlParser::HandlerConditionCodeContext * /*ctx*/) override { }
  virtual void exitHandlerConditionCode(MySqlParser::HandlerConditionCodeContext * /*ctx*/) override { }

  virtual void enterHandlerConditionState(MySqlParser::HandlerConditionStateContext * /*ctx*/) override { }
  virtual void exitHandlerConditionState(MySqlParser::HandlerConditionStateContext * /*ctx*/) override { }

  virtual void enterHandlerConditionName(MySqlParser::HandlerConditionNameContext * /*ctx*/) override { }
  virtual void exitHandlerConditionName(MySqlParser::HandlerConditionNameContext * /*ctx*/) override { }

  virtual void enterHandlerConditionWarning(MySqlParser::HandlerConditionWarningContext * /*ctx*/) override { }
  virtual void exitHandlerConditionWarning(MySqlParser::HandlerConditionWarningContext * /*ctx*/) override { }

  virtual void enterHandlerConditionNotfound(MySqlParser::HandlerConditionNotfoundContext * /*ctx*/) override { }
  virtual void exitHandlerConditionNotfound(MySqlParser::HandlerConditionNotfoundContext * /*ctx*/) override { }

  virtual void enterHandlerConditionException(MySqlParser::HandlerConditionExceptionContext * /*ctx*/) override { }
  virtual void exitHandlerConditionException(MySqlParser::HandlerConditionExceptionContext * /*ctx*/) override { }

  virtual void enterProcedureSqlStatement(MySqlParser::ProcedureSqlStatementContext * /*ctx*/) override { }
  virtual void exitProcedureSqlStatement(MySqlParser::ProcedureSqlStatementContext * /*ctx*/) override { }

  virtual void enterCaseAlternative(MySqlParser::CaseAlternativeContext * /*ctx*/) override { }
  virtual void exitCaseAlternative(MySqlParser::CaseAlternativeContext * /*ctx*/) override { }

  virtual void enterElifAlternative(MySqlParser::ElifAlternativeContext * /*ctx*/) override { }
  virtual void exitElifAlternative(MySqlParser::ElifAlternativeContext * /*ctx*/) override { }

  virtual void enterAlterUserMysqlV56(MySqlParser::AlterUserMysqlV56Context * /*ctx*/) override { }
  virtual void exitAlterUserMysqlV56(MySqlParser::AlterUserMysqlV56Context * /*ctx*/) override { }

  virtual void enterAlterUserMysqlV80(MySqlParser::AlterUserMysqlV80Context * /*ctx*/) override { }
  virtual void exitAlterUserMysqlV80(MySqlParser::AlterUserMysqlV80Context * /*ctx*/) override { }

  virtual void enterCreateUserMysqlV56(MySqlParser::CreateUserMysqlV56Context * /*ctx*/) override { }
  virtual void exitCreateUserMysqlV56(MySqlParser::CreateUserMysqlV56Context * /*ctx*/) override { }

  virtual void enterCreateUserMysqlV80(MySqlParser::CreateUserMysqlV80Context * /*ctx*/) override { }
  virtual void exitCreateUserMysqlV80(MySqlParser::CreateUserMysqlV80Context * /*ctx*/) override { }

  virtual void enterDropUser(MySqlParser::DropUserContext * /*ctx*/) override { }
  virtual void exitDropUser(MySqlParser::DropUserContext * /*ctx*/) override { }

  virtual void enterGrantStatement(MySqlParser::GrantStatementContext * /*ctx*/) override { }
  virtual void exitGrantStatement(MySqlParser::GrantStatementContext * /*ctx*/) override { }

  virtual void enterRoleOption(MySqlParser::RoleOptionContext * /*ctx*/) override { }
  virtual void exitRoleOption(MySqlParser::RoleOptionContext * /*ctx*/) override { }

  virtual void enterGrantProxy(MySqlParser::GrantProxyContext * /*ctx*/) override { }
  virtual void exitGrantProxy(MySqlParser::GrantProxyContext * /*ctx*/) override { }

  virtual void enterRenameUser(MySqlParser::RenameUserContext * /*ctx*/) override { }
  virtual void exitRenameUser(MySqlParser::RenameUserContext * /*ctx*/) override { }

  virtual void enterDetailRevoke(MySqlParser::DetailRevokeContext * /*ctx*/) override { }
  virtual void exitDetailRevoke(MySqlParser::DetailRevokeContext * /*ctx*/) override { }

  virtual void enterShortRevoke(MySqlParser::ShortRevokeContext * /*ctx*/) override { }
  virtual void exitShortRevoke(MySqlParser::ShortRevokeContext * /*ctx*/) override { }

  virtual void enterRoleRevoke(MySqlParser::RoleRevokeContext * /*ctx*/) override { }
  virtual void exitRoleRevoke(MySqlParser::RoleRevokeContext * /*ctx*/) override { }

  virtual void enterRevokeProxy(MySqlParser::RevokeProxyContext * /*ctx*/) override { }
  virtual void exitRevokeProxy(MySqlParser::RevokeProxyContext * /*ctx*/) override { }

  virtual void enterSetPasswordStatement(MySqlParser::SetPasswordStatementContext * /*ctx*/) override { }
  virtual void exitSetPasswordStatement(MySqlParser::SetPasswordStatementContext * /*ctx*/) override { }

  virtual void enterUserSpecification(MySqlParser::UserSpecificationContext * /*ctx*/) override { }
  virtual void exitUserSpecification(MySqlParser::UserSpecificationContext * /*ctx*/) override { }

  virtual void enterHashAuthOption(MySqlParser::HashAuthOptionContext * /*ctx*/) override { }
  virtual void exitHashAuthOption(MySqlParser::HashAuthOptionContext * /*ctx*/) override { }

  virtual void enterStringAuthOption(MySqlParser::StringAuthOptionContext * /*ctx*/) override { }
  virtual void exitStringAuthOption(MySqlParser::StringAuthOptionContext * /*ctx*/) override { }

  virtual void enterModuleAuthOption(MySqlParser::ModuleAuthOptionContext * /*ctx*/) override { }
  virtual void exitModuleAuthOption(MySqlParser::ModuleAuthOptionContext * /*ctx*/) override { }

  virtual void enterSimpleAuthOption(MySqlParser::SimpleAuthOptionContext * /*ctx*/) override { }
  virtual void exitSimpleAuthOption(MySqlParser::SimpleAuthOptionContext * /*ctx*/) override { }

  virtual void enterModule(MySqlParser::ModuleContext * /*ctx*/) override { }
  virtual void exitModule(MySqlParser::ModuleContext * /*ctx*/) override { }

  virtual void enterPasswordModuleOption(MySqlParser::PasswordModuleOptionContext * /*ctx*/) override { }
  virtual void exitPasswordModuleOption(MySqlParser::PasswordModuleOptionContext * /*ctx*/) override { }

  virtual void enterTlsOption(MySqlParser::TlsOptionContext * /*ctx*/) override { }
  virtual void exitTlsOption(MySqlParser::TlsOptionContext * /*ctx*/) override { }

  virtual void enterUserResourceOption(MySqlParser::UserResourceOptionContext * /*ctx*/) override { }
  virtual void exitUserResourceOption(MySqlParser::UserResourceOptionContext * /*ctx*/) override { }

  virtual void enterUserPasswordOption(MySqlParser::UserPasswordOptionContext * /*ctx*/) override { }
  virtual void exitUserPasswordOption(MySqlParser::UserPasswordOptionContext * /*ctx*/) override { }

  virtual void enterUserLockOption(MySqlParser::UserLockOptionContext * /*ctx*/) override { }
  virtual void exitUserLockOption(MySqlParser::UserLockOptionContext * /*ctx*/) override { }

  virtual void enterPrivelegeClause(MySqlParser::PrivelegeClauseContext * /*ctx*/) override { }
  virtual void exitPrivelegeClause(MySqlParser::PrivelegeClauseContext * /*ctx*/) override { }

  virtual void enterPrivilege(MySqlParser::PrivilegeContext * /*ctx*/) override { }
  virtual void exitPrivilege(MySqlParser::PrivilegeContext * /*ctx*/) override { }

  virtual void enterCurrentSchemaPriviLevel(MySqlParser::CurrentSchemaPriviLevelContext * /*ctx*/) override { }
  virtual void exitCurrentSchemaPriviLevel(MySqlParser::CurrentSchemaPriviLevelContext * /*ctx*/) override { }

  virtual void enterGlobalPrivLevel(MySqlParser::GlobalPrivLevelContext * /*ctx*/) override { }
  virtual void exitGlobalPrivLevel(MySqlParser::GlobalPrivLevelContext * /*ctx*/) override { }

  virtual void enterDefiniteSchemaPrivLevel(MySqlParser::DefiniteSchemaPrivLevelContext * /*ctx*/) override { }
  virtual void exitDefiniteSchemaPrivLevel(MySqlParser::DefiniteSchemaPrivLevelContext * /*ctx*/) override { }

  virtual void enterDefiniteFullTablePrivLevel(MySqlParser::DefiniteFullTablePrivLevelContext * /*ctx*/) override { }
  virtual void exitDefiniteFullTablePrivLevel(MySqlParser::DefiniteFullTablePrivLevelContext * /*ctx*/) override { }

  virtual void enterDefiniteFullTablePrivLevel2(MySqlParser::DefiniteFullTablePrivLevel2Context * /*ctx*/) override { }
  virtual void exitDefiniteFullTablePrivLevel2(MySqlParser::DefiniteFullTablePrivLevel2Context * /*ctx*/) override { }

  virtual void enterDefiniteTablePrivLevel(MySqlParser::DefiniteTablePrivLevelContext * /*ctx*/) override { }
  virtual void exitDefiniteTablePrivLevel(MySqlParser::DefiniteTablePrivLevelContext * /*ctx*/) override { }

  virtual void enterRenameUserClause(MySqlParser::RenameUserClauseContext * /*ctx*/) override { }
  virtual void exitRenameUserClause(MySqlParser::RenameUserClauseContext * /*ctx*/) override { }

  virtual void enterAnalyzeTable(MySqlParser::AnalyzeTableContext * /*ctx*/) override { }
  virtual void exitAnalyzeTable(MySqlParser::AnalyzeTableContext * /*ctx*/) override { }

  virtual void enterCheckTable(MySqlParser::CheckTableContext * /*ctx*/) override { }
  virtual void exitCheckTable(MySqlParser::CheckTableContext * /*ctx*/) override { }

  virtual void enterChecksumTable(MySqlParser::ChecksumTableContext * /*ctx*/) override { }
  virtual void exitChecksumTable(MySqlParser::ChecksumTableContext * /*ctx*/) override { }

  virtual void enterOptimizeTable(MySqlParser::OptimizeTableContext * /*ctx*/) override { }
  virtual void exitOptimizeTable(MySqlParser::OptimizeTableContext * /*ctx*/) override { }

  virtual void enterRepairTable(MySqlParser::RepairTableContext * /*ctx*/) override { }
  virtual void exitRepairTable(MySqlParser::RepairTableContext * /*ctx*/) override { }

  virtual void enterCheckTableOption(MySqlParser::CheckTableOptionContext * /*ctx*/) override { }
  virtual void exitCheckTableOption(MySqlParser::CheckTableOptionContext * /*ctx*/) override { }

  virtual void enterCreateUdfunction(MySqlParser::CreateUdfunctionContext * /*ctx*/) override { }
  virtual void exitCreateUdfunction(MySqlParser::CreateUdfunctionContext * /*ctx*/) override { }

  virtual void enterInstallPlugin(MySqlParser::InstallPluginContext * /*ctx*/) override { }
  virtual void exitInstallPlugin(MySqlParser::InstallPluginContext * /*ctx*/) override { }

  virtual void enterUninstallPlugin(MySqlParser::UninstallPluginContext * /*ctx*/) override { }
  virtual void exitUninstallPlugin(MySqlParser::UninstallPluginContext * /*ctx*/) override { }

  virtual void enterSetVariable(MySqlParser::SetVariableContext * /*ctx*/) override { }
  virtual void exitSetVariable(MySqlParser::SetVariableContext * /*ctx*/) override { }

  virtual void enterSetCharset(MySqlParser::SetCharsetContext * /*ctx*/) override { }
  virtual void exitSetCharset(MySqlParser::SetCharsetContext * /*ctx*/) override { }

  virtual void enterSetNames(MySqlParser::SetNamesContext * /*ctx*/) override { }
  virtual void exitSetNames(MySqlParser::SetNamesContext * /*ctx*/) override { }

  virtual void enterSetPassword(MySqlParser::SetPasswordContext * /*ctx*/) override { }
  virtual void exitSetPassword(MySqlParser::SetPasswordContext * /*ctx*/) override { }

  virtual void enterSetTransaction(MySqlParser::SetTransactionContext * /*ctx*/) override { }
  virtual void exitSetTransaction(MySqlParser::SetTransactionContext * /*ctx*/) override { }

  virtual void enterSetAutocommit(MySqlParser::SetAutocommitContext * /*ctx*/) override { }
  virtual void exitSetAutocommit(MySqlParser::SetAutocommitContext * /*ctx*/) override { }

  virtual void enterSetNewValueInsideTrigger(MySqlParser::SetNewValueInsideTriggerContext * /*ctx*/) override { }
  virtual void exitSetNewValueInsideTrigger(MySqlParser::SetNewValueInsideTriggerContext * /*ctx*/) override { }

  virtual void enterShowMasterLogs(MySqlParser::ShowMasterLogsContext * /*ctx*/) override { }
  virtual void exitShowMasterLogs(MySqlParser::ShowMasterLogsContext * /*ctx*/) override { }

  virtual void enterShowLogEvents(MySqlParser::ShowLogEventsContext * /*ctx*/) override { }
  virtual void exitShowLogEvents(MySqlParser::ShowLogEventsContext * /*ctx*/) override { }

  virtual void enterShowObjectFilter(MySqlParser::ShowObjectFilterContext * /*ctx*/) override { }
  virtual void exitShowObjectFilter(MySqlParser::ShowObjectFilterContext * /*ctx*/) override { }

  virtual void enterShowColumns(MySqlParser::ShowColumnsContext * /*ctx*/) override { }
  virtual void exitShowColumns(MySqlParser::ShowColumnsContext * /*ctx*/) override { }

  virtual void enterShowCreateDb(MySqlParser::ShowCreateDbContext * /*ctx*/) override { }
  virtual void exitShowCreateDb(MySqlParser::ShowCreateDbContext * /*ctx*/) override { }

  virtual void enterShowCreateFullIdObject(MySqlParser::ShowCreateFullIdObjectContext * /*ctx*/) override { }
  virtual void exitShowCreateFullIdObject(MySqlParser::ShowCreateFullIdObjectContext * /*ctx*/) override { }

  virtual void enterShowCreateUser(MySqlParser::ShowCreateUserContext * /*ctx*/) override { }
  virtual void exitShowCreateUser(MySqlParser::ShowCreateUserContext * /*ctx*/) override { }

  virtual void enterShowEngine(MySqlParser::ShowEngineContext * /*ctx*/) override { }
  virtual void exitShowEngine(MySqlParser::ShowEngineContext * /*ctx*/) override { }

  virtual void enterShowGlobalInfo(MySqlParser::ShowGlobalInfoContext * /*ctx*/) override { }
  virtual void exitShowGlobalInfo(MySqlParser::ShowGlobalInfoContext * /*ctx*/) override { }

  virtual void enterShowErrors(MySqlParser::ShowErrorsContext * /*ctx*/) override { }
  virtual void exitShowErrors(MySqlParser::ShowErrorsContext * /*ctx*/) override { }

  virtual void enterShowCountErrors(MySqlParser::ShowCountErrorsContext * /*ctx*/) override { }
  virtual void exitShowCountErrors(MySqlParser::ShowCountErrorsContext * /*ctx*/) override { }

  virtual void enterShowSchemaFilter(MySqlParser::ShowSchemaFilterContext * /*ctx*/) override { }
  virtual void exitShowSchemaFilter(MySqlParser::ShowSchemaFilterContext * /*ctx*/) override { }

  virtual void enterShowRoutine(MySqlParser::ShowRoutineContext * /*ctx*/) override { }
  virtual void exitShowRoutine(MySqlParser::ShowRoutineContext * /*ctx*/) override { }

  virtual void enterShowGrants(MySqlParser::ShowGrantsContext * /*ctx*/) override { }
  virtual void exitShowGrants(MySqlParser::ShowGrantsContext * /*ctx*/) override { }

  virtual void enterShowIndexes(MySqlParser::ShowIndexesContext * /*ctx*/) override { }
  virtual void exitShowIndexes(MySqlParser::ShowIndexesContext * /*ctx*/) override { }

  virtual void enterShowOpenTables(MySqlParser::ShowOpenTablesContext * /*ctx*/) override { }
  virtual void exitShowOpenTables(MySqlParser::ShowOpenTablesContext * /*ctx*/) override { }

  virtual void enterShowProfile(MySqlParser::ShowProfileContext * /*ctx*/) override { }
  virtual void exitShowProfile(MySqlParser::ShowProfileContext * /*ctx*/) override { }

  virtual void enterShowSlaveStatus(MySqlParser::ShowSlaveStatusContext * /*ctx*/) override { }
  virtual void exitShowSlaveStatus(MySqlParser::ShowSlaveStatusContext * /*ctx*/) override { }

  virtual void enterVariableClause(MySqlParser::VariableClauseContext * /*ctx*/) override { }
  virtual void exitVariableClause(MySqlParser::VariableClauseContext * /*ctx*/) override { }

  virtual void enterShowCommonEntity(MySqlParser::ShowCommonEntityContext * /*ctx*/) override { }
  virtual void exitShowCommonEntity(MySqlParser::ShowCommonEntityContext * /*ctx*/) override { }

  virtual void enterShowFilter(MySqlParser::ShowFilterContext * /*ctx*/) override { }
  virtual void exitShowFilter(MySqlParser::ShowFilterContext * /*ctx*/) override { }

  virtual void enterShowGlobalInfoClause(MySqlParser::ShowGlobalInfoClauseContext * /*ctx*/) override { }
  virtual void exitShowGlobalInfoClause(MySqlParser::ShowGlobalInfoClauseContext * /*ctx*/) override { }

  virtual void enterShowSchemaEntity(MySqlParser::ShowSchemaEntityContext * /*ctx*/) override { }
  virtual void exitShowSchemaEntity(MySqlParser::ShowSchemaEntityContext * /*ctx*/) override { }

  virtual void enterShowProfileType(MySqlParser::ShowProfileTypeContext * /*ctx*/) override { }
  virtual void exitShowProfileType(MySqlParser::ShowProfileTypeContext * /*ctx*/) override { }

  virtual void enterBinlogStatement(MySqlParser::BinlogStatementContext * /*ctx*/) override { }
  virtual void exitBinlogStatement(MySqlParser::BinlogStatementContext * /*ctx*/) override { }

  virtual void enterCacheIndexStatement(MySqlParser::CacheIndexStatementContext * /*ctx*/) override { }
  virtual void exitCacheIndexStatement(MySqlParser::CacheIndexStatementContext * /*ctx*/) override { }

  virtual void enterFlushStatement(MySqlParser::FlushStatementContext * /*ctx*/) override { }
  virtual void exitFlushStatement(MySqlParser::FlushStatementContext * /*ctx*/) override { }

  virtual void enterKillStatement(MySqlParser::KillStatementContext * /*ctx*/) override { }
  virtual void exitKillStatement(MySqlParser::KillStatementContext * /*ctx*/) override { }

  virtual void enterLoadIndexIntoCache(MySqlParser::LoadIndexIntoCacheContext * /*ctx*/) override { }
  virtual void exitLoadIndexIntoCache(MySqlParser::LoadIndexIntoCacheContext * /*ctx*/) override { }

  virtual void enterResetStatement(MySqlParser::ResetStatementContext * /*ctx*/) override { }
  virtual void exitResetStatement(MySqlParser::ResetStatementContext * /*ctx*/) override { }

  virtual void enterShutdownStatement(MySqlParser::ShutdownStatementContext * /*ctx*/) override { }
  virtual void exitShutdownStatement(MySqlParser::ShutdownStatementContext * /*ctx*/) override { }

  virtual void enterTableIndexes(MySqlParser::TableIndexesContext * /*ctx*/) override { }
  virtual void exitTableIndexes(MySqlParser::TableIndexesContext * /*ctx*/) override { }

  virtual void enterSimpleFlushOption(MySqlParser::SimpleFlushOptionContext * /*ctx*/) override { }
  virtual void exitSimpleFlushOption(MySqlParser::SimpleFlushOptionContext * /*ctx*/) override { }

  virtual void enterChannelFlushOption(MySqlParser::ChannelFlushOptionContext * /*ctx*/) override { }
  virtual void exitChannelFlushOption(MySqlParser::ChannelFlushOptionContext * /*ctx*/) override { }

  virtual void enterTableFlushOption(MySqlParser::TableFlushOptionContext * /*ctx*/) override { }
  virtual void exitTableFlushOption(MySqlParser::TableFlushOptionContext * /*ctx*/) override { }

  virtual void enterFlushTableOption(MySqlParser::FlushTableOptionContext * /*ctx*/) override { }
  virtual void exitFlushTableOption(MySqlParser::FlushTableOptionContext * /*ctx*/) override { }

  virtual void enterLoadedTableIndexes(MySqlParser::LoadedTableIndexesContext * /*ctx*/) override { }
  virtual void exitLoadedTableIndexes(MySqlParser::LoadedTableIndexesContext * /*ctx*/) override { }

  virtual void enterSimpleDescribeStatement(MySqlParser::SimpleDescribeStatementContext * /*ctx*/) override { }
  virtual void exitSimpleDescribeStatement(MySqlParser::SimpleDescribeStatementContext * /*ctx*/) override { }

  virtual void enterFullDescribeStatement(MySqlParser::FullDescribeStatementContext * /*ctx*/) override { }
  virtual void exitFullDescribeStatement(MySqlParser::FullDescribeStatementContext * /*ctx*/) override { }

  virtual void enterHelpStatement(MySqlParser::HelpStatementContext * /*ctx*/) override { }
  virtual void exitHelpStatement(MySqlParser::HelpStatementContext * /*ctx*/) override { }

  virtual void enterUseStatement(MySqlParser::UseStatementContext * /*ctx*/) override { }
  virtual void exitUseStatement(MySqlParser::UseStatementContext * /*ctx*/) override { }

  virtual void enterSignalStatement(MySqlParser::SignalStatementContext * /*ctx*/) override { }
  virtual void exitSignalStatement(MySqlParser::SignalStatementContext * /*ctx*/) override { }

  virtual void enterResignalStatement(MySqlParser::ResignalStatementContext * /*ctx*/) override { }
  virtual void exitResignalStatement(MySqlParser::ResignalStatementContext * /*ctx*/) override { }

  virtual void enterSignalConditionInformation(MySqlParser::SignalConditionInformationContext * /*ctx*/) override { }
  virtual void exitSignalConditionInformation(MySqlParser::SignalConditionInformationContext * /*ctx*/) override { }

  virtual void enterWithStatement(MySqlParser::WithStatementContext * /*ctx*/) override { }
  virtual void exitWithStatement(MySqlParser::WithStatementContext * /*ctx*/) override { }

  virtual void enterTableStatement(MySqlParser::TableStatementContext * /*ctx*/) override { }
  virtual void exitTableStatement(MySqlParser::TableStatementContext * /*ctx*/) override { }

  virtual void enterDiagnosticsStatement(MySqlParser::DiagnosticsStatementContext * /*ctx*/) override { }
  virtual void exitDiagnosticsStatement(MySqlParser::DiagnosticsStatementContext * /*ctx*/) override { }

  virtual void enterDiagnosticsConditionInformationName(MySqlParser::DiagnosticsConditionInformationNameContext * /*ctx*/) override { }
  virtual void exitDiagnosticsConditionInformationName(MySqlParser::DiagnosticsConditionInformationNameContext * /*ctx*/) override { }

  virtual void enterDescribeStatements(MySqlParser::DescribeStatementsContext * /*ctx*/) override { }
  virtual void exitDescribeStatements(MySqlParser::DescribeStatementsContext * /*ctx*/) override { }

  virtual void enterDescribeConnection(MySqlParser::DescribeConnectionContext * /*ctx*/) override { }
  virtual void exitDescribeConnection(MySqlParser::DescribeConnectionContext * /*ctx*/) override { }

  virtual void enterFullId(MySqlParser::FullIdContext * /*ctx*/) override { }
  virtual void exitFullId(MySqlParser::FullIdContext * /*ctx*/) override { }

  virtual void enterTableName(MySqlParser::TableNameContext * /*ctx*/) override { }
  virtual void exitTableName(MySqlParser::TableNameContext * /*ctx*/) override { }

  virtual void enterRoleName(MySqlParser::RoleNameContext * /*ctx*/) override { }
  virtual void exitRoleName(MySqlParser::RoleNameContext * /*ctx*/) override { }

  virtual void enterFullColumnName(MySqlParser::FullColumnNameContext * /*ctx*/) override { }
  virtual void exitFullColumnName(MySqlParser::FullColumnNameContext * /*ctx*/) override { }

  virtual void enterIndexColumnName(MySqlParser::IndexColumnNameContext * /*ctx*/) override { }
  virtual void exitIndexColumnName(MySqlParser::IndexColumnNameContext * /*ctx*/) override { }

  virtual void enterUserName(MySqlParser::UserNameContext * /*ctx*/) override { }
  virtual void exitUserName(MySqlParser::UserNameContext * /*ctx*/) override { }

  virtual void enterMysqlVariable(MySqlParser::MysqlVariableContext * /*ctx*/) override { }
  virtual void exitMysqlVariable(MySqlParser::MysqlVariableContext * /*ctx*/) override { }

  virtual void enterCharsetName(MySqlParser::CharsetNameContext * /*ctx*/) override { }
  virtual void exitCharsetName(MySqlParser::CharsetNameContext * /*ctx*/) override { }

  virtual void enterCollationName(MySqlParser::CollationNameContext * /*ctx*/) override { }
  virtual void exitCollationName(MySqlParser::CollationNameContext * /*ctx*/) override { }

  virtual void enterEngineName(MySqlParser::EngineNameContext * /*ctx*/) override { }
  virtual void exitEngineName(MySqlParser::EngineNameContext * /*ctx*/) override { }

  virtual void enterEngineNameBase(MySqlParser::EngineNameBaseContext * /*ctx*/) override { }
  virtual void exitEngineNameBase(MySqlParser::EngineNameBaseContext * /*ctx*/) override { }

  virtual void enterUuidSet(MySqlParser::UuidSetContext * /*ctx*/) override { }
  virtual void exitUuidSet(MySqlParser::UuidSetContext * /*ctx*/) override { }

  virtual void enterXid(MySqlParser::XidContext * /*ctx*/) override { }
  virtual void exitXid(MySqlParser::XidContext * /*ctx*/) override { }

  virtual void enterXuidStringId(MySqlParser::XuidStringIdContext * /*ctx*/) override { }
  virtual void exitXuidStringId(MySqlParser::XuidStringIdContext * /*ctx*/) override { }

  virtual void enterAuthPlugin(MySqlParser::AuthPluginContext * /*ctx*/) override { }
  virtual void exitAuthPlugin(MySqlParser::AuthPluginContext * /*ctx*/) override { }

  virtual void enterUid(MySqlParser::UidContext * /*ctx*/) override { }
  virtual void exitUid(MySqlParser::UidContext * /*ctx*/) override { }

  virtual void enterSimpleId(MySqlParser::SimpleIdContext * /*ctx*/) override { }
  virtual void exitSimpleId(MySqlParser::SimpleIdContext * /*ctx*/) override { }

  virtual void enterDottedId(MySqlParser::DottedIdContext * /*ctx*/) override { }
  virtual void exitDottedId(MySqlParser::DottedIdContext * /*ctx*/) override { }

  virtual void enterDecimalLiteral(MySqlParser::DecimalLiteralContext * /*ctx*/) override { }
  virtual void exitDecimalLiteral(MySqlParser::DecimalLiteralContext * /*ctx*/) override { }

  virtual void enterFileSizeLiteral(MySqlParser::FileSizeLiteralContext * /*ctx*/) override { }
  virtual void exitFileSizeLiteral(MySqlParser::FileSizeLiteralContext * /*ctx*/) override { }

  virtual void enterStringLiteral(MySqlParser::StringLiteralContext * /*ctx*/) override { }
  virtual void exitStringLiteral(MySqlParser::StringLiteralContext * /*ctx*/) override { }

  virtual void enterBooleanLiteral(MySqlParser::BooleanLiteralContext * /*ctx*/) override { }
  virtual void exitBooleanLiteral(MySqlParser::BooleanLiteralContext * /*ctx*/) override { }

  virtual void enterHexadecimalLiteral(MySqlParser::HexadecimalLiteralContext * /*ctx*/) override { }
  virtual void exitHexadecimalLiteral(MySqlParser::HexadecimalLiteralContext * /*ctx*/) override { }

  virtual void enterNullNotnull(MySqlParser::NullNotnullContext * /*ctx*/) override { }
  virtual void exitNullNotnull(MySqlParser::NullNotnullContext * /*ctx*/) override { }

  virtual void enterConstant(MySqlParser::ConstantContext * /*ctx*/) override { }
  virtual void exitConstant(MySqlParser::ConstantContext * /*ctx*/) override { }

  virtual void enterStringDataType(MySqlParser::StringDataTypeContext * /*ctx*/) override { }
  virtual void exitStringDataType(MySqlParser::StringDataTypeContext * /*ctx*/) override { }

  virtual void enterNationalVaryingStringDataType(MySqlParser::NationalVaryingStringDataTypeContext * /*ctx*/) override { }
  virtual void exitNationalVaryingStringDataType(MySqlParser::NationalVaryingStringDataTypeContext * /*ctx*/) override { }

  virtual void enterNationalStringDataType(MySqlParser::NationalStringDataTypeContext * /*ctx*/) override { }
  virtual void exitNationalStringDataType(MySqlParser::NationalStringDataTypeContext * /*ctx*/) override { }

  virtual void enterDimensionDataType(MySqlParser::DimensionDataTypeContext * /*ctx*/) override { }
  virtual void exitDimensionDataType(MySqlParser::DimensionDataTypeContext * /*ctx*/) override { }

  virtual void enterSimpleDataType(MySqlParser::SimpleDataTypeContext * /*ctx*/) override { }
  virtual void exitSimpleDataType(MySqlParser::SimpleDataTypeContext * /*ctx*/) override { }

  virtual void enterCollectionDataType(MySqlParser::CollectionDataTypeContext * /*ctx*/) override { }
  virtual void exitCollectionDataType(MySqlParser::CollectionDataTypeContext * /*ctx*/) override { }

  virtual void enterSpatialDataType(MySqlParser::SpatialDataTypeContext * /*ctx*/) override { }
  virtual void exitSpatialDataType(MySqlParser::SpatialDataTypeContext * /*ctx*/) override { }

  virtual void enterLongVarcharDataType(MySqlParser::LongVarcharDataTypeContext * /*ctx*/) override { }
  virtual void exitLongVarcharDataType(MySqlParser::LongVarcharDataTypeContext * /*ctx*/) override { }

  virtual void enterLongVarbinaryDataType(MySqlParser::LongVarbinaryDataTypeContext * /*ctx*/) override { }
  virtual void exitLongVarbinaryDataType(MySqlParser::LongVarbinaryDataTypeContext * /*ctx*/) override { }

  virtual void enterCollectionOptions(MySqlParser::CollectionOptionsContext * /*ctx*/) override { }
  virtual void exitCollectionOptions(MySqlParser::CollectionOptionsContext * /*ctx*/) override { }

  virtual void enterConvertedDataType(MySqlParser::ConvertedDataTypeContext * /*ctx*/) override { }
  virtual void exitConvertedDataType(MySqlParser::ConvertedDataTypeContext * /*ctx*/) override { }

  virtual void enterLengthOneDimension(MySqlParser::LengthOneDimensionContext * /*ctx*/) override { }
  virtual void exitLengthOneDimension(MySqlParser::LengthOneDimensionContext * /*ctx*/) override { }

  virtual void enterLengthTwoDimension(MySqlParser::LengthTwoDimensionContext * /*ctx*/) override { }
  virtual void exitLengthTwoDimension(MySqlParser::LengthTwoDimensionContext * /*ctx*/) override { }

  virtual void enterLengthTwoOptionalDimension(MySqlParser::LengthTwoOptionalDimensionContext * /*ctx*/) override { }
  virtual void exitLengthTwoOptionalDimension(MySqlParser::LengthTwoOptionalDimensionContext * /*ctx*/) override { }

  virtual void enterUidList(MySqlParser::UidListContext * /*ctx*/) override { }
  virtual void exitUidList(MySqlParser::UidListContext * /*ctx*/) override { }

  virtual void enterFullColumnNameList(MySqlParser::FullColumnNameListContext * /*ctx*/) override { }
  virtual void exitFullColumnNameList(MySqlParser::FullColumnNameListContext * /*ctx*/) override { }

  virtual void enterTables(MySqlParser::TablesContext * /*ctx*/) override { }
  virtual void exitTables(MySqlParser::TablesContext * /*ctx*/) override { }

  virtual void enterIndexColumnNames(MySqlParser::IndexColumnNamesContext * /*ctx*/) override { }
  virtual void exitIndexColumnNames(MySqlParser::IndexColumnNamesContext * /*ctx*/) override { }

  virtual void enterExpressions(MySqlParser::ExpressionsContext * /*ctx*/) override { }
  virtual void exitExpressions(MySqlParser::ExpressionsContext * /*ctx*/) override { }

  virtual void enterExpressionsWithDefaults(MySqlParser::ExpressionsWithDefaultsContext * /*ctx*/) override { }
  virtual void exitExpressionsWithDefaults(MySqlParser::ExpressionsWithDefaultsContext * /*ctx*/) override { }

  virtual void enterConstants(MySqlParser::ConstantsContext * /*ctx*/) override { }
  virtual void exitConstants(MySqlParser::ConstantsContext * /*ctx*/) override { }

  virtual void enterSimpleStrings(MySqlParser::SimpleStringsContext * /*ctx*/) override { }
  virtual void exitSimpleStrings(MySqlParser::SimpleStringsContext * /*ctx*/) override { }

  virtual void enterUserVariables(MySqlParser::UserVariablesContext * /*ctx*/) override { }
  virtual void exitUserVariables(MySqlParser::UserVariablesContext * /*ctx*/) override { }

  virtual void enterDefaultValue(MySqlParser::DefaultValueContext * /*ctx*/) override { }
  virtual void exitDefaultValue(MySqlParser::DefaultValueContext * /*ctx*/) override { }

  virtual void enterCurrentTimestamp(MySqlParser::CurrentTimestampContext * /*ctx*/) override { }
  virtual void exitCurrentTimestamp(MySqlParser::CurrentTimestampContext * /*ctx*/) override { }

  virtual void enterExpressionOrDefault(MySqlParser::ExpressionOrDefaultContext * /*ctx*/) override { }
  virtual void exitExpressionOrDefault(MySqlParser::ExpressionOrDefaultContext * /*ctx*/) override { }

  virtual void enterIfExists(MySqlParser::IfExistsContext * /*ctx*/) override { }
  virtual void exitIfExists(MySqlParser::IfExistsContext * /*ctx*/) override { }

  virtual void enterIfNotExists(MySqlParser::IfNotExistsContext * /*ctx*/) override { }
  virtual void exitIfNotExists(MySqlParser::IfNotExistsContext * /*ctx*/) override { }

  virtual void enterOrReplace(MySqlParser::OrReplaceContext * /*ctx*/) override { }
  virtual void exitOrReplace(MySqlParser::OrReplaceContext * /*ctx*/) override { }

  virtual void enterWaitNowaitClause(MySqlParser::WaitNowaitClauseContext * /*ctx*/) override { }
  virtual void exitWaitNowaitClause(MySqlParser::WaitNowaitClauseContext * /*ctx*/) override { }

  virtual void enterSpecificFunctionCall(MySqlParser::SpecificFunctionCallContext * /*ctx*/) override { }
  virtual void exitSpecificFunctionCall(MySqlParser::SpecificFunctionCallContext * /*ctx*/) override { }

  virtual void enterAggregateFunctionCall(MySqlParser::AggregateFunctionCallContext * /*ctx*/) override { }
  virtual void exitAggregateFunctionCall(MySqlParser::AggregateFunctionCallContext * /*ctx*/) override { }

  virtual void enterNonAggregateFunctionCall(MySqlParser::NonAggregateFunctionCallContext * /*ctx*/) override { }
  virtual void exitNonAggregateFunctionCall(MySqlParser::NonAggregateFunctionCallContext * /*ctx*/) override { }

  virtual void enterScalarFunctionCall(MySqlParser::ScalarFunctionCallContext * /*ctx*/) override { }
  virtual void exitScalarFunctionCall(MySqlParser::ScalarFunctionCallContext * /*ctx*/) override { }

  virtual void enterUdfFunctionCall(MySqlParser::UdfFunctionCallContext * /*ctx*/) override { }
  virtual void exitUdfFunctionCall(MySqlParser::UdfFunctionCallContext * /*ctx*/) override { }

  virtual void enterPasswordFunctionCall(MySqlParser::PasswordFunctionCallContext * /*ctx*/) override { }
  virtual void exitPasswordFunctionCall(MySqlParser::PasswordFunctionCallContext * /*ctx*/) override { }

  virtual void enterSimpleFunctionCall(MySqlParser::SimpleFunctionCallContext * /*ctx*/) override { }
  virtual void exitSimpleFunctionCall(MySqlParser::SimpleFunctionCallContext * /*ctx*/) override { }

  virtual void enterDataTypeFunctionCall(MySqlParser::DataTypeFunctionCallContext * /*ctx*/) override { }
  virtual void exitDataTypeFunctionCall(MySqlParser::DataTypeFunctionCallContext * /*ctx*/) override { }

  virtual void enterValuesFunctionCall(MySqlParser::ValuesFunctionCallContext * /*ctx*/) override { }
  virtual void exitValuesFunctionCall(MySqlParser::ValuesFunctionCallContext * /*ctx*/) override { }

  virtual void enterCaseExpressionFunctionCall(MySqlParser::CaseExpressionFunctionCallContext * /*ctx*/) override { }
  virtual void exitCaseExpressionFunctionCall(MySqlParser::CaseExpressionFunctionCallContext * /*ctx*/) override { }

  virtual void enterCaseFunctionCall(MySqlParser::CaseFunctionCallContext * /*ctx*/) override { }
  virtual void exitCaseFunctionCall(MySqlParser::CaseFunctionCallContext * /*ctx*/) override { }

  virtual void enterCharFunctionCall(MySqlParser::CharFunctionCallContext * /*ctx*/) override { }
  virtual void exitCharFunctionCall(MySqlParser::CharFunctionCallContext * /*ctx*/) override { }

  virtual void enterPositionFunctionCall(MySqlParser::PositionFunctionCallContext * /*ctx*/) override { }
  virtual void exitPositionFunctionCall(MySqlParser::PositionFunctionCallContext * /*ctx*/) override { }

  virtual void enterSubstrFunctionCall(MySqlParser::SubstrFunctionCallContext * /*ctx*/) override { }
  virtual void exitSubstrFunctionCall(MySqlParser::SubstrFunctionCallContext * /*ctx*/) override { }

  virtual void enterTrimFunctionCall(MySqlParser::TrimFunctionCallContext * /*ctx*/) override { }
  virtual void exitTrimFunctionCall(MySqlParser::TrimFunctionCallContext * /*ctx*/) override { }

  virtual void enterWeightFunctionCall(MySqlParser::WeightFunctionCallContext * /*ctx*/) override { }
  virtual void exitWeightFunctionCall(MySqlParser::WeightFunctionCallContext * /*ctx*/) override { }

  virtual void enterExtractFunctionCall(MySqlParser::ExtractFunctionCallContext * /*ctx*/) override { }
  virtual void exitExtractFunctionCall(MySqlParser::ExtractFunctionCallContext * /*ctx*/) override { }

  virtual void enterGetFormatFunctionCall(MySqlParser::GetFormatFunctionCallContext * /*ctx*/) override { }
  virtual void exitGetFormatFunctionCall(MySqlParser::GetFormatFunctionCallContext * /*ctx*/) override { }

  virtual void enterJsonValueFunctionCall(MySqlParser::JsonValueFunctionCallContext * /*ctx*/) override { }
  virtual void exitJsonValueFunctionCall(MySqlParser::JsonValueFunctionCallContext * /*ctx*/) override { }

  virtual void enterCaseFuncAlternative(MySqlParser::CaseFuncAlternativeContext * /*ctx*/) override { }
  virtual void exitCaseFuncAlternative(MySqlParser::CaseFuncAlternativeContext * /*ctx*/) override { }

  virtual void enterLevelWeightList(MySqlParser::LevelWeightListContext * /*ctx*/) override { }
  virtual void exitLevelWeightList(MySqlParser::LevelWeightListContext * /*ctx*/) override { }

  virtual void enterLevelWeightRange(MySqlParser::LevelWeightRangeContext * /*ctx*/) override { }
  virtual void exitLevelWeightRange(MySqlParser::LevelWeightRangeContext * /*ctx*/) override { }

  virtual void enterLevelInWeightListElement(MySqlParser::LevelInWeightListElementContext * /*ctx*/) override { }
  virtual void exitLevelInWeightListElement(MySqlParser::LevelInWeightListElementContext * /*ctx*/) override { }

  virtual void enterAggregateWindowedFunction(MySqlParser::AggregateWindowedFunctionContext * /*ctx*/) override { }
  virtual void exitAggregateWindowedFunction(MySqlParser::AggregateWindowedFunctionContext * /*ctx*/) override { }

  virtual void enterNonAggregateWindowedFunction(MySqlParser::NonAggregateWindowedFunctionContext * /*ctx*/) override { }
  virtual void exitNonAggregateWindowedFunction(MySqlParser::NonAggregateWindowedFunctionContext * /*ctx*/) override { }

  virtual void enterOverClause(MySqlParser::OverClauseContext * /*ctx*/) override { }
  virtual void exitOverClause(MySqlParser::OverClauseContext * /*ctx*/) override { }

  virtual void enterWindowSpec(MySqlParser::WindowSpecContext * /*ctx*/) override { }
  virtual void exitWindowSpec(MySqlParser::WindowSpecContext * /*ctx*/) override { }

  virtual void enterWindowName(MySqlParser::WindowNameContext * /*ctx*/) override { }
  virtual void exitWindowName(MySqlParser::WindowNameContext * /*ctx*/) override { }

  virtual void enterFrameClause(MySqlParser::FrameClauseContext * /*ctx*/) override { }
  virtual void exitFrameClause(MySqlParser::FrameClauseContext * /*ctx*/) override { }

  virtual void enterFrameUnits(MySqlParser::FrameUnitsContext * /*ctx*/) override { }
  virtual void exitFrameUnits(MySqlParser::FrameUnitsContext * /*ctx*/) override { }

  virtual void enterFrameExtent(MySqlParser::FrameExtentContext * /*ctx*/) override { }
  virtual void exitFrameExtent(MySqlParser::FrameExtentContext * /*ctx*/) override { }

  virtual void enterFrameBetween(MySqlParser::FrameBetweenContext * /*ctx*/) override { }
  virtual void exitFrameBetween(MySqlParser::FrameBetweenContext * /*ctx*/) override { }

  virtual void enterFrameRange(MySqlParser::FrameRangeContext * /*ctx*/) override { }
  virtual void exitFrameRange(MySqlParser::FrameRangeContext * /*ctx*/) override { }

  virtual void enterPartitionClause(MySqlParser::PartitionClauseContext * /*ctx*/) override { }
  virtual void exitPartitionClause(MySqlParser::PartitionClauseContext * /*ctx*/) override { }

  virtual void enterScalarFunctionName(MySqlParser::ScalarFunctionNameContext * /*ctx*/) override { }
  virtual void exitScalarFunctionName(MySqlParser::ScalarFunctionNameContext * /*ctx*/) override { }

  virtual void enterPasswordFunctionClause(MySqlParser::PasswordFunctionClauseContext * /*ctx*/) override { }
  virtual void exitPasswordFunctionClause(MySqlParser::PasswordFunctionClauseContext * /*ctx*/) override { }

  virtual void enterFunctionArgs(MySqlParser::FunctionArgsContext * /*ctx*/) override { }
  virtual void exitFunctionArgs(MySqlParser::FunctionArgsContext * /*ctx*/) override { }

  virtual void enterFunctionArg(MySqlParser::FunctionArgContext * /*ctx*/) override { }
  virtual void exitFunctionArg(MySqlParser::FunctionArgContext * /*ctx*/) override { }

  virtual void enterIsExpression(MySqlParser::IsExpressionContext * /*ctx*/) override { }
  virtual void exitIsExpression(MySqlParser::IsExpressionContext * /*ctx*/) override { }

  virtual void enterNotExpression(MySqlParser::NotExpressionContext * /*ctx*/) override { }
  virtual void exitNotExpression(MySqlParser::NotExpressionContext * /*ctx*/) override { }

  virtual void enterLogicalExpression(MySqlParser::LogicalExpressionContext * /*ctx*/) override { }
  virtual void exitLogicalExpression(MySqlParser::LogicalExpressionContext * /*ctx*/) override { }

  virtual void enterPredicateExpression(MySqlParser::PredicateExpressionContext * /*ctx*/) override { }
  virtual void exitPredicateExpression(MySqlParser::PredicateExpressionContext * /*ctx*/) override { }

  virtual void enterSoundsLikePredicate(MySqlParser::SoundsLikePredicateContext * /*ctx*/) override { }
  virtual void exitSoundsLikePredicate(MySqlParser::SoundsLikePredicateContext * /*ctx*/) override { }

  virtual void enterExpressionAtomPredicate(MySqlParser::ExpressionAtomPredicateContext * /*ctx*/) override { }
  virtual void exitExpressionAtomPredicate(MySqlParser::ExpressionAtomPredicateContext * /*ctx*/) override { }

  virtual void enterSubqueryComparisonPredicate(MySqlParser::SubqueryComparisonPredicateContext * /*ctx*/) override { }
  virtual void exitSubqueryComparisonPredicate(MySqlParser::SubqueryComparisonPredicateContext * /*ctx*/) override { }

  virtual void enterJsonMemberOfPredicate(MySqlParser::JsonMemberOfPredicateContext * /*ctx*/) override { }
  virtual void exitJsonMemberOfPredicate(MySqlParser::JsonMemberOfPredicateContext * /*ctx*/) override { }

  virtual void enterBinaryComparisonPredicate(MySqlParser::BinaryComparisonPredicateContext * /*ctx*/) override { }
  virtual void exitBinaryComparisonPredicate(MySqlParser::BinaryComparisonPredicateContext * /*ctx*/) override { }

  virtual void enterInPredicate(MySqlParser::InPredicateContext * /*ctx*/) override { }
  virtual void exitInPredicate(MySqlParser::InPredicateContext * /*ctx*/) override { }

  virtual void enterBetweenPredicate(MySqlParser::BetweenPredicateContext * /*ctx*/) override { }
  virtual void exitBetweenPredicate(MySqlParser::BetweenPredicateContext * /*ctx*/) override { }

  virtual void enterIsNullPredicate(MySqlParser::IsNullPredicateContext * /*ctx*/) override { }
  virtual void exitIsNullPredicate(MySqlParser::IsNullPredicateContext * /*ctx*/) override { }

  virtual void enterLikePredicate(MySqlParser::LikePredicateContext * /*ctx*/) override { }
  virtual void exitLikePredicate(MySqlParser::LikePredicateContext * /*ctx*/) override { }

  virtual void enterRegexpPredicate(MySqlParser::RegexpPredicateContext * /*ctx*/) override { }
  virtual void exitRegexpPredicate(MySqlParser::RegexpPredicateContext * /*ctx*/) override { }

  virtual void enterUnaryExpressionAtom(MySqlParser::UnaryExpressionAtomContext * /*ctx*/) override { }
  virtual void exitUnaryExpressionAtom(MySqlParser::UnaryExpressionAtomContext * /*ctx*/) override { }

  virtual void enterCollateExpressionAtom(MySqlParser::CollateExpressionAtomContext * /*ctx*/) override { }
  virtual void exitCollateExpressionAtom(MySqlParser::CollateExpressionAtomContext * /*ctx*/) override { }

  virtual void enterMysqlVariableExpressionAtom(MySqlParser::MysqlVariableExpressionAtomContext * /*ctx*/) override { }
  virtual void exitMysqlVariableExpressionAtom(MySqlParser::MysqlVariableExpressionAtomContext * /*ctx*/) override { }

  virtual void enterNestedExpressionAtom(MySqlParser::NestedExpressionAtomContext * /*ctx*/) override { }
  virtual void exitNestedExpressionAtom(MySqlParser::NestedExpressionAtomContext * /*ctx*/) override { }

  virtual void enterNestedRowExpressionAtom(MySqlParser::NestedRowExpressionAtomContext * /*ctx*/) override { }
  virtual void exitNestedRowExpressionAtom(MySqlParser::NestedRowExpressionAtomContext * /*ctx*/) override { }

  virtual void enterMathExpressionAtom(MySqlParser::MathExpressionAtomContext * /*ctx*/) override { }
  virtual void exitMathExpressionAtom(MySqlParser::MathExpressionAtomContext * /*ctx*/) override { }

  virtual void enterExistsExpressionAtom(MySqlParser::ExistsExpressionAtomContext * /*ctx*/) override { }
  virtual void exitExistsExpressionAtom(MySqlParser::ExistsExpressionAtomContext * /*ctx*/) override { }

  virtual void enterIntervalExpressionAtom(MySqlParser::IntervalExpressionAtomContext * /*ctx*/) override { }
  virtual void exitIntervalExpressionAtom(MySqlParser::IntervalExpressionAtomContext * /*ctx*/) override { }

  virtual void enterJsonExpressionAtom(MySqlParser::JsonExpressionAtomContext * /*ctx*/) override { }
  virtual void exitJsonExpressionAtom(MySqlParser::JsonExpressionAtomContext * /*ctx*/) override { }

  virtual void enterSubqueryExpressionAtom(MySqlParser::SubqueryExpressionAtomContext * /*ctx*/) override { }
  virtual void exitSubqueryExpressionAtom(MySqlParser::SubqueryExpressionAtomContext * /*ctx*/) override { }

  virtual void enterConstantExpressionAtom(MySqlParser::ConstantExpressionAtomContext * /*ctx*/) override { }
  virtual void exitConstantExpressionAtom(MySqlParser::ConstantExpressionAtomContext * /*ctx*/) override { }

  virtual void enterFunctionCallExpressionAtom(MySqlParser::FunctionCallExpressionAtomContext * /*ctx*/) override { }
  virtual void exitFunctionCallExpressionAtom(MySqlParser::FunctionCallExpressionAtomContext * /*ctx*/) override { }

  virtual void enterBinaryExpressionAtom(MySqlParser::BinaryExpressionAtomContext * /*ctx*/) override { }
  virtual void exitBinaryExpressionAtom(MySqlParser::BinaryExpressionAtomContext * /*ctx*/) override { }

  virtual void enterFullColumnNameExpressionAtom(MySqlParser::FullColumnNameExpressionAtomContext * /*ctx*/) override { }
  virtual void exitFullColumnNameExpressionAtom(MySqlParser::FullColumnNameExpressionAtomContext * /*ctx*/) override { }

  virtual void enterBitExpressionAtom(MySqlParser::BitExpressionAtomContext * /*ctx*/) override { }
  virtual void exitBitExpressionAtom(MySqlParser::BitExpressionAtomContext * /*ctx*/) override { }

  virtual void enterUnaryOperator(MySqlParser::UnaryOperatorContext * /*ctx*/) override { }
  virtual void exitUnaryOperator(MySqlParser::UnaryOperatorContext * /*ctx*/) override { }

  virtual void enterComparisonOperator(MySqlParser::ComparisonOperatorContext * /*ctx*/) override { }
  virtual void exitComparisonOperator(MySqlParser::ComparisonOperatorContext * /*ctx*/) override { }

  virtual void enterLogicalOperator(MySqlParser::LogicalOperatorContext * /*ctx*/) override { }
  virtual void exitLogicalOperator(MySqlParser::LogicalOperatorContext * /*ctx*/) override { }

  virtual void enterBitOperator(MySqlParser::BitOperatorContext * /*ctx*/) override { }
  virtual void exitBitOperator(MySqlParser::BitOperatorContext * /*ctx*/) override { }

  virtual void enterMathOperator(MySqlParser::MathOperatorContext * /*ctx*/) override { }
  virtual void exitMathOperator(MySqlParser::MathOperatorContext * /*ctx*/) override { }

  virtual void enterJsonOperator(MySqlParser::JsonOperatorContext * /*ctx*/) override { }
  virtual void exitJsonOperator(MySqlParser::JsonOperatorContext * /*ctx*/) override { }

  virtual void enterCharsetNameBase(MySqlParser::CharsetNameBaseContext * /*ctx*/) override { }
  virtual void exitCharsetNameBase(MySqlParser::CharsetNameBaseContext * /*ctx*/) override { }

  virtual void enterTransactionLevelBase(MySqlParser::TransactionLevelBaseContext * /*ctx*/) override { }
  virtual void exitTransactionLevelBase(MySqlParser::TransactionLevelBaseContext * /*ctx*/) override { }

  virtual void enterPrivilegesBase(MySqlParser::PrivilegesBaseContext * /*ctx*/) override { }
  virtual void exitPrivilegesBase(MySqlParser::PrivilegesBaseContext * /*ctx*/) override { }

  virtual void enterIntervalTypeBase(MySqlParser::IntervalTypeBaseContext * /*ctx*/) override { }
  virtual void exitIntervalTypeBase(MySqlParser::IntervalTypeBaseContext * /*ctx*/) override { }

  virtual void enterDataTypeBase(MySqlParser::DataTypeBaseContext * /*ctx*/) override { }
  virtual void exitDataTypeBase(MySqlParser::DataTypeBaseContext * /*ctx*/) override { }

  virtual void enterKeywordsCanBeId(MySqlParser::KeywordsCanBeIdContext * /*ctx*/) override { }
  virtual void exitKeywordsCanBeId(MySqlParser::KeywordsCanBeIdContext * /*ctx*/) override { }

  virtual void enterFunctionNameBase(MySqlParser::FunctionNameBaseContext * /*ctx*/) override { }
  virtual void exitFunctionNameBase(MySqlParser::FunctionNameBaseContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  // TODO: implement visitErrorNode to introduce error handling for syntax errors
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace antlrcpptest
