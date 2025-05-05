#pragma once
#include <stack>
#include <format>
#include <string>

class RPN {
   private:
    std::stack<int> values;
    int real_pop();
    void apply_operator(char operant);

   public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();
    int calculate(char *str);
};

