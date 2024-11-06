#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name):
    name(name)
{}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = weapon;
}

void HumanB::attack() {
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}

