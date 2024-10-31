#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cctype>
#include <cstdio>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <ostream>
#include <string>
#include <cstdlib>

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
    std::cout << "\033[31m" << "Field can't be empty" << "\033[0m" << std::endl;
    return false;
}

bool validate_phonenbr(std::string str) {
    if (!not_empty(str)) {return false;}
    int ignore = 0;
    if (str[0] == '+')
        ignore = 1;
    else if (str.length() >= 2 && str[0] == '0' && str[1] == '0')
        ignore = 2;
    if (str.length() - ignore < 6) {
        std::cout << "\033[31m" << "Number too short (min 6)" << "\033[0m" << std::endl;
        return false;
    }
    if (str.length() - ignore > 15) {
        std::cout << "\033[31m" << "Number too long (max 15)" << "\033[0m" << std::endl;
        return false;
    }
    std::string::iterator it=str.begin();
    it += ignore;
    for ( ; it!=str.end(); ++it) {
        if (!std::isdigit(*it)) {
            std::cout << "\033[31m" << "Not a digit: " << *it << "\033[0m" << std::endl;
            return false;
        }
    }
    return true;
}

std::string get_input(std::string prompt, bool (*validate)(std::string)) {
    std::string input;    

    for (int i = 2; i >=0; i--) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (std::cin.eof()) {
            std::cin.clear();
            std::clearerr(stdin);
            break;
        }
        if (validate(input)) {
            return input;
        }
        std::cout << "\033[31m" << "You got " << i << " tries left." << "\033[0m" << std::endl;
    }
    std::cout << "\033[31m" << "Canceled" << "\033[0m" << std::endl;
    return "";
}

int PhoneBook::add()
{
    std::string first_name = get_input("First Name: ", not_empty);
    if (first_name.length() == 0) {return 1;}
    std::string last_name = get_input("Last Name: ", not_empty);
    if (last_name.length() == 0) {return 1;}
    std::string nickname = get_input("Nickname: ", not_empty);
    if (nickname.length() == 0) {return 1;}
    std::string phone_number = get_input("Phone Number: ", validate_phonenbr);
    if (phone_number.length() == 0) {return 1;}
    std::string secret = get_input("Darkest Secret: ", not_empty);
    if (secret.length() == 0) {return 1;}
    this->contacts[this->index] = Contact(first_name, last_name, nickname, phone_number, secret);

    this->index++;
    if (this->index >= SIZE) {
        this->index = 0;
        this->is_full = true;
    }
    std::cout << "\033[32m" << "Contact added :)" << "\033[0m" << std::endl;
    return 0;
}

int PhoneBook::search()
{
    if (!this->is_full && this->index == 0) {
        std::cout << "\033[31m" << "There are no contacts yet" << "\033[0m" << std::endl;
        return 1;
    }
    std::cout << std::right << "\033[1m" << std::setw(10) << "Index"
			<< "|" << std::setw(10) << "First Name"
			<< "|" << std::setw(10) << "Last Name"
			<< "|" << std::setw(10) << "Nickname" << "\033[0m" << std::endl;
    for (int i = 0; this->valid_index(i); i++)
    {
        std::cout << std::setw(10) << i << "|";
        this->contacts[i].display_short();
    }
    std::cout << "Select an Index: ";
    int index;
    if (!(std::cin >> index)) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.eof()) {
            std::cin.clear();
            clearerr(stdin);
            std::cout << "\033[31m" << "Canceled" << "\033[0m" << std::endl;
            return 1;
        }
        std::cin.clear();
        std::cout << "\033[31m" << "Not a number" << "\033[0m" << std::endl;
        return 1;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (!this->valid_index(index)) {
        std::cout << "\033[31m" << "Index out of range" << "\033[0m" << std::endl;
        return 1;
    }
    this->contacts[index].display();
    return 0;
}

bool PhoneBook::valid_index(int index) {
    return index >= 0 && ((!this->is_full && index < this->index) || (this->is_full && index < 8));
}

