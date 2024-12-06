#include "FragTrap.hpp"

int main() {
    FragTrap a("a");
    FragTrap b("b");
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
    FragTrap c(b);
    std::cout << "Copy of b:" << std::endl;
    c.display();
    for (int i = 0; i < 12; i++) {
        b.beRepaired(4);
    }
    b.display();
    std::cout << "Copy of b:" << std::endl;
    c.display();
    a.highFivesGuys();
    ClapTrap d("d");
    d = a;
    std::cout << "ClapTrap copy of a:" << std::endl;
    d.display();
    return 0;
}
