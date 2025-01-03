#pragma once
#include "Fixed.hpp"

class Point {
   private:
    const Fixed x;
    const Fixed y;

   public:
    Point();
    Point(const float x, const float y);
    Point(const Fixed x, const Fixed y);
    Point(const Point& other);
    Point& operator=(const Point& other);
    ~Point();
    Fixed getX() const;
    Fixed getY() const;
};

std::ostream& operator<<(std::ostream& os, const Point& point);
