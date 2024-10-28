#include "PhoneBook.hpp"
#include <string>
#include <iostream>

int main()
{
    PhoneBook phonebook;
    std::string line;
    while (true)
    {
        std::cout << "Type Command:" << std::endl;
        std::getline(std::cin, line);
        if (line == "ADD")
        {
            phonebook.add();
        }
        else if (line == "SEARCH")
        {
            phonebook.search();
        }
        else if (line == "EXIT")
        {
            break;
        }
    }
    return 0;
}
