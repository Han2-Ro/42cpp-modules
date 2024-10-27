#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "iostream"

PhoneBook::PhoneBook()
{
    std::cout << "Welcome to your shitty new phonbook!" << std::endl;
}

PhoneBook::~PhoneBook()
{
    this->contacts[0]->~Contact();
}

int PhoneBook::add()
{
    this->contacts[index] = new Contact("john", "johnson", "johnny", "+123456", "I like tailor swift");
    this->contacts[index]->display_short();
    this->contacts[index]->display();
    this->index++;
    return 0;
}

int PhoneBook::search()
{
    std::cout << "Searching..." << std::endl;
    return 0;
}
