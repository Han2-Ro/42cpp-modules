#include "DiamondTrap.hpp"

#include <iostream>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name_(name) {
    std::cout << "DiamondTrap " << name_ << ": constructor called" << std::endl;
    health_ = FragTrap::healthStart_;
    energy_ = ScavTrap::energyStart_;
    attackDamage_ = FragTrap::attackDamgeStart_;
}

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap() {
    std::cout << "DiamondTrap " << name_ << ": Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other) {
    std::cout << "DiamondTrap " << name_ << ": Copy constructor called" << std::endl;
    *this = other;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << name_ << ": Destructor called" << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "My DiamondTrap Name is: " << name_ << std::endl;
    std::cout << "My ClapTrap Name is: " << ClapTrap::name_ << std::endl;
}

void DiamondTrap::display() const {
    std::cout << "---------------------" << std::endl;
    std::cout << "DiamondTrap:" << std::endl;
    std::cout << "Name:   " << name_ << " " << &this->name_ << std::endl;
    std::cout << "Health: " << health_ << " " << &this->health_ << std::endl;
    std::cout << "Energy: " << energy_ << std::endl;
    std::cout << "Attack Damage: " << attackDamage_ << std::endl;
    std::cout << "FragTrap:" << std::endl;
    std::cout << "Name:   " << FragTrap::name_ << " " << &this->FragTrap::name_ << std::endl;
    std::cout << "Health: " << FragTrap::health_ << " " << &this->FragTrap::health_ << std::endl;
    std::cout << "Energy: " << FragTrap::energy_ << std::endl;
    std::cout << "Attack Damage: " << FragTrap::attackDamage_ << std::endl;
    std::cout << "ScavTrap:" << std::endl;
    std::cout << "Name:   " << ScavTrap::name_ << " " << &this->ScavTrap::name_ << std::endl;
    std::cout << "Health: " << ScavTrap::health_ << " " << &this->ScavTrap::health_ << std::endl;
    std::cout << "Energy: " << ScavTrap::energy_ << std::endl;
    std::cout << "Attack Damage: " << ScavTrap::attackDamage_ << std::endl;
    std::cout << "ClapTrap:" << std::endl;
    std::cout << "Name:   " << ClapTrap::name_ << " " << &this->ClapTrap::name_ << std::endl;
    std::cout << "Health: " << ClapTrap::health_ << " " << &this->ClapTrap::health_ << std::endl;
    std::cout << "Energy: " << ClapTrap::energy_ << std::endl;
    std::cout << "Attack Damage: " << ClapTrap::attackDamage_ << std::endl;
    std::cout << "---------------------" << std::endl;
}
