#include <iostream>
#include <string>

#include "Tree.hpp"
using namespace ast;

// 
int main(void) {
    // 
    symbol_value_element_list list;

    //
    mcc_symbol *a                  = new mcc_symbol       ("a");
    list_parameter *LIST_1         = new list_parameter   ();
    {
        list_parameter_value *value = new list_parameter_value();
        symbol_value_list *sv_list = new symbol_value_list();
        value->_symbol_value_list = sv_list;
        LIST_1->_list_parameter_value = value;
    }
    mcc_string *b                  = new mcc_string       ("b");
    option_parameter *OPT_1        = new option_parameter ();
    {
        option_parameter_value *value = new option_parameter_value();
        OPT_1->_option_parameter_value = value;
    }
    mcc_symbol *c                  = new mcc_symbol       ("c");
    star_parameter *STAR_1         = new star_parameter   ();
    {

    }
    mcc_string *d                  = new mcc_string       ("d");

    // 
    list.push_back(a);
    list.push_back(LIST_1);
    list.push_back(b);
    list.push_back(OPT_1);
    list.push_back(c);
    list.push_back(STAR_1);
    list.push_back(d);

    // 
    return 0;
}


