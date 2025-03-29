
#include "Span.hpp"

#include <limits.h>

#include <iostream>

Span::Span() : _n(0) {
    std::cout << "Span: Default constructor called" << std::endl;
}

Span::Span(unsigned int N) : _n(N) {
    std::cout << "Span: Parameter constructor called" << std::endl;
}

Span::Span(const Span& other) {
    std::cout << "Span: Copy constructor called" << std::endl;
    *this = other;
}

Span& Span::operator=(const Span& other) {
    std::cout << "Span: Copy assignment operator called" << std::endl;
    this->_n = other._n;
    this->numbers = other.numbers;
    return *this;
}

Span::~Span() {
    std::cout << "Span: Destructor called" << std::endl;
}

int Span::addNumber(int n) {
    if (numbers.size() >= _n) {
        throw SpanFullException();
    }
    numbers.insert(n);
    return 0;
}

unsigned int Span::shortestSpan() {
    if (numbers.size() < 2) {
        throw Span::NotEnoughNumbersException();
    }
    unsigned int                 shortest = UINT_MAX;
    std::multiset<int>::iterator it = numbers.begin();
    std::multiset<int>::iterator it2 = numbers.begin();
    it2++;
    for (; it2 != numbers.end(); it++, it2++) {
        if ((unsigned int)(*it2 - *it) < shortest) {
            shortest = *it2 - *it;
        }
    }
    return shortest;
}

unsigned int Span::longestSpan() {
    if (numbers.size() < 2) {
        throw Span::NotEnoughNumbersException();
    }
    return *numbers.rbegin() - *numbers.begin();
}

void Span::print() {
    for (std::multiset<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        std::cout << *it << std::endl;
    }
}