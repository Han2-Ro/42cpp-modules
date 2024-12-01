#include <iostream>

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

void test(Point const a, Point const b, Point const c, Point const point) {
    std::cout << "Triangle: " << a << b << c << std::endl;
    std::cout << point << " is inside: " << bsp(a, b, c, point) << std::endl << std::endl;
}

int main() {
    Point p1(1.0f, 2.0f);
    Point p2(4.0f, 4.0f);
    Point p3(1.0f, 5.0f);
    test(p1, p2, p3, Point(1.0f, 1.5f));
    test(p1, p2, p3, Point(1.0f, 4.0f));
    test(p1, p2, p3, Point(1.01f, 4.0f));
    test(p1, p2, p3, Point(1.8f, 3.8f));
    test(p1, p2, p3, Point(3.0f, 2.9f));
}
