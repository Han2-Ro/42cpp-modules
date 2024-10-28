#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
    int index = 0;
	bool is_full = false;
    bool valid_index(int i);

public:
    PhoneBook();
    ~PhoneBook();
    int add();
    int search();
};

#endif
