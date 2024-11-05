#include "Weapon.hpp"
#include <string>

std::string Weapon::getType() {
    return this->type;
}

void Weapon::setType(std::string& type) {
    this->type = type;
}

