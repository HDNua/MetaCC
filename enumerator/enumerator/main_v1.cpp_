#include <iostream>
#include <string>


#include <vector>
#include <stack>


// 
class Tree {
    std::string _data;

    std::vector<Tree *> _children;
    std::vector<Tree *>::iterator _iterator;

    public:
    Tree(const std::string &data): _data(data) { }

    // 
    std::string &data() { return _data; }
    // 
    const std::string &data() const { return _data; }

    // 
    std::vector<Tree *> &children() { return _children; }
    // 
    const std::vector<Tree *> &children() const { return _children; }


    // 
    std::vector<Tree *>::iterator iterator() { return _iterator; }
    // 
    const std::vector<Tree *>::iterator &iterator() const { return _iterator; }


    // 
    void push(const std::string &value) {
        _children.push_back(new Tree(value));
    }


    // 
    void initialize();
    // 
    std::vector<Tree *>::iterator coroutine();


    // 
    void enumerate();

    private:
    // 
    std::vector<Tree *> &enumerate(std::vector<Tree *> &out, Tree *tree);
};



// 
void Tree::initialize() {
    _iterator = _children.begin();
}
// 
std::vector<Tree *>::iterator Tree::coroutine() {
    if (_iterator != _children.end()) {
        return _iterator++;
    }
    return _children.end();
}
// 
void Tree::enumerate() {
    std::vector<std::vector<Tree *>::iterator> it_stack;
    std::vector<Tree *> out;

    // 
    std::cout << "enumerator begins " << std::endl;
    do {
        // 
        for (initialize(); _iterator != _children.end(); ++_iterator) {
            Tree *tree = *_iterator;

            if (tree->children().size() > 0) {
                // std::cout << "ADDED NONTERMINAL(" << tree->children().size() << ") " << std::endl;
                it_stack.push_back(tree->coroutine());
            }
            else {
                // std::cout << "ADDED TERMINAL(" << tree->data() << ") " << std::endl;
                it_stack.push_back(_iterator);
            }
        }
        std::cout << "it_stack initialized." << std::endl;

        // 
        for (auto it = it_stack.begin(); it != it_stack.end(); ++it) {
            auto it2 = *it;
            if (it2 != _children.end()) {
                Tree *tree = *it2;

                if (tree) {
                    std::cout << tree->data().c_str() << ' ';
                }
            }
        }
        std::cout << "enumeration ended. " << std::endl;
        break;

        // 
        while ((_iterator = it_stack.back()) == _children.end()) {
            (*_iterator)->initialize();
            it_stack.pop_back();
        }

    } while (it_stack.empty() == false);
}
// 
std::vector<Tree *> &Tree::enumerate(std::vector<Tree *> &out, Tree *tree) {
    return out;
}



// 
int main(void) {
    int n;
    std::cin >> n;

    Tree start("start");

    // 
    while (n--) {
        Tree *tree = new Tree("TREE");

        int n2;
        std::cin >> n2;
        while (n2--) {
            std::string token;
            std::cin >> token;
            tree->push(token);

            std::cout << "token " << token << " was added " << std::endl;
        }

        // 
        start.children().push_back(tree);
    }

    // 
    start.enumerate();

    // 
    return 0;
}


