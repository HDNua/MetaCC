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
        // 
        virtual std::vector<object *> &emit(std::vector<object *> &v) = 0;
    };

    // 
    template <class Type>
    struct list: public object {
        std::vector<Type> _list;
    public:
        virtual std::vector<object *> &emit(std::vector<object *> &v) {
            return v;
        }
    };

    /*
    template <>
    struct list<struct symbol_definition *>: public object {

    public:
        virtual std::vector<object *> &emit(std::vector<object *> &v) { 
            return v;
        }
    };
    typedef list<symbol_definition *> symbol_definition_list;
    */
    struct symbol_definition_list: public list<struct symbol_definition *> {

    public:
        virtual std::vector<object *> &emit(std::vector<object *> &v) {
            return v;
        }
    };

    // 
    template <>
    struct list<struct symbol_value *>: public object {

    public:
        virtual std::vector<object *> &emit(std::vector<object *> &v) { 
            return v;
        }
    };
    typedef list<symbol_value *> symbol_value_list;

    //
    template <>
    struct list<struct symbol_value_element *>: public object {

    public:
        virtual std::vector<object *> &emit(std::vector<object *> &v) { 
            return v;
        }
    };
    typedef list<symbol_value_element *> symbol_value_element_list;

    // 
    struct start: public object {
        symbol_definition_list *_symbol_definition_list;
    
    public:
        virtual std::vector<object *> &emit(std::vector<object *> &v) {
            return v;
        }
    };
    // 
    struct symbol_definition: public object {
        struct symbol_key *_symbol_key;
        symbol_value_list *_symbol_value_list;

    public:
        virtual std::vector<object *> &emit(std::vector<object *> &v) { 
            return v;
        }
    };
    // 
    struct symbol_key: public object {
        struct mcc_string *_value;

    public:
        virtual std::vector<object *> &emit(std::vector<object *> &v) { 
            return v;
        }
    };
    // 
    struct symbol_value: public object {
        symbol_value_element_list *_symbol_value_element_list;

    public:
        virtual std::vector<object *> &emit(std::vector<object *> &v) { 
            return v;
        }
    };
    // 
    struct symbol_value_element: public object {

    public:
        virtual std::vector<object *> &emit(std::vector<object *> &v) { 
            return v;
        }
    };
    // 
    struct mcc_symbol: public symbol_value_element {
        std::string _value;

    public:
        //
        mcc_symbol(const std::string &value): _value(value) { }
        //
        virtual std::vector<object *> &emit(std::vector<object *> &v) { 
            return v;
        }
    };
    // 
    struct mcc_string: public symbol_value_element {
        std::string _value;

    public:
        //
        mcc_string(const std::string &value): _value(value) { }
        //
        virtual std::vector<object *> &emit(std::vector<object *> &v) { 
            return v;
        }
    };
    // 
    struct list_parameter: public symbol_value_element {
        struct list_parameter_value *_list_parameter_value;

    public:
        virtual std::vector<object *> &emit(std::vector<object *> &v) { 
            return v;
        }
    };
    // 
    struct list_parameter_value: public object {
        symbol_value_list *_symbol_value_list;

    public:
        virtual std::vector<object *> &emit(std::vector<object *> &v) { 
            return v;
        }
    };
    // 
    struct option_parameter: public symbol_value_element {
        struct option_parameter_value *_option_parameter_value;

    public:
        virtual std::vector<object *> &emit(std::vector<object *> &v) { 
            return v;
        }
    };
    // 
    struct option_parameter_value: public object {
        symbol_value_list *_symbol_value_list;
        
    public:
        virtual std::vector<object *> &emit(std::vector<object *> &v) { 
            return v;
        }
    };
    // 
    struct star_parameter: public symbol_value_element {
        struct star_parameter_value *_star_parameter_value;

    public:
        virtual std::vector<object *> &emit(std::vector<object *> &v) { 
            return v;
        }
    };
    // 
    struct star_parameter_value: public object {
        struct list_parameter *_list_parameter;

    public:
        virtual std::vector<object *> &emit(std::vector<object *> &v) { 
            return v;
        }
    };
}


#endif
