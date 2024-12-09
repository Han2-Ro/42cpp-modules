#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    unsigned int size = 11;
    Animal*      animals[size];
    for (unsigned int i = 0; i < size; i++) {
        animals[i] = i % 2 ? (Animal*)new Dog() : (Animal*)new Cat();
    }
    for (unsigned int i = 0; i < size; i++) {
        animals[i]->makeSound();
    }
    for (unsigned int i = 0; i < size; i++) {
        delete &animals[i];
    }
    std::cout << "-----------------" << std::endl;
}
