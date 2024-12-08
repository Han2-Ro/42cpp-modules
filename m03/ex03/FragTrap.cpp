#include "FragTrap.hpp"

#include <iostream>

#include "ClapTrap.hpp"

FragTrap::FragTrap() {}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "FragTrap " << name_ << ": constructor called" << std::endl;
    health_ = healthStart_;
    energy_ = energyStart_;
    attackDamage_ = attackDamgeStart_;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap " << name_ << ": Copy constructor called" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << name_ << ": Destructor called" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "Let's do a high five, guys!" << std::endl;
}
