#include "PhoneBook.hpp"
#include <string>
#include <iostream>

int main()
{
    PhoneBook phonebook;
    std::string line;
    while (line != "EXIT" /*&& !std::cin.eof()*/)
    {
		std::cin.clear();
        std::getline(std::cin, line);
        if (line == "ADD")
        {
            phonebook.add();
        }
        else if (line == "SEARCH")
        {
            phonebook.search();
        }
        if (std::cin.eof()) {
            std::cout << "eof in main" << std::endl;
            std::cin.clear();
        }
    }
    return 0;
}
