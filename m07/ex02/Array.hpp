#pragma once

#include <cstddef>

template <typename T, size_t N>
class Array {
   private:
    T _data[N];

   public:
    Array();
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();
};
