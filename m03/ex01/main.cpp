#include "ScavTrap.hpp"

int main() {
    ScavTrap a("a");
    ScavTrap b("b");
    a.display();
    b.display();
    for (int i = 0; i < 12; i++) {
        a.attack("b");
    }
    a.display();
    for (int i = 0; i < 5; i++) {
        b.takeDamage(4);
    }
    b.display();
    ScavTrap c(b);
    std::cout << "Copy of b:" << std::endl;
    c.display();
    for (int i = 0; i < 12; i++) {
        b.beRepaired(4);
    }
    b.display();
    std::cout << "Copy of b:" << std::endl;
    c.display();
    return 0;
}
