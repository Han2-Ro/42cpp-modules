#pragma once
#include <string>

class Zombie {
   private:
    std::string name;

   public:
    Zombie();
    Zombie(const std::string& name);
    ~Zombie();

    void announce();
    void setName(std::string& name);
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);
