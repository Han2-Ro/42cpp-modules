#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
   protected:
    Brain* brain;

   public:
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog();
    Brain* getBrain() const;
    void   makeSound() const;
};
