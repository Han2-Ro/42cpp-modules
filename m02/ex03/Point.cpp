#include "Point.hpp"

Point::Point() : x(0), y(0) {
    // std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {
    // std::cout << "Copy constructor called" << std::endl;
}

Point::~Point() {
    // std::cout << "Destructor called" << std::endl;
};

/*
Point& Point::operator=(const Point& other) {
    // std::cout << "Copy assignment operator called" << std::endl;
    this = &Point(other);
    return *this;
}
*/

Fixed Point::getX() const {
    return x;
}

Fixed Point::getY() const {
    return y;
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.getX() << ", " << point.getY() << ")";
    return os;
}
