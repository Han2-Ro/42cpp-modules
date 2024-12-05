#pragma once

#include <iostream>
#include <string>

class ClapTrap {
   private:
    std::string  name_;
    unsigned int health_;
    unsigned int energy_;
    unsigned int attackDamage_;

   public:
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    ~ClapTrap();
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void display() const;
};
