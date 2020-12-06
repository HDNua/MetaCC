#ifndef __HANDY_VAST_H__
#define __HANDY_VAST_H__

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
    virtual ~object() { }
    
    // 
    ast_type type() const { return _type; }
    
    // 
    virtual void describe(FILE *out) {
        // throw Exception("NOT IMPLEMENTED");
    }
    // 
    virtual std::string glance(FILE *out) {
        // throw Exception("NOT IMPLEMENTED");
        return std::string("NOT IMPLEMENTED");
    }
    // 
    virtual void action(FILE *out) {
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
    void describe(FILE *out) {
        
    }
    // 
    std::string glance(FILE *out) {
        return std::string("NOT IMPLEMENTED");
    }
    // 
    void action(FILE *out) {
        
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
    ast_type                        type;
    
public: 
    // 
    line_list(): object(AST_LINE_LIST) {
        
    }
    ~line_list() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class line: public object {
    ast_type                        type;
    
public: 
    // 
    line(): object(AST_LINE) {
        
    }
    ~line() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class expr: public object {
    ast_type                        type;
    
public: 
    // 
    expr(): object(AST_EXPR) {
        
    }
    ~expr() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class term: public object {
    ast_type                        type;
    
public: 
    // 
    term(): object(AST_TERM) {
        
    }
    ~term() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



// 
class primary: public object {
    ast_type                        type;
    
public: 
    // 
    primary(): object(AST_PRIMARY) {
        
    }
    ~primary() {
        
    }
    
    // 
    void describe(FILE *out);
    // 
    void action(FILE *out);
};



}


#endif
