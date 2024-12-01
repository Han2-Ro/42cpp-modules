#pragma once
#include <ostream>

class Fixed {
   private:
    int              data_;
    static const int BINARY_POINT = 8;

   public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed& other);
    ~Fixed();
    int                 getRawBits(void) const;
    void                setRawBits(const int raw);
    float               toFloat(void) const;
    int                 toInt(void) const;
    Fixed&              operator=(const Fixed& other);
    bool                operator<(const Fixed& other) const;
    bool                operator>(const Fixed& other) const;
    bool                operator<=(const Fixed& other) const;
    bool                operator>=(const Fixed& other) const;
    bool                operator==(const Fixed& other) const;
    bool                operator!=(const Fixed& other) const;
    Fixed&              operator+=(const Fixed& other);
    Fixed               operator+(Fixed other) const;
    Fixed&              operator-=(const Fixed& other);
    Fixed               operator-(Fixed other) const;
    Fixed&              operator*=(const Fixed& other);
    Fixed               operator*(Fixed other) const;
    Fixed&              operator/=(const Fixed& other);
    Fixed               operator/(Fixed other) const;
    Fixed&              operator++();
    Fixed               operator++(int);
    Fixed&              operator--();
    Fixed               operator--(int);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed&       min(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
    static Fixed&       max(Fixed& a, Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
