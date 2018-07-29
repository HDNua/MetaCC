#ifndef __HANDY_VAST_H__
#define __HANDY_VAST_H__

#include <stdio.h>
#include <string.h>



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
    AST_INTERFACE_CLASS_DECLARATION,
    AST_INTERFACE_CLASS_ITEM,
    AST_INTERFACE_CLASS_METHOD,
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
    AST_BINARY_NUMBER,
    AST_OCTAL_NUMBER,
    AST_HEX_NUMBER,
    AST_SIGN,
    AST_SIZE,
    AST_NON_ZERO_UNSIGNED_NUMBER,
    AST_REAL_NUMBER,
    AST_FIXED_POINT_NUMBER,
    AST_EXP,
    AST_UNSIGNED_NUMBER,
    AST_BINARY_VALUE,
    AST_OCTAL_VALUE,
    AST_HEX_VALUE,
    AST_DECIMAL_BASE,
    AST_BINARY_BASE,
    AST_OCTAL_BASE,
    AST_HEX_BASE,
    AST_NON_ZERO_DECIMAL_DIGIT,
    AST_DECIMAL_DIGIT,
    AST_BINARY_DIGIT,
    AST_OCTAL_DIGIT,
    AST_HEX_DIGIT,
    AST_X_DIGIT,
    AST_Z_DIGIT,
    AST_UNBASED_UNSIZED_LITERAL,
    AST_STRING_LITERAL,
    AST_ATTRIBUTE_INSTANCE,
    AST_ATTR_SPEC,
    AST_ATTR_NAME,
    AST_COMMENT,
    AST_ONE_LINE_COMMENT,
    AST_BLOCK_COMMENT,
    AST_COMMENT_TEXT,
    AST_ARRAY_IDENTIFIER,
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
    AST_COVERGROUP_VARIABLE_IDENTIFIER,
    AST_COVER_POINT_IDENTIFIER,
    AST_CROSS_IDENTIFIER,
    AST_DYNAMIC_ARRAY_VARIABLE_IDENTIFIER,
    AST_ENUM_IDENTIFIER,
    AST_ESCAPED_IDENTIFIER,
    AST_FORMAL_IDENTIFIER,
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
    AST_WHITE_SPACE,
    AST_FILE_PATH_SPEC,
} ast_type;



// 
struct ast_list_node {
    ast_type                      type;
    ast_type                      elem_type;
    void                          *elem;
    struct ast_list_node          *next;
};
// 
void ast_list_node_describe(struct ast_list_node *node);
// 
void ast_list_node_action(struct ast_list_node *node);
// 
struct ast_list {
    ast_type                      type;
    ast_type                      elem_type;
    
    struct ast_list_node          head;
    struct ast_list_node          *tail;
    int                           count;
};
// 
struct ast_list *ast_list_new(ast_type type);
// 
void ast_list_append(struct ast_list *list, void *elem, ast_type type);
// 
void ast_list_iterate(struct ast_list *list);
// 
void ast_list_traverse(struct ast_list *list);



// 
struct ast_library_text {
    ast_type                        type;
};
// 
void ast_library_text_describe(FILE *out, struct ast_library_text *this);
// 
void ast_library_text_action(FILE *out, struct ast_library_text *this);



// 
struct ast_library_description {
    ast_type                        type;
};
// 
void ast_library_description_describe(FILE *out, struct ast_library_description *this);
// 
void ast_library_description_action(FILE *out, struct ast_library_description *this);



// 
struct ast_library_declaration {
    ast_type                        type;
};
// 
void ast_library_declaration_describe(FILE *out, struct ast_library_declaration *this);
// 
void ast_library_declaration_action(FILE *out, struct ast_library_declaration *this);



// 
struct ast_include_statement {
    ast_type                        type;
};
// 
void ast_include_statement_describe(FILE *out, struct ast_include_statement *this);
// 
void ast_include_statement_action(FILE *out, struct ast_include_statement *this);



// 
struct ast_source_text {
    ast_type                        type;
};
// 
void ast_source_text_describe(FILE *out, struct ast_source_text *this);
// 
void ast_source_text_action(FILE *out, struct ast_source_text *this);



// 
struct ast_description {
    ast_type                        type;
};
// 
void ast_description_describe(FILE *out, struct ast_description *this);
// 
void ast_description_action(FILE *out, struct ast_description *this);



// 
struct ast_module_nonansi_header {
    ast_type                        type;
};
// 
void ast_module_nonansi_header_describe(FILE *out, struct ast_module_nonansi_header *this);
// 
void ast_module_nonansi_header_action(FILE *out, struct ast_module_nonansi_header *this);



// 
struct ast_module_ansi_header {
    ast_type                        type;
};
// 
void ast_module_ansi_header_describe(FILE *out, struct ast_module_ansi_header *this);
// 
void ast_module_ansi_header_action(FILE *out, struct ast_module_ansi_header *this);



// 
struct ast_module_declaration {
    ast_type                        type;
};
// 
void ast_module_declaration_describe(FILE *out, struct ast_module_declaration *this);
// 
void ast_module_declaration_action(FILE *out, struct ast_module_declaration *this);



// 
struct ast_module_keyword {
    ast_type                        type;
};
// 
void ast_module_keyword_describe(FILE *out, struct ast_module_keyword *this);
// 
void ast_module_keyword_action(FILE *out, struct ast_module_keyword *this);



// 
struct ast_interface_declaration {
    ast_type                        type;
};
// 
void ast_interface_declaration_describe(FILE *out, struct ast_interface_declaration *this);
// 
void ast_interface_declaration_action(FILE *out, struct ast_interface_declaration *this);



// 
struct ast_interface_nonansi_header {
    ast_type                        type;
};
// 
void ast_interface_nonansi_header_describe(FILE *out, struct ast_interface_nonansi_header *this);
// 
void ast_interface_nonansi_header_action(FILE *out, struct ast_interface_nonansi_header *this);



// 
struct ast_interface_ansi_header {
    ast_type                        type;
};
// 
void ast_interface_ansi_header_describe(FILE *out, struct ast_interface_ansi_header *this);
// 
void ast_interface_ansi_header_action(FILE *out, struct ast_interface_ansi_header *this);



// 
struct ast_program_declaration {
    ast_type                        type;
};
// 
void ast_program_declaration_describe(FILE *out, struct ast_program_declaration *this);
// 
void ast_program_declaration_action(FILE *out, struct ast_program_declaration *this);



// 
struct ast_program_nonansi_header {
    ast_type                        type;
};
// 
void ast_program_nonansi_header_describe(FILE *out, struct ast_program_nonansi_header *this);
// 
void ast_program_nonansi_header_action(FILE *out, struct ast_program_nonansi_header *this);



// 
struct ast_program_ansi_header {
    ast_type                        type;
};
// 
void ast_program_ansi_header_describe(FILE *out, struct ast_program_ansi_header *this);
// 
void ast_program_ansi_header_action(FILE *out, struct ast_program_ansi_header *this);



// 
struct ast_checker_declaration {
    ast_type                        type;
};
// 
void ast_checker_declaration_describe(FILE *out, struct ast_checker_declaration *this);
// 
void ast_checker_declaration_action(FILE *out, struct ast_checker_declaration *this);



// 
struct ast_class_declaration {
    ast_type                        type;
};
// 
void ast_class_declaration_describe(FILE *out, struct ast_class_declaration *this);
// 
void ast_class_declaration_action(FILE *out, struct ast_class_declaration *this);



// 
struct ast_interface_class_type {
    ast_type                        type;
};
// 
void ast_interface_class_type_describe(FILE *out, struct ast_interface_class_type *this);
// 
void ast_interface_class_type_action(FILE *out, struct ast_interface_class_type *this);



// 
struct ast_interface_class_declaration {
    ast_type                        type;
};
// 
void ast_interface_class_declaration_describe(FILE *out, struct ast_interface_class_declaration *this);
// 
void ast_interface_class_declaration_action(FILE *out, struct ast_interface_class_declaration *this);



// 
struct ast_interface_class_item {
    ast_type                        type;
};
// 
void ast_interface_class_item_describe(FILE *out, struct ast_interface_class_item *this);
// 
void ast_interface_class_item_action(FILE *out, struct ast_interface_class_item *this);



// 
struct ast_interface_class_method {
    ast_type                        type;
};
// 
void ast_interface_class_method_describe(FILE *out, struct ast_interface_class_method *this);
// 
void ast_interface_class_method_action(FILE *out, struct ast_interface_class_method *this);



// 
struct ast_package_declaration {
    ast_type                        type;
};
// 
void ast_package_declaration_describe(FILE *out, struct ast_package_declaration *this);
// 
void ast_package_declaration_action(FILE *out, struct ast_package_declaration *this);



// 
struct ast_timeunits_declaration {
    ast_type                        type;
};
// 
void ast_timeunits_declaration_describe(FILE *out, struct ast_timeunits_declaration *this);
// 
void ast_timeunits_declaration_action(FILE *out, struct ast_timeunits_declaration *this);



// 
struct ast_parameter_port_list {
    ast_type                        type;
};
// 
void ast_parameter_port_list_describe(FILE *out, struct ast_parameter_port_list *this);
// 
void ast_parameter_port_list_action(FILE *out, struct ast_parameter_port_list *this);



// 
struct ast_parameter_port_declaration {
    ast_type                        type;
};
// 
void ast_parameter_port_declaration_describe(FILE *out, struct ast_parameter_port_declaration *this);
// 
void ast_parameter_port_declaration_action(FILE *out, struct ast_parameter_port_declaration *this);



// 
struct ast_list_of_ports {
    ast_type                        type;
};
// 
void ast_list_of_ports_describe(FILE *out, struct ast_list_of_ports *this);
// 
void ast_list_of_ports_action(FILE *out, struct ast_list_of_ports *this);



// 
struct ast_list_of_port_declarations {
    ast_type                        type;
};
// 
void ast_list_of_port_declarations_describe(FILE *out, struct ast_list_of_port_declarations *this);
// 
void ast_list_of_port_declarations_action(FILE *out, struct ast_list_of_port_declarations *this);



// 
struct ast_port_declaration {
    ast_type                        type;
};
// 
void ast_port_declaration_describe(FILE *out, struct ast_port_declaration *this);
// 
void ast_port_declaration_action(FILE *out, struct ast_port_declaration *this);



// 
struct ast_port {
    ast_type                        type;
};
// 
void ast_port_describe(FILE *out, struct ast_port *this);
// 
void ast_port_action(FILE *out, struct ast_port *this);



// 
struct ast_port_expression {
    ast_type                        type;
};
// 
void ast_port_expression_describe(FILE *out, struct ast_port_expression *this);
// 
void ast_port_expression_action(FILE *out, struct ast_port_expression *this);



// 
struct ast_port_reference {
    ast_type                        type;
};
// 
void ast_port_reference_describe(FILE *out, struct ast_port_reference *this);
// 
void ast_port_reference_action(FILE *out, struct ast_port_reference *this);



// 
struct ast_port_direction {
    ast_type                        type;
};
// 
void ast_port_direction_describe(FILE *out, struct ast_port_direction *this);
// 
void ast_port_direction_action(FILE *out, struct ast_port_direction *this);



// 
struct ast_net_port_header {
    ast_type                        type;
};
// 
void ast_net_port_header_describe(FILE *out, struct ast_net_port_header *this);
// 
void ast_net_port_header_action(FILE *out, struct ast_net_port_header *this);



// 
struct ast_variable_port_header {
    ast_type                        type;
};
// 
void ast_variable_port_header_describe(FILE *out, struct ast_variable_port_header *this);
// 
void ast_variable_port_header_action(FILE *out, struct ast_variable_port_header *this);



// 
struct ast_interface_port_header {
    ast_type                        type;
};
// 
void ast_interface_port_header_describe(FILE *out, struct ast_interface_port_header *this);
// 
void ast_interface_port_header_action(FILE *out, struct ast_interface_port_header *this);



// 
struct ast_ansi_port_declaration {
    ast_type                        type;
};
// 
void ast_ansi_port_declaration_describe(FILE *out, struct ast_ansi_port_declaration *this);
// 
void ast_ansi_port_declaration_action(FILE *out, struct ast_ansi_port_declaration *this);



// 
struct ast_elaboration_system_task {
    ast_type                        type;
};
// 
void ast_elaboration_system_task_describe(FILE *out, struct ast_elaboration_system_task *this);
// 
void ast_elaboration_system_task_action(FILE *out, struct ast_elaboration_system_task *this);



// 
struct ast_finish_number {
    ast_type                        type;
};
// 
void ast_finish_number_describe(FILE *out, struct ast_finish_number *this);
// 
void ast_finish_number_action(FILE *out, struct ast_finish_number *this);



// 
struct ast_module_common_item {
    ast_type                        type;
};
// 
void ast_module_common_item_describe(FILE *out, struct ast_module_common_item *this);
// 
void ast_module_common_item_action(FILE *out, struct ast_module_common_item *this);



// 
struct ast_module_item {
    ast_type                        type;
};
// 
void ast_module_item_describe(FILE *out, struct ast_module_item *this);
// 
void ast_module_item_action(FILE *out, struct ast_module_item *this);



// 
struct ast_module_or_generate_item {
    ast_type                        type;
};
// 
void ast_module_or_generate_item_describe(FILE *out, struct ast_module_or_generate_item *this);
// 
void ast_module_or_generate_item_action(FILE *out, struct ast_module_or_generate_item *this);



// 
struct ast_module_or_generate_item_declaration {
    ast_type                        type;
};
// 
void ast_module_or_generate_item_declaration_describe(FILE *out, struct ast_module_or_generate_item_declaration *this);
// 
void ast_module_or_generate_item_declaration_action(FILE *out, struct ast_module_or_generate_item_declaration *this);



// 
struct ast_non_port_module_item {
    ast_type                        type;
};
// 
void ast_non_port_module_item_describe(FILE *out, struct ast_non_port_module_item *this);
// 
void ast_non_port_module_item_action(FILE *out, struct ast_non_port_module_item *this);



// 
struct ast_parameter_override {
    ast_type                        type;
};
// 
void ast_parameter_override_describe(FILE *out, struct ast_parameter_override *this);
// 
void ast_parameter_override_action(FILE *out, struct ast_parameter_override *this);



// 
struct ast_bind_directive {
    ast_type                        type;
};
// 
void ast_bind_directive_describe(FILE *out, struct ast_bind_directive *this);
// 
void ast_bind_directive_action(FILE *out, struct ast_bind_directive *this);



// 
struct ast_bind_target_scope {
    ast_type                        type;
};
// 
void ast_bind_target_scope_describe(FILE *out, struct ast_bind_target_scope *this);
// 
void ast_bind_target_scope_action(FILE *out, struct ast_bind_target_scope *this);



// 
struct ast_bind_target_instance {
    ast_type                        type;
};
// 
void ast_bind_target_instance_describe(FILE *out, struct ast_bind_target_instance *this);
// 
void ast_bind_target_instance_action(FILE *out, struct ast_bind_target_instance *this);



// 
struct ast_bind_target_instance_list {
    ast_type                        type;
};
// 
void ast_bind_target_instance_list_describe(FILE *out, struct ast_bind_target_instance_list *this);
// 
void ast_bind_target_instance_list_action(FILE *out, struct ast_bind_target_instance_list *this);



// 
struct ast_bind_instantiation {
    ast_type                        type;
};
// 
void ast_bind_instantiation_describe(FILE *out, struct ast_bind_instantiation *this);
// 
void ast_bind_instantiation_action(FILE *out, struct ast_bind_instantiation *this);



// 
struct ast_config_declaration {
    ast_type                        type;
};
// 
void ast_config_declaration_describe(FILE *out, struct ast_config_declaration *this);
// 
void ast_config_declaration_action(FILE *out, struct ast_config_declaration *this);



// 
struct ast_design_statement {
    ast_type                        type;
};
// 
void ast_design_statement_describe(FILE *out, struct ast_design_statement *this);
// 
void ast_design_statement_action(FILE *out, struct ast_design_statement *this);



// 
struct ast_config_rule_statement {
    ast_type                        type;
};
// 
void ast_config_rule_statement_describe(FILE *out, struct ast_config_rule_statement *this);
// 
void ast_config_rule_statement_action(FILE *out, struct ast_config_rule_statement *this);



// 
struct ast_default_clause {
    ast_type                        type;
};
// 
void ast_default_clause_describe(FILE *out, struct ast_default_clause *this);
// 
void ast_default_clause_action(FILE *out, struct ast_default_clause *this);



// 
struct ast_inst_clause {
    ast_type                        type;
};
// 
void ast_inst_clause_describe(FILE *out, struct ast_inst_clause *this);
// 
void ast_inst_clause_action(FILE *out, struct ast_inst_clause *this);



// 
struct ast_inst_name {
    ast_type                        type;
};
// 
void ast_inst_name_describe(FILE *out, struct ast_inst_name *this);
// 
void ast_inst_name_action(FILE *out, struct ast_inst_name *this);



// 
struct ast_cell_clause {
    ast_type                        type;
};
// 
void ast_cell_clause_describe(FILE *out, struct ast_cell_clause *this);
// 
void ast_cell_clause_action(FILE *out, struct ast_cell_clause *this);



// 
struct ast_liblist_clause {
    ast_type                        type;
};
// 
void ast_liblist_clause_describe(FILE *out, struct ast_liblist_clause *this);
// 
void ast_liblist_clause_action(FILE *out, struct ast_liblist_clause *this);



// 
struct ast_use_clause {
    ast_type                        type;
};
// 
void ast_use_clause_describe(FILE *out, struct ast_use_clause *this);
// 
void ast_use_clause_action(FILE *out, struct ast_use_clause *this);



// 
struct ast_interface_or_generate_item {
    ast_type                        type;
};
// 
void ast_interface_or_generate_item_describe(FILE *out, struct ast_interface_or_generate_item *this);
// 
void ast_interface_or_generate_item_action(FILE *out, struct ast_interface_or_generate_item *this);



// 
struct ast_extern_tf_declaration {
    ast_type                        type;
};
// 
void ast_extern_tf_declaration_describe(FILE *out, struct ast_extern_tf_declaration *this);
// 
void ast_extern_tf_declaration_action(FILE *out, struct ast_extern_tf_declaration *this);



// 
struct ast_interface_item {
    ast_type                        type;
};
// 
void ast_interface_item_describe(FILE *out, struct ast_interface_item *this);
// 
void ast_interface_item_action(FILE *out, struct ast_interface_item *this);



// 
struct ast_non_port_interface_item {
    ast_type                        type;
};
// 
void ast_non_port_interface_item_describe(FILE *out, struct ast_non_port_interface_item *this);
// 
void ast_non_port_interface_item_action(FILE *out, struct ast_non_port_interface_item *this);



// 
struct ast_program_item {
    ast_type                        type;
};
// 
void ast_program_item_describe(FILE *out, struct ast_program_item *this);
// 
void ast_program_item_action(FILE *out, struct ast_program_item *this);



// 
struct ast_non_port_program_item {
    ast_type                        type;
};
// 
void ast_non_port_program_item_describe(FILE *out, struct ast_non_port_program_item *this);
// 
void ast_non_port_program_item_action(FILE *out, struct ast_non_port_program_item *this);



// 
struct ast_program_generate_item {
    ast_type                        type;
};
// 
void ast_program_generate_item_describe(FILE *out, struct ast_program_generate_item *this);
// 
void ast_program_generate_item_action(FILE *out, struct ast_program_generate_item *this);



// 
struct ast_checker_port_list {
    ast_type                        type;
};
// 
void ast_checker_port_list_describe(FILE *out, struct ast_checker_port_list *this);
// 
void ast_checker_port_list_action(FILE *out, struct ast_checker_port_list *this);



// 
struct ast_checker_port_item {
    ast_type                        type;
};
// 
void ast_checker_port_item_describe(FILE *out, struct ast_checker_port_item *this);
// 
void ast_checker_port_item_action(FILE *out, struct ast_checker_port_item *this);



// 
struct ast_checker_port_direction {
    ast_type                        type;
};
// 
void ast_checker_port_direction_describe(FILE *out, struct ast_checker_port_direction *this);
// 
void ast_checker_port_direction_action(FILE *out, struct ast_checker_port_direction *this);



// 
struct ast_checker_or_generate_item {
    ast_type                        type;
};
// 
void ast_checker_or_generate_item_describe(FILE *out, struct ast_checker_or_generate_item *this);
// 
void ast_checker_or_generate_item_action(FILE *out, struct ast_checker_or_generate_item *this);



// 
struct ast_checker_or_generate_item_declaration {
    ast_type                        type;
};
// 
void ast_checker_or_generate_item_declaration_describe(FILE *out, struct ast_checker_or_generate_item_declaration *this);
// 
void ast_checker_or_generate_item_declaration_action(FILE *out, struct ast_checker_or_generate_item_declaration *this);



// 
struct ast_checker_generate_item {
    ast_type                        type;
};
// 
void ast_checker_generate_item_describe(FILE *out, struct ast_checker_generate_item *this);
// 
void ast_checker_generate_item_action(FILE *out, struct ast_checker_generate_item *this);



// 
struct ast_class_item {
    ast_type                        type;
};
// 
void ast_class_item_describe(FILE *out, struct ast_class_item *this);
// 
void ast_class_item_action(FILE *out, struct ast_class_item *this);



// 
struct ast_class_property {
    ast_type                        type;
};
// 
void ast_class_property_describe(FILE *out, struct ast_class_property *this);
// 
void ast_class_property_action(FILE *out, struct ast_class_property *this);



// 
struct ast_class_method {
    ast_type                        type;
};
// 
void ast_class_method_describe(FILE *out, struct ast_class_method *this);
// 
void ast_class_method_action(FILE *out, struct ast_class_method *this);



// 
struct ast_class_constructor_prototype {
    ast_type                        type;
};
// 
void ast_class_constructor_prototype_describe(FILE *out, struct ast_class_constructor_prototype *this);
// 
void ast_class_constructor_prototype_action(FILE *out, struct ast_class_constructor_prototype *this);



// 
struct ast_class_constraint {
    ast_type                        type;
};
// 
void ast_class_constraint_describe(FILE *out, struct ast_class_constraint *this);
// 
void ast_class_constraint_action(FILE *out, struct ast_class_constraint *this);



// 
struct ast_class_item_qualifier {
    ast_type                        type;
};
// 
void ast_class_item_qualifier_describe(FILE *out, struct ast_class_item_qualifier *this);
// 
void ast_class_item_qualifier_action(FILE *out, struct ast_class_item_qualifier *this);



// 
struct ast_property_qualifier {
    ast_type                        type;
};
// 
void ast_property_qualifier_describe(FILE *out, struct ast_property_qualifier *this);
// 
void ast_property_qualifier_action(FILE *out, struct ast_property_qualifier *this);



// 
struct ast_random_qualifier {
    ast_type                        type;
};
// 
void ast_random_qualifier_describe(FILE *out, struct ast_random_qualifier *this);
// 
void ast_random_qualifier_action(FILE *out, struct ast_random_qualifier *this);



// 
struct ast_method_qualifier {
    ast_type                        type;
};
// 
void ast_method_qualifier_describe(FILE *out, struct ast_method_qualifier *this);
// 
void ast_method_qualifier_action(FILE *out, struct ast_method_qualifier *this);



// 
struct ast_method_prototype {
    ast_type                        type;
};
// 
void ast_method_prototype_describe(FILE *out, struct ast_method_prototype *this);
// 
void ast_method_prototype_action(FILE *out, struct ast_method_prototype *this);



// 
struct ast_class_constructor_declaration {
    ast_type                        type;
};
// 
void ast_class_constructor_declaration_describe(FILE *out, struct ast_class_constructor_declaration *this);
// 
void ast_class_constructor_declaration_action(FILE *out, struct ast_class_constructor_declaration *this);



// 
struct ast_constraint_declaration {
    ast_type                        type;
};
// 
void ast_constraint_declaration_describe(FILE *out, struct ast_constraint_declaration *this);
// 
void ast_constraint_declaration_action(FILE *out, struct ast_constraint_declaration *this);



// 
struct ast_constraint_block {
    ast_type                        type;
};
// 
void ast_constraint_block_describe(FILE *out, struct ast_constraint_block *this);
// 
void ast_constraint_block_action(FILE *out, struct ast_constraint_block *this);



// 
struct ast_constraint_block_item {
    ast_type                        type;
};
// 
void ast_constraint_block_item_describe(FILE *out, struct ast_constraint_block_item *this);
// 
void ast_constraint_block_item_action(FILE *out, struct ast_constraint_block_item *this);



// 
struct ast_solve_before_list {
    ast_type                        type;
};
// 
void ast_solve_before_list_describe(FILE *out, struct ast_solve_before_list *this);
// 
void ast_solve_before_list_action(FILE *out, struct ast_solve_before_list *this);



// 
struct ast_constraint_primary {
    ast_type                        type;
};
// 
void ast_constraint_primary_describe(FILE *out, struct ast_constraint_primary *this);
// 
void ast_constraint_primary_action(FILE *out, struct ast_constraint_primary *this);



// 
struct ast_constraint_expression {
    ast_type                        type;
};
// 
void ast_constraint_expression_describe(FILE *out, struct ast_constraint_expression *this);
// 
void ast_constraint_expression_action(FILE *out, struct ast_constraint_expression *this);



// 
struct ast_uniqueness_constraint {
    ast_type                        type;
};
// 
void ast_uniqueness_constraint_describe(FILE *out, struct ast_uniqueness_constraint *this);
// 
void ast_uniqueness_constraint_action(FILE *out, struct ast_uniqueness_constraint *this);



// 
struct ast_constraint_set {
    ast_type                        type;
};
// 
void ast_constraint_set_describe(FILE *out, struct ast_constraint_set *this);
// 
void ast_constraint_set_action(FILE *out, struct ast_constraint_set *this);



// 
struct ast_dist_list {
    ast_type                        type;
};
// 
void ast_dist_list_describe(FILE *out, struct ast_dist_list *this);
// 
void ast_dist_list_action(FILE *out, struct ast_dist_list *this);



// 
struct ast_dist_item {
    ast_type                        type;
};
// 
void ast_dist_item_describe(FILE *out, struct ast_dist_item *this);
// 
void ast_dist_item_action(FILE *out, struct ast_dist_item *this);



// 
struct ast_dist_weight {
    ast_type                        type;
};
// 
void ast_dist_weight_describe(FILE *out, struct ast_dist_weight *this);
// 
void ast_dist_weight_action(FILE *out, struct ast_dist_weight *this);



// 
struct ast_constraint_prototype {
    ast_type                        type;
};
// 
void ast_constraint_prototype_describe(FILE *out, struct ast_constraint_prototype *this);
// 
void ast_constraint_prototype_action(FILE *out, struct ast_constraint_prototype *this);



// 
struct ast_constraint_prototype_qualifier {
    ast_type                        type;
};
// 
void ast_constraint_prototype_qualifier_describe(FILE *out, struct ast_constraint_prototype_qualifier *this);
// 
void ast_constraint_prototype_qualifier_action(FILE *out, struct ast_constraint_prototype_qualifier *this);



// 
struct ast_extern_constraint_declaration {
    ast_type                        type;
};
// 
void ast_extern_constraint_declaration_describe(FILE *out, struct ast_extern_constraint_declaration *this);
// 
void ast_extern_constraint_declaration_action(FILE *out, struct ast_extern_constraint_declaration *this);



// 
struct ast_identifier_list {
    ast_type                        type;
};
// 
void ast_identifier_list_describe(FILE *out, struct ast_identifier_list *this);
// 
void ast_identifier_list_action(FILE *out, struct ast_identifier_list *this);



// 
struct ast_package_item {
    ast_type                        type;
};
// 
void ast_package_item_describe(FILE *out, struct ast_package_item *this);
// 
void ast_package_item_action(FILE *out, struct ast_package_item *this);



// 
struct ast_package_or_generate_item_declaration {
    ast_type                        type;
};
// 
void ast_package_or_generate_item_declaration_describe(FILE *out, struct ast_package_or_generate_item_declaration *this);
// 
void ast_package_or_generate_item_declaration_action(FILE *out, struct ast_package_or_generate_item_declaration *this);



// 
struct ast_anonymous_program {
    ast_type                        type;
};
// 
void ast_anonymous_program_describe(FILE *out, struct ast_anonymous_program *this);
// 
void ast_anonymous_program_action(FILE *out, struct ast_anonymous_program *this);



// 
struct ast_anonymous_program_item {
    ast_type                        type;
};
// 
void ast_anonymous_program_item_describe(FILE *out, struct ast_anonymous_program_item *this);
// 
void ast_anonymous_program_item_action(FILE *out, struct ast_anonymous_program_item *this);



// 
struct ast_local_parameter_declaration {
    ast_type                        type;
};
// 
void ast_local_parameter_declaration_describe(FILE *out, struct ast_local_parameter_declaration *this);
// 
void ast_local_parameter_declaration_action(FILE *out, struct ast_local_parameter_declaration *this);



// 
struct ast_parameter_declaration {
    ast_type                        type;
};
// 
void ast_parameter_declaration_describe(FILE *out, struct ast_parameter_declaration *this);
// 
void ast_parameter_declaration_action(FILE *out, struct ast_parameter_declaration *this);



// 
struct ast_specparam_declaration {
    ast_type                        type;
};
// 
void ast_specparam_declaration_describe(FILE *out, struct ast_specparam_declaration *this);
// 
void ast_specparam_declaration_action(FILE *out, struct ast_specparam_declaration *this);



// 
struct ast_inout_declaration {
    ast_type                        type;
};
// 
void ast_inout_declaration_describe(FILE *out, struct ast_inout_declaration *this);
// 
void ast_inout_declaration_action(FILE *out, struct ast_inout_declaration *this);



// 
struct ast_input_declaration {
    ast_type                        type;
};
// 
void ast_input_declaration_describe(FILE *out, struct ast_input_declaration *this);
// 
void ast_input_declaration_action(FILE *out, struct ast_input_declaration *this);



// 
struct ast_output_declaration {
    ast_type                        type;
};
// 
void ast_output_declaration_describe(FILE *out, struct ast_output_declaration *this);
// 
void ast_output_declaration_action(FILE *out, struct ast_output_declaration *this);



// 
struct ast_interface_port_declaration {
    ast_type                        type;
};
// 
void ast_interface_port_declaration_describe(FILE *out, struct ast_interface_port_declaration *this);
// 
void ast_interface_port_declaration_action(FILE *out, struct ast_interface_port_declaration *this);



// 
struct ast_ref_declaration {
    ast_type                        type;
};
// 
void ast_ref_declaration_describe(FILE *out, struct ast_ref_declaration *this);
// 
void ast_ref_declaration_action(FILE *out, struct ast_ref_declaration *this);



// 
struct ast_data_declaration {
    ast_type                        type;
};
// 
void ast_data_declaration_describe(FILE *out, struct ast_data_declaration *this);
// 
void ast_data_declaration_action(FILE *out, struct ast_data_declaration *this);



// 
struct ast_package_import_declaration {
    ast_type                        type;
};
// 
void ast_package_import_declaration_describe(FILE *out, struct ast_package_import_declaration *this);
// 
void ast_package_import_declaration_action(FILE *out, struct ast_package_import_declaration *this);



// 
struct ast_package_import_item {
    ast_type                        type;
};
// 
void ast_package_import_item_describe(FILE *out, struct ast_package_import_item *this);
// 
void ast_package_import_item_action(FILE *out, struct ast_package_import_item *this);



// 
struct ast_package_export_declaration {
    ast_type                        type;
};
// 
void ast_package_export_declaration_describe(FILE *out, struct ast_package_export_declaration *this);
// 
void ast_package_export_declaration_action(FILE *out, struct ast_package_export_declaration *this);



// 
struct ast_genvar_declaration {
    ast_type                        type;
};
// 
void ast_genvar_declaration_describe(FILE *out, struct ast_genvar_declaration *this);
// 
void ast_genvar_declaration_action(FILE *out, struct ast_genvar_declaration *this);



// 
struct ast_net_declaration {
    ast_type                        type;
};
// 
void ast_net_declaration_describe(FILE *out, struct ast_net_declaration *this);
// 
void ast_net_declaration_action(FILE *out, struct ast_net_declaration *this);



// 
struct ast_type_declaration {
    ast_type                        type;
};
// 
void ast_type_declaration_describe(FILE *out, struct ast_type_declaration *this);
// 
void ast_type_declaration_action(FILE *out, struct ast_type_declaration *this);



// 
struct ast_net_type_declaration {
    ast_type                        type;
};
// 
void ast_net_type_declaration_describe(FILE *out, struct ast_net_type_declaration *this);
// 
void ast_net_type_declaration_action(FILE *out, struct ast_net_type_declaration *this);



// 
struct ast_lifetime {
    ast_type                        type;
};
// 
void ast_lifetime_describe(FILE *out, struct ast_lifetime *this);
// 
void ast_lifetime_action(FILE *out, struct ast_lifetime *this);



// 
struct ast_casting_type {
    ast_type                        type;
};
// 
void ast_casting_type_describe(FILE *out, struct ast_casting_type *this);
// 
void ast_casting_type_action(FILE *out, struct ast_casting_type *this);



// 
struct ast_data_type {
    ast_type                        type;
};
// 
void ast_data_type_describe(FILE *out, struct ast_data_type *this);
// 
void ast_data_type_action(FILE *out, struct ast_data_type *this);



// 
struct ast_data_type_or_implicit {
    ast_type                        type;
};
// 
void ast_data_type_or_implicit_describe(FILE *out, struct ast_data_type_or_implicit *this);
// 
void ast_data_type_or_implicit_action(FILE *out, struct ast_data_type_or_implicit *this);



// 
struct ast_implicit_data_type {
    ast_type                        type;
};
// 
void ast_implicit_data_type_describe(FILE *out, struct ast_implicit_data_type *this);
// 
void ast_implicit_data_type_action(FILE *out, struct ast_implicit_data_type *this);



// 
struct ast_enum_base_type {
    ast_type                        type;
};
// 
void ast_enum_base_type_describe(FILE *out, struct ast_enum_base_type *this);
// 
void ast_enum_base_type_action(FILE *out, struct ast_enum_base_type *this);



// 
struct ast_enum_name_declaration {
    ast_type                        type;
};
// 
void ast_enum_name_declaration_describe(FILE *out, struct ast_enum_name_declaration *this);
// 
void ast_enum_name_declaration_action(FILE *out, struct ast_enum_name_declaration *this);



// 
struct ast_class_scope {
    ast_type                        type;
};
// 
void ast_class_scope_describe(FILE *out, struct ast_class_scope *this);
// 
void ast_class_scope_action(FILE *out, struct ast_class_scope *this);



// 
struct ast_class_type {
    ast_type                        type;
};
// 
void ast_class_type_describe(FILE *out, struct ast_class_type *this);
// 
void ast_class_type_action(FILE *out, struct ast_class_type *this);



// 
struct ast_integer_type {
    ast_type                        type;
};
// 
void ast_integer_type_describe(FILE *out, struct ast_integer_type *this);
// 
void ast_integer_type_action(FILE *out, struct ast_integer_type *this);



// 
struct ast_integer_atom_type {
    ast_type                        type;
};
// 
void ast_integer_atom_type_describe(FILE *out, struct ast_integer_atom_type *this);
// 
void ast_integer_atom_type_action(FILE *out, struct ast_integer_atom_type *this);



// 
struct ast_integer_vector_type {
    ast_type                        type;
};
// 
void ast_integer_vector_type_describe(FILE *out, struct ast_integer_vector_type *this);
// 
void ast_integer_vector_type_action(FILE *out, struct ast_integer_vector_type *this);



// 
struct ast_non_integer_type {
    ast_type                        type;
};
// 
void ast_non_integer_type_describe(FILE *out, struct ast_non_integer_type *this);
// 
void ast_non_integer_type_action(FILE *out, struct ast_non_integer_type *this);



// 
struct ast_net_type {
    ast_type                        type;
};
// 
void ast_net_type_describe(FILE *out, struct ast_net_type *this);
// 
void ast_net_type_action(FILE *out, struct ast_net_type *this);



// 
struct ast_net_port_type {
    ast_type                        type;
};
// 
void ast_net_port_type_describe(FILE *out, struct ast_net_port_type *this);
// 
void ast_net_port_type_action(FILE *out, struct ast_net_port_type *this);



// 
struct ast_variable_port_type {
    ast_type                        type;
};
// 
void ast_variable_port_type_describe(FILE *out, struct ast_variable_port_type *this);
// 
void ast_variable_port_type_action(FILE *out, struct ast_variable_port_type *this);



// 
struct ast_var_data_type {
    ast_type                        type;
};
// 
void ast_var_data_type_describe(FILE *out, struct ast_var_data_type *this);
// 
void ast_var_data_type_action(FILE *out, struct ast_var_data_type *this);



// 
struct ast_signing {
    ast_type                        type;
};
// 
void ast_signing_describe(FILE *out, struct ast_signing *this);
// 
void ast_signing_action(FILE *out, struct ast_signing *this);



// 
struct ast_simple_type {
    ast_type                        type;
};
// 
void ast_simple_type_describe(FILE *out, struct ast_simple_type *this);
// 
void ast_simple_type_action(FILE *out, struct ast_simple_type *this);



// 
struct ast_struct_union_member {
    ast_type                        type;
};
// 
void ast_struct_union_member_describe(FILE *out, struct ast_struct_union_member *this);
// 
void ast_struct_union_member_action(FILE *out, struct ast_struct_union_member *this);



// 
struct ast_data_type_or_void {
    ast_type                        type;
};
// 
void ast_data_type_or_void_describe(FILE *out, struct ast_data_type_or_void *this);
// 
void ast_data_type_or_void_action(FILE *out, struct ast_data_type_or_void *this);



// 
struct ast_struct_union {
    ast_type                        type;
};
// 
void ast_struct_union_describe(FILE *out, struct ast_struct_union *this);
// 
void ast_struct_union_action(FILE *out, struct ast_struct_union *this);



// 
struct ast_type_reference {
    ast_type                        type;
};
// 
void ast_type_reference_describe(FILE *out, struct ast_type_reference *this);
// 
void ast_type_reference_action(FILE *out, struct ast_type_reference *this);



// 
struct ast_drive_strength {
    ast_type                        type;
};
// 
void ast_drive_strength_describe(FILE *out, struct ast_drive_strength *this);
// 
void ast_drive_strength_action(FILE *out, struct ast_drive_strength *this);



// 
struct ast_strength0 {
    ast_type                        type;
};
// 
void ast_strength0_describe(FILE *out, struct ast_strength0 *this);
// 
void ast_strength0_action(FILE *out, struct ast_strength0 *this);



// 
struct ast_strength1 {
    ast_type                        type;
};
// 
void ast_strength1_describe(FILE *out, struct ast_strength1 *this);
// 
void ast_strength1_action(FILE *out, struct ast_strength1 *this);



// 
struct ast_charge_strength {
    ast_type                        type;
};
// 
void ast_charge_strength_describe(FILE *out, struct ast_charge_strength *this);
// 
void ast_charge_strength_action(FILE *out, struct ast_charge_strength *this);



// 
struct ast_delay3 {
    ast_type                        type;
};
// 
void ast_delay3_describe(FILE *out, struct ast_delay3 *this);
// 
void ast_delay3_action(FILE *out, struct ast_delay3 *this);



// 
struct ast_delay2 {
    ast_type                        type;
};
// 
void ast_delay2_describe(FILE *out, struct ast_delay2 *this);
// 
void ast_delay2_action(FILE *out, struct ast_delay2 *this);



// 
struct ast_delay_value {
    ast_type                        type;
};
// 
void ast_delay_value_describe(FILE *out, struct ast_delay_value *this);
// 
void ast_delay_value_action(FILE *out, struct ast_delay_value *this);



// 
struct ast_list_of_defparam_assignments {
    ast_type                        type;
};
// 
void ast_list_of_defparam_assignments_describe(FILE *out, struct ast_list_of_defparam_assignments *this);
// 
void ast_list_of_defparam_assignments_action(FILE *out, struct ast_list_of_defparam_assignments *this);



// 
struct ast_list_of_genvar_identifiers {
    ast_type                        type;
};
// 
void ast_list_of_genvar_identifiers_describe(FILE *out, struct ast_list_of_genvar_identifiers *this);
// 
void ast_list_of_genvar_identifiers_action(FILE *out, struct ast_list_of_genvar_identifiers *this);



// 
struct ast_list_of_interface_identifiers {
    ast_type                        type;
};
// 
void ast_list_of_interface_identifiers_describe(FILE *out, struct ast_list_of_interface_identifiers *this);
// 
void ast_list_of_interface_identifiers_action(FILE *out, struct ast_list_of_interface_identifiers *this);



// 
struct ast_list_of_net_decl_assignments {
    ast_type                        type;
};
// 
void ast_list_of_net_decl_assignments_describe(FILE *out, struct ast_list_of_net_decl_assignments *this);
// 
void ast_list_of_net_decl_assignments_action(FILE *out, struct ast_list_of_net_decl_assignments *this);



// 
struct ast_list_of_param_assignments {
    ast_type                        type;
};
// 
void ast_list_of_param_assignments_describe(FILE *out, struct ast_list_of_param_assignments *this);
// 
void ast_list_of_param_assignments_action(FILE *out, struct ast_list_of_param_assignments *this);



// 
struct ast_list_of_port_identifiers {
    ast_type                        type;
};
// 
void ast_list_of_port_identifiers_describe(FILE *out, struct ast_list_of_port_identifiers *this);
// 
void ast_list_of_port_identifiers_action(FILE *out, struct ast_list_of_port_identifiers *this);



// 
struct ast_list_of_udp_port_identifiers {
    ast_type                        type;
};
// 
void ast_list_of_udp_port_identifiers_describe(FILE *out, struct ast_list_of_udp_port_identifiers *this);
// 
void ast_list_of_udp_port_identifiers_action(FILE *out, struct ast_list_of_udp_port_identifiers *this);



// 
struct ast_list_of_specparam_assignments {
    ast_type                        type;
};
// 
void ast_list_of_specparam_assignments_describe(FILE *out, struct ast_list_of_specparam_assignments *this);
// 
void ast_list_of_specparam_assignments_action(FILE *out, struct ast_list_of_specparam_assignments *this);



// 
struct ast_list_of_tf_variable_identifiers {
    ast_type                        type;
};
// 
void ast_list_of_tf_variable_identifiers_describe(FILE *out, struct ast_list_of_tf_variable_identifiers *this);
// 
void ast_list_of_tf_variable_identifiers_action(FILE *out, struct ast_list_of_tf_variable_identifiers *this);



// 
struct ast_list_of_type_assignments {
    ast_type                        type;
};
// 
void ast_list_of_type_assignments_describe(FILE *out, struct ast_list_of_type_assignments *this);
// 
void ast_list_of_type_assignments_action(FILE *out, struct ast_list_of_type_assignments *this);



// 
struct ast_list_of_variable_decl_assignments {
    ast_type                        type;
};
// 
void ast_list_of_variable_decl_assignments_describe(FILE *out, struct ast_list_of_variable_decl_assignments *this);
// 
void ast_list_of_variable_decl_assignments_action(FILE *out, struct ast_list_of_variable_decl_assignments *this);



// 
struct ast_list_of_variable_identifiers {
    ast_type                        type;
};
// 
void ast_list_of_variable_identifiers_describe(FILE *out, struct ast_list_of_variable_identifiers *this);
// 
void ast_list_of_variable_identifiers_action(FILE *out, struct ast_list_of_variable_identifiers *this);



// 
struct ast_list_of_variable_port_identifiers {
    ast_type                        type;
};
// 
void ast_list_of_variable_port_identifiers_describe(FILE *out, struct ast_list_of_variable_port_identifiers *this);
// 
void ast_list_of_variable_port_identifiers_action(FILE *out, struct ast_list_of_variable_port_identifiers *this);



// 
struct ast_defparam_assignment {
    ast_type                        type;
};
// 
void ast_defparam_assignment_describe(FILE *out, struct ast_defparam_assignment *this);
// 
void ast_defparam_assignment_action(FILE *out, struct ast_defparam_assignment *this);



// 
struct ast_net_decl_assignment {
    ast_type                        type;
};
// 
void ast_net_decl_assignment_describe(FILE *out, struct ast_net_decl_assignment *this);
// 
void ast_net_decl_assignment_action(FILE *out, struct ast_net_decl_assignment *this);



// 
struct ast_param_assignment {
    ast_type                        type;
};
// 
void ast_param_assignment_describe(FILE *out, struct ast_param_assignment *this);
// 
void ast_param_assignment_action(FILE *out, struct ast_param_assignment *this);



// 
struct ast_specparam_assignment {
    ast_type                        type;
};
// 
void ast_specparam_assignment_describe(FILE *out, struct ast_specparam_assignment *this);
// 
void ast_specparam_assignment_action(FILE *out, struct ast_specparam_assignment *this);



// 
struct ast_type_assignment {
    ast_type                        type;
};
// 
void ast_type_assignment_describe(FILE *out, struct ast_type_assignment *this);
// 
void ast_type_assignment_action(FILE *out, struct ast_type_assignment *this);



// 
struct ast_pulse_control_specparam {
    ast_type                        type;
};
// 
void ast_pulse_control_specparam_describe(FILE *out, struct ast_pulse_control_specparam *this);
// 
void ast_pulse_control_specparam_action(FILE *out, struct ast_pulse_control_specparam *this);



// 
struct ast_error_limit_value {
    ast_type                        type;
};
// 
void ast_error_limit_value_describe(FILE *out, struct ast_error_limit_value *this);
// 
void ast_error_limit_value_action(FILE *out, struct ast_error_limit_value *this);



// 
struct ast_reject_limit_value {
    ast_type                        type;
};
// 
void ast_reject_limit_value_describe(FILE *out, struct ast_reject_limit_value *this);
// 
void ast_reject_limit_value_action(FILE *out, struct ast_reject_limit_value *this);



// 
struct ast_limit_value {
    ast_type                        type;
};
// 
void ast_limit_value_describe(FILE *out, struct ast_limit_value *this);
// 
void ast_limit_value_action(FILE *out, struct ast_limit_value *this);



// 
struct ast_variable_decl_assignment {
    ast_type                        type;
};
// 
void ast_variable_decl_assignment_describe(FILE *out, struct ast_variable_decl_assignment *this);
// 
void ast_variable_decl_assignment_action(FILE *out, struct ast_variable_decl_assignment *this);



// 
struct ast_class_new {
    ast_type                        type;
};
// 
void ast_class_new_describe(FILE *out, struct ast_class_new *this);
// 
void ast_class_new_action(FILE *out, struct ast_class_new *this);



// 
struct ast_dynamic_array_new {
    ast_type                        type;
};
// 
void ast_dynamic_array_new_describe(FILE *out, struct ast_dynamic_array_new *this);
// 
void ast_dynamic_array_new_action(FILE *out, struct ast_dynamic_array_new *this);



// 
struct ast_unpacked_dimension {
    ast_type                        type;
};
// 
void ast_unpacked_dimension_describe(FILE *out, struct ast_unpacked_dimension *this);
// 
void ast_unpacked_dimension_action(FILE *out, struct ast_unpacked_dimension *this);



// 
struct ast_packed_dimension {
    ast_type                        type;
};
// 
void ast_packed_dimension_describe(FILE *out, struct ast_packed_dimension *this);
// 
void ast_packed_dimension_action(FILE *out, struct ast_packed_dimension *this);



// 
struct ast_associative_dimension {
    ast_type                        type;
};
// 
void ast_associative_dimension_describe(FILE *out, struct ast_associative_dimension *this);
// 
void ast_associative_dimension_action(FILE *out, struct ast_associative_dimension *this);



// 
struct ast_variable_dimension {
    ast_type                        type;
};
// 
void ast_variable_dimension_describe(FILE *out, struct ast_variable_dimension *this);
// 
void ast_variable_dimension_action(FILE *out, struct ast_variable_dimension *this);



// 
struct ast_queue_dimension {
    ast_type                        type;
};
// 
void ast_queue_dimension_describe(FILE *out, struct ast_queue_dimension *this);
// 
void ast_queue_dimension_action(FILE *out, struct ast_queue_dimension *this);



// 
struct ast_unsized_dimension {
    ast_type                        type;
};
// 
void ast_unsized_dimension_describe(FILE *out, struct ast_unsized_dimension *this);
// 
void ast_unsized_dimension_action(FILE *out, struct ast_unsized_dimension *this);



// 
struct ast_function_data_type_or_implicit {
    ast_type                        type;
};
// 
void ast_function_data_type_or_implicit_describe(FILE *out, struct ast_function_data_type_or_implicit *this);
// 
void ast_function_data_type_or_implicit_action(FILE *out, struct ast_function_data_type_or_implicit *this);



// 
struct ast_function_declaration {
    ast_type                        type;
};
// 
void ast_function_declaration_describe(FILE *out, struct ast_function_declaration *this);
// 
void ast_function_declaration_action(FILE *out, struct ast_function_declaration *this);



// 
struct ast_function_body_declaration {
    ast_type                        type;
};
// 
void ast_function_body_declaration_describe(FILE *out, struct ast_function_body_declaration *this);
// 
void ast_function_body_declaration_action(FILE *out, struct ast_function_body_declaration *this);



// 
struct ast_function_prototype {
    ast_type                        type;
};
// 
void ast_function_prototype_describe(FILE *out, struct ast_function_prototype *this);
// 
void ast_function_prototype_action(FILE *out, struct ast_function_prototype *this);



// 
struct ast_dpi_import_export {
    ast_type                        type;
};
// 
void ast_dpi_import_export_describe(FILE *out, struct ast_dpi_import_export *this);
// 
void ast_dpi_import_export_action(FILE *out, struct ast_dpi_import_export *this);



// 
struct ast_dpi_spec_string {
    ast_type                        type;
};
// 
void ast_dpi_spec_string_describe(FILE *out, struct ast_dpi_spec_string *this);
// 
void ast_dpi_spec_string_action(FILE *out, struct ast_dpi_spec_string *this);



// 
struct ast_dpi_function_import_property {
    ast_type                        type;
};
// 
void ast_dpi_function_import_property_describe(FILE *out, struct ast_dpi_function_import_property *this);
// 
void ast_dpi_function_import_property_action(FILE *out, struct ast_dpi_function_import_property *this);



// 
struct ast_dpi_task_import_property {
    ast_type                        type;
};
// 
void ast_dpi_task_import_property_describe(FILE *out, struct ast_dpi_task_import_property *this);
// 
void ast_dpi_task_import_property_action(FILE *out, struct ast_dpi_task_import_property *this);



// 
struct ast_dpi_function_proto {
    ast_type                        type;
};
// 
void ast_dpi_function_proto_describe(FILE *out, struct ast_dpi_function_proto *this);
// 
void ast_dpi_function_proto_action(FILE *out, struct ast_dpi_function_proto *this);



// 
struct ast_dpi_task_proto {
    ast_type                        type;
};
// 
void ast_dpi_task_proto_describe(FILE *out, struct ast_dpi_task_proto *this);
// 
void ast_dpi_task_proto_action(FILE *out, struct ast_dpi_task_proto *this);



// 
struct ast_task_declaration {
    ast_type                        type;
};
// 
void ast_task_declaration_describe(FILE *out, struct ast_task_declaration *this);
// 
void ast_task_declaration_action(FILE *out, struct ast_task_declaration *this);



// 
struct ast_task_body_declaration {
    ast_type                        type;
};
// 
void ast_task_body_declaration_describe(FILE *out, struct ast_task_body_declaration *this);
// 
void ast_task_body_declaration_action(FILE *out, struct ast_task_body_declaration *this);



// 
struct ast_tf_item_declaration {
    ast_type                        type;
};
// 
void ast_tf_item_declaration_describe(FILE *out, struct ast_tf_item_declaration *this);
// 
void ast_tf_item_declaration_action(FILE *out, struct ast_tf_item_declaration *this);



// 
struct ast_tf_port_list {
    ast_type                        type;
};
// 
void ast_tf_port_list_describe(FILE *out, struct ast_tf_port_list *this);
// 
void ast_tf_port_list_action(FILE *out, struct ast_tf_port_list *this);



// 
struct ast_tf_port_item {
    ast_type                        type;
};
// 
void ast_tf_port_item_describe(FILE *out, struct ast_tf_port_item *this);
// 
void ast_tf_port_item_action(FILE *out, struct ast_tf_port_item *this);



// 
struct ast_tf_port_direction {
    ast_type                        type;
};
// 
void ast_tf_port_direction_describe(FILE *out, struct ast_tf_port_direction *this);
// 
void ast_tf_port_direction_action(FILE *out, struct ast_tf_port_direction *this);



// 
struct ast_tf_port_declaration {
    ast_type                        type;
};
// 
void ast_tf_port_declaration_describe(FILE *out, struct ast_tf_port_declaration *this);
// 
void ast_tf_port_declaration_action(FILE *out, struct ast_tf_port_declaration *this);



// 
struct ast_task_prototype {
    ast_type                        type;
};
// 
void ast_task_prototype_describe(FILE *out, struct ast_task_prototype *this);
// 
void ast_task_prototype_action(FILE *out, struct ast_task_prototype *this);



// 
struct ast_block_item_declaration {
    ast_type                        type;
};
// 
void ast_block_item_declaration_describe(FILE *out, struct ast_block_item_declaration *this);
// 
void ast_block_item_declaration_action(FILE *out, struct ast_block_item_declaration *this);



// 
struct ast_overload_declaration {
    ast_type                        type;
};
// 
void ast_overload_declaration_describe(FILE *out, struct ast_overload_declaration *this);
// 
void ast_overload_declaration_action(FILE *out, struct ast_overload_declaration *this);



// 
struct ast_overload_operator {
    ast_type                        type;
};
// 
void ast_overload_operator_describe(FILE *out, struct ast_overload_operator *this);
// 
void ast_overload_operator_action(FILE *out, struct ast_overload_operator *this);



// 
struct ast_overload_proto_formals {
    ast_type                        type;
};
// 
void ast_overload_proto_formals_describe(FILE *out, struct ast_overload_proto_formals *this);
// 
void ast_overload_proto_formals_action(FILE *out, struct ast_overload_proto_formals *this);



// 
struct ast_modport_declaration {
    ast_type                        type;
};
// 
void ast_modport_declaration_describe(FILE *out, struct ast_modport_declaration *this);
// 
void ast_modport_declaration_action(FILE *out, struct ast_modport_declaration *this);



// 
struct ast_modport_item {
    ast_type                        type;
};
// 
void ast_modport_item_describe(FILE *out, struct ast_modport_item *this);
// 
void ast_modport_item_action(FILE *out, struct ast_modport_item *this);



// 
struct ast_modport_ports_declaration {
    ast_type                        type;
};
// 
void ast_modport_ports_declaration_describe(FILE *out, struct ast_modport_ports_declaration *this);
// 
void ast_modport_ports_declaration_action(FILE *out, struct ast_modport_ports_declaration *this);



// 
struct ast_modport_clocking_declaration {
    ast_type                        type;
};
// 
void ast_modport_clocking_declaration_describe(FILE *out, struct ast_modport_clocking_declaration *this);
// 
void ast_modport_clocking_declaration_action(FILE *out, struct ast_modport_clocking_declaration *this);



// 
struct ast_modport_simple_ports_declaration {
    ast_type                        type;
};
// 
void ast_modport_simple_ports_declaration_describe(FILE *out, struct ast_modport_simple_ports_declaration *this);
// 
void ast_modport_simple_ports_declaration_action(FILE *out, struct ast_modport_simple_ports_declaration *this);



// 
struct ast_modport_simple_port {
    ast_type                        type;
};
// 
void ast_modport_simple_port_describe(FILE *out, struct ast_modport_simple_port *this);
// 
void ast_modport_simple_port_action(FILE *out, struct ast_modport_simple_port *this);



// 
struct ast_modport_tf_ports_declaration {
    ast_type                        type;
};
// 
void ast_modport_tf_ports_declaration_describe(FILE *out, struct ast_modport_tf_ports_declaration *this);
// 
void ast_modport_tf_ports_declaration_action(FILE *out, struct ast_modport_tf_ports_declaration *this);



// 
struct ast_modport_tf_port {
    ast_type                        type;
};
// 
void ast_modport_tf_port_describe(FILE *out, struct ast_modport_tf_port *this);
// 
void ast_modport_tf_port_action(FILE *out, struct ast_modport_tf_port *this);



// 
struct ast_import_export {
    ast_type                        type;
};
// 
void ast_import_export_describe(FILE *out, struct ast_import_export *this);
// 
void ast_import_export_action(FILE *out, struct ast_import_export *this);



// 
struct ast_concurrent_assertion_item {
    ast_type                        type;
};
// 
void ast_concurrent_assertion_item_describe(FILE *out, struct ast_concurrent_assertion_item *this);
// 
void ast_concurrent_assertion_item_action(FILE *out, struct ast_concurrent_assertion_item *this);



// 
struct ast_concurrent_assertion_statement {
    ast_type                        type;
};
// 
void ast_concurrent_assertion_statement_describe(FILE *out, struct ast_concurrent_assertion_statement *this);
// 
void ast_concurrent_assertion_statement_action(FILE *out, struct ast_concurrent_assertion_statement *this);



// 
struct ast_assert_property_statement {
    ast_type                        type;
};
// 
void ast_assert_property_statement_describe(FILE *out, struct ast_assert_property_statement *this);
// 
void ast_assert_property_statement_action(FILE *out, struct ast_assert_property_statement *this);



// 
struct ast_assume_property_statement {
    ast_type                        type;
};
// 
void ast_assume_property_statement_describe(FILE *out, struct ast_assume_property_statement *this);
// 
void ast_assume_property_statement_action(FILE *out, struct ast_assume_property_statement *this);



// 
struct ast_cover_property_statement {
    ast_type                        type;
};
// 
void ast_cover_property_statement_describe(FILE *out, struct ast_cover_property_statement *this);
// 
void ast_cover_property_statement_action(FILE *out, struct ast_cover_property_statement *this);



// 
struct ast_expect_property_statement {
    ast_type                        type;
};
// 
void ast_expect_property_statement_describe(FILE *out, struct ast_expect_property_statement *this);
// 
void ast_expect_property_statement_action(FILE *out, struct ast_expect_property_statement *this);



// 
struct ast_cover_sequence_statement {
    ast_type                        type;
};
// 
void ast_cover_sequence_statement_describe(FILE *out, struct ast_cover_sequence_statement *this);
// 
void ast_cover_sequence_statement_action(FILE *out, struct ast_cover_sequence_statement *this);



// 
struct ast_restrict_property_statement {
    ast_type                        type;
};
// 
void ast_restrict_property_statement_describe(FILE *out, struct ast_restrict_property_statement *this);
// 
void ast_restrict_property_statement_action(FILE *out, struct ast_restrict_property_statement *this);



// 
struct ast_property_instance {
    ast_type                        type;
};
// 
void ast_property_instance_describe(FILE *out, struct ast_property_instance *this);
// 
void ast_property_instance_action(FILE *out, struct ast_property_instance *this);



// 
struct ast_property_list_of_arguments {
    ast_type                        type;
};
// 
void ast_property_list_of_arguments_describe(FILE *out, struct ast_property_list_of_arguments *this);
// 
void ast_property_list_of_arguments_action(FILE *out, struct ast_property_list_of_arguments *this);



// 
struct ast_property_actual_arg {
    ast_type                        type;
};
// 
void ast_property_actual_arg_describe(FILE *out, struct ast_property_actual_arg *this);
// 
void ast_property_actual_arg_action(FILE *out, struct ast_property_actual_arg *this);



// 
struct ast_assertion_item_declaration {
    ast_type                        type;
};
// 
void ast_assertion_item_declaration_describe(FILE *out, struct ast_assertion_item_declaration *this);
// 
void ast_assertion_item_declaration_action(FILE *out, struct ast_assertion_item_declaration *this);



// 
struct ast_property_declaration {
    ast_type                        type;
};
// 
void ast_property_declaration_describe(FILE *out, struct ast_property_declaration *this);
// 
void ast_property_declaration_action(FILE *out, struct ast_property_declaration *this);



// 
struct ast_property_port_list {
    ast_type                        type;
};
// 
void ast_property_port_list_describe(FILE *out, struct ast_property_port_list *this);
// 
void ast_property_port_list_action(FILE *out, struct ast_property_port_list *this);



// 
struct ast_property_port_item {
    ast_type                        type;
};
// 
void ast_property_port_item_describe(FILE *out, struct ast_property_port_item *this);
// 
void ast_property_port_item_action(FILE *out, struct ast_property_port_item *this);



// 
struct ast_property_lvar_port_direction {
    ast_type                        type;
};
// 
void ast_property_lvar_port_direction_describe(FILE *out, struct ast_property_lvar_port_direction *this);
// 
void ast_property_lvar_port_direction_action(FILE *out, struct ast_property_lvar_port_direction *this);



// 
struct ast_property_formal_type {
    ast_type                        type;
};
// 
void ast_property_formal_type_describe(FILE *out, struct ast_property_formal_type *this);
// 
void ast_property_formal_type_action(FILE *out, struct ast_property_formal_type *this);



// 
struct ast_property_spec {
    ast_type                        type;
};
// 
void ast_property_spec_describe(FILE *out, struct ast_property_spec *this);
// 
void ast_property_spec_action(FILE *out, struct ast_property_spec *this);



// 
struct ast_property_expr {
    ast_type                        type;
};
// 
void ast_property_expr_describe(FILE *out, struct ast_property_expr *this);
// 
void ast_property_expr_action(FILE *out, struct ast_property_expr *this);



// 
struct ast_property_case_item {
    ast_type                        type;
};
// 
void ast_property_case_item_describe(FILE *out, struct ast_property_case_item *this);
// 
void ast_property_case_item_action(FILE *out, struct ast_property_case_item *this);



// 
struct ast_sequence_declaration {
    ast_type                        type;
};
// 
void ast_sequence_declaration_describe(FILE *out, struct ast_sequence_declaration *this);
// 
void ast_sequence_declaration_action(FILE *out, struct ast_sequence_declaration *this);



// 
struct ast_sequence_port_list {
    ast_type                        type;
};
// 
void ast_sequence_port_list_describe(FILE *out, struct ast_sequence_port_list *this);
// 
void ast_sequence_port_list_action(FILE *out, struct ast_sequence_port_list *this);



// 
struct ast_sequence_port_item {
    ast_type                        type;
};
// 
void ast_sequence_port_item_describe(FILE *out, struct ast_sequence_port_item *this);
// 
void ast_sequence_port_item_action(FILE *out, struct ast_sequence_port_item *this);



// 
struct ast_sequence_lvar_port_direction {
    ast_type                        type;
};
// 
void ast_sequence_lvar_port_direction_describe(FILE *out, struct ast_sequence_lvar_port_direction *this);
// 
void ast_sequence_lvar_port_direction_action(FILE *out, struct ast_sequence_lvar_port_direction *this);



// 
struct ast_sequence_formal_type {
    ast_type                        type;
};
// 
void ast_sequence_formal_type_describe(FILE *out, struct ast_sequence_formal_type *this);
// 
void ast_sequence_formal_type_action(FILE *out, struct ast_sequence_formal_type *this);



// 
struct ast_sequence_expr {
    ast_type                        type;
};
// 
void ast_sequence_expr_describe(FILE *out, struct ast_sequence_expr *this);
// 
void ast_sequence_expr_action(FILE *out, struct ast_sequence_expr *this);



// 
struct ast_cycle_delay_range {
    ast_type                        type;
};
// 
void ast_cycle_delay_range_describe(FILE *out, struct ast_cycle_delay_range *this);
// 
void ast_cycle_delay_range_action(FILE *out, struct ast_cycle_delay_range *this);



// 
struct ast_sequence_method_call {
    ast_type                        type;
};
// 
void ast_sequence_method_call_describe(FILE *out, struct ast_sequence_method_call *this);
// 
void ast_sequence_method_call_action(FILE *out, struct ast_sequence_method_call *this);



// 
struct ast_sequence_match_item {
    ast_type                        type;
};
// 
void ast_sequence_match_item_describe(FILE *out, struct ast_sequence_match_item *this);
// 
void ast_sequence_match_item_action(FILE *out, struct ast_sequence_match_item *this);



// 
struct ast_sequence_instance {
    ast_type                        type;
};
// 
void ast_sequence_instance_describe(FILE *out, struct ast_sequence_instance *this);
// 
void ast_sequence_instance_action(FILE *out, struct ast_sequence_instance *this);



// 
struct ast_sequence_list_of_arguments {
    ast_type                        type;
};
// 
void ast_sequence_list_of_arguments_describe(FILE *out, struct ast_sequence_list_of_arguments *this);
// 
void ast_sequence_list_of_arguments_action(FILE *out, struct ast_sequence_list_of_arguments *this);



// 
struct ast_sequence_actual_arg {
    ast_type                        type;
};
// 
void ast_sequence_actual_arg_describe(FILE *out, struct ast_sequence_actual_arg *this);
// 
void ast_sequence_actual_arg_action(FILE *out, struct ast_sequence_actual_arg *this);



// 
struct ast_boolean_abbrev {
    ast_type                        type;
};
// 
void ast_boolean_abbrev_describe(FILE *out, struct ast_boolean_abbrev *this);
// 
void ast_boolean_abbrev_action(FILE *out, struct ast_boolean_abbrev *this);



// 
struct ast_sequence_abbrev {
    ast_type                        type;
};
// 
void ast_sequence_abbrev_describe(FILE *out, struct ast_sequence_abbrev *this);
// 
void ast_sequence_abbrev_action(FILE *out, struct ast_sequence_abbrev *this);



// 
struct ast_consecutive_repetition {
    ast_type                        type;
};
// 
void ast_consecutive_repetition_describe(FILE *out, struct ast_consecutive_repetition *this);
// 
void ast_consecutive_repetition_action(FILE *out, struct ast_consecutive_repetition *this);



// 
struct ast_non_consecutive_repetition {
    ast_type                        type;
};
// 
void ast_non_consecutive_repetition_describe(FILE *out, struct ast_non_consecutive_repetition *this);
// 
void ast_non_consecutive_repetition_action(FILE *out, struct ast_non_consecutive_repetition *this);



// 
struct ast_goto_repetition {
    ast_type                        type;
};
// 
void ast_goto_repetition_describe(FILE *out, struct ast_goto_repetition *this);
// 
void ast_goto_repetition_action(FILE *out, struct ast_goto_repetition *this);



// 
struct ast_const_or_range_expression {
    ast_type                        type;
};
// 
void ast_const_or_range_expression_describe(FILE *out, struct ast_const_or_range_expression *this);
// 
void ast_const_or_range_expression_action(FILE *out, struct ast_const_or_range_expression *this);



// 
struct ast_cycle_delay_const_range_expression {
    ast_type                        type;
};
// 
void ast_cycle_delay_const_range_expression_describe(FILE *out, struct ast_cycle_delay_const_range_expression *this);
// 
void ast_cycle_delay_const_range_expression_action(FILE *out, struct ast_cycle_delay_const_range_expression *this);



// 
struct ast_expression_or_dist {
    ast_type                        type;
};
// 
void ast_expression_or_dist_describe(FILE *out, struct ast_expression_or_dist *this);
// 
void ast_expression_or_dist_action(FILE *out, struct ast_expression_or_dist *this);



// 
struct ast_assertion_variable_declaration {
    ast_type                        type;
};
// 
void ast_assertion_variable_declaration_describe(FILE *out, struct ast_assertion_variable_declaration *this);
// 
void ast_assertion_variable_declaration_action(FILE *out, struct ast_assertion_variable_declaration *this);



// 
struct ast_let_declaration {
    ast_type                        type;
};
// 
void ast_let_declaration_describe(FILE *out, struct ast_let_declaration *this);
// 
void ast_let_declaration_action(FILE *out, struct ast_let_declaration *this);



// 
struct ast_let_identifier {
    ast_type                        type;
};
// 
void ast_let_identifier_describe(FILE *out, struct ast_let_identifier *this);
// 
void ast_let_identifier_action(FILE *out, struct ast_let_identifier *this);



// 
struct ast_let_port_list {
    ast_type                        type;
};
// 
void ast_let_port_list_describe(FILE *out, struct ast_let_port_list *this);
// 
void ast_let_port_list_action(FILE *out, struct ast_let_port_list *this);



// 
struct ast_let_port_item {
    ast_type                        type;
};
// 
void ast_let_port_item_describe(FILE *out, struct ast_let_port_item *this);
// 
void ast_let_port_item_action(FILE *out, struct ast_let_port_item *this);



// 
struct ast_let_formal_type {
    ast_type                        type;
};
// 
void ast_let_formal_type_describe(FILE *out, struct ast_let_formal_type *this);
// 
void ast_let_formal_type_action(FILE *out, struct ast_let_formal_type *this);



// 
struct ast_let_expression {
    ast_type                        type;
};
// 
void ast_let_expression_describe(FILE *out, struct ast_let_expression *this);
// 
void ast_let_expression_action(FILE *out, struct ast_let_expression *this);



// 
struct ast_let_list_of_arguments {
    ast_type                        type;
};
// 
void ast_let_list_of_arguments_describe(FILE *out, struct ast_let_list_of_arguments *this);
// 
void ast_let_list_of_arguments_action(FILE *out, struct ast_let_list_of_arguments *this);



// 
struct ast_let_actual_arg {
    ast_type                        type;
};
// 
void ast_let_actual_arg_describe(FILE *out, struct ast_let_actual_arg *this);
// 
void ast_let_actual_arg_action(FILE *out, struct ast_let_actual_arg *this);



// 
struct ast_covergroup_declaration {
    ast_type                        type;
};
// 
void ast_covergroup_declaration_describe(FILE *out, struct ast_covergroup_declaration *this);
// 
void ast_covergroup_declaration_action(FILE *out, struct ast_covergroup_declaration *this);



// 
struct ast_coverage_spec_or_option {
    ast_type                        type;
};
// 
void ast_coverage_spec_or_option_describe(FILE *out, struct ast_coverage_spec_or_option *this);
// 
void ast_coverage_spec_or_option_action(FILE *out, struct ast_coverage_spec_or_option *this);



// 
struct ast_coverage_option {
    ast_type                        type;
};
// 
void ast_coverage_option_describe(FILE *out, struct ast_coverage_option *this);
// 
void ast_coverage_option_action(FILE *out, struct ast_coverage_option *this);



// 
struct ast_coverage_spec {
    ast_type                        type;
};
// 
void ast_coverage_spec_describe(FILE *out, struct ast_coverage_spec *this);
// 
void ast_coverage_spec_action(FILE *out, struct ast_coverage_spec *this);



// 
struct ast_coverage_event {
    ast_type                        type;
};
// 
void ast_coverage_event_describe(FILE *out, struct ast_coverage_event *this);
// 
void ast_coverage_event_action(FILE *out, struct ast_coverage_event *this);



// 
struct ast_block_event_expression {
    ast_type                        type;
};
// 
void ast_block_event_expression_describe(FILE *out, struct ast_block_event_expression *this);
// 
void ast_block_event_expression_action(FILE *out, struct ast_block_event_expression *this);



// 
struct ast_hierarchical_btf_identifier {
    ast_type                        type;
};
// 
void ast_hierarchical_btf_identifier_describe(FILE *out, struct ast_hierarchical_btf_identifier *this);
// 
void ast_hierarchical_btf_identifier_action(FILE *out, struct ast_hierarchical_btf_identifier *this);



// 
struct ast_cover_point {
    ast_type                        type;
};
// 
void ast_cover_point_describe(FILE *out, struct ast_cover_point *this);
// 
void ast_cover_point_action(FILE *out, struct ast_cover_point *this);



// 
struct ast_bins_or_empty {
    ast_type                        type;
};
// 
void ast_bins_or_empty_describe(FILE *out, struct ast_bins_or_empty *this);
// 
void ast_bins_or_empty_action(FILE *out, struct ast_bins_or_empty *this);



// 
struct ast_bins_or_options {
    ast_type                        type;
};
// 
void ast_bins_or_options_describe(FILE *out, struct ast_bins_or_options *this);
// 
void ast_bins_or_options_action(FILE *out, struct ast_bins_or_options *this);



// 
struct ast_bins_keyword {
    ast_type                        type;
};
// 
void ast_bins_keyword_describe(FILE *out, struct ast_bins_keyword *this);
// 
void ast_bins_keyword_action(FILE *out, struct ast_bins_keyword *this);



// 
struct ast_trans_list {
    ast_type                        type;
};
// 
void ast_trans_list_describe(FILE *out, struct ast_trans_list *this);
// 
void ast_trans_list_action(FILE *out, struct ast_trans_list *this);



// 
struct ast_trans_set {
    ast_type                        type;
};
// 
void ast_trans_set_describe(FILE *out, struct ast_trans_set *this);
// 
void ast_trans_set_action(FILE *out, struct ast_trans_set *this);



// 
struct ast_trans_range_list {
    ast_type                        type;
};
// 
void ast_trans_range_list_describe(FILE *out, struct ast_trans_range_list *this);
// 
void ast_trans_range_list_action(FILE *out, struct ast_trans_range_list *this);



// 
struct ast_trans_item {
    ast_type                        type;
};
// 
void ast_trans_item_describe(FILE *out, struct ast_trans_item *this);
// 
void ast_trans_item_action(FILE *out, struct ast_trans_item *this);



// 
struct ast_repeat_range {
    ast_type                        type;
};
// 
void ast_repeat_range_describe(FILE *out, struct ast_repeat_range *this);
// 
void ast_repeat_range_action(FILE *out, struct ast_repeat_range *this);



// 
struct ast_cover_cross {
    ast_type                        type;
};
// 
void ast_cover_cross_describe(FILE *out, struct ast_cover_cross *this);
// 
void ast_cover_cross_action(FILE *out, struct ast_cover_cross *this);



// 
struct ast_list_of_cross_items {
    ast_type                        type;
};
// 
void ast_list_of_cross_items_describe(FILE *out, struct ast_list_of_cross_items *this);
// 
void ast_list_of_cross_items_action(FILE *out, struct ast_list_of_cross_items *this);



// 
struct ast_cross_item {
    ast_type                        type;
};
// 
void ast_cross_item_describe(FILE *out, struct ast_cross_item *this);
// 
void ast_cross_item_action(FILE *out, struct ast_cross_item *this);



// 
struct ast_cross_body {
    ast_type                        type;
};
// 
void ast_cross_body_describe(FILE *out, struct ast_cross_body *this);
// 
void ast_cross_body_action(FILE *out, struct ast_cross_body *this);



// 
struct ast_cross_body_item {
    ast_type                        type;
};
// 
void ast_cross_body_item_describe(FILE *out, struct ast_cross_body_item *this);
// 
void ast_cross_body_item_action(FILE *out, struct ast_cross_body_item *this);



// 
struct ast_bins_selection_or_option {
    ast_type                        type;
};
// 
void ast_bins_selection_or_option_describe(FILE *out, struct ast_bins_selection_or_option *this);
// 
void ast_bins_selection_or_option_action(FILE *out, struct ast_bins_selection_or_option *this);



// 
struct ast_bins_selection {
    ast_type                        type;
};
// 
void ast_bins_selection_describe(FILE *out, struct ast_bins_selection *this);
// 
void ast_bins_selection_action(FILE *out, struct ast_bins_selection *this);



// 
struct ast_select_expression {
    ast_type                        type;
};
// 
void ast_select_expression_describe(FILE *out, struct ast_select_expression *this);
// 
void ast_select_expression_action(FILE *out, struct ast_select_expression *this);



// 
struct ast_select_condition {
    ast_type                        type;
};
// 
void ast_select_condition_describe(FILE *out, struct ast_select_condition *this);
// 
void ast_select_condition_action(FILE *out, struct ast_select_condition *this);



// 
struct ast_bins_expression {
    ast_type                        type;
};
// 
void ast_bins_expression_describe(FILE *out, struct ast_bins_expression *this);
// 
void ast_bins_expression_action(FILE *out, struct ast_bins_expression *this);



// 
struct ast_covergroup_range_list {
    ast_type                        type;
};
// 
void ast_covergroup_range_list_describe(FILE *out, struct ast_covergroup_range_list *this);
// 
void ast_covergroup_range_list_action(FILE *out, struct ast_covergroup_range_list *this);



// 
struct ast_covergroup_value_range {
    ast_type                        type;
};
// 
void ast_covergroup_value_range_describe(FILE *out, struct ast_covergroup_value_range *this);
// 
void ast_covergroup_value_range_action(FILE *out, struct ast_covergroup_value_range *this);



// 
struct ast_with_covergroup_expression {
    ast_type                        type;
};
// 
void ast_with_covergroup_expression_describe(FILE *out, struct ast_with_covergroup_expression *this);
// 
void ast_with_covergroup_expression_action(FILE *out, struct ast_with_covergroup_expression *this);



// 
struct ast_set_covergroup_expression {
    ast_type                        type;
};
// 
void ast_set_covergroup_expression_describe(FILE *out, struct ast_set_covergroup_expression *this);
// 
void ast_set_covergroup_expression_action(FILE *out, struct ast_set_covergroup_expression *this);



// 
struct ast_integer_covergroup_expression {
    ast_type                        type;
};
// 
void ast_integer_covergroup_expression_describe(FILE *out, struct ast_integer_covergroup_expression *this);
// 
void ast_integer_covergroup_expression_action(FILE *out, struct ast_integer_covergroup_expression *this);



// 
struct ast_cross_set_expression {
    ast_type                        type;
};
// 
void ast_cross_set_expression_describe(FILE *out, struct ast_cross_set_expression *this);
// 
void ast_cross_set_expression_action(FILE *out, struct ast_cross_set_expression *this);



// 
struct ast_covergroup_expression {
    ast_type                        type;
};
// 
void ast_covergroup_expression_describe(FILE *out, struct ast_covergroup_expression *this);
// 
void ast_covergroup_expression_action(FILE *out, struct ast_covergroup_expression *this);



// 
struct ast_gate_instantiation {
    ast_type                        type;
};
// 
void ast_gate_instantiation_describe(FILE *out, struct ast_gate_instantiation *this);
// 
void ast_gate_instantiation_action(FILE *out, struct ast_gate_instantiation *this);



// 
struct ast_cmos_switch_instance {
    ast_type                        type;
};
// 
void ast_cmos_switch_instance_describe(FILE *out, struct ast_cmos_switch_instance *this);
// 
void ast_cmos_switch_instance_action(FILE *out, struct ast_cmos_switch_instance *this);



// 
struct ast_enable_gate_instance {
    ast_type                        type;
};
// 
void ast_enable_gate_instance_describe(FILE *out, struct ast_enable_gate_instance *this);
// 
void ast_enable_gate_instance_action(FILE *out, struct ast_enable_gate_instance *this);



// 
struct ast_mos_switch_instance {
    ast_type                        type;
};
// 
void ast_mos_switch_instance_describe(FILE *out, struct ast_mos_switch_instance *this);
// 
void ast_mos_switch_instance_action(FILE *out, struct ast_mos_switch_instance *this);



// 
struct ast_n_input_gate_instance {
    ast_type                        type;
};
// 
void ast_n_input_gate_instance_describe(FILE *out, struct ast_n_input_gate_instance *this);
// 
void ast_n_input_gate_instance_action(FILE *out, struct ast_n_input_gate_instance *this);



// 
struct ast_n_output_gate_instance {
    ast_type                        type;
};
// 
void ast_n_output_gate_instance_describe(FILE *out, struct ast_n_output_gate_instance *this);
// 
void ast_n_output_gate_instance_action(FILE *out, struct ast_n_output_gate_instance *this);



// 
struct ast_pass_switch_instance {
    ast_type                        type;
};
// 
void ast_pass_switch_instance_describe(FILE *out, struct ast_pass_switch_instance *this);
// 
void ast_pass_switch_instance_action(FILE *out, struct ast_pass_switch_instance *this);



// 
struct ast_pass_enable_switch_instance {
    ast_type                        type;
};
// 
void ast_pass_enable_switch_instance_describe(FILE *out, struct ast_pass_enable_switch_instance *this);
// 
void ast_pass_enable_switch_instance_action(FILE *out, struct ast_pass_enable_switch_instance *this);



// 
struct ast_pull_gate_instance {
    ast_type                        type;
};
// 
void ast_pull_gate_instance_describe(FILE *out, struct ast_pull_gate_instance *this);
// 
void ast_pull_gate_instance_action(FILE *out, struct ast_pull_gate_instance *this);



// 
struct ast_pulldown_strength {
    ast_type                        type;
};
// 
void ast_pulldown_strength_describe(FILE *out, struct ast_pulldown_strength *this);
// 
void ast_pulldown_strength_action(FILE *out, struct ast_pulldown_strength *this);



// 
struct ast_pullup_strength {
    ast_type                        type;
};
// 
void ast_pullup_strength_describe(FILE *out, struct ast_pullup_strength *this);
// 
void ast_pullup_strength_action(FILE *out, struct ast_pullup_strength *this);



// 
struct ast_enable_terminal {
    ast_type                        type;
};
// 
void ast_enable_terminal_describe(FILE *out, struct ast_enable_terminal *this);
// 
void ast_enable_terminal_action(FILE *out, struct ast_enable_terminal *this);



// 
struct ast_inout_terminal {
    ast_type                        type;
};
// 
void ast_inout_terminal_describe(FILE *out, struct ast_inout_terminal *this);
// 
void ast_inout_terminal_action(FILE *out, struct ast_inout_terminal *this);



// 
struct ast_input_terminal {
    ast_type                        type;
};
// 
void ast_input_terminal_describe(FILE *out, struct ast_input_terminal *this);
// 
void ast_input_terminal_action(FILE *out, struct ast_input_terminal *this);



// 
struct ast_ncontrol_terminal {
    ast_type                        type;
};
// 
void ast_ncontrol_terminal_describe(FILE *out, struct ast_ncontrol_terminal *this);
// 
void ast_ncontrol_terminal_action(FILE *out, struct ast_ncontrol_terminal *this);



// 
struct ast_output_terminal {
    ast_type                        type;
};
// 
void ast_output_terminal_describe(FILE *out, struct ast_output_terminal *this);
// 
void ast_output_terminal_action(FILE *out, struct ast_output_terminal *this);



// 
struct ast_pcontrol_terminal {
    ast_type                        type;
};
// 
void ast_pcontrol_terminal_describe(FILE *out, struct ast_pcontrol_terminal *this);
// 
void ast_pcontrol_terminal_action(FILE *out, struct ast_pcontrol_terminal *this);



// 
struct ast_cmos_switchtype {
    ast_type                        type;
};
// 
void ast_cmos_switchtype_describe(FILE *out, struct ast_cmos_switchtype *this);
// 
void ast_cmos_switchtype_action(FILE *out, struct ast_cmos_switchtype *this);



// 
struct ast_enable_gatetype {
    ast_type                        type;
};
// 
void ast_enable_gatetype_describe(FILE *out, struct ast_enable_gatetype *this);
// 
void ast_enable_gatetype_action(FILE *out, struct ast_enable_gatetype *this);



// 
struct ast_mos_switchtype {
    ast_type                        type;
};
// 
void ast_mos_switchtype_describe(FILE *out, struct ast_mos_switchtype *this);
// 
void ast_mos_switchtype_action(FILE *out, struct ast_mos_switchtype *this);



// 
struct ast_n_input_gatetype {
    ast_type                        type;
};
// 
void ast_n_input_gatetype_describe(FILE *out, struct ast_n_input_gatetype *this);
// 
void ast_n_input_gatetype_action(FILE *out, struct ast_n_input_gatetype *this);



// 
struct ast_n_output_gatetype {
    ast_type                        type;
};
// 
void ast_n_output_gatetype_describe(FILE *out, struct ast_n_output_gatetype *this);
// 
void ast_n_output_gatetype_action(FILE *out, struct ast_n_output_gatetype *this);



// 
struct ast_pass_en_switchtype {
    ast_type                        type;
};
// 
void ast_pass_en_switchtype_describe(FILE *out, struct ast_pass_en_switchtype *this);
// 
void ast_pass_en_switchtype_action(FILE *out, struct ast_pass_en_switchtype *this);



// 
struct ast_pass_switchtype {
    ast_type                        type;
};
// 
void ast_pass_switchtype_describe(FILE *out, struct ast_pass_switchtype *this);
// 
void ast_pass_switchtype_action(FILE *out, struct ast_pass_switchtype *this);



// 
struct ast_module_instantiation {
    ast_type                        type;
};
// 
void ast_module_instantiation_describe(FILE *out, struct ast_module_instantiation *this);
// 
void ast_module_instantiation_action(FILE *out, struct ast_module_instantiation *this);



// 
struct ast_parameter_value_assignment {
    ast_type                        type;
};
// 
void ast_parameter_value_assignment_describe(FILE *out, struct ast_parameter_value_assignment *this);
// 
void ast_parameter_value_assignment_action(FILE *out, struct ast_parameter_value_assignment *this);



// 
struct ast_list_of_parameter_assignments {
    ast_type                        type;
};
// 
void ast_list_of_parameter_assignments_describe(FILE *out, struct ast_list_of_parameter_assignments *this);
// 
void ast_list_of_parameter_assignments_action(FILE *out, struct ast_list_of_parameter_assignments *this);



// 
struct ast_ordered_parameter_assignment {
    ast_type                        type;
};
// 
void ast_ordered_parameter_assignment_describe(FILE *out, struct ast_ordered_parameter_assignment *this);
// 
void ast_ordered_parameter_assignment_action(FILE *out, struct ast_ordered_parameter_assignment *this);



// 
struct ast_named_parameter_assignment {
    ast_type                        type;
};
// 
void ast_named_parameter_assignment_describe(FILE *out, struct ast_named_parameter_assignment *this);
// 
void ast_named_parameter_assignment_action(FILE *out, struct ast_named_parameter_assignment *this);



// 
struct ast_hierarchical_instance {
    ast_type                        type;
};
// 
void ast_hierarchical_instance_describe(FILE *out, struct ast_hierarchical_instance *this);
// 
void ast_hierarchical_instance_action(FILE *out, struct ast_hierarchical_instance *this);



// 
struct ast_name_of_instance {
    ast_type                        type;
};
// 
void ast_name_of_instance_describe(FILE *out, struct ast_name_of_instance *this);
// 
void ast_name_of_instance_action(FILE *out, struct ast_name_of_instance *this);



// 
struct ast_list_of_port_connections {
    ast_type                        type;
};
// 
void ast_list_of_port_connections_describe(FILE *out, struct ast_list_of_port_connections *this);
// 
void ast_list_of_port_connections_action(FILE *out, struct ast_list_of_port_connections *this);



// 
struct ast_ordered_port_connection {
    ast_type                        type;
};
// 
void ast_ordered_port_connection_describe(FILE *out, struct ast_ordered_port_connection *this);
// 
void ast_ordered_port_connection_action(FILE *out, struct ast_ordered_port_connection *this);



// 
struct ast_named_port_connection {
    ast_type                        type;
};
// 
void ast_named_port_connection_describe(FILE *out, struct ast_named_port_connection *this);
// 
void ast_named_port_connection_action(FILE *out, struct ast_named_port_connection *this);



// 
struct ast_interface_instantiation {
    ast_type                        type;
};
// 
void ast_interface_instantiation_describe(FILE *out, struct ast_interface_instantiation *this);
// 
void ast_interface_instantiation_action(FILE *out, struct ast_interface_instantiation *this);



// 
struct ast_program_instantiation {
    ast_type                        type;
};
// 
void ast_program_instantiation_describe(FILE *out, struct ast_program_instantiation *this);
// 
void ast_program_instantiation_action(FILE *out, struct ast_program_instantiation *this);



// 
struct ast_checker_instantiation {
    ast_type                        type;
};
// 
void ast_checker_instantiation_describe(FILE *out, struct ast_checker_instantiation *this);
// 
void ast_checker_instantiation_action(FILE *out, struct ast_checker_instantiation *this);



// 
struct ast_list_of_checker_port_connections {
    ast_type                        type;
};
// 
void ast_list_of_checker_port_connections_describe(FILE *out, struct ast_list_of_checker_port_connections *this);
// 
void ast_list_of_checker_port_connections_action(FILE *out, struct ast_list_of_checker_port_connections *this);



// 
struct ast_ordered_checker_port_connection {
    ast_type                        type;
};
// 
void ast_ordered_checker_port_connection_describe(FILE *out, struct ast_ordered_checker_port_connection *this);
// 
void ast_ordered_checker_port_connection_action(FILE *out, struct ast_ordered_checker_port_connection *this);



// 
struct ast_named_checker_port_connection {
    ast_type                        type;
};
// 
void ast_named_checker_port_connection_describe(FILE *out, struct ast_named_checker_port_connection *this);
// 
void ast_named_checker_port_connection_action(FILE *out, struct ast_named_checker_port_connection *this);



// 
struct ast_generate_region {
    ast_type                        type;
};
// 
void ast_generate_region_describe(FILE *out, struct ast_generate_region *this);
// 
void ast_generate_region_action(FILE *out, struct ast_generate_region *this);



// 
struct ast_loop_generate_construct {
    ast_type                        type;
};
// 
void ast_loop_generate_construct_describe(FILE *out, struct ast_loop_generate_construct *this);
// 
void ast_loop_generate_construct_action(FILE *out, struct ast_loop_generate_construct *this);



// 
struct ast_genvar_initialization {
    ast_type                        type;
};
// 
void ast_genvar_initialization_describe(FILE *out, struct ast_genvar_initialization *this);
// 
void ast_genvar_initialization_action(FILE *out, struct ast_genvar_initialization *this);



// 
struct ast_genvar_iteration {
    ast_type                        type;
};
// 
void ast_genvar_iteration_describe(FILE *out, struct ast_genvar_iteration *this);
// 
void ast_genvar_iteration_action(FILE *out, struct ast_genvar_iteration *this);



// 
struct ast_conditional_generate_construct {
    ast_type                        type;
};
// 
void ast_conditional_generate_construct_describe(FILE *out, struct ast_conditional_generate_construct *this);
// 
void ast_conditional_generate_construct_action(FILE *out, struct ast_conditional_generate_construct *this);



// 
struct ast_if_generate_construct {
    ast_type                        type;
};
// 
void ast_if_generate_construct_describe(FILE *out, struct ast_if_generate_construct *this);
// 
void ast_if_generate_construct_action(FILE *out, struct ast_if_generate_construct *this);



// 
struct ast_case_generate_construct {
    ast_type                        type;
};
// 
void ast_case_generate_construct_describe(FILE *out, struct ast_case_generate_construct *this);
// 
void ast_case_generate_construct_action(FILE *out, struct ast_case_generate_construct *this);



// 
struct ast_case_generate_item {
    ast_type                        type;
};
// 
void ast_case_generate_item_describe(FILE *out, struct ast_case_generate_item *this);
// 
void ast_case_generate_item_action(FILE *out, struct ast_case_generate_item *this);



// 
struct ast_generate_block {
    ast_type                        type;
};
// 
void ast_generate_block_describe(FILE *out, struct ast_generate_block *this);
// 
void ast_generate_block_action(FILE *out, struct ast_generate_block *this);



// 
struct ast_generate_item {
    ast_type                        type;
};
// 
void ast_generate_item_describe(FILE *out, struct ast_generate_item *this);
// 
void ast_generate_item_action(FILE *out, struct ast_generate_item *this);



// 
struct ast_udp_nonansi_declaration {
    ast_type                        type;
};
// 
void ast_udp_nonansi_declaration_describe(FILE *out, struct ast_udp_nonansi_declaration *this);
// 
void ast_udp_nonansi_declaration_action(FILE *out, struct ast_udp_nonansi_declaration *this);



// 
struct ast_udp_ansi_declaration {
    ast_type                        type;
};
// 
void ast_udp_ansi_declaration_describe(FILE *out, struct ast_udp_ansi_declaration *this);
// 
void ast_udp_ansi_declaration_action(FILE *out, struct ast_udp_ansi_declaration *this);



// 
struct ast_udp_declaration {
    ast_type                        type;
};
// 
void ast_udp_declaration_describe(FILE *out, struct ast_udp_declaration *this);
// 
void ast_udp_declaration_action(FILE *out, struct ast_udp_declaration *this);



// 
struct ast_udp_port_list {
    ast_type                        type;
};
// 
void ast_udp_port_list_describe(FILE *out, struct ast_udp_port_list *this);
// 
void ast_udp_port_list_action(FILE *out, struct ast_udp_port_list *this);



// 
struct ast_udp_declaration_port_list {
    ast_type                        type;
};
// 
void ast_udp_declaration_port_list_describe(FILE *out, struct ast_udp_declaration_port_list *this);
// 
void ast_udp_declaration_port_list_action(FILE *out, struct ast_udp_declaration_port_list *this);



// 
struct ast_udp_port_declaration {
    ast_type                        type;
};
// 
void ast_udp_port_declaration_describe(FILE *out, struct ast_udp_port_declaration *this);
// 
void ast_udp_port_declaration_action(FILE *out, struct ast_udp_port_declaration *this);



// 
struct ast_udp_output_declaration {
    ast_type                        type;
};
// 
void ast_udp_output_declaration_describe(FILE *out, struct ast_udp_output_declaration *this);
// 
void ast_udp_output_declaration_action(FILE *out, struct ast_udp_output_declaration *this);



// 
struct ast_udp_input_declaration {
    ast_type                        type;
};
// 
void ast_udp_input_declaration_describe(FILE *out, struct ast_udp_input_declaration *this);
// 
void ast_udp_input_declaration_action(FILE *out, struct ast_udp_input_declaration *this);



// 
struct ast_udp_reg_declaration {
    ast_type                        type;
};
// 
void ast_udp_reg_declaration_describe(FILE *out, struct ast_udp_reg_declaration *this);
// 
void ast_udp_reg_declaration_action(FILE *out, struct ast_udp_reg_declaration *this);



// 
struct ast_udp_body {
    ast_type                        type;
};
// 
void ast_udp_body_describe(FILE *out, struct ast_udp_body *this);
// 
void ast_udp_body_action(FILE *out, struct ast_udp_body *this);



// 
struct ast_combinational_body {
    ast_type                        type;
};
// 
void ast_combinational_body_describe(FILE *out, struct ast_combinational_body *this);
// 
void ast_combinational_body_action(FILE *out, struct ast_combinational_body *this);



// 
struct ast_combinational_entry {
    ast_type                        type;
};
// 
void ast_combinational_entry_describe(FILE *out, struct ast_combinational_entry *this);
// 
void ast_combinational_entry_action(FILE *out, struct ast_combinational_entry *this);



// 
struct ast_sequential_body {
    ast_type                        type;
};
// 
void ast_sequential_body_describe(FILE *out, struct ast_sequential_body *this);
// 
void ast_sequential_body_action(FILE *out, struct ast_sequential_body *this);



// 
struct ast_udp_initial_statement {
    ast_type                        type;
};
// 
void ast_udp_initial_statement_describe(FILE *out, struct ast_udp_initial_statement *this);
// 
void ast_udp_initial_statement_action(FILE *out, struct ast_udp_initial_statement *this);



// 
struct ast_init_val {
    ast_type                        type;
};
// 
void ast_init_val_describe(FILE *out, struct ast_init_val *this);
// 
void ast_init_val_action(FILE *out, struct ast_init_val *this);



// 
struct ast_sequential_entry {
    ast_type                        type;
};
// 
void ast_sequential_entry_describe(FILE *out, struct ast_sequential_entry *this);
// 
void ast_sequential_entry_action(FILE *out, struct ast_sequential_entry *this);



// 
struct ast_seq_input_list {
    ast_type                        type;
};
// 
void ast_seq_input_list_describe(FILE *out, struct ast_seq_input_list *this);
// 
void ast_seq_input_list_action(FILE *out, struct ast_seq_input_list *this);



// 
struct ast_level_input_list {
    ast_type                        type;
};
// 
void ast_level_input_list_describe(FILE *out, struct ast_level_input_list *this);
// 
void ast_level_input_list_action(FILE *out, struct ast_level_input_list *this);



// 
struct ast_edge_input_list {
    ast_type                        type;
};
// 
void ast_edge_input_list_describe(FILE *out, struct ast_edge_input_list *this);
// 
void ast_edge_input_list_action(FILE *out, struct ast_edge_input_list *this);



// 
struct ast_edge_indicator {
    ast_type                        type;
};
// 
void ast_edge_indicator_describe(FILE *out, struct ast_edge_indicator *this);
// 
void ast_edge_indicator_action(FILE *out, struct ast_edge_indicator *this);



// 
struct ast_current_state {
    ast_type                        type;
};
// 
void ast_current_state_describe(FILE *out, struct ast_current_state *this);
// 
void ast_current_state_action(FILE *out, struct ast_current_state *this);



// 
struct ast_next_state {
    ast_type                        type;
};
// 
void ast_next_state_describe(FILE *out, struct ast_next_state *this);
// 
void ast_next_state_action(FILE *out, struct ast_next_state *this);



// 
struct ast_output_symbol {
    ast_type                        type;
};
// 
void ast_output_symbol_describe(FILE *out, struct ast_output_symbol *this);
// 
void ast_output_symbol_action(FILE *out, struct ast_output_symbol *this);



// 
struct ast_level_symbol {
    ast_type                        type;
};
// 
void ast_level_symbol_describe(FILE *out, struct ast_level_symbol *this);
// 
void ast_level_symbol_action(FILE *out, struct ast_level_symbol *this);



// 
struct ast_edge_symbol {
    ast_type                        type;
};
// 
void ast_edge_symbol_describe(FILE *out, struct ast_edge_symbol *this);
// 
void ast_edge_symbol_action(FILE *out, struct ast_edge_symbol *this);



// 
struct ast_udp_instantiation {
    ast_type                        type;
};
// 
void ast_udp_instantiation_describe(FILE *out, struct ast_udp_instantiation *this);
// 
void ast_udp_instantiation_action(FILE *out, struct ast_udp_instantiation *this);



// 
struct ast_udp_instance {
    ast_type                        type;
};
// 
void ast_udp_instance_describe(FILE *out, struct ast_udp_instance *this);
// 
void ast_udp_instance_action(FILE *out, struct ast_udp_instance *this);



// 
struct ast_continuous_assign {
    ast_type                        type;
};
// 
void ast_continuous_assign_describe(FILE *out, struct ast_continuous_assign *this);
// 
void ast_continuous_assign_action(FILE *out, struct ast_continuous_assign *this);



// 
struct ast_list_of_net_assignments {
    ast_type                        type;
};
// 
void ast_list_of_net_assignments_describe(FILE *out, struct ast_list_of_net_assignments *this);
// 
void ast_list_of_net_assignments_action(FILE *out, struct ast_list_of_net_assignments *this);



// 
struct ast_list_of_variable_assignments {
    ast_type                        type;
};
// 
void ast_list_of_variable_assignments_describe(FILE *out, struct ast_list_of_variable_assignments *this);
// 
void ast_list_of_variable_assignments_action(FILE *out, struct ast_list_of_variable_assignments *this);



// 
struct ast_net_alias {
    ast_type                        type;
};
// 
void ast_net_alias_describe(FILE *out, struct ast_net_alias *this);
// 
void ast_net_alias_action(FILE *out, struct ast_net_alias *this);



// 
struct ast_net_assignment {
    ast_type                        type;
};
// 
void ast_net_assignment_describe(FILE *out, struct ast_net_assignment *this);
// 
void ast_net_assignment_action(FILE *out, struct ast_net_assignment *this);



// 
struct ast_initial_construct {
    ast_type                        type;
};
// 
void ast_initial_construct_describe(FILE *out, struct ast_initial_construct *this);
// 
void ast_initial_construct_action(FILE *out, struct ast_initial_construct *this);



// 
struct ast_always_construct {
    ast_type                        type;
};
// 
void ast_always_construct_describe(FILE *out, struct ast_always_construct *this);
// 
void ast_always_construct_action(FILE *out, struct ast_always_construct *this);



// 
struct ast_always_keyword {
    ast_type                        type;
};
// 
void ast_always_keyword_describe(FILE *out, struct ast_always_keyword *this);
// 
void ast_always_keyword_action(FILE *out, struct ast_always_keyword *this);



// 
struct ast_final_construct {
    ast_type                        type;
};
// 
void ast_final_construct_describe(FILE *out, struct ast_final_construct *this);
// 
void ast_final_construct_action(FILE *out, struct ast_final_construct *this);



// 
struct ast_blocking_assignment {
    ast_type                        type;
};
// 
void ast_blocking_assignment_describe(FILE *out, struct ast_blocking_assignment *this);
// 
void ast_blocking_assignment_action(FILE *out, struct ast_blocking_assignment *this);



// 
struct ast_operator_assignment {
    ast_type                        type;
};
// 
void ast_operator_assignment_describe(FILE *out, struct ast_operator_assignment *this);
// 
void ast_operator_assignment_action(FILE *out, struct ast_operator_assignment *this);



// 
struct ast_assignment_operator {
    ast_type                        type;
};
// 
void ast_assignment_operator_describe(FILE *out, struct ast_assignment_operator *this);
// 
void ast_assignment_operator_action(FILE *out, struct ast_assignment_operator *this);



// 
struct ast_nonblocking_assignment {
    ast_type                        type;
};
// 
void ast_nonblocking_assignment_describe(FILE *out, struct ast_nonblocking_assignment *this);
// 
void ast_nonblocking_assignment_action(FILE *out, struct ast_nonblocking_assignment *this);



// 
struct ast_procedural_continuous_assignment {
    ast_type                        type;
};
// 
void ast_procedural_continuous_assignment_describe(FILE *out, struct ast_procedural_continuous_assignment *this);
// 
void ast_procedural_continuous_assignment_action(FILE *out, struct ast_procedural_continuous_assignment *this);



// 
struct ast_variable_assignment {
    ast_type                        type;
};
// 
void ast_variable_assignment_describe(FILE *out, struct ast_variable_assignment *this);
// 
void ast_variable_assignment_action(FILE *out, struct ast_variable_assignment *this);



// 
struct ast_action_block {
    ast_type                        type;
};
// 
void ast_action_block_describe(FILE *out, struct ast_action_block *this);
// 
void ast_action_block_action(FILE *out, struct ast_action_block *this);



// 
struct ast_seq_block {
    ast_type                        type;
};
// 
void ast_seq_block_describe(FILE *out, struct ast_seq_block *this);
// 
void ast_seq_block_action(FILE *out, struct ast_seq_block *this);



// 
struct ast_par_block {
    ast_type                        type;
};
// 
void ast_par_block_describe(FILE *out, struct ast_par_block *this);
// 
void ast_par_block_action(FILE *out, struct ast_par_block *this);



// 
struct ast_join_keyword {
    ast_type                        type;
};
// 
void ast_join_keyword_describe(FILE *out, struct ast_join_keyword *this);
// 
void ast_join_keyword_action(FILE *out, struct ast_join_keyword *this);



// 
struct ast_statement_or_null {
    ast_type                        type;
};
// 
void ast_statement_or_null_describe(FILE *out, struct ast_statement_or_null *this);
// 
void ast_statement_or_null_action(FILE *out, struct ast_statement_or_null *this);



// 
struct ast_statement {
    ast_type                        type;
};
// 
void ast_statement_describe(FILE *out, struct ast_statement *this);
// 
void ast_statement_action(FILE *out, struct ast_statement *this);



// 
struct ast_statement_item {
    ast_type                        type;
};
// 
void ast_statement_item_describe(FILE *out, struct ast_statement_item *this);
// 
void ast_statement_item_action(FILE *out, struct ast_statement_item *this);



// 
struct ast_function_statement {
    ast_type                        type;
};
// 
void ast_function_statement_describe(FILE *out, struct ast_function_statement *this);
// 
void ast_function_statement_action(FILE *out, struct ast_function_statement *this);



// 
struct ast_function_statement_or_null {
    ast_type                        type;
};
// 
void ast_function_statement_or_null_describe(FILE *out, struct ast_function_statement_or_null *this);
// 
void ast_function_statement_or_null_action(FILE *out, struct ast_function_statement_or_null *this);



// 
struct ast_variable_identifier_list {
    ast_type                        type;
};
// 
void ast_variable_identifier_list_describe(FILE *out, struct ast_variable_identifier_list *this);
// 
void ast_variable_identifier_list_action(FILE *out, struct ast_variable_identifier_list *this);



// 
struct ast_procedural_timing_control_statement {
    ast_type                        type;
};
// 
void ast_procedural_timing_control_statement_describe(FILE *out, struct ast_procedural_timing_control_statement *this);
// 
void ast_procedural_timing_control_statement_action(FILE *out, struct ast_procedural_timing_control_statement *this);



// 
struct ast_delay_or_event_control {
    ast_type                        type;
};
// 
void ast_delay_or_event_control_describe(FILE *out, struct ast_delay_or_event_control *this);
// 
void ast_delay_or_event_control_action(FILE *out, struct ast_delay_or_event_control *this);



// 
struct ast_delay_control {
    ast_type                        type;
};
// 
void ast_delay_control_describe(FILE *out, struct ast_delay_control *this);
// 
void ast_delay_control_action(FILE *out, struct ast_delay_control *this);



// 
struct ast_event_control {
    ast_type                        type;
};
// 
void ast_event_control_describe(FILE *out, struct ast_event_control *this);
// 
void ast_event_control_action(FILE *out, struct ast_event_control *this);



// 
struct ast_event_expression {
    ast_type                        type;
};
// 
void ast_event_expression_describe(FILE *out, struct ast_event_expression *this);
// 
void ast_event_expression_action(FILE *out, struct ast_event_expression *this);



// 
struct ast_procedural_timing_control {
    ast_type                        type;
};
// 
void ast_procedural_timing_control_describe(FILE *out, struct ast_procedural_timing_control *this);
// 
void ast_procedural_timing_control_action(FILE *out, struct ast_procedural_timing_control *this);



// 
struct ast_jump_statement {
    ast_type                        type;
};
// 
void ast_jump_statement_describe(FILE *out, struct ast_jump_statement *this);
// 
void ast_jump_statement_action(FILE *out, struct ast_jump_statement *this);



// 
struct ast_wait_statement {
    ast_type                        type;
};
// 
void ast_wait_statement_describe(FILE *out, struct ast_wait_statement *this);
// 
void ast_wait_statement_action(FILE *out, struct ast_wait_statement *this);



// 
struct ast_event_trigger {
    ast_type                        type;
};
// 
void ast_event_trigger_describe(FILE *out, struct ast_event_trigger *this);
// 
void ast_event_trigger_action(FILE *out, struct ast_event_trigger *this);



// 
struct ast_disable_statement {
    ast_type                        type;
};
// 
void ast_disable_statement_describe(FILE *out, struct ast_disable_statement *this);
// 
void ast_disable_statement_action(FILE *out, struct ast_disable_statement *this);



// 
struct ast_conditional_statement {
    ast_type                        type;
};
// 
void ast_conditional_statement_describe(FILE *out, struct ast_conditional_statement *this);
// 
void ast_conditional_statement_action(FILE *out, struct ast_conditional_statement *this);



// 
struct ast_unique_priority {
    ast_type                        type;
};
// 
void ast_unique_priority_describe(FILE *out, struct ast_unique_priority *this);
// 
void ast_unique_priority_action(FILE *out, struct ast_unique_priority *this);



// 
struct ast_cond_predicate {
    ast_type                        type;
};
// 
void ast_cond_predicate_describe(FILE *out, struct ast_cond_predicate *this);
// 
void ast_cond_predicate_action(FILE *out, struct ast_cond_predicate *this);



// 
struct ast_expression_or_cond_pattern {
    ast_type                        type;
};
// 
void ast_expression_or_cond_pattern_describe(FILE *out, struct ast_expression_or_cond_pattern *this);
// 
void ast_expression_or_cond_pattern_action(FILE *out, struct ast_expression_or_cond_pattern *this);



// 
struct ast_cond_pattern {
    ast_type                        type;
};
// 
void ast_cond_pattern_describe(FILE *out, struct ast_cond_pattern *this);
// 
void ast_cond_pattern_action(FILE *out, struct ast_cond_pattern *this);



// 
struct ast_case_statement {
    ast_type                        type;
};
// 
void ast_case_statement_describe(FILE *out, struct ast_case_statement *this);
// 
void ast_case_statement_action(FILE *out, struct ast_case_statement *this);



// 
struct ast_case_keyword {
    ast_type                        type;
};
// 
void ast_case_keyword_describe(FILE *out, struct ast_case_keyword *this);
// 
void ast_case_keyword_action(FILE *out, struct ast_case_keyword *this);



// 
struct ast_case_expression {
    ast_type                        type;
};
// 
void ast_case_expression_describe(FILE *out, struct ast_case_expression *this);
// 
void ast_case_expression_action(FILE *out, struct ast_case_expression *this);



// 
struct ast_case_item {
    ast_type                        type;
};
// 
void ast_case_item_describe(FILE *out, struct ast_case_item *this);
// 
void ast_case_item_action(FILE *out, struct ast_case_item *this);



// 
struct ast_case_pattern_item {
    ast_type                        type;
};
// 
void ast_case_pattern_item_describe(FILE *out, struct ast_case_pattern_item *this);
// 
void ast_case_pattern_item_action(FILE *out, struct ast_case_pattern_item *this);



// 
struct ast_case_inside_item {
    ast_type                        type;
};
// 
void ast_case_inside_item_describe(FILE *out, struct ast_case_inside_item *this);
// 
void ast_case_inside_item_action(FILE *out, struct ast_case_inside_item *this);



// 
struct ast_case_item_expression {
    ast_type                        type;
};
// 
void ast_case_item_expression_describe(FILE *out, struct ast_case_item_expression *this);
// 
void ast_case_item_expression_action(FILE *out, struct ast_case_item_expression *this);



// 
struct ast_randcase_statement {
    ast_type                        type;
};
// 
void ast_randcase_statement_describe(FILE *out, struct ast_randcase_statement *this);
// 
void ast_randcase_statement_action(FILE *out, struct ast_randcase_statement *this);



// 
struct ast_randcase_item {
    ast_type                        type;
};
// 
void ast_randcase_item_describe(FILE *out, struct ast_randcase_item *this);
// 
void ast_randcase_item_action(FILE *out, struct ast_randcase_item *this);



// 
struct ast_open_range_list {
    ast_type                        type;
};
// 
void ast_open_range_list_describe(FILE *out, struct ast_open_range_list *this);
// 
void ast_open_range_list_action(FILE *out, struct ast_open_range_list *this);



// 
struct ast_open_value_range {
    ast_type                        type;
};
// 
void ast_open_value_range_describe(FILE *out, struct ast_open_value_range *this);
// 
void ast_open_value_range_action(FILE *out, struct ast_open_value_range *this);



// 
struct ast_pattern {
    ast_type                        type;
};
// 
void ast_pattern_describe(FILE *out, struct ast_pattern *this);
// 
void ast_pattern_action(FILE *out, struct ast_pattern *this);



// 
struct ast_assignment_pattern {
    ast_type                        type;
};
// 
void ast_assignment_pattern_describe(FILE *out, struct ast_assignment_pattern *this);
// 
void ast_assignment_pattern_action(FILE *out, struct ast_assignment_pattern *this);



// 
struct ast_structure_pattern_key {
    ast_type                        type;
};
// 
void ast_structure_pattern_key_describe(FILE *out, struct ast_structure_pattern_key *this);
// 
void ast_structure_pattern_key_action(FILE *out, struct ast_structure_pattern_key *this);



// 
struct ast_array_pattern_key {
    ast_type                        type;
};
// 
void ast_array_pattern_key_describe(FILE *out, struct ast_array_pattern_key *this);
// 
void ast_array_pattern_key_action(FILE *out, struct ast_array_pattern_key *this);



// 
struct ast_assignment_pattern_key {
    ast_type                        type;
};
// 
void ast_assignment_pattern_key_describe(FILE *out, struct ast_assignment_pattern_key *this);
// 
void ast_assignment_pattern_key_action(FILE *out, struct ast_assignment_pattern_key *this);



// 
struct ast_assignment_pattern_expression {
    ast_type                        type;
};
// 
void ast_assignment_pattern_expression_describe(FILE *out, struct ast_assignment_pattern_expression *this);
// 
void ast_assignment_pattern_expression_action(FILE *out, struct ast_assignment_pattern_expression *this);



// 
struct ast_assignment_pattern_expression_type {
    ast_type                        type;
};
// 
void ast_assignment_pattern_expression_type_describe(FILE *out, struct ast_assignment_pattern_expression_type *this);
// 
void ast_assignment_pattern_expression_type_action(FILE *out, struct ast_assignment_pattern_expression_type *this);



// 
struct ast_constant_assignment_pattern_expression {
    ast_type                        type;
};
// 
void ast_constant_assignment_pattern_expression_describe(FILE *out, struct ast_constant_assignment_pattern_expression *this);
// 
void ast_constant_assignment_pattern_expression_action(FILE *out, struct ast_constant_assignment_pattern_expression *this);



// 
struct ast_assignment_pattern_net_lvalue {
    ast_type                        type;
};
// 
void ast_assignment_pattern_net_lvalue_describe(FILE *out, struct ast_assignment_pattern_net_lvalue *this);
// 
void ast_assignment_pattern_net_lvalue_action(FILE *out, struct ast_assignment_pattern_net_lvalue *this);



// 
struct ast_assignment_pattern_variable_lvalue {
    ast_type                        type;
};
// 
void ast_assignment_pattern_variable_lvalue_describe(FILE *out, struct ast_assignment_pattern_variable_lvalue *this);
// 
void ast_assignment_pattern_variable_lvalue_action(FILE *out, struct ast_assignment_pattern_variable_lvalue *this);



// 
struct ast_loop_statement {
    ast_type                        type;
};
// 
void ast_loop_statement_describe(FILE *out, struct ast_loop_statement *this);
// 
void ast_loop_statement_action(FILE *out, struct ast_loop_statement *this);



// 
struct ast_for_initialization {
    ast_type                        type;
};
// 
void ast_for_initialization_describe(FILE *out, struct ast_for_initialization *this);
// 
void ast_for_initialization_action(FILE *out, struct ast_for_initialization *this);



// 
struct ast_for_variable_declaration {
    ast_type                        type;
};
// 
void ast_for_variable_declaration_describe(FILE *out, struct ast_for_variable_declaration *this);
// 
void ast_for_variable_declaration_action(FILE *out, struct ast_for_variable_declaration *this);



// 
struct ast_for_step {
    ast_type                        type;
};
// 
void ast_for_step_describe(FILE *out, struct ast_for_step *this);
// 
void ast_for_step_action(FILE *out, struct ast_for_step *this);



// 
struct ast_for_step_assignment {
    ast_type                        type;
};
// 
void ast_for_step_assignment_describe(FILE *out, struct ast_for_step_assignment *this);
// 
void ast_for_step_assignment_action(FILE *out, struct ast_for_step_assignment *this);



// 
struct ast_loop_variables {
    ast_type                        type;
};
// 
void ast_loop_variables_describe(FILE *out, struct ast_loop_variables *this);
// 
void ast_loop_variables_action(FILE *out, struct ast_loop_variables *this);



// 
struct ast_subroutine_call_statement {
    ast_type                        type;
};
// 
void ast_subroutine_call_statement_describe(FILE *out, struct ast_subroutine_call_statement *this);
// 
void ast_subroutine_call_statement_action(FILE *out, struct ast_subroutine_call_statement *this);



// 
struct ast_assertion_item {
    ast_type                        type;
};
// 
void ast_assertion_item_describe(FILE *out, struct ast_assertion_item *this);
// 
void ast_assertion_item_action(FILE *out, struct ast_assertion_item *this);



// 
struct ast_deferred_immediate_assertion_item {
    ast_type                        type;
};
// 
void ast_deferred_immediate_assertion_item_describe(FILE *out, struct ast_deferred_immediate_assertion_item *this);
// 
void ast_deferred_immediate_assertion_item_action(FILE *out, struct ast_deferred_immediate_assertion_item *this);



// 
struct ast_procedural_assertion_statement {
    ast_type                        type;
};
// 
void ast_procedural_assertion_statement_describe(FILE *out, struct ast_procedural_assertion_statement *this);
// 
void ast_procedural_assertion_statement_action(FILE *out, struct ast_procedural_assertion_statement *this);



// 
struct ast_immediate_assertion_statement {
    ast_type                        type;
};
// 
void ast_immediate_assertion_statement_describe(FILE *out, struct ast_immediate_assertion_statement *this);
// 
void ast_immediate_assertion_statement_action(FILE *out, struct ast_immediate_assertion_statement *this);



// 
struct ast_simple_immediate_assertion_statement {
    ast_type                        type;
};
// 
void ast_simple_immediate_assertion_statement_describe(FILE *out, struct ast_simple_immediate_assertion_statement *this);
// 
void ast_simple_immediate_assertion_statement_action(FILE *out, struct ast_simple_immediate_assertion_statement *this);



// 
struct ast_simple_immediate_assert_statement {
    ast_type                        type;
};
// 
void ast_simple_immediate_assert_statement_describe(FILE *out, struct ast_simple_immediate_assert_statement *this);
// 
void ast_simple_immediate_assert_statement_action(FILE *out, struct ast_simple_immediate_assert_statement *this);



// 
struct ast_simple_immediate_assume_statement {
    ast_type                        type;
};
// 
void ast_simple_immediate_assume_statement_describe(FILE *out, struct ast_simple_immediate_assume_statement *this);
// 
void ast_simple_immediate_assume_statement_action(FILE *out, struct ast_simple_immediate_assume_statement *this);



// 
struct ast_simple_immediate_cover_statement {
    ast_type                        type;
};
// 
void ast_simple_immediate_cover_statement_describe(FILE *out, struct ast_simple_immediate_cover_statement *this);
// 
void ast_simple_immediate_cover_statement_action(FILE *out, struct ast_simple_immediate_cover_statement *this);



// 
struct ast_deferred_immediate_assertion_statement {
    ast_type                        type;
};
// 
void ast_deferred_immediate_assertion_statement_describe(FILE *out, struct ast_deferred_immediate_assertion_statement *this);
// 
void ast_deferred_immediate_assertion_statement_action(FILE *out, struct ast_deferred_immediate_assertion_statement *this);



// 
struct ast_deferred_immediate_assert_statement {
    ast_type                        type;
};
// 
void ast_deferred_immediate_assert_statement_describe(FILE *out, struct ast_deferred_immediate_assert_statement *this);
// 
void ast_deferred_immediate_assert_statement_action(FILE *out, struct ast_deferred_immediate_assert_statement *this);



// 
struct ast_deferred_immediate_assume_statement {
    ast_type                        type;
};
// 
void ast_deferred_immediate_assume_statement_describe(FILE *out, struct ast_deferred_immediate_assume_statement *this);
// 
void ast_deferred_immediate_assume_statement_action(FILE *out, struct ast_deferred_immediate_assume_statement *this);



// 
struct ast_deferred_immediate_cover_statement {
    ast_type                        type;
};
// 
void ast_deferred_immediate_cover_statement_describe(FILE *out, struct ast_deferred_immediate_cover_statement *this);
// 
void ast_deferred_immediate_cover_statement_action(FILE *out, struct ast_deferred_immediate_cover_statement *this);



// 
struct ast_clocking_declaration {
    ast_type                        type;
};
// 
void ast_clocking_declaration_describe(FILE *out, struct ast_clocking_declaration *this);
// 
void ast_clocking_declaration_action(FILE *out, struct ast_clocking_declaration *this);



// 
struct ast_clocking_event {
    ast_type                        type;
};
// 
void ast_clocking_event_describe(FILE *out, struct ast_clocking_event *this);
// 
void ast_clocking_event_action(FILE *out, struct ast_clocking_event *this);



// 
struct ast_clocking_item {
    ast_type                        type;
};
// 
void ast_clocking_item_describe(FILE *out, struct ast_clocking_item *this);
// 
void ast_clocking_item_action(FILE *out, struct ast_clocking_item *this);



// 
struct ast_default_skew {
    ast_type                        type;
};
// 
void ast_default_skew_describe(FILE *out, struct ast_default_skew *this);
// 
void ast_default_skew_action(FILE *out, struct ast_default_skew *this);



// 
struct ast_clocking_direction {
    ast_type                        type;
};
// 
void ast_clocking_direction_describe(FILE *out, struct ast_clocking_direction *this);
// 
void ast_clocking_direction_action(FILE *out, struct ast_clocking_direction *this);



// 
struct ast_list_of_clocking_decl_assign {
    ast_type                        type;
};
// 
void ast_list_of_clocking_decl_assign_describe(FILE *out, struct ast_list_of_clocking_decl_assign *this);
// 
void ast_list_of_clocking_decl_assign_action(FILE *out, struct ast_list_of_clocking_decl_assign *this);



// 
struct ast_clocking_decl_assign {
    ast_type                        type;
};
// 
void ast_clocking_decl_assign_describe(FILE *out, struct ast_clocking_decl_assign *this);
// 
void ast_clocking_decl_assign_action(FILE *out, struct ast_clocking_decl_assign *this);



// 
struct ast_clocking_skew {
    ast_type                        type;
};
// 
void ast_clocking_skew_describe(FILE *out, struct ast_clocking_skew *this);
// 
void ast_clocking_skew_action(FILE *out, struct ast_clocking_skew *this);



// 
struct ast_clocking_drive {
    ast_type                        type;
};
// 
void ast_clocking_drive_describe(FILE *out, struct ast_clocking_drive *this);
// 
void ast_clocking_drive_action(FILE *out, struct ast_clocking_drive *this);



// 
struct ast_cycle_delay {
    ast_type                        type;
};
// 
void ast_cycle_delay_describe(FILE *out, struct ast_cycle_delay *this);
// 
void ast_cycle_delay_action(FILE *out, struct ast_cycle_delay *this);



// 
struct ast_clockvar {
    ast_type                        type;
};
// 
void ast_clockvar_describe(FILE *out, struct ast_clockvar *this);
// 
void ast_clockvar_action(FILE *out, struct ast_clockvar *this);



// 
struct ast_clockvar_expression {
    ast_type                        type;
};
// 
void ast_clockvar_expression_describe(FILE *out, struct ast_clockvar_expression *this);
// 
void ast_clockvar_expression_action(FILE *out, struct ast_clockvar_expression *this);



// 
struct ast_randsequence_statement {
    ast_type                        type;
};
// 
void ast_randsequence_statement_describe(FILE *out, struct ast_randsequence_statement *this);
// 
void ast_randsequence_statement_action(FILE *out, struct ast_randsequence_statement *this);



// 
struct ast_production {
    ast_type                        type;
};
// 
void ast_production_describe(FILE *out, struct ast_production *this);
// 
void ast_production_action(FILE *out, struct ast_production *this);



// 
struct ast_rs_rule {
    ast_type                        type;
};
// 
void ast_rs_rule_describe(FILE *out, struct ast_rs_rule *this);
// 
void ast_rs_rule_action(FILE *out, struct ast_rs_rule *this);



// 
struct ast_rs_production_list {
    ast_type                        type;
};
// 
void ast_rs_production_list_describe(FILE *out, struct ast_rs_production_list *this);
// 
void ast_rs_production_list_action(FILE *out, struct ast_rs_production_list *this);



// 
struct ast_weight_specification {
    ast_type                        type;
};
// 
void ast_weight_specification_describe(FILE *out, struct ast_weight_specification *this);
// 
void ast_weight_specification_action(FILE *out, struct ast_weight_specification *this);



// 
struct ast_rs_code_block {
    ast_type                        type;
};
// 
void ast_rs_code_block_describe(FILE *out, struct ast_rs_code_block *this);
// 
void ast_rs_code_block_action(FILE *out, struct ast_rs_code_block *this);



// 
struct ast_rs_prod {
    ast_type                        type;
};
// 
void ast_rs_prod_describe(FILE *out, struct ast_rs_prod *this);
// 
void ast_rs_prod_action(FILE *out, struct ast_rs_prod *this);



// 
struct ast_production_item {
    ast_type                        type;
};
// 
void ast_production_item_describe(FILE *out, struct ast_production_item *this);
// 
void ast_production_item_action(FILE *out, struct ast_production_item *this);



// 
struct ast_rs_if_else {
    ast_type                        type;
};
// 
void ast_rs_if_else_describe(FILE *out, struct ast_rs_if_else *this);
// 
void ast_rs_if_else_action(FILE *out, struct ast_rs_if_else *this);



// 
struct ast_rs_repeat {
    ast_type                        type;
};
// 
void ast_rs_repeat_describe(FILE *out, struct ast_rs_repeat *this);
// 
void ast_rs_repeat_action(FILE *out, struct ast_rs_repeat *this);



// 
struct ast_rs_case {
    ast_type                        type;
};
// 
void ast_rs_case_describe(FILE *out, struct ast_rs_case *this);
// 
void ast_rs_case_action(FILE *out, struct ast_rs_case *this);



// 
struct ast_rs_case_item {
    ast_type                        type;
};
// 
void ast_rs_case_item_describe(FILE *out, struct ast_rs_case_item *this);
// 
void ast_rs_case_item_action(FILE *out, struct ast_rs_case_item *this);



// 
struct ast_specify_block {
    ast_type                        type;
};
// 
void ast_specify_block_describe(FILE *out, struct ast_specify_block *this);
// 
void ast_specify_block_action(FILE *out, struct ast_specify_block *this);



// 
struct ast_specify_item {
    ast_type                        type;
};
// 
void ast_specify_item_describe(FILE *out, struct ast_specify_item *this);
// 
void ast_specify_item_action(FILE *out, struct ast_specify_item *this);



// 
struct ast_pulsestyle_declaration {
    ast_type                        type;
};
// 
void ast_pulsestyle_declaration_describe(FILE *out, struct ast_pulsestyle_declaration *this);
// 
void ast_pulsestyle_declaration_action(FILE *out, struct ast_pulsestyle_declaration *this);



// 
struct ast_showcancelled_declaration {
    ast_type                        type;
};
// 
void ast_showcancelled_declaration_describe(FILE *out, struct ast_showcancelled_declaration *this);
// 
void ast_showcancelled_declaration_action(FILE *out, struct ast_showcancelled_declaration *this);



// 
struct ast_path_declaration {
    ast_type                        type;
};
// 
void ast_path_declaration_describe(FILE *out, struct ast_path_declaration *this);
// 
void ast_path_declaration_action(FILE *out, struct ast_path_declaration *this);



// 
struct ast_simple_path_declaration {
    ast_type                        type;
};
// 
void ast_simple_path_declaration_describe(FILE *out, struct ast_simple_path_declaration *this);
// 
void ast_simple_path_declaration_action(FILE *out, struct ast_simple_path_declaration *this);



// 
struct ast_parallel_path_description {
    ast_type                        type;
};
// 
void ast_parallel_path_description_describe(FILE *out, struct ast_parallel_path_description *this);
// 
void ast_parallel_path_description_action(FILE *out, struct ast_parallel_path_description *this);



// 
struct ast_full_path_description {
    ast_type                        type;
};
// 
void ast_full_path_description_describe(FILE *out, struct ast_full_path_description *this);
// 
void ast_full_path_description_action(FILE *out, struct ast_full_path_description *this);



// 
struct ast_list_of_path_inputs {
    ast_type                        type;
};
// 
void ast_list_of_path_inputs_describe(FILE *out, struct ast_list_of_path_inputs *this);
// 
void ast_list_of_path_inputs_action(FILE *out, struct ast_list_of_path_inputs *this);



// 
struct ast_list_of_path_outputs {
    ast_type                        type;
};
// 
void ast_list_of_path_outputs_describe(FILE *out, struct ast_list_of_path_outputs *this);
// 
void ast_list_of_path_outputs_action(FILE *out, struct ast_list_of_path_outputs *this);



// 
struct ast_specify_input_terminal_descriptor {
    ast_type                        type;
};
// 
void ast_specify_input_terminal_descriptor_describe(FILE *out, struct ast_specify_input_terminal_descriptor *this);
// 
void ast_specify_input_terminal_descriptor_action(FILE *out, struct ast_specify_input_terminal_descriptor *this);



// 
struct ast_specify_output_terminal_descriptor {
    ast_type                        type;
};
// 
void ast_specify_output_terminal_descriptor_describe(FILE *out, struct ast_specify_output_terminal_descriptor *this);
// 
void ast_specify_output_terminal_descriptor_action(FILE *out, struct ast_specify_output_terminal_descriptor *this);



// 
struct ast_input_identifier {
    ast_type                        type;
};
// 
void ast_input_identifier_describe(FILE *out, struct ast_input_identifier *this);
// 
void ast_input_identifier_action(FILE *out, struct ast_input_identifier *this);



// 
struct ast_output_identifier {
    ast_type                        type;
};
// 
void ast_output_identifier_describe(FILE *out, struct ast_output_identifier *this);
// 
void ast_output_identifier_action(FILE *out, struct ast_output_identifier *this);



// 
struct ast_path_delay_value {
    ast_type                        type;
};
// 
void ast_path_delay_value_describe(FILE *out, struct ast_path_delay_value *this);
// 
void ast_path_delay_value_action(FILE *out, struct ast_path_delay_value *this);



// 
struct ast_list_of_path_delay_expressions {
    ast_type                        type;
};
// 
void ast_list_of_path_delay_expressions_describe(FILE *out, struct ast_list_of_path_delay_expressions *this);
// 
void ast_list_of_path_delay_expressions_action(FILE *out, struct ast_list_of_path_delay_expressions *this);



// 
struct ast_t_path_delay_expression {
    ast_type                        type;
};
// 
void ast_t_path_delay_expression_describe(FILE *out, struct ast_t_path_delay_expression *this);
// 
void ast_t_path_delay_expression_action(FILE *out, struct ast_t_path_delay_expression *this);



// 
struct ast_trise_path_delay_expression {
    ast_type                        type;
};
// 
void ast_trise_path_delay_expression_describe(FILE *out, struct ast_trise_path_delay_expression *this);
// 
void ast_trise_path_delay_expression_action(FILE *out, struct ast_trise_path_delay_expression *this);



// 
struct ast_tfall_path_delay_expression {
    ast_type                        type;
};
// 
void ast_tfall_path_delay_expression_describe(FILE *out, struct ast_tfall_path_delay_expression *this);
// 
void ast_tfall_path_delay_expression_action(FILE *out, struct ast_tfall_path_delay_expression *this);



// 
struct ast_tz_path_delay_expression {
    ast_type                        type;
};
// 
void ast_tz_path_delay_expression_describe(FILE *out, struct ast_tz_path_delay_expression *this);
// 
void ast_tz_path_delay_expression_action(FILE *out, struct ast_tz_path_delay_expression *this);



// 
struct ast_t01_path_delay_expression {
    ast_type                        type;
};
// 
void ast_t01_path_delay_expression_describe(FILE *out, struct ast_t01_path_delay_expression *this);
// 
void ast_t01_path_delay_expression_action(FILE *out, struct ast_t01_path_delay_expression *this);



// 
struct ast_t10_path_delay_expression {
    ast_type                        type;
};
// 
void ast_t10_path_delay_expression_describe(FILE *out, struct ast_t10_path_delay_expression *this);
// 
void ast_t10_path_delay_expression_action(FILE *out, struct ast_t10_path_delay_expression *this);



// 
struct ast_t0z_path_delay_expression {
    ast_type                        type;
};
// 
void ast_t0z_path_delay_expression_describe(FILE *out, struct ast_t0z_path_delay_expression *this);
// 
void ast_t0z_path_delay_expression_action(FILE *out, struct ast_t0z_path_delay_expression *this);



// 
struct ast_tz1_path_delay_expression {
    ast_type                        type;
};
// 
void ast_tz1_path_delay_expression_describe(FILE *out, struct ast_tz1_path_delay_expression *this);
// 
void ast_tz1_path_delay_expression_action(FILE *out, struct ast_tz1_path_delay_expression *this);



// 
struct ast_t1z_path_delay_expression {
    ast_type                        type;
};
// 
void ast_t1z_path_delay_expression_describe(FILE *out, struct ast_t1z_path_delay_expression *this);
// 
void ast_t1z_path_delay_expression_action(FILE *out, struct ast_t1z_path_delay_expression *this);



// 
struct ast_tz0_path_delay_expression {
    ast_type                        type;
};
// 
void ast_tz0_path_delay_expression_describe(FILE *out, struct ast_tz0_path_delay_expression *this);
// 
void ast_tz0_path_delay_expression_action(FILE *out, struct ast_tz0_path_delay_expression *this);



// 
struct ast_t0x_path_delay_expression {
    ast_type                        type;
};
// 
void ast_t0x_path_delay_expression_describe(FILE *out, struct ast_t0x_path_delay_expression *this);
// 
void ast_t0x_path_delay_expression_action(FILE *out, struct ast_t0x_path_delay_expression *this);



// 
struct ast_tx1_path_delay_expression {
    ast_type                        type;
};
// 
void ast_tx1_path_delay_expression_describe(FILE *out, struct ast_tx1_path_delay_expression *this);
// 
void ast_tx1_path_delay_expression_action(FILE *out, struct ast_tx1_path_delay_expression *this);



// 
struct ast_t1x_path_delay_expression {
    ast_type                        type;
};
// 
void ast_t1x_path_delay_expression_describe(FILE *out, struct ast_t1x_path_delay_expression *this);
// 
void ast_t1x_path_delay_expression_action(FILE *out, struct ast_t1x_path_delay_expression *this);



// 
struct ast_tx0_path_delay_expression {
    ast_type                        type;
};
// 
void ast_tx0_path_delay_expression_describe(FILE *out, struct ast_tx0_path_delay_expression *this);
// 
void ast_tx0_path_delay_expression_action(FILE *out, struct ast_tx0_path_delay_expression *this);



// 
struct ast_txz_path_delay_expression {
    ast_type                        type;
};
// 
void ast_txz_path_delay_expression_describe(FILE *out, struct ast_txz_path_delay_expression *this);
// 
void ast_txz_path_delay_expression_action(FILE *out, struct ast_txz_path_delay_expression *this);



// 
struct ast_tzx_path_delay_expression {
    ast_type                        type;
};
// 
void ast_tzx_path_delay_expression_describe(FILE *out, struct ast_tzx_path_delay_expression *this);
// 
void ast_tzx_path_delay_expression_action(FILE *out, struct ast_tzx_path_delay_expression *this);



// 
struct ast_path_delay_expression {
    ast_type                        type;
};
// 
void ast_path_delay_expression_describe(FILE *out, struct ast_path_delay_expression *this);
// 
void ast_path_delay_expression_action(FILE *out, struct ast_path_delay_expression *this);



// 
struct ast_edge_sensitive_path_declaration {
    ast_type                        type;
};
// 
void ast_edge_sensitive_path_declaration_describe(FILE *out, struct ast_edge_sensitive_path_declaration *this);
// 
void ast_edge_sensitive_path_declaration_action(FILE *out, struct ast_edge_sensitive_path_declaration *this);



// 
struct ast_parallel_edge_sensitive_path_description {
    ast_type                        type;
};
// 
void ast_parallel_edge_sensitive_path_description_describe(FILE *out, struct ast_parallel_edge_sensitive_path_description *this);
// 
void ast_parallel_edge_sensitive_path_description_action(FILE *out, struct ast_parallel_edge_sensitive_path_description *this);



// 
struct ast_full_edge_sensitive_path_description {
    ast_type                        type;
};
// 
void ast_full_edge_sensitive_path_description_describe(FILE *out, struct ast_full_edge_sensitive_path_description *this);
// 
void ast_full_edge_sensitive_path_description_action(FILE *out, struct ast_full_edge_sensitive_path_description *this);



// 
struct ast_data_source_expression {
    ast_type                        type;
};
// 
void ast_data_source_expression_describe(FILE *out, struct ast_data_source_expression *this);
// 
void ast_data_source_expression_action(FILE *out, struct ast_data_source_expression *this);



// 
struct ast_edge_identifier {
    ast_type                        type;
};
// 
void ast_edge_identifier_describe(FILE *out, struct ast_edge_identifier *this);
// 
void ast_edge_identifier_action(FILE *out, struct ast_edge_identifier *this);



// 
struct ast_state_dependent_path_declaration {
    ast_type                        type;
};
// 
void ast_state_dependent_path_declaration_describe(FILE *out, struct ast_state_dependent_path_declaration *this);
// 
void ast_state_dependent_path_declaration_action(FILE *out, struct ast_state_dependent_path_declaration *this);



// 
struct ast_polarity_operator {
    ast_type                        type;
};
// 
void ast_polarity_operator_describe(FILE *out, struct ast_polarity_operator *this);
// 
void ast_polarity_operator_action(FILE *out, struct ast_polarity_operator *this);



// 
struct ast_system_timing_check {
    ast_type                        type;
};
// 
void ast_system_timing_check_describe(FILE *out, struct ast_system_timing_check *this);
// 
void ast_system_timing_check_action(FILE *out, struct ast_system_timing_check *this);



// 
struct ast_dollarsign_setup_timing_check {
    ast_type                        type;
};
// 
void ast_dollarsign_setup_timing_check_describe(FILE *out, struct ast_dollarsign_setup_timing_check *this);
// 
void ast_dollarsign_setup_timing_check_action(FILE *out, struct ast_dollarsign_setup_timing_check *this);



// 
struct ast_dollarsign_hold_timing_check {
    ast_type                        type;
};
// 
void ast_dollarsign_hold_timing_check_describe(FILE *out, struct ast_dollarsign_hold_timing_check *this);
// 
void ast_dollarsign_hold_timing_check_action(FILE *out, struct ast_dollarsign_hold_timing_check *this);



// 
struct ast_dollarsign_setuphold_timing_check {
    ast_type                        type;
};
// 
void ast_dollarsign_setuphold_timing_check_describe(FILE *out, struct ast_dollarsign_setuphold_timing_check *this);
// 
void ast_dollarsign_setuphold_timing_check_action(FILE *out, struct ast_dollarsign_setuphold_timing_check *this);



// 
struct ast_dollarsign_recovery_timing_check {
    ast_type                        type;
};
// 
void ast_dollarsign_recovery_timing_check_describe(FILE *out, struct ast_dollarsign_recovery_timing_check *this);
// 
void ast_dollarsign_recovery_timing_check_action(FILE *out, struct ast_dollarsign_recovery_timing_check *this);



// 
struct ast_dollarsign_removal_timing_check {
    ast_type                        type;
};
// 
void ast_dollarsign_removal_timing_check_describe(FILE *out, struct ast_dollarsign_removal_timing_check *this);
// 
void ast_dollarsign_removal_timing_check_action(FILE *out, struct ast_dollarsign_removal_timing_check *this);



// 
struct ast_dollarsign_recrem_timing_check {
    ast_type                        type;
};
// 
void ast_dollarsign_recrem_timing_check_describe(FILE *out, struct ast_dollarsign_recrem_timing_check *this);
// 
void ast_dollarsign_recrem_timing_check_action(FILE *out, struct ast_dollarsign_recrem_timing_check *this);



// 
struct ast_dollarsign_skew_timing_check {
    ast_type                        type;
};
// 
void ast_dollarsign_skew_timing_check_describe(FILE *out, struct ast_dollarsign_skew_timing_check *this);
// 
void ast_dollarsign_skew_timing_check_action(FILE *out, struct ast_dollarsign_skew_timing_check *this);



// 
struct ast_dollarsign_timeskew_timing_check {
    ast_type                        type;
};
// 
void ast_dollarsign_timeskew_timing_check_describe(FILE *out, struct ast_dollarsign_timeskew_timing_check *this);
// 
void ast_dollarsign_timeskew_timing_check_action(FILE *out, struct ast_dollarsign_timeskew_timing_check *this);



// 
struct ast_dollarsign_fullskew_timing_check {
    ast_type                        type;
};
// 
void ast_dollarsign_fullskew_timing_check_describe(FILE *out, struct ast_dollarsign_fullskew_timing_check *this);
// 
void ast_dollarsign_fullskew_timing_check_action(FILE *out, struct ast_dollarsign_fullskew_timing_check *this);



// 
struct ast_dollarsign_period_timing_check {
    ast_type                        type;
};
// 
void ast_dollarsign_period_timing_check_describe(FILE *out, struct ast_dollarsign_period_timing_check *this);
// 
void ast_dollarsign_period_timing_check_action(FILE *out, struct ast_dollarsign_period_timing_check *this);



// 
struct ast_dollarsign_width_timing_check {
    ast_type                        type;
};
// 
void ast_dollarsign_width_timing_check_describe(FILE *out, struct ast_dollarsign_width_timing_check *this);
// 
void ast_dollarsign_width_timing_check_action(FILE *out, struct ast_dollarsign_width_timing_check *this);



// 
struct ast_dollarsign_nochange_timing_check {
    ast_type                        type;
};
// 
void ast_dollarsign_nochange_timing_check_describe(FILE *out, struct ast_dollarsign_nochange_timing_check *this);
// 
void ast_dollarsign_nochange_timing_check_action(FILE *out, struct ast_dollarsign_nochange_timing_check *this);



// 
struct ast_timecheck_condition {
    ast_type                        type;
};
// 
void ast_timecheck_condition_describe(FILE *out, struct ast_timecheck_condition *this);
// 
void ast_timecheck_condition_action(FILE *out, struct ast_timecheck_condition *this);



// 
struct ast_controlled_reference_event {
    ast_type                        type;
};
// 
void ast_controlled_reference_event_describe(FILE *out, struct ast_controlled_reference_event *this);
// 
void ast_controlled_reference_event_action(FILE *out, struct ast_controlled_reference_event *this);



// 
struct ast_data_event {
    ast_type                        type;
};
// 
void ast_data_event_describe(FILE *out, struct ast_data_event *this);
// 
void ast_data_event_action(FILE *out, struct ast_data_event *this);



// 
struct ast_delayed_data {
    ast_type                        type;
};
// 
void ast_delayed_data_describe(FILE *out, struct ast_delayed_data *this);
// 
void ast_delayed_data_action(FILE *out, struct ast_delayed_data *this);



// 
struct ast_delayed_reference {
    ast_type                        type;
};
// 
void ast_delayed_reference_describe(FILE *out, struct ast_delayed_reference *this);
// 
void ast_delayed_reference_action(FILE *out, struct ast_delayed_reference *this);



// 
struct ast_end_edge_offset {
    ast_type                        type;
};
// 
void ast_end_edge_offset_describe(FILE *out, struct ast_end_edge_offset *this);
// 
void ast_end_edge_offset_action(FILE *out, struct ast_end_edge_offset *this);



// 
struct ast_event_based_flag {
    ast_type                        type;
};
// 
void ast_event_based_flag_describe(FILE *out, struct ast_event_based_flag *this);
// 
void ast_event_based_flag_action(FILE *out, struct ast_event_based_flag *this);



// 
struct ast_notifier {
    ast_type                        type;
};
// 
void ast_notifier_describe(FILE *out, struct ast_notifier *this);
// 
void ast_notifier_action(FILE *out, struct ast_notifier *this);



// 
struct ast_reference_event {
    ast_type                        type;
};
// 
void ast_reference_event_describe(FILE *out, struct ast_reference_event *this);
// 
void ast_reference_event_action(FILE *out, struct ast_reference_event *this);



// 
struct ast_remain_active_flag {
    ast_type                        type;
};
// 
void ast_remain_active_flag_describe(FILE *out, struct ast_remain_active_flag *this);
// 
void ast_remain_active_flag_action(FILE *out, struct ast_remain_active_flag *this);



// 
struct ast_timestamp_condition {
    ast_type                        type;
};
// 
void ast_timestamp_condition_describe(FILE *out, struct ast_timestamp_condition *this);
// 
void ast_timestamp_condition_action(FILE *out, struct ast_timestamp_condition *this);



// 
struct ast_start_edge_offset {
    ast_type                        type;
};
// 
void ast_start_edge_offset_describe(FILE *out, struct ast_start_edge_offset *this);
// 
void ast_start_edge_offset_action(FILE *out, struct ast_start_edge_offset *this);



// 
struct ast_threshold {
    ast_type                        type;
};
// 
void ast_threshold_describe(FILE *out, struct ast_threshold *this);
// 
void ast_threshold_action(FILE *out, struct ast_threshold *this);



// 
struct ast_timing_check_limit {
    ast_type                        type;
};
// 
void ast_timing_check_limit_describe(FILE *out, struct ast_timing_check_limit *this);
// 
void ast_timing_check_limit_action(FILE *out, struct ast_timing_check_limit *this);



// 
struct ast_timing_check_event {
    ast_type                        type;
};
// 
void ast_timing_check_event_describe(FILE *out, struct ast_timing_check_event *this);
// 
void ast_timing_check_event_action(FILE *out, struct ast_timing_check_event *this);



// 
struct ast_controlled_timing_check_event {
    ast_type                        type;
};
// 
void ast_controlled_timing_check_event_describe(FILE *out, struct ast_controlled_timing_check_event *this);
// 
void ast_controlled_timing_check_event_action(FILE *out, struct ast_controlled_timing_check_event *this);



// 
struct ast_timing_check_event_control {
    ast_type                        type;
};
// 
void ast_timing_check_event_control_describe(FILE *out, struct ast_timing_check_event_control *this);
// 
void ast_timing_check_event_control_action(FILE *out, struct ast_timing_check_event_control *this);



// 
struct ast_specify_terminal_descriptor {
    ast_type                        type;
};
// 
void ast_specify_terminal_descriptor_describe(FILE *out, struct ast_specify_terminal_descriptor *this);
// 
void ast_specify_terminal_descriptor_action(FILE *out, struct ast_specify_terminal_descriptor *this);



// 
struct ast_edge_control_specifier {
    ast_type                        type;
};
// 
void ast_edge_control_specifier_describe(FILE *out, struct ast_edge_control_specifier *this);
// 
void ast_edge_control_specifier_action(FILE *out, struct ast_edge_control_specifier *this);



// 
struct ast_edge_descriptor {
    ast_type                        type;
};
// 
void ast_edge_descriptor_describe(FILE *out, struct ast_edge_descriptor *this);
// 
void ast_edge_descriptor_action(FILE *out, struct ast_edge_descriptor *this);



// 
struct ast_zero_or_one {
    ast_type                        type;
};
// 
void ast_zero_or_one_describe(FILE *out, struct ast_zero_or_one *this);
// 
void ast_zero_or_one_action(FILE *out, struct ast_zero_or_one *this);



// 
struct ast_z_or_x {
    ast_type                        type;
};
// 
void ast_z_or_x_describe(FILE *out, struct ast_z_or_x *this);
// 
void ast_z_or_x_action(FILE *out, struct ast_z_or_x *this);



// 
struct ast_timing_check_condition {
    ast_type                        type;
};
// 
void ast_timing_check_condition_describe(FILE *out, struct ast_timing_check_condition *this);
// 
void ast_timing_check_condition_action(FILE *out, struct ast_timing_check_condition *this);



// 
struct ast_scalar_timing_check_condition {
    ast_type                        type;
};
// 
void ast_scalar_timing_check_condition_describe(FILE *out, struct ast_scalar_timing_check_condition *this);
// 
void ast_scalar_timing_check_condition_action(FILE *out, struct ast_scalar_timing_check_condition *this);



// 
struct ast_scalar_constant {
    ast_type                        type;
};
// 
void ast_scalar_constant_describe(FILE *out, struct ast_scalar_constant *this);
// 
void ast_scalar_constant_action(FILE *out, struct ast_scalar_constant *this);



// 
struct ast_concatenation {
    ast_type                        type;
};
// 
void ast_concatenation_describe(FILE *out, struct ast_concatenation *this);
// 
void ast_concatenation_action(FILE *out, struct ast_concatenation *this);



// 
struct ast_constant_concatenation {
    ast_type                        type;
};
// 
void ast_constant_concatenation_describe(FILE *out, struct ast_constant_concatenation *this);
// 
void ast_constant_concatenation_action(FILE *out, struct ast_constant_concatenation *this);



// 
struct ast_constant_multiple_concatenation {
    ast_type                        type;
};
// 
void ast_constant_multiple_concatenation_describe(FILE *out, struct ast_constant_multiple_concatenation *this);
// 
void ast_constant_multiple_concatenation_action(FILE *out, struct ast_constant_multiple_concatenation *this);



// 
struct ast_module_path_concatenation {
    ast_type                        type;
};
// 
void ast_module_path_concatenation_describe(FILE *out, struct ast_module_path_concatenation *this);
// 
void ast_module_path_concatenation_action(FILE *out, struct ast_module_path_concatenation *this);



// 
struct ast_module_path_multiple_concatenation {
    ast_type                        type;
};
// 
void ast_module_path_multiple_concatenation_describe(FILE *out, struct ast_module_path_multiple_concatenation *this);
// 
void ast_module_path_multiple_concatenation_action(FILE *out, struct ast_module_path_multiple_concatenation *this);



// 
struct ast_multiple_concatenation {
    ast_type                        type;
};
// 
void ast_multiple_concatenation_describe(FILE *out, struct ast_multiple_concatenation *this);
// 
void ast_multiple_concatenation_action(FILE *out, struct ast_multiple_concatenation *this);



// 
struct ast_streaming_concatenation {
    ast_type                        type;
};
// 
void ast_streaming_concatenation_describe(FILE *out, struct ast_streaming_concatenation *this);
// 
void ast_streaming_concatenation_action(FILE *out, struct ast_streaming_concatenation *this);



// 
struct ast_stream_operator {
    ast_type                        type;
};
// 
void ast_stream_operator_describe(FILE *out, struct ast_stream_operator *this);
// 
void ast_stream_operator_action(FILE *out, struct ast_stream_operator *this);



// 
struct ast_slice_size {
    ast_type                        type;
};
// 
void ast_slice_size_describe(FILE *out, struct ast_slice_size *this);
// 
void ast_slice_size_action(FILE *out, struct ast_slice_size *this);



// 
struct ast_stream_concatenation {
    ast_type                        type;
};
// 
void ast_stream_concatenation_describe(FILE *out, struct ast_stream_concatenation *this);
// 
void ast_stream_concatenation_action(FILE *out, struct ast_stream_concatenation *this);



// 
struct ast_stream_expression {
    ast_type                        type;
};
// 
void ast_stream_expression_describe(FILE *out, struct ast_stream_expression *this);
// 
void ast_stream_expression_action(FILE *out, struct ast_stream_expression *this);



// 
struct ast_array_range_expression {
    ast_type                        type;
};
// 
void ast_array_range_expression_describe(FILE *out, struct ast_array_range_expression *this);
// 
void ast_array_range_expression_action(FILE *out, struct ast_array_range_expression *this);



// 
struct ast_empty_queue {
    ast_type                        type;
};
// 
void ast_empty_queue_describe(FILE *out, struct ast_empty_queue *this);
// 
void ast_empty_queue_action(FILE *out, struct ast_empty_queue *this);



// 
struct ast_constant_function_call {
    ast_type                        type;
};
// 
void ast_constant_function_call_describe(FILE *out, struct ast_constant_function_call *this);
// 
void ast_constant_function_call_action(FILE *out, struct ast_constant_function_call *this);



// 
struct ast_tf_call {
    ast_type                        type;
};
// 
void ast_tf_call_describe(FILE *out, struct ast_tf_call *this);
// 
void ast_tf_call_action(FILE *out, struct ast_tf_call *this);



// 
struct ast_system_tf_call {
    ast_type                        type;
};
// 
void ast_system_tf_call_describe(FILE *out, struct ast_system_tf_call *this);
// 
void ast_system_tf_call_action(FILE *out, struct ast_system_tf_call *this);



// 
struct ast_subroutine_call {
    ast_type                        type;
};
// 
void ast_subroutine_call_describe(FILE *out, struct ast_subroutine_call *this);
// 
void ast_subroutine_call_action(FILE *out, struct ast_subroutine_call *this);



// 
struct ast_function_subroutine_call {
    ast_type                        type;
};
// 
void ast_function_subroutine_call_describe(FILE *out, struct ast_function_subroutine_call *this);
// 
void ast_function_subroutine_call_action(FILE *out, struct ast_function_subroutine_call *this);



// 
struct ast_list_of_arguments {
    ast_type                        type;
};
// 
void ast_list_of_arguments_describe(FILE *out, struct ast_list_of_arguments *this);
// 
void ast_list_of_arguments_action(FILE *out, struct ast_list_of_arguments *this);



// 
struct ast_method_call {
    ast_type                        type;
};
// 
void ast_method_call_describe(FILE *out, struct ast_method_call *this);
// 
void ast_method_call_action(FILE *out, struct ast_method_call *this);



// 
struct ast_method_call_body {
    ast_type                        type;
};
// 
void ast_method_call_body_describe(FILE *out, struct ast_method_call_body *this);
// 
void ast_method_call_body_action(FILE *out, struct ast_method_call_body *this);



// 
struct ast_built_in_method_call {
    ast_type                        type;
};
// 
void ast_built_in_method_call_describe(FILE *out, struct ast_built_in_method_call *this);
// 
void ast_built_in_method_call_action(FILE *out, struct ast_built_in_method_call *this);



// 
struct ast_array_manipulation_call {
    ast_type                        type;
};
// 
void ast_array_manipulation_call_describe(FILE *out, struct ast_array_manipulation_call *this);
// 
void ast_array_manipulation_call_action(FILE *out, struct ast_array_manipulation_call *this);



// 
struct ast_randomize_call {
    ast_type                        type;
};
// 
void ast_randomize_call_describe(FILE *out, struct ast_randomize_call *this);
// 
void ast_randomize_call_action(FILE *out, struct ast_randomize_call *this);



// 
struct ast_method_call_root {
    ast_type                        type;
};
// 
void ast_method_call_root_describe(FILE *out, struct ast_method_call_root *this);
// 
void ast_method_call_root_action(FILE *out, struct ast_method_call_root *this);



// 
struct ast_array_method_name {
    ast_type                        type;
};
// 
void ast_array_method_name_describe(FILE *out, struct ast_array_method_name *this);
// 
void ast_array_method_name_action(FILE *out, struct ast_array_method_name *this);



// 
struct ast_inc_or_dec_expression {
    ast_type                        type;
};
// 
void ast_inc_or_dec_expression_describe(FILE *out, struct ast_inc_or_dec_expression *this);
// 
void ast_inc_or_dec_expression_action(FILE *out, struct ast_inc_or_dec_expression *this);



// 
struct ast_conditional_expression {
    ast_type                        type;
};
// 
void ast_conditional_expression_describe(FILE *out, struct ast_conditional_expression *this);
// 
void ast_conditional_expression_action(FILE *out, struct ast_conditional_expression *this);



// 
struct ast_constant_expression {
    ast_type                        type;
};
// 
void ast_constant_expression_describe(FILE *out, struct ast_constant_expression *this);
// 
void ast_constant_expression_action(FILE *out, struct ast_constant_expression *this);



// 
struct ast_constant_mintypmax_expression {
    ast_type                        type;
};
// 
void ast_constant_mintypmax_expression_describe(FILE *out, struct ast_constant_mintypmax_expression *this);
// 
void ast_constant_mintypmax_expression_action(FILE *out, struct ast_constant_mintypmax_expression *this);



// 
struct ast_constant_param_expression {
    ast_type                        type;
};
// 
void ast_constant_param_expression_describe(FILE *out, struct ast_constant_param_expression *this);
// 
void ast_constant_param_expression_action(FILE *out, struct ast_constant_param_expression *this);



// 
struct ast_param_expression {
    ast_type                        type;
};
// 
void ast_param_expression_describe(FILE *out, struct ast_param_expression *this);
// 
void ast_param_expression_action(FILE *out, struct ast_param_expression *this);



// 
struct ast_constant_range_expression {
    ast_type                        type;
};
// 
void ast_constant_range_expression_describe(FILE *out, struct ast_constant_range_expression *this);
// 
void ast_constant_range_expression_action(FILE *out, struct ast_constant_range_expression *this);



// 
struct ast_constant_part_select_range {
    ast_type                        type;
};
// 
void ast_constant_part_select_range_describe(FILE *out, struct ast_constant_part_select_range *this);
// 
void ast_constant_part_select_range_action(FILE *out, struct ast_constant_part_select_range *this);



// 
struct ast_constant_range {
    ast_type                        type;
};
// 
void ast_constant_range_describe(FILE *out, struct ast_constant_range *this);
// 
void ast_constant_range_action(FILE *out, struct ast_constant_range *this);



// 
struct ast_constant_indexed_range {
    ast_type                        type;
};
// 
void ast_constant_indexed_range_describe(FILE *out, struct ast_constant_indexed_range *this);
// 
void ast_constant_indexed_range_action(FILE *out, struct ast_constant_indexed_range *this);



// 
struct ast_expression {
    ast_type                        type;
};
// 
void ast_expression_describe(FILE *out, struct ast_expression *this);
// 
void ast_expression_action(FILE *out, struct ast_expression *this);



// 
struct ast_tagged_union_expression {
    ast_type                        type;
};
// 
void ast_tagged_union_expression_describe(FILE *out, struct ast_tagged_union_expression *this);
// 
void ast_tagged_union_expression_action(FILE *out, struct ast_tagged_union_expression *this);



// 
struct ast_inside_expression {
    ast_type                        type;
};
// 
void ast_inside_expression_describe(FILE *out, struct ast_inside_expression *this);
// 
void ast_inside_expression_action(FILE *out, struct ast_inside_expression *this);



// 
struct ast_value_range {
    ast_type                        type;
};
// 
void ast_value_range_describe(FILE *out, struct ast_value_range *this);
// 
void ast_value_range_action(FILE *out, struct ast_value_range *this);



// 
struct ast_mintypmax_expression {
    ast_type                        type;
};
// 
void ast_mintypmax_expression_describe(FILE *out, struct ast_mintypmax_expression *this);
// 
void ast_mintypmax_expression_action(FILE *out, struct ast_mintypmax_expression *this);



// 
struct ast_module_path_conditional_expression {
    ast_type                        type;
};
// 
void ast_module_path_conditional_expression_describe(FILE *out, struct ast_module_path_conditional_expression *this);
// 
void ast_module_path_conditional_expression_action(FILE *out, struct ast_module_path_conditional_expression *this);



// 
struct ast_module_path_expression {
    ast_type                        type;
};
// 
void ast_module_path_expression_describe(FILE *out, struct ast_module_path_expression *this);
// 
void ast_module_path_expression_action(FILE *out, struct ast_module_path_expression *this);



// 
struct ast_module_path_mintypmax_expression {
    ast_type                        type;
};
// 
void ast_module_path_mintypmax_expression_describe(FILE *out, struct ast_module_path_mintypmax_expression *this);
// 
void ast_module_path_mintypmax_expression_action(FILE *out, struct ast_module_path_mintypmax_expression *this);



// 
struct ast_part_select_range {
    ast_type                        type;
};
// 
void ast_part_select_range_describe(FILE *out, struct ast_part_select_range *this);
// 
void ast_part_select_range_action(FILE *out, struct ast_part_select_range *this);



// 
struct ast_indexed_range {
    ast_type                        type;
};
// 
void ast_indexed_range_describe(FILE *out, struct ast_indexed_range *this);
// 
void ast_indexed_range_action(FILE *out, struct ast_indexed_range *this);



// 
struct ast_genvar_expression {
    ast_type                        type;
};
// 
void ast_genvar_expression_describe(FILE *out, struct ast_genvar_expression *this);
// 
void ast_genvar_expression_action(FILE *out, struct ast_genvar_expression *this);



// 
struct ast_constant_primary {
    ast_type                        type;
};
// 
void ast_constant_primary_describe(FILE *out, struct ast_constant_primary *this);
// 
void ast_constant_primary_action(FILE *out, struct ast_constant_primary *this);



// 
struct ast_module_path_primary {
    ast_type                        type;
};
// 
void ast_module_path_primary_describe(FILE *out, struct ast_module_path_primary *this);
// 
void ast_module_path_primary_action(FILE *out, struct ast_module_path_primary *this);



// 
struct ast_primary {
    ast_type                        type;
};
// 
void ast_primary_describe(FILE *out, struct ast_primary *this);
// 
void ast_primary_action(FILE *out, struct ast_primary *this);



// 
struct ast_class_qualifier {
    ast_type                        type;
};
// 
void ast_class_qualifier_describe(FILE *out, struct ast_class_qualifier *this);
// 
void ast_class_qualifier_action(FILE *out, struct ast_class_qualifier *this);



// 
struct ast_range_expression {
    ast_type                        type;
};
// 
void ast_range_expression_describe(FILE *out, struct ast_range_expression *this);
// 
void ast_range_expression_action(FILE *out, struct ast_range_expression *this);



// 
struct ast_primary_literal {
    ast_type                        type;
};
// 
void ast_primary_literal_describe(FILE *out, struct ast_primary_literal *this);
// 
void ast_primary_literal_action(FILE *out, struct ast_primary_literal *this);



// 
struct ast_time_literal {
    ast_type                        type;
};
// 
void ast_time_literal_describe(FILE *out, struct ast_time_literal *this);
// 
void ast_time_literal_action(FILE *out, struct ast_time_literal *this);



// 
struct ast_time_unit {
    ast_type                        type;
};
// 
void ast_time_unit_describe(FILE *out, struct ast_time_unit *this);
// 
void ast_time_unit_action(FILE *out, struct ast_time_unit *this);



// 
struct ast_implicit_class_handle {
    ast_type                        type;
};
// 
void ast_implicit_class_handle_describe(FILE *out, struct ast_implicit_class_handle *this);
// 
void ast_implicit_class_handle_action(FILE *out, struct ast_implicit_class_handle *this);



// 
struct ast_bit_select {
    ast_type                        type;
};
// 
void ast_bit_select_describe(FILE *out, struct ast_bit_select *this);
// 
void ast_bit_select_action(FILE *out, struct ast_bit_select *this);



// 
struct ast_select {
    ast_type                        type;
};
// 
void ast_select_describe(FILE *out, struct ast_select *this);
// 
void ast_select_action(FILE *out, struct ast_select *this);



// 
struct ast_nonrange_select {
    ast_type                        type;
};
// 
void ast_nonrange_select_describe(FILE *out, struct ast_nonrange_select *this);
// 
void ast_nonrange_select_action(FILE *out, struct ast_nonrange_select *this);



// 
struct ast_constant_bit_select {
    ast_type                        type;
};
// 
void ast_constant_bit_select_describe(FILE *out, struct ast_constant_bit_select *this);
// 
void ast_constant_bit_select_action(FILE *out, struct ast_constant_bit_select *this);



// 
struct ast_constant_select {
    ast_type                        type;
};
// 
void ast_constant_select_describe(FILE *out, struct ast_constant_select *this);
// 
void ast_constant_select_action(FILE *out, struct ast_constant_select *this);



// 
struct ast_constant_cast {
    ast_type                        type;
};
// 
void ast_constant_cast_describe(FILE *out, struct ast_constant_cast *this);
// 
void ast_constant_cast_action(FILE *out, struct ast_constant_cast *this);



// 
struct ast_constant_let_expression {
    ast_type                        type;
};
// 
void ast_constant_let_expression_describe(FILE *out, struct ast_constant_let_expression *this);
// 
void ast_constant_let_expression_action(FILE *out, struct ast_constant_let_expression *this);



// 
struct ast_cast {
    ast_type                        type;
};
// 
void ast_cast_describe(FILE *out, struct ast_cast *this);
// 
void ast_cast_action(FILE *out, struct ast_cast *this);



// 
struct ast_net_lvalue {
    ast_type                        type;
};
// 
void ast_net_lvalue_describe(FILE *out, struct ast_net_lvalue *this);
// 
void ast_net_lvalue_action(FILE *out, struct ast_net_lvalue *this);



// 
struct ast_variable_lvalue {
    ast_type                        type;
};
// 
void ast_variable_lvalue_describe(FILE *out, struct ast_variable_lvalue *this);
// 
void ast_variable_lvalue_action(FILE *out, struct ast_variable_lvalue *this);



// 
struct ast_nonrange_variable_lvalue {
    ast_type                        type;
};
// 
void ast_nonrange_variable_lvalue_describe(FILE *out, struct ast_nonrange_variable_lvalue *this);
// 
void ast_nonrange_variable_lvalue_action(FILE *out, struct ast_nonrange_variable_lvalue *this);



// 
struct ast_unary_operator {
    ast_type                        type;
};
// 
void ast_unary_operator_describe(FILE *out, struct ast_unary_operator *this);
// 
void ast_unary_operator_action(FILE *out, struct ast_unary_operator *this);



// 
struct ast_binary_operator {
    ast_type                        type;
};
// 
void ast_binary_operator_describe(FILE *out, struct ast_binary_operator *this);
// 
void ast_binary_operator_action(FILE *out, struct ast_binary_operator *this);



// 
struct ast_inc_or_dec_operator {
    ast_type                        type;
};
// 
void ast_inc_or_dec_operator_describe(FILE *out, struct ast_inc_or_dec_operator *this);
// 
void ast_inc_or_dec_operator_action(FILE *out, struct ast_inc_or_dec_operator *this);



// 
struct ast_unary_module_path_operator {
    ast_type                        type;
};
// 
void ast_unary_module_path_operator_describe(FILE *out, struct ast_unary_module_path_operator *this);
// 
void ast_unary_module_path_operator_action(FILE *out, struct ast_unary_module_path_operator *this);



// 
struct ast_binary_module_path_operator {
    ast_type                        type;
};
// 
void ast_binary_module_path_operator_describe(FILE *out, struct ast_binary_module_path_operator *this);
// 
void ast_binary_module_path_operator_action(FILE *out, struct ast_binary_module_path_operator *this);



// 
struct ast_number {
    ast_type                        type;
};
// 
void ast_number_describe(FILE *out, struct ast_number *this);
// 
void ast_number_action(FILE *out, struct ast_number *this);



// 
struct ast_integral_number {
    ast_type                        type;
};
// 
void ast_integral_number_describe(FILE *out, struct ast_integral_number *this);
// 
void ast_integral_number_action(FILE *out, struct ast_integral_number *this);



// 
struct ast_decimal_number {
    ast_type                        type;
};
// 
void ast_decimal_number_describe(FILE *out, struct ast_decimal_number *this);
// 
void ast_decimal_number_action(FILE *out, struct ast_decimal_number *this);



// 
struct ast_binary_number {
    ast_type                        type;
};
// 
void ast_binary_number_describe(FILE *out, struct ast_binary_number *this);
// 
void ast_binary_number_action(FILE *out, struct ast_binary_number *this);



// 
struct ast_octal_number {
    ast_type                        type;
};
// 
void ast_octal_number_describe(FILE *out, struct ast_octal_number *this);
// 
void ast_octal_number_action(FILE *out, struct ast_octal_number *this);



// 
struct ast_hex_number {
    ast_type                        type;
};
// 
void ast_hex_number_describe(FILE *out, struct ast_hex_number *this);
// 
void ast_hex_number_action(FILE *out, struct ast_hex_number *this);



// 
struct ast_sign {
    ast_type                        type;
};
// 
void ast_sign_describe(FILE *out, struct ast_sign *this);
// 
void ast_sign_action(FILE *out, struct ast_sign *this);



// 
struct ast_size {
    ast_type                        type;
};
// 
void ast_size_describe(FILE *out, struct ast_size *this);
// 
void ast_size_action(FILE *out, struct ast_size *this);



// 
struct ast_non_zero_unsigned_number {
    ast_type                        type;
};
// 
void ast_non_zero_unsigned_number_describe(FILE *out, struct ast_non_zero_unsigned_number *this);
// 
void ast_non_zero_unsigned_number_action(FILE *out, struct ast_non_zero_unsigned_number *this);



// 
struct ast_real_number {
    ast_type                        type;
};
// 
void ast_real_number_describe(FILE *out, struct ast_real_number *this);
// 
void ast_real_number_action(FILE *out, struct ast_real_number *this);



// 
struct ast_fixed_point_number {
    ast_type                        type;
};
// 
void ast_fixed_point_number_describe(FILE *out, struct ast_fixed_point_number *this);
// 
void ast_fixed_point_number_action(FILE *out, struct ast_fixed_point_number *this);



// 
struct ast_exp {
    ast_type                        type;
};
// 
void ast_exp_describe(FILE *out, struct ast_exp *this);
// 
void ast_exp_action(FILE *out, struct ast_exp *this);



// 
struct ast_unsigned_number {
    ast_type                        type;
};
// 
void ast_unsigned_number_describe(FILE *out, struct ast_unsigned_number *this);
// 
void ast_unsigned_number_action(FILE *out, struct ast_unsigned_number *this);



// 
struct ast_binary_value {
    ast_type                        type;
};
// 
void ast_binary_value_describe(FILE *out, struct ast_binary_value *this);
// 
void ast_binary_value_action(FILE *out, struct ast_binary_value *this);



// 
struct ast_octal_value {
    ast_type                        type;
};
// 
void ast_octal_value_describe(FILE *out, struct ast_octal_value *this);
// 
void ast_octal_value_action(FILE *out, struct ast_octal_value *this);



// 
struct ast_hex_value {
    ast_type                        type;
};
// 
void ast_hex_value_describe(FILE *out, struct ast_hex_value *this);
// 
void ast_hex_value_action(FILE *out, struct ast_hex_value *this);



// 
struct ast_decimal_base {
    ast_type                        type;
};
// 
void ast_decimal_base_describe(FILE *out, struct ast_decimal_base *this);
// 
void ast_decimal_base_action(FILE *out, struct ast_decimal_base *this);



// 
struct ast_binary_base {
    ast_type                        type;
};
// 
void ast_binary_base_describe(FILE *out, struct ast_binary_base *this);
// 
void ast_binary_base_action(FILE *out, struct ast_binary_base *this);



// 
struct ast_octal_base {
    ast_type                        type;
};
// 
void ast_octal_base_describe(FILE *out, struct ast_octal_base *this);
// 
void ast_octal_base_action(FILE *out, struct ast_octal_base *this);



// 
struct ast_hex_base {
    ast_type                        type;
};
// 
void ast_hex_base_describe(FILE *out, struct ast_hex_base *this);
// 
void ast_hex_base_action(FILE *out, struct ast_hex_base *this);



// 
struct ast_non_zero_decimal_digit {
    ast_type                        type;
};
// 
void ast_non_zero_decimal_digit_describe(FILE *out, struct ast_non_zero_decimal_digit *this);
// 
void ast_non_zero_decimal_digit_action(FILE *out, struct ast_non_zero_decimal_digit *this);



// 
struct ast_decimal_digit {
    ast_type                        type;
};
// 
void ast_decimal_digit_describe(FILE *out, struct ast_decimal_digit *this);
// 
void ast_decimal_digit_action(FILE *out, struct ast_decimal_digit *this);



// 
struct ast_binary_digit {
    ast_type                        type;
};
// 
void ast_binary_digit_describe(FILE *out, struct ast_binary_digit *this);
// 
void ast_binary_digit_action(FILE *out, struct ast_binary_digit *this);



// 
struct ast_octal_digit {
    ast_type                        type;
};
// 
void ast_octal_digit_describe(FILE *out, struct ast_octal_digit *this);
// 
void ast_octal_digit_action(FILE *out, struct ast_octal_digit *this);



// 
struct ast_hex_digit {
    ast_type                        type;
};
// 
void ast_hex_digit_describe(FILE *out, struct ast_hex_digit *this);
// 
void ast_hex_digit_action(FILE *out, struct ast_hex_digit *this);



// 
struct ast_x_digit {
    ast_type                        type;
};
// 
void ast_x_digit_describe(FILE *out, struct ast_x_digit *this);
// 
void ast_x_digit_action(FILE *out, struct ast_x_digit *this);



// 
struct ast_z_digit {
    ast_type                        type;
};
// 
void ast_z_digit_describe(FILE *out, struct ast_z_digit *this);
// 
void ast_z_digit_action(FILE *out, struct ast_z_digit *this);



// 
struct ast_unbased_unsized_literal {
    ast_type                        type;
};
// 
void ast_unbased_unsized_literal_describe(FILE *out, struct ast_unbased_unsized_literal *this);
// 
void ast_unbased_unsized_literal_action(FILE *out, struct ast_unbased_unsized_literal *this);



// 
struct ast_string_literal {
    ast_type                        type;
};
// 
void ast_string_literal_describe(FILE *out, struct ast_string_literal *this);
// 
void ast_string_literal_action(FILE *out, struct ast_string_literal *this);



// 
struct ast_attribute_instance {
    ast_type                        type;
};
// 
void ast_attribute_instance_describe(FILE *out, struct ast_attribute_instance *this);
// 
void ast_attribute_instance_action(FILE *out, struct ast_attribute_instance *this);



// 
struct ast_attr_spec {
    ast_type                        type;
};
// 
void ast_attr_spec_describe(FILE *out, struct ast_attr_spec *this);
// 
void ast_attr_spec_action(FILE *out, struct ast_attr_spec *this);



// 
struct ast_attr_name {
    ast_type                        type;
};
// 
void ast_attr_name_describe(FILE *out, struct ast_attr_name *this);
// 
void ast_attr_name_action(FILE *out, struct ast_attr_name *this);



// 
struct ast_comment {
    ast_type                        type;
};
// 
void ast_comment_describe(FILE *out, struct ast_comment *this);
// 
void ast_comment_action(FILE *out, struct ast_comment *this);



// 
struct ast_one_line_comment {
    ast_type                        type;
};
// 
void ast_one_line_comment_describe(FILE *out, struct ast_one_line_comment *this);
// 
void ast_one_line_comment_action(FILE *out, struct ast_one_line_comment *this);



// 
struct ast_block_comment {
    ast_type                        type;
};
// 
void ast_block_comment_describe(FILE *out, struct ast_block_comment *this);
// 
void ast_block_comment_action(FILE *out, struct ast_block_comment *this);



// 
struct ast_comment_text {
    ast_type                        type;
};
// 
void ast_comment_text_describe(FILE *out, struct ast_comment_text *this);
// 
void ast_comment_text_action(FILE *out, struct ast_comment_text *this);



// 
struct ast_array_identifier {
    ast_type                        type;
};
// 
void ast_array_identifier_describe(FILE *out, struct ast_array_identifier *this);
// 
void ast_array_identifier_action(FILE *out, struct ast_array_identifier *this);



// 
struct ast_block_identifier {
    ast_type                        type;
};
// 
void ast_block_identifier_describe(FILE *out, struct ast_block_identifier *this);
// 
void ast_block_identifier_action(FILE *out, struct ast_block_identifier *this);



// 
struct ast_bin_identifier {
    ast_type                        type;
};
// 
void ast_bin_identifier_describe(FILE *out, struct ast_bin_identifier *this);
// 
void ast_bin_identifier_action(FILE *out, struct ast_bin_identifier *this);



// 
struct ast_c_identifier {
    ast_type                        type;
};
// 
void ast_c_identifier_describe(FILE *out, struct ast_c_identifier *this);
// 
void ast_c_identifier_action(FILE *out, struct ast_c_identifier *this);



// 
struct ast_cell_identifier {
    ast_type                        type;
};
// 
void ast_cell_identifier_describe(FILE *out, struct ast_cell_identifier *this);
// 
void ast_cell_identifier_action(FILE *out, struct ast_cell_identifier *this);



// 
struct ast_checker_identifier {
    ast_type                        type;
};
// 
void ast_checker_identifier_describe(FILE *out, struct ast_checker_identifier *this);
// 
void ast_checker_identifier_action(FILE *out, struct ast_checker_identifier *this);



// 
struct ast_class_identifier {
    ast_type                        type;
};
// 
void ast_class_identifier_describe(FILE *out, struct ast_class_identifier *this);
// 
void ast_class_identifier_action(FILE *out, struct ast_class_identifier *this);



// 
struct ast_class_variable_identifier {
    ast_type                        type;
};
// 
void ast_class_variable_identifier_describe(FILE *out, struct ast_class_variable_identifier *this);
// 
void ast_class_variable_identifier_action(FILE *out, struct ast_class_variable_identifier *this);



// 
struct ast_clocking_identifier {
    ast_type                        type;
};
// 
void ast_clocking_identifier_describe(FILE *out, struct ast_clocking_identifier *this);
// 
void ast_clocking_identifier_action(FILE *out, struct ast_clocking_identifier *this);



// 
struct ast_config_identifier {
    ast_type                        type;
};
// 
void ast_config_identifier_describe(FILE *out, struct ast_config_identifier *this);
// 
void ast_config_identifier_action(FILE *out, struct ast_config_identifier *this);



// 
struct ast_const_identifier {
    ast_type                        type;
};
// 
void ast_const_identifier_describe(FILE *out, struct ast_const_identifier *this);
// 
void ast_const_identifier_action(FILE *out, struct ast_const_identifier *this);



// 
struct ast_constraint_identifier {
    ast_type                        type;
};
// 
void ast_constraint_identifier_describe(FILE *out, struct ast_constraint_identifier *this);
// 
void ast_constraint_identifier_action(FILE *out, struct ast_constraint_identifier *this);



// 
struct ast_covergroup_identifier {
    ast_type                        type;
};
// 
void ast_covergroup_identifier_describe(FILE *out, struct ast_covergroup_identifier *this);
// 
void ast_covergroup_identifier_action(FILE *out, struct ast_covergroup_identifier *this);



// 
struct ast_covergroup_variable_identifier {
    ast_type                        type;
};
// 
void ast_covergroup_variable_identifier_describe(FILE *out, struct ast_covergroup_variable_identifier *this);
// 
void ast_covergroup_variable_identifier_action(FILE *out, struct ast_covergroup_variable_identifier *this);



// 
struct ast_cover_point_identifier {
    ast_type                        type;
};
// 
void ast_cover_point_identifier_describe(FILE *out, struct ast_cover_point_identifier *this);
// 
void ast_cover_point_identifier_action(FILE *out, struct ast_cover_point_identifier *this);



// 
struct ast_cross_identifier {
    ast_type                        type;
};
// 
void ast_cross_identifier_describe(FILE *out, struct ast_cross_identifier *this);
// 
void ast_cross_identifier_action(FILE *out, struct ast_cross_identifier *this);



// 
struct ast_dynamic_array_variable_identifier {
    ast_type                        type;
};
// 
void ast_dynamic_array_variable_identifier_describe(FILE *out, struct ast_dynamic_array_variable_identifier *this);
// 
void ast_dynamic_array_variable_identifier_action(FILE *out, struct ast_dynamic_array_variable_identifier *this);



// 
struct ast_enum_identifier {
    ast_type                        type;
};
// 
void ast_enum_identifier_describe(FILE *out, struct ast_enum_identifier *this);
// 
void ast_enum_identifier_action(FILE *out, struct ast_enum_identifier *this);



// 
struct ast_escaped_identifier {
    ast_type                        type;
};
// 
void ast_escaped_identifier_describe(FILE *out, struct ast_escaped_identifier *this);
// 
void ast_escaped_identifier_action(FILE *out, struct ast_escaped_identifier *this);



// 
struct ast_formal_identifier {
    ast_type                        type;
};
// 
void ast_formal_identifier_describe(FILE *out, struct ast_formal_identifier *this);
// 
void ast_formal_identifier_action(FILE *out, struct ast_formal_identifier *this);



// 
struct ast_formal_port_identifier {
    ast_type                        type;
};
// 
void ast_formal_port_identifier_describe(FILE *out, struct ast_formal_port_identifier *this);
// 
void ast_formal_port_identifier_action(FILE *out, struct ast_formal_port_identifier *this);



// 
struct ast_function_identifier {
    ast_type                        type;
};
// 
void ast_function_identifier_describe(FILE *out, struct ast_function_identifier *this);
// 
void ast_function_identifier_action(FILE *out, struct ast_function_identifier *this);



// 
struct ast_generate_block_identifier {
    ast_type                        type;
};
// 
void ast_generate_block_identifier_describe(FILE *out, struct ast_generate_block_identifier *this);
// 
void ast_generate_block_identifier_action(FILE *out, struct ast_generate_block_identifier *this);



// 
struct ast_genvar_identifier {
    ast_type                        type;
};
// 
void ast_genvar_identifier_describe(FILE *out, struct ast_genvar_identifier *this);
// 
void ast_genvar_identifier_action(FILE *out, struct ast_genvar_identifier *this);



// 
struct ast_hierarchical_array_identifier {
    ast_type                        type;
};
// 
void ast_hierarchical_array_identifier_describe(FILE *out, struct ast_hierarchical_array_identifier *this);
// 
void ast_hierarchical_array_identifier_action(FILE *out, struct ast_hierarchical_array_identifier *this);



// 
struct ast_hierarchical_block_identifier {
    ast_type                        type;
};
// 
void ast_hierarchical_block_identifier_describe(FILE *out, struct ast_hierarchical_block_identifier *this);
// 
void ast_hierarchical_block_identifier_action(FILE *out, struct ast_hierarchical_block_identifier *this);



// 
struct ast_hierarchical_event_identifier {
    ast_type                        type;
};
// 
void ast_hierarchical_event_identifier_describe(FILE *out, struct ast_hierarchical_event_identifier *this);
// 
void ast_hierarchical_event_identifier_action(FILE *out, struct ast_hierarchical_event_identifier *this);



// 
struct ast_hierarchical_identifier {
    ast_type                        type;
};
// 
void ast_hierarchical_identifier_describe(FILE *out, struct ast_hierarchical_identifier *this);
// 
void ast_hierarchical_identifier_action(FILE *out, struct ast_hierarchical_identifier *this);



// 
struct ast_hierarchical_net_identifier {
    ast_type                        type;
};
// 
void ast_hierarchical_net_identifier_describe(FILE *out, struct ast_hierarchical_net_identifier *this);
// 
void ast_hierarchical_net_identifier_action(FILE *out, struct ast_hierarchical_net_identifier *this);



// 
struct ast_hierarchical_parameter_identifier {
    ast_type                        type;
};
// 
void ast_hierarchical_parameter_identifier_describe(FILE *out, struct ast_hierarchical_parameter_identifier *this);
// 
void ast_hierarchical_parameter_identifier_action(FILE *out, struct ast_hierarchical_parameter_identifier *this);



// 
struct ast_hierarchical_property_identifier {
    ast_type                        type;
};
// 
void ast_hierarchical_property_identifier_describe(FILE *out, struct ast_hierarchical_property_identifier *this);
// 
void ast_hierarchical_property_identifier_action(FILE *out, struct ast_hierarchical_property_identifier *this);



// 
struct ast_hierarchical_sequence_identifier {
    ast_type                        type;
};
// 
void ast_hierarchical_sequence_identifier_describe(FILE *out, struct ast_hierarchical_sequence_identifier *this);
// 
void ast_hierarchical_sequence_identifier_action(FILE *out, struct ast_hierarchical_sequence_identifier *this);



// 
struct ast_hierarchical_task_identifier {
    ast_type                        type;
};
// 
void ast_hierarchical_task_identifier_describe(FILE *out, struct ast_hierarchical_task_identifier *this);
// 
void ast_hierarchical_task_identifier_action(FILE *out, struct ast_hierarchical_task_identifier *this);



// 
struct ast_hierarchical_tf_identifier {
    ast_type                        type;
};
// 
void ast_hierarchical_tf_identifier_describe(FILE *out, struct ast_hierarchical_tf_identifier *this);
// 
void ast_hierarchical_tf_identifier_action(FILE *out, struct ast_hierarchical_tf_identifier *this);



// 
struct ast_hierarchical_variable_identifier {
    ast_type                        type;
};
// 
void ast_hierarchical_variable_identifier_describe(FILE *out, struct ast_hierarchical_variable_identifier *this);
// 
void ast_hierarchical_variable_identifier_action(FILE *out, struct ast_hierarchical_variable_identifier *this);



// 
struct ast_identifier {
    ast_type                        type;
};
// 
void ast_identifier_describe(FILE *out, struct ast_identifier *this);
// 
void ast_identifier_action(FILE *out, struct ast_identifier *this);



// 
struct ast_index_variable_identifier {
    ast_type                        type;
};
// 
void ast_index_variable_identifier_describe(FILE *out, struct ast_index_variable_identifier *this);
// 
void ast_index_variable_identifier_action(FILE *out, struct ast_index_variable_identifier *this);



// 
struct ast_interface_identifier {
    ast_type                        type;
};
// 
void ast_interface_identifier_describe(FILE *out, struct ast_interface_identifier *this);
// 
void ast_interface_identifier_action(FILE *out, struct ast_interface_identifier *this);



// 
struct ast_interface_instance_identifier {
    ast_type                        type;
};
// 
void ast_interface_instance_identifier_describe(FILE *out, struct ast_interface_instance_identifier *this);
// 
void ast_interface_instance_identifier_action(FILE *out, struct ast_interface_instance_identifier *this);



// 
struct ast_inout_port_identifier {
    ast_type                        type;
};
// 
void ast_inout_port_identifier_describe(FILE *out, struct ast_inout_port_identifier *this);
// 
void ast_inout_port_identifier_action(FILE *out, struct ast_inout_port_identifier *this);



// 
struct ast_input_port_identifier {
    ast_type                        type;
};
// 
void ast_input_port_identifier_describe(FILE *out, struct ast_input_port_identifier *this);
// 
void ast_input_port_identifier_action(FILE *out, struct ast_input_port_identifier *this);



// 
struct ast_instance_identifier {
    ast_type                        type;
};
// 
void ast_instance_identifier_describe(FILE *out, struct ast_instance_identifier *this);
// 
void ast_instance_identifier_action(FILE *out, struct ast_instance_identifier *this);



// 
struct ast_library_identifier {
    ast_type                        type;
};
// 
void ast_library_identifier_describe(FILE *out, struct ast_library_identifier *this);
// 
void ast_library_identifier_action(FILE *out, struct ast_library_identifier *this);



// 
struct ast_member_identifier {
    ast_type                        type;
};
// 
void ast_member_identifier_describe(FILE *out, struct ast_member_identifier *this);
// 
void ast_member_identifier_action(FILE *out, struct ast_member_identifier *this);



// 
struct ast_method_identifier {
    ast_type                        type;
};
// 
void ast_method_identifier_describe(FILE *out, struct ast_method_identifier *this);
// 
void ast_method_identifier_action(FILE *out, struct ast_method_identifier *this);



// 
struct ast_modport_identifier {
    ast_type                        type;
};
// 
void ast_modport_identifier_describe(FILE *out, struct ast_modport_identifier *this);
// 
void ast_modport_identifier_action(FILE *out, struct ast_modport_identifier *this);



// 
struct ast_module_identifier {
    ast_type                        type;
};
// 
void ast_module_identifier_describe(FILE *out, struct ast_module_identifier *this);
// 
void ast_module_identifier_action(FILE *out, struct ast_module_identifier *this);



// 
struct ast_net_identifier {
    ast_type                        type;
};
// 
void ast_net_identifier_describe(FILE *out, struct ast_net_identifier *this);
// 
void ast_net_identifier_action(FILE *out, struct ast_net_identifier *this);



// 
struct ast_net_type_identifier {
    ast_type                        type;
};
// 
void ast_net_type_identifier_describe(FILE *out, struct ast_net_type_identifier *this);
// 
void ast_net_type_identifier_action(FILE *out, struct ast_net_type_identifier *this);



// 
struct ast_output_port_identifier {
    ast_type                        type;
};
// 
void ast_output_port_identifier_describe(FILE *out, struct ast_output_port_identifier *this);
// 
void ast_output_port_identifier_action(FILE *out, struct ast_output_port_identifier *this);



// 
struct ast_package_identifier {
    ast_type                        type;
};
// 
void ast_package_identifier_describe(FILE *out, struct ast_package_identifier *this);
// 
void ast_package_identifier_action(FILE *out, struct ast_package_identifier *this);



// 
struct ast_package_scope {
    ast_type                        type;
};
// 
void ast_package_scope_describe(FILE *out, struct ast_package_scope *this);
// 
void ast_package_scope_action(FILE *out, struct ast_package_scope *this);



// 
struct ast_parameter_identifier {
    ast_type                        type;
};
// 
void ast_parameter_identifier_describe(FILE *out, struct ast_parameter_identifier *this);
// 
void ast_parameter_identifier_action(FILE *out, struct ast_parameter_identifier *this);



// 
struct ast_port_identifier {
    ast_type                        type;
};
// 
void ast_port_identifier_describe(FILE *out, struct ast_port_identifier *this);
// 
void ast_port_identifier_action(FILE *out, struct ast_port_identifier *this);



// 
struct ast_production_identifier {
    ast_type                        type;
};
// 
void ast_production_identifier_describe(FILE *out, struct ast_production_identifier *this);
// 
void ast_production_identifier_action(FILE *out, struct ast_production_identifier *this);



// 
struct ast_program_identifier {
    ast_type                        type;
};
// 
void ast_program_identifier_describe(FILE *out, struct ast_program_identifier *this);
// 
void ast_program_identifier_action(FILE *out, struct ast_program_identifier *this);



// 
struct ast_property_identifier {
    ast_type                        type;
};
// 
void ast_property_identifier_describe(FILE *out, struct ast_property_identifier *this);
// 
void ast_property_identifier_action(FILE *out, struct ast_property_identifier *this);



// 
struct ast_ps_class_identifier {
    ast_type                        type;
};
// 
void ast_ps_class_identifier_describe(FILE *out, struct ast_ps_class_identifier *this);
// 
void ast_ps_class_identifier_action(FILE *out, struct ast_ps_class_identifier *this);



// 
struct ast_ps_covergroup_identifier {
    ast_type                        type;
};
// 
void ast_ps_covergroup_identifier_describe(FILE *out, struct ast_ps_covergroup_identifier *this);
// 
void ast_ps_covergroup_identifier_action(FILE *out, struct ast_ps_covergroup_identifier *this);



// 
struct ast_ps_checker_identifier {
    ast_type                        type;
};
// 
void ast_ps_checker_identifier_describe(FILE *out, struct ast_ps_checker_identifier *this);
// 
void ast_ps_checker_identifier_action(FILE *out, struct ast_ps_checker_identifier *this);



// 
struct ast_ps_identifier {
    ast_type                        type;
};
// 
void ast_ps_identifier_describe(FILE *out, struct ast_ps_identifier *this);
// 
void ast_ps_identifier_action(FILE *out, struct ast_ps_identifier *this);



// 
struct ast_ps_or_hierarchical_array_identifier {
    ast_type                        type;
};
// 
void ast_ps_or_hierarchical_array_identifier_describe(FILE *out, struct ast_ps_or_hierarchical_array_identifier *this);
// 
void ast_ps_or_hierarchical_array_identifier_action(FILE *out, struct ast_ps_or_hierarchical_array_identifier *this);



// 
struct ast_ps_or_hierarchical_net_identifier {
    ast_type                        type;
};
// 
void ast_ps_or_hierarchical_net_identifier_describe(FILE *out, struct ast_ps_or_hierarchical_net_identifier *this);
// 
void ast_ps_or_hierarchical_net_identifier_action(FILE *out, struct ast_ps_or_hierarchical_net_identifier *this);



// 
struct ast_ps_or_hierarchical_property_identifier {
    ast_type                        type;
};
// 
void ast_ps_or_hierarchical_property_identifier_describe(FILE *out, struct ast_ps_or_hierarchical_property_identifier *this);
// 
void ast_ps_or_hierarchical_property_identifier_action(FILE *out, struct ast_ps_or_hierarchical_property_identifier *this);



// 
struct ast_ps_or_hierarchical_sequence_identifier {
    ast_type                        type;
};
// 
void ast_ps_or_hierarchical_sequence_identifier_describe(FILE *out, struct ast_ps_or_hierarchical_sequence_identifier *this);
// 
void ast_ps_or_hierarchical_sequence_identifier_action(FILE *out, struct ast_ps_or_hierarchical_sequence_identifier *this);



// 
struct ast_ps_or_hierarchical_tf_identifier {
    ast_type                        type;
};
// 
void ast_ps_or_hierarchical_tf_identifier_describe(FILE *out, struct ast_ps_or_hierarchical_tf_identifier *this);
// 
void ast_ps_or_hierarchical_tf_identifier_action(FILE *out, struct ast_ps_or_hierarchical_tf_identifier *this);



// 
struct ast_ps_parameter_identifier {
    ast_type                        type;
};
// 
void ast_ps_parameter_identifier_describe(FILE *out, struct ast_ps_parameter_identifier *this);
// 
void ast_ps_parameter_identifier_action(FILE *out, struct ast_ps_parameter_identifier *this);



// 
struct ast_ps_type_identifier {
    ast_type                        type;
};
// 
void ast_ps_type_identifier_describe(FILE *out, struct ast_ps_type_identifier *this);
// 
void ast_ps_type_identifier_action(FILE *out, struct ast_ps_type_identifier *this);



// 
struct ast_sequence_identifier {
    ast_type                        type;
};
// 
void ast_sequence_identifier_describe(FILE *out, struct ast_sequence_identifier *this);
// 
void ast_sequence_identifier_action(FILE *out, struct ast_sequence_identifier *this);



// 
struct ast_signal_identifier {
    ast_type                        type;
};
// 
void ast_signal_identifier_describe(FILE *out, struct ast_signal_identifier *this);
// 
void ast_signal_identifier_action(FILE *out, struct ast_signal_identifier *this);



// 
struct ast_simple_identifier {
    ast_type                        type;
};
// 
void ast_simple_identifier_describe(FILE *out, struct ast_simple_identifier *this);
// 
void ast_simple_identifier_action(FILE *out, struct ast_simple_identifier *this);



// 
struct ast_specparam_identifier {
    ast_type                        type;
};
// 
void ast_specparam_identifier_describe(FILE *out, struct ast_specparam_identifier *this);
// 
void ast_specparam_identifier_action(FILE *out, struct ast_specparam_identifier *this);



// 
struct ast_system_tf_identifier {
    ast_type                        type;
};
// 
void ast_system_tf_identifier_describe(FILE *out, struct ast_system_tf_identifier *this);
// 
void ast_system_tf_identifier_action(FILE *out, struct ast_system_tf_identifier *this);



// 
struct ast_task_identifier {
    ast_type                        type;
};
// 
void ast_task_identifier_describe(FILE *out, struct ast_task_identifier *this);
// 
void ast_task_identifier_action(FILE *out, struct ast_task_identifier *this);



// 
struct ast_tf_identifier {
    ast_type                        type;
};
// 
void ast_tf_identifier_describe(FILE *out, struct ast_tf_identifier *this);
// 
void ast_tf_identifier_action(FILE *out, struct ast_tf_identifier *this);



// 
struct ast_terminal_identifier {
    ast_type                        type;
};
// 
void ast_terminal_identifier_describe(FILE *out, struct ast_terminal_identifier *this);
// 
void ast_terminal_identifier_action(FILE *out, struct ast_terminal_identifier *this);



// 
struct ast_topmodule_identifier {
    ast_type                        type;
};
// 
void ast_topmodule_identifier_describe(FILE *out, struct ast_topmodule_identifier *this);
// 
void ast_topmodule_identifier_action(FILE *out, struct ast_topmodule_identifier *this);



// 
struct ast_type_identifier {
    ast_type                        type;
};
// 
void ast_type_identifier_describe(FILE *out, struct ast_type_identifier *this);
// 
void ast_type_identifier_action(FILE *out, struct ast_type_identifier *this);



// 
struct ast_udp_identifier {
    ast_type                        type;
};
// 
void ast_udp_identifier_describe(FILE *out, struct ast_udp_identifier *this);
// 
void ast_udp_identifier_action(FILE *out, struct ast_udp_identifier *this);



// 
struct ast_variable_identifier {
    ast_type                        type;
};
// 
void ast_variable_identifier_describe(FILE *out, struct ast_variable_identifier *this);
// 
void ast_variable_identifier_action(FILE *out, struct ast_variable_identifier *this);



// 
struct ast_white_space {
    ast_type                        type;
};
// 
void ast_white_space_describe(FILE *out, struct ast_white_space *this);
// 
void ast_white_space_action(FILE *out, struct ast_white_space *this);



// 
struct ast_file_path_spec {
    ast_type                        type;
};
// 
void ast_file_path_spec_describe(FILE *out, struct ast_file_path_spec *this);
// 
void ast_file_path_spec_action(FILE *out, struct ast_file_path_spec *this);



#endif
