#include <iostream>

#include "ClapTrap.hpp"

int main() {
    ClapTrap a("a");
    ClapTrap b("b");
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
    ClapTrap c(b);
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
