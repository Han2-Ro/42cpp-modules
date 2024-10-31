#include "Contact.hpp"
#include <ios>
#include <iostream>
#include <iomanip>
#include <string>

Contact::Contact()
{
}

Contact::Contact(std::string first_name, std::string last_name, std::string nickname, std::string number, std::string darkest_sceret)
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

void put_field(std::string label, std::string value)
{
    std::cout << std::right << std::setw(16) << label << value << std::endl;
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
    std::cout << std::setw(10) << trunc(this->first_name)
			<< "|" << std::setw(10) << trunc(this->last_name)
			<< "|" << std::setw(10) << trunc(this->nickname) << std::endl;
}

void Contact::display()
{
    std::cout << std::endl << "----------------------------" << std::endl;
    put_field("First Name: ", this->first_name);
    put_field("Last Name: ", this->last_name);
    put_field("Nickname: ", this->nickname);
    put_field("Phone Number: ", this->phone_number);
    put_field("Darkest Secret: ", this->darkest_secret);
    std::cout << "----------------------------" << std::endl;
}

