#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    {
        // example from subject
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        std::cout << meta->getType() << " " << std::endl;
        i->makeSound();  // will output the cat sound!
        j->makeSound();
        meta->makeSound();
        delete meta;
        delete j;
        delete i;
    }
    std::cout << "----------------" << std::endl;
    {
        // example with WrongAnimal
        const WrongCat*    wrongCat = new WrongCat();
        const WrongAnimal* wrongAnimal = wrongCat;
        std::cout << wrongAnimal->getType() << " " << std::endl;
        wrongCat->makeSound();
        wrongAnimal->makeSound();  // won't output the cat sound!
        delete wrongCat;
    }
    return 0;
}
