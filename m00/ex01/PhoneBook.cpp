#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "iostream"

PhoneBook::PhoneBook()
{
    std::cout << "Welcome to your shitty new phonbook!" << std::endl;
}

PhoneBook::~PhoneBook()
{
}

int PhoneBook::add() {
    this->contacts[index] = new Contact("john", "johnson", "johnny", "+123456", "I like tailor swift");
    this->contacts[index]->display();
    this->index++;
    return 0;
}
