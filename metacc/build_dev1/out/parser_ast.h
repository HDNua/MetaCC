#ifndef __HANDY_VAST_H__
#define __HANDY_VAST_H__

#include <string>
#include <vector>

#include <cstdio>
#include <cstring>



namespace ast {
using std::string;
typedef enum ast_type {
    AST_UNTYPED,
    AST_LIST,
    AST_LIST_NODE,
    AST_LIBRARY_TEXT,
    AST_LIBRARY_DESCRIPTION,
    AST_LIBRARY_DECLARATION,
    AST_INCLUDE_STATEMENT,
    AST_SOURCE_TEXT,
    AST_DESCRIPTION,
    AST_MODULE_NONANSI_HEADER,
    AST_MODULE_ANSI_HEADER,
    AST_MODULE_DECLARATION,
    AST_MODULE_KEYWORD,
    AST_INTERFACE_DECLARATION,
    AST_INTERFACE_NONANSI_HEADER,
    AST_INTERFACE_ANSI_HEADER,
    AST_PROGRAM_DECLARATION,
    AST_PROGRAM_NONANSI_HEADER,
    AST_PROGRAM_ANSI_HEADER,
    AST_CHECKER_DECLARATION,
    AST_CLASS_DECLARATION,
    AST_INTERFACE_CLASS_TYPE,
    AST_PACKAGE_DECLARATION,
    AST_TIMEUNITS_DECLARATION,
    AST_PARAMETER_PORT_LIST,
    AST_PARAMETER_PORT_DECLARATION,
    AST_LIST_OF_PORTS,
    AST_LIST_OF_PORT_DECLARATIONS,
    AST_PORT_DECLARATION,
    AST_PORT,
    AST_PORT_EXPRESSION,
    AST_PORT_REFERENCE,
    AST_PORT_DIRECTION,
    AST_NET_PORT_HEADER,
    AST_VARIABLE_PORT_HEADER,
    AST_INTERFACE_PORT_HEADER,
    AST_ANSI_PORT_DECLARATION,
    AST_ELABORATION_SYSTEM_TASK,
    AST_FINISH_NUMBER,
    AST_MODULE_COMMON_ITEM,
    AST_MODULE_ITEM,
    AST_MODULE_OR_GENERATE_ITEM,
    AST_MODULE_OR_GENERATE_ITEM_DECLARATION,
    AST_NON_PORT_MODULE_ITEM,
    AST_PARAMETER_OVERRIDE,
    AST_BIND_DIRECTIVE,
    AST_BIND_TARGET_SCOPE,
    AST_BIND_TARGET_INSTANCE,
    AST_BIND_TARGET_INSTANCE_LIST,
    AST_BIND_INSTANTIATION,
    AST_CONFIG_DECLARATION,
    AST_DESIGN_STATEMENT,
    AST_CONFIG_RULE_STATEMENT,
    AST_DEFAULT_CLAUSE,
    AST_INST_CLAUSE,
    AST_INST_NAME,
    AST_CELL_CLAUSE,
    AST_LIBLIST_CLAUSE,
    AST_USE_CLAUSE,
    AST_INTERFACE_OR_GENERATE_ITEM,
    AST_EXTERN_TF_DECLARATION,
    AST_INTERFACE_ITEM,
    AST_NON_PORT_INTERFACE_ITEM,
    AST_PROGRAM_ITEM,
    AST_NON_PORT_PROGRAM_ITEM,
    AST_PROGRAM_GENERATE_ITEM,
    AST_CHECKER_PORT_LIST,
    AST_CHECKER_PORT_ITEM,
    AST_CHECKER_PORT_DIRECTION,
    AST_CHECKER_OR_GENERATE_ITEM,
    AST_CHECKER_OR_GENERATE_ITEM_DECLARATION,
    AST_CHECKER_GENERATE_ITEM,
    AST_CLASS_ITEM,
    AST_CLASS_PROPERTY,
    AST_CLASS_METHOD,
    AST_CLASS_CONSTRUCTOR_PROTOTYPE,
    AST_CLASS_CONSTRAINT,
    AST_CLASS_ITEM_QUALIFIER,
    AST_PROPERTY_QUALIFIER,
    AST_RANDOM_QUALIFIER,
    AST_METHOD_QUALIFIER,
    AST_METHOD_PROTOTYPE,
    AST_CLASS_CONSTRUCTOR_DECLARATION,
    AST_CONSTRAINT_DECLARATION,
    AST_CONSTRAINT_BLOCK,
    AST_CONSTRAINT_BLOCK_ITEM,
    AST_SOLVE_BEFORE_LIST,
    AST_CONSTRAINT_PRIMARY,
    AST_CONSTRAINT_EXPRESSION,
    AST_UNIQUENESS_CONSTRAINT,
    AST_CONSTRAINT_SET,
    AST_DIST_LIST,
    AST_DIST_ITEM,
    AST_DIST_WEIGHT,
    AST_CONSTRAINT_PROTOTYPE,
    AST_CONSTRAINT_PROTOTYPE_QUALIFIER,
    AST_EXTERN_CONSTRAINT_DECLARATION,
    AST_IDENTIFIER_LIST,
    AST_PACKAGE_ITEM,
    AST_PACKAGE_OR_GENERATE_ITEM_DECLARATION,
    AST_ANONYMOUS_PROGRAM,
    AST_ANONYMOUS_PROGRAM_ITEM,
    AST_LOCAL_PARAMETER_DECLARATION,
    AST_PARAMETER_DECLARATION,
    AST_SPECPARAM_DECLARATION,
    AST_INOUT_DECLARATION,
    AST_INPUT_DECLARATION,
    AST_OUTPUT_DECLARATION,
    AST_INTERFACE_PORT_DECLARATION,
    AST_REF_DECLARATION,
    AST_DATA_DECLARATION,
    AST_PACKAGE_IMPORT_DECLARATION,
    AST_PACKAGE_IMPORT_ITEM,
    AST_PACKAGE_EXPORT_DECLARATION,
    AST_GENVAR_DECLARATION,
    AST_NET_DECLARATION,
    AST_TYPE_DECLARATION,
    AST_NET_TYPE_DECLARATION,
    AST_LIFETIME,
    AST_CASTING_TYPE,
    AST_DATA_TYPE,
    AST_DATA_TYPE_OR_IMPLICIT,
    AST_IMPLICIT_DATA_TYPE,
    AST_ENUM_BASE_TYPE,
    AST_ENUM_NAME_DECLARATION,
    AST_CLASS_SCOPE,
    AST_CLASS_TYPE,
    AST_INTEGER_TYPE,
    AST_INTEGER_ATOM_TYPE,
    AST_INTEGER_VECTOR_TYPE,
    AST_NON_INTEGER_TYPE,
    AST_NET_TYPE,
    AST_NET_PORT_TYPE,
    AST_VARIABLE_PORT_TYPE,
    AST_VAR_DATA_TYPE,
    AST_SIGNING,
    AST_SIMPLE_TYPE,
    AST_STRUCT_UNION_MEMBER,
    AST_DATA_TYPE_OR_VOID,
    AST_STRUCT_UNION,
    AST_TYPE_REFERENCE,
    AST_DRIVE_STRENGTH,
    AST_STRENGTH0,
    AST_STRENGTH1,
    AST_CHARGE_STRENGTH,
    AST_DELAY3,
    AST_DELAY2,
    AST_DELAY_VALUE,
    AST_LIST_OF_DEFPARAM_ASSIGNMENTS,
    AST_LIST_OF_GENVAR_IDENTIFIERS,
    AST_LIST_OF_INTERFACE_IDENTIFIERS,
    AST_LIST_OF_NET_DECL_ASSIGNMENTS,
    AST_LIST_OF_PARAM_ASSIGNMENTS,
    AST_LIST_OF_PORT_IDENTIFIERS,
    AST_LIST_OF_UDP_PORT_IDENTIFIERS,
    AST_LIST_OF_SPECPARAM_ASSIGNMENTS,
    AST_LIST_OF_TF_VARIABLE_IDENTIFIERS,
    AST_LIST_OF_TYPE_ASSIGNMENTS,
    AST_LIST_OF_VARIABLE_DECL_ASSIGNMENTS,
    AST_LIST_OF_VARIABLE_IDENTIFIERS,
    AST_LIST_OF_VARIABLE_PORT_IDENTIFIERS,
    AST_DEFPARAM_ASSIGNMENT,
    AST_NET_DECL_ASSIGNMENT,
    AST_PARAM_ASSIGNMENT,
    AST_SPECPARAM_ASSIGNMENT,
    AST_TYPE_ASSIGNMENT,
    AST_PULSE_CONTROL_SPECPARAM,
    AST_ERROR_LIMIT_VALUE,
    AST_REJECT_LIMIT_VALUE,
    AST_LIMIT_VALUE,
    AST_VARIABLE_DECL_ASSIGNMENT,
    AST_CLASS_NEW,
    AST_DYNAMIC_ARRAY_NEW,
    AST_UNPACKED_DIMENSION,
    AST_PACKED_DIMENSION,
    AST_ASSOCIATIVE_DIMENSION,
    AST_VARIABLE_DIMENSION,
    AST_QUEUE_DIMENSION,
    AST_UNSIZED_DIMENSION,
    AST_FUNCTION_DATA_TYPE_OR_IMPLICIT,
    AST_FUNCTION_DECLARATION,
    AST_FUNCTION_BODY_DECLARATION,
    AST_FUNCTION_PROTOTYPE,
    AST_DPI_IMPORT_EXPORT,
    AST_DPI_SPEC_STRING,
    AST_DPI_FUNCTION_IMPORT_PROPERTY,
    AST_DPI_TASK_IMPORT_PROPERTY,
    AST_DPI_FUNCTION_PROTO,
    AST_DPI_TASK_PROTO,
    AST_TASK_DECLARATION,
    AST_TASK_BODY_DECLARATION,
    AST_TF_ITEM_DECLARATION,
    AST_TF_PORT_LIST,
    AST_TF_PORT_ITEM,
    AST_TF_PORT_DIRECTION,
    AST_TF_PORT_DECLARATION,
    AST_TASK_PROTOTYPE,
    AST_BLOCK_ITEM_DECLARATION,
    AST_OVERLOAD_DECLARATION,
    AST_OVERLOAD_OPERATOR,
    AST_OVERLOAD_PROTO_FORMALS,
    AST_MODPORT_DECLARATION,
    AST_MODPORT_ITEM,
    AST_MODPORT_PORTS_DECLARATION,
    AST_MODPORT_CLOCKING_DECLARATION,
    AST_MODPORT_SIMPLE_PORTS_DECLARATION,
    AST_MODPORT_SIMPLE_PORT,
    AST_MODPORT_TF_PORTS_DECLARATION,
    AST_MODPORT_TF_PORT,
    AST_IMPORT_EXPORT,
    AST_CONCURRENT_ASSERTION_ITEM,
    AST_CONCURRENT_ASSERTION_STATEMENT,
    AST_ASSERT_PROPERTY_STATEMENT,
    AST_ASSUME_PROPERTY_STATEMENT,
    AST_COVER_PROPERTY_STATEMENT,
    AST_EXPECT_PROPERTY_STATEMENT,
    AST_COVER_SEQUENCE_STATEMENT,
    AST_RESTRICT_PROPERTY_STATEMENT,
    AST_PROPERTY_INSTANCE,
    AST_PROPERTY_LIST_OF_ARGUMENTS,
    AST_PROPERTY_ACTUAL_ARG,
    AST_ASSERTION_ITEM_DECLARATION,
    AST_PROPERTY_DECLARATION,
    AST_PROPERTY_PORT_LIST,
    AST_PROPERTY_PORT_ITEM,
    AST_PROPERTY_LVAR_PORT_DIRECTION,
    AST_PROPERTY_FORMAL_TYPE,
    AST_PROPERTY_SPEC,
    AST_PROPERTY_EXPR,
    AST_PROPERTY_CASE_ITEM,
    AST_SEQUENCE_DECLARATION,
    AST_SEQUENCE_PORT_LIST,
    AST_SEQUENCE_PORT_ITEM,
    AST_SEQUENCE_LVAR_PORT_DIRECTION,
    AST_SEQUENCE_FORMAL_TYPE,
    AST_SEQUENCE_EXPR,
    AST_CYCLE_DELAY_RANGE,
    AST_SEQUENCE_METHOD_CALL,
    AST_SEQUENCE_MATCH_ITEM,
    AST_SEQUENCE_INSTANCE,
    AST_SEQUENCE_LIST_OF_ARGUMENTS,
    AST_SEQUENCE_ACTUAL_ARG,
    AST_BOOLEAN_ABBREV,
    AST_SEQUENCE_ABBREV,
    AST_CONSECUTIVE_REPETITION,
    AST_NON_CONSECUTIVE_REPETITION,
    AST_GOTO_REPETITION,
    AST_CONST_OR_RANGE_EXPRESSION,
    AST_CYCLE_DELAY_CONST_RANGE_EXPRESSION,
    AST_EXPRESSION_OR_DIST,
    AST_ASSERTION_VARIABLE_DECLARATION,
    AST_LET_DECLARATION,
    AST_LET_IDENTIFIER,
    AST_LET_PORT_LIST,
    AST_LET_PORT_ITEM,
    AST_LET_FORMAL_TYPE,
    AST_LET_EXPRESSION,
    AST_LET_LIST_OF_ARGUMENTS,
    AST_LET_ACTUAL_ARG,
    AST_COVERGROUP_DECLARATION,
    AST_COVERAGE_SPEC_OR_OPTION,
    AST_COVERAGE_OPTION,
    AST_COVERAGE_SPEC,
    AST_COVERAGE_EVENT,
    AST_BLOCK_EVENT_EXPRESSION,
    AST_HIERARCHICAL_BTF_IDENTIFIER,
    AST_COVER_POINT,
    AST_BINS_OR_EMPTY,
    AST_BINS_OR_OPTIONS,
    AST_BINS_KEYWORD,
    AST_TRANS_LIST,
    AST_TRANS_SET,
    AST_TRANS_RANGE_LIST,
    AST_TRANS_ITEM,
    AST_REPEAT_RANGE,
    AST_COVER_CROSS,
    AST_LIST_OF_CROSS_ITEMS,
    AST_CROSS_ITEM,
    AST_CROSS_BODY,
    AST_CROSS_BODY_ITEM,
    AST_BINS_SELECTION_OR_OPTION,
    AST_BINS_SELECTION,
    AST_SELECT_EXPRESSION,
    AST_SELECT_CONDITION,
    AST_BINS_EXPRESSION,
    AST_COVERGROUP_RANGE_LIST,
    AST_COVERGROUP_VALUE_RANGE,
    AST_WITH_COVERGROUP_EXPRESSION,
    AST_SET_COVERGROUP_EXPRESSION,
    AST_INTEGER_COVERGROUP_EXPRESSION,
    AST_CROSS_SET_EXPRESSION,
    AST_COVERGROUP_EXPRESSION,
    AST_GATE_INSTANTIATION,
    AST_CMOS_SWITCH_INSTANCE,
    AST_ENABLE_GATE_INSTANCE,
    AST_MOS_SWITCH_INSTANCE,
    AST_N_INPUT_GATE_INSTANCE,
    AST_N_OUTPUT_GATE_INSTANCE,
    AST_PASS_SWITCH_INSTANCE,
    AST_PASS_ENABLE_SWITCH_INSTANCE,
    AST_PULL_GATE_INSTANCE,
    AST_PULLDOWN_STRENGTH,
    AST_PULLUP_STRENGTH,
    AST_ENABLE_TERMINAL,
    AST_INOUT_TERMINAL,
    AST_INPUT_TERMINAL,
    AST_NCONTROL_TERMINAL,
    AST_OUTPUT_TERMINAL,
    AST_PCONTROL_TERMINAL,
    AST_CMOS_SWITCHTYPE,
    AST_ENABLE_GATETYPE,
    AST_MOS_SWITCHTYPE,
    AST_N_INPUT_GATETYPE,
    AST_N_OUTPUT_GATETYPE,
    AST_PASS_EN_SWITCHTYPE,
    AST_PASS_SWITCHTYPE,
    AST_MODULE_INSTANTIATION,
    AST_PARAMETER_VALUE_ASSIGNMENT,
    AST_LIST_OF_PARAMETER_ASSIGNMENTS,
    AST_ORDERED_PARAMETER_ASSIGNMENT,
    AST_NAMED_PARAMETER_ASSIGNMENT,
    AST_HIERARCHICAL_INSTANCE,
    AST_NAME_OF_INSTANCE,
    AST_LIST_OF_PORT_CONNECTIONS,
    AST_ORDERED_PORT_CONNECTION,
    AST_NAMED_PORT_CONNECTION,
    AST_INTERFACE_INSTANTIATION,
    AST_PROGRAM_INSTANTIATION,
    AST_CHECKER_INSTANTIATION,
    AST_LIST_OF_CHECKER_PORT_CONNECTIONS,
    AST_ORDERED_CHECKER_PORT_CONNECTION,
    AST_NAMED_CHECKER_PORT_CONNECTION,
    AST_GENERATE_REGION,
    AST_LOOP_GENERATE_CONSTRUCT,
    AST_GENVAR_INITIALIZATION,
    AST_GENVAR_ITERATION,
    AST_CONDITIONAL_GENERATE_CONSTRUCT,
    AST_IF_GENERATE_CONSTRUCT,
    AST_CASE_GENERATE_CONSTRUCT,
    AST_CASE_GENERATE_ITEM,
    AST_GENERATE_BLOCK,
    AST_GENERATE_ITEM,
    AST_UDP_NONANSI_DECLARATION,
    AST_UDP_ANSI_DECLARATION,
    AST_UDP_DECLARATION,
    AST_UDP_PORT_LIST,
    AST_UDP_DECLARATION_PORT_LIST,
    AST_UDP_PORT_DECLARATION,
    AST_UDP_OUTPUT_DECLARATION,
    AST_UDP_INPUT_DECLARATION,
    AST_UDP_REG_DECLARATION,
    AST_UDP_BODY,
    AST_COMBINATIONAL_BODY,
    AST_COMBINATIONAL_ENTRY,
    AST_SEQUENTIAL_BODY,
    AST_UDP_INITIAL_STATEMENT,
    AST_INIT_VAL,
    AST_SEQUENTIAL_ENTRY,
    AST_SEQ_INPUT_LIST,
    AST_LEVEL_INPUT_LIST,
    AST_EDGE_INPUT_LIST,
    AST_EDGE_INDICATOR,
    AST_CURRENT_STATE,
    AST_NEXT_STATE,
    AST_OUTPUT_SYMBOL,
    AST_LEVEL_SYMBOL,
    AST_EDGE_SYMBOL,
    AST_UDP_INSTANTIATION,
    AST_UDP_INSTANCE,
    AST_CONTINUOUS_ASSIGN,
    AST_LIST_OF_NET_ASSIGNMENTS,
    AST_LIST_OF_VARIABLE_ASSIGNMENTS,
    AST_NET_ALIAS,
    AST_NET_ASSIGNMENT,
    AST_INITIAL_CONSTRUCT,
    AST_ALWAYS_CONSTRUCT,
    AST_ALWAYS_KEYWORD,
    AST_FINAL_CONSTRUCT,
    AST_BLOCKING_ASSIGNMENT,
    AST_OPERATOR_ASSIGNMENT,
    AST_ASSIGNMENT_OPERATOR,
    AST_NONBLOCKING_ASSIGNMENT,
    AST_PROCEDURAL_CONTINUOUS_ASSIGNMENT,
    AST_VARIABLE_ASSIGNMENT,
    AST_ACTION_BLOCK,
    AST_SEQ_BLOCK,
    AST_PAR_BLOCK,
    AST_JOIN_KEYWORD,
    AST_STATEMENT_OR_NULL,
    AST_STATEMENT,
    AST_STATEMENT_ITEM,
    AST_FUNCTION_STATEMENT,
    AST_FUNCTION_STATEMENT_OR_NULL,
    AST_VARIABLE_IDENTIFIER_LIST,
    AST_PROCEDURAL_TIMING_CONTROL_STATEMENT,
    AST_DELAY_OR_EVENT_CONTROL,
    AST_DELAY_CONTROL,
    AST_EVENT_CONTROL,
    AST_EVENT_EXPRESSION,
    AST_PROCEDURAL_TIMING_CONTROL,
    AST_JUMP_STATEMENT,
    AST_WAIT_STATEMENT,
    AST_EVENT_TRIGGER,
    AST_DISABLE_STATEMENT,
    AST_CONDITIONAL_STATEMENT,
    AST_UNIQUE_PRIORITY,
    AST_COND_PREDICATE,
    AST_EXPRESSION_OR_COND_PATTERN,
    AST_COND_PATTERN,
    AST_CASE_STATEMENT,
    AST_CASE_KEYWORD,
    AST_CASE_EXPRESSION,
    AST_CASE_ITEM,
    AST_CASE_PATTERN_ITEM,
    AST_CASE_INSIDE_ITEM,
    AST_CASE_ITEM_EXPRESSION,
    AST_RANDCASE_STATEMENT,
    AST_RANDCASE_ITEM,
    AST_OPEN_RANGE_LIST,
    AST_OPEN_VALUE_RANGE,
    AST_PATTERN,
    AST_ASSIGNMENT_PATTERN,
    AST_STRUCTURE_PATTERN_KEY,
    AST_ARRAY_PATTERN_KEY,
    AST_ASSIGNMENT_PATTERN_KEY,
    AST_ASSIGNMENT_PATTERN_EXPRESSION,
    AST_ASSIGNMENT_PATTERN_EXPRESSION_TYPE,
    AST_CONSTANT_ASSIGNMENT_PATTERN_EXPRESSION,
    AST_ASSIGNMENT_PATTERN_NET_LVALUE,
    AST_ASSIGNMENT_PATTERN_VARIABLE_LVALUE,
    AST_LOOP_STATEMENT,
    AST_FOR_INITIALIZATION,
    AST_FOR_VARIABLE_DECLARATION,
    AST_FOR_STEP,
    AST_FOR_STEP_ASSIGNMENT,
    AST_LOOP_VARIABLES,
    AST_SUBROUTINE_CALL_STATEMENT,
    AST_ASSERTION_ITEM,
    AST_DEFERRED_IMMEDIATE_ASSERTION_ITEM,
    AST_PROCEDURAL_ASSERTION_STATEMENT,
    AST_IMMEDIATE_ASSERTION_STATEMENT,
    AST_SIMPLE_IMMEDIATE_ASSERTION_STATEMENT,
    AST_SIMPLE_IMMEDIATE_ASSERT_STATEMENT,
    AST_SIMPLE_IMMEDIATE_ASSUME_STATEMENT,
    AST_SIMPLE_IMMEDIATE_COVER_STATEMENT,
    AST_DEFERRED_IMMEDIATE_ASSERTION_STATEMENT,
    AST_DEFERRED_IMMEDIATE_ASSERT_STATEMENT,
    AST_DEFERRED_IMMEDIATE_ASSUME_STATEMENT,
    AST_DEFERRED_IMMEDIATE_COVER_STATEMENT,
    AST_CLOCKING_DECLARATION,
    AST_CLOCKING_EVENT,
    AST_CLOCKING_ITEM,
    AST_DEFAULT_SKEW,
    AST_CLOCKING_DIRECTION,
    AST_LIST_OF_CLOCKING_DECL_ASSIGN,
    AST_CLOCKING_DECL_ASSIGN,
    AST_CLOCKING_SKEW,
    AST_CLOCKING_DRIVE,
    AST_CYCLE_DELAY,
    AST_CLOCKVAR,
    AST_CLOCKVAR_EXPRESSION,
    AST_RANDSEQUENCE_STATEMENT,
    AST_PRODUCTION,
    AST_RS_RULE,
    AST_RS_PRODUCTION_LIST,
    AST_WEIGHT_SPECIFICATION,
    AST_RS_CODE_BLOCK,
    AST_RS_PROD,
    AST_PRODUCTION_ITEM,
    AST_RS_IF_ELSE,
    AST_RS_REPEAT,
    AST_RS_CASE,
    AST_RS_CASE_ITEM,
    AST_SPECIFY_BLOCK,
    AST_SPECIFY_ITEM,
    AST_PULSESTYLE_DECLARATION,
    AST_SHOWCANCELLED_DECLARATION,
    AST_PATH_DECLARATION,
    AST_SIMPLE_PATH_DECLARATION,
    AST_PARALLEL_PATH_DESCRIPTION,
    AST_FULL_PATH_DESCRIPTION,
    AST_LIST_OF_PATH_INPUTS,
    AST_LIST_OF_PATH_OUTPUTS,
    AST_SPECIFY_INPUT_TERMINAL_DESCRIPTOR,
    AST_SPECIFY_OUTPUT_TERMINAL_DESCRIPTOR,
    AST_INPUT_IDENTIFIER,
    AST_OUTPUT_IDENTIFIER,
    AST_PATH_DELAY_VALUE,
    AST_LIST_OF_PATH_DELAY_EXPRESSIONS,
    AST_T_PATH_DELAY_EXPRESSION,
    AST_TRISE_PATH_DELAY_EXPRESSION,
    AST_TFALL_PATH_DELAY_EXPRESSION,
    AST_TZ_PATH_DELAY_EXPRESSION,
    AST_T01_PATH_DELAY_EXPRESSION,
    AST_T10_PATH_DELAY_EXPRESSION,
    AST_T0Z_PATH_DELAY_EXPRESSION,
    AST_TZ1_PATH_DELAY_EXPRESSION,
    AST_T1Z_PATH_DELAY_EXPRESSION,
    AST_TZ0_PATH_DELAY_EXPRESSION,
    AST_T0X_PATH_DELAY_EXPRESSION,
    AST_TX1_PATH_DELAY_EXPRESSION,
    AST_T1X_PATH_DELAY_EXPRESSION,
    AST_TX0_PATH_DELAY_EXPRESSION,
    AST_TXZ_PATH_DELAY_EXPRESSION,
    AST_TZX_PATH_DELAY_EXPRESSION,
    AST_PATH_DELAY_EXPRESSION,
    AST_EDGE_SENSITIVE_PATH_DECLARATION,
    AST_PARALLEL_EDGE_SENSITIVE_PATH_DESCRIPTION,
    AST_FULL_EDGE_SENSITIVE_PATH_DESCRIPTION,
    AST_DATA_SOURCE_EXPRESSION,
    AST_EDGE_IDENTIFIER,
    AST_STATE_DEPENDENT_PATH_DECLARATION,
    AST_POLARITY_OPERATOR,
    AST_SYSTEM_TIMING_CHECK,
    AST_DOLLARSIGN_SETUP_TIMING_CHECK,
    AST_DOLLARSIGN_HOLD_TIMING_CHECK,
    AST_DOLLARSIGN_SETUPHOLD_TIMING_CHECK,
    AST_DOLLARSIGN_RECOVERY_TIMING_CHECK,
    AST_DOLLARSIGN_REMOVAL_TIMING_CHECK,
    AST_DOLLARSIGN_RECREM_TIMING_CHECK,
    AST_DOLLARSIGN_SKEW_TIMING_CHECK,
    AST_DOLLARSIGN_TIMESKEW_TIMING_CHECK,
    AST_DOLLARSIGN_FULLSKEW_TIMING_CHECK,
    AST_DOLLARSIGN_PERIOD_TIMING_CHECK,
    AST_DOLLARSIGN_WIDTH_TIMING_CHECK,
    AST_DOLLARSIGN_NOCHANGE_TIMING_CHECK,
    AST_TIMECHECK_CONDITION,
    AST_CONTROLLED_REFERENCE_EVENT,
    AST_DATA_EVENT,
    AST_DELAYED_DATA,
    AST_DELAYED_REFERENCE,
    AST_END_EDGE_OFFSET,
    AST_EVENT_BASED_FLAG,
    AST_NOTIFIER,
    AST_REFERENCE_EVENT,
    AST_REMAIN_ACTIVE_FLAG,
    AST_TIMESTAMP_CONDITION,
    AST_START_EDGE_OFFSET,
    AST_THRESHOLD,
    AST_TIMING_CHECK_LIMIT,
    AST_TIMING_CHECK_EVENT,
    AST_CONTROLLED_TIMING_CHECK_EVENT,
    AST_TIMING_CHECK_EVENT_CONTROL,
    AST_SPECIFY_TERMINAL_DESCRIPTOR,
    AST_EDGE_CONTROL_SPECIFIER,
    AST_EDGE_DESCRIPTOR,
    AST_ZERO_OR_ONE,
    AST_Z_OR_X,
    AST_TIMING_CHECK_CONDITION,
    AST_SCALAR_TIMING_CHECK_CONDITION,
    AST_SCALAR_CONSTANT,
    AST_CONCATENATION,
    AST_CONSTANT_CONCATENATION,
    AST_CONSTANT_MULTIPLE_CONCATENATION,
    AST_MODULE_PATH_CONCATENATION,
    AST_MODULE_PATH_MULTIPLE_CONCATENATION,
    AST_MULTIPLE_CONCATENATION,
    AST_STREAMING_CONCATENATION,
    AST_STREAM_OPERATOR,
    AST_SLICE_SIZE,
    AST_STREAM_CONCATENATION,
    AST_STREAM_EXPRESSION,
    AST_ARRAY_RANGE_EXPRESSION,
    AST_EMPTY_QUEUE,
    AST_CONSTANT_FUNCTION_CALL,
    AST_TF_CALL,
    AST_SYSTEM_TF_CALL,
    AST_SUBROUTINE_CALL,
    AST_FUNCTION_SUBROUTINE_CALL,
    AST_LIST_OF_ARGUMENTS,
    AST_METHOD_CALL,
    AST_METHOD_CALL_BODY,
    AST_BUILT_IN_METHOD_CALL,
    AST_ARRAY_MANIPULATION_CALL,
    AST_RANDOMIZE_CALL,
    AST_METHOD_CALL_ROOT,
    AST_ARRAY_METHOD_NAME,
    AST_INC_OR_DEC_EXPRESSION,
    AST_CONDITIONAL_EXPRESSION,
    AST_CONSTANT_EXPRESSION,
    AST_CONSTANT_MINTYPMAX_EXPRESSION,
    AST_CONSTANT_PARAM_EXPRESSION,
    AST_PARAM_EXPRESSION,
    AST_CONSTANT_RANGE_EXPRESSION,
    AST_CONSTANT_PART_SELECT_RANGE,
    AST_CONSTANT_RANGE,
    AST_CONSTANT_INDEXED_RANGE,
    AST_EXPRESSION,
    AST_TAGGED_UNION_EXPRESSION,
    AST_INSIDE_EXPRESSION,
    AST_VALUE_RANGE,
    AST_MINTYPMAX_EXPRESSION,
    AST_MODULE_PATH_CONDITIONAL_EXPRESSION,
    AST_MODULE_PATH_EXPRESSION,
    AST_MODULE_PATH_MINTYPMAX_EXPRESSION,
    AST_PART_SELECT_RANGE,
    AST_INDEXED_RANGE,
    AST_GENVAR_EXPRESSION,
    AST_CONSTANT_PRIMARY,
    AST_MODULE_PATH_PRIMARY,
    AST_PRIMARY,
    AST_CLASS_QUALIFIER,
    AST_RANGE_EXPRESSION,
    AST_PRIMARY_LITERAL,
    AST_TIME_LITERAL,
    AST_TIME_UNIT,
    AST_IMPLICIT_CLASS_HANDLE,
    AST_BIT_SELECT,
    AST_SELECT,
    AST_NONRANGE_SELECT,
    AST_CONSTANT_BIT_SELECT,
    AST_CONSTANT_SELECT,
    AST_CONSTANT_CAST,
    AST_CONSTANT_LET_EXPRESSION,
    AST_CAST,
    AST_NET_LVALUE,
    AST_VARIABLE_LVALUE,
    AST_NONRANGE_VARIABLE_LVALUE,
    AST_UNARY_OPERATOR,
    AST_BINARY_OPERATOR,
    AST_INC_OR_DEC_OPERATOR,
    AST_UNARY_MODULE_PATH_OPERATOR,
    AST_BINARY_MODULE_PATH_OPERATOR,
    AST_NUMBER,
    AST_INTEGRAL_NUMBER,
    AST_DECIMAL_NUMBER,
    AST_OCTAL_NUMBER,
    AST_BINARY_NUMBER,
    AST_HEX_NUMBER,
    AST_UNSIGNED_NUMBER,
    AST_REAL_NUMBER,
    AST_FIXED_POINT_NUMBER,
    AST_UNBASED_UNSIZED_LITERAL,
    AST_STRING_LITERAL,
    AST_ATTRIBUTE_INSTANCE,
    AST_ATTR_SPEC,
    AST_ATTR_NAME,
    AST_BLOCK_IDENTIFIER,
    AST_BIN_IDENTIFIER,
    AST_C_IDENTIFIER,
    AST_CELL_IDENTIFIER,
    AST_CHECKER_IDENTIFIER,
    AST_CLASS_IDENTIFIER,
    AST_CLASS_VARIABLE_IDENTIFIER,
    AST_CLOCKING_IDENTIFIER,
    AST_CONFIG_IDENTIFIER,
    AST_CONST_IDENTIFIER,
    AST_CONSTRAINT_IDENTIFIER,
    AST_COVERGROUP_IDENTIFIER,
    AST_COVER_POINT_IDENTIFIER,
    AST_CROSS_IDENTIFIER,
    AST_DYNAMIC_ARRAY_VARIABLE_IDENTIFIER,
    AST_ENUM_IDENTIFIER,
    AST_ESCAPED_IDENTIFIER,
    AST_FORMAL_PORT_IDENTIFIER,
    AST_FUNCTION_IDENTIFIER,
    AST_GENERATE_BLOCK_IDENTIFIER,
    AST_GENVAR_IDENTIFIER,
    AST_HIERARCHICAL_ARRAY_IDENTIFIER,
    AST_HIERARCHICAL_BLOCK_IDENTIFIER,
    AST_HIERARCHICAL_EVENT_IDENTIFIER,
    AST_HIERARCHICAL_IDENTIFIER,
    AST_HIERARCHICAL_NET_IDENTIFIER,
    AST_HIERARCHICAL_PARAMETER_IDENTIFIER,
    AST_HIERARCHICAL_PROPERTY_IDENTIFIER,
    AST_HIERARCHICAL_SEQUENCE_IDENTIFIER,
    AST_HIERARCHICAL_TASK_IDENTIFIER,
    AST_HIERARCHICAL_TF_IDENTIFIER,
    AST_HIERARCHICAL_VARIABLE_IDENTIFIER,
    AST_IDENTIFIER,
    AST_INDEX_VARIABLE_IDENTIFIER,
    AST_INTERFACE_IDENTIFIER,
    AST_INTERFACE_INSTANCE_IDENTIFIER,
    AST_INOUT_PORT_IDENTIFIER,
    AST_INPUT_PORT_IDENTIFIER,
    AST_INSTANCE_IDENTIFIER,
    AST_LIBRARY_IDENTIFIER,
    AST_MEMBER_IDENTIFIER,
    AST_METHOD_IDENTIFIER,
    AST_MODPORT_IDENTIFIER,
    AST_MODULE_IDENTIFIER,
    AST_NET_IDENTIFIER,
    AST_NET_TYPE_IDENTIFIER,
    AST_OUTPUT_PORT_IDENTIFIER,
    AST_PACKAGE_IDENTIFIER,
    AST_PACKAGE_SCOPE,
    AST_PARAMETER_IDENTIFIER,
    AST_PORT_IDENTIFIER,
    AST_PRODUCTION_IDENTIFIER,
    AST_PROGRAM_IDENTIFIER,
    AST_PROPERTY_IDENTIFIER,
    AST_PS_CLASS_IDENTIFIER,
    AST_PS_COVERGROUP_IDENTIFIER,
    AST_PS_CHECKER_IDENTIFIER,
    AST_PS_IDENTIFIER,
    AST_PS_OR_HIERARCHICAL_ARRAY_IDENTIFIER,
    AST_PS_OR_HIERARCHICAL_NET_IDENTIFIER,
    AST_PS_OR_HIERARCHICAL_PROPERTY_IDENTIFIER,
    AST_PS_OR_HIERARCHICAL_SEQUENCE_IDENTIFIER,
    AST_PS_OR_HIERARCHICAL_TF_IDENTIFIER,
    AST_PS_PARAMETER_IDENTIFIER,
    AST_PS_TYPE_IDENTIFIER,
    AST_SEQUENCE_IDENTIFIER,
    AST_SIGNAL_IDENTIFIER,
    AST_SIMPLE_IDENTIFIER,
    AST_SPECPARAM_IDENTIFIER,
    AST_SYSTEM_TF_IDENTIFIER,
    AST_TASK_IDENTIFIER,
    AST_TF_IDENTIFIER,
    AST_TERMINAL_IDENTIFIER,
    AST_TOPMODULE_IDENTIFIER,
    AST_TYPE_IDENTIFIER,
    AST_UDP_IDENTIFIER,
    AST_VARIABLE_IDENTIFIER,
    AST_FILE_PATH_SPEC,
} ast_type;



class object {
    ast_type _type;

public:
    // 
    object(ast_type type): _type(type) { }
    // 
    virtual ~object() { }
    
    // 
    ast_type type() const { return _type; }
    
    // 
    virtual void describe(FILE *out) {
        // throw Exception("NOT IMPLEMENTED");
    }
    // 
    virtual std::string glance(FILE *out) {
        // throw Exception("NOT IMPLEMENTED");
        return std::string("NOT IMPLEMENTED");
    }
    // 
    virtual void action(FILE *out) {
        // throw Exception("NOT IMPLEMENTED");
    }
    // 
    virtual int compare(const object *p2) const {
        return this == p2;
    }
    // 
    static int compare(const object *p1, const object *p2) {
        return p1->compare(p2);
    }
};



// 
template <class Type>
class list: public object {
    std::vector<object *> _vector;

public:
    list()
        : object(AST_LIST)
    {
    }
    ~list() {
        
    }
    
    // 
    int count() const { return _vector.size(); }
    
    // 
    void describe(FILE *out) {
        
    }
    // 
    std::string glance(FILE *out) {
        return std::string("NOT IMPLEMENTED");
    }
    // 
    void action(FILE *out) {
        
    }
    
    // 
    int compare(const list *p2) const {
        return -1;
    }
    // 
    virtual int compare(const object *p2) const {
        return compare(dynamic_cast<const list *>(p2));
    }
    // 
    static int compare(const list *p1, const list *p2) {
        return p1->compare(p2);
    }
    
    // 
    void append(object *o) {
        _vector.push_back(o);
    }
    typename     std::vector<Type>::iterator first() {
        return _vector.begin();
    }
    typename     std::vector<Type>::const_iterator first() const {
        return _vector.begin();
    }
};



// 
class library_text: public object {
    ast_type                        type;
    
public: 
    // 
    library_text(): object(AST_LIBRARY_TEXT) {
        
    }
    ~library_text() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class library_description: public object {
    ast_type                        type;
    
public: 
    // 
    library_description(): object(AST_LIBRARY_DESCRIPTION) {
        
    }
    ~library_description() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class library_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    library_declaration(): object(AST_LIBRARY_DECLARATION) {
        
    }
    ~library_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class include_statement: public object {
    ast_type                        type;
    
public: 
    // 
    include_statement(): object(AST_INCLUDE_STATEMENT) {
        
    }
    ~include_statement() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class source_text: public object {
    ast_type                        type;
    
public: 
    // 
    source_text(): object(AST_SOURCE_TEXT) {
        
    }
    ~source_text() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class description: public object {
    ast_type                        type;
    
public: 
    // 
    description(): object(AST_DESCRIPTION) {
        
    }
    ~description() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class module_nonansi_header: public object {
    ast_type                        type;
    
public: 
    // 
    module_nonansi_header(): object(AST_MODULE_NONANSI_HEADER) {
        
    }
    ~module_nonansi_header() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class module_ansi_header: public object {
    ast_type                        type;
    
public: 
    // 
    module_ansi_header(): object(AST_MODULE_ANSI_HEADER) {
        
    }
    ~module_ansi_header() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class module_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    module_declaration(): object(AST_MODULE_DECLARATION) {
        
    }
    ~module_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class module_keyword: public object {
    ast_type                        type;
    
public: 
    // 
    module_keyword(): object(AST_MODULE_KEYWORD) {
        
    }
    ~module_keyword() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class interface_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    interface_declaration(): object(AST_INTERFACE_DECLARATION) {
        
    }
    ~interface_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class interface_nonansi_header: public object {
    ast_type                        type;
    
public: 
    // 
    interface_nonansi_header(): object(AST_INTERFACE_NONANSI_HEADER) {
        
    }
    ~interface_nonansi_header() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class interface_ansi_header: public object {
    ast_type                        type;
    
public: 
    // 
    interface_ansi_header(): object(AST_INTERFACE_ANSI_HEADER) {
        
    }
    ~interface_ansi_header() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class program_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    program_declaration(): object(AST_PROGRAM_DECLARATION) {
        
    }
    ~program_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class program_nonansi_header: public object {
    ast_type                        type;
    
public: 
    // 
    program_nonansi_header(): object(AST_PROGRAM_NONANSI_HEADER) {
        
    }
    ~program_nonansi_header() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class program_ansi_header: public object {
    ast_type                        type;
    
public: 
    // 
    program_ansi_header(): object(AST_PROGRAM_ANSI_HEADER) {
        
    }
    ~program_ansi_header() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class checker_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    checker_declaration(): object(AST_CHECKER_DECLARATION) {
        
    }
    ~checker_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class class_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    class_declaration(): object(AST_CLASS_DECLARATION) {
        
    }
    ~class_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class interface_class_type: public object {
    ast_type                        type;
    
public: 
    // 
    interface_class_type(): object(AST_INTERFACE_CLASS_TYPE) {
        
    }
    ~interface_class_type() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class package_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    package_declaration(): object(AST_PACKAGE_DECLARATION) {
        
    }
    ~package_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class timeunits_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    timeunits_declaration(): object(AST_TIMEUNITS_DECLARATION) {
        
    }
    ~timeunits_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class parameter_port_list: public object {
    ast_type                        type;
    
public: 
    // 
    parameter_port_list(): object(AST_PARAMETER_PORT_LIST) {
        
    }
    ~parameter_port_list() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class parameter_port_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    parameter_port_declaration(): object(AST_PARAMETER_PORT_DECLARATION) {
        
    }
    ~parameter_port_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class list_of_ports: public object {
    ast_type                        type;
    
public: 
    // 
    list_of_ports(): object(AST_LIST_OF_PORTS) {
        
    }
    ~list_of_ports() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class list_of_port_declarations: public object {
    ast_type                        type;
    
public: 
    // 
    list_of_port_declarations(): object(AST_LIST_OF_PORT_DECLARATIONS) {
        
    }
    ~list_of_port_declarations() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class port_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    port_declaration(): object(AST_PORT_DECLARATION) {
        
    }
    ~port_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class port: public object {
    ast_type                        type;
    
public: 
    // 
    port(): object(AST_PORT) {
        
    }
    ~port() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class port_expression: public object {
    ast_type                        type;
    
public: 
    // 
    port_expression(): object(AST_PORT_EXPRESSION) {
        
    }
    ~port_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class port_reference: public object {
    ast_type                        type;
    
public: 
    // 
    port_reference(): object(AST_PORT_REFERENCE) {
        
    }
    ~port_reference() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class port_direction: public object {
    ast_type                        type;
    
public: 
    // 
    port_direction(): object(AST_PORT_DIRECTION) {
        
    }
    ~port_direction() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class net_port_header: public object {
    ast_type                        type;
    
public: 
    // 
    net_port_header(): object(AST_NET_PORT_HEADER) {
        
    }
    ~net_port_header() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class variable_port_header: public object {
    ast_type                        type;
    
public: 
    // 
    variable_port_header(): object(AST_VARIABLE_PORT_HEADER) {
        
    }
    ~variable_port_header() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class interface_port_header: public object {
    ast_type                        type;
    
public: 
    // 
    interface_port_header(): object(AST_INTERFACE_PORT_HEADER) {
        
    }
    ~interface_port_header() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class ansi_port_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    ansi_port_declaration(): object(AST_ANSI_PORT_DECLARATION) {
        
    }
    ~ansi_port_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class elaboration_system_task: public object {
    ast_type                        type;
    
public: 
    // 
    elaboration_system_task(): object(AST_ELABORATION_SYSTEM_TASK) {
        
    }
    ~elaboration_system_task() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class finish_number: public object {
    ast_type                        type;
    
public: 
    // 
    finish_number(): object(AST_FINISH_NUMBER) {
        
    }
    ~finish_number() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class module_common_item: public object {
    ast_type                        type;
    
public: 
    // 
    module_common_item(): object(AST_MODULE_COMMON_ITEM) {
        
    }
    ~module_common_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class module_item: public object {
    ast_type                        type;
    
public: 
    // 
    module_item(): object(AST_MODULE_ITEM) {
        
    }
    ~module_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class module_or_generate_item: public object {
    ast_type                        type;
    
public: 
    // 
    module_or_generate_item(): object(AST_MODULE_OR_GENERATE_ITEM) {
        
    }
    ~module_or_generate_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class module_or_generate_item_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    module_or_generate_item_declaration(): object(AST_MODULE_OR_GENERATE_ITEM_DECLARATION) {
        
    }
    ~module_or_generate_item_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class non_port_module_item: public object {
    ast_type                        type;
    
public: 
    // 
    non_port_module_item(): object(AST_NON_PORT_MODULE_ITEM) {
        
    }
    ~non_port_module_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class parameter_override: public object {
    ast_type                        type;
    
public: 
    // 
    parameter_override(): object(AST_PARAMETER_OVERRIDE) {
        
    }
    ~parameter_override() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class bind_directive: public object {
    ast_type                        type;
    
public: 
    // 
    bind_directive(): object(AST_BIND_DIRECTIVE) {
        
    }
    ~bind_directive() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class bind_target_scope: public object {
    ast_type                        type;
    
public: 
    // 
    bind_target_scope(): object(AST_BIND_TARGET_SCOPE) {
        
    }
    ~bind_target_scope() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class bind_target_instance: public object {
    ast_type                        type;
    
public: 
    // 
    bind_target_instance(): object(AST_BIND_TARGET_INSTANCE) {
        
    }
    ~bind_target_instance() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class bind_target_instance_list: public object {
    ast_type                        type;
    
public: 
    // 
    bind_target_instance_list(): object(AST_BIND_TARGET_INSTANCE_LIST) {
        
    }
    ~bind_target_instance_list() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class bind_instantiation: public object {
    ast_type                        type;
    
public: 
    // 
    bind_instantiation(): object(AST_BIND_INSTANTIATION) {
        
    }
    ~bind_instantiation() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class config_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    config_declaration(): object(AST_CONFIG_DECLARATION) {
        
    }
    ~config_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class design_statement: public object {
    ast_type                        type;
    
public: 
    // 
    design_statement(): object(AST_DESIGN_STATEMENT) {
        
    }
    ~design_statement() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class config_rule_statement: public object {
    ast_type                        type;
    
public: 
    // 
    config_rule_statement(): object(AST_CONFIG_RULE_STATEMENT) {
        
    }
    ~config_rule_statement() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class default_clause: public object {
    ast_type                        type;
    
public: 
    // 
    default_clause(): object(AST_DEFAULT_CLAUSE) {
        
    }
    ~default_clause() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class inst_clause: public object {
    ast_type                        type;
    
public: 
    // 
    inst_clause(): object(AST_INST_CLAUSE) {
        
    }
    ~inst_clause() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class inst_name: public object {
    ast_type                        type;
    
public: 
    // 
    inst_name(): object(AST_INST_NAME) {
        
    }
    ~inst_name() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class cell_clause: public object {
    ast_type                        type;
    
public: 
    // 
    cell_clause(): object(AST_CELL_CLAUSE) {
        
    }
    ~cell_clause() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class liblist_clause: public object {
    ast_type                        type;
    
public: 
    // 
    liblist_clause(): object(AST_LIBLIST_CLAUSE) {
        
    }
    ~liblist_clause() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class use_clause: public object {
    ast_type                        type;
    
public: 
    // 
    use_clause(): object(AST_USE_CLAUSE) {
        
    }
    ~use_clause() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class interface_or_generate_item: public object {
    ast_type                        type;
    
public: 
    // 
    interface_or_generate_item(): object(AST_INTERFACE_OR_GENERATE_ITEM) {
        
    }
    ~interface_or_generate_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class extern_tf_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    extern_tf_declaration(): object(AST_EXTERN_TF_DECLARATION) {
        
    }
    ~extern_tf_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class interface_item: public object {
    ast_type                        type;
    
public: 
    // 
    interface_item(): object(AST_INTERFACE_ITEM) {
        
    }
    ~interface_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class non_port_interface_item: public object {
    ast_type                        type;
    
public: 
    // 
    non_port_interface_item(): object(AST_NON_PORT_INTERFACE_ITEM) {
        
    }
    ~non_port_interface_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class program_item: public object {
    ast_type                        type;
    
public: 
    // 
    program_item(): object(AST_PROGRAM_ITEM) {
        
    }
    ~program_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class non_port_program_item: public object {
    ast_type                        type;
    
public: 
    // 
    non_port_program_item(): object(AST_NON_PORT_PROGRAM_ITEM) {
        
    }
    ~non_port_program_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class program_generate_item: public object {
    ast_type                        type;
    
public: 
    // 
    program_generate_item(): object(AST_PROGRAM_GENERATE_ITEM) {
        
    }
    ~program_generate_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class checker_port_list: public object {
    ast_type                        type;
    
public: 
    // 
    checker_port_list(): object(AST_CHECKER_PORT_LIST) {
        
    }
    ~checker_port_list() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class checker_port_item: public object {
    ast_type                        type;
    
public: 
    // 
    checker_port_item(): object(AST_CHECKER_PORT_ITEM) {
        
    }
    ~checker_port_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class checker_port_direction: public object {
    ast_type                        type;
    
public: 
    // 
    checker_port_direction(): object(AST_CHECKER_PORT_DIRECTION) {
        
    }
    ~checker_port_direction() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class checker_or_generate_item: public object {
    ast_type                        type;
    
public: 
    // 
    checker_or_generate_item(): object(AST_CHECKER_OR_GENERATE_ITEM) {
        
    }
    ~checker_or_generate_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class checker_or_generate_item_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    checker_or_generate_item_declaration(): object(AST_CHECKER_OR_GENERATE_ITEM_DECLARATION) {
        
    }
    ~checker_or_generate_item_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class checker_generate_item: public object {
    ast_type                        type;
    
public: 
    // 
    checker_generate_item(): object(AST_CHECKER_GENERATE_ITEM) {
        
    }
    ~checker_generate_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class class_item: public object {
    ast_type                        type;
    
public: 
    // 
    class_item(): object(AST_CLASS_ITEM) {
        
    }
    ~class_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class class_property: public object {
    ast_type                        type;
    
public: 
    // 
    class_property(): object(AST_CLASS_PROPERTY) {
        
    }
    ~class_property() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class class_method: public object {
    ast_type                        type;
    
public: 
    // 
    class_method(): object(AST_CLASS_METHOD) {
        
    }
    ~class_method() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class class_constructor_prototype: public object {
    ast_type                        type;
    
public: 
    // 
    class_constructor_prototype(): object(AST_CLASS_CONSTRUCTOR_PROTOTYPE) {
        
    }
    ~class_constructor_prototype() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class class_constraint: public object {
    ast_type                        type;
    
public: 
    // 
    class_constraint(): object(AST_CLASS_CONSTRAINT) {
        
    }
    ~class_constraint() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class class_item_qualifier: public object {
    ast_type                        type;
    
public: 
    // 
    class_item_qualifier(): object(AST_CLASS_ITEM_QUALIFIER) {
        
    }
    ~class_item_qualifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class property_qualifier: public object {
    ast_type                        type;
    
public: 
    // 
    property_qualifier(): object(AST_PROPERTY_QUALIFIER) {
        
    }
    ~property_qualifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class random_qualifier: public object {
    ast_type                        type;
    
public: 
    // 
    random_qualifier(): object(AST_RANDOM_QUALIFIER) {
        
    }
    ~random_qualifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class method_qualifier: public object {
    ast_type                        type;
    
public: 
    // 
    method_qualifier(): object(AST_METHOD_QUALIFIER) {
        
    }
    ~method_qualifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class method_prototype: public object {
    ast_type                        type;
    
public: 
    // 
    method_prototype(): object(AST_METHOD_PROTOTYPE) {
        
    }
    ~method_prototype() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class class_constructor_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    class_constructor_declaration(): object(AST_CLASS_CONSTRUCTOR_DECLARATION) {
        
    }
    ~class_constructor_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class constraint_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    constraint_declaration(): object(AST_CONSTRAINT_DECLARATION) {
        
    }
    ~constraint_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class constraint_block: public object {
    ast_type                        type;
    
public: 
    // 
    constraint_block(): object(AST_CONSTRAINT_BLOCK) {
        
    }
    ~constraint_block() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class constraint_block_item: public object {
    ast_type                        type;
    
public: 
    // 
    constraint_block_item(): object(AST_CONSTRAINT_BLOCK_ITEM) {
        
    }
    ~constraint_block_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class solve_before_list: public object {
    ast_type                        type;
    
public: 
    // 
    solve_before_list(): object(AST_SOLVE_BEFORE_LIST) {
        
    }
    ~solve_before_list() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class constraint_primary: public object {
    ast_type                        type;
    
public: 
    // 
    constraint_primary(): object(AST_CONSTRAINT_PRIMARY) {
        
    }
    ~constraint_primary() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class constraint_expression: public object {
    ast_type                        type;
    
public: 
    // 
    constraint_expression(): object(AST_CONSTRAINT_EXPRESSION) {
        
    }
    ~constraint_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class uniqueness_constraint: public object {
    ast_type                        type;
    
public: 
    // 
    uniqueness_constraint(): object(AST_UNIQUENESS_CONSTRAINT) {
        
    }
    ~uniqueness_constraint() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class constraint_set: public object {
    ast_type                        type;
    
public: 
    // 
    constraint_set(): object(AST_CONSTRAINT_SET) {
        
    }
    ~constraint_set() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class dist_list: public object {
    ast_type                        type;
    
public: 
    // 
    dist_list(): object(AST_DIST_LIST) {
        
    }
    ~dist_list() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class dist_item: public object {
    ast_type                        type;
    
public: 
    // 
    dist_item(): object(AST_DIST_ITEM) {
        
    }
    ~dist_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class dist_weight: public object {
    ast_type                        type;
    
public: 
    // 
    dist_weight(): object(AST_DIST_WEIGHT) {
        
    }
    ~dist_weight() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class constraint_prototype: public object {
    ast_type                        type;
    
public: 
    // 
    constraint_prototype(): object(AST_CONSTRAINT_PROTOTYPE) {
        
    }
    ~constraint_prototype() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class constraint_prototype_qualifier: public object {
    ast_type                        type;
    
public: 
    // 
    constraint_prototype_qualifier(): object(AST_CONSTRAINT_PROTOTYPE_QUALIFIER) {
        
    }
    ~constraint_prototype_qualifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class extern_constraint_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    extern_constraint_declaration(): object(AST_EXTERN_CONSTRAINT_DECLARATION) {
        
    }
    ~extern_constraint_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class identifier_list: public object {
    ast_type                        type;
    
public: 
    // 
    identifier_list(): object(AST_IDENTIFIER_LIST) {
        
    }
    ~identifier_list() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class package_item: public object {
    ast_type                        type;
    
public: 
    // 
    package_item(): object(AST_PACKAGE_ITEM) {
        
    }
    ~package_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class package_or_generate_item_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    package_or_generate_item_declaration(): object(AST_PACKAGE_OR_GENERATE_ITEM_DECLARATION) {
        
    }
    ~package_or_generate_item_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class anonymous_program: public object {
    ast_type                        type;
    
public: 
    // 
    anonymous_program(): object(AST_ANONYMOUS_PROGRAM) {
        
    }
    ~anonymous_program() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class anonymous_program_item: public object {
    ast_type                        type;
    
public: 
    // 
    anonymous_program_item(): object(AST_ANONYMOUS_PROGRAM_ITEM) {
        
    }
    ~anonymous_program_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class local_parameter_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    local_parameter_declaration(): object(AST_LOCAL_PARAMETER_DECLARATION) {
        
    }
    ~local_parameter_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class parameter_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    parameter_declaration(): object(AST_PARAMETER_DECLARATION) {
        
    }
    ~parameter_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class specparam_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    specparam_declaration(): object(AST_SPECPARAM_DECLARATION) {
        
    }
    ~specparam_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class inout_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    inout_declaration(): object(AST_INOUT_DECLARATION) {
        
    }
    ~inout_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class input_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    input_declaration(): object(AST_INPUT_DECLARATION) {
        
    }
    ~input_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class output_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    output_declaration(): object(AST_OUTPUT_DECLARATION) {
        
    }
    ~output_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class interface_port_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    interface_port_declaration(): object(AST_INTERFACE_PORT_DECLARATION) {
        
    }
    ~interface_port_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class ref_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    ref_declaration(): object(AST_REF_DECLARATION) {
        
    }
    ~ref_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class data_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    data_declaration(): object(AST_DATA_DECLARATION) {
        
    }
    ~data_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class package_import_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    package_import_declaration(): object(AST_PACKAGE_IMPORT_DECLARATION) {
        
    }
    ~package_import_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class package_import_item: public object {
    ast_type                        type;
    
public: 
    // 
    package_import_item(): object(AST_PACKAGE_IMPORT_ITEM) {
        
    }
    ~package_import_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class package_export_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    package_export_declaration(): object(AST_PACKAGE_EXPORT_DECLARATION) {
        
    }
    ~package_export_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class genvar_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    genvar_declaration(): object(AST_GENVAR_DECLARATION) {
        
    }
    ~genvar_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class net_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    net_declaration(): object(AST_NET_DECLARATION) {
        
    }
    ~net_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class type_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    type_declaration(): object(AST_TYPE_DECLARATION) {
        
    }
    ~type_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class net_type_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    net_type_declaration(): object(AST_NET_TYPE_DECLARATION) {
        
    }
    ~net_type_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class lifetime: public object {
    ast_type                        type;
    
public: 
    // 
    lifetime(): object(AST_LIFETIME) {
        
    }
    ~lifetime() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class casting_type: public object {
    ast_type                        type;
    
public: 
    // 
    casting_type(): object(AST_CASTING_TYPE) {
        
    }
    ~casting_type() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class data_type: public object {
    ast_type                        type;
    
public: 
    // 
    data_type(): object(AST_DATA_TYPE) {
        
    }
    ~data_type() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class data_type_or_implicit: public object {
    ast_type                        type;
    
public: 
    // 
    data_type_or_implicit(): object(AST_DATA_TYPE_OR_IMPLICIT) {
        
    }
    ~data_type_or_implicit() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class implicit_data_type: public object {
    ast_type                        type;
    
public: 
    // 
    implicit_data_type(): object(AST_IMPLICIT_DATA_TYPE) {
        
    }
    ~implicit_data_type() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class enum_base_type: public object {
    ast_type                        type;
    
public: 
    // 
    enum_base_type(): object(AST_ENUM_BASE_TYPE) {
        
    }
    ~enum_base_type() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class enum_name_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    enum_name_declaration(): object(AST_ENUM_NAME_DECLARATION) {
        
    }
    ~enum_name_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class class_scope: public object {
    ast_type                        type;
    
public: 
    // 
    class_scope(): object(AST_CLASS_SCOPE) {
        
    }
    ~class_scope() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class class_type: public object {
    ast_type                        type;
    
public: 
    // 
    class_type(): object(AST_CLASS_TYPE) {
        
    }
    ~class_type() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class integer_type: public object {
    ast_type                        type;
    
public: 
    // 
    integer_type(): object(AST_INTEGER_TYPE) {
        
    }
    ~integer_type() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class integer_atom_type: public object {
    ast_type                        type;
    
public: 
    // 
    integer_atom_type(): object(AST_INTEGER_ATOM_TYPE) {
        
    }
    ~integer_atom_type() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class integer_vector_type: public object {
    ast_type                        type;
    
public: 
    // 
    integer_vector_type(): object(AST_INTEGER_VECTOR_TYPE) {
        
    }
    ~integer_vector_type() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class non_integer_type: public object {
    ast_type                        type;
    
public: 
    // 
    non_integer_type(): object(AST_NON_INTEGER_TYPE) {
        
    }
    ~non_integer_type() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class net_type: public object {
    ast_type                        type;
    
public: 
    // 
    net_type(): object(AST_NET_TYPE) {
        
    }
    ~net_type() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class net_port_type: public object {
    ast_type                        type;
    
public: 
    // 
    net_port_type(): object(AST_NET_PORT_TYPE) {
        
    }
    ~net_port_type() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class variable_port_type: public object {
    ast_type                        type;
    
public: 
    // 
    variable_port_type(): object(AST_VARIABLE_PORT_TYPE) {
        
    }
    ~variable_port_type() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class var_data_type: public object {
    ast_type                        type;
    
public: 
    // 
    var_data_type(): object(AST_VAR_DATA_TYPE) {
        
    }
    ~var_data_type() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class signing: public object {
    ast_type                        type;
    
public: 
    // 
    signing(): object(AST_SIGNING) {
        
    }
    ~signing() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class simple_type: public object {
    ast_type                        type;
    
public: 
    // 
    simple_type(): object(AST_SIMPLE_TYPE) {
        
    }
    ~simple_type() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class struct_union_member: public object {
    ast_type                        type;
    
public: 
    // 
    struct_union_member(): object(AST_STRUCT_UNION_MEMBER) {
        
    }
    ~struct_union_member() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class data_type_or_void: public object {
    ast_type                        type;
    
public: 
    // 
    data_type_or_void(): object(AST_DATA_TYPE_OR_VOID) {
        
    }
    ~data_type_or_void() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class struct_union: public object {
    ast_type                        type;
    
public: 
    // 
    struct_union(): object(AST_STRUCT_UNION) {
        
    }
    ~struct_union() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class type_reference: public object {
    ast_type                        type;
    
public: 
    // 
    type_reference(): object(AST_TYPE_REFERENCE) {
        
    }
    ~type_reference() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class drive_strength: public object {
    ast_type                        type;
    
public: 
    // 
    drive_strength(): object(AST_DRIVE_STRENGTH) {
        
    }
    ~drive_strength() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class strength0: public object {
    ast_type                        type;
    
public: 
    // 
    strength0(): object(AST_STRENGTH0) {
        
    }
    ~strength0() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class strength1: public object {
    ast_type                        type;
    
public: 
    // 
    strength1(): object(AST_STRENGTH1) {
        
    }
    ~strength1() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class charge_strength: public object {
    ast_type                        type;
    
public: 
    // 
    charge_strength(): object(AST_CHARGE_STRENGTH) {
        
    }
    ~charge_strength() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class delay3: public object {
    ast_type                        type;
    
public: 
    // 
    delay3(): object(AST_DELAY3) {
        
    }
    ~delay3() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class delay2: public object {
    ast_type                        type;
    
public: 
    // 
    delay2(): object(AST_DELAY2) {
        
    }
    ~delay2() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class delay_value: public object {
    ast_type                        type;
    
public: 
    // 
    delay_value(): object(AST_DELAY_VALUE) {
        
    }
    ~delay_value() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class list_of_defparam_assignments: public object {
    ast_type                        type;
    
public: 
    // 
    list_of_defparam_assignments(): object(AST_LIST_OF_DEFPARAM_ASSIGNMENTS) {
        
    }
    ~list_of_defparam_assignments() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class list_of_genvar_identifiers: public object {
    ast_type                        type;
    
public: 
    // 
    list_of_genvar_identifiers(): object(AST_LIST_OF_GENVAR_IDENTIFIERS) {
        
    }
    ~list_of_genvar_identifiers() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class list_of_interface_identifiers: public object {
    ast_type                        type;
    
public: 
    // 
    list_of_interface_identifiers(): object(AST_LIST_OF_INTERFACE_IDENTIFIERS) {
        
    }
    ~list_of_interface_identifiers() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class list_of_net_decl_assignments: public object {
    ast_type                        type;
    
public: 
    // 
    list_of_net_decl_assignments(): object(AST_LIST_OF_NET_DECL_ASSIGNMENTS) {
        
    }
    ~list_of_net_decl_assignments() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class list_of_param_assignments: public object {
    ast_type                        type;
    
public: 
    // 
    list_of_param_assignments(): object(AST_LIST_OF_PARAM_ASSIGNMENTS) {
        
    }
    ~list_of_param_assignments() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class list_of_port_identifiers: public object {
    ast_type                        type;
    
public: 
    // 
    list_of_port_identifiers(): object(AST_LIST_OF_PORT_IDENTIFIERS) {
        
    }
    ~list_of_port_identifiers() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class list_of_udp_port_identifiers: public object {
    ast_type                        type;
    
public: 
    // 
    list_of_udp_port_identifiers(): object(AST_LIST_OF_UDP_PORT_IDENTIFIERS) {
        
    }
    ~list_of_udp_port_identifiers() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class list_of_specparam_assignments: public object {
    ast_type                        type;
    
public: 
    // 
    list_of_specparam_assignments(): object(AST_LIST_OF_SPECPARAM_ASSIGNMENTS) {
        
    }
    ~list_of_specparam_assignments() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class list_of_tf_variable_identifiers: public object {
    ast_type                        type;
    
public: 
    // 
    list_of_tf_variable_identifiers(): object(AST_LIST_OF_TF_VARIABLE_IDENTIFIERS) {
        
    }
    ~list_of_tf_variable_identifiers() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class list_of_type_assignments: public object {
    ast_type                        type;
    
public: 
    // 
    list_of_type_assignments(): object(AST_LIST_OF_TYPE_ASSIGNMENTS) {
        
    }
    ~list_of_type_assignments() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class list_of_variable_decl_assignments: public object {
    ast_type                        type;
    
public: 
    // 
    list_of_variable_decl_assignments(): object(AST_LIST_OF_VARIABLE_DECL_ASSIGNMENTS) {
        
    }
    ~list_of_variable_decl_assignments() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class list_of_variable_identifiers: public object {
    ast_type                        type;
    
public: 
    // 
    list_of_variable_identifiers(): object(AST_LIST_OF_VARIABLE_IDENTIFIERS) {
        
    }
    ~list_of_variable_identifiers() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class list_of_variable_port_identifiers: public object {
    ast_type                        type;
    
public: 
    // 
    list_of_variable_port_identifiers(): object(AST_LIST_OF_VARIABLE_PORT_IDENTIFIERS) {
        
    }
    ~list_of_variable_port_identifiers() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class defparam_assignment: public object {
    ast_type                        type;
    
public: 
    // 
    defparam_assignment(): object(AST_DEFPARAM_ASSIGNMENT) {
        
    }
    ~defparam_assignment() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class net_decl_assignment: public object {
    ast_type                        type;
    
public: 
    // 
    net_decl_assignment(): object(AST_NET_DECL_ASSIGNMENT) {
        
    }
    ~net_decl_assignment() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class param_assignment: public object {
    ast_type                        type;
    
public: 
    // 
    param_assignment(): object(AST_PARAM_ASSIGNMENT) {
        
    }
    ~param_assignment() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class specparam_assignment: public object {
    ast_type                        type;
    
public: 
    // 
    specparam_assignment(): object(AST_SPECPARAM_ASSIGNMENT) {
        
    }
    ~specparam_assignment() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class type_assignment: public object {
    ast_type                        type;
    
public: 
    // 
    type_assignment(): object(AST_TYPE_ASSIGNMENT) {
        
    }
    ~type_assignment() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class pulse_control_specparam: public object {
    ast_type                        type;
    
public: 
    // 
    pulse_control_specparam(): object(AST_PULSE_CONTROL_SPECPARAM) {
        
    }
    ~pulse_control_specparam() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class error_limit_value: public object {
    ast_type                        type;
    
public: 
    // 
    error_limit_value(): object(AST_ERROR_LIMIT_VALUE) {
        
    }
    ~error_limit_value() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class reject_limit_value: public object {
    ast_type                        type;
    
public: 
    // 
    reject_limit_value(): object(AST_REJECT_LIMIT_VALUE) {
        
    }
    ~reject_limit_value() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class limit_value: public object {
    ast_type                        type;
    
public: 
    // 
    limit_value(): object(AST_LIMIT_VALUE) {
        
    }
    ~limit_value() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class variable_decl_assignment: public object {
    ast_type                        type;
    
public: 
    // 
    variable_decl_assignment(): object(AST_VARIABLE_DECL_ASSIGNMENT) {
        
    }
    ~variable_decl_assignment() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class class_new: public object {
    ast_type                        type;
    
public: 
    // 
    class_new(): object(AST_CLASS_NEW) {
        
    }
    ~class_new() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class dynamic_array_new: public object {
    ast_type                        type;
    
public: 
    // 
    dynamic_array_new(): object(AST_DYNAMIC_ARRAY_NEW) {
        
    }
    ~dynamic_array_new() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class unpacked_dimension: public object {
    ast_type                        type;
    
public: 
    // 
    unpacked_dimension(): object(AST_UNPACKED_DIMENSION) {
        
    }
    ~unpacked_dimension() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class packed_dimension: public object {
    ast_type                        type;
    
public: 
    // 
    packed_dimension(): object(AST_PACKED_DIMENSION) {
        
    }
    ~packed_dimension() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class associative_dimension: public object {
    ast_type                        type;
    
public: 
    // 
    associative_dimension(): object(AST_ASSOCIATIVE_DIMENSION) {
        
    }
    ~associative_dimension() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class variable_dimension: public object {
    ast_type                        type;
    
public: 
    // 
    variable_dimension(): object(AST_VARIABLE_DIMENSION) {
        
    }
    ~variable_dimension() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class queue_dimension: public object {
    ast_type                        type;
    
public: 
    // 
    queue_dimension(): object(AST_QUEUE_DIMENSION) {
        
    }
    ~queue_dimension() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class unsized_dimension: public object {
    ast_type                        type;
    
public: 
    // 
    unsized_dimension(): object(AST_UNSIZED_DIMENSION) {
        
    }
    ~unsized_dimension() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class function_data_type_or_implicit: public object {
    ast_type                        type;
    
public: 
    // 
    function_data_type_or_implicit(): object(AST_FUNCTION_DATA_TYPE_OR_IMPLICIT) {
        
    }
    ~function_data_type_or_implicit() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class function_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    function_declaration(): object(AST_FUNCTION_DECLARATION) {
        
    }
    ~function_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class function_body_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    function_body_declaration(): object(AST_FUNCTION_BODY_DECLARATION) {
        
    }
    ~function_body_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class function_prototype: public object {
    ast_type                        type;
    
public: 
    // 
    function_prototype(): object(AST_FUNCTION_PROTOTYPE) {
        
    }
    ~function_prototype() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class dpi_import_export: public object {
    ast_type                        type;
    
public: 
    // 
    dpi_import_export(): object(AST_DPI_IMPORT_EXPORT) {
        
    }
    ~dpi_import_export() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class dpi_spec_string: public object {
    ast_type                        type;
    
public: 
    // 
    dpi_spec_string(): object(AST_DPI_SPEC_STRING) {
        
    }
    ~dpi_spec_string() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class dpi_function_import_property: public object {
    ast_type                        type;
    
public: 
    // 
    dpi_function_import_property(): object(AST_DPI_FUNCTION_IMPORT_PROPERTY) {
        
    }
    ~dpi_function_import_property() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class dpi_task_import_property: public object {
    ast_type                        type;
    
public: 
    // 
    dpi_task_import_property(): object(AST_DPI_TASK_IMPORT_PROPERTY) {
        
    }
    ~dpi_task_import_property() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class dpi_function_proto: public object {
    ast_type                        type;
    
public: 
    // 
    dpi_function_proto(): object(AST_DPI_FUNCTION_PROTO) {
        
    }
    ~dpi_function_proto() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class dpi_task_proto: public object {
    ast_type                        type;
    
public: 
    // 
    dpi_task_proto(): object(AST_DPI_TASK_PROTO) {
        
    }
    ~dpi_task_proto() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class task_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    task_declaration(): object(AST_TASK_DECLARATION) {
        
    }
    ~task_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class task_body_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    task_body_declaration(): object(AST_TASK_BODY_DECLARATION) {
        
    }
    ~task_body_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class tf_item_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    tf_item_declaration(): object(AST_TF_ITEM_DECLARATION) {
        
    }
    ~tf_item_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class tf_port_list: public object {
    ast_type                        type;
    
public: 
    // 
    tf_port_list(): object(AST_TF_PORT_LIST) {
        
    }
    ~tf_port_list() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class tf_port_item: public object {
    ast_type                        type;
    
public: 
    // 
    tf_port_item(): object(AST_TF_PORT_ITEM) {
        
    }
    ~tf_port_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class tf_port_direction: public object {
    ast_type                        type;
    
public: 
    // 
    tf_port_direction(): object(AST_TF_PORT_DIRECTION) {
        
    }
    ~tf_port_direction() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class tf_port_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    tf_port_declaration(): object(AST_TF_PORT_DECLARATION) {
        
    }
    ~tf_port_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class task_prototype: public object {
    ast_type                        type;
    
public: 
    // 
    task_prototype(): object(AST_TASK_PROTOTYPE) {
        
    }
    ~task_prototype() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class block_item_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    block_item_declaration(): object(AST_BLOCK_ITEM_DECLARATION) {
        
    }
    ~block_item_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class overload_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    overload_declaration(): object(AST_OVERLOAD_DECLARATION) {
        
    }
    ~overload_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class overload_operator: public object {
    ast_type                        type;
    
public: 
    // 
    overload_operator(): object(AST_OVERLOAD_OPERATOR) {
        
    }
    ~overload_operator() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class overload_proto_formals: public object {
    ast_type                        type;
    
public: 
    // 
    overload_proto_formals(): object(AST_OVERLOAD_PROTO_FORMALS) {
        
    }
    ~overload_proto_formals() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class modport_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    modport_declaration(): object(AST_MODPORT_DECLARATION) {
        
    }
    ~modport_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class modport_item: public object {
    ast_type                        type;
    
public: 
    // 
    modport_item(): object(AST_MODPORT_ITEM) {
        
    }
    ~modport_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class modport_ports_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    modport_ports_declaration(): object(AST_MODPORT_PORTS_DECLARATION) {
        
    }
    ~modport_ports_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class modport_clocking_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    modport_clocking_declaration(): object(AST_MODPORT_CLOCKING_DECLARATION) {
        
    }
    ~modport_clocking_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class modport_simple_ports_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    modport_simple_ports_declaration(): object(AST_MODPORT_SIMPLE_PORTS_DECLARATION) {
        
    }
    ~modport_simple_ports_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class modport_simple_port: public object {
    ast_type                        type;
    
public: 
    // 
    modport_simple_port(): object(AST_MODPORT_SIMPLE_PORT) {
        
    }
    ~modport_simple_port() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class modport_tf_ports_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    modport_tf_ports_declaration(): object(AST_MODPORT_TF_PORTS_DECLARATION) {
        
    }
    ~modport_tf_ports_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class modport_tf_port: public object {
    ast_type                        type;
    
public: 
    // 
    modport_tf_port(): object(AST_MODPORT_TF_PORT) {
        
    }
    ~modport_tf_port() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class import_export: public object {
    ast_type                        type;
    
public: 
    // 
    import_export(): object(AST_IMPORT_EXPORT) {
        
    }
    ~import_export() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class concurrent_assertion_item: public object {
    ast_type                        type;
    
public: 
    // 
    concurrent_assertion_item(): object(AST_CONCURRENT_ASSERTION_ITEM) {
        
    }
    ~concurrent_assertion_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class concurrent_assertion_statement: public object {
    ast_type                        type;
    
public: 
    // 
    concurrent_assertion_statement(): object(AST_CONCURRENT_ASSERTION_STATEMENT) {
        
    }
    ~concurrent_assertion_statement() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class assert_property_statement: public object {
    ast_type                        type;
    
public: 
    // 
    assert_property_statement(): object(AST_ASSERT_PROPERTY_STATEMENT) {
        
    }
    ~assert_property_statement() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class assume_property_statement: public object {
    ast_type                        type;
    
public: 
    // 
    assume_property_statement(): object(AST_ASSUME_PROPERTY_STATEMENT) {
        
    }
    ~assume_property_statement() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class cover_property_statement: public object {
    ast_type                        type;
    
public: 
    // 
    cover_property_statement(): object(AST_COVER_PROPERTY_STATEMENT) {
        
    }
    ~cover_property_statement() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class expect_property_statement: public object {
    ast_type                        type;
    
public: 
    // 
    expect_property_statement(): object(AST_EXPECT_PROPERTY_STATEMENT) {
        
    }
    ~expect_property_statement() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class cover_sequence_statement: public object {
    ast_type                        type;
    
public: 
    // 
    cover_sequence_statement(): object(AST_COVER_SEQUENCE_STATEMENT) {
        
    }
    ~cover_sequence_statement() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class restrict_property_statement: public object {
    ast_type                        type;
    
public: 
    // 
    restrict_property_statement(): object(AST_RESTRICT_PROPERTY_STATEMENT) {
        
    }
    ~restrict_property_statement() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class property_instance: public object {
    ast_type                        type;
    
public: 
    // 
    property_instance(): object(AST_PROPERTY_INSTANCE) {
        
    }
    ~property_instance() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class property_list_of_arguments: public object {
    ast_type                        type;
    
public: 
    // 
    property_list_of_arguments(): object(AST_PROPERTY_LIST_OF_ARGUMENTS) {
        
    }
    ~property_list_of_arguments() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class property_actual_arg: public object {
    ast_type                        type;
    
public: 
    // 
    property_actual_arg(): object(AST_PROPERTY_ACTUAL_ARG) {
        
    }
    ~property_actual_arg() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class assertion_item_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    assertion_item_declaration(): object(AST_ASSERTION_ITEM_DECLARATION) {
        
    }
    ~assertion_item_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class property_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    property_declaration(): object(AST_PROPERTY_DECLARATION) {
        
    }
    ~property_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class property_port_list: public object {
    ast_type                        type;
    
public: 
    // 
    property_port_list(): object(AST_PROPERTY_PORT_LIST) {
        
    }
    ~property_port_list() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class property_port_item: public object {
    ast_type                        type;
    
public: 
    // 
    property_port_item(): object(AST_PROPERTY_PORT_ITEM) {
        
    }
    ~property_port_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class property_lvar_port_direction: public object {
    ast_type                        type;
    
public: 
    // 
    property_lvar_port_direction(): object(AST_PROPERTY_LVAR_PORT_DIRECTION) {
        
    }
    ~property_lvar_port_direction() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class property_formal_type: public object {
    ast_type                        type;
    
public: 
    // 
    property_formal_type(): object(AST_PROPERTY_FORMAL_TYPE) {
        
    }
    ~property_formal_type() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class property_spec: public object {
    ast_type                        type;
    
public: 
    // 
    property_spec(): object(AST_PROPERTY_SPEC) {
        
    }
    ~property_spec() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class property_expr: public object {
    ast_type                        type;
    
public: 
    // 
    property_expr(): object(AST_PROPERTY_EXPR) {
        
    }
    ~property_expr() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class property_case_item: public object {
    ast_type                        type;
    
public: 
    // 
    property_case_item(): object(AST_PROPERTY_CASE_ITEM) {
        
    }
    ~property_case_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class sequence_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    sequence_declaration(): object(AST_SEQUENCE_DECLARATION) {
        
    }
    ~sequence_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class sequence_port_list: public object {
    ast_type                        type;
    
public: 
    // 
    sequence_port_list(): object(AST_SEQUENCE_PORT_LIST) {
        
    }
    ~sequence_port_list() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class sequence_port_item: public object {
    ast_type                        type;
    
public: 
    // 
    sequence_port_item(): object(AST_SEQUENCE_PORT_ITEM) {
        
    }
    ~sequence_port_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class sequence_lvar_port_direction: public object {
    ast_type                        type;
    
public: 
    // 
    sequence_lvar_port_direction(): object(AST_SEQUENCE_LVAR_PORT_DIRECTION) {
        
    }
    ~sequence_lvar_port_direction() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class sequence_formal_type: public object {
    ast_type                        type;
    
public: 
    // 
    sequence_formal_type(): object(AST_SEQUENCE_FORMAL_TYPE) {
        
    }
    ~sequence_formal_type() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class sequence_expr: public object {
    ast_type                        type;
    
public: 
    // 
    sequence_expr(): object(AST_SEQUENCE_EXPR) {
        
    }
    ~sequence_expr() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class cycle_delay_range: public object {
    ast_type                        type;
    
public: 
    // 
    cycle_delay_range(): object(AST_CYCLE_DELAY_RANGE) {
        
    }
    ~cycle_delay_range() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class sequence_method_call: public object {
    ast_type                        type;
    
public: 
    // 
    sequence_method_call(): object(AST_SEQUENCE_METHOD_CALL) {
        
    }
    ~sequence_method_call() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class sequence_match_item: public object {
    ast_type                        type;
    
public: 
    // 
    sequence_match_item(): object(AST_SEQUENCE_MATCH_ITEM) {
        
    }
    ~sequence_match_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class sequence_instance: public object {
    ast_type                        type;
    
public: 
    // 
    sequence_instance(): object(AST_SEQUENCE_INSTANCE) {
        
    }
    ~sequence_instance() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class sequence_list_of_arguments: public object {
    ast_type                        type;
    
public: 
    // 
    sequence_list_of_arguments(): object(AST_SEQUENCE_LIST_OF_ARGUMENTS) {
        
    }
    ~sequence_list_of_arguments() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class sequence_actual_arg: public object {
    ast_type                        type;
    
public: 
    // 
    sequence_actual_arg(): object(AST_SEQUENCE_ACTUAL_ARG) {
        
    }
    ~sequence_actual_arg() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class boolean_abbrev: public object {
    ast_type                        type;
    
public: 
    // 
    boolean_abbrev(): object(AST_BOOLEAN_ABBREV) {
        
    }
    ~boolean_abbrev() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class sequence_abbrev: public object {
    ast_type                        type;
    
public: 
    // 
    sequence_abbrev(): object(AST_SEQUENCE_ABBREV) {
        
    }
    ~sequence_abbrev() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class consecutive_repetition: public object {
    ast_type                        type;
    
public: 
    // 
    consecutive_repetition(): object(AST_CONSECUTIVE_REPETITION) {
        
    }
    ~consecutive_repetition() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class non_consecutive_repetition: public object {
    ast_type                        type;
    
public: 
    // 
    non_consecutive_repetition(): object(AST_NON_CONSECUTIVE_REPETITION) {
        
    }
    ~non_consecutive_repetition() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class goto_repetition: public object {
    ast_type                        type;
    
public: 
    // 
    goto_repetition(): object(AST_GOTO_REPETITION) {
        
    }
    ~goto_repetition() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class const_or_range_expression: public object {
    ast_type                        type;
    
public: 
    // 
    const_or_range_expression(): object(AST_CONST_OR_RANGE_EXPRESSION) {
        
    }
    ~const_or_range_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class cycle_delay_const_range_expression: public object {
    ast_type                        type;
    
public: 
    // 
    cycle_delay_const_range_expression(): object(AST_CYCLE_DELAY_CONST_RANGE_EXPRESSION) {
        
    }
    ~cycle_delay_const_range_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class expression_or_dist: public object {
    ast_type                        type;
    
public: 
    // 
    expression_or_dist(): object(AST_EXPRESSION_OR_DIST) {
        
    }
    ~expression_or_dist() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class assertion_variable_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    assertion_variable_declaration(): object(AST_ASSERTION_VARIABLE_DECLARATION) {
        
    }
    ~assertion_variable_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class let_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    let_declaration(): object(AST_LET_DECLARATION) {
        
    }
    ~let_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class let_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    let_identifier(): object(AST_LET_IDENTIFIER) {
        
    }
    ~let_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class let_port_list: public object {
    ast_type                        type;
    
public: 
    // 
    let_port_list(): object(AST_LET_PORT_LIST) {
        
    }
    ~let_port_list() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class let_port_item: public object {
    ast_type                        type;
    
public: 
    // 
    let_port_item(): object(AST_LET_PORT_ITEM) {
        
    }
    ~let_port_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class let_formal_type: public object {
    ast_type                        type;
    
public: 
    // 
    let_formal_type(): object(AST_LET_FORMAL_TYPE) {
        
    }
    ~let_formal_type() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class let_expression: public object {
    ast_type                        type;
    
public: 
    // 
    let_expression(): object(AST_LET_EXPRESSION) {
        
    }
    ~let_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class let_list_of_arguments: public object {
    ast_type                        type;
    
public: 
    // 
    let_list_of_arguments(): object(AST_LET_LIST_OF_ARGUMENTS) {
        
    }
    ~let_list_of_arguments() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class let_actual_arg: public object {
    ast_type                        type;
    
public: 
    // 
    let_actual_arg(): object(AST_LET_ACTUAL_ARG) {
        
    }
    ~let_actual_arg() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class covergroup_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    covergroup_declaration(): object(AST_COVERGROUP_DECLARATION) {
        
    }
    ~covergroup_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class coverage_spec_or_option: public object {
    ast_type                        type;
    
public: 
    // 
    coverage_spec_or_option(): object(AST_COVERAGE_SPEC_OR_OPTION) {
        
    }
    ~coverage_spec_or_option() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class coverage_option: public object {
    ast_type                        type;
    
public: 
    // 
    coverage_option(): object(AST_COVERAGE_OPTION) {
        
    }
    ~coverage_option() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class coverage_spec: public object {
    ast_type                        type;
    
public: 
    // 
    coverage_spec(): object(AST_COVERAGE_SPEC) {
        
    }
    ~coverage_spec() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class coverage_event: public object {
    ast_type                        type;
    
public: 
    // 
    coverage_event(): object(AST_COVERAGE_EVENT) {
        
    }
    ~coverage_event() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class block_event_expression: public object {
    ast_type                        type;
    
public: 
    // 
    block_event_expression(): object(AST_BLOCK_EVENT_EXPRESSION) {
        
    }
    ~block_event_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class hierarchical_btf_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    hierarchical_btf_identifier(): object(AST_HIERARCHICAL_BTF_IDENTIFIER) {
        
    }
    ~hierarchical_btf_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class cover_point: public object {
    ast_type                        type;
    
public: 
    // 
    cover_point(): object(AST_COVER_POINT) {
        
    }
    ~cover_point() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class bins_or_empty: public object {
    ast_type                        type;
    
public: 
    // 
    bins_or_empty(): object(AST_BINS_OR_EMPTY) {
        
    }
    ~bins_or_empty() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class bins_or_options: public object {
    ast_type                        type;
    
public: 
    // 
    bins_or_options(): object(AST_BINS_OR_OPTIONS) {
        
    }
    ~bins_or_options() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class bins_keyword: public object {
    ast_type                        type;
    
public: 
    // 
    bins_keyword(): object(AST_BINS_KEYWORD) {
        
    }
    ~bins_keyword() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class trans_list: public object {
    ast_type                        type;
    
public: 
    // 
    trans_list(): object(AST_TRANS_LIST) {
        
    }
    ~trans_list() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class trans_set: public object {
    ast_type                        type;
    
public: 
    // 
    trans_set(): object(AST_TRANS_SET) {
        
    }
    ~trans_set() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class trans_range_list: public object {
    ast_type                        type;
    
public: 
    // 
    trans_range_list(): object(AST_TRANS_RANGE_LIST) {
        
    }
    ~trans_range_list() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class trans_item: public object {
    ast_type                        type;
    
public: 
    // 
    trans_item(): object(AST_TRANS_ITEM) {
        
    }
    ~trans_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class repeat_range: public object {
    ast_type                        type;
    
public: 
    // 
    repeat_range(): object(AST_REPEAT_RANGE) {
        
    }
    ~repeat_range() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class cover_cross: public object {
    ast_type                        type;
    
public: 
    // 
    cover_cross(): object(AST_COVER_CROSS) {
        
    }
    ~cover_cross() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class list_of_cross_items: public object {
    ast_type                        type;
    
public: 
    // 
    list_of_cross_items(): object(AST_LIST_OF_CROSS_ITEMS) {
        
    }
    ~list_of_cross_items() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class cross_item: public object {
    ast_type                        type;
    
public: 
    // 
    cross_item(): object(AST_CROSS_ITEM) {
        
    }
    ~cross_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class cross_body: public object {
    ast_type                        type;
    
public: 
    // 
    cross_body(): object(AST_CROSS_BODY) {
        
    }
    ~cross_body() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class cross_body_item: public object {
    ast_type                        type;
    
public: 
    // 
    cross_body_item(): object(AST_CROSS_BODY_ITEM) {
        
    }
    ~cross_body_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class bins_selection_or_option: public object {
    ast_type                        type;
    
public: 
    // 
    bins_selection_or_option(): object(AST_BINS_SELECTION_OR_OPTION) {
        
    }
    ~bins_selection_or_option() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class bins_selection: public object {
    ast_type                        type;
    
public: 
    // 
    bins_selection(): object(AST_BINS_SELECTION) {
        
    }
    ~bins_selection() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class select_expression: public object {
    ast_type                        type;
    
public: 
    // 
    select_expression(): object(AST_SELECT_EXPRESSION) {
        
    }
    ~select_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class select_condition: public object {
    ast_type                        type;
    
public: 
    // 
    select_condition(): object(AST_SELECT_CONDITION) {
        
    }
    ~select_condition() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class bins_expression: public object {
    ast_type                        type;
    
public: 
    // 
    bins_expression(): object(AST_BINS_EXPRESSION) {
        
    }
    ~bins_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class covergroup_range_list: public object {
    ast_type                        type;
    
public: 
    // 
    covergroup_range_list(): object(AST_COVERGROUP_RANGE_LIST) {
        
    }
    ~covergroup_range_list() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class covergroup_value_range: public object {
    ast_type                        type;
    
public: 
    // 
    covergroup_value_range(): object(AST_COVERGROUP_VALUE_RANGE) {
        
    }
    ~covergroup_value_range() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class with_covergroup_expression: public object {
    ast_type                        type;
    
public: 
    // 
    with_covergroup_expression(): object(AST_WITH_COVERGROUP_EXPRESSION) {
        
    }
    ~with_covergroup_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class set_covergroup_expression: public object {
    ast_type                        type;
    
public: 
    // 
    set_covergroup_expression(): object(AST_SET_COVERGROUP_EXPRESSION) {
        
    }
    ~set_covergroup_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class integer_covergroup_expression: public object {
    ast_type                        type;
    
public: 
    // 
    integer_covergroup_expression(): object(AST_INTEGER_COVERGROUP_EXPRESSION) {
        
    }
    ~integer_covergroup_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class cross_set_expression: public object {
    ast_type                        type;
    
public: 
    // 
    cross_set_expression(): object(AST_CROSS_SET_EXPRESSION) {
        
    }
    ~cross_set_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class covergroup_expression: public object {
    ast_type                        type;
    
public: 
    // 
    covergroup_expression(): object(AST_COVERGROUP_EXPRESSION) {
        
    }
    ~covergroup_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class gate_instantiation: public object {
    ast_type                        type;
    
public: 
    // 
    gate_instantiation(): object(AST_GATE_INSTANTIATION) {
        
    }
    ~gate_instantiation() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class cmos_switch_instance: public object {
    ast_type                        type;
    
public: 
    // 
    cmos_switch_instance(): object(AST_CMOS_SWITCH_INSTANCE) {
        
    }
    ~cmos_switch_instance() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class enable_gate_instance: public object {
    ast_type                        type;
    
public: 
    // 
    enable_gate_instance(): object(AST_ENABLE_GATE_INSTANCE) {
        
    }
    ~enable_gate_instance() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class mos_switch_instance: public object {
    ast_type                        type;
    
public: 
    // 
    mos_switch_instance(): object(AST_MOS_SWITCH_INSTANCE) {
        
    }
    ~mos_switch_instance() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class n_input_gate_instance: public object {
    ast_type                        type;
    
public: 
    // 
    n_input_gate_instance(): object(AST_N_INPUT_GATE_INSTANCE) {
        
    }
    ~n_input_gate_instance() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class n_output_gate_instance: public object {
    ast_type                        type;
    
public: 
    // 
    n_output_gate_instance(): object(AST_N_OUTPUT_GATE_INSTANCE) {
        
    }
    ~n_output_gate_instance() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class pass_switch_instance: public object {
    ast_type                        type;
    
public: 
    // 
    pass_switch_instance(): object(AST_PASS_SWITCH_INSTANCE) {
        
    }
    ~pass_switch_instance() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class pass_enable_switch_instance: public object {
    ast_type                        type;
    
public: 
    // 
    pass_enable_switch_instance(): object(AST_PASS_ENABLE_SWITCH_INSTANCE) {
        
    }
    ~pass_enable_switch_instance() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class pull_gate_instance: public object {
    ast_type                        type;
    
public: 
    // 
    pull_gate_instance(): object(AST_PULL_GATE_INSTANCE) {
        
    }
    ~pull_gate_instance() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class pulldown_strength: public object {
    ast_type                        type;
    
public: 
    // 
    pulldown_strength(): object(AST_PULLDOWN_STRENGTH) {
        
    }
    ~pulldown_strength() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class pullup_strength: public object {
    ast_type                        type;
    
public: 
    // 
    pullup_strength(): object(AST_PULLUP_STRENGTH) {
        
    }
    ~pullup_strength() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class enable_terminal: public object {
    ast_type                        type;
    
public: 
    // 
    enable_terminal(): object(AST_ENABLE_TERMINAL) {
        
    }
    ~enable_terminal() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class inout_terminal: public object {
    ast_type                        type;
    
public: 
    // 
    inout_terminal(): object(AST_INOUT_TERMINAL) {
        
    }
    ~inout_terminal() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class input_terminal: public object {
    ast_type                        type;
    
public: 
    // 
    input_terminal(): object(AST_INPUT_TERMINAL) {
        
    }
    ~input_terminal() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class ncontrol_terminal: public object {
    ast_type                        type;
    
public: 
    // 
    ncontrol_terminal(): object(AST_NCONTROL_TERMINAL) {
        
    }
    ~ncontrol_terminal() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class output_terminal: public object {
    ast_type                        type;
    
public: 
    // 
    output_terminal(): object(AST_OUTPUT_TERMINAL) {
        
    }
    ~output_terminal() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class pcontrol_terminal: public object {
    ast_type                        type;
    
public: 
    // 
    pcontrol_terminal(): object(AST_PCONTROL_TERMINAL) {
        
    }
    ~pcontrol_terminal() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class cmos_switchtype: public object {
    ast_type                        type;
    
public: 
    // 
    cmos_switchtype(): object(AST_CMOS_SWITCHTYPE) {
        
    }
    ~cmos_switchtype() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class enable_gatetype: public object {
    ast_type                        type;
    
public: 
    // 
    enable_gatetype(): object(AST_ENABLE_GATETYPE) {
        
    }
    ~enable_gatetype() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class mos_switchtype: public object {
    ast_type                        type;
    
public: 
    // 
    mos_switchtype(): object(AST_MOS_SWITCHTYPE) {
        
    }
    ~mos_switchtype() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class n_input_gatetype: public object {
    ast_type                        type;
    
public: 
    // 
    n_input_gatetype(): object(AST_N_INPUT_GATETYPE) {
        
    }
    ~n_input_gatetype() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class n_output_gatetype: public object {
    ast_type                        type;
    
public: 
    // 
    n_output_gatetype(): object(AST_N_OUTPUT_GATETYPE) {
        
    }
    ~n_output_gatetype() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class pass_en_switchtype: public object {
    ast_type                        type;
    
public: 
    // 
    pass_en_switchtype(): object(AST_PASS_EN_SWITCHTYPE) {
        
    }
    ~pass_en_switchtype() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class pass_switchtype: public object {
    ast_type                        type;
    
public: 
    // 
    pass_switchtype(): object(AST_PASS_SWITCHTYPE) {
        
    }
    ~pass_switchtype() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class module_instantiation: public object {
    ast_type                        type;
    
public: 
    // 
    module_instantiation(): object(AST_MODULE_INSTANTIATION) {
        
    }
    ~module_instantiation() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class parameter_value_assignment: public object {
    ast_type                        type;
    
public: 
    // 
    parameter_value_assignment(): object(AST_PARAMETER_VALUE_ASSIGNMENT) {
        
    }
    ~parameter_value_assignment() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class list_of_parameter_assignments: public object {
    ast_type                        type;
    
public: 
    // 
    list_of_parameter_assignments(): object(AST_LIST_OF_PARAMETER_ASSIGNMENTS) {
        
    }
    ~list_of_parameter_assignments() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class ordered_parameter_assignment: public object {
    ast_type                        type;
    
public: 
    // 
    ordered_parameter_assignment(): object(AST_ORDERED_PARAMETER_ASSIGNMENT) {
        
    }
    ~ordered_parameter_assignment() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class named_parameter_assignment: public object {
    ast_type                        type;
    
public: 
    // 
    named_parameter_assignment(): object(AST_NAMED_PARAMETER_ASSIGNMENT) {
        
    }
    ~named_parameter_assignment() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class hierarchical_instance: public object {
    ast_type                        type;
    
public: 
    // 
    hierarchical_instance(): object(AST_HIERARCHICAL_INSTANCE) {
        
    }
    ~hierarchical_instance() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class name_of_instance: public object {
    ast_type                        type;
    
public: 
    // 
    name_of_instance(): object(AST_NAME_OF_INSTANCE) {
        
    }
    ~name_of_instance() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class list_of_port_connections: public object {
    ast_type                        type;
    
public: 
    // 
    list_of_port_connections(): object(AST_LIST_OF_PORT_CONNECTIONS) {
        
    }
    ~list_of_port_connections() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class ordered_port_connection: public object {
    ast_type                        type;
    
public: 
    // 
    ordered_port_connection(): object(AST_ORDERED_PORT_CONNECTION) {
        
    }
    ~ordered_port_connection() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class named_port_connection: public object {
    ast_type                        type;
    
public: 
    // 
    named_port_connection(): object(AST_NAMED_PORT_CONNECTION) {
        
    }
    ~named_port_connection() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class interface_instantiation: public object {
    ast_type                        type;
    
public: 
    // 
    interface_instantiation(): object(AST_INTERFACE_INSTANTIATION) {
        
    }
    ~interface_instantiation() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class program_instantiation: public object {
    ast_type                        type;
    
public: 
    // 
    program_instantiation(): object(AST_PROGRAM_INSTANTIATION) {
        
    }
    ~program_instantiation() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class checker_instantiation: public object {
    ast_type                        type;
    
public: 
    // 
    checker_instantiation(): object(AST_CHECKER_INSTANTIATION) {
        
    }
    ~checker_instantiation() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class list_of_checker_port_connections: public object {
    ast_type                        type;
    
public: 
    // 
    list_of_checker_port_connections(): object(AST_LIST_OF_CHECKER_PORT_CONNECTIONS) {
        
    }
    ~list_of_checker_port_connections() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class ordered_checker_port_connection: public object {
    ast_type                        type;
    
public: 
    // 
    ordered_checker_port_connection(): object(AST_ORDERED_CHECKER_PORT_CONNECTION) {
        
    }
    ~ordered_checker_port_connection() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class named_checker_port_connection: public object {
    ast_type                        type;
    
public: 
    // 
    named_checker_port_connection(): object(AST_NAMED_CHECKER_PORT_CONNECTION) {
        
    }
    ~named_checker_port_connection() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class generate_region: public object {
    ast_type                        type;
    
public: 
    // 
    generate_region(): object(AST_GENERATE_REGION) {
        
    }
    ~generate_region() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class loop_generate_construct: public object {
    ast_type                        type;
    
public: 
    // 
    loop_generate_construct(): object(AST_LOOP_GENERATE_CONSTRUCT) {
        
    }
    ~loop_generate_construct() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class genvar_initialization: public object {
    ast_type                        type;
    
public: 
    // 
    genvar_initialization(): object(AST_GENVAR_INITIALIZATION) {
        
    }
    ~genvar_initialization() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class genvar_iteration: public object {
    ast_type                        type;
    
public: 
    // 
    genvar_iteration(): object(AST_GENVAR_ITERATION) {
        
    }
    ~genvar_iteration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class conditional_generate_construct: public object {
    ast_type                        type;
    
public: 
    // 
    conditional_generate_construct(): object(AST_CONDITIONAL_GENERATE_CONSTRUCT) {
        
    }
    ~conditional_generate_construct() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class if_generate_construct: public object {
    ast_type                        type;
    
public: 
    // 
    if_generate_construct(): object(AST_IF_GENERATE_CONSTRUCT) {
        
    }
    ~if_generate_construct() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class case_generate_construct: public object {
    ast_type                        type;
    
public: 
    // 
    case_generate_construct(): object(AST_CASE_GENERATE_CONSTRUCT) {
        
    }
    ~case_generate_construct() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class case_generate_item: public object {
    ast_type                        type;
    
public: 
    // 
    case_generate_item(): object(AST_CASE_GENERATE_ITEM) {
        
    }
    ~case_generate_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class generate_block: public object {
    ast_type                        type;
    
public: 
    // 
    generate_block(): object(AST_GENERATE_BLOCK) {
        
    }
    ~generate_block() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class generate_item: public object {
    ast_type                        type;
    
public: 
    // 
    generate_item(): object(AST_GENERATE_ITEM) {
        
    }
    ~generate_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class udp_nonansi_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    udp_nonansi_declaration(): object(AST_UDP_NONANSI_DECLARATION) {
        
    }
    ~udp_nonansi_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class udp_ansi_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    udp_ansi_declaration(): object(AST_UDP_ANSI_DECLARATION) {
        
    }
    ~udp_ansi_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class udp_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    udp_declaration(): object(AST_UDP_DECLARATION) {
        
    }
    ~udp_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class udp_port_list: public object {
    ast_type                        type;
    
public: 
    // 
    udp_port_list(): object(AST_UDP_PORT_LIST) {
        
    }
    ~udp_port_list() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class udp_declaration_port_list: public object {
    ast_type                        type;
    
public: 
    // 
    udp_declaration_port_list(): object(AST_UDP_DECLARATION_PORT_LIST) {
        
    }
    ~udp_declaration_port_list() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class udp_port_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    udp_port_declaration(): object(AST_UDP_PORT_DECLARATION) {
        
    }
    ~udp_port_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class udp_output_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    udp_output_declaration(): object(AST_UDP_OUTPUT_DECLARATION) {
        
    }
    ~udp_output_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class udp_input_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    udp_input_declaration(): object(AST_UDP_INPUT_DECLARATION) {
        
    }
    ~udp_input_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class udp_reg_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    udp_reg_declaration(): object(AST_UDP_REG_DECLARATION) {
        
    }
    ~udp_reg_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class udp_body: public object {
    ast_type                        type;
    
public: 
    // 
    udp_body(): object(AST_UDP_BODY) {
        
    }
    ~udp_body() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class combinational_body: public object {
    ast_type                        type;
    
public: 
    // 
    combinational_body(): object(AST_COMBINATIONAL_BODY) {
        
    }
    ~combinational_body() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class combinational_entry: public object {
    ast_type                        type;
    
public: 
    // 
    combinational_entry(): object(AST_COMBINATIONAL_ENTRY) {
        
    }
    ~combinational_entry() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class sequential_body: public object {
    ast_type                        type;
    
public: 
    // 
    sequential_body(): object(AST_SEQUENTIAL_BODY) {
        
    }
    ~sequential_body() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class udp_initial_statement: public object {
    ast_type                        type;
    
public: 
    // 
    udp_initial_statement(): object(AST_UDP_INITIAL_STATEMENT) {
        
    }
    ~udp_initial_statement() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class init_val: public object {
    ast_type                        type;
    
public: 
    // 
    init_val(): object(AST_INIT_VAL) {
        
    }
    ~init_val() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class sequential_entry: public object {
    ast_type                        type;
    
public: 
    // 
    sequential_entry(): object(AST_SEQUENTIAL_ENTRY) {
        
    }
    ~sequential_entry() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class seq_input_list: public object {
    ast_type                        type;
    
public: 
    // 
    seq_input_list(): object(AST_SEQ_INPUT_LIST) {
        
    }
    ~seq_input_list() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class level_input_list: public object {
    ast_type                        type;
    
public: 
    // 
    level_input_list(): object(AST_LEVEL_INPUT_LIST) {
        
    }
    ~level_input_list() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class edge_input_list: public object {
    ast_type                        type;
    
public: 
    // 
    edge_input_list(): object(AST_EDGE_INPUT_LIST) {
        
    }
    ~edge_input_list() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class edge_indicator: public object {
    ast_type                        type;
    
public: 
    // 
    edge_indicator(): object(AST_EDGE_INDICATOR) {
        
    }
    ~edge_indicator() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class current_state: public object {
    ast_type                        type;
    
public: 
    // 
    current_state(): object(AST_CURRENT_STATE) {
        
    }
    ~current_state() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class next_state: public object {
    ast_type                        type;
    
public: 
    // 
    next_state(): object(AST_NEXT_STATE) {
        
    }
    ~next_state() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class output_symbol: public object {
    ast_type                        type;
    
public: 
    // 
    output_symbol(): object(AST_OUTPUT_SYMBOL) {
        
    }
    ~output_symbol() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class level_symbol: public object {
    ast_type                        type;
    
public: 
    // 
    level_symbol(): object(AST_LEVEL_SYMBOL) {
        
    }
    ~level_symbol() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class edge_symbol: public object {
    ast_type                        type;
    
public: 
    // 
    edge_symbol(): object(AST_EDGE_SYMBOL) {
        
    }
    ~edge_symbol() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class udp_instantiation: public object {
    ast_type                        type;
    
public: 
    // 
    udp_instantiation(): object(AST_UDP_INSTANTIATION) {
        
    }
    ~udp_instantiation() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class udp_instance: public object {
    ast_type                        type;
    
public: 
    // 
    udp_instance(): object(AST_UDP_INSTANCE) {
        
    }
    ~udp_instance() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class continuous_assign: public object {
    ast_type                        type;
    
public: 
    // 
    continuous_assign(): object(AST_CONTINUOUS_ASSIGN) {
        
    }
    ~continuous_assign() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class list_of_net_assignments: public object {
    ast_type                        type;
    
public: 
    // 
    list_of_net_assignments(): object(AST_LIST_OF_NET_ASSIGNMENTS) {
        
    }
    ~list_of_net_assignments() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class list_of_variable_assignments: public object {
    ast_type                        type;
    
public: 
    // 
    list_of_variable_assignments(): object(AST_LIST_OF_VARIABLE_ASSIGNMENTS) {
        
    }
    ~list_of_variable_assignments() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class net_alias: public object {
    ast_type                        type;
    
public: 
    // 
    net_alias(): object(AST_NET_ALIAS) {
        
    }
    ~net_alias() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class net_assignment: public object {
    ast_type                        type;
    
public: 
    // 
    net_assignment(): object(AST_NET_ASSIGNMENT) {
        
    }
    ~net_assignment() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class initial_construct: public object {
    ast_type                        type;
    
public: 
    // 
    initial_construct(): object(AST_INITIAL_CONSTRUCT) {
        
    }
    ~initial_construct() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class always_construct: public object {
    ast_type                        type;
    
public: 
    // 
    always_construct(): object(AST_ALWAYS_CONSTRUCT) {
        
    }
    ~always_construct() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class always_keyword: public object {
    ast_type                        type;
    
public: 
    // 
    always_keyword(): object(AST_ALWAYS_KEYWORD) {
        
    }
    ~always_keyword() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class final_construct: public object {
    ast_type                        type;
    
public: 
    // 
    final_construct(): object(AST_FINAL_CONSTRUCT) {
        
    }
    ~final_construct() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class blocking_assignment: public object {
    ast_type                        type;
    
public: 
    // 
    blocking_assignment(): object(AST_BLOCKING_ASSIGNMENT) {
        
    }
    ~blocking_assignment() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class operator_assignment: public object {
    ast_type                        type;
    
public: 
    // 
    operator_assignment(): object(AST_OPERATOR_ASSIGNMENT) {
        
    }
    ~operator_assignment() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class assignment_operator: public object {
    ast_type                        type;
    
public: 
    // 
    assignment_operator(): object(AST_ASSIGNMENT_OPERATOR) {
        
    }
    ~assignment_operator() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class nonblocking_assignment: public object {
    ast_type                        type;
    
public: 
    // 
    nonblocking_assignment(): object(AST_NONBLOCKING_ASSIGNMENT) {
        
    }
    ~nonblocking_assignment() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class procedural_continuous_assignment: public object {
    ast_type                        type;
    
public: 
    // 
    procedural_continuous_assignment(): object(AST_PROCEDURAL_CONTINUOUS_ASSIGNMENT) {
        
    }
    ~procedural_continuous_assignment() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class variable_assignment: public object {
    ast_type                        type;
    
public: 
    // 
    variable_assignment(): object(AST_VARIABLE_ASSIGNMENT) {
        
    }
    ~variable_assignment() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class action_block: public object {
    ast_type                        type;
    
public: 
    // 
    action_block(): object(AST_ACTION_BLOCK) {
        
    }
    ~action_block() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class seq_block: public object {
    ast_type                        type;
    
public: 
    // 
    seq_block(): object(AST_SEQ_BLOCK) {
        
    }
    ~seq_block() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class par_block: public object {
    ast_type                        type;
    
public: 
    // 
    par_block(): object(AST_PAR_BLOCK) {
        
    }
    ~par_block() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class join_keyword: public object {
    ast_type                        type;
    
public: 
    // 
    join_keyword(): object(AST_JOIN_KEYWORD) {
        
    }
    ~join_keyword() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class statement_or_null: public object {
    ast_type                        type;
    
public: 
    // 
    statement_or_null(): object(AST_STATEMENT_OR_NULL) {
        
    }
    ~statement_or_null() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class statement: public object {
    ast_type                        type;
    
public: 
    // 
    statement(): object(AST_STATEMENT) {
        
    }
    ~statement() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class statement_item: public object {
    ast_type                        type;
    
public: 
    // 
    statement_item(): object(AST_STATEMENT_ITEM) {
        
    }
    ~statement_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class function_statement: public object {
    ast_type                        type;
    
public: 
    // 
    function_statement(): object(AST_FUNCTION_STATEMENT) {
        
    }
    ~function_statement() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class function_statement_or_null: public object {
    ast_type                        type;
    
public: 
    // 
    function_statement_or_null(): object(AST_FUNCTION_STATEMENT_OR_NULL) {
        
    }
    ~function_statement_or_null() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class variable_identifier_list: public object {
    ast_type                        type;
    
public: 
    // 
    variable_identifier_list(): object(AST_VARIABLE_IDENTIFIER_LIST) {
        
    }
    ~variable_identifier_list() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class procedural_timing_control_statement: public object {
    ast_type                        type;
    
public: 
    // 
    procedural_timing_control_statement(): object(AST_PROCEDURAL_TIMING_CONTROL_STATEMENT) {
        
    }
    ~procedural_timing_control_statement() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class delay_or_event_control: public object {
    ast_type                        type;
    
public: 
    // 
    delay_or_event_control(): object(AST_DELAY_OR_EVENT_CONTROL) {
        
    }
    ~delay_or_event_control() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class delay_control: public object {
    ast_type                        type;
    
public: 
    // 
    delay_control(): object(AST_DELAY_CONTROL) {
        
    }
    ~delay_control() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class event_control: public object {
    ast_type                        type;
    
public: 
    // 
    event_control(): object(AST_EVENT_CONTROL) {
        
    }
    ~event_control() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class event_expression: public object {
    ast_type                        type;
    
public: 
    // 
    event_expression(): object(AST_EVENT_EXPRESSION) {
        
    }
    ~event_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class procedural_timing_control: public object {
    ast_type                        type;
    
public: 
    // 
    procedural_timing_control(): object(AST_PROCEDURAL_TIMING_CONTROL) {
        
    }
    ~procedural_timing_control() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class jump_statement: public object {
    ast_type                        type;
    
public: 
    // 
    jump_statement(): object(AST_JUMP_STATEMENT) {
        
    }
    ~jump_statement() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class wait_statement: public object {
    ast_type                        type;
    
public: 
    // 
    wait_statement(): object(AST_WAIT_STATEMENT) {
        
    }
    ~wait_statement() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class event_trigger: public object {
    ast_type                        type;
    
public: 
    // 
    event_trigger(): object(AST_EVENT_TRIGGER) {
        
    }
    ~event_trigger() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class disable_statement: public object {
    ast_type                        type;
    
public: 
    // 
    disable_statement(): object(AST_DISABLE_STATEMENT) {
        
    }
    ~disable_statement() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class conditional_statement: public object {
    ast_type                        type;
    
public: 
    // 
    conditional_statement(): object(AST_CONDITIONAL_STATEMENT) {
        
    }
    ~conditional_statement() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class unique_priority: public object {
    ast_type                        type;
    
public: 
    // 
    unique_priority(): object(AST_UNIQUE_PRIORITY) {
        
    }
    ~unique_priority() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class cond_predicate: public object {
    ast_type                        type;
    
public: 
    // 
    cond_predicate(): object(AST_COND_PREDICATE) {
        
    }
    ~cond_predicate() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class expression_or_cond_pattern: public object {
    ast_type                        type;
    
public: 
    // 
    expression_or_cond_pattern(): object(AST_EXPRESSION_OR_COND_PATTERN) {
        
    }
    ~expression_or_cond_pattern() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class cond_pattern: public object {
    ast_type                        type;
    
public: 
    // 
    cond_pattern(): object(AST_COND_PATTERN) {
        
    }
    ~cond_pattern() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class case_statement: public object {
    ast_type                        type;
    
public: 
    // 
    case_statement(): object(AST_CASE_STATEMENT) {
        
    }
    ~case_statement() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class case_keyword: public object {
    ast_type                        type;
    
public: 
    // 
    case_keyword(): object(AST_CASE_KEYWORD) {
        
    }
    ~case_keyword() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class case_expression: public object {
    ast_type                        type;
    
public: 
    // 
    case_expression(): object(AST_CASE_EXPRESSION) {
        
    }
    ~case_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class case_item: public object {
    ast_type                        type;
    
public: 
    // 
    case_item(): object(AST_CASE_ITEM) {
        
    }
    ~case_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class case_pattern_item: public object {
    ast_type                        type;
    
public: 
    // 
    case_pattern_item(): object(AST_CASE_PATTERN_ITEM) {
        
    }
    ~case_pattern_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class case_inside_item: public object {
    ast_type                        type;
    
public: 
    // 
    case_inside_item(): object(AST_CASE_INSIDE_ITEM) {
        
    }
    ~case_inside_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class case_item_expression: public object {
    ast_type                        type;
    
public: 
    // 
    case_item_expression(): object(AST_CASE_ITEM_EXPRESSION) {
        
    }
    ~case_item_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class randcase_statement: public object {
    ast_type                        type;
    
public: 
    // 
    randcase_statement(): object(AST_RANDCASE_STATEMENT) {
        
    }
    ~randcase_statement() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class randcase_item: public object {
    ast_type                        type;
    
public: 
    // 
    randcase_item(): object(AST_RANDCASE_ITEM) {
        
    }
    ~randcase_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class open_range_list: public object {
    ast_type                        type;
    
public: 
    // 
    open_range_list(): object(AST_OPEN_RANGE_LIST) {
        
    }
    ~open_range_list() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class open_value_range: public object {
    ast_type                        type;
    
public: 
    // 
    open_value_range(): object(AST_OPEN_VALUE_RANGE) {
        
    }
    ~open_value_range() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class pattern: public object {
    ast_type                        type;
    
public: 
    // 
    pattern(): object(AST_PATTERN) {
        
    }
    ~pattern() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class assignment_pattern: public object {
    ast_type                        type;
    
public: 
    // 
    assignment_pattern(): object(AST_ASSIGNMENT_PATTERN) {
        
    }
    ~assignment_pattern() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class structure_pattern_key: public object {
    ast_type                        type;
    
public: 
    // 
    structure_pattern_key(): object(AST_STRUCTURE_PATTERN_KEY) {
        
    }
    ~structure_pattern_key() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class array_pattern_key: public object {
    ast_type                        type;
    
public: 
    // 
    array_pattern_key(): object(AST_ARRAY_PATTERN_KEY) {
        
    }
    ~array_pattern_key() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class assignment_pattern_key: public object {
    ast_type                        type;
    
public: 
    // 
    assignment_pattern_key(): object(AST_ASSIGNMENT_PATTERN_KEY) {
        
    }
    ~assignment_pattern_key() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class assignment_pattern_expression: public object {
    ast_type                        type;
    
public: 
    // 
    assignment_pattern_expression(): object(AST_ASSIGNMENT_PATTERN_EXPRESSION) {
        
    }
    ~assignment_pattern_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class assignment_pattern_expression_type: public object {
    ast_type                        type;
    
public: 
    // 
    assignment_pattern_expression_type(): object(AST_ASSIGNMENT_PATTERN_EXPRESSION_TYPE) {
        
    }
    ~assignment_pattern_expression_type() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class constant_assignment_pattern_expression: public object {
    ast_type                        type;
    
public: 
    // 
    constant_assignment_pattern_expression(): object(AST_CONSTANT_ASSIGNMENT_PATTERN_EXPRESSION) {
        
    }
    ~constant_assignment_pattern_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class assignment_pattern_net_lvalue: public object {
    ast_type                        type;
    
public: 
    // 
    assignment_pattern_net_lvalue(): object(AST_ASSIGNMENT_PATTERN_NET_LVALUE) {
        
    }
    ~assignment_pattern_net_lvalue() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class assignment_pattern_variable_lvalue: public object {
    ast_type                        type;
    
public: 
    // 
    assignment_pattern_variable_lvalue(): object(AST_ASSIGNMENT_PATTERN_VARIABLE_LVALUE) {
        
    }
    ~assignment_pattern_variable_lvalue() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class loop_statement: public object {
    ast_type                        type;
    
public: 
    // 
    loop_statement(): object(AST_LOOP_STATEMENT) {
        
    }
    ~loop_statement() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class for_initialization: public object {
    ast_type                        type;
    
public: 
    // 
    for_initialization(): object(AST_FOR_INITIALIZATION) {
        
    }
    ~for_initialization() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class for_variable_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    for_variable_declaration(): object(AST_FOR_VARIABLE_DECLARATION) {
        
    }
    ~for_variable_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class for_step: public object {
    ast_type                        type;
    
public: 
    // 
    for_step(): object(AST_FOR_STEP) {
        
    }
    ~for_step() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class for_step_assignment: public object {
    ast_type                        type;
    
public: 
    // 
    for_step_assignment(): object(AST_FOR_STEP_ASSIGNMENT) {
        
    }
    ~for_step_assignment() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class loop_variables: public object {
    ast_type                        type;
    
public: 
    // 
    loop_variables(): object(AST_LOOP_VARIABLES) {
        
    }
    ~loop_variables() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class subroutine_call_statement: public object {
    ast_type                        type;
    
public: 
    // 
    subroutine_call_statement(): object(AST_SUBROUTINE_CALL_STATEMENT) {
        
    }
    ~subroutine_call_statement() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class assertion_item: public object {
    ast_type                        type;
    
public: 
    // 
    assertion_item(): object(AST_ASSERTION_ITEM) {
        
    }
    ~assertion_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class deferred_immediate_assertion_item: public object {
    ast_type                        type;
    
public: 
    // 
    deferred_immediate_assertion_item(): object(AST_DEFERRED_IMMEDIATE_ASSERTION_ITEM) {
        
    }
    ~deferred_immediate_assertion_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class procedural_assertion_statement: public object {
    ast_type                        type;
    
public: 
    // 
    procedural_assertion_statement(): object(AST_PROCEDURAL_ASSERTION_STATEMENT) {
        
    }
    ~procedural_assertion_statement() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class immediate_assertion_statement: public object {
    ast_type                        type;
    
public: 
    // 
    immediate_assertion_statement(): object(AST_IMMEDIATE_ASSERTION_STATEMENT) {
        
    }
    ~immediate_assertion_statement() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class simple_immediate_assertion_statement: public object {
    ast_type                        type;
    
public: 
    // 
    simple_immediate_assertion_statement(): object(AST_SIMPLE_IMMEDIATE_ASSERTION_STATEMENT) {
        
    }
    ~simple_immediate_assertion_statement() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class simple_immediate_assert_statement: public object {
    ast_type                        type;
    
public: 
    // 
    simple_immediate_assert_statement(): object(AST_SIMPLE_IMMEDIATE_ASSERT_STATEMENT) {
        
    }
    ~simple_immediate_assert_statement() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class simple_immediate_assume_statement: public object {
    ast_type                        type;
    
public: 
    // 
    simple_immediate_assume_statement(): object(AST_SIMPLE_IMMEDIATE_ASSUME_STATEMENT) {
        
    }
    ~simple_immediate_assume_statement() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class simple_immediate_cover_statement: public object {
    ast_type                        type;
    
public: 
    // 
    simple_immediate_cover_statement(): object(AST_SIMPLE_IMMEDIATE_COVER_STATEMENT) {
        
    }
    ~simple_immediate_cover_statement() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class deferred_immediate_assertion_statement: public object {
    ast_type                        type;
    
public: 
    // 
    deferred_immediate_assertion_statement(): object(AST_DEFERRED_IMMEDIATE_ASSERTION_STATEMENT) {
        
    }
    ~deferred_immediate_assertion_statement() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class deferred_immediate_assert_statement: public object {
    ast_type                        type;
    
public: 
    // 
    deferred_immediate_assert_statement(): object(AST_DEFERRED_IMMEDIATE_ASSERT_STATEMENT) {
        
    }
    ~deferred_immediate_assert_statement() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class deferred_immediate_assume_statement: public object {
    ast_type                        type;
    
public: 
    // 
    deferred_immediate_assume_statement(): object(AST_DEFERRED_IMMEDIATE_ASSUME_STATEMENT) {
        
    }
    ~deferred_immediate_assume_statement() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class deferred_immediate_cover_statement: public object {
    ast_type                        type;
    
public: 
    // 
    deferred_immediate_cover_statement(): object(AST_DEFERRED_IMMEDIATE_COVER_STATEMENT) {
        
    }
    ~deferred_immediate_cover_statement() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class clocking_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    clocking_declaration(): object(AST_CLOCKING_DECLARATION) {
        
    }
    ~clocking_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class clocking_event: public object {
    ast_type                        type;
    
public: 
    // 
    clocking_event(): object(AST_CLOCKING_EVENT) {
        
    }
    ~clocking_event() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class clocking_item: public object {
    ast_type                        type;
    
public: 
    // 
    clocking_item(): object(AST_CLOCKING_ITEM) {
        
    }
    ~clocking_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class default_skew: public object {
    ast_type                        type;
    
public: 
    // 
    default_skew(): object(AST_DEFAULT_SKEW) {
        
    }
    ~default_skew() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class clocking_direction: public object {
    ast_type                        type;
    
public: 
    // 
    clocking_direction(): object(AST_CLOCKING_DIRECTION) {
        
    }
    ~clocking_direction() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class list_of_clocking_decl_assign: public object {
    ast_type                        type;
    
public: 
    // 
    list_of_clocking_decl_assign(): object(AST_LIST_OF_CLOCKING_DECL_ASSIGN) {
        
    }
    ~list_of_clocking_decl_assign() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class clocking_decl_assign: public object {
    ast_type                        type;
    
public: 
    // 
    clocking_decl_assign(): object(AST_CLOCKING_DECL_ASSIGN) {
        
    }
    ~clocking_decl_assign() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class clocking_skew: public object {
    ast_type                        type;
    
public: 
    // 
    clocking_skew(): object(AST_CLOCKING_SKEW) {
        
    }
    ~clocking_skew() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class clocking_drive: public object {
    ast_type                        type;
    
public: 
    // 
    clocking_drive(): object(AST_CLOCKING_DRIVE) {
        
    }
    ~clocking_drive() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class cycle_delay: public object {
    ast_type                        type;
    
public: 
    // 
    cycle_delay(): object(AST_CYCLE_DELAY) {
        
    }
    ~cycle_delay() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class clockvar: public object {
    ast_type                        type;
    
public: 
    // 
    clockvar(): object(AST_CLOCKVAR) {
        
    }
    ~clockvar() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class clockvar_expression: public object {
    ast_type                        type;
    
public: 
    // 
    clockvar_expression(): object(AST_CLOCKVAR_EXPRESSION) {
        
    }
    ~clockvar_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class randsequence_statement: public object {
    ast_type                        type;
    
public: 
    // 
    randsequence_statement(): object(AST_RANDSEQUENCE_STATEMENT) {
        
    }
    ~randsequence_statement() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class production: public object {
    ast_type                        type;
    
public: 
    // 
    production(): object(AST_PRODUCTION) {
        
    }
    ~production() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class rs_rule: public object {
    ast_type                        type;
    
public: 
    // 
    rs_rule(): object(AST_RS_RULE) {
        
    }
    ~rs_rule() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class rs_production_list: public object {
    ast_type                        type;
    
public: 
    // 
    rs_production_list(): object(AST_RS_PRODUCTION_LIST) {
        
    }
    ~rs_production_list() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class weight_specification: public object {
    ast_type                        type;
    
public: 
    // 
    weight_specification(): object(AST_WEIGHT_SPECIFICATION) {
        
    }
    ~weight_specification() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class rs_code_block: public object {
    ast_type                        type;
    
public: 
    // 
    rs_code_block(): object(AST_RS_CODE_BLOCK) {
        
    }
    ~rs_code_block() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class rs_prod: public object {
    ast_type                        type;
    
public: 
    // 
    rs_prod(): object(AST_RS_PROD) {
        
    }
    ~rs_prod() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class production_item: public object {
    ast_type                        type;
    
public: 
    // 
    production_item(): object(AST_PRODUCTION_ITEM) {
        
    }
    ~production_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class rs_if_else: public object {
    ast_type                        type;
    
public: 
    // 
    rs_if_else(): object(AST_RS_IF_ELSE) {
        
    }
    ~rs_if_else() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class rs_repeat: public object {
    ast_type                        type;
    
public: 
    // 
    rs_repeat(): object(AST_RS_REPEAT) {
        
    }
    ~rs_repeat() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class rs_case: public object {
    ast_type                        type;
    
public: 
    // 
    rs_case(): object(AST_RS_CASE) {
        
    }
    ~rs_case() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class rs_case_item: public object {
    ast_type                        type;
    
public: 
    // 
    rs_case_item(): object(AST_RS_CASE_ITEM) {
        
    }
    ~rs_case_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class specify_block: public object {
    ast_type                        type;
    
public: 
    // 
    specify_block(): object(AST_SPECIFY_BLOCK) {
        
    }
    ~specify_block() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class specify_item: public object {
    ast_type                        type;
    
public: 
    // 
    specify_item(): object(AST_SPECIFY_ITEM) {
        
    }
    ~specify_item() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class pulsestyle_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    pulsestyle_declaration(): object(AST_PULSESTYLE_DECLARATION) {
        
    }
    ~pulsestyle_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class showcancelled_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    showcancelled_declaration(): object(AST_SHOWCANCELLED_DECLARATION) {
        
    }
    ~showcancelled_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class path_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    path_declaration(): object(AST_PATH_DECLARATION) {
        
    }
    ~path_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class simple_path_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    simple_path_declaration(): object(AST_SIMPLE_PATH_DECLARATION) {
        
    }
    ~simple_path_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class parallel_path_description: public object {
    ast_type                        type;
    
public: 
    // 
    parallel_path_description(): object(AST_PARALLEL_PATH_DESCRIPTION) {
        
    }
    ~parallel_path_description() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class full_path_description: public object {
    ast_type                        type;
    
public: 
    // 
    full_path_description(): object(AST_FULL_PATH_DESCRIPTION) {
        
    }
    ~full_path_description() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class list_of_path_inputs: public object {
    ast_type                        type;
    
public: 
    // 
    list_of_path_inputs(): object(AST_LIST_OF_PATH_INPUTS) {
        
    }
    ~list_of_path_inputs() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class list_of_path_outputs: public object {
    ast_type                        type;
    
public: 
    // 
    list_of_path_outputs(): object(AST_LIST_OF_PATH_OUTPUTS) {
        
    }
    ~list_of_path_outputs() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class specify_input_terminal_descriptor: public object {
    ast_type                        type;
    
public: 
    // 
    specify_input_terminal_descriptor(): object(AST_SPECIFY_INPUT_TERMINAL_DESCRIPTOR) {
        
    }
    ~specify_input_terminal_descriptor() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class specify_output_terminal_descriptor: public object {
    ast_type                        type;
    
public: 
    // 
    specify_output_terminal_descriptor(): object(AST_SPECIFY_OUTPUT_TERMINAL_DESCRIPTOR) {
        
    }
    ~specify_output_terminal_descriptor() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class input_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    input_identifier(): object(AST_INPUT_IDENTIFIER) {
        
    }
    ~input_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class output_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    output_identifier(): object(AST_OUTPUT_IDENTIFIER) {
        
    }
    ~output_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class path_delay_value: public object {
    ast_type                        type;
    
public: 
    // 
    path_delay_value(): object(AST_PATH_DELAY_VALUE) {
        
    }
    ~path_delay_value() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class list_of_path_delay_expressions: public object {
    ast_type                        type;
    
public: 
    // 
    list_of_path_delay_expressions(): object(AST_LIST_OF_PATH_DELAY_EXPRESSIONS) {
        
    }
    ~list_of_path_delay_expressions() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class t_path_delay_expression: public object {
    ast_type                        type;
    
public: 
    // 
    t_path_delay_expression(): object(AST_T_PATH_DELAY_EXPRESSION) {
        
    }
    ~t_path_delay_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class trise_path_delay_expression: public object {
    ast_type                        type;
    
public: 
    // 
    trise_path_delay_expression(): object(AST_TRISE_PATH_DELAY_EXPRESSION) {
        
    }
    ~trise_path_delay_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class tfall_path_delay_expression: public object {
    ast_type                        type;
    
public: 
    // 
    tfall_path_delay_expression(): object(AST_TFALL_PATH_DELAY_EXPRESSION) {
        
    }
    ~tfall_path_delay_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class tz_path_delay_expression: public object {
    ast_type                        type;
    
public: 
    // 
    tz_path_delay_expression(): object(AST_TZ_PATH_DELAY_EXPRESSION) {
        
    }
    ~tz_path_delay_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class t01_path_delay_expression: public object {
    ast_type                        type;
    
public: 
    // 
    t01_path_delay_expression(): object(AST_T01_PATH_DELAY_EXPRESSION) {
        
    }
    ~t01_path_delay_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class t10_path_delay_expression: public object {
    ast_type                        type;
    
public: 
    // 
    t10_path_delay_expression(): object(AST_T10_PATH_DELAY_EXPRESSION) {
        
    }
    ~t10_path_delay_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class t0z_path_delay_expression: public object {
    ast_type                        type;
    
public: 
    // 
    t0z_path_delay_expression(): object(AST_T0Z_PATH_DELAY_EXPRESSION) {
        
    }
    ~t0z_path_delay_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class tz1_path_delay_expression: public object {
    ast_type                        type;
    
public: 
    // 
    tz1_path_delay_expression(): object(AST_TZ1_PATH_DELAY_EXPRESSION) {
        
    }
    ~tz1_path_delay_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class t1z_path_delay_expression: public object {
    ast_type                        type;
    
public: 
    // 
    t1z_path_delay_expression(): object(AST_T1Z_PATH_DELAY_EXPRESSION) {
        
    }
    ~t1z_path_delay_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class tz0_path_delay_expression: public object {
    ast_type                        type;
    
public: 
    // 
    tz0_path_delay_expression(): object(AST_TZ0_PATH_DELAY_EXPRESSION) {
        
    }
    ~tz0_path_delay_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class t0x_path_delay_expression: public object {
    ast_type                        type;
    
public: 
    // 
    t0x_path_delay_expression(): object(AST_T0X_PATH_DELAY_EXPRESSION) {
        
    }
    ~t0x_path_delay_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class tx1_path_delay_expression: public object {
    ast_type                        type;
    
public: 
    // 
    tx1_path_delay_expression(): object(AST_TX1_PATH_DELAY_EXPRESSION) {
        
    }
    ~tx1_path_delay_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class t1x_path_delay_expression: public object {
    ast_type                        type;
    
public: 
    // 
    t1x_path_delay_expression(): object(AST_T1X_PATH_DELAY_EXPRESSION) {
        
    }
    ~t1x_path_delay_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class tx0_path_delay_expression: public object {
    ast_type                        type;
    
public: 
    // 
    tx0_path_delay_expression(): object(AST_TX0_PATH_DELAY_EXPRESSION) {
        
    }
    ~tx0_path_delay_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class txz_path_delay_expression: public object {
    ast_type                        type;
    
public: 
    // 
    txz_path_delay_expression(): object(AST_TXZ_PATH_DELAY_EXPRESSION) {
        
    }
    ~txz_path_delay_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class tzx_path_delay_expression: public object {
    ast_type                        type;
    
public: 
    // 
    tzx_path_delay_expression(): object(AST_TZX_PATH_DELAY_EXPRESSION) {
        
    }
    ~tzx_path_delay_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class path_delay_expression: public object {
    ast_type                        type;
    
public: 
    // 
    path_delay_expression(): object(AST_PATH_DELAY_EXPRESSION) {
        
    }
    ~path_delay_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class edge_sensitive_path_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    edge_sensitive_path_declaration(): object(AST_EDGE_SENSITIVE_PATH_DECLARATION) {
        
    }
    ~edge_sensitive_path_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class parallel_edge_sensitive_path_description: public object {
    ast_type                        type;
    
public: 
    // 
    parallel_edge_sensitive_path_description(): object(AST_PARALLEL_EDGE_SENSITIVE_PATH_DESCRIPTION) {
        
    }
    ~parallel_edge_sensitive_path_description() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class full_edge_sensitive_path_description: public object {
    ast_type                        type;
    
public: 
    // 
    full_edge_sensitive_path_description(): object(AST_FULL_EDGE_SENSITIVE_PATH_DESCRIPTION) {
        
    }
    ~full_edge_sensitive_path_description() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class data_source_expression: public object {
    ast_type                        type;
    
public: 
    // 
    data_source_expression(): object(AST_DATA_SOURCE_EXPRESSION) {
        
    }
    ~data_source_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class edge_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    edge_identifier(): object(AST_EDGE_IDENTIFIER) {
        
    }
    ~edge_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class state_dependent_path_declaration: public object {
    ast_type                        type;
    
public: 
    // 
    state_dependent_path_declaration(): object(AST_STATE_DEPENDENT_PATH_DECLARATION) {
        
    }
    ~state_dependent_path_declaration() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class polarity_operator: public object {
    ast_type                        type;
    
public: 
    // 
    polarity_operator(): object(AST_POLARITY_OPERATOR) {
        
    }
    ~polarity_operator() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class system_timing_check: public object {
    ast_type                        type;
    
public: 
    // 
    system_timing_check(): object(AST_SYSTEM_TIMING_CHECK) {
        
    }
    ~system_timing_check() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class dollarsign_setup_timing_check: public object {
    ast_type                        type;
    
public: 
    // 
    dollarsign_setup_timing_check(): object(AST_DOLLARSIGN_SETUP_TIMING_CHECK) {
        
    }
    ~dollarsign_setup_timing_check() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class dollarsign_hold_timing_check: public object {
    ast_type                        type;
    
public: 
    // 
    dollarsign_hold_timing_check(): object(AST_DOLLARSIGN_HOLD_TIMING_CHECK) {
        
    }
    ~dollarsign_hold_timing_check() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class dollarsign_setuphold_timing_check: public object {
    ast_type                        type;
    
public: 
    // 
    dollarsign_setuphold_timing_check(): object(AST_DOLLARSIGN_SETUPHOLD_TIMING_CHECK) {
        
    }
    ~dollarsign_setuphold_timing_check() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class dollarsign_recovery_timing_check: public object {
    ast_type                        type;
    
public: 
    // 
    dollarsign_recovery_timing_check(): object(AST_DOLLARSIGN_RECOVERY_TIMING_CHECK) {
        
    }
    ~dollarsign_recovery_timing_check() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class dollarsign_removal_timing_check: public object {
    ast_type                        type;
    
public: 
    // 
    dollarsign_removal_timing_check(): object(AST_DOLLARSIGN_REMOVAL_TIMING_CHECK) {
        
    }
    ~dollarsign_removal_timing_check() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class dollarsign_recrem_timing_check: public object {
    ast_type                        type;
    
public: 
    // 
    dollarsign_recrem_timing_check(): object(AST_DOLLARSIGN_RECREM_TIMING_CHECK) {
        
    }
    ~dollarsign_recrem_timing_check() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class dollarsign_skew_timing_check: public object {
    ast_type                        type;
    
public: 
    // 
    dollarsign_skew_timing_check(): object(AST_DOLLARSIGN_SKEW_TIMING_CHECK) {
        
    }
    ~dollarsign_skew_timing_check() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class dollarsign_timeskew_timing_check: public object {
    ast_type                        type;
    
public: 
    // 
    dollarsign_timeskew_timing_check(): object(AST_DOLLARSIGN_TIMESKEW_TIMING_CHECK) {
        
    }
    ~dollarsign_timeskew_timing_check() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class dollarsign_fullskew_timing_check: public object {
    ast_type                        type;
    
public: 
    // 
    dollarsign_fullskew_timing_check(): object(AST_DOLLARSIGN_FULLSKEW_TIMING_CHECK) {
        
    }
    ~dollarsign_fullskew_timing_check() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class dollarsign_period_timing_check: public object {
    ast_type                        type;
    
public: 
    // 
    dollarsign_period_timing_check(): object(AST_DOLLARSIGN_PERIOD_TIMING_CHECK) {
        
    }
    ~dollarsign_period_timing_check() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class dollarsign_width_timing_check: public object {
    ast_type                        type;
    
public: 
    // 
    dollarsign_width_timing_check(): object(AST_DOLLARSIGN_WIDTH_TIMING_CHECK) {
        
    }
    ~dollarsign_width_timing_check() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class dollarsign_nochange_timing_check: public object {
    ast_type                        type;
    
public: 
    // 
    dollarsign_nochange_timing_check(): object(AST_DOLLARSIGN_NOCHANGE_TIMING_CHECK) {
        
    }
    ~dollarsign_nochange_timing_check() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class timecheck_condition: public object {
    ast_type                        type;
    
public: 
    // 
    timecheck_condition(): object(AST_TIMECHECK_CONDITION) {
        
    }
    ~timecheck_condition() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class controlled_reference_event: public object {
    ast_type                        type;
    
public: 
    // 
    controlled_reference_event(): object(AST_CONTROLLED_REFERENCE_EVENT) {
        
    }
    ~controlled_reference_event() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class data_event: public object {
    ast_type                        type;
    
public: 
    // 
    data_event(): object(AST_DATA_EVENT) {
        
    }
    ~data_event() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class delayed_data: public object {
    ast_type                        type;
    
public: 
    // 
    delayed_data(): object(AST_DELAYED_DATA) {
        
    }
    ~delayed_data() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class delayed_reference: public object {
    ast_type                        type;
    
public: 
    // 
    delayed_reference(): object(AST_DELAYED_REFERENCE) {
        
    }
    ~delayed_reference() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class end_edge_offset: public object {
    ast_type                        type;
    
public: 
    // 
    end_edge_offset(): object(AST_END_EDGE_OFFSET) {
        
    }
    ~end_edge_offset() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class event_based_flag: public object {
    ast_type                        type;
    
public: 
    // 
    event_based_flag(): object(AST_EVENT_BASED_FLAG) {
        
    }
    ~event_based_flag() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class notifier: public object {
    ast_type                        type;
    
public: 
    // 
    notifier(): object(AST_NOTIFIER) {
        
    }
    ~notifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class reference_event: public object {
    ast_type                        type;
    
public: 
    // 
    reference_event(): object(AST_REFERENCE_EVENT) {
        
    }
    ~reference_event() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class remain_active_flag: public object {
    ast_type                        type;
    
public: 
    // 
    remain_active_flag(): object(AST_REMAIN_ACTIVE_FLAG) {
        
    }
    ~remain_active_flag() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class timestamp_condition: public object {
    ast_type                        type;
    
public: 
    // 
    timestamp_condition(): object(AST_TIMESTAMP_CONDITION) {
        
    }
    ~timestamp_condition() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class start_edge_offset: public object {
    ast_type                        type;
    
public: 
    // 
    start_edge_offset(): object(AST_START_EDGE_OFFSET) {
        
    }
    ~start_edge_offset() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class threshold: public object {
    ast_type                        type;
    
public: 
    // 
    threshold(): object(AST_THRESHOLD) {
        
    }
    ~threshold() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class timing_check_limit: public object {
    ast_type                        type;
    
public: 
    // 
    timing_check_limit(): object(AST_TIMING_CHECK_LIMIT) {
        
    }
    ~timing_check_limit() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class timing_check_event: public object {
    ast_type                        type;
    
public: 
    // 
    timing_check_event(): object(AST_TIMING_CHECK_EVENT) {
        
    }
    ~timing_check_event() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class controlled_timing_check_event: public object {
    ast_type                        type;
    
public: 
    // 
    controlled_timing_check_event(): object(AST_CONTROLLED_TIMING_CHECK_EVENT) {
        
    }
    ~controlled_timing_check_event() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class timing_check_event_control: public object {
    ast_type                        type;
    
public: 
    // 
    timing_check_event_control(): object(AST_TIMING_CHECK_EVENT_CONTROL) {
        
    }
    ~timing_check_event_control() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class specify_terminal_descriptor: public object {
    ast_type                        type;
    
public: 
    // 
    specify_terminal_descriptor(): object(AST_SPECIFY_TERMINAL_DESCRIPTOR) {
        
    }
    ~specify_terminal_descriptor() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class edge_control_specifier: public object {
    ast_type                        type;
    
public: 
    // 
    edge_control_specifier(): object(AST_EDGE_CONTROL_SPECIFIER) {
        
    }
    ~edge_control_specifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class edge_descriptor: public object {
    ast_type                        type;
    
public: 
    // 
    edge_descriptor(): object(AST_EDGE_DESCRIPTOR) {
        
    }
    ~edge_descriptor() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class zero_or_one: public object {
    ast_type                        type;
    
public: 
    // 
    zero_or_one(): object(AST_ZERO_OR_ONE) {
        
    }
    ~zero_or_one() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class z_or_x: public object {
    ast_type                        type;
    
public: 
    // 
    z_or_x(): object(AST_Z_OR_X) {
        
    }
    ~z_or_x() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class timing_check_condition: public object {
    ast_type                        type;
    
public: 
    // 
    timing_check_condition(): object(AST_TIMING_CHECK_CONDITION) {
        
    }
    ~timing_check_condition() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class scalar_timing_check_condition: public object {
    ast_type                        type;
    
public: 
    // 
    scalar_timing_check_condition(): object(AST_SCALAR_TIMING_CHECK_CONDITION) {
        
    }
    ~scalar_timing_check_condition() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class scalar_constant: public object {
    ast_type                        type;
    
public: 
    // 
    scalar_constant(): object(AST_SCALAR_CONSTANT) {
        
    }
    ~scalar_constant() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class concatenation: public object {
    ast_type                        type;
    
public: 
    // 
    concatenation(): object(AST_CONCATENATION) {
        
    }
    ~concatenation() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class constant_concatenation: public object {
    ast_type                        type;
    
public: 
    // 
    constant_concatenation(): object(AST_CONSTANT_CONCATENATION) {
        
    }
    ~constant_concatenation() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class constant_multiple_concatenation: public object {
    ast_type                        type;
    
public: 
    // 
    constant_multiple_concatenation(): object(AST_CONSTANT_MULTIPLE_CONCATENATION) {
        
    }
    ~constant_multiple_concatenation() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class module_path_concatenation: public object {
    ast_type                        type;
    
public: 
    // 
    module_path_concatenation(): object(AST_MODULE_PATH_CONCATENATION) {
        
    }
    ~module_path_concatenation() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class module_path_multiple_concatenation: public object {
    ast_type                        type;
    
public: 
    // 
    module_path_multiple_concatenation(): object(AST_MODULE_PATH_MULTIPLE_CONCATENATION) {
        
    }
    ~module_path_multiple_concatenation() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class multiple_concatenation: public object {
    ast_type                        type;
    
public: 
    // 
    multiple_concatenation(): object(AST_MULTIPLE_CONCATENATION) {
        
    }
    ~multiple_concatenation() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class streaming_concatenation: public object {
    ast_type                        type;
    
public: 
    // 
    streaming_concatenation(): object(AST_STREAMING_CONCATENATION) {
        
    }
    ~streaming_concatenation() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class stream_operator: public object {
    ast_type                        type;
    
public: 
    // 
    stream_operator(): object(AST_STREAM_OPERATOR) {
        
    }
    ~stream_operator() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class slice_size: public object {
    ast_type                        type;
    
public: 
    // 
    slice_size(): object(AST_SLICE_SIZE) {
        
    }
    ~slice_size() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class stream_concatenation: public object {
    ast_type                        type;
    
public: 
    // 
    stream_concatenation(): object(AST_STREAM_CONCATENATION) {
        
    }
    ~stream_concatenation() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class stream_expression: public object {
    ast_type                        type;
    
public: 
    // 
    stream_expression(): object(AST_STREAM_EXPRESSION) {
        
    }
    ~stream_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class array_range_expression: public object {
    ast_type                        type;
    
public: 
    // 
    array_range_expression(): object(AST_ARRAY_RANGE_EXPRESSION) {
        
    }
    ~array_range_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class empty_queue: public object {
    ast_type                        type;
    
public: 
    // 
    empty_queue(): object(AST_EMPTY_QUEUE) {
        
    }
    ~empty_queue() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class constant_function_call: public object {
    ast_type                        type;
    
public: 
    // 
    constant_function_call(): object(AST_CONSTANT_FUNCTION_CALL) {
        
    }
    ~constant_function_call() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class tf_call: public object {
    ast_type                        type;
    
public: 
    // 
    tf_call(): object(AST_TF_CALL) {
        
    }
    ~tf_call() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class system_tf_call: public object {
    ast_type                        type;
    
public: 
    // 
    system_tf_call(): object(AST_SYSTEM_TF_CALL) {
        
    }
    ~system_tf_call() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class subroutine_call: public object {
    ast_type                        type;
    
public: 
    // 
    subroutine_call(): object(AST_SUBROUTINE_CALL) {
        
    }
    ~subroutine_call() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class function_subroutine_call: public object {
    ast_type                        type;
    
public: 
    // 
    function_subroutine_call(): object(AST_FUNCTION_SUBROUTINE_CALL) {
        
    }
    ~function_subroutine_call() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class list_of_arguments: public object {
    ast_type                        type;
    
public: 
    // 
    list_of_arguments(): object(AST_LIST_OF_ARGUMENTS) {
        
    }
    ~list_of_arguments() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class method_call: public object {
    ast_type                        type;
    
public: 
    // 
    method_call(): object(AST_METHOD_CALL) {
        
    }
    ~method_call() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class method_call_body: public object {
    ast_type                        type;
    
public: 
    // 
    method_call_body(): object(AST_METHOD_CALL_BODY) {
        
    }
    ~method_call_body() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class built_in_method_call: public object {
    ast_type                        type;
    
public: 
    // 
    built_in_method_call(): object(AST_BUILT_IN_METHOD_CALL) {
        
    }
    ~built_in_method_call() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class array_manipulation_call: public object {
    ast_type                        type;
    
public: 
    // 
    array_manipulation_call(): object(AST_ARRAY_MANIPULATION_CALL) {
        
    }
    ~array_manipulation_call() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class randomize_call: public object {
    ast_type                        type;
    
public: 
    // 
    randomize_call(): object(AST_RANDOMIZE_CALL) {
        
    }
    ~randomize_call() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class method_call_root: public object {
    ast_type                        type;
    
public: 
    // 
    method_call_root(): object(AST_METHOD_CALL_ROOT) {
        
    }
    ~method_call_root() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class array_method_name: public object {
    ast_type                        type;
    
public: 
    // 
    array_method_name(): object(AST_ARRAY_METHOD_NAME) {
        
    }
    ~array_method_name() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class inc_or_dec_expression: public object {
    ast_type                        type;
    
public: 
    // 
    inc_or_dec_expression(): object(AST_INC_OR_DEC_EXPRESSION) {
        
    }
    ~inc_or_dec_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class conditional_expression: public object {
    ast_type                        type;
    
public: 
    // 
    conditional_expression(): object(AST_CONDITIONAL_EXPRESSION) {
        
    }
    ~conditional_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class constant_expression: public object {
    ast_type                        type;
    
public: 
    // 
    constant_expression(): object(AST_CONSTANT_EXPRESSION) {
        
    }
    ~constant_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class constant_mintypmax_expression: public object {
    ast_type                        type;
    
public: 
    // 
    constant_mintypmax_expression(): object(AST_CONSTANT_MINTYPMAX_EXPRESSION) {
        
    }
    ~constant_mintypmax_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class constant_param_expression: public object {
    ast_type                        type;
    
public: 
    // 
    constant_param_expression(): object(AST_CONSTANT_PARAM_EXPRESSION) {
        
    }
    ~constant_param_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class param_expression: public object {
    ast_type                        type;
    
public: 
    // 
    param_expression(): object(AST_PARAM_EXPRESSION) {
        
    }
    ~param_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class constant_range_expression: public object {
    ast_type                        type;
    
public: 
    // 
    constant_range_expression(): object(AST_CONSTANT_RANGE_EXPRESSION) {
        
    }
    ~constant_range_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class constant_part_select_range: public object {
    ast_type                        type;
    
public: 
    // 
    constant_part_select_range(): object(AST_CONSTANT_PART_SELECT_RANGE) {
        
    }
    ~constant_part_select_range() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class constant_range: public object {
    ast_type                        type;
    
public: 
    // 
    constant_range(): object(AST_CONSTANT_RANGE) {
        
    }
    ~constant_range() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class constant_indexed_range: public object {
    ast_type                        type;
    
public: 
    // 
    constant_indexed_range(): object(AST_CONSTANT_INDEXED_RANGE) {
        
    }
    ~constant_indexed_range() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class expression: public object {
    ast_type                        type;
    
public: 
    // 
    expression(): object(AST_EXPRESSION) {
        
    }
    ~expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class tagged_union_expression: public object {
    ast_type                        type;
    
public: 
    // 
    tagged_union_expression(): object(AST_TAGGED_UNION_EXPRESSION) {
        
    }
    ~tagged_union_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class inside_expression: public object {
    ast_type                        type;
    
public: 
    // 
    inside_expression(): object(AST_INSIDE_EXPRESSION) {
        
    }
    ~inside_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class value_range: public object {
    ast_type                        type;
    
public: 
    // 
    value_range(): object(AST_VALUE_RANGE) {
        
    }
    ~value_range() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class mintypmax_expression: public object {
    ast_type                        type;
    
public: 
    // 
    mintypmax_expression(): object(AST_MINTYPMAX_EXPRESSION) {
        
    }
    ~mintypmax_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class module_path_conditional_expression: public object {
    ast_type                        type;
    
public: 
    // 
    module_path_conditional_expression(): object(AST_MODULE_PATH_CONDITIONAL_EXPRESSION) {
        
    }
    ~module_path_conditional_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class module_path_expression: public object {
    ast_type                        type;
    
public: 
    // 
    module_path_expression(): object(AST_MODULE_PATH_EXPRESSION) {
        
    }
    ~module_path_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class module_path_mintypmax_expression: public object {
    ast_type                        type;
    
public: 
    // 
    module_path_mintypmax_expression(): object(AST_MODULE_PATH_MINTYPMAX_EXPRESSION) {
        
    }
    ~module_path_mintypmax_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class part_select_range: public object {
    ast_type                        type;
    
public: 
    // 
    part_select_range(): object(AST_PART_SELECT_RANGE) {
        
    }
    ~part_select_range() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class indexed_range: public object {
    ast_type                        type;
    
public: 
    // 
    indexed_range(): object(AST_INDEXED_RANGE) {
        
    }
    ~indexed_range() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class genvar_expression: public object {
    ast_type                        type;
    
public: 
    // 
    genvar_expression(): object(AST_GENVAR_EXPRESSION) {
        
    }
    ~genvar_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class constant_primary: public object {
    ast_type                        type;
    
public: 
    // 
    constant_primary(): object(AST_CONSTANT_PRIMARY) {
        
    }
    ~constant_primary() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class module_path_primary: public object {
    ast_type                        type;
    
public: 
    // 
    module_path_primary(): object(AST_MODULE_PATH_PRIMARY) {
        
    }
    ~module_path_primary() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class primary: public object {
    ast_type                        type;
    
public: 
    // 
    primary(): object(AST_PRIMARY) {
        
    }
    ~primary() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class class_qualifier: public object {
    ast_type                        type;
    
public: 
    // 
    class_qualifier(): object(AST_CLASS_QUALIFIER) {
        
    }
    ~class_qualifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class range_expression: public object {
    ast_type                        type;
    
public: 
    // 
    range_expression(): object(AST_RANGE_EXPRESSION) {
        
    }
    ~range_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class primary_literal: public object {
    ast_type                        type;
    
public: 
    // 
    primary_literal(): object(AST_PRIMARY_LITERAL) {
        
    }
    ~primary_literal() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class time_literal: public object {
    ast_type                        type;
    
public: 
    // 
    time_literal(): object(AST_TIME_LITERAL) {
        
    }
    ~time_literal() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class time_unit: public object {
    ast_type                        type;
    
public: 
    // 
    time_unit(): object(AST_TIME_UNIT) {
        
    }
    ~time_unit() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class implicit_class_handle: public object {
    ast_type                        type;
    
public: 
    // 
    implicit_class_handle(): object(AST_IMPLICIT_CLASS_HANDLE) {
        
    }
    ~implicit_class_handle() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class bit_select: public object {
    ast_type                        type;
    
public: 
    // 
    bit_select(): object(AST_BIT_SELECT) {
        
    }
    ~bit_select() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class select: public object {
    ast_type                        type;
    
public: 
    // 
    select(): object(AST_SELECT) {
        
    }
    ~select() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class nonrange_select: public object {
    ast_type                        type;
    
public: 
    // 
    nonrange_select(): object(AST_NONRANGE_SELECT) {
        
    }
    ~nonrange_select() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class constant_bit_select: public object {
    ast_type                        type;
    
public: 
    // 
    constant_bit_select(): object(AST_CONSTANT_BIT_SELECT) {
        
    }
    ~constant_bit_select() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class constant_select: public object {
    ast_type                        type;
    
public: 
    // 
    constant_select(): object(AST_CONSTANT_SELECT) {
        
    }
    ~constant_select() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class constant_cast: public object {
    ast_type                        type;
    
public: 
    // 
    constant_cast(): object(AST_CONSTANT_CAST) {
        
    }
    ~constant_cast() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class constant_let_expression: public object {
    ast_type                        type;
    
public: 
    // 
    constant_let_expression(): object(AST_CONSTANT_LET_EXPRESSION) {
        
    }
    ~constant_let_expression() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class cast: public object {
    ast_type                        type;
    
public: 
    // 
    cast(): object(AST_CAST) {
        
    }
    ~cast() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class net_lvalue: public object {
    ast_type                        type;
    
public: 
    // 
    net_lvalue(): object(AST_NET_LVALUE) {
        
    }
    ~net_lvalue() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class variable_lvalue: public object {
    ast_type                        type;
    
public: 
    // 
    variable_lvalue(): object(AST_VARIABLE_LVALUE) {
        
    }
    ~variable_lvalue() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class nonrange_variable_lvalue: public object {
    ast_type                        type;
    
public: 
    // 
    nonrange_variable_lvalue(): object(AST_NONRANGE_VARIABLE_LVALUE) {
        
    }
    ~nonrange_variable_lvalue() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class unary_operator: public object {
    ast_type                        type;
    
public: 
    // 
    unary_operator(): object(AST_UNARY_OPERATOR) {
        
    }
    ~unary_operator() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class binary_operator: public object {
    ast_type                        type;
    
public: 
    // 
    binary_operator(): object(AST_BINARY_OPERATOR) {
        
    }
    ~binary_operator() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class inc_or_dec_operator: public object {
    ast_type                        type;
    
public: 
    // 
    inc_or_dec_operator(): object(AST_INC_OR_DEC_OPERATOR) {
        
    }
    ~inc_or_dec_operator() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class unary_module_path_operator: public object {
    ast_type                        type;
    
public: 
    // 
    unary_module_path_operator(): object(AST_UNARY_MODULE_PATH_OPERATOR) {
        
    }
    ~unary_module_path_operator() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class binary_module_path_operator: public object {
    ast_type                        type;
    
public: 
    // 
    binary_module_path_operator(): object(AST_BINARY_MODULE_PATH_OPERATOR) {
        
    }
    ~binary_module_path_operator() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class number: public object {
    ast_type                        type;
    
public: 
    // 
    number(): object(AST_NUMBER) {
        
    }
    ~number() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class integral_number: public object {
    ast_type                        type;
    
public: 
    // 
    integral_number(): object(AST_INTEGRAL_NUMBER) {
        
    }
    ~integral_number() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class decimal_number: public object {
    ast_type                        type;
    
public: 
    // 
    decimal_number(): object(AST_DECIMAL_NUMBER) {
        
    }
    ~decimal_number() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class octal_number: public object {
    ast_type                        type;
    
public: 
    // 
    octal_number(): object(AST_OCTAL_NUMBER) {
        
    }
    ~octal_number() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class binary_number: public object {
    ast_type                        type;
    
public: 
    // 
    binary_number(): object(AST_BINARY_NUMBER) {
        
    }
    ~binary_number() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class hex_number: public object {
    ast_type                        type;
    
public: 
    // 
    hex_number(): object(AST_HEX_NUMBER) {
        
    }
    ~hex_number() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class unsigned_number: public object {
    ast_type                        type;
    
public: 
    // 
    unsigned_number(): object(AST_UNSIGNED_NUMBER) {
        
    }
    ~unsigned_number() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class real_number: public object {
    ast_type                        type;
    
public: 
    // 
    real_number(): object(AST_REAL_NUMBER) {
        
    }
    ~real_number() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class fixed_point_number: public object {
    ast_type                        type;
    
public: 
    // 
    fixed_point_number(): object(AST_FIXED_POINT_NUMBER) {
        
    }
    ~fixed_point_number() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class unbased_unsized_literal: public object {
    ast_type                        type;
    
public: 
    // 
    unbased_unsized_literal(): object(AST_UNBASED_UNSIZED_LITERAL) {
        
    }
    ~unbased_unsized_literal() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class string_literal: public object {
    ast_type                        type;
    
public: 
    // 
    string_literal(): object(AST_STRING_LITERAL) {
        
    }
    ~string_literal() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class attribute_instance: public object {
    ast_type                        type;
    
public: 
    // 
    attribute_instance(): object(AST_ATTRIBUTE_INSTANCE) {
        
    }
    ~attribute_instance() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class attr_spec: public object {
    ast_type                        type;
    
public: 
    // 
    attr_spec(): object(AST_ATTR_SPEC) {
        
    }
    ~attr_spec() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class attr_name: public object {
    ast_type                        type;
    
public: 
    // 
    attr_name(): object(AST_ATTR_NAME) {
        
    }
    ~attr_name() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class block_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    block_identifier(): object(AST_BLOCK_IDENTIFIER) {
        
    }
    ~block_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class bin_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    bin_identifier(): object(AST_BIN_IDENTIFIER) {
        
    }
    ~bin_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class c_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    c_identifier(): object(AST_C_IDENTIFIER) {
        
    }
    ~c_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class cell_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    cell_identifier(): object(AST_CELL_IDENTIFIER) {
        
    }
    ~cell_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class checker_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    checker_identifier(): object(AST_CHECKER_IDENTIFIER) {
        
    }
    ~checker_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class class_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    class_identifier(): object(AST_CLASS_IDENTIFIER) {
        
    }
    ~class_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class class_variable_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    class_variable_identifier(): object(AST_CLASS_VARIABLE_IDENTIFIER) {
        
    }
    ~class_variable_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class clocking_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    clocking_identifier(): object(AST_CLOCKING_IDENTIFIER) {
        
    }
    ~clocking_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class config_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    config_identifier(): object(AST_CONFIG_IDENTIFIER) {
        
    }
    ~config_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class const_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    const_identifier(): object(AST_CONST_IDENTIFIER) {
        
    }
    ~const_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class constraint_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    constraint_identifier(): object(AST_CONSTRAINT_IDENTIFIER) {
        
    }
    ~constraint_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class covergroup_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    covergroup_identifier(): object(AST_COVERGROUP_IDENTIFIER) {
        
    }
    ~covergroup_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class cover_point_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    cover_point_identifier(): object(AST_COVER_POINT_IDENTIFIER) {
        
    }
    ~cover_point_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class cross_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    cross_identifier(): object(AST_CROSS_IDENTIFIER) {
        
    }
    ~cross_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class dynamic_array_variable_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    dynamic_array_variable_identifier(): object(AST_DYNAMIC_ARRAY_VARIABLE_IDENTIFIER) {
        
    }
    ~dynamic_array_variable_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class enum_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    enum_identifier(): object(AST_ENUM_IDENTIFIER) {
        
    }
    ~enum_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class escaped_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    escaped_identifier(): object(AST_ESCAPED_IDENTIFIER) {
        
    }
    ~escaped_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class formal_port_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    formal_port_identifier(): object(AST_FORMAL_PORT_IDENTIFIER) {
        
    }
    ~formal_port_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class function_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    function_identifier(): object(AST_FUNCTION_IDENTIFIER) {
        
    }
    ~function_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class generate_block_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    generate_block_identifier(): object(AST_GENERATE_BLOCK_IDENTIFIER) {
        
    }
    ~generate_block_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class genvar_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    genvar_identifier(): object(AST_GENVAR_IDENTIFIER) {
        
    }
    ~genvar_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class hierarchical_array_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    hierarchical_array_identifier(): object(AST_HIERARCHICAL_ARRAY_IDENTIFIER) {
        
    }
    ~hierarchical_array_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class hierarchical_block_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    hierarchical_block_identifier(): object(AST_HIERARCHICAL_BLOCK_IDENTIFIER) {
        
    }
    ~hierarchical_block_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class hierarchical_event_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    hierarchical_event_identifier(): object(AST_HIERARCHICAL_EVENT_IDENTIFIER) {
        
    }
    ~hierarchical_event_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class hierarchical_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    hierarchical_identifier(): object(AST_HIERARCHICAL_IDENTIFIER) {
        
    }
    ~hierarchical_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class hierarchical_net_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    hierarchical_net_identifier(): object(AST_HIERARCHICAL_NET_IDENTIFIER) {
        
    }
    ~hierarchical_net_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class hierarchical_parameter_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    hierarchical_parameter_identifier(): object(AST_HIERARCHICAL_PARAMETER_IDENTIFIER) {
        
    }
    ~hierarchical_parameter_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class hierarchical_property_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    hierarchical_property_identifier(): object(AST_HIERARCHICAL_PROPERTY_IDENTIFIER) {
        
    }
    ~hierarchical_property_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class hierarchical_sequence_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    hierarchical_sequence_identifier(): object(AST_HIERARCHICAL_SEQUENCE_IDENTIFIER) {
        
    }
    ~hierarchical_sequence_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class hierarchical_task_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    hierarchical_task_identifier(): object(AST_HIERARCHICAL_TASK_IDENTIFIER) {
        
    }
    ~hierarchical_task_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class hierarchical_tf_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    hierarchical_tf_identifier(): object(AST_HIERARCHICAL_TF_IDENTIFIER) {
        
    }
    ~hierarchical_tf_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class hierarchical_variable_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    hierarchical_variable_identifier(): object(AST_HIERARCHICAL_VARIABLE_IDENTIFIER) {
        
    }
    ~hierarchical_variable_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class identifier: public object {
    ast_type                        type;
    
public: 
    // 
    identifier(): object(AST_IDENTIFIER) {
        
    }
    ~identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class index_variable_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    index_variable_identifier(): object(AST_INDEX_VARIABLE_IDENTIFIER) {
        
    }
    ~index_variable_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class interface_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    interface_identifier(): object(AST_INTERFACE_IDENTIFIER) {
        
    }
    ~interface_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class interface_instance_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    interface_instance_identifier(): object(AST_INTERFACE_INSTANCE_IDENTIFIER) {
        
    }
    ~interface_instance_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class inout_port_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    inout_port_identifier(): object(AST_INOUT_PORT_IDENTIFIER) {
        
    }
    ~inout_port_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class input_port_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    input_port_identifier(): object(AST_INPUT_PORT_IDENTIFIER) {
        
    }
    ~input_port_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class instance_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    instance_identifier(): object(AST_INSTANCE_IDENTIFIER) {
        
    }
    ~instance_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class library_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    library_identifier(): object(AST_LIBRARY_IDENTIFIER) {
        
    }
    ~library_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class member_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    member_identifier(): object(AST_MEMBER_IDENTIFIER) {
        
    }
    ~member_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class method_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    method_identifier(): object(AST_METHOD_IDENTIFIER) {
        
    }
    ~method_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class modport_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    modport_identifier(): object(AST_MODPORT_IDENTIFIER) {
        
    }
    ~modport_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class module_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    module_identifier(): object(AST_MODULE_IDENTIFIER) {
        
    }
    ~module_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class net_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    net_identifier(): object(AST_NET_IDENTIFIER) {
        
    }
    ~net_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class net_type_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    net_type_identifier(): object(AST_NET_TYPE_IDENTIFIER) {
        
    }
    ~net_type_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class output_port_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    output_port_identifier(): object(AST_OUTPUT_PORT_IDENTIFIER) {
        
    }
    ~output_port_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class package_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    package_identifier(): object(AST_PACKAGE_IDENTIFIER) {
        
    }
    ~package_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class package_scope: public object {
    ast_type                        type;
    
public: 
    // 
    package_scope(): object(AST_PACKAGE_SCOPE) {
        
    }
    ~package_scope() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class parameter_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    parameter_identifier(): object(AST_PARAMETER_IDENTIFIER) {
        
    }
    ~parameter_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class port_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    port_identifier(): object(AST_PORT_IDENTIFIER) {
        
    }
    ~port_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class production_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    production_identifier(): object(AST_PRODUCTION_IDENTIFIER) {
        
    }
    ~production_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class program_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    program_identifier(): object(AST_PROGRAM_IDENTIFIER) {
        
    }
    ~program_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class property_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    property_identifier(): object(AST_PROPERTY_IDENTIFIER) {
        
    }
    ~property_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class ps_class_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    ps_class_identifier(): object(AST_PS_CLASS_IDENTIFIER) {
        
    }
    ~ps_class_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class ps_covergroup_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    ps_covergroup_identifier(): object(AST_PS_COVERGROUP_IDENTIFIER) {
        
    }
    ~ps_covergroup_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class ps_checker_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    ps_checker_identifier(): object(AST_PS_CHECKER_IDENTIFIER) {
        
    }
    ~ps_checker_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class ps_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    ps_identifier(): object(AST_PS_IDENTIFIER) {
        
    }
    ~ps_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class ps_or_hierarchical_array_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    ps_or_hierarchical_array_identifier(): object(AST_PS_OR_HIERARCHICAL_ARRAY_IDENTIFIER) {
        
    }
    ~ps_or_hierarchical_array_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class ps_or_hierarchical_net_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    ps_or_hierarchical_net_identifier(): object(AST_PS_OR_HIERARCHICAL_NET_IDENTIFIER) {
        
    }
    ~ps_or_hierarchical_net_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class ps_or_hierarchical_property_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    ps_or_hierarchical_property_identifier(): object(AST_PS_OR_HIERARCHICAL_PROPERTY_IDENTIFIER) {
        
    }
    ~ps_or_hierarchical_property_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class ps_or_hierarchical_sequence_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    ps_or_hierarchical_sequence_identifier(): object(AST_PS_OR_HIERARCHICAL_SEQUENCE_IDENTIFIER) {
        
    }
    ~ps_or_hierarchical_sequence_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class ps_or_hierarchical_tf_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    ps_or_hierarchical_tf_identifier(): object(AST_PS_OR_HIERARCHICAL_TF_IDENTIFIER) {
        
    }
    ~ps_or_hierarchical_tf_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class ps_parameter_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    ps_parameter_identifier(): object(AST_PS_PARAMETER_IDENTIFIER) {
        
    }
    ~ps_parameter_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class ps_type_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    ps_type_identifier(): object(AST_PS_TYPE_IDENTIFIER) {
        
    }
    ~ps_type_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class sequence_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    sequence_identifier(): object(AST_SEQUENCE_IDENTIFIER) {
        
    }
    ~sequence_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class signal_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    signal_identifier(): object(AST_SIGNAL_IDENTIFIER) {
        
    }
    ~signal_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class simple_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    simple_identifier(): object(AST_SIMPLE_IDENTIFIER) {
        
    }
    ~simple_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class specparam_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    specparam_identifier(): object(AST_SPECPARAM_IDENTIFIER) {
        
    }
    ~specparam_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class system_tf_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    system_tf_identifier(): object(AST_SYSTEM_TF_IDENTIFIER) {
        
    }
    ~system_tf_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class task_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    task_identifier(): object(AST_TASK_IDENTIFIER) {
        
    }
    ~task_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class tf_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    tf_identifier(): object(AST_TF_IDENTIFIER) {
        
    }
    ~tf_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class terminal_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    terminal_identifier(): object(AST_TERMINAL_IDENTIFIER) {
        
    }
    ~terminal_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class topmodule_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    topmodule_identifier(): object(AST_TOPMODULE_IDENTIFIER) {
        
    }
    ~topmodule_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class type_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    type_identifier(): object(AST_TYPE_IDENTIFIER) {
        
    }
    ~type_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class udp_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    udp_identifier(): object(AST_UDP_IDENTIFIER) {
        
    }
    ~udp_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class variable_identifier: public object {
    ast_type                        type;
    
public: 
    // 
    variable_identifier(): object(AST_VARIABLE_IDENTIFIER) {
        
    }
    ~variable_identifier() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class file_path_spec: public object {
    ast_type                        type;
    
public: 
    // 
    file_path_spec(): object(AST_FILE_PATH_SPEC) {
        
    }
    ~file_path_spec() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



}


#endif
