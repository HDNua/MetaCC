#ifndef __HANDY_VAST_H__
#define __HANDY_VAST_H__

#include <string>
#include <vector>

#include <cstdio>
#include <cstring>



namespace ast {
using std::string;

class object;
class line_list;
class line;
class expr;
class term;
class primary;
class attribute;


typedef enum ast_type {
    AST_UNTYPED,
    AST_LIST,
    AST_LIST_NODE,
    AST_LINE_LIST,
    AST_LINE,
    AST_EXPR,
    AST_TERM,
    AST_PRIMARY,
    AST_ATTRIBUTE,
} ast_type;

typedef struct cs_info {
    FILE *out;
    const int level;
    cs_info(int level, FILE *out=stdout) : out(out), level(level) { }
    cs_info sub() { return cs_info(level+1); }
    cs_info sub0() { return cs_info(level); }
} cs_info;



class object {
    ast_type _type;

public:
    // 
    object(ast_type type): _type(type) { }
    // 
    virtual ~object() { }
    
    // 
    ast_type type() const { return _type; }
    
    // 
    virtual void describe(cs_info &&cs) {
        // throw Exception("NOT IMPLEMENTED");
    }
    // 
    virtual std::string glance(cs_info &&cs) {
        // throw Exception("NOT IMPLEMENTED");
        return std::string("NOT IMPLEMENTED");
    }
    // 
    virtual void action(cs_info &&cs) {
        // throw Exception("NOT IMPLEMENTED");
    }
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
    std::vector<object *> _vector;

public:
    list()
        : object(AST_LIST)
    {
    }
    ~list() {
        
    }
    
    // 
    int count() const { return _vector.size(); }
    
    // 
    void describe(cs_info &&cs) {
        for (auto it = _vector.begin(); it != _vector.end(); ++it) {
            (*it)->describe(cs.sub());
        }
    }
    // 
    std::string glance(cs_info &&cs) {
        return std::string("NOT IMPLEMENTED");
    }
    // 
    void action(cs_info &&cs) {
        
    }
    
    // 
    int compare(const list *p2) const {
        return -1;
    }
    // 
    virtual int compare(const object *p2) const {
        return compare(dynamic_cast<const list *>(p2));
    }
    // 
    static int compare(const list *p1, const list *p2) {
        return p1->compare(p2);
    }
    
    // 
    void append(object *o) {
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
class line_list: public object {
    //ast_type                        type;
    ast::list<ast::object *>          *_list;
    
public: 
    // 
    line_list()
        : object(AST_LINE_LIST)
        , _list(nullptr)
    {
        
    }
    ~line_list() {
        
    }
    
    // 
    void describe(cs_info &&cs);
    // 
    void action(cs_info &&cs);

    //
    void init_with_list(ast::list<ast::object *> *list) {
        _list = list;
    }
};



// 
class line: public object {
    //ast_type                        type;
    ast::expr                       *_expr;
    
public: 
    // 
    line(): object(AST_LINE) {
        
    }
    ~line() {
        
    }
    
    // 
    void describe(cs_info &&cs);
    // 
    void action(cs_info &&cs);

    //
    void init_with_expr(ast::expr *expr) {
        _expr = expr;
    }
};



// 
class expr: public object {
    //ast_type                        type;
    int                             _init_type;
    ast::expr                       *_expr;
    std::string                     _op;
    ast::term                       *_term;
    
public: 
    // 
    expr()
        : object(AST_EXPR)
        , _init_type(-1)
        , _expr(nullptr)
        , _op("")
        , _term(nullptr)
    {
        
    }
    ~expr() {
        //delete _expr;
        //delete _term;
    }
    
    // 
    void describe(cs_info &&cs);
    // 
    void action(cs_info &&cs);

    //
    void init_with_add(ast::expr *expr, const char *op, ast::term *term) {
        _init_type = 0;
        _expr = expr;
        _op   = op;
        _term = term;
        fprintf(stderr, "[init_with_add] OP IS [ %s ] \n", op);
    }
    void init_with_sub(ast::expr *expr, const char *op, ast::term *term) {
        _init_type = 1;
        _expr = expr;
        _op   = op;
        _term = term;
        fprintf(stderr, "[init_with_sub] OP IS [ %s ] \n", op);
    }
    void init_with_term(ast::term *term) {
        _init_type = 2;
        _expr = nullptr;
        _term = term;
    }
};



// 
class term: public object {
    //ast_type                        type;
    int                             _init_type;
    ast::term                       *_term;
    std::string                     _op;
    ast::primary                    *_primary;
    
public: 
    // 
    term()
        : object(AST_TERM)
        , _init_type(-1)
        , _term(nullptr)
        , _op("")
        , _primary(nullptr)
    {
        
    }
    ~term() {
        //delete _term;
        //delete _primary;
    }
    
    // 
    void describe(cs_info &&cs);
    // 
    void action(cs_info &&cs);

    //
    void init_with_mul(ast::term *term, const char *op, ast::primary *primary) {
        _init_type = 0;
        _term    = term;
        _op      = op;
        _primary = primary;
        fprintf(stderr, "[init_with_mul] OP IS [ %s ] \n", op);
    }
    void init_with_div(ast::term *term, const char *op, ast::primary *primary) {
        _init_type = 1;
        _term    = term;
        _op      = op;
        _primary = primary;
        fprintf(stderr, "[init_with_div] OP IS [ %s ] \n", op);
    }
    void init_with_primary(ast::primary *primary) {
        _init_type = 2;
        _primary = primary;
    }
};



// 
class primary: public object {
    //ast_type                        type;

    int                             _init_type;
    int                             _number;
    std::string                     _string;
    ast::attribute                  *_attribute;
    ast::expr                       *_expr;
    
public: 
    //
    primary()
        : object(AST_PRIMARY)
        , _init_type(-1)
        , _number(0)
        , _string("")
        , _attribute(nullptr)
        , _expr(nullptr)
    {
    }
    ~primary() {
        //delete _string;
        //delete _attribute;
        //delete _expr;
    }

    //
    void init_with_unsigned_number(const char *s) {
        _init_type = 0;
        _number = atoi(s);
    }
    void init_with_decimal_number(const char *s) {
        _init_type = 1;
        _number = atoi(s);
    }
    void init_with_binary_number(const char *s) {
        _init_type = 2;
        _number = atoi(s);
    }
    void init_with_octal_number(const char *s) {
        _init_type = 3;
        _number = atoi(s);
    }
    void init_with_hex_number(const char *s) {
        _init_type = 4;
        _number = atoi(s);
    }
    void init_with_string(const char *s) {
        _init_type = 5;
        _string = s;
    }
    void init_with_attribute(ast::attribute *attribute) {
        _init_type = 6;
        _attribute = attribute;
    }
    void init_with_expr(ast::expr *expr) {
        _init_type = 7;
        _expr = expr;
    }
    
    // 
    void describe(cs_info &&cs);
    // 
    void action(cs_info &&cs);
};



// 
class attribute: public object {
    //ast_type                        type;
    std::string                     _attribute;
    
public: 
    // 
    attribute()
        : object(AST_ATTRIBUTE)
        , _attribute("") {
    }
    ~attribute() {
        
    }
    
    // 
    void describe(cs_info &&cs);
    // 
    void action(cs_info &&cs);

    //
    void init_with_identifier(const std::string &op) {
        fprintf(stderr, "[attribute::attribute()] %s \n", _attribute.c_str());
    }
};



}


#endif
