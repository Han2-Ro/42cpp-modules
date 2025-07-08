#include <iostream>
#include <exception>

#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: expected exactly one argument. Hint: use quotes" << std::endl;
        return 1;
    }
    RPN rpn;
    try {
        std::cout << rpn.calculate(argv[1]) << std::endl;
    } catch (const int e) {
        return e;
    } catch (std::bad_alloc e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}