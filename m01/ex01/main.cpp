#include "Zombie.hpp"
#include "zombieHord.hpp"

#define SIZE 5

int main() {
    Zombie* horde =  zombieHorde(SIZE, "horde member");
    for (int i = 0; i < SIZE; i++) {
        horde[i].announce();
    }
    delete[] horde;
}

