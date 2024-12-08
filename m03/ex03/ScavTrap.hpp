#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
   protected:
    ScavTrap();
    static const int healthStart_ = 100;
    static const int energyStart_ = 50;
    static const int attackDamgeStart_ = 20;

   public:
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap& other);
    ~ScavTrap();
    void guardGate();
    void attack(const std::string& target);
};
