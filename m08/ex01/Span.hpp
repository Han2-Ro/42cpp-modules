#pragma once
#include <set>
#include <iostream>

class Span {
   private:
    unsigned int N;
    std::multiset<int> numbers;

   public:
    class SpanFullException : public std::exception {
       public:
        virtual const char* what() const throw() {
            return "Span is full";
        }
    };
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
