#pragma once

#include <string>

class WrongAnimal {
   protected:
    std::string type;
    WrongAnimal(const std::string& type);

   public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);
    ~WrongAnimal();
    std::string getType() const;
    void        makeSound() const;
};
