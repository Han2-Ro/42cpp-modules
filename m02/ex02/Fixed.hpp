#include <ostream>

class Fixed {
   private:
    int              data_;
    static const int DECIMAL_PLACES = 8;

   public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed& other);
    ~Fixed();
    int    getRawBits(void) const;
    void   setRawBits(const int raw);
    float  toFloat(void) const;
    int    toInt(void) const;
    Fixed& operator=(const Fixed& other);
    bool   operator<(const Fixed& other) const;
    bool   operator>(const Fixed& other) const;
    bool   operator<=(const Fixed& other) const;
    bool   operator>=(const Fixed& other) const;
    bool   operator==(const Fixed& other) const;
    bool   operator!=(const Fixed& other) const;
    Fixed& operator+=(const Fixed& other);
    Fixed  operator+(Fixed other) const;
    Fixed& operator-=(const Fixed& other);
    Fixed  operator-(Fixed other) const;
    Fixed& operator*=(const Fixed& other);
    Fixed  operator*(Fixed other) const;
    Fixed  operator/(Fixed other) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
