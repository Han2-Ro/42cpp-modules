#include "Point.hpp"

Fixed operator*(const Point& a, const Point& b) {
    return a.getX() * b.getY() - a.getY() * b.getX();
}

Point operator-(Point a, const Point b) {
    return Point(a.getX() - b.getX(), a.getY() - b.getY());
}

bool same_side(const Point& a, const Point& b, const Point& x, const Point& y) {
    return ((b - a) * (x - a)) * ((b - a) * (y - a)) > 0;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    return same_side(a, b, point, c) && same_side(a, c, point, b) && same_side(b, c, point, a);
}
