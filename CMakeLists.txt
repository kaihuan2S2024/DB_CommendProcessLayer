cmake_minimum_required(VERSION 3.26)
project(CommandProcessor)

set(CMAKE_CXX_STANDARD 17)
set(CPL_WITH_VDBE_LAYER ON CACHE BOOL "Whether to build CPL with VDBE layer" FORCE)
#if(WIN32)
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-generate")
#else()
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-instr-generate -fcoverage-mapping")
#endif()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-instr-generate -fcoverage-mapping")
add_subdirectory(profiling)

## include Utility in Storage Engine
set(BUILD_TESTING OFF CACHE BOOL "" FORCE)
include(${CMAKE_SOURCE_DIR}/external_dependencies.cmake)

include_directories(generated)
include_directories(parserTree)
include_directories(runtime/antlrcpp-ios)
include_directories(runtime/src)
include_directories(runtime/src/atn)
include_directories(runtime/src/dfa)
include_directories(runtime/src/internal)
include_directories(runtime/src/misc)
include_directories(runtime/src/support)
include_directories(runtime/src/tree)
include_directories(runtime/src/tree/pattern)
include_directories(runtime/src/tree/xpath)

#FetchContent_MakeAvailable(VDBE_LAYER)
set(CPL_SOURCES
        generated/MySqlLexer.cpp
        generated/MySqlLexer.h
        generated/MySqlParser.cpp
        generated/MySqlParser.h
        generated/MySqlParserBaseListener.cpp
        generated/MySqlParserBaseListener.h
        generated/MySqlParserBaseVisitor.cpp
        generated/MySqlParserBaseVisitor.h
        generated/MySqlParserListener.cpp
        generated/MySqlParserListener.h
        generated/MySqlParserVisitor.cpp
        generated/MySqlParserVisitor.h
        parserTree/src/Condition.cpp
        parserTree/include/Condition.h
        parserTree/SQLStatement/DDLStatement/DdlStatement.cpp
        parserTree/SQLStatement/DDLStatement/DdlStatement.h
        parserTree/SQLStatement/DMLStatement/DmlStatement.cpp
        parserTree/SQLStatement/DMLStatement/DmlStatement.h
        parserTree/src/ParserTree.cpp
        parserTree/include/ParserTree.h
        parserTree/src/ParserTreeNode.cpp
        parserTree/include/ParserTreeNode.h
        parserTree/SQLStatement/SqlStatement.cpp
        parserTree/SQLStatement/SqlStatement.h
        runtime/antlrcpp-ios/antlrcpp_ios.h
        runtime/src/atn/ActionTransition.cpp
        runtime/src/atn/ActionTransition.h
        runtime/src/atn/AmbiguityInfo.cpp
        runtime/src/atn/AmbiguityInfo.h
        runtime/src/atn/ArrayPredictionContext.cpp
        runtime/src/atn/ArrayPredictionContext.h
        runtime/src/atn/ATN.cpp
        runtime/src/atn/ATN.h
        runtime/src/atn/ATNConfig.cpp
        runtime/src/atn/ATNConfig.h
        runtime/src/atn/ATNConfigSet.cpp
        runtime/src/atn/ATNConfigSet.h
        runtime/src/atn/ATNDeserializationOptions.cpp
        runtime/src/atn/ATNDeserializationOptions.h
        runtime/src/atn/ATNDeserializer.cpp
        runtime/src/atn/ATNDeserializer.h
        runtime/src/atn/ATNSimulator.cpp
        runtime/src/atn/ATNSimulator.h
        runtime/src/atn/ATNState.cpp
        runtime/src/atn/ATNState.h
        runtime/src/atn/ATNStateType.cpp
        runtime/src/atn/ATNStateType.h
        runtime/src/atn/ATNType.h
        runtime/src/atn/AtomTransition.cpp
        runtime/src/atn/AtomTransition.h
        runtime/src/atn/BasicBlockStartState.h
        runtime/src/atn/BasicState.h
        runtime/src/atn/BlockEndState.h
        runtime/src/atn/BlockStartState.h
        runtime/src/atn/ContextSensitivityInfo.cpp
        runtime/src/atn/ContextSensitivityInfo.h
        runtime/src/atn/DecisionEventInfo.cpp
        runtime/src/atn/DecisionEventInfo.h
        runtime/src/atn/DecisionInfo.cpp
        runtime/src/atn/DecisionInfo.h
        runtime/src/atn/DecisionState.cpp
        runtime/src/atn/DecisionState.h
        runtime/src/atn/EpsilonTransition.cpp
        runtime/src/atn/EpsilonTransition.h
        runtime/src/atn/ErrorInfo.cpp
        runtime/src/atn/ErrorInfo.h
        runtime/src/atn/HashUtils.h
        runtime/src/atn/LexerAction.cpp
        runtime/src/atn/LexerAction.h
        runtime/src/atn/LexerActionExecutor.cpp
        runtime/src/atn/LexerActionExecutor.h
        runtime/src/atn/LexerActionType.h
        runtime/src/atn/LexerATNConfig.cpp
        runtime/src/atn/LexerATNConfig.h
        runtime/src/atn/LexerATNSimulator.cpp
        runtime/src/atn/LexerATNSimulator.h
        runtime/src/atn/LexerChannelAction.cpp
        runtime/src/atn/LexerChannelAction.h
        runtime/src/atn/LexerCustomAction.cpp
        runtime/src/atn/LexerCustomAction.h
        runtime/src/atn/LexerIndexedCustomAction.cpp
        runtime/src/atn/LexerIndexedCustomAction.h
        runtime/src/atn/LexerModeAction.cpp
        runtime/src/atn/LexerModeAction.h
        runtime/src/atn/LexerMoreAction.cpp
        runtime/src/atn/LexerMoreAction.h
        runtime/src/atn/LexerPopModeAction.cpp
        runtime/src/atn/LexerPopModeAction.h
        runtime/src/atn/LexerPushModeAction.cpp
        runtime/src/atn/LexerPushModeAction.h
        runtime/src/atn/LexerSkipAction.cpp
        runtime/src/atn/LexerSkipAction.h
        runtime/src/atn/LexerTypeAction.cpp
        runtime/src/atn/LexerTypeAction.h
        runtime/src/atn/LL1Analyzer.cpp
        runtime/src/atn/LL1Analyzer.h
        runtime/src/atn/LookaheadEventInfo.cpp
        runtime/src/atn/LookaheadEventInfo.h
        runtime/src/atn/LoopEndState.h
        runtime/src/atn/NotSetTransition.cpp
        runtime/src/atn/NotSetTransition.h
        runtime/src/atn/OrderedATNConfigSet.cpp
        runtime/src/atn/OrderedATNConfigSet.h
        runtime/src/atn/ParseInfo.cpp
        runtime/src/atn/ParseInfo.h
        runtime/src/atn/ParserATNSimulator.cpp
        runtime/src/atn/ParserATNSimulator.h
        runtime/src/atn/ParserATNSimulatorOptions.h
        runtime/src/atn/PlusBlockStartState.h
        runtime/src/atn/PlusLoopbackState.h
        runtime/src/atn/PrecedencePredicateTransition.cpp
        runtime/src/atn/PrecedencePredicateTransition.h
        runtime/src/atn/PredicateEvalInfo.cpp
        runtime/src/atn/PredicateEvalInfo.h
        runtime/src/atn/PredicateTransition.cpp
        runtime/src/atn/PredicateTransition.h
        runtime/src/atn/PredictionContext.cpp
        runtime/src/atn/PredictionContext.h
        runtime/src/atn/PredictionContextCache.cpp
        runtime/src/atn/PredictionContextCache.h
        runtime/src/atn/PredictionContextMergeCache.cpp
        runtime/src/atn/PredictionContextMergeCache.h
        runtime/src/atn/PredictionContextMergeCacheOptions.h
        runtime/src/atn/PredictionContextType.h
        runtime/src/atn/PredictionMode.cpp
        runtime/src/atn/PredictionMode.h
        runtime/src/atn/ProfilingATNSimulator.cpp
        runtime/src/atn/ProfilingATNSimulator.h
        runtime/src/atn/RangeTransition.cpp
        runtime/src/atn/RangeTransition.h
        runtime/src/atn/RuleStartState.h
        runtime/src/atn/RuleStopState.h
        runtime/src/atn/RuleTransition.cpp
        runtime/src/atn/RuleTransition.h
        runtime/src/atn/SemanticContext.cpp
        runtime/src/atn/SemanticContext.h
        runtime/src/atn/SemanticContextType.h
        runtime/src/atn/SerializedATNView.h
        runtime/src/atn/SetTransition.cpp
        runtime/src/atn/SetTransition.h
        runtime/src/atn/SingletonPredictionContext.cpp
        runtime/src/atn/SingletonPredictionContext.h
        runtime/src/atn/StarBlockStartState.h
        runtime/src/atn/StarLoopbackState.cpp
        runtime/src/atn/StarLoopbackState.h
        runtime/src/atn/StarLoopEntryState.h
        runtime/src/atn/TokensStartState.h
        runtime/src/atn/Transition.cpp
        runtime/src/atn/Transition.h
        runtime/src/atn/TransitionType.cpp
        runtime/src/atn/TransitionType.h
        runtime/src/atn/WildcardTransition.cpp
        runtime/src/atn/WildcardTransition.h
        runtime/src/dfa/DFA.cpp
        runtime/src/dfa/DFA.h
        runtime/src/dfa/DFASerializer.cpp
        runtime/src/dfa/DFASerializer.h
        runtime/src/dfa/DFAState.cpp
        runtime/src/dfa/DFAState.h
        runtime/src/dfa/LexerDFASerializer.cpp
        runtime/src/dfa/LexerDFASerializer.h
        runtime/src/internal/Synchronization.cpp
        runtime/src/internal/Synchronization.h
        runtime/src/misc/InterpreterDataReader.cpp
        runtime/src/misc/InterpreterDataReader.h
        runtime/src/misc/Interval.cpp
        runtime/src/misc/Interval.h
        runtime/src/misc/IntervalSet.cpp
        runtime/src/misc/IntervalSet.h
        runtime/src/misc/MurmurHash.cpp
        runtime/src/misc/MurmurHash.h
        runtime/src/misc/Predicate.cpp
        runtime/src/misc/Predicate.h
        runtime/src/support/Any.cpp
        runtime/src/support/Any.h
        runtime/src/support/Arrays.cpp
        runtime/src/support/Arrays.h
        runtime/src/support/BitSet.h
        runtime/src/support/Casts.h
        runtime/src/support/CPPUtils.cpp
        runtime/src/support/CPPUtils.h
        runtime/src/support/Declarations.h
        runtime/src/support/StringUtils.cpp
        runtime/src/support/StringUtils.h
        runtime/src/support/Unicode.h
        runtime/src/support/Utf8.cpp
        runtime/src/support/Utf8.h
        runtime/src/tree/pattern/Chunk.cpp
        runtime/src/tree/pattern/Chunk.h
        runtime/src/tree/pattern/ParseTreeMatch.cpp
        runtime/src/tree/pattern/ParseTreeMatch.h
        runtime/src/tree/pattern/ParseTreePattern.cpp
        runtime/src/tree/pattern/ParseTreePattern.h
        runtime/src/tree/pattern/ParseTreePatternMatcher.cpp
        runtime/src/tree/pattern/ParseTreePatternMatcher.h
        runtime/src/tree/pattern/RuleTagToken.cpp
        runtime/src/tree/pattern/RuleTagToken.h
        runtime/src/tree/pattern/TagChunk.cpp
        runtime/src/tree/pattern/TagChunk.h
        runtime/src/tree/pattern/TextChunk.cpp
        runtime/src/tree/pattern/TextChunk.h
        runtime/src/tree/pattern/TokenTagToken.cpp
        runtime/src/tree/pattern/TokenTagToken.h
        runtime/src/tree/xpath/XPath.cpp
        runtime/src/tree/xpath/XPath.h
        runtime/src/tree/xpath/XPathElement.cpp
        runtime/src/tree/xpath/XPathElement.h
        runtime/src/tree/xpath/XPathLexer.cpp
        runtime/src/tree/xpath/XPathLexer.h
        runtime/src/tree/xpath/XPathLexerErrorListener.cpp
        runtime/src/tree/xpath/XPathLexerErrorListener.h
        runtime/src/tree/xpath/XPathRuleAnywhereElement.cpp
        runtime/src/tree/xpath/XPathRuleAnywhereElement.h
        runtime/src/tree/xpath/XPathRuleElement.cpp
        runtime/src/tree/xpath/XPathRuleElement.h
        runtime/src/tree/xpath/XPathTokenAnywhereElement.cpp
        runtime/src/tree/xpath/XPathTokenAnywhereElement.h
        runtime/src/tree/xpath/XPathTokenElement.cpp
        runtime/src/tree/xpath/XPathTokenElement.h
        runtime/src/tree/xpath/XPathWildcardAnywhereElement.cpp
        runtime/src/tree/xpath/XPathWildcardAnywhereElement.h
        runtime/src/tree/xpath/XPathWildcardElement.cpp
        runtime/src/tree/xpath/XPathWildcardElement.h
        runtime/src/tree/AbstractParseTreeVisitor.h
        runtime/src/tree/ErrorNode.h
        runtime/src/tree/ErrorNodeImpl.cpp
        runtime/src/tree/ErrorNodeImpl.h
        runtime/src/tree/IterativeParseTreeWalker.cpp
        runtime/src/tree/IterativeParseTreeWalker.h
        runtime/src/tree/ParseTree.cpp
        runtime/src/tree/ParseTree.h
        runtime/src/tree/ParseTreeListener.cpp
        runtime/src/tree/ParseTreeListener.h
        runtime/src/tree/ParseTreeProperty.h
        runtime/src/tree/ParseTreeType.h
        runtime/src/tree/ParseTreeVisitor.cpp
        runtime/src/tree/ParseTreeVisitor.h
        runtime/src/tree/ParseTreeWalker.cpp
        runtime/src/tree/ParseTreeWalker.h
        runtime/src/tree/TerminalNode.h
        runtime/src/tree/TerminalNodeImpl.cpp
        runtime/src/tree/TerminalNodeImpl.h
        runtime/src/tree/Trees.cpp
        runtime/src/tree/Trees.h
        runtime/src/antlr4-common.h
        runtime/src/antlr4-runtime.h
        runtime/src/ANTLRErrorListener.cpp
        runtime/src/ANTLRErrorListener.h
        runtime/src/ANTLRErrorStrategy.cpp
        runtime/src/ANTLRErrorStrategy.h
        runtime/src/ANTLRFileStream.cpp
        runtime/src/ANTLRFileStream.h
        runtime/src/ANTLRInputStream.cpp
        runtime/src/ANTLRInputStream.h
        runtime/src/BailErrorStrategy.cpp
        runtime/src/BailErrorStrategy.h
        runtime/src/BaseErrorListener.cpp
        runtime/src/BaseErrorListener.h
        runtime/src/BufferedTokenStream.cpp
        runtime/src/BufferedTokenStream.h
        runtime/src/CharStream.cpp
        runtime/src/CharStream.h
        runtime/src/CommonToken.cpp
        runtime/src/CommonToken.h
        runtime/src/CommonTokenFactory.cpp
        runtime/src/CommonTokenFactory.h
        runtime/src/CommonTokenStream.cpp
        runtime/src/CommonTokenStream.h
        runtime/src/ConsoleErrorListener.cpp
        runtime/src/ConsoleErrorListener.h
        runtime/src/DefaultErrorStrategy.cpp
        runtime/src/DefaultErrorStrategy.h
        runtime/src/DiagnosticErrorListener.cpp
        runtime/src/DiagnosticErrorListener.h
        runtime/src/Exceptions.cpp
        runtime/src/Exceptions.h
        runtime/src/FailedPredicateException.cpp
        runtime/src/FailedPredicateException.h
        runtime/src/FlatHashMap.h
        runtime/src/FlatHashSet.h
        runtime/src/InputMismatchException.cpp
        runtime/src/InputMismatchException.h
        runtime/src/InterpreterRuleContext.cpp
        runtime/src/InterpreterRuleContext.h
        runtime/src/IntStream.cpp
        runtime/src/IntStream.h
        runtime/src/Lexer.cpp
        runtime/src/Lexer.h
        runtime/src/LexerInterpreter.cpp
        runtime/src/LexerInterpreter.h
        runtime/src/LexerNoViableAltException.cpp
        runtime/src/LexerNoViableAltException.h
        runtime/src/ListTokenSource.cpp
        runtime/src/ListTokenSource.h
        runtime/src/NoViableAltException.cpp
        runtime/src/NoViableAltException.h
        runtime/src/Parser.cpp
        runtime/src/Parser.h
        runtime/src/ParserInterpreter.cpp
        runtime/src/ParserInterpreter.h
        runtime/src/ParserRuleContext.cpp
        runtime/src/ParserRuleContext.h
        runtime/src/ProxyErrorListener.cpp
        runtime/src/ProxyErrorListener.h
        runtime/src/RecognitionException.cpp
        runtime/src/RecognitionException.h
        runtime/src/Recognizer.cpp
        runtime/src/Recognizer.h
        runtime/src/RuleContext.cpp
        runtime/src/RuleContext.h
        runtime/src/RuleContextWithAltNum.cpp
        runtime/src/RuleContextWithAltNum.h
        runtime/src/RuntimeMetaData.cpp
        runtime/src/RuntimeMetaData.h
        runtime/src/Token.cpp
        runtime/src/Token.h
        runtime/src/TokenFactory.h
        runtime/src/TokenSource.cpp
        runtime/src/TokenSource.h
        runtime/src/TokenStream.cpp
        runtime/src/TokenStream.h
        runtime/src/TokenStreamRewriter.cpp
        runtime/src/TokenStreamRewriter.h
        runtime/src/UnbufferedCharStream.cpp
        runtime/src/UnbufferedCharStream.h
        runtime/src/UnbufferedTokenStream.cpp
        runtime/src/UnbufferedTokenStream.h
        runtime/src/Version.h
        runtime/src/Vocabulary.cpp
        runtime/src/Vocabulary.h
        runtime/src/WritableToken.cpp
        runtime/src/WritableToken.h
        parserTree/MyListener/MyListener.cpp
        parserTree/MyListener/MyListener.h
        parserTree/SQLStatement/DMLStatement/src/SelectStatement.cpp
        parserTree/SQLStatement/DMLStatement/include/SelectStatement.h
        parserTree/src/Element.cpp
        parserTree/include/Element.h
        parserTree/src/Operator.cpp
        parserTree/include/Operator.h
        parserTree/SQLStatement/DMLStatement/src/UpdateStatement.cpp
        parserTree/SQLStatement/DMLStatement/include/UpdateStatement.h
        parserTree/SQLStatement/DMLStatement/src/InsertStatement.cpp
        parserTree/SQLStatement/DMLStatement/include/InsertStatement.h
        parserTree/SQLStatement/DMLStatement/src/DeleteStatement.cpp
        parserTree/SQLStatement/DMLStatement/include/DeleteStatement.h
        parserTree/SQLStatement/DMLStatement/src/Join.cpp
        parserTree/SQLStatement/DMLStatement/include/Join.h
        parserTree/SQLStatement/DDLStatement/src/DropTableStatement.cpp
        parserTree/SQLStatement/DDLStatement/include/DropTableStatement.h
        parserTree/SQLStatement/DDLStatement/src/DropDbStatement.cpp
        parserTree/SQLStatement/DDLStatement/include/DropDbStatement.h
        parserTree/SQLStatement/DDLStatement/src/CreateDbStatement.cpp
        parserTree/SQLStatement/DDLStatement/include/CreateDbStatement.h
        parserTree/SQLStatement/DDLStatement/src/CreateTableStatement.cpp
        parserTree/SQLStatement/DDLStatement/include/CreateTableStatement.h
        queryOptimization/Optimizer.cpp
        parserTree/SQLStatement/DDLStatement/src/ShowTables.cpp
        parserTree/SQLStatement/DDLStatement/include/ShowTables.h
        parserTree/SQLStatement/DDLStatement/include/UseDBStatement.h
        parserTree/SQLStatement/DDLStatement/src/UseDBStatement.cpp
        parserTree/SQLStatement/DDLStatement/include/ShowDatabases.h
        commandProcessor/CommandProcessor.cpp
)

add_library(CommandProcessorLib ${CPL_SOURCES})
target_include_directories(CommandProcessorLib PUBLIC generated)
target_include_directories(CommandProcessorLib PUBLIC parserTree)
target_include_directories(CommandProcessorLib PUBLIC queryOptimization)
target_include_directories(CommandProcessorLib PUBLIC runtime/antlrcpp-ios)
target_include_directories(CommandProcessorLib PUBLIC runtime/src)
target_include_directories(CommandProcessorLib PUBLIC runtime/src/atn)
target_include_directories(CommandProcessorLib PUBLIC runtime/src/dfa)
target_include_directories(CommandProcessorLib PUBLIC runtime/src/internal)
target_include_directories(CommandProcessorLib PUBLIC runtime/src/misc)
target_include_directories(CommandProcessorLib PUBLIC runtime/src/support)
target_include_directories(CommandProcessorLib PUBLIC runtime/src/tree)
target_include_directories(CommandProcessorLib PUBLIC runtime/src/tree/pattern)
target_include_directories(CommandProcessorLib PUBLIC runtime/src/tree/xpath)
target_include_directories(CommandProcessorLib PUBLIC commandProcessor)
target_link_libraries(CommandProcessorLib PUBLIC VDBE_LAYER)

# Assuming that the StorageEngine's CMakeLists.txt properly defines a target (e.g., Utility),
# you can link against it directly.
#target_link_libraries(CommandProcessor PUBLIC Utility)
#find_package(GTest QUIET)

# Force to fetch googletest
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

message(STATUS "GTest library path: ${GTEST_LIBRARIES}")

link_libraries(${GTEST_LIBRARIES} gtest_main pthread)
add_executable(CommandProcessor main.cpp)
target_link_libraries(CommandProcessor PUBLIC VDBE_LAYER CommandProcessorLib)
#if (NOT TARGET gtest)
    add_subdirectory(Google_tests)
#endif ()
