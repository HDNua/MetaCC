#ifndef __HANDY_AST_JAVACC_HPP__
#define __HANDY_AST_JAVACC_HPP__

#include <string>
#include <vector>

#include <cstdio>
#include <cstring>



namespace ast {
    namespace javacc {
        using std::string;

        // 
        const int MAX_TOKEN_LEN = 2048;

        // 
        typedef enum ast_type {
            AST_UNTYPED,                    // 0
            AST_LIST,                       // 1
            AST_SYMBOL_DEFINITION,          // 2
            AST_SYMBOL_KEY,                 // 3
            AST_KEY_ATTRIBUTES,             // 4
            AST_SYMBOL_VALUE,               // 5
            AST_SYMBOL_VALUE_ELEMENT,       // 6
            AST_LIST_PARAMETER,             // 7
            AST_OPTION_PARAMETER,           // 8
            AST_STAR_PARAMETER,             // 9
            AST_TOKEN_DEFINITION,           // 10

            // 
            AST_LIST_NODE,                  // 11

            // 
            AST_MCC_STRING,                 // 12
            AST_MCC_SYMBOL,                 // 13
            AST_CSTRING,                    // 14
            AST_NULL,                       // 15
            AST_TOKEN,                      // 16

            // 
            AST_LIST_PARAMETER_VALUE,
            AST_OPTION_PARAMETER_VALUE,
            AST_STAR_PARAMETER_VALUE,

        } ast_type;

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
        class object {
            ast_type _type;

            public:
            // 
            object(ast_type type): _type(type) { }
            // 
            virtual ~object();

            // 
            ast_type type() const { return _type; }

            // 
            void describe(FILE *out) {
                ;
            }
            // 
            virtual std::string glance(FILE *out, act_opt option) = 0;
            // 
            virtual void action(FILE *out, act_opt option = ACTOPT_NONE) = 0;
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
        class list_node: public object {
            ast_type                            _elem_type;
            object                              *_elem;
            list_node                           *_next;

            public:
            list_node(object *elem, ast_type elem_type)
                : object(AST_LIST_NODE), _elem_type(elem_type), _elem(elem), _next(nullptr)
            {
            }
            ~list_node();

            ast_type elem_type() const { return _elem_type; }
            object *ast_elem() { return _elem; }
            const object *ast_elem() const { return _elem; }
            void set_ast_elem(object *value) { _elem = value; }
            list_node *next() { return _next; }
            const list_node *next() const { return _next; }
            void set_next(list_node *value) { _next = value; }

            void describe(FILE *out);
            std::string glance(FILE *out, act_opt option);
            void action(FILE *out, act_opt option);
            int compare(const list_node *p2) const;
            virtual int compare(const object *p2) const {
                return compare(dynamic_cast<const list_node *>(p2));
            }
            static int compare(const list_node *p1, const list_node *p2) {
                return p1->compare(p2);
            }
        };



        // 
        class list: public object {
            ast_type                            _elem_type;
            class list_node                     _head;
            class list_node                     *_tail;
            int                         	    _count;

            public:
            list(ast_type _elem_type)
                : object(AST_LIST), _elem_type(_elem_type), _head(nullptr, _elem_type), _count(0)
            {
                _tail = &_head;
            }
            ~list();

            ast_type elem_type() const { return _elem_type; }
            int count() const { return _count; }

            void describe(FILE *out);
            std::string glance(FILE *out, act_opt option);
            void action(FILE *out, act_opt option);
            int compare(const list *p2) const;
            virtual int compare(const object *p2) const { 
                return compare(dynamic_cast<const list *>(p2));
            }
            static int compare(const list *p1, const list *p2) {
                return p1->compare(p2);
            }

            void append(object *o, ast_type elem_type) {
                list_node *node = new list_node(o, elem_type);
                _tail->set_next(node);
                _tail = node;
                _count += 1;
            }
            list_node *first() { return _head.next(); }
            const list_node *first() const { return _head.next(); }
        };



        // 
        class symbol_definition: public object {
            class symbol_key                    *_symbol_key; 
            class list                          *_symbol_value_list;

            public:
            symbol_definition(symbol_key *_symbol_key, list *_symbol_value_list)
                : object(AST_SYMBOL_DEFINITION), _symbol_key(_symbol_key), _symbol_value_list(_symbol_value_list)
            {
            }
            ~symbol_definition();

            symbol_key *ast_symbol_key() { return _symbol_key; }
            const symbol_key *ast_symbol_key() const { return _symbol_key; }
            list *ast_symbol_value_list() { return _symbol_value_list; }
            const list *ast_symbol_value_list() const { return _symbol_value_list; }

            void describe(FILE *out);
            std::string glance(FILE *out, act_opt option);
            void action(FILE *out, act_opt option);
            int compare(const symbol_definition *p2) const;
            virtual int compare(const object *p2) const { 
                const symbol_definition *child = (const symbol_definition *)p2;
                return compare(child);
            }
            static int compare(const symbol_definition *p1, const symbol_definition *p2) {
                return p1->compare(p2);
            }
        };



        // 
        class symbol_key: public object {
            string                              _symbol_name;
            class key_attributes                *_key_attributes;

            public:
            symbol_key(const std::string &symbol_name, key_attributes *_key_attributes)
                : object(AST_SYMBOL_KEY), _symbol_name(symbol_name), _key_attributes(_key_attributes)
            {
            }
            ~symbol_key();

            string &symbol_name() { return _symbol_name; }
            const string &symbol_name() const { return _symbol_name; }
            key_attributes *ast_key_attributes() { return _key_attributes; }
            const key_attributes *ast_key_attributes() const { return _key_attributes; }

            void describe(FILE *out);
            std::string glance(FILE *out, act_opt option);
            void action(FILE *out, act_opt option);
            int compare(const symbol_key *p2) const;
            virtual int compare(const object *p2) const { 
                // return compare(dynamic_cast<const symbol_key *>(p2));
                const symbol_key *child = (const symbol_key *)p2;
                return compare(child);
            }
            static int compare(const symbol_key *p1, const symbol_key *p2) {
                return p1->compare(p2);
            }
        };



        // 
        class key_attributes: public object {
            string                              _attributes;

            public:
            key_attributes(const std::string &attributes)
                : object(AST_KEY_ATTRIBUTES), _attributes(attributes)
            {
            }
            ~key_attributes();

            string &attributes() { return _attributes; }
            const string &attributes() const { return _attributes; }

            void describe(FILE *out);
            std::string glance(FILE *out, act_opt option);
            void action(FILE *out, act_opt option);
            int compare(const key_attributes *p2) const;
            virtual int compare(const object *p2) const { 
                // return compare(dynamic_cast<const key_attributes *>(p2));
                const key_attributes *child = (const key_attributes *)p2;
                return compare(child);
            }
            static int compare(const key_attributes *p1, const key_attributes *p2) {
                return p1->compare(p2);
            }
        };



        // 
        class symbol_value: public object {
            class list                          *_symbol_value_element_list;

            public:
            symbol_value(list *_symbol_value_element_list)
                : object(AST_SYMBOL_VALUE), _symbol_value_element_list(_symbol_value_element_list)
            {
            }
            ~symbol_value();

            list *ast_symbol_value_element_list() { return _symbol_value_element_list; }
            const list *ast_symbol_value_element_list() const { return _symbol_value_element_list; }

            void describe(FILE *out);
            std::string glance(FILE *out, act_opt option);
            void action(FILE *out, act_opt option);
            int compare(const symbol_value *p2) const;
            virtual int compare(const object *p2) const { 
                // return compare(dynamic_cast<const symbol_value *>(p2));
                const symbol_value *child = dynamic_cast<const symbol_value *>(p2);
                return compare(child);
            }
            static int compare(const symbol_value *p1, const symbol_value *p2) {
                return p1->compare(p2);
            }
        };



        // 
        class symbol_value_element: public object {
            ast_type                            _elem_type;

            public:
            symbol_value_element(ast_type elem_type)
                : object(AST_SYMBOL_VALUE_ELEMENT), _elem_type(elem_type)
            {
            }
            ~symbol_value_element();

            ast_type elem_type() const { return _elem_type; }

            void describe(FILE *out);
            std::string glance(FILE *out, act_opt option);
            void action(FILE *out, act_opt option);
            virtual int compare(const symbol_value_element *p2) const = 0;
            virtual int compare(const object *p2) const { 
                // return compare(dynamic_cast<const symbol_value_element *>(p2));
                // const symbol_value_element *child = (const symbol_value_element *)p2;
                const symbol_value_element *child = dynamic_cast<const symbol_value_element *>(p2);
                return compare(child);
            }
            static int compare(const symbol_value_element *p1, const symbol_value_element *p2) {
                return p1->compare(p2);
            }
        };



        // 
        class mcc_string: public symbol_value_element {    
            string                              _value;

            public:
            // 
            mcc_string(const char *value)
                : symbol_value_element(AST_MCC_STRING), _value(value)
            {
            }
            // 
            mcc_string(const std::string &value)
                : symbol_value_element(AST_MCC_STRING), _value(value)
            {
            }
            // 
            ~mcc_string();


            // 
            string &value() { return _value; }
            // 
            const string &value() const { return _value; }


            // 
            void describe(FILE *out);
            // 
            std::string glance(FILE *out, act_opt option);
            // 
            void action(FILE *out, act_opt option);


            // 
            int compare(const mcc_string &p2) const {
                return _value.compare(p2.value());
            }
            // 
            virtual int compare(const object *p2) const { 
                // return compare(dynamic_cast<const mcc_string *>(p2));
                // const mcc_string *child = (const mcc_string *)p2;
                const mcc_string *child = dynamic_cast<const mcc_string *>(p2);
                return compare(*child);
            }
            // 
            static int compare(const mcc_string *p1, const mcc_string *p2) {
                return p1->compare(*p2);
            }
            // 
            virtual int compare(const symbol_value_element *p2) const {
                // return compare(dynamic_cast<const mcc_string *>(p2));
                // const mcc_string *child = (const mcc_string *)p2;
                const mcc_string *child = dynamic_cast<const mcc_string *>(p2);
                return compare(*child);
            }


            // 
            int compare(const std::string &value) const {
                // fprintf(stderr, "cmp [%s] vs [%s] \n", _value.c_str(), value.c_str());
                return _value == value;
            }
            // 
            int compare(const char *value) const {
                // fprintf(stderr, "cmp [%s] vs [%s] \n", _value.c_str(), value);
                return _value == value;
            }

            // 
            bool operator ==(const mcc_string &value) const {
                // fprintf(stderr, "cmp [%s] vs [%s] \n", _value.c_str(), value.value().c_str());
                return _value == value.value();
            }
            // 
            bool operator ==(const std::string &value) const {
                // fprintf(stderr, "cmp [%s] vs [%s] \n", _value.c_str(), value.c_str());
                return _value == value;
            }
            // 
            bool operator ==(const char *value) const {
                // fprintf(stderr, "cmp [%s] vs [%s] \n", _value.c_str(), value);
                return _value == value;
            }

            // 
            bool operator !=(const mcc_string &value) const {
                // fprintf(stderr, "!cmp [%s] vs [%s] \n", _value.c_str(), value.value().c_str());
                return _value != value.value();
            }
            // 
            bool operator !=(const std::string &value) const {
                // fprintf(stderr, "!cmp [%s] vs [%s] \n", _value.c_str(), value.c_str());
                return _value != value;
            }
            // 
            bool operator !=(const char *value) const {
                // fprintf(stderr, "!cmp [%s] vs [%s] \n", _value.c_str(), value);
                return _value != value;
            }
        };



        // 
        class mcc_symbol: public symbol_value_element {    
            string                              _value;

            public:
            mcc_symbol(const char *value)
                : symbol_value_element(AST_MCC_SYMBOL), _value(value)
            {
            }
            mcc_symbol(const std::string &value) 
                : symbol_value_element(AST_MCC_SYMBOL), _value(value)
            {

            }
            ~mcc_symbol();

            string &value() { return _value; }
            const string &value() const { return _value; }

            void describe(FILE *out);
            std::string glance(FILE *out, act_opt option);
            void action(FILE *out, act_opt option);
            int compare(const mcc_symbol *p2) const {
                return _value.compare(p2->value());
            }
            virtual int compare(const object *p2) const { 
                // return compare(dynamic_cast<const mcc_symbol *>(p2));
                // const mcc_symbol *child = (const mcc_symbol *)p2;
                const mcc_symbol *child = dynamic_cast<const mcc_symbol *>(p2);
                return compare(child);
            }
            static int compare(const mcc_symbol *p1, const mcc_symbol *p2) {
                return p1->compare(p2);
            }
            virtual int compare(const symbol_value_element *p2) const {
                // return compare(dynamic_cast<const mcc_symbol *>(p2));
                // const mcc_symbol *child = (const mcc_symbol *)p2;
                const mcc_symbol *child = dynamic_cast<const mcc_symbol *>(p2);
                return compare(child);
            }

        };



        // 
        class list_parameter: public symbol_value_element {
            class list_parameter_value          *_list_parameter_value;
            class mcc_string                    *_list_parameter_delim;

            public:
            list_parameter(list_parameter_value *_list_parameter_value, const char *list_parameter_delim)
                : symbol_value_element(AST_LIST_PARAMETER),
                _list_parameter_value(_list_parameter_value)
            {
                _list_parameter_delim = new mcc_string(list_parameter_delim);
            }
            ~list_parameter();

            list_parameter_value *ast_list_parameter_value() { return _list_parameter_value; }
            const list_parameter_value *ast_list_parameter_value() const { return _list_parameter_value; }
            mcc_string *list_parameter_delim() { return _list_parameter_delim; }
            const mcc_string *list_parameter_delim() const { return _list_parameter_delim; }

            void describe(FILE *out);
            std::string glance(FILE *out, act_opt option);
            void action(FILE *out, act_opt option);
            int compare(const list_parameter *p2) const;
            virtual int compare(const object *p2) const { 
                // return compare(dynamic_cast<const list_parameter *>(p2));
                // const list_parameter *child = (const list_parameter *)p2;
                const list_parameter *child = dynamic_cast<const list_parameter *>(p2);
                return compare(child);
            }
            static int compare(const list_parameter *p1, const list_parameter *p2) {
                return p1->compare(p2);
            }
            virtual int compare(const symbol_value_element *p2) const {
                // return compare(dynamic_cast<const list_parameter *>(p2));
                // const list_parameter *child = (const list_parameter *)p2;
                const list_parameter *child = dynamic_cast<const list_parameter *>(p2);
                return compare(child);
            }

        };



        // 
        class option_parameter: public symbol_value_element {
            class option_parameter_value        *_option_parameter_value;

            public:
            option_parameter(option_parameter_value *_option_parameter_value)
                : symbol_value_element(AST_OPTION_PARAMETER), _option_parameter_value(_option_parameter_value)
            {
            }
            ~option_parameter();

            option_parameter_value *ast_option_parameter_value() { return _option_parameter_value; }
            const option_parameter_value *ast_option_parameter_value() const { return _option_parameter_value; }

            void describe(FILE *out);
            std::string glance(FILE *out, act_opt option);
            void action(FILE *out, act_opt option);
            int compare(const option_parameter *p2) const;
            virtual int compare(const object *p2) const { 
                // return compare(dynamic_cast<const option_parameter *>(p2));
                // const option_parameter *child = (const option_parameter *)p2;
                const option_parameter *child = dynamic_cast<const option_parameter *>(p2);
                return compare(child);
            }
            static int compare(const option_parameter *p1, const option_parameter *p2) {
                return p1->compare(p2);
            }
            virtual int compare(const symbol_value_element *p2) const {
                // return compare(dynamic_cast<const option_parameter *>(p2));
                // const option_parameter *child = (const option_parameter *)p2;
                const option_parameter *child = dynamic_cast<const option_parameter *>(p2);
                return compare(child);
            }

        };



        // 
        class star_parameter: public symbol_value_element {
            class star_parameter_value          *_star_parameter_value;

            public:
            star_parameter(star_parameter_value *_star_parameter_value)
                : symbol_value_element(AST_STAR_PARAMETER), _star_parameter_value(_star_parameter_value)
            {
            }
            ~star_parameter();

            star_parameter_value *ast_star_parameter_value() { return _star_parameter_value; }
            const star_parameter_value *ast_star_parameter_value() const { return _star_parameter_value; }

            void describe(FILE *out);
            std::string glance(FILE *out, act_opt option);
            void action(FILE *out, act_opt option);
            int compare(const star_parameter *p2) const;
            virtual int compare(const object *p2) const { 
                // return compare(dynamic_cast<const star_parameter *>(p2));
                // const star_parameter *child = (const star_parameter *)p2;
                const star_parameter *child = dynamic_cast<const star_parameter *>(p2);
                return compare(child);
            }
            static int compare(const star_parameter *p1, const star_parameter *p2) {
                return p1->compare(p2);
            }
            virtual int compare(const symbol_value_element *p2) const {
                // return compare(dynamic_cast<const star_parameter *>(p2));
                // const star_parameter *child = (const star_parameter *)p2;
                const star_parameter *child = dynamic_cast<const star_parameter *>(p2);
                return compare(child);
            }

        };



        // 
        class list_parameter_value: public object {
            class list                          *_symbol_value_list;

            public:
            list_parameter_value(list *_symbol_value_list)
                : object(AST_LIST_PARAMETER_VALUE), _symbol_value_list(_symbol_value_list)
            {
            }
            ~list_parameter_value();

            list *ast_symbol_value_list() { return _symbol_value_list; }
            const list *ast_symbol_value_list() const { return _symbol_value_list; }

            void describe(FILE *out);
            std::string glance(FILE *out, act_opt option);
            void action(FILE *out, act_opt option);
            int compare(const list_parameter_value *p2) const;
            virtual int compare(const object *p2) const { 
                // return compare(dynamic_cast<const list_parameter_value *>(p2));
                // const list_parameter_value *child = (const list_parameter_value *)p2;
                const list_parameter_value *child = dynamic_cast<const list_parameter_value *>(p2);
                return compare(child);
            }
            static int compare(const list_parameter_value *p1, const list_parameter_value *p2) {
                return p1->compare(p2);
            }
        };



        // 
        class option_parameter_value: public object {
            class list                          *_symbol_value_list;

            public:
            option_parameter_value(list *_symbol_value_list)
                : object(AST_OPTION_PARAMETER_VALUE), _symbol_value_list(_symbol_value_list)
            {
            }
            ~option_parameter_value();

            list *ast_symbol_value_list() { return _symbol_value_list; }
            const list *ast_symbol_value_list() const { return _symbol_value_list; }

            void describe(FILE *out);
            std::string glance(FILE *out, act_opt option);
            void action(FILE *out, act_opt option);
            int compare(const option_parameter_value *p2) const;
            virtual int compare(const object *p2) const { 
                // return compare(dynamic_cast<const option_parameter_value *>(p2));
                // const option_parameter_value *child = (const option_parameter_value *)p2;
                const option_parameter_value *child = dynamic_cast<const option_parameter_value *>(p2);
                return compare(child);
            }
            static int compare(const option_parameter_value *p1, const option_parameter_value *p2) {
                return p1->compare(p2);
            }
        };



        // 
        class star_parameter_value: public object {
            class list_parameter                *_list_parameter;

            public:
            star_parameter_value(list_parameter *_list_parameter)
                : object(AST_STAR_PARAMETER_VALUE), _list_parameter(_list_parameter)
            {
            }
            ~star_parameter_value();

            list_parameter *ast_list_parameter() { return _list_parameter; }
            const list_parameter *ast_list_parameter() const { return _list_parameter; }

            void describe(FILE *out);
            std::string glance(FILE *out, act_opt option);
            void action(FILE *out, act_opt option);
            int compare(const star_parameter_value *p2) const;
            virtual int compare(const object *p2) const { 
                // return compare(dynamic_cast<const star_parameter_value *>(p2));
                // const star_parameter_value *child = (const star_parameter_value *)p2;
                const star_parameter_value *child = dynamic_cast<const star_parameter_value *>(p2);
                return compare(child);
            }
            static int compare(const star_parameter_value *p1, const star_parameter_value *p2) {
                return p1->compare(p2);
            }
        };



        // 
        class token_definition: public symbol_value_element {
            string                              _token_key;
            string                              _token_value;

            public:
            // 
            token_definition(const char *token_key, const char *token_value)
                : symbol_value_element(AST_TOKEN_DEFINITION),
                _token_key(token_key), _token_value(token_value)
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
            void describe(FILE *out);
            // 
            std::string glance(FILE *out, act_opt option);
            // 
            void action(FILE *out, act_opt option);
            // 
            int compare(const token_definition *p2) const;
            // 
            virtual int compare(const object *p2) const { 
                const token_definition *child = dynamic_cast<const token_definition *>(p2);
                return compare(child);
            }
            // 
            static int compare(const token_definition *p1, const token_definition *p2) {
                return p1->compare(p2);
            }
            // 
            virtual int compare(const symbol_value_element *p2) const {
                const token_definition *child = dynamic_cast<const token_definition *>(p2);
                return compare(child);
            }

        };



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
        // tables.
        struct table {
            char *list[1024];
            int count;
        };
        struct ast_table {
            symbol_value_element *list[1024];
            int count;
        };
        // 
        void table_init(struct table *table);
        // 
        int table_index(struct table *table, const char *key);
        // 
        void table_add(struct table *table, const char *key);

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
        void tokens_init();
        // 
        int tokens_index(const char *symbol_name);
        // 
        void tokens_add(const char *token_name);

        // 
        void ast_table_init(struct ast_table *table);
        // 
        int ast_table_index(struct ast_table *table, symbol_value_element *elem);
        // 
        void ast_table_add(struct ast_table *table, symbol_value_element *elem);

        // 
        void ast_table_LIST_init();
        // 
        int ast_table_LIST_index(list_parameter *elem);
        // 
        int ast_table_LIST_index(const std::vector<std::string> &sve_list);
        // 
        int ast_table_LIST_index(const std::vector<object *> &obj_list);
        // 
        void ast_table_LIST_add(const char *key, list_parameter *elem);
        // 
        void ast_table_OPT_init();
        // 
        int ast_table_OPT_index(option_parameter *elem);
        // 
        void ast_table_OPT_add(const char *key, option_parameter *elem);
        // 
        void ast_table_STAR_init();
        // 
        int ast_table_STAR_index(star_parameter *elem);
        // 
        void ast_table_STAR_add(const char *key, star_parameter *elem);

        // 
        void main();
    }
}



#endif
