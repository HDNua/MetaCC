#ifndef __TREE_HPP__
#define __TREE_HPP__


#include <string>
#include <vector>


// 
namespace ast {
    
}


// 
namespace ast {
    // 
    struct object {

    public:
    };

    // 
    template <class Type>
    struct list: public object {
        std::vector<Type> _list;
    public:
        //
        void push_back(const Type &value) {
            _list.push_back(value);
        }
    };
    //
    struct symbol_definition_list: public list<struct symbol_definition *> {

    public:
        //
        void push_back(struct symbol_definition *value) {
            _list.push_back(value);
        }
    };
    // 
    struct symbol_value_list: public list<struct symbol_value *> {

    public:
        //
        void push_back(struct symbol_value *value) {
            _list.push_back(value);
        }
    };
    //
    struct symbol_value_element_list: public list<struct symbol_value_element *> {

    public:
        //
        void push_back(struct symbol_value_element *value) {
            _list.push_back(value);
        }
    };


    // 
    struct start: public object {
        symbol_definition_list *_symbol_definition_list;
    
    public:

    };
    // 
    struct symbol_definition: public object {
        struct symbol_key *_symbol_key;
        symbol_value_list *_symbol_value_list;

    public:

    };
    // 
    struct symbol_key: public object {
        struct mcc_string *_value;

    public:

    };
    // 
    struct symbol_value: public object {
        symbol_value_element_list *_symbol_value_element_list;

    public:

    };
    // 
    struct symbol_value_element: public object {

    public:
        virtual bool emit(std::vector<symbol_value_element *> &v) = 0;
    };
    // 
    struct mcc_symbol: public symbol_value_element {
        std::string _value;

    public:
        //
        mcc_symbol(const std::string &value): _value(value) { }
        //
        virtual bool emit(std::vector<symbol_value_element *> &v) {
            v.push_back(this);
            return true;
        }
    };
    // 
    struct mcc_string: public symbol_value_element {
        std::string _value;

    public:
        //
        mcc_string(const std::string &value): _value(value) { }
        //
        virtual bool emit(std::vector<symbol_value_element *> &v) {
            v.push_back(this);
            return true;
        }
    };
    // 
    struct list_parameter: public symbol_value_element {
        struct list_parameter_value *_list_parameter_value;
        struct mcc_string *_list_parameter_delim;

    public:
        //
        virtual bool emit(std::vector<symbol_value_element *> &v) {
            v.push_back(this);
            return true;
        }
    };
    // 
    struct list_parameter_value: public object {
        symbol_value_list *_symbol_value_list;

    public:

    };
    // 
    struct option_parameter: public symbol_value_element {
        struct option_parameter_value *_option_parameter_value;

    public:
        //
        virtual bool emit(std::vector<symbol_value_element *> &v) {
            v.push_back(this);
            return true;
        }
    };
    // 
    struct option_parameter_value: public object {
        symbol_value_list *_symbol_value_list;
        
    public:

    };
    // 
    struct star_parameter: public symbol_value_element {
        struct star_parameter_value *_star_parameter_value;

    public:
        //
        virtual bool emit(std::vector<symbol_value_element *> &v) {
            v.push_back(this);
            return true;
        }
    };
    // 
    struct star_parameter_value: public object {
        struct list_parameter *_list_parameter;

    public:

    };
}


#endif
