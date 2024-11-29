#include <iostream>

#include "Point.hpp"

int main() {
    Point p1(1.0f, 2.0f);
    Point p2 = p1;
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
}
