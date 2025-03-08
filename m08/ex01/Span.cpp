
#include "Span.hpp"

#include <iostream>

Span::Span() : N(0) {
    std::cout << "Span: Default constructor called" << std::endl;
}

Span::Span(unsigned int N) : N(N) {
    std::cout << "Span: Parameter constructor called" << std::endl;
}

Span::Span(const Span& other) {
    std::cout << "Span: Copy constructor called" << std::endl;
    *this = other;
}

Span& Span::operator=(const Span& other) {
    std::cout << "Span: Copy assignment operator called" << std::endl;
    this->N = other.N;
    this->numbers = other.numbers;
    return *this;
}

Span::~Span() {
    std::cout << "Span: Destructor called" << std::endl;
}

int Span::addNumber(int n) {
    if (numbers.size() >= N) {
        throw SpanFullException();
    }
    numbers.insert(n);
    return 0;
}

int Span::shortestSpan() {
    return 0;
}

int Span::longestSpan() {
    return 0;
}

void Span::print() {
    for (std::multiset<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        std::cout << *it << std::endl;
    }
}