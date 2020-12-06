%{
#include <cstdio>
#include <cstdlib>

#include "parser_ast.h"
const int MAX_TOKEN_LEN = 2048;



class ast::object *start;
class ast::object *start_library_text;
class ast::object *start_source_text;



int yylex();
int yyerror(char const *str);

%}
%union {
    char token_str[MAX_TOKEN_LEN];
    class ast::list<class ast::object *> *ast_list;
    
    ast::library_text                             *ast_library_text;
    ast::library_description                      *ast_library_description;
    ast::library_declaration                      *ast_library_declaration;
    ast::include_statement                        *ast_include_statement;
    ast::source_text                              *ast_source_text;
    ast::description                              *ast_description;
    ast::module_nonansi_header                    *ast_module_nonansi_header;
    ast::module_ansi_header                       *ast_module_ansi_header;
    ast::module_declaration                       *ast_module_declaration;
    ast::module_keyword                           *ast_module_keyword;
    ast::interface_declaration                    *ast_interface_declaration;
    ast::interface_nonansi_header                 *ast_interface_nonansi_header;
    ast::interface_ansi_header                    *ast_interface_ansi_header;
    ast::program_declaration                      *ast_program_declaration;
    ast::program_nonansi_header                   *ast_program_nonansi_header;
    ast::program_ansi_header                      *ast_program_ansi_header;
    ast::checker_declaration                      *ast_checker_declaration;
    ast::class_declaration                        *ast_class_declaration;
    ast::interface_class_type                     *ast_interface_class_type;
    ast::package_declaration                      *ast_package_declaration;
    ast::timeunits_declaration                    *ast_timeunits_declaration;
    ast::parameter_port_list                      *ast_parameter_port_list;
    ast::parameter_port_declaration               *ast_parameter_port_declaration;
    ast::list_of_ports                            *ast_list_of_ports;
    ast::list_of_port_declarations                *ast_list_of_port_declarations;
    ast::port_declaration                         *ast_port_declaration;
    ast::port                                     *ast_port;
    ast::port_expression                          *ast_port_expression;
    ast::port_reference                           *ast_port_reference;
    ast::port_direction                           *ast_port_direction;
    ast::net_port_header                          *ast_net_port_header;
    ast::variable_port_header                     *ast_variable_port_header;
    ast::interface_port_header                    *ast_interface_port_header;
    ast::ansi_port_declaration                    *ast_ansi_port_declaration;
    ast::elaboration_system_task                  *ast_elaboration_system_task;
    ast::finish_number                            *ast_finish_number;
    ast::module_common_item                       *ast_module_common_item;
    ast::module_item                              *ast_module_item;
    ast::module_or_generate_item                  *ast_module_or_generate_item;
    ast::module_or_generate_item_declaration      *ast_module_or_generate_item_declaration;
    ast::non_port_module_item                     *ast_non_port_module_item;
    ast::parameter_override                       *ast_parameter_override;
    ast::bind_directive                           *ast_bind_directive;
    ast::bind_target_scope                        *ast_bind_target_scope;
    ast::bind_target_instance                     *ast_bind_target_instance;
    ast::bind_target_instance_list                *ast_bind_target_instance_list;
    ast::bind_instantiation                       *ast_bind_instantiation;
    ast::config_declaration                       *ast_config_declaration;
    ast::design_statement                         *ast_design_statement;
    ast::config_rule_statement                    *ast_config_rule_statement;
    ast::default_clause                           *ast_default_clause;
    ast::inst_clause                              *ast_inst_clause;
    ast::inst_name                                *ast_inst_name;
    ast::cell_clause                              *ast_cell_clause;
    ast::liblist_clause                           *ast_liblist_clause;
    ast::use_clause                               *ast_use_clause;
    ast::interface_or_generate_item               *ast_interface_or_generate_item;
    ast::extern_tf_declaration                    *ast_extern_tf_declaration;
    ast::interface_item                           *ast_interface_item;
    ast::non_port_interface_item                  *ast_non_port_interface_item;
    ast::program_item                             *ast_program_item;
    ast::non_port_program_item                    *ast_non_port_program_item;
    ast::program_generate_item                    *ast_program_generate_item;
    ast::checker_port_list                        *ast_checker_port_list;
    ast::checker_port_item                        *ast_checker_port_item;
    ast::checker_port_direction                   *ast_checker_port_direction;
    ast::checker_or_generate_item                 *ast_checker_or_generate_item;
    ast::checker_or_generate_item_declaration     *ast_checker_or_generate_item_declaration;
    ast::checker_generate_item                    *ast_checker_generate_item;
    ast::class_item                               *ast_class_item;
    ast::class_property                           *ast_class_property;
    ast::class_method                             *ast_class_method;
    ast::class_constructor_prototype              *ast_class_constructor_prototype;
    ast::class_constraint                         *ast_class_constraint;
    ast::class_item_qualifier                     *ast_class_item_qualifier;
    ast::property_qualifier                       *ast_property_qualifier;
    ast::random_qualifier                         *ast_random_qualifier;
    ast::method_qualifier                         *ast_method_qualifier;
    ast::method_prototype                         *ast_method_prototype;
    ast::class_constructor_declaration            *ast_class_constructor_declaration;
    ast::constraint_declaration                   *ast_constraint_declaration;
    ast::constraint_block                         *ast_constraint_block;
    ast::constraint_block_item                    *ast_constraint_block_item;
    ast::solve_before_list                        *ast_solve_before_list;
    ast::constraint_primary                       *ast_constraint_primary;
    ast::constraint_expression                    *ast_constraint_expression;
    ast::uniqueness_constraint                    *ast_uniqueness_constraint;
    ast::constraint_set                           *ast_constraint_set;
    ast::dist_list                                *ast_dist_list;
    ast::dist_item                                *ast_dist_item;
    ast::dist_weight                              *ast_dist_weight;
    ast::constraint_prototype                     *ast_constraint_prototype;
    ast::constraint_prototype_qualifier           *ast_constraint_prototype_qualifier;
    ast::extern_constraint_declaration            *ast_extern_constraint_declaration;
    ast::identifier_list                          *ast_identifier_list;
    ast::package_item                             *ast_package_item;
    ast::package_or_generate_item_declaration     *ast_package_or_generate_item_declaration;
    ast::anonymous_program                        *ast_anonymous_program;
    ast::anonymous_program_item                   *ast_anonymous_program_item;
    ast::local_parameter_declaration              *ast_local_parameter_declaration;
    ast::parameter_declaration                    *ast_parameter_declaration;
    ast::specparam_declaration                    *ast_specparam_declaration;
    ast::inout_declaration                        *ast_inout_declaration;
    ast::input_declaration                        *ast_input_declaration;
    ast::output_declaration                       *ast_output_declaration;
    ast::interface_port_declaration               *ast_interface_port_declaration;
    ast::ref_declaration                          *ast_ref_declaration;
    ast::data_declaration                         *ast_data_declaration;
    ast::package_import_declaration               *ast_package_import_declaration;
    ast::package_import_item                      *ast_package_import_item;
    ast::package_export_declaration               *ast_package_export_declaration;
    ast::genvar_declaration                       *ast_genvar_declaration;
    ast::net_declaration                          *ast_net_declaration;
    ast::type_declaration                         *ast_type_declaration;
    ast::net_type_declaration                     *ast_net_type_declaration;
    ast::lifetime                                 *ast_lifetime;
    ast::casting_type                             *ast_casting_type;
    ast::data_type                                *ast_data_type;
    ast::data_type_or_implicit                    *ast_data_type_or_implicit;
    ast::implicit_data_type                       *ast_implicit_data_type;
    ast::enum_base_type                           *ast_enum_base_type;
    ast::enum_name_declaration                    *ast_enum_name_declaration;
    ast::class_scope                              *ast_class_scope;
    ast::class_type                               *ast_class_type;
    ast::integer_type                             *ast_integer_type;
    ast::integer_atom_type                        *ast_integer_atom_type;
    ast::integer_vector_type                      *ast_integer_vector_type;
    ast::non_integer_type                         *ast_non_integer_type;
    ast::net_type                                 *ast_net_type;
    ast::net_port_type                            *ast_net_port_type;
    ast::variable_port_type                       *ast_variable_port_type;
    ast::var_data_type                            *ast_var_data_type;
    ast::signing                                  *ast_signing;
    ast::simple_type                              *ast_simple_type;
    ast::struct_union_member                      *ast_struct_union_member;
    ast::data_type_or_void                        *ast_data_type_or_void;
    ast::struct_union                             *ast_struct_union;
    ast::type_reference                           *ast_type_reference;
    ast::drive_strength                           *ast_drive_strength;
    ast::strength0                                *ast_strength0;
    ast::strength1                                *ast_strength1;
    ast::charge_strength                          *ast_charge_strength;
    ast::delay3                                   *ast_delay3;
    ast::delay2                                   *ast_delay2;
    ast::delay_value                              *ast_delay_value;
    ast::list_of_defparam_assignments             *ast_list_of_defparam_assignments;
    ast::list_of_genvar_identifiers               *ast_list_of_genvar_identifiers;
    ast::list_of_interface_identifiers            *ast_list_of_interface_identifiers;
    ast::list_of_net_decl_assignments             *ast_list_of_net_decl_assignments;
    ast::list_of_param_assignments                *ast_list_of_param_assignments;
    ast::list_of_port_identifiers                 *ast_list_of_port_identifiers;
    ast::list_of_udp_port_identifiers             *ast_list_of_udp_port_identifiers;
    ast::list_of_specparam_assignments            *ast_list_of_specparam_assignments;
    ast::list_of_tf_variable_identifiers          *ast_list_of_tf_variable_identifiers;
    ast::list_of_type_assignments                 *ast_list_of_type_assignments;
    ast::list_of_variable_decl_assignments        *ast_list_of_variable_decl_assignments;
    ast::list_of_variable_identifiers             *ast_list_of_variable_identifiers;
    ast::list_of_variable_port_identifiers        *ast_list_of_variable_port_identifiers;
    ast::defparam_assignment                      *ast_defparam_assignment;
    ast::net_decl_assignment                      *ast_net_decl_assignment;
    ast::param_assignment                         *ast_param_assignment;
    ast::specparam_assignment                     *ast_specparam_assignment;
    ast::type_assignment                          *ast_type_assignment;
    ast::pulse_control_specparam                  *ast_pulse_control_specparam;
    ast::error_limit_value                        *ast_error_limit_value;
    ast::reject_limit_value                       *ast_reject_limit_value;
    ast::limit_value                              *ast_limit_value;
    ast::variable_decl_assignment                 *ast_variable_decl_assignment;
    ast::class_new                                *ast_class_new;
    ast::dynamic_array_new                        *ast_dynamic_array_new;
    ast::unpacked_dimension                       *ast_unpacked_dimension;
    ast::packed_dimension                         *ast_packed_dimension;
    ast::associative_dimension                    *ast_associative_dimension;
    ast::variable_dimension                       *ast_variable_dimension;
    ast::queue_dimension                          *ast_queue_dimension;
    ast::unsized_dimension                        *ast_unsized_dimension;
    ast::function_data_type_or_implicit           *ast_function_data_type_or_implicit;
    ast::function_declaration                     *ast_function_declaration;
    ast::function_body_declaration                *ast_function_body_declaration;
    ast::function_prototype                       *ast_function_prototype;
    ast::dpi_import_export                        *ast_dpi_import_export;
    ast::dpi_spec_string                          *ast_dpi_spec_string;
    ast::dpi_function_import_property             *ast_dpi_function_import_property;
    ast::dpi_task_import_property                 *ast_dpi_task_import_property;
    ast::dpi_function_proto                       *ast_dpi_function_proto;
    ast::dpi_task_proto                           *ast_dpi_task_proto;
    ast::task_declaration                         *ast_task_declaration;
    ast::task_body_declaration                    *ast_task_body_declaration;
    ast::tf_item_declaration                      *ast_tf_item_declaration;
    ast::tf_port_list                             *ast_tf_port_list;
    ast::tf_port_item                             *ast_tf_port_item;
    ast::tf_port_direction                        *ast_tf_port_direction;
    ast::tf_port_declaration                      *ast_tf_port_declaration;
    ast::task_prototype                           *ast_task_prototype;
    ast::block_item_declaration                   *ast_block_item_declaration;
    ast::overload_declaration                     *ast_overload_declaration;
    ast::overload_operator                        *ast_overload_operator;
    ast::overload_proto_formals                   *ast_overload_proto_formals;
    ast::modport_declaration                      *ast_modport_declaration;
    ast::modport_item                             *ast_modport_item;
    ast::modport_ports_declaration                *ast_modport_ports_declaration;
    ast::modport_clocking_declaration             *ast_modport_clocking_declaration;
    ast::modport_simple_ports_declaration         *ast_modport_simple_ports_declaration;
    ast::modport_simple_port                      *ast_modport_simple_port;
    ast::modport_tf_ports_declaration             *ast_modport_tf_ports_declaration;
    ast::modport_tf_port                          *ast_modport_tf_port;
    ast::import_export                            *ast_import_export;
    ast::concurrent_assertion_item                *ast_concurrent_assertion_item;
    ast::concurrent_assertion_statement           *ast_concurrent_assertion_statement;
    ast::assert_property_statement                *ast_assert_property_statement;
    ast::assume_property_statement                *ast_assume_property_statement;
    ast::cover_property_statement                 *ast_cover_property_statement;
    ast::expect_property_statement                *ast_expect_property_statement;
    ast::cover_sequence_statement                 *ast_cover_sequence_statement;
    ast::restrict_property_statement              *ast_restrict_property_statement;
    ast::property_instance                        *ast_property_instance;
    ast::property_list_of_arguments               *ast_property_list_of_arguments;
    ast::property_actual_arg                      *ast_property_actual_arg;
    ast::assertion_item_declaration               *ast_assertion_item_declaration;
    ast::property_declaration                     *ast_property_declaration;
    ast::property_port_list                       *ast_property_port_list;
    ast::property_port_item                       *ast_property_port_item;
    ast::property_lvar_port_direction             *ast_property_lvar_port_direction;
    ast::property_formal_type                     *ast_property_formal_type;
    ast::property_spec                            *ast_property_spec;
    ast::property_expr                            *ast_property_expr;
    ast::property_case_item                       *ast_property_case_item;
    ast::sequence_declaration                     *ast_sequence_declaration;
    ast::sequence_port_list                       *ast_sequence_port_list;
    ast::sequence_port_item                       *ast_sequence_port_item;
    ast::sequence_lvar_port_direction             *ast_sequence_lvar_port_direction;
    ast::sequence_formal_type                     *ast_sequence_formal_type;
    ast::sequence_expr                            *ast_sequence_expr;
    ast::cycle_delay_range                        *ast_cycle_delay_range;
    ast::sequence_method_call                     *ast_sequence_method_call;
    ast::sequence_match_item                      *ast_sequence_match_item;
    ast::sequence_instance                        *ast_sequence_instance;
    ast::sequence_list_of_arguments               *ast_sequence_list_of_arguments;
    ast::sequence_actual_arg                      *ast_sequence_actual_arg;
    ast::boolean_abbrev                           *ast_boolean_abbrev;
    ast::sequence_abbrev                          *ast_sequence_abbrev;
    ast::consecutive_repetition                   *ast_consecutive_repetition;
    ast::non_consecutive_repetition               *ast_non_consecutive_repetition;
    ast::goto_repetition                          *ast_goto_repetition;
    ast::const_or_range_expression                *ast_const_or_range_expression;
    ast::cycle_delay_const_range_expression       *ast_cycle_delay_const_range_expression;
    ast::expression_or_dist                       *ast_expression_or_dist;
    ast::assertion_variable_declaration           *ast_assertion_variable_declaration;
    ast::let_declaration                          *ast_let_declaration;
    ast::let_identifier                           *ast_let_identifier;
    ast::let_port_list                            *ast_let_port_list;
    ast::let_port_item                            *ast_let_port_item;
    ast::let_formal_type                          *ast_let_formal_type;
    ast::let_expression                           *ast_let_expression;
    ast::let_list_of_arguments                    *ast_let_list_of_arguments;
    ast::let_actual_arg                           *ast_let_actual_arg;
    ast::covergroup_declaration                   *ast_covergroup_declaration;
    ast::coverage_spec_or_option                  *ast_coverage_spec_or_option;
    ast::coverage_option                          *ast_coverage_option;
    ast::coverage_spec                            *ast_coverage_spec;
    ast::coverage_event                           *ast_coverage_event;
    ast::block_event_expression                   *ast_block_event_expression;
    ast::hierarchical_btf_identifier              *ast_hierarchical_btf_identifier;
    ast::cover_point                              *ast_cover_point;
    ast::bins_or_empty                            *ast_bins_or_empty;
    ast::bins_or_options                          *ast_bins_or_options;
    ast::bins_keyword                             *ast_bins_keyword;
    ast::trans_list                               *ast_trans_list;
    ast::trans_set                                *ast_trans_set;
    ast::trans_range_list                         *ast_trans_range_list;
    ast::trans_item                               *ast_trans_item;
    ast::repeat_range                             *ast_repeat_range;
    ast::cover_cross                              *ast_cover_cross;
    ast::list_of_cross_items                      *ast_list_of_cross_items;
    ast::cross_item                               *ast_cross_item;
    ast::cross_body                               *ast_cross_body;
    ast::cross_body_item                          *ast_cross_body_item;
    ast::bins_selection_or_option                 *ast_bins_selection_or_option;
    ast::bins_selection                           *ast_bins_selection;
    ast::select_expression                        *ast_select_expression;
    ast::select_condition                         *ast_select_condition;
    ast::bins_expression                          *ast_bins_expression;
    ast::covergroup_range_list                    *ast_covergroup_range_list;
    ast::covergroup_value_range                   *ast_covergroup_value_range;
    ast::with_covergroup_expression               *ast_with_covergroup_expression;
    ast::set_covergroup_expression                *ast_set_covergroup_expression;
    ast::integer_covergroup_expression            *ast_integer_covergroup_expression;
    ast::cross_set_expression                     *ast_cross_set_expression;
    ast::covergroup_expression                    *ast_covergroup_expression;
    ast::gate_instantiation                       *ast_gate_instantiation;
    ast::cmos_switch_instance                     *ast_cmos_switch_instance;
    ast::enable_gate_instance                     *ast_enable_gate_instance;
    ast::mos_switch_instance                      *ast_mos_switch_instance;
    ast::n_input_gate_instance                    *ast_n_input_gate_instance;
    ast::n_output_gate_instance                   *ast_n_output_gate_instance;
    ast::pass_switch_instance                     *ast_pass_switch_instance;
    ast::pass_enable_switch_instance              *ast_pass_enable_switch_instance;
    ast::pull_gate_instance                       *ast_pull_gate_instance;
    ast::pulldown_strength                        *ast_pulldown_strength;
    ast::pullup_strength                          *ast_pullup_strength;
    ast::enable_terminal                          *ast_enable_terminal;
    ast::inout_terminal                           *ast_inout_terminal;
    ast::input_terminal                           *ast_input_terminal;
    ast::ncontrol_terminal                        *ast_ncontrol_terminal;
    ast::output_terminal                          *ast_output_terminal;
    ast::pcontrol_terminal                        *ast_pcontrol_terminal;
    ast::cmos_switchtype                          *ast_cmos_switchtype;
    ast::enable_gatetype                          *ast_enable_gatetype;
    ast::mos_switchtype                           *ast_mos_switchtype;
    ast::n_input_gatetype                         *ast_n_input_gatetype;
    ast::n_output_gatetype                        *ast_n_output_gatetype;
    ast::pass_en_switchtype                       *ast_pass_en_switchtype;
    ast::pass_switchtype                          *ast_pass_switchtype;
    ast::module_instantiation                     *ast_module_instantiation;
    ast::parameter_value_assignment               *ast_parameter_value_assignment;
    ast::list_of_parameter_assignments            *ast_list_of_parameter_assignments;
    ast::ordered_parameter_assignment             *ast_ordered_parameter_assignment;
    ast::named_parameter_assignment               *ast_named_parameter_assignment;
    ast::hierarchical_instance                    *ast_hierarchical_instance;
    ast::name_of_instance                         *ast_name_of_instance;
    ast::list_of_port_connections                 *ast_list_of_port_connections;
    ast::ordered_port_connection                  *ast_ordered_port_connection;
    ast::named_port_connection                    *ast_named_port_connection;
    ast::interface_instantiation                  *ast_interface_instantiation;
    ast::program_instantiation                    *ast_program_instantiation;
    ast::checker_instantiation                    *ast_checker_instantiation;
    ast::list_of_checker_port_connections         *ast_list_of_checker_port_connections;
    ast::ordered_checker_port_connection          *ast_ordered_checker_port_connection;
    ast::named_checker_port_connection            *ast_named_checker_port_connection;
    ast::generate_region                          *ast_generate_region;
    ast::loop_generate_construct                  *ast_loop_generate_construct;
    ast::genvar_initialization                    *ast_genvar_initialization;
    ast::genvar_iteration                         *ast_genvar_iteration;
    ast::conditional_generate_construct           *ast_conditional_generate_construct;
    ast::if_generate_construct                    *ast_if_generate_construct;
    ast::case_generate_construct                  *ast_case_generate_construct;
    ast::case_generate_item                       *ast_case_generate_item;
    ast::generate_block                           *ast_generate_block;
    ast::generate_item                            *ast_generate_item;
    ast::udp_nonansi_declaration                  *ast_udp_nonansi_declaration;
    ast::udp_ansi_declaration                     *ast_udp_ansi_declaration;
    ast::udp_declaration                          *ast_udp_declaration;
    ast::udp_port_list                            *ast_udp_port_list;
    ast::udp_declaration_port_list                *ast_udp_declaration_port_list;
    ast::udp_port_declaration                     *ast_udp_port_declaration;
    ast::udp_output_declaration                   *ast_udp_output_declaration;
    ast::udp_input_declaration                    *ast_udp_input_declaration;
    ast::udp_reg_declaration                      *ast_udp_reg_declaration;
    ast::udp_body                                 *ast_udp_body;
    ast::combinational_body                       *ast_combinational_body;
    ast::combinational_entry                      *ast_combinational_entry;
    ast::sequential_body                          *ast_sequential_body;
    ast::udp_initial_statement                    *ast_udp_initial_statement;
    ast::init_val                                 *ast_init_val;
    ast::sequential_entry                         *ast_sequential_entry;
    ast::seq_input_list                           *ast_seq_input_list;
    ast::level_input_list                         *ast_level_input_list;
    ast::edge_input_list                          *ast_edge_input_list;
    ast::edge_indicator                           *ast_edge_indicator;
    ast::current_state                            *ast_current_state;
    ast::next_state                               *ast_next_state;
    ast::output_symbol                            *ast_output_symbol;
    ast::level_symbol                             *ast_level_symbol;
    ast::edge_symbol                              *ast_edge_symbol;
    ast::udp_instantiation                        *ast_udp_instantiation;
    ast::udp_instance                             *ast_udp_instance;
    ast::continuous_assign                        *ast_continuous_assign;
    ast::list_of_net_assignments                  *ast_list_of_net_assignments;
    ast::list_of_variable_assignments             *ast_list_of_variable_assignments;
    ast::net_alias                                *ast_net_alias;
    ast::net_assignment                           *ast_net_assignment;
    ast::initial_construct                        *ast_initial_construct;
    ast::always_construct                         *ast_always_construct;
    ast::always_keyword                           *ast_always_keyword;
    ast::final_construct                          *ast_final_construct;
    ast::blocking_assignment                      *ast_blocking_assignment;
    ast::operator_assignment                      *ast_operator_assignment;
    ast::assignment_operator                      *ast_assignment_operator;
    ast::nonblocking_assignment                   *ast_nonblocking_assignment;
    ast::procedural_continuous_assignment         *ast_procedural_continuous_assignment;
    ast::variable_assignment                      *ast_variable_assignment;
    ast::action_block                             *ast_action_block;
    ast::seq_block                                *ast_seq_block;
    ast::par_block                                *ast_par_block;
    ast::join_keyword                             *ast_join_keyword;
    ast::statement_or_null                        *ast_statement_or_null;
    ast::statement                                *ast_statement;
    ast::statement_item                           *ast_statement_item;
    ast::function_statement                       *ast_function_statement;
    ast::function_statement_or_null               *ast_function_statement_or_null;
    ast::variable_identifier_list                 *ast_variable_identifier_list;
    ast::procedural_timing_control_statement      *ast_procedural_timing_control_statement;
    ast::delay_or_event_control                   *ast_delay_or_event_control;
    ast::delay_control                            *ast_delay_control;
    ast::event_control                            *ast_event_control;
    ast::event_expression                         *ast_event_expression;
    ast::procedural_timing_control                *ast_procedural_timing_control;
    ast::jump_statement                           *ast_jump_statement;
    ast::wait_statement                           *ast_wait_statement;
    ast::event_trigger                            *ast_event_trigger;
    ast::disable_statement                        *ast_disable_statement;
    ast::conditional_statement                    *ast_conditional_statement;
    ast::unique_priority                          *ast_unique_priority;
    ast::cond_predicate                           *ast_cond_predicate;
    ast::expression_or_cond_pattern               *ast_expression_or_cond_pattern;
    ast::cond_pattern                             *ast_cond_pattern;
    ast::case_statement                           *ast_case_statement;
    ast::case_keyword                             *ast_case_keyword;
    ast::case_expression                          *ast_case_expression;
    ast::case_item                                *ast_case_item;
    ast::case_pattern_item                        *ast_case_pattern_item;
    ast::case_inside_item                         *ast_case_inside_item;
    ast::case_item_expression                     *ast_case_item_expression;
    ast::randcase_statement                       *ast_randcase_statement;
    ast::randcase_item                            *ast_randcase_item;
    ast::open_range_list                          *ast_open_range_list;
    ast::open_value_range                         *ast_open_value_range;
    ast::pattern                                  *ast_pattern;
    ast::assignment_pattern                       *ast_assignment_pattern;
    ast::structure_pattern_key                    *ast_structure_pattern_key;
    ast::array_pattern_key                        *ast_array_pattern_key;
    ast::assignment_pattern_key                   *ast_assignment_pattern_key;
    ast::assignment_pattern_expression            *ast_assignment_pattern_expression;
    ast::assignment_pattern_expression_type       *ast_assignment_pattern_expression_type;
    ast::constant_assignment_pattern_expression   *ast_constant_assignment_pattern_expression;
    ast::assignment_pattern_net_lvalue            *ast_assignment_pattern_net_lvalue;
    ast::assignment_pattern_variable_lvalue       *ast_assignment_pattern_variable_lvalue;
    ast::loop_statement                           *ast_loop_statement;
    ast::for_initialization                       *ast_for_initialization;
    ast::for_variable_declaration                 *ast_for_variable_declaration;
    ast::for_step                                 *ast_for_step;
    ast::for_step_assignment                      *ast_for_step_assignment;
    ast::loop_variables                           *ast_loop_variables;
    ast::subroutine_call_statement                *ast_subroutine_call_statement;
    ast::assertion_item                           *ast_assertion_item;
    ast::deferred_immediate_assertion_item        *ast_deferred_immediate_assertion_item;
    ast::procedural_assertion_statement           *ast_procedural_assertion_statement;
    ast::immediate_assertion_statement            *ast_immediate_assertion_statement;
    ast::simple_immediate_assertion_statement     *ast_simple_immediate_assertion_statement;
    ast::simple_immediate_assert_statement        *ast_simple_immediate_assert_statement;
    ast::simple_immediate_assume_statement        *ast_simple_immediate_assume_statement;
    ast::simple_immediate_cover_statement         *ast_simple_immediate_cover_statement;
    ast::deferred_immediate_assertion_statement   *ast_deferred_immediate_assertion_statement;
    ast::deferred_immediate_assert_statement      *ast_deferred_immediate_assert_statement;
    ast::deferred_immediate_assume_statement      *ast_deferred_immediate_assume_statement;
    ast::deferred_immediate_cover_statement       *ast_deferred_immediate_cover_statement;
    ast::clocking_declaration                     *ast_clocking_declaration;
    ast::clocking_event                           *ast_clocking_event;
    ast::clocking_item                            *ast_clocking_item;
    ast::default_skew                             *ast_default_skew;
    ast::clocking_direction                       *ast_clocking_direction;
    ast::list_of_clocking_decl_assign             *ast_list_of_clocking_decl_assign;
    ast::clocking_decl_assign                     *ast_clocking_decl_assign;
    ast::clocking_skew                            *ast_clocking_skew;
    ast::clocking_drive                           *ast_clocking_drive;
    ast::cycle_delay                              *ast_cycle_delay;
    ast::clockvar                                 *ast_clockvar;
    ast::clockvar_expression                      *ast_clockvar_expression;
    ast::randsequence_statement                   *ast_randsequence_statement;
    ast::production                               *ast_production;
    ast::rs_rule                                  *ast_rs_rule;
    ast::rs_production_list                       *ast_rs_production_list;
    ast::weight_specification                     *ast_weight_specification;
    ast::rs_code_block                            *ast_rs_code_block;
    ast::rs_prod                                  *ast_rs_prod;
    ast::production_item                          *ast_production_item;
    ast::rs_if_else                               *ast_rs_if_else;
    ast::rs_repeat                                *ast_rs_repeat;
    ast::rs_case                                  *ast_rs_case;
    ast::rs_case_item                             *ast_rs_case_item;
    ast::specify_block                            *ast_specify_block;
    ast::specify_item                             *ast_specify_item;
    ast::pulsestyle_declaration                   *ast_pulsestyle_declaration;
    ast::showcancelled_declaration                *ast_showcancelled_declaration;
    ast::path_declaration                         *ast_path_declaration;
    ast::simple_path_declaration                  *ast_simple_path_declaration;
    ast::parallel_path_description                *ast_parallel_path_description;
    ast::full_path_description                    *ast_full_path_description;
    ast::list_of_path_inputs                      *ast_list_of_path_inputs;
    ast::list_of_path_outputs                     *ast_list_of_path_outputs;
    ast::specify_input_terminal_descriptor        *ast_specify_input_terminal_descriptor;
    ast::specify_output_terminal_descriptor       *ast_specify_output_terminal_descriptor;
    ast::input_identifier                         *ast_input_identifier;
    ast::output_identifier                        *ast_output_identifier;
    ast::path_delay_value                         *ast_path_delay_value;
    ast::list_of_path_delay_expressions           *ast_list_of_path_delay_expressions;
    ast::t_path_delay_expression                  *ast_t_path_delay_expression;
    ast::trise_path_delay_expression              *ast_trise_path_delay_expression;
    ast::tfall_path_delay_expression              *ast_tfall_path_delay_expression;
    ast::tz_path_delay_expression                 *ast_tz_path_delay_expression;
    ast::t01_path_delay_expression                *ast_t01_path_delay_expression;
    ast::t10_path_delay_expression                *ast_t10_path_delay_expression;
    ast::t0z_path_delay_expression                *ast_t0z_path_delay_expression;
    ast::tz1_path_delay_expression                *ast_tz1_path_delay_expression;
    ast::t1z_path_delay_expression                *ast_t1z_path_delay_expression;
    ast::tz0_path_delay_expression                *ast_tz0_path_delay_expression;
    ast::t0x_path_delay_expression                *ast_t0x_path_delay_expression;
    ast::tx1_path_delay_expression                *ast_tx1_path_delay_expression;
    ast::t1x_path_delay_expression                *ast_t1x_path_delay_expression;
    ast::tx0_path_delay_expression                *ast_tx0_path_delay_expression;
    ast::txz_path_delay_expression                *ast_txz_path_delay_expression;
    ast::tzx_path_delay_expression                *ast_tzx_path_delay_expression;
    ast::path_delay_expression                    *ast_path_delay_expression;
    ast::edge_sensitive_path_declaration          *ast_edge_sensitive_path_declaration;
    ast::parallel_edge_sensitive_path_description *ast_parallel_edge_sensitive_path_description;
    ast::full_edge_sensitive_path_description     *ast_full_edge_sensitive_path_description;
    ast::data_source_expression                   *ast_data_source_expression;
    ast::edge_identifier                          *ast_edge_identifier;
    ast::state_dependent_path_declaration         *ast_state_dependent_path_declaration;
    ast::polarity_operator                        *ast_polarity_operator;
    ast::system_timing_check                      *ast_system_timing_check;
    ast::dollarsign_setup_timing_check            *ast_dollarsign_setup_timing_check;
    ast::dollarsign_hold_timing_check             *ast_dollarsign_hold_timing_check;
    ast::dollarsign_setuphold_timing_check        *ast_dollarsign_setuphold_timing_check;
    ast::dollarsign_recovery_timing_check         *ast_dollarsign_recovery_timing_check;
    ast::dollarsign_removal_timing_check          *ast_dollarsign_removal_timing_check;
    ast::dollarsign_recrem_timing_check           *ast_dollarsign_recrem_timing_check;
    ast::dollarsign_skew_timing_check             *ast_dollarsign_skew_timing_check;
    ast::dollarsign_timeskew_timing_check         *ast_dollarsign_timeskew_timing_check;
    ast::dollarsign_fullskew_timing_check         *ast_dollarsign_fullskew_timing_check;
    ast::dollarsign_period_timing_check           *ast_dollarsign_period_timing_check;
    ast::dollarsign_width_timing_check            *ast_dollarsign_width_timing_check;
    ast::dollarsign_nochange_timing_check         *ast_dollarsign_nochange_timing_check;
    ast::timecheck_condition                      *ast_timecheck_condition;
    ast::controlled_reference_event               *ast_controlled_reference_event;
    ast::data_event                               *ast_data_event;
    ast::delayed_data                             *ast_delayed_data;
    ast::delayed_reference                        *ast_delayed_reference;
    ast::end_edge_offset                          *ast_end_edge_offset;
    ast::event_based_flag                         *ast_event_based_flag;
    ast::notifier                                 *ast_notifier;
    ast::reference_event                          *ast_reference_event;
    ast::remain_active_flag                       *ast_remain_active_flag;
    ast::timestamp_condition                      *ast_timestamp_condition;
    ast::start_edge_offset                        *ast_start_edge_offset;
    ast::threshold                                *ast_threshold;
    ast::timing_check_limit                       *ast_timing_check_limit;
    ast::timing_check_event                       *ast_timing_check_event;
    ast::controlled_timing_check_event            *ast_controlled_timing_check_event;
    ast::timing_check_event_control               *ast_timing_check_event_control;
    ast::specify_terminal_descriptor              *ast_specify_terminal_descriptor;
    ast::edge_control_specifier                   *ast_edge_control_specifier;
    ast::edge_descriptor                          *ast_edge_descriptor;
    ast::zero_or_one                              *ast_zero_or_one;
    ast::z_or_x                                   *ast_z_or_x;
    ast::timing_check_condition                   *ast_timing_check_condition;
    ast::scalar_timing_check_condition            *ast_scalar_timing_check_condition;
    ast::scalar_constant                          *ast_scalar_constant;
    ast::concatenation                            *ast_concatenation;
    ast::constant_concatenation                   *ast_constant_concatenation;
    ast::constant_multiple_concatenation          *ast_constant_multiple_concatenation;
    ast::module_path_concatenation                *ast_module_path_concatenation;
    ast::module_path_multiple_concatenation       *ast_module_path_multiple_concatenation;
    ast::multiple_concatenation                   *ast_multiple_concatenation;
    ast::streaming_concatenation                  *ast_streaming_concatenation;
    ast::stream_operator                          *ast_stream_operator;
    ast::slice_size                               *ast_slice_size;
    ast::stream_concatenation                     *ast_stream_concatenation;
    ast::stream_expression                        *ast_stream_expression;
    ast::array_range_expression                   *ast_array_range_expression;
    ast::empty_queue                              *ast_empty_queue;
    ast::constant_function_call                   *ast_constant_function_call;
    ast::tf_call                                  *ast_tf_call;
    ast::system_tf_call                           *ast_system_tf_call;
    ast::subroutine_call                          *ast_subroutine_call;
    ast::function_subroutine_call                 *ast_function_subroutine_call;
    ast::list_of_arguments                        *ast_list_of_arguments;
    ast::method_call                              *ast_method_call;
    ast::method_call_body                         *ast_method_call_body;
    ast::built_in_method_call                     *ast_built_in_method_call;
    ast::array_manipulation_call                  *ast_array_manipulation_call;
    ast::randomize_call                           *ast_randomize_call;
    ast::method_call_root                         *ast_method_call_root;
    ast::array_method_name                        *ast_array_method_name;
    ast::inc_or_dec_expression                    *ast_inc_or_dec_expression;
    ast::conditional_expression                   *ast_conditional_expression;
    ast::constant_expression                      *ast_constant_expression;
    ast::constant_mintypmax_expression            *ast_constant_mintypmax_expression;
    ast::constant_param_expression                *ast_constant_param_expression;
    ast::param_expression                         *ast_param_expression;
    ast::constant_range_expression                *ast_constant_range_expression;
    ast::constant_part_select_range               *ast_constant_part_select_range;
    ast::constant_range                           *ast_constant_range;
    ast::constant_indexed_range                   *ast_constant_indexed_range;
    ast::expression                               *ast_expression;
    ast::tagged_union_expression                  *ast_tagged_union_expression;
    ast::inside_expression                        *ast_inside_expression;
    ast::value_range                              *ast_value_range;
    ast::mintypmax_expression                     *ast_mintypmax_expression;
    ast::module_path_conditional_expression       *ast_module_path_conditional_expression;
    ast::module_path_expression                   *ast_module_path_expression;
    ast::module_path_mintypmax_expression         *ast_module_path_mintypmax_expression;
    ast::part_select_range                        *ast_part_select_range;
    ast::indexed_range                            *ast_indexed_range;
    ast::genvar_expression                        *ast_genvar_expression;
    ast::constant_primary                         *ast_constant_primary;
    ast::module_path_primary                      *ast_module_path_primary;
    ast::primary                                  *ast_primary;
    ast::class_qualifier                          *ast_class_qualifier;
    ast::range_expression                         *ast_range_expression;
    ast::primary_literal                          *ast_primary_literal;
    ast::time_literal                             *ast_time_literal;
    ast::time_unit                                *ast_time_unit;
    ast::implicit_class_handle                    *ast_implicit_class_handle;
    ast::bit_select                               *ast_bit_select;
    ast::select                                   *ast_select;
    ast::nonrange_select                          *ast_nonrange_select;
    ast::constant_bit_select                      *ast_constant_bit_select;
    ast::constant_select                          *ast_constant_select;
    ast::constant_cast                            *ast_constant_cast;
    ast::constant_let_expression                  *ast_constant_let_expression;
    ast::cast                                     *ast_cast;
    ast::net_lvalue                               *ast_net_lvalue;
    ast::variable_lvalue                          *ast_variable_lvalue;
    ast::nonrange_variable_lvalue                 *ast_nonrange_variable_lvalue;
    ast::unary_operator                           *ast_unary_operator;
    ast::binary_operator                          *ast_binary_operator;
    ast::inc_or_dec_operator                      *ast_inc_or_dec_operator;
    ast::unary_module_path_operator               *ast_unary_module_path_operator;
    ast::binary_module_path_operator              *ast_binary_module_path_operator;
    ast::number                                   *ast_number;
    ast::integral_number                          *ast_integral_number;
    ast::decimal_number                           *ast_decimal_number;
    ast::octal_number                             *ast_octal_number;
    ast::binary_number                            *ast_binary_number;
    ast::hex_number                               *ast_hex_number;
    ast::unsigned_number                          *ast_unsigned_number;
    ast::real_number                              *ast_real_number;
    ast::fixed_point_number                       *ast_fixed_point_number;
    ast::unbased_unsized_literal                  *ast_unbased_unsized_literal;
    ast::string_literal                           *ast_string_literal;
    ast::attribute_instance                       *ast_attribute_instance;
    ast::attr_spec                                *ast_attr_spec;
    ast::attr_name                                *ast_attr_name;
    ast::block_identifier                         *ast_block_identifier;
    ast::bin_identifier                           *ast_bin_identifier;
    ast::c_identifier                             *ast_c_identifier;
    ast::cell_identifier                          *ast_cell_identifier;
    ast::checker_identifier                       *ast_checker_identifier;
    ast::class_identifier                         *ast_class_identifier;
    ast::class_variable_identifier                *ast_class_variable_identifier;
    ast::clocking_identifier                      *ast_clocking_identifier;
    ast::config_identifier                        *ast_config_identifier;
    ast::const_identifier                         *ast_const_identifier;
    ast::constraint_identifier                    *ast_constraint_identifier;
    ast::covergroup_identifier                    *ast_covergroup_identifier;
    ast::cover_point_identifier                   *ast_cover_point_identifier;
    ast::cross_identifier                         *ast_cross_identifier;
    ast::dynamic_array_variable_identifier        *ast_dynamic_array_variable_identifier;
    ast::enum_identifier                          *ast_enum_identifier;
    ast::escaped_identifier                       *ast_escaped_identifier;
    ast::formal_port_identifier                   *ast_formal_port_identifier;
    ast::function_identifier                      *ast_function_identifier;
    ast::generate_block_identifier                *ast_generate_block_identifier;
    ast::genvar_identifier                        *ast_genvar_identifier;
    ast::hierarchical_array_identifier            *ast_hierarchical_array_identifier;
    ast::hierarchical_block_identifier            *ast_hierarchical_block_identifier;
    ast::hierarchical_event_identifier            *ast_hierarchical_event_identifier;
    ast::hierarchical_identifier                  *ast_hierarchical_identifier;
    ast::hierarchical_net_identifier              *ast_hierarchical_net_identifier;
    ast::hierarchical_parameter_identifier        *ast_hierarchical_parameter_identifier;
    ast::hierarchical_property_identifier         *ast_hierarchical_property_identifier;
    ast::hierarchical_sequence_identifier         *ast_hierarchical_sequence_identifier;
    ast::hierarchical_task_identifier             *ast_hierarchical_task_identifier;
    ast::hierarchical_tf_identifier               *ast_hierarchical_tf_identifier;
    ast::hierarchical_variable_identifier         *ast_hierarchical_variable_identifier;
    ast::identifier                               *ast_identifier;
    ast::index_variable_identifier                *ast_index_variable_identifier;
    ast::interface_identifier                     *ast_interface_identifier;
    ast::interface_instance_identifier            *ast_interface_instance_identifier;
    ast::inout_port_identifier                    *ast_inout_port_identifier;
    ast::input_port_identifier                    *ast_input_port_identifier;
    ast::instance_identifier                      *ast_instance_identifier;
    ast::library_identifier                       *ast_library_identifier;
    ast::member_identifier                        *ast_member_identifier;
    ast::method_identifier                        *ast_method_identifier;
    ast::modport_identifier                       *ast_modport_identifier;
    ast::module_identifier                        *ast_module_identifier;
    ast::net_identifier                           *ast_net_identifier;
    ast::net_type_identifier                      *ast_net_type_identifier;
    ast::output_port_identifier                   *ast_output_port_identifier;
    ast::package_identifier                       *ast_package_identifier;
    ast::package_scope                            *ast_package_scope;
    ast::parameter_identifier                     *ast_parameter_identifier;
    ast::port_identifier                          *ast_port_identifier;
    ast::production_identifier                    *ast_production_identifier;
    ast::program_identifier                       *ast_program_identifier;
    ast::property_identifier                      *ast_property_identifier;
    ast::ps_class_identifier                      *ast_ps_class_identifier;
    ast::ps_covergroup_identifier                 *ast_ps_covergroup_identifier;
    ast::ps_checker_identifier                    *ast_ps_checker_identifier;
    ast::ps_identifier                            *ast_ps_identifier;
    ast::ps_or_hierarchical_array_identifier      *ast_ps_or_hierarchical_array_identifier;
    ast::ps_or_hierarchical_net_identifier        *ast_ps_or_hierarchical_net_identifier;
    ast::ps_or_hierarchical_property_identifier   *ast_ps_or_hierarchical_property_identifier;
    ast::ps_or_hierarchical_sequence_identifier   *ast_ps_or_hierarchical_sequence_identifier;
    ast::ps_or_hierarchical_tf_identifier         *ast_ps_or_hierarchical_tf_identifier;
    ast::ps_parameter_identifier                  *ast_ps_parameter_identifier;
    ast::ps_type_identifier                       *ast_ps_type_identifier;
    ast::sequence_identifier                      *ast_sequence_identifier;
    ast::signal_identifier                        *ast_signal_identifier;
    ast::simple_identifier                        *ast_simple_identifier;
    ast::specparam_identifier                     *ast_specparam_identifier;
    ast::system_tf_identifier                     *ast_system_tf_identifier;
    ast::task_identifier                          *ast_task_identifier;
    ast::tf_identifier                            *ast_tf_identifier;
    ast::terminal_identifier                      *ast_terminal_identifier;
    ast::topmodule_identifier                     *ast_topmodule_identifier;
    ast::type_identifier                          *ast_type_identifier;
    ast::udp_identifier                           *ast_udp_identifier;
    ast::variable_identifier                      *ast_variable_identifier;
    ast::file_path_spec                           *ast_file_path_spec;
}



%token SEMICOLON /* ; */
%token LIBRARY_ /* library */
%token COMMA /* , */
%token DASH_INCDIR_ /* -incdir */
%token INCLUDE_ /* include */
%token ENDMODULE_ /* endmodule */
%token COLON /* : */
%token EXTERN_ /* extern */
%token MODULE_ /* module */
%token MACROMODULE_ /* macromodule */
%token ENDINTERFACE_ /* endinterface */
%token INTERFACE_ /* interface */
%token LP /* ( */
%token DOT_STAR /* .* */
%token RP /* ) */
%token ENDPROGRAM_ /* endprogram */
%token PROGRAM_ /* program */
%token CHECKER_ /* checker */
%token ENDCHECKER_ /* endchecker */
%token VIRTUAL_ /* virtual */
%token CLASS_ /* class */
%token EXTENDS_ /* extends */
%token IMPLEMENTS_ /* implements */
%token ENDCLASS_ /* endclass */
%token PACKAGE_ /* package */
%token ENDPACKAGE_ /* endpackage */
%token TIMEUNIT_ /* timeunit */
%token SLASH /* / */
%token TIMEPRECISION_ /* timeprecision */
%token SHARP /* # */
%token TYPE_ /* type */
%token DOT /* . */
%token LMP /* { */
%token RMP /* } */
%token INPUT_ /* input */
%token OUTPUT_ /* output */
%token INOUT_ /* inout */
%token REF_ /* ref */
%token EQ /* = */
%token DOLLAR_FATAL_ /* dollarsign_fatal */
%token DOLLAR_ERROR_ /* dollarsign_error */
%token DOLLAR_WARNING_ /* dollarsign_warning */
%token DOLLAR_INFO_ /* dollarsign_info */
%token ZERO_ /* 0 */
%token ONE_ /* 1 */
%token TWO_ /* 2 */
%token DEFAULT_ /* default */
%token CLOCKING_ /* clocking */
%token DISABLE_ /* disable */
%token IFF_ /* iff */
%token DEFPARAM_ /* defparam */
%token BIND_ /* bind */
%token CONFIG_ /* config */
%token ENDCONFIG_ /* endconfig */
%token DESIGN_ /* design */
%token INSTANCE_ /* instance */
%token CELL_ /* cell */
%token LIBLIST_ /* liblist */
%token USE_ /* use */
%token FORKJOIN_ /* forkjoin */
%token RAND_ /* rand */
%token CONST_ /* const */
%token PURE_ /* pure */
%token FUNCTION_ /* function */
%token NEW_ /* new */
%token STATIC_ /* static */
%token PROTECTED_ /* protected */
%token LOCAL_ /* local */
%token RANDC_ /* randc */
%token SUPER_ /* super */
%token ENDFUNCTION_ /* endfunction */
%token CONSTRAINT_ /* constraint */
%token SOLVE_ /* solve */
%token BEFORE_ /* before */
%token SOFT_ /* soft */
%token RIGHTARROW /* -> */
%token IF_ /* if */
%token ELSE_ /* else */
%token FOREACH_ /* foreach */
%token LSP /* [ */
%token RSP /* ] */
%token UNIQUE_ /* unique */
%token COLON_EQUAL /* := */
%token COLON_SLASH /* :/ */
%token LOCALPARAM_ /* localparam */
%token PARAMETER_ /* parameter */
%token SPECPARAM_ /* specparam */
%token VAR_ /* var */
%token IMPORT_ /* import */
%token COLON2 /* :: */
%token STAR /* * */
%token EXPORT_ /* export */
%token STAR_COLON2_STAR /* *::* */
%token GENVAR_ /* genvar */
%token VECTORED_ /* vectored */
%token SCALARED_ /* scalared */
%token INTERCONNECT_ /* interconnect */
%token TYPEDEF_ /* typedef */
%token ENUM_ /* enum */
%token STRUCT_ /* struct */
%token UNION_ /* union */
%token NETTYPE_ /* nettype */
%token WITH_ /* with */
%token AUTOMATIC_ /* automatic */
%token STRING_ /* string */
%token PACKED_ /* packed */
%token CHANDLE_ /* chandle */
%token EVENT_ /* event */
%token BYTE_ /* byte */
%token SHORTINT_ /* shortint */
%token INT_ /* int */
%token LONGINT_ /* longint */
%token INTEGER_ /* integer */
%token TIME_ /* time */
%token BIT_ /* bit */
%token LOGIC_ /* logic */
%token REG_ /* reg */
%token SHORTREAL_ /* shortreal */
%token REAL_ /* real */
%token REALTIME_ /* realtime */
%token SUPPLY0_ /* supply0 */
%token SUPPLY1_ /* supply1 */
%token TRI_ /* tri */
%token TRIAND_ /* triand */
%token TRIOR_ /* trior */
%token TRIREG_ /* trireg */
%token TRI0_ /* tri0 */
%token TRI1_ /* tri1 */
%token UWIRE_ /* uwire */
%token WIRE_ /* wire */
%token WAND_ /* wand */
%token WOR_ /* wor */
%token SIGNED_ /* signed */
%token UNSIGNED_ /* unsigned */
%token VOID_ /* void */
%token TAGGED_ /* tagged */
%token HIGHZ1_ /* highz1 */
%token HIGHZ0_ /* highz0 */
%token STRONG0_ /* strong0 */
%token PULL0_ /* pull0 */
%token WEAK0_ /* weak0 */
%token STRONG1_ /* strong1 */
%token PULL1_ /* pull1 */
%token WEAK1_ /* weak1 */
%token SMALL_ /* small */
%token MEDIUM_ /* medium */
%token LARGE_ /* large */
%token ONESTEP_ /* 1step */
%token DOLLAR_ /* dollarsign_ */
%token TASK_ /* task */
%token DPI_C_ /* DPI-C */
%token DPI_ /* DPI */
%token CONTEXT_ /* context */
%token ENDTASK_ /* endtask */
%token PLUS /* + */
%token PLUS2 /* ++ */
%token MINUS /* - */
%token MINUS2 /* -- */
%token STAR2 /* ** */
%token PERCENT /* % */
%token EQ2 /* == */
%token NEQ /* != */
%token LT /* < */
%token LTE /* <= */
%token GT /* > */
%token GTE /* >= */
%token MODPORT_ /* modport */
%token ASSERT_ /* assert */
%token PROPERTY_ /* property */
%token ASSUME_ /* assume */
%token COVER_ /* cover */
%token EXPECT_ /* expect */
%token SEQUENCE_ /* sequence */
%token RESTRICT_ /* restrict */
%token ENDPROPERTY_ /* endproperty */
%token STRONG_ /* strong */
%token WEAK_ /* weak */
%token NOT_ /* not */
%token OR_ /* or */
%token AND_ /* and */
%token BAR_DASH_GT /* |-> */
%token BAR_EQ_GT /* |=> */
%token CASE_ /* case */
%token ENDCASE_ /* endcase */
%token SHARP_DASH_SHARP /* #-# */
%token SHARP_EQ_SHARP /* #=# */
%token NEXTTIME_ /* nexttime */
%token S_NEXTTIME_ /* s_nexttime */
%token ALWAYS_ /* always */
%token S_ALWAYS_ /* s_always */
%token S_EVENTUALLY_ /* s_eventually */
%token UNTIL_ /* until */
%token S_UNTIL_ /* s_until */
%token UNTIL_WITH_ /* until_with */
%token S_UNTIL_WITH_ /* s_until_with */
%token IMPLIES_ /* implies */
%token ACCEPT_ON_ /* accept_on */
%token REJECT_ON_ /* reject_on */
%token SYNC_ACCEPT_ON_ /* sync_accept_on */
%token SYNC_REJECT_ON_ /* sync_reject_on */
%token ENDSEQUENCE_ /* endsequence */
%token UNTYPED_ /* untyped */
%token INTERSECT_ /* intersect */
%token FIRST_MATCH_ /* first_match */
%token THROUGHOUT_ /* throughout */
%token WITHIN_ /* within */
%token SHARP2 /* ## */
%token LSP_STAR_RSP /* [*] */
%token LSP_PLUS_RSP /* [+] */
%token LSP_STAR /* [* */
%token LSP_EQ /* [= */
%token LSP_DASH_GT /* [-> */
%token DIST_ /* dist */
%token LET_ /* let */
%token COVERGROUP_ /* covergroup */
%token ENDGROUP_ /* endgroup */
%token OPTION_ /* option */
%token TYPE_OPTION_ /* type_option */
%token SAMPLE_ /* sample */
%token AT2 /* @@ */
%token BEGIN_ /* begin */
%token END_ /* end */
%token COVERPOINT_ /* coverpoint */
%token WILDCARD_ /* wildcard */
%token BINS_ /* bins */
%token ILLEGRAL_BINS_ /* illegal_bins */
%token IGNORE_BINS_ /* ignore_bins */
%token EQ_GT /* => */
%token CROSS_ /* cross */
%token NOT /* ! */
%token AND2 /* && */
%token BAR2 /* || */
%token MATCHES_ /* matches */
%token BINSOF_ /* binsof */
%token PULLDOWN_ /* pulldown */
%token PULLUP_ /* pullup */
%token CMOS_ /* cmos */
%token RCMOS_ /* rcmos */
%token BUFIF0_ /* bufif0 */
%token BUFIF1_ /* bufif1 */
%token NOTIF0_ /* notif0 */
%token NOTIF1_ /* notif1 */
%token NMOS_ /* nmos */
%token PMOS_ /* pmos */
%token RNMOS_ /* rnmos */
%token RPMOS_ /* rpmos */
%token NAND_ /* nand */
%token NOR_ /* nor */
%token XOR_ /* xor */
%token XNOR_ /* xnor */
%token BUF_ /* buf */
%token TRANIF0_ /* tranif0 */
%token TRANIF1_ /* tranif1 */
%token RTRANIF0_ /* rtranif0 */
%token RTRANIF1_ /* rtranif1 */
%token TRAN_ /* tran */
%token RTRAN_ /* rtran */
%token GENERATE_ /* generate */
%token ENDGENERATE_ /* endgenerate */
%token FOR_ /* for */
%token PRIMITIVE_ /* primitive */
%token ENDPRIMITIVE_ /* endprimitive */
%token TABLE_ /* table */
%token ENDTABLE_ /* endtable */
%token INITIAL_ /* initial */
%token ONEBIT_GND /* 1'b0 */
%token ONEBIT_VDD /* 1'b1 */
%token ONEBIT_X0 /* 1'bx */
%token ONEBIT_X1 /* 1'bX */
%token ONEBIT_BGND /* 1'B0 */
%token ONEBIT_BVDD /* 1'B1 */
%token ONEBIT_BX0 /* 1'Bx */
%token ONEBIT_BX1 /* 1'BX */
%token LETTER_X0_ /* x */
%token LETTER_X1_ /* X */
%token QMARK /* ? */
%token LETTER_B0_ /* b */
%token LETTER_B1_ /* B */
%token LETTER_R0_ /* r */
%token LETTER_R1_ /* R */
%token LETTER_F0_ /* f */
%token LETTER_F1_ /* F */
%token LETTER_P0_ /* p */
%token LETTER_P1_ /* P */
%token LETTER_N0_ /* n */
%token LETTER_N1_ /* N */
%token ASSIGN_ /* assign */
%token ALIAS_ /* alias */
%token ALWAYS_COMB_ /* always_comb */
%token ALWAYS_LATCH_ /* always_latch */
%token ALWAYS_FF_ /* always_ff */
%token FINAL_ /* final */
%token PLUS_EQ /* += */
%token MINUS_EQ /* -= */
%token STAR_EQ /* *= */
%token SLASH_EQ /* /= */
%token PERCENT_EQ /* %= */
%token AND_EQ /* &= */
%token BAR_EQ /* |= */
%token XOR_EQ /* ^= */
%token LSHIFT_EQ /* <<= */
%token RSHIFT_EQ /* >>= */
%token LSHIFT2_EQ /* <<<= */
%token RSHIFT2_EQ /* >>>= */
%token DEASSIGN_ /* deassign */
%token FORCE_ /* force */
%token RELEASE_ /* release */
%token FORK_ /* fork */
%token JOIN_ /* join */
%token JOIN_ANY_ /* join_any */
%token JOIN_NONE_ /* join_none */
%token REPEAT_ /* repeat */
%token AT /* @ */
%token RETURN_ /* return */
%token BREAK_ /* break */
%token CONTINUE_ /* continue */
%token WAIT_ /* wait */
%token WAIT_ORDER_ /* wait_order */
%token DASH_RSHIFT /* ->> */
%token UNIQUE0_ /* unique0 */
%token PRIORITY_ /* priority */
%token AND3 /* &&& */
%token INSIDE_ /* inside */
%token CASEX_ /* casex */
%token CASEZ_ /* casez */
%token RANDCASE_ /* randcase */
%token APOSTROPHE /* ' */
%token FOREVER_ /* forever */
%token WHILE_ /* while */
%token DO_ /* do */
%token SHARP0_ /* #0 */
%token ENDCLOCKING_ /* endclocking */
%token GLOBAL_ /* global */
%token RANDSEQUENCE_ /* randsequence */
%token BAR_ /* | */
%token SPECIFY_ /* specify */
%token ENDSPECIFY_ /* endspecify */
%token PULSESTYLE_ONEVENT_ /* pulsestyle_onevent */
%token PULSESTYPE_ONDETECT_ /* pulsestyle_ondetect */
%token SHOWCANCELLED_ /* showcancelled */
%token NOSHOWCANCELLED_ /* noshowcancelled */
%token STAR_RT /* *> */
%token POSEDGE_ /* posedge */
%token NEGEDGE_ /* negedge */
%token EDGE_ /* edge */
%token IFNONE_ /* ifnone */
%token DOLLAR_SETUP_ /* dollarsign_setup */
%token DOLLAR_HOLD_ /* dollarsign_hold */
%token DOLLAR_SETUPHOLD_ /* dollarsign_setuphold */
%token DOLLAR_RECOVERY_ /* dollarsign_recovery */
%token DOLLAR_REMOVAL_ /* dollarsign_removal */
%token DOLLAR_RECREM_ /* dollarsign_recrem */
%token DOLLAR_SKEW_ /* dollarsign_skew */
%token DOLLAR_TIMESKEW_ /* dollarsign_timeskew */
%token DOLLAR_FULLSKEW_ /* dollarsign_fullskew */
%token DOLLAR_PERIOD_ /* dollarsign_period */
%token DOLLAR_WIDTH_ /* dollarsign_width */
%token DOLLAR_NOCHANGE_ /* dollarsign_nochange */
%token ZERO_ONE /* 01 */
%token ONE_ZERO /* 10 */
%token LETTER_Z0_ /* z */
%token LETTER_Z1_ /* Z */
%token WAVE /* ~ */
%token EQ3 /* === */
%token NEQ2 /* !== */
%token APOSTROPHE_B0_GND /* 'b0 */
%token APOSTROPHE_B0_VDD /* 'b1 */
%token APOSTROPHE_B1_GND /* 'B0 */
%token APOSTROPHE_B1_VDD /* 'B1 */
%token RSHIFT /* >> */
%token LSHIFT /* << */
%token PLUS_COLON /* +: */
%token MINUS_COLON /* -: */
%token STD_COLON2 /* std:: */
%token RANDOMIZE_ /* randomize */
%token NULL_ /* null */
%token THIS_ /* this */
%token LOCAL_COLON2 /* local:: */
%token LETTER_S0_ /* s */
%token MS_ /* ms */
%token US_ /* us */
%token NS_ /* ns */
%token PS_ /* ps */
%token FS_ /* fs */
%token AND /* & */
%token WAVE_AND /* ~& */
%token WAVE_BAR /* ~| */
%token XOR /* ^ */
%token WAVE_XOR /* ~^ */
%token XOR_WAVE /* ^~ */
%token EQ2_QMARK /* ==? */
%token NEQ_QMARK /* !=? */
%token RSHIFT2 /* >>> */
%token LSHIFT2 /* <<< */
%token LT_DASH_RT /* <-> */
%token APOSTROPHE_GND /* '0 */
%token APOSTROPHE_VDD /* '1 */
%token LP_STAR /* (* */
%token STAR_RP /* *) */
%token DOLLAR_UNIT_ /* dollarsign_unit */
%token TOKEN_400 /* PATHPULSEdollarsign_ */
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
%type <token_str> SEMICOLON
%type <token_str> LIBRARY_
%type <token_str> COMMA
%type <token_str> DASH_INCDIR_
%type <token_str> INCLUDE_
%type <token_str> ENDMODULE_
%type <token_str> COLON
%type <token_str> EXTERN_
%type <token_str> MODULE_
%type <token_str> MACROMODULE_
%type <token_str> ENDINTERFACE_
%type <token_str> INTERFACE_
%type <token_str> LP
%type <token_str> DOT_STAR
%type <token_str> RP
%type <token_str> ENDPROGRAM_
%type <token_str> PROGRAM_
%type <token_str> CHECKER_
%type <token_str> ENDCHECKER_
%type <token_str> VIRTUAL_
%type <token_str> CLASS_
%type <token_str> EXTENDS_
%type <token_str> IMPLEMENTS_
%type <token_str> ENDCLASS_
%type <token_str> PACKAGE_
%type <token_str> ENDPACKAGE_
%type <token_str> TIMEUNIT_
%type <token_str> SLASH
%type <token_str> TIMEPRECISION_
%type <token_str> SHARP
%type <token_str> TYPE_
%type <token_str> DOT
%type <token_str> LMP
%type <token_str> RMP
%type <token_str> INPUT_
%type <token_str> OUTPUT_
%type <token_str> INOUT_
%type <token_str> REF_
%type <token_str> EQ
%type <token_str> DOLLAR_FATAL_
%type <token_str> DOLLAR_ERROR_
%type <token_str> DOLLAR_WARNING_
%type <token_str> DOLLAR_INFO_
%type <token_str> ZERO_
%type <token_str> ONE_
%type <token_str> TWO_
%type <token_str> DEFAULT_
%type <token_str> CLOCKING_
%type <token_str> DISABLE_
%type <token_str> IFF_
%type <token_str> DEFPARAM_
%type <token_str> BIND_
%type <token_str> CONFIG_
%type <token_str> ENDCONFIG_
%type <token_str> DESIGN_
%type <token_str> INSTANCE_
%type <token_str> CELL_
%type <token_str> LIBLIST_
%type <token_str> USE_
%type <token_str> FORKJOIN_
%type <token_str> RAND_
%type <token_str> CONST_
%type <token_str> PURE_
%type <token_str> FUNCTION_
%type <token_str> NEW_
%type <token_str> STATIC_
%type <token_str> PROTECTED_
%type <token_str> LOCAL_
%type <token_str> RANDC_
%type <token_str> SUPER_
%type <token_str> ENDFUNCTION_
%type <token_str> CONSTRAINT_
%type <token_str> SOLVE_
%type <token_str> BEFORE_
%type <token_str> SOFT_
%type <token_str> RIGHTARROW
%type <token_str> IF_
%type <token_str> ELSE_
%type <token_str> FOREACH_
%type <token_str> LSP
%type <token_str> RSP
%type <token_str> UNIQUE_
%type <token_str> COLON_EQUAL
%type <token_str> COLON_SLASH
%type <token_str> LOCALPARAM_
%type <token_str> PARAMETER_
%type <token_str> SPECPARAM_
%type <token_str> VAR_
%type <token_str> IMPORT_
%type <token_str> COLON2
%type <token_str> STAR
%type <token_str> EXPORT_
%type <token_str> STAR_COLON2_STAR
%type <token_str> GENVAR_
%type <token_str> VECTORED_
%type <token_str> SCALARED_
%type <token_str> INTERCONNECT_
%type <token_str> TYPEDEF_
%type <token_str> ENUM_
%type <token_str> STRUCT_
%type <token_str> UNION_
%type <token_str> NETTYPE_
%type <token_str> WITH_
%type <token_str> AUTOMATIC_
%type <token_str> STRING_
%type <token_str> PACKED_
%type <token_str> CHANDLE_
%type <token_str> EVENT_
%type <token_str> BYTE_
%type <token_str> SHORTINT_
%type <token_str> INT_
%type <token_str> LONGINT_
%type <token_str> INTEGER_
%type <token_str> TIME_
%type <token_str> BIT_
%type <token_str> LOGIC_
%type <token_str> REG_
%type <token_str> SHORTREAL_
%type <token_str> REAL_
%type <token_str> REALTIME_
%type <token_str> SUPPLY0_
%type <token_str> SUPPLY1_
%type <token_str> TRI_
%type <token_str> TRIAND_
%type <token_str> TRIOR_
%type <token_str> TRIREG_
%type <token_str> TRI0_
%type <token_str> TRI1_
%type <token_str> UWIRE_
%type <token_str> WIRE_
%type <token_str> WAND_
%type <token_str> WOR_
%type <token_str> SIGNED_
%type <token_str> UNSIGNED_
%type <token_str> VOID_
%type <token_str> TAGGED_
%type <token_str> HIGHZ1_
%type <token_str> HIGHZ0_
%type <token_str> STRONG0_
%type <token_str> PULL0_
%type <token_str> WEAK0_
%type <token_str> STRONG1_
%type <token_str> PULL1_
%type <token_str> WEAK1_
%type <token_str> SMALL_
%type <token_str> MEDIUM_
%type <token_str> LARGE_
%type <token_str> ONESTEP_
%type <token_str> DOLLAR_
%type <token_str> TASK_
%type <token_str> DPI_C_
%type <token_str> DPI_
%type <token_str> CONTEXT_
%type <token_str> ENDTASK_
%type <token_str> PLUS
%type <token_str> PLUS2
%type <token_str> MINUS
%type <token_str> MINUS2
%type <token_str> STAR2
%type <token_str> PERCENT
%type <token_str> EQ2
%type <token_str> NEQ
%type <token_str> LT
%type <token_str> LTE
%type <token_str> GT
%type <token_str> GTE
%type <token_str> MODPORT_
%type <token_str> ASSERT_
%type <token_str> PROPERTY_
%type <token_str> ASSUME_
%type <token_str> COVER_
%type <token_str> EXPECT_
%type <token_str> SEQUENCE_
%type <token_str> RESTRICT_
%type <token_str> ENDPROPERTY_
%type <token_str> STRONG_
%type <token_str> WEAK_
%type <token_str> NOT_
%type <token_str> OR_
%type <token_str> AND_
%type <token_str> BAR_DASH_GT
%type <token_str> BAR_EQ_GT
%type <token_str> CASE_
%type <token_str> ENDCASE_
%type <token_str> SHARP_DASH_SHARP
%type <token_str> SHARP_EQ_SHARP
%type <token_str> NEXTTIME_
%type <token_str> S_NEXTTIME_
%type <token_str> ALWAYS_
%type <token_str> S_ALWAYS_
%type <token_str> S_EVENTUALLY_
%type <token_str> UNTIL_
%type <token_str> S_UNTIL_
%type <token_str> UNTIL_WITH_
%type <token_str> S_UNTIL_WITH_
%type <token_str> IMPLIES_
%type <token_str> ACCEPT_ON_
%type <token_str> REJECT_ON_
%type <token_str> SYNC_ACCEPT_ON_
%type <token_str> SYNC_REJECT_ON_
%type <token_str> ENDSEQUENCE_
%type <token_str> UNTYPED_
%type <token_str> INTERSECT_
%type <token_str> FIRST_MATCH_
%type <token_str> THROUGHOUT_
%type <token_str> WITHIN_
%type <token_str> SHARP2
%type <token_str> LSP_STAR_RSP
%type <token_str> LSP_PLUS_RSP
%type <token_str> LSP_STAR
%type <token_str> LSP_EQ
%type <token_str> LSP_DASH_GT
%type <token_str> DIST_
%type <token_str> LET_
%type <token_str> COVERGROUP_
%type <token_str> ENDGROUP_
%type <token_str> OPTION_
%type <token_str> TYPE_OPTION_
%type <token_str> SAMPLE_
%type <token_str> AT2
%type <token_str> BEGIN_
%type <token_str> END_
%type <token_str> COVERPOINT_
%type <token_str> WILDCARD_
%type <token_str> BINS_
%type <token_str> ILLEGRAL_BINS_
%type <token_str> IGNORE_BINS_
%type <token_str> EQ_GT
%type <token_str> CROSS_
%type <token_str> NOT
%type <token_str> AND2
%type <token_str> BAR2
%type <token_str> MATCHES_
%type <token_str> BINSOF_
%type <token_str> PULLDOWN_
%type <token_str> PULLUP_
%type <token_str> CMOS_
%type <token_str> RCMOS_
%type <token_str> BUFIF0_
%type <token_str> BUFIF1_
%type <token_str> NOTIF0_
%type <token_str> NOTIF1_
%type <token_str> NMOS_
%type <token_str> PMOS_
%type <token_str> RNMOS_
%type <token_str> RPMOS_
%type <token_str> NAND_
%type <token_str> NOR_
%type <token_str> XOR_
%type <token_str> XNOR_
%type <token_str> BUF_
%type <token_str> TRANIF0_
%type <token_str> TRANIF1_
%type <token_str> RTRANIF0_
%type <token_str> RTRANIF1_
%type <token_str> TRAN_
%type <token_str> RTRAN_
%type <token_str> GENERATE_
%type <token_str> ENDGENERATE_
%type <token_str> FOR_
%type <token_str> PRIMITIVE_
%type <token_str> ENDPRIMITIVE_
%type <token_str> TABLE_
%type <token_str> ENDTABLE_
%type <token_str> INITIAL_
%type <token_str> ONEBIT_GND
%type <token_str> ONEBIT_VDD
%type <token_str> ONEBIT_X0
%type <token_str> ONEBIT_X1
%type <token_str> ONEBIT_BGND
%type <token_str> ONEBIT_BVDD
%type <token_str> ONEBIT_BX0
%type <token_str> ONEBIT_BX1
%type <token_str> LETTER_X0_
%type <token_str> LETTER_X1_
%type <token_str> QMARK
%type <token_str> LETTER_B0_
%type <token_str> LETTER_B1_
%type <token_str> LETTER_R0_
%type <token_str> LETTER_R1_
%type <token_str> LETTER_F0_
%type <token_str> LETTER_F1_
%type <token_str> LETTER_P0_
%type <token_str> LETTER_P1_
%type <token_str> LETTER_N0_
%type <token_str> LETTER_N1_
%type <token_str> ASSIGN_
%type <token_str> ALIAS_
%type <token_str> ALWAYS_COMB_
%type <token_str> ALWAYS_LATCH_
%type <token_str> ALWAYS_FF_
%type <token_str> FINAL_
%type <token_str> PLUS_EQ
%type <token_str> MINUS_EQ
%type <token_str> STAR_EQ
%type <token_str> SLASH_EQ
%type <token_str> PERCENT_EQ
%type <token_str> AND_EQ
%type <token_str> BAR_EQ
%type <token_str> XOR_EQ
%type <token_str> LSHIFT_EQ
%type <token_str> RSHIFT_EQ
%type <token_str> LSHIFT2_EQ
%type <token_str> RSHIFT2_EQ
%type <token_str> DEASSIGN_
%type <token_str> FORCE_
%type <token_str> RELEASE_
%type <token_str> FORK_
%type <token_str> JOIN_
%type <token_str> JOIN_ANY_
%type <token_str> JOIN_NONE_
%type <token_str> REPEAT_
%type <token_str> AT
%type <token_str> RETURN_
%type <token_str> BREAK_
%type <token_str> CONTINUE_
%type <token_str> WAIT_
%type <token_str> WAIT_ORDER_
%type <token_str> DASH_RSHIFT
%type <token_str> UNIQUE0_
%type <token_str> PRIORITY_
%type <token_str> AND3
%type <token_str> INSIDE_
%type <token_str> CASEX_
%type <token_str> CASEZ_
%type <token_str> RANDCASE_
%type <token_str> APOSTROPHE
%type <token_str> FOREVER_
%type <token_str> WHILE_
%type <token_str> DO_
%type <token_str> SHARP0_
%type <token_str> ENDCLOCKING_
%type <token_str> GLOBAL_
%type <token_str> RANDSEQUENCE_
%type <token_str> BAR_
%type <token_str> SPECIFY_
%type <token_str> ENDSPECIFY_
%type <token_str> PULSESTYLE_ONEVENT_
%type <token_str> PULSESTYPE_ONDETECT_
%type <token_str> SHOWCANCELLED_
%type <token_str> NOSHOWCANCELLED_
%type <token_str> STAR_RT
%type <token_str> POSEDGE_
%type <token_str> NEGEDGE_
%type <token_str> EDGE_
%type <token_str> IFNONE_
%type <token_str> DOLLAR_SETUP_
%type <token_str> DOLLAR_HOLD_
%type <token_str> DOLLAR_SETUPHOLD_
%type <token_str> DOLLAR_RECOVERY_
%type <token_str> DOLLAR_REMOVAL_
%type <token_str> DOLLAR_RECREM_
%type <token_str> DOLLAR_SKEW_
%type <token_str> DOLLAR_TIMESKEW_
%type <token_str> DOLLAR_FULLSKEW_
%type <token_str> DOLLAR_PERIOD_
%type <token_str> DOLLAR_WIDTH_
%type <token_str> DOLLAR_NOCHANGE_
%type <token_str> ZERO_ONE
%type <token_str> ONE_ZERO
%type <token_str> LETTER_Z0_
%type <token_str> LETTER_Z1_
%type <token_str> WAVE
%type <token_str> EQ3
%type <token_str> NEQ2
%type <token_str> APOSTROPHE_B0_GND
%type <token_str> APOSTROPHE_B0_VDD
%type <token_str> APOSTROPHE_B1_GND
%type <token_str> APOSTROPHE_B1_VDD
%type <token_str> RSHIFT
%type <token_str> LSHIFT
%type <token_str> PLUS_COLON
%type <token_str> MINUS_COLON
%type <token_str> STD_COLON2
%type <token_str> RANDOMIZE_
%type <token_str> NULL_
%type <token_str> THIS_
%type <token_str> LOCAL_COLON2
%type <token_str> LETTER_S0_
%type <token_str> MS_
%type <token_str> US_
%type <token_str> NS_
%type <token_str> PS_
%type <token_str> FS_
%type <token_str> AND
%type <token_str> WAVE_AND
%type <token_str> WAVE_BAR
%type <token_str> XOR
%type <token_str> WAVE_XOR
%type <token_str> XOR_WAVE
%type <token_str> EQ2_QMARK
%type <token_str> NEQ_QMARK
%type <token_str> RSHIFT2
%type <token_str> LSHIFT2
%type <token_str> LT_DASH_RT
%type <token_str> APOSTROPHE_GND
%type <token_str> APOSTROPHE_VDD
%type <token_str> LP_STAR
%type <token_str> STAR_RP
%type <token_str> DOLLAR_UNIT_
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
        ast::library_text *ret = new ast::library_text;
        $$ = ret;
    }
    ;

library_description 
    : library_declaration 
    {
        ast::library_description *ret = new ast::library_description;
        $$ = ret;
    }
    | include_statement 
    {
        ast::library_description *ret = new ast::library_description;
        $$ = ret;
    }
    | config_declaration 
    {
        ast::library_description *ret = new ast::library_description;
        $$ = ret;
    }
    | SEMICOLON 
    {
        ast::library_description *ret = new ast::library_description;
        $$ = ret;
    }
    ;

library_declaration 
    : LIBRARY_ library_identifier LIST_1 OPT_0 SEMICOLON 
    {
        ast::library_declaration *ret = new ast::library_declaration;
        $$ = ret;
    }
    ;

include_statement 
    : INCLUDE_ file_path_spec SEMICOLON 
    {
        ast::include_statement *ret = new ast::include_statement;
        $$ = ret;
    }
    ;

source_text 
    : OPT_1 STAR_1 
    {
        ast::source_text *ret = new ast::source_text;
        $$ = ret;
    }
    ;

description 
    : module_declaration 
    {
        ast::description *ret = new ast::description;
        $$ = ret;
    }
    | udp_declaration 
    {
        ast::description *ret = new ast::description;
        $$ = ret;
    }
    | interface_declaration 
    {
        ast::description *ret = new ast::description;
        $$ = ret;
    }
    | program_declaration 
    {
        ast::description *ret = new ast::description;
        $$ = ret;
    }
    | package_declaration 
    {
        ast::description *ret = new ast::description;
        $$ = ret;
    }
    | STAR_2 package_item 
    {
        ast::description *ret = new ast::description;
        $$ = ret;
    }
    | STAR_2 bind_directive 
    {
        ast::description *ret = new ast::description;
        $$ = ret;
    }
    | config_declaration 
    {
        ast::description *ret = new ast::description;
        $$ = ret;
    }
    ;

module_nonansi_header 
    : STAR_2 module_keyword OPT_2 module_identifier STAR_3 OPT_3 list_of_ports SEMICOLON 
    {
        ast::module_nonansi_header *ret = new ast::module_nonansi_header;
        $$ = ret;
    }
    ;

module_ansi_header 
    : STAR_2 module_keyword OPT_2 module_identifier STAR_3 OPT_3 OPT_4 SEMICOLON 
    {
        ast::module_ansi_header *ret = new ast::module_ansi_header;
        $$ = ret;
    }
    ;

module_declaration 
    : module_nonansi_header OPT_1 STAR_4 ENDMODULE_ OPT_5 
    {
        ast::module_declaration *ret = new ast::module_declaration;
        $$ = ret;
    }
    | module_ansi_header OPT_1 STAR_5 ENDMODULE_ OPT_5 
    {
        ast::module_declaration *ret = new ast::module_declaration;
        $$ = ret;
    }
    | EXTERN_ module_nonansi_header 
    {
        ast::module_declaration *ret = new ast::module_declaration;
        $$ = ret;
    }
    | EXTERN_ module_ansi_header 
    {
        ast::module_declaration *ret = new ast::module_declaration;
        $$ = ret;
    }
    ;

module_keyword 
    : MODULE_ 
    {
        ast::module_keyword *ret = new ast::module_keyword;
        $$ = ret;
    }
    | MACROMODULE_ 
    {
        ast::module_keyword *ret = new ast::module_keyword;
        $$ = ret;
    }
    ;

interface_declaration 
    : interface_nonansi_header OPT_1 STAR_6 ENDINTERFACE_ OPT_6 
    {
        ast::interface_declaration *ret = new ast::interface_declaration;
        $$ = ret;
    }
    | interface_ansi_header OPT_1 STAR_7 ENDINTERFACE_ OPT_6 
    {
        ast::interface_declaration *ret = new ast::interface_declaration;
        $$ = ret;
    }
    | STAR_2 INTERFACE_ interface_identifier LP DOT_STAR RP SEMICOLON OPT_1 STAR_6 ENDINTERFACE_ OPT_6 
    {
        ast::interface_declaration *ret = new ast::interface_declaration;
        $$ = ret;
    }
    | EXTERN_ interface_nonansi_header 
    {
        ast::interface_declaration *ret = new ast::interface_declaration;
        $$ = ret;
    }
    | EXTERN_ interface_ansi_header 
    {
        ast::interface_declaration *ret = new ast::interface_declaration;
        $$ = ret;
    }
    ;

interface_nonansi_header 
    : STAR_2 INTERFACE_ OPT_2 interface_identifier STAR_3 OPT_3 list_of_ports SEMICOLON 
    {
        ast::interface_nonansi_header *ret = new ast::interface_nonansi_header;
        $$ = ret;
    }
    ;

interface_ansi_header 
    : STAR_2 INTERFACE_ OPT_2 interface_identifier STAR_3 OPT_3 OPT_4 SEMICOLON 
    {
        ast::interface_ansi_header *ret = new ast::interface_ansi_header;
        $$ = ret;
    }
    ;

program_declaration 
    : program_nonansi_header OPT_1 STAR_8 ENDPROGRAM_ OPT_7 
    {
        ast::program_declaration *ret = new ast::program_declaration;
        $$ = ret;
    }
    | program_ansi_header OPT_1 STAR_9 ENDPROGRAM_ OPT_7 
    {
        ast::program_declaration *ret = new ast::program_declaration;
        $$ = ret;
    }
    | STAR_2 PROGRAM_ program_identifier LP DOT_STAR RP SEMICOLON OPT_1 STAR_8 ENDPROGRAM_ OPT_7 
    {
        ast::program_declaration *ret = new ast::program_declaration;
        $$ = ret;
    }
    | EXTERN_ program_nonansi_header 
    {
        ast::program_declaration *ret = new ast::program_declaration;
        $$ = ret;
    }
    | EXTERN_ program_ansi_header 
    {
        ast::program_declaration *ret = new ast::program_declaration;
        $$ = ret;
    }
    ;

program_nonansi_header 
    : STAR_2 PROGRAM_ OPT_2 program_identifier STAR_3 OPT_3 list_of_ports SEMICOLON 
    {
        ast::program_nonansi_header *ret = new ast::program_nonansi_header;
        $$ = ret;
    }
    ;

program_ansi_header 
    : STAR_2 PROGRAM_ OPT_2 program_identifier STAR_3 OPT_3 OPT_4 SEMICOLON 
    {
        ast::program_ansi_header *ret = new ast::program_ansi_header;
        $$ = ret;
    }
    ;

checker_declaration 
    : CHECKER_ checker_identifier OPT_9 SEMICOLON STAR_10 ENDCHECKER_ OPT_10 
    {
        ast::checker_declaration *ret = new ast::checker_declaration;
        $$ = ret;
    }
    ;

class_declaration 
    : OPT_11 CLASS_ OPT_2 class_identifier OPT_3 OPT_13 OPT_14 SEMICOLON STAR_11 ENDCLASS_ OPT_15 
    {
        ast::class_declaration *ret = new ast::class_declaration;
        $$ = ret;
    }
    ;

interface_class_type 
    : ps_class_identifier OPT_16 
    {
        ast::interface_class_type *ret = new ast::interface_class_type;
        $$ = ret;
    }
    ;

package_declaration 
    : STAR_2 PACKAGE_ OPT_2 package_identifier SEMICOLON OPT_1 STAR_12 ENDPACKAGE_ OPT_17 
    {
        ast::package_declaration *ret = new ast::package_declaration;
        $$ = ret;
    }
    ;

timeunits_declaration 
    : TIMEUNIT_ time_literal OPT_18 SEMICOLON 
    {
        ast::timeunits_declaration *ret = new ast::timeunits_declaration;
        $$ = ret;
    }
    | TIMEPRECISION_ time_literal SEMICOLON 
    {
        ast::timeunits_declaration *ret = new ast::timeunits_declaration;
        $$ = ret;
    }
    | TIMEUNIT_ time_literal SEMICOLON TIMEPRECISION_ time_literal SEMICOLON 
    {
        ast::timeunits_declaration *ret = new ast::timeunits_declaration;
        $$ = ret;
    }
    | TIMEPRECISION_ time_literal SEMICOLON TIMEUNIT_ time_literal SEMICOLON 
    {
        ast::timeunits_declaration *ret = new ast::timeunits_declaration;
        $$ = ret;
    }
    ;

parameter_port_list 
    : SHARP LP list_of_param_assignments STAR_13 RP 
    {
        ast::parameter_port_list *ret = new ast::parameter_port_list;
        $$ = ret;
    }
    | SHARP LP LIST_16 RP 
    {
        ast::parameter_port_list *ret = new ast::parameter_port_list;
        $$ = ret;
    }
    | SHARP LP RP 
    {
        ast::parameter_port_list *ret = new ast::parameter_port_list;
        $$ = ret;
    }
    ;

parameter_port_declaration 
    : parameter_declaration 
    {
        ast::parameter_port_declaration *ret = new ast::parameter_port_declaration;
        $$ = ret;
    }
    | local_parameter_declaration 
    {
        ast::parameter_port_declaration *ret = new ast::parameter_port_declaration;
        $$ = ret;
    }
    | data_type list_of_param_assignments 
    {
        ast::parameter_port_declaration *ret = new ast::parameter_port_declaration;
        $$ = ret;
    }
    | TYPE_ list_of_type_assignments 
    {
        ast::parameter_port_declaration *ret = new ast::parameter_port_declaration;
        $$ = ret;
    }
    ;

list_of_ports 
    : LP LIST_17 RP 
    {
        ast::list_of_ports *ret = new ast::list_of_ports;
        $$ = ret;
    }
    ;

list_of_port_declarations 
    : LP OPT_19 RP 
    {
        ast::list_of_port_declarations *ret = new ast::list_of_port_declarations;
        $$ = ret;
    }
    ;

port_declaration 
    : STAR_2 inout_declaration 
    {
        ast::port_declaration *ret = new ast::port_declaration;
        $$ = ret;
    }
    | STAR_2 input_declaration 
    {
        ast::port_declaration *ret = new ast::port_declaration;
        $$ = ret;
    }
    | STAR_2 output_declaration 
    {
        ast::port_declaration *ret = new ast::port_declaration;
        $$ = ret;
    }
    | STAR_2 ref_declaration 
    {
        ast::port_declaration *ret = new ast::port_declaration;
        $$ = ret;
    }
    | STAR_2 interface_port_declaration 
    {
        ast::port_declaration *ret = new ast::port_declaration;
        $$ = ret;
    }
    ;

port 
    : OPT_20 
    {
        ast::port *ret = new ast::port;
        $$ = ret;
    }
    | DOT port_identifier LP OPT_20 RP 
    {
        ast::port *ret = new ast::port;
        $$ = ret;
    }
    ;

port_expression 
    : port_reference 
    {
        ast::port_expression *ret = new ast::port_expression;
        $$ = ret;
    }
    | LMP LIST_19 RMP 
    {
        ast::port_expression *ret = new ast::port_expression;
        $$ = ret;
    }
    ;

port_reference 
    : port_identifier constant_select 
    {
        ast::port_reference *ret = new ast::port_reference;
        $$ = ret;
    }
    ;

port_direction 
    : INPUT_ 
    {
        ast::port_direction *ret = new ast::port_direction;
        $$ = ret;
    }
    | OUTPUT_ 
    {
        ast::port_direction *ret = new ast::port_direction;
        $$ = ret;
    }
    | INOUT_ 
    {
        ast::port_direction *ret = new ast::port_direction;
        $$ = ret;
    }
    | REF_ 
    {
        ast::port_direction *ret = new ast::port_direction;
        $$ = ret;
    }
    ;

net_port_header 
    : OPT_21 net_port_type 
    {
        ast::net_port_header *ret = new ast::net_port_header;
        $$ = ret;
    }
    ;

variable_port_header 
    : OPT_21 variable_port_type 
    {
        ast::variable_port_header *ret = new ast::variable_port_header;
        $$ = ret;
    }
    ;

interface_port_header 
    : interface_identifier OPT_22 
    {
        ast::interface_port_header *ret = new ast::interface_port_header;
        $$ = ret;
    }
    | INTERFACE_ OPT_22 
    {
        ast::interface_port_header *ret = new ast::interface_port_header;
        $$ = ret;
    }
    ;

ansi_port_declaration 
    : OPT_23 port_identifier STAR_14 OPT_24 
    {
        ast::ansi_port_declaration *ret = new ast::ansi_port_declaration;
        $$ = ret;
    }
    | OPT_25 port_identifier STAR_15 OPT_24 
    {
        ast::ansi_port_declaration *ret = new ast::ansi_port_declaration;
        $$ = ret;
    }
    | OPT_21 DOT port_identifier LP OPT_26 RP 
    {
        ast::ansi_port_declaration *ret = new ast::ansi_port_declaration;
        $$ = ret;
    }
    ;

elaboration_system_task 
    : DOLLAR_FATAL_ OPT_28 SEMICOLON 
    {
        ast::elaboration_system_task *ret = new ast::elaboration_system_task;
        $$ = ret;
    }
    | DOLLAR_ERROR_ OPT_30 SEMICOLON 
    {
        ast::elaboration_system_task *ret = new ast::elaboration_system_task;
        $$ = ret;
    }
    | DOLLAR_WARNING_ OPT_30 SEMICOLON 
    {
        ast::elaboration_system_task *ret = new ast::elaboration_system_task;
        $$ = ret;
    }
    | DOLLAR_INFO_ OPT_30 SEMICOLON 
    {
        ast::elaboration_system_task *ret = new ast::elaboration_system_task;
        $$ = ret;
    }
    ;

finish_number 
    : ZERO_ 
    {
        ast::finish_number *ret = new ast::finish_number;
        $$ = ret;
    }
    | ONE_ 
    {
        ast::finish_number *ret = new ast::finish_number;
        $$ = ret;
    }
    | TWO_ 
    {
        ast::finish_number *ret = new ast::finish_number;
        $$ = ret;
    }
    ;

module_common_item 
    : module_or_generate_item_declaration 
    {
        ast::module_common_item *ret = new ast::module_common_item;
        $$ = ret;
    }
    | interface_instantiation 
    {
        ast::module_common_item *ret = new ast::module_common_item;
        $$ = ret;
    }
    | program_instantiation 
    {
        ast::module_common_item *ret = new ast::module_common_item;
        $$ = ret;
    }
    | assertion_item 
    {
        ast::module_common_item *ret = new ast::module_common_item;
        $$ = ret;
    }
    | bind_directive 
    {
        ast::module_common_item *ret = new ast::module_common_item;
        $$ = ret;
    }
    | continuous_assign 
    {
        ast::module_common_item *ret = new ast::module_common_item;
        $$ = ret;
    }
    | net_alias 
    {
        ast::module_common_item *ret = new ast::module_common_item;
        $$ = ret;
    }
    | initial_construct 
    {
        ast::module_common_item *ret = new ast::module_common_item;
        $$ = ret;
    }
    | final_construct 
    {
        ast::module_common_item *ret = new ast::module_common_item;
        $$ = ret;
    }
    | always_construct 
    {
        ast::module_common_item *ret = new ast::module_common_item;
        $$ = ret;
    }
    | loop_generate_construct 
    {
        ast::module_common_item *ret = new ast::module_common_item;
        $$ = ret;
    }
    | conditional_generate_construct 
    {
        ast::module_common_item *ret = new ast::module_common_item;
        $$ = ret;
    }
    | elaboration_system_task 
    {
        ast::module_common_item *ret = new ast::module_common_item;
        $$ = ret;
    }
    ;

module_item 
    : port_declaration SEMICOLON 
    {
        ast::module_item *ret = new ast::module_item;
        $$ = ret;
    }
    | non_port_module_item 
    {
        ast::module_item *ret = new ast::module_item;
        $$ = ret;
    }
    ;

module_or_generate_item 
    : STAR_2 parameter_override 
    {
        ast::module_or_generate_item *ret = new ast::module_or_generate_item;
        $$ = ret;
    }
    | STAR_2 gate_instantiation 
    {
        ast::module_or_generate_item *ret = new ast::module_or_generate_item;
        $$ = ret;
    }
    | STAR_2 udp_instantiation 
    {
        ast::module_or_generate_item *ret = new ast::module_or_generate_item;
        $$ = ret;
    }
    | STAR_2 module_instantiation 
    {
        ast::module_or_generate_item *ret = new ast::module_or_generate_item;
        $$ = ret;
    }
    | STAR_2 module_common_item 
    {
        ast::module_or_generate_item *ret = new ast::module_or_generate_item;
        $$ = ret;
    }
    ;

module_or_generate_item_declaration 
    : package_or_generate_item_declaration 
    {
        ast::module_or_generate_item_declaration *ret = new ast::module_or_generate_item_declaration;
        $$ = ret;
    }
    | genvar_declaration 
    {
        ast::module_or_generate_item_declaration *ret = new ast::module_or_generate_item_declaration;
        $$ = ret;
    }
    | clocking_declaration 
    {
        ast::module_or_generate_item_declaration *ret = new ast::module_or_generate_item_declaration;
        $$ = ret;
    }
    | DEFAULT_ CLOCKING_ clocking_identifier SEMICOLON 
    {
        ast::module_or_generate_item_declaration *ret = new ast::module_or_generate_item_declaration;
        $$ = ret;
    }
    | DEFAULT_ DISABLE_ IFF_ expression_or_dist SEMICOLON 
    {
        ast::module_or_generate_item_declaration *ret = new ast::module_or_generate_item_declaration;
        $$ = ret;
    }
    ;

non_port_module_item 
    : generate_region 
    {
        ast::non_port_module_item *ret = new ast::non_port_module_item;
        $$ = ret;
    }
    | module_or_generate_item 
    {
        ast::non_port_module_item *ret = new ast::non_port_module_item;
        $$ = ret;
    }
    | specify_block 
    {
        ast::non_port_module_item *ret = new ast::non_port_module_item;
        $$ = ret;
    }
    | STAR_2 specparam_declaration 
    {
        ast::non_port_module_item *ret = new ast::non_port_module_item;
        $$ = ret;
    }
    | program_declaration 
    {
        ast::non_port_module_item *ret = new ast::non_port_module_item;
        $$ = ret;
    }
    | module_declaration 
    {
        ast::non_port_module_item *ret = new ast::non_port_module_item;
        $$ = ret;
    }
    | interface_declaration 
    {
        ast::non_port_module_item *ret = new ast::non_port_module_item;
        $$ = ret;
    }
    | timeunits_declaration 
    {
        ast::non_port_module_item *ret = new ast::non_port_module_item;
        $$ = ret;
    }
    ;

parameter_override 
    : DEFPARAM_ list_of_defparam_assignments SEMICOLON 
    {
        ast::parameter_override *ret = new ast::parameter_override;
        $$ = ret;
    }
    ;

bind_directive 
    : BIND_ bind_target_scope OPT_31 bind_instantiation SEMICOLON 
    {
        ast::bind_directive *ret = new ast::bind_directive;
        $$ = ret;
    }
    | BIND_ bind_target_instance bind_instantiation SEMICOLON 
    {
        ast::bind_directive *ret = new ast::bind_directive;
        $$ = ret;
    }
    ;

bind_target_scope 
    : module_identifier 
    {
        ast::bind_target_scope *ret = new ast::bind_target_scope;
        $$ = ret;
    }
    | interface_identifier 
    {
        ast::bind_target_scope *ret = new ast::bind_target_scope;
        $$ = ret;
    }
    ;

bind_target_instance 
    : hierarchical_identifier constant_bit_select 
    {
        ast::bind_target_instance *ret = new ast::bind_target_instance;
        $$ = ret;
    }
    ;

bind_target_instance_list 
    : LIST_22 
    {
        ast::bind_target_instance_list *ret = new ast::bind_target_instance_list;
        $$ = ret;
    }
    ;

bind_instantiation 
    : program_instantiation 
    {
        ast::bind_instantiation *ret = new ast::bind_instantiation;
        $$ = ret;
    }
    | module_instantiation 
    {
        ast::bind_instantiation *ret = new ast::bind_instantiation;
        $$ = ret;
    }
    | interface_instantiation 
    {
        ast::bind_instantiation *ret = new ast::bind_instantiation;
        $$ = ret;
    }
    | checker_instantiation 
    {
        ast::bind_instantiation *ret = new ast::bind_instantiation;
        $$ = ret;
    }
    ;

config_declaration 
    : CONFIG_ config_identifier SEMICOLON STAR_16 design_statement STAR_17 ENDCONFIG_ OPT_32 
    {
        ast::config_declaration *ret = new ast::config_declaration;
        $$ = ret;
    }
    ;

design_statement 
    : DESIGN_ STAR_18 SEMICOLON 
    {
        ast::design_statement *ret = new ast::design_statement;
        $$ = ret;
    }
    ;

config_rule_statement 
    : default_clause liblist_clause SEMICOLON 
    {
        ast::config_rule_statement *ret = new ast::config_rule_statement;
        $$ = ret;
    }
    | inst_clause liblist_clause SEMICOLON 
    {
        ast::config_rule_statement *ret = new ast::config_rule_statement;
        $$ = ret;
    }
    | inst_clause use_clause SEMICOLON 
    {
        ast::config_rule_statement *ret = new ast::config_rule_statement;
        $$ = ret;
    }
    | cell_clause liblist_clause SEMICOLON 
    {
        ast::config_rule_statement *ret = new ast::config_rule_statement;
        $$ = ret;
    }
    | cell_clause use_clause SEMICOLON 
    {
        ast::config_rule_statement *ret = new ast::config_rule_statement;
        $$ = ret;
    }
    ;

default_clause 
    : DEFAULT_ 
    {
        ast::default_clause *ret = new ast::default_clause;
        $$ = ret;
    }
    ;

inst_clause 
    : INSTANCE_ inst_name 
    {
        ast::inst_clause *ret = new ast::inst_clause;
        $$ = ret;
    }
    ;

inst_name 
    : topmodule_identifier STAR_19 
    {
        ast::inst_name *ret = new ast::inst_name;
        $$ = ret;
    }
    ;

cell_clause 
    : CELL_ OPT_33 cell_identifier 
    {
        ast::cell_clause *ret = new ast::cell_clause;
        $$ = ret;
    }
    ;

liblist_clause 
    : LIBLIST_ STAR_20 
    {
        ast::liblist_clause *ret = new ast::liblist_clause;
        $$ = ret;
    }
    ;

use_clause 
    : USE_ OPT_33 cell_identifier OPT_34 
    {
        ast::use_clause *ret = new ast::use_clause;
        $$ = ret;
    }
    | USE_ LIST_28 OPT_34 
    {
        ast::use_clause *ret = new ast::use_clause;
        $$ = ret;
    }
    | USE_ OPT_33 cell_identifier LIST_28 OPT_34 
    {
        ast::use_clause *ret = new ast::use_clause;
        $$ = ret;
    }
    ;

interface_or_generate_item 
    : STAR_2 module_common_item 
    {
        ast::interface_or_generate_item *ret = new ast::interface_or_generate_item;
        $$ = ret;
    }
    | STAR_2 modport_declaration 
    {
        ast::interface_or_generate_item *ret = new ast::interface_or_generate_item;
        $$ = ret;
    }
    | STAR_2 extern_tf_declaration 
    {
        ast::interface_or_generate_item *ret = new ast::interface_or_generate_item;
        $$ = ret;
    }
    ;

extern_tf_declaration 
    : EXTERN_ method_prototype SEMICOLON 
    {
        ast::extern_tf_declaration *ret = new ast::extern_tf_declaration;
        $$ = ret;
    }
    | EXTERN_ FORKJOIN_ task_prototype SEMICOLON 
    {
        ast::extern_tf_declaration *ret = new ast::extern_tf_declaration;
        $$ = ret;
    }
    ;

interface_item 
    : port_declaration SEMICOLON 
    {
        ast::interface_item *ret = new ast::interface_item;
        $$ = ret;
    }
    | non_port_interface_item 
    {
        ast::interface_item *ret = new ast::interface_item;
        $$ = ret;
    }
    ;

non_port_interface_item 
    : generate_region 
    {
        ast::non_port_interface_item *ret = new ast::non_port_interface_item;
        $$ = ret;
    }
    | interface_or_generate_item 
    {
        ast::non_port_interface_item *ret = new ast::non_port_interface_item;
        $$ = ret;
    }
    | program_declaration 
    {
        ast::non_port_interface_item *ret = new ast::non_port_interface_item;
        $$ = ret;
    }
    | interface_declaration 
    {
        ast::non_port_interface_item *ret = new ast::non_port_interface_item;
        $$ = ret;
    }
    | timeunits_declaration 
    {
        ast::non_port_interface_item *ret = new ast::non_port_interface_item;
        $$ = ret;
    }
    ;

program_item 
    : port_declaration SEMICOLON 
    {
        ast::program_item *ret = new ast::program_item;
        $$ = ret;
    }
    | non_port_program_item 
    {
        ast::program_item *ret = new ast::program_item;
        $$ = ret;
    }
    ;

non_port_program_item 
    : STAR_2 continuous_assign 
    {
        ast::non_port_program_item *ret = new ast::non_port_program_item;
        $$ = ret;
    }
    | STAR_2 module_or_generate_item_declaration 
    {
        ast::non_port_program_item *ret = new ast::non_port_program_item;
        $$ = ret;
    }
    | STAR_2 initial_construct 
    {
        ast::non_port_program_item *ret = new ast::non_port_program_item;
        $$ = ret;
    }
    | STAR_2 final_construct 
    {
        ast::non_port_program_item *ret = new ast::non_port_program_item;
        $$ = ret;
    }
    | STAR_2 concurrent_assertion_item 
    {
        ast::non_port_program_item *ret = new ast::non_port_program_item;
        $$ = ret;
    }
    | timeunits_declaration 
    {
        ast::non_port_program_item *ret = new ast::non_port_program_item;
        $$ = ret;
    }
    | program_generate_item 
    {
        ast::non_port_program_item *ret = new ast::non_port_program_item;
        $$ = ret;
    }
    ;

program_generate_item 
    : loop_generate_construct 
    {
        ast::program_generate_item *ret = new ast::program_generate_item;
        $$ = ret;
    }
    | conditional_generate_construct 
    {
        ast::program_generate_item *ret = new ast::program_generate_item;
        $$ = ret;
    }
    | generate_region 
    {
        ast::program_generate_item *ret = new ast::program_generate_item;
        $$ = ret;
    }
    | elaboration_system_task 
    {
        ast::program_generate_item *ret = new ast::program_generate_item;
        $$ = ret;
    }
    ;

checker_port_list 
    : LIST_29 
    {
        ast::checker_port_list *ret = new ast::checker_port_list;
        $$ = ret;
    }
    ;

checker_port_item 
    : STAR_2 OPT_35 property_formal_type formal_port_identifier STAR_15 OPT_36 
    {
        ast::checker_port_item *ret = new ast::checker_port_item;
        $$ = ret;
    }
    ;

checker_port_direction 
    : INPUT_ 
    {
        ast::checker_port_direction *ret = new ast::checker_port_direction;
        $$ = ret;
    }
    | OUTPUT_ 
    {
        ast::checker_port_direction *ret = new ast::checker_port_direction;
        $$ = ret;
    }
    ;

checker_or_generate_item 
    : checker_or_generate_item_declaration 
    {
        ast::checker_or_generate_item *ret = new ast::checker_or_generate_item;
        $$ = ret;
    }
    | initial_construct 
    {
        ast::checker_or_generate_item *ret = new ast::checker_or_generate_item;
        $$ = ret;
    }
    | always_construct 
    {
        ast::checker_or_generate_item *ret = new ast::checker_or_generate_item;
        $$ = ret;
    }
    | final_construct 
    {
        ast::checker_or_generate_item *ret = new ast::checker_or_generate_item;
        $$ = ret;
    }
    | assertion_item 
    {
        ast::checker_or_generate_item *ret = new ast::checker_or_generate_item;
        $$ = ret;
    }
    | continuous_assign 
    {
        ast::checker_or_generate_item *ret = new ast::checker_or_generate_item;
        $$ = ret;
    }
    | checker_generate_item 
    {
        ast::checker_or_generate_item *ret = new ast::checker_or_generate_item;
        $$ = ret;
    }
    ;

checker_or_generate_item_declaration 
    : OPT_37 data_declaration 
    {
        ast::checker_or_generate_item_declaration *ret = new ast::checker_or_generate_item_declaration;
        $$ = ret;
    }
    | function_declaration 
    {
        ast::checker_or_generate_item_declaration *ret = new ast::checker_or_generate_item_declaration;
        $$ = ret;
    }
    | checker_declaration 
    {
        ast::checker_or_generate_item_declaration *ret = new ast::checker_or_generate_item_declaration;
        $$ = ret;
    }
    | assertion_item_declaration 
    {
        ast::checker_or_generate_item_declaration *ret = new ast::checker_or_generate_item_declaration;
        $$ = ret;
    }
    | covergroup_declaration 
    {
        ast::checker_or_generate_item_declaration *ret = new ast::checker_or_generate_item_declaration;
        $$ = ret;
    }
    | overload_declaration 
    {
        ast::checker_or_generate_item_declaration *ret = new ast::checker_or_generate_item_declaration;
        $$ = ret;
    }
    | genvar_declaration 
    {
        ast::checker_or_generate_item_declaration *ret = new ast::checker_or_generate_item_declaration;
        $$ = ret;
    }
    | clocking_declaration 
    {
        ast::checker_or_generate_item_declaration *ret = new ast::checker_or_generate_item_declaration;
        $$ = ret;
    }
    | DEFAULT_ CLOCKING_ clocking_identifier SEMICOLON 
    {
        ast::checker_or_generate_item_declaration *ret = new ast::checker_or_generate_item_declaration;
        $$ = ret;
    }
    | DEFAULT_ DISABLE_ IFF_ expression_or_dist SEMICOLON 
    {
        ast::checker_or_generate_item_declaration *ret = new ast::checker_or_generate_item_declaration;
        $$ = ret;
    }
    ;

checker_generate_item 
    : loop_generate_construct 
    {
        ast::checker_generate_item *ret = new ast::checker_generate_item;
        $$ = ret;
    }
    | conditional_generate_construct 
    {
        ast::checker_generate_item *ret = new ast::checker_generate_item;
        $$ = ret;
    }
    | generate_region 
    {
        ast::checker_generate_item *ret = new ast::checker_generate_item;
        $$ = ret;
    }
    | elaboration_system_task 
    {
        ast::checker_generate_item *ret = new ast::checker_generate_item;
        $$ = ret;
    }
    ;

class_item 
    : STAR_2 class_property 
    {
        ast::class_item *ret = new ast::class_item;
        $$ = ret;
    }
    | STAR_2 class_method 
    {
        ast::class_item *ret = new ast::class_item;
        $$ = ret;
    }
    | STAR_2 class_constraint 
    {
        ast::class_item *ret = new ast::class_item;
        $$ = ret;
    }
    | STAR_2 class_declaration 
    {
        ast::class_item *ret = new ast::class_item;
        $$ = ret;
    }
    | STAR_2 covergroup_declaration 
    {
        ast::class_item *ret = new ast::class_item;
        $$ = ret;
    }
    | local_parameter_declaration SEMICOLON 
    {
        ast::class_item *ret = new ast::class_item;
        $$ = ret;
    }
    | parameter_declaration SEMICOLON 
    {
        ast::class_item *ret = new ast::class_item;
        $$ = ret;
    }
    | SEMICOLON 
    {
        ast::class_item *ret = new ast::class_item;
        $$ = ret;
    }
    ;

class_property 
    : STAR_21 data_declaration 
    {
        ast::class_property *ret = new ast::class_property;
        $$ = ret;
    }
    | CONST_ STAR_22 data_type const_identifier OPT_24 SEMICOLON 
    {
        ast::class_property *ret = new ast::class_property;
        $$ = ret;
    }
    ;

class_method 
    : STAR_23 task_declaration 
    {
        ast::class_method *ret = new ast::class_method;
        $$ = ret;
    }
    | STAR_23 function_declaration 
    {
        ast::class_method *ret = new ast::class_method;
        $$ = ret;
    }
    | PURE_ VIRTUAL_ STAR_22 method_prototype SEMICOLON 
    {
        ast::class_method *ret = new ast::class_method;
        $$ = ret;
    }
    | EXTERN_ STAR_23 method_prototype SEMICOLON 
    {
        ast::class_method *ret = new ast::class_method;
        $$ = ret;
    }
    | STAR_23 class_constructor_declaration 
    {
        ast::class_method *ret = new ast::class_method;
        $$ = ret;
    }
    | EXTERN_ STAR_23 class_constructor_prototype 
    {
        ast::class_method *ret = new ast::class_method;
        $$ = ret;
    }
    ;

class_constructor_prototype 
    : FUNCTION_ NEW_ OPT_39 SEMICOLON 
    {
        ast::class_constructor_prototype *ret = new ast::class_constructor_prototype;
        $$ = ret;
    }
    ;

class_constraint 
    : constraint_prototype 
    {
        ast::class_constraint *ret = new ast::class_constraint;
        $$ = ret;
    }
    | constraint_declaration 
    {
        ast::class_constraint *ret = new ast::class_constraint;
        $$ = ret;
    }
    ;

class_item_qualifier 
    : STATIC_ 
    {
        ast::class_item_qualifier *ret = new ast::class_item_qualifier;
        $$ = ret;
    }
    | PROTECTED_ 
    {
        ast::class_item_qualifier *ret = new ast::class_item_qualifier;
        $$ = ret;
    }
    | LOCAL_ 
    {
        ast::class_item_qualifier *ret = new ast::class_item_qualifier;
        $$ = ret;
    }
    ;

property_qualifier 
    : random_qualifier 
    {
        ast::property_qualifier *ret = new ast::property_qualifier;
        $$ = ret;
    }
    | class_item_qualifier 
    {
        ast::property_qualifier *ret = new ast::property_qualifier;
        $$ = ret;
    }
    ;

random_qualifier 
    : RAND_ 
    {
        ast::random_qualifier *ret = new ast::random_qualifier;
        $$ = ret;
    }
    | RANDC_ 
    {
        ast::random_qualifier *ret = new ast::random_qualifier;
        $$ = ret;
    }
    ;

method_qualifier 
    : OPT_40 VIRTUAL_ 
    {
        ast::method_qualifier *ret = new ast::method_qualifier;
        $$ = ret;
    }
    | class_item_qualifier 
    {
        ast::method_qualifier *ret = new ast::method_qualifier;
        $$ = ret;
    }
    ;

method_prototype 
    : task_prototype 
    {
        ast::method_prototype *ret = new ast::method_prototype;
        $$ = ret;
    }
    | function_prototype 
    {
        ast::method_prototype *ret = new ast::method_prototype;
        $$ = ret;
    }
    ;

class_constructor_declaration 
    : FUNCTION_ OPT_41 NEW_ OPT_39 SEMICOLON STAR_24 OPT_42 STAR_25 ENDFUNCTION_ OPT_43 
    {
        ast::class_constructor_declaration *ret = new ast::class_constructor_declaration;
        $$ = ret;
    }
    ;

constraint_declaration 
    : OPT_44 CONSTRAINT_ constraint_identifier constraint_block 
    {
        ast::constraint_declaration *ret = new ast::constraint_declaration;
        $$ = ret;
    }
    ;

constraint_block 
    : LMP STAR_26 RMP 
    {
        ast::constraint_block *ret = new ast::constraint_block;
        $$ = ret;
    }
    ;

constraint_block_item 
    : SOLVE_ solve_before_list BEFORE_ solve_before_list SEMICOLON 
    {
        ast::constraint_block_item *ret = new ast::constraint_block_item;
        $$ = ret;
    }
    | constraint_expression 
    {
        ast::constraint_block_item *ret = new ast::constraint_block_item;
        $$ = ret;
    }
    ;

solve_before_list 
    : LIST_36 
    {
        ast::solve_before_list *ret = new ast::solve_before_list;
        $$ = ret;
    }
    ;

constraint_primary 
    : OPT_45 hierarchical_identifier select 
    {
        ast::constraint_primary *ret = new ast::constraint_primary;
        $$ = ret;
    }
    ;

constraint_expression 
    : OPT_46 expression_or_dist SEMICOLON 
    {
        ast::constraint_expression *ret = new ast::constraint_expression;
        $$ = ret;
    }
    | uniqueness_constraint SEMICOLON 
    {
        ast::constraint_expression *ret = new ast::constraint_expression;
        $$ = ret;
    }
    | expression RIGHTARROW constraint_set 
    {
        ast::constraint_expression *ret = new ast::constraint_expression;
        $$ = ret;
    }
    | IF_ LP expression RP constraint_set OPT_47 
    {
        ast::constraint_expression *ret = new ast::constraint_expression;
        $$ = ret;
    }
    | FOREACH_ LP ps_or_hierarchical_array_identifier LSP loop_variables RSP RP constraint_set 
    {
        ast::constraint_expression *ret = new ast::constraint_expression;
        $$ = ret;
    }
    | DISABLE_ SOFT_ constraint_primary SEMICOLON 
    {
        ast::constraint_expression *ret = new ast::constraint_expression;
        $$ = ret;
    }
    ;

uniqueness_constraint 
    : UNIQUE_ LMP open_range_list RMP 
    {
        ast::uniqueness_constraint *ret = new ast::uniqueness_constraint;
        $$ = ret;
    }
    ;

constraint_set 
    : constraint_expression 
    {
        ast::constraint_set *ret = new ast::constraint_set;
        $$ = ret;
    }
    | LMP STAR_27 RMP 
    {
        ast::constraint_set *ret = new ast::constraint_set;
        $$ = ret;
    }
    ;

dist_list 
    : LIST_38 
    {
        ast::dist_list *ret = new ast::dist_list;
        $$ = ret;
    }
    ;

dist_item 
    : value_range OPT_48 
    {
        ast::dist_item *ret = new ast::dist_item;
        $$ = ret;
    }
    ;

dist_weight 
    : COLON_EQUAL expression 
    {
        ast::dist_weight *ret = new ast::dist_weight;
        $$ = ret;
    }
    | COLON_SLASH expression 
    {
        ast::dist_weight *ret = new ast::dist_weight;
        $$ = ret;
    }
    ;

constraint_prototype 
    : OPT_49 OPT_44 CONSTRAINT_ constraint_identifier SEMICOLON 
    {
        ast::constraint_prototype *ret = new ast::constraint_prototype;
        $$ = ret;
    }
    ;

constraint_prototype_qualifier 
    : EXTERN_ 
    {
        ast::constraint_prototype_qualifier *ret = new ast::constraint_prototype_qualifier;
        $$ = ret;
    }
    | PURE_ 
    {
        ast::constraint_prototype_qualifier *ret = new ast::constraint_prototype_qualifier;
        $$ = ret;
    }
    ;

extern_constraint_declaration 
    : OPT_44 CONSTRAINT_ class_scope constraint_identifier constraint_block 
    {
        ast::extern_constraint_declaration *ret = new ast::extern_constraint_declaration;
        $$ = ret;
    }
    ;

identifier_list 
    : LIST_39 
    {
        ast::identifier_list *ret = new ast::identifier_list;
        $$ = ret;
    }
    ;

package_item 
    : package_or_generate_item_declaration 
    {
        ast::package_item *ret = new ast::package_item;
        $$ = ret;
    }
    | anonymous_program 
    {
        ast::package_item *ret = new ast::package_item;
        $$ = ret;
    }
    | package_export_declaration 
    {
        ast::package_item *ret = new ast::package_item;
        $$ = ret;
    }
    | timeunits_declaration 
    {
        ast::package_item *ret = new ast::package_item;
        $$ = ret;
    }
    ;

package_or_generate_item_declaration 
    : net_declaration 
    {
        ast::package_or_generate_item_declaration *ret = new ast::package_or_generate_item_declaration;
        $$ = ret;
    }
    | data_declaration 
    {
        ast::package_or_generate_item_declaration *ret = new ast::package_or_generate_item_declaration;
        $$ = ret;
    }
    | task_declaration 
    {
        ast::package_or_generate_item_declaration *ret = new ast::package_or_generate_item_declaration;
        $$ = ret;
    }
    | function_declaration 
    {
        ast::package_or_generate_item_declaration *ret = new ast::package_or_generate_item_declaration;
        $$ = ret;
    }
    | checker_declaration 
    {
        ast::package_or_generate_item_declaration *ret = new ast::package_or_generate_item_declaration;
        $$ = ret;
    }
    | dpi_import_export 
    {
        ast::package_or_generate_item_declaration *ret = new ast::package_or_generate_item_declaration;
        $$ = ret;
    }
    | extern_constraint_declaration 
    {
        ast::package_or_generate_item_declaration *ret = new ast::package_or_generate_item_declaration;
        $$ = ret;
    }
    | class_declaration 
    {
        ast::package_or_generate_item_declaration *ret = new ast::package_or_generate_item_declaration;
        $$ = ret;
    }
    | class_constructor_declaration 
    {
        ast::package_or_generate_item_declaration *ret = new ast::package_or_generate_item_declaration;
        $$ = ret;
    }
    | local_parameter_declaration SEMICOLON 
    {
        ast::package_or_generate_item_declaration *ret = new ast::package_or_generate_item_declaration;
        $$ = ret;
    }
    | parameter_declaration SEMICOLON 
    {
        ast::package_or_generate_item_declaration *ret = new ast::package_or_generate_item_declaration;
        $$ = ret;
    }
    | covergroup_declaration 
    {
        ast::package_or_generate_item_declaration *ret = new ast::package_or_generate_item_declaration;
        $$ = ret;
    }
    | overload_declaration 
    {
        ast::package_or_generate_item_declaration *ret = new ast::package_or_generate_item_declaration;
        $$ = ret;
    }
    | assertion_item_declaration 
    {
        ast::package_or_generate_item_declaration *ret = new ast::package_or_generate_item_declaration;
        $$ = ret;
    }
    | SEMICOLON 
    {
        ast::package_or_generate_item_declaration *ret = new ast::package_or_generate_item_declaration;
        $$ = ret;
    }
    ;

anonymous_program 
    : PROGRAM_ SEMICOLON STAR_28 ENDPROGRAM_ 
    {
        ast::anonymous_program *ret = new ast::anonymous_program;
        $$ = ret;
    }
    ;

anonymous_program_item 
    : task_declaration 
    {
        ast::anonymous_program_item *ret = new ast::anonymous_program_item;
        $$ = ret;
    }
    | function_declaration 
    {
        ast::anonymous_program_item *ret = new ast::anonymous_program_item;
        $$ = ret;
    }
    | class_declaration 
    {
        ast::anonymous_program_item *ret = new ast::anonymous_program_item;
        $$ = ret;
    }
    | covergroup_declaration 
    {
        ast::anonymous_program_item *ret = new ast::anonymous_program_item;
        $$ = ret;
    }
    | class_constructor_declaration 
    {
        ast::anonymous_program_item *ret = new ast::anonymous_program_item;
        $$ = ret;
    }
    | SEMICOLON 
    {
        ast::anonymous_program_item *ret = new ast::anonymous_program_item;
        $$ = ret;
    }
    ;

local_parameter_declaration 
    : LOCALPARAM_ data_type_or_implicit list_of_param_assignments 
    {
        ast::local_parameter_declaration *ret = new ast::local_parameter_declaration;
        $$ = ret;
    }
    | LOCALPARAM_ TYPE_ list_of_type_assignments 
    {
        ast::local_parameter_declaration *ret = new ast::local_parameter_declaration;
        $$ = ret;
    }
    ;

parameter_declaration 
    : PARAMETER_ data_type_or_implicit list_of_param_assignments 
    {
        ast::parameter_declaration *ret = new ast::parameter_declaration;
        $$ = ret;
    }
    | PARAMETER_ TYPE_ list_of_type_assignments 
    {
        ast::parameter_declaration *ret = new ast::parameter_declaration;
        $$ = ret;
    }
    ;

specparam_declaration 
    : SPECPARAM_ OPT_50 list_of_specparam_assignments SEMICOLON 
    {
        ast::specparam_declaration *ret = new ast::specparam_declaration;
        $$ = ret;
    }
    ;

inout_declaration 
    : INOUT_ net_port_type list_of_port_identifiers 
    {
        ast::inout_declaration *ret = new ast::inout_declaration;
        $$ = ret;
    }
    ;

input_declaration 
    : INPUT_ net_port_type list_of_port_identifiers 
    {
        ast::input_declaration *ret = new ast::input_declaration;
        $$ = ret;
    }
    | INPUT_ variable_port_type list_of_variable_identifiers 
    {
        ast::input_declaration *ret = new ast::input_declaration;
        $$ = ret;
    }
    ;

output_declaration 
    : OUTPUT_ net_port_type list_of_port_identifiers 
    {
        ast::output_declaration *ret = new ast::output_declaration;
        $$ = ret;
    }
    | OUTPUT_ variable_port_type list_of_variable_port_identifiers 
    {
        ast::output_declaration *ret = new ast::output_declaration;
        $$ = ret;
    }
    ;

interface_port_declaration 
    : interface_identifier list_of_interface_identifiers 
    {
        ast::interface_port_declaration *ret = new ast::interface_port_declaration;
        $$ = ret;
    }
    | interface_identifier DOT modport_identifier list_of_interface_identifiers 
    {
        ast::interface_port_declaration *ret = new ast::interface_port_declaration;
        $$ = ret;
    }
    ;

ref_declaration 
    : REF_ variable_port_type list_of_variable_identifiers 
    {
        ast::ref_declaration *ret = new ast::ref_declaration;
        $$ = ret;
    }
    ;

data_declaration 
    : OPT_51 OPT_52 OPT_2 data_type_or_implicit list_of_variable_decl_assignments SEMICOLON 
    {
        ast::data_declaration *ret = new ast::data_declaration;
        $$ = ret;
    }
    | type_declaration 
    {
        ast::data_declaration *ret = new ast::data_declaration;
        $$ = ret;
    }
    | package_import_declaration 
    {
        ast::data_declaration *ret = new ast::data_declaration;
        $$ = ret;
    }
    | net_type_declaration 
    {
        ast::data_declaration *ret = new ast::data_declaration;
        $$ = ret;
    }
    ;

package_import_declaration 
    : IMPORT_ LIST_41 SEMICOLON 
    {
        ast::package_import_declaration *ret = new ast::package_import_declaration;
        $$ = ret;
    }
    ;

package_import_item 
    : package_identifier COLON2 identifier 
    {
        ast::package_import_item *ret = new ast::package_import_item;
        $$ = ret;
    }
    | package_identifier COLON2 STAR 
    {
        ast::package_import_item *ret = new ast::package_import_item;
        $$ = ret;
    }
    ;

package_export_declaration 
    : EXPORT_ STAR_COLON2_STAR SEMICOLON 
    {
        ast::package_export_declaration *ret = new ast::package_export_declaration;
        $$ = ret;
    }
    | EXPORT_ LIST_41 SEMICOLON 
    {
        ast::package_export_declaration *ret = new ast::package_export_declaration;
        $$ = ret;
    }
    ;

genvar_declaration 
    : GENVAR_ list_of_genvar_identifiers SEMICOLON 
    {
        ast::genvar_declaration *ret = new ast::genvar_declaration;
        $$ = ret;
    }
    ;

net_declaration 
    : net_type OPT_53 OPT_54 data_type_or_implicit OPT_55 list_of_net_decl_assignments SEMICOLON 
    {
        ast::net_declaration *ret = new ast::net_declaration;
        $$ = ret;
    }
    | net_type_identifier OPT_56 list_of_net_decl_assignments SEMICOLON 
    {
        ast::net_declaration *ret = new ast::net_declaration;
        $$ = ret;
    }
    | INTERCONNECT_ implicit_data_type OPT_57 LIST_42 SEMICOLON 
    {
        ast::net_declaration *ret = new ast::net_declaration;
        $$ = ret;
    }
    ;

type_declaration 
    : TYPEDEF_ data_type type_identifier STAR_15 SEMICOLON 
    {
        ast::type_declaration *ret = new ast::type_declaration;
        $$ = ret;
    }
    | TYPEDEF_ interface_instance_identifier constant_bit_select DOT type_identifier type_identifier SEMICOLON 
    {
        ast::type_declaration *ret = new ast::type_declaration;
        $$ = ret;
    }
    | TYPEDEF_ OPT_58 type_identifier SEMICOLON 
    {
        ast::type_declaration *ret = new ast::type_declaration;
        $$ = ret;
    }
    ;

net_type_declaration 
    : NETTYPE_ data_type net_type_identifier OPT_60 SEMICOLON 
    {
        ast::net_type_declaration *ret = new ast::net_type_declaration;
        $$ = ret;
    }
    | NETTYPE_ OPT_59 net_type_identifier net_type_identifier SEMICOLON 
    {
        ast::net_type_declaration *ret = new ast::net_type_declaration;
        $$ = ret;
    }
    ;

lifetime 
    : STATIC_ 
    {
        ast::lifetime *ret = new ast::lifetime;
        $$ = ret;
    }
    | AUTOMATIC_ 
    {
        ast::lifetime *ret = new ast::lifetime;
        $$ = ret;
    }
    ;

casting_type 
    : simple_type 
    {
        ast::casting_type *ret = new ast::casting_type;
        $$ = ret;
    }
    | constant_primary 
    {
        ast::casting_type *ret = new ast::casting_type;
        $$ = ret;
    }
    | signing 
    {
        ast::casting_type *ret = new ast::casting_type;
        $$ = ret;
    }
    | STRING_ 
    {
        ast::casting_type *ret = new ast::casting_type;
        $$ = ret;
    }
    | CONST_ 
    {
        ast::casting_type *ret = new ast::casting_type;
        $$ = ret;
    }
    ;

data_type 
    : integer_vector_type OPT_61 STAR_29 
    {
        ast::data_type *ret = new ast::data_type;
        $$ = ret;
    }
    | integer_atom_type OPT_61 
    {
        ast::data_type *ret = new ast::data_type;
        $$ = ret;
    }
    | non_integer_type 
    {
        ast::data_type *ret = new ast::data_type;
        $$ = ret;
    }
    | struct_union OPT_62 LMP LIST_44 RMP STAR_29 
    {
        ast::data_type *ret = new ast::data_type;
        $$ = ret;
    }
    | ENUM_ OPT_63 LMP LIST_45 RMP STAR_29 
    {
        ast::data_type *ret = new ast::data_type;
        $$ = ret;
    }
    | STRING_ 
    {
        ast::data_type *ret = new ast::data_type;
        $$ = ret;
    }
    | CHANDLE_ 
    {
        ast::data_type *ret = new ast::data_type;
        $$ = ret;
    }
    | VIRTUAL_ OPT_64 interface_identifier OPT_16 OPT_22 
    {
        ast::data_type *ret = new ast::data_type;
        $$ = ret;
    }
    | OPT_65 type_identifier STAR_29 
    {
        ast::data_type *ret = new ast::data_type;
        $$ = ret;
    }
    | class_type 
    {
        ast::data_type *ret = new ast::data_type;
        $$ = ret;
    }
    | EVENT_ 
    {
        ast::data_type *ret = new ast::data_type;
        $$ = ret;
    }
    | ps_covergroup_identifier 
    {
        ast::data_type *ret = new ast::data_type;
        $$ = ret;
    }
    | type_reference 
    {
        ast::data_type *ret = new ast::data_type;
        $$ = ret;
    }
    ;

data_type_or_implicit 
    : data_type 
    {
        ast::data_type_or_implicit *ret = new ast::data_type_or_implicit;
        $$ = ret;
    }
    | implicit_data_type 
    {
        ast::data_type_or_implicit *ret = new ast::data_type_or_implicit;
        $$ = ret;
    }
    ;

implicit_data_type 
    : OPT_61 STAR_29 
    {
        ast::implicit_data_type *ret = new ast::implicit_data_type;
        $$ = ret;
    }
    ;

enum_base_type 
    : integer_atom_type OPT_61 
    {
        ast::enum_base_type *ret = new ast::enum_base_type;
        $$ = ret;
    }
    | integer_vector_type OPT_61 OPT_50 
    {
        ast::enum_base_type *ret = new ast::enum_base_type;
        $$ = ret;
    }
    | type_identifier OPT_50 
    {
        ast::enum_base_type *ret = new ast::enum_base_type;
        $$ = ret;
    }
    ;

enum_name_declaration 
    : enum_identifier OPT_67 OPT_24 
    {
        ast::enum_name_declaration *ret = new ast::enum_name_declaration;
        $$ = ret;
    }
    ;

class_scope 
    : class_type COLON2 
    {
        ast::class_scope *ret = new ast::class_scope;
        $$ = ret;
    }
    ;

class_type 
    : ps_class_identifier OPT_16 STAR_30 
    {
        ast::class_type *ret = new ast::class_type;
        $$ = ret;
    }
    ;

integer_type 
    : integer_vector_type 
    {
        ast::integer_type *ret = new ast::integer_type;
        $$ = ret;
    }
    | integer_atom_type 
    {
        ast::integer_type *ret = new ast::integer_type;
        $$ = ret;
    }
    ;

integer_atom_type 
    : BYTE_ 
    {
        ast::integer_atom_type *ret = new ast::integer_atom_type;
        $$ = ret;
    }
    | SHORTINT_ 
    {
        ast::integer_atom_type *ret = new ast::integer_atom_type;
        $$ = ret;
    }
    | INT_ 
    {
        ast::integer_atom_type *ret = new ast::integer_atom_type;
        $$ = ret;
    }
    | LONGINT_ 
    {
        ast::integer_atom_type *ret = new ast::integer_atom_type;
        $$ = ret;
    }
    | INTEGER_ 
    {
        ast::integer_atom_type *ret = new ast::integer_atom_type;
        $$ = ret;
    }
    | TIME_ 
    {
        ast::integer_atom_type *ret = new ast::integer_atom_type;
        $$ = ret;
    }
    ;

integer_vector_type 
    : BIT_ 
    {
        ast::integer_vector_type *ret = new ast::integer_vector_type;
        $$ = ret;
    }
    | LOGIC_ 
    {
        ast::integer_vector_type *ret = new ast::integer_vector_type;
        $$ = ret;
    }
    | REG_ 
    {
        ast::integer_vector_type *ret = new ast::integer_vector_type;
        $$ = ret;
    }
    ;

non_integer_type 
    : SHORTREAL_ 
    {
        ast::non_integer_type *ret = new ast::non_integer_type;
        $$ = ret;
    }
    | REAL_ 
    {
        ast::non_integer_type *ret = new ast::non_integer_type;
        $$ = ret;
    }
    | REALTIME_ 
    {
        ast::non_integer_type *ret = new ast::non_integer_type;
        $$ = ret;
    }
    ;

net_type 
    : SUPPLY0_ 
    {
        ast::net_type *ret = new ast::net_type;
        $$ = ret;
    }
    | SUPPLY1_ 
    {
        ast::net_type *ret = new ast::net_type;
        $$ = ret;
    }
    | TRI_ 
    {
        ast::net_type *ret = new ast::net_type;
        $$ = ret;
    }
    | TRIAND_ 
    {
        ast::net_type *ret = new ast::net_type;
        $$ = ret;
    }
    | TRIOR_ 
    {
        ast::net_type *ret = new ast::net_type;
        $$ = ret;
    }
    | TRIREG_ 
    {
        ast::net_type *ret = new ast::net_type;
        $$ = ret;
    }
    | TRI0_ 
    {
        ast::net_type *ret = new ast::net_type;
        $$ = ret;
    }
    | TRI1_ 
    {
        ast::net_type *ret = new ast::net_type;
        $$ = ret;
    }
    | UWIRE_ 
    {
        ast::net_type *ret = new ast::net_type;
        $$ = ret;
    }
    | WIRE_ 
    {
        ast::net_type *ret = new ast::net_type;
        $$ = ret;
    }
    | WAND_ 
    {
        ast::net_type *ret = new ast::net_type;
        $$ = ret;
    }
    | WOR_ 
    {
        ast::net_type *ret = new ast::net_type;
        $$ = ret;
    }
    ;

net_port_type 
    : OPT_68 data_type_or_implicit 
    {
        ast::net_port_type *ret = new ast::net_port_type;
        $$ = ret;
    }
    | net_type_identifier 
    {
        ast::net_port_type *ret = new ast::net_port_type;
        $$ = ret;
    }
    | INTERCONNECT_ implicit_data_type 
    {
        ast::net_port_type *ret = new ast::net_port_type;
        $$ = ret;
    }
    ;

variable_port_type 
    : var_data_type 
    {
        ast::variable_port_type *ret = new ast::variable_port_type;
        $$ = ret;
    }
    ;

var_data_type 
    : data_type 
    {
        ast::var_data_type *ret = new ast::var_data_type;
        $$ = ret;
    }
    | VAR_ data_type_or_implicit 
    {
        ast::var_data_type *ret = new ast::var_data_type;
        $$ = ret;
    }
    ;

signing 
    : SIGNED_ 
    {
        ast::signing *ret = new ast::signing;
        $$ = ret;
    }
    | UNSIGNED_ 
    {
        ast::signing *ret = new ast::signing;
        $$ = ret;
    }
    ;

simple_type 
    : integer_type 
    {
        ast::simple_type *ret = new ast::simple_type;
        $$ = ret;
    }
    | non_integer_type 
    {
        ast::simple_type *ret = new ast::simple_type;
        $$ = ret;
    }
    | ps_type_identifier 
    {
        ast::simple_type *ret = new ast::simple_type;
        $$ = ret;
    }
    | ps_parameter_identifier 
    {
        ast::simple_type *ret = new ast::simple_type;
        $$ = ret;
    }
    ;

struct_union_member 
    : STAR_2 OPT_69 data_type_or_void list_of_variable_decl_assignments SEMICOLON 
    {
        ast::struct_union_member *ret = new ast::struct_union_member;
        $$ = ret;
    }
    ;

data_type_or_void 
    : data_type 
    {
        ast::data_type_or_void *ret = new ast::data_type_or_void;
        $$ = ret;
    }
    | VOID_ 
    {
        ast::data_type_or_void *ret = new ast::data_type_or_void;
        $$ = ret;
    }
    ;

struct_union 
    : STRUCT_ 
    {
        ast::struct_union *ret = new ast::struct_union;
        $$ = ret;
    }
    | UNION_ OPT_70 
    {
        ast::struct_union *ret = new ast::struct_union;
        $$ = ret;
    }
    ;

type_reference 
    : TYPE_ LP expression RP 
    {
        ast::type_reference *ret = new ast::type_reference;
        $$ = ret;
    }
    | TYPE_ LP data_type RP 
    {
        ast::type_reference *ret = new ast::type_reference;
        $$ = ret;
    }
    ;

drive_strength 
    : LP strength0 COMMA strength1 RP 
    {
        ast::drive_strength *ret = new ast::drive_strength;
        $$ = ret;
    }
    | LP strength1 COMMA strength0 RP 
    {
        ast::drive_strength *ret = new ast::drive_strength;
        $$ = ret;
    }
    | LP strength0 COMMA HIGHZ1_ RP 
    {
        ast::drive_strength *ret = new ast::drive_strength;
        $$ = ret;
    }
    | LP strength1 COMMA HIGHZ0_ RP 
    {
        ast::drive_strength *ret = new ast::drive_strength;
        $$ = ret;
    }
    | LP HIGHZ0_ COMMA strength1 RP 
    {
        ast::drive_strength *ret = new ast::drive_strength;
        $$ = ret;
    }
    | LP HIGHZ1_ COMMA strength0 RP 
    {
        ast::drive_strength *ret = new ast::drive_strength;
        $$ = ret;
    }
    ;

strength0 
    : SUPPLY0_ 
    {
        ast::strength0 *ret = new ast::strength0;
        $$ = ret;
    }
    | STRONG0_ 
    {
        ast::strength0 *ret = new ast::strength0;
        $$ = ret;
    }
    | PULL0_ 
    {
        ast::strength0 *ret = new ast::strength0;
        $$ = ret;
    }
    | WEAK0_ 
    {
        ast::strength0 *ret = new ast::strength0;
        $$ = ret;
    }
    ;

strength1 
    : SUPPLY1_ 
    {
        ast::strength1 *ret = new ast::strength1;
        $$ = ret;
    }
    | STRONG1_ 
    {
        ast::strength1 *ret = new ast::strength1;
        $$ = ret;
    }
    | PULL1_ 
    {
        ast::strength1 *ret = new ast::strength1;
        $$ = ret;
    }
    | WEAK1_ 
    {
        ast::strength1 *ret = new ast::strength1;
        $$ = ret;
    }
    ;

charge_strength 
    : LP SMALL_ RP 
    {
        ast::charge_strength *ret = new ast::charge_strength;
        $$ = ret;
    }
    | LP MEDIUM_ RP 
    {
        ast::charge_strength *ret = new ast::charge_strength;
        $$ = ret;
    }
    | LP LARGE_ RP 
    {
        ast::charge_strength *ret = new ast::charge_strength;
        $$ = ret;
    }
    ;

delay3 
    : SHARP delay_value 
    {
        ast::delay3 *ret = new ast::delay3;
        $$ = ret;
    }
    | SHARP LP mintypmax_expression OPT_72 RP 
    {
        ast::delay3 *ret = new ast::delay3;
        $$ = ret;
    }
    ;

delay2 
    : SHARP delay_value 
    {
        ast::delay2 *ret = new ast::delay2;
        $$ = ret;
    }
    | SHARP LP mintypmax_expression OPT_71 RP 
    {
        ast::delay2 *ret = new ast::delay2;
        $$ = ret;
    }
    ;

delay_value 
    : unsigned_number 
    {
        ast::delay_value *ret = new ast::delay_value;
        $$ = ret;
    }
    | real_number 
    {
        ast::delay_value *ret = new ast::delay_value;
        $$ = ret;
    }
    | ps_identifier 
    {
        ast::delay_value *ret = new ast::delay_value;
        $$ = ret;
    }
    | time_literal 
    {
        ast::delay_value *ret = new ast::delay_value;
        $$ = ret;
    }
    | ONESTEP_ 
    {
        ast::delay_value *ret = new ast::delay_value;
        $$ = ret;
    }
    ;

list_of_defparam_assignments 
    : LIST_47 
    {
        ast::list_of_defparam_assignments *ret = new ast::list_of_defparam_assignments;
        $$ = ret;
    }
    ;

list_of_genvar_identifiers 
    : LIST_48 
    {
        ast::list_of_genvar_identifiers *ret = new ast::list_of_genvar_identifiers;
        $$ = ret;
    }
    ;

list_of_interface_identifiers 
    : LIST_49 
    {
        ast::list_of_interface_identifiers *ret = new ast::list_of_interface_identifiers;
        $$ = ret;
    }
    ;

list_of_net_decl_assignments 
    : LIST_50 
    {
        ast::list_of_net_decl_assignments *ret = new ast::list_of_net_decl_assignments;
        $$ = ret;
    }
    ;

list_of_param_assignments 
    : LIST_51 
    {
        ast::list_of_param_assignments *ret = new ast::list_of_param_assignments;
        $$ = ret;
    }
    ;

list_of_port_identifiers 
    : LIST_52 
    {
        ast::list_of_port_identifiers *ret = new ast::list_of_port_identifiers;
        $$ = ret;
    }
    ;

list_of_udp_port_identifiers 
    : LIST_53 
    {
        ast::list_of_udp_port_identifiers *ret = new ast::list_of_udp_port_identifiers;
        $$ = ret;
    }
    ;

list_of_specparam_assignments 
    : LIST_54 
    {
        ast::list_of_specparam_assignments *ret = new ast::list_of_specparam_assignments;
        $$ = ret;
    }
    ;

list_of_tf_variable_identifiers 
    : LIST_55 
    {
        ast::list_of_tf_variable_identifiers *ret = new ast::list_of_tf_variable_identifiers;
        $$ = ret;
    }
    ;

list_of_type_assignments 
    : LIST_56 
    {
        ast::list_of_type_assignments *ret = new ast::list_of_type_assignments;
        $$ = ret;
    }
    ;

list_of_variable_decl_assignments 
    : LIST_57 
    {
        ast::list_of_variable_decl_assignments *ret = new ast::list_of_variable_decl_assignments;
        $$ = ret;
    }
    ;

list_of_variable_identifiers 
    : LIST_58 
    {
        ast::list_of_variable_identifiers *ret = new ast::list_of_variable_identifiers;
        $$ = ret;
    }
    ;

list_of_variable_port_identifiers 
    : LIST_59 
    {
        ast::list_of_variable_port_identifiers *ret = new ast::list_of_variable_port_identifiers;
        $$ = ret;
    }
    ;

defparam_assignment 
    : hierarchical_parameter_identifier EQ constant_mintypmax_expression 
    {
        ast::defparam_assignment *ret = new ast::defparam_assignment;
        $$ = ret;
    }
    ;

net_decl_assignment 
    : net_identifier STAR_14 OPT_73 
    {
        ast::net_decl_assignment *ret = new ast::net_decl_assignment;
        $$ = ret;
    }
    ;

param_assignment 
    : parameter_identifier STAR_14 OPT_74 
    {
        ast::param_assignment *ret = new ast::param_assignment;
        $$ = ret;
    }
    ;

specparam_assignment 
    : specparam_identifier EQ constant_mintypmax_expression 
    {
        ast::specparam_assignment *ret = new ast::specparam_assignment;
        $$ = ret;
    }
    | pulse_control_specparam 
    {
        ast::specparam_assignment *ret = new ast::specparam_assignment;
        $$ = ret;
    }
    ;

type_assignment 
    : type_identifier OPT_75 
    {
        ast::type_assignment *ret = new ast::type_assignment;
        $$ = ret;
    }
    ;

pulse_control_specparam 
    : TOKEN_400 EQ LP reject_limit_value OPT_76 RP 
    {
        ast::pulse_control_specparam *ret = new ast::pulse_control_specparam;
        $$ = ret;
    }
    | TOKEN_400 specify_input_terminal_descriptor DOLLAR_ specify_output_terminal_descriptor EQ LP reject_limit_value OPT_76 RP 
    {
        ast::pulse_control_specparam *ret = new ast::pulse_control_specparam;
        $$ = ret;
    }
    ;

error_limit_value 
    : limit_value 
    {
        ast::error_limit_value *ret = new ast::error_limit_value;
        $$ = ret;
    }
    ;

reject_limit_value 
    : limit_value 
    {
        ast::reject_limit_value *ret = new ast::reject_limit_value;
        $$ = ret;
    }
    ;

limit_value 
    : constant_mintypmax_expression 
    {
        ast::limit_value *ret = new ast::limit_value;
        $$ = ret;
    }
    ;

variable_decl_assignment 
    : variable_identifier STAR_15 OPT_73 
    {
        ast::variable_decl_assignment *ret = new ast::variable_decl_assignment;
        $$ = ret;
    }
    | dynamic_array_variable_identifier unsized_dimension STAR_15 OPT_77 
    {
        ast::variable_decl_assignment *ret = new ast::variable_decl_assignment;
        $$ = ret;
    }
    | class_variable_identifier OPT_78 
    {
        ast::variable_decl_assignment *ret = new ast::variable_decl_assignment;
        $$ = ret;
    }
    ;

class_new 
    : OPT_41 NEW_ OPT_12 
    {
        ast::class_new *ret = new ast::class_new;
        $$ = ret;
    }
    | NEW_ expression 
    {
        ast::class_new *ret = new ast::class_new;
        $$ = ret;
    }
    ;

dynamic_array_new 
    : NEW_ LSP expression RSP OPT_79 
    {
        ast::dynamic_array_new *ret = new ast::dynamic_array_new;
        $$ = ret;
    }
    ;

unpacked_dimension 
    : LSP constant_range RSP 
    {
        ast::unpacked_dimension *ret = new ast::unpacked_dimension;
        $$ = ret;
    }
    | LSP constant_expression RSP 
    {
        ast::unpacked_dimension *ret = new ast::unpacked_dimension;
        $$ = ret;
    }
    ;

packed_dimension 
    : LSP constant_range RSP 
    {
        ast::packed_dimension *ret = new ast::packed_dimension;
        $$ = ret;
    }
    | unsized_dimension 
    {
        ast::packed_dimension *ret = new ast::packed_dimension;
        $$ = ret;
    }
    ;

associative_dimension 
    : LSP data_type RSP 
    {
        ast::associative_dimension *ret = new ast::associative_dimension;
        $$ = ret;
    }
    | LSP STAR RSP 
    {
        ast::associative_dimension *ret = new ast::associative_dimension;
        $$ = ret;
    }
    ;

variable_dimension 
    : unsized_dimension 
    {
        ast::variable_dimension *ret = new ast::variable_dimension;
        $$ = ret;
    }
    | unpacked_dimension 
    {
        ast::variable_dimension *ret = new ast::variable_dimension;
        $$ = ret;
    }
    | associative_dimension 
    {
        ast::variable_dimension *ret = new ast::variable_dimension;
        $$ = ret;
    }
    | queue_dimension 
    {
        ast::variable_dimension *ret = new ast::variable_dimension;
        $$ = ret;
    }
    ;

queue_dimension 
    : LSP DOLLAR_ OPT_80 RSP 
    {
        ast::queue_dimension *ret = new ast::queue_dimension;
        $$ = ret;
    }
    ;

unsized_dimension 
    : LSP RSP 
    {
        ast::unsized_dimension *ret = new ast::unsized_dimension;
        $$ = ret;
    }
    ;

function_data_type_or_implicit 
    : data_type_or_void 
    {
        ast::function_data_type_or_implicit *ret = new ast::function_data_type_or_implicit;
        $$ = ret;
    }
    | implicit_data_type 
    {
        ast::function_data_type_or_implicit *ret = new ast::function_data_type_or_implicit;
        $$ = ret;
    }
    ;

function_declaration 
    : FUNCTION_ OPT_2 function_body_declaration 
    {
        ast::function_declaration *ret = new ast::function_declaration;
        $$ = ret;
    }
    ;

function_body_declaration 
    : function_data_type_or_implicit OPT_81 function_identifier SEMICOLON STAR_31 STAR_25 ENDFUNCTION_ OPT_82 
    {
        ast::function_body_declaration *ret = new ast::function_body_declaration;
        $$ = ret;
    }
    | function_data_type_or_implicit OPT_81 function_identifier LP OPT_38 RP SEMICOLON STAR_24 STAR_25 ENDFUNCTION_ OPT_82 
    {
        ast::function_body_declaration *ret = new ast::function_body_declaration;
        $$ = ret;
    }
    ;

function_prototype 
    : FUNCTION_ data_type_or_void function_identifier OPT_39 
    {
        ast::function_prototype *ret = new ast::function_prototype;
        $$ = ret;
    }
    ;

dpi_import_export 
    : IMPORT_ dpi_spec_string OPT_83 OPT_84 dpi_function_proto SEMICOLON 
    {
        ast::dpi_import_export *ret = new ast::dpi_import_export;
        $$ = ret;
    }
    | IMPORT_ dpi_spec_string OPT_85 OPT_84 dpi_task_proto SEMICOLON 
    {
        ast::dpi_import_export *ret = new ast::dpi_import_export;
        $$ = ret;
    }
    | EXPORT_ dpi_spec_string OPT_84 FUNCTION_ function_identifier SEMICOLON 
    {
        ast::dpi_import_export *ret = new ast::dpi_import_export;
        $$ = ret;
    }
    | EXPORT_ dpi_spec_string OPT_84 TASK_ task_identifier SEMICOLON 
    {
        ast::dpi_import_export *ret = new ast::dpi_import_export;
        $$ = ret;
    }
    ;

dpi_spec_string 
    : DPI_C_ 
    {
        ast::dpi_spec_string *ret = new ast::dpi_spec_string;
        $$ = ret;
    }
    | DPI_ 
    {
        ast::dpi_spec_string *ret = new ast::dpi_spec_string;
        $$ = ret;
    }
    ;

dpi_function_import_property 
    : CONTEXT_ 
    {
        ast::dpi_function_import_property *ret = new ast::dpi_function_import_property;
        $$ = ret;
    }
    | PURE_ 
    {
        ast::dpi_function_import_property *ret = new ast::dpi_function_import_property;
        $$ = ret;
    }
    ;

dpi_task_import_property 
    : CONTEXT_ 
    {
        ast::dpi_task_import_property *ret = new ast::dpi_task_import_property;
        $$ = ret;
    }
    ;

dpi_function_proto 
    : function_prototype 
    {
        ast::dpi_function_proto *ret = new ast::dpi_function_proto;
        $$ = ret;
    }
    ;

dpi_task_proto 
    : task_prototype 
    {
        ast::dpi_task_proto *ret = new ast::dpi_task_proto;
        $$ = ret;
    }
    ;

task_declaration 
    : TASK_ OPT_2 task_body_declaration 
    {
        ast::task_declaration *ret = new ast::task_declaration;
        $$ = ret;
    }
    ;

task_body_declaration 
    : OPT_81 task_identifier SEMICOLON STAR_31 STAR_32 ENDTASK_ OPT_86 
    {
        ast::task_body_declaration *ret = new ast::task_body_declaration;
        $$ = ret;
    }
    | OPT_81 task_identifier LP OPT_38 RP SEMICOLON STAR_24 STAR_32 ENDTASK_ OPT_86 
    {
        ast::task_body_declaration *ret = new ast::task_body_declaration;
        $$ = ret;
    }
    ;

tf_item_declaration 
    : block_item_declaration 
    {
        ast::tf_item_declaration *ret = new ast::tf_item_declaration;
        $$ = ret;
    }
    | tf_port_declaration 
    {
        ast::tf_item_declaration *ret = new ast::tf_item_declaration;
        $$ = ret;
    }
    ;

tf_port_list 
    : LIST_62 
    {
        ast::tf_port_list *ret = new ast::tf_port_list;
        $$ = ret;
    }
    ;

tf_port_item 
    : STAR_2 OPT_87 OPT_52 data_type_or_implicit OPT_88 
    {
        ast::tf_port_item *ret = new ast::tf_port_item;
        $$ = ret;
    }
    ;

tf_port_direction 
    : port_direction 
    {
        ast::tf_port_direction *ret = new ast::tf_port_direction;
        $$ = ret;
    }
    | CONST_ REF_ 
    {
        ast::tf_port_direction *ret = new ast::tf_port_direction;
        $$ = ret;
    }
    ;

tf_port_declaration 
    : STAR_2 tf_port_direction OPT_52 data_type_or_implicit list_of_tf_variable_identifiers SEMICOLON 
    {
        ast::tf_port_declaration *ret = new ast::tf_port_declaration;
        $$ = ret;
    }
    ;

task_prototype 
    : TASK_ task_identifier OPT_39 
    {
        ast::task_prototype *ret = new ast::task_prototype;
        $$ = ret;
    }
    ;

block_item_declaration 
    : STAR_2 data_declaration 
    {
        ast::block_item_declaration *ret = new ast::block_item_declaration;
        $$ = ret;
    }
    | STAR_2 local_parameter_declaration SEMICOLON 
    {
        ast::block_item_declaration *ret = new ast::block_item_declaration;
        $$ = ret;
    }
    | STAR_2 parameter_declaration SEMICOLON 
    {
        ast::block_item_declaration *ret = new ast::block_item_declaration;
        $$ = ret;
    }
    | STAR_2 overload_declaration 
    {
        ast::block_item_declaration *ret = new ast::block_item_declaration;
        $$ = ret;
    }
    | STAR_2 let_declaration 
    {
        ast::block_item_declaration *ret = new ast::block_item_declaration;
        $$ = ret;
    }
    ;

overload_declaration 
    : BIND_ overload_operator FUNCTION_ data_type function_identifier LP overload_proto_formals RP SEMICOLON 
    {
        ast::overload_declaration *ret = new ast::overload_declaration;
        $$ = ret;
    }
    ;

overload_operator 
    : PLUS 
    {
        ast::overload_operator *ret = new ast::overload_operator;
        $$ = ret;
    }
    | PLUS2 
    {
        ast::overload_operator *ret = new ast::overload_operator;
        $$ = ret;
    }
    | MINUS 
    {
        ast::overload_operator *ret = new ast::overload_operator;
        $$ = ret;
    }
    | MINUS2 
    {
        ast::overload_operator *ret = new ast::overload_operator;
        $$ = ret;
    }
    | STAR 
    {
        ast::overload_operator *ret = new ast::overload_operator;
        $$ = ret;
    }
    | STAR2 
    {
        ast::overload_operator *ret = new ast::overload_operator;
        $$ = ret;
    }
    | SLASH 
    {
        ast::overload_operator *ret = new ast::overload_operator;
        $$ = ret;
    }
    | PERCENT 
    {
        ast::overload_operator *ret = new ast::overload_operator;
        $$ = ret;
    }
    | EQ2 
    {
        ast::overload_operator *ret = new ast::overload_operator;
        $$ = ret;
    }
    | NEQ 
    {
        ast::overload_operator *ret = new ast::overload_operator;
        $$ = ret;
    }
    | LT 
    {
        ast::overload_operator *ret = new ast::overload_operator;
        $$ = ret;
    }
    | LTE 
    {
        ast::overload_operator *ret = new ast::overload_operator;
        $$ = ret;
    }
    | GT 
    {
        ast::overload_operator *ret = new ast::overload_operator;
        $$ = ret;
    }
    | GTE 
    {
        ast::overload_operator *ret = new ast::overload_operator;
        $$ = ret;
    }
    | EQ 
    {
        ast::overload_operator *ret = new ast::overload_operator;
        $$ = ret;
    }
    ;

overload_proto_formals 
    : LIST_63 
    {
        ast::overload_proto_formals *ret = new ast::overload_proto_formals;
        $$ = ret;
    }
    ;

modport_declaration 
    : MODPORT_ LIST_64 SEMICOLON 
    {
        ast::modport_declaration *ret = new ast::modport_declaration;
        $$ = ret;
    }
    ;

modport_item 
    : modport_identifier LP LIST_65 RP 
    {
        ast::modport_item *ret = new ast::modport_item;
        $$ = ret;
    }
    ;

modport_ports_declaration 
    : STAR_2 modport_simple_ports_declaration 
    {
        ast::modport_ports_declaration *ret = new ast::modport_ports_declaration;
        $$ = ret;
    }
    | STAR_2 modport_tf_ports_declaration 
    {
        ast::modport_ports_declaration *ret = new ast::modport_ports_declaration;
        $$ = ret;
    }
    | STAR_2 modport_clocking_declaration 
    {
        ast::modport_ports_declaration *ret = new ast::modport_ports_declaration;
        $$ = ret;
    }
    ;

modport_clocking_declaration 
    : CLOCKING_ clocking_identifier 
    {
        ast::modport_clocking_declaration *ret = new ast::modport_clocking_declaration;
        $$ = ret;
    }
    ;

modport_simple_ports_declaration 
    : port_direction LIST_66 
    {
        ast::modport_simple_ports_declaration *ret = new ast::modport_simple_ports_declaration;
        $$ = ret;
    }
    ;

modport_simple_port 
    : port_identifier 
    {
        ast::modport_simple_port *ret = new ast::modport_simple_port;
        $$ = ret;
    }
    | DOT port_identifier LP OPT_26 RP 
    {
        ast::modport_simple_port *ret = new ast::modport_simple_port;
        $$ = ret;
    }
    ;

modport_tf_ports_declaration 
    : import_export LIST_67 
    {
        ast::modport_tf_ports_declaration *ret = new ast::modport_tf_ports_declaration;
        $$ = ret;
    }
    ;

modport_tf_port 
    : method_prototype 
    {
        ast::modport_tf_port *ret = new ast::modport_tf_port;
        $$ = ret;
    }
    | tf_identifier 
    {
        ast::modport_tf_port *ret = new ast::modport_tf_port;
        $$ = ret;
    }
    ;

import_export 
    : IMPORT_ 
    {
        ast::import_export *ret = new ast::import_export;
        $$ = ret;
    }
    | EXPORT_ 
    {
        ast::import_export *ret = new ast::import_export;
        $$ = ret;
    }
    ;

concurrent_assertion_item 
    : OPT_89 concurrent_assertion_statement 
    {
        ast::concurrent_assertion_item *ret = new ast::concurrent_assertion_item;
        $$ = ret;
    }
    | checker_instantiation 
    {
        ast::concurrent_assertion_item *ret = new ast::concurrent_assertion_item;
        $$ = ret;
    }
    ;

concurrent_assertion_statement 
    : assert_property_statement 
    {
        ast::concurrent_assertion_statement *ret = new ast::concurrent_assertion_statement;
        $$ = ret;
    }
    | assume_property_statement 
    {
        ast::concurrent_assertion_statement *ret = new ast::concurrent_assertion_statement;
        $$ = ret;
    }
    | cover_property_statement 
    {
        ast::concurrent_assertion_statement *ret = new ast::concurrent_assertion_statement;
        $$ = ret;
    }
    | cover_sequence_statement 
    {
        ast::concurrent_assertion_statement *ret = new ast::concurrent_assertion_statement;
        $$ = ret;
    }
    | restrict_property_statement 
    {
        ast::concurrent_assertion_statement *ret = new ast::concurrent_assertion_statement;
        $$ = ret;
    }
    ;

assert_property_statement 
    : ASSERT_ PROPERTY_ LP property_spec RP action_block 
    {
        ast::assert_property_statement *ret = new ast::assert_property_statement;
        $$ = ret;
    }
    ;

assume_property_statement 
    : ASSUME_ PROPERTY_ LP property_spec RP action_block 
    {
        ast::assume_property_statement *ret = new ast::assume_property_statement;
        $$ = ret;
    }
    ;

cover_property_statement 
    : COVER_ PROPERTY_ LP property_spec RP statement_or_null 
    {
        ast::cover_property_statement *ret = new ast::cover_property_statement;
        $$ = ret;
    }
    ;

expect_property_statement 
    : EXPECT_ LP property_spec RP action_block 
    {
        ast::expect_property_statement *ret = new ast::expect_property_statement;
        $$ = ret;
    }
    ;

cover_sequence_statement 
    : COVER_ SEQUENCE_ LP OPT_90 OPT_91 RP statement_or_null 
    {
        ast::cover_sequence_statement *ret = new ast::cover_sequence_statement;
        $$ = ret;
    }
    ;

restrict_property_statement 
    : RESTRICT_ PROPERTY_ LP property_spec RP SEMICOLON 
    {
        ast::restrict_property_statement *ret = new ast::restrict_property_statement;
        $$ = ret;
    }
    ;

property_instance 
    : ps_or_hierarchical_property_identifier OPT_93 
    {
        ast::property_instance *ret = new ast::property_instance;
        $$ = ret;
    }
    ;

property_list_of_arguments 
    : LIST_68 STAR_33 
    {
        ast::property_list_of_arguments *ret = new ast::property_list_of_arguments;
        $$ = ret;
    }
    | LIST_70 
    {
        ast::property_list_of_arguments *ret = new ast::property_list_of_arguments;
        $$ = ret;
    }
    ;

property_actual_arg 
    : property_expr 
    {
        ast::property_actual_arg *ret = new ast::property_actual_arg;
        $$ = ret;
    }
    | sequence_actual_arg 
    {
        ast::property_actual_arg *ret = new ast::property_actual_arg;
        $$ = ret;
    }
    ;

assertion_item_declaration 
    : property_declaration 
    {
        ast::assertion_item_declaration *ret = new ast::assertion_item_declaration;
        $$ = ret;
    }
    | sequence_declaration 
    {
        ast::assertion_item_declaration *ret = new ast::assertion_item_declaration;
        $$ = ret;
    }
    | let_declaration 
    {
        ast::assertion_item_declaration *ret = new ast::assertion_item_declaration;
        $$ = ret;
    }
    ;

property_declaration 
    : PROPERTY_ property_identifier OPT_96 SEMICOLON STAR_34 property_spec OPT_97 ENDPROPERTY_ OPT_98 
    {
        ast::property_declaration *ret = new ast::property_declaration;
        $$ = ret;
    }
    ;

property_port_list 
    : LIST_72 
    {
        ast::property_port_list *ret = new ast::property_port_list;
        $$ = ret;
    }
    ;

property_port_item 
    : STAR_2 OPT_100 property_formal_type formal_port_identifier STAR_15 OPT_36 
    {
        ast::property_port_item *ret = new ast::property_port_item;
        $$ = ret;
    }
    ;

property_lvar_port_direction 
    : INPUT_ 
    {
        ast::property_lvar_port_direction *ret = new ast::property_lvar_port_direction;
        $$ = ret;
    }
    ;

property_formal_type 
    : sequence_formal_type 
    {
        ast::property_formal_type *ret = new ast::property_formal_type;
        $$ = ret;
    }
    | PROPERTY_ 
    {
        ast::property_formal_type *ret = new ast::property_formal_type;
        $$ = ret;
    }
    ;

property_spec 
    : OPT_90 OPT_91 property_expr 
    {
        ast::property_spec *ret = new ast::property_spec;
        $$ = ret;
    }
    ;

property_expr 
    : sequence_expr 
    {
        ast::property_expr *ret = new ast::property_expr;
        $$ = ret;
    }
    | STRONG_ LP sequence_expr RP 
    {
        ast::property_expr *ret = new ast::property_expr;
        $$ = ret;
    }
    | WEAK_ LP sequence_expr RP 
    {
        ast::property_expr *ret = new ast::property_expr;
        $$ = ret;
    }
    | LP property_expr RP 
    {
        ast::property_expr *ret = new ast::property_expr;
        $$ = ret;
    }
    | NOT_ property_expr 
    {
        ast::property_expr *ret = new ast::property_expr;
        $$ = ret;
    }
    | property_expr OR_ property_expr 
    {
        ast::property_expr *ret = new ast::property_expr;
        $$ = ret;
    }
    | property_expr AND_ property_expr 
    {
        ast::property_expr *ret = new ast::property_expr;
        $$ = ret;
    }
    | sequence_expr BAR_DASH_GT property_expr 
    {
        ast::property_expr *ret = new ast::property_expr;
        $$ = ret;
    }
    | sequence_expr BAR_EQ_GT property_expr 
    {
        ast::property_expr *ret = new ast::property_expr;
        $$ = ret;
    }
    | IF_ LP expression_or_dist RP property_expr OPT_101 
    {
        ast::property_expr *ret = new ast::property_expr;
        $$ = ret;
    }
    | CASE_ LP expression_or_dist RP LIST_73 ENDCASE_ 
    {
        ast::property_expr *ret = new ast::property_expr;
        $$ = ret;
    }
    | sequence_expr SHARP_DASH_SHARP property_expr 
    {
        ast::property_expr *ret = new ast::property_expr;
        $$ = ret;
    }
    | sequence_expr SHARP_EQ_SHARP property_expr 
    {
        ast::property_expr *ret = new ast::property_expr;
        $$ = ret;
    }
    | NEXTTIME_ property_expr 
    {
        ast::property_expr *ret = new ast::property_expr;
        $$ = ret;
    }
    | NEXTTIME_ LSP constant_expression RSP property_expr 
    {
        ast::property_expr *ret = new ast::property_expr;
        $$ = ret;
    }
    | S_NEXTTIME_ property_expr 
    {
        ast::property_expr *ret = new ast::property_expr;
        $$ = ret;
    }
    | S_NEXTTIME_ LSP constant_expression RSP property_expr 
    {
        ast::property_expr *ret = new ast::property_expr;
        $$ = ret;
    }
    | ALWAYS_ property_expr 
    {
        ast::property_expr *ret = new ast::property_expr;
        $$ = ret;
    }
    | ALWAYS_ LSP cycle_delay_const_range_expression RSP property_expr 
    {
        ast::property_expr *ret = new ast::property_expr;
        $$ = ret;
    }
    | S_ALWAYS_ LSP constant_range RSP property_expr 
    {
        ast::property_expr *ret = new ast::property_expr;
        $$ = ret;
    }
    | S_EVENTUALLY_ LSP cycle_delay_const_range_expression RSP property_expr 
    {
        ast::property_expr *ret = new ast::property_expr;
        $$ = ret;
    }
    | property_expr UNTIL_ property_expr 
    {
        ast::property_expr *ret = new ast::property_expr;
        $$ = ret;
    }
    | property_expr S_UNTIL_ property_expr 
    {
        ast::property_expr *ret = new ast::property_expr;
        $$ = ret;
    }
    | property_expr UNTIL_WITH_ property_expr 
    {
        ast::property_expr *ret = new ast::property_expr;
        $$ = ret;
    }
    | property_expr S_UNTIL_WITH_ property_expr 
    {
        ast::property_expr *ret = new ast::property_expr;
        $$ = ret;
    }
    | property_expr IMPLIES_ property_expr 
    {
        ast::property_expr *ret = new ast::property_expr;
        $$ = ret;
    }
    | property_expr IFF_ property_expr 
    {
        ast::property_expr *ret = new ast::property_expr;
        $$ = ret;
    }
    | ACCEPT_ON_ LP expression_or_dist RP property_expr 
    {
        ast::property_expr *ret = new ast::property_expr;
        $$ = ret;
    }
    | REJECT_ON_ LP expression_or_dist RP property_expr 
    {
        ast::property_expr *ret = new ast::property_expr;
        $$ = ret;
    }
    | SYNC_ACCEPT_ON_ LP expression_or_dist RP property_expr 
    {
        ast::property_expr *ret = new ast::property_expr;
        $$ = ret;
    }
    | SYNC_REJECT_ON_ LP expression_or_dist RP property_expr 
    {
        ast::property_expr *ret = new ast::property_expr;
        $$ = ret;
    }
    | property_instance 
    {
        ast::property_expr *ret = new ast::property_expr;
        $$ = ret;
    }
    | clocking_event property_expr 
    {
        ast::property_expr *ret = new ast::property_expr;
        $$ = ret;
    }
    ;

property_case_item 
    : LIST_74 COLON property_expr OPT_97 
    {
        ast::property_case_item *ret = new ast::property_case_item;
        $$ = ret;
    }
    | DEFAULT_ OPT_102 property_expr OPT_97 
    {
        ast::property_case_item *ret = new ast::property_case_item;
        $$ = ret;
    }
    ;

sequence_declaration 
    : SEQUENCE_ sequence_identifier OPT_104 SEMICOLON STAR_34 sequence_expr OPT_97 ENDSEQUENCE_ OPT_105 
    {
        ast::sequence_declaration *ret = new ast::sequence_declaration;
        $$ = ret;
    }
    ;

sequence_port_list 
    : LIST_75 
    {
        ast::sequence_port_list *ret = new ast::sequence_port_list;
        $$ = ret;
    }
    ;

sequence_port_item 
    : STAR_2 OPT_107 sequence_formal_type formal_port_identifier STAR_15 OPT_108 
    {
        ast::sequence_port_item *ret = new ast::sequence_port_item;
        $$ = ret;
    }
    ;

sequence_lvar_port_direction 
    : INPUT_ 
    {
        ast::sequence_lvar_port_direction *ret = new ast::sequence_lvar_port_direction;
        $$ = ret;
    }
    | INOUT_ 
    {
        ast::sequence_lvar_port_direction *ret = new ast::sequence_lvar_port_direction;
        $$ = ret;
    }
    | OUTPUT_ 
    {
        ast::sequence_lvar_port_direction *ret = new ast::sequence_lvar_port_direction;
        $$ = ret;
    }
    ;

sequence_formal_type 
    : data_type_or_implicit 
    {
        ast::sequence_formal_type *ret = new ast::sequence_formal_type;
        $$ = ret;
    }
    | SEQUENCE_ 
    {
        ast::sequence_formal_type *ret = new ast::sequence_formal_type;
        $$ = ret;
    }
    | UNTYPED_ 
    {
        ast::sequence_formal_type *ret = new ast::sequence_formal_type;
        $$ = ret;
    }
    ;

sequence_expr 
    : LIST_76 
    {
        ast::sequence_expr *ret = new ast::sequence_expr;
        $$ = ret;
    }
    | sequence_expr LIST_76 
    {
        ast::sequence_expr *ret = new ast::sequence_expr;
        $$ = ret;
    }
    | expression_or_dist OPT_109 
    {
        ast::sequence_expr *ret = new ast::sequence_expr;
        $$ = ret;
    }
    | sequence_instance 
    {
        ast::sequence_expr *ret = new ast::sequence_expr;
        $$ = ret;
    }
    | LP sequence_expr STAR_35 RP OPT_110 
    {
        ast::sequence_expr *ret = new ast::sequence_expr;
        $$ = ret;
    }
    | sequence_expr AND_ sequence_expr 
    {
        ast::sequence_expr *ret = new ast::sequence_expr;
        $$ = ret;
    }
    | sequence_expr INTERSECT_ sequence_expr 
    {
        ast::sequence_expr *ret = new ast::sequence_expr;
        $$ = ret;
    }
    | sequence_expr OR_ sequence_expr 
    {
        ast::sequence_expr *ret = new ast::sequence_expr;
        $$ = ret;
    }
    | FIRST_MATCH_ LP sequence_expr STAR_35 RP 
    {
        ast::sequence_expr *ret = new ast::sequence_expr;
        $$ = ret;
    }
    | expression_or_dist THROUGHOUT_ sequence_expr 
    {
        ast::sequence_expr *ret = new ast::sequence_expr;
        $$ = ret;
    }
    | sequence_expr WITHIN_ sequence_expr 
    {
        ast::sequence_expr *ret = new ast::sequence_expr;
        $$ = ret;
    }
    | clocking_event sequence_expr 
    {
        ast::sequence_expr *ret = new ast::sequence_expr;
        $$ = ret;
    }
    ;

cycle_delay_range 
    : SHARP2 constant_primary 
    {
        ast::cycle_delay_range *ret = new ast::cycle_delay_range;
        $$ = ret;
    }
    | SHARP2 LSP cycle_delay_const_range_expression RSP 
    {
        ast::cycle_delay_range *ret = new ast::cycle_delay_range;
        $$ = ret;
    }
    | SHARP2 LSP_STAR_RSP 
    {
        ast::cycle_delay_range *ret = new ast::cycle_delay_range;
        $$ = ret;
    }
    | SHARP2 LSP_PLUS_RSP 
    {
        ast::cycle_delay_range *ret = new ast::cycle_delay_range;
        $$ = ret;
    }
    ;

sequence_method_call 
    : sequence_instance DOT method_identifier 
    {
        ast::sequence_method_call *ret = new ast::sequence_method_call;
        $$ = ret;
    }
    ;

sequence_match_item 
    : operator_assignment 
    {
        ast::sequence_match_item *ret = new ast::sequence_match_item;
        $$ = ret;
    }
    | inc_or_dec_expression 
    {
        ast::sequence_match_item *ret = new ast::sequence_match_item;
        $$ = ret;
    }
    | subroutine_call 
    {
        ast::sequence_match_item *ret = new ast::sequence_match_item;
        $$ = ret;
    }
    ;

sequence_instance 
    : ps_or_hierarchical_sequence_identifier OPT_111 
    {
        ast::sequence_instance *ret = new ast::sequence_instance;
        $$ = ret;
    }
    ;

sequence_list_of_arguments 
    : LIST_78 STAR_36 
    {
        ast::sequence_list_of_arguments *ret = new ast::sequence_list_of_arguments;
        $$ = ret;
    }
    | LIST_80 
    {
        ast::sequence_list_of_arguments *ret = new ast::sequence_list_of_arguments;
        $$ = ret;
    }
    ;

sequence_actual_arg 
    : event_expression 
    {
        ast::sequence_actual_arg *ret = new ast::sequence_actual_arg;
        $$ = ret;
    }
    | sequence_expr 
    {
        ast::sequence_actual_arg *ret = new ast::sequence_actual_arg;
        $$ = ret;
    }
    ;

boolean_abbrev 
    : consecutive_repetition 
    {
        ast::boolean_abbrev *ret = new ast::boolean_abbrev;
        $$ = ret;
    }
    | non_consecutive_repetition 
    {
        ast::boolean_abbrev *ret = new ast::boolean_abbrev;
        $$ = ret;
    }
    | goto_repetition 
    {
        ast::boolean_abbrev *ret = new ast::boolean_abbrev;
        $$ = ret;
    }
    ;

sequence_abbrev 
    : consecutive_repetition 
    {
        ast::sequence_abbrev *ret = new ast::sequence_abbrev;
        $$ = ret;
    }
    ;

consecutive_repetition 
    : LSP_STAR const_or_range_expression RSP 
    {
        ast::consecutive_repetition *ret = new ast::consecutive_repetition;
        $$ = ret;
    }
    | LSP_STAR_RSP 
    {
        ast::consecutive_repetition *ret = new ast::consecutive_repetition;
        $$ = ret;
    }
    | LSP_PLUS_RSP 
    {
        ast::consecutive_repetition *ret = new ast::consecutive_repetition;
        $$ = ret;
    }
    ;

non_consecutive_repetition 
    : LSP_EQ const_or_range_expression RSP 
    {
        ast::non_consecutive_repetition *ret = new ast::non_consecutive_repetition;
        $$ = ret;
    }
    ;

goto_repetition 
    : LSP_DASH_GT const_or_range_expression RSP 
    {
        ast::goto_repetition *ret = new ast::goto_repetition;
        $$ = ret;
    }
    ;

const_or_range_expression 
    : constant_expression 
    {
        ast::const_or_range_expression *ret = new ast::const_or_range_expression;
        $$ = ret;
    }
    | cycle_delay_const_range_expression 
    {
        ast::const_or_range_expression *ret = new ast::const_or_range_expression;
        $$ = ret;
    }
    ;

cycle_delay_const_range_expression 
    : constant_expression COLON constant_expression 
    {
        ast::cycle_delay_const_range_expression *ret = new ast::cycle_delay_const_range_expression;
        $$ = ret;
    }
    | constant_expression COLON DOLLAR_ 
    {
        ast::cycle_delay_const_range_expression *ret = new ast::cycle_delay_const_range_expression;
        $$ = ret;
    }
    ;

expression_or_dist 
    : expression OPT_113 
    {
        ast::expression_or_dist *ret = new ast::expression_or_dist;
        $$ = ret;
    }
    ;

assertion_variable_declaration 
    : var_data_type list_of_variable_decl_assignments SEMICOLON 
    {
        ast::assertion_variable_declaration *ret = new ast::assertion_variable_declaration;
        $$ = ret;
    }
    ;

let_declaration 
    : LET_ let_identifier OPT_115 EQ expression SEMICOLON 
    {
        ast::let_declaration *ret = new ast::let_declaration;
        $$ = ret;
    }
    ;

let_identifier 
    : identifier 
    {
        ast::let_identifier *ret = new ast::let_identifier;
        $$ = ret;
    }
    ;

let_port_list 
    : LIST_81 
    {
        ast::let_port_list *ret = new ast::let_port_list;
        $$ = ret;
    }
    ;

let_port_item 
    : STAR_2 let_formal_type formal_port_identifier STAR_15 OPT_73 
    {
        ast::let_port_item *ret = new ast::let_port_item;
        $$ = ret;
    }
    ;

let_formal_type 
    : data_type_or_implicit 
    {
        ast::let_formal_type *ret = new ast::let_formal_type;
        $$ = ret;
    }
    | UNTYPED_ 
    {
        ast::let_formal_type *ret = new ast::let_formal_type;
        $$ = ret;
    }
    ;

let_expression 
    : OPT_116 let_identifier OPT_118 
    {
        ast::let_expression *ret = new ast::let_expression;
        $$ = ret;
    }
    ;

let_list_of_arguments 
    : LIST_82 STAR_37 
    {
        ast::let_list_of_arguments *ret = new ast::let_list_of_arguments;
        $$ = ret;
    }
    | LIST_84 
    {
        ast::let_list_of_arguments *ret = new ast::let_list_of_arguments;
        $$ = ret;
    }
    ;

let_actual_arg 
    : expression 
    {
        ast::let_actual_arg *ret = new ast::let_actual_arg;
        $$ = ret;
    }
    ;

covergroup_declaration 
    : COVERGROUP_ covergroup_identifier OPT_39 OPT_120 SEMICOLON STAR_38 ENDGROUP_ OPT_121 
    {
        ast::covergroup_declaration *ret = new ast::covergroup_declaration;
        $$ = ret;
    }
    ;

coverage_spec_or_option 
    : STAR_2 coverage_spec 
    {
        ast::coverage_spec_or_option *ret = new ast::coverage_spec_or_option;
        $$ = ret;
    }
    | STAR_2 coverage_option SEMICOLON 
    {
        ast::coverage_spec_or_option *ret = new ast::coverage_spec_or_option;
        $$ = ret;
    }
    ;

coverage_option 
    : OPTION_ DOT member_identifier EQ expression 
    {
        ast::coverage_option *ret = new ast::coverage_option;
        $$ = ret;
    }
    | TYPE_OPTION_ DOT member_identifier EQ constant_expression 
    {
        ast::coverage_option *ret = new ast::coverage_option;
        $$ = ret;
    }
    ;

coverage_spec 
    : cover_point 
    {
        ast::coverage_spec *ret = new ast::coverage_spec;
        $$ = ret;
    }
    | cover_cross 
    {
        ast::coverage_spec *ret = new ast::coverage_spec;
        $$ = ret;
    }
    ;

coverage_event 
    : clocking_event 
    {
        ast::coverage_event *ret = new ast::coverage_event;
        $$ = ret;
    }
    | WITH_ FUNCTION_ SAMPLE_ LP OPT_38 RP 
    {
        ast::coverage_event *ret = new ast::coverage_event;
        $$ = ret;
    }
    | AT2 LP block_event_expression RP 
    {
        ast::coverage_event *ret = new ast::coverage_event;
        $$ = ret;
    }
    ;

block_event_expression 
    : LIST_86 
    {
        ast::block_event_expression *ret = new ast::block_event_expression;
        $$ = ret;
    }
    | BEGIN_ hierarchical_btf_identifier 
    {
        ast::block_event_expression *ret = new ast::block_event_expression;
        $$ = ret;
    }
    | END_ hierarchical_btf_identifier 
    {
        ast::block_event_expression *ret = new ast::block_event_expression;
        $$ = ret;
    }
    ;

hierarchical_btf_identifier 
    : hierarchical_tf_identifier 
    {
        ast::hierarchical_btf_identifier *ret = new ast::hierarchical_btf_identifier;
        $$ = ret;
    }
    | hierarchical_block_identifier 
    {
        ast::hierarchical_btf_identifier *ret = new ast::hierarchical_btf_identifier;
        $$ = ret;
    }
    | OPT_122 method_identifier 
    {
        ast::hierarchical_btf_identifier *ret = new ast::hierarchical_btf_identifier;
        $$ = ret;
    }
    ;

cover_point 
    : OPT_124 COVERPOINT_ expression OPT_125 bins_or_empty 
    {
        ast::cover_point *ret = new ast::cover_point;
        $$ = ret;
    }
    ;

bins_or_empty 
    : LMP STAR_2 STAR_39 RMP 
    {
        ast::bins_or_empty *ret = new ast::bins_or_empty;
        $$ = ret;
    }
    | SEMICOLON 
    {
        ast::bins_or_empty *ret = new ast::bins_or_empty;
        $$ = ret;
    }
    ;

bins_or_options 
    : coverage_option 
    {
        ast::bins_or_options *ret = new ast::bins_or_options;
        $$ = ret;
    }
    | OPT_126 bins_keyword bin_identifier OPT_128 EQ LMP covergroup_range_list RMP OPT_129 OPT_125 
    {
        ast::bins_or_options *ret = new ast::bins_or_options;
        $$ = ret;
    }
    | OPT_126 bins_keyword bin_identifier OPT_128 EQ cover_point_identifier OPT_129 OPT_125 
    {
        ast::bins_or_options *ret = new ast::bins_or_options;
        $$ = ret;
    }
    | OPT_126 bins_keyword bin_identifier OPT_128 EQ set_covergroup_expression OPT_125 
    {
        ast::bins_or_options *ret = new ast::bins_or_options;
        $$ = ret;
    }
    | OPT_126 bins_keyword bin_identifier OPT_130 EQ trans_list OPT_125 
    {
        ast::bins_or_options *ret = new ast::bins_or_options;
        $$ = ret;
    }
    | bins_keyword bin_identifier OPT_128 EQ DEFAULT_ OPT_125 
    {
        ast::bins_or_options *ret = new ast::bins_or_options;
        $$ = ret;
    }
    | bins_keyword bin_identifier EQ DEFAULT_ SEQUENCE_ OPT_125 
    {
        ast::bins_or_options *ret = new ast::bins_or_options;
        $$ = ret;
    }
    ;

bins_keyword 
    : BINS_ 
    {
        ast::bins_keyword *ret = new ast::bins_keyword;
        $$ = ret;
    }
    | ILLEGRAL_BINS_ 
    {
        ast::bins_keyword *ret = new ast::bins_keyword;
        $$ = ret;
    }
    | IGNORE_BINS_ 
    {
        ast::bins_keyword *ret = new ast::bins_keyword;
        $$ = ret;
    }
    ;

trans_list 
    : LIST_88 
    {
        ast::trans_list *ret = new ast::trans_list;
        $$ = ret;
    }
    ;

trans_set 
    : LIST_89 
    {
        ast::trans_set *ret = new ast::trans_set;
        $$ = ret;
    }
    ;

trans_range_list 
    : trans_item 
    {
        ast::trans_range_list *ret = new ast::trans_range_list;
        $$ = ret;
    }
    | trans_item LSP_STAR repeat_range RSP 
    {
        ast::trans_range_list *ret = new ast::trans_range_list;
        $$ = ret;
    }
    | trans_item LSP_DASH_GT repeat_range RSP 
    {
        ast::trans_range_list *ret = new ast::trans_range_list;
        $$ = ret;
    }
    | trans_item LSP_EQ repeat_range RSP 
    {
        ast::trans_range_list *ret = new ast::trans_range_list;
        $$ = ret;
    }
    ;

trans_item 
    : covergroup_range_list 
    {
        ast::trans_item *ret = new ast::trans_item;
        $$ = ret;
    }
    ;

repeat_range 
    : covergroup_expression 
    {
        ast::repeat_range *ret = new ast::repeat_range;
        $$ = ret;
    }
    | covergroup_expression COLON covergroup_expression 
    {
        ast::repeat_range *ret = new ast::repeat_range;
        $$ = ret;
    }
    ;

cover_cross 
    : OPT_131 CROSS_ list_of_cross_items OPT_125 cross_body 
    {
        ast::cover_cross *ret = new ast::cover_cross;
        $$ = ret;
    }
    ;

list_of_cross_items 
    : cross_item COMMA LIST_90 
    {
        ast::list_of_cross_items *ret = new ast::list_of_cross_items;
        $$ = ret;
    }
    ;

cross_item 
    : cover_point_identifier 
    {
        ast::cross_item *ret = new ast::cross_item;
        $$ = ret;
    }
    | variable_identifier 
    {
        ast::cross_item *ret = new ast::cross_item;
        $$ = ret;
    }
    ;

cross_body 
    : LMP STAR_40 RMP 
    {
        ast::cross_body *ret = new ast::cross_body;
        $$ = ret;
    }
    | SEMICOLON 
    {
        ast::cross_body *ret = new ast::cross_body;
        $$ = ret;
    }
    ;

cross_body_item 
    : function_declaration 
    {
        ast::cross_body_item *ret = new ast::cross_body_item;
        $$ = ret;
    }
    | bins_selection_or_option SEMICOLON 
    {
        ast::cross_body_item *ret = new ast::cross_body_item;
        $$ = ret;
    }
    ;

bins_selection_or_option 
    : STAR_2 coverage_option 
    {
        ast::bins_selection_or_option *ret = new ast::bins_selection_or_option;
        $$ = ret;
    }
    | STAR_2 bins_selection 
    {
        ast::bins_selection_or_option *ret = new ast::bins_selection_or_option;
        $$ = ret;
    }
    ;

bins_selection 
    : bins_keyword bin_identifier EQ select_expression OPT_125 
    {
        ast::bins_selection *ret = new ast::bins_selection;
        $$ = ret;
    }
    ;

select_expression 
    : select_condition 
    {
        ast::select_expression *ret = new ast::select_expression;
        $$ = ret;
    }
    | NOT select_condition 
    {
        ast::select_expression *ret = new ast::select_expression;
        $$ = ret;
    }
    | select_expression AND2 select_expression 
    {
        ast::select_expression *ret = new ast::select_expression;
        $$ = ret;
    }
    | select_expression BAR2 select_expression 
    {
        ast::select_expression *ret = new ast::select_expression;
        $$ = ret;
    }
    | LP select_expression RP 
    {
        ast::select_expression *ret = new ast::select_expression;
        $$ = ret;
    }
    | select_expression WITH_ LP with_covergroup_expression RP OPT_132 
    {
        ast::select_expression *ret = new ast::select_expression;
        $$ = ret;
    }
    | cross_identifier 
    {
        ast::select_expression *ret = new ast::select_expression;
        $$ = ret;
    }
    | cross_set_expression OPT_132 
    {
        ast::select_expression *ret = new ast::select_expression;
        $$ = ret;
    }
    ;

select_condition 
    : BINSOF_ LP bins_expression RP OPT_133 
    {
        ast::select_condition *ret = new ast::select_condition;
        $$ = ret;
    }
    ;

bins_expression 
    : variable_identifier 
    {
        ast::bins_expression *ret = new ast::bins_expression;
        $$ = ret;
    }
    | cover_point_identifier OPT_134 
    {
        ast::bins_expression *ret = new ast::bins_expression;
        $$ = ret;
    }
    ;

covergroup_range_list 
    : LIST_92 
    {
        ast::covergroup_range_list *ret = new ast::covergroup_range_list;
        $$ = ret;
    }
    ;

covergroup_value_range 
    : covergroup_expression 
    {
        ast::covergroup_value_range *ret = new ast::covergroup_value_range;
        $$ = ret;
    }
    | LSP covergroup_expression COLON covergroup_expression RSP 
    {
        ast::covergroup_value_range *ret = new ast::covergroup_value_range;
        $$ = ret;
    }
    ;

with_covergroup_expression 
    : covergroup_expression 
    {
        ast::with_covergroup_expression *ret = new ast::with_covergroup_expression;
        $$ = ret;
    }
    ;

set_covergroup_expression 
    : covergroup_expression 
    {
        ast::set_covergroup_expression *ret = new ast::set_covergroup_expression;
        $$ = ret;
    }
    ;

integer_covergroup_expression 
    : covergroup_expression 
    {
        ast::integer_covergroup_expression *ret = new ast::integer_covergroup_expression;
        $$ = ret;
    }
    ;

cross_set_expression 
    : covergroup_expression 
    {
        ast::cross_set_expression *ret = new ast::cross_set_expression;
        $$ = ret;
    }
    ;

covergroup_expression 
    : expression 
    {
        ast::covergroup_expression *ret = new ast::covergroup_expression;
        $$ = ret;
    }
    ;

gate_instantiation 
    : cmos_switchtype OPT_55 LIST_93 SEMICOLON 
    {
        ast::gate_instantiation *ret = new ast::gate_instantiation;
        $$ = ret;
    }
    | enable_gatetype OPT_135 OPT_55 LIST_94 SEMICOLON 
    {
        ast::gate_instantiation *ret = new ast::gate_instantiation;
        $$ = ret;
    }
    | mos_switchtype OPT_55 LIST_95 SEMICOLON 
    {
        ast::gate_instantiation *ret = new ast::gate_instantiation;
        $$ = ret;
    }
    | n_input_gatetype OPT_135 OPT_136 LIST_96 SEMICOLON 
    {
        ast::gate_instantiation *ret = new ast::gate_instantiation;
        $$ = ret;
    }
    | n_output_gatetype OPT_135 OPT_136 LIST_97 SEMICOLON 
    {
        ast::gate_instantiation *ret = new ast::gate_instantiation;
        $$ = ret;
    }
    | pass_en_switchtype OPT_136 LIST_98 SEMICOLON 
    {
        ast::gate_instantiation *ret = new ast::gate_instantiation;
        $$ = ret;
    }
    | pass_switchtype LIST_99 SEMICOLON 
    {
        ast::gate_instantiation *ret = new ast::gate_instantiation;
        $$ = ret;
    }
    | PULLDOWN_ OPT_137 LIST_100 SEMICOLON 
    {
        ast::gate_instantiation *ret = new ast::gate_instantiation;
        $$ = ret;
    }
    | PULLUP_ OPT_138 LIST_100 SEMICOLON 
    {
        ast::gate_instantiation *ret = new ast::gate_instantiation;
        $$ = ret;
    }
    ;

cmos_switch_instance 
    : OPT_139 LP output_terminal COMMA input_terminal COMMA ncontrol_terminal COMMA pcontrol_terminal RP 
    {
        ast::cmos_switch_instance *ret = new ast::cmos_switch_instance;
        $$ = ret;
    }
    ;

enable_gate_instance 
    : OPT_139 LP output_terminal COMMA input_terminal COMMA enable_terminal RP 
    {
        ast::enable_gate_instance *ret = new ast::enable_gate_instance;
        $$ = ret;
    }
    ;

mos_switch_instance 
    : OPT_139 LP output_terminal COMMA input_terminal COMMA enable_terminal RP 
    {
        ast::mos_switch_instance *ret = new ast::mos_switch_instance;
        $$ = ret;
    }
    ;

n_input_gate_instance 
    : OPT_139 LP output_terminal COMMA LIST_101 RP 
    {
        ast::n_input_gate_instance *ret = new ast::n_input_gate_instance;
        $$ = ret;
    }
    ;

n_output_gate_instance 
    : OPT_139 LP LIST_102 RP 
    {
        ast::n_output_gate_instance *ret = new ast::n_output_gate_instance;
        $$ = ret;
    }
    ;

pass_switch_instance 
    : OPT_139 LP inout_terminal COMMA inout_terminal RP 
    {
        ast::pass_switch_instance *ret = new ast::pass_switch_instance;
        $$ = ret;
    }
    ;

pass_enable_switch_instance 
    : OPT_139 LP inout_terminal COMMA inout_terminal COMMA enable_terminal RP 
    {
        ast::pass_enable_switch_instance *ret = new ast::pass_enable_switch_instance;
        $$ = ret;
    }
    ;

pull_gate_instance 
    : OPT_139 LP output_terminal RP 
    {
        ast::pull_gate_instance *ret = new ast::pull_gate_instance;
        $$ = ret;
    }
    ;

pulldown_strength 
    : LP strength0 COMMA strength1 RP 
    {
        ast::pulldown_strength *ret = new ast::pulldown_strength;
        $$ = ret;
    }
    | LP strength1 COMMA strength0 RP 
    {
        ast::pulldown_strength *ret = new ast::pulldown_strength;
        $$ = ret;
    }
    | LP strength0 RP 
    {
        ast::pulldown_strength *ret = new ast::pulldown_strength;
        $$ = ret;
    }
    ;

pullup_strength 
    : LP strength0 COMMA strength1 RP 
    {
        ast::pullup_strength *ret = new ast::pullup_strength;
        $$ = ret;
    }
    | LP strength1 COMMA strength0 RP 
    {
        ast::pullup_strength *ret = new ast::pullup_strength;
        $$ = ret;
    }
    | LP strength1 RP 
    {
        ast::pullup_strength *ret = new ast::pullup_strength;
        $$ = ret;
    }
    ;

enable_terminal 
    : expression 
    {
        ast::enable_terminal *ret = new ast::enable_terminal;
        $$ = ret;
    }
    ;

inout_terminal 
    : net_lvalue 
    {
        ast::inout_terminal *ret = new ast::inout_terminal;
        $$ = ret;
    }
    ;

input_terminal 
    : expression 
    {
        ast::input_terminal *ret = new ast::input_terminal;
        $$ = ret;
    }
    ;

ncontrol_terminal 
    : expression 
    {
        ast::ncontrol_terminal *ret = new ast::ncontrol_terminal;
        $$ = ret;
    }
    ;

output_terminal 
    : net_lvalue 
    {
        ast::output_terminal *ret = new ast::output_terminal;
        $$ = ret;
    }
    ;

pcontrol_terminal 
    : expression 
    {
        ast::pcontrol_terminal *ret = new ast::pcontrol_terminal;
        $$ = ret;
    }
    ;

cmos_switchtype 
    : CMOS_ 
    {
        ast::cmos_switchtype *ret = new ast::cmos_switchtype;
        $$ = ret;
    }
    | RCMOS_ 
    {
        ast::cmos_switchtype *ret = new ast::cmos_switchtype;
        $$ = ret;
    }
    ;

enable_gatetype 
    : BUFIF0_ 
    {
        ast::enable_gatetype *ret = new ast::enable_gatetype;
        $$ = ret;
    }
    | BUFIF1_ 
    {
        ast::enable_gatetype *ret = new ast::enable_gatetype;
        $$ = ret;
    }
    | NOTIF0_ 
    {
        ast::enable_gatetype *ret = new ast::enable_gatetype;
        $$ = ret;
    }
    | NOTIF1_ 
    {
        ast::enable_gatetype *ret = new ast::enable_gatetype;
        $$ = ret;
    }
    ;

mos_switchtype 
    : NMOS_ 
    {
        ast::mos_switchtype *ret = new ast::mos_switchtype;
        $$ = ret;
    }
    | PMOS_ 
    {
        ast::mos_switchtype *ret = new ast::mos_switchtype;
        $$ = ret;
    }
    | RNMOS_ 
    {
        ast::mos_switchtype *ret = new ast::mos_switchtype;
        $$ = ret;
    }
    | RPMOS_ 
    {
        ast::mos_switchtype *ret = new ast::mos_switchtype;
        $$ = ret;
    }
    ;

n_input_gatetype 
    : AND_ 
    {
        ast::n_input_gatetype *ret = new ast::n_input_gatetype;
        $$ = ret;
    }
    | NAND_ 
    {
        ast::n_input_gatetype *ret = new ast::n_input_gatetype;
        $$ = ret;
    }
    | OR_ 
    {
        ast::n_input_gatetype *ret = new ast::n_input_gatetype;
        $$ = ret;
    }
    | NOR_ 
    {
        ast::n_input_gatetype *ret = new ast::n_input_gatetype;
        $$ = ret;
    }
    | XOR_ 
    {
        ast::n_input_gatetype *ret = new ast::n_input_gatetype;
        $$ = ret;
    }
    | XNOR_ 
    {
        ast::n_input_gatetype *ret = new ast::n_input_gatetype;
        $$ = ret;
    }
    ;

n_output_gatetype 
    : BUF_ 
    {
        ast::n_output_gatetype *ret = new ast::n_output_gatetype;
        $$ = ret;
    }
    | NOT_ 
    {
        ast::n_output_gatetype *ret = new ast::n_output_gatetype;
        $$ = ret;
    }
    ;

pass_en_switchtype 
    : TRANIF0_ 
    {
        ast::pass_en_switchtype *ret = new ast::pass_en_switchtype;
        $$ = ret;
    }
    | TRANIF1_ 
    {
        ast::pass_en_switchtype *ret = new ast::pass_en_switchtype;
        $$ = ret;
    }
    | RTRANIF0_ 
    {
        ast::pass_en_switchtype *ret = new ast::pass_en_switchtype;
        $$ = ret;
    }
    | RTRANIF1_ 
    {
        ast::pass_en_switchtype *ret = new ast::pass_en_switchtype;
        $$ = ret;
    }
    ;

pass_switchtype 
    : TRAN_ 
    {
        ast::pass_switchtype *ret = new ast::pass_switchtype;
        $$ = ret;
    }
    | RTRAN_ 
    {
        ast::pass_switchtype *ret = new ast::pass_switchtype;
        $$ = ret;
    }
    ;

module_instantiation 
    : module_identifier OPT_16 LIST_103 SEMICOLON 
    {
        ast::module_instantiation *ret = new ast::module_instantiation;
        $$ = ret;
    }
    ;

parameter_value_assignment 
    : SHARP LP OPT_140 RP 
    {
        ast::parameter_value_assignment *ret = new ast::parameter_value_assignment;
        $$ = ret;
    }
    ;

list_of_parameter_assignments 
    : LIST_104 
    {
        ast::list_of_parameter_assignments *ret = new ast::list_of_parameter_assignments;
        $$ = ret;
    }
    | LIST_28 
    {
        ast::list_of_parameter_assignments *ret = new ast::list_of_parameter_assignments;
        $$ = ret;
    }
    ;

ordered_parameter_assignment 
    : param_expression 
    {
        ast::ordered_parameter_assignment *ret = new ast::ordered_parameter_assignment;
        $$ = ret;
    }
    ;

named_parameter_assignment 
    : DOT parameter_identifier LP OPT_141 RP 
    {
        ast::named_parameter_assignment *ret = new ast::named_parameter_assignment;
        $$ = ret;
    }
    ;

hierarchical_instance 
    : name_of_instance LP OPT_142 RP 
    {
        ast::hierarchical_instance *ret = new ast::hierarchical_instance;
        $$ = ret;
    }
    ;

name_of_instance 
    : instance_identifier STAR_14 
    {
        ast::name_of_instance *ret = new ast::name_of_instance;
        $$ = ret;
    }
    ;

list_of_port_connections 
    : LIST_105 
    {
        ast::list_of_port_connections *ret = new ast::list_of_port_connections;
        $$ = ret;
    }
    | LIST_106 
    {
        ast::list_of_port_connections *ret = new ast::list_of_port_connections;
        $$ = ret;
    }
    ;

ordered_port_connection 
    : STAR_2 OPT_26 
    {
        ast::ordered_port_connection *ret = new ast::ordered_port_connection;
        $$ = ret;
    }
    ;

named_port_connection 
    : STAR_2 DOT port_identifier OPT_143 
    {
        ast::named_port_connection *ret = new ast::named_port_connection;
        $$ = ret;
    }
    | STAR_2 DOT STAR 
    {
        ast::named_port_connection *ret = new ast::named_port_connection;
        $$ = ret;
    }
    ;

interface_instantiation 
    : interface_identifier OPT_16 LIST_103 SEMICOLON 
    {
        ast::interface_instantiation *ret = new ast::interface_instantiation;
        $$ = ret;
    }
    ;

program_instantiation 
    : program_identifier OPT_16 LIST_103 SEMICOLON 
    {
        ast::program_instantiation *ret = new ast::program_instantiation;
        $$ = ret;
    }
    ;

checker_instantiation 
    : ps_checker_identifier name_of_instance LP OPT_144 RP SEMICOLON 
    {
        ast::checker_instantiation *ret = new ast::checker_instantiation;
        $$ = ret;
    }
    ;

list_of_checker_port_connections 
    : LIST_107 
    {
        ast::list_of_checker_port_connections *ret = new ast::list_of_checker_port_connections;
        $$ = ret;
    }
    | LIST_108 
    {
        ast::list_of_checker_port_connections *ret = new ast::list_of_checker_port_connections;
        $$ = ret;
    }
    ;

ordered_checker_port_connection 
    : STAR_2 OPT_94 
    {
        ast::ordered_checker_port_connection *ret = new ast::ordered_checker_port_connection;
        $$ = ret;
    }
    ;

named_checker_port_connection 
    : STAR_2 DOT formal_port_identifier OPT_145 
    {
        ast::named_checker_port_connection *ret = new ast::named_checker_port_connection;
        $$ = ret;
    }
    | STAR_2 DOT STAR 
    {
        ast::named_checker_port_connection *ret = new ast::named_checker_port_connection;
        $$ = ret;
    }
    ;

generate_region 
    : GENERATE_ STAR_41 ENDGENERATE_ 
    {
        ast::generate_region *ret = new ast::generate_region;
        $$ = ret;
    }
    ;

loop_generate_construct 
    : FOR_ LP genvar_initialization SEMICOLON genvar_expression SEMICOLON genvar_iteration RP generate_block 
    {
        ast::loop_generate_construct *ret = new ast::loop_generate_construct;
        $$ = ret;
    }
    ;

genvar_initialization 
    : OPT_146 genvar_identifier EQ constant_expression 
    {
        ast::genvar_initialization *ret = new ast::genvar_initialization;
        $$ = ret;
    }
    ;

genvar_iteration 
    : genvar_identifier assignment_operator genvar_expression 
    {
        ast::genvar_iteration *ret = new ast::genvar_iteration;
        $$ = ret;
    }
    | inc_or_dec_operator genvar_identifier 
    {
        ast::genvar_iteration *ret = new ast::genvar_iteration;
        $$ = ret;
    }
    | genvar_identifier inc_or_dec_operator 
    {
        ast::genvar_iteration *ret = new ast::genvar_iteration;
        $$ = ret;
    }
    ;

conditional_generate_construct 
    : if_generate_construct 
    {
        ast::conditional_generate_construct *ret = new ast::conditional_generate_construct;
        $$ = ret;
    }
    | case_generate_construct 
    {
        ast::conditional_generate_construct *ret = new ast::conditional_generate_construct;
        $$ = ret;
    }
    ;

if_generate_construct 
    : IF_ LP constant_expression RP generate_block OPT_147 
    {
        ast::if_generate_construct *ret = new ast::if_generate_construct;
        $$ = ret;
    }
    ;

case_generate_construct 
    : CASE_ LP constant_expression RP case_generate_item LMP case_generate_item RMP ENDCASE_ 
    {
        ast::case_generate_construct *ret = new ast::case_generate_construct;
        $$ = ret;
    }
    ;

case_generate_item 
    : LIST_110 COLON generate_block 
    {
        ast::case_generate_item *ret = new ast::case_generate_item;
        $$ = ret;
    }
    | DEFAULT_ OPT_102 generate_block 
    {
        ast::case_generate_item *ret = new ast::case_generate_item;
        $$ = ret;
    }
    ;

generate_block 
    : generate_item 
    {
        ast::generate_block *ret = new ast::generate_block;
        $$ = ret;
    }
    | OPT_148 BEGIN_ OPT_149 STAR_41 END_ OPT_149 
    {
        ast::generate_block *ret = new ast::generate_block;
        $$ = ret;
    }
    ;

generate_item 
    : module_or_generate_item 
    {
        ast::generate_item *ret = new ast::generate_item;
        $$ = ret;
    }
    | interface_or_generate_item 
    {
        ast::generate_item *ret = new ast::generate_item;
        $$ = ret;
    }
    | checker_or_generate_item 
    {
        ast::generate_item *ret = new ast::generate_item;
        $$ = ret;
    }
    ;

udp_nonansi_declaration 
    : STAR_2 PRIMITIVE_ udp_identifier LP udp_port_list RP SEMICOLON 
    {
        ast::udp_nonansi_declaration *ret = new ast::udp_nonansi_declaration;
        $$ = ret;
    }
    ;

udp_ansi_declaration 
    : STAR_2 PRIMITIVE_ udp_identifier LP udp_declaration_port_list RP SEMICOLON 
    {
        ast::udp_ansi_declaration *ret = new ast::udp_ansi_declaration;
        $$ = ret;
    }
    ;

udp_declaration 
    : udp_nonansi_declaration LIST_111 udp_body ENDPRIMITIVE_ OPT_150 
    {
        ast::udp_declaration *ret = new ast::udp_declaration;
        $$ = ret;
    }
    | udp_ansi_declaration udp_body ENDPRIMITIVE_ OPT_150 
    {
        ast::udp_declaration *ret = new ast::udp_declaration;
        $$ = ret;
    }
    | EXTERN_ udp_nonansi_declaration 
    {
        ast::udp_declaration *ret = new ast::udp_declaration;
        $$ = ret;
    }
    | EXTERN_ udp_ansi_declaration 
    {
        ast::udp_declaration *ret = new ast::udp_declaration;
        $$ = ret;
    }
    | STAR_2 PRIMITIVE_ udp_identifier LP DOT_STAR RP SEMICOLON STAR_42 udp_body ENDPRIMITIVE_ OPT_150 
    {
        ast::udp_declaration *ret = new ast::udp_declaration;
        $$ = ret;
    }
    ;

udp_port_list 
    : output_port_identifier COMMA LIST_112 
    {
        ast::udp_port_list *ret = new ast::udp_port_list;
        $$ = ret;
    }
    ;

udp_declaration_port_list 
    : udp_output_declaration COMMA LIST_113 
    {
        ast::udp_declaration_port_list *ret = new ast::udp_declaration_port_list;
        $$ = ret;
    }
    ;

udp_port_declaration 
    : udp_output_declaration SEMICOLON 
    {
        ast::udp_port_declaration *ret = new ast::udp_port_declaration;
        $$ = ret;
    }
    | udp_input_declaration SEMICOLON 
    {
        ast::udp_port_declaration *ret = new ast::udp_port_declaration;
        $$ = ret;
    }
    | udp_reg_declaration SEMICOLON 
    {
        ast::udp_port_declaration *ret = new ast::udp_port_declaration;
        $$ = ret;
    }
    ;

udp_output_declaration 
    : STAR_2 OUTPUT_ port_identifier 
    {
        ast::udp_output_declaration *ret = new ast::udp_output_declaration;
        $$ = ret;
    }
    | STAR_2 OUTPUT_ REG_ port_identifier OPT_24 
    {
        ast::udp_output_declaration *ret = new ast::udp_output_declaration;
        $$ = ret;
    }
    ;

udp_input_declaration 
    : STAR_2 INPUT_ list_of_udp_port_identifiers 
    {
        ast::udp_input_declaration *ret = new ast::udp_input_declaration;
        $$ = ret;
    }
    ;

udp_reg_declaration 
    : STAR_2 REG_ variable_identifier 
    {
        ast::udp_reg_declaration *ret = new ast::udp_reg_declaration;
        $$ = ret;
    }
    ;

udp_body 
    : combinational_body 
    {
        ast::udp_body *ret = new ast::udp_body;
        $$ = ret;
    }
    | sequential_body 
    {
        ast::udp_body *ret = new ast::udp_body;
        $$ = ret;
    }
    ;

combinational_body 
    : TABLE_ LIST_114 ENDTABLE_ 
    {
        ast::combinational_body *ret = new ast::combinational_body;
        $$ = ret;
    }
    ;

combinational_entry 
    : level_input_list COLON output_symbol SEMICOLON 
    {
        ast::combinational_entry *ret = new ast::combinational_entry;
        $$ = ret;
    }
    ;

sequential_body 
    : OPT_151 TABLE_ LIST_115 ENDTABLE_ 
    {
        ast::sequential_body *ret = new ast::sequential_body;
        $$ = ret;
    }
    ;

udp_initial_statement 
    : INITIAL_ output_port_identifier EQ init_val SEMICOLON 
    {
        ast::udp_initial_statement *ret = new ast::udp_initial_statement;
        $$ = ret;
    }
    ;

init_val 
    : ONEBIT_GND 
    {
        ast::init_val *ret = new ast::init_val;
        $$ = ret;
    }
    | ONEBIT_VDD 
    {
        ast::init_val *ret = new ast::init_val;
        $$ = ret;
    }
    | ONEBIT_X0 
    {
        ast::init_val *ret = new ast::init_val;
        $$ = ret;
    }
    | ONEBIT_X1 
    {
        ast::init_val *ret = new ast::init_val;
        $$ = ret;
    }
    | ONEBIT_BGND 
    {
        ast::init_val *ret = new ast::init_val;
        $$ = ret;
    }
    | ONEBIT_BVDD 
    {
        ast::init_val *ret = new ast::init_val;
        $$ = ret;
    }
    | ONEBIT_BX0 
    {
        ast::init_val *ret = new ast::init_val;
        $$ = ret;
    }
    | ONEBIT_BX1 
    {
        ast::init_val *ret = new ast::init_val;
        $$ = ret;
    }
    | ONE_ 
    {
        ast::init_val *ret = new ast::init_val;
        $$ = ret;
    }
    | ZERO_ 
    {
        ast::init_val *ret = new ast::init_val;
        $$ = ret;
    }
    ;

sequential_entry 
    : seq_input_list COLON current_state COLON next_state SEMICOLON 
    {
        ast::sequential_entry *ret = new ast::sequential_entry;
        $$ = ret;
    }
    ;

seq_input_list 
    : level_input_list 
    {
        ast::seq_input_list *ret = new ast::seq_input_list;
        $$ = ret;
    }
    | edge_input_list 
    {
        ast::seq_input_list *ret = new ast::seq_input_list;
        $$ = ret;
    }
    ;

level_input_list 
    : LIST_116 
    {
        ast::level_input_list *ret = new ast::level_input_list;
        $$ = ret;
    }
    ;

edge_input_list 
    : STAR_43 edge_indicator STAR_43 
    {
        ast::edge_input_list *ret = new ast::edge_input_list;
        $$ = ret;
    }
    ;

edge_indicator 
    : LP level_symbol level_symbol RP 
    {
        ast::edge_indicator *ret = new ast::edge_indicator;
        $$ = ret;
    }
    | edge_symbol 
    {
        ast::edge_indicator *ret = new ast::edge_indicator;
        $$ = ret;
    }
    ;

current_state 
    : level_symbol 
    {
        ast::current_state *ret = new ast::current_state;
        $$ = ret;
    }
    ;

next_state 
    : output_symbol 
    {
        ast::next_state *ret = new ast::next_state;
        $$ = ret;
    }
    | MINUS 
    {
        ast::next_state *ret = new ast::next_state;
        $$ = ret;
    }
    ;

output_symbol 
    : ZERO_ 
    {
        ast::output_symbol *ret = new ast::output_symbol;
        $$ = ret;
    }
    | ONE_ 
    {
        ast::output_symbol *ret = new ast::output_symbol;
        $$ = ret;
    }
    | LETTER_X0_ 
    {
        ast::output_symbol *ret = new ast::output_symbol;
        $$ = ret;
    }
    | LETTER_X1_ 
    {
        ast::output_symbol *ret = new ast::output_symbol;
        $$ = ret;
    }
    ;

level_symbol 
    : ZERO_ 
    {
        ast::level_symbol *ret = new ast::level_symbol;
        $$ = ret;
    }
    | ONE_ 
    {
        ast::level_symbol *ret = new ast::level_symbol;
        $$ = ret;
    }
    | LETTER_X0_ 
    {
        ast::level_symbol *ret = new ast::level_symbol;
        $$ = ret;
    }
    | LETTER_X1_ 
    {
        ast::level_symbol *ret = new ast::level_symbol;
        $$ = ret;
    }
    | QMARK 
    {
        ast::level_symbol *ret = new ast::level_symbol;
        $$ = ret;
    }
    | LETTER_B0_ 
    {
        ast::level_symbol *ret = new ast::level_symbol;
        $$ = ret;
    }
    | LETTER_B1_ 
    {
        ast::level_symbol *ret = new ast::level_symbol;
        $$ = ret;
    }
    ;

edge_symbol 
    : LETTER_R0_ 
    {
        ast::edge_symbol *ret = new ast::edge_symbol;
        $$ = ret;
    }
    | LETTER_R1_ 
    {
        ast::edge_symbol *ret = new ast::edge_symbol;
        $$ = ret;
    }
    | LETTER_F0_ 
    {
        ast::edge_symbol *ret = new ast::edge_symbol;
        $$ = ret;
    }
    | LETTER_F1_ 
    {
        ast::edge_symbol *ret = new ast::edge_symbol;
        $$ = ret;
    }
    | LETTER_P0_ 
    {
        ast::edge_symbol *ret = new ast::edge_symbol;
        $$ = ret;
    }
    | LETTER_P1_ 
    {
        ast::edge_symbol *ret = new ast::edge_symbol;
        $$ = ret;
    }
    | LETTER_N0_ 
    {
        ast::edge_symbol *ret = new ast::edge_symbol;
        $$ = ret;
    }
    | LETTER_N1_ 
    {
        ast::edge_symbol *ret = new ast::edge_symbol;
        $$ = ret;
    }
    | STAR 
    {
        ast::edge_symbol *ret = new ast::edge_symbol;
        $$ = ret;
    }
    ;

udp_instantiation 
    : udp_identifier OPT_135 OPT_136 LIST_117 SEMICOLON 
    {
        ast::udp_instantiation *ret = new ast::udp_instantiation;
        $$ = ret;
    }
    ;

udp_instance 
    : OPT_139 LP output_terminal COMMA LIST_101 RP 
    {
        ast::udp_instance *ret = new ast::udp_instance;
        $$ = ret;
    }
    ;

continuous_assign 
    : ASSIGN_ OPT_135 OPT_55 list_of_net_assignments SEMICOLON 
    {
        ast::continuous_assign *ret = new ast::continuous_assign;
        $$ = ret;
    }
    | ASSIGN_ OPT_56 list_of_variable_assignments SEMICOLON 
    {
        ast::continuous_assign *ret = new ast::continuous_assign;
        $$ = ret;
    }
    ;

list_of_net_assignments 
    : LIST_118 
    {
        ast::list_of_net_assignments *ret = new ast::list_of_net_assignments;
        $$ = ret;
    }
    ;

list_of_variable_assignments 
    : LIST_119 
    {
        ast::list_of_variable_assignments *ret = new ast::list_of_variable_assignments;
        $$ = ret;
    }
    ;

net_alias 
    : ALIAS_ net_lvalue LIST_120 
    {
        ast::net_alias *ret = new ast::net_alias;
        $$ = ret;
    }
    ;

net_assignment 
    : net_lvalue EQ expression 
    {
        ast::net_assignment *ret = new ast::net_assignment;
        $$ = ret;
    }
    ;

initial_construct 
    : INITIAL_ statement_or_null 
    {
        ast::initial_construct *ret = new ast::initial_construct;
        $$ = ret;
    }
    ;

always_construct 
    : always_keyword statement 
    {
        ast::always_construct *ret = new ast::always_construct;
        $$ = ret;
    }
    ;

always_keyword 
    : ALWAYS_ 
    {
        ast::always_keyword *ret = new ast::always_keyword;
        $$ = ret;
    }
    | ALWAYS_COMB_ 
    {
        ast::always_keyword *ret = new ast::always_keyword;
        $$ = ret;
    }
    | ALWAYS_LATCH_ 
    {
        ast::always_keyword *ret = new ast::always_keyword;
        $$ = ret;
    }
    | ALWAYS_FF_ 
    {
        ast::always_keyword *ret = new ast::always_keyword;
        $$ = ret;
    }
    ;

final_construct 
    : FINAL_ function_statement 
    {
        ast::final_construct *ret = new ast::final_construct;
        $$ = ret;
    }
    ;

blocking_assignment 
    : variable_lvalue EQ delay_or_event_control expression 
    {
        ast::blocking_assignment *ret = new ast::blocking_assignment;
        $$ = ret;
    }
    | nonrange_variable_lvalue EQ dynamic_array_new 
    {
        ast::blocking_assignment *ret = new ast::blocking_assignment;
        $$ = ret;
    }
    | OPT_152 hierarchical_variable_identifier select EQ class_new 
    {
        ast::blocking_assignment *ret = new ast::blocking_assignment;
        $$ = ret;
    }
    | operator_assignment 
    {
        ast::blocking_assignment *ret = new ast::blocking_assignment;
        $$ = ret;
    }
    ;

operator_assignment 
    : variable_lvalue assignment_operator expression 
    {
        ast::operator_assignment *ret = new ast::operator_assignment;
        $$ = ret;
    }
    ;

assignment_operator 
    : EQ 
    {
        ast::assignment_operator *ret = new ast::assignment_operator;
        $$ = ret;
    }
    | PLUS_EQ 
    {
        ast::assignment_operator *ret = new ast::assignment_operator;
        $$ = ret;
    }
    | MINUS_EQ 
    {
        ast::assignment_operator *ret = new ast::assignment_operator;
        $$ = ret;
    }
    | STAR_EQ 
    {
        ast::assignment_operator *ret = new ast::assignment_operator;
        $$ = ret;
    }
    | SLASH_EQ 
    {
        ast::assignment_operator *ret = new ast::assignment_operator;
        $$ = ret;
    }
    | PERCENT_EQ 
    {
        ast::assignment_operator *ret = new ast::assignment_operator;
        $$ = ret;
    }
    | AND_EQ 
    {
        ast::assignment_operator *ret = new ast::assignment_operator;
        $$ = ret;
    }
    | BAR_EQ 
    {
        ast::assignment_operator *ret = new ast::assignment_operator;
        $$ = ret;
    }
    | XOR_EQ 
    {
        ast::assignment_operator *ret = new ast::assignment_operator;
        $$ = ret;
    }
    | LSHIFT_EQ 
    {
        ast::assignment_operator *ret = new ast::assignment_operator;
        $$ = ret;
    }
    | RSHIFT_EQ 
    {
        ast::assignment_operator *ret = new ast::assignment_operator;
        $$ = ret;
    }
    | LSHIFT2_EQ 
    {
        ast::assignment_operator *ret = new ast::assignment_operator;
        $$ = ret;
    }
    | RSHIFT2_EQ 
    {
        ast::assignment_operator *ret = new ast::assignment_operator;
        $$ = ret;
    }
    ;

nonblocking_assignment 
    : variable_lvalue LTE OPT_153 expression 
    {
        ast::nonblocking_assignment *ret = new ast::nonblocking_assignment;
        $$ = ret;
    }
    ;

procedural_continuous_assignment 
    : ASSIGN_ variable_assignment 
    {
        ast::procedural_continuous_assignment *ret = new ast::procedural_continuous_assignment;
        $$ = ret;
    }
    | DEASSIGN_ variable_lvalue 
    {
        ast::procedural_continuous_assignment *ret = new ast::procedural_continuous_assignment;
        $$ = ret;
    }
    | FORCE_ variable_assignment 
    {
        ast::procedural_continuous_assignment *ret = new ast::procedural_continuous_assignment;
        $$ = ret;
    }
    | FORCE_ net_assignment 
    {
        ast::procedural_continuous_assignment *ret = new ast::procedural_continuous_assignment;
        $$ = ret;
    }
    | RELEASE_ variable_lvalue 
    {
        ast::procedural_continuous_assignment *ret = new ast::procedural_continuous_assignment;
        $$ = ret;
    }
    | RELEASE_ net_lvalue 
    {
        ast::procedural_continuous_assignment *ret = new ast::procedural_continuous_assignment;
        $$ = ret;
    }
    ;

variable_assignment 
    : variable_lvalue EQ expression 
    {
        ast::variable_assignment *ret = new ast::variable_assignment;
        $$ = ret;
    }
    ;

action_block 
    : statement_or_null 
    {
        ast::action_block *ret = new ast::action_block;
        $$ = ret;
    }
    | OPT_154 ELSE_ statement_or_null 
    {
        ast::action_block *ret = new ast::action_block;
        $$ = ret;
    }
    ;

seq_block 
    : BEGIN_ OPT_155 STAR_24 STAR_32 END_ OPT_155 
    {
        ast::seq_block *ret = new ast::seq_block;
        $$ = ret;
    }
    ;

par_block 
    : FORK_ OPT_155 STAR_24 STAR_32 join_keyword OPT_155 
    {
        ast::par_block *ret = new ast::par_block;
        $$ = ret;
    }
    ;

join_keyword 
    : JOIN_ 
    {
        ast::join_keyword *ret = new ast::join_keyword;
        $$ = ret;
    }
    | JOIN_ANY_ 
    {
        ast::join_keyword *ret = new ast::join_keyword;
        $$ = ret;
    }
    | JOIN_NONE_ 
    {
        ast::join_keyword *ret = new ast::join_keyword;
        $$ = ret;
    }
    ;

statement_or_null 
    : statement 
    {
        ast::statement_or_null *ret = new ast::statement_or_null;
        $$ = ret;
    }
    | STAR_2 SEMICOLON 
    {
        ast::statement_or_null *ret = new ast::statement_or_null;
        $$ = ret;
    }
    ;

statement 
    : OPT_89 STAR_2 statement_item 
    {
        ast::statement *ret = new ast::statement;
        $$ = ret;
    }
    ;

statement_item 
    : blocking_assignment SEMICOLON 
    {
        ast::statement_item *ret = new ast::statement_item;
        $$ = ret;
    }
    | nonblocking_assignment SEMICOLON 
    {
        ast::statement_item *ret = new ast::statement_item;
        $$ = ret;
    }
    | procedural_continuous_assignment SEMICOLON 
    {
        ast::statement_item *ret = new ast::statement_item;
        $$ = ret;
    }
    | case_statement 
    {
        ast::statement_item *ret = new ast::statement_item;
        $$ = ret;
    }
    | conditional_statement 
    {
        ast::statement_item *ret = new ast::statement_item;
        $$ = ret;
    }
    | inc_or_dec_expression SEMICOLON 
    {
        ast::statement_item *ret = new ast::statement_item;
        $$ = ret;
    }
    | subroutine_call_statement 
    {
        ast::statement_item *ret = new ast::statement_item;
        $$ = ret;
    }
    | disable_statement 
    {
        ast::statement_item *ret = new ast::statement_item;
        $$ = ret;
    }
    | event_trigger 
    {
        ast::statement_item *ret = new ast::statement_item;
        $$ = ret;
    }
    | loop_statement 
    {
        ast::statement_item *ret = new ast::statement_item;
        $$ = ret;
    }
    | jump_statement 
    {
        ast::statement_item *ret = new ast::statement_item;
        $$ = ret;
    }
    | par_block 
    {
        ast::statement_item *ret = new ast::statement_item;
        $$ = ret;
    }
    | procedural_timing_control_statement 
    {
        ast::statement_item *ret = new ast::statement_item;
        $$ = ret;
    }
    | seq_block 
    {
        ast::statement_item *ret = new ast::statement_item;
        $$ = ret;
    }
    | wait_statement 
    {
        ast::statement_item *ret = new ast::statement_item;
        $$ = ret;
    }
    | procedural_assertion_statement 
    {
        ast::statement_item *ret = new ast::statement_item;
        $$ = ret;
    }
    | clocking_drive SEMICOLON 
    {
        ast::statement_item *ret = new ast::statement_item;
        $$ = ret;
    }
    | randsequence_statement 
    {
        ast::statement_item *ret = new ast::statement_item;
        $$ = ret;
    }
    | randcase_statement 
    {
        ast::statement_item *ret = new ast::statement_item;
        $$ = ret;
    }
    | expect_property_statement 
    {
        ast::statement_item *ret = new ast::statement_item;
        $$ = ret;
    }
    ;

function_statement 
    : statement 
    {
        ast::function_statement *ret = new ast::function_statement;
        $$ = ret;
    }
    ;

function_statement_or_null 
    : function_statement 
    {
        ast::function_statement_or_null *ret = new ast::function_statement_or_null;
        $$ = ret;
    }
    | STAR_2 SEMICOLON 
    {
        ast::function_statement_or_null *ret = new ast::function_statement_or_null;
        $$ = ret;
    }
    ;

variable_identifier_list 
    : LIST_121 
    {
        ast::variable_identifier_list *ret = new ast::variable_identifier_list;
        $$ = ret;
    }
    ;

procedural_timing_control_statement 
    : procedural_timing_control statement_or_null 
    {
        ast::procedural_timing_control_statement *ret = new ast::procedural_timing_control_statement;
        $$ = ret;
    }
    ;

delay_or_event_control 
    : delay_control 
    {
        ast::delay_or_event_control *ret = new ast::delay_or_event_control;
        $$ = ret;
    }
    | event_control 
    {
        ast::delay_or_event_control *ret = new ast::delay_or_event_control;
        $$ = ret;
    }
    | REPEAT_ LP expression RP event_control 
    {
        ast::delay_or_event_control *ret = new ast::delay_or_event_control;
        $$ = ret;
    }
    ;

delay_control 
    : SHARP delay_value 
    {
        ast::delay_control *ret = new ast::delay_control;
        $$ = ret;
    }
    | SHARP LP mintypmax_expression RP 
    {
        ast::delay_control *ret = new ast::delay_control;
        $$ = ret;
    }
    ;

event_control 
    : AT hierarchical_event_identifier 
    {
        ast::event_control *ret = new ast::event_control;
        $$ = ret;
    }
    | AT LP event_expression RP 
    {
        ast::event_control *ret = new ast::event_control;
        $$ = ret;
    }
    | AT STAR 
    {
        ast::event_control *ret = new ast::event_control;
        $$ = ret;
    }
    | AT LP STAR RP 
    {
        ast::event_control *ret = new ast::event_control;
        $$ = ret;
    }
    | AT ps_or_hierarchical_sequence_identifier 
    {
        ast::event_control *ret = new ast::event_control;
        $$ = ret;
    }
    ;

event_expression 
    : OPT_156 expression OPT_157 
    {
        ast::event_expression *ret = new ast::event_expression;
        $$ = ret;
    }
    | sequence_instance OPT_157 
    {
        ast::event_expression *ret = new ast::event_expression;
        $$ = ret;
    }
    | event_expression OR_ event_expression 
    {
        ast::event_expression *ret = new ast::event_expression;
        $$ = ret;
    }
    | event_expression COMMA event_expression 
    {
        ast::event_expression *ret = new ast::event_expression;
        $$ = ret;
    }
    | LP event_expression RP 
    {
        ast::event_expression *ret = new ast::event_expression;
        $$ = ret;
    }
    ;

procedural_timing_control 
    : delay_control 
    {
        ast::procedural_timing_control *ret = new ast::procedural_timing_control;
        $$ = ret;
    }
    | event_control 
    {
        ast::procedural_timing_control *ret = new ast::procedural_timing_control;
        $$ = ret;
    }
    | cycle_delay 
    {
        ast::procedural_timing_control *ret = new ast::procedural_timing_control;
        $$ = ret;
    }
    ;

jump_statement 
    : RETURN_ OPT_26 SEMICOLON 
    {
        ast::jump_statement *ret = new ast::jump_statement;
        $$ = ret;
    }
    | BREAK_ SEMICOLON 
    {
        ast::jump_statement *ret = new ast::jump_statement;
        $$ = ret;
    }
    | CONTINUE_ SEMICOLON 
    {
        ast::jump_statement *ret = new ast::jump_statement;
        $$ = ret;
    }
    ;

wait_statement 
    : WAIT_ LP expression RP statement_or_null 
    {
        ast::wait_statement *ret = new ast::wait_statement;
        $$ = ret;
    }
    | WAIT_ FORK_ SEMICOLON 
    {
        ast::wait_statement *ret = new ast::wait_statement;
        $$ = ret;
    }
    | WAIT_ORDER_ LP LIST_122 RP action_block 
    {
        ast::wait_statement *ret = new ast::wait_statement;
        $$ = ret;
    }
    ;

event_trigger 
    : RIGHTARROW hierarchical_event_identifier SEMICOLON 
    {
        ast::event_trigger *ret = new ast::event_trigger;
        $$ = ret;
    }
    | DASH_RSHIFT OPT_153 hierarchical_event_identifier SEMICOLON 
    {
        ast::event_trigger *ret = new ast::event_trigger;
        $$ = ret;
    }
    ;

disable_statement 
    : DISABLE_ hierarchical_task_identifier SEMICOLON 
    {
        ast::disable_statement *ret = new ast::disable_statement;
        $$ = ret;
    }
    | DISABLE_ hierarchical_block_identifier SEMICOLON 
    {
        ast::disable_statement *ret = new ast::disable_statement;
        $$ = ret;
    }
    | DISABLE_ FORK_ SEMICOLON 
    {
        ast::disable_statement *ret = new ast::disable_statement;
        $$ = ret;
    }
    ;

conditional_statement 
    : OPT_158 IF_ LP cond_predicate RP statement_or_null STAR_44 OPT_159 
    {
        ast::conditional_statement *ret = new ast::conditional_statement;
        $$ = ret;
    }
    ;

unique_priority 
    : UNIQUE_ 
    {
        ast::unique_priority *ret = new ast::unique_priority;
        $$ = ret;
    }
    | UNIQUE0_ 
    {
        ast::unique_priority *ret = new ast::unique_priority;
        $$ = ret;
    }
    | PRIORITY_ 
    {
        ast::unique_priority *ret = new ast::unique_priority;
        $$ = ret;
    }
    ;

cond_predicate 
    : LIST_124 
    {
        ast::cond_predicate *ret = new ast::cond_predicate;
        $$ = ret;
    }
    ;

expression_or_cond_pattern 
    : expression 
    {
        ast::expression_or_cond_pattern *ret = new ast::expression_or_cond_pattern;
        $$ = ret;
    }
    | cond_pattern 
    {
        ast::expression_or_cond_pattern *ret = new ast::expression_or_cond_pattern;
        $$ = ret;
    }
    ;

cond_pattern 
    : expression MATCHES_ pattern 
    {
        ast::cond_pattern *ret = new ast::cond_pattern;
        $$ = ret;
    }
    ;

case_statement 
    : OPT_158 case_keyword LP case_expression RP LIST_125 ENDCASE_ 
    {
        ast::case_statement *ret = new ast::case_statement;
        $$ = ret;
    }
    | OPT_158 case_keyword LP case_expression RP MATCHES_ LIST_126 ENDCASE_ 
    {
        ast::case_statement *ret = new ast::case_statement;
        $$ = ret;
    }
    | OPT_158 CASE_ LP case_expression RP INSIDE_ LIST_127 ENDCASE_ 
    {
        ast::case_statement *ret = new ast::case_statement;
        $$ = ret;
    }
    ;

case_keyword 
    : CASE_ 
    {
        ast::case_keyword *ret = new ast::case_keyword;
        $$ = ret;
    }
    | CASEX_ 
    {
        ast::case_keyword *ret = new ast::case_keyword;
        $$ = ret;
    }
    | CASEZ_ 
    {
        ast::case_keyword *ret = new ast::case_keyword;
        $$ = ret;
    }
    ;

case_expression 
    : expression 
    {
        ast::case_expression *ret = new ast::case_expression;
        $$ = ret;
    }
    ;

case_item 
    : LIST_128 COLON statement_or_null 
    {
        ast::case_item *ret = new ast::case_item;
        $$ = ret;
    }
    | DEFAULT_ OPT_102 statement_or_null 
    {
        ast::case_item *ret = new ast::case_item;
        $$ = ret;
    }
    ;

case_pattern_item 
    : pattern OPT_160 COLON statement_or_null 
    {
        ast::case_pattern_item *ret = new ast::case_pattern_item;
        $$ = ret;
    }
    | DEFAULT_ OPT_102 statement_or_null 
    {
        ast::case_pattern_item *ret = new ast::case_pattern_item;
        $$ = ret;
    }
    ;

case_inside_item 
    : open_range_list COLON statement_or_null 
    {
        ast::case_inside_item *ret = new ast::case_inside_item;
        $$ = ret;
    }
    | DEFAULT_ OPT_102 statement_or_null 
    {
        ast::case_inside_item *ret = new ast::case_inside_item;
        $$ = ret;
    }
    ;

case_item_expression 
    : expression 
    {
        ast::case_item_expression *ret = new ast::case_item_expression;
        $$ = ret;
    }
    ;

randcase_statement 
    : RANDCASE_ LIST_129 ENDCASE_ 
    {
        ast::randcase_statement *ret = new ast::randcase_statement;
        $$ = ret;
    }
    ;

randcase_item 
    : expression COLON statement_or_null 
    {
        ast::randcase_item *ret = new ast::randcase_item;
        $$ = ret;
    }
    ;

open_range_list 
    : LIST_130 
    {
        ast::open_range_list *ret = new ast::open_range_list;
        $$ = ret;
    }
    ;

open_value_range 
    : value_range 
    {
        ast::open_value_range *ret = new ast::open_value_range;
        $$ = ret;
    }
    ;

pattern 
    : DOT variable_identifier 
    {
        ast::pattern *ret = new ast::pattern;
        $$ = ret;
    }
    | DOT STAR 
    {
        ast::pattern *ret = new ast::pattern;
        $$ = ret;
    }
    | constant_expression 
    {
        ast::pattern *ret = new ast::pattern;
        $$ = ret;
    }
    | TAGGED_ member_identifier OPT_161 
    {
        ast::pattern *ret = new ast::pattern;
        $$ = ret;
    }
    | APOSTROPHE LMP LIST_131 RMP 
    {
        ast::pattern *ret = new ast::pattern;
        $$ = ret;
    }
    | APOSTROPHE LMP LIST_132 RMP 
    {
        ast::pattern *ret = new ast::pattern;
        $$ = ret;
    }
    ;

assignment_pattern 
    : APOSTROPHE LMP LIST_133 RMP 
    {
        ast::assignment_pattern *ret = new ast::assignment_pattern;
        $$ = ret;
    }
    | APOSTROPHE LMP LIST_134 RMP 
    {
        ast::assignment_pattern *ret = new ast::assignment_pattern;
        $$ = ret;
    }
    | APOSTROPHE LMP LIST_135 RMP 
    {
        ast::assignment_pattern *ret = new ast::assignment_pattern;
        $$ = ret;
    }
    | APOSTROPHE LMP constant_expression LMP LIST_133 RMP RMP 
    {
        ast::assignment_pattern *ret = new ast::assignment_pattern;
        $$ = ret;
    }
    ;

structure_pattern_key 
    : member_identifier 
    {
        ast::structure_pattern_key *ret = new ast::structure_pattern_key;
        $$ = ret;
    }
    | assignment_pattern_key 
    {
        ast::structure_pattern_key *ret = new ast::structure_pattern_key;
        $$ = ret;
    }
    ;

array_pattern_key 
    : constant_expression 
    {
        ast::array_pattern_key *ret = new ast::array_pattern_key;
        $$ = ret;
    }
    | assignment_pattern_key 
    {
        ast::array_pattern_key *ret = new ast::array_pattern_key;
        $$ = ret;
    }
    ;

assignment_pattern_key 
    : simple_type 
    {
        ast::assignment_pattern_key *ret = new ast::assignment_pattern_key;
        $$ = ret;
    }
    | DEFAULT_ 
    {
        ast::assignment_pattern_key *ret = new ast::assignment_pattern_key;
        $$ = ret;
    }
    ;

assignment_pattern_expression 
    : OPT_162 assignment_pattern 
    {
        ast::assignment_pattern_expression *ret = new ast::assignment_pattern_expression;
        $$ = ret;
    }
    ;

assignment_pattern_expression_type 
    : ps_type_identifier 
    {
        ast::assignment_pattern_expression_type *ret = new ast::assignment_pattern_expression_type;
        $$ = ret;
    }
    | ps_parameter_identifier 
    {
        ast::assignment_pattern_expression_type *ret = new ast::assignment_pattern_expression_type;
        $$ = ret;
    }
    | integer_atom_type 
    {
        ast::assignment_pattern_expression_type *ret = new ast::assignment_pattern_expression_type;
        $$ = ret;
    }
    | type_reference 
    {
        ast::assignment_pattern_expression_type *ret = new ast::assignment_pattern_expression_type;
        $$ = ret;
    }
    ;

constant_assignment_pattern_expression 
    : assignment_pattern_expression 
    {
        ast::constant_assignment_pattern_expression *ret = new ast::constant_assignment_pattern_expression;
        $$ = ret;
    }
    ;

assignment_pattern_net_lvalue 
    : APOSTROPHE LMP LIST_136 RMP 
    {
        ast::assignment_pattern_net_lvalue *ret = new ast::assignment_pattern_net_lvalue;
        $$ = ret;
    }
    ;

assignment_pattern_variable_lvalue 
    : APOSTROPHE LMP LIST_137 RMP 
    {
        ast::assignment_pattern_variable_lvalue *ret = new ast::assignment_pattern_variable_lvalue;
        $$ = ret;
    }
    ;

loop_statement 
    : FOREVER_ statement_or_null 
    {
        ast::loop_statement *ret = new ast::loop_statement;
        $$ = ret;
    }
    | REPEAT_ LP expression RP statement_or_null 
    {
        ast::loop_statement *ret = new ast::loop_statement;
        $$ = ret;
    }
    | WHILE_ LP expression RP statement_or_null 
    {
        ast::loop_statement *ret = new ast::loop_statement;
        $$ = ret;
    }
    | FOR_ LP OPT_163 SEMICOLON OPT_26 SEMICOLON OPT_164 RP statement_or_null 
    {
        ast::loop_statement *ret = new ast::loop_statement;
        $$ = ret;
    }
    | DO_ statement_or_null WHILE_ LP expression RP SEMICOLON 
    {
        ast::loop_statement *ret = new ast::loop_statement;
        $$ = ret;
    }
    | FOREACH_ LP ps_or_hierarchical_array_identifier LSP loop_variables RSP RP statement 
    {
        ast::loop_statement *ret = new ast::loop_statement;
        $$ = ret;
    }
    ;

for_initialization 
    : list_of_variable_assignments 
    {
        ast::for_initialization *ret = new ast::for_initialization;
        $$ = ret;
    }
    | LIST_138 
    {
        ast::for_initialization *ret = new ast::for_initialization;
        $$ = ret;
    }
    ;

for_variable_declaration 
    : OPT_52 LIST_139 
    {
        ast::for_variable_declaration *ret = new ast::for_variable_declaration;
        $$ = ret;
    }
    ;

for_step 
    : LIST_140 
    {
        ast::for_step *ret = new ast::for_step;
        $$ = ret;
    }
    ;

for_step_assignment 
    : operator_assignment 
    {
        ast::for_step_assignment *ret = new ast::for_step_assignment;
        $$ = ret;
    }
    | inc_or_dec_expression 
    {
        ast::for_step_assignment *ret = new ast::for_step_assignment;
        $$ = ret;
    }
    | function_subroutine_call 
    {
        ast::for_step_assignment *ret = new ast::for_step_assignment;
        $$ = ret;
    }
    ;

loop_variables 
    : LIST_141 
    {
        ast::loop_variables *ret = new ast::loop_variables;
        $$ = ret;
    }
    ;

subroutine_call_statement 
    : subroutine_call SEMICOLON 
    {
        ast::subroutine_call_statement *ret = new ast::subroutine_call_statement;
        $$ = ret;
    }
    | VOID_ APOSTROPHE LP function_subroutine_call RP SEMICOLON 
    {
        ast::subroutine_call_statement *ret = new ast::subroutine_call_statement;
        $$ = ret;
    }
    ;

assertion_item 
    : concurrent_assertion_item 
    {
        ast::assertion_item *ret = new ast::assertion_item;
        $$ = ret;
    }
    | deferred_immediate_assertion_item 
    {
        ast::assertion_item *ret = new ast::assertion_item;
        $$ = ret;
    }
    ;

deferred_immediate_assertion_item 
    : OPT_89 deferred_immediate_assertion_statement 
    {
        ast::deferred_immediate_assertion_item *ret = new ast::deferred_immediate_assertion_item;
        $$ = ret;
    }
    ;

procedural_assertion_statement 
    : concurrent_assertion_statement 
    {
        ast::procedural_assertion_statement *ret = new ast::procedural_assertion_statement;
        $$ = ret;
    }
    | immediate_assertion_statement 
    {
        ast::procedural_assertion_statement *ret = new ast::procedural_assertion_statement;
        $$ = ret;
    }
    | checker_instantiation 
    {
        ast::procedural_assertion_statement *ret = new ast::procedural_assertion_statement;
        $$ = ret;
    }
    ;

immediate_assertion_statement 
    : simple_immediate_assertion_statement 
    {
        ast::immediate_assertion_statement *ret = new ast::immediate_assertion_statement;
        $$ = ret;
    }
    | deferred_immediate_assertion_statement 
    {
        ast::immediate_assertion_statement *ret = new ast::immediate_assertion_statement;
        $$ = ret;
    }
    ;

simple_immediate_assertion_statement 
    : simple_immediate_assert_statement 
    {
        ast::simple_immediate_assertion_statement *ret = new ast::simple_immediate_assertion_statement;
        $$ = ret;
    }
    | simple_immediate_assume_statement 
    {
        ast::simple_immediate_assertion_statement *ret = new ast::simple_immediate_assertion_statement;
        $$ = ret;
    }
    | simple_immediate_cover_statement 
    {
        ast::simple_immediate_assertion_statement *ret = new ast::simple_immediate_assertion_statement;
        $$ = ret;
    }
    ;

simple_immediate_assert_statement 
    : ASSERT_ LP expression RP action_block 
    {
        ast::simple_immediate_assert_statement *ret = new ast::simple_immediate_assert_statement;
        $$ = ret;
    }
    ;

simple_immediate_assume_statement 
    : ASSUME_ LP expression RP action_block 
    {
        ast::simple_immediate_assume_statement *ret = new ast::simple_immediate_assume_statement;
        $$ = ret;
    }
    ;

simple_immediate_cover_statement 
    : COVER_ LP expression RP action_block 
    {
        ast::simple_immediate_cover_statement *ret = new ast::simple_immediate_cover_statement;
        $$ = ret;
    }
    ;

deferred_immediate_assertion_statement 
    : deferred_immediate_assert_statement 
    {
        ast::deferred_immediate_assertion_statement *ret = new ast::deferred_immediate_assertion_statement;
        $$ = ret;
    }
    | deferred_immediate_assume_statement 
    {
        ast::deferred_immediate_assertion_statement *ret = new ast::deferred_immediate_assertion_statement;
        $$ = ret;
    }
    | deferred_immediate_cover_statement 
    {
        ast::deferred_immediate_assertion_statement *ret = new ast::deferred_immediate_assertion_statement;
        $$ = ret;
    }
    ;

deferred_immediate_assert_statement 
    : ASSERT_ SHARP0_ LP expression RP action_block 
    {
        ast::deferred_immediate_assert_statement *ret = new ast::deferred_immediate_assert_statement;
        $$ = ret;
    }
    | ASSERT_ FINAL_ LP expression RP action_block 
    {
        ast::deferred_immediate_assert_statement *ret = new ast::deferred_immediate_assert_statement;
        $$ = ret;
    }
    ;

deferred_immediate_assume_statement 
    : ASSUME_ SHARP0_ LP expression RP action_block 
    {
        ast::deferred_immediate_assume_statement *ret = new ast::deferred_immediate_assume_statement;
        $$ = ret;
    }
    | ASSUME_ FINAL_ LP expression RP action_block 
    {
        ast::deferred_immediate_assume_statement *ret = new ast::deferred_immediate_assume_statement;
        $$ = ret;
    }
    ;

deferred_immediate_cover_statement 
    : COVER_ SHARP0_ LP expression RP statement_or_null 
    {
        ast::deferred_immediate_cover_statement *ret = new ast::deferred_immediate_cover_statement;
        $$ = ret;
    }
    | COVER_ FINAL_ LP expression RP statement_or_null 
    {
        ast::deferred_immediate_cover_statement *ret = new ast::deferred_immediate_cover_statement;
        $$ = ret;
    }
    ;

clocking_declaration 
    : OPT_166 CLOCKING_ OPT_167 clocking_event SEMICOLON STAR_45 ENDCLOCKING_ OPT_168 
    {
        ast::clocking_declaration *ret = new ast::clocking_declaration;
        $$ = ret;
    }
    | GLOBAL_ CLOCKING_ OPT_167 clocking_event SEMICOLON ENDCLOCKING_ OPT_168 
    {
        ast::clocking_declaration *ret = new ast::clocking_declaration;
        $$ = ret;
    }
    ;

clocking_event 
    : AT identifier 
    {
        ast::clocking_event *ret = new ast::clocking_event;
        $$ = ret;
    }
    | AT LP event_expression RP 
    {
        ast::clocking_event *ret = new ast::clocking_event;
        $$ = ret;
    }
    ;

clocking_item 
    : DEFAULT_ default_skew SEMICOLON 
    {
        ast::clocking_item *ret = new ast::clocking_item;
        $$ = ret;
    }
    | clocking_direction list_of_clocking_decl_assign SEMICOLON 
    {
        ast::clocking_item *ret = new ast::clocking_item;
        $$ = ret;
    }
    | STAR_2 assertion_item_declaration 
    {
        ast::clocking_item *ret = new ast::clocking_item;
        $$ = ret;
    }
    ;

default_skew 
    : INPUT_ clocking_skew 
    {
        ast::default_skew *ret = new ast::default_skew;
        $$ = ret;
    }
    | OUTPUT_ clocking_skew 
    {
        ast::default_skew *ret = new ast::default_skew;
        $$ = ret;
    }
    | INPUT_ clocking_skew OUTPUT_ clocking_skew 
    {
        ast::default_skew *ret = new ast::default_skew;
        $$ = ret;
    }
    ;

clocking_direction 
    : INPUT_ OPT_169 
    {
        ast::clocking_direction *ret = new ast::clocking_direction;
        $$ = ret;
    }
    | OUTPUT_ OPT_169 
    {
        ast::clocking_direction *ret = new ast::clocking_direction;
        $$ = ret;
    }
    | INPUT_ OPT_169 OUTPUT_ OPT_169 
    {
        ast::clocking_direction *ret = new ast::clocking_direction;
        $$ = ret;
    }
    | INOUT_ 
    {
        ast::clocking_direction *ret = new ast::clocking_direction;
        $$ = ret;
    }
    ;

list_of_clocking_decl_assign 
    : LIST_143 
    {
        ast::list_of_clocking_decl_assign *ret = new ast::list_of_clocking_decl_assign;
        $$ = ret;
    }
    ;

clocking_decl_assign 
    : signal_identifier OPT_73 
    {
        ast::clocking_decl_assign *ret = new ast::clocking_decl_assign;
        $$ = ret;
    }
    ;

clocking_skew 
    : edge_identifier OPT_56 
    {
        ast::clocking_skew *ret = new ast::clocking_skew;
        $$ = ret;
    }
    | delay_control 
    {
        ast::clocking_skew *ret = new ast::clocking_skew;
        $$ = ret;
    }
    ;

clocking_drive 
    : clockvar_expression LTE OPT_170 expression 
    {
        ast::clocking_drive *ret = new ast::clocking_drive;
        $$ = ret;
    }
    ;

cycle_delay 
    : SHARP2 integral_number 
    {
        ast::cycle_delay *ret = new ast::cycle_delay;
        $$ = ret;
    }
    | SHARP2 identifier 
    {
        ast::cycle_delay *ret = new ast::cycle_delay;
        $$ = ret;
    }
    | SHARP2 LP expression RP 
    {
        ast::cycle_delay *ret = new ast::cycle_delay;
        $$ = ret;
    }
    ;

clockvar 
    : hierarchical_identifier 
    {
        ast::clockvar *ret = new ast::clockvar;
        $$ = ret;
    }
    ;

clockvar_expression 
    : clockvar select 
    {
        ast::clockvar_expression *ret = new ast::clockvar_expression;
        $$ = ret;
    }
    ;

randsequence_statement 
    : RANDSEQUENCE_ LP OPT_171 RP LIST_144 ENDSEQUENCE_ 
    {
        ast::randsequence_statement *ret = new ast::randsequence_statement;
        $$ = ret;
    }
    ;

production 
    : OPT_172 production_identifier OPT_173 COLON LIST_145 SEMICOLON 
    {
        ast::production *ret = new ast::production;
        $$ = ret;
    }
    ;

rs_rule 
    : rs_production_list OPT_175 
    {
        ast::rs_rule *ret = new ast::rs_rule;
        $$ = ret;
    }
    ;

rs_production_list 
    : LIST_146 
    {
        ast::rs_production_list *ret = new ast::rs_production_list;
        $$ = ret;
    }
    | RAND_ JOIN_ OPT_79 production_item LIST_147 
    {
        ast::rs_production_list *ret = new ast::rs_production_list;
        $$ = ret;
    }
    ;

weight_specification 
    : integral_number 
    {
        ast::weight_specification *ret = new ast::weight_specification;
        $$ = ret;
    }
    | ps_identifier 
    {
        ast::weight_specification *ret = new ast::weight_specification;
        $$ = ret;
    }
    | LP expression RP 
    {
        ast::weight_specification *ret = new ast::weight_specification;
        $$ = ret;
    }
    ;

rs_code_block 
    : LMP STAR_46 STAR_32 RMP 
    {
        ast::rs_code_block *ret = new ast::rs_code_block;
        $$ = ret;
    }
    ;

rs_prod 
    : production_item 
    {
        ast::rs_prod *ret = new ast::rs_prod;
        $$ = ret;
    }
    | rs_code_block 
    {
        ast::rs_prod *ret = new ast::rs_prod;
        $$ = ret;
    }
    | rs_if_else 
    {
        ast::rs_prod *ret = new ast::rs_prod;
        $$ = ret;
    }
    | rs_repeat 
    {
        ast::rs_prod *ret = new ast::rs_prod;
        $$ = ret;
    }
    | rs_case 
    {
        ast::rs_prod *ret = new ast::rs_prod;
        $$ = ret;
    }
    ;

production_item 
    : production_identifier OPT_12 
    {
        ast::production_item *ret = new ast::production_item;
        $$ = ret;
    }
    ;

rs_if_else 
    : IF_ LP expression RP production_item OPT_176 
    {
        ast::rs_if_else *ret = new ast::rs_if_else;
        $$ = ret;
    }
    ;

rs_repeat 
    : REPEAT_ LP expression RP production_item 
    {
        ast::rs_repeat *ret = new ast::rs_repeat;
        $$ = ret;
    }
    ;

rs_case 
    : CASE_ LP case_expression RP LIST_149 ENDCASE_ 
    {
        ast::rs_case *ret = new ast::rs_case;
        $$ = ret;
    }
    ;

rs_case_item 
    : LIST_128 COLON production_item SEMICOLON 
    {
        ast::rs_case_item *ret = new ast::rs_case_item;
        $$ = ret;
    }
    | DEFAULT_ OPT_102 production_item SEMICOLON 
    {
        ast::rs_case_item *ret = new ast::rs_case_item;
        $$ = ret;
    }
    ;

specify_block 
    : SPECIFY_ STAR_47 ENDSPECIFY_ 
    {
        ast::specify_block *ret = new ast::specify_block;
        $$ = ret;
    }
    ;

specify_item 
    : specparam_declaration 
    {
        ast::specify_item *ret = new ast::specify_item;
        $$ = ret;
    }
    | pulsestyle_declaration 
    {
        ast::specify_item *ret = new ast::specify_item;
        $$ = ret;
    }
    | showcancelled_declaration 
    {
        ast::specify_item *ret = new ast::specify_item;
        $$ = ret;
    }
    | path_declaration 
    {
        ast::specify_item *ret = new ast::specify_item;
        $$ = ret;
    }
    | system_timing_check 
    {
        ast::specify_item *ret = new ast::specify_item;
        $$ = ret;
    }
    ;

pulsestyle_declaration 
    : PULSESTYLE_ONEVENT_ list_of_path_outputs SEMICOLON 
    {
        ast::pulsestyle_declaration *ret = new ast::pulsestyle_declaration;
        $$ = ret;
    }
    | PULSESTYPE_ONDETECT_ list_of_path_outputs SEMICOLON 
    {
        ast::pulsestyle_declaration *ret = new ast::pulsestyle_declaration;
        $$ = ret;
    }
    ;

showcancelled_declaration 
    : SHOWCANCELLED_ list_of_path_outputs SEMICOLON 
    {
        ast::showcancelled_declaration *ret = new ast::showcancelled_declaration;
        $$ = ret;
    }
    | NOSHOWCANCELLED_ list_of_path_outputs SEMICOLON 
    {
        ast::showcancelled_declaration *ret = new ast::showcancelled_declaration;
        $$ = ret;
    }
    ;

path_declaration 
    : simple_path_declaration SEMICOLON 
    {
        ast::path_declaration *ret = new ast::path_declaration;
        $$ = ret;
    }
    | edge_sensitive_path_declaration SEMICOLON 
    {
        ast::path_declaration *ret = new ast::path_declaration;
        $$ = ret;
    }
    | state_dependent_path_declaration SEMICOLON 
    {
        ast::path_declaration *ret = new ast::path_declaration;
        $$ = ret;
    }
    ;

simple_path_declaration 
    : parallel_path_description EQ path_delay_value 
    {
        ast::simple_path_declaration *ret = new ast::simple_path_declaration;
        $$ = ret;
    }
    | full_path_description EQ path_delay_value 
    {
        ast::simple_path_declaration *ret = new ast::simple_path_declaration;
        $$ = ret;
    }
    ;

parallel_path_description 
    : LP specify_input_terminal_descriptor OPT_177 EQ_GT specify_output_terminal_descriptor RP 
    {
        ast::parallel_path_description *ret = new ast::parallel_path_description;
        $$ = ret;
    }
    ;

full_path_description 
    : LP list_of_path_inputs OPT_177 STAR_RT list_of_path_outputs RP 
    {
        ast::full_path_description *ret = new ast::full_path_description;
        $$ = ret;
    }
    ;

list_of_path_inputs 
    : LIST_151 
    {
        ast::list_of_path_inputs *ret = new ast::list_of_path_inputs;
        $$ = ret;
    }
    ;

list_of_path_outputs 
    : LIST_152 
    {
        ast::list_of_path_outputs *ret = new ast::list_of_path_outputs;
        $$ = ret;
    }
    ;

specify_input_terminal_descriptor 
    : input_identifier OPT_178 
    {
        ast::specify_input_terminal_descriptor *ret = new ast::specify_input_terminal_descriptor;
        $$ = ret;
    }
    ;

specify_output_terminal_descriptor 
    : output_identifier OPT_178 
    {
        ast::specify_output_terminal_descriptor *ret = new ast::specify_output_terminal_descriptor;
        $$ = ret;
    }
    ;

input_identifier 
    : input_port_identifier 
    {
        ast::input_identifier *ret = new ast::input_identifier;
        $$ = ret;
    }
    | inout_port_identifier 
    {
        ast::input_identifier *ret = new ast::input_identifier;
        $$ = ret;
    }
    | interface_identifier DOT port_identifier 
    {
        ast::input_identifier *ret = new ast::input_identifier;
        $$ = ret;
    }
    ;

output_identifier 
    : output_port_identifier 
    {
        ast::output_identifier *ret = new ast::output_identifier;
        $$ = ret;
    }
    | inout_port_identifier 
    {
        ast::output_identifier *ret = new ast::output_identifier;
        $$ = ret;
    }
    | interface_identifier DOT port_identifier 
    {
        ast::output_identifier *ret = new ast::output_identifier;
        $$ = ret;
    }
    ;

path_delay_value 
    : list_of_path_delay_expressions 
    {
        ast::path_delay_value *ret = new ast::path_delay_value;
        $$ = ret;
    }
    | LP list_of_path_delay_expressions RP 
    {
        ast::path_delay_value *ret = new ast::path_delay_value;
        $$ = ret;
    }
    ;

list_of_path_delay_expressions 
    : t_path_delay_expression 
    {
        ast::list_of_path_delay_expressions *ret = new ast::list_of_path_delay_expressions;
        $$ = ret;
    }
    | trise_path_delay_expression COMMA tfall_path_delay_expression 
    {
        ast::list_of_path_delay_expressions *ret = new ast::list_of_path_delay_expressions;
        $$ = ret;
    }
    | trise_path_delay_expression COMMA tfall_path_delay_expression COMMA tz_path_delay_expression 
    {
        ast::list_of_path_delay_expressions *ret = new ast::list_of_path_delay_expressions;
        $$ = ret;
    }
    | t01_path_delay_expression COMMA t10_path_delay_expression COMMA t0z_path_delay_expression COMMA tz1_path_delay_expression COMMA t1z_path_delay_expression COMMA tz0_path_delay_expression 
    {
        ast::list_of_path_delay_expressions *ret = new ast::list_of_path_delay_expressions;
        $$ = ret;
    }
    | t01_path_delay_expression COMMA t10_path_delay_expression COMMA t0z_path_delay_expression COMMA tz1_path_delay_expression COMMA t1z_path_delay_expression COMMA tz0_path_delay_expression COMMA t0x_path_delay_expression COMMA tx1_path_delay_expression COMMA t1x_path_delay_expression COMMA tx0_path_delay_expression COMMA txz_path_delay_expression COMMA tzx_path_delay_expression 
    {
        ast::list_of_path_delay_expressions *ret = new ast::list_of_path_delay_expressions;
        $$ = ret;
    }
    ;

t_path_delay_expression 
    : path_delay_expression 
    {
        ast::t_path_delay_expression *ret = new ast::t_path_delay_expression;
        $$ = ret;
    }
    ;

trise_path_delay_expression 
    : path_delay_expression 
    {
        ast::trise_path_delay_expression *ret = new ast::trise_path_delay_expression;
        $$ = ret;
    }
    ;

tfall_path_delay_expression 
    : path_delay_expression 
    {
        ast::tfall_path_delay_expression *ret = new ast::tfall_path_delay_expression;
        $$ = ret;
    }
    ;

tz_path_delay_expression 
    : path_delay_expression 
    {
        ast::tz_path_delay_expression *ret = new ast::tz_path_delay_expression;
        $$ = ret;
    }
    ;

t01_path_delay_expression 
    : path_delay_expression 
    {
        ast::t01_path_delay_expression *ret = new ast::t01_path_delay_expression;
        $$ = ret;
    }
    ;

t10_path_delay_expression 
    : path_delay_expression 
    {
        ast::t10_path_delay_expression *ret = new ast::t10_path_delay_expression;
        $$ = ret;
    }
    ;

t0z_path_delay_expression 
    : path_delay_expression 
    {
        ast::t0z_path_delay_expression *ret = new ast::t0z_path_delay_expression;
        $$ = ret;
    }
    ;

tz1_path_delay_expression 
    : path_delay_expression 
    {
        ast::tz1_path_delay_expression *ret = new ast::tz1_path_delay_expression;
        $$ = ret;
    }
    ;

t1z_path_delay_expression 
    : path_delay_expression 
    {
        ast::t1z_path_delay_expression *ret = new ast::t1z_path_delay_expression;
        $$ = ret;
    }
    ;

tz0_path_delay_expression 
    : path_delay_expression 
    {
        ast::tz0_path_delay_expression *ret = new ast::tz0_path_delay_expression;
        $$ = ret;
    }
    ;

t0x_path_delay_expression 
    : path_delay_expression 
    {
        ast::t0x_path_delay_expression *ret = new ast::t0x_path_delay_expression;
        $$ = ret;
    }
    ;

tx1_path_delay_expression 
    : path_delay_expression 
    {
        ast::tx1_path_delay_expression *ret = new ast::tx1_path_delay_expression;
        $$ = ret;
    }
    ;

t1x_path_delay_expression 
    : path_delay_expression 
    {
        ast::t1x_path_delay_expression *ret = new ast::t1x_path_delay_expression;
        $$ = ret;
    }
    ;

tx0_path_delay_expression 
    : path_delay_expression 
    {
        ast::tx0_path_delay_expression *ret = new ast::tx0_path_delay_expression;
        $$ = ret;
    }
    ;

txz_path_delay_expression 
    : path_delay_expression 
    {
        ast::txz_path_delay_expression *ret = new ast::txz_path_delay_expression;
        $$ = ret;
    }
    ;

tzx_path_delay_expression 
    : path_delay_expression 
    {
        ast::tzx_path_delay_expression *ret = new ast::tzx_path_delay_expression;
        $$ = ret;
    }
    ;

path_delay_expression 
    : constant_mintypmax_expression 
    {
        ast::path_delay_expression *ret = new ast::path_delay_expression;
        $$ = ret;
    }
    ;

edge_sensitive_path_declaration 
    : parallel_edge_sensitive_path_description EQ path_delay_value 
    {
        ast::edge_sensitive_path_declaration *ret = new ast::edge_sensitive_path_declaration;
        $$ = ret;
    }
    | full_edge_sensitive_path_description EQ path_delay_value 
    {
        ast::edge_sensitive_path_declaration *ret = new ast::edge_sensitive_path_declaration;
        $$ = ret;
    }
    ;

parallel_edge_sensitive_path_description 
    : LP OPT_156 specify_input_terminal_descriptor OPT_177 EQ_GT LP specify_output_terminal_descriptor OPT_177 COLON data_source_expression RP RP 
    {
        ast::parallel_edge_sensitive_path_description *ret = new ast::parallel_edge_sensitive_path_description;
        $$ = ret;
    }
    ;

full_edge_sensitive_path_description 
    : LP OPT_156 list_of_path_inputs OPT_177 STAR_RT LP list_of_path_outputs OPT_177 COLON data_source_expression RP RP 
    {
        ast::full_edge_sensitive_path_description *ret = new ast::full_edge_sensitive_path_description;
        $$ = ret;
    }
    ;

data_source_expression 
    : expression 
    {
        ast::data_source_expression *ret = new ast::data_source_expression;
        $$ = ret;
    }
    ;

edge_identifier 
    : POSEDGE_ 
    {
        ast::edge_identifier *ret = new ast::edge_identifier;
        $$ = ret;
    }
    | NEGEDGE_ 
    {
        ast::edge_identifier *ret = new ast::edge_identifier;
        $$ = ret;
    }
    | EDGE_ 
    {
        ast::edge_identifier *ret = new ast::edge_identifier;
        $$ = ret;
    }
    ;

state_dependent_path_declaration 
    : IF_ LP module_path_expression RP simple_path_declaration 
    {
        ast::state_dependent_path_declaration *ret = new ast::state_dependent_path_declaration;
        $$ = ret;
    }
    | IF_ LP module_path_expression RP edge_sensitive_path_declaration 
    {
        ast::state_dependent_path_declaration *ret = new ast::state_dependent_path_declaration;
        $$ = ret;
    }
    | IFNONE_ simple_path_declaration 
    {
        ast::state_dependent_path_declaration *ret = new ast::state_dependent_path_declaration;
        $$ = ret;
    }
    ;

polarity_operator 
    : PLUS 
    {
        ast::polarity_operator *ret = new ast::polarity_operator;
        $$ = ret;
    }
    | MINUS 
    {
        ast::polarity_operator *ret = new ast::polarity_operator;
        $$ = ret;
    }
    ;

system_timing_check 
    : dollarsign_setup_timing_check 
    {
        ast::system_timing_check *ret = new ast::system_timing_check;
        $$ = ret;
    }
    | dollarsign_hold_timing_check 
    {
        ast::system_timing_check *ret = new ast::system_timing_check;
        $$ = ret;
    }
    | dollarsign_setuphold_timing_check 
    {
        ast::system_timing_check *ret = new ast::system_timing_check;
        $$ = ret;
    }
    | dollarsign_recovery_timing_check 
    {
        ast::system_timing_check *ret = new ast::system_timing_check;
        $$ = ret;
    }
    | dollarsign_removal_timing_check 
    {
        ast::system_timing_check *ret = new ast::system_timing_check;
        $$ = ret;
    }
    | dollarsign_recrem_timing_check 
    {
        ast::system_timing_check *ret = new ast::system_timing_check;
        $$ = ret;
    }
    | dollarsign_skew_timing_check 
    {
        ast::system_timing_check *ret = new ast::system_timing_check;
        $$ = ret;
    }
    | dollarsign_timeskew_timing_check 
    {
        ast::system_timing_check *ret = new ast::system_timing_check;
        $$ = ret;
    }
    | dollarsign_fullskew_timing_check 
    {
        ast::system_timing_check *ret = new ast::system_timing_check;
        $$ = ret;
    }
    | dollarsign_period_timing_check 
    {
        ast::system_timing_check *ret = new ast::system_timing_check;
        $$ = ret;
    }
    | dollarsign_width_timing_check 
    {
        ast::system_timing_check *ret = new ast::system_timing_check;
        $$ = ret;
    }
    | dollarsign_nochange_timing_check 
    {
        ast::system_timing_check *ret = new ast::system_timing_check;
        $$ = ret;
    }
    ;

dollarsign_setup_timing_check 
    : DOLLAR_SETUP_ LP data_event COMMA reference_event COMMA timing_check_limit OPT_180 RP SEMICOLON 
    {
        ast::dollarsign_setup_timing_check *ret = new ast::dollarsign_setup_timing_check;
        $$ = ret;
    }
    ;

dollarsign_hold_timing_check 
    : DOLLAR_HOLD_ LP reference_event COMMA data_event COMMA timing_check_limit OPT_180 RP SEMICOLON 
    {
        ast::dollarsign_hold_timing_check *ret = new ast::dollarsign_hold_timing_check;
        $$ = ret;
    }
    ;

dollarsign_setuphold_timing_check 
    : DOLLAR_SETUPHOLD_ LP reference_event COMMA data_event COMMA timing_check_limit COMMA timing_check_limit OPT_189 RP SEMICOLON 
    {
        ast::dollarsign_setuphold_timing_check *ret = new ast::dollarsign_setuphold_timing_check;
        $$ = ret;
    }
    ;

dollarsign_recovery_timing_check 
    : DOLLAR_RECOVERY_ LP reference_event COMMA data_event COMMA timing_check_limit OPT_180 RP SEMICOLON 
    {
        ast::dollarsign_recovery_timing_check *ret = new ast::dollarsign_recovery_timing_check;
        $$ = ret;
    }
    ;

dollarsign_removal_timing_check 
    : DOLLAR_REMOVAL_ LP reference_event COMMA data_event COMMA timing_check_limit OPT_180 RP SEMICOLON 
    {
        ast::dollarsign_removal_timing_check *ret = new ast::dollarsign_removal_timing_check;
        $$ = ret;
    }
    ;

dollarsign_recrem_timing_check 
    : DOLLAR_RECREM_ LP reference_event COMMA data_event COMMA RP SEMICOLON 
    {
        ast::dollarsign_recrem_timing_check *ret = new ast::dollarsign_recrem_timing_check;
        $$ = ret;
    }
    ;

dollarsign_skew_timing_check 
    : DOLLAR_SKEW_ LP reference_event COMMA data_event COMMA timing_check_limit OPT_180 RP SEMICOLON 
    {
        ast::dollarsign_skew_timing_check *ret = new ast::dollarsign_skew_timing_check;
        $$ = ret;
    }
    ;

dollarsign_timeskew_timing_check 
    : DOLLAR_TIMESKEW_ LP reference_event COMMA data_event COMMA timing_check_limit OPT_194 RP SEMICOLON 
    {
        ast::dollarsign_timeskew_timing_check *ret = new ast::dollarsign_timeskew_timing_check;
        $$ = ret;
    }
    ;

dollarsign_fullskew_timing_check 
    : DOLLAR_FULLSKEW_ LP reference_event COMMA data_event COMMA timing_check_limit COMMA timing_check_limit OPT_194 RP SEMICOLON 
    {
        ast::dollarsign_fullskew_timing_check *ret = new ast::dollarsign_fullskew_timing_check;
        $$ = ret;
    }
    ;

dollarsign_period_timing_check 
    : DOLLAR_PERIOD_ LP RP SEMICOLON 
    {
        ast::dollarsign_period_timing_check *ret = new ast::dollarsign_period_timing_check;
        $$ = ret;
    }
    ;

dollarsign_width_timing_check 
    : DOLLAR_WIDTH_ LP controlled_reference_event COMMA timing_check_limit COMMA threshold OPT_180 RP SEMICOLON 
    {
        ast::dollarsign_width_timing_check *ret = new ast::dollarsign_width_timing_check;
        $$ = ret;
    }
    ;

dollarsign_nochange_timing_check 
    : DOLLAR_NOCHANGE_ LP reference_event COMMA data_event COMMA start_edge_offset COMMA end_edge_offset OPT_180 RP SEMICOLON 
    {
        ast::dollarsign_nochange_timing_check *ret = new ast::dollarsign_nochange_timing_check;
        $$ = ret;
    }
    ;

timecheck_condition 
    : mintypmax_expression 
    {
        ast::timecheck_condition *ret = new ast::timecheck_condition;
        $$ = ret;
    }
    ;

controlled_reference_event 
    : controlled_timing_check_event 
    {
        ast::controlled_reference_event *ret = new ast::controlled_reference_event;
        $$ = ret;
    }
    ;

data_event 
    : timing_check_event 
    {
        ast::data_event *ret = new ast::data_event;
        $$ = ret;
    }
    ;

delayed_data 
    : terminal_identifier 
    {
        ast::delayed_data *ret = new ast::delayed_data;
        $$ = ret;
    }
    | terminal_identifier LSP constant_mintypmax_expression RSP 
    {
        ast::delayed_data *ret = new ast::delayed_data;
        $$ = ret;
    }
    ;

delayed_reference 
    : terminal_identifier 
    {
        ast::delayed_reference *ret = new ast::delayed_reference;
        $$ = ret;
    }
    | terminal_identifier LSP constant_mintypmax_expression RSP 
    {
        ast::delayed_reference *ret = new ast::delayed_reference;
        $$ = ret;
    }
    ;

end_edge_offset 
    : mintypmax_expression 
    {
        ast::end_edge_offset *ret = new ast::end_edge_offset;
        $$ = ret;
    }
    ;

event_based_flag 
    : constant_expression 
    {
        ast::event_based_flag *ret = new ast::event_based_flag;
        $$ = ret;
    }
    ;

notifier 
    : variable_identifier 
    {
        ast::notifier *ret = new ast::notifier;
        $$ = ret;
    }
    ;

reference_event 
    : timing_check_event 
    {
        ast::reference_event *ret = new ast::reference_event;
        $$ = ret;
    }
    ;

remain_active_flag 
    : constant_mintypmax_expression 
    {
        ast::remain_active_flag *ret = new ast::remain_active_flag;
        $$ = ret;
    }
    ;

timestamp_condition 
    : mintypmax_expression 
    {
        ast::timestamp_condition *ret = new ast::timestamp_condition;
        $$ = ret;
    }
    ;

start_edge_offset 
    : mintypmax_expression 
    {
        ast::start_edge_offset *ret = new ast::start_edge_offset;
        $$ = ret;
    }
    ;

threshold 
    : constant_expression 
    {
        ast::threshold *ret = new ast::threshold;
        $$ = ret;
    }
    ;

timing_check_limit 
    : expression 
    {
        ast::timing_check_limit *ret = new ast::timing_check_limit;
        $$ = ret;
    }
    ;

timing_check_event 
    : OPT_195 specify_terminal_descriptor OPT_196 
    {
        ast::timing_check_event *ret = new ast::timing_check_event;
        $$ = ret;
    }
    ;

controlled_timing_check_event 
    : timing_check_event_control specify_terminal_descriptor OPT_196 
    {
        ast::controlled_timing_check_event *ret = new ast::controlled_timing_check_event;
        $$ = ret;
    }
    ;

timing_check_event_control 
    : POSEDGE_ 
    {
        ast::timing_check_event_control *ret = new ast::timing_check_event_control;
        $$ = ret;
    }
    | NEGEDGE_ 
    {
        ast::timing_check_event_control *ret = new ast::timing_check_event_control;
        $$ = ret;
    }
    | EDGE_ 
    {
        ast::timing_check_event_control *ret = new ast::timing_check_event_control;
        $$ = ret;
    }
    | edge_control_specifier 
    {
        ast::timing_check_event_control *ret = new ast::timing_check_event_control;
        $$ = ret;
    }
    ;

specify_terminal_descriptor 
    : specify_input_terminal_descriptor 
    {
        ast::specify_terminal_descriptor *ret = new ast::specify_terminal_descriptor;
        $$ = ret;
    }
    | specify_output_terminal_descriptor 
    {
        ast::specify_terminal_descriptor *ret = new ast::specify_terminal_descriptor;
        $$ = ret;
    }
    ;

edge_control_specifier 
    : EDGE_ LSP LIST_153 RSP 
    {
        ast::edge_control_specifier *ret = new ast::edge_control_specifier;
        $$ = ret;
    }
    ;

edge_descriptor 
    : ZERO_ONE 
    {
        ast::edge_descriptor *ret = new ast::edge_descriptor;
        $$ = ret;
    }
    | ONE_ZERO 
    {
        ast::edge_descriptor *ret = new ast::edge_descriptor;
        $$ = ret;
    }
    | z_or_x zero_or_one 
    {
        ast::edge_descriptor *ret = new ast::edge_descriptor;
        $$ = ret;
    }
    | zero_or_one z_or_x 
    {
        ast::edge_descriptor *ret = new ast::edge_descriptor;
        $$ = ret;
    }
    ;

zero_or_one 
    : ZERO_ 
    {
        ast::zero_or_one *ret = new ast::zero_or_one;
        $$ = ret;
    }
    | ONE_ 
    {
        ast::zero_or_one *ret = new ast::zero_or_one;
        $$ = ret;
    }
    ;

z_or_x 
    : LETTER_Z0_ 
    {
        ast::z_or_x *ret = new ast::z_or_x;
        $$ = ret;
    }
    | LETTER_Z1_ 
    {
        ast::z_or_x *ret = new ast::z_or_x;
        $$ = ret;
    }
    | LETTER_X0_ 
    {
        ast::z_or_x *ret = new ast::z_or_x;
        $$ = ret;
    }
    | LETTER_X1_ 
    {
        ast::z_or_x *ret = new ast::z_or_x;
        $$ = ret;
    }
    ;

timing_check_condition 
    : scalar_timing_check_condition 
    {
        ast::timing_check_condition *ret = new ast::timing_check_condition;
        $$ = ret;
    }
    | LP scalar_timing_check_condition RP 
    {
        ast::timing_check_condition *ret = new ast::timing_check_condition;
        $$ = ret;
    }
    ;

scalar_timing_check_condition 
    : expression 
    {
        ast::scalar_timing_check_condition *ret = new ast::scalar_timing_check_condition;
        $$ = ret;
    }
    | WAVE expression 
    {
        ast::scalar_timing_check_condition *ret = new ast::scalar_timing_check_condition;
        $$ = ret;
    }
    | expression EQ2 scalar_constant 
    {
        ast::scalar_timing_check_condition *ret = new ast::scalar_timing_check_condition;
        $$ = ret;
    }
    | expression EQ3 scalar_constant 
    {
        ast::scalar_timing_check_condition *ret = new ast::scalar_timing_check_condition;
        $$ = ret;
    }
    | expression NEQ scalar_constant 
    {
        ast::scalar_timing_check_condition *ret = new ast::scalar_timing_check_condition;
        $$ = ret;
    }
    | expression NEQ2 scalar_constant 
    {
        ast::scalar_timing_check_condition *ret = new ast::scalar_timing_check_condition;
        $$ = ret;
    }
    ;

scalar_constant 
    : ONEBIT_GND 
    {
        ast::scalar_constant *ret = new ast::scalar_constant;
        $$ = ret;
    }
    | ONEBIT_VDD 
    {
        ast::scalar_constant *ret = new ast::scalar_constant;
        $$ = ret;
    }
    | ONEBIT_BGND 
    {
        ast::scalar_constant *ret = new ast::scalar_constant;
        $$ = ret;
    }
    | ONEBIT_BVDD 
    {
        ast::scalar_constant *ret = new ast::scalar_constant;
        $$ = ret;
    }
    | APOSTROPHE_B0_GND 
    {
        ast::scalar_constant *ret = new ast::scalar_constant;
        $$ = ret;
    }
    | APOSTROPHE_B0_VDD 
    {
        ast::scalar_constant *ret = new ast::scalar_constant;
        $$ = ret;
    }
    | APOSTROPHE_B1_GND 
    {
        ast::scalar_constant *ret = new ast::scalar_constant;
        $$ = ret;
    }
    | APOSTROPHE_B1_VDD 
    {
        ast::scalar_constant *ret = new ast::scalar_constant;
        $$ = ret;
    }
    | ONE_ 
    {
        ast::scalar_constant *ret = new ast::scalar_constant;
        $$ = ret;
    }
    | ZERO_ 
    {
        ast::scalar_constant *ret = new ast::scalar_constant;
        $$ = ret;
    }
    ;

concatenation 
    : LMP LIST_133 RMP 
    {
        ast::concatenation *ret = new ast::concatenation;
        $$ = ret;
    }
    ;

constant_concatenation 
    : LMP LIST_110 RMP 
    {
        ast::constant_concatenation *ret = new ast::constant_concatenation;
        $$ = ret;
    }
    ;

constant_multiple_concatenation 
    : LMP constant_expression constant_concatenation RMP 
    {
        ast::constant_multiple_concatenation *ret = new ast::constant_multiple_concatenation;
        $$ = ret;
    }
    ;

module_path_concatenation 
    : LMP LIST_154 RMP 
    {
        ast::module_path_concatenation *ret = new ast::module_path_concatenation;
        $$ = ret;
    }
    ;

module_path_multiple_concatenation 
    : LMP constant_expression module_path_concatenation RMP 
    {
        ast::module_path_multiple_concatenation *ret = new ast::module_path_multiple_concatenation;
        $$ = ret;
    }
    ;

multiple_concatenation 
    : LMP expression concatenation RMP 
    {
        ast::multiple_concatenation *ret = new ast::multiple_concatenation;
        $$ = ret;
    }
    ;

streaming_concatenation 
    : LMP stream_operator OPT_197 stream_concatenation RMP 
    {
        ast::streaming_concatenation *ret = new ast::streaming_concatenation;
        $$ = ret;
    }
    ;

stream_operator 
    : RSHIFT 
    {
        ast::stream_operator *ret = new ast::stream_operator;
        $$ = ret;
    }
    | LSHIFT 
    {
        ast::stream_operator *ret = new ast::stream_operator;
        $$ = ret;
    }
    ;

slice_size 
    : simple_type 
    {
        ast::slice_size *ret = new ast::slice_size;
        $$ = ret;
    }
    | constant_expression 
    {
        ast::slice_size *ret = new ast::slice_size;
        $$ = ret;
    }
    ;

stream_concatenation 
    : LMP LIST_155 RMP 
    {
        ast::stream_concatenation *ret = new ast::stream_concatenation;
        $$ = ret;
    }
    ;

stream_expression 
    : expression OPT_198 
    {
        ast::stream_expression *ret = new ast::stream_expression;
        $$ = ret;
    }
    ;

array_range_expression 
    : expression 
    {
        ast::array_range_expression *ret = new ast::array_range_expression;
        $$ = ret;
    }
    | expression COLON expression 
    {
        ast::array_range_expression *ret = new ast::array_range_expression;
        $$ = ret;
    }
    | expression PLUS_COLON expression 
    {
        ast::array_range_expression *ret = new ast::array_range_expression;
        $$ = ret;
    }
    | expression MINUS_COLON expression 
    {
        ast::array_range_expression *ret = new ast::array_range_expression;
        $$ = ret;
    }
    ;

empty_queue 
    : LMP RMP 
    {
        ast::empty_queue *ret = new ast::empty_queue;
        $$ = ret;
    }
    ;

constant_function_call 
    : function_subroutine_call 
    {
        ast::constant_function_call *ret = new ast::constant_function_call;
        $$ = ret;
    }
    ;

tf_call 
    : ps_or_hierarchical_tf_identifier STAR_2 OPT_12 
    {
        ast::tf_call *ret = new ast::tf_call;
        $$ = ret;
    }
    ;

system_tf_call 
    : system_tf_identifier OPT_12 
    {
        ast::system_tf_call *ret = new ast::system_tf_call;
        $$ = ret;
    }
    ;

subroutine_call 
    : tf_call 
    {
        ast::subroutine_call *ret = new ast::subroutine_call;
        $$ = ret;
    }
    | system_tf_call 
    {
        ast::subroutine_call *ret = new ast::subroutine_call;
        $$ = ret;
    }
    | method_call 
    {
        ast::subroutine_call *ret = new ast::subroutine_call;
        $$ = ret;
    }
    | OPT_199 randomize_call 
    {
        ast::subroutine_call *ret = new ast::subroutine_call;
        $$ = ret;
    }
    ;

function_subroutine_call 
    : subroutine_call 
    {
        ast::function_subroutine_call *ret = new ast::function_subroutine_call;
        $$ = ret;
    }
    ;

list_of_arguments 
    : LIST_156 STAR_48 
    {
        ast::list_of_arguments *ret = new ast::list_of_arguments;
        $$ = ret;
    }
    | DOT identifier LP OPT_26 RP STAR_48 
    {
        ast::list_of_arguments *ret = new ast::list_of_arguments;
        $$ = ret;
    }
    ;

method_call 
    : method_call_root DOT method_call_body 
    {
        ast::method_call *ret = new ast::method_call;
        $$ = ret;
    }
    ;

method_call_body 
    : method_identifier STAR_2 OPT_12 
    {
        ast::method_call_body *ret = new ast::method_call_body;
        $$ = ret;
    }
    | built_in_method_call 
    {
        ast::method_call_body *ret = new ast::method_call_body;
        $$ = ret;
    }
    ;

built_in_method_call 
    : array_manipulation_call 
    {
        ast::built_in_method_call *ret = new ast::built_in_method_call;
        $$ = ret;
    }
    | randomize_call 
    {
        ast::built_in_method_call *ret = new ast::built_in_method_call;
        $$ = ret;
    }
    ;

array_manipulation_call 
    : array_method_name STAR_2 OPT_12 OPT_200 
    {
        ast::array_manipulation_call *ret = new ast::array_manipulation_call;
        $$ = ret;
    }
    ;

randomize_call 
    : RANDOMIZE_ STAR_2 OPT_202 OPT_204 
    {
        ast::randomize_call *ret = new ast::randomize_call;
        $$ = ret;
    }
    ;

method_call_root 
    : primary 
    {
        ast::method_call_root *ret = new ast::method_call_root;
        $$ = ret;
    }
    | implicit_class_handle 
    {
        ast::method_call_root *ret = new ast::method_call_root;
        $$ = ret;
    }
    ;

array_method_name 
    : method_identifier 
    {
        ast::array_method_name *ret = new ast::array_method_name;
        $$ = ret;
    }
    | UNIQUE_ 
    {
        ast::array_method_name *ret = new ast::array_method_name;
        $$ = ret;
    }
    | AND_ 
    {
        ast::array_method_name *ret = new ast::array_method_name;
        $$ = ret;
    }
    | OR_ 
    {
        ast::array_method_name *ret = new ast::array_method_name;
        $$ = ret;
    }
    | XOR_ 
    {
        ast::array_method_name *ret = new ast::array_method_name;
        $$ = ret;
    }
    ;

inc_or_dec_expression 
    : inc_or_dec_operator STAR_2 variable_lvalue 
    {
        ast::inc_or_dec_expression *ret = new ast::inc_or_dec_expression;
        $$ = ret;
    }
    | variable_lvalue STAR_2 inc_or_dec_operator 
    {
        ast::inc_or_dec_expression *ret = new ast::inc_or_dec_expression;
        $$ = ret;
    }
    ;

conditional_expression 
    : cond_predicate QMARK STAR_2 expression COLON expression 
    {
        ast::conditional_expression *ret = new ast::conditional_expression;
        $$ = ret;
    }
    ;

constant_expression 
    : constant_primary 
    {
        ast::constant_expression *ret = new ast::constant_expression;
        $$ = ret;
    }
    | unary_operator STAR_2 constant_primary 
    {
        ast::constant_expression *ret = new ast::constant_expression;
        $$ = ret;
    }
    | constant_expression binary_operator STAR_2 constant_expression 
    {
        ast::constant_expression *ret = new ast::constant_expression;
        $$ = ret;
    }
    | constant_expression QMARK STAR_2 constant_expression COLON constant_expression 
    {
        ast::constant_expression *ret = new ast::constant_expression;
        $$ = ret;
    }
    ;

constant_mintypmax_expression 
    : constant_expression 
    {
        ast::constant_mintypmax_expression *ret = new ast::constant_mintypmax_expression;
        $$ = ret;
    }
    | constant_expression COLON constant_expression COLON constant_expression 
    {
        ast::constant_mintypmax_expression *ret = new ast::constant_mintypmax_expression;
        $$ = ret;
    }
    ;

constant_param_expression 
    : constant_mintypmax_expression 
    {
        ast::constant_param_expression *ret = new ast::constant_param_expression;
        $$ = ret;
    }
    | data_type 
    {
        ast::constant_param_expression *ret = new ast::constant_param_expression;
        $$ = ret;
    }
    | DOLLAR_ 
    {
        ast::constant_param_expression *ret = new ast::constant_param_expression;
        $$ = ret;
    }
    ;

param_expression 
    : mintypmax_expression 
    {
        ast::param_expression *ret = new ast::param_expression;
        $$ = ret;
    }
    | data_type 
    {
        ast::param_expression *ret = new ast::param_expression;
        $$ = ret;
    }
    | DOLLAR_ 
    {
        ast::param_expression *ret = new ast::param_expression;
        $$ = ret;
    }
    ;

constant_range_expression 
    : constant_expression 
    {
        ast::constant_range_expression *ret = new ast::constant_range_expression;
        $$ = ret;
    }
    | constant_part_select_range 
    {
        ast::constant_range_expression *ret = new ast::constant_range_expression;
        $$ = ret;
    }
    ;

constant_part_select_range 
    : constant_range 
    {
        ast::constant_part_select_range *ret = new ast::constant_part_select_range;
        $$ = ret;
    }
    | constant_indexed_range 
    {
        ast::constant_part_select_range *ret = new ast::constant_part_select_range;
        $$ = ret;
    }
    ;

constant_range 
    : constant_expression COLON constant_expression 
    {
        ast::constant_range *ret = new ast::constant_range;
        $$ = ret;
    }
    ;

constant_indexed_range 
    : constant_expression PLUS_COLON constant_expression 
    {
        ast::constant_indexed_range *ret = new ast::constant_indexed_range;
        $$ = ret;
    }
    | constant_expression MINUS_COLON constant_expression 
    {
        ast::constant_indexed_range *ret = new ast::constant_indexed_range;
        $$ = ret;
    }
    ;

expression 
    : primary 
    {
        ast::expression *ret = new ast::expression;
        $$ = ret;
    }
    | unary_operator STAR_2 primary 
    {
        ast::expression *ret = new ast::expression;
        $$ = ret;
    }
    | inc_or_dec_expression 
    {
        ast::expression *ret = new ast::expression;
        $$ = ret;
    }
    | LP operator_assignment RP 
    {
        ast::expression *ret = new ast::expression;
        $$ = ret;
    }
    | expression binary_operator STAR_2 expression 
    {
        ast::expression *ret = new ast::expression;
        $$ = ret;
    }
    | conditional_expression 
    {
        ast::expression *ret = new ast::expression;
        $$ = ret;
    }
    | inside_expression 
    {
        ast::expression *ret = new ast::expression;
        $$ = ret;
    }
    | tagged_union_expression 
    {
        ast::expression *ret = new ast::expression;
        $$ = ret;
    }
    ;

tagged_union_expression 
    : TAGGED_ member_identifier OPT_26 
    {
        ast::tagged_union_expression *ret = new ast::tagged_union_expression;
        $$ = ret;
    }
    ;

inside_expression 
    : expression INSIDE_ LMP open_range_list RMP 
    {
        ast::inside_expression *ret = new ast::inside_expression;
        $$ = ret;
    }
    ;

value_range 
    : expression 
    {
        ast::value_range *ret = new ast::value_range;
        $$ = ret;
    }
    | LSP expression COLON expression RSP 
    {
        ast::value_range *ret = new ast::value_range;
        $$ = ret;
    }
    ;

mintypmax_expression 
    : expression 
    {
        ast::mintypmax_expression *ret = new ast::mintypmax_expression;
        $$ = ret;
    }
    | expression COLON expression COLON expression 
    {
        ast::mintypmax_expression *ret = new ast::mintypmax_expression;
        $$ = ret;
    }
    ;

module_path_conditional_expression 
    : module_path_expression QMARK STAR_2 module_path_expression COLON module_path_expression 
    {
        ast::module_path_conditional_expression *ret = new ast::module_path_conditional_expression;
        $$ = ret;
    }
    ;

module_path_expression 
    : module_path_primary 
    {
        ast::module_path_expression *ret = new ast::module_path_expression;
        $$ = ret;
    }
    | unary_module_path_operator STAR_2 module_path_primary 
    {
        ast::module_path_expression *ret = new ast::module_path_expression;
        $$ = ret;
    }
    | module_path_expression binary_module_path_operator STAR_2 module_path_conditional_expression 
    {
        ast::module_path_expression *ret = new ast::module_path_expression;
        $$ = ret;
    }
    ;

module_path_mintypmax_expression 
    : module_path_expression 
    {
        ast::module_path_mintypmax_expression *ret = new ast::module_path_mintypmax_expression;
        $$ = ret;
    }
    | module_path_expression COLON module_path_expression COLON module_path_expression 
    {
        ast::module_path_mintypmax_expression *ret = new ast::module_path_mintypmax_expression;
        $$ = ret;
    }
    ;

part_select_range 
    : constant_range 
    {
        ast::part_select_range *ret = new ast::part_select_range;
        $$ = ret;
    }
    | indexed_range 
    {
        ast::part_select_range *ret = new ast::part_select_range;
        $$ = ret;
    }
    ;

indexed_range 
    : expression PLUS_COLON constant_expression 
    {
        ast::indexed_range *ret = new ast::indexed_range;
        $$ = ret;
    }
    | expression MINUS_COLON constant_expression 
    {
        ast::indexed_range *ret = new ast::indexed_range;
        $$ = ret;
    }
    ;

genvar_expression 
    : constant_expression 
    {
        ast::genvar_expression *ret = new ast::genvar_expression;
        $$ = ret;
    }
    ;

constant_primary 
    : primary_literal 
    {
        ast::constant_primary *ret = new ast::constant_primary;
        $$ = ret;
    }
    | ps_parameter_identifier constant_select 
    {
        ast::constant_primary *ret = new ast::constant_primary;
        $$ = ret;
    }
    | specparam_identifier OPT_178 
    {
        ast::constant_primary *ret = new ast::constant_primary;
        $$ = ret;
    }
    | genvar_identifier 
    {
        ast::constant_primary *ret = new ast::constant_primary;
        $$ = ret;
    }
    | formal_port_identifier constant_select 
    {
        ast::constant_primary *ret = new ast::constant_primary;
        $$ = ret;
    }
    | OPT_59 enum_identifier 
    {
        ast::constant_primary *ret = new ast::constant_primary;
        $$ = ret;
    }
    | constant_concatenation OPT_178 
    {
        ast::constant_primary *ret = new ast::constant_primary;
        $$ = ret;
    }
    | constant_multiple_concatenation OPT_178 
    {
        ast::constant_primary *ret = new ast::constant_primary;
        $$ = ret;
    }
    | constant_function_call 
    {
        ast::constant_primary *ret = new ast::constant_primary;
        $$ = ret;
    }
    | constant_let_expression 
    {
        ast::constant_primary *ret = new ast::constant_primary;
        $$ = ret;
    }
    | LP constant_mintypmax_expression RP 
    {
        ast::constant_primary *ret = new ast::constant_primary;
        $$ = ret;
    }
    | constant_cast 
    {
        ast::constant_primary *ret = new ast::constant_primary;
        $$ = ret;
    }
    | constant_assignment_pattern_expression 
    {
        ast::constant_primary *ret = new ast::constant_primary;
        $$ = ret;
    }
    | type_reference 
    {
        ast::constant_primary *ret = new ast::constant_primary;
        $$ = ret;
    }
    ;

module_path_primary 
    : number 
    {
        ast::module_path_primary *ret = new ast::module_path_primary;
        $$ = ret;
    }
    | identifier 
    {
        ast::module_path_primary *ret = new ast::module_path_primary;
        $$ = ret;
    }
    | module_path_concatenation 
    {
        ast::module_path_primary *ret = new ast::module_path_primary;
        $$ = ret;
    }
    | module_path_multiple_concatenation 
    {
        ast::module_path_primary *ret = new ast::module_path_primary;
        $$ = ret;
    }
    | function_subroutine_call 
    {
        ast::module_path_primary *ret = new ast::module_path_primary;
        $$ = ret;
    }
    | LP module_path_mintypmax_expression RP 
    {
        ast::module_path_primary *ret = new ast::module_path_primary;
        $$ = ret;
    }
    ;

primary 
    : primary_literal 
    {
        ast::primary *ret = new ast::primary;
        $$ = ret;
    }
    | OPT_205 hierarchical_identifier select 
    {
        ast::primary *ret = new ast::primary;
        $$ = ret;
    }
    | empty_queue 
    {
        ast::primary *ret = new ast::primary;
        $$ = ret;
    }
    | concatenation OPT_206 
    {
        ast::primary *ret = new ast::primary;
        $$ = ret;
    }
    | multiple_concatenation OPT_206 
    {
        ast::primary *ret = new ast::primary;
        $$ = ret;
    }
    | function_subroutine_call 
    {
        ast::primary *ret = new ast::primary;
        $$ = ret;
    }
    | let_expression 
    {
        ast::primary *ret = new ast::primary;
        $$ = ret;
    }
    | LP mintypmax_expression RP 
    {
        ast::primary *ret = new ast::primary;
        $$ = ret;
    }
    | cast 
    {
        ast::primary *ret = new ast::primary;
        $$ = ret;
    }
    | assignment_pattern_expression 
    {
        ast::primary *ret = new ast::primary;
        $$ = ret;
    }
    | streaming_concatenation 
    {
        ast::primary *ret = new ast::primary;
        $$ = ret;
    }
    | sequence_method_call 
    {
        ast::primary *ret = new ast::primary;
        $$ = ret;
    }
    | THIS_ 
    {
        ast::primary *ret = new ast::primary;
        $$ = ret;
    }
    | DOLLAR_ 
    {
        ast::primary *ret = new ast::primary;
        $$ = ret;
    }
    | NULL_ 
    {
        ast::primary *ret = new ast::primary;
        $$ = ret;
    }
    ;

class_qualifier 
    : OPT_207 OPT_45 
    {
        ast::class_qualifier *ret = new ast::class_qualifier;
        $$ = ret;
    }
    ;

range_expression 
    : expression 
    {
        ast::range_expression *ret = new ast::range_expression;
        $$ = ret;
    }
    | part_select_range 
    {
        ast::range_expression *ret = new ast::range_expression;
        $$ = ret;
    }
    ;

primary_literal 
    : number 
    {
        ast::primary_literal *ret = new ast::primary_literal;
        $$ = ret;
    }
    | time_literal 
    {
        ast::primary_literal *ret = new ast::primary_literal;
        $$ = ret;
    }
    | unbased_unsized_literal 
    {
        ast::primary_literal *ret = new ast::primary_literal;
        $$ = ret;
    }
    | string_literal 
    {
        ast::primary_literal *ret = new ast::primary_literal;
        $$ = ret;
    }
    ;

time_literal 
    : unsigned_number time_unit 
    {
        ast::time_literal *ret = new ast::time_literal;
        $$ = ret;
    }
    | fixed_point_number time_unit 
    {
        ast::time_literal *ret = new ast::time_literal;
        $$ = ret;
    }
    ;

time_unit 
    : LETTER_S0_ 
    {
        ast::time_unit *ret = new ast::time_unit;
        $$ = ret;
    }
    | MS_ 
    {
        ast::time_unit *ret = new ast::time_unit;
        $$ = ret;
    }
    | US_ 
    {
        ast::time_unit *ret = new ast::time_unit;
        $$ = ret;
    }
    | NS_ 
    {
        ast::time_unit *ret = new ast::time_unit;
        $$ = ret;
    }
    | PS_ 
    {
        ast::time_unit *ret = new ast::time_unit;
        $$ = ret;
    }
    | FS_ 
    {
        ast::time_unit *ret = new ast::time_unit;
        $$ = ret;
    }
    ;

implicit_class_handle 
    : THIS_ 
    {
        ast::implicit_class_handle *ret = new ast::implicit_class_handle;
        $$ = ret;
    }
    | SUPER_ 
    {
        ast::implicit_class_handle *ret = new ast::implicit_class_handle;
        $$ = ret;
    }
    | THIS_ DOT SUPER_ 
    {
        ast::implicit_class_handle *ret = new ast::implicit_class_handle;
        $$ = ret;
    }
    ;

bit_select 
    : STAR_49 
    {
        ast::bit_select *ret = new ast::bit_select;
        $$ = ret;
    }
    ;

select 
    : OPT_208 bit_select OPT_209 
    {
        ast::select *ret = new ast::select;
        $$ = ret;
    }
    ;

nonrange_select 
    : OPT_208 bit_select 
    {
        ast::nonrange_select *ret = new ast::nonrange_select;
        $$ = ret;
    }
    ;

constant_bit_select 
    : STAR_49 
    {
        ast::constant_bit_select *ret = new ast::constant_bit_select;
        $$ = ret;
    }
    ;

constant_select 
    : OPT_210 constant_bit_select OPT_211 
    {
        ast::constant_select *ret = new ast::constant_select;
        $$ = ret;
    }
    ;

constant_cast 
    : casting_type APOSTROPHE LP constant_expression RP 
    {
        ast::constant_cast *ret = new ast::constant_cast;
        $$ = ret;
    }
    ;

constant_let_expression 
    : let_expression 
    {
        ast::constant_let_expression *ret = new ast::constant_let_expression;
        $$ = ret;
    }
    ;

cast 
    : casting_type APOSTROPHE LP expression RP 
    {
        ast::cast *ret = new ast::cast;
        $$ = ret;
    }
    ;

net_lvalue 
    : ps_or_hierarchical_net_identifier constant_select 
    {
        ast::net_lvalue *ret = new ast::net_lvalue;
        $$ = ret;
    }
    | LMP LIST_136 RMP 
    {
        ast::net_lvalue *ret = new ast::net_lvalue;
        $$ = ret;
    }
    | OPT_162 assignment_pattern_net_lvalue 
    {
        ast::net_lvalue *ret = new ast::net_lvalue;
        $$ = ret;
    }
    ;

variable_lvalue 
    : OPT_212 hierarchical_variable_identifier select 
    {
        ast::variable_lvalue *ret = new ast::variable_lvalue;
        $$ = ret;
    }
    | LMP LIST_137 RMP 
    {
        ast::variable_lvalue *ret = new ast::variable_lvalue;
        $$ = ret;
    }
    | OPT_162 assignment_pattern_variable_lvalue 
    {
        ast::variable_lvalue *ret = new ast::variable_lvalue;
        $$ = ret;
    }
    | streaming_concatenation 
    {
        ast::variable_lvalue *ret = new ast::variable_lvalue;
        $$ = ret;
    }
    ;

nonrange_variable_lvalue 
    : OPT_212 hierarchical_variable_identifier nonrange_select 
    {
        ast::nonrange_variable_lvalue *ret = new ast::nonrange_variable_lvalue;
        $$ = ret;
    }
    ;

unary_operator 
    : PLUS 
    {
        ast::unary_operator *ret = new ast::unary_operator;
        $$ = ret;
    }
    | MINUS 
    {
        ast::unary_operator *ret = new ast::unary_operator;
        $$ = ret;
    }
    | NOT 
    {
        ast::unary_operator *ret = new ast::unary_operator;
        $$ = ret;
    }
    | WAVE 
    {
        ast::unary_operator *ret = new ast::unary_operator;
        $$ = ret;
    }
    | AND 
    {
        ast::unary_operator *ret = new ast::unary_operator;
        $$ = ret;
    }
    | WAVE_AND 
    {
        ast::unary_operator *ret = new ast::unary_operator;
        $$ = ret;
    }
    | BAR_ 
    {
        ast::unary_operator *ret = new ast::unary_operator;
        $$ = ret;
    }
    | WAVE_BAR 
    {
        ast::unary_operator *ret = new ast::unary_operator;
        $$ = ret;
    }
    | XOR 
    {
        ast::unary_operator *ret = new ast::unary_operator;
        $$ = ret;
    }
    | WAVE_XOR 
    {
        ast::unary_operator *ret = new ast::unary_operator;
        $$ = ret;
    }
    | XOR_WAVE 
    {
        ast::unary_operator *ret = new ast::unary_operator;
        $$ = ret;
    }
    ;

binary_operator 
    : PLUS 
    {
        ast::binary_operator *ret = new ast::binary_operator;
        $$ = ret;
    }
    | MINUS 
    {
        ast::binary_operator *ret = new ast::binary_operator;
        $$ = ret;
    }
    | STAR 
    {
        ast::binary_operator *ret = new ast::binary_operator;
        $$ = ret;
    }
    | SLASH 
    {
        ast::binary_operator *ret = new ast::binary_operator;
        $$ = ret;
    }
    | PERCENT 
    {
        ast::binary_operator *ret = new ast::binary_operator;
        $$ = ret;
    }
    | EQ2 
    {
        ast::binary_operator *ret = new ast::binary_operator;
        $$ = ret;
    }
    | NEQ 
    {
        ast::binary_operator *ret = new ast::binary_operator;
        $$ = ret;
    }
    | EQ3 
    {
        ast::binary_operator *ret = new ast::binary_operator;
        $$ = ret;
    }
    | NEQ2 
    {
        ast::binary_operator *ret = new ast::binary_operator;
        $$ = ret;
    }
    | EQ2_QMARK 
    {
        ast::binary_operator *ret = new ast::binary_operator;
        $$ = ret;
    }
    | NEQ_QMARK 
    {
        ast::binary_operator *ret = new ast::binary_operator;
        $$ = ret;
    }
    | AND2 
    {
        ast::binary_operator *ret = new ast::binary_operator;
        $$ = ret;
    }
    | BAR2 
    {
        ast::binary_operator *ret = new ast::binary_operator;
        $$ = ret;
    }
    | STAR2 
    {
        ast::binary_operator *ret = new ast::binary_operator;
        $$ = ret;
    }
    | LT 
    {
        ast::binary_operator *ret = new ast::binary_operator;
        $$ = ret;
    }
    | LTE 
    {
        ast::binary_operator *ret = new ast::binary_operator;
        $$ = ret;
    }
    | GT 
    {
        ast::binary_operator *ret = new ast::binary_operator;
        $$ = ret;
    }
    | GTE 
    {
        ast::binary_operator *ret = new ast::binary_operator;
        $$ = ret;
    }
    | AND 
    {
        ast::binary_operator *ret = new ast::binary_operator;
        $$ = ret;
    }
    | BAR_ 
    {
        ast::binary_operator *ret = new ast::binary_operator;
        $$ = ret;
    }
    | XOR 
    {
        ast::binary_operator *ret = new ast::binary_operator;
        $$ = ret;
    }
    | XOR_WAVE 
    {
        ast::binary_operator *ret = new ast::binary_operator;
        $$ = ret;
    }
    | WAVE_XOR 
    {
        ast::binary_operator *ret = new ast::binary_operator;
        $$ = ret;
    }
    | RSHIFT 
    {
        ast::binary_operator *ret = new ast::binary_operator;
        $$ = ret;
    }
    | LSHIFT 
    {
        ast::binary_operator *ret = new ast::binary_operator;
        $$ = ret;
    }
    | RSHIFT2 
    {
        ast::binary_operator *ret = new ast::binary_operator;
        $$ = ret;
    }
    | LSHIFT2 
    {
        ast::binary_operator *ret = new ast::binary_operator;
        $$ = ret;
    }
    | RIGHTARROW 
    {
        ast::binary_operator *ret = new ast::binary_operator;
        $$ = ret;
    }
    | LT_DASH_RT 
    {
        ast::binary_operator *ret = new ast::binary_operator;
        $$ = ret;
    }
    ;

inc_or_dec_operator 
    : PLUS2 
    {
        ast::inc_or_dec_operator *ret = new ast::inc_or_dec_operator;
        $$ = ret;
    }
    | MINUS2 
    {
        ast::inc_or_dec_operator *ret = new ast::inc_or_dec_operator;
        $$ = ret;
    }
    ;

unary_module_path_operator 
    : NOT 
    {
        ast::unary_module_path_operator *ret = new ast::unary_module_path_operator;
        $$ = ret;
    }
    | WAVE 
    {
        ast::unary_module_path_operator *ret = new ast::unary_module_path_operator;
        $$ = ret;
    }
    | AND 
    {
        ast::unary_module_path_operator *ret = new ast::unary_module_path_operator;
        $$ = ret;
    }
    | WAVE_AND 
    {
        ast::unary_module_path_operator *ret = new ast::unary_module_path_operator;
        $$ = ret;
    }
    | BAR_ 
    {
        ast::unary_module_path_operator *ret = new ast::unary_module_path_operator;
        $$ = ret;
    }
    | WAVE_BAR 
    {
        ast::unary_module_path_operator *ret = new ast::unary_module_path_operator;
        $$ = ret;
    }
    | XOR 
    {
        ast::unary_module_path_operator *ret = new ast::unary_module_path_operator;
        $$ = ret;
    }
    | WAVE_XOR 
    {
        ast::unary_module_path_operator *ret = new ast::unary_module_path_operator;
        $$ = ret;
    }
    | XOR_WAVE 
    {
        ast::unary_module_path_operator *ret = new ast::unary_module_path_operator;
        $$ = ret;
    }
    ;

binary_module_path_operator 
    : EQ2 
    {
        ast::binary_module_path_operator *ret = new ast::binary_module_path_operator;
        $$ = ret;
    }
    | NEQ 
    {
        ast::binary_module_path_operator *ret = new ast::binary_module_path_operator;
        $$ = ret;
    }
    | AND2 
    {
        ast::binary_module_path_operator *ret = new ast::binary_module_path_operator;
        $$ = ret;
    }
    | BAR2 
    {
        ast::binary_module_path_operator *ret = new ast::binary_module_path_operator;
        $$ = ret;
    }
    | AND 
    {
        ast::binary_module_path_operator *ret = new ast::binary_module_path_operator;
        $$ = ret;
    }
    | BAR_ 
    {
        ast::binary_module_path_operator *ret = new ast::binary_module_path_operator;
        $$ = ret;
    }
    | XOR 
    {
        ast::binary_module_path_operator *ret = new ast::binary_module_path_operator;
        $$ = ret;
    }
    | XOR_WAVE 
    {
        ast::binary_module_path_operator *ret = new ast::binary_module_path_operator;
        $$ = ret;
    }
    | WAVE_XOR 
    {
        ast::binary_module_path_operator *ret = new ast::binary_module_path_operator;
        $$ = ret;
    }
    ;

number 
    : integral_number 
    {
        ast::number *ret = new ast::number;
        $$ = ret;
    }
    ;

integral_number 
    : decimal_number 
    {
        ast::integral_number *ret = new ast::integral_number;
        $$ = ret;
    }
    | octal_number 
    {
        ast::integral_number *ret = new ast::integral_number;
        $$ = ret;
    }
    | binary_number 
    {
        ast::integral_number *ret = new ast::integral_number;
        $$ = ret;
    }
    | hex_number 
    {
        ast::integral_number *ret = new ast::integral_number;
        $$ = ret;
    }
    ;

decimal_number 
    : SV_UNSIGNED_NUMBER 
    {
        ast::decimal_number *ret = new ast::decimal_number;
        $$ = ret;
    }
    | SV_DECIMAL_NUMBER 
    {
        ast::decimal_number *ret = new ast::decimal_number;
        $$ = ret;
    }
    ;

octal_number 
    : SV_OCTAL_NUMBER 
    {
        ast::octal_number *ret = new ast::octal_number;
        $$ = ret;
    }
    ;

binary_number 
    : SV_BINARY_NUMBER 
    {
        ast::binary_number *ret = new ast::binary_number;
        $$ = ret;
    }
    ;

hex_number 
    : SV_HEX_NUMBER 
    {
        ast::hex_number *ret = new ast::hex_number;
        $$ = ret;
    }
    ;

unsigned_number 
    : SV_UNSIGNED_INTEGER 
    {
        ast::unsigned_number *ret = new ast::unsigned_number;
        $$ = ret;
    }
    ;

real_number 
    : fixed_point_number 
    {
        ast::real_number *ret = new ast::real_number;
        $$ = ret;
    }
    | SV_EXPONENTIAL_NUMBER 
    {
        ast::real_number *ret = new ast::real_number;
        $$ = ret;
    }
    ;

fixed_point_number 
    : SV_FIXED_POINT_NUMBER 
    {
        ast::fixed_point_number *ret = new ast::fixed_point_number;
        $$ = ret;
    }
    ;

unbased_unsized_literal 
    : APOSTROPHE_GND 
    {
        ast::unbased_unsized_literal *ret = new ast::unbased_unsized_literal;
        $$ = ret;
    }
    | APOSTROPHE_VDD 
    {
        ast::unbased_unsized_literal *ret = new ast::unbased_unsized_literal;
        $$ = ret;
    }
    | APOSTROPHE z_or_x 
    {
        ast::unbased_unsized_literal *ret = new ast::unbased_unsized_literal;
        $$ = ret;
    }
    ;

string_literal 
    : SV_STRING 
    {
        ast::string_literal *ret = new ast::string_literal;
        $$ = ret;
    }
    ;

attribute_instance 
    : LP_STAR LIST_161 STAR_RP 
    {
        ast::attribute_instance *ret = new ast::attribute_instance;
        $$ = ret;
    }
    ;

attr_spec 
    : attr_name OPT_24 
    {
        ast::attr_spec *ret = new ast::attr_spec;
        $$ = ret;
    }
    ;

attr_name 
    : identifier 
    {
        ast::attr_name *ret = new ast::attr_name;
        $$ = ret;
    }
    ;

block_identifier 
    : identifier 
    {
        ast::block_identifier *ret = new ast::block_identifier;
        $$ = ret;
    }
    ;

bin_identifier 
    : identifier 
    {
        ast::bin_identifier *ret = new ast::bin_identifier;
        $$ = ret;
    }
    ;

c_identifier 
    : identifier 
    {
        ast::c_identifier *ret = new ast::c_identifier;
        $$ = ret;
    }
    ;

cell_identifier 
    : identifier 
    {
        ast::cell_identifier *ret = new ast::cell_identifier;
        $$ = ret;
    }
    ;

checker_identifier 
    : identifier 
    {
        ast::checker_identifier *ret = new ast::checker_identifier;
        $$ = ret;
    }
    ;

class_identifier 
    : identifier 
    {
        ast::class_identifier *ret = new ast::class_identifier;
        $$ = ret;
    }
    ;

class_variable_identifier 
    : identifier 
    {
        ast::class_variable_identifier *ret = new ast::class_variable_identifier;
        $$ = ret;
    }
    ;

clocking_identifier 
    : identifier 
    {
        ast::clocking_identifier *ret = new ast::clocking_identifier;
        $$ = ret;
    }
    ;

config_identifier 
    : identifier 
    {
        ast::config_identifier *ret = new ast::config_identifier;
        $$ = ret;
    }
    ;

const_identifier 
    : identifier 
    {
        ast::const_identifier *ret = new ast::const_identifier;
        $$ = ret;
    }
    ;

constraint_identifier 
    : identifier 
    {
        ast::constraint_identifier *ret = new ast::constraint_identifier;
        $$ = ret;
    }
    ;

covergroup_identifier 
    : identifier 
    {
        ast::covergroup_identifier *ret = new ast::covergroup_identifier;
        $$ = ret;
    }
    ;

cover_point_identifier 
    : identifier 
    {
        ast::cover_point_identifier *ret = new ast::cover_point_identifier;
        $$ = ret;
    }
    ;

cross_identifier 
    : identifier 
    {
        ast::cross_identifier *ret = new ast::cross_identifier;
        $$ = ret;
    }
    ;

dynamic_array_variable_identifier 
    : identifier 
    {
        ast::dynamic_array_variable_identifier *ret = new ast::dynamic_array_variable_identifier;
        $$ = ret;
    }
    ;

enum_identifier 
    : identifier 
    {
        ast::enum_identifier *ret = new ast::enum_identifier;
        $$ = ret;
    }
    ;

escaped_identifier 
    : SV_ESCAPED_IDENTIFIER 
    {
        ast::escaped_identifier *ret = new ast::escaped_identifier;
        $$ = ret;
    }
    ;

formal_port_identifier 
    : identifier 
    {
        ast::formal_port_identifier *ret = new ast::formal_port_identifier;
        $$ = ret;
    }
    ;

function_identifier 
    : identifier 
    {
        ast::function_identifier *ret = new ast::function_identifier;
        $$ = ret;
    }
    ;

generate_block_identifier 
    : identifier 
    {
        ast::generate_block_identifier *ret = new ast::generate_block_identifier;
        $$ = ret;
    }
    ;

genvar_identifier 
    : identifier 
    {
        ast::genvar_identifier *ret = new ast::genvar_identifier;
        $$ = ret;
    }
    ;

hierarchical_array_identifier 
    : identifier 
    {
        ast::hierarchical_array_identifier *ret = new ast::hierarchical_array_identifier;
        $$ = ret;
    }
    ;

hierarchical_block_identifier 
    : identifier 
    {
        ast::hierarchical_block_identifier *ret = new ast::hierarchical_block_identifier;
        $$ = ret;
    }
    ;

hierarchical_event_identifier 
    : identifier 
    {
        ast::hierarchical_event_identifier *ret = new ast::hierarchical_event_identifier;
        $$ = ret;
    }
    ;

hierarchical_identifier 
    : identifier 
    {
        ast::hierarchical_identifier *ret = new ast::hierarchical_identifier;
        $$ = ret;
    }
    ;

hierarchical_net_identifier 
    : identifier 
    {
        ast::hierarchical_net_identifier *ret = new ast::hierarchical_net_identifier;
        $$ = ret;
    }
    ;

hierarchical_parameter_identifier 
    : identifier 
    {
        ast::hierarchical_parameter_identifier *ret = new ast::hierarchical_parameter_identifier;
        $$ = ret;
    }
    ;

hierarchical_property_identifier 
    : identifier 
    {
        ast::hierarchical_property_identifier *ret = new ast::hierarchical_property_identifier;
        $$ = ret;
    }
    ;

hierarchical_sequence_identifier 
    : identifier 
    {
        ast::hierarchical_sequence_identifier *ret = new ast::hierarchical_sequence_identifier;
        $$ = ret;
    }
    ;

hierarchical_task_identifier 
    : identifier 
    {
        ast::hierarchical_task_identifier *ret = new ast::hierarchical_task_identifier;
        $$ = ret;
    }
    ;

hierarchical_tf_identifier 
    : identifier 
    {
        ast::hierarchical_tf_identifier *ret = new ast::hierarchical_tf_identifier;
        $$ = ret;
    }
    ;

hierarchical_variable_identifier 
    : identifier 
    {
        ast::hierarchical_variable_identifier *ret = new ast::hierarchical_variable_identifier;
        $$ = ret;
    }
    ;

identifier 
    : simple_identifier 
    {
        ast::identifier *ret = new ast::identifier;
        $$ = ret;
    }
    | escaped_identifier 
    {
        ast::identifier *ret = new ast::identifier;
        $$ = ret;
    }
    ;

index_variable_identifier 
    : identifier 
    {
        ast::index_variable_identifier *ret = new ast::index_variable_identifier;
        $$ = ret;
    }
    ;

interface_identifier 
    : identifier 
    {
        ast::interface_identifier *ret = new ast::interface_identifier;
        $$ = ret;
    }
    ;

interface_instance_identifier 
    : identifier 
    {
        ast::interface_instance_identifier *ret = new ast::interface_instance_identifier;
        $$ = ret;
    }
    ;

inout_port_identifier 
    : identifier 
    {
        ast::inout_port_identifier *ret = new ast::inout_port_identifier;
        $$ = ret;
    }
    ;

input_port_identifier 
    : identifier 
    {
        ast::input_port_identifier *ret = new ast::input_port_identifier;
        $$ = ret;
    }
    ;

instance_identifier 
    : identifier 
    {
        ast::instance_identifier *ret = new ast::instance_identifier;
        $$ = ret;
    }
    ;

library_identifier 
    : identifier 
    {
        ast::library_identifier *ret = new ast::library_identifier;
        $$ = ret;
    }
    ;

member_identifier 
    : identifier 
    {
        ast::member_identifier *ret = new ast::member_identifier;
        $$ = ret;
    }
    ;

method_identifier 
    : identifier 
    {
        ast::method_identifier *ret = new ast::method_identifier;
        $$ = ret;
    }
    ;

modport_identifier 
    : identifier 
    {
        ast::modport_identifier *ret = new ast::modport_identifier;
        $$ = ret;
    }
    ;

module_identifier 
    : identifier 
    {
        ast::module_identifier *ret = new ast::module_identifier;
        $$ = ret;
    }
    ;

net_identifier 
    : identifier 
    {
        ast::net_identifier *ret = new ast::net_identifier;
        $$ = ret;
    }
    ;

net_type_identifier 
    : identifier 
    {
        ast::net_type_identifier *ret = new ast::net_type_identifier;
        $$ = ret;
    }
    ;

output_port_identifier 
    : identifier 
    {
        ast::output_port_identifier *ret = new ast::output_port_identifier;
        $$ = ret;
    }
    ;

package_identifier 
    : identifier 
    {
        ast::package_identifier *ret = new ast::package_identifier;
        $$ = ret;
    }
    ;

package_scope 
    : package_identifier COLON2 
    {
        ast::package_scope *ret = new ast::package_scope;
        $$ = ret;
    }
    | DOLLAR_UNIT_ COLON2 
    {
        ast::package_scope *ret = new ast::package_scope;
        $$ = ret;
    }
    ;

parameter_identifier 
    : identifier 
    {
        ast::parameter_identifier *ret = new ast::parameter_identifier;
        $$ = ret;
    }
    ;

port_identifier 
    : identifier 
    {
        ast::port_identifier *ret = new ast::port_identifier;
        $$ = ret;
    }
    ;

production_identifier 
    : identifier 
    {
        ast::production_identifier *ret = new ast::production_identifier;
        $$ = ret;
    }
    ;

program_identifier 
    : identifier 
    {
        ast::program_identifier *ret = new ast::program_identifier;
        $$ = ret;
    }
    ;

property_identifier 
    : identifier 
    {
        ast::property_identifier *ret = new ast::property_identifier;
        $$ = ret;
    }
    ;

ps_class_identifier 
    : OPT_116 class_identifier 
    {
        ast::ps_class_identifier *ret = new ast::ps_class_identifier;
        $$ = ret;
    }
    ;

ps_covergroup_identifier 
    : OPT_116 covergroup_identifier 
    {
        ast::ps_covergroup_identifier *ret = new ast::ps_covergroup_identifier;
        $$ = ret;
    }
    ;

ps_checker_identifier 
    : OPT_116 checker_identifier 
    {
        ast::ps_checker_identifier *ret = new ast::ps_checker_identifier;
        $$ = ret;
    }
    ;

ps_identifier 
    : OPT_116 identifier 
    {
        ast::ps_identifier *ret = new ast::ps_identifier;
        $$ = ret;
    }
    ;

ps_or_hierarchical_array_identifier 
    : OPT_152 hierarchical_array_identifier 
    {
        ast::ps_or_hierarchical_array_identifier *ret = new ast::ps_or_hierarchical_array_identifier;
        $$ = ret;
    }
    ;

ps_or_hierarchical_net_identifier 
    : OPT_116 net_identifier 
    {
        ast::ps_or_hierarchical_net_identifier *ret = new ast::ps_or_hierarchical_net_identifier;
        $$ = ret;
    }
    | hierarchical_net_identifier 
    {
        ast::ps_or_hierarchical_net_identifier *ret = new ast::ps_or_hierarchical_net_identifier;
        $$ = ret;
    }
    ;

ps_or_hierarchical_property_identifier 
    : OPT_116 property_identifier 
    {
        ast::ps_or_hierarchical_property_identifier *ret = new ast::ps_or_hierarchical_property_identifier;
        $$ = ret;
    }
    | hierarchical_property_identifier 
    {
        ast::ps_or_hierarchical_property_identifier *ret = new ast::ps_or_hierarchical_property_identifier;
        $$ = ret;
    }
    ;

ps_or_hierarchical_sequence_identifier 
    : OPT_116 sequence_identifier 
    {
        ast::ps_or_hierarchical_sequence_identifier *ret = new ast::ps_or_hierarchical_sequence_identifier;
        $$ = ret;
    }
    | hierarchical_sequence_identifier 
    {
        ast::ps_or_hierarchical_sequence_identifier *ret = new ast::ps_or_hierarchical_sequence_identifier;
        $$ = ret;
    }
    ;

ps_or_hierarchical_tf_identifier 
    : OPT_116 tf_identifier 
    {
        ast::ps_or_hierarchical_tf_identifier *ret = new ast::ps_or_hierarchical_tf_identifier;
        $$ = ret;
    }
    | hierarchical_tf_identifier 
    {
        ast::ps_or_hierarchical_tf_identifier *ret = new ast::ps_or_hierarchical_tf_identifier;
        $$ = ret;
    }
    ;

ps_parameter_identifier 
    : OPT_59 parameter_identifier 
    {
        ast::ps_parameter_identifier *ret = new ast::ps_parameter_identifier;
        $$ = ret;
    }
    | STAR_52 parameter_identifier 
    {
        ast::ps_parameter_identifier *ret = new ast::ps_parameter_identifier;
        $$ = ret;
    }
    ;

ps_type_identifier 
    : OPT_214 type_identifier 
    {
        ast::ps_type_identifier *ret = new ast::ps_type_identifier;
        $$ = ret;
    }
    ;

sequence_identifier 
    : identifier 
    {
        ast::sequence_identifier *ret = new ast::sequence_identifier;
        $$ = ret;
    }
    ;

signal_identifier 
    : identifier 
    {
        ast::signal_identifier *ret = new ast::signal_identifier;
        $$ = ret;
    }
    ;

simple_identifier 
    : SV_IDENTIFIER 
    {
        ast::simple_identifier *ret = new ast::simple_identifier;
        $$ = ret;
    }
    ;

specparam_identifier 
    : identifier 
    {
        ast::specparam_identifier *ret = new ast::specparam_identifier;
        $$ = ret;
    }
    ;

system_tf_identifier 
    : identifier 
    {
        ast::system_tf_identifier *ret = new ast::system_tf_identifier;
        $$ = ret;
    }
    ;

task_identifier 
    : identifier 
    {
        ast::task_identifier *ret = new ast::task_identifier;
        $$ = ret;
    }
    ;

tf_identifier 
    : identifier 
    {
        ast::tf_identifier *ret = new ast::tf_identifier;
        $$ = ret;
    }
    ;

terminal_identifier 
    : identifier 
    {
        ast::terminal_identifier *ret = new ast::terminal_identifier;
        $$ = ret;
    }
    ;

topmodule_identifier 
    : identifier 
    {
        ast::topmodule_identifier *ret = new ast::topmodule_identifier;
        $$ = ret;
    }
    ;

type_identifier 
    : identifier 
    {
        ast::type_identifier *ret = new ast::type_identifier;
        $$ = ret;
    }
    ;

udp_identifier 
    : identifier 
    {
        ast::udp_identifier *ret = new ast::udp_identifier;
        $$ = ret;
    }
    ;

variable_identifier 
    : identifier 
    {
        ast::variable_identifier *ret = new ast::variable_identifier;
        $$ = ret;
    }
    ;

file_path_spec 
    : FILE_PATH 
    {
        ast::file_path_spec *ret = new ast::file_path_spec;
        $$ = ret;
    }
    ;

LIST_0
    : library_description 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_0  library_description 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_1
    : file_path_spec 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_1 COMMA file_path_spec 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_2
    : description 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_2  description 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_3
    : attribute_instance 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_3  attribute_instance 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_4
    : package_import_declaration 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_4  package_import_declaration 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_5
    : module_item 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_5  module_item 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_6
    : non_port_module_item 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_6  non_port_module_item 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_7
    : interface_item 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_7  interface_item 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_8
    : non_port_interface_item 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_8  non_port_interface_item 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_9
    : program_item 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_9  program_item 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_10
    : non_port_program_item 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_10  non_port_program_item 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_11
    : STAR_2 checker_or_generate_item 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_11  STAR_2 checker_or_generate_item 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_12
    : interface_class_type 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_12 COMMA interface_class_type 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_13
    : class_item 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_13  class_item 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_14
    : STAR_2 package_item 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_14  STAR_2 package_item 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_15
    : COMMA parameter_port_declaration 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_15  COMMA parameter_port_declaration 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_16
    : parameter_port_declaration 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_16 COMMA parameter_port_declaration 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_17
    : port 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_17 COMMA port 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_18
    : STAR_2 ansi_port_declaration 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_18 COMMA STAR_2 ansi_port_declaration 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_19
    : port_reference 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_19 COMMA port_reference 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_20
    : unpacked_dimension 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_20  unpacked_dimension 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_21
    : variable_dimension 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_21  variable_dimension 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_22
    : bind_target_instance 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_22 COMMA bind_target_instance 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_23
    : local_parameter_declaration SEMICOLON 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_23  local_parameter_declaration SEMICOLON 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_24
    : config_rule_statement 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_24  config_rule_statement 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_25
    : OPT_33 cell_identifier 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_25  OPT_33 cell_identifier 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_26
    : DOT instance_identifier 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_26  DOT instance_identifier 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_27
    : library_identifier 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_27  library_identifier 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_28
    : named_parameter_assignment 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_28 COMMA named_parameter_assignment 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_29
    : checker_port_item 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_29 COMMA checker_port_item 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_30
    : property_qualifier 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_30  property_qualifier 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_31
    : class_item_qualifier 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_31  class_item_qualifier 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_32
    : method_qualifier 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_32  method_qualifier 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_33
    : block_item_declaration 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_33  block_item_declaration 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_34
    : function_statement_or_null 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_34  function_statement_or_null 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_35
    : constraint_block_item 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_35  constraint_block_item 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_36
    : constraint_primary 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_36 COMMA constraint_primary 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_37
    : constraint_expression 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_37  constraint_expression 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_38
    : dist_item 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_38 COMMA dist_item 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_39
    : identifier 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_39 COMMA identifier 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_40
    : anonymous_program_item 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_40  anonymous_program_item 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_41
    : package_import_item 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_41 COMMA package_import_item 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_42
    : net_identifier STAR_14 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_42 COMMA net_identifier STAR_14 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_43
    : packed_dimension 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_43  packed_dimension 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_44
    : struct_union_member 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_44  struct_union_member 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_45
    : enum_name_declaration 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_45 COMMA enum_name_declaration 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_46
    : COLON2 class_identifier OPT_16 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_46  COLON2 class_identifier OPT_16 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_47
    : defparam_assignment 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_47 COMMA defparam_assignment 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_48
    : genvar_identifier 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_48 COMMA genvar_identifier 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_49
    : interface_identifier STAR_14 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_49 COMMA interface_identifier STAR_14 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_50
    : net_decl_assignment 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_50 COMMA net_decl_assignment 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_51
    : param_assignment 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_51 COMMA param_assignment 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_52
    : port_identifier STAR_14 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_52 COMMA port_identifier STAR_14 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_53
    : port_identifier 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_53 COMMA port_identifier 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_54
    : specparam_assignment 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_54 COMMA specparam_assignment 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_55
    : port_identifier STAR_15 OPT_73 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_55 COMMA port_identifier STAR_15 OPT_73 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_56
    : type_assignment 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_56 COMMA type_assignment 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_57
    : variable_decl_assignment 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_57 COMMA variable_decl_assignment 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_58
    : variable_identifier STAR_15 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_58 COMMA variable_identifier STAR_15 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_59
    : port_identifier STAR_15 OPT_24 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_59 COMMA port_identifier STAR_15 OPT_24 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_60
    : tf_item_declaration 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_60  tf_item_declaration 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_61
    : statement_or_null 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_61  statement_or_null 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_62
    : tf_port_item 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_62 COMMA tf_port_item 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_63
    : data_type 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_63 COMMA data_type 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_64
    : modport_item 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_64 COMMA modport_item 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_65
    : modport_ports_declaration 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_65 COMMA modport_ports_declaration 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_66
    : modport_simple_port 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_66 COMMA modport_simple_port 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_67
    : modport_tf_port 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_67 COMMA modport_tf_port 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_68
    : OPT_94 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_68 COMMA OPT_94 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_69
    : COMMA DOT identifier LP OPT_94 RP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_69  COMMA DOT identifier LP OPT_94 RP 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_70
    : DOT identifier LP OPT_94 RP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_70 COMMA DOT identifier LP OPT_94 RP 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_71
    : assertion_variable_declaration 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_71  assertion_variable_declaration 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_72
    : property_port_item 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_72 COMMA property_port_item 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_73
    : property_case_item 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_73  property_case_item 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_74
    : expression_or_dist 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_74 COMMA expression_or_dist 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_75
    : sequence_port_item 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_75 COMMA sequence_port_item 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_76
    : cycle_delay_range sequence_expr 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_76  cycle_delay_range sequence_expr 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_77
    : COMMA sequence_match_item 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_77  COMMA sequence_match_item 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_78
    : OPT_112 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_78 COMMA OPT_112 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_79
    : COMMA DOT identifier LP OPT_112 RP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_79  COMMA DOT identifier LP OPT_112 RP 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_80
    : DOT identifier LP OPT_112 RP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_80 COMMA DOT identifier LP OPT_112 RP 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_81
    : let_port_item 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_81 COMMA let_port_item 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_82
    : OPT_119 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_82 COMMA OPT_119 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_83
    : COMMA DOT identifier LP OPT_119 RP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_83  COMMA DOT identifier LP OPT_119 RP 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_84
    : DOT identifier LP OPT_119 RP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_84 COMMA DOT identifier LP OPT_119 RP 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_85
    : coverage_spec_or_option 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_85  coverage_spec_or_option 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_86
    : block_event_expression 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_86 OR_ block_event_expression 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_87
    : bins_or_options SEMICOLON 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_87  bins_or_options SEMICOLON 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_88
    : LP trans_set RP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_88 COMMA LP trans_set RP 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_89
    : trans_range_list 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_89 EQ_GT trans_range_list 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_90
    : cross_item 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_90 COMMA cross_item 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_91
    : cross_body_item SEMICOLON 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_91  cross_body_item SEMICOLON 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_92
    : covergroup_value_range 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_92 COMMA covergroup_value_range 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_93
    : cmos_switch_instance 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_93 COMMA cmos_switch_instance 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_94
    : enable_gate_instance 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_94 COMMA enable_gate_instance 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_95
    : mos_switch_instance 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_95 COMMA mos_switch_instance 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_96
    : n_input_gate_instance 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_96 COMMA n_input_gate_instance 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_97
    : n_output_gate_instance 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_97 COMMA n_output_gate_instance 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_98
    : pass_enable_switch_instance 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_98 COMMA pass_enable_switch_instance 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_99
    : pass_switch_instance 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_99 COMMA pass_switch_instance 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_100
    : pull_gate_instance 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_100 COMMA pull_gate_instance 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_101
    : input_terminal 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_101 COMMA input_terminal 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_102
    : output_terminal 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_102 COMMA output_terminal 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_103
    : hierarchical_instance 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_103 COMMA hierarchical_instance 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_104
    : ordered_parameter_assignment 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_104 COMMA ordered_parameter_assignment 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_105
    : ordered_port_connection 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_105 COMMA ordered_port_connection 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_106
    : named_port_connection 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_106 COMMA named_port_connection 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_107
    : ordered_checker_port_connection 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_107 COMMA ordered_checker_port_connection 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_108
    : named_checker_port_connection 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_108 COMMA named_checker_port_connection 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_109
    : generate_item 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_109  generate_item 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_110
    : constant_expression 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_110 COMMA constant_expression 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_111
    : udp_port_declaration 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_111  udp_port_declaration 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_112
    : input_port_identifier 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_112 COMMA input_port_identifier 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_113
    : udp_input_declaration 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_113 COMMA udp_input_declaration 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_114
    : combinational_entry 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_114  combinational_entry 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_115
    : sequential_entry 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_115  sequential_entry 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_116
    : level_symbol 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_116  level_symbol 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_117
    : udp_instance 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_117 COMMA udp_instance 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_118
    : net_assignment 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_118 COMMA net_assignment 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_119
    : variable_assignment 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_119 COMMA variable_assignment 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_120
    : EQ net_lvalue 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_120  EQ net_lvalue 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_121
    : variable_identifier 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_121 COMMA variable_identifier 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_122
    : hierarchical_identifier 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_122 COMMA hierarchical_identifier 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_123
    : ELSE_ IF_ LP cond_predicate RP statement_or_null 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_123  ELSE_ IF_ LP cond_predicate RP statement_or_null 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_124
    : expression_or_cond_pattern 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_124 AND3 expression_or_cond_pattern 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_125
    : case_item 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_125  case_item 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_126
    : case_pattern_item 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_126  case_pattern_item 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_127
    : case_inside_item 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_127  case_inside_item 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_128
    : case_item_expression 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_128 COMMA case_item_expression 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_129
    : randcase_item 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_129  randcase_item 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_130
    : open_value_range 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_130 COMMA open_value_range 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_131
    : pattern 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_131 COMMA pattern 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_132
    : member_identifier COLON pattern 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_132 COMMA member_identifier COLON pattern 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_133
    : expression 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_133 COMMA expression 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_134
    : structure_pattern_key COLON expression 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_134 COMMA structure_pattern_key COLON expression 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_135
    : array_pattern_key COLON expression 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_135 COMMA array_pattern_key COLON expression 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_136
    : net_lvalue 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_136 COMMA net_lvalue 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_137
    : variable_lvalue 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_137 COMMA variable_lvalue 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_138
    : for_variable_declaration 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_138 COMMA for_variable_declaration 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_139
    : data_type variable_identifier EQ expression 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_139 COMMA data_type variable_identifier EQ expression 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_140
    : for_step_assignment 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_140 COMMA for_step_assignment 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_141
    : OPT_165 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_141 COMMA OPT_165 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_142
    : clocking_item 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_142  clocking_item 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_143
    : clocking_decl_assign 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_143 COMMA clocking_decl_assign 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_144
    : production 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_144  production 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_145
    : rs_rule 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_145 BAR_ rs_rule 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_146
    : rs_prod 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_146  rs_prod 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_147
    : production_item 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_147  production_item 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_148
    : data_declaration 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_148  data_declaration 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_149
    : rs_case_item 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_149  rs_case_item 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_150
    : specify_item 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_150  specify_item 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_151
    : specify_input_terminal_descriptor 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_151 COMMA specify_input_terminal_descriptor 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_152
    : specify_output_terminal_descriptor 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_152 COMMA specify_output_terminal_descriptor 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_153
    : edge_descriptor 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_153 COMMA edge_descriptor 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_154
    : module_path_expression 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_154 COMMA module_path_expression 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_155
    : stream_expression 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_155 COMMA stream_expression 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_156
    : OPT_26 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_156 COMMA OPT_26 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_157
    : COMMA DOT identifier LP OPT_26 RP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_157  COMMA DOT identifier LP OPT_26 RP 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_158
    : LSP expression RSP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_158  LSP expression RSP 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_159
    : DOT member_identifier bit_select 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_159  DOT member_identifier bit_select 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_160
    : DOT member_identifier constant_bit_select 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_160  DOT member_identifier constant_bit_select 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_161
    : attr_spec 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_161 COMMA attr_spec 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
LIST_162
    : generate_block_identifier OPT_213 DOT 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | LIST_162  generate_block_identifier OPT_213 DOT 
    {
        // $1->append($2);
        $$ = $1;
    }
    ;
OPT_0
    : /* empty */
    {
        $$ = NULL;
    }
    | DASH_INCDIR_ LIST_1 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_5
    : /* empty */
    {
        $$ = NULL;
    }
    | COLON module_identifier 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_6
    : /* empty */
    {
        $$ = NULL;
    }
    | COLON interface_identifier 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_7
    : /* empty */
    {
        $$ = NULL;
    }
    | COLON program_identifier 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_9
    : /* empty */
    {
        $$ = NULL;
    }
    | LP OPT_8 RP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_10
    : /* empty */
    {
        $$ = NULL;
    }
    | COLON checker_identifier 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_11
    : /* empty */
    {
        $$ = NULL;
    }
    | VIRTUAL_ 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_12
    : /* empty */
    {
        $$ = NULL;
    }
    | LP list_of_arguments RP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_13
    : /* empty */
    {
        $$ = NULL;
    }
    | EXTENDS_ class_type OPT_12 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_14
    : /* empty */
    {
        $$ = NULL;
    }
    | IMPLEMENTS_ LIST_12 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_15
    : /* empty */
    {
        $$ = NULL;
    }
    | COLON class_identifier 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_17
    : /* empty */
    {
        $$ = NULL;
    }
    | COLON package_identifier 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_18
    : /* empty */
    {
        $$ = NULL;
    }
    | SLASH time_literal 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_22
    : /* empty */
    {
        $$ = NULL;
    }
    | DOT modport_identifier 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | interface_port_header 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_24
    : /* empty */
    {
        $$ = NULL;
    }
    | EQ constant_expression 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_27
    : /* empty */
    {
        $$ = NULL;
    }
    | COMMA list_of_arguments 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_28
    : /* empty */
    {
        $$ = NULL;
    }
    | LP finish_number OPT_27 RP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_30
    : /* empty */
    {
        $$ = NULL;
    }
    | LP OPT_29 RP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_31
    : /* empty */
    {
        $$ = NULL;
    }
    | COLON bind_target_instance_list 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_32
    : /* empty */
    {
        $$ = NULL;
    }
    | COLON config_identifier 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_33
    : /* empty */
    {
        $$ = NULL;
    }
    | library_identifier DOT 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_34
    : /* empty */
    {
        $$ = NULL;
    }
    | COLON CONFIG_ 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_36
    : /* empty */
    {
        $$ = NULL;
    }
    | EQ property_actual_arg 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_37
    : /* empty */
    {
        $$ = NULL;
    }
    | RAND_ 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_39
    : /* empty */
    {
        $$ = NULL;
    }
    | LP OPT_38 RP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_40
    : /* empty */
    {
        $$ = NULL;
    }
    | PURE_ 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_42
    : /* empty */
    {
        $$ = NULL;
    }
    | SUPER_ DOT NEW_ OPT_12 SEMICOLON 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_43
    : /* empty */
    {
        $$ = NULL;
    }
    | COLON NEW_ 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_44
    : /* empty */
    {
        $$ = NULL;
    }
    | STATIC_ 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_45
    : /* empty */
    {
        $$ = NULL;
    }
    | implicit_class_handle DOT 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | class_scope 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_46
    : /* empty */
    {
        $$ = NULL;
    }
    | SOFT_ 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_47
    : /* empty */
    {
        $$ = NULL;
    }
    | ELSE_ constraint_set 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_51
    : /* empty */
    {
        $$ = NULL;
    }
    | CONST_ 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_52
    : /* empty */
    {
        $$ = NULL;
    }
    | VAR_ 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | charge_strength 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_54
    : /* empty */
    {
        $$ = NULL;
    }
    | VECTORED_ 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | SCALARED_ 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_57
    : /* empty */
    {
        $$ = NULL;
    }
    | SHARP delay_value 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_58
    : /* empty */
    {
        $$ = NULL;
    }
    | ENUM_ 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | STRUCT_ 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | UNION_ 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | CLASS_ 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | INTERFACE_ CLASS_ 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | class_scope 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_60
    : /* empty */
    {
        $$ = NULL;
    }
    | WITH_ OPT_59 tf_identifier 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_62
    : /* empty */
    {
        $$ = NULL;
    }
    | PACKED_ OPT_61 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_64
    : /* empty */
    {
        $$ = NULL;
    }
    | INTERFACE_ 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | package_scope 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_66
    : /* empty */
    {
        $$ = NULL;
    }
    | COLON integral_number 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_67
    : /* empty */
    {
        $$ = NULL;
    }
    | LSP integral_number OPT_66 RSP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_70
    : /* empty */
    {
        $$ = NULL;
    }
    | TAGGED_ 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_71
    : /* empty */
    {
        $$ = NULL;
    }
    | COMMA mintypmax_expression 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_72
    : /* empty */
    {
        $$ = NULL;
    }
    | COMMA mintypmax_expression OPT_71 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_73
    : /* empty */
    {
        $$ = NULL;
    }
    | EQ expression 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_74
    : /* empty */
    {
        $$ = NULL;
    }
    | EQ constant_param_expression 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_75
    : /* empty */
    {
        $$ = NULL;
    }
    | EQ data_type 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_76
    : /* empty */
    {
        $$ = NULL;
    }
    | COMMA error_limit_value 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_77
    : /* empty */
    {
        $$ = NULL;
    }
    | EQ dynamic_array_new 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_78
    : /* empty */
    {
        $$ = NULL;
    }
    | EQ class_new 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_79
    : /* empty */
    {
        $$ = NULL;
    }
    | LP expression RP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_80
    : /* empty */
    {
        $$ = NULL;
    }
    | COLON constant_expression 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_81
    : /* empty */
    {
        $$ = NULL;
    }
    | interface_identifier DOT 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | class_scope 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_82
    : /* empty */
    {
        $$ = NULL;
    }
    | COLON function_identifier 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_84
    : /* empty */
    {
        $$ = NULL;
    }
    | c_identifier EQ 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_86
    : /* empty */
    {
        $$ = NULL;
    }
    | COLON task_identifier 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_89
    : /* empty */
    {
        $$ = NULL;
    }
    | block_identifier COLON 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_91
    : /* empty */
    {
        $$ = NULL;
    }
    | DISABLE_ IFF_ LP expression_or_dist RP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_93
    : /* empty */
    {
        $$ = NULL;
    }
    | LP OPT_92 RP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_96
    : /* empty */
    {
        $$ = NULL;
    }
    | LP OPT_95 RP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_97
    : /* empty */
    {
        $$ = NULL;
    }
    | SEMICOLON 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_98
    : /* empty */
    {
        $$ = NULL;
    }
    | COLON property_identifier 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_100
    : /* empty */
    {
        $$ = NULL;
    }
    | LOCAL_ OPT_99 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_101
    : /* empty */
    {
        $$ = NULL;
    }
    | ELSE_ property_expr 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_102
    : /* empty */
    {
        $$ = NULL;
    }
    | COLON 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_104
    : /* empty */
    {
        $$ = NULL;
    }
    | LP OPT_103 RP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_105
    : /* empty */
    {
        $$ = NULL;
    }
    | COLON sequence_identifier 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_107
    : /* empty */
    {
        $$ = NULL;
    }
    | LOCAL_ OPT_106 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_108
    : /* empty */
    {
        $$ = NULL;
    }
    | EQ sequence_actual_arg 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_111
    : /* empty */
    {
        $$ = NULL;
    }
    | LP sequence_list_of_arguments RP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_113
    : /* empty */
    {
        $$ = NULL;
    }
    | DIST_ LMP dist_list RMP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_115
    : /* empty */
    {
        $$ = NULL;
    }
    | LP OPT_114 RP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_118
    : /* empty */
    {
        $$ = NULL;
    }
    | LP OPT_117 RP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_121
    : /* empty */
    {
        $$ = NULL;
    }
    | COLON covergroup_identifier 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_122
    : /* empty */
    {
        $$ = NULL;
    }
    | hierarchical_identifier DOT 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | class_scope 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_124
    : /* empty */
    {
        $$ = NULL;
    }
    | OPT_123 cover_point_identifier COLON 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_125
    : /* empty */
    {
        $$ = NULL;
    }
    | IFF_ LP expression RP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_126
    : /* empty */
    {
        $$ = NULL;
    }
    | WILDCARD_ 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_128
    : /* empty */
    {
        $$ = NULL;
    }
    | LSP OPT_127 RSP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_129
    : /* empty */
    {
        $$ = NULL;
    }
    | WITH_ LP with_covergroup_expression RP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_130
    : /* empty */
    {
        $$ = NULL;
    }
    | LSP RSP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_131
    : /* empty */
    {
        $$ = NULL;
    }
    | cross_identifier COLON 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_132
    : /* empty */
    {
        $$ = NULL;
    }
    | MATCHES_ integer_covergroup_expression 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_133
    : /* empty */
    {
        $$ = NULL;
    }
    | INTERSECT_ LMP covergroup_range_list RMP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_134
    : /* empty */
    {
        $$ = NULL;
    }
    | DOT bin_identifier 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_143
    : /* empty */
    {
        $$ = NULL;
    }
    | LP OPT_26 RP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_145
    : /* empty */
    {
        $$ = NULL;
    }
    | LP OPT_94 RP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_146
    : /* empty */
    {
        $$ = NULL;
    }
    | GENVAR_ 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_147
    : /* empty */
    {
        $$ = NULL;
    }
    | ELSE_ generate_block 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_148
    : /* empty */
    {
        $$ = NULL;
    }
    | generate_block_identifier COLON 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_149
    : /* empty */
    {
        $$ = NULL;
    }
    | COLON generate_block_identifier 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_150
    : /* empty */
    {
        $$ = NULL;
    }
    | COLON udp_identifier 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_152
    : /* empty */
    {
        $$ = NULL;
    }
    | implicit_class_handle DOT 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | class_scope 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | package_scope 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_155
    : /* empty */
    {
        $$ = NULL;
    }
    | COLON block_identifier 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_157
    : /* empty */
    {
        $$ = NULL;
    }
    | IFF_ expression 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_159
    : /* empty */
    {
        $$ = NULL;
    }
    | ELSE_ statement_or_null 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_160
    : /* empty */
    {
        $$ = NULL;
    }
    | AND3 expression 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_166
    : /* empty */
    {
        $$ = NULL;
    }
    | DEFAULT_ 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_168
    : /* empty */
    {
        $$ = NULL;
    }
    | COLON clocking_identifier 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_173
    : /* empty */
    {
        $$ = NULL;
    }
    | LP tf_port_list RP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_175
    : /* empty */
    {
        $$ = NULL;
    }
    | COLON_EQUAL weight_specification OPT_174 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_176
    : /* empty */
    {
        $$ = NULL;
    }
    | ELSE_ production_item 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_178
    : /* empty */
    {
        $$ = NULL;
    }
    | LSP constant_range_expression RSP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_180
    : /* empty */
    {
        $$ = NULL;
    }
    | COMMA OPT_179 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_185
    : /* empty */
    {
        $$ = NULL;
    }
    | COMMA OPT_184 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_186
    : /* empty */
    {
        $$ = NULL;
    }
    | COMMA OPT_183 OPT_185 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_187
    : /* empty */
    {
        $$ = NULL;
    }
    | COMMA OPT_182 OPT_186 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_188
    : /* empty */
    {
        $$ = NULL;
    }
    | COMMA OPT_181 OPT_187 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_189
    : /* empty */
    {
        $$ = NULL;
    }
    | COMMA OPT_179 OPT_188 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_192
    : /* empty */
    {
        $$ = NULL;
    }
    | COMMA OPT_191 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_193
    : /* empty */
    {
        $$ = NULL;
    }
    | COMMA OPT_190 OPT_192 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_194
    : /* empty */
    {
        $$ = NULL;
    }
    | COMMA OPT_179 OPT_193 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_196
    : /* empty */
    {
        $$ = NULL;
    }
    | AND3 timing_check_condition 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_198
    : /* empty */
    {
        $$ = NULL;
    }
    | WITH_ LSP array_range_expression RSP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_199
    : /* empty */
    {
        $$ = NULL;
    }
    | STD_COLON2 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_200
    : /* empty */
    {
        $$ = NULL;
    }
    | WITH_ LP expression RP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | NULL_ 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_202
    : /* empty */
    {
        $$ = NULL;
    }
    | LP OPT_201 RP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_203
    : /* empty */
    {
        $$ = NULL;
    }
    | LP identifier_list RP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_204
    : /* empty */
    {
        $$ = NULL;
    }
    | WITH_ OPT_203 constraint_block 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | package_scope 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_206
    : /* empty */
    {
        $$ = NULL;
    }
    | LSP range_expression RSP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_207
    : /* empty */
    {
        $$ = NULL;
    }
    | LOCAL_COLON2 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_208
    : /* empty */
    {
        $$ = NULL;
    }
    | STAR_50 DOT member_identifier 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_209
    : /* empty */
    {
        $$ = NULL;
    }
    | LSP part_select_range RSP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_210
    : /* empty */
    {
        $$ = NULL;
    }
    | STAR_51 DOT member_identifier 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_211
    : /* empty */
    {
        $$ = NULL;
    }
    | LSP constant_part_select_range RSP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_212
    : /* empty */
    {
        $$ = NULL;
    }
    | implicit_class_handle DOT 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | package_scope 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_213
    : /* empty */
    {
        $$ = NULL;
    }
    | LSP constant_expression RSP 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    ;
OPT_214
    : /* empty */
    {
        $$ = NULL;
    }
    | LOCAL_COLON2 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
        $$ = list;
    }
    | package_scope 
    {
        ast::list<ast::object *> *list = new ast::list<ast::object *>();
        // list->append($1);
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
