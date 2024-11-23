#include "Harl.hpp"

#include <cctype>
#include <iostream>
#include <string>

Harl::Harl() {
    this->dict["debug"] = &Harl::debug;
    this->dict["info"] = &Harl::info;
    this->dict["warning"] = &Harl::warning;
    this->dict["error"] = &Harl::error;
}

Harl::~Harl() {}

void Harl::debug(void) {
    std::cout
        << "Ain't too happy with how this new computer's running slower than molasses in January."
        << std::endl;
}

void Harl::info(void) {
    std::cout << "I swear on my grandpappy's grave, these machines are deliberately acting up just "
                 "to get under my skin!"
              << std::endl;
}

void Harl::warning(void) {
    std::cout << "If I have to restart this worthless hunk of junk ONE MORE TIME, I'm gonna throw "
                 "it clean through the window!"
              << std::endl;
}

void Harl::error(void) {
    std::cout << "WELL THAT TEARS IT - thirty years I've been working with equipment and I've "
                 "NEVER seen such a useless piece of overpriced garbage that couldn't even manage "
                 "to send ONE SIMPLE EMAIL without crashing!"
              << std::endl;
}

std::string lowercase(std::string& str) {
    for (unsigned int i = 0; i < str.length(); i++) {
        str.at(i) = std::tolower(str.at(i));
    }
    return str;
}

void Harl::complain(std::string level) {
    std::map<std::string, void (Harl::*)()>::iterator it = dict.find(lowercase(level));
    if (it != dict.end()) {
        (this->*it->second)();
    }
}
