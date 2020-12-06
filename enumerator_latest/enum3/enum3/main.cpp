#include <iostream>

#include <string>
#include <vector>

class Array {
    std::vector<std::string> _list;
    int _index;

public:
    //
    Array(): _index(0) { }

    //
    void init() {
        _index = 0;
    }
    //
    std::string get() {
        if (_index < _list.size()) {
            std::string ret = _list[_index++];
            return ret;
        }
        return "";
    }
    //
    void push_back(const std::string &value) {
        _list.push_back(value);
    }
};

int main() {
    std::vector<bool> emitted_stack;
    std::vector<std::string> emitted_string;

    Array tree[5];
    tree[0].push_back("a");
    tree[0].push_back("b");
    tree[0].push_back("c");
    tree[1].push_back("d");
    tree[1].push_back("e");
    tree[2].push_back("f");
    tree[2].push_back("g");
    tree[2].push_back("h");
    tree[2].push_back("i");
    tree[3].push_back("k");
    tree[4].push_back("l");
    tree[4].push_back("m");
    tree[4].push_back("n");

    //
    bool all_emitted;
    do {
        all_emitted = true;

        //
        if (emitted_stack.empty() == false) {
            while (emitted_stack.back() == false) {
                emitted_stack.pop_back();
                emitted_string.pop_back();

                int index = emitted_string.size();
                tree[index].init();
            }
        }

        //
        for (int i=emitted_stack.size(), len=5; i<len; ++i) {
            std::string ret = tree[i].get();
            bool emitted = (ret == "");

            emitted_stack.push_back(emitted);
            emitted_string.push_back(ret);
        }

        //
        for (auto it = emitted_stack.begin(); it != emitted_stack.end(); ++it) {
            if (*it == false) {
                all_emitted = false;
                break;
            }
        }

        //
        for (auto it = emitted_string.begin(); it != emitted_string.end(); ++it) {
            std::cout << *it << ' ';
        }
        std::cout << std::endl;
    } while (all_emitted == false);

    return 0;
}

