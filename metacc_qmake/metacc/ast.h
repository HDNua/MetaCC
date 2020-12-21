#ifndef __HANDY_AST_H__
#define __HANDY_AST_H__

// #include <stdio.h>
// #include <string.h>

#include <string>
#include <vector>
#include <map>
#include <typeinfo>
#include <exception>
#include <stdexcept>

#include <cstdio>
#include <cstring>

#include <iostream>


namespace ast {
    class object;

    template <class Type>
    class list;

    class symbol_definition;
    class symbol_key;
    class key_attributes;
    class symbol_value;
    class symbol_value_element;
    class list_parameter;
    class option_parameter;
    class star_parameter;
    class token_definition;

    class symbol_value_implementation;
    class symbol_value_initializer;
    class initializer_call;
    
    class mcc_string;
    class mcc_symbol;

    class list_parameter_value;
    class option_parameter_value;
    class star_parameter_value;

    //
    class field_initializer;
    class field_declaration;
    class method_initializer;
    class method_declaration;

    //
    class C_variable_declaration;
    class C_function_declaration;
    class C_function_call;
    class C_declaration_qualifier;
    class C_init_declarator_list;
    class C_init_declarator;
    class C_declarator;
    class C_direct_declarator;

    //
    class symbol_definition_list;
    class symbol_value_list;
    class symbol_value_element_list;
    class symbol_value_initializer_list;
    //class field_initializer_list;
    class field_declaration_list;
    //class method_initializer_list;
    class method_declaration_list;
}



namespace ast {
    using std::string;

    // 
    const int MAX_TOKEN_LEN = 2048;

    // 
    typedef const std::type_info& ast_type;

    // 
    typedef enum action_option {
        ACTOPT_NONE,
        ACTOPT_IS_NONTERMINAL,

    } act_opt;



    // 
    const char *ast_str(ast_type type);


    
    // 
    class mcc_string;

    // 
    class exception {
        std::string _msg;

    public:
        exception(const std::string &msg): _msg(msg) { }

        // 
        const std::string &message() const { return _msg; }
    };

    class NotImplementedException: public std::logic_error {

    public:
        NotImplementedException(): std::logic_error("not implemented") {}
    };



    ///
    /// \brief The describe_args struct
    ///
    struct describe_args {
        FILE *fout;
        describe_args(FILE *fout = NULL): fout(fout) {}
    };
    ///
    /// \brief The glance_args struct
    ///
    struct glance_args {
        FILE *fout;
        act_opt option;
        glance_args(FILE *fout = NULL, act_opt option = ACTOPT_NONE): fout(fout), option(option) {}
    };
    ///
    /// \brief The action_args struct
    ///
    struct action_args {
        FILE *fout;
        act_opt option;
        action_args(FILE *fout = NULL, act_opt option = ACTOPT_NONE): fout(fout), option(option) {}
    };



    ///
    /// \brief The object class
    ///
    class object {

    public:
        // 
        object() { }
        // 
        virtual ~object();

        // 
        ast_type type() const { return typeid(*this); }

        // 
        virtual void describe(describe_args args) {
            throw NotImplementedException();
        }
        // 
        virtual std::string glance(glance_args args) {
            throw NotImplementedException();
        }
        // 
        virtual void action(action_args args) {
            throw NotImplementedException();
        }
        // 
        virtual int compare(const object *p2) const {
            return (this == p2) ? 0 : 1;
        }
        // 
        static int compare(const object *p1, const object *p2) {
            return p1->compare(p2);
        }


        // 
        void compare_header() const;
        // 
        void glance_header() const;
        // 
        void action_header() const;
    };



    ///
    /// \brief The list class
    ///
    template <class Type>
    class list: public object {
        std::vector<Type>                   _vector;

    public:
        // 
        list(): object() {

        }
        // 
        virtual ~list() {
            for (auto it = _vector.begin(); it != _vector.end(); ++it) {
                delete *it;
            }
            fprintf(stderr, "~list(%p) \n", this);
        }
        
        // 
        int count() const { return _vector.size(); }

        // 
        void describe(describe_args args) {
            ;
        }
        // 
        std::string glance(glance_args args) {
            for (auto node = this->first(); node != this->end(); ++node) {
                (*node)->glance(args);
            }
            return std::string("list");
        }
        // 
        void action(action_args args) {
            // 
            for (auto node = this->first(); node != this->end(); ++node) {
                (*node)->action(args);
            }
        }
        // 
        int compare(const list *p2) const {
            if (this != p2) {
                if (this->count() != p2->count()) {
                    return 1;
                }
                else {
                    auto n1 = this->first();
                    auto n2 = p2->first();

                    while (n1 != _vector.end()) {
                        if ((*n1)->compare(*n2)) {
                            return 1;
                        }
                        ++n1;
                        ++n2;
                    }
                }
            }
            return 0;
        }
        // 
        virtual int compare(const object *p2) const { 
            const list *child = dynamic_cast<const list *>(p2);
            if (child) {
                // return compare(dynamic_cast<const list *>(p2));
                return compare(child);
            }
            return 1;
        }
        // 
        static int compare(const list *p1, const list *p2) {
            return p1->compare(p2);
        }

        // 
        void append(Type &o) {
            _vector.push_back(o);
        }
        // 
        void append(const Type &o) {
            _vector.push_back(o);
        }
        // 
        typename std::vector<Type>::iterator first() {
            return _vector.begin(); // _head.next();
        }
        // 
        typename std::vector<Type>::const_iterator first() const {
            return _vector.begin(); // _head.next();
        }
        // 
        typename std::vector<Type>::iterator end() {
            return _vector.end();
        }
        // 
        typename std::vector<Type>::const_iterator end() const {
            return _vector.end();
        }
    };



    ///
    /// \brief The symbol_definition class
    ///
    class symbol_definition: public object {
        class symbol_key                    *_symbol_key; 
        class symbol_value_list             *_symbol_value_list;
        class field_initializer             *_field_initializer;
        class method_initializer            *_method_initializer;

    public:
        // 
        symbol_definition(symbol_key *_symbol_key, symbol_value_list *_symbol_value_list)
            : object() // object(AST_SYMBOL_DEFINITION)
            , _symbol_key(_symbol_key)
            , _symbol_value_list(_symbol_value_list)
            , _field_initializer(nullptr)
            , _method_initializer(nullptr)
        {
        }
        symbol_definition(symbol_key *_symbol_key, field_initializer *_field_initializer, symbol_value_list *_symbol_value_list)
            : object() // object(AST_SYMBOL_DEFINITION)
            , _symbol_key(_symbol_key)
            , _symbol_value_list(_symbol_value_list)
            , _field_initializer(_field_initializer)
            , _method_initializer(nullptr)
        {
        }
        symbol_definition(symbol_key *_symbol_key, method_initializer *_method_initializer, symbol_value_list *_symbol_value_list)
            : object() // object(AST_SYMBOL_DEFINITION)
            , _symbol_key(_symbol_key)
            , _symbol_value_list(_symbol_value_list)
            , _field_initializer(nullptr)
            , _method_initializer(_method_initializer)
        {
        }
        symbol_definition(
                symbol_key *_symbol_key, 
                field_initializer *_field_initializer, 
                method_initializer *_method_initializer, 
                symbol_value_list *_symbol_value_list)
            : object() // object(AST_SYMBOL_DEFINITION)
            , _symbol_key(_symbol_key)
            , _symbol_value_list(_symbol_value_list)
            , _field_initializer(_field_initializer)
            , _method_initializer(_method_initializer)
        {
        }
        // 
        ~symbol_definition();

        // 
        symbol_key *ast_symbol_key() { return _symbol_key; }
        // 
        const symbol_key *ast_symbol_key() const { return _symbol_key; }
        // 
        symbol_value_list *ast_symbol_value_list() { return _symbol_value_list; }
        // 
        const symbol_value_list *ast_symbol_value_list() const { return _symbol_value_list; }

        // 
        void describe(describe_args args);
        // 
        std::string glance(glance_args args);
        // 
        void action(action_args args);
        // 
        int compare(const symbol_definition *p2) const;
        // 
        virtual int compare(const object *p2) const { 
            const symbol_definition *child = (const symbol_definition *)p2;
            if (child) {
                return compare(child);
            }
            return 1;
        }
        // 
        static int compare(const symbol_definition *p1, const symbol_definition *p2) {
            return p1->compare(p2);
        }
    };



    ///
    /// \brief The symbol_key class
    ///
    class symbol_key: public object {
        string                              _symbol_name;
        class key_attributes                *_key_attributes;

    public:
        //
        symbol_key(const std::string &symbol_name, key_attributes *_key_attributes)
            : object() // object(AST_SYMBOL_KEY)
            , _symbol_name(symbol_name)
            , _key_attributes(_key_attributes)
        {
        }
        //
        ~symbol_key();

        //
        string &symbol_name() { return _symbol_name; }
        //
        const string &symbol_name() const { return _symbol_name; }
        //
        key_attributes *ast_key_attributes() { return _key_attributes; }
        //
        const key_attributes *ast_key_attributes() const { return _key_attributes; }

        //
        void describe(describe_args args);
        //
        std::string glance(glance_args args);
        //
        void action(action_args args);
        //
        int compare(const symbol_key *p2) const;
        //
        virtual int compare(const object *p2) const { 
            const symbol_key *child = (const symbol_key *)p2;
            if (child) {
                return compare(child);
            }
            return 1;
        }
        //
        static int compare(const symbol_key *p1, const symbol_key *p2) {
            return p1->compare(p2);
        }
    };



    ///
    /// \brief The key_attributes class
    ///
    class key_attributes: public object {
        string                              _attributes;

    public:
        //
        key_attributes(const std::string &attributes)
            : object() // object(AST_KEY_ATTRIBUTES)
            , _attributes(attributes)
        {
        }
        //
        ~key_attributes();

        //
        string &attributes() { return _attributes; }
        //
        const string &attributes() const { return _attributes; }

        //
        void describe(describe_args args);
        //
        std::string glance(glance_args args);
        //
        void action(action_args args);
        //
        int compare(const key_attributes *p2) const;
        //
        virtual int compare(const object *p2) const { 
            const key_attributes *child = (const key_attributes *)p2;
            if (child) {
                return compare(child);
            }
            return 1;
        }
        //
        static int compare(const key_attributes *p1, const key_attributes *p2) {
            return p1->compare(p2);
        }
    };



    ///
    /// \brief The symbol_value class
    ///
    class symbol_value: public object {
        class symbol_value_element_list     *_symbol_value_element_list;
        class symbol_value_implementation   *_symbol_value_implementation;

    public:
        // 
        symbol_value(symbol_value_element_list *_symbol_value_element_list)
            : object() // object(AST_SYMBOL_VALUE)
            , _symbol_value_element_list(_symbol_value_element_list)
            , _symbol_value_implementation(nullptr)
        {
        }
        symbol_value(
                symbol_value_element_list *_symbol_value_element_list,
                symbol_value_implementation *_symbol_value_implementation
                )
            : object() // object(AST_SYMBOL_VALUE)
            , _symbol_value_element_list(_symbol_value_element_list)
            , _symbol_value_implementation(_symbol_value_implementation)
        {
        }
        //
        ~symbol_value();

        //
        symbol_value_element_list *ast_symbol_value_element_list() { 
            return _symbol_value_element_list;
        }
        //
        const symbol_value_element_list *ast_symbol_value_element_list() const {
            return _symbol_value_element_list;
        }

        //
        void describe(describe_args args);
        //
        std::string glance(glance_args args);
        //
        void action(action_args args);
        //
        int compare(const symbol_value *p2) const;
        //
        virtual int compare(const object *p2) const { 
            const symbol_value *child = dynamic_cast<const symbol_value *>(p2);
            if (child) {
                return compare(child);
            }
            return 1;
        }
        // 
        static int compare(const symbol_value *p1, const symbol_value *p2) {
            return p1->compare(p2);
        }
    };



    ///
    /// \brief The symbol_value_element class
    ///
    class symbol_value_element: public object {

    public:
        // 
        symbol_value_element()
            : object() // object(AST_SYMBOL_VALUE_ELEMENT)
        {
        }
        // 
        ~symbol_value_element();

        // 
        void describe(describe_args args);
        // 
        std::string glance(glance_args args);
        // 
        void action(action_args args);
        // 
        virtual int compare(const symbol_value_element *p2) const = 0;
        // 
        virtual int compare(const object *p2) const { 
            const symbol_value_element *child 
                = dynamic_cast<const symbol_value_element *>(p2);
            if (child) {
                return compare(child);
            }
            return 1;
        }
        // 
        static int compare(const symbol_value_element *p1, const symbol_value_element *p2) {
            return p1->compare(p2);
        }
    };



    ///
    /// \brief The mcc_string class
    ///
    class mcc_string: public symbol_value_element {    
        string                              _value;

    public:
        // 
        mcc_string(const char *value)
            : symbol_value_element() // symbol_value_element(AST_MCC_STRING)
            , _value(value)
        {
        }
        // 
        mcc_string(const std::string &value)
            : symbol_value_element() // symbol_value_element(AST_MCC_STRING)
            , _value(value)
        {
        }
        // 
        ~mcc_string();

        // 
        string &value() { return _value; }
        // 
        const string &value() const { return _value; }

        // 
        void describe(describe_args args);
        // 
        std::string glance(glance_args args);
        // 
        void action(action_args args);

        // 
        int compare(const mcc_string &p2) const {
            return _value.compare(p2.value());
        }
        // 
        virtual int compare(const object *p2) const { 
            const mcc_string *child = dynamic_cast<const mcc_string *>(p2);
            if (child) {
                return compare(*child);
            }
            return 1;
        }
        // 
        static int compare(const mcc_string *p1, const mcc_string *p2) {
            return p1->compare(*p2);
        }
        // 
        virtual int compare(const symbol_value_element *p2) const {
            const mcc_string *child = dynamic_cast<const mcc_string *>(p2);
            if (child) {
                return compare(*child);
            }
            return 1;
        }

        // 
        int compare(const std::string &value) const {
            return _value == value;
        }
        // 
        int compare(const char *value) const {
            return _value == value;
        }

        // 
        bool operator ==(const mcc_string &value) const {
            return _value == value.value();
        }
        // 
        bool operator ==(const std::string &value) const {
            return _value == value;
        }
        // 
        bool operator ==(const char *value) const {
            return _value == value;
        }

        // 
        bool operator !=(const mcc_string &value) const {
            return _value != value.value();
        }
        // 
        bool operator !=(const std::string &value) const {
            return _value != value;
        }
        // 
        bool operator !=(const char *value) const {
            return _value != value;
        }
    };



    ///
    /// \brief The mcc_symbol class
    ///
    class mcc_symbol: public symbol_value_element {    
        string                              _value;

    public:
        // 
        mcc_symbol(const char *value)
            : symbol_value_element() // symbol_value_element(AST_MCC_SYMBOL)
            , _value(value)
        {
        }
        // 
        mcc_symbol(const std::string &value) 
            : symbol_value_element() // symbol_value_element(AST_MCC_SYMBOL)
            , _value(value)
        {
            
        }
        // 
        ~mcc_symbol();
        
        // 
        string &value() { return _value; }
        // 
        const string &value() const { return _value; }

        // 
        void describe(describe_args args);
        // 
        std::string glance(glance_args args);
        // 
        void action(action_args args);
        // 
        int compare(const mcc_symbol *p2) const {
            return _value.compare(p2->value());
        }
        // 
        virtual int compare(const object *p2) const { 
            const mcc_symbol *child = dynamic_cast<const mcc_symbol *>(p2);
            if (child) {
                return compare(child);
            }
            return 1;
        }
        // 
        static int compare(const mcc_symbol *p1, const mcc_symbol *p2) {
            return p1->compare(p2);
        }
        // 
        virtual int compare(const symbol_value_element *p2) const {
            const mcc_symbol *child = dynamic_cast<const mcc_symbol *>(p2);
            if (child) {
                return compare(child);
            }
            return 1;
        }
    };



    ///
    /// \brief The list_parameter class
    ///
    class list_parameter: public symbol_value_element {
        class list_parameter_value          *_list_parameter_value;
        class mcc_string                    *_list_parameter_delim;

    public:
        // 
        list_parameter(
                list_parameter_value *_list_parameter_value, 
                const char *list_parameter_delim
                )
            : symbol_value_element() // symbol_value_element(AST_LIST_PARAMETER)
            , _list_parameter_value(_list_parameter_value)
        {
            _list_parameter_delim = new mcc_string(list_parameter_delim);
        }
        // 
        ~list_parameter();

        // 
        list_parameter_value *ast_list_parameter_value() { 
            return _list_parameter_value;
        }
        // 
        const list_parameter_value *ast_list_parameter_value() const {
            return _list_parameter_value;
        }
        // 
        mcc_string *list_parameter_delim() { return _list_parameter_delim; }
        // 
        const mcc_string *list_parameter_delim() const { return _list_parameter_delim; }

        // 
        void describe(describe_args args);
        // 
        std::string glance(glance_args args);
        // 
        void action(action_args args);
        // 
        int compare(const list_parameter *p2) const;
        // 
        virtual int compare(const object *p2) const { 
            const list_parameter *child = dynamic_cast<const list_parameter *>(p2);
            if (child) {
                return compare(child);
            }
            return 1;
        }
        // 
        static int compare(const list_parameter *p1, const list_parameter *p2) {
            return p1->compare(p2);
        }
        // 
        virtual int compare(const symbol_value_element *p2) const {
            const list_parameter *child = dynamic_cast<const list_parameter *>(p2);
            if (child) {
                return compare(child);
            }
            return 1;
        }
    };



    ///
    /// \brief The option_parameter class
    ///
    class option_parameter: public symbol_value_element {
        class option_parameter_value        *_option_parameter_value;

    public:
        // 
        option_parameter(option_parameter_value *_option_parameter_value)
            : symbol_value_element() // symbol_value_element(AST_OPTION_PARAMETER)
            , _option_parameter_value(_option_parameter_value)
        {
        }
        // 
        ~option_parameter();
        
        // 
        option_parameter_value *ast_option_parameter_value() {
            return _option_parameter_value;
        }
        // 
        const option_parameter_value *ast_option_parameter_value() const {
            return _option_parameter_value;
        }

        // 
        void describe(describe_args args);
        // 
        std::string glance(glance_args args);
        // 
        void action(action_args args);
        // 
        int compare(const option_parameter *p2) const;
        // 
        virtual int compare(const object *p2) const { 
            const option_parameter *child = dynamic_cast<const option_parameter *>(p2);
            if (child) {
                return compare(child);
            }
            return 1;
        }
        // 
        static int compare(const option_parameter *p1, const option_parameter *p2) {
            return p1->compare(p2);
        }
        // 
        virtual int compare(const symbol_value_element *p2) const {
            const option_parameter *child = dynamic_cast<const option_parameter *>(p2);
            if (child) {
                return compare(child);
            }
            return 1;
        }
    };



    ///
    /// \brief The star_parameter class
    ///
    class star_parameter: public symbol_value_element {
        class star_parameter_value          *_star_parameter_value;

    public:
        // 
        star_parameter(star_parameter_value *_star_parameter_value)
            : symbol_value_element() // symbol_value_element(AST_STAR_PARAMETER)
            , _star_parameter_value(_star_parameter_value)
        {
        }
        // 
        ~star_parameter();

        // 
        star_parameter_value *ast_star_parameter_value() {
            return _star_parameter_value;
        }
        // 
        const star_parameter_value *ast_star_parameter_value() const {
            return _star_parameter_value;
        }

        // 
        void describe(describe_args args);
        // 
        std::string glance(glance_args args);
        // 
        void action(action_args args);
        // 
        int compare(const star_parameter *p2) const;
        // 
        virtual int compare(const object *p2) const { 
            const star_parameter *child = dynamic_cast<const star_parameter *>(p2);
            if (child) {
                return compare(child);
            }
            return 1;
        }
        // 
        static int compare(const star_parameter *p1, const star_parameter *p2) {
            return p1->compare(p2);
        }
        // 
        virtual int compare(const symbol_value_element *p2) const {
            const star_parameter *child = dynamic_cast<const star_parameter *>(p2);
            if (child) {
                return compare(child);
            }
            return 1;
        }
    };



    ///
    /// \brief The list_parameter_value class
    ///
    class list_parameter_value: public object {
        class symbol_value_list             *_symbol_value_list;

    public:
        // 
        list_parameter_value(symbol_value_list *_symbol_value_list)
            : object() // object(AST_LIST_PARAMETER_VALUE)
            , _symbol_value_list(_symbol_value_list)
        {
        }
        // 
        ~list_parameter_value();

        // 
        symbol_value_list *ast_symbol_value_list() {
            return _symbol_value_list;
        }
        // 
        const symbol_value_list *ast_symbol_value_list() const {
            return _symbol_value_list;
        }

        // 
        void describe(describe_args args);
        // 
        std::string glance(glance_args args);
        // 
        void action(action_args args);
        // 
        int compare(const list_parameter_value *p2) const;
        // 
        virtual int compare(const object *p2) const { 
            const list_parameter_value *child 
                = dynamic_cast<const list_parameter_value *>(p2);
            if (child) {
                return compare(child);
            }
            return 1;
        }
        // 
        static int compare(
                const list_parameter_value *p1, 
                const list_parameter_value *p2) 
        {
            return p1->compare(p2);
        }
    };



    ///
    /// \brief The option_parameter_value class
    ///
    class option_parameter_value: public object {
        class symbol_value_list             *_symbol_value_list;

    public:
        // 
        option_parameter_value(symbol_value_list *_symbol_value_list)
            : object() // object(AST_OPTION_PARAMETER_VALUE)
            , _symbol_value_list(_symbol_value_list)
        {
        }
        // 
        ~option_parameter_value();

        // 
        symbol_value_list *ast_symbol_value_list() {
            return _symbol_value_list;
        }
        // 
        const symbol_value_list *ast_symbol_value_list() const {
            return _symbol_value_list;
        }

        // 
        void describe(describe_args args);
        // 
        std::string glance(glance_args args);
        // 
        void action(action_args args);
        // 
        int compare(const option_parameter_value *p2) const;
        // 
        virtual int compare(const object *p2) const { 
            const option_parameter_value *child 
                = dynamic_cast<const option_parameter_value *>(p2);
            if (child) {
                return compare(child);
            }
            return 1;
        }
        // 
        static int compare(
                const option_parameter_value *p1, 
                const option_parameter_value *p2)
        {
            return p1->compare(p2);
        }
    };



    ///
    /// \brief The star_parameter_value class
    ///
    class star_parameter_value: public object {
        class list_parameter                *_list_parameter;

    public:
        // 
        star_parameter_value(class list_parameter *_list_parameter)
            : object() // object(AST_STAR_PARAMETER_VALUE)
            , _list_parameter(_list_parameter)
        {
        }
        // 
        ~star_parameter_value();

        // 
        list_parameter *ast_list_parameter() { return _list_parameter; }
        // 
        const list_parameter *ast_list_parameter() const { return _list_parameter; }

        // 
        void describe(describe_args args);
        // 
        std::string glance(glance_args args);
        // 
        void action(action_args args);
        // 
        int compare(const star_parameter_value *p2) const;
        // 
        virtual int compare(const object *p2) const { 
            const star_parameter_value *child = dynamic_cast<const star_parameter_value *>(p2);
            if (child) {
                return compare(child);
            }
            return 1;
        }
        // 
        static int compare(
                const star_parameter_value *p1, 
                const star_parameter_value *p2) 
        {
            return p1->compare(p2);
        }
    };



    ///
    /// \brief The token_definition class
    ///
    class token_definition: public symbol_value_element {
        string                              _token_key;
        string                              _token_value;

    public:
        // 
        token_definition(const char *token_key, const char *token_value)
            : symbol_value_element() // symbol_value_element(AST_TOKEN_DEFINITION),
            , _token_key(token_key)
            , _token_value(token_value)
        {
        }
        // 
        ~token_definition();

        // 
        string &token_key() { return _token_key; }
        // 
        const string &token_key() const { return _token_key; }
        // 
        string &token_value() { return _token_value; }
        // 
        const string &token_value() const { return _token_value; }

        // 
        void describe(describe_args args);
        // 
        std::string glance(glance_args args);
        // 
        void action(action_args args);
        // 
        int compare(const token_definition *p2) const;
        // 
        virtual int compare(const object *p2) const { 
            const token_definition *child = dynamic_cast<const token_definition *>(p2);
            if (child) {
                return compare(child);
            }
            return 1;
        }
        // 
        static int compare(const token_definition *p1, const token_definition *p2) {
            return p1->compare(p2);
        }
        // 
        virtual int compare(const symbol_value_element *p2) const {
            const token_definition *child = dynamic_cast<const token_definition *>(p2);
            if (child) {
                return compare(child);
            }
            return 1;
        }
    };



    ///
    /// \brief The symbol_value_implementation class
    ///
    class symbol_value_implementation: public object {
        class symbol_value_initializer_list *_symbol_value_initializer_list;

    public:
        symbol_value_implementation()
            : _symbol_value_initializer_list(nullptr)
        {
        }
        ~symbol_value_implementation() {}

        //
        void init_with_symbol_value_initializer_list(symbol_value_initializer_list *_symbol_value_initializer_list) {
            this->_symbol_value_initializer_list = _symbol_value_initializer_list;
        }
    };
    ///
    /// \brief The symbol_value_initializer class
    ///
    class symbol_value_initializer: public object {
        class initializer_call *_initializer_call;

    public:
        symbol_value_initializer()
            : _initializer_call(nullptr)
        {
        }
        ~symbol_value_initializer() {}

        //
        void init_with_initializer_call(initializer_call *_initializer_call) {
            this->_initializer_call = _initializer_call;
        }
    };
    ///
    /// \brief The initializer_call class
    ///
    class initializer_call: public object {
        class C_function_call *_C_function_call;

    public:
        initializer_call()
            : _C_function_call(nullptr)
        {
        }
        ~initializer_call() {}

        //
        void init_with_C_function_call(C_function_call *_C_function_call) {
            this->_C_function_call = _C_function_call;
        }
    };



    ///
    /// \brief The field_initializer class
    ///
    class field_initializer: public object {
        class field_declaration_list *_field_declaration_list;

    public:
        field_initializer()
            : _field_declaration_list(nullptr)
        {}
        ~field_initializer() {}

        //
        void init_with_field_declaration_list(field_declaration_list *_field_declaration_list) {
            this->_field_declaration_list = _field_declaration_list;
        }
    };
    ///
    /// \brief The field_declaration class
    ///
    class field_declaration: public object {
        class C_variable_declaration *_C_variable_declaration;
    
    public:
        field_declaration()
            : _C_variable_declaration(nullptr)
        {}
        ~field_declaration() {}

        //
        void init_with_C_variable_declaration(C_variable_declaration *_C_variable_declaration) {
            this->_C_variable_declaration = _C_variable_declaration;
        }
    };



    ///
    /// \brief The method_initializer class
    ///
    class method_initializer: public object {
        class method_declaration_list *_method_declaration_list;

    public:
        method_initializer()
            : _method_declaration_list(nullptr)
        {}
        ~method_initializer() {}

        //
        void init_with_method_declaration_list(method_declaration_list *_method_declaration_list) {
            this->_method_declaration_list = _method_declaration_list;
        }
    };
    ///
    /// \brief The method_declaration class
    ///
    class method_declaration: public object {
        class C_function_declaration *_C_function_declaration;

    public:
        method_declaration()
            : _C_function_declaration(nullptr)
        {}
        ~method_declaration() {}

        //
        void init_with_C_function_declaration(C_function_declaration *_C_function_declaration) {
            this->_C_function_declaration = _C_function_declaration;
        }
    };



    ///
    /// \brief The C_variable_declaration class
    ///
    class C_variable_declaration: public object {
        class C_declaration_qualifier *_C_declaration_qualifier;
        class C_init_declarator_list *_C_init_declarator_list;

    public:
        C_variable_declaration()
            : _C_declaration_qualifier(nullptr)
            , _C_init_declarator_list(nullptr)
        {}
        ~C_variable_declaration() {}

        //
        void init_with_1(
                C_declaration_qualifier *_C_declaration_qualifier,
                C_init_declarator_list *_C_init_declarator_list) {
            this->_C_declaration_qualifier = _C_declaration_qualifier;
            this->_C_init_declarator_list = _C_init_declarator_list;
        }
    };
    ///
    /// \brief The C_function_declaration class
    ///
    class C_function_declaration: public object {
        class C_declaration_qualifier *_C_declaration_qualifier;
        class C_direct_declarator *_C_direct_declarator;

    public:
        C_function_declaration()
            : _C_declaration_qualifier(nullptr)
            , _C_direct_declarator(nullptr)
        {}
        ~C_function_declaration() {}

        //
        void init_with_1(
                C_declaration_qualifier *_C_declaration_qualifier,
                C_direct_declarator *_C_direct_declarator
                ) {
            this->_C_declaration_qualifier = _C_declaration_qualifier;
            this->_C_direct_declarator = _C_direct_declarator;
        }
    };
    ///
    /// \brief The C_function_call class
    ///
    class C_function_call: public object {
        class C_direct_declarator *_C_direct_declarator;

    public:
        C_function_call()
            : _C_direct_declarator(nullptr)
        {}
        ~C_function_call() {}

        //
        void init_with_1(C_direct_declarator *_C_direct_declarator) {
            this->_C_direct_declarator = _C_direct_declarator;
        }
    };
    ///
    /// \brief The C_declaration_qualifier class
    ///
    class C_declaration_qualifier: public object {

    public:
        C_declaration_qualifier() {}
        ~C_declaration_qualifier() {}

        //
        void init_with_C_MCC_TYPE(const std::string &value) {
        }
        void init_with_MCC_SYMBOL(const std::string &value) {
        }
    };
    ///
    /// \brief The C_init_declarator class
    ///
    class C_init_declarator: public object {
        class C_declarator *_C_declarator;

    public:
        C_init_declarator()
            : _C_declarator(nullptr)
        {}
        ~C_init_declarator() {}

        //
        void init_with_C_declarator(C_declarator *_C_declarator) {
            this->_C_declarator = _C_declarator;
        }
    };
    ///
    /// \brief The C_declarator class
    ///
    class C_declarator: public object {
        int                       _pointer;
        class C_declarator        *_C_declarator;
        class C_direct_declarator *_C_direct_declarator;

    public:
        C_declarator()
            : _pointer(-1)
            , _C_declarator(nullptr)
            , _C_direct_declarator(nullptr)
        {}
        ~C_declarator() {}

        //
        void init_with_ASTERISK_C_declarator(C_declarator *_C_declarator) {
            this->_pointer = 1;
            this->_C_declarator = _C_declarator;
        }
        void init_with_C_direct_declarator(C_direct_declarator *_C_direct_declarator) {
            this->_pointer = 0;
            this->_C_direct_declarator = _C_direct_declarator;
        }
    };
    ///
    /// \brief The C_direct_declarator class
    ///
    class C_direct_declarator: public object {
        class C_declarator *_C_declarator;

    public:
        C_direct_declarator() {}
        ~C_direct_declarator() {}

        //
        void init_with_MCC_SYMBOL(const std::string &value) {
        }
        void init_with_C_IDENTIFIER(const std::string &value) {
        }
        void init_with_C_declarator(C_declarator *_C_declarator) {
            this->_C_declarator = _C_declarator;
        }
    };



    ///
    /// \brief The symbol_definition_list class
    ///
    class symbol_definition_list: public list<symbol_definition *> {
        std::string _symbol_name;

    public:
        // 
        symbol_definition_list(): list<symbol_definition *>() { }
        // 
        ~symbol_definition_list() { }

        // 
        std::string &symbol_name() { return _symbol_name; }
        // 
        const std::string &symbol_name() const { return _symbol_name; }
        // 
        void set_symbol_name(const std::string &value) { _symbol_name = value; }

        // 
        void describe(describe_args args);
        // 
        std::string glance(glance_args args);
        // 
        void action(action_args args);
        // 
        int compare(const symbol_definition_list *p2) const;
        // 
        virtual int compare(const object *p2) const { 
            const symbol_definition_list *child = dynamic_cast<const symbol_definition_list *>(p2);
            if (child) {
                return compare(child);
            }
            return 1;
        }
        // 
        static int compare(const symbol_definition_list *p1, const symbol_definition_list *p2) {
            return p1->compare(p2);
        }
    };
    ///
    /// \brief The symbol_value_list class
    ///
    class symbol_value_list: public list<symbol_value *> {
        std::string _symbol_name;

    public:
        // 
        symbol_value_list(): list<symbol_value *>() { }
        // 
        ~symbol_value_list() { }

        // 
        std::string &symbol_name() { return _symbol_name; }
        // 
        const std::string &symbol_name() const { return _symbol_name; }
        // 
        void set_symbol_name(const std::string &value) { _symbol_name = value; }

        // 
        void describe(describe_args args);
        // 
        std::string glance(glance_args args);
        // 
        void action(action_args args);
        // 
        int compare(const symbol_value_list *p2) const;
        // 
        virtual int compare(const object *p2) const { 
            const symbol_value_list *child = dynamic_cast<const symbol_value_list *>(p2);
            if (child) {
                return compare(child);
            }
            return 1;
        }
        // 
        static int compare(const symbol_value_list *p1, const symbol_value_list *p2) {
            return p1->compare(p2);
        }
    };
    ///
    /// \brief The symbol_value_element_list class
    ///
    class symbol_value_element_list: public list<symbol_value_element *> {

    public:
        // 
        symbol_value_element_list(): list<symbol_value_element *>() { }
        // 
        ~symbol_value_element_list() { }

        // 
        void describe(describe_args args);
        // 
        std::string glance(glance_args args);
        // 
        void action(action_args args);

        // 
        int compare(const symbol_value_element_list *p2) const;
        // 
        virtual int compare(const object *p2) const { 
            const symbol_value_element_list *child = dynamic_cast<const symbol_value_element_list *>(p2);
            if (child) {
                return compare(child);
            }
            return 1;
        }
        // 
        static int compare(const symbol_value_element_list *p1, const symbol_value_element_list *p2) {
            return p1->compare(p2);
        }
    };
    ///
    /// \brief The symbol_value_initializer_list class
    ///
    class symbol_value_initializer_list: public list<symbol_value_initializer *> {

    public:
        // 
        symbol_value_initializer_list(): list<symbol_value_initializer *>() { }
        // 
        ~symbol_value_initializer_list() { }

        // 
        void describe(describe_args args) { throw NotImplementedException(); }
        // 
        std::string glance(glance_args args) { throw NotImplementedException(); }
        // 
        void action(action_args args) { throw NotImplementedException(); }

        // 
        int compare(const symbol_value_initializer_list *p2) const;
        // 
        virtual int compare(const object *p2) const { 
            const symbol_value_initializer_list *child = dynamic_cast<const symbol_value_initializer_list *>(p2);
            if (child) {
                return compare(child);
            }
            return 1;
        }
        // 
        static int compare(const symbol_value_initializer_list *p1, const symbol_value_initializer_list *p2) {
            return p1->compare(p2);
        }
    };
    ///
    /// \brief The field_declaration_list class
    ///
    class field_declaration_list: public list<field_declaration *> {

    public:
        //
        field_declaration_list(): list<field_declaration *>() { }
        //
        ~field_declaration_list() { }

        //
        void describe(describe_args args) { throw NotImplementedException(); }
        //
        std::string glance(glance_args args) { throw NotImplementedException(); }
        //
        void action(action_args args) { throw NotImplementedException(); }

        //
        int compare(const field_declaration_list *p2) const;
        //
        virtual int compare(const object *p2) const { 
            const field_declaration_list *child = dynamic_cast<const field_declaration_list *>(p2);
            if (child) {
                return compare(child);
            }
            return 1;
        }
        //
        static int compare(const field_declaration_list *p1, const field_declaration_list *p2) {
            return p1->compare(p2);
        }
    };
    ///
    /// \brief The method_declaration_list class
    ///
    class method_declaration_list: public list<method_declaration *> {

    public:
        //
        method_declaration_list(): list<method_declaration *>() { }
        //
        ~method_declaration_list() { }

        //
        void describe(describe_args args) { throw NotImplementedException(); }
        //
        std::string glance(glance_args args) { throw NotImplementedException(); }
        //
        void action(action_args args) { throw NotImplementedException(); }

        //
        int compare(const method_declaration_list *p2) const;
        //
        virtual int compare(const object *p2) const {
            const method_declaration_list *child = dynamic_cast<const method_declaration_list *>(p2);
            if (child) {
                return compare(child);
            }
            return 1;
        }
        //
        static int compare(const method_declaration_list *p1, const method_declaration_list *p2) {
            return p1->compare(p2);
        }
    };
    ///
    /// \brief The C_init_declarator_list class
    ///
    class C_init_declarator_list: public list<C_init_declarator *> {

    public:
        //
        C_init_declarator_list(): list<C_init_declarator *>() { }
        //
        ~C_init_declarator_list() { }

        //
        void describe(describe_args args) { throw NotImplementedException(); }
        //
        std::string glance(glance_args args) { throw NotImplementedException(); }
        //
        void action(action_args args) { throw NotImplementedException(); }

        //
        int compare(const C_init_declarator_list *p2) const;
        //
        virtual int compare(const object *p2) const {
            const C_init_declarator_list *child = dynamic_cast<const C_init_declarator_list *>(p2);
            if (child) {
                return compare(child);
            }
            return 1;
        }
        //
        static int compare(const C_init_declarator_list *p1, const C_init_declarator_list *p2) {
            return p1->compare(p2);
        }
    };



    //
    extern std::vector< std::string >                                      symbols;
    extern std::vector< std::pair<std::string, std::string> >              string_tokens;
    extern std::vector< std::string >                                      tokens;
    extern std::vector< std::pair<std::string, ast::list_parameter *> >    ast_table_LIST;
    extern std::vector< std::pair<std::string, ast::option_parameter *> >  ast_table_OPT;
    extern std::vector< std::pair<std::string, ast::star_parameter *> >    ast_table_STAR;
}



//==============================================================================
extern FILE *out_jj;
extern FILE *out_java;

//------------------------------------------------------------------------------
extern FILE *out_lyc;
extern FILE *out_lyc_y;
extern FILE *out_lyc_y_union;
extern FILE *out_lyc_y_token;
extern FILE *out_lyc_y_type;
extern FILE *out_lyc_y_list;
extern FILE *out_lyc_y_option;
extern FILE *out_lyc_y_star;
extern FILE *out_lyc_l;
extern FILE *out_lyc_l_tokendef;
extern FILE *out_lyc_ast_h;
extern FILE *out_lyc_ast_h_typedef;
extern FILE *out_lyc_ast_h_declaration;
extern FILE *out_lyc_ast_c;
extern FILE *out_lyc_ast_c_templates;

//------------------------------------------------------------------------------
extern FILE *out_lycpp;



//==============================================================================
// 
extern int longest_symbol_length;
// 
void symbols_init();
// 
int symbols_index(const char *symbol_name);
// 
int symbols_add(const char *symbol_name);

// 
void string_tokens_init();
// 
int string_tokens_key_index(const char *key);
// 
int string_tokens_value_index(const char *value);
// 
int string_tokens_add(const char *key, const char *value);
// 
int string_tokens_add(const std::string &key, const std::string &value);

// 
void tokens_init();
// 
int tokens_index(const char *symbol_name);
// 
void tokens_add(const char *token_name);

// 
void ast_table_LIST_init();
// 
int ast_table_LIST_index(ast::list_parameter *elem);
// 
int ast_table_LIST_index(const std::vector<ast::symbol_value_element *> &obj_list);
// 
void ast_table_LIST_add(const char *key, ast::list_parameter *elem);
// 
void ast_table_OPT_init();
// 
int ast_table_OPT_index(ast::option_parameter *elem);
// 
void ast_table_OPT_add(const char *key, ast::option_parameter *elem);
// 
void ast_table_STAR_init();
// 
int ast_table_STAR_index(ast::star_parameter *elem);
// 
void ast_table_STAR_add(const char *key, ast::star_parameter *elem);










#endif
