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
        virtual const char* what() const throw() {
            return "Span is full";
        }
    };
    class NotEnoughNumbersException : public std::exception {
       public:
        virtual const char* what() const throw() {
            return "Not enough numbers to calculate span";
        }
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
