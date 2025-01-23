#include <iostream>
#include <string>

#include "whatever.hpp"

int main() {
    {
        int a = 3;
        int b = -7;
        std::cout << "a: " << a << ", b: " << b << std::endl;
        swap(a, b);
        std::cout << "a: " << a << ", b: " << b << std::endl;
    }
    {
        std::string a = "hello";
        std::string b = "world";
        std::cout << "a: " << a << ", b: " << b << std::endl;
        swap(a, b);
        std::cout << "a: " << a << ", b: " << b << std::endl;
    }
}