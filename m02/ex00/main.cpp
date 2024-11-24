#include <iostream>

#include "Fixed.hpp"

int main() {
    Fixed a;
    Fixed b(a);
    Fixed c;
    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    a.setRawBits(420);
    std::cout << a.getRawBits() << std::endl;
    b = a;
    std::cout << b.getRawBits() << std::endl;
    return 0;
}
