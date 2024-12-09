
#include "WrongCat.hpp"

#include <iostream>

#include "WrongAnimal.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << "WrongCat: Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) {
    std::cout << "WrongCat: Copy constructor called" << std::endl;
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "WrongCat: Copy assignment operator called" << std::endl;
    type = other.type;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat: Destructor called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Meow moew!" << std::endl;
}
