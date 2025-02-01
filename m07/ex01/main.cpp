#include <iostream>

#include "iter.hpp"

void print(const int& num) {
    std::cout << num << std::endl;
}

void add_one(int& num) {
    num += 1;
}

void double_num(int& num) {
    num *= 2;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    iter(arr, 5, print);
    iter(arr, 5, add_one);
    std::cout << std::endl;
    iter(arr, 5, print);
    iter(arr, 5, double_num);
    std::cout << std::endl;
    iter(arr, 5, print);
    return 0;
}