#pragma once
#include <iostream>

template <typename T>
class Array {
   private:
    unsigned int N;
    T*           _data;

   public:
    Array();
    Array(const unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();

    T&           operator[](unsigned int idx);
    const T&     operator[](unsigned int idx) const;
    unsigned int size() const;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& obj);

#include "Array.tpp"
