
#include "Dog.hpp"

#include <iostream>

#include "Animal.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain()) {
    std::cout << "Dog: Default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain()) {
    std::cout << "Dog: Copy constructor called" << std::endl;
    *this = other;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog: Copy assignment operator called" << std::endl;
    type = other.type;
    *brain = *other.brain;
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog: Destructor called" << std::endl;
    delete brain;
}

Brain* Dog::getBrain() const {
    return brain;
}

void Dog::makeSound() const {
    std::cout << "Woof woof!" << std::endl;
}
