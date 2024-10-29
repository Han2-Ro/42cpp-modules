#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <ostream>
#include <string>

PhoneBook::PhoneBook()
{
    this->index = 0;
	this->is_full = false;
    std::cout << "Welcome to your shitty new phonbook!" << std::endl;
}

PhoneBook::~PhoneBook()
{
    std::cout << "Bye!" << std::endl;
}

bool not_empty(std::string str) {
		if (str.length() > 0) {
				return true;
		}
		std::cout << "Field can't be empty" << std::endl;
		return false;
}

std::string get_input(std::string prompt, bool (*validate)(std::string)) {
    std::string input;    
		 
    std::cout << prompt;
	for (int i = 0; i < 3; i++) {
		std::getline(std::cin, input);
		if (validate(input)) {
				return input;
		}
    }
	return NULL;
}

int PhoneBook::add()
{
		std::string first_name = get_input("First Name: ", not_empty);
    this->index++;
    if (this->index >= SIZE) {
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
    return index >= 0 && ((!this->is_full && index < this->index) || (this->is_full && index < 8));
}

