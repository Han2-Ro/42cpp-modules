#pragma once
#include <stack>

class RPN {
   private:
    std::stack<int> values;
    int real_pop();

   public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();
    int calculate(char *str);
};

