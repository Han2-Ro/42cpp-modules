#pragma once
#include <algorithm>

template <typename T>
class MutantStack: public std::stack<T> {
   public:
    MutantStack();
    MutantStack(const MutantStack& other);
    MutantStack& operator=(const MutantStack& other);
    ~MutantStack();
};

