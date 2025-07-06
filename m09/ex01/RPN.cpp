#include "RPN.hpp"

#include <iostream>
#include <limits>

RPN::RPN() {}

RPN::RPN(const RPN& other) {
    *this = other;
}

RPN& RPN::operator=(const RPN& other) {
    this->values = other.values;
    return *this;
}

RPN::~RPN() {}

int RPN::real_pop() {
    int result = values.top();
    values.pop();
    return result;
}

void RPN::apply_operator(char symbol) {
    if (values.size() < 2) {
        std::cerr << "Error: bad input: '" << symbol << "'" << std::endl;
        throw 1;
    }
    switch (symbol) {
        case '+': {
            int b = this->real_pop();
            int a = this->real_pop();
            if ((b > 0 && a > std::numeric_limits<int>::max() - b) ||
                (b < 0 && a < std::numeric_limits<int>::min() - b)) {
                std::cerr << "Error: integer overflow in addition" << std::endl;
                throw 1;
            }
            values.push(a + b);
        } break;
        case '-': {
            int b = this->real_pop();
            int a = this->real_pop();
            if ((b < 0 && a > std::numeric_limits<int>::max() + b) ||
                (b > 0 && a < std::numeric_limits<int>::min() + b)) {
                std::cerr << "Error: integer overflow in subtraction" << std::endl;
                throw 1;
            }
            values.push(a - b);
        } break;
        case '*': {
            int b = this->real_pop();
            int a = this->real_pop();
            int product = a * b;
            if (a != 0 && product / a != b) {
                std::cerr << "Error: integer overflow in multiplication" << std::endl;
                throw 1;
            }
            values.push(product);
        } break;
        case '/': {
            int b = this->real_pop();
            if (b == 0) {
                std::cerr << "Error: division by zero" << std::endl;
                throw 1;
            }
            int a = this->real_pop();
            if (a == std::numeric_limits<int>::min() && b == -1) {
                std::cerr << "Error: integer overflow in division" << std::endl;
                throw 1;
            }
            values.push(a / b);
        } break;

        default:
            std::cerr << "Error: bad input: '" << symbol << "'" << std::endl;
            throw 1;
            break;
    }
}

int RPN::calculate(char* str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ') {
            continue;
        }
        if (str[i] >= '0' && str[i] <= '9') {
            values.push(str[i] - '0');
        } else {
            this->apply_operator(str[i]);
        }
    }
    if (values.size() != 1) {
        std::cerr << "Error: unporcessed values left without operators" << std::endl;
        throw 1;
    }
    return (values.top());
}