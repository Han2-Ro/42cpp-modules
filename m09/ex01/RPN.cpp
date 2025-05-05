
#include "RPN.hpp"

#include <iostream>

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

int RPN::calculate(char* str) {
    int newest_number;
    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ') {
            i++;
        }
        if (str[i] >= '0' && str[i] <= '9') {
            values.push(str[i] - '0');
            continue;
        }
        switch (str[i]) {
            case '+':
                values.push(this->real_pop() + this->real_pop());
                break;
            case '-':
                newest_number = this->real_pop();
                values.push(this->real_pop() - newest_number);
                break;
            case '*':
                values.push(this->real_pop() * this->real_pop());
                break;
            case '/':
                newest_number = this->real_pop();
                values.push(this->real_pop() / newest_number);
                break;

            default:
                std::cerr << "Error: bad input: '" << str[i] << "'" << std::endl;
                break;
        }
    }
    if (values.size() != 1) {
        std::cerr << "Error: bad input" << std::endl;
    }
    return (values.top());
}