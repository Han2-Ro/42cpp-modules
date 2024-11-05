#pragma once
#include <string>

class Zombie {
    private:
        std::string name;

    public:
        Zombie(const std::string& name);
        ~Zombie();

        void announce();
        static Zombie* newZombie(std::string name);
        static void randomChump(std::string name);
};

