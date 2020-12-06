#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

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
        symbol_value *sv = new symbol_value();
        symbol_value_element_list *sve_list = new symbol_value_element_list();
        mcc_symbol *symbol = new mcc_symbol("x");
        sve_list->push_back(symbol);
        sv->_symbol_value_element_list = sve_list;
        sv_list->push_back(sv);
        value->_symbol_value_list = sv_list;
        LIST_1->_list_parameter_value = value;
    }
    mcc_string *b                  = new mcc_string       ("b");
    option_parameter *OPT_1        = new option_parameter ();
    {
        option_parameter_value *value = new option_parameter_value();
        symbol_value_list *sv_list = new symbol_value_list();
        symbol_value *sv = new symbol_value();
        symbol_value_element_list *sve_list = new symbol_value_element_list();
        mcc_symbol *symbol = new mcc_symbol("y");
        sve_list->push_back(symbol);
        sv->_symbol_value_element_list = sve_list;
        sv_list->push_back(sv);
        value->_symbol_value_list = sv_list;
        OPT_1->_option_parameter_value = value;
    }
    mcc_symbol *c                  = new mcc_symbol       ("c");
    star_parameter *STAR_1         = new star_parameter   ();
    {
        star_parameter_value *value = new star_parameter_value();
        list_parameter *lp = new list_parameter();
        list_parameter_value *lp_value = new list_parameter_value();
        symbol_value_list *sv_list = new symbol_value_list();
        symbol_value *sv = new symbol_value();
        symbol_value_element_list *sve_list = new symbol_value_element_list();
        mcc_symbol *symbol = new mcc_symbol("LIST_2");
        sve_list->push_back(symbol);
        sv->_symbol_value_element_list = sve_list;
        sv_list->push_back(sv);
        lp_value->_symbol_value_list = sv_list;
        lp->_list_parameter_value = lp_value;
        value->_list_parameter = lp;
        STAR_1->_star_parameter_value = value;
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
    std::vector<ast::symbol_value_element *> emit_stack;
    bool all_emitted;
    do {
        all_emitted = true;
        std::vector<bool> emitted;

        //
        for (int i=0, len=list._list.size(); i < len; ++i) {
            ast::symbol_value_element *elem = list._list[i];
            emitted.push_back(elem->emit(emit_stack));
        }

        //
        for (int i=0, len=emitted.size(); i < len; ++i) {
            if (emitted[i] == false) {
                all_emitted = false;
                break;
            }
        }

        //
        for (int i=0, len=list._list.size(); i < len; ++i) {
            symbol_value_element *elem = list._list[i];

            if (typeid(*elem) == typeid(mcc_string)) {
                mcc_string *casted = static_cast<mcc_string *>(elem);
                std::string value = casted->_value;
                printf("%s ", value.c_str());
            }
            else if (typeid(*elem) == typeid(mcc_symbol)) {
                mcc_symbol *casted = static_cast<mcc_symbol *>(elem);
                std::string value = casted->_value;
                printf("%s ", value.c_str());
            }
            else if (typeid(*elem) == typeid(list_parameter)) {
                list_parameter *casted = static_cast<list_parameter *>(elem);
                // std::string value = casted->_value;
                printf("LIST ");
            }
            else if (typeid(*elem) == typeid(option_parameter)) {
                option_parameter *casted = static_cast<option_parameter *>(elem);
                // std::string value = casted->_value;
                printf("OPTION ");
            }
            else if (typeid(*elem) == typeid(star_parameter)) {
                star_parameter *casted = static_cast<star_parameter *>(elem);
                // std::string value = casted->_value;
                printf("STAR ");
            }
        }
        printf("\n");

        //
        break;
    } while (all_emitted);

    // 
    return 0;
}


