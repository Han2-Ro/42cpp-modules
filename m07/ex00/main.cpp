#include <iostream>
#include <string>

#include "whatever.hpp"

struct Data {
    int         value;
    std::string str;
};

bool operator<(const Data& lhs, const Data& rhs) {
    return lhs.value < rhs.value;
}

bool operator>(const Data& lhs, const Data& rhs) {
    return lhs.value > rhs.value;
}

int main() {
    {
        int a = 3;
        int b = -7;
        std::cout << "a: " << a << ", b: " << b << std::endl;
        swap(a, b);
        std::cout << "a: " << a << ", b: " << b << std::endl;
    }
    std::cout << std::endl;
    {
        std::string a = "hello";
        std::string b = "world";
        std::cout << "a: " << a << ", b: " << b << std::endl;
        swap(a, b);
        std::cout << "a: " << a << ", b: " << b << std::endl;
    }
    std::cout << std::endl;
    {
        Data a = {1, "hello"};
        Data b = {2, "world"};
        Data min_data = min(a, b);
        std::cout << "min_data: " << min_data.value << ", " << min_data.str << std::endl;
        Data max_data = max(a, b);
        std::cout << "max_data: " << max_data.value << ", " << max_data.str << std::endl;
    }
    std::cout << std::endl;
    {
        Data a = {1, "hello"};
        Data b = {1, "world"};
        Data min_data = min(a, b);
        std::cout << "min_data: " << min_data.value << ", " << min_data.str << std::endl;
        Data max_data = max(a, b);
        std::cout << "max_data: " << max_data.value << ", " << max_data.str << std::endl;
    }
    std::cout << std::endl;
    {
        int a = 42;
        int b = -42;
        std::cout << "min(a, b): " << min(a, b) << std::endl;
        std::cout << "max(a, b): " << max(a, b) << std::endl;
    }
    std::cout << std::endl;
    {
        // subject
        int a = 2;
        int b = 3;
        ::swap(a, b);
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
        std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
        std::string c = "chaine1";
        std::string d = "chaine2";
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
        std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
    }
}