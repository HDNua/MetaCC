#include <stdio.h>
#include <stdlib.h>
#include "parser_ast.h"



//==============================================================================
// 
static struct ast_list_node *ast_list_node_new(void *elem, ast_type type) {
    struct ast_list_node *ret = (struct ast_list_node *)malloc(sizeof(struct ast_list_node));
    ret->type = AST_LIST_NODE;
    ret->elem_type = type;
    ret->elem = elem;
    ret->next = NULL;
    return ret;
}
// 
struct ast_list *ast_list_new(ast_type type) {
    struct ast_list *ret = (struct ast_list *)malloc(sizeof(struct ast_list));
    ret->type = AST_LIST;
    ret->elem_type = type;
    ret->tail = &ret->head;
    ret->count = 0;
    return ret;
};
// 
void ast_list_append(struct ast_list *self, void *elem, ast_type type) {
    struct ast_list_node *node = ast_list_node_new(elem, type);
    self->tail->next = node;
    self->tail = node;
    self->count += 1;
}
// 
void ast_list_iterate(struct ast_list *self) {
    struct ast_list_node *node;
    for (node=self->head.next; node; node=node->next) {
        ast_list_node_describe(node);
    }
}



// 
static int description_depth = 0;
static int describe_begin() {
    return ++description_depth;
}
static int describe_end() {
    return --description_depth;
}
static void indent_depth(const char *s) {
    int i;
    for (i=0; i<description_depth; ++i) {
        printf("%s", s);
    }
}
static void tab_depth() {
    indent_depth("    ");
}



// 
void ast_list_traverse(struct ast_list *list) {
    
}
// 
void ast_list_node_describe(struct ast_list_node *node) {
    
}
void ast_list_node_action(struct ast_list_node *node) {
    
}






// 
void ast_library_text_describe(FILE *out, struct ast_library_text *this) {
    
}
// 
void ast_library_text_action(FILE *out, struct ast_library_text *this) {
    
}



// 
void ast_library_description_describe(FILE *out, struct ast_library_description *this) {
    
}
// 
void ast_library_description_action(FILE *out, struct ast_library_description *this) {
    
}



// 
void ast_library_declaration_describe(FILE *out, struct ast_library_declaration *this) {
    
}
// 
void ast_library_declaration_action(FILE *out, struct ast_library_declaration *this) {
    
}



// 
void ast_include_statement_describe(FILE *out, struct ast_include_statement *this) {
    
}
// 
void ast_include_statement_action(FILE *out, struct ast_include_statement *this) {
    
}



// 
void ast_source_text_describe(FILE *out, struct ast_source_text *this) {
    
}
// 
void ast_source_text_action(FILE *out, struct ast_source_text *this) {
    
}



// 
void ast_description_describe(FILE *out, struct ast_description *this) {
    
}
// 
void ast_description_action(FILE *out, struct ast_description *this) {
    
}



// 
void ast_module_nonansi_header_describe(FILE *out, struct ast_module_nonansi_header *this) {
    
}
// 
void ast_module_nonansi_header_action(FILE *out, struct ast_module_nonansi_header *this) {
    
}



// 
void ast_module_ansi_header_describe(FILE *out, struct ast_module_ansi_header *this) {
    
}
// 
void ast_module_ansi_header_action(FILE *out, struct ast_module_ansi_header *this) {
    
}



// 
void ast_module_declaration_describe(FILE *out, struct ast_module_declaration *this) {
    
}
// 
void ast_module_declaration_action(FILE *out, struct ast_module_declaration *this) {
    
}



// 
void ast_module_keyword_describe(FILE *out, struct ast_module_keyword *this) {
    
}
// 
void ast_module_keyword_action(FILE *out, struct ast_module_keyword *this) {
    
}



// 
void ast_interface_declaration_describe(FILE *out, struct ast_interface_declaration *this) {
    
}
// 
void ast_interface_declaration_action(FILE *out, struct ast_interface_declaration *this) {
    
}



// 
void ast_interface_nonansi_header_describe(FILE *out, struct ast_interface_nonansi_header *this) {
    
}
// 
void ast_interface_nonansi_header_action(FILE *out, struct ast_interface_nonansi_header *this) {
    
}



// 
void ast_interface_ansi_header_describe(FILE *out, struct ast_interface_ansi_header *this) {
    
}
// 
void ast_interface_ansi_header_action(FILE *out, struct ast_interface_ansi_header *this) {
    
}



// 
void ast_program_declaration_describe(FILE *out, struct ast_program_declaration *this) {
    
}
// 
void ast_program_declaration_action(FILE *out, struct ast_program_declaration *this) {
    
}



// 
void ast_program_nonansi_header_describe(FILE *out, struct ast_program_nonansi_header *this) {
    
}
// 
void ast_program_nonansi_header_action(FILE *out, struct ast_program_nonansi_header *this) {
    
}



// 
void ast_program_ansi_header_describe(FILE *out, struct ast_program_ansi_header *this) {
    
}
// 
void ast_program_ansi_header_action(FILE *out, struct ast_program_ansi_header *this) {
    
}



// 
void ast_checker_declaration_describe(FILE *out, struct ast_checker_declaration *this) {
    
}
// 
void ast_checker_declaration_action(FILE *out, struct ast_checker_declaration *this) {
    
}



// 
void ast_class_declaration_describe(FILE *out, struct ast_class_declaration *this) {
    
}
// 
void ast_class_declaration_action(FILE *out, struct ast_class_declaration *this) {
    
}



// 
void ast_interface_class_type_describe(FILE *out, struct ast_interface_class_type *this) {
    
}
// 
void ast_interface_class_type_action(FILE *out, struct ast_interface_class_type *this) {
    
}



// 
void ast_interface_class_declaration_describe(FILE *out, struct ast_interface_class_declaration *this) {
    
}
// 
void ast_interface_class_declaration_action(FILE *out, struct ast_interface_class_declaration *this) {
    
}



// 
void ast_interface_class_item_describe(FILE *out, struct ast_interface_class_item *this) {
    
}
// 
void ast_interface_class_item_action(FILE *out, struct ast_interface_class_item *this) {
    
}



// 
void ast_interface_class_method_describe(FILE *out, struct ast_interface_class_method *this) {
    
}
// 
void ast_interface_class_method_action(FILE *out, struct ast_interface_class_method *this) {
    
}



// 
void ast_package_declaration_describe(FILE *out, struct ast_package_declaration *this) {
    
}
// 
void ast_package_declaration_action(FILE *out, struct ast_package_declaration *this) {
    
}



// 
void ast_timeunits_declaration_describe(FILE *out, struct ast_timeunits_declaration *this) {
    
}
// 
void ast_timeunits_declaration_action(FILE *out, struct ast_timeunits_declaration *this) {
    
}



// 
void ast_parameter_port_list_describe(FILE *out, struct ast_parameter_port_list *this) {
    
}
// 
void ast_parameter_port_list_action(FILE *out, struct ast_parameter_port_list *this) {
    
}



// 
void ast_parameter_port_declaration_describe(FILE *out, struct ast_parameter_port_declaration *this) {
    
}
// 
void ast_parameter_port_declaration_action(FILE *out, struct ast_parameter_port_declaration *this) {
    
}



// 
void ast_list_of_ports_describe(FILE *out, struct ast_list_of_ports *this) {
    
}
// 
void ast_list_of_ports_action(FILE *out, struct ast_list_of_ports *this) {
    
}



// 
void ast_list_of_port_declarations_describe(FILE *out, struct ast_list_of_port_declarations *this) {
    
}
// 
void ast_list_of_port_declarations_action(FILE *out, struct ast_list_of_port_declarations *this) {
    
}



// 
void ast_port_declaration_describe(FILE *out, struct ast_port_declaration *this) {
    
}
// 
void ast_port_declaration_action(FILE *out, struct ast_port_declaration *this) {
    
}



// 
void ast_port_describe(FILE *out, struct ast_port *this) {
    
}
// 
void ast_port_action(FILE *out, struct ast_port *this) {
    
}



// 
void ast_port_expression_describe(FILE *out, struct ast_port_expression *this) {
    
}
// 
void ast_port_expression_action(FILE *out, struct ast_port_expression *this) {
    
}



// 
void ast_port_reference_describe(FILE *out, struct ast_port_reference *this) {
    
}
// 
void ast_port_reference_action(FILE *out, struct ast_port_reference *this) {
    
}



// 
void ast_port_direction_describe(FILE *out, struct ast_port_direction *this) {
    
}
// 
void ast_port_direction_action(FILE *out, struct ast_port_direction *this) {
    
}



// 
void ast_net_port_header_describe(FILE *out, struct ast_net_port_header *this) {
    
}
// 
void ast_net_port_header_action(FILE *out, struct ast_net_port_header *this) {
    
}



// 
void ast_variable_port_header_describe(FILE *out, struct ast_variable_port_header *this) {
    
}
// 
void ast_variable_port_header_action(FILE *out, struct ast_variable_port_header *this) {
    
}



// 
void ast_interface_port_header_describe(FILE *out, struct ast_interface_port_header *this) {
    
}
// 
void ast_interface_port_header_action(FILE *out, struct ast_interface_port_header *this) {
    
}



// 
void ast_ansi_port_declaration_describe(FILE *out, struct ast_ansi_port_declaration *this) {
    
}
// 
void ast_ansi_port_declaration_action(FILE *out, struct ast_ansi_port_declaration *this) {
    
}



// 
void ast_elaboration_system_task_describe(FILE *out, struct ast_elaboration_system_task *this) {
    
}
// 
void ast_elaboration_system_task_action(FILE *out, struct ast_elaboration_system_task *this) {
    
}



// 
void ast_finish_number_describe(FILE *out, struct ast_finish_number *this) {
    
}
// 
void ast_finish_number_action(FILE *out, struct ast_finish_number *this) {
    
}



// 
void ast_module_common_item_describe(FILE *out, struct ast_module_common_item *this) {
    
}
// 
void ast_module_common_item_action(FILE *out, struct ast_module_common_item *this) {
    
}



// 
void ast_module_item_describe(FILE *out, struct ast_module_item *this) {
    
}
// 
void ast_module_item_action(FILE *out, struct ast_module_item *this) {
    
}



// 
void ast_module_or_generate_item_describe(FILE *out, struct ast_module_or_generate_item *this) {
    
}
// 
void ast_module_or_generate_item_action(FILE *out, struct ast_module_or_generate_item *this) {
    
}



// 
void ast_module_or_generate_item_declaration_describe(FILE *out, struct ast_module_or_generate_item_declaration *this) {
    
}
// 
void ast_module_or_generate_item_declaration_action(FILE *out, struct ast_module_or_generate_item_declaration *this) {
    
}



// 
void ast_non_port_module_item_describe(FILE *out, struct ast_non_port_module_item *this) {
    
}
// 
void ast_non_port_module_item_action(FILE *out, struct ast_non_port_module_item *this) {
    
}



// 
void ast_parameter_override_describe(FILE *out, struct ast_parameter_override *this) {
    
}
// 
void ast_parameter_override_action(FILE *out, struct ast_parameter_override *this) {
    
}



// 
void ast_bind_directive_describe(FILE *out, struct ast_bind_directive *this) {
    
}
// 
void ast_bind_directive_action(FILE *out, struct ast_bind_directive *this) {
    
}



// 
void ast_bind_target_scope_describe(FILE *out, struct ast_bind_target_scope *this) {
    
}
// 
void ast_bind_target_scope_action(FILE *out, struct ast_bind_target_scope *this) {
    
}



// 
void ast_bind_target_instance_describe(FILE *out, struct ast_bind_target_instance *this) {
    
}
// 
void ast_bind_target_instance_action(FILE *out, struct ast_bind_target_instance *this) {
    
}



// 
void ast_bind_target_instance_list_describe(FILE *out, struct ast_bind_target_instance_list *this) {
    
}
// 
void ast_bind_target_instance_list_action(FILE *out, struct ast_bind_target_instance_list *this) {
    
}



// 
void ast_bind_instantiation_describe(FILE *out, struct ast_bind_instantiation *this) {
    
}
// 
void ast_bind_instantiation_action(FILE *out, struct ast_bind_instantiation *this) {
    
}



// 
void ast_config_declaration_describe(FILE *out, struct ast_config_declaration *this) {
    
}
// 
void ast_config_declaration_action(FILE *out, struct ast_config_declaration *this) {
    
}



// 
void ast_design_statement_describe(FILE *out, struct ast_design_statement *this) {
    
}
// 
void ast_design_statement_action(FILE *out, struct ast_design_statement *this) {
    
}



// 
void ast_config_rule_statement_describe(FILE *out, struct ast_config_rule_statement *this) {
    
}
// 
void ast_config_rule_statement_action(FILE *out, struct ast_config_rule_statement *this) {
    
}



// 
void ast_default_clause_describe(FILE *out, struct ast_default_clause *this) {
    
}
// 
void ast_default_clause_action(FILE *out, struct ast_default_clause *this) {
    
}



// 
void ast_inst_clause_describe(FILE *out, struct ast_inst_clause *this) {
    
}
// 
void ast_inst_clause_action(FILE *out, struct ast_inst_clause *this) {
    
}



// 
void ast_inst_name_describe(FILE *out, struct ast_inst_name *this) {
    
}
// 
void ast_inst_name_action(FILE *out, struct ast_inst_name *this) {
    
}



// 
void ast_cell_clause_describe(FILE *out, struct ast_cell_clause *this) {
    
}
// 
void ast_cell_clause_action(FILE *out, struct ast_cell_clause *this) {
    
}



// 
void ast_liblist_clause_describe(FILE *out, struct ast_liblist_clause *this) {
    
}
// 
void ast_liblist_clause_action(FILE *out, struct ast_liblist_clause *this) {
    
}



// 
void ast_use_clause_describe(FILE *out, struct ast_use_clause *this) {
    
}
// 
void ast_use_clause_action(FILE *out, struct ast_use_clause *this) {
    
}



// 
void ast_interface_or_generate_item_describe(FILE *out, struct ast_interface_or_generate_item *this) {
    
}
// 
void ast_interface_or_generate_item_action(FILE *out, struct ast_interface_or_generate_item *this) {
    
}



// 
void ast_extern_tf_declaration_describe(FILE *out, struct ast_extern_tf_declaration *this) {
    
}
// 
void ast_extern_tf_declaration_action(FILE *out, struct ast_extern_tf_declaration *this) {
    
}



// 
void ast_interface_item_describe(FILE *out, struct ast_interface_item *this) {
    
}
// 
void ast_interface_item_action(FILE *out, struct ast_interface_item *this) {
    
}



// 
void ast_non_port_interface_item_describe(FILE *out, struct ast_non_port_interface_item *this) {
    
}
// 
void ast_non_port_interface_item_action(FILE *out, struct ast_non_port_interface_item *this) {
    
}



// 
void ast_program_item_describe(FILE *out, struct ast_program_item *this) {
    
}
// 
void ast_program_item_action(FILE *out, struct ast_program_item *this) {
    
}



// 
void ast_non_port_program_item_describe(FILE *out, struct ast_non_port_program_item *this) {
    
}
// 
void ast_non_port_program_item_action(FILE *out, struct ast_non_port_program_item *this) {
    
}



// 
void ast_program_generate_item_describe(FILE *out, struct ast_program_generate_item *this) {
    
}
// 
void ast_program_generate_item_action(FILE *out, struct ast_program_generate_item *this) {
    
}



// 
void ast_checker_port_list_describe(FILE *out, struct ast_checker_port_list *this) {
    
}
// 
void ast_checker_port_list_action(FILE *out, struct ast_checker_port_list *this) {
    
}



// 
void ast_checker_port_item_describe(FILE *out, struct ast_checker_port_item *this) {
    
}
// 
void ast_checker_port_item_action(FILE *out, struct ast_checker_port_item *this) {
    
}



// 
void ast_checker_port_direction_describe(FILE *out, struct ast_checker_port_direction *this) {
    
}
// 
void ast_checker_port_direction_action(FILE *out, struct ast_checker_port_direction *this) {
    
}



// 
void ast_checker_or_generate_item_describe(FILE *out, struct ast_checker_or_generate_item *this) {
    
}
// 
void ast_checker_or_generate_item_action(FILE *out, struct ast_checker_or_generate_item *this) {
    
}



// 
void ast_checker_or_generate_item_declaration_describe(FILE *out, struct ast_checker_or_generate_item_declaration *this) {
    
}
// 
void ast_checker_or_generate_item_declaration_action(FILE *out, struct ast_checker_or_generate_item_declaration *this) {
    
}



// 
void ast_checker_generate_item_describe(FILE *out, struct ast_checker_generate_item *this) {
    
}
// 
void ast_checker_generate_item_action(FILE *out, struct ast_checker_generate_item *this) {
    
}



// 
void ast_class_item_describe(FILE *out, struct ast_class_item *this) {
    
}
// 
void ast_class_item_action(FILE *out, struct ast_class_item *this) {
    
}



// 
void ast_class_property_describe(FILE *out, struct ast_class_property *this) {
    
}
// 
void ast_class_property_action(FILE *out, struct ast_class_property *this) {
    
}



// 
void ast_class_method_describe(FILE *out, struct ast_class_method *this) {
    
}
// 
void ast_class_method_action(FILE *out, struct ast_class_method *this) {
    
}



// 
void ast_class_constructor_prototype_describe(FILE *out, struct ast_class_constructor_prototype *this) {
    
}
// 
void ast_class_constructor_prototype_action(FILE *out, struct ast_class_constructor_prototype *this) {
    
}



// 
void ast_class_constraint_describe(FILE *out, struct ast_class_constraint *this) {
    
}
// 
void ast_class_constraint_action(FILE *out, struct ast_class_constraint *this) {
    
}



// 
void ast_class_item_qualifier_describe(FILE *out, struct ast_class_item_qualifier *this) {
    
}
// 
void ast_class_item_qualifier_action(FILE *out, struct ast_class_item_qualifier *this) {
    
}



// 
void ast_property_qualifier_describe(FILE *out, struct ast_property_qualifier *this) {
    
}
// 
void ast_property_qualifier_action(FILE *out, struct ast_property_qualifier *this) {
    
}



// 
void ast_random_qualifier_describe(FILE *out, struct ast_random_qualifier *this) {
    
}
// 
void ast_random_qualifier_action(FILE *out, struct ast_random_qualifier *this) {
    
}



// 
void ast_method_qualifier_describe(FILE *out, struct ast_method_qualifier *this) {
    
}
// 
void ast_method_qualifier_action(FILE *out, struct ast_method_qualifier *this) {
    
}



// 
void ast_method_prototype_describe(FILE *out, struct ast_method_prototype *this) {
    
}
// 
void ast_method_prototype_action(FILE *out, struct ast_method_prototype *this) {
    
}



// 
void ast_class_constructor_declaration_describe(FILE *out, struct ast_class_constructor_declaration *this) {
    
}
// 
void ast_class_constructor_declaration_action(FILE *out, struct ast_class_constructor_declaration *this) {
    
}



// 
void ast_constraint_declaration_describe(FILE *out, struct ast_constraint_declaration *this) {
    
}
// 
void ast_constraint_declaration_action(FILE *out, struct ast_constraint_declaration *this) {
    
}



// 
void ast_constraint_block_describe(FILE *out, struct ast_constraint_block *this) {
    
}
// 
void ast_constraint_block_action(FILE *out, struct ast_constraint_block *this) {
    
}



// 
void ast_constraint_block_item_describe(FILE *out, struct ast_constraint_block_item *this) {
    
}
// 
void ast_constraint_block_item_action(FILE *out, struct ast_constraint_block_item *this) {
    
}



// 
void ast_solve_before_list_describe(FILE *out, struct ast_solve_before_list *this) {
    
}
// 
void ast_solve_before_list_action(FILE *out, struct ast_solve_before_list *this) {
    
}



// 
void ast_constraint_primary_describe(FILE *out, struct ast_constraint_primary *this) {
    
}
// 
void ast_constraint_primary_action(FILE *out, struct ast_constraint_primary *this) {
    
}



// 
void ast_constraint_expression_describe(FILE *out, struct ast_constraint_expression *this) {
    
}
// 
void ast_constraint_expression_action(FILE *out, struct ast_constraint_expression *this) {
    
}



// 
void ast_uniqueness_constraint_describe(FILE *out, struct ast_uniqueness_constraint *this) {
    
}
// 
void ast_uniqueness_constraint_action(FILE *out, struct ast_uniqueness_constraint *this) {
    
}



// 
void ast_constraint_set_describe(FILE *out, struct ast_constraint_set *this) {
    
}
// 
void ast_constraint_set_action(FILE *out, struct ast_constraint_set *this) {
    
}



// 
void ast_dist_list_describe(FILE *out, struct ast_dist_list *this) {
    
}
// 
void ast_dist_list_action(FILE *out, struct ast_dist_list *this) {
    
}



// 
void ast_dist_item_describe(FILE *out, struct ast_dist_item *this) {
    
}
// 
void ast_dist_item_action(FILE *out, struct ast_dist_item *this) {
    
}



// 
void ast_dist_weight_describe(FILE *out, struct ast_dist_weight *this) {
    
}
// 
void ast_dist_weight_action(FILE *out, struct ast_dist_weight *this) {
    
}



// 
void ast_constraint_prototype_describe(FILE *out, struct ast_constraint_prototype *this) {
    
}
// 
void ast_constraint_prototype_action(FILE *out, struct ast_constraint_prototype *this) {
    
}



// 
void ast_constraint_prototype_qualifier_describe(FILE *out, struct ast_constraint_prototype_qualifier *this) {
    
}
// 
void ast_constraint_prototype_qualifier_action(FILE *out, struct ast_constraint_prototype_qualifier *this) {
    
}



// 
void ast_extern_constraint_declaration_describe(FILE *out, struct ast_extern_constraint_declaration *this) {
    
}
// 
void ast_extern_constraint_declaration_action(FILE *out, struct ast_extern_constraint_declaration *this) {
    
}



// 
void ast_identifier_list_describe(FILE *out, struct ast_identifier_list *this) {
    
}
// 
void ast_identifier_list_action(FILE *out, struct ast_identifier_list *this) {
    
}



// 
void ast_package_item_describe(FILE *out, struct ast_package_item *this) {
    
}
// 
void ast_package_item_action(FILE *out, struct ast_package_item *this) {
    
}



// 
void ast_package_or_generate_item_declaration_describe(FILE *out, struct ast_package_or_generate_item_declaration *this) {
    
}
// 
void ast_package_or_generate_item_declaration_action(FILE *out, struct ast_package_or_generate_item_declaration *this) {
    
}



// 
void ast_anonymous_program_describe(FILE *out, struct ast_anonymous_program *this) {
    
}
// 
void ast_anonymous_program_action(FILE *out, struct ast_anonymous_program *this) {
    
}



// 
void ast_anonymous_program_item_describe(FILE *out, struct ast_anonymous_program_item *this) {
    
}
// 
void ast_anonymous_program_item_action(FILE *out, struct ast_anonymous_program_item *this) {
    
}



// 
void ast_local_parameter_declaration_describe(FILE *out, struct ast_local_parameter_declaration *this) {
    
}
// 
void ast_local_parameter_declaration_action(FILE *out, struct ast_local_parameter_declaration *this) {
    
}



// 
void ast_parameter_declaration_describe(FILE *out, struct ast_parameter_declaration *this) {
    
}
// 
void ast_parameter_declaration_action(FILE *out, struct ast_parameter_declaration *this) {
    
}



// 
void ast_specparam_declaration_describe(FILE *out, struct ast_specparam_declaration *this) {
    
}
// 
void ast_specparam_declaration_action(FILE *out, struct ast_specparam_declaration *this) {
    
}



// 
void ast_inout_declaration_describe(FILE *out, struct ast_inout_declaration *this) {
    
}
// 
void ast_inout_declaration_action(FILE *out, struct ast_inout_declaration *this) {
    
}



// 
void ast_input_declaration_describe(FILE *out, struct ast_input_declaration *this) {
    
}
// 
void ast_input_declaration_action(FILE *out, struct ast_input_declaration *this) {
    
}



// 
void ast_output_declaration_describe(FILE *out, struct ast_output_declaration *this) {
    
}
// 
void ast_output_declaration_action(FILE *out, struct ast_output_declaration *this) {
    
}



// 
void ast_interface_port_declaration_describe(FILE *out, struct ast_interface_port_declaration *this) {
    
}
// 
void ast_interface_port_declaration_action(FILE *out, struct ast_interface_port_declaration *this) {
    
}



// 
void ast_ref_declaration_describe(FILE *out, struct ast_ref_declaration *this) {
    
}
// 
void ast_ref_declaration_action(FILE *out, struct ast_ref_declaration *this) {
    
}



// 
void ast_data_declaration_describe(FILE *out, struct ast_data_declaration *this) {
    
}
// 
void ast_data_declaration_action(FILE *out, struct ast_data_declaration *this) {
    
}



// 
void ast_package_import_declaration_describe(FILE *out, struct ast_package_import_declaration *this) {
    
}
// 
void ast_package_import_declaration_action(FILE *out, struct ast_package_import_declaration *this) {
    
}



// 
void ast_package_import_item_describe(FILE *out, struct ast_package_import_item *this) {
    
}
// 
void ast_package_import_item_action(FILE *out, struct ast_package_import_item *this) {
    
}



// 
void ast_package_export_declaration_describe(FILE *out, struct ast_package_export_declaration *this) {
    
}
// 
void ast_package_export_declaration_action(FILE *out, struct ast_package_export_declaration *this) {
    
}



// 
void ast_genvar_declaration_describe(FILE *out, struct ast_genvar_declaration *this) {
    
}
// 
void ast_genvar_declaration_action(FILE *out, struct ast_genvar_declaration *this) {
    
}



// 
void ast_net_declaration_describe(FILE *out, struct ast_net_declaration *this) {
    
}
// 
void ast_net_declaration_action(FILE *out, struct ast_net_declaration *this) {
    
}



// 
void ast_type_declaration_describe(FILE *out, struct ast_type_declaration *this) {
    
}
// 
void ast_type_declaration_action(FILE *out, struct ast_type_declaration *this) {
    
}



// 
void ast_net_type_declaration_describe(FILE *out, struct ast_net_type_declaration *this) {
    
}
// 
void ast_net_type_declaration_action(FILE *out, struct ast_net_type_declaration *this) {
    
}



// 
void ast_lifetime_describe(FILE *out, struct ast_lifetime *this) {
    
}
// 
void ast_lifetime_action(FILE *out, struct ast_lifetime *this) {
    
}



// 
void ast_casting_type_describe(FILE *out, struct ast_casting_type *this) {
    
}
// 
void ast_casting_type_action(FILE *out, struct ast_casting_type *this) {
    
}



// 
void ast_data_type_describe(FILE *out, struct ast_data_type *this) {
    
}
// 
void ast_data_type_action(FILE *out, struct ast_data_type *this) {
    
}



// 
void ast_data_type_or_implicit_describe(FILE *out, struct ast_data_type_or_implicit *this) {
    
}
// 
void ast_data_type_or_implicit_action(FILE *out, struct ast_data_type_or_implicit *this) {
    
}



// 
void ast_implicit_data_type_describe(FILE *out, struct ast_implicit_data_type *this) {
    
}
// 
void ast_implicit_data_type_action(FILE *out, struct ast_implicit_data_type *this) {
    
}



// 
void ast_enum_base_type_describe(FILE *out, struct ast_enum_base_type *this) {
    
}
// 
void ast_enum_base_type_action(FILE *out, struct ast_enum_base_type *this) {
    
}



// 
void ast_enum_name_declaration_describe(FILE *out, struct ast_enum_name_declaration *this) {
    
}
// 
void ast_enum_name_declaration_action(FILE *out, struct ast_enum_name_declaration *this) {
    
}



// 
void ast_class_scope_describe(FILE *out, struct ast_class_scope *this) {
    
}
// 
void ast_class_scope_action(FILE *out, struct ast_class_scope *this) {
    
}



// 
void ast_class_type_describe(FILE *out, struct ast_class_type *this) {
    
}
// 
void ast_class_type_action(FILE *out, struct ast_class_type *this) {
    
}



// 
void ast_integer_type_describe(FILE *out, struct ast_integer_type *this) {
    
}
// 
void ast_integer_type_action(FILE *out, struct ast_integer_type *this) {
    
}



// 
void ast_integer_atom_type_describe(FILE *out, struct ast_integer_atom_type *this) {
    
}
// 
void ast_integer_atom_type_action(FILE *out, struct ast_integer_atom_type *this) {
    
}



// 
void ast_integer_vector_type_describe(FILE *out, struct ast_integer_vector_type *this) {
    
}
// 
void ast_integer_vector_type_action(FILE *out, struct ast_integer_vector_type *this) {
    
}



// 
void ast_non_integer_type_describe(FILE *out, struct ast_non_integer_type *this) {
    
}
// 
void ast_non_integer_type_action(FILE *out, struct ast_non_integer_type *this) {
    
}



// 
void ast_net_type_describe(FILE *out, struct ast_net_type *this) {
    
}
// 
void ast_net_type_action(FILE *out, struct ast_net_type *this) {
    
}



// 
void ast_net_port_type_describe(FILE *out, struct ast_net_port_type *this) {
    
}
// 
void ast_net_port_type_action(FILE *out, struct ast_net_port_type *this) {
    
}



// 
void ast_variable_port_type_describe(FILE *out, struct ast_variable_port_type *this) {
    
}
// 
void ast_variable_port_type_action(FILE *out, struct ast_variable_port_type *this) {
    
}



// 
void ast_var_data_type_describe(FILE *out, struct ast_var_data_type *this) {
    
}
// 
void ast_var_data_type_action(FILE *out, struct ast_var_data_type *this) {
    
}



// 
void ast_signing_describe(FILE *out, struct ast_signing *this) {
    
}
// 
void ast_signing_action(FILE *out, struct ast_signing *this) {
    
}



// 
void ast_simple_type_describe(FILE *out, struct ast_simple_type *this) {
    
}
// 
void ast_simple_type_action(FILE *out, struct ast_simple_type *this) {
    
}



// 
void ast_struct_union_member_describe(FILE *out, struct ast_struct_union_member *this) {
    
}
// 
void ast_struct_union_member_action(FILE *out, struct ast_struct_union_member *this) {
    
}



// 
void ast_data_type_or_void_describe(FILE *out, struct ast_data_type_or_void *this) {
    
}
// 
void ast_data_type_or_void_action(FILE *out, struct ast_data_type_or_void *this) {
    
}



// 
void ast_struct_union_describe(FILE *out, struct ast_struct_union *this) {
    
}
// 
void ast_struct_union_action(FILE *out, struct ast_struct_union *this) {
    
}



// 
void ast_type_reference_describe(FILE *out, struct ast_type_reference *this) {
    
}
// 
void ast_type_reference_action(FILE *out, struct ast_type_reference *this) {
    
}



// 
void ast_drive_strength_describe(FILE *out, struct ast_drive_strength *this) {
    
}
// 
void ast_drive_strength_action(FILE *out, struct ast_drive_strength *this) {
    
}



// 
void ast_strength0_describe(FILE *out, struct ast_strength0 *this) {
    
}
// 
void ast_strength0_action(FILE *out, struct ast_strength0 *this) {
    
}



// 
void ast_strength1_describe(FILE *out, struct ast_strength1 *this) {
    
}
// 
void ast_strength1_action(FILE *out, struct ast_strength1 *this) {
    
}



// 
void ast_charge_strength_describe(FILE *out, struct ast_charge_strength *this) {
    
}
// 
void ast_charge_strength_action(FILE *out, struct ast_charge_strength *this) {
    
}



// 
void ast_delay3_describe(FILE *out, struct ast_delay3 *this) {
    
}
// 
void ast_delay3_action(FILE *out, struct ast_delay3 *this) {
    
}



// 
void ast_delay2_describe(FILE *out, struct ast_delay2 *this) {
    
}
// 
void ast_delay2_action(FILE *out, struct ast_delay2 *this) {
    
}



// 
void ast_delay_value_describe(FILE *out, struct ast_delay_value *this) {
    
}
// 
void ast_delay_value_action(FILE *out, struct ast_delay_value *this) {
    
}



// 
void ast_list_of_defparam_assignments_describe(FILE *out, struct ast_list_of_defparam_assignments *this) {
    
}
// 
void ast_list_of_defparam_assignments_action(FILE *out, struct ast_list_of_defparam_assignments *this) {
    
}



// 
void ast_list_of_genvar_identifiers_describe(FILE *out, struct ast_list_of_genvar_identifiers *this) {
    
}
// 
void ast_list_of_genvar_identifiers_action(FILE *out, struct ast_list_of_genvar_identifiers *this) {
    
}



// 
void ast_list_of_interface_identifiers_describe(FILE *out, struct ast_list_of_interface_identifiers *this) {
    
}
// 
void ast_list_of_interface_identifiers_action(FILE *out, struct ast_list_of_interface_identifiers *this) {
    
}



// 
void ast_list_of_net_decl_assignments_describe(FILE *out, struct ast_list_of_net_decl_assignments *this) {
    
}
// 
void ast_list_of_net_decl_assignments_action(FILE *out, struct ast_list_of_net_decl_assignments *this) {
    
}



// 
void ast_list_of_param_assignments_describe(FILE *out, struct ast_list_of_param_assignments *this) {
    
}
// 
void ast_list_of_param_assignments_action(FILE *out, struct ast_list_of_param_assignments *this) {
    
}



// 
void ast_list_of_port_identifiers_describe(FILE *out, struct ast_list_of_port_identifiers *this) {
    
}
// 
void ast_list_of_port_identifiers_action(FILE *out, struct ast_list_of_port_identifiers *this) {
    
}



// 
void ast_list_of_udp_port_identifiers_describe(FILE *out, struct ast_list_of_udp_port_identifiers *this) {
    
}
// 
void ast_list_of_udp_port_identifiers_action(FILE *out, struct ast_list_of_udp_port_identifiers *this) {
    
}



// 
void ast_list_of_specparam_assignments_describe(FILE *out, struct ast_list_of_specparam_assignments *this) {
    
}
// 
void ast_list_of_specparam_assignments_action(FILE *out, struct ast_list_of_specparam_assignments *this) {
    
}



// 
void ast_list_of_tf_variable_identifiers_describe(FILE *out, struct ast_list_of_tf_variable_identifiers *this) {
    
}
// 
void ast_list_of_tf_variable_identifiers_action(FILE *out, struct ast_list_of_tf_variable_identifiers *this) {
    
}



// 
void ast_list_of_type_assignments_describe(FILE *out, struct ast_list_of_type_assignments *this) {
    
}
// 
void ast_list_of_type_assignments_action(FILE *out, struct ast_list_of_type_assignments *this) {
    
}



// 
void ast_list_of_variable_decl_assignments_describe(FILE *out, struct ast_list_of_variable_decl_assignments *this) {
    
}
// 
void ast_list_of_variable_decl_assignments_action(FILE *out, struct ast_list_of_variable_decl_assignments *this) {
    
}



// 
void ast_list_of_variable_identifiers_describe(FILE *out, struct ast_list_of_variable_identifiers *this) {
    
}
// 
void ast_list_of_variable_identifiers_action(FILE *out, struct ast_list_of_variable_identifiers *this) {
    
}



// 
void ast_list_of_variable_port_identifiers_describe(FILE *out, struct ast_list_of_variable_port_identifiers *this) {
    
}
// 
void ast_list_of_variable_port_identifiers_action(FILE *out, struct ast_list_of_variable_port_identifiers *this) {
    
}



// 
void ast_defparam_assignment_describe(FILE *out, struct ast_defparam_assignment *this) {
    
}
// 
void ast_defparam_assignment_action(FILE *out, struct ast_defparam_assignment *this) {
    
}



// 
void ast_net_decl_assignment_describe(FILE *out, struct ast_net_decl_assignment *this) {
    
}
// 
void ast_net_decl_assignment_action(FILE *out, struct ast_net_decl_assignment *this) {
    
}



// 
void ast_param_assignment_describe(FILE *out, struct ast_param_assignment *this) {
    
}
// 
void ast_param_assignment_action(FILE *out, struct ast_param_assignment *this) {
    
}



// 
void ast_specparam_assignment_describe(FILE *out, struct ast_specparam_assignment *this) {
    
}
// 
void ast_specparam_assignment_action(FILE *out, struct ast_specparam_assignment *this) {
    
}



// 
void ast_type_assignment_describe(FILE *out, struct ast_type_assignment *this) {
    
}
// 
void ast_type_assignment_action(FILE *out, struct ast_type_assignment *this) {
    
}



// 
void ast_pulse_control_specparam_describe(FILE *out, struct ast_pulse_control_specparam *this) {
    
}
// 
void ast_pulse_control_specparam_action(FILE *out, struct ast_pulse_control_specparam *this) {
    
}



// 
void ast_error_limit_value_describe(FILE *out, struct ast_error_limit_value *this) {
    
}
// 
void ast_error_limit_value_action(FILE *out, struct ast_error_limit_value *this) {
    
}



// 
void ast_reject_limit_value_describe(FILE *out, struct ast_reject_limit_value *this) {
    
}
// 
void ast_reject_limit_value_action(FILE *out, struct ast_reject_limit_value *this) {
    
}



// 
void ast_limit_value_describe(FILE *out, struct ast_limit_value *this) {
    
}
// 
void ast_limit_value_action(FILE *out, struct ast_limit_value *this) {
    
}



// 
void ast_variable_decl_assignment_describe(FILE *out, struct ast_variable_decl_assignment *this) {
    
}
// 
void ast_variable_decl_assignment_action(FILE *out, struct ast_variable_decl_assignment *this) {
    
}



// 
void ast_class_new_describe(FILE *out, struct ast_class_new *this) {
    
}
// 
void ast_class_new_action(FILE *out, struct ast_class_new *this) {
    
}



// 
void ast_dynamic_array_new_describe(FILE *out, struct ast_dynamic_array_new *this) {
    
}
// 
void ast_dynamic_array_new_action(FILE *out, struct ast_dynamic_array_new *this) {
    
}



// 
void ast_unpacked_dimension_describe(FILE *out, struct ast_unpacked_dimension *this) {
    
}
// 
void ast_unpacked_dimension_action(FILE *out, struct ast_unpacked_dimension *this) {
    
}



// 
void ast_packed_dimension_describe(FILE *out, struct ast_packed_dimension *this) {
    
}
// 
void ast_packed_dimension_action(FILE *out, struct ast_packed_dimension *this) {
    
}



// 
void ast_associative_dimension_describe(FILE *out, struct ast_associative_dimension *this) {
    
}
// 
void ast_associative_dimension_action(FILE *out, struct ast_associative_dimension *this) {
    
}



// 
void ast_variable_dimension_describe(FILE *out, struct ast_variable_dimension *this) {
    
}
// 
void ast_variable_dimension_action(FILE *out, struct ast_variable_dimension *this) {
    
}



// 
void ast_queue_dimension_describe(FILE *out, struct ast_queue_dimension *this) {
    
}
// 
void ast_queue_dimension_action(FILE *out, struct ast_queue_dimension *this) {
    
}



// 
void ast_unsized_dimension_describe(FILE *out, struct ast_unsized_dimension *this) {
    
}
// 
void ast_unsized_dimension_action(FILE *out, struct ast_unsized_dimension *this) {
    
}



// 
void ast_function_data_type_or_implicit_describe(FILE *out, struct ast_function_data_type_or_implicit *this) {
    
}
// 
void ast_function_data_type_or_implicit_action(FILE *out, struct ast_function_data_type_or_implicit *this) {
    
}



// 
void ast_function_declaration_describe(FILE *out, struct ast_function_declaration *this) {
    
}
// 
void ast_function_declaration_action(FILE *out, struct ast_function_declaration *this) {
    
}



// 
void ast_function_body_declaration_describe(FILE *out, struct ast_function_body_declaration *this) {
    
}
// 
void ast_function_body_declaration_action(FILE *out, struct ast_function_body_declaration *this) {
    
}



// 
void ast_function_prototype_describe(FILE *out, struct ast_function_prototype *this) {
    
}
// 
void ast_function_prototype_action(FILE *out, struct ast_function_prototype *this) {
    
}



// 
void ast_dpi_import_export_describe(FILE *out, struct ast_dpi_import_export *this) {
    
}
// 
void ast_dpi_import_export_action(FILE *out, struct ast_dpi_import_export *this) {
    
}



// 
void ast_dpi_spec_string_describe(FILE *out, struct ast_dpi_spec_string *this) {
    
}
// 
void ast_dpi_spec_string_action(FILE *out, struct ast_dpi_spec_string *this) {
    
}



// 
void ast_dpi_function_import_property_describe(FILE *out, struct ast_dpi_function_import_property *this) {
    
}
// 
void ast_dpi_function_import_property_action(FILE *out, struct ast_dpi_function_import_property *this) {
    
}



// 
void ast_dpi_task_import_property_describe(FILE *out, struct ast_dpi_task_import_property *this) {
    
}
// 
void ast_dpi_task_import_property_action(FILE *out, struct ast_dpi_task_import_property *this) {
    
}



// 
void ast_dpi_function_proto_describe(FILE *out, struct ast_dpi_function_proto *this) {
    
}
// 
void ast_dpi_function_proto_action(FILE *out, struct ast_dpi_function_proto *this) {
    
}



// 
void ast_dpi_task_proto_describe(FILE *out, struct ast_dpi_task_proto *this) {
    
}
// 
void ast_dpi_task_proto_action(FILE *out, struct ast_dpi_task_proto *this) {
    
}



// 
void ast_task_declaration_describe(FILE *out, struct ast_task_declaration *this) {
    
}
// 
void ast_task_declaration_action(FILE *out, struct ast_task_declaration *this) {
    
}



// 
void ast_task_body_declaration_describe(FILE *out, struct ast_task_body_declaration *this) {
    
}
// 
void ast_task_body_declaration_action(FILE *out, struct ast_task_body_declaration *this) {
    
}



// 
void ast_tf_item_declaration_describe(FILE *out, struct ast_tf_item_declaration *this) {
    
}
// 
void ast_tf_item_declaration_action(FILE *out, struct ast_tf_item_declaration *this) {
    
}



// 
void ast_tf_port_list_describe(FILE *out, struct ast_tf_port_list *this) {
    
}
// 
void ast_tf_port_list_action(FILE *out, struct ast_tf_port_list *this) {
    
}



// 
void ast_tf_port_item_describe(FILE *out, struct ast_tf_port_item *this) {
    
}
// 
void ast_tf_port_item_action(FILE *out, struct ast_tf_port_item *this) {
    
}



// 
void ast_tf_port_direction_describe(FILE *out, struct ast_tf_port_direction *this) {
    
}
// 
void ast_tf_port_direction_action(FILE *out, struct ast_tf_port_direction *this) {
    
}



// 
void ast_tf_port_declaration_describe(FILE *out, struct ast_tf_port_declaration *this) {
    
}
// 
void ast_tf_port_declaration_action(FILE *out, struct ast_tf_port_declaration *this) {
    
}



// 
void ast_task_prototype_describe(FILE *out, struct ast_task_prototype *this) {
    
}
// 
void ast_task_prototype_action(FILE *out, struct ast_task_prototype *this) {
    
}



// 
void ast_block_item_declaration_describe(FILE *out, struct ast_block_item_declaration *this) {
    
}
// 
void ast_block_item_declaration_action(FILE *out, struct ast_block_item_declaration *this) {
    
}



// 
void ast_overload_declaration_describe(FILE *out, struct ast_overload_declaration *this) {
    
}
// 
void ast_overload_declaration_action(FILE *out, struct ast_overload_declaration *this) {
    
}



// 
void ast_overload_operator_describe(FILE *out, struct ast_overload_operator *this) {
    
}
// 
void ast_overload_operator_action(FILE *out, struct ast_overload_operator *this) {
    
}



// 
void ast_overload_proto_formals_describe(FILE *out, struct ast_overload_proto_formals *this) {
    
}
// 
void ast_overload_proto_formals_action(FILE *out, struct ast_overload_proto_formals *this) {
    
}



// 
void ast_modport_declaration_describe(FILE *out, struct ast_modport_declaration *this) {
    
}
// 
void ast_modport_declaration_action(FILE *out, struct ast_modport_declaration *this) {
    
}



// 
void ast_modport_item_describe(FILE *out, struct ast_modport_item *this) {
    
}
// 
void ast_modport_item_action(FILE *out, struct ast_modport_item *this) {
    
}



// 
void ast_modport_ports_declaration_describe(FILE *out, struct ast_modport_ports_declaration *this) {
    
}
// 
void ast_modport_ports_declaration_action(FILE *out, struct ast_modport_ports_declaration *this) {
    
}



// 
void ast_modport_clocking_declaration_describe(FILE *out, struct ast_modport_clocking_declaration *this) {
    
}
// 
void ast_modport_clocking_declaration_action(FILE *out, struct ast_modport_clocking_declaration *this) {
    
}



// 
void ast_modport_simple_ports_declaration_describe(FILE *out, struct ast_modport_simple_ports_declaration *this) {
    
}
// 
void ast_modport_simple_ports_declaration_action(FILE *out, struct ast_modport_simple_ports_declaration *this) {
    
}



// 
void ast_modport_simple_port_describe(FILE *out, struct ast_modport_simple_port *this) {
    
}
// 
void ast_modport_simple_port_action(FILE *out, struct ast_modport_simple_port *this) {
    
}



// 
void ast_modport_tf_ports_declaration_describe(FILE *out, struct ast_modport_tf_ports_declaration *this) {
    
}
// 
void ast_modport_tf_ports_declaration_action(FILE *out, struct ast_modport_tf_ports_declaration *this) {
    
}



// 
void ast_modport_tf_port_describe(FILE *out, struct ast_modport_tf_port *this) {
    
}
// 
void ast_modport_tf_port_action(FILE *out, struct ast_modport_tf_port *this) {
    
}



// 
void ast_import_export_describe(FILE *out, struct ast_import_export *this) {
    
}
// 
void ast_import_export_action(FILE *out, struct ast_import_export *this) {
    
}



// 
void ast_concurrent_assertion_item_describe(FILE *out, struct ast_concurrent_assertion_item *this) {
    
}
// 
void ast_concurrent_assertion_item_action(FILE *out, struct ast_concurrent_assertion_item *this) {
    
}



// 
void ast_concurrent_assertion_statement_describe(FILE *out, struct ast_concurrent_assertion_statement *this) {
    
}
// 
void ast_concurrent_assertion_statement_action(FILE *out, struct ast_concurrent_assertion_statement *this) {
    
}



// 
void ast_assert_property_statement_describe(FILE *out, struct ast_assert_property_statement *this) {
    
}
// 
void ast_assert_property_statement_action(FILE *out, struct ast_assert_property_statement *this) {
    
}



// 
void ast_assume_property_statement_describe(FILE *out, struct ast_assume_property_statement *this) {
    
}
// 
void ast_assume_property_statement_action(FILE *out, struct ast_assume_property_statement *this) {
    
}



// 
void ast_cover_property_statement_describe(FILE *out, struct ast_cover_property_statement *this) {
    
}
// 
void ast_cover_property_statement_action(FILE *out, struct ast_cover_property_statement *this) {
    
}



// 
void ast_expect_property_statement_describe(FILE *out, struct ast_expect_property_statement *this) {
    
}
// 
void ast_expect_property_statement_action(FILE *out, struct ast_expect_property_statement *this) {
    
}



// 
void ast_cover_sequence_statement_describe(FILE *out, struct ast_cover_sequence_statement *this) {
    
}
// 
void ast_cover_sequence_statement_action(FILE *out, struct ast_cover_sequence_statement *this) {
    
}



// 
void ast_restrict_property_statement_describe(FILE *out, struct ast_restrict_property_statement *this) {
    
}
// 
void ast_restrict_property_statement_action(FILE *out, struct ast_restrict_property_statement *this) {
    
}



// 
void ast_property_instance_describe(FILE *out, struct ast_property_instance *this) {
    
}
// 
void ast_property_instance_action(FILE *out, struct ast_property_instance *this) {
    
}



// 
void ast_property_list_of_arguments_describe(FILE *out, struct ast_property_list_of_arguments *this) {
    
}
// 
void ast_property_list_of_arguments_action(FILE *out, struct ast_property_list_of_arguments *this) {
    
}



// 
void ast_property_actual_arg_describe(FILE *out, struct ast_property_actual_arg *this) {
    
}
// 
void ast_property_actual_arg_action(FILE *out, struct ast_property_actual_arg *this) {
    
}



// 
void ast_assertion_item_declaration_describe(FILE *out, struct ast_assertion_item_declaration *this) {
    
}
// 
void ast_assertion_item_declaration_action(FILE *out, struct ast_assertion_item_declaration *this) {
    
}



// 
void ast_property_declaration_describe(FILE *out, struct ast_property_declaration *this) {
    
}
// 
void ast_property_declaration_action(FILE *out, struct ast_property_declaration *this) {
    
}



// 
void ast_property_port_list_describe(FILE *out, struct ast_property_port_list *this) {
    
}
// 
void ast_property_port_list_action(FILE *out, struct ast_property_port_list *this) {
    
}



// 
void ast_property_port_item_describe(FILE *out, struct ast_property_port_item *this) {
    
}
// 
void ast_property_port_item_action(FILE *out, struct ast_property_port_item *this) {
    
}



// 
void ast_property_lvar_port_direction_describe(FILE *out, struct ast_property_lvar_port_direction *this) {
    
}
// 
void ast_property_lvar_port_direction_action(FILE *out, struct ast_property_lvar_port_direction *this) {
    
}



// 
void ast_property_formal_type_describe(FILE *out, struct ast_property_formal_type *this) {
    
}
// 
void ast_property_formal_type_action(FILE *out, struct ast_property_formal_type *this) {
    
}



// 
void ast_property_spec_describe(FILE *out, struct ast_property_spec *this) {
    
}
// 
void ast_property_spec_action(FILE *out, struct ast_property_spec *this) {
    
}



// 
void ast_property_expr_describe(FILE *out, struct ast_property_expr *this) {
    
}
// 
void ast_property_expr_action(FILE *out, struct ast_property_expr *this) {
    
}



// 
void ast_property_case_item_describe(FILE *out, struct ast_property_case_item *this) {
    
}
// 
void ast_property_case_item_action(FILE *out, struct ast_property_case_item *this) {
    
}



// 
void ast_sequence_declaration_describe(FILE *out, struct ast_sequence_declaration *this) {
    
}
// 
void ast_sequence_declaration_action(FILE *out, struct ast_sequence_declaration *this) {
    
}



// 
void ast_sequence_port_list_describe(FILE *out, struct ast_sequence_port_list *this) {
    
}
// 
void ast_sequence_port_list_action(FILE *out, struct ast_sequence_port_list *this) {
    
}



// 
void ast_sequence_port_item_describe(FILE *out, struct ast_sequence_port_item *this) {
    
}
// 
void ast_sequence_port_item_action(FILE *out, struct ast_sequence_port_item *this) {
    
}



// 
void ast_sequence_lvar_port_direction_describe(FILE *out, struct ast_sequence_lvar_port_direction *this) {
    
}
// 
void ast_sequence_lvar_port_direction_action(FILE *out, struct ast_sequence_lvar_port_direction *this) {
    
}



// 
void ast_sequence_formal_type_describe(FILE *out, struct ast_sequence_formal_type *this) {
    
}
// 
void ast_sequence_formal_type_action(FILE *out, struct ast_sequence_formal_type *this) {
    
}



// 
void ast_sequence_expr_describe(FILE *out, struct ast_sequence_expr *this) {
    
}
// 
void ast_sequence_expr_action(FILE *out, struct ast_sequence_expr *this) {
    
}



// 
void ast_cycle_delay_range_describe(FILE *out, struct ast_cycle_delay_range *this) {
    
}
// 
void ast_cycle_delay_range_action(FILE *out, struct ast_cycle_delay_range *this) {
    
}



// 
void ast_sequence_method_call_describe(FILE *out, struct ast_sequence_method_call *this) {
    
}
// 
void ast_sequence_method_call_action(FILE *out, struct ast_sequence_method_call *this) {
    
}



// 
void ast_sequence_match_item_describe(FILE *out, struct ast_sequence_match_item *this) {
    
}
// 
void ast_sequence_match_item_action(FILE *out, struct ast_sequence_match_item *this) {
    
}



// 
void ast_sequence_instance_describe(FILE *out, struct ast_sequence_instance *this) {
    
}
// 
void ast_sequence_instance_action(FILE *out, struct ast_sequence_instance *this) {
    
}



// 
void ast_sequence_list_of_arguments_describe(FILE *out, struct ast_sequence_list_of_arguments *this) {
    
}
// 
void ast_sequence_list_of_arguments_action(FILE *out, struct ast_sequence_list_of_arguments *this) {
    
}



// 
void ast_sequence_actual_arg_describe(FILE *out, struct ast_sequence_actual_arg *this) {
    
}
// 
void ast_sequence_actual_arg_action(FILE *out, struct ast_sequence_actual_arg *this) {
    
}



// 
void ast_boolean_abbrev_describe(FILE *out, struct ast_boolean_abbrev *this) {
    
}
// 
void ast_boolean_abbrev_action(FILE *out, struct ast_boolean_abbrev *this) {
    
}



// 
void ast_sequence_abbrev_describe(FILE *out, struct ast_sequence_abbrev *this) {
    
}
// 
void ast_sequence_abbrev_action(FILE *out, struct ast_sequence_abbrev *this) {
    
}



// 
void ast_consecutive_repetition_describe(FILE *out, struct ast_consecutive_repetition *this) {
    
}
// 
void ast_consecutive_repetition_action(FILE *out, struct ast_consecutive_repetition *this) {
    
}



// 
void ast_non_consecutive_repetition_describe(FILE *out, struct ast_non_consecutive_repetition *this) {
    
}
// 
void ast_non_consecutive_repetition_action(FILE *out, struct ast_non_consecutive_repetition *this) {
    
}



// 
void ast_goto_repetition_describe(FILE *out, struct ast_goto_repetition *this) {
    
}
// 
void ast_goto_repetition_action(FILE *out, struct ast_goto_repetition *this) {
    
}



// 
void ast_const_or_range_expression_describe(FILE *out, struct ast_const_or_range_expression *this) {
    
}
// 
void ast_const_or_range_expression_action(FILE *out, struct ast_const_or_range_expression *this) {
    
}



// 
void ast_cycle_delay_const_range_expression_describe(FILE *out, struct ast_cycle_delay_const_range_expression *this) {
    
}
// 
void ast_cycle_delay_const_range_expression_action(FILE *out, struct ast_cycle_delay_const_range_expression *this) {
    
}



// 
void ast_expression_or_dist_describe(FILE *out, struct ast_expression_or_dist *this) {
    
}
// 
void ast_expression_or_dist_action(FILE *out, struct ast_expression_or_dist *this) {
    
}



// 
void ast_assertion_variable_declaration_describe(FILE *out, struct ast_assertion_variable_declaration *this) {
    
}
// 
void ast_assertion_variable_declaration_action(FILE *out, struct ast_assertion_variable_declaration *this) {
    
}



// 
void ast_let_declaration_describe(FILE *out, struct ast_let_declaration *this) {
    
}
// 
void ast_let_declaration_action(FILE *out, struct ast_let_declaration *this) {
    
}



// 
void ast_let_identifier_describe(FILE *out, struct ast_let_identifier *this) {
    
}
// 
void ast_let_identifier_action(FILE *out, struct ast_let_identifier *this) {
    
}



// 
void ast_let_port_list_describe(FILE *out, struct ast_let_port_list *this) {
    
}
// 
void ast_let_port_list_action(FILE *out, struct ast_let_port_list *this) {
    
}



// 
void ast_let_port_item_describe(FILE *out, struct ast_let_port_item *this) {
    
}
// 
void ast_let_port_item_action(FILE *out, struct ast_let_port_item *this) {
    
}



// 
void ast_let_formal_type_describe(FILE *out, struct ast_let_formal_type *this) {
    
}
// 
void ast_let_formal_type_action(FILE *out, struct ast_let_formal_type *this) {
    
}



// 
void ast_let_expression_describe(FILE *out, struct ast_let_expression *this) {
    
}
// 
void ast_let_expression_action(FILE *out, struct ast_let_expression *this) {
    
}



// 
void ast_let_list_of_arguments_describe(FILE *out, struct ast_let_list_of_arguments *this) {
    
}
// 
void ast_let_list_of_arguments_action(FILE *out, struct ast_let_list_of_arguments *this) {
    
}



// 
void ast_let_actual_arg_describe(FILE *out, struct ast_let_actual_arg *this) {
    
}
// 
void ast_let_actual_arg_action(FILE *out, struct ast_let_actual_arg *this) {
    
}



// 
void ast_covergroup_declaration_describe(FILE *out, struct ast_covergroup_declaration *this) {
    
}
// 
void ast_covergroup_declaration_action(FILE *out, struct ast_covergroup_declaration *this) {
    
}



// 
void ast_coverage_spec_or_option_describe(FILE *out, struct ast_coverage_spec_or_option *this) {
    
}
// 
void ast_coverage_spec_or_option_action(FILE *out, struct ast_coverage_spec_or_option *this) {
    
}



// 
void ast_coverage_option_describe(FILE *out, struct ast_coverage_option *this) {
    
}
// 
void ast_coverage_option_action(FILE *out, struct ast_coverage_option *this) {
    
}



// 
void ast_coverage_spec_describe(FILE *out, struct ast_coverage_spec *this) {
    
}
// 
void ast_coverage_spec_action(FILE *out, struct ast_coverage_spec *this) {
    
}



// 
void ast_coverage_event_describe(FILE *out, struct ast_coverage_event *this) {
    
}
// 
void ast_coverage_event_action(FILE *out, struct ast_coverage_event *this) {
    
}



// 
void ast_block_event_expression_describe(FILE *out, struct ast_block_event_expression *this) {
    
}
// 
void ast_block_event_expression_action(FILE *out, struct ast_block_event_expression *this) {
    
}



// 
void ast_hierarchical_btf_identifier_describe(FILE *out, struct ast_hierarchical_btf_identifier *this) {
    
}
// 
void ast_hierarchical_btf_identifier_action(FILE *out, struct ast_hierarchical_btf_identifier *this) {
    
}



// 
void ast_cover_point_describe(FILE *out, struct ast_cover_point *this) {
    
}
// 
void ast_cover_point_action(FILE *out, struct ast_cover_point *this) {
    
}



// 
void ast_bins_or_empty_describe(FILE *out, struct ast_bins_or_empty *this) {
    
}
// 
void ast_bins_or_empty_action(FILE *out, struct ast_bins_or_empty *this) {
    
}



// 
void ast_bins_or_options_describe(FILE *out, struct ast_bins_or_options *this) {
    
}
// 
void ast_bins_or_options_action(FILE *out, struct ast_bins_or_options *this) {
    
}



// 
void ast_bins_keyword_describe(FILE *out, struct ast_bins_keyword *this) {
    
}
// 
void ast_bins_keyword_action(FILE *out, struct ast_bins_keyword *this) {
    
}



// 
void ast_trans_list_describe(FILE *out, struct ast_trans_list *this) {
    
}
// 
void ast_trans_list_action(FILE *out, struct ast_trans_list *this) {
    
}



// 
void ast_trans_set_describe(FILE *out, struct ast_trans_set *this) {
    
}
// 
void ast_trans_set_action(FILE *out, struct ast_trans_set *this) {
    
}



// 
void ast_trans_range_list_describe(FILE *out, struct ast_trans_range_list *this) {
    
}
// 
void ast_trans_range_list_action(FILE *out, struct ast_trans_range_list *this) {
    
}



// 
void ast_trans_item_describe(FILE *out, struct ast_trans_item *this) {
    
}
// 
void ast_trans_item_action(FILE *out, struct ast_trans_item *this) {
    
}



// 
void ast_repeat_range_describe(FILE *out, struct ast_repeat_range *this) {
    
}
// 
void ast_repeat_range_action(FILE *out, struct ast_repeat_range *this) {
    
}



// 
void ast_cover_cross_describe(FILE *out, struct ast_cover_cross *this) {
    
}
// 
void ast_cover_cross_action(FILE *out, struct ast_cover_cross *this) {
    
}



// 
void ast_list_of_cross_items_describe(FILE *out, struct ast_list_of_cross_items *this) {
    
}
// 
void ast_list_of_cross_items_action(FILE *out, struct ast_list_of_cross_items *this) {
    
}



// 
void ast_cross_item_describe(FILE *out, struct ast_cross_item *this) {
    
}
// 
void ast_cross_item_action(FILE *out, struct ast_cross_item *this) {
    
}



// 
void ast_cross_body_describe(FILE *out, struct ast_cross_body *this) {
    
}
// 
void ast_cross_body_action(FILE *out, struct ast_cross_body *this) {
    
}



// 
void ast_cross_body_item_describe(FILE *out, struct ast_cross_body_item *this) {
    
}
// 
void ast_cross_body_item_action(FILE *out, struct ast_cross_body_item *this) {
    
}



// 
void ast_bins_selection_or_option_describe(FILE *out, struct ast_bins_selection_or_option *this) {
    
}
// 
void ast_bins_selection_or_option_action(FILE *out, struct ast_bins_selection_or_option *this) {
    
}



// 
void ast_bins_selection_describe(FILE *out, struct ast_bins_selection *this) {
    
}
// 
void ast_bins_selection_action(FILE *out, struct ast_bins_selection *this) {
    
}



// 
void ast_select_expression_describe(FILE *out, struct ast_select_expression *this) {
    
}
// 
void ast_select_expression_action(FILE *out, struct ast_select_expression *this) {
    
}



// 
void ast_select_condition_describe(FILE *out, struct ast_select_condition *this) {
    
}
// 
void ast_select_condition_action(FILE *out, struct ast_select_condition *this) {
    
}



// 
void ast_bins_expression_describe(FILE *out, struct ast_bins_expression *this) {
    
}
// 
void ast_bins_expression_action(FILE *out, struct ast_bins_expression *this) {
    
}



// 
void ast_covergroup_range_list_describe(FILE *out, struct ast_covergroup_range_list *this) {
    
}
// 
void ast_covergroup_range_list_action(FILE *out, struct ast_covergroup_range_list *this) {
    
}



// 
void ast_covergroup_value_range_describe(FILE *out, struct ast_covergroup_value_range *this) {
    
}
// 
void ast_covergroup_value_range_action(FILE *out, struct ast_covergroup_value_range *this) {
    
}



// 
void ast_with_covergroup_expression_describe(FILE *out, struct ast_with_covergroup_expression *this) {
    
}
// 
void ast_with_covergroup_expression_action(FILE *out, struct ast_with_covergroup_expression *this) {
    
}



// 
void ast_set_covergroup_expression_describe(FILE *out, struct ast_set_covergroup_expression *this) {
    
}
// 
void ast_set_covergroup_expression_action(FILE *out, struct ast_set_covergroup_expression *this) {
    
}



// 
void ast_integer_covergroup_expression_describe(FILE *out, struct ast_integer_covergroup_expression *this) {
    
}
// 
void ast_integer_covergroup_expression_action(FILE *out, struct ast_integer_covergroup_expression *this) {
    
}



// 
void ast_cross_set_expression_describe(FILE *out, struct ast_cross_set_expression *this) {
    
}
// 
void ast_cross_set_expression_action(FILE *out, struct ast_cross_set_expression *this) {
    
}



// 
void ast_covergroup_expression_describe(FILE *out, struct ast_covergroup_expression *this) {
    
}
// 
void ast_covergroup_expression_action(FILE *out, struct ast_covergroup_expression *this) {
    
}



// 
void ast_gate_instantiation_describe(FILE *out, struct ast_gate_instantiation *this) {
    
}
// 
void ast_gate_instantiation_action(FILE *out, struct ast_gate_instantiation *this) {
    
}



// 
void ast_cmos_switch_instance_describe(FILE *out, struct ast_cmos_switch_instance *this) {
    
}
// 
void ast_cmos_switch_instance_action(FILE *out, struct ast_cmos_switch_instance *this) {
    
}



// 
void ast_enable_gate_instance_describe(FILE *out, struct ast_enable_gate_instance *this) {
    
}
// 
void ast_enable_gate_instance_action(FILE *out, struct ast_enable_gate_instance *this) {
    
}



// 
void ast_mos_switch_instance_describe(FILE *out, struct ast_mos_switch_instance *this) {
    
}
// 
void ast_mos_switch_instance_action(FILE *out, struct ast_mos_switch_instance *this) {
    
}



// 
void ast_n_input_gate_instance_describe(FILE *out, struct ast_n_input_gate_instance *this) {
    
}
// 
void ast_n_input_gate_instance_action(FILE *out, struct ast_n_input_gate_instance *this) {
    
}



// 
void ast_n_output_gate_instance_describe(FILE *out, struct ast_n_output_gate_instance *this) {
    
}
// 
void ast_n_output_gate_instance_action(FILE *out, struct ast_n_output_gate_instance *this) {
    
}



// 
void ast_pass_switch_instance_describe(FILE *out, struct ast_pass_switch_instance *this) {
    
}
// 
void ast_pass_switch_instance_action(FILE *out, struct ast_pass_switch_instance *this) {
    
}



// 
void ast_pass_enable_switch_instance_describe(FILE *out, struct ast_pass_enable_switch_instance *this) {
    
}
// 
void ast_pass_enable_switch_instance_action(FILE *out, struct ast_pass_enable_switch_instance *this) {
    
}



// 
void ast_pull_gate_instance_describe(FILE *out, struct ast_pull_gate_instance *this) {
    
}
// 
void ast_pull_gate_instance_action(FILE *out, struct ast_pull_gate_instance *this) {
    
}



// 
void ast_pulldown_strength_describe(FILE *out, struct ast_pulldown_strength *this) {
    
}
// 
void ast_pulldown_strength_action(FILE *out, struct ast_pulldown_strength *this) {
    
}



// 
void ast_pullup_strength_describe(FILE *out, struct ast_pullup_strength *this) {
    
}
// 
void ast_pullup_strength_action(FILE *out, struct ast_pullup_strength *this) {
    
}



// 
void ast_enable_terminal_describe(FILE *out, struct ast_enable_terminal *this) {
    
}
// 
void ast_enable_terminal_action(FILE *out, struct ast_enable_terminal *this) {
    
}



// 
void ast_inout_terminal_describe(FILE *out, struct ast_inout_terminal *this) {
    
}
// 
void ast_inout_terminal_action(FILE *out, struct ast_inout_terminal *this) {
    
}



// 
void ast_input_terminal_describe(FILE *out, struct ast_input_terminal *this) {
    
}
// 
void ast_input_terminal_action(FILE *out, struct ast_input_terminal *this) {
    
}



// 
void ast_ncontrol_terminal_describe(FILE *out, struct ast_ncontrol_terminal *this) {
    
}
// 
void ast_ncontrol_terminal_action(FILE *out, struct ast_ncontrol_terminal *this) {
    
}



// 
void ast_output_terminal_describe(FILE *out, struct ast_output_terminal *this) {
    
}
// 
void ast_output_terminal_action(FILE *out, struct ast_output_terminal *this) {
    
}



// 
void ast_pcontrol_terminal_describe(FILE *out, struct ast_pcontrol_terminal *this) {
    
}
// 
void ast_pcontrol_terminal_action(FILE *out, struct ast_pcontrol_terminal *this) {
    
}



// 
void ast_cmos_switchtype_describe(FILE *out, struct ast_cmos_switchtype *this) {
    
}
// 
void ast_cmos_switchtype_action(FILE *out, struct ast_cmos_switchtype *this) {
    
}



// 
void ast_enable_gatetype_describe(FILE *out, struct ast_enable_gatetype *this) {
    
}
// 
void ast_enable_gatetype_action(FILE *out, struct ast_enable_gatetype *this) {
    
}



// 
void ast_mos_switchtype_describe(FILE *out, struct ast_mos_switchtype *this) {
    
}
// 
void ast_mos_switchtype_action(FILE *out, struct ast_mos_switchtype *this) {
    
}



// 
void ast_n_input_gatetype_describe(FILE *out, struct ast_n_input_gatetype *this) {
    
}
// 
void ast_n_input_gatetype_action(FILE *out, struct ast_n_input_gatetype *this) {
    
}



// 
void ast_n_output_gatetype_describe(FILE *out, struct ast_n_output_gatetype *this) {
    
}
// 
void ast_n_output_gatetype_action(FILE *out, struct ast_n_output_gatetype *this) {
    
}



// 
void ast_pass_en_switchtype_describe(FILE *out, struct ast_pass_en_switchtype *this) {
    
}
// 
void ast_pass_en_switchtype_action(FILE *out, struct ast_pass_en_switchtype *this) {
    
}



// 
void ast_pass_switchtype_describe(FILE *out, struct ast_pass_switchtype *this) {
    
}
// 
void ast_pass_switchtype_action(FILE *out, struct ast_pass_switchtype *this) {
    
}



// 
void ast_module_instantiation_describe(FILE *out, struct ast_module_instantiation *this) {
    
}
// 
void ast_module_instantiation_action(FILE *out, struct ast_module_instantiation *this) {
    
}



// 
void ast_parameter_value_assignment_describe(FILE *out, struct ast_parameter_value_assignment *this) {
    
}
// 
void ast_parameter_value_assignment_action(FILE *out, struct ast_parameter_value_assignment *this) {
    
}



// 
void ast_list_of_parameter_assignments_describe(FILE *out, struct ast_list_of_parameter_assignments *this) {
    
}
// 
void ast_list_of_parameter_assignments_action(FILE *out, struct ast_list_of_parameter_assignments *this) {
    
}



// 
void ast_ordered_parameter_assignment_describe(FILE *out, struct ast_ordered_parameter_assignment *this) {
    
}
// 
void ast_ordered_parameter_assignment_action(FILE *out, struct ast_ordered_parameter_assignment *this) {
    
}



// 
void ast_named_parameter_assignment_describe(FILE *out, struct ast_named_parameter_assignment *this) {
    
}
// 
void ast_named_parameter_assignment_action(FILE *out, struct ast_named_parameter_assignment *this) {
    
}



// 
void ast_hierarchical_instance_describe(FILE *out, struct ast_hierarchical_instance *this) {
    
}
// 
void ast_hierarchical_instance_action(FILE *out, struct ast_hierarchical_instance *this) {
    
}



// 
void ast_name_of_instance_describe(FILE *out, struct ast_name_of_instance *this) {
    
}
// 
void ast_name_of_instance_action(FILE *out, struct ast_name_of_instance *this) {
    
}



// 
void ast_list_of_port_connections_describe(FILE *out, struct ast_list_of_port_connections *this) {
    
}
// 
void ast_list_of_port_connections_action(FILE *out, struct ast_list_of_port_connections *this) {
    
}



// 
void ast_ordered_port_connection_describe(FILE *out, struct ast_ordered_port_connection *this) {
    
}
// 
void ast_ordered_port_connection_action(FILE *out, struct ast_ordered_port_connection *this) {
    
}



// 
void ast_named_port_connection_describe(FILE *out, struct ast_named_port_connection *this) {
    
}
// 
void ast_named_port_connection_action(FILE *out, struct ast_named_port_connection *this) {
    
}



// 
void ast_interface_instantiation_describe(FILE *out, struct ast_interface_instantiation *this) {
    
}
// 
void ast_interface_instantiation_action(FILE *out, struct ast_interface_instantiation *this) {
    
}



// 
void ast_program_instantiation_describe(FILE *out, struct ast_program_instantiation *this) {
    
}
// 
void ast_program_instantiation_action(FILE *out, struct ast_program_instantiation *this) {
    
}



// 
void ast_checker_instantiation_describe(FILE *out, struct ast_checker_instantiation *this) {
    
}
// 
void ast_checker_instantiation_action(FILE *out, struct ast_checker_instantiation *this) {
    
}



// 
void ast_list_of_checker_port_connections_describe(FILE *out, struct ast_list_of_checker_port_connections *this) {
    
}
// 
void ast_list_of_checker_port_connections_action(FILE *out, struct ast_list_of_checker_port_connections *this) {
    
}



// 
void ast_ordered_checker_port_connection_describe(FILE *out, struct ast_ordered_checker_port_connection *this) {
    
}
// 
void ast_ordered_checker_port_connection_action(FILE *out, struct ast_ordered_checker_port_connection *this) {
    
}



// 
void ast_named_checker_port_connection_describe(FILE *out, struct ast_named_checker_port_connection *this) {
    
}
// 
void ast_named_checker_port_connection_action(FILE *out, struct ast_named_checker_port_connection *this) {
    
}



// 
void ast_generate_region_describe(FILE *out, struct ast_generate_region *this) {
    
}
// 
void ast_generate_region_action(FILE *out, struct ast_generate_region *this) {
    
}



// 
void ast_loop_generate_construct_describe(FILE *out, struct ast_loop_generate_construct *this) {
    
}
// 
void ast_loop_generate_construct_action(FILE *out, struct ast_loop_generate_construct *this) {
    
}



// 
void ast_genvar_initialization_describe(FILE *out, struct ast_genvar_initialization *this) {
    
}
// 
void ast_genvar_initialization_action(FILE *out, struct ast_genvar_initialization *this) {
    
}



// 
void ast_genvar_iteration_describe(FILE *out, struct ast_genvar_iteration *this) {
    
}
// 
void ast_genvar_iteration_action(FILE *out, struct ast_genvar_iteration *this) {
    
}



// 
void ast_conditional_generate_construct_describe(FILE *out, struct ast_conditional_generate_construct *this) {
    
}
// 
void ast_conditional_generate_construct_action(FILE *out, struct ast_conditional_generate_construct *this) {
    
}



// 
void ast_if_generate_construct_describe(FILE *out, struct ast_if_generate_construct *this) {
    
}
// 
void ast_if_generate_construct_action(FILE *out, struct ast_if_generate_construct *this) {
    
}



// 
void ast_case_generate_construct_describe(FILE *out, struct ast_case_generate_construct *this) {
    
}
// 
void ast_case_generate_construct_action(FILE *out, struct ast_case_generate_construct *this) {
    
}



// 
void ast_case_generate_item_describe(FILE *out, struct ast_case_generate_item *this) {
    
}
// 
void ast_case_generate_item_action(FILE *out, struct ast_case_generate_item *this) {
    
}



// 
void ast_generate_block_describe(FILE *out, struct ast_generate_block *this) {
    
}
// 
void ast_generate_block_action(FILE *out, struct ast_generate_block *this) {
    
}



// 
void ast_generate_item_describe(FILE *out, struct ast_generate_item *this) {
    
}
// 
void ast_generate_item_action(FILE *out, struct ast_generate_item *this) {
    
}



// 
void ast_udp_nonansi_declaration_describe(FILE *out, struct ast_udp_nonansi_declaration *this) {
    
}
// 
void ast_udp_nonansi_declaration_action(FILE *out, struct ast_udp_nonansi_declaration *this) {
    
}



// 
void ast_udp_ansi_declaration_describe(FILE *out, struct ast_udp_ansi_declaration *this) {
    
}
// 
void ast_udp_ansi_declaration_action(FILE *out, struct ast_udp_ansi_declaration *this) {
    
}



// 
void ast_udp_declaration_describe(FILE *out, struct ast_udp_declaration *this) {
    
}
// 
void ast_udp_declaration_action(FILE *out, struct ast_udp_declaration *this) {
    
}



// 
void ast_udp_port_list_describe(FILE *out, struct ast_udp_port_list *this) {
    
}
// 
void ast_udp_port_list_action(FILE *out, struct ast_udp_port_list *this) {
    
}



// 
void ast_udp_declaration_port_list_describe(FILE *out, struct ast_udp_declaration_port_list *this) {
    
}
// 
void ast_udp_declaration_port_list_action(FILE *out, struct ast_udp_declaration_port_list *this) {
    
}



// 
void ast_udp_port_declaration_describe(FILE *out, struct ast_udp_port_declaration *this) {
    
}
// 
void ast_udp_port_declaration_action(FILE *out, struct ast_udp_port_declaration *this) {
    
}



// 
void ast_udp_output_declaration_describe(FILE *out, struct ast_udp_output_declaration *this) {
    
}
// 
void ast_udp_output_declaration_action(FILE *out, struct ast_udp_output_declaration *this) {
    
}



// 
void ast_udp_input_declaration_describe(FILE *out, struct ast_udp_input_declaration *this) {
    
}
// 
void ast_udp_input_declaration_action(FILE *out, struct ast_udp_input_declaration *this) {
    
}



// 
void ast_udp_reg_declaration_describe(FILE *out, struct ast_udp_reg_declaration *this) {
    
}
// 
void ast_udp_reg_declaration_action(FILE *out, struct ast_udp_reg_declaration *this) {
    
}



// 
void ast_udp_body_describe(FILE *out, struct ast_udp_body *this) {
    
}
// 
void ast_udp_body_action(FILE *out, struct ast_udp_body *this) {
    
}



// 
void ast_combinational_body_describe(FILE *out, struct ast_combinational_body *this) {
    
}
// 
void ast_combinational_body_action(FILE *out, struct ast_combinational_body *this) {
    
}



// 
void ast_combinational_entry_describe(FILE *out, struct ast_combinational_entry *this) {
    
}
// 
void ast_combinational_entry_action(FILE *out, struct ast_combinational_entry *this) {
    
}



// 
void ast_sequential_body_describe(FILE *out, struct ast_sequential_body *this) {
    
}
// 
void ast_sequential_body_action(FILE *out, struct ast_sequential_body *this) {
    
}



// 
void ast_udp_initial_statement_describe(FILE *out, struct ast_udp_initial_statement *this) {
    
}
// 
void ast_udp_initial_statement_action(FILE *out, struct ast_udp_initial_statement *this) {
    
}



// 
void ast_init_val_describe(FILE *out, struct ast_init_val *this) {
    
}
// 
void ast_init_val_action(FILE *out, struct ast_init_val *this) {
    
}



// 
void ast_sequential_entry_describe(FILE *out, struct ast_sequential_entry *this) {
    
}
// 
void ast_sequential_entry_action(FILE *out, struct ast_sequential_entry *this) {
    
}



// 
void ast_seq_input_list_describe(FILE *out, struct ast_seq_input_list *this) {
    
}
// 
void ast_seq_input_list_action(FILE *out, struct ast_seq_input_list *this) {
    
}



// 
void ast_level_input_list_describe(FILE *out, struct ast_level_input_list *this) {
    
}
// 
void ast_level_input_list_action(FILE *out, struct ast_level_input_list *this) {
    
}



// 
void ast_edge_input_list_describe(FILE *out, struct ast_edge_input_list *this) {
    
}
// 
void ast_edge_input_list_action(FILE *out, struct ast_edge_input_list *this) {
    
}



// 
void ast_edge_indicator_describe(FILE *out, struct ast_edge_indicator *this) {
    
}
// 
void ast_edge_indicator_action(FILE *out, struct ast_edge_indicator *this) {
    
}



// 
void ast_current_state_describe(FILE *out, struct ast_current_state *this) {
    
}
// 
void ast_current_state_action(FILE *out, struct ast_current_state *this) {
    
}



// 
void ast_next_state_describe(FILE *out, struct ast_next_state *this) {
    
}
// 
void ast_next_state_action(FILE *out, struct ast_next_state *this) {
    
}



// 
void ast_output_symbol_describe(FILE *out, struct ast_output_symbol *this) {
    
}
// 
void ast_output_symbol_action(FILE *out, struct ast_output_symbol *this) {
    
}



// 
void ast_level_symbol_describe(FILE *out, struct ast_level_symbol *this) {
    
}
// 
void ast_level_symbol_action(FILE *out, struct ast_level_symbol *this) {
    
}



// 
void ast_edge_symbol_describe(FILE *out, struct ast_edge_symbol *this) {
    
}
// 
void ast_edge_symbol_action(FILE *out, struct ast_edge_symbol *this) {
    
}



// 
void ast_udp_instantiation_describe(FILE *out, struct ast_udp_instantiation *this) {
    
}
// 
void ast_udp_instantiation_action(FILE *out, struct ast_udp_instantiation *this) {
    
}



// 
void ast_udp_instance_describe(FILE *out, struct ast_udp_instance *this) {
    
}
// 
void ast_udp_instance_action(FILE *out, struct ast_udp_instance *this) {
    
}



// 
void ast_continuous_assign_describe(FILE *out, struct ast_continuous_assign *this) {
    
}
// 
void ast_continuous_assign_action(FILE *out, struct ast_continuous_assign *this) {
    
}



// 
void ast_list_of_net_assignments_describe(FILE *out, struct ast_list_of_net_assignments *this) {
    
}
// 
void ast_list_of_net_assignments_action(FILE *out, struct ast_list_of_net_assignments *this) {
    
}



// 
void ast_list_of_variable_assignments_describe(FILE *out, struct ast_list_of_variable_assignments *this) {
    
}
// 
void ast_list_of_variable_assignments_action(FILE *out, struct ast_list_of_variable_assignments *this) {
    
}



// 
void ast_net_alias_describe(FILE *out, struct ast_net_alias *this) {
    
}
// 
void ast_net_alias_action(FILE *out, struct ast_net_alias *this) {
    
}



// 
void ast_net_assignment_describe(FILE *out, struct ast_net_assignment *this) {
    
}
// 
void ast_net_assignment_action(FILE *out, struct ast_net_assignment *this) {
    
}



// 
void ast_initial_construct_describe(FILE *out, struct ast_initial_construct *this) {
    
}
// 
void ast_initial_construct_action(FILE *out, struct ast_initial_construct *this) {
    
}



// 
void ast_always_construct_describe(FILE *out, struct ast_always_construct *this) {
    
}
// 
void ast_always_construct_action(FILE *out, struct ast_always_construct *this) {
    
}



// 
void ast_always_keyword_describe(FILE *out, struct ast_always_keyword *this) {
    
}
// 
void ast_always_keyword_action(FILE *out, struct ast_always_keyword *this) {
    
}



// 
void ast_final_construct_describe(FILE *out, struct ast_final_construct *this) {
    
}
// 
void ast_final_construct_action(FILE *out, struct ast_final_construct *this) {
    
}



// 
void ast_blocking_assignment_describe(FILE *out, struct ast_blocking_assignment *this) {
    
}
// 
void ast_blocking_assignment_action(FILE *out, struct ast_blocking_assignment *this) {
    
}



// 
void ast_operator_assignment_describe(FILE *out, struct ast_operator_assignment *this) {
    
}
// 
void ast_operator_assignment_action(FILE *out, struct ast_operator_assignment *this) {
    
}



// 
void ast_assignment_operator_describe(FILE *out, struct ast_assignment_operator *this) {
    
}
// 
void ast_assignment_operator_action(FILE *out, struct ast_assignment_operator *this) {
    
}



// 
void ast_nonblocking_assignment_describe(FILE *out, struct ast_nonblocking_assignment *this) {
    
}
// 
void ast_nonblocking_assignment_action(FILE *out, struct ast_nonblocking_assignment *this) {
    
}



// 
void ast_procedural_continuous_assignment_describe(FILE *out, struct ast_procedural_continuous_assignment *this) {
    
}
// 
void ast_procedural_continuous_assignment_action(FILE *out, struct ast_procedural_continuous_assignment *this) {
    
}



// 
void ast_variable_assignment_describe(FILE *out, struct ast_variable_assignment *this) {
    
}
// 
void ast_variable_assignment_action(FILE *out, struct ast_variable_assignment *this) {
    
}



// 
void ast_action_block_describe(FILE *out, struct ast_action_block *this) {
    
}
// 
void ast_action_block_action(FILE *out, struct ast_action_block *this) {
    
}



// 
void ast_seq_block_describe(FILE *out, struct ast_seq_block *this) {
    
}
// 
void ast_seq_block_action(FILE *out, struct ast_seq_block *this) {
    
}



// 
void ast_par_block_describe(FILE *out, struct ast_par_block *this) {
    
}
// 
void ast_par_block_action(FILE *out, struct ast_par_block *this) {
    
}



// 
void ast_join_keyword_describe(FILE *out, struct ast_join_keyword *this) {
    
}
// 
void ast_join_keyword_action(FILE *out, struct ast_join_keyword *this) {
    
}



// 
void ast_statement_or_null_describe(FILE *out, struct ast_statement_or_null *this) {
    
}
// 
void ast_statement_or_null_action(FILE *out, struct ast_statement_or_null *this) {
    
}



// 
void ast_statement_describe(FILE *out, struct ast_statement *this) {
    
}
// 
void ast_statement_action(FILE *out, struct ast_statement *this) {
    
}



// 
void ast_statement_item_describe(FILE *out, struct ast_statement_item *this) {
    
}
// 
void ast_statement_item_action(FILE *out, struct ast_statement_item *this) {
    
}



// 
void ast_function_statement_describe(FILE *out, struct ast_function_statement *this) {
    
}
// 
void ast_function_statement_action(FILE *out, struct ast_function_statement *this) {
    
}



// 
void ast_function_statement_or_null_describe(FILE *out, struct ast_function_statement_or_null *this) {
    
}
// 
void ast_function_statement_or_null_action(FILE *out, struct ast_function_statement_or_null *this) {
    
}



// 
void ast_variable_identifier_list_describe(FILE *out, struct ast_variable_identifier_list *this) {
    
}
// 
void ast_variable_identifier_list_action(FILE *out, struct ast_variable_identifier_list *this) {
    
}



// 
void ast_procedural_timing_control_statement_describe(FILE *out, struct ast_procedural_timing_control_statement *this) {
    
}
// 
void ast_procedural_timing_control_statement_action(FILE *out, struct ast_procedural_timing_control_statement *this) {
    
}



// 
void ast_delay_or_event_control_describe(FILE *out, struct ast_delay_or_event_control *this) {
    
}
// 
void ast_delay_or_event_control_action(FILE *out, struct ast_delay_or_event_control *this) {
    
}



// 
void ast_delay_control_describe(FILE *out, struct ast_delay_control *this) {
    
}
// 
void ast_delay_control_action(FILE *out, struct ast_delay_control *this) {
    
}



// 
void ast_event_control_describe(FILE *out, struct ast_event_control *this) {
    
}
// 
void ast_event_control_action(FILE *out, struct ast_event_control *this) {
    
}



// 
void ast_event_expression_describe(FILE *out, struct ast_event_expression *this) {
    
}
// 
void ast_event_expression_action(FILE *out, struct ast_event_expression *this) {
    
}



// 
void ast_procedural_timing_control_describe(FILE *out, struct ast_procedural_timing_control *this) {
    
}
// 
void ast_procedural_timing_control_action(FILE *out, struct ast_procedural_timing_control *this) {
    
}



// 
void ast_jump_statement_describe(FILE *out, struct ast_jump_statement *this) {
    
}
// 
void ast_jump_statement_action(FILE *out, struct ast_jump_statement *this) {
    
}



// 
void ast_wait_statement_describe(FILE *out, struct ast_wait_statement *this) {
    
}
// 
void ast_wait_statement_action(FILE *out, struct ast_wait_statement *this) {
    
}



// 
void ast_event_trigger_describe(FILE *out, struct ast_event_trigger *this) {
    
}
// 
void ast_event_trigger_action(FILE *out, struct ast_event_trigger *this) {
    
}



// 
void ast_disable_statement_describe(FILE *out, struct ast_disable_statement *this) {
    
}
// 
void ast_disable_statement_action(FILE *out, struct ast_disable_statement *this) {
    
}



// 
void ast_conditional_statement_describe(FILE *out, struct ast_conditional_statement *this) {
    
}
// 
void ast_conditional_statement_action(FILE *out, struct ast_conditional_statement *this) {
    
}



// 
void ast_unique_priority_describe(FILE *out, struct ast_unique_priority *this) {
    
}
// 
void ast_unique_priority_action(FILE *out, struct ast_unique_priority *this) {
    
}



// 
void ast_cond_predicate_describe(FILE *out, struct ast_cond_predicate *this) {
    
}
// 
void ast_cond_predicate_action(FILE *out, struct ast_cond_predicate *this) {
    
}



// 
void ast_expression_or_cond_pattern_describe(FILE *out, struct ast_expression_or_cond_pattern *this) {
    
}
// 
void ast_expression_or_cond_pattern_action(FILE *out, struct ast_expression_or_cond_pattern *this) {
    
}



// 
void ast_cond_pattern_describe(FILE *out, struct ast_cond_pattern *this) {
    
}
// 
void ast_cond_pattern_action(FILE *out, struct ast_cond_pattern *this) {
    
}



// 
void ast_case_statement_describe(FILE *out, struct ast_case_statement *this) {
    
}
// 
void ast_case_statement_action(FILE *out, struct ast_case_statement *this) {
    
}



// 
void ast_case_keyword_describe(FILE *out, struct ast_case_keyword *this) {
    
}
// 
void ast_case_keyword_action(FILE *out, struct ast_case_keyword *this) {
    
}



// 
void ast_case_expression_describe(FILE *out, struct ast_case_expression *this) {
    
}
// 
void ast_case_expression_action(FILE *out, struct ast_case_expression *this) {
    
}



// 
void ast_case_item_describe(FILE *out, struct ast_case_item *this) {
    
}
// 
void ast_case_item_action(FILE *out, struct ast_case_item *this) {
    
}



// 
void ast_case_pattern_item_describe(FILE *out, struct ast_case_pattern_item *this) {
    
}
// 
void ast_case_pattern_item_action(FILE *out, struct ast_case_pattern_item *this) {
    
}



// 
void ast_case_inside_item_describe(FILE *out, struct ast_case_inside_item *this) {
    
}
// 
void ast_case_inside_item_action(FILE *out, struct ast_case_inside_item *this) {
    
}



// 
void ast_case_item_expression_describe(FILE *out, struct ast_case_item_expression *this) {
    
}
// 
void ast_case_item_expression_action(FILE *out, struct ast_case_item_expression *this) {
    
}



// 
void ast_randcase_statement_describe(FILE *out, struct ast_randcase_statement *this) {
    
}
// 
void ast_randcase_statement_action(FILE *out, struct ast_randcase_statement *this) {
    
}



// 
void ast_randcase_item_describe(FILE *out, struct ast_randcase_item *this) {
    
}
// 
void ast_randcase_item_action(FILE *out, struct ast_randcase_item *this) {
    
}



// 
void ast_open_range_list_describe(FILE *out, struct ast_open_range_list *this) {
    
}
// 
void ast_open_range_list_action(FILE *out, struct ast_open_range_list *this) {
    
}



// 
void ast_open_value_range_describe(FILE *out, struct ast_open_value_range *this) {
    
}
// 
void ast_open_value_range_action(FILE *out, struct ast_open_value_range *this) {
    
}



// 
void ast_pattern_describe(FILE *out, struct ast_pattern *this) {
    
}
// 
void ast_pattern_action(FILE *out, struct ast_pattern *this) {
    
}



// 
void ast_assignment_pattern_describe(FILE *out, struct ast_assignment_pattern *this) {
    
}
// 
void ast_assignment_pattern_action(FILE *out, struct ast_assignment_pattern *this) {
    
}



// 
void ast_structure_pattern_key_describe(FILE *out, struct ast_structure_pattern_key *this) {
    
}
// 
void ast_structure_pattern_key_action(FILE *out, struct ast_structure_pattern_key *this) {
    
}



// 
void ast_array_pattern_key_describe(FILE *out, struct ast_array_pattern_key *this) {
    
}
// 
void ast_array_pattern_key_action(FILE *out, struct ast_array_pattern_key *this) {
    
}



// 
void ast_assignment_pattern_key_describe(FILE *out, struct ast_assignment_pattern_key *this) {
    
}
// 
void ast_assignment_pattern_key_action(FILE *out, struct ast_assignment_pattern_key *this) {
    
}



// 
void ast_assignment_pattern_expression_describe(FILE *out, struct ast_assignment_pattern_expression *this) {
    
}
// 
void ast_assignment_pattern_expression_action(FILE *out, struct ast_assignment_pattern_expression *this) {
    
}



// 
void ast_assignment_pattern_expression_type_describe(FILE *out, struct ast_assignment_pattern_expression_type *this) {
    
}
// 
void ast_assignment_pattern_expression_type_action(FILE *out, struct ast_assignment_pattern_expression_type *this) {
    
}



// 
void ast_constant_assignment_pattern_expression_describe(FILE *out, struct ast_constant_assignment_pattern_expression *this) {
    
}
// 
void ast_constant_assignment_pattern_expression_action(FILE *out, struct ast_constant_assignment_pattern_expression *this) {
    
}



// 
void ast_assignment_pattern_net_lvalue_describe(FILE *out, struct ast_assignment_pattern_net_lvalue *this) {
    
}
// 
void ast_assignment_pattern_net_lvalue_action(FILE *out, struct ast_assignment_pattern_net_lvalue *this) {
    
}



// 
void ast_assignment_pattern_variable_lvalue_describe(FILE *out, struct ast_assignment_pattern_variable_lvalue *this) {
    
}
// 
void ast_assignment_pattern_variable_lvalue_action(FILE *out, struct ast_assignment_pattern_variable_lvalue *this) {
    
}



// 
void ast_loop_statement_describe(FILE *out, struct ast_loop_statement *this) {
    
}
// 
void ast_loop_statement_action(FILE *out, struct ast_loop_statement *this) {
    
}



// 
void ast_for_initialization_describe(FILE *out, struct ast_for_initialization *this) {
    
}
// 
void ast_for_initialization_action(FILE *out, struct ast_for_initialization *this) {
    
}



// 
void ast_for_variable_declaration_describe(FILE *out, struct ast_for_variable_declaration *this) {
    
}
// 
void ast_for_variable_declaration_action(FILE *out, struct ast_for_variable_declaration *this) {
    
}



// 
void ast_for_step_describe(FILE *out, struct ast_for_step *this) {
    
}
// 
void ast_for_step_action(FILE *out, struct ast_for_step *this) {
    
}



// 
void ast_for_step_assignment_describe(FILE *out, struct ast_for_step_assignment *this) {
    
}
// 
void ast_for_step_assignment_action(FILE *out, struct ast_for_step_assignment *this) {
    
}



// 
void ast_loop_variables_describe(FILE *out, struct ast_loop_variables *this) {
    
}
// 
void ast_loop_variables_action(FILE *out, struct ast_loop_variables *this) {
    
}



// 
void ast_subroutine_call_statement_describe(FILE *out, struct ast_subroutine_call_statement *this) {
    
}
// 
void ast_subroutine_call_statement_action(FILE *out, struct ast_subroutine_call_statement *this) {
    
}



// 
void ast_assertion_item_describe(FILE *out, struct ast_assertion_item *this) {
    
}
// 
void ast_assertion_item_action(FILE *out, struct ast_assertion_item *this) {
    
}



// 
void ast_deferred_immediate_assertion_item_describe(FILE *out, struct ast_deferred_immediate_assertion_item *this) {
    
}
// 
void ast_deferred_immediate_assertion_item_action(FILE *out, struct ast_deferred_immediate_assertion_item *this) {
    
}



// 
void ast_procedural_assertion_statement_describe(FILE *out, struct ast_procedural_assertion_statement *this) {
    
}
// 
void ast_procedural_assertion_statement_action(FILE *out, struct ast_procedural_assertion_statement *this) {
    
}



// 
void ast_immediate_assertion_statement_describe(FILE *out, struct ast_immediate_assertion_statement *this) {
    
}
// 
void ast_immediate_assertion_statement_action(FILE *out, struct ast_immediate_assertion_statement *this) {
    
}



// 
void ast_simple_immediate_assertion_statement_describe(FILE *out, struct ast_simple_immediate_assertion_statement *this) {
    
}
// 
void ast_simple_immediate_assertion_statement_action(FILE *out, struct ast_simple_immediate_assertion_statement *this) {
    
}



// 
void ast_simple_immediate_assert_statement_describe(FILE *out, struct ast_simple_immediate_assert_statement *this) {
    
}
// 
void ast_simple_immediate_assert_statement_action(FILE *out, struct ast_simple_immediate_assert_statement *this) {
    
}



// 
void ast_simple_immediate_assume_statement_describe(FILE *out, struct ast_simple_immediate_assume_statement *this) {
    
}
// 
void ast_simple_immediate_assume_statement_action(FILE *out, struct ast_simple_immediate_assume_statement *this) {
    
}



// 
void ast_simple_immediate_cover_statement_describe(FILE *out, struct ast_simple_immediate_cover_statement *this) {
    
}
// 
void ast_simple_immediate_cover_statement_action(FILE *out, struct ast_simple_immediate_cover_statement *this) {
    
}



// 
void ast_deferred_immediate_assertion_statement_describe(FILE *out, struct ast_deferred_immediate_assertion_statement *this) {
    
}
// 
void ast_deferred_immediate_assertion_statement_action(FILE *out, struct ast_deferred_immediate_assertion_statement *this) {
    
}



// 
void ast_deferred_immediate_assert_statement_describe(FILE *out, struct ast_deferred_immediate_assert_statement *this) {
    
}
// 
void ast_deferred_immediate_assert_statement_action(FILE *out, struct ast_deferred_immediate_assert_statement *this) {
    
}



// 
void ast_deferred_immediate_assume_statement_describe(FILE *out, struct ast_deferred_immediate_assume_statement *this) {
    
}
// 
void ast_deferred_immediate_assume_statement_action(FILE *out, struct ast_deferred_immediate_assume_statement *this) {
    
}



// 
void ast_deferred_immediate_cover_statement_describe(FILE *out, struct ast_deferred_immediate_cover_statement *this) {
    
}
// 
void ast_deferred_immediate_cover_statement_action(FILE *out, struct ast_deferred_immediate_cover_statement *this) {
    
}



// 
void ast_clocking_declaration_describe(FILE *out, struct ast_clocking_declaration *this) {
    
}
// 
void ast_clocking_declaration_action(FILE *out, struct ast_clocking_declaration *this) {
    
}



// 
void ast_clocking_event_describe(FILE *out, struct ast_clocking_event *this) {
    
}
// 
void ast_clocking_event_action(FILE *out, struct ast_clocking_event *this) {
    
}



// 
void ast_clocking_item_describe(FILE *out, struct ast_clocking_item *this) {
    
}
// 
void ast_clocking_item_action(FILE *out, struct ast_clocking_item *this) {
    
}



// 
void ast_default_skew_describe(FILE *out, struct ast_default_skew *this) {
    
}
// 
void ast_default_skew_action(FILE *out, struct ast_default_skew *this) {
    
}



// 
void ast_clocking_direction_describe(FILE *out, struct ast_clocking_direction *this) {
    
}
// 
void ast_clocking_direction_action(FILE *out, struct ast_clocking_direction *this) {
    
}



// 
void ast_list_of_clocking_decl_assign_describe(FILE *out, struct ast_list_of_clocking_decl_assign *this) {
    
}
// 
void ast_list_of_clocking_decl_assign_action(FILE *out, struct ast_list_of_clocking_decl_assign *this) {
    
}



// 
void ast_clocking_decl_assign_describe(FILE *out, struct ast_clocking_decl_assign *this) {
    
}
// 
void ast_clocking_decl_assign_action(FILE *out, struct ast_clocking_decl_assign *this) {
    
}



// 
void ast_clocking_skew_describe(FILE *out, struct ast_clocking_skew *this) {
    
}
// 
void ast_clocking_skew_action(FILE *out, struct ast_clocking_skew *this) {
    
}



// 
void ast_clocking_drive_describe(FILE *out, struct ast_clocking_drive *this) {
    
}
// 
void ast_clocking_drive_action(FILE *out, struct ast_clocking_drive *this) {
    
}



// 
void ast_cycle_delay_describe(FILE *out, struct ast_cycle_delay *this) {
    
}
// 
void ast_cycle_delay_action(FILE *out, struct ast_cycle_delay *this) {
    
}



// 
void ast_clockvar_describe(FILE *out, struct ast_clockvar *this) {
    
}
// 
void ast_clockvar_action(FILE *out, struct ast_clockvar *this) {
    
}



// 
void ast_clockvar_expression_describe(FILE *out, struct ast_clockvar_expression *this) {
    
}
// 
void ast_clockvar_expression_action(FILE *out, struct ast_clockvar_expression *this) {
    
}



// 
void ast_randsequence_statement_describe(FILE *out, struct ast_randsequence_statement *this) {
    
}
// 
void ast_randsequence_statement_action(FILE *out, struct ast_randsequence_statement *this) {
    
}



// 
void ast_production_describe(FILE *out, struct ast_production *this) {
    
}
// 
void ast_production_action(FILE *out, struct ast_production *this) {
    
}



// 
void ast_rs_rule_describe(FILE *out, struct ast_rs_rule *this) {
    
}
// 
void ast_rs_rule_action(FILE *out, struct ast_rs_rule *this) {
    
}



// 
void ast_rs_production_list_describe(FILE *out, struct ast_rs_production_list *this) {
    
}
// 
void ast_rs_production_list_action(FILE *out, struct ast_rs_production_list *this) {
    
}



// 
void ast_weight_specification_describe(FILE *out, struct ast_weight_specification *this) {
    
}
// 
void ast_weight_specification_action(FILE *out, struct ast_weight_specification *this) {
    
}



// 
void ast_rs_code_block_describe(FILE *out, struct ast_rs_code_block *this) {
    
}
// 
void ast_rs_code_block_action(FILE *out, struct ast_rs_code_block *this) {
    
}



// 
void ast_rs_prod_describe(FILE *out, struct ast_rs_prod *this) {
    
}
// 
void ast_rs_prod_action(FILE *out, struct ast_rs_prod *this) {
    
}



// 
void ast_production_item_describe(FILE *out, struct ast_production_item *this) {
    
}
// 
void ast_production_item_action(FILE *out, struct ast_production_item *this) {
    
}



// 
void ast_rs_if_else_describe(FILE *out, struct ast_rs_if_else *this) {
    
}
// 
void ast_rs_if_else_action(FILE *out, struct ast_rs_if_else *this) {
    
}



// 
void ast_rs_repeat_describe(FILE *out, struct ast_rs_repeat *this) {
    
}
// 
void ast_rs_repeat_action(FILE *out, struct ast_rs_repeat *this) {
    
}



// 
void ast_rs_case_describe(FILE *out, struct ast_rs_case *this) {
    
}
// 
void ast_rs_case_action(FILE *out, struct ast_rs_case *this) {
    
}



// 
void ast_rs_case_item_describe(FILE *out, struct ast_rs_case_item *this) {
    
}
// 
void ast_rs_case_item_action(FILE *out, struct ast_rs_case_item *this) {
    
}



// 
void ast_specify_block_describe(FILE *out, struct ast_specify_block *this) {
    
}
// 
void ast_specify_block_action(FILE *out, struct ast_specify_block *this) {
    
}



// 
void ast_specify_item_describe(FILE *out, struct ast_specify_item *this) {
    
}
// 
void ast_specify_item_action(FILE *out, struct ast_specify_item *this) {
    
}



// 
void ast_pulsestyle_declaration_describe(FILE *out, struct ast_pulsestyle_declaration *this) {
    
}
// 
void ast_pulsestyle_declaration_action(FILE *out, struct ast_pulsestyle_declaration *this) {
    
}



// 
void ast_showcancelled_declaration_describe(FILE *out, struct ast_showcancelled_declaration *this) {
    
}
// 
void ast_showcancelled_declaration_action(FILE *out, struct ast_showcancelled_declaration *this) {
    
}



// 
void ast_path_declaration_describe(FILE *out, struct ast_path_declaration *this) {
    
}
// 
void ast_path_declaration_action(FILE *out, struct ast_path_declaration *this) {
    
}



// 
void ast_simple_path_declaration_describe(FILE *out, struct ast_simple_path_declaration *this) {
    
}
// 
void ast_simple_path_declaration_action(FILE *out, struct ast_simple_path_declaration *this) {
    
}



// 
void ast_parallel_path_description_describe(FILE *out, struct ast_parallel_path_description *this) {
    
}
// 
void ast_parallel_path_description_action(FILE *out, struct ast_parallel_path_description *this) {
    
}



// 
void ast_full_path_description_describe(FILE *out, struct ast_full_path_description *this) {
    
}
// 
void ast_full_path_description_action(FILE *out, struct ast_full_path_description *this) {
    
}



// 
void ast_list_of_path_inputs_describe(FILE *out, struct ast_list_of_path_inputs *this) {
    
}
// 
void ast_list_of_path_inputs_action(FILE *out, struct ast_list_of_path_inputs *this) {
    
}



// 
void ast_list_of_path_outputs_describe(FILE *out, struct ast_list_of_path_outputs *this) {
    
}
// 
void ast_list_of_path_outputs_action(FILE *out, struct ast_list_of_path_outputs *this) {
    
}



// 
void ast_specify_input_terminal_descriptor_describe(FILE *out, struct ast_specify_input_terminal_descriptor *this) {
    
}
// 
void ast_specify_input_terminal_descriptor_action(FILE *out, struct ast_specify_input_terminal_descriptor *this) {
    
}



// 
void ast_specify_output_terminal_descriptor_describe(FILE *out, struct ast_specify_output_terminal_descriptor *this) {
    
}
// 
void ast_specify_output_terminal_descriptor_action(FILE *out, struct ast_specify_output_terminal_descriptor *this) {
    
}



// 
void ast_input_identifier_describe(FILE *out, struct ast_input_identifier *this) {
    
}
// 
void ast_input_identifier_action(FILE *out, struct ast_input_identifier *this) {
    
}



// 
void ast_output_identifier_describe(FILE *out, struct ast_output_identifier *this) {
    
}
// 
void ast_output_identifier_action(FILE *out, struct ast_output_identifier *this) {
    
}



// 
void ast_path_delay_value_describe(FILE *out, struct ast_path_delay_value *this) {
    
}
// 
void ast_path_delay_value_action(FILE *out, struct ast_path_delay_value *this) {
    
}



// 
void ast_list_of_path_delay_expressions_describe(FILE *out, struct ast_list_of_path_delay_expressions *this) {
    
}
// 
void ast_list_of_path_delay_expressions_action(FILE *out, struct ast_list_of_path_delay_expressions *this) {
    
}



// 
void ast_t_path_delay_expression_describe(FILE *out, struct ast_t_path_delay_expression *this) {
    
}
// 
void ast_t_path_delay_expression_action(FILE *out, struct ast_t_path_delay_expression *this) {
    
}



// 
void ast_trise_path_delay_expression_describe(FILE *out, struct ast_trise_path_delay_expression *this) {
    
}
// 
void ast_trise_path_delay_expression_action(FILE *out, struct ast_trise_path_delay_expression *this) {
    
}



// 
void ast_tfall_path_delay_expression_describe(FILE *out, struct ast_tfall_path_delay_expression *this) {
    
}
// 
void ast_tfall_path_delay_expression_action(FILE *out, struct ast_tfall_path_delay_expression *this) {
    
}



// 
void ast_tz_path_delay_expression_describe(FILE *out, struct ast_tz_path_delay_expression *this) {
    
}
// 
void ast_tz_path_delay_expression_action(FILE *out, struct ast_tz_path_delay_expression *this) {
    
}



// 
void ast_t01_path_delay_expression_describe(FILE *out, struct ast_t01_path_delay_expression *this) {
    
}
// 
void ast_t01_path_delay_expression_action(FILE *out, struct ast_t01_path_delay_expression *this) {
    
}



// 
void ast_t10_path_delay_expression_describe(FILE *out, struct ast_t10_path_delay_expression *this) {
    
}
// 
void ast_t10_path_delay_expression_action(FILE *out, struct ast_t10_path_delay_expression *this) {
    
}



// 
void ast_t0z_path_delay_expression_describe(FILE *out, struct ast_t0z_path_delay_expression *this) {
    
}
// 
void ast_t0z_path_delay_expression_action(FILE *out, struct ast_t0z_path_delay_expression *this) {
    
}



// 
void ast_tz1_path_delay_expression_describe(FILE *out, struct ast_tz1_path_delay_expression *this) {
    
}
// 
void ast_tz1_path_delay_expression_action(FILE *out, struct ast_tz1_path_delay_expression *this) {
    
}



// 
void ast_t1z_path_delay_expression_describe(FILE *out, struct ast_t1z_path_delay_expression *this) {
    
}
// 
void ast_t1z_path_delay_expression_action(FILE *out, struct ast_t1z_path_delay_expression *this) {
    
}



// 
void ast_tz0_path_delay_expression_describe(FILE *out, struct ast_tz0_path_delay_expression *this) {
    
}
// 
void ast_tz0_path_delay_expression_action(FILE *out, struct ast_tz0_path_delay_expression *this) {
    
}



// 
void ast_t0x_path_delay_expression_describe(FILE *out, struct ast_t0x_path_delay_expression *this) {
    
}
// 
void ast_t0x_path_delay_expression_action(FILE *out, struct ast_t0x_path_delay_expression *this) {
    
}



// 
void ast_tx1_path_delay_expression_describe(FILE *out, struct ast_tx1_path_delay_expression *this) {
    
}
// 
void ast_tx1_path_delay_expression_action(FILE *out, struct ast_tx1_path_delay_expression *this) {
    
}



// 
void ast_t1x_path_delay_expression_describe(FILE *out, struct ast_t1x_path_delay_expression *this) {
    
}
// 
void ast_t1x_path_delay_expression_action(FILE *out, struct ast_t1x_path_delay_expression *this) {
    
}



// 
void ast_tx0_path_delay_expression_describe(FILE *out, struct ast_tx0_path_delay_expression *this) {
    
}
// 
void ast_tx0_path_delay_expression_action(FILE *out, struct ast_tx0_path_delay_expression *this) {
    
}



// 
void ast_txz_path_delay_expression_describe(FILE *out, struct ast_txz_path_delay_expression *this) {
    
}
// 
void ast_txz_path_delay_expression_action(FILE *out, struct ast_txz_path_delay_expression *this) {
    
}



// 
void ast_tzx_path_delay_expression_describe(FILE *out, struct ast_tzx_path_delay_expression *this) {
    
}
// 
void ast_tzx_path_delay_expression_action(FILE *out, struct ast_tzx_path_delay_expression *this) {
    
}



// 
void ast_path_delay_expression_describe(FILE *out, struct ast_path_delay_expression *this) {
    
}
// 
void ast_path_delay_expression_action(FILE *out, struct ast_path_delay_expression *this) {
    
}



// 
void ast_edge_sensitive_path_declaration_describe(FILE *out, struct ast_edge_sensitive_path_declaration *this) {
    
}
// 
void ast_edge_sensitive_path_declaration_action(FILE *out, struct ast_edge_sensitive_path_declaration *this) {
    
}



// 
void ast_parallel_edge_sensitive_path_description_describe(FILE *out, struct ast_parallel_edge_sensitive_path_description *this) {
    
}
// 
void ast_parallel_edge_sensitive_path_description_action(FILE *out, struct ast_parallel_edge_sensitive_path_description *this) {
    
}



// 
void ast_full_edge_sensitive_path_description_describe(FILE *out, struct ast_full_edge_sensitive_path_description *this) {
    
}
// 
void ast_full_edge_sensitive_path_description_action(FILE *out, struct ast_full_edge_sensitive_path_description *this) {
    
}



// 
void ast_data_source_expression_describe(FILE *out, struct ast_data_source_expression *this) {
    
}
// 
void ast_data_source_expression_action(FILE *out, struct ast_data_source_expression *this) {
    
}



// 
void ast_edge_identifier_describe(FILE *out, struct ast_edge_identifier *this) {
    
}
// 
void ast_edge_identifier_action(FILE *out, struct ast_edge_identifier *this) {
    
}



// 
void ast_state_dependent_path_declaration_describe(FILE *out, struct ast_state_dependent_path_declaration *this) {
    
}
// 
void ast_state_dependent_path_declaration_action(FILE *out, struct ast_state_dependent_path_declaration *this) {
    
}



// 
void ast_polarity_operator_describe(FILE *out, struct ast_polarity_operator *this) {
    
}
// 
void ast_polarity_operator_action(FILE *out, struct ast_polarity_operator *this) {
    
}



// 
void ast_system_timing_check_describe(FILE *out, struct ast_system_timing_check *this) {
    
}
// 
void ast_system_timing_check_action(FILE *out, struct ast_system_timing_check *this) {
    
}



// 
void ast_dollarsign_setup_timing_check_describe(FILE *out, struct ast_dollarsign_setup_timing_check *this) {
    
}
// 
void ast_dollarsign_setup_timing_check_action(FILE *out, struct ast_dollarsign_setup_timing_check *this) {
    
}



// 
void ast_dollarsign_hold_timing_check_describe(FILE *out, struct ast_dollarsign_hold_timing_check *this) {
    
}
// 
void ast_dollarsign_hold_timing_check_action(FILE *out, struct ast_dollarsign_hold_timing_check *this) {
    
}



// 
void ast_dollarsign_setuphold_timing_check_describe(FILE *out, struct ast_dollarsign_setuphold_timing_check *this) {
    
}
// 
void ast_dollarsign_setuphold_timing_check_action(FILE *out, struct ast_dollarsign_setuphold_timing_check *this) {
    
}



// 
void ast_dollarsign_recovery_timing_check_describe(FILE *out, struct ast_dollarsign_recovery_timing_check *this) {
    
}
// 
void ast_dollarsign_recovery_timing_check_action(FILE *out, struct ast_dollarsign_recovery_timing_check *this) {
    
}



// 
void ast_dollarsign_removal_timing_check_describe(FILE *out, struct ast_dollarsign_removal_timing_check *this) {
    
}
// 
void ast_dollarsign_removal_timing_check_action(FILE *out, struct ast_dollarsign_removal_timing_check *this) {
    
}



// 
void ast_dollarsign_recrem_timing_check_describe(FILE *out, struct ast_dollarsign_recrem_timing_check *this) {
    
}
// 
void ast_dollarsign_recrem_timing_check_action(FILE *out, struct ast_dollarsign_recrem_timing_check *this) {
    
}



// 
void ast_dollarsign_skew_timing_check_describe(FILE *out, struct ast_dollarsign_skew_timing_check *this) {
    
}
// 
void ast_dollarsign_skew_timing_check_action(FILE *out, struct ast_dollarsign_skew_timing_check *this) {
    
}



// 
void ast_dollarsign_timeskew_timing_check_describe(FILE *out, struct ast_dollarsign_timeskew_timing_check *this) {
    
}
// 
void ast_dollarsign_timeskew_timing_check_action(FILE *out, struct ast_dollarsign_timeskew_timing_check *this) {
    
}



// 
void ast_dollarsign_fullskew_timing_check_describe(FILE *out, struct ast_dollarsign_fullskew_timing_check *this) {
    
}
// 
void ast_dollarsign_fullskew_timing_check_action(FILE *out, struct ast_dollarsign_fullskew_timing_check *this) {
    
}



// 
void ast_dollarsign_period_timing_check_describe(FILE *out, struct ast_dollarsign_period_timing_check *this) {
    
}
// 
void ast_dollarsign_period_timing_check_action(FILE *out, struct ast_dollarsign_period_timing_check *this) {
    
}



// 
void ast_dollarsign_width_timing_check_describe(FILE *out, struct ast_dollarsign_width_timing_check *this) {
    
}
// 
void ast_dollarsign_width_timing_check_action(FILE *out, struct ast_dollarsign_width_timing_check *this) {
    
}



// 
void ast_dollarsign_nochange_timing_check_describe(FILE *out, struct ast_dollarsign_nochange_timing_check *this) {
    
}
// 
void ast_dollarsign_nochange_timing_check_action(FILE *out, struct ast_dollarsign_nochange_timing_check *this) {
    
}



// 
void ast_timecheck_condition_describe(FILE *out, struct ast_timecheck_condition *this) {
    
}
// 
void ast_timecheck_condition_action(FILE *out, struct ast_timecheck_condition *this) {
    
}



// 
void ast_controlled_reference_event_describe(FILE *out, struct ast_controlled_reference_event *this) {
    
}
// 
void ast_controlled_reference_event_action(FILE *out, struct ast_controlled_reference_event *this) {
    
}



// 
void ast_data_event_describe(FILE *out, struct ast_data_event *this) {
    
}
// 
void ast_data_event_action(FILE *out, struct ast_data_event *this) {
    
}



// 
void ast_delayed_data_describe(FILE *out, struct ast_delayed_data *this) {
    
}
// 
void ast_delayed_data_action(FILE *out, struct ast_delayed_data *this) {
    
}



// 
void ast_delayed_reference_describe(FILE *out, struct ast_delayed_reference *this) {
    
}
// 
void ast_delayed_reference_action(FILE *out, struct ast_delayed_reference *this) {
    
}



// 
void ast_end_edge_offset_describe(FILE *out, struct ast_end_edge_offset *this) {
    
}
// 
void ast_end_edge_offset_action(FILE *out, struct ast_end_edge_offset *this) {
    
}



// 
void ast_event_based_flag_describe(FILE *out, struct ast_event_based_flag *this) {
    
}
// 
void ast_event_based_flag_action(FILE *out, struct ast_event_based_flag *this) {
    
}



// 
void ast_notifier_describe(FILE *out, struct ast_notifier *this) {
    
}
// 
void ast_notifier_action(FILE *out, struct ast_notifier *this) {
    
}



// 
void ast_reference_event_describe(FILE *out, struct ast_reference_event *this) {
    
}
// 
void ast_reference_event_action(FILE *out, struct ast_reference_event *this) {
    
}



// 
void ast_remain_active_flag_describe(FILE *out, struct ast_remain_active_flag *this) {
    
}
// 
void ast_remain_active_flag_action(FILE *out, struct ast_remain_active_flag *this) {
    
}



// 
void ast_timestamp_condition_describe(FILE *out, struct ast_timestamp_condition *this) {
    
}
// 
void ast_timestamp_condition_action(FILE *out, struct ast_timestamp_condition *this) {
    
}



// 
void ast_start_edge_offset_describe(FILE *out, struct ast_start_edge_offset *this) {
    
}
// 
void ast_start_edge_offset_action(FILE *out, struct ast_start_edge_offset *this) {
    
}



// 
void ast_threshold_describe(FILE *out, struct ast_threshold *this) {
    
}
// 
void ast_threshold_action(FILE *out, struct ast_threshold *this) {
    
}



// 
void ast_timing_check_limit_describe(FILE *out, struct ast_timing_check_limit *this) {
    
}
// 
void ast_timing_check_limit_action(FILE *out, struct ast_timing_check_limit *this) {
    
}



// 
void ast_timing_check_event_describe(FILE *out, struct ast_timing_check_event *this) {
    
}
// 
void ast_timing_check_event_action(FILE *out, struct ast_timing_check_event *this) {
    
}



// 
void ast_controlled_timing_check_event_describe(FILE *out, struct ast_controlled_timing_check_event *this) {
    
}
// 
void ast_controlled_timing_check_event_action(FILE *out, struct ast_controlled_timing_check_event *this) {
    
}



// 
void ast_timing_check_event_control_describe(FILE *out, struct ast_timing_check_event_control *this) {
    
}
// 
void ast_timing_check_event_control_action(FILE *out, struct ast_timing_check_event_control *this) {
    
}



// 
void ast_specify_terminal_descriptor_describe(FILE *out, struct ast_specify_terminal_descriptor *this) {
    
}
// 
void ast_specify_terminal_descriptor_action(FILE *out, struct ast_specify_terminal_descriptor *this) {
    
}



// 
void ast_edge_control_specifier_describe(FILE *out, struct ast_edge_control_specifier *this) {
    
}
// 
void ast_edge_control_specifier_action(FILE *out, struct ast_edge_control_specifier *this) {
    
}



// 
void ast_edge_descriptor_describe(FILE *out, struct ast_edge_descriptor *this) {
    
}
// 
void ast_edge_descriptor_action(FILE *out, struct ast_edge_descriptor *this) {
    
}



// 
void ast_zero_or_one_describe(FILE *out, struct ast_zero_or_one *this) {
    
}
// 
void ast_zero_or_one_action(FILE *out, struct ast_zero_or_one *this) {
    
}



// 
void ast_z_or_x_describe(FILE *out, struct ast_z_or_x *this) {
    
}
// 
void ast_z_or_x_action(FILE *out, struct ast_z_or_x *this) {
    
}



// 
void ast_timing_check_condition_describe(FILE *out, struct ast_timing_check_condition *this) {
    
}
// 
void ast_timing_check_condition_action(FILE *out, struct ast_timing_check_condition *this) {
    
}



// 
void ast_scalar_timing_check_condition_describe(FILE *out, struct ast_scalar_timing_check_condition *this) {
    
}
// 
void ast_scalar_timing_check_condition_action(FILE *out, struct ast_scalar_timing_check_condition *this) {
    
}



// 
void ast_scalar_constant_describe(FILE *out, struct ast_scalar_constant *this) {
    
}
// 
void ast_scalar_constant_action(FILE *out, struct ast_scalar_constant *this) {
    
}



// 
void ast_concatenation_describe(FILE *out, struct ast_concatenation *this) {
    
}
// 
void ast_concatenation_action(FILE *out, struct ast_concatenation *this) {
    
}



// 
void ast_constant_concatenation_describe(FILE *out, struct ast_constant_concatenation *this) {
    
}
// 
void ast_constant_concatenation_action(FILE *out, struct ast_constant_concatenation *this) {
    
}



// 
void ast_constant_multiple_concatenation_describe(FILE *out, struct ast_constant_multiple_concatenation *this) {
    
}
// 
void ast_constant_multiple_concatenation_action(FILE *out, struct ast_constant_multiple_concatenation *this) {
    
}



// 
void ast_module_path_concatenation_describe(FILE *out, struct ast_module_path_concatenation *this) {
    
}
// 
void ast_module_path_concatenation_action(FILE *out, struct ast_module_path_concatenation *this) {
    
}



// 
void ast_module_path_multiple_concatenation_describe(FILE *out, struct ast_module_path_multiple_concatenation *this) {
    
}
// 
void ast_module_path_multiple_concatenation_action(FILE *out, struct ast_module_path_multiple_concatenation *this) {
    
}



// 
void ast_multiple_concatenation_describe(FILE *out, struct ast_multiple_concatenation *this) {
    
}
// 
void ast_multiple_concatenation_action(FILE *out, struct ast_multiple_concatenation *this) {
    
}



// 
void ast_streaming_concatenation_describe(FILE *out, struct ast_streaming_concatenation *this) {
    
}
// 
void ast_streaming_concatenation_action(FILE *out, struct ast_streaming_concatenation *this) {
    
}



// 
void ast_stream_operator_describe(FILE *out, struct ast_stream_operator *this) {
    
}
// 
void ast_stream_operator_action(FILE *out, struct ast_stream_operator *this) {
    
}



// 
void ast_slice_size_describe(FILE *out, struct ast_slice_size *this) {
    
}
// 
void ast_slice_size_action(FILE *out, struct ast_slice_size *this) {
    
}



// 
void ast_stream_concatenation_describe(FILE *out, struct ast_stream_concatenation *this) {
    
}
// 
void ast_stream_concatenation_action(FILE *out, struct ast_stream_concatenation *this) {
    
}



// 
void ast_stream_expression_describe(FILE *out, struct ast_stream_expression *this) {
    
}
// 
void ast_stream_expression_action(FILE *out, struct ast_stream_expression *this) {
    
}



// 
void ast_array_range_expression_describe(FILE *out, struct ast_array_range_expression *this) {
    
}
// 
void ast_array_range_expression_action(FILE *out, struct ast_array_range_expression *this) {
    
}



// 
void ast_empty_queue_describe(FILE *out, struct ast_empty_queue *this) {
    
}
// 
void ast_empty_queue_action(FILE *out, struct ast_empty_queue *this) {
    
}



// 
void ast_constant_function_call_describe(FILE *out, struct ast_constant_function_call *this) {
    
}
// 
void ast_constant_function_call_action(FILE *out, struct ast_constant_function_call *this) {
    
}



// 
void ast_tf_call_describe(FILE *out, struct ast_tf_call *this) {
    
}
// 
void ast_tf_call_action(FILE *out, struct ast_tf_call *this) {
    
}



// 
void ast_system_tf_call_describe(FILE *out, struct ast_system_tf_call *this) {
    
}
// 
void ast_system_tf_call_action(FILE *out, struct ast_system_tf_call *this) {
    
}



// 
void ast_subroutine_call_describe(FILE *out, struct ast_subroutine_call *this) {
    
}
// 
void ast_subroutine_call_action(FILE *out, struct ast_subroutine_call *this) {
    
}



// 
void ast_function_subroutine_call_describe(FILE *out, struct ast_function_subroutine_call *this) {
    
}
// 
void ast_function_subroutine_call_action(FILE *out, struct ast_function_subroutine_call *this) {
    
}



// 
void ast_list_of_arguments_describe(FILE *out, struct ast_list_of_arguments *this) {
    
}
// 
void ast_list_of_arguments_action(FILE *out, struct ast_list_of_arguments *this) {
    
}



// 
void ast_method_call_describe(FILE *out, struct ast_method_call *this) {
    
}
// 
void ast_method_call_action(FILE *out, struct ast_method_call *this) {
    
}



// 
void ast_method_call_body_describe(FILE *out, struct ast_method_call_body *this) {
    
}
// 
void ast_method_call_body_action(FILE *out, struct ast_method_call_body *this) {
    
}



// 
void ast_built_in_method_call_describe(FILE *out, struct ast_built_in_method_call *this) {
    
}
// 
void ast_built_in_method_call_action(FILE *out, struct ast_built_in_method_call *this) {
    
}



// 
void ast_array_manipulation_call_describe(FILE *out, struct ast_array_manipulation_call *this) {
    
}
// 
void ast_array_manipulation_call_action(FILE *out, struct ast_array_manipulation_call *this) {
    
}



// 
void ast_randomize_call_describe(FILE *out, struct ast_randomize_call *this) {
    
}
// 
void ast_randomize_call_action(FILE *out, struct ast_randomize_call *this) {
    
}



// 
void ast_method_call_root_describe(FILE *out, struct ast_method_call_root *this) {
    
}
// 
void ast_method_call_root_action(FILE *out, struct ast_method_call_root *this) {
    
}



// 
void ast_array_method_name_describe(FILE *out, struct ast_array_method_name *this) {
    
}
// 
void ast_array_method_name_action(FILE *out, struct ast_array_method_name *this) {
    
}



// 
void ast_inc_or_dec_expression_describe(FILE *out, struct ast_inc_or_dec_expression *this) {
    
}
// 
void ast_inc_or_dec_expression_action(FILE *out, struct ast_inc_or_dec_expression *this) {
    
}



// 
void ast_conditional_expression_describe(FILE *out, struct ast_conditional_expression *this) {
    
}
// 
void ast_conditional_expression_action(FILE *out, struct ast_conditional_expression *this) {
    
}



// 
void ast_constant_expression_describe(FILE *out, struct ast_constant_expression *this) {
    
}
// 
void ast_constant_expression_action(FILE *out, struct ast_constant_expression *this) {
    
}



// 
void ast_constant_mintypmax_expression_describe(FILE *out, struct ast_constant_mintypmax_expression *this) {
    
}
// 
void ast_constant_mintypmax_expression_action(FILE *out, struct ast_constant_mintypmax_expression *this) {
    
}



// 
void ast_constant_param_expression_describe(FILE *out, struct ast_constant_param_expression *this) {
    
}
// 
void ast_constant_param_expression_action(FILE *out, struct ast_constant_param_expression *this) {
    
}



// 
void ast_param_expression_describe(FILE *out, struct ast_param_expression *this) {
    
}
// 
void ast_param_expression_action(FILE *out, struct ast_param_expression *this) {
    
}



// 
void ast_constant_range_expression_describe(FILE *out, struct ast_constant_range_expression *this) {
    
}
// 
void ast_constant_range_expression_action(FILE *out, struct ast_constant_range_expression *this) {
    
}



// 
void ast_constant_part_select_range_describe(FILE *out, struct ast_constant_part_select_range *this) {
    
}
// 
void ast_constant_part_select_range_action(FILE *out, struct ast_constant_part_select_range *this) {
    
}



// 
void ast_constant_range_describe(FILE *out, struct ast_constant_range *this) {
    
}
// 
void ast_constant_range_action(FILE *out, struct ast_constant_range *this) {
    
}



// 
void ast_constant_indexed_range_describe(FILE *out, struct ast_constant_indexed_range *this) {
    
}
// 
void ast_constant_indexed_range_action(FILE *out, struct ast_constant_indexed_range *this) {
    
}



// 
void ast_expression_describe(FILE *out, struct ast_expression *this) {
    
}
// 
void ast_expression_action(FILE *out, struct ast_expression *this) {
    
}



// 
void ast_tagged_union_expression_describe(FILE *out, struct ast_tagged_union_expression *this) {
    
}
// 
void ast_tagged_union_expression_action(FILE *out, struct ast_tagged_union_expression *this) {
    
}



// 
void ast_inside_expression_describe(FILE *out, struct ast_inside_expression *this) {
    
}
// 
void ast_inside_expression_action(FILE *out, struct ast_inside_expression *this) {
    
}



// 
void ast_value_range_describe(FILE *out, struct ast_value_range *this) {
    
}
// 
void ast_value_range_action(FILE *out, struct ast_value_range *this) {
    
}



// 
void ast_mintypmax_expression_describe(FILE *out, struct ast_mintypmax_expression *this) {
    
}
// 
void ast_mintypmax_expression_action(FILE *out, struct ast_mintypmax_expression *this) {
    
}



// 
void ast_module_path_conditional_expression_describe(FILE *out, struct ast_module_path_conditional_expression *this) {
    
}
// 
void ast_module_path_conditional_expression_action(FILE *out, struct ast_module_path_conditional_expression *this) {
    
}



// 
void ast_module_path_expression_describe(FILE *out, struct ast_module_path_expression *this) {
    
}
// 
void ast_module_path_expression_action(FILE *out, struct ast_module_path_expression *this) {
    
}



// 
void ast_module_path_mintypmax_expression_describe(FILE *out, struct ast_module_path_mintypmax_expression *this) {
    
}
// 
void ast_module_path_mintypmax_expression_action(FILE *out, struct ast_module_path_mintypmax_expression *this) {
    
}



// 
void ast_part_select_range_describe(FILE *out, struct ast_part_select_range *this) {
    
}
// 
void ast_part_select_range_action(FILE *out, struct ast_part_select_range *this) {
    
}



// 
void ast_indexed_range_describe(FILE *out, struct ast_indexed_range *this) {
    
}
// 
void ast_indexed_range_action(FILE *out, struct ast_indexed_range *this) {
    
}



// 
void ast_genvar_expression_describe(FILE *out, struct ast_genvar_expression *this) {
    
}
// 
void ast_genvar_expression_action(FILE *out, struct ast_genvar_expression *this) {
    
}



// 
void ast_constant_primary_describe(FILE *out, struct ast_constant_primary *this) {
    
}
// 
void ast_constant_primary_action(FILE *out, struct ast_constant_primary *this) {
    
}



// 
void ast_module_path_primary_describe(FILE *out, struct ast_module_path_primary *this) {
    
}
// 
void ast_module_path_primary_action(FILE *out, struct ast_module_path_primary *this) {
    
}



// 
void ast_primary_describe(FILE *out, struct ast_primary *this) {
    
}
// 
void ast_primary_action(FILE *out, struct ast_primary *this) {
    
}



// 
void ast_class_qualifier_describe(FILE *out, struct ast_class_qualifier *this) {
    
}
// 
void ast_class_qualifier_action(FILE *out, struct ast_class_qualifier *this) {
    
}



// 
void ast_range_expression_describe(FILE *out, struct ast_range_expression *this) {
    
}
// 
void ast_range_expression_action(FILE *out, struct ast_range_expression *this) {
    
}



// 
void ast_primary_literal_describe(FILE *out, struct ast_primary_literal *this) {
    
}
// 
void ast_primary_literal_action(FILE *out, struct ast_primary_literal *this) {
    
}



// 
void ast_time_literal_describe(FILE *out, struct ast_time_literal *this) {
    
}
// 
void ast_time_literal_action(FILE *out, struct ast_time_literal *this) {
    
}



// 
void ast_time_unit_describe(FILE *out, struct ast_time_unit *this) {
    
}
// 
void ast_time_unit_action(FILE *out, struct ast_time_unit *this) {
    
}



// 
void ast_implicit_class_handle_describe(FILE *out, struct ast_implicit_class_handle *this) {
    
}
// 
void ast_implicit_class_handle_action(FILE *out, struct ast_implicit_class_handle *this) {
    
}



// 
void ast_bit_select_describe(FILE *out, struct ast_bit_select *this) {
    
}
// 
void ast_bit_select_action(FILE *out, struct ast_bit_select *this) {
    
}



// 
void ast_select_describe(FILE *out, struct ast_select *this) {
    
}
// 
void ast_select_action(FILE *out, struct ast_select *this) {
    
}



// 
void ast_nonrange_select_describe(FILE *out, struct ast_nonrange_select *this) {
    
}
// 
void ast_nonrange_select_action(FILE *out, struct ast_nonrange_select *this) {
    
}



// 
void ast_constant_bit_select_describe(FILE *out, struct ast_constant_bit_select *this) {
    
}
// 
void ast_constant_bit_select_action(FILE *out, struct ast_constant_bit_select *this) {
    
}



// 
void ast_constant_select_describe(FILE *out, struct ast_constant_select *this) {
    
}
// 
void ast_constant_select_action(FILE *out, struct ast_constant_select *this) {
    
}



// 
void ast_constant_cast_describe(FILE *out, struct ast_constant_cast *this) {
    
}
// 
void ast_constant_cast_action(FILE *out, struct ast_constant_cast *this) {
    
}



// 
void ast_constant_let_expression_describe(FILE *out, struct ast_constant_let_expression *this) {
    
}
// 
void ast_constant_let_expression_action(FILE *out, struct ast_constant_let_expression *this) {
    
}



// 
void ast_cast_describe(FILE *out, struct ast_cast *this) {
    
}
// 
void ast_cast_action(FILE *out, struct ast_cast *this) {
    
}



// 
void ast_net_lvalue_describe(FILE *out, struct ast_net_lvalue *this) {
    
}
// 
void ast_net_lvalue_action(FILE *out, struct ast_net_lvalue *this) {
    
}



// 
void ast_variable_lvalue_describe(FILE *out, struct ast_variable_lvalue *this) {
    
}
// 
void ast_variable_lvalue_action(FILE *out, struct ast_variable_lvalue *this) {
    
}



// 
void ast_nonrange_variable_lvalue_describe(FILE *out, struct ast_nonrange_variable_lvalue *this) {
    
}
// 
void ast_nonrange_variable_lvalue_action(FILE *out, struct ast_nonrange_variable_lvalue *this) {
    
}



// 
void ast_unary_operator_describe(FILE *out, struct ast_unary_operator *this) {
    
}
// 
void ast_unary_operator_action(FILE *out, struct ast_unary_operator *this) {
    
}



// 
void ast_binary_operator_describe(FILE *out, struct ast_binary_operator *this) {
    
}
// 
void ast_binary_operator_action(FILE *out, struct ast_binary_operator *this) {
    
}



// 
void ast_inc_or_dec_operator_describe(FILE *out, struct ast_inc_or_dec_operator *this) {
    
}
// 
void ast_inc_or_dec_operator_action(FILE *out, struct ast_inc_or_dec_operator *this) {
    
}



// 
void ast_unary_module_path_operator_describe(FILE *out, struct ast_unary_module_path_operator *this) {
    
}
// 
void ast_unary_module_path_operator_action(FILE *out, struct ast_unary_module_path_operator *this) {
    
}



// 
void ast_binary_module_path_operator_describe(FILE *out, struct ast_binary_module_path_operator *this) {
    
}
// 
void ast_binary_module_path_operator_action(FILE *out, struct ast_binary_module_path_operator *this) {
    
}



// 
void ast_number_describe(FILE *out, struct ast_number *this) {
    
}
// 
void ast_number_action(FILE *out, struct ast_number *this) {
    
}



// 
void ast_integral_number_describe(FILE *out, struct ast_integral_number *this) {
    
}
// 
void ast_integral_number_action(FILE *out, struct ast_integral_number *this) {
    
}



// 
void ast_decimal_number_describe(FILE *out, struct ast_decimal_number *this) {
    
}
// 
void ast_decimal_number_action(FILE *out, struct ast_decimal_number *this) {
    
}



// 
void ast_binary_number_describe(FILE *out, struct ast_binary_number *this) {
    
}
// 
void ast_binary_number_action(FILE *out, struct ast_binary_number *this) {
    
}



// 
void ast_octal_number_describe(FILE *out, struct ast_octal_number *this) {
    
}
// 
void ast_octal_number_action(FILE *out, struct ast_octal_number *this) {
    
}



// 
void ast_hex_number_describe(FILE *out, struct ast_hex_number *this) {
    
}
// 
void ast_hex_number_action(FILE *out, struct ast_hex_number *this) {
    
}



// 
void ast_sign_describe(FILE *out, struct ast_sign *this) {
    
}
// 
void ast_sign_action(FILE *out, struct ast_sign *this) {
    
}



// 
void ast_size_describe(FILE *out, struct ast_size *this) {
    
}
// 
void ast_size_action(FILE *out, struct ast_size *this) {
    
}



// 
void ast_non_zero_unsigned_number_describe(FILE *out, struct ast_non_zero_unsigned_number *this) {
    
}
// 
void ast_non_zero_unsigned_number_action(FILE *out, struct ast_non_zero_unsigned_number *this) {
    
}



// 
void ast_real_number_describe(FILE *out, struct ast_real_number *this) {
    
}
// 
void ast_real_number_action(FILE *out, struct ast_real_number *this) {
    
}



// 
void ast_fixed_point_number_describe(FILE *out, struct ast_fixed_point_number *this) {
    
}
// 
void ast_fixed_point_number_action(FILE *out, struct ast_fixed_point_number *this) {
    
}



// 
void ast_exp_describe(FILE *out, struct ast_exp *this) {
    
}
// 
void ast_exp_action(FILE *out, struct ast_exp *this) {
    
}



// 
void ast_unsigned_number_describe(FILE *out, struct ast_unsigned_number *this) {
    
}
// 
void ast_unsigned_number_action(FILE *out, struct ast_unsigned_number *this) {
    
}



// 
void ast_binary_value_describe(FILE *out, struct ast_binary_value *this) {
    
}
// 
void ast_binary_value_action(FILE *out, struct ast_binary_value *this) {
    
}



// 
void ast_octal_value_describe(FILE *out, struct ast_octal_value *this) {
    
}
// 
void ast_octal_value_action(FILE *out, struct ast_octal_value *this) {
    
}



// 
void ast_hex_value_describe(FILE *out, struct ast_hex_value *this) {
    
}
// 
void ast_hex_value_action(FILE *out, struct ast_hex_value *this) {
    
}



// 
void ast_decimal_base_describe(FILE *out, struct ast_decimal_base *this) {
    
}
// 
void ast_decimal_base_action(FILE *out, struct ast_decimal_base *this) {
    
}



// 
void ast_binary_base_describe(FILE *out, struct ast_binary_base *this) {
    
}
// 
void ast_binary_base_action(FILE *out, struct ast_binary_base *this) {
    
}



// 
void ast_octal_base_describe(FILE *out, struct ast_octal_base *this) {
    
}
// 
void ast_octal_base_action(FILE *out, struct ast_octal_base *this) {
    
}



// 
void ast_hex_base_describe(FILE *out, struct ast_hex_base *this) {
    
}
// 
void ast_hex_base_action(FILE *out, struct ast_hex_base *this) {
    
}



// 
void ast_non_zero_decimal_digit_describe(FILE *out, struct ast_non_zero_decimal_digit *this) {
    
}
// 
void ast_non_zero_decimal_digit_action(FILE *out, struct ast_non_zero_decimal_digit *this) {
    
}



// 
void ast_decimal_digit_describe(FILE *out, struct ast_decimal_digit *this) {
    
}
// 
void ast_decimal_digit_action(FILE *out, struct ast_decimal_digit *this) {
    
}



// 
void ast_binary_digit_describe(FILE *out, struct ast_binary_digit *this) {
    
}
// 
void ast_binary_digit_action(FILE *out, struct ast_binary_digit *this) {
    
}



// 
void ast_octal_digit_describe(FILE *out, struct ast_octal_digit *this) {
    
}
// 
void ast_octal_digit_action(FILE *out, struct ast_octal_digit *this) {
    
}



// 
void ast_hex_digit_describe(FILE *out, struct ast_hex_digit *this) {
    
}
// 
void ast_hex_digit_action(FILE *out, struct ast_hex_digit *this) {
    
}



// 
void ast_x_digit_describe(FILE *out, struct ast_x_digit *this) {
    
}
// 
void ast_x_digit_action(FILE *out, struct ast_x_digit *this) {
    
}



// 
void ast_z_digit_describe(FILE *out, struct ast_z_digit *this) {
    
}
// 
void ast_z_digit_action(FILE *out, struct ast_z_digit *this) {
    
}



// 
void ast_unbased_unsized_literal_describe(FILE *out, struct ast_unbased_unsized_literal *this) {
    
}
// 
void ast_unbased_unsized_literal_action(FILE *out, struct ast_unbased_unsized_literal *this) {
    
}



// 
void ast_string_literal_describe(FILE *out, struct ast_string_literal *this) {
    
}
// 
void ast_string_literal_action(FILE *out, struct ast_string_literal *this) {
    
}



// 
void ast_attribute_instance_describe(FILE *out, struct ast_attribute_instance *this) {
    
}
// 
void ast_attribute_instance_action(FILE *out, struct ast_attribute_instance *this) {
    
}



// 
void ast_attr_spec_describe(FILE *out, struct ast_attr_spec *this) {
    
}
// 
void ast_attr_spec_action(FILE *out, struct ast_attr_spec *this) {
    
}



// 
void ast_attr_name_describe(FILE *out, struct ast_attr_name *this) {
    
}
// 
void ast_attr_name_action(FILE *out, struct ast_attr_name *this) {
    
}



// 
void ast_comment_describe(FILE *out, struct ast_comment *this) {
    
}
// 
void ast_comment_action(FILE *out, struct ast_comment *this) {
    
}



// 
void ast_one_line_comment_describe(FILE *out, struct ast_one_line_comment *this) {
    
}
// 
void ast_one_line_comment_action(FILE *out, struct ast_one_line_comment *this) {
    
}



// 
void ast_block_comment_describe(FILE *out, struct ast_block_comment *this) {
    
}
// 
void ast_block_comment_action(FILE *out, struct ast_block_comment *this) {
    
}



// 
void ast_comment_text_describe(FILE *out, struct ast_comment_text *this) {
    
}
// 
void ast_comment_text_action(FILE *out, struct ast_comment_text *this) {
    
}



// 
void ast_array_identifier_describe(FILE *out, struct ast_array_identifier *this) {
    
}
// 
void ast_array_identifier_action(FILE *out, struct ast_array_identifier *this) {
    
}



// 
void ast_block_identifier_describe(FILE *out, struct ast_block_identifier *this) {
    
}
// 
void ast_block_identifier_action(FILE *out, struct ast_block_identifier *this) {
    
}



// 
void ast_bin_identifier_describe(FILE *out, struct ast_bin_identifier *this) {
    
}
// 
void ast_bin_identifier_action(FILE *out, struct ast_bin_identifier *this) {
    
}



// 
void ast_c_identifier_describe(FILE *out, struct ast_c_identifier *this) {
    
}
// 
void ast_c_identifier_action(FILE *out, struct ast_c_identifier *this) {
    
}



// 
void ast_cell_identifier_describe(FILE *out, struct ast_cell_identifier *this) {
    
}
// 
void ast_cell_identifier_action(FILE *out, struct ast_cell_identifier *this) {
    
}



// 
void ast_checker_identifier_describe(FILE *out, struct ast_checker_identifier *this) {
    
}
// 
void ast_checker_identifier_action(FILE *out, struct ast_checker_identifier *this) {
    
}



// 
void ast_class_identifier_describe(FILE *out, struct ast_class_identifier *this) {
    
}
// 
void ast_class_identifier_action(FILE *out, struct ast_class_identifier *this) {
    
}



// 
void ast_class_variable_identifier_describe(FILE *out, struct ast_class_variable_identifier *this) {
    
}
// 
void ast_class_variable_identifier_action(FILE *out, struct ast_class_variable_identifier *this) {
    
}



// 
void ast_clocking_identifier_describe(FILE *out, struct ast_clocking_identifier *this) {
    
}
// 
void ast_clocking_identifier_action(FILE *out, struct ast_clocking_identifier *this) {
    
}



// 
void ast_config_identifier_describe(FILE *out, struct ast_config_identifier *this) {
    
}
// 
void ast_config_identifier_action(FILE *out, struct ast_config_identifier *this) {
    
}



// 
void ast_const_identifier_describe(FILE *out, struct ast_const_identifier *this) {
    
}
// 
void ast_const_identifier_action(FILE *out, struct ast_const_identifier *this) {
    
}



// 
void ast_constraint_identifier_describe(FILE *out, struct ast_constraint_identifier *this) {
    
}
// 
void ast_constraint_identifier_action(FILE *out, struct ast_constraint_identifier *this) {
    
}



// 
void ast_covergroup_identifier_describe(FILE *out, struct ast_covergroup_identifier *this) {
    
}
// 
void ast_covergroup_identifier_action(FILE *out, struct ast_covergroup_identifier *this) {
    
}



// 
void ast_covergroup_variable_identifier_describe(FILE *out, struct ast_covergroup_variable_identifier *this) {
    
}
// 
void ast_covergroup_variable_identifier_action(FILE *out, struct ast_covergroup_variable_identifier *this) {
    
}



// 
void ast_cover_point_identifier_describe(FILE *out, struct ast_cover_point_identifier *this) {
    
}
// 
void ast_cover_point_identifier_action(FILE *out, struct ast_cover_point_identifier *this) {
    
}



// 
void ast_cross_identifier_describe(FILE *out, struct ast_cross_identifier *this) {
    
}
// 
void ast_cross_identifier_action(FILE *out, struct ast_cross_identifier *this) {
    
}



// 
void ast_dynamic_array_variable_identifier_describe(FILE *out, struct ast_dynamic_array_variable_identifier *this) {
    
}
// 
void ast_dynamic_array_variable_identifier_action(FILE *out, struct ast_dynamic_array_variable_identifier *this) {
    
}



// 
void ast_enum_identifier_describe(FILE *out, struct ast_enum_identifier *this) {
    
}
// 
void ast_enum_identifier_action(FILE *out, struct ast_enum_identifier *this) {
    
}



// 
void ast_escaped_identifier_describe(FILE *out, struct ast_escaped_identifier *this) {
    
}
// 
void ast_escaped_identifier_action(FILE *out, struct ast_escaped_identifier *this) {
    
}



// 
void ast_formal_identifier_describe(FILE *out, struct ast_formal_identifier *this) {
    
}
// 
void ast_formal_identifier_action(FILE *out, struct ast_formal_identifier *this) {
    
}



// 
void ast_formal_port_identifier_describe(FILE *out, struct ast_formal_port_identifier *this) {
    
}
// 
void ast_formal_port_identifier_action(FILE *out, struct ast_formal_port_identifier *this) {
    
}



// 
void ast_function_identifier_describe(FILE *out, struct ast_function_identifier *this) {
    
}
// 
void ast_function_identifier_action(FILE *out, struct ast_function_identifier *this) {
    
}



// 
void ast_generate_block_identifier_describe(FILE *out, struct ast_generate_block_identifier *this) {
    
}
// 
void ast_generate_block_identifier_action(FILE *out, struct ast_generate_block_identifier *this) {
    
}



// 
void ast_genvar_identifier_describe(FILE *out, struct ast_genvar_identifier *this) {
    
}
// 
void ast_genvar_identifier_action(FILE *out, struct ast_genvar_identifier *this) {
    
}



// 
void ast_hierarchical_array_identifier_describe(FILE *out, struct ast_hierarchical_array_identifier *this) {
    
}
// 
void ast_hierarchical_array_identifier_action(FILE *out, struct ast_hierarchical_array_identifier *this) {
    
}



// 
void ast_hierarchical_block_identifier_describe(FILE *out, struct ast_hierarchical_block_identifier *this) {
    
}
// 
void ast_hierarchical_block_identifier_action(FILE *out, struct ast_hierarchical_block_identifier *this) {
    
}



// 
void ast_hierarchical_event_identifier_describe(FILE *out, struct ast_hierarchical_event_identifier *this) {
    
}
// 
void ast_hierarchical_event_identifier_action(FILE *out, struct ast_hierarchical_event_identifier *this) {
    
}



// 
void ast_hierarchical_identifier_describe(FILE *out, struct ast_hierarchical_identifier *this) {
    
}
// 
void ast_hierarchical_identifier_action(FILE *out, struct ast_hierarchical_identifier *this) {
    
}



// 
void ast_hierarchical_net_identifier_describe(FILE *out, struct ast_hierarchical_net_identifier *this) {
    
}
// 
void ast_hierarchical_net_identifier_action(FILE *out, struct ast_hierarchical_net_identifier *this) {
    
}



// 
void ast_hierarchical_parameter_identifier_describe(FILE *out, struct ast_hierarchical_parameter_identifier *this) {
    
}
// 
void ast_hierarchical_parameter_identifier_action(FILE *out, struct ast_hierarchical_parameter_identifier *this) {
    
}



// 
void ast_hierarchical_property_identifier_describe(FILE *out, struct ast_hierarchical_property_identifier *this) {
    
}
// 
void ast_hierarchical_property_identifier_action(FILE *out, struct ast_hierarchical_property_identifier *this) {
    
}



// 
void ast_hierarchical_sequence_identifier_describe(FILE *out, struct ast_hierarchical_sequence_identifier *this) {
    
}
// 
void ast_hierarchical_sequence_identifier_action(FILE *out, struct ast_hierarchical_sequence_identifier *this) {
    
}



// 
void ast_hierarchical_task_identifier_describe(FILE *out, struct ast_hierarchical_task_identifier *this) {
    
}
// 
void ast_hierarchical_task_identifier_action(FILE *out, struct ast_hierarchical_task_identifier *this) {
    
}



// 
void ast_hierarchical_tf_identifier_describe(FILE *out, struct ast_hierarchical_tf_identifier *this) {
    
}
// 
void ast_hierarchical_tf_identifier_action(FILE *out, struct ast_hierarchical_tf_identifier *this) {
    
}



// 
void ast_hierarchical_variable_identifier_describe(FILE *out, struct ast_hierarchical_variable_identifier *this) {
    
}
// 
void ast_hierarchical_variable_identifier_action(FILE *out, struct ast_hierarchical_variable_identifier *this) {
    
}



// 
void ast_identifier_describe(FILE *out, struct ast_identifier *this) {
    
}
// 
void ast_identifier_action(FILE *out, struct ast_identifier *this) {
    
}



// 
void ast_index_variable_identifier_describe(FILE *out, struct ast_index_variable_identifier *this) {
    
}
// 
void ast_index_variable_identifier_action(FILE *out, struct ast_index_variable_identifier *this) {
    
}



// 
void ast_interface_identifier_describe(FILE *out, struct ast_interface_identifier *this) {
    
}
// 
void ast_interface_identifier_action(FILE *out, struct ast_interface_identifier *this) {
    
}



// 
void ast_interface_instance_identifier_describe(FILE *out, struct ast_interface_instance_identifier *this) {
    
}
// 
void ast_interface_instance_identifier_action(FILE *out, struct ast_interface_instance_identifier *this) {
    
}



// 
void ast_inout_port_identifier_describe(FILE *out, struct ast_inout_port_identifier *this) {
    
}
// 
void ast_inout_port_identifier_action(FILE *out, struct ast_inout_port_identifier *this) {
    
}



// 
void ast_input_port_identifier_describe(FILE *out, struct ast_input_port_identifier *this) {
    
}
// 
void ast_input_port_identifier_action(FILE *out, struct ast_input_port_identifier *this) {
    
}



// 
void ast_instance_identifier_describe(FILE *out, struct ast_instance_identifier *this) {
    
}
// 
void ast_instance_identifier_action(FILE *out, struct ast_instance_identifier *this) {
    
}



// 
void ast_library_identifier_describe(FILE *out, struct ast_library_identifier *this) {
    
}
// 
void ast_library_identifier_action(FILE *out, struct ast_library_identifier *this) {
    
}



// 
void ast_member_identifier_describe(FILE *out, struct ast_member_identifier *this) {
    
}
// 
void ast_member_identifier_action(FILE *out, struct ast_member_identifier *this) {
    
}



// 
void ast_method_identifier_describe(FILE *out, struct ast_method_identifier *this) {
    
}
// 
void ast_method_identifier_action(FILE *out, struct ast_method_identifier *this) {
    
}



// 
void ast_modport_identifier_describe(FILE *out, struct ast_modport_identifier *this) {
    
}
// 
void ast_modport_identifier_action(FILE *out, struct ast_modport_identifier *this) {
    
}



// 
void ast_module_identifier_describe(FILE *out, struct ast_module_identifier *this) {
    
}
// 
void ast_module_identifier_action(FILE *out, struct ast_module_identifier *this) {
    
}



// 
void ast_net_identifier_describe(FILE *out, struct ast_net_identifier *this) {
    
}
// 
void ast_net_identifier_action(FILE *out, struct ast_net_identifier *this) {
    
}



// 
void ast_net_type_identifier_describe(FILE *out, struct ast_net_type_identifier *this) {
    
}
// 
void ast_net_type_identifier_action(FILE *out, struct ast_net_type_identifier *this) {
    
}



// 
void ast_output_port_identifier_describe(FILE *out, struct ast_output_port_identifier *this) {
    
}
// 
void ast_output_port_identifier_action(FILE *out, struct ast_output_port_identifier *this) {
    
}



// 
void ast_package_identifier_describe(FILE *out, struct ast_package_identifier *this) {
    
}
// 
void ast_package_identifier_action(FILE *out, struct ast_package_identifier *this) {
    
}



// 
void ast_package_scope_describe(FILE *out, struct ast_package_scope *this) {
    
}
// 
void ast_package_scope_action(FILE *out, struct ast_package_scope *this) {
    
}



// 
void ast_parameter_identifier_describe(FILE *out, struct ast_parameter_identifier *this) {
    
}
// 
void ast_parameter_identifier_action(FILE *out, struct ast_parameter_identifier *this) {
    
}



// 
void ast_port_identifier_describe(FILE *out, struct ast_port_identifier *this) {
    
}
// 
void ast_port_identifier_action(FILE *out, struct ast_port_identifier *this) {
    
}



// 
void ast_production_identifier_describe(FILE *out, struct ast_production_identifier *this) {
    
}
// 
void ast_production_identifier_action(FILE *out, struct ast_production_identifier *this) {
    
}



// 
void ast_program_identifier_describe(FILE *out, struct ast_program_identifier *this) {
    
}
// 
void ast_program_identifier_action(FILE *out, struct ast_program_identifier *this) {
    
}



// 
void ast_property_identifier_describe(FILE *out, struct ast_property_identifier *this) {
    
}
// 
void ast_property_identifier_action(FILE *out, struct ast_property_identifier *this) {
    
}



// 
void ast_ps_class_identifier_describe(FILE *out, struct ast_ps_class_identifier *this) {
    
}
// 
void ast_ps_class_identifier_action(FILE *out, struct ast_ps_class_identifier *this) {
    
}



// 
void ast_ps_covergroup_identifier_describe(FILE *out, struct ast_ps_covergroup_identifier *this) {
    
}
// 
void ast_ps_covergroup_identifier_action(FILE *out, struct ast_ps_covergroup_identifier *this) {
    
}



// 
void ast_ps_checker_identifier_describe(FILE *out, struct ast_ps_checker_identifier *this) {
    
}
// 
void ast_ps_checker_identifier_action(FILE *out, struct ast_ps_checker_identifier *this) {
    
}



// 
void ast_ps_identifier_describe(FILE *out, struct ast_ps_identifier *this) {
    
}
// 
void ast_ps_identifier_action(FILE *out, struct ast_ps_identifier *this) {
    
}



// 
void ast_ps_or_hierarchical_array_identifier_describe(FILE *out, struct ast_ps_or_hierarchical_array_identifier *this) {
    
}
// 
void ast_ps_or_hierarchical_array_identifier_action(FILE *out, struct ast_ps_or_hierarchical_array_identifier *this) {
    
}



// 
void ast_ps_or_hierarchical_net_identifier_describe(FILE *out, struct ast_ps_or_hierarchical_net_identifier *this) {
    
}
// 
void ast_ps_or_hierarchical_net_identifier_action(FILE *out, struct ast_ps_or_hierarchical_net_identifier *this) {
    
}



// 
void ast_ps_or_hierarchical_property_identifier_describe(FILE *out, struct ast_ps_or_hierarchical_property_identifier *this) {
    
}
// 
void ast_ps_or_hierarchical_property_identifier_action(FILE *out, struct ast_ps_or_hierarchical_property_identifier *this) {
    
}



// 
void ast_ps_or_hierarchical_sequence_identifier_describe(FILE *out, struct ast_ps_or_hierarchical_sequence_identifier *this) {
    
}
// 
void ast_ps_or_hierarchical_sequence_identifier_action(FILE *out, struct ast_ps_or_hierarchical_sequence_identifier *this) {
    
}



// 
void ast_ps_or_hierarchical_tf_identifier_describe(FILE *out, struct ast_ps_or_hierarchical_tf_identifier *this) {
    
}
// 
void ast_ps_or_hierarchical_tf_identifier_action(FILE *out, struct ast_ps_or_hierarchical_tf_identifier *this) {
    
}



// 
void ast_ps_parameter_identifier_describe(FILE *out, struct ast_ps_parameter_identifier *this) {
    
}
// 
void ast_ps_parameter_identifier_action(FILE *out, struct ast_ps_parameter_identifier *this) {
    
}



// 
void ast_ps_type_identifier_describe(FILE *out, struct ast_ps_type_identifier *this) {
    
}
// 
void ast_ps_type_identifier_action(FILE *out, struct ast_ps_type_identifier *this) {
    
}



// 
void ast_sequence_identifier_describe(FILE *out, struct ast_sequence_identifier *this) {
    
}
// 
void ast_sequence_identifier_action(FILE *out, struct ast_sequence_identifier *this) {
    
}



// 
void ast_signal_identifier_describe(FILE *out, struct ast_signal_identifier *this) {
    
}
// 
void ast_signal_identifier_action(FILE *out, struct ast_signal_identifier *this) {
    
}



// 
void ast_simple_identifier_describe(FILE *out, struct ast_simple_identifier *this) {
    
}
// 
void ast_simple_identifier_action(FILE *out, struct ast_simple_identifier *this) {
    
}



// 
void ast_specparam_identifier_describe(FILE *out, struct ast_specparam_identifier *this) {
    
}
// 
void ast_specparam_identifier_action(FILE *out, struct ast_specparam_identifier *this) {
    
}



// 
void ast_system_tf_identifier_describe(FILE *out, struct ast_system_tf_identifier *this) {
    
}
// 
void ast_system_tf_identifier_action(FILE *out, struct ast_system_tf_identifier *this) {
    
}



// 
void ast_task_identifier_describe(FILE *out, struct ast_task_identifier *this) {
    
}
// 
void ast_task_identifier_action(FILE *out, struct ast_task_identifier *this) {
    
}



// 
void ast_tf_identifier_describe(FILE *out, struct ast_tf_identifier *this) {
    
}
// 
void ast_tf_identifier_action(FILE *out, struct ast_tf_identifier *this) {
    
}



// 
void ast_terminal_identifier_describe(FILE *out, struct ast_terminal_identifier *this) {
    
}
// 
void ast_terminal_identifier_action(FILE *out, struct ast_terminal_identifier *this) {
    
}



// 
void ast_topmodule_identifier_describe(FILE *out, struct ast_topmodule_identifier *this) {
    
}
// 
void ast_topmodule_identifier_action(FILE *out, struct ast_topmodule_identifier *this) {
    
}



// 
void ast_type_identifier_describe(FILE *out, struct ast_type_identifier *this) {
    
}
// 
void ast_type_identifier_action(FILE *out, struct ast_type_identifier *this) {
    
}



// 
void ast_udp_identifier_describe(FILE *out, struct ast_udp_identifier *this) {
    
}
// 
void ast_udp_identifier_action(FILE *out, struct ast_udp_identifier *this) {
    
}



// 
void ast_variable_identifier_describe(FILE *out, struct ast_variable_identifier *this) {
    
}
// 
void ast_variable_identifier_action(FILE *out, struct ast_variable_identifier *this) {
    
}



// 
void ast_white_space_describe(FILE *out, struct ast_white_space *this) {
    
}
// 
void ast_white_space_action(FILE *out, struct ast_white_space *this) {
    
}



// 
void ast_file_path_spec_describe(FILE *out, struct ast_file_path_spec *this) {
    
}
// 
void ast_file_path_spec_action(FILE *out, struct ast_file_path_spec *this) {
    
}



