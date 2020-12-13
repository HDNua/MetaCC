#ifndef __HANDY_TABLE_H__
#define __HANDY_TABLE_H__

#include <vector>



template <class Type>
class table {
    std::vector<Type *> _list;

public:
    // 
    table() {

    }
    // 
    ~table() {
        for (std::vector<Type *>::iterator it = _list.begin(); it != _list.end(); ++it) {
            delete *it;
        }
    }

    // 
    int index(const Type *value) const { return -1; }
    // 
    void add(Type *value) {
        _list.push_back(value);
    }
};

template <>
class table<std::string> {
    std::vector<std::string> _list;

public:
    // 
    table() { }
    // 
    ~table() { }

    // 
    int index(const std::string &value) const { return -1; } 
    // 
    void add(const std::string &value) { _list.push_back(value); }
}



#endif
