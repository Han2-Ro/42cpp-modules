#include "ScavTrap.hpp"

#include <iostream>

#include "ClapTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "ScavTrap: constructor called" << std::endl;
    health_ = 100;
    energy_ = 50;
    attackDamage_ = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap: Copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap: Destructor called" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name_ << " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (energy_ > 0) {
        energy_--;
        std::cout << "ScavTrap " << name_ << " attacks " << target << ", causing " << attackDamage_
                  << " points of damage!" << std::endl;
    } else {
        std::cout << "ScavTrap " << name_ << " does not have enough energy to attack." << std::endl;
    }
}
