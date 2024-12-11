
#include "Animal.hpp"

#include <iostream>
#include <string>

Animal::Animal() : type("Undefined") {
    std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::Animal(const std::string& type) : type(type) {
    std::cout << "Animal: Parameter constructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
    std::cout << "Animal: Copy constructor called" << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal: Copy assignment operator called" << std::endl;
    type = other.type;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal: Destructor called" << std::endl;
}

std::string Animal::getType() const {
    return type;
}

void Animal::makeSound() const {
    std::cout << "<silence>" << std::endl;
}
