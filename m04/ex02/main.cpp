#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    {
        // array of Animals
        const unsigned int size = 11;
        Animal*            animals[size];
        for (unsigned int i = 0; i < size; i++) {
            animals[i] = i % 2 ? (Animal*)new Dog() : (Animal*)new Cat();
        }
        for (unsigned int i = 0; i < size; i++) {
            animals[i]->makeSound();
        }
        for (unsigned int i = 0; i < size; i++) {
            delete animals[i];
        }
    }
    std::cout << "-----------------" << std::endl;
    {
        // test deep copy
        Cat* a = new Cat();
        a->getBrain()->setIdea(0, "I want food.");
        std::cout << "a: " << a->getBrain()->getIdea(0) << std::endl;
        Cat* b = new Cat(*a);
        std::cout << "b: " << b->getBrain()->getIdea(0) << std::endl;
        a->getBrain()->setIdea(0, "I want more food.");
        std::cout << "a: " << a->getBrain()->getIdea(0) << std::endl;
        std::cout << "b: " << b->getBrain()->getIdea(0) << std::endl;
        a->makeSound();
        b->makeSound();
        delete a;
        delete b;
    }
    // This does not work anymore:
    // Animal *a = new Animal();
    // Animal b;
}
