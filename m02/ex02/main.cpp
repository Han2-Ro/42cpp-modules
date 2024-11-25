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

    // debug
    Fixed x(42.4f);
    Fixed y = 5;
    Fixed z;
    z = x + y;
    std::cout << x << "+" << y << "=" << z << std::endl;
    return 0;
}
