#include "Fixed.hpp"

#include <iostream>
#include <ostream>

Fixed::Fixed() : data_(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : data_(value * (2 ^ decimalPoint_)) {}

Fixed::Fixed(const float value) : data_(0) {
    (void)value;
}

Fixed::Fixed(const Fixed& other) : data_(other.data_) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    data_ = other.data_;
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits() const {
    std::cout << "getRawBits called" << std::endl;
    return data_;
}

void Fixed::setRawBits(const int raw) {
    std::cout << "setRawBits called" << std::endl;
    data_ = raw;
}

int Fixed::toInt() const {
    return 0;
}

float Fixed::toFloat() const {
    return 0.0;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    (void)fixed;
    os << "WIP";
    return os;
}
