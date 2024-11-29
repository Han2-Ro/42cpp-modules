#include <iostream>

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
    Point p1(1.0f, 2.0f);
    Point p2(4.0f, 4.0f);
    Point p3(1.0f, 5.0f);
    Point p4(1.0f, 5.0f);

    std::cout << "Triangle: " << p1 << p2 << p3 << std::endl;
    std::cout << p4 << " is inside: " << bsp(p1, p2, p3, p4) << std::endl;
}
