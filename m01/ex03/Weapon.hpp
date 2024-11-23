#pragma once
#include <string>

class Weapon {
   private:
    std::string type;

   public:
    Weapon(const std::string& type);
    ~Weapon();
    std::string getType();
    void        setType(const std::string& type);
};
