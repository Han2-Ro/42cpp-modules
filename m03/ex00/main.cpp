#include "ClapTrap.hpp"

int main() {
    ClapTrap a("a");
    ClapTrap b("b");
    a.display();
    b.display();
    a.attack("b");
    a.display();
    b.display();
    a.beRepaired(1);
    a.beRepaired(1);
    a.beRepaired(1);
    a.beRepaired(1);
    a.beRepaired(1);
    a.beRepaired(1);
    a.beRepaired(1);
    a.beRepaired(1);
    a.beRepaired(1);
    a.beRepaired(1);
    a.beRepaired(1);
    a.beRepaired(1);
    a.beRepaired(1);
    a.display();
    return 0;
}
