#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed() : value_(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : value_(other.value_) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    value_ = other.value_;
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits() const {
    std::cout << "getRawBits called" << std::endl;
    return value_;
}

void Fixed::setRawBits(const int raw) {
    std::cout << "setRawBits called" << std::endl;
    value_ = raw;
}
