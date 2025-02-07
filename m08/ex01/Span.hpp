#pragma once
#include <set>
#include <iostream>

class Span {
   private:
    unsigned int N;
    std::multiset<int> numbers;

   public:
    Span();
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();
    int addNumber(int n);
    int shortestSpan();
    int longestSpan();
    void print();
};
