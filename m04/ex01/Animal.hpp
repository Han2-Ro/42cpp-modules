#pragma once

#include <string>
#include "Brain.hpp"

class Animal {
   protected:
    std::string type;
    Brain* brain;
    Animal(const std::string& type);

   public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();
    std::string  getType() const;
    Brain* getBrain() const;
    virtual void makeSound() const;
};
