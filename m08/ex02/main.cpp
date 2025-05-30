#include <algorithm>
#include <iostream>
#include <list>
#include <stack>
#include <vector>

#include "MutantStack.hpp"

void print(int n) {
    std::cout << n << std::endl;
}

int main() {
    {
        std::cout << "std::vector" << std::endl;
        std::vector<int> l;
        l.push_back(5);
        l.push_back(17);
        std::cout << l.back() << std::endl;
        l.pop_back();
        std::cout << l.size() << std::endl;
        l.push_back(3);
        l.push_back(5);
        l.push_back(737);
        //[...]
        l.push_back(0);
        std::vector<int>::iterator it = l.begin();
        std::vector<int>::iterator ite = l.end();
        ++it;
        --it;
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
        std::vector<int> s(l);
    }
    std::cout << std::endl;
    {
        std::cout << "MutantStack" << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
    std::cout << std::endl;
    {
        MutantStack<int> mstack;
        for (int i = 0; i < 10; i++) {
            mstack.push(i);
        }
        std::for_each(mstack.begin(), mstack.end(), print);
        std::cout << "size: " << mstack.size() << std::endl;
        std::cout << "top: " << mstack.top() << std::endl;
        for (int i = 0; i < 10; i++) {
            mstack.pop();
        }
        std::cout << "size: " << mstack.size() << std::endl;
        std::cout << "empty: " << mstack.empty() << std::endl;
    }
    return 0;
}