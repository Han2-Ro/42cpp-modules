#include "FragTrap.hpp"

#include <iostream>

#include "ClapTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "FragTrap: constructor called" << std::endl;
    health_ = 100;
    energy_ = 100;
    attackDamage_ = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap: Copy constructor called" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap: Destructor called" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "Let's do a high five, guys!" << std::endl;
}
