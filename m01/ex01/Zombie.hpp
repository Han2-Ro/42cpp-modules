#pragma once
#include <string>

class Zombie {
    private:
        std::string name;

    public:
        Zombie();
        ~Zombie();

        void announce();
        void setName(std::string& name);
};

