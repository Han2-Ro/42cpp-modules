#include "Fixed.hpp"

#include <cmath>
#include <iostream>
#include <ostream>

Fixed::Fixed() : data_(0) {
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
    data_ = value * std::pow(2, DECIMAL_PLACES);
}

Fixed::Fixed(const float value) {
    data_ = value * std::pow(2, DECIMAL_PLACES);
}

Fixed::Fixed(const Fixed& other) : data_(other.data_) {
    // std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(){
    // std::cout << "Destructor called" << std::endl;
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
    return data_ / std::pow(2, DECIMAL_PLACES);
}

float Fixed::toFloat() const {
    return data_ / std::pow(2, DECIMAL_PLACES);
}

Fixed& Fixed::operator=(const Fixed& other) {
    // std::cout << "Copy assignment operator called" << std::endl;
    data_ = other.data_;
    return *this;
}

bool Fixed::operator<(const Fixed& other) const {
    return data_ < other.data_;
}

bool Fixed::operator>(const Fixed& other) const {
    return other < *this;
}

bool Fixed::operator<=(const Fixed& other) const {
    return !(*this > other);
}

bool Fixed::operator>=(const Fixed& other) const {
    return !(*this < other);
}

bool Fixed::operator==(const Fixed& other) const {
    return data_ == other.data_;
}

bool Fixed::operator!=(const Fixed& other) const {
    return !(data_ == other.data_);
}

Fixed& Fixed::operator+=(const Fixed& other) {
    this->data_ += other.data_;
    return *this;
}

Fixed Fixed::operator+(Fixed other) const {
    other += *this;
    return other;
}

Fixed& Fixed::operator-=(const Fixed& other) {
    this->data_ -= other.data_;
    return *this;
}

Fixed Fixed::operator-(Fixed other) const {
    Fixed res(*this);
    res -= other;
    return res;
}

Fixed& Fixed::operator*=(const Fixed& other) {
    double d = this->data_ * other.data_;
    this->data_ = d / pow(2, DECIMAL_PLACES);
    return *this;
}

Fixed Fixed::operator*(Fixed other) const {
    other *= *this;
    return other;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
