#include <iostream>
using namespace std;

#include <string>
#include <vector>


//
struct Tree {
    std::string _value;
    Tree *_left;
    Tree *_right;

public:
    Tree(const std::string &value): _value(value), _left(nullptr), _right(nullptr) { }

    //
    void postorder() {
        std::vector<Tree *> stack;
        postorder(stack);
    }

    //
    void postorder(std::vector<Tree *> &stack) {
        if (_left) {
            _left->postorder(stack);
        }
        if (_right) {
            _right->postorder(stack);
        }

        //
        if (_left == nullptr && _right == nullptr) {
            std::cout << _value.c_str() << " " << std::endl;
        }
    }
};

//
int main() {
    Tree *o1 = new Tree("OPT_1");
    {
        Tree *a = new Tree("a");
        o1->_left = a;

        Tree *b = new Tree("b");
        Tree *c = new Tree("c");
        Tree *o2 = new Tree("OPT_2");
        o2->_left = b;
        o2->_right = c;
        o1->_right = o2;
    }

    //
    o1->postorder();

    //
    return 0;
}
