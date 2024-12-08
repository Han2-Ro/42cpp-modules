#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
   protected:
    FragTrap();
    static const int healthStart_ = 100;
    static const int energyStart_ = 100;
    static const int attackDamgeStart_ = 30;

   public:
    FragTrap(std::string name);
    FragTrap(const FragTrap& other);
    ~FragTrap();
    void highFivesGuys();
};
