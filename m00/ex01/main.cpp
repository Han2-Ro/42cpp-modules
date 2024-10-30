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
        std::getline(std::cin, line);
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
