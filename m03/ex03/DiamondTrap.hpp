#pragma once
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
   private:
    std::string name_;
    DiamondTrap();

   public:
    DiamondTrap(const std::string& name);
    DiamondTrap(const DiamondTrap& other);
    ~DiamondTrap();
    void display() const;
};
