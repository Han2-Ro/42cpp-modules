#pragma once

#include <string>

class ClapTrap {
   protected:
    std::string  name_;
    unsigned int health_;
    unsigned int energy_;
    unsigned int attackDamage_;
    ClapTrap();

   public:
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    ~ClapTrap();
    virtual void attack(const std::string& target);
    void         takeDamage(unsigned int amount);
    void         beRepaired(unsigned int amount);
    void         display() const;
};
