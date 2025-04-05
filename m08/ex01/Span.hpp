#pragma once
#include <set>
#include <iostream>

class Span {
   private:
    unsigned int _n;
    std::multiset<int> numbers;

   public:
    class SpanFullException : public std::exception {
       public:
        virtual const char* what() const throw();
    };
    class NotEnoughNumbersException : public std::exception {
       public:
        virtual const char* what() const throw();
    };
    Span();
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();
    int addNumber(int n);
    unsigned int shortestSpan();
    unsigned int longestSpan();
    void print();
    template <typename Iterator>
    void addNumbers(Iterator begin, Iterator end) {
        while (begin != end) {
            addNumber(*begin);
            begin++;
        }
    }
};
