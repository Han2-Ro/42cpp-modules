
#include "Cat.hpp"

#include <iostream>

#include "Animal.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain()) {
    std::cout << "Cat: Default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain()) {
    std::cout << "Cat: Copy constructor called" << std::endl;
    *this = other;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat: Copy assignment operator called" << std::endl;
    type = other.type;
    *brain = *other.brain;
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat: Destructor called" << std::endl;
    delete brain;
}

Brain* Cat::getBrain() const {
    return brain;
}

void Cat::makeSound() const {
    std::cout << "Meow moew!" << std::endl;
}
