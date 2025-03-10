#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
   public:
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap& other);
    ~ScavTrap();
    void guardGate();
    void attack(const std::string& target);
};
