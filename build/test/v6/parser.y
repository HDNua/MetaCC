%{
#include <stdio.h>
#include <stdlib.h>

#include "parser_ast.h"
#define MAX_TOKEN_LEN 2048
#define new(TYPE) (TYPE *)malloc(sizeof(TYPE))



#ifdef YYDEBUG
int yydebug = 1;
#endif



struct ast_list *start_list;
struct ast_library_text *start_library_text;
struct ast_source_text *start_source_text;



int yylex();
int yyerror(char const *str);

%}
%union {
    char token_str[MAX_TOKEN_LEN];
    struct ast_list *ast_list;
    
    struct ast_library_text                             *ast_library_text;
    struct ast_library_description                      *ast_library_description;
    struct ast_library_declaration                      *ast_library_declaration;
    struct ast_include_statement                        *ast_include_statement;
    struct ast_source_text                              *ast_source_text;
    struct ast_description                              *ast_description;
    struct ast_module_nonansi_header                    *ast_module_nonansi_header;
    struct ast_module_ansi_header                       *ast_module_ansi_header;
    struct ast_module_declaration                       *ast_module_declaration;
    struct ast_module_keyword                           *ast_module_keyword;
    struct ast_interface_declaration                    *ast_interface_declaration;
    struct ast_interface_nonansi_header                 *ast_interface_nonansi_header;
    struct ast_interface_ansi_header                    *ast_interface_ansi_header;
    struct ast_program_declaration                      *ast_program_declaration;
    struct ast_program_nonansi_header                   *ast_program_nonansi_header;
    struct ast_program_ansi_header                      *ast_program_ansi_header;
    struct ast_checker_declaration                      *ast_checker_declaration;
    struct ast_class_declaration                        *ast_class_declaration;
    struct ast_interface_class_type                     *ast_interface_class_type;
    struct ast_package_declaration                      *ast_package_declaration;
    struct ast_timeunits_declaration                    *ast_timeunits_declaration;
    struct ast_parameter_port_list                      *ast_parameter_port_list;
    struct ast_parameter_port_declaration               *ast_parameter_port_declaration;
    struct ast_list_of_ports                            *ast_list_of_ports;
    struct ast_list_of_port_declarations                *ast_list_of_port_declarations;
    struct ast_port_declaration                         *ast_port_declaration;
    struct ast_port                                     *ast_port;
    struct ast_port_expression                          *ast_port_expression;
    struct ast_port_reference                           *ast_port_reference;
    struct ast_port_direction                           *ast_port_direction;
    struct ast_net_port_header                          *ast_net_port_header;
    struct ast_variable_port_header                     *ast_variable_port_header;
    struct ast_interface_port_header                    *ast_interface_port_header;
    struct ast_ansi_port_declaration                    *ast_ansi_port_declaration;
    struct ast_elaboration_system_task                  *ast_elaboration_system_task;
    struct ast_finish_number                            *ast_finish_number;
    struct ast_module_common_item                       *ast_module_common_item;
    struct ast_module_item                              *ast_module_item;
    struct ast_module_or_generate_item                  *ast_module_or_generate_item;
    struct ast_module_or_generate_item_declaration      *ast_module_or_generate_item_declaration;
    struct ast_non_port_module_item                     *ast_non_port_module_item;
    struct ast_parameter_override                       *ast_parameter_override;
    struct ast_bind_directive                           *ast_bind_directive;
    struct ast_bind_target_scope                        *ast_bind_target_scope;
    struct ast_bind_target_instance                     *ast_bind_target_instance;
    struct ast_bind_target_instance_list                *ast_bind_target_instance_list;
    struct ast_bind_instantiation                       *ast_bind_instantiation;
    struct ast_config_declaration                       *ast_config_declaration;
    struct ast_design_statement                         *ast_design_statement;
    struct ast_config_rule_statement                    *ast_config_rule_statement;
    struct ast_default_clause                           *ast_default_clause;
    struct ast_inst_clause                              *ast_inst_clause;
    struct ast_inst_name                                *ast_inst_name;
    struct ast_cell_clause                              *ast_cell_clause;
    struct ast_liblist_clause                           *ast_liblist_clause;
    struct ast_use_clause                               *ast_use_clause;
    struct ast_interface_or_generate_item               *ast_interface_or_generate_item;
    struct ast_extern_tf_declaration                    *ast_extern_tf_declaration;
    struct ast_interface_item                           *ast_interface_item;
    struct ast_non_port_interface_item                  *ast_non_port_interface_item;
    struct ast_program_item                             *ast_program_item;
    struct ast_non_port_program_item                    *ast_non_port_program_item;
    struct ast_program_generate_item                    *ast_program_generate_item;
    struct ast_checker_port_list                        *ast_checker_port_list;
    struct ast_checker_port_item                        *ast_checker_port_item;
    struct ast_checker_port_direction                   *ast_checker_port_direction;
    struct ast_checker_or_generate_item                 *ast_checker_or_generate_item;
    struct ast_checker_or_generate_item_declaration     *ast_checker_or_generate_item_declaration;
    struct ast_checker_generate_item                    *ast_checker_generate_item;
    struct ast_class_item                               *ast_class_item;
    struct ast_class_property                           *ast_class_property;
    struct ast_class_method                             *ast_class_method;
    struct ast_class_constructor_prototype              *ast_class_constructor_prototype;
    struct ast_class_constraint                         *ast_class_constraint;
    struct ast_class_item_qualifier                     *ast_class_item_qualifier;
    struct ast_property_qualifier                       *ast_property_qualifier;
    struct ast_random_qualifier                         *ast_random_qualifier;
    struct ast_method_qualifier                         *ast_method_qualifier;
    struct ast_method_prototype                         *ast_method_prototype;
    struct ast_class_constructor_declaration            *ast_class_constructor_declaration;
    struct ast_constraint_declaration                   *ast_constraint_declaration;
    struct ast_constraint_block                         *ast_constraint_block;
    struct ast_constraint_block_item                    *ast_constraint_block_item;
    struct ast_solve_before_list                        *ast_solve_before_list;
    struct ast_constraint_primary                       *ast_constraint_primary;
    struct ast_constraint_expression                    *ast_constraint_expression;
    struct ast_uniqueness_constraint                    *ast_uniqueness_constraint;
    struct ast_constraint_set                           *ast_constraint_set;
    struct ast_dist_list                                *ast_dist_list;
    struct ast_dist_item                                *ast_dist_item;
    struct ast_dist_weight                              *ast_dist_weight;
    struct ast_constraint_prototype                     *ast_constraint_prototype;
    struct ast_constraint_prototype_qualifier           *ast_constraint_prototype_qualifier;
    struct ast_extern_constraint_declaration            *ast_extern_constraint_declaration;
    struct ast_identifier_list                          *ast_identifier_list;
    struct ast_package_item                             *ast_package_item;
    struct ast_package_or_generate_item_declaration     *ast_package_or_generate_item_declaration;
    struct ast_anonymous_program                        *ast_anonymous_program;
    struct ast_anonymous_program_item                   *ast_anonymous_program_item;
    struct ast_local_parameter_declaration              *ast_local_parameter_declaration;
    struct ast_parameter_declaration                    *ast_parameter_declaration;
    struct ast_specparam_declaration                    *ast_specparam_declaration;
    struct ast_inout_declaration                        *ast_inout_declaration;
    struct ast_input_declaration                        *ast_input_declaration;
    struct ast_output_declaration                       *ast_output_declaration;
    struct ast_interface_port_declaration               *ast_interface_port_declaration;
    struct ast_ref_declaration                          *ast_ref_declaration;
    struct ast_data_declaration                         *ast_data_declaration;
    struct ast_package_import_declaration               *ast_package_import_declaration;
    struct ast_package_import_item                      *ast_package_import_item;
    struct ast_package_export_declaration               *ast_package_export_declaration;
    struct ast_genvar_declaration                       *ast_genvar_declaration;
    struct ast_net_declaration                          *ast_net_declaration;
    struct ast_type_declaration                         *ast_type_declaration;
    struct ast_net_type_declaration                     *ast_net_type_declaration;
    struct ast_lifetime                                 *ast_lifetime;
    struct ast_casting_type                             *ast_casting_type;
    struct ast_data_type                                *ast_data_type;
    struct ast_data_type_or_implicit                    *ast_data_type_or_implicit;
    struct ast_implicit_data_type                       *ast_implicit_data_type;
    struct ast_enum_base_type                           *ast_enum_base_type;
    struct ast_enum_name_declaration                    *ast_enum_name_declaration;
    struct ast_class_scope                              *ast_class_scope;
    struct ast_class_type                               *ast_class_type;
    struct ast_integer_type                             *ast_integer_type;
    struct ast_integer_atom_type                        *ast_integer_atom_type;
    struct ast_integer_vector_type                      *ast_integer_vector_type;
    struct ast_non_integer_type                         *ast_non_integer_type;
    struct ast_net_type                                 *ast_net_type;
    struct ast_net_port_type                            *ast_net_port_type;
    struct ast_variable_port_type                       *ast_variable_port_type;
    struct ast_var_data_type                            *ast_var_data_type;
    struct ast_signing                                  *ast_signing;
    struct ast_simple_type                              *ast_simple_type;
    struct ast_struct_union_member                      *ast_struct_union_member;
    struct ast_data_type_or_void                        *ast_data_type_or_void;
    struct ast_struct_union                             *ast_struct_union;
    struct ast_type_reference                           *ast_type_reference;
    struct ast_drive_strength                           *ast_drive_strength;
    struct ast_strength0                                *ast_strength0;
    struct ast_strength1                                *ast_strength1;
    struct ast_charge_strength                          *ast_charge_strength;
    struct ast_delay3                                   *ast_delay3;
    struct ast_delay2                                   *ast_delay2;
    struct ast_delay_value                              *ast_delay_value;
    struct ast_list_of_defparam_assignments             *ast_list_of_defparam_assignments;
    struct ast_list_of_genvar_identifiers               *ast_list_of_genvar_identifiers;
    struct ast_list_of_interface_identifiers            *ast_list_of_interface_identifiers;
    struct ast_list_of_net_decl_assignments             *ast_list_of_net_decl_assignments;
    struct ast_list_of_param_assignments                *ast_list_of_param_assignments;
    struct ast_list_of_port_identifiers                 *ast_list_of_port_identifiers;
    struct ast_list_of_udp_port_identifiers             *ast_list_of_udp_port_identifiers;
    struct ast_list_of_specparam_assignments            *ast_list_of_specparam_assignments;
    struct ast_list_of_tf_variable_identifiers          *ast_list_of_tf_variable_identifiers;
    struct ast_list_of_type_assignments                 *ast_list_of_type_assignments;
    struct ast_list_of_variable_decl_assignments        *ast_list_of_variable_decl_assignments;
    struct ast_list_of_variable_identifiers             *ast_list_of_variable_identifiers;
    struct ast_list_of_variable_port_identifiers        *ast_list_of_variable_port_identifiers;
    struct ast_defparam_assignment                      *ast_defparam_assignment;
    struct ast_net_decl_assignment                      *ast_net_decl_assignment;
    struct ast_param_assignment                         *ast_param_assignment;
    struct ast_specparam_assignment                     *ast_specparam_assignment;
    struct ast_type_assignment                          *ast_type_assignment;
    struct ast_pulse_control_specparam                  *ast_pulse_control_specparam;
    struct ast_error_limit_value                        *ast_error_limit_value;
    struct ast_reject_limit_value                       *ast_reject_limit_value;
    struct ast_limit_value                              *ast_limit_value;
    struct ast_variable_decl_assignment                 *ast_variable_decl_assignment;
    struct ast_class_new                                *ast_class_new;
    struct ast_dynamic_array_new                        *ast_dynamic_array_new;
    struct ast_unpacked_dimension                       *ast_unpacked_dimension;
    struct ast_packed_dimension                         *ast_packed_dimension;
    struct ast_associative_dimension                    *ast_associative_dimension;
    struct ast_variable_dimension                       *ast_variable_dimension;
    struct ast_queue_dimension                          *ast_queue_dimension;
    struct ast_unsized_dimension                        *ast_unsized_dimension;
    struct ast_function_data_type_or_implicit           *ast_function_data_type_or_implicit;
    struct ast_function_declaration                     *ast_function_declaration;
    struct ast_function_body_declaration                *ast_function_body_declaration;
    struct ast_function_prototype                       *ast_function_prototype;
    struct ast_dpi_import_export                        *ast_dpi_import_export;
    struct ast_dpi_spec_string                          *ast_dpi_spec_string;
    struct ast_dpi_function_import_property             *ast_dpi_function_import_property;
    struct ast_dpi_task_import_property                 *ast_dpi_task_import_property;
    struct ast_dpi_function_proto                       *ast_dpi_function_proto;
    struct ast_dpi_task_proto                           *ast_dpi_task_proto;
    struct ast_task_declaration                         *ast_task_declaration;
    struct ast_task_body_declaration                    *ast_task_body_declaration;
    struct ast_tf_item_declaration                      *ast_tf_item_declaration;
    struct ast_tf_port_list                             *ast_tf_port_list;
    struct ast_tf_port_item                             *ast_tf_port_item;
    struct ast_tf_port_direction                        *ast_tf_port_direction;
    struct ast_tf_port_declaration                      *ast_tf_port_declaration;
    struct ast_task_prototype                           *ast_task_prototype;
    struct ast_block_item_declaration                   *ast_block_item_declaration;
    struct ast_overload_declaration                     *ast_overload_declaration;
    struct ast_overload_operator                        *ast_overload_operator;
    struct ast_overload_proto_formals                   *ast_overload_proto_formals;
    struct ast_modport_declaration                      *ast_modport_declaration;
    struct ast_modport_item                             *ast_modport_item;
    struct ast_modport_ports_declaration                *ast_modport_ports_declaration;
    struct ast_modport_clocking_declaration             *ast_modport_clocking_declaration;
    struct ast_modport_simple_ports_declaration         *ast_modport_simple_ports_declaration;
    struct ast_modport_simple_port                      *ast_modport_simple_port;
    struct ast_modport_tf_ports_declaration             *ast_modport_tf_ports_declaration;
    struct ast_modport_tf_port                          *ast_modport_tf_port;
    struct ast_import_export                            *ast_import_export;
    struct ast_concurrent_assertion_item                *ast_concurrent_assertion_item;
    struct ast_concurrent_assertion_statement           *ast_concurrent_assertion_statement;
    struct ast_assert_property_statement                *ast_assert_property_statement;
    struct ast_assume_property_statement                *ast_assume_property_statement;
    struct ast_cover_property_statement                 *ast_cover_property_statement;
    struct ast_expect_property_statement                *ast_expect_property_statement;
    struct ast_cover_sequence_statement                 *ast_cover_sequence_statement;
    struct ast_restrict_property_statement              *ast_restrict_property_statement;
    struct ast_property_instance                        *ast_property_instance;
    struct ast_property_list_of_arguments               *ast_property_list_of_arguments;
    struct ast_property_actual_arg                      *ast_property_actual_arg;
    struct ast_assertion_item_declaration               *ast_assertion_item_declaration;
    struct ast_property_declaration                     *ast_property_declaration;
    struct ast_property_port_list                       *ast_property_port_list;
    struct ast_property_port_item                       *ast_property_port_item;
    struct ast_property_lvar_port_direction             *ast_property_lvar_port_direction;
    struct ast_property_formal_type                     *ast_property_formal_type;
    struct ast_property_spec                            *ast_property_spec;
    struct ast_property_expr                            *ast_property_expr;
    struct ast_property_case_item                       *ast_property_case_item;
    struct ast_sequence_declaration                     *ast_sequence_declaration;
    struct ast_sequence_port_list                       *ast_sequence_port_list;
    struct ast_sequence_port_item                       *ast_sequence_port_item;
    struct ast_sequence_lvar_port_direction             *ast_sequence_lvar_port_direction;
    struct ast_sequence_formal_type                     *ast_sequence_formal_type;
    struct ast_sequence_expr                            *ast_sequence_expr;
    struct ast_cycle_delay_range                        *ast_cycle_delay_range;
    struct ast_sequence_method_call                     *ast_sequence_method_call;
    struct ast_sequence_match_item                      *ast_sequence_match_item;
    struct ast_sequence_instance                        *ast_sequence_instance;
    struct ast_sequence_list_of_arguments               *ast_sequence_list_of_arguments;
    struct ast_sequence_actual_arg                      *ast_sequence_actual_arg;
    struct ast_boolean_abbrev                           *ast_boolean_abbrev;
    struct ast_sequence_abbrev                          *ast_sequence_abbrev;
    struct ast_consecutive_repetition                   *ast_consecutive_repetition;
    struct ast_non_consecutive_repetition               *ast_non_consecutive_repetition;
    struct ast_goto_repetition                          *ast_goto_repetition;
    struct ast_const_or_range_expression                *ast_const_or_range_expression;
    struct ast_cycle_delay_const_range_expression       *ast_cycle_delay_const_range_expression;
    struct ast_expression_or_dist                       *ast_expression_or_dist;
    struct ast_assertion_variable_declaration           *ast_assertion_variable_declaration;
    struct ast_let_declaration                          *ast_let_declaration;
    struct ast_let_identifier                           *ast_let_identifier;
    struct ast_let_port_list                            *ast_let_port_list;
    struct ast_let_port_item                            *ast_let_port_item;
    struct ast_let_formal_type                          *ast_let_formal_type;
    struct ast_let_expression                           *ast_let_expression;
    struct ast_let_list_of_arguments                    *ast_let_list_of_arguments;
    struct ast_let_actual_arg                           *ast_let_actual_arg;
    struct ast_covergroup_declaration                   *ast_covergroup_declaration;
    struct ast_coverage_spec_or_option                  *ast_coverage_spec_or_option;
    struct ast_coverage_option                          *ast_coverage_option;
    struct ast_coverage_spec                            *ast_coverage_spec;
    struct ast_coverage_event                           *ast_coverage_event;
    struct ast_block_event_expression                   *ast_block_event_expression;
    struct ast_hierarchical_btf_identifier              *ast_hierarchical_btf_identifier;
    struct ast_cover_point                              *ast_cover_point;
    struct ast_bins_or_empty                            *ast_bins_or_empty;
    struct ast_bins_or_options                          *ast_bins_or_options;
    struct ast_bins_keyword                             *ast_bins_keyword;
    struct ast_trans_list                               *ast_trans_list;
    struct ast_trans_set                                *ast_trans_set;
    struct ast_trans_range_list                         *ast_trans_range_list;
    struct ast_trans_item                               *ast_trans_item;
    struct ast_repeat_range                             *ast_repeat_range;
    struct ast_cover_cross                              *ast_cover_cross;
    struct ast_list_of_cross_items                      *ast_list_of_cross_items;
    struct ast_cross_item                               *ast_cross_item;
    struct ast_cross_body                               *ast_cross_body;
    struct ast_cross_body_item                          *ast_cross_body_item;
    struct ast_bins_selection_or_option                 *ast_bins_selection_or_option;
    struct ast_bins_selection                           *ast_bins_selection;
    struct ast_select_expression                        *ast_select_expression;
    struct ast_select_condition                         *ast_select_condition;
    struct ast_bins_expression                          *ast_bins_expression;
    struct ast_covergroup_range_list                    *ast_covergroup_range_list;
    struct ast_covergroup_value_range                   *ast_covergroup_value_range;
    struct ast_with_covergroup_expression               *ast_with_covergroup_expression;
    struct ast_set_covergroup_expression                *ast_set_covergroup_expression;
    struct ast_integer_covergroup_expression            *ast_integer_covergroup_expression;
    struct ast_cross_set_expression                     *ast_cross_set_expression;
    struct ast_covergroup_expression                    *ast_covergroup_expression;
    struct ast_gate_instantiation                       *ast_gate_instantiation;
    struct ast_cmos_switch_instance                     *ast_cmos_switch_instance;
    struct ast_enable_gate_instance                     *ast_enable_gate_instance;
    struct ast_mos_switch_instance                      *ast_mos_switch_instance;
    struct ast_n_input_gate_instance                    *ast_n_input_gate_instance;
    struct ast_n_output_gate_instance                   *ast_n_output_gate_instance;
    struct ast_pass_switch_instance                     *ast_pass_switch_instance;
    struct ast_pass_enable_switch_instance              *ast_pass_enable_switch_instance;
    struct ast_pull_gate_instance                       *ast_pull_gate_instance;
    struct ast_pulldown_strength                        *ast_pulldown_strength;
    struct ast_pullup_strength                          *ast_pullup_strength;
    struct ast_enable_terminal                          *ast_enable_terminal;
    struct ast_inout_terminal                           *ast_inout_terminal;
    struct ast_input_terminal                           *ast_input_terminal;
    struct ast_ncontrol_terminal                        *ast_ncontrol_terminal;
    struct ast_output_terminal                          *ast_output_terminal;
    struct ast_pcontrol_terminal                        *ast_pcontrol_terminal;
    struct ast_cmos_switchtype                          *ast_cmos_switchtype;
    struct ast_enable_gatetype                          *ast_enable_gatetype;
    struct ast_mos_switchtype                           *ast_mos_switchtype;
    struct ast_n_input_gatetype                         *ast_n_input_gatetype;
    struct ast_n_output_gatetype                        *ast_n_output_gatetype;
    struct ast_pass_en_switchtype                       *ast_pass_en_switchtype;
    struct ast_pass_switchtype                          *ast_pass_switchtype;
    struct ast_module_instantiation                     *ast_module_instantiation;
    struct ast_parameter_value_assignment               *ast_parameter_value_assignment;
    struct ast_list_of_parameter_assignments            *ast_list_of_parameter_assignments;
    struct ast_ordered_parameter_assignment             *ast_ordered_parameter_assignment;
    struct ast_named_parameter_assignment               *ast_named_parameter_assignment;
    struct ast_hierarchical_instance                    *ast_hierarchical_instance;
    struct ast_name_of_instance                         *ast_name_of_instance;
    struct ast_list_of_port_connections                 *ast_list_of_port_connections;
    struct ast_ordered_port_connection                  *ast_ordered_port_connection;
    struct ast_named_port_connection                    *ast_named_port_connection;
    struct ast_interface_instantiation                  *ast_interface_instantiation;
    struct ast_program_instantiation                    *ast_program_instantiation;
    struct ast_checker_instantiation                    *ast_checker_instantiation;
    struct ast_list_of_checker_port_connections         *ast_list_of_checker_port_connections;
    struct ast_ordered_checker_port_connection          *ast_ordered_checker_port_connection;
    struct ast_named_checker_port_connection            *ast_named_checker_port_connection;
    struct ast_generate_region                          *ast_generate_region;
    struct ast_loop_generate_construct                  *ast_loop_generate_construct;
    struct ast_genvar_initialization                    *ast_genvar_initialization;
    struct ast_genvar_iteration                         *ast_genvar_iteration;
    struct ast_conditional_generate_construct           *ast_conditional_generate_construct;
    struct ast_if_generate_construct                    *ast_if_generate_construct;
    struct ast_case_generate_construct                  *ast_case_generate_construct;
    struct ast_case_generate_item                       *ast_case_generate_item;
    struct ast_generate_block                           *ast_generate_block;
    struct ast_generate_item                            *ast_generate_item;
    struct ast_udp_nonansi_declaration                  *ast_udp_nonansi_declaration;
    struct ast_udp_ansi_declaration                     *ast_udp_ansi_declaration;
    struct ast_udp_declaration                          *ast_udp_declaration;
    struct ast_udp_port_list                            *ast_udp_port_list;
    struct ast_udp_declaration_port_list                *ast_udp_declaration_port_list;
    struct ast_udp_port_declaration                     *ast_udp_port_declaration;
    struct ast_udp_output_declaration                   *ast_udp_output_declaration;
    struct ast_udp_input_declaration                    *ast_udp_input_declaration;
    struct ast_udp_reg_declaration                      *ast_udp_reg_declaration;
    struct ast_udp_body                                 *ast_udp_body;
    struct ast_combinational_body                       *ast_combinational_body;
    struct ast_combinational_entry                      *ast_combinational_entry;
    struct ast_sequential_body                          *ast_sequential_body;
    struct ast_udp_initial_statement                    *ast_udp_initial_statement;
    struct ast_init_val                                 *ast_init_val;
    struct ast_sequential_entry                         *ast_sequential_entry;
    struct ast_seq_input_list                           *ast_seq_input_list;
    struct ast_level_input_list                         *ast_level_input_list;
    struct ast_edge_input_list                          *ast_edge_input_list;
    struct ast_edge_indicator                           *ast_edge_indicator;
    struct ast_current_state                            *ast_current_state;
    struct ast_next_state                               *ast_next_state;
    struct ast_output_symbol                            *ast_output_symbol;
    struct ast_level_symbol                             *ast_level_symbol;
    struct ast_edge_symbol                              *ast_edge_symbol;
    struct ast_udp_instantiation                        *ast_udp_instantiation;
    struct ast_udp_instance                             *ast_udp_instance;
    struct ast_continuous_assign                        *ast_continuous_assign;
    struct ast_list_of_net_assignments                  *ast_list_of_net_assignments;
    struct ast_list_of_variable_assignments             *ast_list_of_variable_assignments;
    struct ast_net_alias                                *ast_net_alias;
    struct ast_net_assignment                           *ast_net_assignment;
    struct ast_initial_construct                        *ast_initial_construct;
    struct ast_always_construct                         *ast_always_construct;
    struct ast_always_keyword                           *ast_always_keyword;
    struct ast_final_construct                          *ast_final_construct;
    struct ast_blocking_assignment                      *ast_blocking_assignment;
    struct ast_operator_assignment                      *ast_operator_assignment;
    struct ast_assignment_operator                      *ast_assignment_operator;
    struct ast_nonblocking_assignment                   *ast_nonblocking_assignment;
    struct ast_procedural_continuous_assignment         *ast_procedural_continuous_assignment;
    struct ast_variable_assignment                      *ast_variable_assignment;
    struct ast_action_block                             *ast_action_block;
    struct ast_seq_block                                *ast_seq_block;
    struct ast_par_block                                *ast_par_block;
    struct ast_join_keyword                             *ast_join_keyword;
    struct ast_statement_or_null                        *ast_statement_or_null;
    struct ast_statement                                *ast_statement;
    struct ast_statement_item                           *ast_statement_item;
    struct ast_function_statement                       *ast_function_statement;
    struct ast_function_statement_or_null               *ast_function_statement_or_null;
    struct ast_variable_identifier_list                 *ast_variable_identifier_list;
    struct ast_procedural_timing_control_statement      *ast_procedural_timing_control_statement;
    struct ast_delay_or_event_control                   *ast_delay_or_event_control;
    struct ast_delay_control                            *ast_delay_control;
    struct ast_event_control                            *ast_event_control;
    struct ast_event_expression                         *ast_event_expression;
    struct ast_procedural_timing_control                *ast_procedural_timing_control;
    struct ast_jump_statement                           *ast_jump_statement;
    struct ast_wait_statement                           *ast_wait_statement;
    struct ast_event_trigger                            *ast_event_trigger;
    struct ast_disable_statement                        *ast_disable_statement;
    struct ast_conditional_statement                    *ast_conditional_statement;
    struct ast_unique_priority                          *ast_unique_priority;
    struct ast_cond_predicate                           *ast_cond_predicate;
    struct ast_expression_or_cond_pattern               *ast_expression_or_cond_pattern;
    struct ast_cond_pattern                             *ast_cond_pattern;
    struct ast_case_statement                           *ast_case_statement;
    struct ast_case_keyword                             *ast_case_keyword;
    struct ast_case_expression                          *ast_case_expression;
    struct ast_case_item                                *ast_case_item;
    struct ast_case_pattern_item                        *ast_case_pattern_item;
    struct ast_case_inside_item                         *ast_case_inside_item;
    struct ast_case_item_expression                     *ast_case_item_expression;
    struct ast_randcase_statement                       *ast_randcase_statement;
    struct ast_randcase_item                            *ast_randcase_item;
    struct ast_open_range_list                          *ast_open_range_list;
    struct ast_open_value_range                         *ast_open_value_range;
    struct ast_pattern                                  *ast_pattern;
    struct ast_assignment_pattern                       *ast_assignment_pattern;
    struct ast_structure_pattern_key                    *ast_structure_pattern_key;
    struct ast_array_pattern_key                        *ast_array_pattern_key;
    struct ast_assignment_pattern_key                   *ast_assignment_pattern_key;
    struct ast_assignment_pattern_expression            *ast_assignment_pattern_expression;
    struct ast_assignment_pattern_expression_type       *ast_assignment_pattern_expression_type;
    struct ast_constant_assignment_pattern_expression   *ast_constant_assignment_pattern_expression;
    struct ast_assignment_pattern_net_lvalue            *ast_assignment_pattern_net_lvalue;
    struct ast_assignment_pattern_variable_lvalue       *ast_assignment_pattern_variable_lvalue;
    struct ast_loop_statement                           *ast_loop_statement;
    struct ast_for_initialization                       *ast_for_initialization;
    struct ast_for_variable_declaration                 *ast_for_variable_declaration;
    struct ast_for_step                                 *ast_for_step;
    struct ast_for_step_assignment                      *ast_for_step_assignment;
    struct ast_loop_variables                           *ast_loop_variables;
    struct ast_subroutine_call_statement                *ast_subroutine_call_statement;
    struct ast_assertion_item                           *ast_assertion_item;
    struct ast_deferred_immediate_assertion_item        *ast_deferred_immediate_assertion_item;
    struct ast_procedural_assertion_statement           *ast_procedural_assertion_statement;
    struct ast_immediate_assertion_statement            *ast_immediate_assertion_statement;
    struct ast_simple_immediate_assertion_statement     *ast_simple_immediate_assertion_statement;
    struct ast_simple_immediate_assert_statement        *ast_simple_immediate_assert_statement;
    struct ast_simple_immediate_assume_statement        *ast_simple_immediate_assume_statement;
    struct ast_simple_immediate_cover_statement         *ast_simple_immediate_cover_statement;
    struct ast_deferred_immediate_assertion_statement   *ast_deferred_immediate_assertion_statement;
    struct ast_deferred_immediate_assert_statement      *ast_deferred_immediate_assert_statement;
    struct ast_deferred_immediate_assume_statement      *ast_deferred_immediate_assume_statement;
    struct ast_deferred_immediate_cover_statement       *ast_deferred_immediate_cover_statement;
    struct ast_clocking_declaration                     *ast_clocking_declaration;
    struct ast_clocking_event                           *ast_clocking_event;
    struct ast_clocking_item                            *ast_clocking_item;
    struct ast_default_skew                             *ast_default_skew;
    struct ast_clocking_direction                       *ast_clocking_direction;
    struct ast_list_of_clocking_decl_assign             *ast_list_of_clocking_decl_assign;
    struct ast_clocking_decl_assign                     *ast_clocking_decl_assign;
    struct ast_clocking_skew                            *ast_clocking_skew;
    struct ast_clocking_drive                           *ast_clocking_drive;
    struct ast_cycle_delay                              *ast_cycle_delay;
    struct ast_clockvar                                 *ast_clockvar;
    struct ast_clockvar_expression                      *ast_clockvar_expression;
    struct ast_randsequence_statement                   *ast_randsequence_statement;
    struct ast_production                               *ast_production;
    struct ast_rs_rule                                  *ast_rs_rule;
    struct ast_rs_production_list                       *ast_rs_production_list;
    struct ast_weight_specification                     *ast_weight_specification;
    struct ast_rs_code_block                            *ast_rs_code_block;
    struct ast_rs_prod                                  *ast_rs_prod;
    struct ast_production_item                          *ast_production_item;
    struct ast_rs_if_else                               *ast_rs_if_else;
    struct ast_rs_repeat                                *ast_rs_repeat;
    struct ast_rs_case                                  *ast_rs_case;
    struct ast_rs_case_item                             *ast_rs_case_item;
    struct ast_specify_block                            *ast_specify_block;
    struct ast_specify_item                             *ast_specify_item;
    struct ast_pulsestyle_declaration                   *ast_pulsestyle_declaration;
    struct ast_showcancelled_declaration                *ast_showcancelled_declaration;
    struct ast_path_declaration                         *ast_path_declaration;
    struct ast_simple_path_declaration                  *ast_simple_path_declaration;
    struct ast_parallel_path_description                *ast_parallel_path_description;
    struct ast_full_path_description                    *ast_full_path_description;
    struct ast_list_of_path_inputs                      *ast_list_of_path_inputs;
    struct ast_list_of_path_outputs                     *ast_list_of_path_outputs;
    struct ast_specify_input_terminal_descriptor        *ast_specify_input_terminal_descriptor;
    struct ast_specify_output_terminal_descriptor       *ast_specify_output_terminal_descriptor;
    struct ast_input_identifier                         *ast_input_identifier;
    struct ast_output_identifier                        *ast_output_identifier;
    struct ast_path_delay_value                         *ast_path_delay_value;
    struct ast_list_of_path_delay_expressions           *ast_list_of_path_delay_expressions;
    struct ast_t_path_delay_expression                  *ast_t_path_delay_expression;
    struct ast_trise_path_delay_expression              *ast_trise_path_delay_expression;
    struct ast_tfall_path_delay_expression              *ast_tfall_path_delay_expression;
    struct ast_tz_path_delay_expression                 *ast_tz_path_delay_expression;
    struct ast_t01_path_delay_expression                *ast_t01_path_delay_expression;
    struct ast_t10_path_delay_expression                *ast_t10_path_delay_expression;
    struct ast_t0z_path_delay_expression                *ast_t0z_path_delay_expression;
    struct ast_tz1_path_delay_expression                *ast_tz1_path_delay_expression;
    struct ast_t1z_path_delay_expression                *ast_t1z_path_delay_expression;
    struct ast_tz0_path_delay_expression                *ast_tz0_path_delay_expression;
    struct ast_t0x_path_delay_expression                *ast_t0x_path_delay_expression;
    struct ast_tx1_path_delay_expression                *ast_tx1_path_delay_expression;
    struct ast_t1x_path_delay_expression                *ast_t1x_path_delay_expression;
    struct ast_tx0_path_delay_expression                *ast_tx0_path_delay_expression;
    struct ast_txz_path_delay_expression                *ast_txz_path_delay_expression;
    struct ast_tzx_path_delay_expression                *ast_tzx_path_delay_expression;
    struct ast_path_delay_expression                    *ast_path_delay_expression;
    struct ast_edge_sensitive_path_declaration          *ast_edge_sensitive_path_declaration;
    struct ast_parallel_edge_sensitive_path_description *ast_parallel_edge_sensitive_path_description;
    struct ast_full_edge_sensitive_path_description     *ast_full_edge_sensitive_path_description;
    struct ast_data_source_expression                   *ast_data_source_expression;
    struct ast_edge_identifier                          *ast_edge_identifier;
    struct ast_state_dependent_path_declaration         *ast_state_dependent_path_declaration;
    struct ast_polarity_operator                        *ast_polarity_operator;
    struct ast_system_timing_check                      *ast_system_timing_check;
    struct ast_dollarsign_setup_timing_check            *ast_dollarsign_setup_timing_check;
    struct ast_dollarsign_hold_timing_check             *ast_dollarsign_hold_timing_check;
    struct ast_dollarsign_setuphold_timing_check        *ast_dollarsign_setuphold_timing_check;
    struct ast_dollarsign_recovery_timing_check         *ast_dollarsign_recovery_timing_check;
    struct ast_dollarsign_removal_timing_check          *ast_dollarsign_removal_timing_check;
    struct ast_dollarsign_recrem_timing_check           *ast_dollarsign_recrem_timing_check;
    struct ast_dollarsign_skew_timing_check             *ast_dollarsign_skew_timing_check;
    struct ast_dollarsign_timeskew_timing_check         *ast_dollarsign_timeskew_timing_check;
    struct ast_dollarsign_fullskew_timing_check         *ast_dollarsign_fullskew_timing_check;
    struct ast_dollarsign_period_timing_check           *ast_dollarsign_period_timing_check;
    struct ast_dollarsign_width_timing_check            *ast_dollarsign_width_timing_check;
    struct ast_dollarsign_nochange_timing_check         *ast_dollarsign_nochange_timing_check;
    struct ast_timecheck_condition                      *ast_timecheck_condition;
    struct ast_controlled_reference_event               *ast_controlled_reference_event;
    struct ast_data_event                               *ast_data_event;
    struct ast_delayed_data                             *ast_delayed_data;
    struct ast_delayed_reference                        *ast_delayed_reference;
    struct ast_end_edge_offset                          *ast_end_edge_offset;
    struct ast_event_based_flag                         *ast_event_based_flag;
    struct ast_notifier                                 *ast_notifier;
    struct ast_reference_event                          *ast_reference_event;
    struct ast_remain_active_flag                       *ast_remain_active_flag;
    struct ast_timestamp_condition                      *ast_timestamp_condition;
    struct ast_start_edge_offset                        *ast_start_edge_offset;
    struct ast_threshold                                *ast_threshold;
    struct ast_timing_check_limit                       *ast_timing_check_limit;
    struct ast_timing_check_event                       *ast_timing_check_event;
    struct ast_controlled_timing_check_event            *ast_controlled_timing_check_event;
    struct ast_timing_check_event_control               *ast_timing_check_event_control;
    struct ast_specify_terminal_descriptor              *ast_specify_terminal_descriptor;
    struct ast_edge_control_specifier                   *ast_edge_control_specifier;
    struct ast_edge_descriptor                          *ast_edge_descriptor;
    struct ast_zero_or_one                              *ast_zero_or_one;
    struct ast_z_or_x                                   *ast_z_or_x;
    struct ast_timing_check_condition                   *ast_timing_check_condition;
    struct ast_scalar_timing_check_condition            *ast_scalar_timing_check_condition;
    struct ast_scalar_constant                          *ast_scalar_constant;
    struct ast_concatenation                            *ast_concatenation;
    struct ast_constant_concatenation                   *ast_constant_concatenation;
    struct ast_constant_multiple_concatenation          *ast_constant_multiple_concatenation;
    struct ast_module_path_concatenation                *ast_module_path_concatenation;
    struct ast_module_path_multiple_concatenation       *ast_module_path_multiple_concatenation;
    struct ast_multiple_concatenation                   *ast_multiple_concatenation;
    struct ast_streaming_concatenation                  *ast_streaming_concatenation;
    struct ast_stream_operator                          *ast_stream_operator;
    struct ast_slice_size                               *ast_slice_size;
    struct ast_stream_concatenation                     *ast_stream_concatenation;
    struct ast_stream_expression                        *ast_stream_expression;
    struct ast_array_range_expression                   *ast_array_range_expression;
    struct ast_empty_queue                              *ast_empty_queue;
    struct ast_constant_function_call                   *ast_constant_function_call;
    struct ast_tf_call                                  *ast_tf_call;
    struct ast_system_tf_call                           *ast_system_tf_call;
    struct ast_subroutine_call                          *ast_subroutine_call;
    struct ast_function_subroutine_call                 *ast_function_subroutine_call;
    struct ast_list_of_arguments                        *ast_list_of_arguments;
    struct ast_method_call                              *ast_method_call;
    struct ast_method_call_body                         *ast_method_call_body;
    struct ast_built_in_method_call                     *ast_built_in_method_call;
    struct ast_array_manipulation_call                  *ast_array_manipulation_call;
    struct ast_randomize_call                           *ast_randomize_call;
    struct ast_method_call_root                         *ast_method_call_root;
    struct ast_array_method_name                        *ast_array_method_name;
    struct ast_inc_or_dec_expression                    *ast_inc_or_dec_expression;
    struct ast_conditional_expression                   *ast_conditional_expression;
    struct ast_constant_expression                      *ast_constant_expression;
    struct ast_constant_mintypmax_expression            *ast_constant_mintypmax_expression;
    struct ast_constant_param_expression                *ast_constant_param_expression;
    struct ast_param_expression                         *ast_param_expression;
    struct ast_constant_range_expression                *ast_constant_range_expression;
    struct ast_constant_part_select_range               *ast_constant_part_select_range;
    struct ast_constant_range                           *ast_constant_range;
    struct ast_constant_indexed_range                   *ast_constant_indexed_range;
    struct ast_expression                               *ast_expression;
    struct ast_tagged_union_expression                  *ast_tagged_union_expression;
    struct ast_inside_expression                        *ast_inside_expression;
    struct ast_value_range                              *ast_value_range;
    struct ast_mintypmax_expression                     *ast_mintypmax_expression;
    struct ast_module_path_conditional_expression       *ast_module_path_conditional_expression;
    struct ast_module_path_expression                   *ast_module_path_expression;
    struct ast_module_path_mintypmax_expression         *ast_module_path_mintypmax_expression;
    struct ast_part_select_range                        *ast_part_select_range;
    struct ast_indexed_range                            *ast_indexed_range;
    struct ast_genvar_expression                        *ast_genvar_expression;
    struct ast_constant_primary                         *ast_constant_primary;
    struct ast_module_path_primary                      *ast_module_path_primary;
    struct ast_primary                                  *ast_primary;
    struct ast_class_qualifier                          *ast_class_qualifier;
    struct ast_range_expression                         *ast_range_expression;
    struct ast_primary_literal                          *ast_primary_literal;
    struct ast_time_literal                             *ast_time_literal;
    struct ast_time_unit                                *ast_time_unit;
    struct ast_implicit_class_handle                    *ast_implicit_class_handle;
    struct ast_bit_select                               *ast_bit_select;
    struct ast_select                                   *ast_select;
    struct ast_nonrange_select                          *ast_nonrange_select;
    struct ast_constant_bit_select                      *ast_constant_bit_select;
    struct ast_constant_select                          *ast_constant_select;
    struct ast_constant_cast                            *ast_constant_cast;
    struct ast_constant_let_expression                  *ast_constant_let_expression;
    struct ast_cast                                     *ast_cast;
    struct ast_net_lvalue                               *ast_net_lvalue;
    struct ast_variable_lvalue                          *ast_variable_lvalue;
    struct ast_nonrange_variable_lvalue                 *ast_nonrange_variable_lvalue;
    struct ast_unary_operator                           *ast_unary_operator;
    struct ast_binary_operator                          *ast_binary_operator;
    struct ast_inc_or_dec_operator                      *ast_inc_or_dec_operator;
    struct ast_unary_module_path_operator               *ast_unary_module_path_operator;
    struct ast_binary_module_path_operator              *ast_binary_module_path_operator;
    struct ast_number                                   *ast_number;
    struct ast_integral_number                          *ast_integral_number;
    struct ast_decimal_number                           *ast_decimal_number;
    struct ast_octal_number                             *ast_octal_number;
    struct ast_binary_number                            *ast_binary_number;
    struct ast_hex_number                               *ast_hex_number;
    struct ast_unsigned_number                          *ast_unsigned_number;
    struct ast_real_number                              *ast_real_number;
    struct ast_fixed_point_number                       *ast_fixed_point_number;
    struct ast_unbased_unsized_literal                  *ast_unbased_unsized_literal;
    struct ast_string_literal                           *ast_string_literal;
    struct ast_attribute_instance                       *ast_attribute_instance;
    struct ast_attr_spec                                *ast_attr_spec;
    struct ast_attr_name                                *ast_attr_name;
    struct ast_block_identifier                         *ast_block_identifier;
    struct ast_bin_identifier                           *ast_bin_identifier;
    struct ast_c_identifier                             *ast_c_identifier;
    struct ast_cell_identifier                          *ast_cell_identifier;
    struct ast_checker_identifier                       *ast_checker_identifier;
    struct ast_class_identifier                         *ast_class_identifier;
    struct ast_class_variable_identifier                *ast_class_variable_identifier;
    struct ast_clocking_identifier                      *ast_clocking_identifier;
    struct ast_config_identifier                        *ast_config_identifier;
    struct ast_const_identifier                         *ast_const_identifier;
    struct ast_constraint_identifier                    *ast_constraint_identifier;
    struct ast_covergroup_identifier                    *ast_covergroup_identifier;
    struct ast_cover_point_identifier                   *ast_cover_point_identifier;
    struct ast_cross_identifier                         *ast_cross_identifier;
    struct ast_dynamic_array_variable_identifier        *ast_dynamic_array_variable_identifier;
    struct ast_enum_identifier                          *ast_enum_identifier;
    struct ast_escaped_identifier                       *ast_escaped_identifier;
    struct ast_formal_port_identifier                   *ast_formal_port_identifier;
    struct ast_function_identifier                      *ast_function_identifier;
    struct ast_generate_block_identifier                *ast_generate_block_identifier;
    struct ast_genvar_identifier                        *ast_genvar_identifier;
    struct ast_hierarchical_array_identifier            *ast_hierarchical_array_identifier;
    struct ast_hierarchical_block_identifier            *ast_hierarchical_block_identifier;
    struct ast_hierarchical_event_identifier            *ast_hierarchical_event_identifier;
    struct ast_hierarchical_identifier                  *ast_hierarchical_identifier;
    struct ast_hierarchical_net_identifier              *ast_hierarchical_net_identifier;
    struct ast_hierarchical_parameter_identifier        *ast_hierarchical_parameter_identifier;
    struct ast_hierarchical_property_identifier         *ast_hierarchical_property_identifier;
    struct ast_hierarchical_sequence_identifier         *ast_hierarchical_sequence_identifier;
    struct ast_hierarchical_task_identifier             *ast_hierarchical_task_identifier;
    struct ast_hierarchical_tf_identifier               *ast_hierarchical_tf_identifier;
    struct ast_hierarchical_variable_identifier         *ast_hierarchical_variable_identifier;
    struct ast_identifier                               *ast_identifier;
    struct ast_index_variable_identifier                *ast_index_variable_identifier;
    struct ast_interface_identifier                     *ast_interface_identifier;
    struct ast_interface_instance_identifier            *ast_interface_instance_identifier;
    struct ast_inout_port_identifier                    *ast_inout_port_identifier;
    struct ast_input_port_identifier                    *ast_input_port_identifier;
    struct ast_instance_identifier                      *ast_instance_identifier;
    struct ast_library_identifier                       *ast_library_identifier;
    struct ast_member_identifier                        *ast_member_identifier;
    struct ast_method_identifier                        *ast_method_identifier;
    struct ast_modport_identifier                       *ast_modport_identifier;
    struct ast_module_identifier                        *ast_module_identifier;
    struct ast_net_identifier                           *ast_net_identifier;
    struct ast_net_type_identifier                      *ast_net_type_identifier;
    struct ast_output_port_identifier                   *ast_output_port_identifier;
    struct ast_package_identifier                       *ast_package_identifier;
    struct ast_package_scope                            *ast_package_scope;
    struct ast_parameter_identifier                     *ast_parameter_identifier;
    struct ast_port_identifier                          *ast_port_identifier;
    struct ast_production_identifier                    *ast_production_identifier;
    struct ast_program_identifier                       *ast_program_identifier;
    struct ast_property_identifier                      *ast_property_identifier;
    struct ast_ps_class_identifier                      *ast_ps_class_identifier;
    struct ast_ps_covergroup_identifier                 *ast_ps_covergroup_identifier;
    struct ast_ps_checker_identifier                    *ast_ps_checker_identifier;
    struct ast_ps_identifier                            *ast_ps_identifier;
    struct ast_ps_or_hierarchical_array_identifier      *ast_ps_or_hierarchical_array_identifier;
    struct ast_ps_or_hierarchical_net_identifier        *ast_ps_or_hierarchical_net_identifier;
    struct ast_ps_or_hierarchical_property_identifier   *ast_ps_or_hierarchical_property_identifier;
    struct ast_ps_or_hierarchical_sequence_identifier   *ast_ps_or_hierarchical_sequence_identifier;
    struct ast_ps_or_hierarchical_tf_identifier         *ast_ps_or_hierarchical_tf_identifier;
    struct ast_ps_parameter_identifier                  *ast_ps_parameter_identifier;
    struct ast_ps_type_identifier                       *ast_ps_type_identifier;
    struct ast_sequence_identifier                      *ast_sequence_identifier;
    struct ast_signal_identifier                        *ast_signal_identifier;
    struct ast_simple_identifier                        *ast_simple_identifier;
    struct ast_specparam_identifier                     *ast_specparam_identifier;
    struct ast_system_tf_identifier                     *ast_system_tf_identifier;
    struct ast_task_identifier                          *ast_task_identifier;
    struct ast_tf_identifier                            *ast_tf_identifier;
    struct ast_terminal_identifier                      *ast_terminal_identifier;
    struct ast_topmodule_identifier                     *ast_topmodule_identifier;
    struct ast_type_identifier                          *ast_type_identifier;
    struct ast_udp_identifier                           *ast_udp_identifier;
    struct ast_variable_identifier                      *ast_variable_identifier;
    struct ast_file_path_spec                           *ast_file_path_spec;
}




%token TOKEN_0     /* ; */
%token TOKEN_1     /* library */
%token TOKEN_2     /* , */
%token TOKEN_3     /* -incdir */
%token TOKEN_4     /* include */
%token TOKEN_5     /* endmodule */
%token TOKEN_6     /* : */
%token TOKEN_7     /* extern */
%token TOKEN_8     /* module */
%token TOKEN_9     /* macromodule */
%token TOKEN_10    /* endinterface */
%token TOKEN_11    /* interface */
%token TOKEN_12    /* ( */
%token TOKEN_13    /* .* */
%token TOKEN_14    /* ) */
%token TOKEN_15    /* endprogram */
%token TOKEN_16    /* program */
%token TOKEN_17    /* checker */
%token TOKEN_18    /* endchecker */
%token TOKEN_19    /* virtual */
%token TOKEN_20    /* class */
%token TOKEN_21    /* extends */
%token TOKEN_22    /* implements */
%token TOKEN_23    /* endclass */
%token TOKEN_24    /* package */
%token TOKEN_25    /* endpackage */
%token TOKEN_26    /* timeunit */
%token TOKEN_27    /* / */
%token TOKEN_28    /* timeprecision */
%token TOKEN_29    /* # */
%token TOKEN_30    /* type */
%token TOKEN_31    /* . */
%token TOKEN_32    /* { */
%token TOKEN_33    /* } */
%token TOKEN_34    /* input */
%token TOKEN_35    /* output */
%token TOKEN_36    /* inout */
%token TOKEN_37    /* ref */
%token TOKEN_38    /* = */
%token TOKEN_39    /* dollarsign_fatal */
%token TOKEN_40    /* dollarsign_error */
%token TOKEN_41    /* dollarsign_warning */
%token TOKEN_42    /* dollarsign_info */
%token TOKEN_43    /* 0 */
%token TOKEN_44    /* 1 */
%token TOKEN_45    /* 2 */
%token TOKEN_46    /* default */
%token TOKEN_47    /* clocking */
%token TOKEN_48    /* disable */
%token TOKEN_49    /* iff */
%token TOKEN_50    /* defparam */
%token TOKEN_51    /* bind */
%token TOKEN_52    /* config */
%token TOKEN_53    /* endconfig */
%token TOKEN_54    /* design */
%token TOKEN_55    /* instance */
%token TOKEN_56    /* cell */
%token TOKEN_57    /* liblist */
%token TOKEN_58    /* use */
%token TOKEN_59    /* forkjoin */
%token TOKEN_60    /* rand */
%token TOKEN_61    /* const */
%token TOKEN_62    /* pure */
%token TOKEN_63    /* function */
%token TOKEN_64    /* new */
%token TOKEN_65    /* static */
%token TOKEN_66    /* protected */
%token TOKEN_67    /* local */
%token TOKEN_68    /* randc */
%token TOKEN_69    /* super */
%token TOKEN_70    /* endfunction */
%token TOKEN_71    /* constraint */
%token TOKEN_72    /* solve */
%token TOKEN_73    /* before */
%token TOKEN_74    /* soft */
%token TOKEN_75    /* -> */
%token TOKEN_76    /* if */
%token TOKEN_77    /* else */
%token TOKEN_78    /* foreach */
%token TOKEN_79    /* [ */
%token TOKEN_80    /* ] */
%token TOKEN_81    /* unique */
%token TOKEN_82    /* := */
%token TOKEN_83    /* :/ */
%token TOKEN_84    /* localparam */
%token TOKEN_85    /* parameter */
%token TOKEN_86    /* specparam */
%token TOKEN_87    /* var */
%token TOKEN_88    /* import */
%token TOKEN_89    /* :: */
%token TOKEN_90    /* * */
%token TOKEN_91    /* export */
%token TOKEN_92    /* *::* */
%token TOKEN_93    /* genvar */
%token TOKEN_94    /* vectored */
%token TOKEN_95    /* scalared */
%token TOKEN_96    /* interconnect */
%token TOKEN_97    /* typedef */
%token TOKEN_98    /* enum */
%token TOKEN_99    /* struct */
%token TOKEN_100   /* union */
%token TOKEN_101   /* nettype */
%token TOKEN_102   /* with */
%token TOKEN_103   /* automatic */
%token TOKEN_104   /* string */
%token TOKEN_105   /* packed */
%token TOKEN_106   /* chandle */
%token TOKEN_107   /* event */
%token TOKEN_108   /* byte */
%token TOKEN_109   /* shortint */
%token TOKEN_110   /* int */
%token TOKEN_111   /* longint */
%token TOKEN_112   /* integer */
%token TOKEN_113   /* time */
%token TOKEN_114   /* bit */
%token TOKEN_115   /* logic */
%token TOKEN_116   /* reg */
%token TOKEN_117   /* shortreal */
%token TOKEN_118   /* real */
%token TOKEN_119   /* realtime */
%token TOKEN_120   /* supply0 */
%token TOKEN_121   /* supply1 */
%token TOKEN_122   /* tri */
%token TOKEN_123   /* triand */
%token TOKEN_124   /* trior */
%token TOKEN_125   /* trireg */
%token TOKEN_126   /* tri0 */
%token TOKEN_127   /* tri1 */
%token TOKEN_128   /* uwire */
%token TOKEN_129   /* wire */
%token TOKEN_130   /* wand */
%token TOKEN_131   /* wor */
%token TOKEN_132   /* signed */
%token TOKEN_133   /* unsigned */
%token TOKEN_134   /* void */
%token TOKEN_135   /* tagged */
%token TOKEN_136   /* highz1 */
%token TOKEN_137   /* highz0 */
%token TOKEN_138   /* strong0 */
%token TOKEN_139   /* pull0 */
%token TOKEN_140   /* weak0 */
%token TOKEN_141   /* strong1 */
%token TOKEN_142   /* pull1 */
%token TOKEN_143   /* weak1 */
%token TOKEN_144   /* small */
%token TOKEN_145   /* medium */
%token TOKEN_146   /* large */
%token TOKEN_147   /* 1step */
%token TOKEN_148   /* PATHPULSEdollarsign_ */
%token TOKEN_149   /* dollarsign_ */
%token TOKEN_150   /* task */
%token TOKEN_151   /* DPI-C */
%token TOKEN_152   /* DPI */
%token TOKEN_153   /* context */
%token TOKEN_154   /* endtask */
%token TOKEN_155   /* + */
%token TOKEN_156   /* ++ */
%token TOKEN_157   /* - */
%token TOKEN_158   /* -- */
%token TOKEN_159   /* ** */
%token TOKEN_160   /* % */
%token TOKEN_161   /* == */
%token TOKEN_162   /* != */
%token TOKEN_163   /* < */
%token TOKEN_164   /* <= */
%token TOKEN_165   /* > */
%token TOKEN_166   /* >= */
%token TOKEN_167   /* modport */
%token TOKEN_168   /* assert */
%token TOKEN_169   /* property */
%token TOKEN_170   /* assume */
%token TOKEN_171   /* cover */
%token TOKEN_172   /* expect */
%token TOKEN_173   /* sequence */
%token TOKEN_174   /* restrict */
%token TOKEN_175   /* endproperty */
%token TOKEN_176   /* strong */
%token TOKEN_177   /* weak */
%token TOKEN_178   /* not */
%token TOKEN_179   /* or */
%token TOKEN_180   /* and */
%token TOKEN_181   /* |-> */
%token TOKEN_182   /* |=> */
%token TOKEN_183   /* case */
%token TOKEN_184   /* endcase */
%token TOKEN_185   /* #-# */
%token TOKEN_186   /* #=# */
%token TOKEN_187   /* nexttime */
%token TOKEN_188   /* s_nexttime */
%token TOKEN_189   /* always */
%token TOKEN_190   /* s_always */
%token TOKEN_191   /* s_eventually */
%token TOKEN_192   /* until */
%token TOKEN_193   /* s_until */
%token TOKEN_194   /* until_with */
%token TOKEN_195   /* s_until_with */
%token TOKEN_196   /* implies */
%token TOKEN_197   /* accept_on */
%token TOKEN_198   /* reject_on */
%token TOKEN_199   /* sync_accept_on */
%token TOKEN_200   /* sync_reject_on */
%token TOKEN_201   /* endsequence */
%token TOKEN_202   /* untyped */
%token TOKEN_203   /* intersect */
%token TOKEN_204   /* first_match */
%token TOKEN_205   /* throughout */
%token TOKEN_206   /* within */
%token TOKEN_207   /* ## */
%token TOKEN_208   /* [*] */
%token TOKEN_209   /* [+] */
%token TOKEN_210   /* [* */
%token TOKEN_211   /* [= */
%token TOKEN_212   /* [-> */
%token TOKEN_213   /* dist */
%token TOKEN_214   /* let */
%token TOKEN_215   /* covergroup */
%token TOKEN_216   /* endgroup */
%token TOKEN_217   /* option */
%token TOKEN_218   /* type_option */
%token TOKEN_219   /* sample */
%token TOKEN_220   /* @@ */
%token TOKEN_221   /* begin */
%token TOKEN_222   /* end */
%token TOKEN_223   /* coverpoint */
%token TOKEN_224   /* wildcard */
%token TOKEN_225   /* bins */
%token TOKEN_226   /* illegal_bins */
%token TOKEN_227   /* ignore_bins */
%token TOKEN_228   /* => */
%token TOKEN_229   /* cross */
%token TOKEN_230   /* ! */
%token TOKEN_231   /* && */
%token TOKEN_232   /* || */
%token TOKEN_233   /* matches */
%token TOKEN_234   /* binsof */
%token TOKEN_235   /* pulldown */
%token TOKEN_236   /* pullup */
%token TOKEN_237   /* cmos */
%token TOKEN_238   /* rcmos */
%token TOKEN_239   /* bufif0 */
%token TOKEN_240   /* bufif1 */
%token TOKEN_241   /* notif0 */
%token TOKEN_242   /* notif1 */
%token TOKEN_243   /* nmos */
%token TOKEN_244   /* pmos */
%token TOKEN_245   /* rnmos */
%token TOKEN_246   /* rpmos */
%token TOKEN_247   /* nand */
%token TOKEN_248   /* nor */
%token TOKEN_249   /* xor */
%token TOKEN_250   /* xnor */
%token TOKEN_251   /* buf */
%token TOKEN_252   /* tranif0 */
%token TOKEN_253   /* tranif1 */
%token TOKEN_254   /* rtranif0 */
%token TOKEN_255   /* rtranif1 */
%token TOKEN_256   /* tran */
%token TOKEN_257   /* rtran */
%token TOKEN_258   /* generate */
%token TOKEN_259   /* endgenerate */
%token TOKEN_260   /* for */
%token TOKEN_261   /* primitive */
%token TOKEN_262   /* endprimitive */
%token TOKEN_263   /* table */
%token TOKEN_264   /* endtable */
%token TOKEN_265   /* initial */
%token TOKEN_266   /* 1'b0 */
%token TOKEN_267   /* 1'b1 */
%token TOKEN_268   /* 1'bx */
%token TOKEN_269   /* 1'bX */
%token TOKEN_270   /* 1'B0 */
%token TOKEN_271   /* 1'B1 */
%token TOKEN_272   /* 1'Bx */
%token TOKEN_273   /* 1'BX */
%token TOKEN_274   /* x */
%token TOKEN_275   /* X */
%token TOKEN_276   /* ? */
%token TOKEN_277   /* b */
%token TOKEN_278   /* B */
%token TOKEN_279   /* r */
%token TOKEN_280   /* R */
%token TOKEN_281   /* f */
%token TOKEN_282   /* F */
%token TOKEN_283   /* p */
%token TOKEN_284   /* P */
%token TOKEN_285   /* n */
%token TOKEN_286   /* N */
%token TOKEN_287   /* assign */
%token TOKEN_288   /* alias */
%token TOKEN_289   /* always_comb */
%token TOKEN_290   /* always_latch */
%token TOKEN_291   /* always_ff */
%token TOKEN_292   /* final */
%token TOKEN_293   /* += */
%token TOKEN_294   /* -= */
%token TOKEN_295   /* *= */
%token TOKEN_296   /* /= */
%token TOKEN_297   /* %= */
%token TOKEN_298   /* &= */
%token TOKEN_299   /* |= */
%token TOKEN_300   /* ^= */
%token TOKEN_301   /* <<= */
%token TOKEN_302   /* >>= */
%token TOKEN_303   /* <<<= */
%token TOKEN_304   /* >>>= */
%token TOKEN_305   /* deassign */
%token TOKEN_306   /* force */
%token TOKEN_307   /* release */
%token TOKEN_308   /* fork */
%token TOKEN_309   /* join */
%token TOKEN_310   /* join_any */
%token TOKEN_311   /* join_none */
%token TOKEN_312   /* repeat */
%token TOKEN_313   /* @ */
%token TOKEN_314   /* return */
%token TOKEN_315   /* break */
%token TOKEN_316   /* continue */
%token TOKEN_317   /* wait */
%token TOKEN_318   /* wait_order */
%token TOKEN_319   /* ->> */
%token TOKEN_320   /* unique0 */
%token TOKEN_321   /* priority */
%token TOKEN_322   /* &&& */
%token TOKEN_323   /* inside */
%token TOKEN_324   /* casex */
%token TOKEN_325   /* casez */
%token TOKEN_326   /* randcase */
%token TOKEN_327   /* ' */
%token TOKEN_328   /* forever */
%token TOKEN_329   /* while */
%token TOKEN_330   /* do */
%token TOKEN_331   /* #0 */
%token TOKEN_332   /* endclocking */
%token TOKEN_333   /* global */
%token TOKEN_334   /* randsequence */
%token TOKEN_335   /* | */
%token TOKEN_336   /* specify */
%token TOKEN_337   /* endspecify */
%token TOKEN_338   /* pulsestyle_onevent */
%token TOKEN_339   /* pulsestyle_ondetect */
%token TOKEN_340   /* showcancelled */
%token TOKEN_341   /* noshowcancelled */
%token TOKEN_342   /* *> */
%token TOKEN_343   /* posedge */
%token TOKEN_344   /* negedge */
%token TOKEN_345   /* edge */
%token TOKEN_346   /* ifnone */
%token TOKEN_347   /* dollarsign_setup */
%token TOKEN_348   /* dollarsign_hold */
%token TOKEN_349   /* dollarsign_setuphold */
%token TOKEN_350   /* dollarsign_recovery */
%token TOKEN_351   /* dollarsign_removal */
%token TOKEN_352   /* dollarsign_recrem */
%token TOKEN_353   /* dollarsign_skew */
%token TOKEN_354   /* dollarsign_timeskew */
%token TOKEN_355   /* dollarsign_fullskew */
%token TOKEN_356   /* dollarsign_period */
%token TOKEN_357   /* dollarsign_width */
%token TOKEN_358   /* dollarsign_nochange */
%token TOKEN_359   /* 01 */
%token TOKEN_360   /* 10 */
%token TOKEN_361   /* z */
%token TOKEN_362   /* Z */
%token TOKEN_363   /* ~ */
%token TOKEN_364   /* === */
%token TOKEN_365   /* !== */
%token TOKEN_366   /* 'b0 */
%token TOKEN_367   /* 'b1 */
%token TOKEN_368   /* 'B0 */
%token TOKEN_369   /* 'B1 */
%token TOKEN_370   /* >> */
%token TOKEN_371   /* << */
%token TOKEN_372   /* +: */
%token TOKEN_373   /* -: */
%token TOKEN_374   /* std:: */
%token TOKEN_375   /* randomize */
%token TOKEN_376   /* null */
%token TOKEN_377   /* this */
%token TOKEN_378   /* local:: */
%token TOKEN_379   /* s */
%token TOKEN_380   /* ms */
%token TOKEN_381   /* us */
%token TOKEN_382   /* ns */
%token TOKEN_383   /* ps */
%token TOKEN_384   /* fs */
%token TOKEN_385   /* & */
%token TOKEN_386   /* ~& */
%token TOKEN_387   /* ~| */
%token TOKEN_388   /* ^ */
%token TOKEN_389   /* ~^ */
%token TOKEN_390   /* ^~ */
%token TOKEN_391   /* ==? */
%token TOKEN_392   /* !=? */
%token TOKEN_393   /* >>> */
%token TOKEN_394   /* <<< */
%token TOKEN_395   /* <-> */
%token TOKEN_396   /* '0 */
%token TOKEN_397   /* '1 */
%token TOKEN_398   /* (* */
%token TOKEN_399   /* *) */
%token TOKEN_400   /* dollarsign_unit */
%token SV_UNSIGNED_NUMBER /* SV_UNSIGNED_NUMBER */
%token SV_DECIMAL_NUMBER /* SV_DECIMAL_NUMBER */
%token SV_OCTAL_NUMBER /* SV_OCTAL_NUMBER */
%token SV_BINARY_NUMBER /* SV_BINARY_NUMBER */
%token SV_HEX_NUMBER /* SV_HEX_NUMBER */
%token SV_UNSIGNED_INTEGER /* SV_UNSIGNED_INTEGER */
%token SV_EXPONENTIAL_NUMBER /* SV_EXPONENTIAL_NUMBER */
%token SV_FIXED_POINT_NUMBER /* SV_FIXED_POINT_NUMBER */
%token SV_STRING    /* SV_STRING */
%token SV_ESCAPED_IDENTIFIER /* SV_ESCAPED_IDENTIFIER */
%token SV_IDENTIFIER /* SV_IDENTIFIER */
%token FILE_PATH    /* FILE_PATH */
%token SV_INTEGER

%type <ast_library_text>                               library_text
%type <ast_library_description>                        library_description
%type <ast_library_declaration>                        library_declaration
%type <ast_include_statement>                          include_statement
%type <ast_source_text>                                source_text
%type <ast_description>                                description
%type <ast_module_nonansi_header>                      module_nonansi_header
%type <ast_module_ansi_header>                         module_ansi_header
%type <ast_module_declaration>                         module_declaration
%type <ast_module_keyword>                             module_keyword
%type <ast_interface_declaration>                      interface_declaration
%type <ast_interface_nonansi_header>                   interface_nonansi_header
%type <ast_interface_ansi_header>                      interface_ansi_header
%type <ast_program_declaration>                        program_declaration
%type <ast_program_nonansi_header>                     program_nonansi_header
%type <ast_program_ansi_header>                        program_ansi_header
%type <ast_checker_declaration>                        checker_declaration
%type <ast_class_declaration>                          class_declaration
%type <ast_interface_class_type>                       interface_class_type
%type <ast_package_declaration>                        package_declaration
%type <ast_timeunits_declaration>                      timeunits_declaration
%type <ast_parameter_port_list>                        parameter_port_list
%type <ast_parameter_port_declaration>                 parameter_port_declaration
%type <ast_list_of_ports>                              list_of_ports
%type <ast_list_of_port_declarations>                  list_of_port_declarations
%type <ast_port_declaration>                           port_declaration
%type <ast_port>                                       port
%type <ast_port_expression>                            port_expression
%type <ast_port_reference>                             port_reference
%type <ast_port_direction>                             port_direction
%type <ast_net_port_header>                            net_port_header
%type <ast_variable_port_header>                       variable_port_header
%type <ast_interface_port_header>                      interface_port_header
%type <ast_ansi_port_declaration>                      ansi_port_declaration
%type <ast_elaboration_system_task>                    elaboration_system_task
%type <ast_finish_number>                              finish_number
%type <ast_module_common_item>                         module_common_item
%type <ast_module_item>                                module_item
%type <ast_module_or_generate_item>                    module_or_generate_item
%type <ast_module_or_generate_item_declaration>        module_or_generate_item_declaration
%type <ast_non_port_module_item>                       non_port_module_item
%type <ast_parameter_override>                         parameter_override
%type <ast_bind_directive>                             bind_directive
%type <ast_bind_target_scope>                          bind_target_scope
%type <ast_bind_target_instance>                       bind_target_instance
%type <ast_bind_target_instance_list>                  bind_target_instance_list
%type <ast_bind_instantiation>                         bind_instantiation
%type <ast_config_declaration>                         config_declaration
%type <ast_design_statement>                           design_statement
%type <ast_config_rule_statement>                      config_rule_statement
%type <ast_default_clause>                             default_clause
%type <ast_inst_clause>                                inst_clause
%type <ast_inst_name>                                  inst_name
%type <ast_cell_clause>                                cell_clause
%type <ast_liblist_clause>                             liblist_clause
%type <ast_use_clause>                                 use_clause
%type <ast_interface_or_generate_item>                 interface_or_generate_item
%type <ast_extern_tf_declaration>                      extern_tf_declaration
%type <ast_interface_item>                             interface_item
%type <ast_non_port_interface_item>                    non_port_interface_item
%type <ast_program_item>                               program_item
%type <ast_non_port_program_item>                      non_port_program_item
%type <ast_program_generate_item>                      program_generate_item
%type <ast_checker_port_list>                          checker_port_list
%type <ast_checker_port_item>                          checker_port_item
%type <ast_checker_port_direction>                     checker_port_direction
%type <ast_checker_or_generate_item>                   checker_or_generate_item
%type <ast_checker_or_generate_item_declaration>       checker_or_generate_item_declaration
%type <ast_checker_generate_item>                      checker_generate_item
%type <ast_class_item>                                 class_item
%type <ast_class_property>                             class_property
%type <ast_class_method>                               class_method
%type <ast_class_constructor_prototype>                class_constructor_prototype
%type <ast_class_constraint>                           class_constraint
%type <ast_class_item_qualifier>                       class_item_qualifier
%type <ast_property_qualifier>                         property_qualifier
%type <ast_random_qualifier>                           random_qualifier
%type <ast_method_qualifier>                           method_qualifier
%type <ast_method_prototype>                           method_prototype
%type <ast_class_constructor_declaration>              class_constructor_declaration
%type <ast_constraint_declaration>                     constraint_declaration
%type <ast_constraint_block>                           constraint_block
%type <ast_constraint_block_item>                      constraint_block_item
%type <ast_solve_before_list>                          solve_before_list
%type <ast_constraint_primary>                         constraint_primary
%type <ast_constraint_expression>                      constraint_expression
%type <ast_uniqueness_constraint>                      uniqueness_constraint
%type <ast_constraint_set>                             constraint_set
%type <ast_dist_list>                                  dist_list
%type <ast_dist_item>                                  dist_item
%type <ast_dist_weight>                                dist_weight
%type <ast_constraint_prototype>                       constraint_prototype
%type <ast_constraint_prototype_qualifier>             constraint_prototype_qualifier
%type <ast_extern_constraint_declaration>              extern_constraint_declaration
%type <ast_identifier_list>                            identifier_list
%type <ast_package_item>                               package_item
%type <ast_package_or_generate_item_declaration>       package_or_generate_item_declaration
%type <ast_anonymous_program>                          anonymous_program
%type <ast_anonymous_program_item>                     anonymous_program_item
%type <ast_local_parameter_declaration>                local_parameter_declaration
%type <ast_parameter_declaration>                      parameter_declaration
%type <ast_specparam_declaration>                      specparam_declaration
%type <ast_inout_declaration>                          inout_declaration
%type <ast_input_declaration>                          input_declaration
%type <ast_output_declaration>                         output_declaration
%type <ast_interface_port_declaration>                 interface_port_declaration
%type <ast_ref_declaration>                            ref_declaration
%type <ast_data_declaration>                           data_declaration
%type <ast_package_import_declaration>                 package_import_declaration
%type <ast_package_import_item>                        package_import_item
%type <ast_package_export_declaration>                 package_export_declaration
%type <ast_genvar_declaration>                         genvar_declaration
%type <ast_net_declaration>                            net_declaration
%type <ast_type_declaration>                           type_declaration
%type <ast_net_type_declaration>                       net_type_declaration
%type <ast_lifetime>                                   lifetime
%type <ast_casting_type>                               casting_type
%type <ast_data_type>                                  data_type
%type <ast_data_type_or_implicit>                      data_type_or_implicit
%type <ast_implicit_data_type>                         implicit_data_type
%type <ast_enum_base_type>                             enum_base_type
%type <ast_enum_name_declaration>                      enum_name_declaration
%type <ast_class_scope>                                class_scope
%type <ast_class_type>                                 class_type
%type <ast_integer_type>                               integer_type
%type <ast_integer_atom_type>                          integer_atom_type
%type <ast_integer_vector_type>                        integer_vector_type
%type <ast_non_integer_type>                           non_integer_type
%type <ast_net_type>                                   net_type
%type <ast_net_port_type>                              net_port_type
%type <ast_variable_port_type>                         variable_port_type
%type <ast_var_data_type>                              var_data_type
%type <ast_signing>                                    signing
%type <ast_simple_type>                                simple_type
%type <ast_struct_union_member>                        struct_union_member
%type <ast_data_type_or_void>                          data_type_or_void
%type <ast_struct_union>                               struct_union
%type <ast_type_reference>                             type_reference
%type <ast_drive_strength>                             drive_strength
%type <ast_strength0>                                  strength0
%type <ast_strength1>                                  strength1
%type <ast_charge_strength>                            charge_strength
%type <ast_delay3>                                     delay3
%type <ast_delay2>                                     delay2
%type <ast_delay_value>                                delay_value
%type <ast_list_of_defparam_assignments>               list_of_defparam_assignments
%type <ast_list_of_genvar_identifiers>                 list_of_genvar_identifiers
%type <ast_list_of_interface_identifiers>              list_of_interface_identifiers
%type <ast_list_of_net_decl_assignments>               list_of_net_decl_assignments
%type <ast_list_of_param_assignments>                  list_of_param_assignments
%type <ast_list_of_port_identifiers>                   list_of_port_identifiers
%type <ast_list_of_udp_port_identifiers>               list_of_udp_port_identifiers
%type <ast_list_of_specparam_assignments>              list_of_specparam_assignments
%type <ast_list_of_tf_variable_identifiers>            list_of_tf_variable_identifiers
%type <ast_list_of_type_assignments>                   list_of_type_assignments
%type <ast_list_of_variable_decl_assignments>          list_of_variable_decl_assignments
%type <ast_list_of_variable_identifiers>               list_of_variable_identifiers
%type <ast_list_of_variable_port_identifiers>          list_of_variable_port_identifiers
%type <ast_defparam_assignment>                        defparam_assignment
%type <ast_net_decl_assignment>                        net_decl_assignment
%type <ast_param_assignment>                           param_assignment
%type <ast_specparam_assignment>                       specparam_assignment
%type <ast_type_assignment>                            type_assignment
%type <ast_pulse_control_specparam>                    pulse_control_specparam
%type <ast_error_limit_value>                          error_limit_value
%type <ast_reject_limit_value>                         reject_limit_value
%type <ast_limit_value>                                limit_value
%type <ast_variable_decl_assignment>                   variable_decl_assignment
%type <ast_class_new>                                  class_new
%type <ast_dynamic_array_new>                          dynamic_array_new
%type <ast_unpacked_dimension>                         unpacked_dimension
%type <ast_packed_dimension>                           packed_dimension
%type <ast_associative_dimension>                      associative_dimension
%type <ast_variable_dimension>                         variable_dimension
%type <ast_queue_dimension>                            queue_dimension
%type <ast_unsized_dimension>                          unsized_dimension
%type <ast_function_data_type_or_implicit>             function_data_type_or_implicit
%type <ast_function_declaration>                       function_declaration
%type <ast_function_body_declaration>                  function_body_declaration
%type <ast_function_prototype>                         function_prototype
%type <ast_dpi_import_export>                          dpi_import_export
%type <ast_dpi_spec_string>                            dpi_spec_string
%type <ast_dpi_function_import_property>               dpi_function_import_property
%type <ast_dpi_task_import_property>                   dpi_task_import_property
%type <ast_dpi_function_proto>                         dpi_function_proto
%type <ast_dpi_task_proto>                             dpi_task_proto
%type <ast_task_declaration>                           task_declaration
%type <ast_task_body_declaration>                      task_body_declaration
%type <ast_tf_item_declaration>                        tf_item_declaration
%type <ast_tf_port_list>                               tf_port_list
%type <ast_tf_port_item>                               tf_port_item
%type <ast_tf_port_direction>                          tf_port_direction
%type <ast_tf_port_declaration>                        tf_port_declaration
%type <ast_task_prototype>                             task_prototype
%type <ast_block_item_declaration>                     block_item_declaration
%type <ast_overload_declaration>                       overload_declaration
%type <ast_overload_operator>                          overload_operator
%type <ast_overload_proto_formals>                     overload_proto_formals
%type <ast_modport_declaration>                        modport_declaration
%type <ast_modport_item>                               modport_item
%type <ast_modport_ports_declaration>                  modport_ports_declaration
%type <ast_modport_clocking_declaration>               modport_clocking_declaration
%type <ast_modport_simple_ports_declaration>           modport_simple_ports_declaration
%type <ast_modport_simple_port>                        modport_simple_port
%type <ast_modport_tf_ports_declaration>               modport_tf_ports_declaration
%type <ast_modport_tf_port>                            modport_tf_port
%type <ast_import_export>                              import_export
%type <ast_concurrent_assertion_item>                  concurrent_assertion_item
%type <ast_concurrent_assertion_statement>             concurrent_assertion_statement
%type <ast_assert_property_statement>                  assert_property_statement
%type <ast_assume_property_statement>                  assume_property_statement
%type <ast_cover_property_statement>                   cover_property_statement
%type <ast_expect_property_statement>                  expect_property_statement
%type <ast_cover_sequence_statement>                   cover_sequence_statement
%type <ast_restrict_property_statement>                restrict_property_statement
%type <ast_property_instance>                          property_instance
%type <ast_property_list_of_arguments>                 property_list_of_arguments
%type <ast_property_actual_arg>                        property_actual_arg
%type <ast_assertion_item_declaration>                 assertion_item_declaration
%type <ast_property_declaration>                       property_declaration
%type <ast_property_port_list>                         property_port_list
%type <ast_property_port_item>                         property_port_item
%type <ast_property_lvar_port_direction>               property_lvar_port_direction
%type <ast_property_formal_type>                       property_formal_type
%type <ast_property_spec>                              property_spec
%type <ast_property_expr>                              property_expr
%type <ast_property_case_item>                         property_case_item
%type <ast_sequence_declaration>                       sequence_declaration
%type <ast_sequence_port_list>                         sequence_port_list
%type <ast_sequence_port_item>                         sequence_port_item
%type <ast_sequence_lvar_port_direction>               sequence_lvar_port_direction
%type <ast_sequence_formal_type>                       sequence_formal_type
%type <ast_sequence_expr>                              sequence_expr
%type <ast_cycle_delay_range>                          cycle_delay_range
%type <ast_sequence_method_call>                       sequence_method_call
%type <ast_sequence_match_item>                        sequence_match_item
%type <ast_sequence_instance>                          sequence_instance
%type <ast_sequence_list_of_arguments>                 sequence_list_of_arguments
%type <ast_sequence_actual_arg>                        sequence_actual_arg
%type <ast_boolean_abbrev>                             boolean_abbrev
%type <ast_sequence_abbrev>                            sequence_abbrev
%type <ast_consecutive_repetition>                     consecutive_repetition
%type <ast_non_consecutive_repetition>                 non_consecutive_repetition
%type <ast_goto_repetition>                            goto_repetition
%type <ast_const_or_range_expression>                  const_or_range_expression
%type <ast_cycle_delay_const_range_expression>         cycle_delay_const_range_expression
%type <ast_expression_or_dist>                         expression_or_dist
%type <ast_assertion_variable_declaration>             assertion_variable_declaration
%type <ast_let_declaration>                            let_declaration
%type <ast_let_identifier>                             let_identifier
%type <ast_let_port_list>                              let_port_list
%type <ast_let_port_item>                              let_port_item
%type <ast_let_formal_type>                            let_formal_type
%type <ast_let_expression>                             let_expression
%type <ast_let_list_of_arguments>                      let_list_of_arguments
%type <ast_let_actual_arg>                             let_actual_arg
%type <ast_covergroup_declaration>                     covergroup_declaration
%type <ast_coverage_spec_or_option>                    coverage_spec_or_option
%type <ast_coverage_option>                            coverage_option
%type <ast_coverage_spec>                              coverage_spec
%type <ast_coverage_event>                             coverage_event
%type <ast_block_event_expression>                     block_event_expression
%type <ast_hierarchical_btf_identifier>                hierarchical_btf_identifier
%type <ast_cover_point>                                cover_point
%type <ast_bins_or_empty>                              bins_or_empty
%type <ast_bins_or_options>                            bins_or_options
%type <ast_bins_keyword>                               bins_keyword
%type <ast_trans_list>                                 trans_list
%type <ast_trans_set>                                  trans_set
%type <ast_trans_range_list>                           trans_range_list
%type <ast_trans_item>                                 trans_item
%type <ast_repeat_range>                               repeat_range
%type <ast_cover_cross>                                cover_cross
%type <ast_list_of_cross_items>                        list_of_cross_items
%type <ast_cross_item>                                 cross_item
%type <ast_cross_body>                                 cross_body
%type <ast_cross_body_item>                            cross_body_item
%type <ast_bins_selection_or_option>                   bins_selection_or_option
%type <ast_bins_selection>                             bins_selection
%type <ast_select_expression>                          select_expression
%type <ast_select_condition>                           select_condition
%type <ast_bins_expression>                            bins_expression
%type <ast_covergroup_range_list>                      covergroup_range_list
%type <ast_covergroup_value_range>                     covergroup_value_range
%type <ast_with_covergroup_expression>                 with_covergroup_expression
%type <ast_set_covergroup_expression>                  set_covergroup_expression
%type <ast_integer_covergroup_expression>              integer_covergroup_expression
%type <ast_cross_set_expression>                       cross_set_expression
%type <ast_covergroup_expression>                      covergroup_expression
%type <ast_gate_instantiation>                         gate_instantiation
%type <ast_cmos_switch_instance>                       cmos_switch_instance
%type <ast_enable_gate_instance>                       enable_gate_instance
%type <ast_mos_switch_instance>                        mos_switch_instance
%type <ast_n_input_gate_instance>                      n_input_gate_instance
%type <ast_n_output_gate_instance>                     n_output_gate_instance
%type <ast_pass_switch_instance>                       pass_switch_instance
%type <ast_pass_enable_switch_instance>                pass_enable_switch_instance
%type <ast_pull_gate_instance>                         pull_gate_instance
%type <ast_pulldown_strength>                          pulldown_strength
%type <ast_pullup_strength>                            pullup_strength
%type <ast_enable_terminal>                            enable_terminal
%type <ast_inout_terminal>                             inout_terminal
%type <ast_input_terminal>                             input_terminal
%type <ast_ncontrol_terminal>                          ncontrol_terminal
%type <ast_output_terminal>                            output_terminal
%type <ast_pcontrol_terminal>                          pcontrol_terminal
%type <ast_cmos_switchtype>                            cmos_switchtype
%type <ast_enable_gatetype>                            enable_gatetype
%type <ast_mos_switchtype>                             mos_switchtype
%type <ast_n_input_gatetype>                           n_input_gatetype
%type <ast_n_output_gatetype>                          n_output_gatetype
%type <ast_pass_en_switchtype>                         pass_en_switchtype
%type <ast_pass_switchtype>                            pass_switchtype
%type <ast_module_instantiation>                       module_instantiation
%type <ast_parameter_value_assignment>                 parameter_value_assignment
%type <ast_list_of_parameter_assignments>              list_of_parameter_assignments
%type <ast_ordered_parameter_assignment>               ordered_parameter_assignment
%type <ast_named_parameter_assignment>                 named_parameter_assignment
%type <ast_hierarchical_instance>                      hierarchical_instance
%type <ast_name_of_instance>                           name_of_instance
%type <ast_list_of_port_connections>                   list_of_port_connections
%type <ast_ordered_port_connection>                    ordered_port_connection
%type <ast_named_port_connection>                      named_port_connection
%type <ast_interface_instantiation>                    interface_instantiation
%type <ast_program_instantiation>                      program_instantiation
%type <ast_checker_instantiation>                      checker_instantiation
%type <ast_list_of_checker_port_connections>           list_of_checker_port_connections
%type <ast_ordered_checker_port_connection>            ordered_checker_port_connection
%type <ast_named_checker_port_connection>              named_checker_port_connection
%type <ast_generate_region>                            generate_region
%type <ast_loop_generate_construct>                    loop_generate_construct
%type <ast_genvar_initialization>                      genvar_initialization
%type <ast_genvar_iteration>                           genvar_iteration
%type <ast_conditional_generate_construct>             conditional_generate_construct
%type <ast_if_generate_construct>                      if_generate_construct
%type <ast_case_generate_construct>                    case_generate_construct
%type <ast_case_generate_item>                         case_generate_item
%type <ast_generate_block>                             generate_block
%type <ast_generate_item>                              generate_item
%type <ast_udp_nonansi_declaration>                    udp_nonansi_declaration
%type <ast_udp_ansi_declaration>                       udp_ansi_declaration
%type <ast_udp_declaration>                            udp_declaration
%type <ast_udp_port_list>                              udp_port_list
%type <ast_udp_declaration_port_list>                  udp_declaration_port_list
%type <ast_udp_port_declaration>                       udp_port_declaration
%type <ast_udp_output_declaration>                     udp_output_declaration
%type <ast_udp_input_declaration>                      udp_input_declaration
%type <ast_udp_reg_declaration>                        udp_reg_declaration
%type <ast_udp_body>                                   udp_body
%type <ast_combinational_body>                         combinational_body
%type <ast_combinational_entry>                        combinational_entry
%type <ast_sequential_body>                            sequential_body
%type <ast_udp_initial_statement>                      udp_initial_statement
%type <ast_init_val>                                   init_val
%type <ast_sequential_entry>                           sequential_entry
%type <ast_seq_input_list>                             seq_input_list
%type <ast_level_input_list>                           level_input_list
%type <ast_edge_input_list>                            edge_input_list
%type <ast_edge_indicator>                             edge_indicator
%type <ast_current_state>                              current_state
%type <ast_next_state>                                 next_state
%type <ast_output_symbol>                              output_symbol
%type <ast_level_symbol>                               level_symbol
%type <ast_edge_symbol>                                edge_symbol
%type <ast_udp_instantiation>                          udp_instantiation
%type <ast_udp_instance>                               udp_instance
%type <ast_continuous_assign>                          continuous_assign
%type <ast_list_of_net_assignments>                    list_of_net_assignments
%type <ast_list_of_variable_assignments>               list_of_variable_assignments
%type <ast_net_alias>                                  net_alias
%type <ast_net_assignment>                             net_assignment
%type <ast_initial_construct>                          initial_construct
%type <ast_always_construct>                           always_construct
%type <ast_always_keyword>                             always_keyword
%type <ast_final_construct>                            final_construct
%type <ast_blocking_assignment>                        blocking_assignment
%type <ast_operator_assignment>                        operator_assignment
%type <ast_assignment_operator>                        assignment_operator
%type <ast_nonblocking_assignment>                     nonblocking_assignment
%type <ast_procedural_continuous_assignment>           procedural_continuous_assignment
%type <ast_variable_assignment>                        variable_assignment
%type <ast_action_block>                               action_block
%type <ast_seq_block>                                  seq_block
%type <ast_par_block>                                  par_block
%type <ast_join_keyword>                               join_keyword
%type <ast_statement_or_null>                          statement_or_null
%type <ast_statement>                                  statement
%type <ast_statement_item>                             statement_item
%type <ast_function_statement>                         function_statement
%type <ast_function_statement_or_null>                 function_statement_or_null
%type <ast_variable_identifier_list>                   variable_identifier_list
%type <ast_procedural_timing_control_statement>        procedural_timing_control_statement
%type <ast_delay_or_event_control>                     delay_or_event_control
%type <ast_delay_control>                              delay_control
%type <ast_event_control>                              event_control
%type <ast_event_expression>                           event_expression
%type <ast_procedural_timing_control>                  procedural_timing_control
%type <ast_jump_statement>                             jump_statement
%type <ast_wait_statement>                             wait_statement
%type <ast_event_trigger>                              event_trigger
%type <ast_disable_statement>                          disable_statement
%type <ast_conditional_statement>                      conditional_statement
%type <ast_unique_priority>                            unique_priority
%type <ast_cond_predicate>                             cond_predicate
%type <ast_expression_or_cond_pattern>                 expression_or_cond_pattern
%type <ast_cond_pattern>                               cond_pattern
%type <ast_case_statement>                             case_statement
%type <ast_case_keyword>                               case_keyword
%type <ast_case_expression>                            case_expression
%type <ast_case_item>                                  case_item
%type <ast_case_pattern_item>                          case_pattern_item
%type <ast_case_inside_item>                           case_inside_item
%type <ast_case_item_expression>                       case_item_expression
%type <ast_randcase_statement>                         randcase_statement
%type <ast_randcase_item>                              randcase_item
%type <ast_open_range_list>                            open_range_list
%type <ast_open_value_range>                           open_value_range
%type <ast_pattern>                                    pattern
%type <ast_assignment_pattern>                         assignment_pattern
%type <ast_structure_pattern_key>                      structure_pattern_key
%type <ast_array_pattern_key>                          array_pattern_key
%type <ast_assignment_pattern_key>                     assignment_pattern_key
%type <ast_assignment_pattern_expression>              assignment_pattern_expression
%type <ast_assignment_pattern_expression_type>         assignment_pattern_expression_type
%type <ast_constant_assignment_pattern_expression>     constant_assignment_pattern_expression
%type <ast_assignment_pattern_net_lvalue>              assignment_pattern_net_lvalue
%type <ast_assignment_pattern_variable_lvalue>         assignment_pattern_variable_lvalue
%type <ast_loop_statement>                             loop_statement
%type <ast_for_initialization>                         for_initialization
%type <ast_for_variable_declaration>                   for_variable_declaration
%type <ast_for_step>                                   for_step
%type <ast_for_step_assignment>                        for_step_assignment
%type <ast_loop_variables>                             loop_variables
%type <ast_subroutine_call_statement>                  subroutine_call_statement
%type <ast_assertion_item>                             assertion_item
%type <ast_deferred_immediate_assertion_item>          deferred_immediate_assertion_item
%type <ast_procedural_assertion_statement>             procedural_assertion_statement
%type <ast_immediate_assertion_statement>              immediate_assertion_statement
%type <ast_simple_immediate_assertion_statement>       simple_immediate_assertion_statement
%type <ast_simple_immediate_assert_statement>          simple_immediate_assert_statement
%type <ast_simple_immediate_assume_statement>          simple_immediate_assume_statement
%type <ast_simple_immediate_cover_statement>           simple_immediate_cover_statement
%type <ast_deferred_immediate_assertion_statement>     deferred_immediate_assertion_statement
%type <ast_deferred_immediate_assert_statement>        deferred_immediate_assert_statement
%type <ast_deferred_immediate_assume_statement>        deferred_immediate_assume_statement
%type <ast_deferred_immediate_cover_statement>         deferred_immediate_cover_statement
%type <ast_clocking_declaration>                       clocking_declaration
%type <ast_clocking_event>                             clocking_event
%type <ast_clocking_item>                              clocking_item
%type <ast_default_skew>                               default_skew
%type <ast_clocking_direction>                         clocking_direction
%type <ast_list_of_clocking_decl_assign>               list_of_clocking_decl_assign
%type <ast_clocking_decl_assign>                       clocking_decl_assign
%type <ast_clocking_skew>                              clocking_skew
%type <ast_clocking_drive>                             clocking_drive
%type <ast_cycle_delay>                                cycle_delay
%type <ast_clockvar>                                   clockvar
%type <ast_clockvar_expression>                        clockvar_expression
%type <ast_randsequence_statement>                     randsequence_statement
%type <ast_production>                                 production
%type <ast_rs_rule>                                    rs_rule
%type <ast_rs_production_list>                         rs_production_list
%type <ast_weight_specification>                       weight_specification
%type <ast_rs_code_block>                              rs_code_block
%type <ast_rs_prod>                                    rs_prod
%type <ast_production_item>                            production_item
%type <ast_rs_if_else>                                 rs_if_else
%type <ast_rs_repeat>                                  rs_repeat
%type <ast_rs_case>                                    rs_case
%type <ast_rs_case_item>                               rs_case_item
%type <ast_specify_block>                              specify_block
%type <ast_specify_item>                               specify_item
%type <ast_pulsestyle_declaration>                     pulsestyle_declaration
%type <ast_showcancelled_declaration>                  showcancelled_declaration
%type <ast_path_declaration>                           path_declaration
%type <ast_simple_path_declaration>                    simple_path_declaration
%type <ast_parallel_path_description>                  parallel_path_description
%type <ast_full_path_description>                      full_path_description
%type <ast_list_of_path_inputs>                        list_of_path_inputs
%type <ast_list_of_path_outputs>                       list_of_path_outputs
%type <ast_specify_input_terminal_descriptor>          specify_input_terminal_descriptor
%type <ast_specify_output_terminal_descriptor>         specify_output_terminal_descriptor
%type <ast_input_identifier>                           input_identifier
%type <ast_output_identifier>                          output_identifier
%type <ast_path_delay_value>                           path_delay_value
%type <ast_list_of_path_delay_expressions>             list_of_path_delay_expressions
%type <ast_t_path_delay_expression>                    t_path_delay_expression
%type <ast_trise_path_delay_expression>                trise_path_delay_expression
%type <ast_tfall_path_delay_expression>                tfall_path_delay_expression
%type <ast_tz_path_delay_expression>                   tz_path_delay_expression
%type <ast_t01_path_delay_expression>                  t01_path_delay_expression
%type <ast_t10_path_delay_expression>                  t10_path_delay_expression
%type <ast_t0z_path_delay_expression>                  t0z_path_delay_expression
%type <ast_tz1_path_delay_expression>                  tz1_path_delay_expression
%type <ast_t1z_path_delay_expression>                  t1z_path_delay_expression
%type <ast_tz0_path_delay_expression>                  tz0_path_delay_expression
%type <ast_t0x_path_delay_expression>                  t0x_path_delay_expression
%type <ast_tx1_path_delay_expression>                  tx1_path_delay_expression
%type <ast_t1x_path_delay_expression>                  t1x_path_delay_expression
%type <ast_tx0_path_delay_expression>                  tx0_path_delay_expression
%type <ast_txz_path_delay_expression>                  txz_path_delay_expression
%type <ast_tzx_path_delay_expression>                  tzx_path_delay_expression
%type <ast_path_delay_expression>                      path_delay_expression
%type <ast_edge_sensitive_path_declaration>            edge_sensitive_path_declaration
%type <ast_parallel_edge_sensitive_path_description>   parallel_edge_sensitive_path_description
%type <ast_full_edge_sensitive_path_description>       full_edge_sensitive_path_description
%type <ast_data_source_expression>                     data_source_expression
%type <ast_edge_identifier>                            edge_identifier
%type <ast_state_dependent_path_declaration>           state_dependent_path_declaration
%type <ast_polarity_operator>                          polarity_operator
%type <ast_system_timing_check>                        system_timing_check
%type <ast_dollarsign_setup_timing_check>              dollarsign_setup_timing_check
%type <ast_dollarsign_hold_timing_check>               dollarsign_hold_timing_check
%type <ast_dollarsign_setuphold_timing_check>          dollarsign_setuphold_timing_check
%type <ast_dollarsign_recovery_timing_check>           dollarsign_recovery_timing_check
%type <ast_dollarsign_removal_timing_check>            dollarsign_removal_timing_check
%type <ast_dollarsign_recrem_timing_check>             dollarsign_recrem_timing_check
%type <ast_dollarsign_skew_timing_check>               dollarsign_skew_timing_check
%type <ast_dollarsign_timeskew_timing_check>           dollarsign_timeskew_timing_check
%type <ast_dollarsign_fullskew_timing_check>           dollarsign_fullskew_timing_check
%type <ast_dollarsign_period_timing_check>             dollarsign_period_timing_check
%type <ast_dollarsign_width_timing_check>              dollarsign_width_timing_check
%type <ast_dollarsign_nochange_timing_check>           dollarsign_nochange_timing_check
%type <ast_timecheck_condition>                        timecheck_condition
%type <ast_controlled_reference_event>                 controlled_reference_event
%type <ast_data_event>                                 data_event
%type <ast_delayed_data>                               delayed_data
%type <ast_delayed_reference>                          delayed_reference
%type <ast_end_edge_offset>                            end_edge_offset
%type <ast_event_based_flag>                           event_based_flag
%type <ast_notifier>                                   notifier
%type <ast_reference_event>                            reference_event
%type <ast_remain_active_flag>                         remain_active_flag
%type <ast_timestamp_condition>                        timestamp_condition
%type <ast_start_edge_offset>                          start_edge_offset
%type <ast_threshold>                                  threshold
%type <ast_timing_check_limit>                         timing_check_limit
%type <ast_timing_check_event>                         timing_check_event
%type <ast_controlled_timing_check_event>              controlled_timing_check_event
%type <ast_timing_check_event_control>                 timing_check_event_control
%type <ast_specify_terminal_descriptor>                specify_terminal_descriptor
%type <ast_edge_control_specifier>                     edge_control_specifier
%type <ast_edge_descriptor>                            edge_descriptor
%type <ast_zero_or_one>                                zero_or_one
%type <ast_z_or_x>                                     z_or_x
%type <ast_timing_check_condition>                     timing_check_condition
%type <ast_scalar_timing_check_condition>              scalar_timing_check_condition
%type <ast_scalar_constant>                            scalar_constant
%type <ast_concatenation>                              concatenation
%type <ast_constant_concatenation>                     constant_concatenation
%type <ast_constant_multiple_concatenation>            constant_multiple_concatenation
%type <ast_module_path_concatenation>                  module_path_concatenation
%type <ast_module_path_multiple_concatenation>         module_path_multiple_concatenation
%type <ast_multiple_concatenation>                     multiple_concatenation
%type <ast_streaming_concatenation>                    streaming_concatenation
%type <ast_stream_operator>                            stream_operator
%type <ast_slice_size>                                 slice_size
%type <ast_stream_concatenation>                       stream_concatenation
%type <ast_stream_expression>                          stream_expression
%type <ast_array_range_expression>                     array_range_expression
%type <ast_empty_queue>                                empty_queue
%type <ast_constant_function_call>                     constant_function_call
%type <ast_tf_call>                                    tf_call
%type <ast_system_tf_call>                             system_tf_call
%type <ast_subroutine_call>                            subroutine_call
%type <ast_function_subroutine_call>                   function_subroutine_call
%type <ast_list_of_arguments>                          list_of_arguments
%type <ast_method_call>                                method_call
%type <ast_method_call_body>                           method_call_body
%type <ast_built_in_method_call>                       built_in_method_call
%type <ast_array_manipulation_call>                    array_manipulation_call
%type <ast_randomize_call>                             randomize_call
%type <ast_method_call_root>                           method_call_root
%type <ast_array_method_name>                          array_method_name
%type <ast_inc_or_dec_expression>                      inc_or_dec_expression
%type <ast_conditional_expression>                     conditional_expression
%type <ast_constant_expression>                        constant_expression
%type <ast_constant_mintypmax_expression>              constant_mintypmax_expression
%type <ast_constant_param_expression>                  constant_param_expression
%type <ast_param_expression>                           param_expression
%type <ast_constant_range_expression>                  constant_range_expression
%type <ast_constant_part_select_range>                 constant_part_select_range
%type <ast_constant_range>                             constant_range
%type <ast_constant_indexed_range>                     constant_indexed_range
%type <ast_expression>                                 expression
%type <ast_tagged_union_expression>                    tagged_union_expression
%type <ast_inside_expression>                          inside_expression
%type <ast_value_range>                                value_range
%type <ast_mintypmax_expression>                       mintypmax_expression
%type <ast_module_path_conditional_expression>         module_path_conditional_expression
%type <ast_module_path_expression>                     module_path_expression
%type <ast_module_path_mintypmax_expression>           module_path_mintypmax_expression
%type <ast_part_select_range>                          part_select_range
%type <ast_indexed_range>                              indexed_range
%type <ast_genvar_expression>                          genvar_expression
%type <ast_constant_primary>                           constant_primary
%type <ast_module_path_primary>                        module_path_primary
%type <ast_primary>                                    primary
%type <ast_class_qualifier>                            class_qualifier
%type <ast_range_expression>                           range_expression
%type <ast_primary_literal>                            primary_literal
%type <ast_time_literal>                               time_literal
%type <ast_time_unit>                                  time_unit
%type <ast_implicit_class_handle>                      implicit_class_handle
%type <ast_bit_select>                                 bit_select
%type <ast_select>                                     select
%type <ast_nonrange_select>                            nonrange_select
%type <ast_constant_bit_select>                        constant_bit_select
%type <ast_constant_select>                            constant_select
%type <ast_constant_cast>                              constant_cast
%type <ast_constant_let_expression>                    constant_let_expression
%type <ast_cast>                                       cast
%type <ast_net_lvalue>                                 net_lvalue
%type <ast_variable_lvalue>                            variable_lvalue
%type <ast_nonrange_variable_lvalue>                   nonrange_variable_lvalue
%type <ast_unary_operator>                             unary_operator
%type <ast_binary_operator>                            binary_operator
%type <ast_inc_or_dec_operator>                        inc_or_dec_operator
%type <ast_unary_module_path_operator>                 unary_module_path_operator
%type <ast_binary_module_path_operator>                binary_module_path_operator
%type <ast_number>                                     number
%type <ast_integral_number>                            integral_number
%type <ast_decimal_number>                             decimal_number
%type <ast_octal_number>                               octal_number
%type <ast_binary_number>                              binary_number
%type <ast_hex_number>                                 hex_number
%type <ast_unsigned_number>                            unsigned_number
%type <ast_real_number>                                real_number
%type <ast_fixed_point_number>                         fixed_point_number
%type <ast_unbased_unsized_literal>                    unbased_unsized_literal
%type <ast_string_literal>                             string_literal
%type <ast_attribute_instance>                         attribute_instance
%type <ast_attr_spec>                                  attr_spec
%type <ast_attr_name>                                  attr_name
%type <ast_block_identifier>                           block_identifier
%type <ast_bin_identifier>                             bin_identifier
%type <ast_c_identifier>                               c_identifier
%type <ast_cell_identifier>                            cell_identifier
%type <ast_checker_identifier>                         checker_identifier
%type <ast_class_identifier>                           class_identifier
%type <ast_class_variable_identifier>                  class_variable_identifier
%type <ast_clocking_identifier>                        clocking_identifier
%type <ast_config_identifier>                          config_identifier
%type <ast_const_identifier>                           const_identifier
%type <ast_constraint_identifier>                      constraint_identifier
%type <ast_covergroup_identifier>                      covergroup_identifier
%type <ast_cover_point_identifier>                     cover_point_identifier
%type <ast_cross_identifier>                           cross_identifier
%type <ast_dynamic_array_variable_identifier>          dynamic_array_variable_identifier
%type <ast_enum_identifier>                            enum_identifier
%type <ast_escaped_identifier>                         escaped_identifier
%type <ast_formal_port_identifier>                     formal_port_identifier
%type <ast_function_identifier>                        function_identifier
%type <ast_generate_block_identifier>                  generate_block_identifier
%type <ast_genvar_identifier>                          genvar_identifier
%type <ast_hierarchical_array_identifier>              hierarchical_array_identifier
%type <ast_hierarchical_block_identifier>              hierarchical_block_identifier
%type <ast_hierarchical_event_identifier>              hierarchical_event_identifier
%type <ast_hierarchical_identifier>                    hierarchical_identifier
%type <ast_hierarchical_net_identifier>                hierarchical_net_identifier
%type <ast_hierarchical_parameter_identifier>          hierarchical_parameter_identifier
%type <ast_hierarchical_property_identifier>           hierarchical_property_identifier
%type <ast_hierarchical_sequence_identifier>           hierarchical_sequence_identifier
%type <ast_hierarchical_task_identifier>               hierarchical_task_identifier
%type <ast_hierarchical_tf_identifier>                 hierarchical_tf_identifier
%type <ast_hierarchical_variable_identifier>           hierarchical_variable_identifier
%type <ast_identifier>                                 identifier
%type <ast_index_variable_identifier>                  index_variable_identifier
%type <ast_interface_identifier>                       interface_identifier
%type <ast_interface_instance_identifier>              interface_instance_identifier
%type <ast_inout_port_identifier>                      inout_port_identifier
%type <ast_input_port_identifier>                      input_port_identifier
%type <ast_instance_identifier>                        instance_identifier
%type <ast_library_identifier>                         library_identifier
%type <ast_member_identifier>                          member_identifier
%type <ast_method_identifier>                          method_identifier
%type <ast_modport_identifier>                         modport_identifier
%type <ast_module_identifier>                          module_identifier
%type <ast_net_identifier>                             net_identifier
%type <ast_net_type_identifier>                        net_type_identifier
%type <ast_output_port_identifier>                     output_port_identifier
%type <ast_package_identifier>                         package_identifier
%type <ast_package_scope>                              package_scope
%type <ast_parameter_identifier>                       parameter_identifier
%type <ast_port_identifier>                            port_identifier
%type <ast_production_identifier>                      production_identifier
%type <ast_program_identifier>                         program_identifier
%type <ast_property_identifier>                        property_identifier
%type <ast_ps_class_identifier>                        ps_class_identifier
%type <ast_ps_covergroup_identifier>                   ps_covergroup_identifier
%type <ast_ps_checker_identifier>                      ps_checker_identifier
%type <ast_ps_identifier>                              ps_identifier
%type <ast_ps_or_hierarchical_array_identifier>        ps_or_hierarchical_array_identifier
%type <ast_ps_or_hierarchical_net_identifier>          ps_or_hierarchical_net_identifier
%type <ast_ps_or_hierarchical_property_identifier>     ps_or_hierarchical_property_identifier
%type <ast_ps_or_hierarchical_sequence_identifier>     ps_or_hierarchical_sequence_identifier
%type <ast_ps_or_hierarchical_tf_identifier>           ps_or_hierarchical_tf_identifier
%type <ast_ps_parameter_identifier>                    ps_parameter_identifier
%type <ast_ps_type_identifier>                         ps_type_identifier
%type <ast_sequence_identifier>                        sequence_identifier
%type <ast_signal_identifier>                          signal_identifier
%type <ast_simple_identifier>                          simple_identifier
%type <ast_specparam_identifier>                       specparam_identifier
%type <ast_system_tf_identifier>                       system_tf_identifier
%type <ast_task_identifier>                            task_identifier
%type <ast_tf_identifier>                              tf_identifier
%type <ast_terminal_identifier>                        terminal_identifier
%type <ast_topmodule_identifier>                       topmodule_identifier
%type <ast_type_identifier>                            type_identifier
%type <ast_udp_identifier>                             udp_identifier
%type <ast_variable_identifier>                        variable_identifier
%type <ast_file_path_spec>                             file_path_spec
%type <ast_list> LIST_0
%type <ast_list> LIST_1
%type <ast_list> LIST_2
%type <ast_list> LIST_3
%type <ast_list> LIST_4
%type <ast_list> LIST_5
%type <ast_list> LIST_6
%type <ast_list> LIST_7
%type <ast_list> LIST_8
%type <ast_list> LIST_9
%type <ast_list> LIST_10
%type <ast_list> LIST_11
%type <ast_list> LIST_12
%type <ast_list> LIST_13
%type <ast_list> LIST_14
%type <ast_list> LIST_15
%type <ast_list> LIST_16
%type <ast_list> LIST_17
%type <ast_list> LIST_18
%type <ast_list> LIST_19
%type <ast_list> LIST_20
%type <ast_list> LIST_21
%type <ast_list> LIST_22
%type <ast_list> LIST_23
%type <ast_list> LIST_24
%type <ast_list> LIST_25
%type <ast_list> LIST_26
%type <ast_list> LIST_27
%type <ast_list> LIST_28
%type <ast_list> LIST_29
%type <ast_list> LIST_30
%type <ast_list> LIST_31
%type <ast_list> LIST_32
%type <ast_list> LIST_33
%type <ast_list> LIST_34
%type <ast_list> LIST_35
%type <ast_list> LIST_36
%type <ast_list> LIST_37
%type <ast_list> LIST_38
%type <ast_list> LIST_39
%type <ast_list> LIST_40
%type <ast_list> LIST_41
%type <ast_list> LIST_42
%type <ast_list> LIST_43
%type <ast_list> LIST_44
%type <ast_list> LIST_45
%type <ast_list> LIST_46
%type <ast_list> LIST_47
%type <ast_list> LIST_48
%type <ast_list> LIST_49
%type <ast_list> LIST_50
%type <ast_list> LIST_51
%type <ast_list> LIST_52
%type <ast_list> LIST_53
%type <ast_list> LIST_54
%type <ast_list> LIST_55
%type <ast_list> LIST_56
%type <ast_list> LIST_57
%type <ast_list> LIST_58
%type <ast_list> LIST_59
%type <ast_list> LIST_60
%type <ast_list> LIST_61
%type <ast_list> LIST_62
%type <ast_list> LIST_63
%type <ast_list> LIST_64
%type <ast_list> LIST_65
%type <ast_list> LIST_66
%type <ast_list> LIST_67
%type <ast_list> LIST_68
%type <ast_list> LIST_69
%type <ast_list> LIST_70
%type <ast_list> LIST_71
%type <ast_list> LIST_72
%type <ast_list> LIST_73
%type <ast_list> LIST_74
%type <ast_list> LIST_75
%type <ast_list> LIST_76
%type <ast_list> LIST_77
%type <ast_list> LIST_78
%type <ast_list> LIST_79
%type <ast_list> LIST_80
%type <ast_list> LIST_81
%type <ast_list> LIST_82
%type <ast_list> LIST_83
%type <ast_list> LIST_84
%type <ast_list> LIST_85
%type <ast_list> LIST_86
%type <ast_list> LIST_87
%type <ast_list> LIST_88
%type <ast_list> LIST_89
%type <ast_list> LIST_90
%type <ast_list> LIST_91
%type <ast_list> LIST_92
%type <ast_list> LIST_93
%type <ast_list> LIST_94
%type <ast_list> LIST_95
%type <ast_list> LIST_96
%type <ast_list> LIST_97
%type <ast_list> LIST_98
%type <ast_list> LIST_99
%type <ast_list> LIST_100
%type <ast_list> LIST_101
%type <ast_list> LIST_102
%type <ast_list> LIST_103
%type <ast_list> LIST_104
%type <ast_list> LIST_105
%type <ast_list> LIST_106
%type <ast_list> LIST_107
%type <ast_list> LIST_108
%type <ast_list> LIST_109
%type <ast_list> LIST_110
%type <ast_list> LIST_111
%type <ast_list> LIST_112
%type <ast_list> LIST_113
%type <ast_list> LIST_114
%type <ast_list> LIST_115
%type <ast_list> LIST_116
%type <ast_list> LIST_117
%type <ast_list> LIST_118
%type <ast_list> LIST_119
%type <ast_list> LIST_120
%type <ast_list> LIST_121
%type <ast_list> LIST_122
%type <ast_list> LIST_123
%type <ast_list> LIST_124
%type <ast_list> LIST_125
%type <ast_list> LIST_126
%type <ast_list> LIST_127
%type <ast_list> LIST_128
%type <ast_list> LIST_129
%type <ast_list> LIST_130
%type <ast_list> LIST_131
%type <ast_list> LIST_132
%type <ast_list> LIST_133
%type <ast_list> LIST_134
%type <ast_list> LIST_135
%type <ast_list> LIST_136
%type <ast_list> LIST_137
%type <ast_list> LIST_138
%type <ast_list> LIST_139
%type <ast_list> LIST_140
%type <ast_list> LIST_141
%type <ast_list> LIST_142
%type <ast_list> LIST_143
%type <ast_list> LIST_144
%type <ast_list> LIST_145
%type <ast_list> LIST_146
%type <ast_list> LIST_147
%type <ast_list> LIST_148
%type <ast_list> LIST_149
%type <ast_list> LIST_150
%type <ast_list> LIST_151
%type <ast_list> LIST_152
%type <ast_list> LIST_153
%type <ast_list> LIST_154
%type <ast_list> LIST_155
%type <ast_list> LIST_156
%type <ast_list> LIST_157
%type <ast_list> LIST_158
%type <ast_list> LIST_159
%type <ast_list> LIST_160
%type <ast_list> LIST_161
%type <ast_list> LIST_162
%type <ast_list> OPT_0
%type <ast_list> OPT_1
%type <ast_list> OPT_2
%type <ast_list> OPT_3
%type <ast_list> OPT_4
%type <ast_list> OPT_5
%type <ast_list> OPT_6
%type <ast_list> OPT_7
%type <ast_list> OPT_8
%type <ast_list> OPT_9
%type <ast_list> OPT_10
%type <ast_list> OPT_11
%type <ast_list> OPT_12
%type <ast_list> OPT_13
%type <ast_list> OPT_14
%type <ast_list> OPT_15
%type <ast_list> OPT_16
%type <ast_list> OPT_17
%type <ast_list> OPT_18
%type <ast_list> OPT_19
%type <ast_list> OPT_20
%type <ast_list> OPT_21
%type <ast_list> OPT_22
%type <ast_list> OPT_23
%type <ast_list> OPT_24
%type <ast_list> OPT_25
%type <ast_list> OPT_26
%type <ast_list> OPT_27
%type <ast_list> OPT_28
%type <ast_list> OPT_29
%type <ast_list> OPT_30
%type <ast_list> OPT_31
%type <ast_list> OPT_32
%type <ast_list> OPT_33
%type <ast_list> OPT_34
%type <ast_list> OPT_35
%type <ast_list> OPT_36
%type <ast_list> OPT_37
%type <ast_list> OPT_38
%type <ast_list> OPT_39
%type <ast_list> OPT_40
%type <ast_list> OPT_41
%type <ast_list> OPT_42
%type <ast_list> OPT_43
%type <ast_list> OPT_44
%type <ast_list> OPT_45
%type <ast_list> OPT_46
%type <ast_list> OPT_47
%type <ast_list> OPT_48
%type <ast_list> OPT_49
%type <ast_list> OPT_50
%type <ast_list> OPT_51
%type <ast_list> OPT_52
%type <ast_list> OPT_53
%type <ast_list> OPT_54
%type <ast_list> OPT_55
%type <ast_list> OPT_56
%type <ast_list> OPT_57
%type <ast_list> OPT_58
%type <ast_list> OPT_59
%type <ast_list> OPT_60
%type <ast_list> OPT_61
%type <ast_list> OPT_62
%type <ast_list> OPT_63
%type <ast_list> OPT_64
%type <ast_list> OPT_65
%type <ast_list> OPT_66
%type <ast_list> OPT_67
%type <ast_list> OPT_68
%type <ast_list> OPT_69
%type <ast_list> OPT_70
%type <ast_list> OPT_71
%type <ast_list> OPT_72
%type <ast_list> OPT_73
%type <ast_list> OPT_74
%type <ast_list> OPT_75
%type <ast_list> OPT_76
%type <ast_list> OPT_77
%type <ast_list> OPT_78
%type <ast_list> OPT_79
%type <ast_list> OPT_80
%type <ast_list> OPT_81
%type <ast_list> OPT_82
%type <ast_list> OPT_83
%type <ast_list> OPT_84
%type <ast_list> OPT_85
%type <ast_list> OPT_86
%type <ast_list> OPT_87
%type <ast_list> OPT_88
%type <ast_list> OPT_89
%type <ast_list> OPT_90
%type <ast_list> OPT_91
%type <ast_list> OPT_92
%type <ast_list> OPT_93
%type <ast_list> OPT_94
%type <ast_list> OPT_95
%type <ast_list> OPT_96
%type <ast_list> OPT_97
%type <ast_list> OPT_98
%type <ast_list> OPT_99
%type <ast_list> OPT_100
%type <ast_list> OPT_101
%type <ast_list> OPT_102
%type <ast_list> OPT_103
%type <ast_list> OPT_104
%type <ast_list> OPT_105
%type <ast_list> OPT_106
%type <ast_list> OPT_107
%type <ast_list> OPT_108
%type <ast_list> OPT_109
%type <ast_list> OPT_110
%type <ast_list> OPT_111
%type <ast_list> OPT_112
%type <ast_list> OPT_113
%type <ast_list> OPT_114
%type <ast_list> OPT_115
%type <ast_list> OPT_116
%type <ast_list> OPT_117
%type <ast_list> OPT_118
%type <ast_list> OPT_119
%type <ast_list> OPT_120
%type <ast_list> OPT_121
%type <ast_list> OPT_122
%type <ast_list> OPT_123
%type <ast_list> OPT_124
%type <ast_list> OPT_125
%type <ast_list> OPT_126
%type <ast_list> OPT_127
%type <ast_list> OPT_128
%type <ast_list> OPT_129
%type <ast_list> OPT_130
%type <ast_list> OPT_131
%type <ast_list> OPT_132
%type <ast_list> OPT_133
%type <ast_list> OPT_134
%type <ast_list> OPT_135
%type <ast_list> OPT_136
%type <ast_list> OPT_137
%type <ast_list> OPT_138
%type <ast_list> OPT_139
%type <ast_list> OPT_140
%type <ast_list> OPT_141
%type <ast_list> OPT_142
%type <ast_list> OPT_143
%type <ast_list> OPT_144
%type <ast_list> OPT_145
%type <ast_list> OPT_146
%type <ast_list> OPT_147
%type <ast_list> OPT_148
%type <ast_list> OPT_149
%type <ast_list> OPT_150
%type <ast_list> OPT_151
%type <ast_list> OPT_152
%type <ast_list> OPT_153
%type <ast_list> OPT_154
%type <ast_list> OPT_155
%type <ast_list> OPT_156
%type <ast_list> OPT_157
%type <ast_list> OPT_158
%type <ast_list> OPT_159
%type <ast_list> OPT_160
%type <ast_list> OPT_161
%type <ast_list> OPT_162
%type <ast_list> OPT_163
%type <ast_list> OPT_164
%type <ast_list> OPT_165
%type <ast_list> OPT_166
%type <ast_list> OPT_167
%type <ast_list> OPT_168
%type <ast_list> OPT_169
%type <ast_list> OPT_170
%type <ast_list> OPT_171
%type <ast_list> OPT_172
%type <ast_list> OPT_173
%type <ast_list> OPT_174
%type <ast_list> OPT_175
%type <ast_list> OPT_176
%type <ast_list> OPT_177
%type <ast_list> OPT_178
%type <ast_list> OPT_179
%type <ast_list> OPT_180
%type <ast_list> OPT_181
%type <ast_list> OPT_182
%type <ast_list> OPT_183
%type <ast_list> OPT_184
%type <ast_list> OPT_185
%type <ast_list> OPT_186
%type <ast_list> OPT_187
%type <ast_list> OPT_188
%type <ast_list> OPT_189
%type <ast_list> OPT_190
%type <ast_list> OPT_191
%type <ast_list> OPT_192
%type <ast_list> OPT_193
%type <ast_list> OPT_194
%type <ast_list> OPT_195
%type <ast_list> OPT_196
%type <ast_list> OPT_197
%type <ast_list> OPT_198
%type <ast_list> OPT_199
%type <ast_list> OPT_200
%type <ast_list> OPT_201
%type <ast_list> OPT_202
%type <ast_list> OPT_203
%type <ast_list> OPT_204
%type <ast_list> OPT_205
%type <ast_list> OPT_206
%type <ast_list> OPT_207
%type <ast_list> OPT_208
%type <ast_list> OPT_209
%type <ast_list> OPT_210
%type <ast_list> OPT_211
%type <ast_list> OPT_212
%type <ast_list> OPT_213
%type <ast_list> OPT_214
%type <ast_list> STAR_0
%type <ast_list> STAR_1
%type <ast_list> STAR_2
%type <ast_list> STAR_3
%type <ast_list> STAR_4
%type <ast_list> STAR_5
%type <ast_list> STAR_6
%type <ast_list> STAR_7
%type <ast_list> STAR_8
%type <ast_list> STAR_9
%type <ast_list> STAR_10
%type <ast_list> STAR_11
%type <ast_list> STAR_12
%type <ast_list> STAR_13
%type <ast_list> STAR_14
%type <ast_list> STAR_15
%type <ast_list> STAR_16
%type <ast_list> STAR_17
%type <ast_list> STAR_18
%type <ast_list> STAR_19
%type <ast_list> STAR_20
%type <ast_list> STAR_21
%type <ast_list> STAR_22
%type <ast_list> STAR_23
%type <ast_list> STAR_24
%type <ast_list> STAR_25
%type <ast_list> STAR_26
%type <ast_list> STAR_27
%type <ast_list> STAR_28
%type <ast_list> STAR_29
%type <ast_list> STAR_30
%type <ast_list> STAR_31
%type <ast_list> STAR_32
%type <ast_list> STAR_33
%type <ast_list> STAR_34
%type <ast_list> STAR_35
%type <ast_list> STAR_36
%type <ast_list> STAR_37
%type <ast_list> STAR_38
%type <ast_list> STAR_39
%type <ast_list> STAR_40
%type <ast_list> STAR_41
%type <ast_list> STAR_42
%type <ast_list> STAR_43
%type <ast_list> STAR_44
%type <ast_list> STAR_45
%type <ast_list> STAR_46
%type <ast_list> STAR_47
%type <ast_list> STAR_48
%type <ast_list> STAR_49
%type <ast_list> STAR_50
%type <ast_list> STAR_51
%type <ast_list> STAR_52
%type <token_str> TOKEN_0
%type <token_str> TOKEN_1
%type <token_str> TOKEN_2
%type <token_str> TOKEN_3
%type <token_str> TOKEN_4
%type <token_str> TOKEN_5
%type <token_str> TOKEN_6
%type <token_str> TOKEN_7
%type <token_str> TOKEN_8
%type <token_str> TOKEN_9
%type <token_str> TOKEN_10
%type <token_str> TOKEN_11
%type <token_str> TOKEN_12
%type <token_str> TOKEN_13
%type <token_str> TOKEN_14
%type <token_str> TOKEN_15
%type <token_str> TOKEN_16
%type <token_str> TOKEN_17
%type <token_str> TOKEN_18
%type <token_str> TOKEN_19
%type <token_str> TOKEN_20
%type <token_str> TOKEN_21
%type <token_str> TOKEN_22
%type <token_str> TOKEN_23
%type <token_str> TOKEN_24
%type <token_str> TOKEN_25
%type <token_str> TOKEN_26
%type <token_str> TOKEN_27
%type <token_str> TOKEN_28
%type <token_str> TOKEN_29
%type <token_str> TOKEN_30
%type <token_str> TOKEN_31
%type <token_str> TOKEN_32
%type <token_str> TOKEN_33
%type <token_str> TOKEN_34
%type <token_str> TOKEN_35
%type <token_str> TOKEN_36
%type <token_str> TOKEN_37
%type <token_str> TOKEN_38
%type <token_str> TOKEN_39
%type <token_str> TOKEN_40
%type <token_str> TOKEN_41
%type <token_str> TOKEN_42
%type <token_str> TOKEN_43
%type <token_str> TOKEN_44
%type <token_str> TOKEN_45
%type <token_str> TOKEN_46
%type <token_str> TOKEN_47
%type <token_str> TOKEN_48
%type <token_str> TOKEN_49
%type <token_str> TOKEN_50
%type <token_str> TOKEN_51
%type <token_str> TOKEN_52
%type <token_str> TOKEN_53
%type <token_str> TOKEN_54
%type <token_str> TOKEN_55
%type <token_str> TOKEN_56
%type <token_str> TOKEN_57
%type <token_str> TOKEN_58
%type <token_str> TOKEN_59
%type <token_str> TOKEN_60
%type <token_str> TOKEN_61
%type <token_str> TOKEN_62
%type <token_str> TOKEN_63
%type <token_str> TOKEN_64
%type <token_str> TOKEN_65
%type <token_str> TOKEN_66
%type <token_str> TOKEN_67
%type <token_str> TOKEN_68
%type <token_str> TOKEN_69
%type <token_str> TOKEN_70
%type <token_str> TOKEN_71
%type <token_str> TOKEN_72
%type <token_str> TOKEN_73
%type <token_str> TOKEN_74
%type <token_str> TOKEN_75
%type <token_str> TOKEN_76
%type <token_str> TOKEN_77
%type <token_str> TOKEN_78
%type <token_str> TOKEN_79
%type <token_str> TOKEN_80
%type <token_str> TOKEN_81
%type <token_str> TOKEN_82
%type <token_str> TOKEN_83
%type <token_str> TOKEN_84
%type <token_str> TOKEN_85
%type <token_str> TOKEN_86
%type <token_str> TOKEN_87
%type <token_str> TOKEN_88
%type <token_str> TOKEN_89
%type <token_str> TOKEN_90
%type <token_str> TOKEN_91
%type <token_str> TOKEN_92
%type <token_str> TOKEN_93
%type <token_str> TOKEN_94
%type <token_str> TOKEN_95
%type <token_str> TOKEN_96
%type <token_str> TOKEN_97
%type <token_str> TOKEN_98
%type <token_str> TOKEN_99
%type <token_str> TOKEN_100
%type <token_str> TOKEN_101
%type <token_str> TOKEN_102
%type <token_str> TOKEN_103
%type <token_str> TOKEN_104
%type <token_str> TOKEN_105
%type <token_str> TOKEN_106
%type <token_str> TOKEN_107
%type <token_str> TOKEN_108
%type <token_str> TOKEN_109
%type <token_str> TOKEN_110
%type <token_str> TOKEN_111
%type <token_str> TOKEN_112
%type <token_str> TOKEN_113
%type <token_str> TOKEN_114
%type <token_str> TOKEN_115
%type <token_str> TOKEN_116
%type <token_str> TOKEN_117
%type <token_str> TOKEN_118
%type <token_str> TOKEN_119
%type <token_str> TOKEN_120
%type <token_str> TOKEN_121
%type <token_str> TOKEN_122
%type <token_str> TOKEN_123
%type <token_str> TOKEN_124
%type <token_str> TOKEN_125
%type <token_str> TOKEN_126
%type <token_str> TOKEN_127
%type <token_str> TOKEN_128
%type <token_str> TOKEN_129
%type <token_str> TOKEN_130
%type <token_str> TOKEN_131
%type <token_str> TOKEN_132
%type <token_str> TOKEN_133
%type <token_str> TOKEN_134
%type <token_str> TOKEN_135
%type <token_str> TOKEN_136
%type <token_str> TOKEN_137
%type <token_str> TOKEN_138
%type <token_str> TOKEN_139
%type <token_str> TOKEN_140
%type <token_str> TOKEN_141
%type <token_str> TOKEN_142
%type <token_str> TOKEN_143
%type <token_str> TOKEN_144
%type <token_str> TOKEN_145
%type <token_str> TOKEN_146
%type <token_str> TOKEN_147
%type <token_str> TOKEN_148
%type <token_str> TOKEN_149
%type <token_str> TOKEN_150
%type <token_str> TOKEN_151
%type <token_str> TOKEN_152
%type <token_str> TOKEN_153
%type <token_str> TOKEN_154
%type <token_str> TOKEN_155
%type <token_str> TOKEN_156
%type <token_str> TOKEN_157
%type <token_str> TOKEN_158
%type <token_str> TOKEN_159
%type <token_str> TOKEN_160
%type <token_str> TOKEN_161
%type <token_str> TOKEN_162
%type <token_str> TOKEN_163
%type <token_str> TOKEN_164
%type <token_str> TOKEN_165
%type <token_str> TOKEN_166
%type <token_str> TOKEN_167
%type <token_str> TOKEN_168
%type <token_str> TOKEN_169
%type <token_str> TOKEN_170
%type <token_str> TOKEN_171
%type <token_str> TOKEN_172
%type <token_str> TOKEN_173
%type <token_str> TOKEN_174
%type <token_str> TOKEN_175
%type <token_str> TOKEN_176
%type <token_str> TOKEN_177
%type <token_str> TOKEN_178
%type <token_str> TOKEN_179
%type <token_str> TOKEN_180
%type <token_str> TOKEN_181
%type <token_str> TOKEN_182
%type <token_str> TOKEN_183
%type <token_str> TOKEN_184
%type <token_str> TOKEN_185
%type <token_str> TOKEN_186
%type <token_str> TOKEN_187
%type <token_str> TOKEN_188
%type <token_str> TOKEN_189
%type <token_str> TOKEN_190
%type <token_str> TOKEN_191
%type <token_str> TOKEN_192
%type <token_str> TOKEN_193
%type <token_str> TOKEN_194
%type <token_str> TOKEN_195
%type <token_str> TOKEN_196
%type <token_str> TOKEN_197
%type <token_str> TOKEN_198
%type <token_str> TOKEN_199
%type <token_str> TOKEN_200
%type <token_str> TOKEN_201
%type <token_str> TOKEN_202
%type <token_str> TOKEN_203
%type <token_str> TOKEN_204
%type <token_str> TOKEN_205
%type <token_str> TOKEN_206
%type <token_str> TOKEN_207
%type <token_str> TOKEN_208
%type <token_str> TOKEN_209
%type <token_str> TOKEN_210
%type <token_str> TOKEN_211
%type <token_str> TOKEN_212
%type <token_str> TOKEN_213
%type <token_str> TOKEN_214
%type <token_str> TOKEN_215
%type <token_str> TOKEN_216
%type <token_str> TOKEN_217
%type <token_str> TOKEN_218
%type <token_str> TOKEN_219
%type <token_str> TOKEN_220
%type <token_str> TOKEN_221
%type <token_str> TOKEN_222
%type <token_str> TOKEN_223
%type <token_str> TOKEN_224
%type <token_str> TOKEN_225
%type <token_str> TOKEN_226
%type <token_str> TOKEN_227
%type <token_str> TOKEN_228
%type <token_str> TOKEN_229
%type <token_str> TOKEN_230
%type <token_str> TOKEN_231
%type <token_str> TOKEN_232
%type <token_str> TOKEN_233
%type <token_str> TOKEN_234
%type <token_str> TOKEN_235
%type <token_str> TOKEN_236
%type <token_str> TOKEN_237
%type <token_str> TOKEN_238
%type <token_str> TOKEN_239
%type <token_str> TOKEN_240
%type <token_str> TOKEN_241
%type <token_str> TOKEN_242
%type <token_str> TOKEN_243
%type <token_str> TOKEN_244
%type <token_str> TOKEN_245
%type <token_str> TOKEN_246
%type <token_str> TOKEN_247
%type <token_str> TOKEN_248
%type <token_str> TOKEN_249
%type <token_str> TOKEN_250
%type <token_str> TOKEN_251
%type <token_str> TOKEN_252
%type <token_str> TOKEN_253
%type <token_str> TOKEN_254
%type <token_str> TOKEN_255
%type <token_str> TOKEN_256
%type <token_str> TOKEN_257
%type <token_str> TOKEN_258
%type <token_str> TOKEN_259
%type <token_str> TOKEN_260
%type <token_str> TOKEN_261
%type <token_str> TOKEN_262
%type <token_str> TOKEN_263
%type <token_str> TOKEN_264
%type <token_str> TOKEN_265
%type <token_str> TOKEN_266
%type <token_str> TOKEN_267
%type <token_str> TOKEN_268
%type <token_str> TOKEN_269
%type <token_str> TOKEN_270
%type <token_str> TOKEN_271
%type <token_str> TOKEN_272
%type <token_str> TOKEN_273
%type <token_str> TOKEN_274
%type <token_str> TOKEN_275
%type <token_str> TOKEN_276
%type <token_str> TOKEN_277
%type <token_str> TOKEN_278
%type <token_str> TOKEN_279
%type <token_str> TOKEN_280
%type <token_str> TOKEN_281
%type <token_str> TOKEN_282
%type <token_str> TOKEN_283
%type <token_str> TOKEN_284
%type <token_str> TOKEN_285
%type <token_str> TOKEN_286
%type <token_str> TOKEN_287
%type <token_str> TOKEN_288
%type <token_str> TOKEN_289
%type <token_str> TOKEN_290
%type <token_str> TOKEN_291
%type <token_str> TOKEN_292
%type <token_str> TOKEN_293
%type <token_str> TOKEN_294
%type <token_str> TOKEN_295
%type <token_str> TOKEN_296
%type <token_str> TOKEN_297
%type <token_str> TOKEN_298
%type <token_str> TOKEN_299
%type <token_str> TOKEN_300
%type <token_str> TOKEN_301
%type <token_str> TOKEN_302
%type <token_str> TOKEN_303
%type <token_str> TOKEN_304
%type <token_str> TOKEN_305
%type <token_str> TOKEN_306
%type <token_str> TOKEN_307
%type <token_str> TOKEN_308
%type <token_str> TOKEN_309
%type <token_str> TOKEN_310
%type <token_str> TOKEN_311
%type <token_str> TOKEN_312
%type <token_str> TOKEN_313
%type <token_str> TOKEN_314
%type <token_str> TOKEN_315
%type <token_str> TOKEN_316
%type <token_str> TOKEN_317
%type <token_str> TOKEN_318
%type <token_str> TOKEN_319
%type <token_str> TOKEN_320
%type <token_str> TOKEN_321
%type <token_str> TOKEN_322
%type <token_str> TOKEN_323
%type <token_str> TOKEN_324
%type <token_str> TOKEN_325
%type <token_str> TOKEN_326
%type <token_str> TOKEN_327
%type <token_str> TOKEN_328
%type <token_str> TOKEN_329
%type <token_str> TOKEN_330
%type <token_str> TOKEN_331
%type <token_str> TOKEN_332
%type <token_str> TOKEN_333
%type <token_str> TOKEN_334
%type <token_str> TOKEN_335
%type <token_str> TOKEN_336
%type <token_str> TOKEN_337
%type <token_str> TOKEN_338
%type <token_str> TOKEN_339
%type <token_str> TOKEN_340
%type <token_str> TOKEN_341
%type <token_str> TOKEN_342
%type <token_str> TOKEN_343
%type <token_str> TOKEN_344
%type <token_str> TOKEN_345
%type <token_str> TOKEN_346
%type <token_str> TOKEN_347
%type <token_str> TOKEN_348
%type <token_str> TOKEN_349
%type <token_str> TOKEN_350
%type <token_str> TOKEN_351
%type <token_str> TOKEN_352
%type <token_str> TOKEN_353
%type <token_str> TOKEN_354
%type <token_str> TOKEN_355
%type <token_str> TOKEN_356
%type <token_str> TOKEN_357
%type <token_str> TOKEN_358
%type <token_str> TOKEN_359
%type <token_str> TOKEN_360
%type <token_str> TOKEN_361
%type <token_str> TOKEN_362
%type <token_str> TOKEN_363
%type <token_str> TOKEN_364
%type <token_str> TOKEN_365
%type <token_str> TOKEN_366
%type <token_str> TOKEN_367
%type <token_str> TOKEN_368
%type <token_str> TOKEN_369
%type <token_str> TOKEN_370
%type <token_str> TOKEN_371
%type <token_str> TOKEN_372
%type <token_str> TOKEN_373
%type <token_str> TOKEN_374
%type <token_str> TOKEN_375
%type <token_str> TOKEN_376
%type <token_str> TOKEN_377
%type <token_str> TOKEN_378
%type <token_str> TOKEN_379
%type <token_str> TOKEN_380
%type <token_str> TOKEN_381
%type <token_str> TOKEN_382
%type <token_str> TOKEN_383
%type <token_str> TOKEN_384
%type <token_str> TOKEN_385
%type <token_str> TOKEN_386
%type <token_str> TOKEN_387
%type <token_str> TOKEN_388
%type <token_str> TOKEN_389
%type <token_str> TOKEN_390
%type <token_str> TOKEN_391
%type <token_str> TOKEN_392
%type <token_str> TOKEN_393
%type <token_str> TOKEN_394
%type <token_str> TOKEN_395
%type <token_str> TOKEN_396
%type <token_str> TOKEN_397
%type <token_str> TOKEN_398
%type <token_str> TOKEN_399
%type <token_str> TOKEN_400
%type <token_str> SV_UNSIGNED_NUMBER
%type <token_str> SV_DECIMAL_NUMBER
%type <token_str> SV_OCTAL_NUMBER
%type <token_str> SV_BINARY_NUMBER
%type <token_str> SV_HEX_NUMBER
%type <token_str> SV_UNSIGNED_INTEGER
%type <token_str> SV_EXPONENTIAL_NUMBER
%type <token_str> SV_FIXED_POINT_NUMBER
%type <token_str> SV_STRING
%type <token_str> SV_ESCAPED_IDENTIFIER
%type <token_str> SV_IDENTIFIER
%type <token_str> FILE_PATH
%type <token_str> SV_INTEGER


%%



start
	: library_text
	{
		start_library_text = $1;
	}
	| source_text
	{
		start_source_text = $1;
	}
	;





library_text 
    : STAR_0 
    {
        struct ast_library_text *ret = new (struct ast_library_text);
        $$ = ret;
    }
    ;

library_description 
    : library_declaration 
    {
        struct ast_library_description *ret = new (struct ast_library_description);
        $$ = ret;
    }
    | include_statement 
    {
        struct ast_library_description *ret = new (struct ast_library_description);
        $$ = ret;
    }
    | config_declaration 
    {
        struct ast_library_description *ret = new (struct ast_library_description);
        $$ = ret;
    }
    | TOKEN_0 /* ; */ 
    {
        struct ast_library_description *ret = new (struct ast_library_description);
        $$ = ret;
    }
    ;

library_declaration 
    : TOKEN_1 /* library */ library_identifier LIST_1 OPT_0 TOKEN_0 /* ; */ 
    {
        struct ast_library_declaration *ret = new (struct ast_library_declaration);
        $$ = ret;
    }
    ;

include_statement 
    : TOKEN_4 /* include */ file_path_spec TOKEN_0 /* ; */ 
    {
        struct ast_include_statement *ret = new (struct ast_include_statement);
        $$ = ret;
    }
    ;

source_text 
    : OPT_1 STAR_1 
    {
        struct ast_source_text *ret = new (struct ast_source_text);
        $$ = ret;
    }
    ;

description 
    : module_declaration 
    {
        struct ast_description *ret = new (struct ast_description);
        $$ = ret;
    }
    | udp_declaration 
    {
        struct ast_description *ret = new (struct ast_description);
        $$ = ret;
    }
    | interface_declaration 
    {
        struct ast_description *ret = new (struct ast_description);
        $$ = ret;
    }
    | program_declaration 
    {
        struct ast_description *ret = new (struct ast_description);
        $$ = ret;
    }
    | package_declaration 
    {
        struct ast_description *ret = new (struct ast_description);
        $$ = ret;
    }
    | STAR_2 package_item 
    {
        struct ast_description *ret = new (struct ast_description);
        $$ = ret;
    }
    | STAR_2 bind_directive 
    {
        struct ast_description *ret = new (struct ast_description);
        $$ = ret;
    }
    | config_declaration 
    {
        struct ast_description *ret = new (struct ast_description);
        $$ = ret;
    }
    ;

module_nonansi_header 
    : STAR_2 module_keyword OPT_2 module_identifier STAR_3 OPT_3 list_of_ports TOKEN_0 /* ; */ 
    {
        struct ast_module_nonansi_header *ret = new (struct ast_module_nonansi_header);
        $$ = ret;
    }
    ;

module_ansi_header 
    : STAR_2 module_keyword OPT_2 module_identifier STAR_3 OPT_3 OPT_4 TOKEN_0 /* ; */ 
    {
        struct ast_module_ansi_header *ret = new (struct ast_module_ansi_header);
        $$ = ret;
    }
    ;

module_declaration 
    : module_nonansi_header OPT_1 STAR_4 TOKEN_5 /* endmodule */ OPT_5 
    {
        struct ast_module_declaration *ret = new (struct ast_module_declaration);
        $$ = ret;
    }
    | module_ansi_header OPT_1 STAR_5 TOKEN_5 /* endmodule */ OPT_5 
    {
        struct ast_module_declaration *ret = new (struct ast_module_declaration);
        $$ = ret;
    }
    | TOKEN_7 /* extern */ module_nonansi_header 
    {
        struct ast_module_declaration *ret = new (struct ast_module_declaration);
        $$ = ret;
    }
    | TOKEN_7 /* extern */ module_ansi_header 
    {
        struct ast_module_declaration *ret = new (struct ast_module_declaration);
        $$ = ret;
    }
    ;

module_keyword 
    : TOKEN_8 /* module */ 
    {
        struct ast_module_keyword *ret = new (struct ast_module_keyword);
        $$ = ret;
    }
    | TOKEN_9 /* macromodule */ 
    {
        struct ast_module_keyword *ret = new (struct ast_module_keyword);
        $$ = ret;
    }
    ;

interface_declaration 
    : interface_nonansi_header OPT_1 STAR_6 TOKEN_10 /* endinterface */ OPT_6 
    {
        struct ast_interface_declaration *ret = new (struct ast_interface_declaration);
        $$ = ret;
    }
    | interface_ansi_header OPT_1 STAR_7 TOKEN_10 /* endinterface */ OPT_6 
    {
        struct ast_interface_declaration *ret = new (struct ast_interface_declaration);
        $$ = ret;
    }
    | STAR_2 TOKEN_11 /* interface */ interface_identifier TOKEN_12 /* ( */ TOKEN_13 /* .* */ TOKEN_14 /* ) */ TOKEN_0 /* ; */ OPT_1 STAR_6 TOKEN_10 /* endinterface */ OPT_6 
    {
        struct ast_interface_declaration *ret = new (struct ast_interface_declaration);
        $$ = ret;
    }
    | TOKEN_7 /* extern */ interface_nonansi_header 
    {
        struct ast_interface_declaration *ret = new (struct ast_interface_declaration);
        $$ = ret;
    }
    | TOKEN_7 /* extern */ interface_ansi_header 
    {
        struct ast_interface_declaration *ret = new (struct ast_interface_declaration);
        $$ = ret;
    }
    ;

interface_nonansi_header 
    : STAR_2 TOKEN_11 /* interface */ OPT_2 interface_identifier STAR_3 OPT_3 list_of_ports TOKEN_0 /* ; */ 
    {
        struct ast_interface_nonansi_header *ret = new (struct ast_interface_nonansi_header);
        $$ = ret;
    }
    ;

interface_ansi_header 
    : STAR_2 TOKEN_11 /* interface */ OPT_2 interface_identifier STAR_3 OPT_3 OPT_4 TOKEN_0 /* ; */ 
    {
        struct ast_interface_ansi_header *ret = new (struct ast_interface_ansi_header);
        $$ = ret;
    }
    ;

program_declaration 
    : program_nonansi_header OPT_1 STAR_8 TOKEN_15 /* endprogram */ OPT_7 
    {
        struct ast_program_declaration *ret = new (struct ast_program_declaration);
        $$ = ret;
    }
    | program_ansi_header OPT_1 STAR_9 TOKEN_15 /* endprogram */ OPT_7 
    {
        struct ast_program_declaration *ret = new (struct ast_program_declaration);
        $$ = ret;
    }
    | STAR_2 TOKEN_16 /* program */ program_identifier TOKEN_12 /* ( */ TOKEN_13 /* .* */ TOKEN_14 /* ) */ TOKEN_0 /* ; */ OPT_1 STAR_8 TOKEN_15 /* endprogram */ OPT_7 
    {
        struct ast_program_declaration *ret = new (struct ast_program_declaration);
        $$ = ret;
    }
    | TOKEN_7 /* extern */ program_nonansi_header 
    {
        struct ast_program_declaration *ret = new (struct ast_program_declaration);
        $$ = ret;
    }
    | TOKEN_7 /* extern */ program_ansi_header 
    {
        struct ast_program_declaration *ret = new (struct ast_program_declaration);
        $$ = ret;
    }
    ;

program_nonansi_header 
    : STAR_2 TOKEN_16 /* program */ OPT_2 program_identifier STAR_3 OPT_3 list_of_ports TOKEN_0 /* ; */ 
    {
        struct ast_program_nonansi_header *ret = new (struct ast_program_nonansi_header);
        $$ = ret;
    }
    ;

program_ansi_header 
    : STAR_2 TOKEN_16 /* program */ OPT_2 program_identifier STAR_3 OPT_3 OPT_4 TOKEN_0 /* ; */ 
    {
        struct ast_program_ansi_header *ret = new (struct ast_program_ansi_header);
        $$ = ret;
    }
    ;

checker_declaration 
    : TOKEN_17 /* checker */ checker_identifier OPT_9 TOKEN_0 /* ; */ STAR_10 TOKEN_18 /* endchecker */ OPT_10 
    {
        struct ast_checker_declaration *ret = new (struct ast_checker_declaration);
        $$ = ret;
    }
    ;

class_declaration 
    : OPT_11 TOKEN_20 /* class */ OPT_2 class_identifier OPT_3 OPT_13 OPT_14 TOKEN_0 /* ; */ STAR_11 TOKEN_23 /* endclass */ OPT_15 
    {
        struct ast_class_declaration *ret = new (struct ast_class_declaration);
        $$ = ret;
    }
    ;

interface_class_type 
    : ps_class_identifier OPT_16 
    {
        struct ast_interface_class_type *ret = new (struct ast_interface_class_type);
        $$ = ret;
    }
    ;

package_declaration 
    : STAR_2 TOKEN_24 /* package */ OPT_2 package_identifier TOKEN_0 /* ; */ OPT_1 STAR_12 TOKEN_25 /* endpackage */ OPT_17 
    {
        struct ast_package_declaration *ret = new (struct ast_package_declaration);
        $$ = ret;
    }
    ;

timeunits_declaration 
    : TOKEN_26 /* timeunit */ time_literal OPT_18 TOKEN_0 /* ; */ 
    {
        struct ast_timeunits_declaration *ret = new (struct ast_timeunits_declaration);
        $$ = ret;
    }
    | TOKEN_28 /* timeprecision */ time_literal TOKEN_0 /* ; */ 
    {
        struct ast_timeunits_declaration *ret = new (struct ast_timeunits_declaration);
        $$ = ret;
    }
    | TOKEN_26 /* timeunit */ time_literal TOKEN_0 /* ; */ TOKEN_28 /* timeprecision */ time_literal TOKEN_0 /* ; */ 
    {
        struct ast_timeunits_declaration *ret = new (struct ast_timeunits_declaration);
        $$ = ret;
    }
    | TOKEN_28 /* timeprecision */ time_literal TOKEN_0 /* ; */ TOKEN_26 /* timeunit */ time_literal TOKEN_0 /* ; */ 
    {
        struct ast_timeunits_declaration *ret = new (struct ast_timeunits_declaration);
        $$ = ret;
    }
    ;

parameter_port_list 
    : TOKEN_29 /* # */ TOKEN_12 /* ( */ list_of_param_assignments STAR_13 TOKEN_14 /* ) */ 
    {
        struct ast_parameter_port_list *ret = new (struct ast_parameter_port_list);
        $$ = ret;
    }
    | TOKEN_29 /* # */ TOKEN_12 /* ( */ LIST_16 TOKEN_14 /* ) */ 
    {
        struct ast_parameter_port_list *ret = new (struct ast_parameter_port_list);
        $$ = ret;
    }
    | TOKEN_29 /* # */ TOKEN_12 /* ( */ TOKEN_14 /* ) */ 
    {
        struct ast_parameter_port_list *ret = new (struct ast_parameter_port_list);
        $$ = ret;
    }
    ;

parameter_port_declaration 
    : parameter_declaration 
    {
        struct ast_parameter_port_declaration *ret = new (struct ast_parameter_port_declaration);
        $$ = ret;
    }
    | local_parameter_declaration 
    {
        struct ast_parameter_port_declaration *ret = new (struct ast_parameter_port_declaration);
        $$ = ret;
    }
    | data_type list_of_param_assignments 
    {
        struct ast_parameter_port_declaration *ret = new (struct ast_parameter_port_declaration);
        $$ = ret;
    }
    | TOKEN_30 /* type */ list_of_type_assignments 
    {
        struct ast_parameter_port_declaration *ret = new (struct ast_parameter_port_declaration);
        $$ = ret;
    }
    ;

list_of_ports 
    : TOKEN_12 /* ( */ LIST_17 TOKEN_14 /* ) */ 
    {
        struct ast_list_of_ports *ret = new (struct ast_list_of_ports);
        $$ = ret;
    }
    ;

list_of_port_declarations 
    : TOKEN_12 /* ( */ OPT_19 TOKEN_14 /* ) */ 
    {
        struct ast_list_of_port_declarations *ret = new (struct ast_list_of_port_declarations);
        $$ = ret;
    }
    ;

port_declaration 
    : STAR_2 inout_declaration 
    {
        struct ast_port_declaration *ret = new (struct ast_port_declaration);
        $$ = ret;
    }
    | STAR_2 input_declaration 
    {
        struct ast_port_declaration *ret = new (struct ast_port_declaration);
        $$ = ret;
    }
    | STAR_2 output_declaration 
    {
        struct ast_port_declaration *ret = new (struct ast_port_declaration);
        $$ = ret;
    }
    | STAR_2 ref_declaration 
    {
        struct ast_port_declaration *ret = new (struct ast_port_declaration);
        $$ = ret;
    }
    | STAR_2 interface_port_declaration 
    {
        struct ast_port_declaration *ret = new (struct ast_port_declaration);
        $$ = ret;
    }
    ;

port 
    : OPT_20 
    {
        struct ast_port *ret = new (struct ast_port);
        $$ = ret;
    }
    | TOKEN_31 /* . */ port_identifier TOKEN_12 /* ( */ OPT_20 TOKEN_14 /* ) */ 
    {
        struct ast_port *ret = new (struct ast_port);
        $$ = ret;
    }
    ;

port_expression 
    : port_reference 
    {
        struct ast_port_expression *ret = new (struct ast_port_expression);
        $$ = ret;
    }
    | TOKEN_32 /* { */ LIST_19 TOKEN_33 /* } */ 
    {
        struct ast_port_expression *ret = new (struct ast_port_expression);
        $$ = ret;
    }
    ;

port_reference 
    : port_identifier constant_select 
    {
        struct ast_port_reference *ret = new (struct ast_port_reference);
        $$ = ret;
    }
    ;

port_direction 
    : TOKEN_34 /* input */ 
    {
        struct ast_port_direction *ret = new (struct ast_port_direction);
        $$ = ret;
    }
    | TOKEN_35 /* output */ 
    {
        struct ast_port_direction *ret = new (struct ast_port_direction);
        $$ = ret;
    }
    | TOKEN_36 /* inout */ 
    {
        struct ast_port_direction *ret = new (struct ast_port_direction);
        $$ = ret;
    }
    | TOKEN_37 /* ref */ 
    {
        struct ast_port_direction *ret = new (struct ast_port_direction);
        $$ = ret;
    }
    ;

net_port_header 
    : OPT_21 net_port_type 
    {
        struct ast_net_port_header *ret = new (struct ast_net_port_header);
        $$ = ret;
    }
    ;

variable_port_header 
    : OPT_21 variable_port_type 
    {
        struct ast_variable_port_header *ret = new (struct ast_variable_port_header);
        $$ = ret;
    }
    ;

interface_port_header 
    : interface_identifier OPT_22 
    {
        struct ast_interface_port_header *ret = new (struct ast_interface_port_header);
        $$ = ret;
    }
    | TOKEN_11 /* interface */ OPT_22 
    {
        struct ast_interface_port_header *ret = new (struct ast_interface_port_header);
        $$ = ret;
    }
    ;

ansi_port_declaration 
    : OPT_23 port_identifier STAR_14 OPT_24 
    {
        struct ast_ansi_port_declaration *ret = new (struct ast_ansi_port_declaration);
        $$ = ret;
    }
    | OPT_25 port_identifier STAR_15 OPT_24 
    {
        struct ast_ansi_port_declaration *ret = new (struct ast_ansi_port_declaration);
        $$ = ret;
    }
    | OPT_21 TOKEN_31 /* . */ port_identifier TOKEN_12 /* ( */ OPT_26 TOKEN_14 /* ) */ 
    {
        struct ast_ansi_port_declaration *ret = new (struct ast_ansi_port_declaration);
        $$ = ret;
    }
    ;

elaboration_system_task 
    : TOKEN_39 /* dollarsign_fatal */ OPT_28 TOKEN_0 /* ; */ 
    {
        struct ast_elaboration_system_task *ret = new (struct ast_elaboration_system_task);
        $$ = ret;
    }
    | TOKEN_40 /* dollarsign_error */ OPT_30 TOKEN_0 /* ; */ 
    {
        struct ast_elaboration_system_task *ret = new (struct ast_elaboration_system_task);
        $$ = ret;
    }
    | TOKEN_41 /* dollarsign_warning */ OPT_30 TOKEN_0 /* ; */ 
    {
        struct ast_elaboration_system_task *ret = new (struct ast_elaboration_system_task);
        $$ = ret;
    }
    | TOKEN_42 /* dollarsign_info */ OPT_30 TOKEN_0 /* ; */ 
    {
        struct ast_elaboration_system_task *ret = new (struct ast_elaboration_system_task);
        $$ = ret;
    }
    ;

finish_number 
    : TOKEN_43 /* 0 */ 
    {
        struct ast_finish_number *ret = new (struct ast_finish_number);
        $$ = ret;
    }
    | TOKEN_44 /* 1 */ 
    {
        struct ast_finish_number *ret = new (struct ast_finish_number);
        $$ = ret;
    }
    | TOKEN_45 /* 2 */ 
    {
        struct ast_finish_number *ret = new (struct ast_finish_number);
        $$ = ret;
    }
    ;

module_common_item 
    : module_or_generate_item_declaration 
    {
        struct ast_module_common_item *ret = new (struct ast_module_common_item);
        $$ = ret;
    }
    | interface_instantiation 
    {
        struct ast_module_common_item *ret = new (struct ast_module_common_item);
        $$ = ret;
    }
    | program_instantiation 
    {
        struct ast_module_common_item *ret = new (struct ast_module_common_item);
        $$ = ret;
    }
    | assertion_item 
    {
        struct ast_module_common_item *ret = new (struct ast_module_common_item);
        $$ = ret;
    }
    | bind_directive 
    {
        struct ast_module_common_item *ret = new (struct ast_module_common_item);
        $$ = ret;
    }
    | continuous_assign 
    {
        struct ast_module_common_item *ret = new (struct ast_module_common_item);
        $$ = ret;
    }
    | net_alias 
    {
        struct ast_module_common_item *ret = new (struct ast_module_common_item);
        $$ = ret;
    }
    | initial_construct 
    {
        struct ast_module_common_item *ret = new (struct ast_module_common_item);
        $$ = ret;
    }
    | final_construct 
    {
        struct ast_module_common_item *ret = new (struct ast_module_common_item);
        $$ = ret;
    }
    | always_construct 
    {
        struct ast_module_common_item *ret = new (struct ast_module_common_item);
        $$ = ret;
    }
    | loop_generate_construct 
    {
        struct ast_module_common_item *ret = new (struct ast_module_common_item);
        $$ = ret;
    }
    | conditional_generate_construct 
    {
        struct ast_module_common_item *ret = new (struct ast_module_common_item);
        $$ = ret;
    }
    | elaboration_system_task 
    {
        struct ast_module_common_item *ret = new (struct ast_module_common_item);
        $$ = ret;
    }
    ;

module_item 
    : port_declaration TOKEN_0 /* ; */ 
    {
        struct ast_module_item *ret = new (struct ast_module_item);
        $$ = ret;
    }
    | non_port_module_item 
    {
        struct ast_module_item *ret = new (struct ast_module_item);
        $$ = ret;
    }
    ;

module_or_generate_item 
    : STAR_2 parameter_override 
    {
        struct ast_module_or_generate_item *ret = new (struct ast_module_or_generate_item);
        $$ = ret;
    }
    | STAR_2 gate_instantiation 
    {
        struct ast_module_or_generate_item *ret = new (struct ast_module_or_generate_item);
        $$ = ret;
    }
    | STAR_2 udp_instantiation 
    {
        struct ast_module_or_generate_item *ret = new (struct ast_module_or_generate_item);
        $$ = ret;
    }
    | STAR_2 module_instantiation 
    {
        struct ast_module_or_generate_item *ret = new (struct ast_module_or_generate_item);
        $$ = ret;
    }
    | STAR_2 module_common_item 
    {
        struct ast_module_or_generate_item *ret = new (struct ast_module_or_generate_item);
        $$ = ret;
    }
    ;

module_or_generate_item_declaration 
    : package_or_generate_item_declaration 
    {
        struct ast_module_or_generate_item_declaration *ret = new (struct ast_module_or_generate_item_declaration);
        $$ = ret;
    }
    | genvar_declaration 
    {
        struct ast_module_or_generate_item_declaration *ret = new (struct ast_module_or_generate_item_declaration);
        $$ = ret;
    }
    | clocking_declaration 
    {
        struct ast_module_or_generate_item_declaration *ret = new (struct ast_module_or_generate_item_declaration);
        $$ = ret;
    }
    | TOKEN_46 /* default */ TOKEN_47 /* clocking */ clocking_identifier TOKEN_0 /* ; */ 
    {
        struct ast_module_or_generate_item_declaration *ret = new (struct ast_module_or_generate_item_declaration);
        $$ = ret;
    }
    | TOKEN_46 /* default */ TOKEN_48 /* disable */ TOKEN_49 /* iff */ expression_or_dist TOKEN_0 /* ; */ 
    {
        struct ast_module_or_generate_item_declaration *ret = new (struct ast_module_or_generate_item_declaration);
        $$ = ret;
    }
    ;

non_port_module_item 
    : generate_region 
    {
        struct ast_non_port_module_item *ret = new (struct ast_non_port_module_item);
        $$ = ret;
    }
    | module_or_generate_item 
    {
        struct ast_non_port_module_item *ret = new (struct ast_non_port_module_item);
        $$ = ret;
    }
    | specify_block 
    {
        struct ast_non_port_module_item *ret = new (struct ast_non_port_module_item);
        $$ = ret;
    }
    | STAR_2 specparam_declaration 
    {
        struct ast_non_port_module_item *ret = new (struct ast_non_port_module_item);
        $$ = ret;
    }
    | program_declaration 
    {
        struct ast_non_port_module_item *ret = new (struct ast_non_port_module_item);
        $$ = ret;
    }
    | module_declaration 
    {
        struct ast_non_port_module_item *ret = new (struct ast_non_port_module_item);
        $$ = ret;
    }
    | interface_declaration 
    {
        struct ast_non_port_module_item *ret = new (struct ast_non_port_module_item);
        $$ = ret;
    }
    | timeunits_declaration 
    {
        struct ast_non_port_module_item *ret = new (struct ast_non_port_module_item);
        $$ = ret;
    }
    ;

parameter_override 
    : TOKEN_50 /* defparam */ list_of_defparam_assignments TOKEN_0 /* ; */ 
    {
        struct ast_parameter_override *ret = new (struct ast_parameter_override);
        $$ = ret;
    }
    ;

bind_directive 
    : TOKEN_51 /* bind */ bind_target_scope OPT_31 bind_instantiation TOKEN_0 /* ; */ 
    {
        struct ast_bind_directive *ret = new (struct ast_bind_directive);
        $$ = ret;
    }
    | TOKEN_51 /* bind */ bind_target_instance bind_instantiation TOKEN_0 /* ; */ 
    {
        struct ast_bind_directive *ret = new (struct ast_bind_directive);
        $$ = ret;
    }
    ;

bind_target_scope 
    : module_identifier 
    {
        struct ast_bind_target_scope *ret = new (struct ast_bind_target_scope);
        $$ = ret;
    }
    | interface_identifier 
    {
        struct ast_bind_target_scope *ret = new (struct ast_bind_target_scope);
        $$ = ret;
    }
    ;

bind_target_instance 
    : hierarchical_identifier constant_bit_select 
    {
        struct ast_bind_target_instance *ret = new (struct ast_bind_target_instance);
        $$ = ret;
    }
    ;

bind_target_instance_list 
    : LIST_22 
    {
        struct ast_bind_target_instance_list *ret = new (struct ast_bind_target_instance_list);
        $$ = ret;
    }
    ;

bind_instantiation 
    : program_instantiation 
    {
        struct ast_bind_instantiation *ret = new (struct ast_bind_instantiation);
        $$ = ret;
    }
    | module_instantiation 
    {
        struct ast_bind_instantiation *ret = new (struct ast_bind_instantiation);
        $$ = ret;
    }
    | interface_instantiation 
    {
        struct ast_bind_instantiation *ret = new (struct ast_bind_instantiation);
        $$ = ret;
    }
    | checker_instantiation 
    {
        struct ast_bind_instantiation *ret = new (struct ast_bind_instantiation);
        $$ = ret;
    }
    ;

config_declaration 
    : TOKEN_52 /* config */ config_identifier TOKEN_0 /* ; */ STAR_16 design_statement STAR_17 TOKEN_53 /* endconfig */ OPT_32 
    {
        struct ast_config_declaration *ret = new (struct ast_config_declaration);
        $$ = ret;
    }
    ;

design_statement 
    : TOKEN_54 /* design */ STAR_18 TOKEN_0 /* ; */ 
    {
        struct ast_design_statement *ret = new (struct ast_design_statement);
        $$ = ret;
    }
    ;

config_rule_statement 
    : default_clause liblist_clause TOKEN_0 /* ; */ 
    {
        struct ast_config_rule_statement *ret = new (struct ast_config_rule_statement);
        $$ = ret;
    }
    | inst_clause liblist_clause TOKEN_0 /* ; */ 
    {
        struct ast_config_rule_statement *ret = new (struct ast_config_rule_statement);
        $$ = ret;
    }
    | inst_clause use_clause TOKEN_0 /* ; */ 
    {
        struct ast_config_rule_statement *ret = new (struct ast_config_rule_statement);
        $$ = ret;
    }
    | cell_clause liblist_clause TOKEN_0 /* ; */ 
    {
        struct ast_config_rule_statement *ret = new (struct ast_config_rule_statement);
        $$ = ret;
    }
    | cell_clause use_clause TOKEN_0 /* ; */ 
    {
        struct ast_config_rule_statement *ret = new (struct ast_config_rule_statement);
        $$ = ret;
    }
    ;

default_clause 
    : TOKEN_46 /* default */ 
    {
        struct ast_default_clause *ret = new (struct ast_default_clause);
        $$ = ret;
    }
    ;

inst_clause 
    : TOKEN_55 /* instance */ inst_name 
    {
        struct ast_inst_clause *ret = new (struct ast_inst_clause);
        $$ = ret;
    }
    ;

inst_name 
    : topmodule_identifier STAR_19 
    {
        struct ast_inst_name *ret = new (struct ast_inst_name);
        $$ = ret;
    }
    ;

cell_clause 
    : TOKEN_56 /* cell */ OPT_33 cell_identifier 
    {
        struct ast_cell_clause *ret = new (struct ast_cell_clause);
        $$ = ret;
    }
    ;

liblist_clause 
    : TOKEN_57 /* liblist */ STAR_20 
    {
        struct ast_liblist_clause *ret = new (struct ast_liblist_clause);
        $$ = ret;
    }
    ;

use_clause 
    : TOKEN_58 /* use */ OPT_33 cell_identifier OPT_34 
    {
        struct ast_use_clause *ret = new (struct ast_use_clause);
        $$ = ret;
    }
    | TOKEN_58 /* use */ LIST_28 OPT_34 
    {
        struct ast_use_clause *ret = new (struct ast_use_clause);
        $$ = ret;
    }
    | TOKEN_58 /* use */ OPT_33 cell_identifier LIST_28 OPT_34 
    {
        struct ast_use_clause *ret = new (struct ast_use_clause);
        $$ = ret;
    }
    ;

interface_or_generate_item 
    : STAR_2 module_common_item 
    {
        struct ast_interface_or_generate_item *ret = new (struct ast_interface_or_generate_item);
        $$ = ret;
    }
    | STAR_2 modport_declaration 
    {
        struct ast_interface_or_generate_item *ret = new (struct ast_interface_or_generate_item);
        $$ = ret;
    }
    | STAR_2 extern_tf_declaration 
    {
        struct ast_interface_or_generate_item *ret = new (struct ast_interface_or_generate_item);
        $$ = ret;
    }
    ;

extern_tf_declaration 
    : TOKEN_7 /* extern */ method_prototype TOKEN_0 /* ; */ 
    {
        struct ast_extern_tf_declaration *ret = new (struct ast_extern_tf_declaration);
        $$ = ret;
    }
    | TOKEN_7 /* extern */ TOKEN_59 /* forkjoin */ task_prototype TOKEN_0 /* ; */ 
    {
        struct ast_extern_tf_declaration *ret = new (struct ast_extern_tf_declaration);
        $$ = ret;
    }
    ;

interface_item 
    : port_declaration TOKEN_0 /* ; */ 
    {
        struct ast_interface_item *ret = new (struct ast_interface_item);
        $$ = ret;
    }
    | non_port_interface_item 
    {
        struct ast_interface_item *ret = new (struct ast_interface_item);
        $$ = ret;
    }
    ;

non_port_interface_item 
    : generate_region 
    {
        struct ast_non_port_interface_item *ret = new (struct ast_non_port_interface_item);
        $$ = ret;
    }
    | interface_or_generate_item 
    {
        struct ast_non_port_interface_item *ret = new (struct ast_non_port_interface_item);
        $$ = ret;
    }
    | program_declaration 
    {
        struct ast_non_port_interface_item *ret = new (struct ast_non_port_interface_item);
        $$ = ret;
    }
    | interface_declaration 
    {
        struct ast_non_port_interface_item *ret = new (struct ast_non_port_interface_item);
        $$ = ret;
    }
    | timeunits_declaration 
    {
        struct ast_non_port_interface_item *ret = new (struct ast_non_port_interface_item);
        $$ = ret;
    }
    ;

program_item 
    : port_declaration TOKEN_0 /* ; */ 
    {
        struct ast_program_item *ret = new (struct ast_program_item);
        $$ = ret;
    }
    | non_port_program_item 
    {
        struct ast_program_item *ret = new (struct ast_program_item);
        $$ = ret;
    }
    ;

non_port_program_item 
    : STAR_2 continuous_assign 
    {
        struct ast_non_port_program_item *ret = new (struct ast_non_port_program_item);
        $$ = ret;
    }
    | STAR_2 module_or_generate_item_declaration 
    {
        struct ast_non_port_program_item *ret = new (struct ast_non_port_program_item);
        $$ = ret;
    }
    | STAR_2 initial_construct 
    {
        struct ast_non_port_program_item *ret = new (struct ast_non_port_program_item);
        $$ = ret;
    }
    | STAR_2 final_construct 
    {
        struct ast_non_port_program_item *ret = new (struct ast_non_port_program_item);
        $$ = ret;
    }
    | STAR_2 concurrent_assertion_item 
    {
        struct ast_non_port_program_item *ret = new (struct ast_non_port_program_item);
        $$ = ret;
    }
    | timeunits_declaration 
    {
        struct ast_non_port_program_item *ret = new (struct ast_non_port_program_item);
        $$ = ret;
    }
    | program_generate_item 
    {
        struct ast_non_port_program_item *ret = new (struct ast_non_port_program_item);
        $$ = ret;
    }
    ;

program_generate_item 
    : loop_generate_construct 
    {
        struct ast_program_generate_item *ret = new (struct ast_program_generate_item);
        $$ = ret;
    }
    | conditional_generate_construct 
    {
        struct ast_program_generate_item *ret = new (struct ast_program_generate_item);
        $$ = ret;
    }
    | generate_region 
    {
        struct ast_program_generate_item *ret = new (struct ast_program_generate_item);
        $$ = ret;
    }
    | elaboration_system_task 
    {
        struct ast_program_generate_item *ret = new (struct ast_program_generate_item);
        $$ = ret;
    }
    ;

checker_port_list 
    : LIST_29 
    {
        struct ast_checker_port_list *ret = new (struct ast_checker_port_list);
        $$ = ret;
    }
    ;

checker_port_item 
    : STAR_2 OPT_35 property_formal_type formal_port_identifier STAR_15 OPT_36 
    {
        struct ast_checker_port_item *ret = new (struct ast_checker_port_item);
        $$ = ret;
    }
    ;

checker_port_direction 
    : TOKEN_34 /* input */ 
    {
        struct ast_checker_port_direction *ret = new (struct ast_checker_port_direction);
        $$ = ret;
    }
    | TOKEN_35 /* output */ 
    {
        struct ast_checker_port_direction *ret = new (struct ast_checker_port_direction);
        $$ = ret;
    }
    ;

checker_or_generate_item 
    : checker_or_generate_item_declaration 
    {
        struct ast_checker_or_generate_item *ret = new (struct ast_checker_or_generate_item);
        $$ = ret;
    }
    | initial_construct 
    {
        struct ast_checker_or_generate_item *ret = new (struct ast_checker_or_generate_item);
        $$ = ret;
    }
    | always_construct 
    {
        struct ast_checker_or_generate_item *ret = new (struct ast_checker_or_generate_item);
        $$ = ret;
    }
    | final_construct 
    {
        struct ast_checker_or_generate_item *ret = new (struct ast_checker_or_generate_item);
        $$ = ret;
    }
    | assertion_item 
    {
        struct ast_checker_or_generate_item *ret = new (struct ast_checker_or_generate_item);
        $$ = ret;
    }
    | continuous_assign 
    {
        struct ast_checker_or_generate_item *ret = new (struct ast_checker_or_generate_item);
        $$ = ret;
    }
    | checker_generate_item 
    {
        struct ast_checker_or_generate_item *ret = new (struct ast_checker_or_generate_item);
        $$ = ret;
    }
    ;

checker_or_generate_item_declaration 
    : OPT_37 data_declaration 
    {
        struct ast_checker_or_generate_item_declaration *ret = new (struct ast_checker_or_generate_item_declaration);
        $$ = ret;
    }
    | function_declaration 
    {
        struct ast_checker_or_generate_item_declaration *ret = new (struct ast_checker_or_generate_item_declaration);
        $$ = ret;
    }
    | checker_declaration 
    {
        struct ast_checker_or_generate_item_declaration *ret = new (struct ast_checker_or_generate_item_declaration);
        $$ = ret;
    }
    | assertion_item_declaration 
    {
        struct ast_checker_or_generate_item_declaration *ret = new (struct ast_checker_or_generate_item_declaration);
        $$ = ret;
    }
    | covergroup_declaration 
    {
        struct ast_checker_or_generate_item_declaration *ret = new (struct ast_checker_or_generate_item_declaration);
        $$ = ret;
    }
    | overload_declaration 
    {
        struct ast_checker_or_generate_item_declaration *ret = new (struct ast_checker_or_generate_item_declaration);
        $$ = ret;
    }
    | genvar_declaration 
    {
        struct ast_checker_or_generate_item_declaration *ret = new (struct ast_checker_or_generate_item_declaration);
        $$ = ret;
    }
    | clocking_declaration 
    {
        struct ast_checker_or_generate_item_declaration *ret = new (struct ast_checker_or_generate_item_declaration);
        $$ = ret;
    }
    | TOKEN_46 /* default */ TOKEN_47 /* clocking */ clocking_identifier TOKEN_0 /* ; */ 
    {
        struct ast_checker_or_generate_item_declaration *ret = new (struct ast_checker_or_generate_item_declaration);
        $$ = ret;
    }
    | TOKEN_46 /* default */ TOKEN_48 /* disable */ TOKEN_49 /* iff */ expression_or_dist TOKEN_0 /* ; */ 
    {
        struct ast_checker_or_generate_item_declaration *ret = new (struct ast_checker_or_generate_item_declaration);
        $$ = ret;
    }
    ;

checker_generate_item 
    : loop_generate_construct 
    {
        struct ast_checker_generate_item *ret = new (struct ast_checker_generate_item);
        $$ = ret;
    }
    | conditional_generate_construct 
    {
        struct ast_checker_generate_item *ret = new (struct ast_checker_generate_item);
        $$ = ret;
    }
    | generate_region 
    {
        struct ast_checker_generate_item *ret = new (struct ast_checker_generate_item);
        $$ = ret;
    }
    | elaboration_system_task 
    {
        struct ast_checker_generate_item *ret = new (struct ast_checker_generate_item);
        $$ = ret;
    }
    ;

class_item 
    : STAR_2 class_property 
    {
        struct ast_class_item *ret = new (struct ast_class_item);
        $$ = ret;
    }
    | STAR_2 class_method 
    {
        struct ast_class_item *ret = new (struct ast_class_item);
        $$ = ret;
    }
    | STAR_2 class_constraint 
    {
        struct ast_class_item *ret = new (struct ast_class_item);
        $$ = ret;
    }
    | STAR_2 class_declaration 
    {
        struct ast_class_item *ret = new (struct ast_class_item);
        $$ = ret;
    }
    | STAR_2 covergroup_declaration 
    {
        struct ast_class_item *ret = new (struct ast_class_item);
        $$ = ret;
    }
    | local_parameter_declaration TOKEN_0 /* ; */ 
    {
        struct ast_class_item *ret = new (struct ast_class_item);
        $$ = ret;
    }
    | parameter_declaration TOKEN_0 /* ; */ 
    {
        struct ast_class_item *ret = new (struct ast_class_item);
        $$ = ret;
    }
    | TOKEN_0 /* ; */ 
    {
        struct ast_class_item *ret = new (struct ast_class_item);
        $$ = ret;
    }
    ;

class_property 
    : STAR_21 data_declaration 
    {
        struct ast_class_property *ret = new (struct ast_class_property);
        $$ = ret;
    }
    | TOKEN_61 /* const */ STAR_22 data_type const_identifier OPT_24 TOKEN_0 /* ; */ 
    {
        struct ast_class_property *ret = new (struct ast_class_property);
        $$ = ret;
    }
    ;

class_method 
    : STAR_23 task_declaration 
    {
        struct ast_class_method *ret = new (struct ast_class_method);
        $$ = ret;
    }
    | STAR_23 function_declaration 
    {
        struct ast_class_method *ret = new (struct ast_class_method);
        $$ = ret;
    }
    | TOKEN_62 /* pure */ TOKEN_19 /* virtual */ STAR_22 method_prototype TOKEN_0 /* ; */ 
    {
        struct ast_class_method *ret = new (struct ast_class_method);
        $$ = ret;
    }
    | TOKEN_7 /* extern */ STAR_23 method_prototype TOKEN_0 /* ; */ 
    {
        struct ast_class_method *ret = new (struct ast_class_method);
        $$ = ret;
    }
    | STAR_23 class_constructor_declaration 
    {
        struct ast_class_method *ret = new (struct ast_class_method);
        $$ = ret;
    }
    | TOKEN_7 /* extern */ STAR_23 class_constructor_prototype 
    {
        struct ast_class_method *ret = new (struct ast_class_method);
        $$ = ret;
    }
    ;

class_constructor_prototype 
    : TOKEN_63 /* function */ TOKEN_64 /* new */ OPT_39 TOKEN_0 /* ; */ 
    {
        struct ast_class_constructor_prototype *ret = new (struct ast_class_constructor_prototype);
        $$ = ret;
    }
    ;

class_constraint 
    : constraint_prototype 
    {
        struct ast_class_constraint *ret = new (struct ast_class_constraint);
        $$ = ret;
    }
    | constraint_declaration 
    {
        struct ast_class_constraint *ret = new (struct ast_class_constraint);
        $$ = ret;
    }
    ;

class_item_qualifier 
    : TOKEN_65 /* static */ 
    {
        struct ast_class_item_qualifier *ret = new (struct ast_class_item_qualifier);
        $$ = ret;
    }
    | TOKEN_66 /* protected */ 
    {
        struct ast_class_item_qualifier *ret = new (struct ast_class_item_qualifier);
        $$ = ret;
    }
    | TOKEN_67 /* local */ 
    {
        struct ast_class_item_qualifier *ret = new (struct ast_class_item_qualifier);
        $$ = ret;
    }
    ;

property_qualifier 
    : random_qualifier 
    {
        struct ast_property_qualifier *ret = new (struct ast_property_qualifier);
        $$ = ret;
    }
    | class_item_qualifier 
    {
        struct ast_property_qualifier *ret = new (struct ast_property_qualifier);
        $$ = ret;
    }
    ;

random_qualifier 
    : TOKEN_60 /* rand */ 
    {
        struct ast_random_qualifier *ret = new (struct ast_random_qualifier);
        $$ = ret;
    }
    | TOKEN_68 /* randc */ 
    {
        struct ast_random_qualifier *ret = new (struct ast_random_qualifier);
        $$ = ret;
    }
    ;

method_qualifier 
    : OPT_40 TOKEN_19 /* virtual */ 
    {
        struct ast_method_qualifier *ret = new (struct ast_method_qualifier);
        $$ = ret;
    }
    | class_item_qualifier 
    {
        struct ast_method_qualifier *ret = new (struct ast_method_qualifier);
        $$ = ret;
    }
    ;

method_prototype 
    : task_prototype 
    {
        struct ast_method_prototype *ret = new (struct ast_method_prototype);
        $$ = ret;
    }
    | function_prototype 
    {
        struct ast_method_prototype *ret = new (struct ast_method_prototype);
        $$ = ret;
    }
    ;

class_constructor_declaration 
    : TOKEN_63 /* function */ OPT_41 TOKEN_64 /* new */ OPT_39 TOKEN_0 /* ; */ STAR_24 OPT_42 STAR_25 TOKEN_70 /* endfunction */ OPT_43 
    {
        struct ast_class_constructor_declaration *ret = new (struct ast_class_constructor_declaration);
        $$ = ret;
    }
    ;

constraint_declaration 
    : OPT_44 TOKEN_71 /* constraint */ constraint_identifier constraint_block 
    {
        struct ast_constraint_declaration *ret = new (struct ast_constraint_declaration);
        $$ = ret;
    }
    ;

constraint_block 
    : TOKEN_32 /* { */ STAR_26 TOKEN_33 /* } */ 
    {
        struct ast_constraint_block *ret = new (struct ast_constraint_block);
        $$ = ret;
    }
    ;

constraint_block_item 
    : TOKEN_72 /* solve */ solve_before_list TOKEN_73 /* before */ solve_before_list TOKEN_0 /* ; */ 
    {
        struct ast_constraint_block_item *ret = new (struct ast_constraint_block_item);
        $$ = ret;
    }
    | constraint_expression 
    {
        struct ast_constraint_block_item *ret = new (struct ast_constraint_block_item);
        $$ = ret;
    }
    ;

solve_before_list 
    : LIST_36 
    {
        struct ast_solve_before_list *ret = new (struct ast_solve_before_list);
        $$ = ret;
    }
    ;

constraint_primary 
    : OPT_45 hierarchical_identifier select 
    {
        struct ast_constraint_primary *ret = new (struct ast_constraint_primary);
        $$ = ret;
    }
    ;

constraint_expression 
    : OPT_46 expression_or_dist TOKEN_0 /* ; */ 
    {
        struct ast_constraint_expression *ret = new (struct ast_constraint_expression);
        $$ = ret;
    }
    | uniqueness_constraint TOKEN_0 /* ; */ 
    {
        struct ast_constraint_expression *ret = new (struct ast_constraint_expression);
        $$ = ret;
    }
    | expression TOKEN_75 /* -> */ constraint_set 
    {
        struct ast_constraint_expression *ret = new (struct ast_constraint_expression);
        $$ = ret;
    }
    | TOKEN_76 /* if */ TOKEN_12 /* ( */ expression TOKEN_14 /* ) */ constraint_set OPT_47 
    {
        struct ast_constraint_expression *ret = new (struct ast_constraint_expression);
        $$ = ret;
    }
    | TOKEN_78 /* foreach */ TOKEN_12 /* ( */ ps_or_hierarchical_array_identifier TOKEN_79 /* [ */ loop_variables TOKEN_80 /* ] */ TOKEN_14 /* ) */ constraint_set 
    {
        struct ast_constraint_expression *ret = new (struct ast_constraint_expression);
        $$ = ret;
    }
    | TOKEN_48 /* disable */ TOKEN_74 /* soft */ constraint_primary TOKEN_0 /* ; */ 
    {
        struct ast_constraint_expression *ret = new (struct ast_constraint_expression);
        $$ = ret;
    }
    ;

uniqueness_constraint 
    : TOKEN_81 /* unique */ TOKEN_32 /* { */ open_range_list TOKEN_33 /* } */ 
    {
        struct ast_uniqueness_constraint *ret = new (struct ast_uniqueness_constraint);
        $$ = ret;
    }
    ;

constraint_set 
    : constraint_expression 
    {
        struct ast_constraint_set *ret = new (struct ast_constraint_set);
        $$ = ret;
    }
    | TOKEN_32 /* { */ STAR_27 TOKEN_33 /* } */ 
    {
        struct ast_constraint_set *ret = new (struct ast_constraint_set);
        $$ = ret;
    }
    ;

dist_list 
    : LIST_38 
    {
        struct ast_dist_list *ret = new (struct ast_dist_list);
        $$ = ret;
    }
    ;

dist_item 
    : value_range OPT_48 
    {
        struct ast_dist_item *ret = new (struct ast_dist_item);
        $$ = ret;
    }
    ;

dist_weight 
    : TOKEN_82 /* := */ expression 
    {
        struct ast_dist_weight *ret = new (struct ast_dist_weight);
        $$ = ret;
    }
    | TOKEN_83 /* :/ */ expression 
    {
        struct ast_dist_weight *ret = new (struct ast_dist_weight);
        $$ = ret;
    }
    ;

constraint_prototype 
    : OPT_49 OPT_44 TOKEN_71 /* constraint */ constraint_identifier TOKEN_0 /* ; */ 
    {
        struct ast_constraint_prototype *ret = new (struct ast_constraint_prototype);
        $$ = ret;
    }
    ;

constraint_prototype_qualifier 
    : TOKEN_7 /* extern */ 
    {
        struct ast_constraint_prototype_qualifier *ret = new (struct ast_constraint_prototype_qualifier);
        $$ = ret;
    }
    | TOKEN_62 /* pure */ 
    {
        struct ast_constraint_prototype_qualifier *ret = new (struct ast_constraint_prototype_qualifier);
        $$ = ret;
    }
    ;

extern_constraint_declaration 
    : OPT_44 TOKEN_71 /* constraint */ class_scope constraint_identifier constraint_block 
    {
        struct ast_extern_constraint_declaration *ret = new (struct ast_extern_constraint_declaration);
        $$ = ret;
    }
    ;

identifier_list 
    : LIST_39 
    {
        struct ast_identifier_list *ret = new (struct ast_identifier_list);
        $$ = ret;
    }
    ;

package_item 
    : package_or_generate_item_declaration 
    {
        struct ast_package_item *ret = new (struct ast_package_item);
        $$ = ret;
    }
    | anonymous_program 
    {
        struct ast_package_item *ret = new (struct ast_package_item);
        $$ = ret;
    }
    | package_export_declaration 
    {
        struct ast_package_item *ret = new (struct ast_package_item);
        $$ = ret;
    }
    | timeunits_declaration 
    {
        struct ast_package_item *ret = new (struct ast_package_item);
        $$ = ret;
    }
    ;

package_or_generate_item_declaration 
    : net_declaration 
    {
        struct ast_package_or_generate_item_declaration *ret = new (struct ast_package_or_generate_item_declaration);
        $$ = ret;
    }
    | data_declaration 
    {
        struct ast_package_or_generate_item_declaration *ret = new (struct ast_package_or_generate_item_declaration);
        $$ = ret;
    }
    | task_declaration 
    {
        struct ast_package_or_generate_item_declaration *ret = new (struct ast_package_or_generate_item_declaration);
        $$ = ret;
    }
    | function_declaration 
    {
        struct ast_package_or_generate_item_declaration *ret = new (struct ast_package_or_generate_item_declaration);
        $$ = ret;
    }
    | checker_declaration 
    {
        struct ast_package_or_generate_item_declaration *ret = new (struct ast_package_or_generate_item_declaration);
        $$ = ret;
    }
    | dpi_import_export 
    {
        struct ast_package_or_generate_item_declaration *ret = new (struct ast_package_or_generate_item_declaration);
        $$ = ret;
    }
    | extern_constraint_declaration 
    {
        struct ast_package_or_generate_item_declaration *ret = new (struct ast_package_or_generate_item_declaration);
        $$ = ret;
    }
    | class_declaration 
    {
        struct ast_package_or_generate_item_declaration *ret = new (struct ast_package_or_generate_item_declaration);
        $$ = ret;
    }
    | class_constructor_declaration 
    {
        struct ast_package_or_generate_item_declaration *ret = new (struct ast_package_or_generate_item_declaration);
        $$ = ret;
    }
    | local_parameter_declaration TOKEN_0 /* ; */ 
    {
        struct ast_package_or_generate_item_declaration *ret = new (struct ast_package_or_generate_item_declaration);
        $$ = ret;
    }
    | parameter_declaration TOKEN_0 /* ; */ 
    {
        struct ast_package_or_generate_item_declaration *ret = new (struct ast_package_or_generate_item_declaration);
        $$ = ret;
    }
    | covergroup_declaration 
    {
        struct ast_package_or_generate_item_declaration *ret = new (struct ast_package_or_generate_item_declaration);
        $$ = ret;
    }
    | overload_declaration 
    {
        struct ast_package_or_generate_item_declaration *ret = new (struct ast_package_or_generate_item_declaration);
        $$ = ret;
    }
    | assertion_item_declaration 
    {
        struct ast_package_or_generate_item_declaration *ret = new (struct ast_package_or_generate_item_declaration);
        $$ = ret;
    }
    | TOKEN_0 /* ; */ 
    {
        struct ast_package_or_generate_item_declaration *ret = new (struct ast_package_or_generate_item_declaration);
        $$ = ret;
    }
    ;

anonymous_program 
    : TOKEN_16 /* program */ TOKEN_0 /* ; */ STAR_28 TOKEN_15 /* endprogram */ 
    {
        struct ast_anonymous_program *ret = new (struct ast_anonymous_program);
        $$ = ret;
    }
    ;

anonymous_program_item 
    : task_declaration 
    {
        struct ast_anonymous_program_item *ret = new (struct ast_anonymous_program_item);
        $$ = ret;
    }
    | function_declaration 
    {
        struct ast_anonymous_program_item *ret = new (struct ast_anonymous_program_item);
        $$ = ret;
    }
    | class_declaration 
    {
        struct ast_anonymous_program_item *ret = new (struct ast_anonymous_program_item);
        $$ = ret;
    }
    | covergroup_declaration 
    {
        struct ast_anonymous_program_item *ret = new (struct ast_anonymous_program_item);
        $$ = ret;
    }
    | class_constructor_declaration 
    {
        struct ast_anonymous_program_item *ret = new (struct ast_anonymous_program_item);
        $$ = ret;
    }
    | TOKEN_0 /* ; */ 
    {
        struct ast_anonymous_program_item *ret = new (struct ast_anonymous_program_item);
        $$ = ret;
    }
    ;

local_parameter_declaration 
    : TOKEN_84 /* localparam */ data_type_or_implicit list_of_param_assignments 
    {
        struct ast_local_parameter_declaration *ret = new (struct ast_local_parameter_declaration);
        $$ = ret;
    }
    | TOKEN_84 /* localparam */ TOKEN_30 /* type */ list_of_type_assignments 
    {
        struct ast_local_parameter_declaration *ret = new (struct ast_local_parameter_declaration);
        $$ = ret;
    }
    ;

parameter_declaration 
    : TOKEN_85 /* parameter */ data_type_or_implicit list_of_param_assignments 
    {
        struct ast_parameter_declaration *ret = new (struct ast_parameter_declaration);
        $$ = ret;
    }
    | TOKEN_85 /* parameter */ TOKEN_30 /* type */ list_of_type_assignments 
    {
        struct ast_parameter_declaration *ret = new (struct ast_parameter_declaration);
        $$ = ret;
    }
    ;

specparam_declaration 
    : TOKEN_86 /* specparam */ OPT_50 list_of_specparam_assignments TOKEN_0 /* ; */ 
    {
        struct ast_specparam_declaration *ret = new (struct ast_specparam_declaration);
        $$ = ret;
    }
    ;

inout_declaration 
    : TOKEN_36 /* inout */ net_port_type list_of_port_identifiers 
    {
        struct ast_inout_declaration *ret = new (struct ast_inout_declaration);
        $$ = ret;
    }
    ;

input_declaration 
    : TOKEN_34 /* input */ net_port_type list_of_port_identifiers 
    {
        struct ast_input_declaration *ret = new (struct ast_input_declaration);
        $$ = ret;
    }
    | TOKEN_34 /* input */ variable_port_type list_of_variable_identifiers 
    {
        struct ast_input_declaration *ret = new (struct ast_input_declaration);
        $$ = ret;
    }
    ;

output_declaration 
    : TOKEN_35 /* output */ net_port_type list_of_port_identifiers 
    {
        struct ast_output_declaration *ret = new (struct ast_output_declaration);
        $$ = ret;
    }
    | TOKEN_35 /* output */ variable_port_type list_of_variable_port_identifiers 
    {
        struct ast_output_declaration *ret = new (struct ast_output_declaration);
        $$ = ret;
    }
    ;

interface_port_declaration 
    : interface_identifier list_of_interface_identifiers 
    {
        struct ast_interface_port_declaration *ret = new (struct ast_interface_port_declaration);
        $$ = ret;
    }
    | interface_identifier TOKEN_31 /* . */ modport_identifier list_of_interface_identifiers 
    {
        struct ast_interface_port_declaration *ret = new (struct ast_interface_port_declaration);
        $$ = ret;
    }
    ;

ref_declaration 
    : TOKEN_37 /* ref */ variable_port_type list_of_variable_identifiers 
    {
        struct ast_ref_declaration *ret = new (struct ast_ref_declaration);
        $$ = ret;
    }
    ;

data_declaration 
    : OPT_51 OPT_52 OPT_2 data_type_or_implicit list_of_variable_decl_assignments TOKEN_0 /* ; */ 
    {
        struct ast_data_declaration *ret = new (struct ast_data_declaration);
        $$ = ret;
    }
    | type_declaration 
    {
        struct ast_data_declaration *ret = new (struct ast_data_declaration);
        $$ = ret;
    }
    | package_import_declaration 
    {
        struct ast_data_declaration *ret = new (struct ast_data_declaration);
        $$ = ret;
    }
    | net_type_declaration 
    {
        struct ast_data_declaration *ret = new (struct ast_data_declaration);
        $$ = ret;
    }
    ;

package_import_declaration 
    : TOKEN_88 /* import */ LIST_41 TOKEN_0 /* ; */ 
    {
        struct ast_package_import_declaration *ret = new (struct ast_package_import_declaration);
        $$ = ret;
    }
    ;

package_import_item 
    : package_identifier TOKEN_89 /* :: */ identifier 
    {
        struct ast_package_import_item *ret = new (struct ast_package_import_item);
        $$ = ret;
    }
    | package_identifier TOKEN_89 /* :: */ TOKEN_90 /* * */ 
    {
        struct ast_package_import_item *ret = new (struct ast_package_import_item);
        $$ = ret;
    }
    ;

package_export_declaration 
    : TOKEN_91 /* export */ TOKEN_92 /* *::* */ TOKEN_0 /* ; */ 
    {
        struct ast_package_export_declaration *ret = new (struct ast_package_export_declaration);
        $$ = ret;
    }
    | TOKEN_91 /* export */ LIST_41 TOKEN_0 /* ; */ 
    {
        struct ast_package_export_declaration *ret = new (struct ast_package_export_declaration);
        $$ = ret;
    }
    ;

genvar_declaration 
    : TOKEN_93 /* genvar */ list_of_genvar_identifiers TOKEN_0 /* ; */ 
    {
        struct ast_genvar_declaration *ret = new (struct ast_genvar_declaration);
        $$ = ret;
    }
    ;

net_declaration 
    : net_type OPT_53 OPT_54 data_type_or_implicit OPT_55 list_of_net_decl_assignments TOKEN_0 /* ; */ 
    {
        struct ast_net_declaration *ret = new (struct ast_net_declaration);
        $$ = ret;
    }
    | net_type_identifier OPT_56 list_of_net_decl_assignments TOKEN_0 /* ; */ 
    {
        struct ast_net_declaration *ret = new (struct ast_net_declaration);
        $$ = ret;
    }
    | TOKEN_96 /* interconnect */ implicit_data_type OPT_57 LIST_42 TOKEN_0 /* ; */ 
    {
        struct ast_net_declaration *ret = new (struct ast_net_declaration);
        $$ = ret;
    }
    ;

type_declaration 
    : TOKEN_97 /* typedef */ data_type type_identifier STAR_15 TOKEN_0 /* ; */ 
    {
        struct ast_type_declaration *ret = new (struct ast_type_declaration);
        $$ = ret;
    }
    | TOKEN_97 /* typedef */ interface_instance_identifier constant_bit_select TOKEN_31 /* . */ type_identifier type_identifier TOKEN_0 /* ; */ 
    {
        struct ast_type_declaration *ret = new (struct ast_type_declaration);
        $$ = ret;
    }
    | TOKEN_97 /* typedef */ OPT_58 type_identifier TOKEN_0 /* ; */ 
    {
        struct ast_type_declaration *ret = new (struct ast_type_declaration);
        $$ = ret;
    }
    ;

net_type_declaration 
    : TOKEN_101 /* nettype */ data_type net_type_identifier OPT_60 TOKEN_0 /* ; */ 
    {
        struct ast_net_type_declaration *ret = new (struct ast_net_type_declaration);
        $$ = ret;
    }
    | TOKEN_101 /* nettype */ OPT_59 net_type_identifier net_type_identifier TOKEN_0 /* ; */ 
    {
        struct ast_net_type_declaration *ret = new (struct ast_net_type_declaration);
        $$ = ret;
    }
    ;

lifetime 
    : TOKEN_65 /* static */ 
    {
        struct ast_lifetime *ret = new (struct ast_lifetime);
        $$ = ret;
    }
    | TOKEN_103 /* automatic */ 
    {
        struct ast_lifetime *ret = new (struct ast_lifetime);
        $$ = ret;
    }
    ;

casting_type 
    : simple_type 
    {
        struct ast_casting_type *ret = new (struct ast_casting_type);
        $$ = ret;
    }
    | constant_primary 
    {
        struct ast_casting_type *ret = new (struct ast_casting_type);
        $$ = ret;
    }
    | signing 
    {
        struct ast_casting_type *ret = new (struct ast_casting_type);
        $$ = ret;
    }
    | TOKEN_104 /* string */ 
    {
        struct ast_casting_type *ret = new (struct ast_casting_type);
        $$ = ret;
    }
    | TOKEN_61 /* const */ 
    {
        struct ast_casting_type *ret = new (struct ast_casting_type);
        $$ = ret;
    }
    ;

data_type 
    : integer_vector_type OPT_61 STAR_29 
    {
        struct ast_data_type *ret = new (struct ast_data_type);
        $$ = ret;
    }
    | integer_atom_type OPT_61 
    {
        struct ast_data_type *ret = new (struct ast_data_type);
        $$ = ret;
    }
    | non_integer_type 
    {
        struct ast_data_type *ret = new (struct ast_data_type);
        $$ = ret;
    }
    | struct_union OPT_62 TOKEN_32 /* { */ LIST_44 TOKEN_33 /* } */ STAR_29 
    {
        struct ast_data_type *ret = new (struct ast_data_type);
        $$ = ret;
    }
    | TOKEN_98 /* enum */ OPT_63 TOKEN_32 /* { */ LIST_45 TOKEN_33 /* } */ STAR_29 
    {
        struct ast_data_type *ret = new (struct ast_data_type);
        $$ = ret;
    }
    | TOKEN_104 /* string */ 
    {
        struct ast_data_type *ret = new (struct ast_data_type);
        $$ = ret;
    }
    | TOKEN_106 /* chandle */ 
    {
        struct ast_data_type *ret = new (struct ast_data_type);
        $$ = ret;
    }
    | TOKEN_19 /* virtual */ OPT_64 interface_identifier OPT_16 OPT_22 
    {
        struct ast_data_type *ret = new (struct ast_data_type);
        $$ = ret;
    }
    | OPT_65 type_identifier STAR_29 
    {
        struct ast_data_type *ret = new (struct ast_data_type);
        $$ = ret;
    }
    | class_type 
    {
        struct ast_data_type *ret = new (struct ast_data_type);
        $$ = ret;
    }
    | TOKEN_107 /* event */ 
    {
        struct ast_data_type *ret = new (struct ast_data_type);
        $$ = ret;
    }
    | ps_covergroup_identifier 
    {
        struct ast_data_type *ret = new (struct ast_data_type);
        $$ = ret;
    }
    | type_reference 
    {
        struct ast_data_type *ret = new (struct ast_data_type);
        $$ = ret;
    }
    ;

data_type_or_implicit 
    : data_type 
    {
        struct ast_data_type_or_implicit *ret = new (struct ast_data_type_or_implicit);
        $$ = ret;
    }
    | implicit_data_type 
    {
        struct ast_data_type_or_implicit *ret = new (struct ast_data_type_or_implicit);
        $$ = ret;
    }
    ;

implicit_data_type 
    : OPT_61 STAR_29 
    {
        struct ast_implicit_data_type *ret = new (struct ast_implicit_data_type);
        $$ = ret;
    }
    ;

enum_base_type 
    : integer_atom_type OPT_61 
    {
        struct ast_enum_base_type *ret = new (struct ast_enum_base_type);
        $$ = ret;
    }
    | integer_vector_type OPT_61 OPT_50 
    {
        struct ast_enum_base_type *ret = new (struct ast_enum_base_type);
        $$ = ret;
    }
    | type_identifier OPT_50 
    {
        struct ast_enum_base_type *ret = new (struct ast_enum_base_type);
        $$ = ret;
    }
    ;

enum_name_declaration 
    : enum_identifier OPT_67 OPT_24 
    {
        struct ast_enum_name_declaration *ret = new (struct ast_enum_name_declaration);
        $$ = ret;
    }
    ;

class_scope 
    : class_type TOKEN_89 /* :: */ 
    {
        struct ast_class_scope *ret = new (struct ast_class_scope);
        $$ = ret;
    }
    ;

class_type 
    : ps_class_identifier OPT_16 STAR_30 
    {
        struct ast_class_type *ret = new (struct ast_class_type);
        $$ = ret;
    }
    ;

integer_type 
    : integer_vector_type 
    {
        struct ast_integer_type *ret = new (struct ast_integer_type);
        $$ = ret;
    }
    | integer_atom_type 
    {
        struct ast_integer_type *ret = new (struct ast_integer_type);
        $$ = ret;
    }
    ;

integer_atom_type 
    : TOKEN_108 /* byte */ 
    {
        struct ast_integer_atom_type *ret = new (struct ast_integer_atom_type);
        $$ = ret;
    }
    | TOKEN_109 /* shortint */ 
    {
        struct ast_integer_atom_type *ret = new (struct ast_integer_atom_type);
        $$ = ret;
    }
    | TOKEN_110 /* int */ 
    {
        struct ast_integer_atom_type *ret = new (struct ast_integer_atom_type);
        $$ = ret;
    }
    | TOKEN_111 /* longint */ 
    {
        struct ast_integer_atom_type *ret = new (struct ast_integer_atom_type);
        $$ = ret;
    }
    | TOKEN_112 /* integer */ 
    {
        struct ast_integer_atom_type *ret = new (struct ast_integer_atom_type);
        $$ = ret;
    }
    | TOKEN_113 /* time */ 
    {
        struct ast_integer_atom_type *ret = new (struct ast_integer_atom_type);
        $$ = ret;
    }
    ;

integer_vector_type 
    : TOKEN_114 /* bit */ 
    {
        struct ast_integer_vector_type *ret = new (struct ast_integer_vector_type);
        $$ = ret;
    }
    | TOKEN_115 /* logic */ 
    {
        struct ast_integer_vector_type *ret = new (struct ast_integer_vector_type);
        $$ = ret;
    }
    | TOKEN_116 /* reg */ 
    {
        struct ast_integer_vector_type *ret = new (struct ast_integer_vector_type);
        $$ = ret;
    }
    ;

non_integer_type 
    : TOKEN_117 /* shortreal */ 
    {
        struct ast_non_integer_type *ret = new (struct ast_non_integer_type);
        $$ = ret;
    }
    | TOKEN_118 /* real */ 
    {
        struct ast_non_integer_type *ret = new (struct ast_non_integer_type);
        $$ = ret;
    }
    | TOKEN_119 /* realtime */ 
    {
        struct ast_non_integer_type *ret = new (struct ast_non_integer_type);
        $$ = ret;
    }
    ;

net_type 
    : TOKEN_120 /* supply0 */ 
    {
        struct ast_net_type *ret = new (struct ast_net_type);
        $$ = ret;
    }
    | TOKEN_121 /* supply1 */ 
    {
        struct ast_net_type *ret = new (struct ast_net_type);
        $$ = ret;
    }
    | TOKEN_122 /* tri */ 
    {
        struct ast_net_type *ret = new (struct ast_net_type);
        $$ = ret;
    }
    | TOKEN_123 /* triand */ 
    {
        struct ast_net_type *ret = new (struct ast_net_type);
        $$ = ret;
    }
    | TOKEN_124 /* trior */ 
    {
        struct ast_net_type *ret = new (struct ast_net_type);
        $$ = ret;
    }
    | TOKEN_125 /* trireg */ 
    {
        struct ast_net_type *ret = new (struct ast_net_type);
        $$ = ret;
    }
    | TOKEN_126 /* tri0 */ 
    {
        struct ast_net_type *ret = new (struct ast_net_type);
        $$ = ret;
    }
    | TOKEN_127 /* tri1 */ 
    {
        struct ast_net_type *ret = new (struct ast_net_type);
        $$ = ret;
    }
    | TOKEN_128 /* uwire */ 
    {
        struct ast_net_type *ret = new (struct ast_net_type);
        $$ = ret;
    }
    | TOKEN_129 /* wire */ 
    {
        struct ast_net_type *ret = new (struct ast_net_type);
        $$ = ret;
    }
    | TOKEN_130 /* wand */ 
    {
        struct ast_net_type *ret = new (struct ast_net_type);
        $$ = ret;
    }
    | TOKEN_131 /* wor */ 
    {
        struct ast_net_type *ret = new (struct ast_net_type);
        $$ = ret;
    }
    ;

net_port_type 
    : OPT_68 data_type_or_implicit 
    {
        struct ast_net_port_type *ret = new (struct ast_net_port_type);
        $$ = ret;
    }
    | net_type_identifier 
    {
        struct ast_net_port_type *ret = new (struct ast_net_port_type);
        $$ = ret;
    }
    | TOKEN_96 /* interconnect */ implicit_data_type 
    {
        struct ast_net_port_type *ret = new (struct ast_net_port_type);
        $$ = ret;
    }
    ;

variable_port_type 
    : var_data_type 
    {
        struct ast_variable_port_type *ret = new (struct ast_variable_port_type);
        $$ = ret;
    }
    ;

var_data_type 
    : data_type 
    {
        struct ast_var_data_type *ret = new (struct ast_var_data_type);
        $$ = ret;
    }
    | TOKEN_87 /* var */ data_type_or_implicit 
    {
        struct ast_var_data_type *ret = new (struct ast_var_data_type);
        $$ = ret;
    }
    ;

signing 
    : TOKEN_132 /* signed */ 
    {
        struct ast_signing *ret = new (struct ast_signing);
        $$ = ret;
    }
    | TOKEN_133 /* unsigned */ 
    {
        struct ast_signing *ret = new (struct ast_signing);
        $$ = ret;
    }
    ;

simple_type 
    : integer_type 
    {
        struct ast_simple_type *ret = new (struct ast_simple_type);
        $$ = ret;
    }
    | non_integer_type 
    {
        struct ast_simple_type *ret = new (struct ast_simple_type);
        $$ = ret;
    }
    | ps_type_identifier 
    {
        struct ast_simple_type *ret = new (struct ast_simple_type);
        $$ = ret;
    }
    | ps_parameter_identifier 
    {
        struct ast_simple_type *ret = new (struct ast_simple_type);
        $$ = ret;
    }
    ;

struct_union_member 
    : STAR_2 OPT_69 data_type_or_void list_of_variable_decl_assignments TOKEN_0 /* ; */ 
    {
        struct ast_struct_union_member *ret = new (struct ast_struct_union_member);
        $$ = ret;
    }
    ;

data_type_or_void 
    : data_type 
    {
        struct ast_data_type_or_void *ret = new (struct ast_data_type_or_void);
        $$ = ret;
    }
    | TOKEN_134 /* void */ 
    {
        struct ast_data_type_or_void *ret = new (struct ast_data_type_or_void);
        $$ = ret;
    }
    ;

struct_union 
    : TOKEN_99 /* struct */ 
    {
        struct ast_struct_union *ret = new (struct ast_struct_union);
        $$ = ret;
    }
    | TOKEN_100 /* union */ OPT_70 
    {
        struct ast_struct_union *ret = new (struct ast_struct_union);
        $$ = ret;
    }
    ;

type_reference 
    : TOKEN_30 /* type */ TOKEN_12 /* ( */ expression TOKEN_14 /* ) */ 
    {
        struct ast_type_reference *ret = new (struct ast_type_reference);
        $$ = ret;
    }
    | TOKEN_30 /* type */ TOKEN_12 /* ( */ data_type TOKEN_14 /* ) */ 
    {
        struct ast_type_reference *ret = new (struct ast_type_reference);
        $$ = ret;
    }
    ;

drive_strength 
    : TOKEN_12 /* ( */ strength0 TOKEN_2 /* , */ strength1 TOKEN_14 /* ) */ 
    {
        struct ast_drive_strength *ret = new (struct ast_drive_strength);
        $$ = ret;
    }
    | TOKEN_12 /* ( */ strength1 TOKEN_2 /* , */ strength0 TOKEN_14 /* ) */ 
    {
        struct ast_drive_strength *ret = new (struct ast_drive_strength);
        $$ = ret;
    }
    | TOKEN_12 /* ( */ strength0 TOKEN_2 /* , */ TOKEN_136 /* highz1 */ TOKEN_14 /* ) */ 
    {
        struct ast_drive_strength *ret = new (struct ast_drive_strength);
        $$ = ret;
    }
    | TOKEN_12 /* ( */ strength1 TOKEN_2 /* , */ TOKEN_137 /* highz0 */ TOKEN_14 /* ) */ 
    {
        struct ast_drive_strength *ret = new (struct ast_drive_strength);
        $$ = ret;
    }
    | TOKEN_12 /* ( */ TOKEN_137 /* highz0 */ TOKEN_2 /* , */ strength1 TOKEN_14 /* ) */ 
    {
        struct ast_drive_strength *ret = new (struct ast_drive_strength);
        $$ = ret;
    }
    | TOKEN_12 /* ( */ TOKEN_136 /* highz1 */ TOKEN_2 /* , */ strength0 TOKEN_14 /* ) */ 
    {
        struct ast_drive_strength *ret = new (struct ast_drive_strength);
        $$ = ret;
    }
    ;

strength0 
    : TOKEN_120 /* supply0 */ 
    {
        struct ast_strength0 *ret = new (struct ast_strength0);
        $$ = ret;
    }
    | TOKEN_138 /* strong0 */ 
    {
        struct ast_strength0 *ret = new (struct ast_strength0);
        $$ = ret;
    }
    | TOKEN_139 /* pull0 */ 
    {
        struct ast_strength0 *ret = new (struct ast_strength0);
        $$ = ret;
    }
    | TOKEN_140 /* weak0 */ 
    {
        struct ast_strength0 *ret = new (struct ast_strength0);
        $$ = ret;
    }
    ;

strength1 
    : TOKEN_121 /* supply1 */ 
    {
        struct ast_strength1 *ret = new (struct ast_strength1);
        $$ = ret;
    }
    | TOKEN_141 /* strong1 */ 
    {
        struct ast_strength1 *ret = new (struct ast_strength1);
        $$ = ret;
    }
    | TOKEN_142 /* pull1 */ 
    {
        struct ast_strength1 *ret = new (struct ast_strength1);
        $$ = ret;
    }
    | TOKEN_143 /* weak1 */ 
    {
        struct ast_strength1 *ret = new (struct ast_strength1);
        $$ = ret;
    }
    ;

charge_strength 
    : TOKEN_12 /* ( */ TOKEN_144 /* small */ TOKEN_14 /* ) */ 
    {
        struct ast_charge_strength *ret = new (struct ast_charge_strength);
        $$ = ret;
    }
    | TOKEN_12 /* ( */ TOKEN_145 /* medium */ TOKEN_14 /* ) */ 
    {
        struct ast_charge_strength *ret = new (struct ast_charge_strength);
        $$ = ret;
    }
    | TOKEN_12 /* ( */ TOKEN_146 /* large */ TOKEN_14 /* ) */ 
    {
        struct ast_charge_strength *ret = new (struct ast_charge_strength);
        $$ = ret;
    }
    ;

delay3 
    : TOKEN_29 /* # */ delay_value 
    {
        struct ast_delay3 *ret = new (struct ast_delay3);
        $$ = ret;
    }
    | TOKEN_29 /* # */ TOKEN_12 /* ( */ mintypmax_expression OPT_72 TOKEN_14 /* ) */ 
    {
        struct ast_delay3 *ret = new (struct ast_delay3);
        $$ = ret;
    }
    ;

delay2 
    : TOKEN_29 /* # */ delay_value 
    {
        struct ast_delay2 *ret = new (struct ast_delay2);
        $$ = ret;
    }
    | TOKEN_29 /* # */ TOKEN_12 /* ( */ mintypmax_expression OPT_71 TOKEN_14 /* ) */ 
    {
        struct ast_delay2 *ret = new (struct ast_delay2);
        $$ = ret;
    }
    ;

delay_value 
    : unsigned_number 
    {
        struct ast_delay_value *ret = new (struct ast_delay_value);
        $$ = ret;
    }
    | real_number 
    {
        struct ast_delay_value *ret = new (struct ast_delay_value);
        $$ = ret;
    }
    | ps_identifier 
    {
        struct ast_delay_value *ret = new (struct ast_delay_value);
        $$ = ret;
    }
    | time_literal 
    {
        struct ast_delay_value *ret = new (struct ast_delay_value);
        $$ = ret;
    }
    | TOKEN_147 /* 1step */ 
    {
        struct ast_delay_value *ret = new (struct ast_delay_value);
        $$ = ret;
    }
    ;

list_of_defparam_assignments 
    : LIST_47 
    {
        struct ast_list_of_defparam_assignments *ret = new (struct ast_list_of_defparam_assignments);
        $$ = ret;
    }
    ;

list_of_genvar_identifiers 
    : LIST_48 
    {
        struct ast_list_of_genvar_identifiers *ret = new (struct ast_list_of_genvar_identifiers);
        $$ = ret;
    }
    ;

list_of_interface_identifiers 
    : LIST_49 
    {
        struct ast_list_of_interface_identifiers *ret = new (struct ast_list_of_interface_identifiers);
        $$ = ret;
    }
    ;

list_of_net_decl_assignments 
    : LIST_50 
    {
        struct ast_list_of_net_decl_assignments *ret = new (struct ast_list_of_net_decl_assignments);
        $$ = ret;
    }
    ;

list_of_param_assignments 
    : LIST_51 
    {
        struct ast_list_of_param_assignments *ret = new (struct ast_list_of_param_assignments);
        $$ = ret;
    }
    ;

list_of_port_identifiers 
    : LIST_52 
    {
        struct ast_list_of_port_identifiers *ret = new (struct ast_list_of_port_identifiers);
        $$ = ret;
    }
    ;

list_of_udp_port_identifiers 
    : LIST_53 
    {
        struct ast_list_of_udp_port_identifiers *ret = new (struct ast_list_of_udp_port_identifiers);
        $$ = ret;
    }
    ;

list_of_specparam_assignments 
    : LIST_54 
    {
        struct ast_list_of_specparam_assignments *ret = new (struct ast_list_of_specparam_assignments);
        $$ = ret;
    }
    ;

list_of_tf_variable_identifiers 
    : LIST_55 
    {
        struct ast_list_of_tf_variable_identifiers *ret = new (struct ast_list_of_tf_variable_identifiers);
        $$ = ret;
    }
    ;

list_of_type_assignments 
    : LIST_56 
    {
        struct ast_list_of_type_assignments *ret = new (struct ast_list_of_type_assignments);
        $$ = ret;
    }
    ;

list_of_variable_decl_assignments 
    : LIST_57 
    {
        struct ast_list_of_variable_decl_assignments *ret = new (struct ast_list_of_variable_decl_assignments);
        $$ = ret;
    }
    ;

list_of_variable_identifiers 
    : LIST_58 
    {
        struct ast_list_of_variable_identifiers *ret = new (struct ast_list_of_variable_identifiers);
        $$ = ret;
    }
    ;

list_of_variable_port_identifiers 
    : LIST_59 
    {
        struct ast_list_of_variable_port_identifiers *ret = new (struct ast_list_of_variable_port_identifiers);
        $$ = ret;
    }
    ;

defparam_assignment 
    : hierarchical_parameter_identifier TOKEN_38 /* = */ constant_mintypmax_expression 
    {
        struct ast_defparam_assignment *ret = new (struct ast_defparam_assignment);
        $$ = ret;
    }
    ;

net_decl_assignment 
    : net_identifier STAR_14 OPT_73 
    {
        struct ast_net_decl_assignment *ret = new (struct ast_net_decl_assignment);
        $$ = ret;
    }
    ;

param_assignment 
    : parameter_identifier STAR_14 OPT_74 
    {
        struct ast_param_assignment *ret = new (struct ast_param_assignment);
        $$ = ret;
    }
    ;

specparam_assignment 
    : specparam_identifier TOKEN_38 /* = */ constant_mintypmax_expression 
    {
        struct ast_specparam_assignment *ret = new (struct ast_specparam_assignment);
        $$ = ret;
    }
    | pulse_control_specparam 
    {
        struct ast_specparam_assignment *ret = new (struct ast_specparam_assignment);
        $$ = ret;
    }
    ;

type_assignment 
    : type_identifier OPT_75 
    {
        struct ast_type_assignment *ret = new (struct ast_type_assignment);
        $$ = ret;
    }
    ;

pulse_control_specparam 
    : TOKEN_148 /* PATHPULSEdollarsign_ */ TOKEN_38 /* = */ TOKEN_12 /* ( */ reject_limit_value OPT_76 TOKEN_14 /* ) */ 
    {
        struct ast_pulse_control_specparam *ret = new (struct ast_pulse_control_specparam);
        $$ = ret;
    }
    | TOKEN_148 /* PATHPULSEdollarsign_ */ specify_input_terminal_descriptor TOKEN_149 /* dollarsign_ */ specify_output_terminal_descriptor TOKEN_38 /* = */ TOKEN_12 /* ( */ reject_limit_value OPT_76 TOKEN_14 /* ) */ 
    {
        struct ast_pulse_control_specparam *ret = new (struct ast_pulse_control_specparam);
        $$ = ret;
    }
    ;

error_limit_value 
    : limit_value 
    {
        struct ast_error_limit_value *ret = new (struct ast_error_limit_value);
        $$ = ret;
    }
    ;

reject_limit_value 
    : limit_value 
    {
        struct ast_reject_limit_value *ret = new (struct ast_reject_limit_value);
        $$ = ret;
    }
    ;

limit_value 
    : constant_mintypmax_expression 
    {
        struct ast_limit_value *ret = new (struct ast_limit_value);
        $$ = ret;
    }
    ;

variable_decl_assignment 
    : variable_identifier STAR_15 OPT_73 
    {
        struct ast_variable_decl_assignment *ret = new (struct ast_variable_decl_assignment);
        $$ = ret;
    }
    | dynamic_array_variable_identifier unsized_dimension STAR_15 OPT_77 
    {
        struct ast_variable_decl_assignment *ret = new (struct ast_variable_decl_assignment);
        $$ = ret;
    }
    | class_variable_identifier OPT_78 
    {
        struct ast_variable_decl_assignment *ret = new (struct ast_variable_decl_assignment);
        $$ = ret;
    }
    ;

class_new 
    : OPT_41 TOKEN_64 /* new */ OPT_12 
    {
        struct ast_class_new *ret = new (struct ast_class_new);
        $$ = ret;
    }
    | TOKEN_64 /* new */ expression 
    {
        struct ast_class_new *ret = new (struct ast_class_new);
        $$ = ret;
    }
    ;

dynamic_array_new 
    : TOKEN_64 /* new */ TOKEN_79 /* [ */ expression TOKEN_80 /* ] */ OPT_79 
    {
        struct ast_dynamic_array_new *ret = new (struct ast_dynamic_array_new);
        $$ = ret;
    }
    ;

unpacked_dimension 
    : TOKEN_79 /* [ */ constant_range TOKEN_80 /* ] */ 
    {
        struct ast_unpacked_dimension *ret = new (struct ast_unpacked_dimension);
        $$ = ret;
    }
    | TOKEN_79 /* [ */ constant_expression TOKEN_80 /* ] */ 
    {
        struct ast_unpacked_dimension *ret = new (struct ast_unpacked_dimension);
        $$ = ret;
    }
    ;

packed_dimension 
    : TOKEN_79 /* [ */ constant_range TOKEN_80 /* ] */ 
    {
        struct ast_packed_dimension *ret = new (struct ast_packed_dimension);
        $$ = ret;
    }
    | unsized_dimension 
    {
        struct ast_packed_dimension *ret = new (struct ast_packed_dimension);
        $$ = ret;
    }
    ;

associative_dimension 
    : TOKEN_79 /* [ */ data_type TOKEN_80 /* ] */ 
    {
        struct ast_associative_dimension *ret = new (struct ast_associative_dimension);
        $$ = ret;
    }
    | TOKEN_79 /* [ */ TOKEN_90 /* * */ TOKEN_80 /* ] */ 
    {
        struct ast_associative_dimension *ret = new (struct ast_associative_dimension);
        $$ = ret;
    }
    ;

variable_dimension 
    : unsized_dimension 
    {
        struct ast_variable_dimension *ret = new (struct ast_variable_dimension);
        $$ = ret;
    }
    | unpacked_dimension 
    {
        struct ast_variable_dimension *ret = new (struct ast_variable_dimension);
        $$ = ret;
    }
    | associative_dimension 
    {
        struct ast_variable_dimension *ret = new (struct ast_variable_dimension);
        $$ = ret;
    }
    | queue_dimension 
    {
        struct ast_variable_dimension *ret = new (struct ast_variable_dimension);
        $$ = ret;
    }
    ;

queue_dimension 
    : TOKEN_79 /* [ */ TOKEN_149 /* dollarsign_ */ OPT_80 TOKEN_80 /* ] */ 
    {
        struct ast_queue_dimension *ret = new (struct ast_queue_dimension);
        $$ = ret;
    }
    ;

unsized_dimension 
    : TOKEN_79 /* [ */ TOKEN_80 /* ] */ 
    {
        struct ast_unsized_dimension *ret = new (struct ast_unsized_dimension);
        $$ = ret;
    }
    ;

function_data_type_or_implicit 
    : data_type_or_void 
    {
        struct ast_function_data_type_or_implicit *ret = new (struct ast_function_data_type_or_implicit);
        $$ = ret;
    }
    | implicit_data_type 
    {
        struct ast_function_data_type_or_implicit *ret = new (struct ast_function_data_type_or_implicit);
        $$ = ret;
    }
    ;

function_declaration 
    : TOKEN_63 /* function */ OPT_2 function_body_declaration 
    {
        struct ast_function_declaration *ret = new (struct ast_function_declaration);
        $$ = ret;
    }
    ;

function_body_declaration 
    : function_data_type_or_implicit OPT_81 function_identifier TOKEN_0 /* ; */ STAR_31 STAR_25 TOKEN_70 /* endfunction */ OPT_82 
    {
        struct ast_function_body_declaration *ret = new (struct ast_function_body_declaration);
        $$ = ret;
    }
    | function_data_type_or_implicit OPT_81 function_identifier TOKEN_12 /* ( */ OPT_38 TOKEN_14 /* ) */ TOKEN_0 /* ; */ STAR_24 STAR_25 TOKEN_70 /* endfunction */ OPT_82 
    {
        struct ast_function_body_declaration *ret = new (struct ast_function_body_declaration);
        $$ = ret;
    }
    ;

function_prototype 
    : TOKEN_63 /* function */ data_type_or_void function_identifier OPT_39 
    {
        struct ast_function_prototype *ret = new (struct ast_function_prototype);
        $$ = ret;
    }
    ;

dpi_import_export 
    : TOKEN_88 /* import */ dpi_spec_string OPT_83 OPT_84 dpi_function_proto TOKEN_0 /* ; */ 
    {
        struct ast_dpi_import_export *ret = new (struct ast_dpi_import_export);
        $$ = ret;
    }
    | TOKEN_88 /* import */ dpi_spec_string OPT_85 OPT_84 dpi_task_proto TOKEN_0 /* ; */ 
    {
        struct ast_dpi_import_export *ret = new (struct ast_dpi_import_export);
        $$ = ret;
    }
    | TOKEN_91 /* export */ dpi_spec_string OPT_84 TOKEN_63 /* function */ function_identifier TOKEN_0 /* ; */ 
    {
        struct ast_dpi_import_export *ret = new (struct ast_dpi_import_export);
        $$ = ret;
    }
    | TOKEN_91 /* export */ dpi_spec_string OPT_84 TOKEN_150 /* task */ task_identifier TOKEN_0 /* ; */ 
    {
        struct ast_dpi_import_export *ret = new (struct ast_dpi_import_export);
        $$ = ret;
    }
    ;

dpi_spec_string 
    : TOKEN_151 /* DPI-C */ 
    {
        struct ast_dpi_spec_string *ret = new (struct ast_dpi_spec_string);
        $$ = ret;
    }
    | TOKEN_152 /* DPI */ 
    {
        struct ast_dpi_spec_string *ret = new (struct ast_dpi_spec_string);
        $$ = ret;
    }
    ;

dpi_function_import_property 
    : TOKEN_153 /* context */ 
    {
        struct ast_dpi_function_import_property *ret = new (struct ast_dpi_function_import_property);
        $$ = ret;
    }
    | TOKEN_62 /* pure */ 
    {
        struct ast_dpi_function_import_property *ret = new (struct ast_dpi_function_import_property);
        $$ = ret;
    }
    ;

dpi_task_import_property 
    : TOKEN_153 /* context */ 
    {
        struct ast_dpi_task_import_property *ret = new (struct ast_dpi_task_import_property);
        $$ = ret;
    }
    ;

dpi_function_proto 
    : function_prototype 
    {
        struct ast_dpi_function_proto *ret = new (struct ast_dpi_function_proto);
        $$ = ret;
    }
    ;

dpi_task_proto 
    : task_prototype 
    {
        struct ast_dpi_task_proto *ret = new (struct ast_dpi_task_proto);
        $$ = ret;
    }
    ;

task_declaration 
    : TOKEN_150 /* task */ OPT_2 task_body_declaration 
    {
        struct ast_task_declaration *ret = new (struct ast_task_declaration);
        $$ = ret;
    }
    ;

task_body_declaration 
    : OPT_81 task_identifier TOKEN_0 /* ; */ STAR_31 STAR_32 TOKEN_154 /* endtask */ OPT_86 
    {
        struct ast_task_body_declaration *ret = new (struct ast_task_body_declaration);
        $$ = ret;
    }
    | OPT_81 task_identifier TOKEN_12 /* ( */ OPT_38 TOKEN_14 /* ) */ TOKEN_0 /* ; */ STAR_24 STAR_32 TOKEN_154 /* endtask */ OPT_86 
    {
        struct ast_task_body_declaration *ret = new (struct ast_task_body_declaration);
        $$ = ret;
    }
    ;

tf_item_declaration 
    : block_item_declaration 
    {
        struct ast_tf_item_declaration *ret = new (struct ast_tf_item_declaration);
        $$ = ret;
    }
    | tf_port_declaration 
    {
        struct ast_tf_item_declaration *ret = new (struct ast_tf_item_declaration);
        $$ = ret;
    }
    ;

tf_port_list 
    : LIST_62 
    {
        struct ast_tf_port_list *ret = new (struct ast_tf_port_list);
        $$ = ret;
    }
    ;

tf_port_item 
    : STAR_2 OPT_87 OPT_52 data_type_or_implicit OPT_88 
    {
        struct ast_tf_port_item *ret = new (struct ast_tf_port_item);
        $$ = ret;
    }
    ;

tf_port_direction 
    : port_direction 
    {
        struct ast_tf_port_direction *ret = new (struct ast_tf_port_direction);
        $$ = ret;
    }
    | TOKEN_61 /* const */ TOKEN_37 /* ref */ 
    {
        struct ast_tf_port_direction *ret = new (struct ast_tf_port_direction);
        $$ = ret;
    }
    ;

tf_port_declaration 
    : STAR_2 tf_port_direction OPT_52 data_type_or_implicit list_of_tf_variable_identifiers TOKEN_0 /* ; */ 
    {
        struct ast_tf_port_declaration *ret = new (struct ast_tf_port_declaration);
        $$ = ret;
    }
    ;

task_prototype 
    : TOKEN_150 /* task */ task_identifier OPT_39 
    {
        struct ast_task_prototype *ret = new (struct ast_task_prototype);
        $$ = ret;
    }
    ;

block_item_declaration 
    : STAR_2 data_declaration 
    {
        struct ast_block_item_declaration *ret = new (struct ast_block_item_declaration);
        $$ = ret;
    }
    | STAR_2 local_parameter_declaration TOKEN_0 /* ; */ 
    {
        struct ast_block_item_declaration *ret = new (struct ast_block_item_declaration);
        $$ = ret;
    }
    | STAR_2 parameter_declaration TOKEN_0 /* ; */ 
    {
        struct ast_block_item_declaration *ret = new (struct ast_block_item_declaration);
        $$ = ret;
    }
    | STAR_2 overload_declaration 
    {
        struct ast_block_item_declaration *ret = new (struct ast_block_item_declaration);
        $$ = ret;
    }
    | STAR_2 let_declaration 
    {
        struct ast_block_item_declaration *ret = new (struct ast_block_item_declaration);
        $$ = ret;
    }
    ;

overload_declaration 
    : TOKEN_51 /* bind */ overload_operator TOKEN_63 /* function */ data_type function_identifier TOKEN_12 /* ( */ overload_proto_formals TOKEN_14 /* ) */ TOKEN_0 /* ; */ 
    {
        struct ast_overload_declaration *ret = new (struct ast_overload_declaration);
        $$ = ret;
    }
    ;

overload_operator 
    : TOKEN_155 /* + */ 
    {
        struct ast_overload_operator *ret = new (struct ast_overload_operator);
        $$ = ret;
    }
    | TOKEN_156 /* ++ */ 
    {
        struct ast_overload_operator *ret = new (struct ast_overload_operator);
        $$ = ret;
    }
    | TOKEN_157 /* - */ 
    {
        struct ast_overload_operator *ret = new (struct ast_overload_operator);
        $$ = ret;
    }
    | TOKEN_158 /* -- */ 
    {
        struct ast_overload_operator *ret = new (struct ast_overload_operator);
        $$ = ret;
    }
    | TOKEN_90 /* * */ 
    {
        struct ast_overload_operator *ret = new (struct ast_overload_operator);
        $$ = ret;
    }
    | TOKEN_159 /* ** */ 
    {
        struct ast_overload_operator *ret = new (struct ast_overload_operator);
        $$ = ret;
    }
    | TOKEN_27 /* / */ 
    {
        struct ast_overload_operator *ret = new (struct ast_overload_operator);
        $$ = ret;
    }
    | TOKEN_160 /* % */ 
    {
        struct ast_overload_operator *ret = new (struct ast_overload_operator);
        $$ = ret;
    }
    | TOKEN_161 /* == */ 
    {
        struct ast_overload_operator *ret = new (struct ast_overload_operator);
        $$ = ret;
    }
    | TOKEN_162 /* != */ 
    {
        struct ast_overload_operator *ret = new (struct ast_overload_operator);
        $$ = ret;
    }
    | TOKEN_163 /* < */ 
    {
        struct ast_overload_operator *ret = new (struct ast_overload_operator);
        $$ = ret;
    }
    | TOKEN_164 /* <= */ 
    {
        struct ast_overload_operator *ret = new (struct ast_overload_operator);
        $$ = ret;
    }
    | TOKEN_165 /* > */ 
    {
        struct ast_overload_operator *ret = new (struct ast_overload_operator);
        $$ = ret;
    }
    | TOKEN_166 /* >= */ 
    {
        struct ast_overload_operator *ret = new (struct ast_overload_operator);
        $$ = ret;
    }
    | TOKEN_38 /* = */ 
    {
        struct ast_overload_operator *ret = new (struct ast_overload_operator);
        $$ = ret;
    }
    ;

overload_proto_formals 
    : LIST_63 
    {
        struct ast_overload_proto_formals *ret = new (struct ast_overload_proto_formals);
        $$ = ret;
    }
    ;

modport_declaration 
    : TOKEN_167 /* modport */ LIST_64 TOKEN_0 /* ; */ 
    {
        struct ast_modport_declaration *ret = new (struct ast_modport_declaration);
        $$ = ret;
    }
    ;

modport_item 
    : modport_identifier TOKEN_12 /* ( */ LIST_65 TOKEN_14 /* ) */ 
    {
        struct ast_modport_item *ret = new (struct ast_modport_item);
        $$ = ret;
    }
    ;

modport_ports_declaration 
    : STAR_2 modport_simple_ports_declaration 
    {
        struct ast_modport_ports_declaration *ret = new (struct ast_modport_ports_declaration);
        $$ = ret;
    }
    | STAR_2 modport_tf_ports_declaration 
    {
        struct ast_modport_ports_declaration *ret = new (struct ast_modport_ports_declaration);
        $$ = ret;
    }
    | STAR_2 modport_clocking_declaration 
    {
        struct ast_modport_ports_declaration *ret = new (struct ast_modport_ports_declaration);
        $$ = ret;
    }
    ;

modport_clocking_declaration 
    : TOKEN_47 /* clocking */ clocking_identifier 
    {
        struct ast_modport_clocking_declaration *ret = new (struct ast_modport_clocking_declaration);
        $$ = ret;
    }
    ;

modport_simple_ports_declaration 
    : port_direction LIST_66 
    {
        struct ast_modport_simple_ports_declaration *ret = new (struct ast_modport_simple_ports_declaration);
        $$ = ret;
    }
    ;

modport_simple_port 
    : port_identifier 
    {
        struct ast_modport_simple_port *ret = new (struct ast_modport_simple_port);
        $$ = ret;
    }
    | TOKEN_31 /* . */ port_identifier TOKEN_12 /* ( */ OPT_26 TOKEN_14 /* ) */ 
    {
        struct ast_modport_simple_port *ret = new (struct ast_modport_simple_port);
        $$ = ret;
    }
    ;

modport_tf_ports_declaration 
    : import_export LIST_67 
    {
        struct ast_modport_tf_ports_declaration *ret = new (struct ast_modport_tf_ports_declaration);
        $$ = ret;
    }
    ;

modport_tf_port 
    : method_prototype 
    {
        struct ast_modport_tf_port *ret = new (struct ast_modport_tf_port);
        $$ = ret;
    }
    | tf_identifier 
    {
        struct ast_modport_tf_port *ret = new (struct ast_modport_tf_port);
        $$ = ret;
    }
    ;

import_export 
    : TOKEN_88 /* import */ 
    {
        struct ast_import_export *ret = new (struct ast_import_export);
        $$ = ret;
    }
    | TOKEN_91 /* export */ 
    {
        struct ast_import_export *ret = new (struct ast_import_export);
        $$ = ret;
    }
    ;

concurrent_assertion_item 
    : OPT_89 concurrent_assertion_statement 
    {
        struct ast_concurrent_assertion_item *ret = new (struct ast_concurrent_assertion_item);
        $$ = ret;
    }
    | checker_instantiation 
    {
        struct ast_concurrent_assertion_item *ret = new (struct ast_concurrent_assertion_item);
        $$ = ret;
    }
    ;

concurrent_assertion_statement 
    : assert_property_statement 
    {
        struct ast_concurrent_assertion_statement *ret = new (struct ast_concurrent_assertion_statement);
        $$ = ret;
    }
    | assume_property_statement 
    {
        struct ast_concurrent_assertion_statement *ret = new (struct ast_concurrent_assertion_statement);
        $$ = ret;
    }
    | cover_property_statement 
    {
        struct ast_concurrent_assertion_statement *ret = new (struct ast_concurrent_assertion_statement);
        $$ = ret;
    }
    | cover_sequence_statement 
    {
        struct ast_concurrent_assertion_statement *ret = new (struct ast_concurrent_assertion_statement);
        $$ = ret;
    }
    | restrict_property_statement 
    {
        struct ast_concurrent_assertion_statement *ret = new (struct ast_concurrent_assertion_statement);
        $$ = ret;
    }
    ;

assert_property_statement 
    : TOKEN_168 /* assert */ TOKEN_169 /* property */ TOKEN_12 /* ( */ property_spec TOKEN_14 /* ) */ action_block 
    {
        struct ast_assert_property_statement *ret = new (struct ast_assert_property_statement);
        $$ = ret;
    }
    ;

assume_property_statement 
    : TOKEN_170 /* assume */ TOKEN_169 /* property */ TOKEN_12 /* ( */ property_spec TOKEN_14 /* ) */ action_block 
    {
        struct ast_assume_property_statement *ret = new (struct ast_assume_property_statement);
        $$ = ret;
    }
    ;

cover_property_statement 
    : TOKEN_171 /* cover */ TOKEN_169 /* property */ TOKEN_12 /* ( */ property_spec TOKEN_14 /* ) */ statement_or_null 
    {
        struct ast_cover_property_statement *ret = new (struct ast_cover_property_statement);
        $$ = ret;
    }
    ;

expect_property_statement 
    : TOKEN_172 /* expect */ TOKEN_12 /* ( */ property_spec TOKEN_14 /* ) */ action_block 
    {
        struct ast_expect_property_statement *ret = new (struct ast_expect_property_statement);
        $$ = ret;
    }
    ;

cover_sequence_statement 
    : TOKEN_171 /* cover */ TOKEN_173 /* sequence */ TOKEN_12 /* ( */ OPT_90 OPT_91 TOKEN_14 /* ) */ statement_or_null 
    {
        struct ast_cover_sequence_statement *ret = new (struct ast_cover_sequence_statement);
        $$ = ret;
    }
    ;

restrict_property_statement 
    : TOKEN_174 /* restrict */ TOKEN_169 /* property */ TOKEN_12 /* ( */ property_spec TOKEN_14 /* ) */ TOKEN_0 /* ; */ 
    {
        struct ast_restrict_property_statement *ret = new (struct ast_restrict_property_statement);
        $$ = ret;
    }
    ;

property_instance 
    : ps_or_hierarchical_property_identifier OPT_93 
    {
        struct ast_property_instance *ret = new (struct ast_property_instance);
        $$ = ret;
    }
    ;

property_list_of_arguments 
    : LIST_68 STAR_33 
    {
        struct ast_property_list_of_arguments *ret = new (struct ast_property_list_of_arguments);
        $$ = ret;
    }
    | LIST_70 
    {
        struct ast_property_list_of_arguments *ret = new (struct ast_property_list_of_arguments);
        $$ = ret;
    }
    ;

property_actual_arg 
    : property_expr 
    {
        struct ast_property_actual_arg *ret = new (struct ast_property_actual_arg);
        $$ = ret;
    }
    | sequence_actual_arg 
    {
        struct ast_property_actual_arg *ret = new (struct ast_property_actual_arg);
        $$ = ret;
    }
    ;

assertion_item_declaration 
    : property_declaration 
    {
        struct ast_assertion_item_declaration *ret = new (struct ast_assertion_item_declaration);
        $$ = ret;
    }
    | sequence_declaration 
    {
        struct ast_assertion_item_declaration *ret = new (struct ast_assertion_item_declaration);
        $$ = ret;
    }
    | let_declaration 
    {
        struct ast_assertion_item_declaration *ret = new (struct ast_assertion_item_declaration);
        $$ = ret;
    }
    ;

property_declaration 
    : TOKEN_169 /* property */ property_identifier OPT_96 TOKEN_0 /* ; */ STAR_34 property_spec OPT_97 TOKEN_175 /* endproperty */ OPT_98 
    {
        struct ast_property_declaration *ret = new (struct ast_property_declaration);
        $$ = ret;
    }
    ;

property_port_list 
    : LIST_72 
    {
        struct ast_property_port_list *ret = new (struct ast_property_port_list);
        $$ = ret;
    }
    ;

property_port_item 
    : STAR_2 OPT_100 property_formal_type formal_port_identifier STAR_15 OPT_36 
    {
        struct ast_property_port_item *ret = new (struct ast_property_port_item);
        $$ = ret;
    }
    ;

property_lvar_port_direction 
    : TOKEN_34 /* input */ 
    {
        struct ast_property_lvar_port_direction *ret = new (struct ast_property_lvar_port_direction);
        $$ = ret;
    }
    ;

property_formal_type 
    : sequence_formal_type 
    {
        struct ast_property_formal_type *ret = new (struct ast_property_formal_type);
        $$ = ret;
    }
    | TOKEN_169 /* property */ 
    {
        struct ast_property_formal_type *ret = new (struct ast_property_formal_type);
        $$ = ret;
    }
    ;

property_spec 
    : OPT_90 OPT_91 property_expr 
    {
        struct ast_property_spec *ret = new (struct ast_property_spec);
        $$ = ret;
    }
    ;

property_expr 
    : sequence_expr 
    {
        struct ast_property_expr *ret = new (struct ast_property_expr);
        $$ = ret;
    }
    | TOKEN_176 /* strong */ TOKEN_12 /* ( */ sequence_expr TOKEN_14 /* ) */ 
    {
        struct ast_property_expr *ret = new (struct ast_property_expr);
        $$ = ret;
    }
    | TOKEN_177 /* weak */ TOKEN_12 /* ( */ sequence_expr TOKEN_14 /* ) */ 
    {
        struct ast_property_expr *ret = new (struct ast_property_expr);
        $$ = ret;
    }
    | TOKEN_12 /* ( */ property_expr TOKEN_14 /* ) */ 
    {
        struct ast_property_expr *ret = new (struct ast_property_expr);
        $$ = ret;
    }
    | TOKEN_178 /* not */ property_expr 
    {
        struct ast_property_expr *ret = new (struct ast_property_expr);
        $$ = ret;
    }
    | property_expr TOKEN_179 /* or */ property_expr 
    {
        struct ast_property_expr *ret = new (struct ast_property_expr);
        $$ = ret;
    }
    | property_expr TOKEN_180 /* and */ property_expr 
    {
        struct ast_property_expr *ret = new (struct ast_property_expr);
        $$ = ret;
    }
    | sequence_expr TOKEN_181 /* |-> */ property_expr 
    {
        struct ast_property_expr *ret = new (struct ast_property_expr);
        $$ = ret;
    }
    | sequence_expr TOKEN_182 /* |=> */ property_expr 
    {
        struct ast_property_expr *ret = new (struct ast_property_expr);
        $$ = ret;
    }
    | TOKEN_76 /* if */ TOKEN_12 /* ( */ expression_or_dist TOKEN_14 /* ) */ property_expr OPT_101 
    {
        struct ast_property_expr *ret = new (struct ast_property_expr);
        $$ = ret;
    }
    | TOKEN_183 /* case */ TOKEN_12 /* ( */ expression_or_dist TOKEN_14 /* ) */ LIST_73 TOKEN_184 /* endcase */ 
    {
        struct ast_property_expr *ret = new (struct ast_property_expr);
        $$ = ret;
    }
    | sequence_expr TOKEN_185 /* #-# */ property_expr 
    {
        struct ast_property_expr *ret = new (struct ast_property_expr);
        $$ = ret;
    }
    | sequence_expr TOKEN_186 /* #=# */ property_expr 
    {
        struct ast_property_expr *ret = new (struct ast_property_expr);
        $$ = ret;
    }
    | TOKEN_187 /* nexttime */ property_expr 
    {
        struct ast_property_expr *ret = new (struct ast_property_expr);
        $$ = ret;
    }
    | TOKEN_187 /* nexttime */ TOKEN_79 /* [ */ constant_expression TOKEN_80 /* ] */ property_expr 
    {
        struct ast_property_expr *ret = new (struct ast_property_expr);
        $$ = ret;
    }
    | TOKEN_188 /* s_nexttime */ property_expr 
    {
        struct ast_property_expr *ret = new (struct ast_property_expr);
        $$ = ret;
    }
    | TOKEN_188 /* s_nexttime */ TOKEN_79 /* [ */ constant_expression TOKEN_80 /* ] */ property_expr 
    {
        struct ast_property_expr *ret = new (struct ast_property_expr);
        $$ = ret;
    }
    | TOKEN_189 /* always */ property_expr 
    {
        struct ast_property_expr *ret = new (struct ast_property_expr);
        $$ = ret;
    }
    | TOKEN_189 /* always */ TOKEN_79 /* [ */ cycle_delay_const_range_expression TOKEN_80 /* ] */ property_expr 
    {
        struct ast_property_expr *ret = new (struct ast_property_expr);
        $$ = ret;
    }
    | TOKEN_190 /* s_always */ TOKEN_79 /* [ */ constant_range TOKEN_80 /* ] */ property_expr 
    {
        struct ast_property_expr *ret = new (struct ast_property_expr);
        $$ = ret;
    }
    | TOKEN_191 /* s_eventually */ TOKEN_79 /* [ */ cycle_delay_const_range_expression TOKEN_80 /* ] */ property_expr 
    {
        struct ast_property_expr *ret = new (struct ast_property_expr);
        $$ = ret;
    }
    | property_expr TOKEN_192 /* until */ property_expr 
    {
        struct ast_property_expr *ret = new (struct ast_property_expr);
        $$ = ret;
    }
    | property_expr TOKEN_193 /* s_until */ property_expr 
    {
        struct ast_property_expr *ret = new (struct ast_property_expr);
        $$ = ret;
    }
    | property_expr TOKEN_194 /* until_with */ property_expr 
    {
        struct ast_property_expr *ret = new (struct ast_property_expr);
        $$ = ret;
    }
    | property_expr TOKEN_195 /* s_until_with */ property_expr 
    {
        struct ast_property_expr *ret = new (struct ast_property_expr);
        $$ = ret;
    }
    | property_expr TOKEN_196 /* implies */ property_expr 
    {
        struct ast_property_expr *ret = new (struct ast_property_expr);
        $$ = ret;
    }
    | property_expr TOKEN_49 /* iff */ property_expr 
    {
        struct ast_property_expr *ret = new (struct ast_property_expr);
        $$ = ret;
    }
    | TOKEN_197 /* accept_on */ TOKEN_12 /* ( */ expression_or_dist TOKEN_14 /* ) */ property_expr 
    {
        struct ast_property_expr *ret = new (struct ast_property_expr);
        $$ = ret;
    }
    | TOKEN_198 /* reject_on */ TOKEN_12 /* ( */ expression_or_dist TOKEN_14 /* ) */ property_expr 
    {
        struct ast_property_expr *ret = new (struct ast_property_expr);
        $$ = ret;
    }
    | TOKEN_199 /* sync_accept_on */ TOKEN_12 /* ( */ expression_or_dist TOKEN_14 /* ) */ property_expr 
    {
        struct ast_property_expr *ret = new (struct ast_property_expr);
        $$ = ret;
    }
    | TOKEN_200 /* sync_reject_on */ TOKEN_12 /* ( */ expression_or_dist TOKEN_14 /* ) */ property_expr 
    {
        struct ast_property_expr *ret = new (struct ast_property_expr);
        $$ = ret;
    }
    | property_instance 
    {
        struct ast_property_expr *ret = new (struct ast_property_expr);
        $$ = ret;
    }
    | clocking_event property_expr 
    {
        struct ast_property_expr *ret = new (struct ast_property_expr);
        $$ = ret;
    }
    ;

property_case_item 
    : LIST_74 TOKEN_6 /* : */ property_expr OPT_97 
    {
        struct ast_property_case_item *ret = new (struct ast_property_case_item);
        $$ = ret;
    }
    | TOKEN_46 /* default */ OPT_102 property_expr OPT_97 
    {
        struct ast_property_case_item *ret = new (struct ast_property_case_item);
        $$ = ret;
    }
    ;

sequence_declaration 
    : TOKEN_173 /* sequence */ sequence_identifier OPT_104 TOKEN_0 /* ; */ STAR_34 sequence_expr OPT_97 TOKEN_201 /* endsequence */ OPT_105 
    {
        struct ast_sequence_declaration *ret = new (struct ast_sequence_declaration);
        $$ = ret;
    }
    ;

sequence_port_list 
    : LIST_75 
    {
        struct ast_sequence_port_list *ret = new (struct ast_sequence_port_list);
        $$ = ret;
    }
    ;

sequence_port_item 
    : STAR_2 OPT_107 sequence_formal_type formal_port_identifier STAR_15 OPT_108 
    {
        struct ast_sequence_port_item *ret = new (struct ast_sequence_port_item);
        $$ = ret;
    }
    ;

sequence_lvar_port_direction 
    : TOKEN_34 /* input */ 
    {
        struct ast_sequence_lvar_port_direction *ret = new (struct ast_sequence_lvar_port_direction);
        $$ = ret;
    }
    | TOKEN_36 /* inout */ 
    {
        struct ast_sequence_lvar_port_direction *ret = new (struct ast_sequence_lvar_port_direction);
        $$ = ret;
    }
    | TOKEN_35 /* output */ 
    {
        struct ast_sequence_lvar_port_direction *ret = new (struct ast_sequence_lvar_port_direction);
        $$ = ret;
    }
    ;

sequence_formal_type 
    : data_type_or_implicit 
    {
        struct ast_sequence_formal_type *ret = new (struct ast_sequence_formal_type);
        $$ = ret;
    }
    | TOKEN_173 /* sequence */ 
    {
        struct ast_sequence_formal_type *ret = new (struct ast_sequence_formal_type);
        $$ = ret;
    }
    | TOKEN_202 /* untyped */ 
    {
        struct ast_sequence_formal_type *ret = new (struct ast_sequence_formal_type);
        $$ = ret;
    }
    ;

sequence_expr 
    : LIST_76 
    {
        struct ast_sequence_expr *ret = new (struct ast_sequence_expr);
        $$ = ret;
    }
    | sequence_expr LIST_76 
    {
        struct ast_sequence_expr *ret = new (struct ast_sequence_expr);
        $$ = ret;
    }
    | expression_or_dist OPT_109 
    {
        struct ast_sequence_expr *ret = new (struct ast_sequence_expr);
        $$ = ret;
    }
    | sequence_instance 
    {
        struct ast_sequence_expr *ret = new (struct ast_sequence_expr);
        $$ = ret;
    }
    | TOKEN_12 /* ( */ sequence_expr STAR_35 TOKEN_14 /* ) */ OPT_110 
    {
        struct ast_sequence_expr *ret = new (struct ast_sequence_expr);
        $$ = ret;
    }
    | sequence_expr TOKEN_180 /* and */ sequence_expr 
    {
        struct ast_sequence_expr *ret = new (struct ast_sequence_expr);
        $$ = ret;
    }
    | sequence_expr TOKEN_203 /* intersect */ sequence_expr 
    {
        struct ast_sequence_expr *ret = new (struct ast_sequence_expr);
        $$ = ret;
    }
    | sequence_expr TOKEN_179 /* or */ sequence_expr 
    {
        struct ast_sequence_expr *ret = new (struct ast_sequence_expr);
        $$ = ret;
    }
    | TOKEN_204 /* first_match */ TOKEN_12 /* ( */ sequence_expr STAR_35 TOKEN_14 /* ) */ 
    {
        struct ast_sequence_expr *ret = new (struct ast_sequence_expr);
        $$ = ret;
    }
    | expression_or_dist TOKEN_205 /* throughout */ sequence_expr 
    {
        struct ast_sequence_expr *ret = new (struct ast_sequence_expr);
        $$ = ret;
    }
    | sequence_expr TOKEN_206 /* within */ sequence_expr 
    {
        struct ast_sequence_expr *ret = new (struct ast_sequence_expr);
        $$ = ret;
    }
    | clocking_event sequence_expr 
    {
        struct ast_sequence_expr *ret = new (struct ast_sequence_expr);
        $$ = ret;
    }
    ;

cycle_delay_range 
    : TOKEN_207 /* ## */ constant_primary 
    {
        struct ast_cycle_delay_range *ret = new (struct ast_cycle_delay_range);
        $$ = ret;
    }
    | TOKEN_207 /* ## */ TOKEN_79 /* [ */ cycle_delay_const_range_expression TOKEN_80 /* ] */ 
    {
        struct ast_cycle_delay_range *ret = new (struct ast_cycle_delay_range);
        $$ = ret;
    }
    | TOKEN_207 /* ## */ TOKEN_208 /* [*] */ 
    {
        struct ast_cycle_delay_range *ret = new (struct ast_cycle_delay_range);
        $$ = ret;
    }
    | TOKEN_207 /* ## */ TOKEN_209 /* [+] */ 
    {
        struct ast_cycle_delay_range *ret = new (struct ast_cycle_delay_range);
        $$ = ret;
    }
    ;

sequence_method_call 
    : sequence_instance TOKEN_31 /* . */ method_identifier 
    {
        struct ast_sequence_method_call *ret = new (struct ast_sequence_method_call);
        $$ = ret;
    }
    ;

sequence_match_item 
    : operator_assignment 
    {
        struct ast_sequence_match_item *ret = new (struct ast_sequence_match_item);
        $$ = ret;
    }
    | inc_or_dec_expression 
    {
        struct ast_sequence_match_item *ret = new (struct ast_sequence_match_item);
        $$ = ret;
    }
    | subroutine_call 
    {
        struct ast_sequence_match_item *ret = new (struct ast_sequence_match_item);
        $$ = ret;
    }
    ;

sequence_instance 
    : ps_or_hierarchical_sequence_identifier OPT_111 
    {
        struct ast_sequence_instance *ret = new (struct ast_sequence_instance);
        $$ = ret;
    }
    ;

sequence_list_of_arguments 
    : LIST_78 STAR_36 
    {
        struct ast_sequence_list_of_arguments *ret = new (struct ast_sequence_list_of_arguments);
        $$ = ret;
    }
    | LIST_80 
    {
        struct ast_sequence_list_of_arguments *ret = new (struct ast_sequence_list_of_arguments);
        $$ = ret;
    }
    ;

sequence_actual_arg 
    : event_expression 
    {
        struct ast_sequence_actual_arg *ret = new (struct ast_sequence_actual_arg);
        $$ = ret;
    }
    | sequence_expr 
    {
        struct ast_sequence_actual_arg *ret = new (struct ast_sequence_actual_arg);
        $$ = ret;
    }
    ;

boolean_abbrev 
    : consecutive_repetition 
    {
        struct ast_boolean_abbrev *ret = new (struct ast_boolean_abbrev);
        $$ = ret;
    }
    | non_consecutive_repetition 
    {
        struct ast_boolean_abbrev *ret = new (struct ast_boolean_abbrev);
        $$ = ret;
    }
    | goto_repetition 
    {
        struct ast_boolean_abbrev *ret = new (struct ast_boolean_abbrev);
        $$ = ret;
    }
    ;

sequence_abbrev 
    : consecutive_repetition 
    {
        struct ast_sequence_abbrev *ret = new (struct ast_sequence_abbrev);
        $$ = ret;
    }
    ;

consecutive_repetition 
    : TOKEN_210 /* [* */ const_or_range_expression TOKEN_80 /* ] */ 
    {
        struct ast_consecutive_repetition *ret = new (struct ast_consecutive_repetition);
        $$ = ret;
    }
    | TOKEN_208 /* [*] */ 
    {
        struct ast_consecutive_repetition *ret = new (struct ast_consecutive_repetition);
        $$ = ret;
    }
    | TOKEN_209 /* [+] */ 
    {
        struct ast_consecutive_repetition *ret = new (struct ast_consecutive_repetition);
        $$ = ret;
    }
    ;

non_consecutive_repetition 
    : TOKEN_211 /* [= */ const_or_range_expression TOKEN_80 /* ] */ 
    {
        struct ast_non_consecutive_repetition *ret = new (struct ast_non_consecutive_repetition);
        $$ = ret;
    }
    ;

goto_repetition 
    : TOKEN_212 /* [-> */ const_or_range_expression TOKEN_80 /* ] */ 
    {
        struct ast_goto_repetition *ret = new (struct ast_goto_repetition);
        $$ = ret;
    }
    ;

const_or_range_expression 
    : constant_expression 
    {
        struct ast_const_or_range_expression *ret = new (struct ast_const_or_range_expression);
        $$ = ret;
    }
    | cycle_delay_const_range_expression 
    {
        struct ast_const_or_range_expression *ret = new (struct ast_const_or_range_expression);
        $$ = ret;
    }
    ;

cycle_delay_const_range_expression 
    : constant_expression TOKEN_6 /* : */ constant_expression 
    {
        struct ast_cycle_delay_const_range_expression *ret = new (struct ast_cycle_delay_const_range_expression);
        $$ = ret;
    }
    | constant_expression TOKEN_6 /* : */ TOKEN_149 /* dollarsign_ */ 
    {
        struct ast_cycle_delay_const_range_expression *ret = new (struct ast_cycle_delay_const_range_expression);
        $$ = ret;
    }
    ;

expression_or_dist 
    : expression OPT_113 
    {
        struct ast_expression_or_dist *ret = new (struct ast_expression_or_dist);
        $$ = ret;
    }
    ;

assertion_variable_declaration 
    : var_data_type list_of_variable_decl_assignments TOKEN_0 /* ; */ 
    {
        struct ast_assertion_variable_declaration *ret = new (struct ast_assertion_variable_declaration);
        $$ = ret;
    }
    ;

let_declaration 
    : TOKEN_214 /* let */ let_identifier OPT_115 TOKEN_38 /* = */ expression TOKEN_0 /* ; */ 
    {
        struct ast_let_declaration *ret = new (struct ast_let_declaration);
        $$ = ret;
    }
    ;

let_identifier 
    : identifier 
    {
        struct ast_let_identifier *ret = new (struct ast_let_identifier);
        $$ = ret;
    }
    ;

let_port_list 
    : LIST_81 
    {
        struct ast_let_port_list *ret = new (struct ast_let_port_list);
        $$ = ret;
    }
    ;

let_port_item 
    : STAR_2 let_formal_type formal_port_identifier STAR_15 OPT_73 
    {
        struct ast_let_port_item *ret = new (struct ast_let_port_item);
        $$ = ret;
    }
    ;

let_formal_type 
    : data_type_or_implicit 
    {
        struct ast_let_formal_type *ret = new (struct ast_let_formal_type);
        $$ = ret;
    }
    | TOKEN_202 /* untyped */ 
    {
        struct ast_let_formal_type *ret = new (struct ast_let_formal_type);
        $$ = ret;
    }
    ;

let_expression 
    : OPT_116 let_identifier OPT_118 
    {
        struct ast_let_expression *ret = new (struct ast_let_expression);
        $$ = ret;
    }
    ;

let_list_of_arguments 
    : LIST_82 STAR_37 
    {
        struct ast_let_list_of_arguments *ret = new (struct ast_let_list_of_arguments);
        $$ = ret;
    }
    | LIST_84 
    {
        struct ast_let_list_of_arguments *ret = new (struct ast_let_list_of_arguments);
        $$ = ret;
    }
    ;

let_actual_arg 
    : expression 
    {
        struct ast_let_actual_arg *ret = new (struct ast_let_actual_arg);
        $$ = ret;
    }
    ;

covergroup_declaration 
    : TOKEN_215 /* covergroup */ covergroup_identifier OPT_39 OPT_120 TOKEN_0 /* ; */ STAR_38 TOKEN_216 /* endgroup */ OPT_121 
    {
        struct ast_covergroup_declaration *ret = new (struct ast_covergroup_declaration);
        $$ = ret;
    }
    ;

coverage_spec_or_option 
    : STAR_2 coverage_spec 
    {
        struct ast_coverage_spec_or_option *ret = new (struct ast_coverage_spec_or_option);
        $$ = ret;
    }
    | STAR_2 coverage_option TOKEN_0 /* ; */ 
    {
        struct ast_coverage_spec_or_option *ret = new (struct ast_coverage_spec_or_option);
        $$ = ret;
    }
    ;

coverage_option 
    : TOKEN_217 /* option */ TOKEN_31 /* . */ member_identifier TOKEN_38 /* = */ expression 
    {
        struct ast_coverage_option *ret = new (struct ast_coverage_option);
        $$ = ret;
    }
    | TOKEN_218 /* type_option */ TOKEN_31 /* . */ member_identifier TOKEN_38 /* = */ constant_expression 
    {
        struct ast_coverage_option *ret = new (struct ast_coverage_option);
        $$ = ret;
    }
    ;

coverage_spec 
    : cover_point 
    {
        struct ast_coverage_spec *ret = new (struct ast_coverage_spec);
        $$ = ret;
    }
    | cover_cross 
    {
        struct ast_coverage_spec *ret = new (struct ast_coverage_spec);
        $$ = ret;
    }
    ;

coverage_event 
    : clocking_event 
    {
        struct ast_coverage_event *ret = new (struct ast_coverage_event);
        $$ = ret;
    }
    | TOKEN_102 /* with */ TOKEN_63 /* function */ TOKEN_219 /* sample */ TOKEN_12 /* ( */ OPT_38 TOKEN_14 /* ) */ 
    {
        struct ast_coverage_event *ret = new (struct ast_coverage_event);
        $$ = ret;
    }
    | TOKEN_220 /* @@ */ TOKEN_12 /* ( */ block_event_expression TOKEN_14 /* ) */ 
    {
        struct ast_coverage_event *ret = new (struct ast_coverage_event);
        $$ = ret;
    }
    ;

block_event_expression 
    : LIST_86 
    {
        struct ast_block_event_expression *ret = new (struct ast_block_event_expression);
        $$ = ret;
    }
    | TOKEN_221 /* begin */ hierarchical_btf_identifier 
    {
        struct ast_block_event_expression *ret = new (struct ast_block_event_expression);
        $$ = ret;
    }
    | TOKEN_222 /* end */ hierarchical_btf_identifier 
    {
        struct ast_block_event_expression *ret = new (struct ast_block_event_expression);
        $$ = ret;
    }
    ;

hierarchical_btf_identifier 
    : hierarchical_tf_identifier 
    {
        struct ast_hierarchical_btf_identifier *ret = new (struct ast_hierarchical_btf_identifier);
        $$ = ret;
    }
    | hierarchical_block_identifier 
    {
        struct ast_hierarchical_btf_identifier *ret = new (struct ast_hierarchical_btf_identifier);
        $$ = ret;
    }
    | OPT_122 method_identifier 
    {
        struct ast_hierarchical_btf_identifier *ret = new (struct ast_hierarchical_btf_identifier);
        $$ = ret;
    }
    ;

cover_point 
    : OPT_124 TOKEN_223 /* coverpoint */ expression OPT_125 bins_or_empty 
    {
        struct ast_cover_point *ret = new (struct ast_cover_point);
        $$ = ret;
    }
    ;

bins_or_empty 
    : TOKEN_32 /* { */ STAR_2 STAR_39 TOKEN_33 /* } */ 
    {
        struct ast_bins_or_empty *ret = new (struct ast_bins_or_empty);
        $$ = ret;
    }
    | TOKEN_0 /* ; */ 
    {
        struct ast_bins_or_empty *ret = new (struct ast_bins_or_empty);
        $$ = ret;
    }
    ;

bins_or_options 
    : coverage_option 
    {
        struct ast_bins_or_options *ret = new (struct ast_bins_or_options);
        $$ = ret;
    }
    | OPT_126 bins_keyword bin_identifier OPT_128 TOKEN_38 /* = */ TOKEN_32 /* { */ covergroup_range_list TOKEN_33 /* } */ OPT_129 OPT_125 
    {
        struct ast_bins_or_options *ret = new (struct ast_bins_or_options);
        $$ = ret;
    }
    | OPT_126 bins_keyword bin_identifier OPT_128 TOKEN_38 /* = */ cover_point_identifier OPT_129 OPT_125 
    {
        struct ast_bins_or_options *ret = new (struct ast_bins_or_options);
        $$ = ret;
    }
    | OPT_126 bins_keyword bin_identifier OPT_128 TOKEN_38 /* = */ set_covergroup_expression OPT_125 
    {
        struct ast_bins_or_options *ret = new (struct ast_bins_or_options);
        $$ = ret;
    }
    | OPT_126 bins_keyword bin_identifier OPT_130 TOKEN_38 /* = */ trans_list OPT_125 
    {
        struct ast_bins_or_options *ret = new (struct ast_bins_or_options);
        $$ = ret;
    }
    | bins_keyword bin_identifier OPT_128 TOKEN_38 /* = */ TOKEN_46 /* default */ OPT_125 
    {
        struct ast_bins_or_options *ret = new (struct ast_bins_or_options);
        $$ = ret;
    }
    | bins_keyword bin_identifier TOKEN_38 /* = */ TOKEN_46 /* default */ TOKEN_173 /* sequence */ OPT_125 
    {
        struct ast_bins_or_options *ret = new (struct ast_bins_or_options);
        $$ = ret;
    }
    ;

bins_keyword 
    : TOKEN_225 /* bins */ 
    {
        struct ast_bins_keyword *ret = new (struct ast_bins_keyword);
        $$ = ret;
    }
    | TOKEN_226 /* illegal_bins */ 
    {
        struct ast_bins_keyword *ret = new (struct ast_bins_keyword);
        $$ = ret;
    }
    | TOKEN_227 /* ignore_bins */ 
    {
        struct ast_bins_keyword *ret = new (struct ast_bins_keyword);
        $$ = ret;
    }
    ;

trans_list 
    : LIST_88 
    {
        struct ast_trans_list *ret = new (struct ast_trans_list);
        $$ = ret;
    }
    ;

trans_set 
    : LIST_89 
    {
        struct ast_trans_set *ret = new (struct ast_trans_set);
        $$ = ret;
    }
    ;

trans_range_list 
    : trans_item 
    {
        struct ast_trans_range_list *ret = new (struct ast_trans_range_list);
        $$ = ret;
    }
    | trans_item TOKEN_210 /* [* */ repeat_range TOKEN_80 /* ] */ 
    {
        struct ast_trans_range_list *ret = new (struct ast_trans_range_list);
        $$ = ret;
    }
    | trans_item TOKEN_212 /* [-> */ repeat_range TOKEN_80 /* ] */ 
    {
        struct ast_trans_range_list *ret = new (struct ast_trans_range_list);
        $$ = ret;
    }
    | trans_item TOKEN_211 /* [= */ repeat_range TOKEN_80 /* ] */ 
    {
        struct ast_trans_range_list *ret = new (struct ast_trans_range_list);
        $$ = ret;
    }
    ;

trans_item 
    : covergroup_range_list 
    {
        struct ast_trans_item *ret = new (struct ast_trans_item);
        $$ = ret;
    }
    ;

repeat_range 
    : covergroup_expression 
    {
        struct ast_repeat_range *ret = new (struct ast_repeat_range);
        $$ = ret;
    }
    | covergroup_expression TOKEN_6 /* : */ covergroup_expression 
    {
        struct ast_repeat_range *ret = new (struct ast_repeat_range);
        $$ = ret;
    }
    ;

cover_cross 
    : OPT_131 TOKEN_229 /* cross */ list_of_cross_items OPT_125 cross_body 
    {
        struct ast_cover_cross *ret = new (struct ast_cover_cross);
        $$ = ret;
    }
    ;

list_of_cross_items 
    : cross_item TOKEN_2 /* , */ LIST_90 
    {
        struct ast_list_of_cross_items *ret = new (struct ast_list_of_cross_items);
        $$ = ret;
    }
    ;

cross_item 
    : cover_point_identifier 
    {
        struct ast_cross_item *ret = new (struct ast_cross_item);
        $$ = ret;
    }
    | variable_identifier 
    {
        struct ast_cross_item *ret = new (struct ast_cross_item);
        $$ = ret;
    }
    ;

cross_body 
    : TOKEN_32 /* { */ STAR_40 TOKEN_33 /* } */ 
    {
        struct ast_cross_body *ret = new (struct ast_cross_body);
        $$ = ret;
    }
    | TOKEN_0 /* ; */ 
    {
        struct ast_cross_body *ret = new (struct ast_cross_body);
        $$ = ret;
    }
    ;

cross_body_item 
    : function_declaration 
    {
        struct ast_cross_body_item *ret = new (struct ast_cross_body_item);
        $$ = ret;
    }
    | bins_selection_or_option TOKEN_0 /* ; */ 
    {
        struct ast_cross_body_item *ret = new (struct ast_cross_body_item);
        $$ = ret;
    }
    ;

bins_selection_or_option 
    : STAR_2 coverage_option 
    {
        struct ast_bins_selection_or_option *ret = new (struct ast_bins_selection_or_option);
        $$ = ret;
    }
    | STAR_2 bins_selection 
    {
        struct ast_bins_selection_or_option *ret = new (struct ast_bins_selection_or_option);
        $$ = ret;
    }
    ;

bins_selection 
    : bins_keyword bin_identifier TOKEN_38 /* = */ select_expression OPT_125 
    {
        struct ast_bins_selection *ret = new (struct ast_bins_selection);
        $$ = ret;
    }
    ;

select_expression 
    : select_condition 
    {
        struct ast_select_expression *ret = new (struct ast_select_expression);
        $$ = ret;
    }
    | TOKEN_230 /* ! */ select_condition 
    {
        struct ast_select_expression *ret = new (struct ast_select_expression);
        $$ = ret;
    }
    | select_expression TOKEN_231 /* && */ select_expression 
    {
        struct ast_select_expression *ret = new (struct ast_select_expression);
        $$ = ret;
    }
    | select_expression TOKEN_232 /* || */ select_expression 
    {
        struct ast_select_expression *ret = new (struct ast_select_expression);
        $$ = ret;
    }
    | TOKEN_12 /* ( */ select_expression TOKEN_14 /* ) */ 
    {
        struct ast_select_expression *ret = new (struct ast_select_expression);
        $$ = ret;
    }
    | select_expression TOKEN_102 /* with */ TOKEN_12 /* ( */ with_covergroup_expression TOKEN_14 /* ) */ OPT_132 
    {
        struct ast_select_expression *ret = new (struct ast_select_expression);
        $$ = ret;
    }
    | cross_identifier 
    {
        struct ast_select_expression *ret = new (struct ast_select_expression);
        $$ = ret;
    }
    | cross_set_expression OPT_132 
    {
        struct ast_select_expression *ret = new (struct ast_select_expression);
        $$ = ret;
    }
    ;

select_condition 
    : TOKEN_234 /* binsof */ TOKEN_12 /* ( */ bins_expression TOKEN_14 /* ) */ OPT_133 
    {
        struct ast_select_condition *ret = new (struct ast_select_condition);
        $$ = ret;
    }
    ;

bins_expression 
    : variable_identifier 
    {
        struct ast_bins_expression *ret = new (struct ast_bins_expression);
        $$ = ret;
    }
    | cover_point_identifier OPT_134 
    {
        struct ast_bins_expression *ret = new (struct ast_bins_expression);
        $$ = ret;
    }
    ;

covergroup_range_list 
    : LIST_92 
    {
        struct ast_covergroup_range_list *ret = new (struct ast_covergroup_range_list);
        $$ = ret;
    }
    ;

covergroup_value_range 
    : covergroup_expression 
    {
        struct ast_covergroup_value_range *ret = new (struct ast_covergroup_value_range);
        $$ = ret;
    }
    | TOKEN_79 /* [ */ covergroup_expression TOKEN_6 /* : */ covergroup_expression TOKEN_80 /* ] */ 
    {
        struct ast_covergroup_value_range *ret = new (struct ast_covergroup_value_range);
        $$ = ret;
    }
    ;

with_covergroup_expression 
    : covergroup_expression 
    {
        struct ast_with_covergroup_expression *ret = new (struct ast_with_covergroup_expression);
        $$ = ret;
    }
    ;

set_covergroup_expression 
    : covergroup_expression 
    {
        struct ast_set_covergroup_expression *ret = new (struct ast_set_covergroup_expression);
        $$ = ret;
    }
    ;

integer_covergroup_expression 
    : covergroup_expression 
    {
        struct ast_integer_covergroup_expression *ret = new (struct ast_integer_covergroup_expression);
        $$ = ret;
    }
    ;

cross_set_expression 
    : covergroup_expression 
    {
        struct ast_cross_set_expression *ret = new (struct ast_cross_set_expression);
        $$ = ret;
    }
    ;

covergroup_expression 
    : expression 
    {
        struct ast_covergroup_expression *ret = new (struct ast_covergroup_expression);
        $$ = ret;
    }
    ;

gate_instantiation 
    : cmos_switchtype OPT_55 LIST_93 TOKEN_0 /* ; */ 
    {
        struct ast_gate_instantiation *ret = new (struct ast_gate_instantiation);
        $$ = ret;
    }
    | enable_gatetype OPT_135 OPT_55 LIST_94 TOKEN_0 /* ; */ 
    {
        struct ast_gate_instantiation *ret = new (struct ast_gate_instantiation);
        $$ = ret;
    }
    | mos_switchtype OPT_55 LIST_95 TOKEN_0 /* ; */ 
    {
        struct ast_gate_instantiation *ret = new (struct ast_gate_instantiation);
        $$ = ret;
    }
    | n_input_gatetype OPT_135 OPT_136 LIST_96 TOKEN_0 /* ; */ 
    {
        struct ast_gate_instantiation *ret = new (struct ast_gate_instantiation);
        $$ = ret;
    }
    | n_output_gatetype OPT_135 OPT_136 LIST_97 TOKEN_0 /* ; */ 
    {
        struct ast_gate_instantiation *ret = new (struct ast_gate_instantiation);
        $$ = ret;
    }
    | pass_en_switchtype OPT_136 LIST_98 TOKEN_0 /* ; */ 
    {
        struct ast_gate_instantiation *ret = new (struct ast_gate_instantiation);
        $$ = ret;
    }
    | pass_switchtype LIST_99 TOKEN_0 /* ; */ 
    {
        struct ast_gate_instantiation *ret = new (struct ast_gate_instantiation);
        $$ = ret;
    }
    | TOKEN_235 /* pulldown */ OPT_137 LIST_100 TOKEN_0 /* ; */ 
    {
        struct ast_gate_instantiation *ret = new (struct ast_gate_instantiation);
        $$ = ret;
    }
    | TOKEN_236 /* pullup */ OPT_138 LIST_100 TOKEN_0 /* ; */ 
    {
        struct ast_gate_instantiation *ret = new (struct ast_gate_instantiation);
        $$ = ret;
    }
    ;

cmos_switch_instance 
    : OPT_139 TOKEN_12 /* ( */ output_terminal TOKEN_2 /* , */ input_terminal TOKEN_2 /* , */ ncontrol_terminal TOKEN_2 /* , */ pcontrol_terminal TOKEN_14 /* ) */ 
    {
        struct ast_cmos_switch_instance *ret = new (struct ast_cmos_switch_instance);
        $$ = ret;
    }
    ;

enable_gate_instance 
    : OPT_139 TOKEN_12 /* ( */ output_terminal TOKEN_2 /* , */ input_terminal TOKEN_2 /* , */ enable_terminal TOKEN_14 /* ) */ 
    {
        struct ast_enable_gate_instance *ret = new (struct ast_enable_gate_instance);
        $$ = ret;
    }
    ;

mos_switch_instance 
    : OPT_139 TOKEN_12 /* ( */ output_terminal TOKEN_2 /* , */ input_terminal TOKEN_2 /* , */ enable_terminal TOKEN_14 /* ) */ 
    {
        struct ast_mos_switch_instance *ret = new (struct ast_mos_switch_instance);
        $$ = ret;
    }
    ;

n_input_gate_instance 
    : OPT_139 TOKEN_12 /* ( */ output_terminal TOKEN_2 /* , */ LIST_101 TOKEN_14 /* ) */ 
    {
        struct ast_n_input_gate_instance *ret = new (struct ast_n_input_gate_instance);
        $$ = ret;
    }
    ;

n_output_gate_instance 
    : OPT_139 TOKEN_12 /* ( */ LIST_102 TOKEN_14 /* ) */ 
    {
        struct ast_n_output_gate_instance *ret = new (struct ast_n_output_gate_instance);
        $$ = ret;
    }
    ;

pass_switch_instance 
    : OPT_139 TOKEN_12 /* ( */ inout_terminal TOKEN_2 /* , */ inout_terminal TOKEN_14 /* ) */ 
    {
        struct ast_pass_switch_instance *ret = new (struct ast_pass_switch_instance);
        $$ = ret;
    }
    ;

pass_enable_switch_instance 
    : OPT_139 TOKEN_12 /* ( */ inout_terminal TOKEN_2 /* , */ inout_terminal TOKEN_2 /* , */ enable_terminal TOKEN_14 /* ) */ 
    {
        struct ast_pass_enable_switch_instance *ret = new (struct ast_pass_enable_switch_instance);
        $$ = ret;
    }
    ;

pull_gate_instance 
    : OPT_139 TOKEN_12 /* ( */ output_terminal TOKEN_14 /* ) */ 
    {
        struct ast_pull_gate_instance *ret = new (struct ast_pull_gate_instance);
        $$ = ret;
    }
    ;

pulldown_strength 
    : TOKEN_12 /* ( */ strength0 TOKEN_2 /* , */ strength1 TOKEN_14 /* ) */ 
    {
        struct ast_pulldown_strength *ret = new (struct ast_pulldown_strength);
        $$ = ret;
    }
    | TOKEN_12 /* ( */ strength1 TOKEN_2 /* , */ strength0 TOKEN_14 /* ) */ 
    {
        struct ast_pulldown_strength *ret = new (struct ast_pulldown_strength);
        $$ = ret;
    }
    | TOKEN_12 /* ( */ strength0 TOKEN_14 /* ) */ 
    {
        struct ast_pulldown_strength *ret = new (struct ast_pulldown_strength);
        $$ = ret;
    }
    ;

pullup_strength 
    : TOKEN_12 /* ( */ strength0 TOKEN_2 /* , */ strength1 TOKEN_14 /* ) */ 
    {
        struct ast_pullup_strength *ret = new (struct ast_pullup_strength);
        $$ = ret;
    }
    | TOKEN_12 /* ( */ strength1 TOKEN_2 /* , */ strength0 TOKEN_14 /* ) */ 
    {
        struct ast_pullup_strength *ret = new (struct ast_pullup_strength);
        $$ = ret;
    }
    | TOKEN_12 /* ( */ strength1 TOKEN_14 /* ) */ 
    {
        struct ast_pullup_strength *ret = new (struct ast_pullup_strength);
        $$ = ret;
    }
    ;

enable_terminal 
    : expression 
    {
        struct ast_enable_terminal *ret = new (struct ast_enable_terminal);
        $$ = ret;
    }
    ;

inout_terminal 
    : net_lvalue 
    {
        struct ast_inout_terminal *ret = new (struct ast_inout_terminal);
        $$ = ret;
    }
    ;

input_terminal 
    : expression 
    {
        struct ast_input_terminal *ret = new (struct ast_input_terminal);
        $$ = ret;
    }
    ;

ncontrol_terminal 
    : expression 
    {
        struct ast_ncontrol_terminal *ret = new (struct ast_ncontrol_terminal);
        $$ = ret;
    }
    ;

output_terminal 
    : net_lvalue 
    {
        struct ast_output_terminal *ret = new (struct ast_output_terminal);
        $$ = ret;
    }
    ;

pcontrol_terminal 
    : expression 
    {
        struct ast_pcontrol_terminal *ret = new (struct ast_pcontrol_terminal);
        $$ = ret;
    }
    ;

cmos_switchtype 
    : TOKEN_237 /* cmos */ 
    {
        struct ast_cmos_switchtype *ret = new (struct ast_cmos_switchtype);
        $$ = ret;
    }
    | TOKEN_238 /* rcmos */ 
    {
        struct ast_cmos_switchtype *ret = new (struct ast_cmos_switchtype);
        $$ = ret;
    }
    ;

enable_gatetype 
    : TOKEN_239 /* bufif0 */ 
    {
        struct ast_enable_gatetype *ret = new (struct ast_enable_gatetype);
        $$ = ret;
    }
    | TOKEN_240 /* bufif1 */ 
    {
        struct ast_enable_gatetype *ret = new (struct ast_enable_gatetype);
        $$ = ret;
    }
    | TOKEN_241 /* notif0 */ 
    {
        struct ast_enable_gatetype *ret = new (struct ast_enable_gatetype);
        $$ = ret;
    }
    | TOKEN_242 /* notif1 */ 
    {
        struct ast_enable_gatetype *ret = new (struct ast_enable_gatetype);
        $$ = ret;
    }
    ;

mos_switchtype 
    : TOKEN_243 /* nmos */ 
    {
        struct ast_mos_switchtype *ret = new (struct ast_mos_switchtype);
        $$ = ret;
    }
    | TOKEN_244 /* pmos */ 
    {
        struct ast_mos_switchtype *ret = new (struct ast_mos_switchtype);
        $$ = ret;
    }
    | TOKEN_245 /* rnmos */ 
    {
        struct ast_mos_switchtype *ret = new (struct ast_mos_switchtype);
        $$ = ret;
    }
    | TOKEN_246 /* rpmos */ 
    {
        struct ast_mos_switchtype *ret = new (struct ast_mos_switchtype);
        $$ = ret;
    }
    ;

n_input_gatetype 
    : TOKEN_180 /* and */ 
    {
        struct ast_n_input_gatetype *ret = new (struct ast_n_input_gatetype);
        $$ = ret;
    }
    | TOKEN_247 /* nand */ 
    {
        struct ast_n_input_gatetype *ret = new (struct ast_n_input_gatetype);
        $$ = ret;
    }
    | TOKEN_179 /* or */ 
    {
        struct ast_n_input_gatetype *ret = new (struct ast_n_input_gatetype);
        $$ = ret;
    }
    | TOKEN_248 /* nor */ 
    {
        struct ast_n_input_gatetype *ret = new (struct ast_n_input_gatetype);
        $$ = ret;
    }
    | TOKEN_249 /* xor */ 
    {
        struct ast_n_input_gatetype *ret = new (struct ast_n_input_gatetype);
        $$ = ret;
    }
    | TOKEN_250 /* xnor */ 
    {
        struct ast_n_input_gatetype *ret = new (struct ast_n_input_gatetype);
        $$ = ret;
    }
    ;

n_output_gatetype 
    : TOKEN_251 /* buf */ 
    {
        struct ast_n_output_gatetype *ret = new (struct ast_n_output_gatetype);
        $$ = ret;
    }
    | TOKEN_178 /* not */ 
    {
        struct ast_n_output_gatetype *ret = new (struct ast_n_output_gatetype);
        $$ = ret;
    }
    ;

pass_en_switchtype 
    : TOKEN_252 /* tranif0 */ 
    {
        struct ast_pass_en_switchtype *ret = new (struct ast_pass_en_switchtype);
        $$ = ret;
    }
    | TOKEN_253 /* tranif1 */ 
    {
        struct ast_pass_en_switchtype *ret = new (struct ast_pass_en_switchtype);
        $$ = ret;
    }
    | TOKEN_254 /* rtranif0 */ 
    {
        struct ast_pass_en_switchtype *ret = new (struct ast_pass_en_switchtype);
        $$ = ret;
    }
    | TOKEN_255 /* rtranif1 */ 
    {
        struct ast_pass_en_switchtype *ret = new (struct ast_pass_en_switchtype);
        $$ = ret;
    }
    ;

pass_switchtype 
    : TOKEN_256 /* tran */ 
    {
        struct ast_pass_switchtype *ret = new (struct ast_pass_switchtype);
        $$ = ret;
    }
    | TOKEN_257 /* rtran */ 
    {
        struct ast_pass_switchtype *ret = new (struct ast_pass_switchtype);
        $$ = ret;
    }
    ;

module_instantiation 
    : module_identifier OPT_16 LIST_103 TOKEN_0 /* ; */ 
    {
        struct ast_module_instantiation *ret = new (struct ast_module_instantiation);
        $$ = ret;
    }
    ;

parameter_value_assignment 
    : TOKEN_29 /* # */ TOKEN_12 /* ( */ OPT_140 TOKEN_14 /* ) */ 
    {
        struct ast_parameter_value_assignment *ret = new (struct ast_parameter_value_assignment);
        $$ = ret;
    }
    ;

list_of_parameter_assignments 
    : LIST_104 
    {
        struct ast_list_of_parameter_assignments *ret = new (struct ast_list_of_parameter_assignments);
        $$ = ret;
    }
    | LIST_28 
    {
        struct ast_list_of_parameter_assignments *ret = new (struct ast_list_of_parameter_assignments);
        $$ = ret;
    }
    ;

ordered_parameter_assignment 
    : param_expression 
    {
        struct ast_ordered_parameter_assignment *ret = new (struct ast_ordered_parameter_assignment);
        $$ = ret;
    }
    ;

named_parameter_assignment 
    : TOKEN_31 /* . */ parameter_identifier TOKEN_12 /* ( */ OPT_141 TOKEN_14 /* ) */ 
    {
        struct ast_named_parameter_assignment *ret = new (struct ast_named_parameter_assignment);
        $$ = ret;
    }
    ;

hierarchical_instance 
    : name_of_instance TOKEN_12 /* ( */ OPT_142 TOKEN_14 /* ) */ 
    {
        struct ast_hierarchical_instance *ret = new (struct ast_hierarchical_instance);
        $$ = ret;
    }
    ;

name_of_instance 
    : instance_identifier STAR_14 
    {
        struct ast_name_of_instance *ret = new (struct ast_name_of_instance);
        $$ = ret;
    }
    ;

list_of_port_connections 
    : LIST_105 
    {
        struct ast_list_of_port_connections *ret = new (struct ast_list_of_port_connections);
        $$ = ret;
    }
    | LIST_106 
    {
        struct ast_list_of_port_connections *ret = new (struct ast_list_of_port_connections);
        $$ = ret;
    }
    ;

ordered_port_connection 
    : STAR_2 OPT_26 
    {
        struct ast_ordered_port_connection *ret = new (struct ast_ordered_port_connection);
        $$ = ret;
    }
    ;

named_port_connection 
    : STAR_2 TOKEN_31 /* . */ port_identifier OPT_143 
    {
        struct ast_named_port_connection *ret = new (struct ast_named_port_connection);
        $$ = ret;
    }
    | STAR_2 TOKEN_31 /* . */ TOKEN_90 /* * */ 
    {
        struct ast_named_port_connection *ret = new (struct ast_named_port_connection);
        $$ = ret;
    }
    ;

interface_instantiation 
    : interface_identifier OPT_16 LIST_103 TOKEN_0 /* ; */ 
    {
        struct ast_interface_instantiation *ret = new (struct ast_interface_instantiation);
        $$ = ret;
    }
    ;

program_instantiation 
    : program_identifier OPT_16 LIST_103 TOKEN_0 /* ; */ 
    {
        struct ast_program_instantiation *ret = new (struct ast_program_instantiation);
        $$ = ret;
    }
    ;

checker_instantiation 
    : ps_checker_identifier name_of_instance TOKEN_12 /* ( */ OPT_144 TOKEN_14 /* ) */ TOKEN_0 /* ; */ 
    {
        struct ast_checker_instantiation *ret = new (struct ast_checker_instantiation);
        $$ = ret;
    }
    ;

list_of_checker_port_connections 
    : LIST_107 
    {
        struct ast_list_of_checker_port_connections *ret = new (struct ast_list_of_checker_port_connections);
        $$ = ret;
    }
    | LIST_108 
    {
        struct ast_list_of_checker_port_connections *ret = new (struct ast_list_of_checker_port_connections);
        $$ = ret;
    }
    ;

ordered_checker_port_connection 
    : STAR_2 OPT_94 
    {
        struct ast_ordered_checker_port_connection *ret = new (struct ast_ordered_checker_port_connection);
        $$ = ret;
    }
    ;

named_checker_port_connection 
    : STAR_2 TOKEN_31 /* . */ formal_port_identifier OPT_145 
    {
        struct ast_named_checker_port_connection *ret = new (struct ast_named_checker_port_connection);
        $$ = ret;
    }
    | STAR_2 TOKEN_31 /* . */ TOKEN_90 /* * */ 
    {
        struct ast_named_checker_port_connection *ret = new (struct ast_named_checker_port_connection);
        $$ = ret;
    }
    ;

generate_region 
    : TOKEN_258 /* generate */ STAR_41 TOKEN_259 /* endgenerate */ 
    {
        struct ast_generate_region *ret = new (struct ast_generate_region);
        $$ = ret;
    }
    ;

loop_generate_construct 
    : TOKEN_260 /* for */ TOKEN_12 /* ( */ genvar_initialization TOKEN_0 /* ; */ genvar_expression TOKEN_0 /* ; */ genvar_iteration TOKEN_14 /* ) */ generate_block 
    {
        struct ast_loop_generate_construct *ret = new (struct ast_loop_generate_construct);
        $$ = ret;
    }
    ;

genvar_initialization 
    : OPT_146 genvar_identifier TOKEN_38 /* = */ constant_expression 
    {
        struct ast_genvar_initialization *ret = new (struct ast_genvar_initialization);
        $$ = ret;
    }
    ;

genvar_iteration 
    : genvar_identifier assignment_operator genvar_expression 
    {
        struct ast_genvar_iteration *ret = new (struct ast_genvar_iteration);
        $$ = ret;
    }
    | inc_or_dec_operator genvar_identifier 
    {
        struct ast_genvar_iteration *ret = new (struct ast_genvar_iteration);
        $$ = ret;
    }
    | genvar_identifier inc_or_dec_operator 
    {
        struct ast_genvar_iteration *ret = new (struct ast_genvar_iteration);
        $$ = ret;
    }
    ;

conditional_generate_construct 
    : if_generate_construct 
    {
        struct ast_conditional_generate_construct *ret = new (struct ast_conditional_generate_construct);
        $$ = ret;
    }
    | case_generate_construct 
    {
        struct ast_conditional_generate_construct *ret = new (struct ast_conditional_generate_construct);
        $$ = ret;
    }
    ;

if_generate_construct 
    : TOKEN_76 /* if */ TOKEN_12 /* ( */ constant_expression TOKEN_14 /* ) */ generate_block OPT_147 
    {
        struct ast_if_generate_construct *ret = new (struct ast_if_generate_construct);
        $$ = ret;
    }
    ;

case_generate_construct 
    : TOKEN_183 /* case */ TOKEN_12 /* ( */ constant_expression TOKEN_14 /* ) */ case_generate_item TOKEN_32 /* { */ case_generate_item TOKEN_33 /* } */ TOKEN_184 /* endcase */ 
    {
        struct ast_case_generate_construct *ret = new (struct ast_case_generate_construct);
        $$ = ret;
    }
    ;

case_generate_item 
    : LIST_110 TOKEN_6 /* : */ generate_block 
    {
        struct ast_case_generate_item *ret = new (struct ast_case_generate_item);
        $$ = ret;
    }
    | TOKEN_46 /* default */ OPT_102 generate_block 
    {
        struct ast_case_generate_item *ret = new (struct ast_case_generate_item);
        $$ = ret;
    }
    ;

generate_block 
    : generate_item 
    {
        struct ast_generate_block *ret = new (struct ast_generate_block);
        $$ = ret;
    }
    | OPT_148 TOKEN_221 /* begin */ OPT_149 STAR_41 TOKEN_222 /* end */ OPT_149 
    {
        struct ast_generate_block *ret = new (struct ast_generate_block);
        $$ = ret;
    }
    ;

generate_item 
    : module_or_generate_item 
    {
        struct ast_generate_item *ret = new (struct ast_generate_item);
        $$ = ret;
    }
    | interface_or_generate_item 
    {
        struct ast_generate_item *ret = new (struct ast_generate_item);
        $$ = ret;
    }
    | checker_or_generate_item 
    {
        struct ast_generate_item *ret = new (struct ast_generate_item);
        $$ = ret;
    }
    ;

udp_nonansi_declaration 
    : STAR_2 TOKEN_261 /* primitive */ udp_identifier TOKEN_12 /* ( */ udp_port_list TOKEN_14 /* ) */ TOKEN_0 /* ; */ 
    {
        struct ast_udp_nonansi_declaration *ret = new (struct ast_udp_nonansi_declaration);
        $$ = ret;
    }
    ;

udp_ansi_declaration 
    : STAR_2 TOKEN_261 /* primitive */ udp_identifier TOKEN_12 /* ( */ udp_declaration_port_list TOKEN_14 /* ) */ TOKEN_0 /* ; */ 
    {
        struct ast_udp_ansi_declaration *ret = new (struct ast_udp_ansi_declaration);
        $$ = ret;
    }
    ;

udp_declaration 
    : udp_nonansi_declaration LIST_111 udp_body TOKEN_262 /* endprimitive */ OPT_150 
    {
        struct ast_udp_declaration *ret = new (struct ast_udp_declaration);
        $$ = ret;
    }
    | udp_ansi_declaration udp_body TOKEN_262 /* endprimitive */ OPT_150 
    {
        struct ast_udp_declaration *ret = new (struct ast_udp_declaration);
        $$ = ret;
    }
    | TOKEN_7 /* extern */ udp_nonansi_declaration 
    {
        struct ast_udp_declaration *ret = new (struct ast_udp_declaration);
        $$ = ret;
    }
    | TOKEN_7 /* extern */ udp_ansi_declaration 
    {
        struct ast_udp_declaration *ret = new (struct ast_udp_declaration);
        $$ = ret;
    }
    | STAR_2 TOKEN_261 /* primitive */ udp_identifier TOKEN_12 /* ( */ TOKEN_13 /* .* */ TOKEN_14 /* ) */ TOKEN_0 /* ; */ STAR_42 udp_body TOKEN_262 /* endprimitive */ OPT_150 
    {
        struct ast_udp_declaration *ret = new (struct ast_udp_declaration);
        $$ = ret;
    }
    ;

udp_port_list 
    : output_port_identifier TOKEN_2 /* , */ LIST_112 
    {
        struct ast_udp_port_list *ret = new (struct ast_udp_port_list);
        $$ = ret;
    }
    ;

udp_declaration_port_list 
    : udp_output_declaration TOKEN_2 /* , */ LIST_113 
    {
        struct ast_udp_declaration_port_list *ret = new (struct ast_udp_declaration_port_list);
        $$ = ret;
    }
    ;

udp_port_declaration 
    : udp_output_declaration TOKEN_0 /* ; */ 
    {
        struct ast_udp_port_declaration *ret = new (struct ast_udp_port_declaration);
        $$ = ret;
    }
    | udp_input_declaration TOKEN_0 /* ; */ 
    {
        struct ast_udp_port_declaration *ret = new (struct ast_udp_port_declaration);
        $$ = ret;
    }
    | udp_reg_declaration TOKEN_0 /* ; */ 
    {
        struct ast_udp_port_declaration *ret = new (struct ast_udp_port_declaration);
        $$ = ret;
    }
    ;

udp_output_declaration 
    : STAR_2 TOKEN_35 /* output */ port_identifier 
    {
        struct ast_udp_output_declaration *ret = new (struct ast_udp_output_declaration);
        $$ = ret;
    }
    | STAR_2 TOKEN_35 /* output */ TOKEN_116 /* reg */ port_identifier OPT_24 
    {
        struct ast_udp_output_declaration *ret = new (struct ast_udp_output_declaration);
        $$ = ret;
    }
    ;

udp_input_declaration 
    : STAR_2 TOKEN_34 /* input */ list_of_udp_port_identifiers 
    {
        struct ast_udp_input_declaration *ret = new (struct ast_udp_input_declaration);
        $$ = ret;
    }
    ;

udp_reg_declaration 
    : STAR_2 TOKEN_116 /* reg */ variable_identifier 
    {
        struct ast_udp_reg_declaration *ret = new (struct ast_udp_reg_declaration);
        $$ = ret;
    }
    ;

udp_body 
    : combinational_body 
    {
        struct ast_udp_body *ret = new (struct ast_udp_body);
        $$ = ret;
    }
    | sequential_body 
    {
        struct ast_udp_body *ret = new (struct ast_udp_body);
        $$ = ret;
    }
    ;

combinational_body 
    : TOKEN_263 /* table */ LIST_114 TOKEN_264 /* endtable */ 
    {
        struct ast_combinational_body *ret = new (struct ast_combinational_body);
        $$ = ret;
    }
    ;

combinational_entry 
    : level_input_list TOKEN_6 /* : */ output_symbol TOKEN_0 /* ; */ 
    {
        struct ast_combinational_entry *ret = new (struct ast_combinational_entry);
        $$ = ret;
    }
    ;

sequential_body 
    : OPT_151 TOKEN_263 /* table */ LIST_115 TOKEN_264 /* endtable */ 
    {
        struct ast_sequential_body *ret = new (struct ast_sequential_body);
        $$ = ret;
    }
    ;

udp_initial_statement 
    : TOKEN_265 /* initial */ output_port_identifier TOKEN_38 /* = */ init_val TOKEN_0 /* ; */ 
    {
        struct ast_udp_initial_statement *ret = new (struct ast_udp_initial_statement);
        $$ = ret;
    }
    ;

init_val 
    : TOKEN_266 /* 1'b0 */ 
    {
        struct ast_init_val *ret = new (struct ast_init_val);
        $$ = ret;
    }
    | TOKEN_267 /* 1'b1 */ 
    {
        struct ast_init_val *ret = new (struct ast_init_val);
        $$ = ret;
    }
    | TOKEN_268 /* 1'bx */ 
    {
        struct ast_init_val *ret = new (struct ast_init_val);
        $$ = ret;
    }
    | TOKEN_269 /* 1'bX */ 
    {
        struct ast_init_val *ret = new (struct ast_init_val);
        $$ = ret;
    }
    | TOKEN_270 /* 1'B0 */ 
    {
        struct ast_init_val *ret = new (struct ast_init_val);
        $$ = ret;
    }
    | TOKEN_271 /* 1'B1 */ 
    {
        struct ast_init_val *ret = new (struct ast_init_val);
        $$ = ret;
    }
    | TOKEN_272 /* 1'Bx */ 
    {
        struct ast_init_val *ret = new (struct ast_init_val);
        $$ = ret;
    }
    | TOKEN_273 /* 1'BX */ 
    {
        struct ast_init_val *ret = new (struct ast_init_val);
        $$ = ret;
    }
    | TOKEN_44 /* 1 */ 
    {
        struct ast_init_val *ret = new (struct ast_init_val);
        $$ = ret;
    }
    | TOKEN_43 /* 0 */ 
    {
        struct ast_init_val *ret = new (struct ast_init_val);
        $$ = ret;
    }
    ;

sequential_entry 
    : seq_input_list TOKEN_6 /* : */ current_state TOKEN_6 /* : */ next_state TOKEN_0 /* ; */ 
    {
        struct ast_sequential_entry *ret = new (struct ast_sequential_entry);
        $$ = ret;
    }
    ;

seq_input_list 
    : level_input_list 
    {
        struct ast_seq_input_list *ret = new (struct ast_seq_input_list);
        $$ = ret;
    }
    | edge_input_list 
    {
        struct ast_seq_input_list *ret = new (struct ast_seq_input_list);
        $$ = ret;
    }
    ;

level_input_list 
    : LIST_116 
    {
        struct ast_level_input_list *ret = new (struct ast_level_input_list);
        $$ = ret;
    }
    ;

edge_input_list 
    : STAR_43 edge_indicator STAR_43 
    {
        struct ast_edge_input_list *ret = new (struct ast_edge_input_list);
        $$ = ret;
    }
    ;

edge_indicator 
    : TOKEN_12 /* ( */ level_symbol level_symbol TOKEN_14 /* ) */ 
    {
        struct ast_edge_indicator *ret = new (struct ast_edge_indicator);
        $$ = ret;
    }
    | edge_symbol 
    {
        struct ast_edge_indicator *ret = new (struct ast_edge_indicator);
        $$ = ret;
    }
    ;

current_state 
    : level_symbol 
    {
        struct ast_current_state *ret = new (struct ast_current_state);
        $$ = ret;
    }
    ;

next_state 
    : output_symbol 
    {
        struct ast_next_state *ret = new (struct ast_next_state);
        $$ = ret;
    }
    | TOKEN_157 /* - */ 
    {
        struct ast_next_state *ret = new (struct ast_next_state);
        $$ = ret;
    }
    ;

output_symbol 
    : TOKEN_43 /* 0 */ 
    {
        struct ast_output_symbol *ret = new (struct ast_output_symbol);
        $$ = ret;
    }
    | TOKEN_44 /* 1 */ 
    {
        struct ast_output_symbol *ret = new (struct ast_output_symbol);
        $$ = ret;
    }
    | TOKEN_274 /* x */ 
    {
        struct ast_output_symbol *ret = new (struct ast_output_symbol);
        $$ = ret;
    }
    | TOKEN_275 /* X */ 
    {
        struct ast_output_symbol *ret = new (struct ast_output_symbol);
        $$ = ret;
    }
    ;

level_symbol 
    : TOKEN_43 /* 0 */ 
    {
        struct ast_level_symbol *ret = new (struct ast_level_symbol);
        $$ = ret;
    }
    | TOKEN_44 /* 1 */ 
    {
        struct ast_level_symbol *ret = new (struct ast_level_symbol);
        $$ = ret;
    }
    | TOKEN_274 /* x */ 
    {
        struct ast_level_symbol *ret = new (struct ast_level_symbol);
        $$ = ret;
    }
    | TOKEN_275 /* X */ 
    {
        struct ast_level_symbol *ret = new (struct ast_level_symbol);
        $$ = ret;
    }
    | TOKEN_276 /* ? */ 
    {
        struct ast_level_symbol *ret = new (struct ast_level_symbol);
        $$ = ret;
    }
    | TOKEN_277 /* b */ 
    {
        struct ast_level_symbol *ret = new (struct ast_level_symbol);
        $$ = ret;
    }
    | TOKEN_278 /* B */ 
    {
        struct ast_level_symbol *ret = new (struct ast_level_symbol);
        $$ = ret;
    }
    ;

edge_symbol 
    : TOKEN_279 /* r */ 
    {
        struct ast_edge_symbol *ret = new (struct ast_edge_symbol);
        $$ = ret;
    }
    | TOKEN_280 /* R */ 
    {
        struct ast_edge_symbol *ret = new (struct ast_edge_symbol);
        $$ = ret;
    }
    | TOKEN_281 /* f */ 
    {
        struct ast_edge_symbol *ret = new (struct ast_edge_symbol);
        $$ = ret;
    }
    | TOKEN_282 /* F */ 
    {
        struct ast_edge_symbol *ret = new (struct ast_edge_symbol);
        $$ = ret;
    }
    | TOKEN_283 /* p */ 
    {
        struct ast_edge_symbol *ret = new (struct ast_edge_symbol);
        $$ = ret;
    }
    | TOKEN_284 /* P */ 
    {
        struct ast_edge_symbol *ret = new (struct ast_edge_symbol);
        $$ = ret;
    }
    | TOKEN_285 /* n */ 
    {
        struct ast_edge_symbol *ret = new (struct ast_edge_symbol);
        $$ = ret;
    }
    | TOKEN_286 /* N */ 
    {
        struct ast_edge_symbol *ret = new (struct ast_edge_symbol);
        $$ = ret;
    }
    | TOKEN_90 /* * */ 
    {
        struct ast_edge_symbol *ret = new (struct ast_edge_symbol);
        $$ = ret;
    }
    ;

udp_instantiation 
    : udp_identifier OPT_135 OPT_136 LIST_117 TOKEN_0 /* ; */ 
    {
        struct ast_udp_instantiation *ret = new (struct ast_udp_instantiation);
        $$ = ret;
    }
    ;

udp_instance 
    : OPT_139 TOKEN_12 /* ( */ output_terminal TOKEN_2 /* , */ LIST_101 TOKEN_14 /* ) */ 
    {
        struct ast_udp_instance *ret = new (struct ast_udp_instance);
        $$ = ret;
    }
    ;

continuous_assign 
    : TOKEN_287 /* assign */ OPT_135 OPT_55 list_of_net_assignments TOKEN_0 /* ; */ 
    {
        struct ast_continuous_assign *ret = new (struct ast_continuous_assign);
        $$ = ret;
    }
    | TOKEN_287 /* assign */ OPT_56 list_of_variable_assignments TOKEN_0 /* ; */ 
    {
        struct ast_continuous_assign *ret = new (struct ast_continuous_assign);
        $$ = ret;
    }
    ;

list_of_net_assignments 
    : LIST_118 
    {
        struct ast_list_of_net_assignments *ret = new (struct ast_list_of_net_assignments);
        $$ = ret;
    }
    ;

list_of_variable_assignments 
    : LIST_119 
    {
        struct ast_list_of_variable_assignments *ret = new (struct ast_list_of_variable_assignments);
        $$ = ret;
    }
    ;

net_alias 
    : TOKEN_288 /* alias */ net_lvalue LIST_120 
    {
        struct ast_net_alias *ret = new (struct ast_net_alias);
        $$ = ret;
    }
    ;

net_assignment 
    : net_lvalue TOKEN_38 /* = */ expression 
    {
        struct ast_net_assignment *ret = new (struct ast_net_assignment);
        $$ = ret;
    }
    ;

initial_construct 
    : TOKEN_265 /* initial */ statement_or_null 
    {
        struct ast_initial_construct *ret = new (struct ast_initial_construct);
        $$ = ret;
    }
    ;

always_construct 
    : always_keyword statement 
    {
        struct ast_always_construct *ret = new (struct ast_always_construct);
        $$ = ret;
    }
    ;

always_keyword 
    : TOKEN_189 /* always */ 
    {
        struct ast_always_keyword *ret = new (struct ast_always_keyword);
        $$ = ret;
    }
    | TOKEN_289 /* always_comb */ 
    {
        struct ast_always_keyword *ret = new (struct ast_always_keyword);
        $$ = ret;
    }
    | TOKEN_290 /* always_latch */ 
    {
        struct ast_always_keyword *ret = new (struct ast_always_keyword);
        $$ = ret;
    }
    | TOKEN_291 /* always_ff */ 
    {
        struct ast_always_keyword *ret = new (struct ast_always_keyword);
        $$ = ret;
    }
    ;

final_construct 
    : TOKEN_292 /* final */ function_statement 
    {
        struct ast_final_construct *ret = new (struct ast_final_construct);
        $$ = ret;
    }
    ;

blocking_assignment 
    : variable_lvalue TOKEN_38 /* = */ delay_or_event_control expression 
    {
        struct ast_blocking_assignment *ret = new (struct ast_blocking_assignment);
        $$ = ret;
    }
    | nonrange_variable_lvalue TOKEN_38 /* = */ dynamic_array_new 
    {
        struct ast_blocking_assignment *ret = new (struct ast_blocking_assignment);
        $$ = ret;
    }
    | OPT_152 hierarchical_variable_identifier select TOKEN_38 /* = */ class_new 
    {
        struct ast_blocking_assignment *ret = new (struct ast_blocking_assignment);
        $$ = ret;
    }
    | operator_assignment 
    {
        struct ast_blocking_assignment *ret = new (struct ast_blocking_assignment);
        $$ = ret;
    }
    ;

operator_assignment 
    : variable_lvalue assignment_operator expression 
    {
        struct ast_operator_assignment *ret = new (struct ast_operator_assignment);
        $$ = ret;
    }
    ;

assignment_operator 
    : TOKEN_38 /* = */ 
    {
        struct ast_assignment_operator *ret = new (struct ast_assignment_operator);
        $$ = ret;
    }
    | TOKEN_293 /* += */ 
    {
        struct ast_assignment_operator *ret = new (struct ast_assignment_operator);
        $$ = ret;
    }
    | TOKEN_294 /* -= */ 
    {
        struct ast_assignment_operator *ret = new (struct ast_assignment_operator);
        $$ = ret;
    }
    | TOKEN_295 /* *= */ 
    {
        struct ast_assignment_operator *ret = new (struct ast_assignment_operator);
        $$ = ret;
    }
    | TOKEN_296 /* /= */ 
    {
        struct ast_assignment_operator *ret = new (struct ast_assignment_operator);
        $$ = ret;
    }
    | TOKEN_297 /* %= */ 
    {
        struct ast_assignment_operator *ret = new (struct ast_assignment_operator);
        $$ = ret;
    }
    | TOKEN_298 /* &= */ 
    {
        struct ast_assignment_operator *ret = new (struct ast_assignment_operator);
        $$ = ret;
    }
    | TOKEN_299 /* |= */ 
    {
        struct ast_assignment_operator *ret = new (struct ast_assignment_operator);
        $$ = ret;
    }
    | TOKEN_300 /* ^= */ 
    {
        struct ast_assignment_operator *ret = new (struct ast_assignment_operator);
        $$ = ret;
    }
    | TOKEN_301 /* <<= */ 
    {
        struct ast_assignment_operator *ret = new (struct ast_assignment_operator);
        $$ = ret;
    }
    | TOKEN_302 /* >>= */ 
    {
        struct ast_assignment_operator *ret = new (struct ast_assignment_operator);
        $$ = ret;
    }
    | TOKEN_303 /* <<<= */ 
    {
        struct ast_assignment_operator *ret = new (struct ast_assignment_operator);
        $$ = ret;
    }
    | TOKEN_304 /* >>>= */ 
    {
        struct ast_assignment_operator *ret = new (struct ast_assignment_operator);
        $$ = ret;
    }
    ;

nonblocking_assignment 
    : variable_lvalue TOKEN_164 /* <= */ OPT_153 expression 
    {
        struct ast_nonblocking_assignment *ret = new (struct ast_nonblocking_assignment);
        $$ = ret;
    }
    ;

procedural_continuous_assignment 
    : TOKEN_287 /* assign */ variable_assignment 
    {
        struct ast_procedural_continuous_assignment *ret = new (struct ast_procedural_continuous_assignment);
        $$ = ret;
    }
    | TOKEN_305 /* deassign */ variable_lvalue 
    {
        struct ast_procedural_continuous_assignment *ret = new (struct ast_procedural_continuous_assignment);
        $$ = ret;
    }
    | TOKEN_306 /* force */ variable_assignment 
    {
        struct ast_procedural_continuous_assignment *ret = new (struct ast_procedural_continuous_assignment);
        $$ = ret;
    }
    | TOKEN_306 /* force */ net_assignment 
    {
        struct ast_procedural_continuous_assignment *ret = new (struct ast_procedural_continuous_assignment);
        $$ = ret;
    }
    | TOKEN_307 /* release */ variable_lvalue 
    {
        struct ast_procedural_continuous_assignment *ret = new (struct ast_procedural_continuous_assignment);
        $$ = ret;
    }
    | TOKEN_307 /* release */ net_lvalue 
    {
        struct ast_procedural_continuous_assignment *ret = new (struct ast_procedural_continuous_assignment);
        $$ = ret;
    }
    ;

variable_assignment 
    : variable_lvalue TOKEN_38 /* = */ expression 
    {
        struct ast_variable_assignment *ret = new (struct ast_variable_assignment);
        $$ = ret;
    }
    ;

action_block 
    : statement_or_null 
    {
        struct ast_action_block *ret = new (struct ast_action_block);
        $$ = ret;
    }
    | OPT_154 TOKEN_77 /* else */ statement_or_null 
    {
        struct ast_action_block *ret = new (struct ast_action_block);
        $$ = ret;
    }
    ;

seq_block 
    : TOKEN_221 /* begin */ OPT_155 STAR_24 STAR_32 TOKEN_222 /* end */ OPT_155 
    {
        struct ast_seq_block *ret = new (struct ast_seq_block);
        $$ = ret;
    }
    ;

par_block 
    : TOKEN_308 /* fork */ OPT_155 STAR_24 STAR_32 join_keyword OPT_155 
    {
        struct ast_par_block *ret = new (struct ast_par_block);
        $$ = ret;
    }
    ;

join_keyword 
    : TOKEN_309 /* join */ 
    {
        struct ast_join_keyword *ret = new (struct ast_join_keyword);
        $$ = ret;
    }
    | TOKEN_310 /* join_any */ 
    {
        struct ast_join_keyword *ret = new (struct ast_join_keyword);
        $$ = ret;
    }
    | TOKEN_311 /* join_none */ 
    {
        struct ast_join_keyword *ret = new (struct ast_join_keyword);
        $$ = ret;
    }
    ;

statement_or_null 
    : statement 
    {
        struct ast_statement_or_null *ret = new (struct ast_statement_or_null);
        $$ = ret;
    }
    | STAR_2 TOKEN_0 /* ; */ 
    {
        struct ast_statement_or_null *ret = new (struct ast_statement_or_null);
        $$ = ret;
    }
    ;

statement 
    : OPT_89 STAR_2 statement_item 
    {
        struct ast_statement *ret = new (struct ast_statement);
        $$ = ret;
    }
    ;

statement_item 
    : blocking_assignment TOKEN_0 /* ; */ 
    {
        struct ast_statement_item *ret = new (struct ast_statement_item);
        $$ = ret;
    }
    | nonblocking_assignment TOKEN_0 /* ; */ 
    {
        struct ast_statement_item *ret = new (struct ast_statement_item);
        $$ = ret;
    }
    | procedural_continuous_assignment TOKEN_0 /* ; */ 
    {
        struct ast_statement_item *ret = new (struct ast_statement_item);
        $$ = ret;
    }
    | case_statement 
    {
        struct ast_statement_item *ret = new (struct ast_statement_item);
        $$ = ret;
    }
    | conditional_statement 
    {
        struct ast_statement_item *ret = new (struct ast_statement_item);
        $$ = ret;
    }
    | inc_or_dec_expression TOKEN_0 /* ; */ 
    {
        struct ast_statement_item *ret = new (struct ast_statement_item);
        $$ = ret;
    }
    | subroutine_call_statement 
    {
        struct ast_statement_item *ret = new (struct ast_statement_item);
        $$ = ret;
    }
    | disable_statement 
    {
        struct ast_statement_item *ret = new (struct ast_statement_item);
        $$ = ret;
    }
    | event_trigger 
    {
        struct ast_statement_item *ret = new (struct ast_statement_item);
        $$ = ret;
    }
    | loop_statement 
    {
        struct ast_statement_item *ret = new (struct ast_statement_item);
        $$ = ret;
    }
    | jump_statement 
    {
        struct ast_statement_item *ret = new (struct ast_statement_item);
        $$ = ret;
    }
    | par_block 
    {
        struct ast_statement_item *ret = new (struct ast_statement_item);
        $$ = ret;
    }
    | procedural_timing_control_statement 
    {
        struct ast_statement_item *ret = new (struct ast_statement_item);
        $$ = ret;
    }
    | seq_block 
    {
        struct ast_statement_item *ret = new (struct ast_statement_item);
        $$ = ret;
    }
    | wait_statement 
    {
        struct ast_statement_item *ret = new (struct ast_statement_item);
        $$ = ret;
    }
    | procedural_assertion_statement 
    {
        struct ast_statement_item *ret = new (struct ast_statement_item);
        $$ = ret;
    }
    | clocking_drive TOKEN_0 /* ; */ 
    {
        struct ast_statement_item *ret = new (struct ast_statement_item);
        $$ = ret;
    }
    | randsequence_statement 
    {
        struct ast_statement_item *ret = new (struct ast_statement_item);
        $$ = ret;
    }
    | randcase_statement 
    {
        struct ast_statement_item *ret = new (struct ast_statement_item);
        $$ = ret;
    }
    | expect_property_statement 
    {
        struct ast_statement_item *ret = new (struct ast_statement_item);
        $$ = ret;
    }
    ;

function_statement 
    : statement 
    {
        struct ast_function_statement *ret = new (struct ast_function_statement);
        $$ = ret;
    }
    ;

function_statement_or_null 
    : function_statement 
    {
        struct ast_function_statement_or_null *ret = new (struct ast_function_statement_or_null);
        $$ = ret;
    }
    | STAR_2 TOKEN_0 /* ; */ 
    {
        struct ast_function_statement_or_null *ret = new (struct ast_function_statement_or_null);
        $$ = ret;
    }
    ;

variable_identifier_list 
    : LIST_121 
    {
        struct ast_variable_identifier_list *ret = new (struct ast_variable_identifier_list);
        $$ = ret;
    }
    ;

procedural_timing_control_statement 
    : procedural_timing_control statement_or_null 
    {
        struct ast_procedural_timing_control_statement *ret = new (struct ast_procedural_timing_control_statement);
        $$ = ret;
    }
    ;

delay_or_event_control 
    : delay_control 
    {
        struct ast_delay_or_event_control *ret = new (struct ast_delay_or_event_control);
        $$ = ret;
    }
    | event_control 
    {
        struct ast_delay_or_event_control *ret = new (struct ast_delay_or_event_control);
        $$ = ret;
    }
    | TOKEN_312 /* repeat */ TOKEN_12 /* ( */ expression TOKEN_14 /* ) */ event_control 
    {
        struct ast_delay_or_event_control *ret = new (struct ast_delay_or_event_control);
        $$ = ret;
    }
    ;

delay_control 
    : TOKEN_29 /* # */ delay_value 
    {
        struct ast_delay_control *ret = new (struct ast_delay_control);
        $$ = ret;
    }
    | TOKEN_29 /* # */ TOKEN_12 /* ( */ mintypmax_expression TOKEN_14 /* ) */ 
    {
        struct ast_delay_control *ret = new (struct ast_delay_control);
        $$ = ret;
    }
    ;

event_control 
    : TOKEN_313 /* @ */ hierarchical_event_identifier 
    {
        struct ast_event_control *ret = new (struct ast_event_control);
        $$ = ret;
    }
    | TOKEN_313 /* @ */ TOKEN_12 /* ( */ event_expression TOKEN_14 /* ) */ 
    {
        struct ast_event_control *ret = new (struct ast_event_control);
        $$ = ret;
    }
    | TOKEN_313 /* @ */ TOKEN_90 /* * */ 
    {
        struct ast_event_control *ret = new (struct ast_event_control);
        $$ = ret;
    }
    | TOKEN_313 /* @ */ TOKEN_12 /* ( */ TOKEN_90 /* * */ TOKEN_14 /* ) */ 
    {
        struct ast_event_control *ret = new (struct ast_event_control);
        $$ = ret;
    }
    | TOKEN_313 /* @ */ ps_or_hierarchical_sequence_identifier 
    {
        struct ast_event_control *ret = new (struct ast_event_control);
        $$ = ret;
    }
    ;

event_expression 
    : OPT_156 expression OPT_157 
    {
        struct ast_event_expression *ret = new (struct ast_event_expression);
        $$ = ret;
    }
    | sequence_instance OPT_157 
    {
        struct ast_event_expression *ret = new (struct ast_event_expression);
        $$ = ret;
    }
    | event_expression TOKEN_179 /* or */ event_expression 
    {
        struct ast_event_expression *ret = new (struct ast_event_expression);
        $$ = ret;
    }
    | event_expression TOKEN_2 /* , */ event_expression 
    {
        struct ast_event_expression *ret = new (struct ast_event_expression);
        $$ = ret;
    }
    | TOKEN_12 /* ( */ event_expression TOKEN_14 /* ) */ 
    {
        struct ast_event_expression *ret = new (struct ast_event_expression);
        $$ = ret;
    }
    ;

procedural_timing_control 
    : delay_control 
    {
        struct ast_procedural_timing_control *ret = new (struct ast_procedural_timing_control);
        $$ = ret;
    }
    | event_control 
    {
        struct ast_procedural_timing_control *ret = new (struct ast_procedural_timing_control);
        $$ = ret;
    }
    | cycle_delay 
    {
        struct ast_procedural_timing_control *ret = new (struct ast_procedural_timing_control);
        $$ = ret;
    }
    ;

jump_statement 
    : TOKEN_314 /* return */ OPT_26 TOKEN_0 /* ; */ 
    {
        struct ast_jump_statement *ret = new (struct ast_jump_statement);
        $$ = ret;
    }
    | TOKEN_315 /* break */ TOKEN_0 /* ; */ 
    {
        struct ast_jump_statement *ret = new (struct ast_jump_statement);
        $$ = ret;
    }
    | TOKEN_316 /* continue */ TOKEN_0 /* ; */ 
    {
        struct ast_jump_statement *ret = new (struct ast_jump_statement);
        $$ = ret;
    }
    ;

wait_statement 
    : TOKEN_317 /* wait */ TOKEN_12 /* ( */ expression TOKEN_14 /* ) */ statement_or_null 
    {
        struct ast_wait_statement *ret = new (struct ast_wait_statement);
        $$ = ret;
    }
    | TOKEN_317 /* wait */ TOKEN_308 /* fork */ TOKEN_0 /* ; */ 
    {
        struct ast_wait_statement *ret = new (struct ast_wait_statement);
        $$ = ret;
    }
    | TOKEN_318 /* wait_order */ TOKEN_12 /* ( */ LIST_122 TOKEN_14 /* ) */ action_block 
    {
        struct ast_wait_statement *ret = new (struct ast_wait_statement);
        $$ = ret;
    }
    ;

event_trigger 
    : TOKEN_75 /* -> */ hierarchical_event_identifier TOKEN_0 /* ; */ 
    {
        struct ast_event_trigger *ret = new (struct ast_event_trigger);
        $$ = ret;
    }
    | TOKEN_319 /* ->> */ OPT_153 hierarchical_event_identifier TOKEN_0 /* ; */ 
    {
        struct ast_event_trigger *ret = new (struct ast_event_trigger);
        $$ = ret;
    }
    ;

disable_statement 
    : TOKEN_48 /* disable */ hierarchical_task_identifier TOKEN_0 /* ; */ 
    {
        struct ast_disable_statement *ret = new (struct ast_disable_statement);
        $$ = ret;
    }
    | TOKEN_48 /* disable */ hierarchical_block_identifier TOKEN_0 /* ; */ 
    {
        struct ast_disable_statement *ret = new (struct ast_disable_statement);
        $$ = ret;
    }
    | TOKEN_48 /* disable */ TOKEN_308 /* fork */ TOKEN_0 /* ; */ 
    {
        struct ast_disable_statement *ret = new (struct ast_disable_statement);
        $$ = ret;
    }
    ;

conditional_statement 
    : OPT_158 TOKEN_76 /* if */ TOKEN_12 /* ( */ cond_predicate TOKEN_14 /* ) */ statement_or_null STAR_44 OPT_159 
    {
        struct ast_conditional_statement *ret = new (struct ast_conditional_statement);
        $$ = ret;
    }
    ;

unique_priority 
    : TOKEN_81 /* unique */ 
    {
        struct ast_unique_priority *ret = new (struct ast_unique_priority);
        $$ = ret;
    }
    | TOKEN_320 /* unique0 */ 
    {
        struct ast_unique_priority *ret = new (struct ast_unique_priority);
        $$ = ret;
    }
    | TOKEN_321 /* priority */ 
    {
        struct ast_unique_priority *ret = new (struct ast_unique_priority);
        $$ = ret;
    }
    ;

cond_predicate 
    : LIST_124 
    {
        struct ast_cond_predicate *ret = new (struct ast_cond_predicate);
        $$ = ret;
    }
    ;

expression_or_cond_pattern 
    : expression 
    {
        struct ast_expression_or_cond_pattern *ret = new (struct ast_expression_or_cond_pattern);
        $$ = ret;
    }
    | cond_pattern 
    {
        struct ast_expression_or_cond_pattern *ret = new (struct ast_expression_or_cond_pattern);
        $$ = ret;
    }
    ;

cond_pattern 
    : expression TOKEN_233 /* matches */ pattern 
    {
        struct ast_cond_pattern *ret = new (struct ast_cond_pattern);
        $$ = ret;
    }
    ;

case_statement 
    : OPT_158 case_keyword TOKEN_12 /* ( */ case_expression TOKEN_14 /* ) */ LIST_125 TOKEN_184 /* endcase */ 
    {
        struct ast_case_statement *ret = new (struct ast_case_statement);
        $$ = ret;
    }
    | OPT_158 case_keyword TOKEN_12 /* ( */ case_expression TOKEN_14 /* ) */ TOKEN_233 /* matches */ LIST_126 TOKEN_184 /* endcase */ 
    {
        struct ast_case_statement *ret = new (struct ast_case_statement);
        $$ = ret;
    }
    | OPT_158 TOKEN_183 /* case */ TOKEN_12 /* ( */ case_expression TOKEN_14 /* ) */ TOKEN_323 /* inside */ LIST_127 TOKEN_184 /* endcase */ 
    {
        struct ast_case_statement *ret = new (struct ast_case_statement);
        $$ = ret;
    }
    ;

case_keyword 
    : TOKEN_183 /* case */ 
    {
        struct ast_case_keyword *ret = new (struct ast_case_keyword);
        $$ = ret;
    }
    | TOKEN_324 /* casex */ 
    {
        struct ast_case_keyword *ret = new (struct ast_case_keyword);
        $$ = ret;
    }
    | TOKEN_325 /* casez */ 
    {
        struct ast_case_keyword *ret = new (struct ast_case_keyword);
        $$ = ret;
    }
    ;

case_expression 
    : expression 
    {
        struct ast_case_expression *ret = new (struct ast_case_expression);
        $$ = ret;
    }
    ;

case_item 
    : LIST_128 TOKEN_6 /* : */ statement_or_null 
    {
        struct ast_case_item *ret = new (struct ast_case_item);
        $$ = ret;
    }
    | TOKEN_46 /* default */ OPT_102 statement_or_null 
    {
        struct ast_case_item *ret = new (struct ast_case_item);
        $$ = ret;
    }
    ;

case_pattern_item 
    : pattern OPT_160 TOKEN_6 /* : */ statement_or_null 
    {
        struct ast_case_pattern_item *ret = new (struct ast_case_pattern_item);
        $$ = ret;
    }
    | TOKEN_46 /* default */ OPT_102 statement_or_null 
    {
        struct ast_case_pattern_item *ret = new (struct ast_case_pattern_item);
        $$ = ret;
    }
    ;

case_inside_item 
    : open_range_list TOKEN_6 /* : */ statement_or_null 
    {
        struct ast_case_inside_item *ret = new (struct ast_case_inside_item);
        $$ = ret;
    }
    | TOKEN_46 /* default */ OPT_102 statement_or_null 
    {
        struct ast_case_inside_item *ret = new (struct ast_case_inside_item);
        $$ = ret;
    }
    ;

case_item_expression 
    : expression 
    {
        struct ast_case_item_expression *ret = new (struct ast_case_item_expression);
        $$ = ret;
    }
    ;

randcase_statement 
    : TOKEN_326 /* randcase */ LIST_129 TOKEN_184 /* endcase */ 
    {
        struct ast_randcase_statement *ret = new (struct ast_randcase_statement);
        $$ = ret;
    }
    ;

randcase_item 
    : expression TOKEN_6 /* : */ statement_or_null 
    {
        struct ast_randcase_item *ret = new (struct ast_randcase_item);
        $$ = ret;
    }
    ;

open_range_list 
    : LIST_130 
    {
        struct ast_open_range_list *ret = new (struct ast_open_range_list);
        $$ = ret;
    }
    ;

open_value_range 
    : value_range 
    {
        struct ast_open_value_range *ret = new (struct ast_open_value_range);
        $$ = ret;
    }
    ;

pattern 
    : TOKEN_31 /* . */ variable_identifier 
    {
        struct ast_pattern *ret = new (struct ast_pattern);
        $$ = ret;
    }
    | TOKEN_31 /* . */ TOKEN_90 /* * */ 
    {
        struct ast_pattern *ret = new (struct ast_pattern);
        $$ = ret;
    }
    | constant_expression 
    {
        struct ast_pattern *ret = new (struct ast_pattern);
        $$ = ret;
    }
    | TOKEN_135 /* tagged */ member_identifier OPT_161 
    {
        struct ast_pattern *ret = new (struct ast_pattern);
        $$ = ret;
    }
    | TOKEN_327 /* ' */ TOKEN_32 /* { */ LIST_131 TOKEN_33 /* } */ 
    {
        struct ast_pattern *ret = new (struct ast_pattern);
        $$ = ret;
    }
    | TOKEN_327 /* ' */ TOKEN_32 /* { */ LIST_132 TOKEN_33 /* } */ 
    {
        struct ast_pattern *ret = new (struct ast_pattern);
        $$ = ret;
    }
    ;

assignment_pattern 
    : TOKEN_327 /* ' */ TOKEN_32 /* { */ LIST_133 TOKEN_33 /* } */ 
    {
        struct ast_assignment_pattern *ret = new (struct ast_assignment_pattern);
        $$ = ret;
    }
    | TOKEN_327 /* ' */ TOKEN_32 /* { */ LIST_134 TOKEN_33 /* } */ 
    {
        struct ast_assignment_pattern *ret = new (struct ast_assignment_pattern);
        $$ = ret;
    }
    | TOKEN_327 /* ' */ TOKEN_32 /* { */ LIST_135 TOKEN_33 /* } */ 
    {
        struct ast_assignment_pattern *ret = new (struct ast_assignment_pattern);
        $$ = ret;
    }
    | TOKEN_327 /* ' */ TOKEN_32 /* { */ constant_expression TOKEN_32 /* { */ LIST_133 TOKEN_33 /* } */ TOKEN_33 /* } */ 
    {
        struct ast_assignment_pattern *ret = new (struct ast_assignment_pattern);
        $$ = ret;
    }
    ;

structure_pattern_key 
    : member_identifier 
    {
        struct ast_structure_pattern_key *ret = new (struct ast_structure_pattern_key);
        $$ = ret;
    }
    | assignment_pattern_key 
    {
        struct ast_structure_pattern_key *ret = new (struct ast_structure_pattern_key);
        $$ = ret;
    }
    ;

array_pattern_key 
    : constant_expression 
    {
        struct ast_array_pattern_key *ret = new (struct ast_array_pattern_key);
        $$ = ret;
    }
    | assignment_pattern_key 
    {
        struct ast_array_pattern_key *ret = new (struct ast_array_pattern_key);
        $$ = ret;
    }
    ;

assignment_pattern_key 
    : simple_type 
    {
        struct ast_assignment_pattern_key *ret = new (struct ast_assignment_pattern_key);
        $$ = ret;
    }
    | TOKEN_46 /* default */ 
    {
        struct ast_assignment_pattern_key *ret = new (struct ast_assignment_pattern_key);
        $$ = ret;
    }
    ;

assignment_pattern_expression 
    : OPT_162 assignment_pattern 
    {
        struct ast_assignment_pattern_expression *ret = new (struct ast_assignment_pattern_expression);
        $$ = ret;
    }
    ;

assignment_pattern_expression_type 
    : ps_type_identifier 
    {
        struct ast_assignment_pattern_expression_type *ret = new (struct ast_assignment_pattern_expression_type);
        $$ = ret;
    }
    | ps_parameter_identifier 
    {
        struct ast_assignment_pattern_expression_type *ret = new (struct ast_assignment_pattern_expression_type);
        $$ = ret;
    }
    | integer_atom_type 
    {
        struct ast_assignment_pattern_expression_type *ret = new (struct ast_assignment_pattern_expression_type);
        $$ = ret;
    }
    | type_reference 
    {
        struct ast_assignment_pattern_expression_type *ret = new (struct ast_assignment_pattern_expression_type);
        $$ = ret;
    }
    ;

constant_assignment_pattern_expression 
    : assignment_pattern_expression 
    {
        struct ast_constant_assignment_pattern_expression *ret = new (struct ast_constant_assignment_pattern_expression);
        $$ = ret;
    }
    ;

assignment_pattern_net_lvalue 
    : TOKEN_327 /* ' */ TOKEN_32 /* { */ LIST_136 TOKEN_33 /* } */ 
    {
        struct ast_assignment_pattern_net_lvalue *ret = new (struct ast_assignment_pattern_net_lvalue);
        $$ = ret;
    }
    ;

assignment_pattern_variable_lvalue 
    : TOKEN_327 /* ' */ TOKEN_32 /* { */ LIST_137 TOKEN_33 /* } */ 
    {
        struct ast_assignment_pattern_variable_lvalue *ret = new (struct ast_assignment_pattern_variable_lvalue);
        $$ = ret;
    }
    ;

loop_statement 
    : TOKEN_328 /* forever */ statement_or_null 
    {
        struct ast_loop_statement *ret = new (struct ast_loop_statement);
        $$ = ret;
    }
    | TOKEN_312 /* repeat */ TOKEN_12 /* ( */ expression TOKEN_14 /* ) */ statement_or_null 
    {
        struct ast_loop_statement *ret = new (struct ast_loop_statement);
        $$ = ret;
    }
    | TOKEN_329 /* while */ TOKEN_12 /* ( */ expression TOKEN_14 /* ) */ statement_or_null 
    {
        struct ast_loop_statement *ret = new (struct ast_loop_statement);
        $$ = ret;
    }
    | TOKEN_260 /* for */ TOKEN_12 /* ( */ OPT_163 TOKEN_0 /* ; */ OPT_26 TOKEN_0 /* ; */ OPT_164 TOKEN_14 /* ) */ statement_or_null 
    {
        struct ast_loop_statement *ret = new (struct ast_loop_statement);
        $$ = ret;
    }
    | TOKEN_330 /* do */ statement_or_null TOKEN_329 /* while */ TOKEN_12 /* ( */ expression TOKEN_14 /* ) */ TOKEN_0 /* ; */ 
    {
        struct ast_loop_statement *ret = new (struct ast_loop_statement);
        $$ = ret;
    }
    | TOKEN_78 /* foreach */ TOKEN_12 /* ( */ ps_or_hierarchical_array_identifier TOKEN_79 /* [ */ loop_variables TOKEN_80 /* ] */ TOKEN_14 /* ) */ statement 
    {
        struct ast_loop_statement *ret = new (struct ast_loop_statement);
        $$ = ret;
    }
    ;

for_initialization 
    : list_of_variable_assignments 
    {
        struct ast_for_initialization *ret = new (struct ast_for_initialization);
        $$ = ret;
    }
    | LIST_138 
    {
        struct ast_for_initialization *ret = new (struct ast_for_initialization);
        $$ = ret;
    }
    ;

for_variable_declaration 
    : OPT_52 LIST_139 
    {
        struct ast_for_variable_declaration *ret = new (struct ast_for_variable_declaration);
        $$ = ret;
    }
    ;

for_step 
    : LIST_140 
    {
        struct ast_for_step *ret = new (struct ast_for_step);
        $$ = ret;
    }
    ;

for_step_assignment 
    : operator_assignment 
    {
        struct ast_for_step_assignment *ret = new (struct ast_for_step_assignment);
        $$ = ret;
    }
    | inc_or_dec_expression 
    {
        struct ast_for_step_assignment *ret = new (struct ast_for_step_assignment);
        $$ = ret;
    }
    | function_subroutine_call 
    {
        struct ast_for_step_assignment *ret = new (struct ast_for_step_assignment);
        $$ = ret;
    }
    ;

loop_variables 
    : LIST_141 
    {
        struct ast_loop_variables *ret = new (struct ast_loop_variables);
        $$ = ret;
    }
    ;

subroutine_call_statement 
    : subroutine_call TOKEN_0 /* ; */ 
    {
        struct ast_subroutine_call_statement *ret = new (struct ast_subroutine_call_statement);
        $$ = ret;
    }
    | TOKEN_134 /* void */ TOKEN_327 /* ' */ TOKEN_12 /* ( */ function_subroutine_call TOKEN_14 /* ) */ TOKEN_0 /* ; */ 
    {
        struct ast_subroutine_call_statement *ret = new (struct ast_subroutine_call_statement);
        $$ = ret;
    }
    ;

assertion_item 
    : concurrent_assertion_item 
    {
        struct ast_assertion_item *ret = new (struct ast_assertion_item);
        $$ = ret;
    }
    | deferred_immediate_assertion_item 
    {
        struct ast_assertion_item *ret = new (struct ast_assertion_item);
        $$ = ret;
    }
    ;

deferred_immediate_assertion_item 
    : OPT_89 deferred_immediate_assertion_statement 
    {
        struct ast_deferred_immediate_assertion_item *ret = new (struct ast_deferred_immediate_assertion_item);
        $$ = ret;
    }
    ;

procedural_assertion_statement 
    : concurrent_assertion_statement 
    {
        struct ast_procedural_assertion_statement *ret = new (struct ast_procedural_assertion_statement);
        $$ = ret;
    }
    | immediate_assertion_statement 
    {
        struct ast_procedural_assertion_statement *ret = new (struct ast_procedural_assertion_statement);
        $$ = ret;
    }
    | checker_instantiation 
    {
        struct ast_procedural_assertion_statement *ret = new (struct ast_procedural_assertion_statement);
        $$ = ret;
    }
    ;

immediate_assertion_statement 
    : simple_immediate_assertion_statement 
    {
        struct ast_immediate_assertion_statement *ret = new (struct ast_immediate_assertion_statement);
        $$ = ret;
    }
    | deferred_immediate_assertion_statement 
    {
        struct ast_immediate_assertion_statement *ret = new (struct ast_immediate_assertion_statement);
        $$ = ret;
    }
    ;

simple_immediate_assertion_statement 
    : simple_immediate_assert_statement 
    {
        struct ast_simple_immediate_assertion_statement *ret = new (struct ast_simple_immediate_assertion_statement);
        $$ = ret;
    }
    | simple_immediate_assume_statement 
    {
        struct ast_simple_immediate_assertion_statement *ret = new (struct ast_simple_immediate_assertion_statement);
        $$ = ret;
    }
    | simple_immediate_cover_statement 
    {
        struct ast_simple_immediate_assertion_statement *ret = new (struct ast_simple_immediate_assertion_statement);
        $$ = ret;
    }
    ;

simple_immediate_assert_statement 
    : TOKEN_168 /* assert */ TOKEN_12 /* ( */ expression TOKEN_14 /* ) */ action_block 
    {
        struct ast_simple_immediate_assert_statement *ret = new (struct ast_simple_immediate_assert_statement);
        $$ = ret;
    }
    ;

simple_immediate_assume_statement 
    : TOKEN_170 /* assume */ TOKEN_12 /* ( */ expression TOKEN_14 /* ) */ action_block 
    {
        struct ast_simple_immediate_assume_statement *ret = new (struct ast_simple_immediate_assume_statement);
        $$ = ret;
    }
    ;

simple_immediate_cover_statement 
    : TOKEN_171 /* cover */ TOKEN_12 /* ( */ expression TOKEN_14 /* ) */ action_block 
    {
        struct ast_simple_immediate_cover_statement *ret = new (struct ast_simple_immediate_cover_statement);
        $$ = ret;
    }
    ;

deferred_immediate_assertion_statement 
    : deferred_immediate_assert_statement 
    {
        struct ast_deferred_immediate_assertion_statement *ret = new (struct ast_deferred_immediate_assertion_statement);
        $$ = ret;
    }
    | deferred_immediate_assume_statement 
    {
        struct ast_deferred_immediate_assertion_statement *ret = new (struct ast_deferred_immediate_assertion_statement);
        $$ = ret;
    }
    | deferred_immediate_cover_statement 
    {
        struct ast_deferred_immediate_assertion_statement *ret = new (struct ast_deferred_immediate_assertion_statement);
        $$ = ret;
    }
    ;

deferred_immediate_assert_statement 
    : TOKEN_168 /* assert */ TOKEN_331 /* #0 */ TOKEN_12 /* ( */ expression TOKEN_14 /* ) */ action_block 
    {
        struct ast_deferred_immediate_assert_statement *ret = new (struct ast_deferred_immediate_assert_statement);
        $$ = ret;
    }
    | TOKEN_168 /* assert */ TOKEN_292 /* final */ TOKEN_12 /* ( */ expression TOKEN_14 /* ) */ action_block 
    {
        struct ast_deferred_immediate_assert_statement *ret = new (struct ast_deferred_immediate_assert_statement);
        $$ = ret;
    }
    ;

deferred_immediate_assume_statement 
    : TOKEN_170 /* assume */ TOKEN_331 /* #0 */ TOKEN_12 /* ( */ expression TOKEN_14 /* ) */ action_block 
    {
        struct ast_deferred_immediate_assume_statement *ret = new (struct ast_deferred_immediate_assume_statement);
        $$ = ret;
    }
    | TOKEN_170 /* assume */ TOKEN_292 /* final */ TOKEN_12 /* ( */ expression TOKEN_14 /* ) */ action_block 
    {
        struct ast_deferred_immediate_assume_statement *ret = new (struct ast_deferred_immediate_assume_statement);
        $$ = ret;
    }
    ;

deferred_immediate_cover_statement 
    : TOKEN_171 /* cover */ TOKEN_331 /* #0 */ TOKEN_12 /* ( */ expression TOKEN_14 /* ) */ statement_or_null 
    {
        struct ast_deferred_immediate_cover_statement *ret = new (struct ast_deferred_immediate_cover_statement);
        $$ = ret;
    }
    | TOKEN_171 /* cover */ TOKEN_292 /* final */ TOKEN_12 /* ( */ expression TOKEN_14 /* ) */ statement_or_null 
    {
        struct ast_deferred_immediate_cover_statement *ret = new (struct ast_deferred_immediate_cover_statement);
        $$ = ret;
    }
    ;

clocking_declaration 
    : OPT_166 TOKEN_47 /* clocking */ OPT_167 clocking_event TOKEN_0 /* ; */ STAR_45 TOKEN_332 /* endclocking */ OPT_168 
    {
        struct ast_clocking_declaration *ret = new (struct ast_clocking_declaration);
        $$ = ret;
    }
    | TOKEN_333 /* global */ TOKEN_47 /* clocking */ OPT_167 clocking_event TOKEN_0 /* ; */ TOKEN_332 /* endclocking */ OPT_168 
    {
        struct ast_clocking_declaration *ret = new (struct ast_clocking_declaration);
        $$ = ret;
    }
    ;

clocking_event 
    : TOKEN_313 /* @ */ identifier 
    {
        struct ast_clocking_event *ret = new (struct ast_clocking_event);
        $$ = ret;
    }
    | TOKEN_313 /* @ */ TOKEN_12 /* ( */ event_expression TOKEN_14 /* ) */ 
    {
        struct ast_clocking_event *ret = new (struct ast_clocking_event);
        $$ = ret;
    }
    ;

clocking_item 
    : TOKEN_46 /* default */ default_skew TOKEN_0 /* ; */ 
    {
        struct ast_clocking_item *ret = new (struct ast_clocking_item);
        $$ = ret;
    }
    | clocking_direction list_of_clocking_decl_assign TOKEN_0 /* ; */ 
    {
        struct ast_clocking_item *ret = new (struct ast_clocking_item);
        $$ = ret;
    }
    | STAR_2 assertion_item_declaration 
    {
        struct ast_clocking_item *ret = new (struct ast_clocking_item);
        $$ = ret;
    }
    ;

default_skew 
    : TOKEN_34 /* input */ clocking_skew 
    {
        struct ast_default_skew *ret = new (struct ast_default_skew);
        $$ = ret;
    }
    | TOKEN_35 /* output */ clocking_skew 
    {
        struct ast_default_skew *ret = new (struct ast_default_skew);
        $$ = ret;
    }
    | TOKEN_34 /* input */ clocking_skew TOKEN_35 /* output */ clocking_skew 
    {
        struct ast_default_skew *ret = new (struct ast_default_skew);
        $$ = ret;
    }
    ;

clocking_direction 
    : TOKEN_34 /* input */ OPT_169 
    {
        struct ast_clocking_direction *ret = new (struct ast_clocking_direction);
        $$ = ret;
    }
    | TOKEN_35 /* output */ OPT_169 
    {
        struct ast_clocking_direction *ret = new (struct ast_clocking_direction);
        $$ = ret;
    }
    | TOKEN_34 /* input */ OPT_169 TOKEN_35 /* output */ OPT_169 
    {
        struct ast_clocking_direction *ret = new (struct ast_clocking_direction);
        $$ = ret;
    }
    | TOKEN_36 /* inout */ 
    {
        struct ast_clocking_direction *ret = new (struct ast_clocking_direction);
        $$ = ret;
    }
    ;

list_of_clocking_decl_assign 
    : LIST_143 
    {
        struct ast_list_of_clocking_decl_assign *ret = new (struct ast_list_of_clocking_decl_assign);
        $$ = ret;
    }
    ;

clocking_decl_assign 
    : signal_identifier OPT_73 
    {
        struct ast_clocking_decl_assign *ret = new (struct ast_clocking_decl_assign);
        $$ = ret;
    }
    ;

clocking_skew 
    : edge_identifier OPT_56 
    {
        struct ast_clocking_skew *ret = new (struct ast_clocking_skew);
        $$ = ret;
    }
    | delay_control 
    {
        struct ast_clocking_skew *ret = new (struct ast_clocking_skew);
        $$ = ret;
    }
    ;

clocking_drive 
    : clockvar_expression TOKEN_164 /* <= */ OPT_170 expression 
    {
        struct ast_clocking_drive *ret = new (struct ast_clocking_drive);
        $$ = ret;
    }
    ;

cycle_delay 
    : TOKEN_207 /* ## */ integral_number 
    {
        struct ast_cycle_delay *ret = new (struct ast_cycle_delay);
        $$ = ret;
    }
    | TOKEN_207 /* ## */ identifier 
    {
        struct ast_cycle_delay *ret = new (struct ast_cycle_delay);
        $$ = ret;
    }
    | TOKEN_207 /* ## */ TOKEN_12 /* ( */ expression TOKEN_14 /* ) */ 
    {
        struct ast_cycle_delay *ret = new (struct ast_cycle_delay);
        $$ = ret;
    }
    ;

clockvar 
    : hierarchical_identifier 
    {
        struct ast_clockvar *ret = new (struct ast_clockvar);
        $$ = ret;
    }
    ;

clockvar_expression 
    : clockvar select 
    {
        struct ast_clockvar_expression *ret = new (struct ast_clockvar_expression);
        $$ = ret;
    }
    ;

randsequence_statement 
    : TOKEN_334 /* randsequence */ TOKEN_12 /* ( */ OPT_171 TOKEN_14 /* ) */ LIST_144 TOKEN_201 /* endsequence */ 
    {
        struct ast_randsequence_statement *ret = new (struct ast_randsequence_statement);
        $$ = ret;
    }
    ;

production 
    : OPT_172 production_identifier OPT_173 TOKEN_6 /* : */ LIST_145 TOKEN_0 /* ; */ 
    {
        struct ast_production *ret = new (struct ast_production);
        $$ = ret;
    }
    ;

rs_rule 
    : rs_production_list OPT_175 
    {
        struct ast_rs_rule *ret = new (struct ast_rs_rule);
        $$ = ret;
    }
    ;

rs_production_list 
    : LIST_146 
    {
        struct ast_rs_production_list *ret = new (struct ast_rs_production_list);
        $$ = ret;
    }
    | TOKEN_60 /* rand */ TOKEN_309 /* join */ OPT_79 production_item LIST_147 
    {
        struct ast_rs_production_list *ret = new (struct ast_rs_production_list);
        $$ = ret;
    }
    ;

weight_specification 
    : integral_number 
    {
        struct ast_weight_specification *ret = new (struct ast_weight_specification);
        $$ = ret;
    }
    | ps_identifier 
    {
        struct ast_weight_specification *ret = new (struct ast_weight_specification);
        $$ = ret;
    }
    | TOKEN_12 /* ( */ expression TOKEN_14 /* ) */ 
    {
        struct ast_weight_specification *ret = new (struct ast_weight_specification);
        $$ = ret;
    }
    ;

rs_code_block 
    : TOKEN_32 /* { */ STAR_46 STAR_32 TOKEN_33 /* } */ 
    {
        struct ast_rs_code_block *ret = new (struct ast_rs_code_block);
        $$ = ret;
    }
    ;

rs_prod 
    : production_item 
    {
        struct ast_rs_prod *ret = new (struct ast_rs_prod);
        $$ = ret;
    }
    | rs_code_block 
    {
        struct ast_rs_prod *ret = new (struct ast_rs_prod);
        $$ = ret;
    }
    | rs_if_else 
    {
        struct ast_rs_prod *ret = new (struct ast_rs_prod);
        $$ = ret;
    }
    | rs_repeat 
    {
        struct ast_rs_prod *ret = new (struct ast_rs_prod);
        $$ = ret;
    }
    | rs_case 
    {
        struct ast_rs_prod *ret = new (struct ast_rs_prod);
        $$ = ret;
    }
    ;

production_item 
    : production_identifier OPT_12 
    {
        struct ast_production_item *ret = new (struct ast_production_item);
        $$ = ret;
    }
    ;

rs_if_else 
    : TOKEN_76 /* if */ TOKEN_12 /* ( */ expression TOKEN_14 /* ) */ production_item OPT_176 
    {
        struct ast_rs_if_else *ret = new (struct ast_rs_if_else);
        $$ = ret;
    }
    ;

rs_repeat 
    : TOKEN_312 /* repeat */ TOKEN_12 /* ( */ expression TOKEN_14 /* ) */ production_item 
    {
        struct ast_rs_repeat *ret = new (struct ast_rs_repeat);
        $$ = ret;
    }
    ;

rs_case 
    : TOKEN_183 /* case */ TOKEN_12 /* ( */ case_expression TOKEN_14 /* ) */ LIST_149 TOKEN_184 /* endcase */ 
    {
        struct ast_rs_case *ret = new (struct ast_rs_case);
        $$ = ret;
    }
    ;

rs_case_item 
    : LIST_128 TOKEN_6 /* : */ production_item TOKEN_0 /* ; */ 
    {
        struct ast_rs_case_item *ret = new (struct ast_rs_case_item);
        $$ = ret;
    }
    | TOKEN_46 /* default */ OPT_102 production_item TOKEN_0 /* ; */ 
    {
        struct ast_rs_case_item *ret = new (struct ast_rs_case_item);
        $$ = ret;
    }
    ;

specify_block 
    : TOKEN_336 /* specify */ STAR_47 TOKEN_337 /* endspecify */ 
    {
        struct ast_specify_block *ret = new (struct ast_specify_block);
        $$ = ret;
    }
    ;

specify_item 
    : specparam_declaration 
    {
        struct ast_specify_item *ret = new (struct ast_specify_item);
        $$ = ret;
    }
    | pulsestyle_declaration 
    {
        struct ast_specify_item *ret = new (struct ast_specify_item);
        $$ = ret;
    }
    | showcancelled_declaration 
    {
        struct ast_specify_item *ret = new (struct ast_specify_item);
        $$ = ret;
    }
    | path_declaration 
    {
        struct ast_specify_item *ret = new (struct ast_specify_item);
        $$ = ret;
    }
    | system_timing_check 
    {
        struct ast_specify_item *ret = new (struct ast_specify_item);
        $$ = ret;
    }
    ;

pulsestyle_declaration 
    : TOKEN_338 /* pulsestyle_onevent */ list_of_path_outputs TOKEN_0 /* ; */ 
    {
        struct ast_pulsestyle_declaration *ret = new (struct ast_pulsestyle_declaration);
        $$ = ret;
    }
    | TOKEN_339 /* pulsestyle_ondetect */ list_of_path_outputs TOKEN_0 /* ; */ 
    {
        struct ast_pulsestyle_declaration *ret = new (struct ast_pulsestyle_declaration);
        $$ = ret;
    }
    ;

showcancelled_declaration 
    : TOKEN_340 /* showcancelled */ list_of_path_outputs TOKEN_0 /* ; */ 
    {
        struct ast_showcancelled_declaration *ret = new (struct ast_showcancelled_declaration);
        $$ = ret;
    }
    | TOKEN_341 /* noshowcancelled */ list_of_path_outputs TOKEN_0 /* ; */ 
    {
        struct ast_showcancelled_declaration *ret = new (struct ast_showcancelled_declaration);
        $$ = ret;
    }
    ;

path_declaration 
    : simple_path_declaration TOKEN_0 /* ; */ 
    {
        struct ast_path_declaration *ret = new (struct ast_path_declaration);
        $$ = ret;
    }
    | edge_sensitive_path_declaration TOKEN_0 /* ; */ 
    {
        struct ast_path_declaration *ret = new (struct ast_path_declaration);
        $$ = ret;
    }
    | state_dependent_path_declaration TOKEN_0 /* ; */ 
    {
        struct ast_path_declaration *ret = new (struct ast_path_declaration);
        $$ = ret;
    }
    ;

simple_path_declaration 
    : parallel_path_description TOKEN_38 /* = */ path_delay_value 
    {
        struct ast_simple_path_declaration *ret = new (struct ast_simple_path_declaration);
        $$ = ret;
    }
    | full_path_description TOKEN_38 /* = */ path_delay_value 
    {
        struct ast_simple_path_declaration *ret = new (struct ast_simple_path_declaration);
        $$ = ret;
    }
    ;

parallel_path_description 
    : TOKEN_12 /* ( */ specify_input_terminal_descriptor OPT_177 TOKEN_228 /* => */ specify_output_terminal_descriptor TOKEN_14 /* ) */ 
    {
        struct ast_parallel_path_description *ret = new (struct ast_parallel_path_description);
        $$ = ret;
    }
    ;

full_path_description 
    : TOKEN_12 /* ( */ list_of_path_inputs OPT_177 TOKEN_342 /* *> */ list_of_path_outputs TOKEN_14 /* ) */ 
    {
        struct ast_full_path_description *ret = new (struct ast_full_path_description);
        $$ = ret;
    }
    ;

list_of_path_inputs 
    : LIST_151 
    {
        struct ast_list_of_path_inputs *ret = new (struct ast_list_of_path_inputs);
        $$ = ret;
    }
    ;

list_of_path_outputs 
    : LIST_152 
    {
        struct ast_list_of_path_outputs *ret = new (struct ast_list_of_path_outputs);
        $$ = ret;
    }
    ;

specify_input_terminal_descriptor 
    : input_identifier OPT_178 
    {
        struct ast_specify_input_terminal_descriptor *ret = new (struct ast_specify_input_terminal_descriptor);
        $$ = ret;
    }
    ;

specify_output_terminal_descriptor 
    : output_identifier OPT_178 
    {
        struct ast_specify_output_terminal_descriptor *ret = new (struct ast_specify_output_terminal_descriptor);
        $$ = ret;
    }
    ;

input_identifier 
    : input_port_identifier 
    {
        struct ast_input_identifier *ret = new (struct ast_input_identifier);
        $$ = ret;
    }
    | inout_port_identifier 
    {
        struct ast_input_identifier *ret = new (struct ast_input_identifier);
        $$ = ret;
    }
    | interface_identifier TOKEN_31 /* . */ port_identifier 
    {
        struct ast_input_identifier *ret = new (struct ast_input_identifier);
        $$ = ret;
    }
    ;

output_identifier 
    : output_port_identifier 
    {
        struct ast_output_identifier *ret = new (struct ast_output_identifier);
        $$ = ret;
    }
    | inout_port_identifier 
    {
        struct ast_output_identifier *ret = new (struct ast_output_identifier);
        $$ = ret;
    }
    | interface_identifier TOKEN_31 /* . */ port_identifier 
    {
        struct ast_output_identifier *ret = new (struct ast_output_identifier);
        $$ = ret;
    }
    ;

path_delay_value 
    : list_of_path_delay_expressions 
    {
        struct ast_path_delay_value *ret = new (struct ast_path_delay_value);
        $$ = ret;
    }
    | TOKEN_12 /* ( */ list_of_path_delay_expressions TOKEN_14 /* ) */ 
    {
        struct ast_path_delay_value *ret = new (struct ast_path_delay_value);
        $$ = ret;
    }
    ;

list_of_path_delay_expressions 
    : t_path_delay_expression 
    {
        struct ast_list_of_path_delay_expressions *ret = new (struct ast_list_of_path_delay_expressions);
        $$ = ret;
    }
    | trise_path_delay_expression TOKEN_2 /* , */ tfall_path_delay_expression 
    {
        struct ast_list_of_path_delay_expressions *ret = new (struct ast_list_of_path_delay_expressions);
        $$ = ret;
    }
    | trise_path_delay_expression TOKEN_2 /* , */ tfall_path_delay_expression TOKEN_2 /* , */ tz_path_delay_expression 
    {
        struct ast_list_of_path_delay_expressions *ret = new (struct ast_list_of_path_delay_expressions);
        $$ = ret;
    }
    | t01_path_delay_expression TOKEN_2 /* , */ t10_path_delay_expression TOKEN_2 /* , */ t0z_path_delay_expression TOKEN_2 /* , */ tz1_path_delay_expression TOKEN_2 /* , */ t1z_path_delay_expression TOKEN_2 /* , */ tz0_path_delay_expression 
    {
        struct ast_list_of_path_delay_expressions *ret = new (struct ast_list_of_path_delay_expressions);
        $$ = ret;
    }
    | t01_path_delay_expression TOKEN_2 /* , */ t10_path_delay_expression TOKEN_2 /* , */ t0z_path_delay_expression TOKEN_2 /* , */ tz1_path_delay_expression TOKEN_2 /* , */ t1z_path_delay_expression TOKEN_2 /* , */ tz0_path_delay_expression TOKEN_2 /* , */ t0x_path_delay_expression TOKEN_2 /* , */ tx1_path_delay_expression TOKEN_2 /* , */ t1x_path_delay_expression TOKEN_2 /* , */ tx0_path_delay_expression TOKEN_2 /* , */ txz_path_delay_expression TOKEN_2 /* , */ tzx_path_delay_expression 
    {
        struct ast_list_of_path_delay_expressions *ret = new (struct ast_list_of_path_delay_expressions);
        $$ = ret;
    }
    ;

t_path_delay_expression 
    : path_delay_expression 
    {
        struct ast_t_path_delay_expression *ret = new (struct ast_t_path_delay_expression);
        $$ = ret;
    }
    ;

trise_path_delay_expression 
    : path_delay_expression 
    {
        struct ast_trise_path_delay_expression *ret = new (struct ast_trise_path_delay_expression);
        $$ = ret;
    }
    ;

tfall_path_delay_expression 
    : path_delay_expression 
    {
        struct ast_tfall_path_delay_expression *ret = new (struct ast_tfall_path_delay_expression);
        $$ = ret;
    }
    ;

tz_path_delay_expression 
    : path_delay_expression 
    {
        struct ast_tz_path_delay_expression *ret = new (struct ast_tz_path_delay_expression);
        $$ = ret;
    }
    ;

t01_path_delay_expression 
    : path_delay_expression 
    {
        struct ast_t01_path_delay_expression *ret = new (struct ast_t01_path_delay_expression);
        $$ = ret;
    }
    ;

t10_path_delay_expression 
    : path_delay_expression 
    {
        struct ast_t10_path_delay_expression *ret = new (struct ast_t10_path_delay_expression);
        $$ = ret;
    }
    ;

t0z_path_delay_expression 
    : path_delay_expression 
    {
        struct ast_t0z_path_delay_expression *ret = new (struct ast_t0z_path_delay_expression);
        $$ = ret;
    }
    ;

tz1_path_delay_expression 
    : path_delay_expression 
    {
        struct ast_tz1_path_delay_expression *ret = new (struct ast_tz1_path_delay_expression);
        $$ = ret;
    }
    ;

t1z_path_delay_expression 
    : path_delay_expression 
    {
        struct ast_t1z_path_delay_expression *ret = new (struct ast_t1z_path_delay_expression);
        $$ = ret;
    }
    ;

tz0_path_delay_expression 
    : path_delay_expression 
    {
        struct ast_tz0_path_delay_expression *ret = new (struct ast_tz0_path_delay_expression);
        $$ = ret;
    }
    ;

t0x_path_delay_expression 
    : path_delay_expression 
    {
        struct ast_t0x_path_delay_expression *ret = new (struct ast_t0x_path_delay_expression);
        $$ = ret;
    }
    ;

tx1_path_delay_expression 
    : path_delay_expression 
    {
        struct ast_tx1_path_delay_expression *ret = new (struct ast_tx1_path_delay_expression);
        $$ = ret;
    }
    ;

t1x_path_delay_expression 
    : path_delay_expression 
    {
        struct ast_t1x_path_delay_expression *ret = new (struct ast_t1x_path_delay_expression);
        $$ = ret;
    }
    ;

tx0_path_delay_expression 
    : path_delay_expression 
    {
        struct ast_tx0_path_delay_expression *ret = new (struct ast_tx0_path_delay_expression);
        $$ = ret;
    }
    ;

txz_path_delay_expression 
    : path_delay_expression 
    {
        struct ast_txz_path_delay_expression *ret = new (struct ast_txz_path_delay_expression);
        $$ = ret;
    }
    ;

tzx_path_delay_expression 
    : path_delay_expression 
    {
        struct ast_tzx_path_delay_expression *ret = new (struct ast_tzx_path_delay_expression);
        $$ = ret;
    }
    ;

path_delay_expression 
    : constant_mintypmax_expression 
    {
        struct ast_path_delay_expression *ret = new (struct ast_path_delay_expression);
        $$ = ret;
    }
    ;

edge_sensitive_path_declaration 
    : parallel_edge_sensitive_path_description TOKEN_38 /* = */ path_delay_value 
    {
        struct ast_edge_sensitive_path_declaration *ret = new (struct ast_edge_sensitive_path_declaration);
        $$ = ret;
    }
    | full_edge_sensitive_path_description TOKEN_38 /* = */ path_delay_value 
    {
        struct ast_edge_sensitive_path_declaration *ret = new (struct ast_edge_sensitive_path_declaration);
        $$ = ret;
    }
    ;

parallel_edge_sensitive_path_description 
    : TOKEN_12 /* ( */ OPT_156 specify_input_terminal_descriptor OPT_177 TOKEN_228 /* => */ TOKEN_12 /* ( */ specify_output_terminal_descriptor OPT_177 TOKEN_6 /* : */ data_source_expression TOKEN_14 /* ) */ TOKEN_14 /* ) */ 
    {
        struct ast_parallel_edge_sensitive_path_description *ret = new (struct ast_parallel_edge_sensitive_path_description);
        $$ = ret;
    }
    ;

full_edge_sensitive_path_description 
    : TOKEN_12 /* ( */ OPT_156 list_of_path_inputs OPT_177 TOKEN_342 /* *> */ TOKEN_12 /* ( */ list_of_path_outputs OPT_177 TOKEN_6 /* : */ data_source_expression TOKEN_14 /* ) */ TOKEN_14 /* ) */ 
    {
        struct ast_full_edge_sensitive_path_description *ret = new (struct ast_full_edge_sensitive_path_description);
        $$ = ret;
    }
    ;

data_source_expression 
    : expression 
    {
        struct ast_data_source_expression *ret = new (struct ast_data_source_expression);
        $$ = ret;
    }
    ;

edge_identifier 
    : TOKEN_343 /* posedge */ 
    {
        struct ast_edge_identifier *ret = new (struct ast_edge_identifier);
        $$ = ret;
    }
    | TOKEN_344 /* negedge */ 
    {
        struct ast_edge_identifier *ret = new (struct ast_edge_identifier);
        $$ = ret;
    }
    | TOKEN_345 /* edge */ 
    {
        struct ast_edge_identifier *ret = new (struct ast_edge_identifier);
        $$ = ret;
    }
    ;

state_dependent_path_declaration 
    : TOKEN_76 /* if */ TOKEN_12 /* ( */ module_path_expression TOKEN_14 /* ) */ simple_path_declaration 
    {
        struct ast_state_dependent_path_declaration *ret = new (struct ast_state_dependent_path_declaration);
        $$ = ret;
    }
    | TOKEN_76 /* if */ TOKEN_12 /* ( */ module_path_expression TOKEN_14 /* ) */ edge_sensitive_path_declaration 
    {
        struct ast_state_dependent_path_declaration *ret = new (struct ast_state_dependent_path_declaration);
        $$ = ret;
    }
    | TOKEN_346 /* ifnone */ simple_path_declaration 
    {
        struct ast_state_dependent_path_declaration *ret = new (struct ast_state_dependent_path_declaration);
        $$ = ret;
    }
    ;

polarity_operator 
    : TOKEN_155 /* + */ 
    {
        struct ast_polarity_operator *ret = new (struct ast_polarity_operator);
        $$ = ret;
    }
    | TOKEN_157 /* - */ 
    {
        struct ast_polarity_operator *ret = new (struct ast_polarity_operator);
        $$ = ret;
    }
    ;

system_timing_check 
    : dollarsign_setup_timing_check 
    {
        struct ast_system_timing_check *ret = new (struct ast_system_timing_check);
        $$ = ret;
    }
    | dollarsign_hold_timing_check 
    {
        struct ast_system_timing_check *ret = new (struct ast_system_timing_check);
        $$ = ret;
    }
    | dollarsign_setuphold_timing_check 
    {
        struct ast_system_timing_check *ret = new (struct ast_system_timing_check);
        $$ = ret;
    }
    | dollarsign_recovery_timing_check 
    {
        struct ast_system_timing_check *ret = new (struct ast_system_timing_check);
        $$ = ret;
    }
    | dollarsign_removal_timing_check 
    {
        struct ast_system_timing_check *ret = new (struct ast_system_timing_check);
        $$ = ret;
    }
    | dollarsign_recrem_timing_check 
    {
        struct ast_system_timing_check *ret = new (struct ast_system_timing_check);
        $$ = ret;
    }
    | dollarsign_skew_timing_check 
    {
        struct ast_system_timing_check *ret = new (struct ast_system_timing_check);
        $$ = ret;
    }
    | dollarsign_timeskew_timing_check 
    {
        struct ast_system_timing_check *ret = new (struct ast_system_timing_check);
        $$ = ret;
    }
    | dollarsign_fullskew_timing_check 
    {
        struct ast_system_timing_check *ret = new (struct ast_system_timing_check);
        $$ = ret;
    }
    | dollarsign_period_timing_check 
    {
        struct ast_system_timing_check *ret = new (struct ast_system_timing_check);
        $$ = ret;
    }
    | dollarsign_width_timing_check 
    {
        struct ast_system_timing_check *ret = new (struct ast_system_timing_check);
        $$ = ret;
    }
    | dollarsign_nochange_timing_check 
    {
        struct ast_system_timing_check *ret = new (struct ast_system_timing_check);
        $$ = ret;
    }
    ;

dollarsign_setup_timing_check 
    : TOKEN_347 /* dollarsign_setup */ TOKEN_12 /* ( */ data_event TOKEN_2 /* , */ reference_event TOKEN_2 /* , */ timing_check_limit OPT_180 TOKEN_14 /* ) */ TOKEN_0 /* ; */ 
    {
        struct ast_dollarsign_setup_timing_check *ret = new (struct ast_dollarsign_setup_timing_check);
        $$ = ret;
    }
    ;

dollarsign_hold_timing_check 
    : TOKEN_348 /* dollarsign_hold */ TOKEN_12 /* ( */ reference_event TOKEN_2 /* , */ data_event TOKEN_2 /* , */ timing_check_limit OPT_180 TOKEN_14 /* ) */ TOKEN_0 /* ; */ 
    {
        struct ast_dollarsign_hold_timing_check *ret = new (struct ast_dollarsign_hold_timing_check);
        $$ = ret;
    }
    ;

dollarsign_setuphold_timing_check 
    : TOKEN_349 /* dollarsign_setuphold */ TOKEN_12 /* ( */ reference_event TOKEN_2 /* , */ data_event TOKEN_2 /* , */ timing_check_limit TOKEN_2 /* , */ timing_check_limit OPT_189 TOKEN_14 /* ) */ TOKEN_0 /* ; */ 
    {
        struct ast_dollarsign_setuphold_timing_check *ret = new (struct ast_dollarsign_setuphold_timing_check);
        $$ = ret;
    }
    ;

dollarsign_recovery_timing_check 
    : TOKEN_350 /* dollarsign_recovery */ TOKEN_12 /* ( */ reference_event TOKEN_2 /* , */ data_event TOKEN_2 /* , */ timing_check_limit OPT_180 TOKEN_14 /* ) */ TOKEN_0 /* ; */ 
    {
        struct ast_dollarsign_recovery_timing_check *ret = new (struct ast_dollarsign_recovery_timing_check);
        $$ = ret;
    }
    ;

dollarsign_removal_timing_check 
    : TOKEN_351 /* dollarsign_removal */ TOKEN_12 /* ( */ reference_event TOKEN_2 /* , */ data_event TOKEN_2 /* , */ timing_check_limit OPT_180 TOKEN_14 /* ) */ TOKEN_0 /* ; */ 
    {
        struct ast_dollarsign_removal_timing_check *ret = new (struct ast_dollarsign_removal_timing_check);
        $$ = ret;
    }
    ;

dollarsign_recrem_timing_check 
    : TOKEN_352 /* dollarsign_recrem */ TOKEN_12 /* ( */ reference_event TOKEN_2 /* , */ data_event TOKEN_2 /* , */ TOKEN_14 /* ) */ TOKEN_0 /* ; */ 
    {
        struct ast_dollarsign_recrem_timing_check *ret = new (struct ast_dollarsign_recrem_timing_check);
        $$ = ret;
    }
    ;

dollarsign_skew_timing_check 
    : TOKEN_353 /* dollarsign_skew */ TOKEN_12 /* ( */ reference_event TOKEN_2 /* , */ data_event TOKEN_2 /* , */ timing_check_limit OPT_180 TOKEN_14 /* ) */ TOKEN_0 /* ; */ 
    {
        struct ast_dollarsign_skew_timing_check *ret = new (struct ast_dollarsign_skew_timing_check);
        $$ = ret;
    }
    ;

dollarsign_timeskew_timing_check 
    : TOKEN_354 /* dollarsign_timeskew */ TOKEN_12 /* ( */ reference_event TOKEN_2 /* , */ data_event TOKEN_2 /* , */ timing_check_limit OPT_194 TOKEN_14 /* ) */ TOKEN_0 /* ; */ 
    {
        struct ast_dollarsign_timeskew_timing_check *ret = new (struct ast_dollarsign_timeskew_timing_check);
        $$ = ret;
    }
    ;

dollarsign_fullskew_timing_check 
    : TOKEN_355 /* dollarsign_fullskew */ TOKEN_12 /* ( */ reference_event TOKEN_2 /* , */ data_event TOKEN_2 /* , */ timing_check_limit TOKEN_2 /* , */ timing_check_limit OPT_194 TOKEN_14 /* ) */ TOKEN_0 /* ; */ 
    {
        struct ast_dollarsign_fullskew_timing_check *ret = new (struct ast_dollarsign_fullskew_timing_check);
        $$ = ret;
    }
    ;

dollarsign_period_timing_check 
    : TOKEN_356 /* dollarsign_period */ TOKEN_12 /* ( */ TOKEN_14 /* ) */ TOKEN_0 /* ; */ 
    {
        struct ast_dollarsign_period_timing_check *ret = new (struct ast_dollarsign_period_timing_check);
        $$ = ret;
    }
    ;

dollarsign_width_timing_check 
    : TOKEN_357 /* dollarsign_width */ TOKEN_12 /* ( */ controlled_reference_event TOKEN_2 /* , */ timing_check_limit TOKEN_2 /* , */ threshold OPT_180 TOKEN_14 /* ) */ TOKEN_0 /* ; */ 
    {
        struct ast_dollarsign_width_timing_check *ret = new (struct ast_dollarsign_width_timing_check);
        $$ = ret;
    }
    ;

dollarsign_nochange_timing_check 
    : TOKEN_358 /* dollarsign_nochange */ TOKEN_12 /* ( */ reference_event TOKEN_2 /* , */ data_event TOKEN_2 /* , */ start_edge_offset TOKEN_2 /* , */ end_edge_offset OPT_180 TOKEN_14 /* ) */ TOKEN_0 /* ; */ 
    {
        struct ast_dollarsign_nochange_timing_check *ret = new (struct ast_dollarsign_nochange_timing_check);
        $$ = ret;
    }
    ;

timecheck_condition 
    : mintypmax_expression 
    {
        struct ast_timecheck_condition *ret = new (struct ast_timecheck_condition);
        $$ = ret;
    }
    ;

controlled_reference_event 
    : controlled_timing_check_event 
    {
        struct ast_controlled_reference_event *ret = new (struct ast_controlled_reference_event);
        $$ = ret;
    }
    ;

data_event 
    : timing_check_event 
    {
        struct ast_data_event *ret = new (struct ast_data_event);
        $$ = ret;
    }
    ;

delayed_data 
    : terminal_identifier 
    {
        struct ast_delayed_data *ret = new (struct ast_delayed_data);
        $$ = ret;
    }
    | terminal_identifier TOKEN_79 /* [ */ constant_mintypmax_expression TOKEN_80 /* ] */ 
    {
        struct ast_delayed_data *ret = new (struct ast_delayed_data);
        $$ = ret;
    }
    ;

delayed_reference 
    : terminal_identifier 
    {
        struct ast_delayed_reference *ret = new (struct ast_delayed_reference);
        $$ = ret;
    }
    | terminal_identifier TOKEN_79 /* [ */ constant_mintypmax_expression TOKEN_80 /* ] */ 
    {
        struct ast_delayed_reference *ret = new (struct ast_delayed_reference);
        $$ = ret;
    }
    ;

end_edge_offset 
    : mintypmax_expression 
    {
        struct ast_end_edge_offset *ret = new (struct ast_end_edge_offset);
        $$ = ret;
    }
    ;

event_based_flag 
    : constant_expression 
    {
        struct ast_event_based_flag *ret = new (struct ast_event_based_flag);
        $$ = ret;
    }
    ;

notifier 
    : variable_identifier 
    {
        struct ast_notifier *ret = new (struct ast_notifier);
        $$ = ret;
    }
    ;

reference_event 
    : timing_check_event 
    {
        struct ast_reference_event *ret = new (struct ast_reference_event);
        $$ = ret;
    }
    ;

remain_active_flag 
    : constant_mintypmax_expression 
    {
        struct ast_remain_active_flag *ret = new (struct ast_remain_active_flag);
        $$ = ret;
    }
    ;

timestamp_condition 
    : mintypmax_expression 
    {
        struct ast_timestamp_condition *ret = new (struct ast_timestamp_condition);
        $$ = ret;
    }
    ;

start_edge_offset 
    : mintypmax_expression 
    {
        struct ast_start_edge_offset *ret = new (struct ast_start_edge_offset);
        $$ = ret;
    }
    ;

threshold 
    : constant_expression 
    {
        struct ast_threshold *ret = new (struct ast_threshold);
        $$ = ret;
    }
    ;

timing_check_limit 
    : expression 
    {
        struct ast_timing_check_limit *ret = new (struct ast_timing_check_limit);
        $$ = ret;
    }
    ;

timing_check_event 
    : OPT_195 specify_terminal_descriptor OPT_196 
    {
        struct ast_timing_check_event *ret = new (struct ast_timing_check_event);
        $$ = ret;
    }
    ;

controlled_timing_check_event 
    : timing_check_event_control specify_terminal_descriptor OPT_196 
    {
        struct ast_controlled_timing_check_event *ret = new (struct ast_controlled_timing_check_event);
        $$ = ret;
    }
    ;

timing_check_event_control 
    : TOKEN_343 /* posedge */ 
    {
        struct ast_timing_check_event_control *ret = new (struct ast_timing_check_event_control);
        $$ = ret;
    }
    | TOKEN_344 /* negedge */ 
    {
        struct ast_timing_check_event_control *ret = new (struct ast_timing_check_event_control);
        $$ = ret;
    }
    | TOKEN_345 /* edge */ 
    {
        struct ast_timing_check_event_control *ret = new (struct ast_timing_check_event_control);
        $$ = ret;
    }
    | edge_control_specifier 
    {
        struct ast_timing_check_event_control *ret = new (struct ast_timing_check_event_control);
        $$ = ret;
    }
    ;

specify_terminal_descriptor 
    : specify_input_terminal_descriptor 
    {
        struct ast_specify_terminal_descriptor *ret = new (struct ast_specify_terminal_descriptor);
        $$ = ret;
    }
    | specify_output_terminal_descriptor 
    {
        struct ast_specify_terminal_descriptor *ret = new (struct ast_specify_terminal_descriptor);
        $$ = ret;
    }
    ;

edge_control_specifier 
    : TOKEN_345 /* edge */ TOKEN_79 /* [ */ LIST_153 TOKEN_80 /* ] */ 
    {
        struct ast_edge_control_specifier *ret = new (struct ast_edge_control_specifier);
        $$ = ret;
    }
    ;

edge_descriptor 
    : TOKEN_359 /* 01 */ 
    {
        struct ast_edge_descriptor *ret = new (struct ast_edge_descriptor);
        $$ = ret;
    }
    | TOKEN_360 /* 10 */ 
    {
        struct ast_edge_descriptor *ret = new (struct ast_edge_descriptor);
        $$ = ret;
    }
    | z_or_x zero_or_one 
    {
        struct ast_edge_descriptor *ret = new (struct ast_edge_descriptor);
        $$ = ret;
    }
    | zero_or_one z_or_x 
    {
        struct ast_edge_descriptor *ret = new (struct ast_edge_descriptor);
        $$ = ret;
    }
    ;

zero_or_one 
    : TOKEN_43 /* 0 */ 
    {
        struct ast_zero_or_one *ret = new (struct ast_zero_or_one);
        $$ = ret;
    }
    | TOKEN_44 /* 1 */ 
    {
        struct ast_zero_or_one *ret = new (struct ast_zero_or_one);
        $$ = ret;
    }
    ;

z_or_x 
    : TOKEN_361 /* z */ 
    {
        struct ast_z_or_x *ret = new (struct ast_z_or_x);
        $$ = ret;
    }
    | TOKEN_362 /* Z */ 
    {
        struct ast_z_or_x *ret = new (struct ast_z_or_x);
        $$ = ret;
    }
    | TOKEN_274 /* x */ 
    {
        struct ast_z_or_x *ret = new (struct ast_z_or_x);
        $$ = ret;
    }
    | TOKEN_275 /* X */ 
    {
        struct ast_z_or_x *ret = new (struct ast_z_or_x);
        $$ = ret;
    }
    ;

timing_check_condition 
    : scalar_timing_check_condition 
    {
        struct ast_timing_check_condition *ret = new (struct ast_timing_check_condition);
        $$ = ret;
    }
    | TOKEN_12 /* ( */ scalar_timing_check_condition TOKEN_14 /* ) */ 
    {
        struct ast_timing_check_condition *ret = new (struct ast_timing_check_condition);
        $$ = ret;
    }
    ;

scalar_timing_check_condition 
    : expression 
    {
        struct ast_scalar_timing_check_condition *ret = new (struct ast_scalar_timing_check_condition);
        $$ = ret;
    }
    | TOKEN_363 /* ~ */ expression 
    {
        struct ast_scalar_timing_check_condition *ret = new (struct ast_scalar_timing_check_condition);
        $$ = ret;
    }
    | expression TOKEN_161 /* == */ scalar_constant 
    {
        struct ast_scalar_timing_check_condition *ret = new (struct ast_scalar_timing_check_condition);
        $$ = ret;
    }
    | expression TOKEN_364 /* === */ scalar_constant 
    {
        struct ast_scalar_timing_check_condition *ret = new (struct ast_scalar_timing_check_condition);
        $$ = ret;
    }
    | expression TOKEN_162 /* != */ scalar_constant 
    {
        struct ast_scalar_timing_check_condition *ret = new (struct ast_scalar_timing_check_condition);
        $$ = ret;
    }
    | expression TOKEN_365 /* !== */ scalar_constant 
    {
        struct ast_scalar_timing_check_condition *ret = new (struct ast_scalar_timing_check_condition);
        $$ = ret;
    }
    ;

scalar_constant 
    : TOKEN_266 /* 1'b0 */ 
    {
        struct ast_scalar_constant *ret = new (struct ast_scalar_constant);
        $$ = ret;
    }
    | TOKEN_267 /* 1'b1 */ 
    {
        struct ast_scalar_constant *ret = new (struct ast_scalar_constant);
        $$ = ret;
    }
    | TOKEN_270 /* 1'B0 */ 
    {
        struct ast_scalar_constant *ret = new (struct ast_scalar_constant);
        $$ = ret;
    }
    | TOKEN_271 /* 1'B1 */ 
    {
        struct ast_scalar_constant *ret = new (struct ast_scalar_constant);
        $$ = ret;
    }
    | TOKEN_366 /* 'b0 */ 
    {
        struct ast_scalar_constant *ret = new (struct ast_scalar_constant);
        $$ = ret;
    }
    | TOKEN_367 /* 'b1 */ 
    {
        struct ast_scalar_constant *ret = new (struct ast_scalar_constant);
        $$ = ret;
    }
    | TOKEN_368 /* 'B0 */ 
    {
        struct ast_scalar_constant *ret = new (struct ast_scalar_constant);
        $$ = ret;
    }
    | TOKEN_369 /* 'B1 */ 
    {
        struct ast_scalar_constant *ret = new (struct ast_scalar_constant);
        $$ = ret;
    }
    | TOKEN_44 /* 1 */ 
    {
        struct ast_scalar_constant *ret = new (struct ast_scalar_constant);
        $$ = ret;
    }
    | TOKEN_43 /* 0 */ 
    {
        struct ast_scalar_constant *ret = new (struct ast_scalar_constant);
        $$ = ret;
    }
    ;

concatenation 
    : TOKEN_32 /* { */ LIST_133 TOKEN_33 /* } */ 
    {
        struct ast_concatenation *ret = new (struct ast_concatenation);
        $$ = ret;
    }
    ;

constant_concatenation 
    : TOKEN_32 /* { */ LIST_110 TOKEN_33 /* } */ 
    {
        struct ast_constant_concatenation *ret = new (struct ast_constant_concatenation);
        $$ = ret;
    }
    ;

constant_multiple_concatenation 
    : TOKEN_32 /* { */ constant_expression constant_concatenation TOKEN_33 /* } */ 
    {
        struct ast_constant_multiple_concatenation *ret = new (struct ast_constant_multiple_concatenation);
        $$ = ret;
    }
    ;

module_path_concatenation 
    : TOKEN_32 /* { */ LIST_154 TOKEN_33 /* } */ 
    {
        struct ast_module_path_concatenation *ret = new (struct ast_module_path_concatenation);
        $$ = ret;
    }
    ;

module_path_multiple_concatenation 
    : TOKEN_32 /* { */ constant_expression module_path_concatenation TOKEN_33 /* } */ 
    {
        struct ast_module_path_multiple_concatenation *ret = new (struct ast_module_path_multiple_concatenation);
        $$ = ret;
    }
    ;

multiple_concatenation 
    : TOKEN_32 /* { */ expression concatenation TOKEN_33 /* } */ 
    {
        struct ast_multiple_concatenation *ret = new (struct ast_multiple_concatenation);
        $$ = ret;
    }
    ;

streaming_concatenation 
    : TOKEN_32 /* { */ stream_operator OPT_197 stream_concatenation TOKEN_33 /* } */ 
    {
        struct ast_streaming_concatenation *ret = new (struct ast_streaming_concatenation);
        $$ = ret;
    }
    ;

stream_operator 
    : TOKEN_370 /* >> */ 
    {
        struct ast_stream_operator *ret = new (struct ast_stream_operator);
        $$ = ret;
    }
    | TOKEN_371 /* << */ 
    {
        struct ast_stream_operator *ret = new (struct ast_stream_operator);
        $$ = ret;
    }
    ;

slice_size 
    : simple_type 
    {
        struct ast_slice_size *ret = new (struct ast_slice_size);
        $$ = ret;
    }
    | constant_expression 
    {
        struct ast_slice_size *ret = new (struct ast_slice_size);
        $$ = ret;
    }
    ;

stream_concatenation 
    : TOKEN_32 /* { */ LIST_155 TOKEN_33 /* } */ 
    {
        struct ast_stream_concatenation *ret = new (struct ast_stream_concatenation);
        $$ = ret;
    }
    ;

stream_expression 
    : expression OPT_198 
    {
        struct ast_stream_expression *ret = new (struct ast_stream_expression);
        $$ = ret;
    }
    ;

array_range_expression 
    : expression 
    {
        struct ast_array_range_expression *ret = new (struct ast_array_range_expression);
        $$ = ret;
    }
    | expression TOKEN_6 /* : */ expression 
    {
        struct ast_array_range_expression *ret = new (struct ast_array_range_expression);
        $$ = ret;
    }
    | expression TOKEN_372 /* +: */ expression 
    {
        struct ast_array_range_expression *ret = new (struct ast_array_range_expression);
        $$ = ret;
    }
    | expression TOKEN_373 /* -: */ expression 
    {
        struct ast_array_range_expression *ret = new (struct ast_array_range_expression);
        $$ = ret;
    }
    ;

empty_queue 
    : TOKEN_32 /* { */ TOKEN_33 /* } */ 
    {
        struct ast_empty_queue *ret = new (struct ast_empty_queue);
        $$ = ret;
    }
    ;

constant_function_call 
    : function_subroutine_call 
    {
        struct ast_constant_function_call *ret = new (struct ast_constant_function_call);
        $$ = ret;
    }
    ;

tf_call 
    : ps_or_hierarchical_tf_identifier STAR_2 OPT_12 
    {
        struct ast_tf_call *ret = new (struct ast_tf_call);
        $$ = ret;
    }
    ;

system_tf_call 
    : system_tf_identifier OPT_12 
    {
        struct ast_system_tf_call *ret = new (struct ast_system_tf_call);
        $$ = ret;
    }
    ;

subroutine_call 
    : tf_call 
    {
        struct ast_subroutine_call *ret = new (struct ast_subroutine_call);
        $$ = ret;
    }
    | system_tf_call 
    {
        struct ast_subroutine_call *ret = new (struct ast_subroutine_call);
        $$ = ret;
    }
    | method_call 
    {
        struct ast_subroutine_call *ret = new (struct ast_subroutine_call);
        $$ = ret;
    }
    | OPT_199 
    {
        struct ast_subroutine_call *ret = new (struct ast_subroutine_call);
        $$ = ret;
    }
    ;

function_subroutine_call 
    : subroutine_call 
    {
        struct ast_function_subroutine_call *ret = new (struct ast_function_subroutine_call);
        $$ = ret;
    }
    ;

list_of_arguments 
    : LIST_156 STAR_48 
    {
        struct ast_list_of_arguments *ret = new (struct ast_list_of_arguments);
        $$ = ret;
    }
    | TOKEN_31 /* . */ identifier TOKEN_12 /* ( */ OPT_26 TOKEN_14 /* ) */ STAR_48 
    {
        struct ast_list_of_arguments *ret = new (struct ast_list_of_arguments);
        $$ = ret;
    }
    ;

method_call 
    : method_call_root TOKEN_31 /* . */ method_call_body 
    {
        struct ast_method_call *ret = new (struct ast_method_call);
        $$ = ret;
    }
    ;

method_call_body 
    : method_identifier STAR_2 OPT_12 
    {
        struct ast_method_call_body *ret = new (struct ast_method_call_body);
        $$ = ret;
    }
    | built_in_method_call 
    {
        struct ast_method_call_body *ret = new (struct ast_method_call_body);
        $$ = ret;
    }
    ;

built_in_method_call 
    : array_manipulation_call 
    {
        struct ast_built_in_method_call *ret = new (struct ast_built_in_method_call);
        $$ = ret;
    }
    | randomize_call 
    {
        struct ast_built_in_method_call *ret = new (struct ast_built_in_method_call);
        $$ = ret;
    }
    ;

array_manipulation_call 
    : array_method_name STAR_2 OPT_12 OPT_200 
    {
        struct ast_array_manipulation_call *ret = new (struct ast_array_manipulation_call);
        $$ = ret;
    }
    ;

randomize_call 
    : TOKEN_375 /* randomize */ STAR_2 OPT_202 OPT_204 
    {
        struct ast_randomize_call *ret = new (struct ast_randomize_call);
        $$ = ret;
    }
    ;

method_call_root 
    : primary 
    {
        struct ast_method_call_root *ret = new (struct ast_method_call_root);
        $$ = ret;
    }
    | implicit_class_handle 
    {
        struct ast_method_call_root *ret = new (struct ast_method_call_root);
        $$ = ret;
    }
    ;

array_method_name 
    : method_identifier 
    {
        struct ast_array_method_name *ret = new (struct ast_array_method_name);
        $$ = ret;
    }
    | TOKEN_81 /* unique */ 
    {
        struct ast_array_method_name *ret = new (struct ast_array_method_name);
        $$ = ret;
    }
    | TOKEN_180 /* and */ 
    {
        struct ast_array_method_name *ret = new (struct ast_array_method_name);
        $$ = ret;
    }
    | TOKEN_179 /* or */ 
    {
        struct ast_array_method_name *ret = new (struct ast_array_method_name);
        $$ = ret;
    }
    | TOKEN_249 /* xor */ 
    {
        struct ast_array_method_name *ret = new (struct ast_array_method_name);
        $$ = ret;
    }
    ;

inc_or_dec_expression 
    : inc_or_dec_operator STAR_2 variable_lvalue 
    {
        struct ast_inc_or_dec_expression *ret = new (struct ast_inc_or_dec_expression);
        $$ = ret;
    }
    | variable_lvalue STAR_2 inc_or_dec_operator 
    {
        struct ast_inc_or_dec_expression *ret = new (struct ast_inc_or_dec_expression);
        $$ = ret;
    }
    ;

conditional_expression 
    : cond_predicate TOKEN_276 /* ? */ STAR_2 expression TOKEN_6 /* : */ expression 
    {
        struct ast_conditional_expression *ret = new (struct ast_conditional_expression);
        $$ = ret;
    }
    ;

constant_expression 
    : constant_primary 
    {
        struct ast_constant_expression *ret = new (struct ast_constant_expression);
        $$ = ret;
    }
    | unary_operator STAR_2 constant_primary 
    {
        struct ast_constant_expression *ret = new (struct ast_constant_expression);
        $$ = ret;
    }
    | constant_expression binary_operator STAR_2 constant_expression 
    {
        struct ast_constant_expression *ret = new (struct ast_constant_expression);
        $$ = ret;
    }
    | constant_expression TOKEN_276 /* ? */ STAR_2 constant_expression TOKEN_6 /* : */ constant_expression 
    {
        struct ast_constant_expression *ret = new (struct ast_constant_expression);
        $$ = ret;
    }
    ;

constant_mintypmax_expression 
    : constant_expression 
    {
        struct ast_constant_mintypmax_expression *ret = new (struct ast_constant_mintypmax_expression);
        $$ = ret;
    }
    | constant_expression TOKEN_6 /* : */ constant_expression TOKEN_6 /* : */ constant_expression 
    {
        struct ast_constant_mintypmax_expression *ret = new (struct ast_constant_mintypmax_expression);
        $$ = ret;
    }
    ;

constant_param_expression 
    : constant_mintypmax_expression 
    {
        struct ast_constant_param_expression *ret = new (struct ast_constant_param_expression);
        $$ = ret;
    }
    | data_type 
    {
        struct ast_constant_param_expression *ret = new (struct ast_constant_param_expression);
        $$ = ret;
    }
    | TOKEN_149 /* dollarsign_ */ 
    {
        struct ast_constant_param_expression *ret = new (struct ast_constant_param_expression);
        $$ = ret;
    }
    ;

param_expression 
    : mintypmax_expression 
    {
        struct ast_param_expression *ret = new (struct ast_param_expression);
        $$ = ret;
    }
    | data_type 
    {
        struct ast_param_expression *ret = new (struct ast_param_expression);
        $$ = ret;
    }
    | TOKEN_149 /* dollarsign_ */ 
    {
        struct ast_param_expression *ret = new (struct ast_param_expression);
        $$ = ret;
    }
    ;

constant_range_expression 
    : constant_expression 
    {
        struct ast_constant_range_expression *ret = new (struct ast_constant_range_expression);
        $$ = ret;
    }
    | constant_part_select_range 
    {
        struct ast_constant_range_expression *ret = new (struct ast_constant_range_expression);
        $$ = ret;
    }
    ;

constant_part_select_range 
    : constant_range 
    {
        struct ast_constant_part_select_range *ret = new (struct ast_constant_part_select_range);
        $$ = ret;
    }
    | constant_indexed_range 
    {
        struct ast_constant_part_select_range *ret = new (struct ast_constant_part_select_range);
        $$ = ret;
    }
    ;

constant_range 
    : constant_expression TOKEN_6 /* : */ constant_expression 
    {
        struct ast_constant_range *ret = new (struct ast_constant_range);
        $$ = ret;
    }
    ;

constant_indexed_range 
    : constant_expression TOKEN_372 /* +: */ constant_expression 
    {
        struct ast_constant_indexed_range *ret = new (struct ast_constant_indexed_range);
        $$ = ret;
    }
    | constant_expression TOKEN_373 /* -: */ constant_expression 
    {
        struct ast_constant_indexed_range *ret = new (struct ast_constant_indexed_range);
        $$ = ret;
    }
    ;

expression 
    : primary 
    {
        struct ast_expression *ret = new (struct ast_expression);
        $$ = ret;
    }
    | unary_operator STAR_2 primary 
    {
        struct ast_expression *ret = new (struct ast_expression);
        $$ = ret;
    }
    | inc_or_dec_expression 
    {
        struct ast_expression *ret = new (struct ast_expression);
        $$ = ret;
    }
    | TOKEN_12 /* ( */ operator_assignment TOKEN_14 /* ) */ 
    {
        struct ast_expression *ret = new (struct ast_expression);
        $$ = ret;
    }
    | expression binary_operator STAR_2 expression 
    {
        struct ast_expression *ret = new (struct ast_expression);
        $$ = ret;
    }
    | conditional_expression 
    {
        struct ast_expression *ret = new (struct ast_expression);
        $$ = ret;
    }
    | inside_expression 
    {
        struct ast_expression *ret = new (struct ast_expression);
        $$ = ret;
    }
    | tagged_union_expression 
    {
        struct ast_expression *ret = new (struct ast_expression);
        $$ = ret;
    }
    ;

tagged_union_expression 
    : TOKEN_135 /* tagged */ member_identifier OPT_26 
    {
        struct ast_tagged_union_expression *ret = new (struct ast_tagged_union_expression);
        $$ = ret;
    }
    ;

inside_expression 
    : expression TOKEN_323 /* inside */ TOKEN_32 /* { */ open_range_list TOKEN_33 /* } */ 
    {
        struct ast_inside_expression *ret = new (struct ast_inside_expression);
        $$ = ret;
    }
    ;

value_range 
    : expression 
    {
        struct ast_value_range *ret = new (struct ast_value_range);
        $$ = ret;
    }
    | TOKEN_79 /* [ */ expression TOKEN_6 /* : */ expression TOKEN_80 /* ] */ 
    {
        struct ast_value_range *ret = new (struct ast_value_range);
        $$ = ret;
    }
    ;

mintypmax_expression 
    : expression 
    {
        struct ast_mintypmax_expression *ret = new (struct ast_mintypmax_expression);
        $$ = ret;
    }
    | expression TOKEN_6 /* : */ expression TOKEN_6 /* : */ expression 
    {
        struct ast_mintypmax_expression *ret = new (struct ast_mintypmax_expression);
        $$ = ret;
    }
    ;

module_path_conditional_expression 
    : module_path_expression TOKEN_276 /* ? */ STAR_2 module_path_expression TOKEN_6 /* : */ module_path_expression 
    {
        struct ast_module_path_conditional_expression *ret = new (struct ast_module_path_conditional_expression);
        $$ = ret;
    }
    ;

module_path_expression 
    : module_path_primary 
    {
        struct ast_module_path_expression *ret = new (struct ast_module_path_expression);
        $$ = ret;
    }
    | unary_module_path_operator STAR_2 module_path_primary 
    {
        struct ast_module_path_expression *ret = new (struct ast_module_path_expression);
        $$ = ret;
    }
    | module_path_expression binary_module_path_operator STAR_2 module_path_conditional_expression 
    {
        struct ast_module_path_expression *ret = new (struct ast_module_path_expression);
        $$ = ret;
    }
    ;

module_path_mintypmax_expression 
    : module_path_expression 
    {
        struct ast_module_path_mintypmax_expression *ret = new (struct ast_module_path_mintypmax_expression);
        $$ = ret;
    }
    | module_path_expression TOKEN_6 /* : */ module_path_expression TOKEN_6 /* : */ module_path_expression 
    {
        struct ast_module_path_mintypmax_expression *ret = new (struct ast_module_path_mintypmax_expression);
        $$ = ret;
    }
    ;

part_select_range 
    : constant_range 
    {
        struct ast_part_select_range *ret = new (struct ast_part_select_range);
        $$ = ret;
    }
    | indexed_range 
    {
        struct ast_part_select_range *ret = new (struct ast_part_select_range);
        $$ = ret;
    }
    ;

indexed_range 
    : expression TOKEN_372 /* +: */ constant_expression 
    {
        struct ast_indexed_range *ret = new (struct ast_indexed_range);
        $$ = ret;
    }
    | expression TOKEN_373 /* -: */ constant_expression 
    {
        struct ast_indexed_range *ret = new (struct ast_indexed_range);
        $$ = ret;
    }
    ;

genvar_expression 
    : constant_expression 
    {
        struct ast_genvar_expression *ret = new (struct ast_genvar_expression);
        $$ = ret;
    }
    ;

constant_primary 
    : primary_literal 
    {
        struct ast_constant_primary *ret = new (struct ast_constant_primary);
        $$ = ret;
    }
    | ps_parameter_identifier constant_select 
    {
        struct ast_constant_primary *ret = new (struct ast_constant_primary);
        $$ = ret;
    }
    | specparam_identifier OPT_178 
    {
        struct ast_constant_primary *ret = new (struct ast_constant_primary);
        $$ = ret;
    }
    | genvar_identifier 
    {
        struct ast_constant_primary *ret = new (struct ast_constant_primary);
        $$ = ret;
    }
    | formal_port_identifier constant_select 
    {
        struct ast_constant_primary *ret = new (struct ast_constant_primary);
        $$ = ret;
    }
    | OPT_59 enum_identifier 
    {
        struct ast_constant_primary *ret = new (struct ast_constant_primary);
        $$ = ret;
    }
    | constant_concatenation OPT_178 
    {
        struct ast_constant_primary *ret = new (struct ast_constant_primary);
        $$ = ret;
    }
    | constant_multiple_concatenation OPT_178 
    {
        struct ast_constant_primary *ret = new (struct ast_constant_primary);
        $$ = ret;
    }
    | constant_function_call 
    {
        struct ast_constant_primary *ret = new (struct ast_constant_primary);
        $$ = ret;
    }
    | constant_let_expression 
    {
        struct ast_constant_primary *ret = new (struct ast_constant_primary);
        $$ = ret;
    }
    | TOKEN_12 /* ( */ constant_mintypmax_expression TOKEN_14 /* ) */ 
    {
        struct ast_constant_primary *ret = new (struct ast_constant_primary);
        $$ = ret;
    }
    | constant_cast 
    {
        struct ast_constant_primary *ret = new (struct ast_constant_primary);
        $$ = ret;
    }
    | constant_assignment_pattern_expression 
    {
        struct ast_constant_primary *ret = new (struct ast_constant_primary);
        $$ = ret;
    }
    | type_reference 
    {
        struct ast_constant_primary *ret = new (struct ast_constant_primary);
        $$ = ret;
    }
    ;

module_path_primary 
    : number 
    {
        struct ast_module_path_primary *ret = new (struct ast_module_path_primary);
        $$ = ret;
    }
    | identifier 
    {
        struct ast_module_path_primary *ret = new (struct ast_module_path_primary);
        $$ = ret;
    }
    | module_path_concatenation 
    {
        struct ast_module_path_primary *ret = new (struct ast_module_path_primary);
        $$ = ret;
    }
    | module_path_multiple_concatenation 
    {
        struct ast_module_path_primary *ret = new (struct ast_module_path_primary);
        $$ = ret;
    }
    | function_subroutine_call 
    {
        struct ast_module_path_primary *ret = new (struct ast_module_path_primary);
        $$ = ret;
    }
    | TOKEN_12 /* ( */ module_path_mintypmax_expression TOKEN_14 /* ) */ 
    {
        struct ast_module_path_primary *ret = new (struct ast_module_path_primary);
        $$ = ret;
    }
    ;

primary 
    : primary_literal 
    {
        struct ast_primary *ret = new (struct ast_primary);
        $$ = ret;
    }
    | OPT_205 hierarchical_identifier select 
    {
        struct ast_primary *ret = new (struct ast_primary);
        $$ = ret;
    }
    | empty_queue 
    {
        struct ast_primary *ret = new (struct ast_primary);
        $$ = ret;
    }
    | concatenation OPT_206 
    {
        struct ast_primary *ret = new (struct ast_primary);
        $$ = ret;
    }
    | multiple_concatenation OPT_206 
    {
        struct ast_primary *ret = new (struct ast_primary);
        $$ = ret;
    }
    | function_subroutine_call 
    {
        struct ast_primary *ret = new (struct ast_primary);
        $$ = ret;
    }
    | let_expression 
    {
        struct ast_primary *ret = new (struct ast_primary);
        $$ = ret;
    }
    | TOKEN_12 /* ( */ mintypmax_expression TOKEN_14 /* ) */ 
    {
        struct ast_primary *ret = new (struct ast_primary);
        $$ = ret;
    }
    | cast 
    {
        struct ast_primary *ret = new (struct ast_primary);
        $$ = ret;
    }
    | assignment_pattern_expression 
    {
        struct ast_primary *ret = new (struct ast_primary);
        $$ = ret;
    }
    | streaming_concatenation 
    {
        struct ast_primary *ret = new (struct ast_primary);
        $$ = ret;
    }
    | sequence_method_call 
    {
        struct ast_primary *ret = new (struct ast_primary);
        $$ = ret;
    }
    | TOKEN_377 /* this */ 
    {
        struct ast_primary *ret = new (struct ast_primary);
        $$ = ret;
    }
    | TOKEN_149 /* dollarsign_ */ 
    {
        struct ast_primary *ret = new (struct ast_primary);
        $$ = ret;
    }
    | TOKEN_376 /* null */ 
    {
        struct ast_primary *ret = new (struct ast_primary);
        $$ = ret;
    }
    ;

class_qualifier 
    : OPT_207 OPT_45 
    {
        struct ast_class_qualifier *ret = new (struct ast_class_qualifier);
        $$ = ret;
    }
    ;

range_expression 
    : expression 
    {
        struct ast_range_expression *ret = new (struct ast_range_expression);
        $$ = ret;
    }
    | part_select_range 
    {
        struct ast_range_expression *ret = new (struct ast_range_expression);
        $$ = ret;
    }
    ;

primary_literal 
    : number 
    {
        struct ast_primary_literal *ret = new (struct ast_primary_literal);
        $$ = ret;
    }
    | time_literal 
    {
        struct ast_primary_literal *ret = new (struct ast_primary_literal);
        $$ = ret;
    }
    | unbased_unsized_literal 
    {
        struct ast_primary_literal *ret = new (struct ast_primary_literal);
        $$ = ret;
    }
    | string_literal 
    {
        struct ast_primary_literal *ret = new (struct ast_primary_literal);
        $$ = ret;
    }
    ;

time_literal 
    : unsigned_number time_unit 
    {
        struct ast_time_literal *ret = new (struct ast_time_literal);
        $$ = ret;
    }
    | fixed_point_number time_unit 
    {
        struct ast_time_literal *ret = new (struct ast_time_literal);
        $$ = ret;
    }
    ;

time_unit 
    : TOKEN_379 /* s */ 
    {
        struct ast_time_unit *ret = new (struct ast_time_unit);
        $$ = ret;
    }
    | TOKEN_380 /* ms */ 
    {
        struct ast_time_unit *ret = new (struct ast_time_unit);
        $$ = ret;
    }
    | TOKEN_381 /* us */ 
    {
        struct ast_time_unit *ret = new (struct ast_time_unit);
        $$ = ret;
    }
    | TOKEN_382 /* ns */ 
    {
        struct ast_time_unit *ret = new (struct ast_time_unit);
        $$ = ret;
    }
    | TOKEN_383 /* ps */ 
    {
        struct ast_time_unit *ret = new (struct ast_time_unit);
        $$ = ret;
    }
    | TOKEN_384 /* fs */ 
    {
        struct ast_time_unit *ret = new (struct ast_time_unit);
        $$ = ret;
    }
    ;

implicit_class_handle 
    : TOKEN_377 /* this */ 
    {
        struct ast_implicit_class_handle *ret = new (struct ast_implicit_class_handle);
        $$ = ret;
    }
    | TOKEN_69 /* super */ 
    {
        struct ast_implicit_class_handle *ret = new (struct ast_implicit_class_handle);
        $$ = ret;
    }
    | TOKEN_377 /* this */ TOKEN_31 /* . */ TOKEN_69 /* super */ 
    {
        struct ast_implicit_class_handle *ret = new (struct ast_implicit_class_handle);
        $$ = ret;
    }
    ;

bit_select 
    : STAR_49 
    {
        struct ast_bit_select *ret = new (struct ast_bit_select);
        $$ = ret;
    }
    ;

select 
    : OPT_208 bit_select OPT_209 
    {
        struct ast_select *ret = new (struct ast_select);
        $$ = ret;
    }
    ;

nonrange_select 
    : OPT_208 bit_select 
    {
        struct ast_nonrange_select *ret = new (struct ast_nonrange_select);
        $$ = ret;
    }
    ;

constant_bit_select 
    : STAR_49 
    {
        struct ast_constant_bit_select *ret = new (struct ast_constant_bit_select);
        $$ = ret;
    }
    ;

constant_select 
    : OPT_210 constant_bit_select OPT_211 
    {
        struct ast_constant_select *ret = new (struct ast_constant_select);
        $$ = ret;
    }
    ;

constant_cast 
    : casting_type TOKEN_327 /* ' */ TOKEN_12 /* ( */ constant_expression TOKEN_14 /* ) */ 
    {
        struct ast_constant_cast *ret = new (struct ast_constant_cast);
        $$ = ret;
    }
    ;

constant_let_expression 
    : let_expression 
    {
        struct ast_constant_let_expression *ret = new (struct ast_constant_let_expression);
        $$ = ret;
    }
    ;

cast 
    : casting_type TOKEN_327 /* ' */ TOKEN_12 /* ( */ expression TOKEN_14 /* ) */ 
    {
        struct ast_cast *ret = new (struct ast_cast);
        $$ = ret;
    }
    ;

net_lvalue 
    : ps_or_hierarchical_net_identifier constant_select 
    {
        struct ast_net_lvalue *ret = new (struct ast_net_lvalue);
        $$ = ret;
    }
    | TOKEN_32 /* { */ LIST_136 TOKEN_33 /* } */ 
    {
        struct ast_net_lvalue *ret = new (struct ast_net_lvalue);
        $$ = ret;
    }
    | OPT_162 assignment_pattern_net_lvalue 
    {
        struct ast_net_lvalue *ret = new (struct ast_net_lvalue);
        $$ = ret;
    }
    ;

variable_lvalue 
    : OPT_212 hierarchical_variable_identifier select 
    {
        struct ast_variable_lvalue *ret = new (struct ast_variable_lvalue);
        $$ = ret;
    }
    | TOKEN_32 /* { */ LIST_137 TOKEN_33 /* } */ 
    {
        struct ast_variable_lvalue *ret = new (struct ast_variable_lvalue);
        $$ = ret;
    }
    | OPT_162 assignment_pattern_variable_lvalue 
    {
        struct ast_variable_lvalue *ret = new (struct ast_variable_lvalue);
        $$ = ret;
    }
    | streaming_concatenation 
    {
        struct ast_variable_lvalue *ret = new (struct ast_variable_lvalue);
        $$ = ret;
    }
    ;

nonrange_variable_lvalue 
    : OPT_212 hierarchical_variable_identifier nonrange_select 
    {
        struct ast_nonrange_variable_lvalue *ret = new (struct ast_nonrange_variable_lvalue);
        $$ = ret;
    }
    ;

unary_operator 
    : TOKEN_155 /* + */ 
    {
        struct ast_unary_operator *ret = new (struct ast_unary_operator);
        $$ = ret;
    }
    | TOKEN_157 /* - */ 
    {
        struct ast_unary_operator *ret = new (struct ast_unary_operator);
        $$ = ret;
    }
    | TOKEN_230 /* ! */ 
    {
        struct ast_unary_operator *ret = new (struct ast_unary_operator);
        $$ = ret;
    }
    | TOKEN_363 /* ~ */ 
    {
        struct ast_unary_operator *ret = new (struct ast_unary_operator);
        $$ = ret;
    }
    | TOKEN_385 /* & */ 
    {
        struct ast_unary_operator *ret = new (struct ast_unary_operator);
        $$ = ret;
    }
    | TOKEN_386 /* ~& */ 
    {
        struct ast_unary_operator *ret = new (struct ast_unary_operator);
        $$ = ret;
    }
    | TOKEN_335 /* | */ 
    {
        struct ast_unary_operator *ret = new (struct ast_unary_operator);
        $$ = ret;
    }
    | TOKEN_387 /* ~| */ 
    {
        struct ast_unary_operator *ret = new (struct ast_unary_operator);
        $$ = ret;
    }
    | TOKEN_388 /* ^ */ 
    {
        struct ast_unary_operator *ret = new (struct ast_unary_operator);
        $$ = ret;
    }
    | TOKEN_389 /* ~^ */ 
    {
        struct ast_unary_operator *ret = new (struct ast_unary_operator);
        $$ = ret;
    }
    | TOKEN_390 /* ^~ */ 
    {
        struct ast_unary_operator *ret = new (struct ast_unary_operator);
        $$ = ret;
    }
    ;

binary_operator 
    : TOKEN_155 /* + */ 
    {
        struct ast_binary_operator *ret = new (struct ast_binary_operator);
        $$ = ret;
    }
    | TOKEN_157 /* - */ 
    {
        struct ast_binary_operator *ret = new (struct ast_binary_operator);
        $$ = ret;
    }
    | TOKEN_90 /* * */ 
    {
        struct ast_binary_operator *ret = new (struct ast_binary_operator);
        $$ = ret;
    }
    | TOKEN_27 /* / */ 
    {
        struct ast_binary_operator *ret = new (struct ast_binary_operator);
        $$ = ret;
    }
    | TOKEN_160 /* % */ 
    {
        struct ast_binary_operator *ret = new (struct ast_binary_operator);
        $$ = ret;
    }
    | TOKEN_161 /* == */ 
    {
        struct ast_binary_operator *ret = new (struct ast_binary_operator);
        $$ = ret;
    }
    | TOKEN_162 /* != */ 
    {
        struct ast_binary_operator *ret = new (struct ast_binary_operator);
        $$ = ret;
    }
    | TOKEN_364 /* === */ 
    {
        struct ast_binary_operator *ret = new (struct ast_binary_operator);
        $$ = ret;
    }
    | TOKEN_365 /* !== */ 
    {
        struct ast_binary_operator *ret = new (struct ast_binary_operator);
        $$ = ret;
    }
    | TOKEN_391 /* ==? */ 
    {
        struct ast_binary_operator *ret = new (struct ast_binary_operator);
        $$ = ret;
    }
    | TOKEN_392 /* !=? */ 
    {
        struct ast_binary_operator *ret = new (struct ast_binary_operator);
        $$ = ret;
    }
    | TOKEN_231 /* && */ 
    {
        struct ast_binary_operator *ret = new (struct ast_binary_operator);
        $$ = ret;
    }
    | TOKEN_232 /* || */ 
    {
        struct ast_binary_operator *ret = new (struct ast_binary_operator);
        $$ = ret;
    }
    | TOKEN_159 /* ** */ 
    {
        struct ast_binary_operator *ret = new (struct ast_binary_operator);
        $$ = ret;
    }
    | TOKEN_163 /* < */ 
    {
        struct ast_binary_operator *ret = new (struct ast_binary_operator);
        $$ = ret;
    }
    | TOKEN_164 /* <= */ 
    {
        struct ast_binary_operator *ret = new (struct ast_binary_operator);
        $$ = ret;
    }
    | TOKEN_165 /* > */ 
    {
        struct ast_binary_operator *ret = new (struct ast_binary_operator);
        $$ = ret;
    }
    | TOKEN_166 /* >= */ 
    {
        struct ast_binary_operator *ret = new (struct ast_binary_operator);
        $$ = ret;
    }
    | TOKEN_385 /* & */ 
    {
        struct ast_binary_operator *ret = new (struct ast_binary_operator);
        $$ = ret;
    }
    | TOKEN_335 /* | */ 
    {
        struct ast_binary_operator *ret = new (struct ast_binary_operator);
        $$ = ret;
    }
    | TOKEN_388 /* ^ */ 
    {
        struct ast_binary_operator *ret = new (struct ast_binary_operator);
        $$ = ret;
    }
    | TOKEN_390 /* ^~ */ 
    {
        struct ast_binary_operator *ret = new (struct ast_binary_operator);
        $$ = ret;
    }
    | TOKEN_389 /* ~^ */ 
    {
        struct ast_binary_operator *ret = new (struct ast_binary_operator);
        $$ = ret;
    }
    | TOKEN_370 /* >> */ 
    {
        struct ast_binary_operator *ret = new (struct ast_binary_operator);
        $$ = ret;
    }
    | TOKEN_371 /* << */ 
    {
        struct ast_binary_operator *ret = new (struct ast_binary_operator);
        $$ = ret;
    }
    | TOKEN_393 /* >>> */ 
    {
        struct ast_binary_operator *ret = new (struct ast_binary_operator);
        $$ = ret;
    }
    | TOKEN_394 /* <<< */ 
    {
        struct ast_binary_operator *ret = new (struct ast_binary_operator);
        $$ = ret;
    }
    | TOKEN_75 /* -> */ 
    {
        struct ast_binary_operator *ret = new (struct ast_binary_operator);
        $$ = ret;
    }
    | TOKEN_395 /* <-> */ 
    {
        struct ast_binary_operator *ret = new (struct ast_binary_operator);
        $$ = ret;
    }
    ;

inc_or_dec_operator 
    : TOKEN_156 /* ++ */ 
    {
        struct ast_inc_or_dec_operator *ret = new (struct ast_inc_or_dec_operator);
        $$ = ret;
    }
    | TOKEN_158 /* -- */ 
    {
        struct ast_inc_or_dec_operator *ret = new (struct ast_inc_or_dec_operator);
        $$ = ret;
    }
    ;

unary_module_path_operator 
    : TOKEN_230 /* ! */ 
    {
        struct ast_unary_module_path_operator *ret = new (struct ast_unary_module_path_operator);
        $$ = ret;
    }
    | TOKEN_363 /* ~ */ 
    {
        struct ast_unary_module_path_operator *ret = new (struct ast_unary_module_path_operator);
        $$ = ret;
    }
    | TOKEN_385 /* & */ 
    {
        struct ast_unary_module_path_operator *ret = new (struct ast_unary_module_path_operator);
        $$ = ret;
    }
    | TOKEN_386 /* ~& */ 
    {
        struct ast_unary_module_path_operator *ret = new (struct ast_unary_module_path_operator);
        $$ = ret;
    }
    | TOKEN_335 /* | */ 
    {
        struct ast_unary_module_path_operator *ret = new (struct ast_unary_module_path_operator);
        $$ = ret;
    }
    | TOKEN_387 /* ~| */ 
    {
        struct ast_unary_module_path_operator *ret = new (struct ast_unary_module_path_operator);
        $$ = ret;
    }
    | TOKEN_388 /* ^ */ 
    {
        struct ast_unary_module_path_operator *ret = new (struct ast_unary_module_path_operator);
        $$ = ret;
    }
    | TOKEN_389 /* ~^ */ 
    {
        struct ast_unary_module_path_operator *ret = new (struct ast_unary_module_path_operator);
        $$ = ret;
    }
    | TOKEN_390 /* ^~ */ 
    {
        struct ast_unary_module_path_operator *ret = new (struct ast_unary_module_path_operator);
        $$ = ret;
    }
    ;

binary_module_path_operator 
    : TOKEN_161 /* == */ 
    {
        struct ast_binary_module_path_operator *ret = new (struct ast_binary_module_path_operator);
        $$ = ret;
    }
    | TOKEN_162 /* != */ 
    {
        struct ast_binary_module_path_operator *ret = new (struct ast_binary_module_path_operator);
        $$ = ret;
    }
    | TOKEN_231 /* && */ 
    {
        struct ast_binary_module_path_operator *ret = new (struct ast_binary_module_path_operator);
        $$ = ret;
    }
    | TOKEN_232 /* || */ 
    {
        struct ast_binary_module_path_operator *ret = new (struct ast_binary_module_path_operator);
        $$ = ret;
    }
    | TOKEN_385 /* & */ 
    {
        struct ast_binary_module_path_operator *ret = new (struct ast_binary_module_path_operator);
        $$ = ret;
    }
    | TOKEN_335 /* | */ 
    {
        struct ast_binary_module_path_operator *ret = new (struct ast_binary_module_path_operator);
        $$ = ret;
    }
    | TOKEN_388 /* ^ */ 
    {
        struct ast_binary_module_path_operator *ret = new (struct ast_binary_module_path_operator);
        $$ = ret;
    }
    | TOKEN_390 /* ^~ */ 
    {
        struct ast_binary_module_path_operator *ret = new (struct ast_binary_module_path_operator);
        $$ = ret;
    }
    | TOKEN_389 /* ~^ */ 
    {
        struct ast_binary_module_path_operator *ret = new (struct ast_binary_module_path_operator);
        $$ = ret;
    }
    ;

number 
    : integral_number 
    {
        struct ast_number *ret = new (struct ast_number);
        $$ = ret;
    }
    ;

integral_number 
    : decimal_number 
    {
        struct ast_integral_number *ret = new (struct ast_integral_number);
        $$ = ret;
    }
    | octal_number 
    {
        struct ast_integral_number *ret = new (struct ast_integral_number);
        $$ = ret;
    }
    | binary_number 
    {
        struct ast_integral_number *ret = new (struct ast_integral_number);
        $$ = ret;
    }
    | hex_number 
    {
        struct ast_integral_number *ret = new (struct ast_integral_number);
        $$ = ret;
    }
    ;

decimal_number 
    : SV_UNSIGNED_NUMBER 
    {
        struct ast_decimal_number *ret = new (struct ast_decimal_number);
        $$ = ret;
    }
    | SV_DECIMAL_NUMBER 
    {
        struct ast_decimal_number *ret = new (struct ast_decimal_number);
        $$ = ret;
    }
    ;

octal_number 
    : SV_OCTAL_NUMBER 
    {
        struct ast_octal_number *ret = new (struct ast_octal_number);
        $$ = ret;
    }
    ;

binary_number 
    : SV_BINARY_NUMBER 
    {
        struct ast_binary_number *ret = new (struct ast_binary_number);
        $$ = ret;
    }
    ;

hex_number 
    : SV_HEX_NUMBER 
    {
        struct ast_hex_number *ret = new (struct ast_hex_number);
        $$ = ret;
    }
    ;

unsigned_number 
    : SV_UNSIGNED_INTEGER 
    {
        struct ast_unsigned_number *ret = new (struct ast_unsigned_number);
        $$ = ret;
    }
    ;

real_number 
    : fixed_point_number 
    {
        struct ast_real_number *ret = new (struct ast_real_number);
        $$ = ret;
    }
    | SV_EXPONENTIAL_NUMBER 
    {
        struct ast_real_number *ret = new (struct ast_real_number);
        $$ = ret;
    }
    ;

fixed_point_number 
    : SV_FIXED_POINT_NUMBER 
    {
        struct ast_fixed_point_number *ret = new (struct ast_fixed_point_number);
        $$ = ret;
    }
    ;

unbased_unsized_literal 
    : TOKEN_396 /* '0 */ 
    {
        struct ast_unbased_unsized_literal *ret = new (struct ast_unbased_unsized_literal);
        $$ = ret;
    }
    | TOKEN_397 /* '1 */ 
    {
        struct ast_unbased_unsized_literal *ret = new (struct ast_unbased_unsized_literal);
        $$ = ret;
    }
    | TOKEN_327 /* ' */ z_or_x 
    {
        struct ast_unbased_unsized_literal *ret = new (struct ast_unbased_unsized_literal);
        $$ = ret;
    }
    ;

string_literal 
    : SV_STRING 
    {
        struct ast_string_literal *ret = new (struct ast_string_literal);
        $$ = ret;
    }
    ;

attribute_instance 
    : TOKEN_398 /* (* */ LIST_161 TOKEN_399 /* *) */ 
    {
        struct ast_attribute_instance *ret = new (struct ast_attribute_instance);
        $$ = ret;
    }
    ;

attr_spec 
    : attr_name OPT_24 
    {
        struct ast_attr_spec *ret = new (struct ast_attr_spec);
        $$ = ret;
    }
    ;

attr_name 
    : identifier 
    {
        struct ast_attr_name *ret = new (struct ast_attr_name);
        $$ = ret;
    }
    ;

block_identifier 
    : identifier 
    {
        struct ast_block_identifier *ret = new (struct ast_block_identifier);
        $$ = ret;
    }
    ;

bin_identifier 
    : identifier 
    {
        struct ast_bin_identifier *ret = new (struct ast_bin_identifier);
        $$ = ret;
    }
    ;

c_identifier 
    : identifier 
    {
        struct ast_c_identifier *ret = new (struct ast_c_identifier);
        $$ = ret;
    }
    ;

cell_identifier 
    : identifier 
    {
        struct ast_cell_identifier *ret = new (struct ast_cell_identifier);
        $$ = ret;
    }
    ;

checker_identifier 
    : identifier 
    {
        struct ast_checker_identifier *ret = new (struct ast_checker_identifier);
        $$ = ret;
    }
    ;

class_identifier 
    : identifier 
    {
        struct ast_class_identifier *ret = new (struct ast_class_identifier);
        $$ = ret;
    }
    ;

class_variable_identifier 
    : identifier 
    {
        struct ast_class_variable_identifier *ret = new (struct ast_class_variable_identifier);
        $$ = ret;
    }
    ;

clocking_identifier 
    : identifier 
    {
        struct ast_clocking_identifier *ret = new (struct ast_clocking_identifier);
        $$ = ret;
    }
    ;

config_identifier 
    : identifier 
    {
        struct ast_config_identifier *ret = new (struct ast_config_identifier);
        $$ = ret;
    }
    ;

const_identifier 
    : identifier 
    {
        struct ast_const_identifier *ret = new (struct ast_const_identifier);
        $$ = ret;
    }
    ;

constraint_identifier 
    : identifier 
    {
        struct ast_constraint_identifier *ret = new (struct ast_constraint_identifier);
        $$ = ret;
    }
    ;

covergroup_identifier 
    : identifier 
    {
        struct ast_covergroup_identifier *ret = new (struct ast_covergroup_identifier);
        $$ = ret;
    }
    ;

cover_point_identifier 
    : identifier 
    {
        struct ast_cover_point_identifier *ret = new (struct ast_cover_point_identifier);
        $$ = ret;
    }
    ;

cross_identifier 
    : identifier 
    {
        struct ast_cross_identifier *ret = new (struct ast_cross_identifier);
        $$ = ret;
    }
    ;

dynamic_array_variable_identifier 
    : identifier 
    {
        struct ast_dynamic_array_variable_identifier *ret = new (struct ast_dynamic_array_variable_identifier);
        $$ = ret;
    }
    ;

enum_identifier 
    : identifier 
    {
        struct ast_enum_identifier *ret = new (struct ast_enum_identifier);
        $$ = ret;
    }
    ;

escaped_identifier 
    : SV_ESCAPED_IDENTIFIER 
    {
        struct ast_escaped_identifier *ret = new (struct ast_escaped_identifier);
        $$ = ret;
    }
    ;

formal_port_identifier 
    : identifier 
    {
        struct ast_formal_port_identifier *ret = new (struct ast_formal_port_identifier);
        $$ = ret;
    }
    ;

function_identifier 
    : identifier 
    {
        struct ast_function_identifier *ret = new (struct ast_function_identifier);
        $$ = ret;
    }
    ;

generate_block_identifier 
    : identifier 
    {
        struct ast_generate_block_identifier *ret = new (struct ast_generate_block_identifier);
        $$ = ret;
    }
    ;

genvar_identifier 
    : identifier 
    {
        struct ast_genvar_identifier *ret = new (struct ast_genvar_identifier);
        $$ = ret;
    }
    ;

hierarchical_array_identifier 
    : identifier 
    {
        struct ast_hierarchical_array_identifier *ret = new (struct ast_hierarchical_array_identifier);
        $$ = ret;
    }
    ;

hierarchical_block_identifier 
    : identifier 
    {
        struct ast_hierarchical_block_identifier *ret = new (struct ast_hierarchical_block_identifier);
        $$ = ret;
    }
    ;

hierarchical_event_identifier 
    : identifier 
    {
        struct ast_hierarchical_event_identifier *ret = new (struct ast_hierarchical_event_identifier);
        $$ = ret;
    }
    ;

hierarchical_identifier 
    : identifier 
    {
        struct ast_hierarchical_identifier *ret = new (struct ast_hierarchical_identifier);
        $$ = ret;
    }
    ;

hierarchical_net_identifier 
    : identifier 
    {
        struct ast_hierarchical_net_identifier *ret = new (struct ast_hierarchical_net_identifier);
        $$ = ret;
    }
    ;

hierarchical_parameter_identifier 
    : identifier 
    {
        struct ast_hierarchical_parameter_identifier *ret = new (struct ast_hierarchical_parameter_identifier);
        $$ = ret;
    }
    ;

hierarchical_property_identifier 
    : identifier 
    {
        struct ast_hierarchical_property_identifier *ret = new (struct ast_hierarchical_property_identifier);
        $$ = ret;
    }
    ;

hierarchical_sequence_identifier 
    : identifier 
    {
        struct ast_hierarchical_sequence_identifier *ret = new (struct ast_hierarchical_sequence_identifier);
        $$ = ret;
    }
    ;

hierarchical_task_identifier 
    : identifier 
    {
        struct ast_hierarchical_task_identifier *ret = new (struct ast_hierarchical_task_identifier);
        $$ = ret;
    }
    ;

hierarchical_tf_identifier 
    : identifier 
    {
        struct ast_hierarchical_tf_identifier *ret = new (struct ast_hierarchical_tf_identifier);
        $$ = ret;
    }
    ;

hierarchical_variable_identifier 
    : identifier 
    {
        struct ast_hierarchical_variable_identifier *ret = new (struct ast_hierarchical_variable_identifier);
        $$ = ret;
    }
    ;

identifier 
    : simple_identifier 
    {
        struct ast_identifier *ret = new (struct ast_identifier);
        $$ = ret;
    }
    | escaped_identifier 
    {
        struct ast_identifier *ret = new (struct ast_identifier);
        $$ = ret;
    }
    ;

index_variable_identifier 
    : identifier 
    {
        struct ast_index_variable_identifier *ret = new (struct ast_index_variable_identifier);
        $$ = ret;
    }
    ;

interface_identifier 
    : identifier 
    {
        struct ast_interface_identifier *ret = new (struct ast_interface_identifier);
        $$ = ret;
    }
    ;

interface_instance_identifier 
    : identifier 
    {
        struct ast_interface_instance_identifier *ret = new (struct ast_interface_instance_identifier);
        $$ = ret;
    }
    ;

inout_port_identifier 
    : identifier 
    {
        struct ast_inout_port_identifier *ret = new (struct ast_inout_port_identifier);
        $$ = ret;
    }
    ;

input_port_identifier 
    : identifier 
    {
        struct ast_input_port_identifier *ret = new (struct ast_input_port_identifier);
        $$ = ret;
    }
    ;

instance_identifier 
    : identifier 
    {
        struct ast_instance_identifier *ret = new (struct ast_instance_identifier);
        $$ = ret;
    }
    ;

library_identifier 
    : identifier 
    {
        struct ast_library_identifier *ret = new (struct ast_library_identifier);
        $$ = ret;
    }
    ;

member_identifier 
    : identifier 
    {
        struct ast_member_identifier *ret = new (struct ast_member_identifier);
        $$ = ret;
    }
    ;

method_identifier 
    : identifier 
    {
        struct ast_method_identifier *ret = new (struct ast_method_identifier);
        $$ = ret;
    }
    ;

modport_identifier 
    : identifier 
    {
        struct ast_modport_identifier *ret = new (struct ast_modport_identifier);
        $$ = ret;
    }
    ;

module_identifier 
    : identifier 
    {
        struct ast_module_identifier *ret = new (struct ast_module_identifier);
        $$ = ret;
    }
    ;

net_identifier 
    : identifier 
    {
        struct ast_net_identifier *ret = new (struct ast_net_identifier);
        $$ = ret;
    }
    ;

net_type_identifier 
    : identifier 
    {
        struct ast_net_type_identifier *ret = new (struct ast_net_type_identifier);
        $$ = ret;
    }
    ;

output_port_identifier 
    : identifier 
    {
        struct ast_output_port_identifier *ret = new (struct ast_output_port_identifier);
        $$ = ret;
    }
    ;

package_identifier 
    : identifier 
    {
        struct ast_package_identifier *ret = new (struct ast_package_identifier);
        $$ = ret;
    }
    ;

package_scope 
    : package_identifier TOKEN_89 /* :: */ 
    {
        struct ast_package_scope *ret = new (struct ast_package_scope);
        $$ = ret;
    }
    | TOKEN_400 /* dollarsign_unit */ TOKEN_89 /* :: */ 
    {
        struct ast_package_scope *ret = new (struct ast_package_scope);
        $$ = ret;
    }
    ;

parameter_identifier 
    : identifier 
    {
        struct ast_parameter_identifier *ret = new (struct ast_parameter_identifier);
        $$ = ret;
    }
    ;

port_identifier 
    : identifier 
    {
        struct ast_port_identifier *ret = new (struct ast_port_identifier);
        $$ = ret;
    }
    ;

production_identifier 
    : identifier 
    {
        struct ast_production_identifier *ret = new (struct ast_production_identifier);
        $$ = ret;
    }
    ;

program_identifier 
    : identifier 
    {
        struct ast_program_identifier *ret = new (struct ast_program_identifier);
        $$ = ret;
    }
    ;

property_identifier 
    : identifier 
    {
        struct ast_property_identifier *ret = new (struct ast_property_identifier);
        $$ = ret;
    }
    ;

ps_class_identifier 
    : OPT_116 class_identifier 
    {
        struct ast_ps_class_identifier *ret = new (struct ast_ps_class_identifier);
        $$ = ret;
    }
    ;

ps_covergroup_identifier 
    : OPT_116 covergroup_identifier 
    {
        struct ast_ps_covergroup_identifier *ret = new (struct ast_ps_covergroup_identifier);
        $$ = ret;
    }
    ;

ps_checker_identifier 
    : OPT_116 checker_identifier 
    {
        struct ast_ps_checker_identifier *ret = new (struct ast_ps_checker_identifier);
        $$ = ret;
    }
    ;

ps_identifier 
    : OPT_116 identifier 
    {
        struct ast_ps_identifier *ret = new (struct ast_ps_identifier);
        $$ = ret;
    }
    ;

ps_or_hierarchical_array_identifier 
    : OPT_152 hierarchical_array_identifier 
    {
        struct ast_ps_or_hierarchical_array_identifier *ret = new (struct ast_ps_or_hierarchical_array_identifier);
        $$ = ret;
    }
    ;

ps_or_hierarchical_net_identifier 
    : OPT_116 net_identifier 
    {
        struct ast_ps_or_hierarchical_net_identifier *ret = new (struct ast_ps_or_hierarchical_net_identifier);
        $$ = ret;
    }
    | hierarchical_net_identifier 
    {
        struct ast_ps_or_hierarchical_net_identifier *ret = new (struct ast_ps_or_hierarchical_net_identifier);
        $$ = ret;
    }
    ;

ps_or_hierarchical_property_identifier 
    : OPT_116 property_identifier 
    {
        struct ast_ps_or_hierarchical_property_identifier *ret = new (struct ast_ps_or_hierarchical_property_identifier);
        $$ = ret;
    }
    | hierarchical_property_identifier 
    {
        struct ast_ps_or_hierarchical_property_identifier *ret = new (struct ast_ps_or_hierarchical_property_identifier);
        $$ = ret;
    }
    ;

ps_or_hierarchical_sequence_identifier 
    : OPT_116 sequence_identifier 
    {
        struct ast_ps_or_hierarchical_sequence_identifier *ret = new (struct ast_ps_or_hierarchical_sequence_identifier);
        $$ = ret;
    }
    | hierarchical_sequence_identifier 
    {
        struct ast_ps_or_hierarchical_sequence_identifier *ret = new (struct ast_ps_or_hierarchical_sequence_identifier);
        $$ = ret;
    }
    ;

ps_or_hierarchical_tf_identifier 
    : OPT_116 tf_identifier 
    {
        struct ast_ps_or_hierarchical_tf_identifier *ret = new (struct ast_ps_or_hierarchical_tf_identifier);
        $$ = ret;
    }
    | hierarchical_tf_identifier 
    {
        struct ast_ps_or_hierarchical_tf_identifier *ret = new (struct ast_ps_or_hierarchical_tf_identifier);
        $$ = ret;
    }
    ;

ps_parameter_identifier 
    : OPT_59 parameter_identifier 
    {
        struct ast_ps_parameter_identifier *ret = new (struct ast_ps_parameter_identifier);
        $$ = ret;
    }
    | STAR_52 parameter_identifier 
    {
        struct ast_ps_parameter_identifier *ret = new (struct ast_ps_parameter_identifier);
        $$ = ret;
    }
    ;

ps_type_identifier 
    : OPT_214 type_identifier 
    {
        struct ast_ps_type_identifier *ret = new (struct ast_ps_type_identifier);
        $$ = ret;
    }
    ;

sequence_identifier 
    : identifier 
    {
        struct ast_sequence_identifier *ret = new (struct ast_sequence_identifier);
        $$ = ret;
    }
    ;

signal_identifier 
    : identifier 
    {
        struct ast_signal_identifier *ret = new (struct ast_signal_identifier);
        $$ = ret;
    }
    ;

simple_identifier 
    : SV_IDENTIFIER 
    {
        struct ast_simple_identifier *ret = new (struct ast_simple_identifier);
        $$ = ret;
    }
    ;

specparam_identifier 
    : identifier 
    {
        struct ast_specparam_identifier *ret = new (struct ast_specparam_identifier);
        $$ = ret;
    }
    ;

system_tf_identifier 
    : identifier 
    {
        struct ast_system_tf_identifier *ret = new (struct ast_system_tf_identifier);
        $$ = ret;
    }
    ;

task_identifier 
    : identifier 
    {
        struct ast_task_identifier *ret = new (struct ast_task_identifier);
        $$ = ret;
    }
    ;

tf_identifier 
    : identifier 
    {
        struct ast_tf_identifier *ret = new (struct ast_tf_identifier);
        $$ = ret;
    }
    ;

terminal_identifier 
    : identifier 
    {
        struct ast_terminal_identifier *ret = new (struct ast_terminal_identifier);
        $$ = ret;
    }
    ;

topmodule_identifier 
    : identifier 
    {
        struct ast_topmodule_identifier *ret = new (struct ast_topmodule_identifier);
        $$ = ret;
    }
    ;

type_identifier 
    : identifier 
    {
        struct ast_type_identifier *ret = new (struct ast_type_identifier);
        $$ = ret;
    }
    ;

udp_identifier 
    : identifier 
    {
        struct ast_udp_identifier *ret = new (struct ast_udp_identifier);
        $$ = ret;
    }
    ;

variable_identifier 
    : identifier 
    {
        struct ast_variable_identifier *ret = new (struct ast_variable_identifier);
        $$ = ret;
    }
    ;

file_path_spec 
    : FILE_PATH 
    {
        struct ast_file_path_spec *ret = new (struct ast_file_path_spec);
        $$ = ret;
    }
    ;

LIST_0
    : library_description 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_0  library_description 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_1
    : file_path_spec 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_1 TOKEN_2 file_path_spec 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_2
    : description 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_2  description 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_3
    : attribute_instance 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_3  attribute_instance 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_4
    : package_import_declaration 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_4  package_import_declaration 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_5
    : module_item 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_5  module_item 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_6
    : non_port_module_item 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_6  non_port_module_item 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_7
    : interface_item 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_7  interface_item 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_8
    : non_port_interface_item 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_8  non_port_interface_item 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_9
    : program_item 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_9  program_item 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_10
    : non_port_program_item 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_10  non_port_program_item 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_11
    : STAR_2 checker_or_generate_item 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_11  STAR_2 checker_or_generate_item 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_12
    : interface_class_type 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_12 TOKEN_2 interface_class_type 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_13
    : class_item 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_13  class_item 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_14
    : STAR_2 package_item 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_14  STAR_2 package_item 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_15
    : TOKEN_2 parameter_port_declaration 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_15  TOKEN_2 parameter_port_declaration 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_16
    : parameter_port_declaration 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_16 TOKEN_2 parameter_port_declaration 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_17
    : port 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_17 TOKEN_2 port 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_18
    : STAR_2 ansi_port_declaration 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_18 TOKEN_2 STAR_2 ansi_port_declaration 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_19
    : port_reference 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_19 TOKEN_2 port_reference 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_20
    : unpacked_dimension 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_20  unpacked_dimension 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_21
    : variable_dimension 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_21  variable_dimension 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_22
    : bind_target_instance 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_22 TOKEN_2 bind_target_instance 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_23
    : local_parameter_declaration TOKEN_0 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_23  local_parameter_declaration TOKEN_0 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_24
    : config_rule_statement 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_24  config_rule_statement 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_25
    : OPT_33 cell_identifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_25  OPT_33 cell_identifier 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_26
    : TOKEN_31 instance_identifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_26  TOKEN_31 instance_identifier 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_27
    : library_identifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_27  library_identifier 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_28
    : named_parameter_assignment 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_28 TOKEN_2 named_parameter_assignment 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_29
    : checker_port_item 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_29 TOKEN_2 checker_port_item 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_30
    : property_qualifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_30  property_qualifier 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_31
    : class_item_qualifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_31  class_item_qualifier 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_32
    : method_qualifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_32  method_qualifier 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_33
    : block_item_declaration 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_33  block_item_declaration 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_34
    : function_statement_or_null 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_34  function_statement_or_null 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_35
    : constraint_block_item 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_35  constraint_block_item 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_36
    : constraint_primary 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_36 TOKEN_2 constraint_primary 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_37
    : constraint_expression 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_37  constraint_expression 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_38
    : dist_item 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_38 TOKEN_2 dist_item 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_39
    : identifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_39 TOKEN_2 identifier 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_40
    : anonymous_program_item 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_40  anonymous_program_item 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_41
    : package_import_item 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_41 TOKEN_2 package_import_item 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_42
    : net_identifier STAR_14 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_42 TOKEN_2 net_identifier STAR_14 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_43
    : packed_dimension 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_43  packed_dimension 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_44
    : struct_union_member 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_44  struct_union_member 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_45
    : enum_name_declaration 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_45 TOKEN_2 enum_name_declaration 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_46
    : TOKEN_89 class_identifier OPT_16 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_46  TOKEN_89 class_identifier OPT_16 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_47
    : defparam_assignment 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_47 TOKEN_2 defparam_assignment 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_48
    : genvar_identifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_48 TOKEN_2 genvar_identifier 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_49
    : interface_identifier STAR_14 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_49 TOKEN_2 interface_identifier STAR_14 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_50
    : net_decl_assignment 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_50 TOKEN_2 net_decl_assignment 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_51
    : param_assignment 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_51 TOKEN_2 param_assignment 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_52
    : port_identifier STAR_14 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_52 TOKEN_2 port_identifier STAR_14 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_53
    : port_identifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_53 TOKEN_2 port_identifier 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_54
    : specparam_assignment 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_54 TOKEN_2 specparam_assignment 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_55
    : port_identifier STAR_15 OPT_73 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_55 TOKEN_2 port_identifier STAR_15 OPT_73 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_56
    : type_assignment 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_56 TOKEN_2 type_assignment 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_57
    : variable_decl_assignment 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_57 TOKEN_2 variable_decl_assignment 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_58
    : variable_identifier STAR_15 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_58 TOKEN_2 variable_identifier STAR_15 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_59
    : port_identifier STAR_15 OPT_24 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_59 TOKEN_2 port_identifier STAR_15 OPT_24 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_60
    : tf_item_declaration 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_60  tf_item_declaration 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_61
    : statement_or_null 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_61  statement_or_null 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_62
    : tf_port_item 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_62 TOKEN_2 tf_port_item 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_63
    : data_type 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_63 TOKEN_2 data_type 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_64
    : modport_item 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_64 TOKEN_2 modport_item 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_65
    : modport_ports_declaration 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_65 TOKEN_2 modport_ports_declaration 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_66
    : modport_simple_port 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_66 TOKEN_2 modport_simple_port 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_67
    : modport_tf_port 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_67 TOKEN_2 modport_tf_port 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_68
    : OPT_94 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_68 TOKEN_2 OPT_94 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_69
    : TOKEN_2 TOKEN_31 identifier TOKEN_12 OPT_94 TOKEN_14 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_69  TOKEN_2 TOKEN_31 identifier TOKEN_12 OPT_94 TOKEN_14 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_70
    : TOKEN_31 identifier TOKEN_12 OPT_94 TOKEN_14 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_70 TOKEN_2 TOKEN_31 identifier TOKEN_12 OPT_94 TOKEN_14 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_71
    : assertion_variable_declaration 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_71  assertion_variable_declaration 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_72
    : property_port_item 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_72 TOKEN_2 property_port_item 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_73
    : property_case_item 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_73  property_case_item 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_74
    : expression_or_dist 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_74 TOKEN_2 expression_or_dist 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_75
    : sequence_port_item 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_75 TOKEN_2 sequence_port_item 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_76
    : cycle_delay_range sequence_expr 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_76  cycle_delay_range sequence_expr 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_77
    : TOKEN_2 sequence_match_item 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_77  TOKEN_2 sequence_match_item 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_78
    : OPT_112 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_78 TOKEN_2 OPT_112 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_79
    : TOKEN_2 TOKEN_31 identifier TOKEN_12 OPT_112 TOKEN_14 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_79  TOKEN_2 TOKEN_31 identifier TOKEN_12 OPT_112 TOKEN_14 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_80
    : TOKEN_31 identifier TOKEN_12 OPT_112 TOKEN_14 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_80 TOKEN_2 TOKEN_31 identifier TOKEN_12 OPT_112 TOKEN_14 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_81
    : let_port_item 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_81 TOKEN_2 let_port_item 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_82
    : OPT_119 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_82 TOKEN_2 OPT_119 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_83
    : TOKEN_2 TOKEN_31 identifier TOKEN_12 OPT_119 TOKEN_14 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_83  TOKEN_2 TOKEN_31 identifier TOKEN_12 OPT_119 TOKEN_14 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_84
    : TOKEN_31 identifier TOKEN_12 OPT_119 TOKEN_14 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_84 TOKEN_2 TOKEN_31 identifier TOKEN_12 OPT_119 TOKEN_14 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_85
    : coverage_spec_or_option 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_85  coverage_spec_or_option 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_86
    : block_event_expression 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_86 TOKEN_179 block_event_expression 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_87
    : bins_or_options TOKEN_0 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_87  bins_or_options TOKEN_0 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_88
    : TOKEN_12 trans_set TOKEN_14 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_88 TOKEN_2 TOKEN_12 trans_set TOKEN_14 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_89
    : trans_range_list 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_89 TOKEN_228 trans_range_list 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_90
    : cross_item 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_90 TOKEN_2 cross_item 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_91
    : cross_body_item TOKEN_0 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_91  cross_body_item TOKEN_0 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_92
    : covergroup_value_range 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_92 TOKEN_2 covergroup_value_range 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_93
    : cmos_switch_instance 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_93 TOKEN_2 cmos_switch_instance 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_94
    : enable_gate_instance 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_94 TOKEN_2 enable_gate_instance 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_95
    : mos_switch_instance 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_95 TOKEN_2 mos_switch_instance 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_96
    : n_input_gate_instance 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_96 TOKEN_2 n_input_gate_instance 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_97
    : n_output_gate_instance 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_97 TOKEN_2 n_output_gate_instance 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_98
    : pass_enable_switch_instance 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_98 TOKEN_2 pass_enable_switch_instance 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_99
    : pass_switch_instance 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_99 TOKEN_2 pass_switch_instance 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_100
    : pull_gate_instance 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_100 TOKEN_2 pull_gate_instance 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_101
    : input_terminal 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_101 TOKEN_2 input_terminal 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_102
    : output_terminal 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_102 TOKEN_2 output_terminal 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_103
    : hierarchical_instance 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_103 TOKEN_2 hierarchical_instance 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_104
    : ordered_parameter_assignment 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_104 TOKEN_2 ordered_parameter_assignment 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_105
    : ordered_port_connection 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_105 TOKEN_2 ordered_port_connection 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_106
    : named_port_connection 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_106 TOKEN_2 named_port_connection 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_107
    : ordered_checker_port_connection 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_107 TOKEN_2 ordered_checker_port_connection 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_108
    : named_checker_port_connection 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_108 TOKEN_2 named_checker_port_connection 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_109
    : generate_item 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_109  generate_item 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_110
    : constant_expression 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_110 TOKEN_2 constant_expression 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_111
    : udp_port_declaration 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_111  udp_port_declaration 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_112
    : input_port_identifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_112 TOKEN_2 input_port_identifier 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_113
    : udp_input_declaration 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_113 TOKEN_2 udp_input_declaration 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_114
    : combinational_entry 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_114  combinational_entry 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_115
    : sequential_entry 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_115  sequential_entry 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_116
    : level_symbol 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_116  level_symbol 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_117
    : udp_instance 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_117 TOKEN_2 udp_instance 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_118
    : net_assignment 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_118 TOKEN_2 net_assignment 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_119
    : variable_assignment 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_119 TOKEN_2 variable_assignment 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_120
    : TOKEN_38 net_lvalue 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_120  TOKEN_38 net_lvalue 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_121
    : variable_identifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_121 TOKEN_2 variable_identifier 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_122
    : hierarchical_identifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_122 TOKEN_2 hierarchical_identifier 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_123
    : TOKEN_77 TOKEN_76 TOKEN_12 cond_predicate TOKEN_14 statement_or_null 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_123  TOKEN_77 TOKEN_76 TOKEN_12 cond_predicate TOKEN_14 statement_or_null 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_124
    : expression_or_cond_pattern 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_124 TOKEN_322 expression_or_cond_pattern 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_125
    : case_item 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_125  case_item 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_126
    : case_pattern_item 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_126  case_pattern_item 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_127
    : case_inside_item 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_127  case_inside_item 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_128
    : case_item_expression 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_128 TOKEN_2 case_item_expression 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_129
    : randcase_item 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_129  randcase_item 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_130
    : open_value_range 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_130 TOKEN_2 open_value_range 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_131
    : pattern 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_131 TOKEN_2 pattern 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_132
    : member_identifier TOKEN_6 pattern 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_132 TOKEN_2 member_identifier TOKEN_6 pattern 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_133
    : expression 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_133 TOKEN_2 expression 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_134
    : structure_pattern_key TOKEN_6 expression 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_134 TOKEN_2 structure_pattern_key TOKEN_6 expression 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_135
    : array_pattern_key TOKEN_6 expression 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_135 TOKEN_2 array_pattern_key TOKEN_6 expression 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_136
    : net_lvalue 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_136 TOKEN_2 net_lvalue 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_137
    : variable_lvalue 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_137 TOKEN_2 variable_lvalue 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_138
    : for_variable_declaration 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_138 TOKEN_2 for_variable_declaration 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_139
    : data_type variable_identifier TOKEN_38 expression 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_139 TOKEN_2 data_type variable_identifier TOKEN_38 expression 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_140
    : for_step_assignment 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_140 TOKEN_2 for_step_assignment 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_141
    : OPT_165 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_141 TOKEN_2 OPT_165 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_142
    : clocking_item 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_142  clocking_item 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_143
    : clocking_decl_assign 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_143 TOKEN_2 clocking_decl_assign 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_144
    : production 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_144  production 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_145
    : rs_rule 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_145 TOKEN_335 rs_rule 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_146
    : rs_prod 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_146  rs_prod 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_147
    : production_item 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_147  production_item 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_148
    : data_declaration 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_148  data_declaration 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_149
    : rs_case_item 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_149  rs_case_item 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_150
    : specify_item 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_150  specify_item 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_151
    : specify_input_terminal_descriptor 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_151 TOKEN_2 specify_input_terminal_descriptor 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_152
    : specify_output_terminal_descriptor 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_152 TOKEN_2 specify_output_terminal_descriptor 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_153
    : edge_descriptor 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_153 TOKEN_2 edge_descriptor 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_154
    : module_path_expression 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_154 TOKEN_2 module_path_expression 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_155
    : stream_expression 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_155 TOKEN_2 stream_expression 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_156
    : OPT_26 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_156 TOKEN_2 OPT_26 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_157
    : TOKEN_2 TOKEN_31 identifier TOKEN_12 OPT_26 TOKEN_14 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_157  TOKEN_2 TOKEN_31 identifier TOKEN_12 OPT_26 TOKEN_14 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_158
    : TOKEN_79 expression TOKEN_80 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_158  TOKEN_79 expression TOKEN_80 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_159
    : TOKEN_31 member_identifier bit_select 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_159  TOKEN_31 member_identifier bit_select 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_160
    : TOKEN_31 member_identifier constant_bit_select 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_160  TOKEN_31 member_identifier constant_bit_select 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_161
    : attr_spec 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_161 TOKEN_2 attr_spec 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
LIST_162
    : generate_block_identifier OPT_213 TOKEN_31 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | LIST_162  generate_block_identifier OPT_213 TOKEN_31 
    {
        ast_list_append($1, $2, AST_UNTYPED);
        $$ = $1;
    }
    ;
OPT_0
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_3 /* -incdir */ LIST_1 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_1
    : /* empty */
    {
        $$ = NULL;
    }
    | timeunits_declaration 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_2
    : /* empty */
    {
        $$ = NULL;
    }
    | lifetime 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_3
    : /* empty */
    {
        $$ = NULL;
    }
    | parameter_port_list 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_4
    : /* empty */
    {
        $$ = NULL;
    }
    | list_of_port_declarations 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_5
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_6 /* : */ module_identifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_6
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_6 /* : */ interface_identifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_7
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_6 /* : */ program_identifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_8
    : /* empty */
    {
        $$ = NULL;
    }
    | checker_port_list 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_9
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_12 /* ( */ OPT_8 TOKEN_14 /* ) */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_10
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_6 /* : */ checker_identifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_11
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_19 /* virtual */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_12
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_12 /* ( */ list_of_arguments TOKEN_14 /* ) */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_13
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_21 /* extends */ class_type OPT_12 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_14
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_22 /* implements */ LIST_12 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_15
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_6 /* : */ class_identifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_16
    : /* empty */
    {
        $$ = NULL;
    }
    | parameter_value_assignment 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_17
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_6 /* : */ package_identifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_18
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_27 /* / */ time_literal 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_19
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_18 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_20
    : /* empty */
    {
        $$ = NULL;
    }
    | port_expression 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_21
    : /* empty */
    {
        $$ = NULL;
    }
    | port_direction 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_22
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_31 /* . */ modport_identifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_23
    : /* empty */
    {
        $$ = NULL;
    }
    | net_port_header 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | interface_port_header 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_24
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_38 /* = */ constant_expression 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_25
    : /* empty */
    {
        $$ = NULL;
    }
    | variable_port_header 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_26
    : /* empty */
    {
        $$ = NULL;
    }
    | expression 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_27
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_2 /* , */ list_of_arguments 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_28
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_12 /* ( */ finish_number OPT_27 TOKEN_14 /* ) */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_29
    : /* empty */
    {
        $$ = NULL;
    }
    | list_of_arguments 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_30
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_12 /* ( */ OPT_29 TOKEN_14 /* ) */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_31
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_6 /* : */ bind_target_instance_list 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_32
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_6 /* : */ config_identifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_33
    : /* empty */
    {
        $$ = NULL;
    }
    | library_identifier TOKEN_31 /* . */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_34
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_6 /* : */ TOKEN_52 /* config */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_35
    : /* empty */
    {
        $$ = NULL;
    }
    | checker_port_direction 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_36
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_38 /* = */ property_actual_arg 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_37
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_60 /* rand */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_38
    : /* empty */
    {
        $$ = NULL;
    }
    | tf_port_list 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_39
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_12 /* ( */ OPT_38 TOKEN_14 /* ) */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_40
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_62 /* pure */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_41
    : /* empty */
    {
        $$ = NULL;
    }
    | class_scope 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_42
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_69 /* super */ TOKEN_31 /* . */ TOKEN_64 /* new */ OPT_12 TOKEN_0 /* ; */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_43
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_6 /* : */ TOKEN_64 /* new */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_44
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_65 /* static */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_45
    : /* empty */
    {
        $$ = NULL;
    }
    | implicit_class_handle TOKEN_31 /* . */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | class_scope 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_46
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_74 /* soft */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_47
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_77 /* else */ constraint_set 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_48
    : /* empty */
    {
        $$ = NULL;
    }
    | dist_weight 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_49
    : /* empty */
    {
        $$ = NULL;
    }
    | constraint_prototype_qualifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_50
    : /* empty */
    {
        $$ = NULL;
    }
    | packed_dimension 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_51
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_61 /* const */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_52
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_87 /* var */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_53
    : /* empty */
    {
        $$ = NULL;
    }
    | drive_strength 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | charge_strength 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_54
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_94 /* vectored */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | TOKEN_95 /* scalared */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_55
    : /* empty */
    {
        $$ = NULL;
    }
    | delay3 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_56
    : /* empty */
    {
        $$ = NULL;
    }
    | delay_control 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_57
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_29 /* # */ delay_value 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_58
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_98 /* enum */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | TOKEN_99 /* struct */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | TOKEN_100 /* union */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | TOKEN_20 /* class */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | TOKEN_11 /* interface */ TOKEN_20 /* class */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_59
    : /* empty */
    {
        $$ = NULL;
    }
    | package_scope 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | class_scope 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_60
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_102 /* with */ OPT_59 tf_identifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_61
    : /* empty */
    {
        $$ = NULL;
    }
    | signing 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_62
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_105 /* packed */ OPT_61 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_63
    : /* empty */
    {
        $$ = NULL;
    }
    | enum_base_type 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_64
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_11 /* interface */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_65
    : /* empty */
    {
        $$ = NULL;
    }
    | class_scope 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | package_scope 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_66
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_6 /* : */ integral_number 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_67
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_79 /* [ */ integral_number OPT_66 TOKEN_80 /* ] */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_68
    : /* empty */
    {
        $$ = NULL;
    }
    | net_type 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_69
    : /* empty */
    {
        $$ = NULL;
    }
    | random_qualifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_70
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_135 /* tagged */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_71
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_2 /* , */ mintypmax_expression 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_72
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_2 /* , */ mintypmax_expression OPT_71 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_73
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_38 /* = */ expression 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_74
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_38 /* = */ constant_param_expression 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_75
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_38 /* = */ data_type 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_76
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_2 /* , */ error_limit_value 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_77
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_38 /* = */ dynamic_array_new 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_78
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_38 /* = */ class_new 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_79
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_12 /* ( */ expression TOKEN_14 /* ) */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_80
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_6 /* : */ constant_expression 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_81
    : /* empty */
    {
        $$ = NULL;
    }
    | interface_identifier TOKEN_31 /* . */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | class_scope 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_82
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_6 /* : */ function_identifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_83
    : /* empty */
    {
        $$ = NULL;
    }
    | dpi_function_import_property 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_84
    : /* empty */
    {
        $$ = NULL;
    }
    | c_identifier TOKEN_38 /* = */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_85
    : /* empty */
    {
        $$ = NULL;
    }
    | dpi_task_import_property 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_86
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_6 /* : */ task_identifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_87
    : /* empty */
    {
        $$ = NULL;
    }
    | tf_port_direction 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_88
    : /* empty */
    {
        $$ = NULL;
    }
    | port_identifier STAR_15 OPT_73 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_89
    : /* empty */
    {
        $$ = NULL;
    }
    | block_identifier TOKEN_6 /* : */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_90
    : /* empty */
    {
        $$ = NULL;
    }
    | clocking_event 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_91
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_48 /* disable */ TOKEN_49 /* iff */ TOKEN_12 /* ( */ expression_or_dist TOKEN_14 /* ) */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_92
    : /* empty */
    {
        $$ = NULL;
    }
    | property_list_of_arguments 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_93
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_12 /* ( */ OPT_92 TOKEN_14 /* ) */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_94
    : /* empty */
    {
        $$ = NULL;
    }
    | property_actual_arg 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_95
    : /* empty */
    {
        $$ = NULL;
    }
    | property_port_list 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_96
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_12 /* ( */ OPT_95 TOKEN_14 /* ) */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_97
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_0 /* ; */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_98
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_6 /* : */ property_identifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_99
    : /* empty */
    {
        $$ = NULL;
    }
    | property_lvar_port_direction 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_100
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_67 /* local */ OPT_99 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_101
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_77 /* else */ property_expr 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_102
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_6 /* : */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_103
    : /* empty */
    {
        $$ = NULL;
    }
    | sequence_port_list 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_104
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_12 /* ( */ OPT_103 TOKEN_14 /* ) */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_105
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_6 /* : */ sequence_identifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_106
    : /* empty */
    {
        $$ = NULL;
    }
    | sequence_lvar_port_direction 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_107
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_67 /* local */ OPT_106 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_108
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_38 /* = */ sequence_actual_arg 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_109
    : /* empty */
    {
        $$ = NULL;
    }
    | boolean_abbrev 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_110
    : /* empty */
    {
        $$ = NULL;
    }
    | sequence_abbrev 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_111
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_12 /* ( */ sequence_list_of_arguments TOKEN_14 /* ) */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_112
    : /* empty */
    {
        $$ = NULL;
    }
    | sequence_actual_arg 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_113
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_213 /* dist */ TOKEN_32 /* { */ dist_list TOKEN_33 /* } */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_114
    : /* empty */
    {
        $$ = NULL;
    }
    | let_port_list 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_115
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_12 /* ( */ OPT_114 TOKEN_14 /* ) */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_116
    : /* empty */
    {
        $$ = NULL;
    }
    | package_scope 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_117
    : /* empty */
    {
        $$ = NULL;
    }
    | let_list_of_arguments 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_118
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_12 /* ( */ OPT_117 TOKEN_14 /* ) */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_119
    : /* empty */
    {
        $$ = NULL;
    }
    | let_actual_arg 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_120
    : /* empty */
    {
        $$ = NULL;
    }
    | coverage_event 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_121
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_6 /* : */ covergroup_identifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_122
    : /* empty */
    {
        $$ = NULL;
    }
    | hierarchical_identifier TOKEN_31 /* . */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | class_scope 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_123
    : /* empty */
    {
        $$ = NULL;
    }
    | data_type_or_implicit 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_124
    : /* empty */
    {
        $$ = NULL;
    }
    | OPT_123 cover_point_identifier TOKEN_6 /* : */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_125
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_49 /* iff */ TOKEN_12 /* ( */ expression TOKEN_14 /* ) */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_126
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_224 /* wildcard */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_127
    : /* empty */
    {
        $$ = NULL;
    }
    | covergroup_expression 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_128
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_79 /* [ */ OPT_127 TOKEN_80 /* ] */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_129
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_102 /* with */ TOKEN_12 /* ( */ with_covergroup_expression TOKEN_14 /* ) */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_130
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_79 /* [ */ TOKEN_80 /* ] */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_131
    : /* empty */
    {
        $$ = NULL;
    }
    | cross_identifier TOKEN_6 /* : */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_132
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_233 /* matches */ integer_covergroup_expression 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_133
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_203 /* intersect */ TOKEN_32 /* { */ covergroup_range_list TOKEN_33 /* } */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_134
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_31 /* . */ bin_identifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_135
    : /* empty */
    {
        $$ = NULL;
    }
    | drive_strength 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_136
    : /* empty */
    {
        $$ = NULL;
    }
    | delay2 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_137
    : /* empty */
    {
        $$ = NULL;
    }
    | pulldown_strength 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_138
    : /* empty */
    {
        $$ = NULL;
    }
    | pullup_strength 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_139
    : /* empty */
    {
        $$ = NULL;
    }
    | name_of_instance 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_140
    : /* empty */
    {
        $$ = NULL;
    }
    | list_of_parameter_assignments 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_141
    : /* empty */
    {
        $$ = NULL;
    }
    | param_expression 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_142
    : /* empty */
    {
        $$ = NULL;
    }
    | list_of_port_connections 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_143
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_12 /* ( */ OPT_26 TOKEN_14 /* ) */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_144
    : /* empty */
    {
        $$ = NULL;
    }
    | list_of_checker_port_connections 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_145
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_12 /* ( */ OPT_94 TOKEN_14 /* ) */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_146
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_93 /* genvar */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_147
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_77 /* else */ generate_block 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_148
    : /* empty */
    {
        $$ = NULL;
    }
    | generate_block_identifier TOKEN_6 /* : */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_149
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_6 /* : */ generate_block_identifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_150
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_6 /* : */ udp_identifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_151
    : /* empty */
    {
        $$ = NULL;
    }
    | udp_initial_statement 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_152
    : /* empty */
    {
        $$ = NULL;
    }
    | implicit_class_handle TOKEN_31 /* . */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | class_scope 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | package_scope 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_153
    : /* empty */
    {
        $$ = NULL;
    }
    | delay_or_event_control 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_154
    : /* empty */
    {
        $$ = NULL;
    }
    | statement 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_155
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_6 /* : */ block_identifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_156
    : /* empty */
    {
        $$ = NULL;
    }
    | edge_identifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_157
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_49 /* iff */ expression 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_158
    : /* empty */
    {
        $$ = NULL;
    }
    | unique_priority 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_159
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_77 /* else */ statement_or_null 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_160
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_322 /* &&& */ expression 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_161
    : /* empty */
    {
        $$ = NULL;
    }
    | pattern 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_162
    : /* empty */
    {
        $$ = NULL;
    }
    | assignment_pattern_expression_type 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_163
    : /* empty */
    {
        $$ = NULL;
    }
    | for_initialization 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_164
    : /* empty */
    {
        $$ = NULL;
    }
    | for_step 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_165
    : /* empty */
    {
        $$ = NULL;
    }
    | index_variable_identifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_166
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_46 /* default */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_167
    : /* empty */
    {
        $$ = NULL;
    }
    | clocking_identifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_168
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_6 /* : */ clocking_identifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_169
    : /* empty */
    {
        $$ = NULL;
    }
    | clocking_skew 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_170
    : /* empty */
    {
        $$ = NULL;
    }
    | cycle_delay 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_171
    : /* empty */
    {
        $$ = NULL;
    }
    | production_identifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_172
    : /* empty */
    {
        $$ = NULL;
    }
    | data_type_or_void 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_173
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_12 /* ( */ tf_port_list TOKEN_14 /* ) */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_174
    : /* empty */
    {
        $$ = NULL;
    }
    | rs_code_block 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_175
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_82 /* := */ weight_specification OPT_174 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_176
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_77 /* else */ production_item 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_177
    : /* empty */
    {
        $$ = NULL;
    }
    | polarity_operator 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_178
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_79 /* [ */ constant_range_expression TOKEN_80 /* ] */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_179
    : /* empty */
    {
        $$ = NULL;
    }
    | notifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_180
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_2 /* , */ OPT_179 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_181
    : /* empty */
    {
        $$ = NULL;
    }
    | timestamp_condition 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_182
    : /* empty */
    {
        $$ = NULL;
    }
    | timecheck_condition 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_183
    : /* empty */
    {
        $$ = NULL;
    }
    | delayed_reference 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_184
    : /* empty */
    {
        $$ = NULL;
    }
    | delayed_data 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_185
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_2 /* , */ OPT_184 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_186
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_2 /* , */ OPT_183 OPT_185 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_187
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_2 /* , */ OPT_182 OPT_186 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_188
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_2 /* , */ OPT_181 OPT_187 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_189
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_2 /* , */ OPT_179 OPT_188 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_190
    : /* empty */
    {
        $$ = NULL;
    }
    | event_based_flag 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_191
    : /* empty */
    {
        $$ = NULL;
    }
    | remain_active_flag 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_192
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_2 /* , */ OPT_191 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_193
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_2 /* , */ OPT_190 OPT_192 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_194
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_2 /* , */ OPT_179 OPT_193 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_195
    : /* empty */
    {
        $$ = NULL;
    }
    | timing_check_event_control 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_196
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_322 /* &&& */ timing_check_condition 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_197
    : /* empty */
    {
        $$ = NULL;
    }
    | slice_size 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_198
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_102 /* with */ TOKEN_79 /* [ */ array_range_expression TOKEN_80 /* ] */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_199
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_374 /* std:: */ randomize_call 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_200
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_102 /* with */ TOKEN_12 /* ( */ expression TOKEN_14 /* ) */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_201
    : /* empty */
    {
        $$ = NULL;
    }
    | variable_identifier_list 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | TOKEN_376 /* null */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_202
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_12 /* ( */ OPT_201 TOKEN_14 /* ) */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_203
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_12 /* ( */ identifier_list TOKEN_14 /* ) */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_204
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_102 /* with */ OPT_203 constraint_block 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_205
    : /* empty */
    {
        $$ = NULL;
    }
    | class_qualifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | package_scope 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_206
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_79 /* [ */ range_expression TOKEN_80 /* ] */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_207
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_378 /* local:: */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_208
    : /* empty */
    {
        $$ = NULL;
    }
    | STAR_50 TOKEN_31 /* . */ member_identifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_209
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_79 /* [ */ part_select_range TOKEN_80 /* ] */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_210
    : /* empty */
    {
        $$ = NULL;
    }
    | STAR_51 TOKEN_31 /* . */ member_identifier 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_211
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_79 /* [ */ constant_part_select_range TOKEN_80 /* ] */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_212
    : /* empty */
    {
        $$ = NULL;
    }
    | implicit_class_handle TOKEN_31 /* . */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | package_scope 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_213
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_79 /* [ */ constant_expression TOKEN_80 /* ] */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
OPT_214
    : /* empty */
    {
        $$ = NULL;
    }
    | TOKEN_378 /* local:: */ 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    | package_scope 
    {
        struct ast_list *list = ast_list_new(AST_UNTYPED);
        ast_list_append(list, $1, AST_UNTYPED);
        $$ = list;
    }
    ;
STAR_0
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_0 
    {
        $$ = $1;
    }

    ;
STAR_1
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_2 
    {
        $$ = $1;
    }

    ;
STAR_2
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_3 
    {
        $$ = $1;
    }

    ;
STAR_3
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_4 
    {
        $$ = $1;
    }

    ;
STAR_4
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_5 
    {
        $$ = $1;
    }

    ;
STAR_5
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_6 
    {
        $$ = $1;
    }

    ;
STAR_6
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_7 
    {
        $$ = $1;
    }

    ;
STAR_7
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_8 
    {
        $$ = $1;
    }

    ;
STAR_8
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_9 
    {
        $$ = $1;
    }

    ;
STAR_9
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_10 
    {
        $$ = $1;
    }

    ;
STAR_10
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_11 
    {
        $$ = $1;
    }

    ;
STAR_11
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_13 
    {
        $$ = $1;
    }

    ;
STAR_12
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_14 
    {
        $$ = $1;
    }

    ;
STAR_13
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_15 
    {
        $$ = $1;
    }

    ;
STAR_14
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_20 
    {
        $$ = $1;
    }

    ;
STAR_15
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_21 
    {
        $$ = $1;
    }

    ;
STAR_16
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_23 
    {
        $$ = $1;
    }

    ;
STAR_17
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_24 
    {
        $$ = $1;
    }

    ;
STAR_18
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_25 
    {
        $$ = $1;
    }

    ;
STAR_19
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_26 
    {
        $$ = $1;
    }

    ;
STAR_20
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_27 
    {
        $$ = $1;
    }

    ;
STAR_21
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_30 
    {
        $$ = $1;
    }

    ;
STAR_22
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_31 
    {
        $$ = $1;
    }

    ;
STAR_23
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_32 
    {
        $$ = $1;
    }

    ;
STAR_24
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_33 
    {
        $$ = $1;
    }

    ;
STAR_25
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_34 
    {
        $$ = $1;
    }

    ;
STAR_26
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_35 
    {
        $$ = $1;
    }

    ;
STAR_27
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_37 
    {
        $$ = $1;
    }

    ;
STAR_28
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_40 
    {
        $$ = $1;
    }

    ;
STAR_29
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_43 
    {
        $$ = $1;
    }

    ;
STAR_30
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_46 
    {
        $$ = $1;
    }

    ;
STAR_31
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_60 
    {
        $$ = $1;
    }

    ;
STAR_32
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_61 
    {
        $$ = $1;
    }

    ;
STAR_33
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_69 
    {
        $$ = $1;
    }

    ;
STAR_34
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_71 
    {
        $$ = $1;
    }

    ;
STAR_35
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_77 
    {
        $$ = $1;
    }

    ;
STAR_36
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_79 
    {
        $$ = $1;
    }

    ;
STAR_37
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_83 
    {
        $$ = $1;
    }

    ;
STAR_38
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_85 
    {
        $$ = $1;
    }

    ;
STAR_39
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_87 
    {
        $$ = $1;
    }

    ;
STAR_40
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_91 
    {
        $$ = $1;
    }

    ;
STAR_41
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_109 
    {
        $$ = $1;
    }

    ;
STAR_42
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_111 
    {
        $$ = $1;
    }

    ;
STAR_43
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_116 
    {
        $$ = $1;
    }

    ;
STAR_44
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_123 
    {
        $$ = $1;
    }

    ;
STAR_45
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_142 
    {
        $$ = $1;
    }

    ;
STAR_46
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_148 
    {
        $$ = $1;
    }

    ;
STAR_47
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_150 
    {
        $$ = $1;
    }

    ;
STAR_48
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_157 
    {
        $$ = $1;
    }

    ;
STAR_49
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_158 
    {
        $$ = $1;
    }

    ;
STAR_50
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_159 
    {
        $$ = $1;
    }

    ;
STAR_51
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_160 
    {
        $$ = $1;
    }

    ;
STAR_52
    : /* empty */
    {
        $$ = NULL;
    }
    | LIST_162 
    {
        $$ = $1;
    }

    ;

%%
int line_count = 0;

// 
int
yyerror(char const *str)
{
    extern char *yytext;
    fprintf(stderr, "%5d: %s: syntax error\n", line_count, yytext);
    return 0;
}

// 
int main(int argc, const char *argv[]) {
    extern int yyparse(void);
    extern FILE *yyin;
    
    yyin = stdin;
    if (yyparse()) {
        fprintf(stderr, "Compilation error \n");
    }
    
    return 0;
}
