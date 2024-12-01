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
    // from subject
    Fixed       a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;
    std::cout << std::endl;

    // my tests
    Fixed x(42.625f);
    Fixed y = 5;
    y += 1;  // 6
    Fixed z;
    z = x + y;
    std::cout << x << "+" << y << "=" << z << std::endl;
    y -= -4;  // 10
    z = x - y;
    std::cout << x << "-" << y << "=" << z << std::endl;
    x = 3;
    z = x * y;
    std::cout << x << "*" << y << "=" << z << std::endl;
    x *= 4.5f;  // 13.5
    y /= 2;     // 5
    z = x / y;
    std::cout << x << "/" << y << "=" << z << std::endl;

    std::cout << "3 < 4: " << (Fixed(3) < Fixed(4)) << std::endl;
    std::cout << "4 < 4: " << (Fixed(4) < Fixed(4)) << std::endl;
    std::cout << "4 <= 4: " << (Fixed(4) <= Fixed(4)) << std::endl;
    std::cout << "4.1 > 4: " << (Fixed(4.1f) > Fixed(4)) << std::endl;
    std::cout << "4.1 >= 100.123: " << (Fixed(4.1f) >= Fixed(100.123f)) << std::endl;
    std::cout << "3.1 == 3.1: " << (Fixed(3.1f) == Fixed(3.1f)) << std::endl;
    std::cout << "3.1 != 3.1: " << (Fixed(3.1f) != Fixed(3.1f)) << std::endl;
    return 0;
}
