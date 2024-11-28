
#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap(std::string name) : name_(name), health_(10), energy_(10), attackDamage_(0) {
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "Copy constructor called" << std::endl;
    name_ = other.name_;
    health_ = other.health_;
    energy_ = other.energy_;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    *this = ClapTrap(other);
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    energy_--;
    std::cout << "ClapTrap " << name_ << " attacks " << target << ", causing " << attackDamage_
              << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount) {
    health_ -= amount;
}
void ClapTrap::beRepaired(unsigned int amount) {}
