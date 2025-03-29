#pragma once
#include <algorithm>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
   public:
    class iterator : public std::iterator<std::input_iterator_tag, T, T, T*, T&> {
        unsigned int _index;
        MutantStack<T>* _stack;
       public:
        iterator(unsigned int index, MutantStack<T>* stack) : _index(index), _stack(stack) {}
        iterator& operator++() {
            _index++;
            return *this;
        }
        iterator operator++(int) {
            iterator retval = *this;
            ++(*this);
            return retval;
        }
        iterator& operator--() {
            _index--;
            return *this;
        }
        iterator operator--(int) {
            iterator retval = *this;
            --(*this);
            return retval;
        }
        bool operator==(iterator other) const {
            return _index == other._index;
        }
        bool operator!=(iterator other) const {
            return !(*this == other);
        }
        T& operator*() {
            if (_index >= _stack->size()) {
                throw std::out_of_range("Iterator out of range");
            }
            return _stack->c[_index];
        }
    };
    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack& other) : std::stack<T>(other) {}
    ~MutantStack() {}
    iterator begin() {
        return iterator(0, this);
    }
    iterator end() {
        return iterator(this->size(), this);
    }
};
