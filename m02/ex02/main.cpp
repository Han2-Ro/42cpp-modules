#include <iomanip>
#include <ios>
#include <iostream>
#include <ostream>

#include "Fixed.hpp"

void printBinary(int n) {
    for (int i = 31; i >= 0; i--) {
        std::cout << ((n >> i) & 1);
    }
}

void printBinary(float num) {
    int   intPart = (int)num;
    float fracPart = num - intPart;

    int         i = intPart;
    std::string binary;
    while (i > 0) {
        binary = (char)('0' + (i % 2)) + binary;
        i /= 2;
    }
    std::cout << (binary.empty() ? "0" : binary) << ".";

    for (int i = 0; i < 10 && fracPart > 0; i++) {
        fracPart *= 2;
        std::cout << (int)fracPart;
        fracPart -= (int)fracPart;
    }
}

void compare(float value) {
    Fixed fixed(value);

    std::cout << std::fixed << std::setprecision(5) << "Exp: " << value << std::endl;
    std::cout << "Act: " << fixed.toFloat() << std::endl;
    std::cout << "Exp: ";
    printBinary(value);
    std::cout << std::endl;
    std::cout << "Act: ";
    printBinary(fixed.toFloat());
    std::cout << std::endl;
    std::cout << "ToInt: " << fixed.toInt() << std::endl;
}

int main() {
    // From the subject
    Fixed       a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);
    a = Fixed(1234.4321f);
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    // My own checks
    compare(1);
    compare(1234.4321);
    compare(1.1111);
    compare(42.4242);
    compare(0.00390625);
    compare(1.005859375);
    compare(536870912);
    compare(-4242.42);

    // demonstration of overflow
    short x = short(40000);
    std::cout << x << std::endl;
    return 0;
}
