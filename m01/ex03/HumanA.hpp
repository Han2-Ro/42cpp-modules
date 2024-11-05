#pragma once
#include <string>
#include "Weapon.hpp"

class HumanA {
    private:
        std::string name;
        Weapon weapon;
    public:
        HumanA(Weapon& weapon);
        ~HumanA();
        void attack();
};
