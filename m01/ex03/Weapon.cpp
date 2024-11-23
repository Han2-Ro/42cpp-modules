#include "Weapon.hpp"

#include <string>

Weapon::Weapon(const std::string& type) : type(type) {}

Weapon::~Weapon() {}

std::string Weapon::getType() {
    return this->type;
}

void Weapon::setType(const std::string& type) {
    this->type = type;
}
