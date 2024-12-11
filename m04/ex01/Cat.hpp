#pragma once

#include "Animal.hpp"

class Cat : public Animal {
   protected:
    Brain* brain;

   public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat();
    void makeSound() const;
};
