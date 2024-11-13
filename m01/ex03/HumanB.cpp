#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <cstddef>

HumanB::HumanB(const std::string& name):
    name(name),
    weapon(NULL)
{}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon;
}

void HumanB::attack() {
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

