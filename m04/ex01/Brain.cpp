
#include "Brain.hpp"

#include <iostream>

Brain::Brain() {
    std::cout << "Brain: Default constructor called" << std::endl;
    for (unsigned int i = 0; i < size; ++i) {
        ideas[i] = "<empty>";
    }
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain: Copy constructor called" << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Brain: Copy assignment operator called" << std::endl;
    if (this != &other) {
        for (unsigned int i = 0; i < size; ++i) {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain: Destructor called" << std::endl;
}

std::string Brain::getIdea(const unsigned int& index) const {
    if (index < size) {
        return ideas[index];
    } else {
        return "<empty>";
    }
}

void Brain::setIdea(const unsigned int& index, std::string idea) {
    if (index < size) {
        ideas[index] = idea;
    }
}
