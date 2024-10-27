#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

Contact::Contact()
{
}

Contact::Contact(char *first_name, char *last_name, char *nickname, char *number, char *darkest_sceret)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->nickname = nickname;
    this->phone_number = number;
    this->darkest_secret = darkest_sceret;
}

Contact::~Contact()
{
}

void put_field(char *label, char *value)
{
    std::cout << std::left << std::setw(16) << label << value << "." << std::endl;
}

std::string trunc(std::string str)
{
    if (str.length() > 10)
    {
        return (str.substr(0, 9) + ".");
    }
    return str;
}

void Contact::display_short() {
    std::cout << trunc(this->first_name) << "|" << trunc(this->last_name) << "|" << trunc(this->nickname) << std::endl;
}

void Contact::display()
{
    put_field("First Name:", this->first_name);
    put_field("Last Name:", this->last_name);
    put_field("Nickname:", this->nickname);
    put_field("Phone Number ☎️:", this->phone_number);
    put_field("Darkest Secret:", this->darkest_secret);
}
