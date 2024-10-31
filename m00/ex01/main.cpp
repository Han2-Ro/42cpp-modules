#include "PhoneBook.hpp"
#include <string>
#include <iostream>

int main()
{
    PhoneBook phonebook;
    std::string line;
    while (line != "EXIT" && !std::cin.eof())
    {
		std::cin.clear();
        std::cout << "Type ADD, SEARCH or EXIT:" << std::endl;
        std::getline(std::cin, line);
        std::cout << "\033[2J\033[1;1H";
        if (line == "ADD")
        {
            phonebook.add();
            std::cout << std::endl;
        }
        else if (line == "SEARCH")
        {
            phonebook.search();
            std::cout << std::endl;
        }
    }
    return 0;
}

