#pragma once
#include <algorithm>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
   public:
    class iterator : public std::iterator<T> {
    }
    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack& other) : std::stack<T>(other) {}
    ~MutantStack() {}
    iterator begin() {
        
    }
    iterator end() {}
};
