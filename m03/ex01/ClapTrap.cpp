#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap() {}

ClapTrap::ClapTrap(std::string name) : name_(name), health_(10), energy_(10), attackDamage_(0) {
    std::cout << "ClapTrap " << name_ << ": Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "ClapTrap " << name_ << ": Copy constructor called" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap " << name_ << ": Copy assignment operator called" << std::endl;
    name_ = other.name_;
    health_ = other.health_;
    energy_ = other.energy_;
    attackDamage_ = other.attackDamage_;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name_ << ": Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (energy_ > 0) {
        energy_--;
        std::cout << "ClapTrap " << name_ << " attacks " << target << ", causing " << attackDamage_
                  << " points of damage!" << std::endl;
    } else {
        std::cout << "ClapTrap " << name_ << " does not have enough energy to attack." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (health_ > 0) {
        std::cout << "ClapTrap " << name_ << " taking " << amount << " damage." << std::endl;
        if (amount < health_) {
            health_ -= amount;
        } else {
            health_ = 0;
        }
    }
    if (health_ == 0) {
        std::cout << "ClapTrap " << name_ << " is dead." << std::endl;
    }
}
void ClapTrap::beRepaired(unsigned int amount) {
    if (energy_ > 0) {
        std::cout << "ClapTrap " << name_ << " gets repaired by " << amount << std::endl;
        energy_--;
        health_ += amount;
    } else {
        std::cout << "ClapTrap " << name_ << " does not have enough energy to repair." << std::endl;
    }
}

void ClapTrap::display() const {
    std::cout << "---------------------" << std::endl;
    std::cout << "Name:   " << name_ << std::endl;
    std::cout << "Health: " << health_ << std::endl;
    std::cout << "Energy: " << energy_ << std::endl;
    std::cout << "Attack Damage: " << attackDamage_ << std::endl;
    std::cout << "---------------------" << std::endl;
}
