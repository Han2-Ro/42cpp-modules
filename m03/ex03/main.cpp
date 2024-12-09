#include <iostream>

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    {
        DiamondTrap a("a");
        a.display();
        a.whoAmI();
        DiamondTrap b("b");
        b.display();
        b.whoAmI();
        for (int i = 0; i < 12; i++) {
            a.attack("b");
        }
        a.display();
        for (int i = 0; i < 5; i++) {
            b.takeDamage(4);
        }
        b.display();
        DiamondTrap c(b);
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
    }
    {
        std::cout << std::endl << "polymorphism test:" << std::endl;
        ScavTrap  scavTrap("scavy scones");
        ClapTrap* clapTrap = &scavTrap;
        clapTrap->display();
        clapTrap->attack("nobody");
    }
    return 0;
}
