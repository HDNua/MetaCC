#include <string>
#include <vector>

#include <cstdio>
#include <cstring>



namespace ast {
    using std::string;
    typedef enum ast_type {
        AST_UNTYPED,
        AST_LIST,
        AST_LIST_NODE,
        AST_LINE_LIST,
        AST_LINE,
        AST_EXPR,
        AST_TERM,
        AST_PRIMARY,
    } ast_type;



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
        virtual std::string glance(FILE *out) = 0;
        // 
        virtual void action(FILE *out) = 0;
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
    template <class Type>
        class list: public object {
            ast_type _elem_type;
            std::vector<Type> _vector;

            public:
            list(ast_type elem_type)
                : object(AST_LIST), _elem_type(elem_type)
            {
            }
            ~list();

            // 
            ast_type elem_type() const { return _elem_type; }
            // 
            int count() const { return _vector.size(); }

            // 
            void describe(FILE *out);
            // 
            std::string glance(FILE *out);
            // 
            void action(FILE *out);

            // 
            int compare(const list *p2) const;
            // 
            virtual int compare(const object *p2) const {
                return compare(dynamic_cast<const list *>(p2));
            }
            // 
            static int compare(const list *p1, const list *p2) {
                return p1->compare(p2);
            }

            // 
            void append(object *o, ast_type elem_type) {
                _vector.push_back(o);
            }
            typename     std::vector<Type>::iterator first() {
                return _vector.begin();
            }
            typename     std::vector<Type>::const_iterator first() const {
                return _vector.begin();
            }
        };



    // 
    class line_list {
        ast_type                        type;

        public: 
        // 
        void describe(FILE *out);
        // 
        void action(FILE *out);
    };



    // 
    class line {
        ast_type                        type;

        public: 
        // 
        void describe(FILE *out);
        // 
        void action(FILE *out);
    };



    // 
    class expr {
        ast_type                        type;

        public: 
        // 
        void describe(FILE *out);
        // 
        void action(FILE *out);
    };



    // 
    class term {
        ast_type                        type;

        public: 
        // 
        void describe(FILE *out);
        // 
        void action(FILE *out);
    };



    // 
    class primary {
        ast_type                        type;

        public: 
        // 
        void describe(FILE *out);
        // 
        void action(FILE *out);
    };



}


