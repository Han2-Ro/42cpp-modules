#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie(const std::string &str) : name(str) {}

Zombie::~Zombie() {
    std::cout << this->name << " destructed" << std::endl;
}

void Zombie::announce() {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
