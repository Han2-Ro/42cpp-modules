#include "Harl.hpp"

int main() {
    Harl harl;
    harl.complain("debug");
    harl.complain("INFO");
    harl.complain("warning");
    harl.complain("error");
    harl.complain("invalid");
}
