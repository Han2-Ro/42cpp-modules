#include <ostream>

class Fixed {
   private:
    int              data_;
    static const int decimalPoint_ = 8;

   public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();
    int   getRawBits(void) const;
    void  setRawBits(const int raw);
    float toFloat(void) const;
    int   toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
