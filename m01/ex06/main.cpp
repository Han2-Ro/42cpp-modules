#include <iostream>
#include <map>
#include <string>

#include "Harl.hpp"

int main(int argc, char *argv[]) {
    Harl        harl;
    std::string str_level;

    if (argc != 2) {
        std::cerr << "Expected exactly one argument. Got " << argc - 1 << std::endl;
        return 1;
    }
    str_level = argv[1];
    lowercase(str_level);

    std::map<std::string, int> levels;
    levels["debug"] = 0;
    levels["info"] = 1;
    levels["warning"] = 2;
    levels["error"] = 3;

    switch (levels.find(str_level) != levels.end() ? levels[str_level] : -1) {
        case 0:
            std::cout << "[ DEBUG ]" << std::endl;
            harl.complain("debug");
            std::cout << std::endl;
        case 1:
            std::cout << "[ INFO ]" << std::endl;
            harl.complain("info");
            std::cout << std::endl;
        case 2:
            std::cout << "[ WARNING ]" << std::endl;
            harl.complain("warning");
            std::cout << std::endl;
        case 3:
            std::cout << "[ ERROR ]" << std::endl;
            harl.complain("error");
            std::cout << std::endl;
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
