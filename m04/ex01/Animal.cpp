
#include "Animal.hpp"

#include <iostream>
#include <string>

Animal::Animal() : type("Undefined"), brain(new Brain()) {
    std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::Animal(const std::string& type) : type(type), brain(new Brain()) {
    std::cout << "Animal: Parmeter constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : brain(new Brain()) {
    std::cout << "Animal: Copy constructor called" << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal: Copy assignment operator called" << std::endl;
    type = other.type;
    *brain = *other.brain;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal: Destructor called" << std::endl;
    delete brain;
}

std::string Animal::getType() const {
    return type;
}

Brain* Animal::getBrain() const {
    return brain;
}

void Animal::makeSound() const {
    std::cout << "<silence>" << std::endl;
}
