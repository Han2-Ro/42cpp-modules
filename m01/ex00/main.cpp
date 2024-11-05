#include "Zombie.hpp"

int main() {
    Zombie* zombie = Zombie::newZombie("heap");
    zombie->announce();
    delete zombie;
    Zombie::randomChump("stack");
}

