
#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap(std::string name) : name_(name), health_(10), energy_(10), attackDamage_(0) {
    std::cout << "Default constructor called" << std::endl;
    // dict_[name_] = *this;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "Copy constructor called" << std::endl;
    name_ = other.name_;
    health_ = other.health_;
    energy_ = other.energy_;
    // dict_[name_] = *this;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    name_ = other.name_;
    health_ = other.health_;
    energy_ = other.energy_;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    energy_--;
    /*
    std::map<std::string, ClapTrap&>::iterator it = ClapTrap::dict_.find(target);
    if (it != ClapTrap::dict_.end()) {
        it->second.takeDamage(attackDamage_);
    }
    */
    std::cout << "ClapTrap " << name_ << " attacks " << target << ", causing " << attackDamage_
              << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount) {
    health_ -= amount;
}
void ClapTrap::beRepaired(unsigned int amount) {
    energy_--;
    health_ += amount;
}

void ClapTrap::display() const {
    std::cout << "---------------------" << std::endl;
    std::cout << "Name:   " << name_ << std::endl;
    std::cout << "Health: " << health_ << std::endl;
    std::cout << "Energy: " << energy_ << std::endl;
}
