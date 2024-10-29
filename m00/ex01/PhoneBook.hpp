#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "Contact.hpp"

#define SIZE 8

class PhoneBook
{
private:
    Contact contacts[SIZE];
    int index;
	bool is_full;
    bool valid_index(int i);

public:
    PhoneBook();
    ~PhoneBook();
    int add();
    int search();
};

#endif
