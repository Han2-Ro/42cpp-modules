#include <iostream>

#include "Array.hpp"

template <typename T, size_t N>
Array<T, N>::Array() : _data(new T[N]) {
    std::cout << "Array: Default constructor called" << std::endl;
}

template <typename T, size_t N>
Array<T, N>::Array(const Array& other) {
    std::cout << "Array: Copy constructor called" << std::endl;
}

template <typename T, size_t N>
Array<T, N>& Array<T, N>::operator=(const Array& other) {
    std::cout << "Array: Copy assignment operator called" << std::endl;
}

template <typename T, size_t N>
Array<T, N>::~Array() {
    std::cout << "Array: Destructor called" << std::endl;
    delete[] _data;
}
