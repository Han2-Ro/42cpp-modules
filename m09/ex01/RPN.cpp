
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

void RPN::apply_operator(char symbol) {
    int newest_number;
    if (values.size() < 2) {
        std::cerr << "Error: bad inputS: '" << symbol << "'" << std::endl;
        throw 1;
    }
    switch (symbol) {
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