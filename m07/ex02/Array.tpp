#include <iostream>

template <typename T>
Array<T>::Array() : N(0), _data(new T[0]) {
    std::cout << "Array: Default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(const unsigned int n) : N(n), _data(new T[n]) {
    std::cout << "Array: Parameter constructor called" << std::endl;
    for (unsigned int i = 0; i < N; i++) {
        _data[i] = T();
    }
}

template <typename T>
Array<T>::Array(const Array& other) : N(other.N), _data(new T[other.N]) {
    std::cout << "Array: Copy constructor called" << std::endl;
    for (unsigned int i = 0; i < N; i++) {
        _data[i] = other._data[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    std::cout << "Array: Copy assignment operator called" << std::endl;
    this->N = other.N;
    delete[] this->_data;
    this->_data = new T[this->N];
    for (unsigned int i = 0; i < this->N; i++) {
        this->_data[i] = other._data[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    std::cout << "Array: Destructor called" << std::endl;
    delete[] _data;
}

template <typename T>
T& Array<T>::operator[](unsigned int idx) {
    if (idx >= N) {
        throw std::out_of_range("Index out of range");
    }
    return _data[idx];
}

template <typename T>
const T& Array<T>::operator[](unsigned int idx) const {
    if (idx >= N) {
        throw std::out_of_range("Index out of range");
    }
    return _data[idx];
}

template <typename T>
unsigned int Array<T>::size() const {
    return N;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr) {
    os << "[ ";
    for (unsigned int i = 0; i < arr.size(); i++) {
        os << arr[i] << " ";
    }
    os << "]";
    return os;
}