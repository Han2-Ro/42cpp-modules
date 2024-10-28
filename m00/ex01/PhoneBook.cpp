#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <ostream>

PhoneBook::PhoneBook()
{
    std::cout << "Welcome to your shitty new phonbook!" << std::endl;
}

PhoneBook::~PhoneBook()
{
    std::cout << "Bye!" << std::endl;
}

int PhoneBook::add()
{
    this->contacts[index].set_values();
    this->contacts[index].display_short();
    this->contacts[index].display();
    this->index++;
    if (this->index >= 8) {
        this->index = 0;
        this->is_full = true;
    }
    return 0;
}

int PhoneBook::search()
{
    std::cout << "Searching..." << std::endl;
    for (int i = 0; this->valid_index(i); i++)
    {
        std::cout << i << "|";
        this->contacts[i].display_short();
    }
    std::cout << "Index:";
    int index;
    std::cin >> index;
    if (std::cin.fail() || !this->valid_index(index)) {
        std::cin.clear();
        std::cout << "Invalid Index" << std::endl;
        return 1;
    }
    this->contacts[index].display();
    return 0;
}

bool PhoneBook::valid_index(int index) {
    return index >= 0 && (!this->is_full && index < this->index) || (this->is_full && index < 8);
}

