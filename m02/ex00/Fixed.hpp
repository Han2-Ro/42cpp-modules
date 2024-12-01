#pragma once

class Fixed {
   private:
    int              value_;
    static const int decimalPoint_ = 8;

   public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();
    int  getRawBits(void) const;
    void setRawBits(const int raw);
};
