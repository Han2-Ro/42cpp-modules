#include "Harl.hpp"
#include <iostream>
#include <string>

Harl::Harl() {
    std::cout << "dict init" << std::endl;
    this->dict["debug"] = &Harl::debug;
    this->dict["info"] = &Harl::info;
    this->dict["warning"] = &Harl::warning;
    this->dict["error"] = &Harl::error;
}

Harl::~Harl() {}

void Harl::debug(void) {
    std::cout << "DEbuggG" << std::endl;
}

void Harl::info(void) {
    std::cout << "InnffoO" << std::endl;
}

void Harl::warning(void) {
    std::cout << "Warninggg" << std::endl;
}

void Harl::error(void) {
    std::cout << "ErRorr" << std::endl;
}

void Harl::complain(std::string level) {
    (this->*dict.at(level))();
}

