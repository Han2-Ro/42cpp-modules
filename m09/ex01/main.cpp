#include <iostream>

#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        return 1;
    }
    RPN rpn;
    try {
        std::cout << rpn.calculate(argv[1]) << std::endl;
    } catch (const int e) {
        return e;
    }
}