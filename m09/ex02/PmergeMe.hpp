#pragma once
#include <iostream>
#include <vector>

#include "Container.hpp"

extern unsigned int       comparasions_counter;
Container<unsigned int> sort_merge_insert(Container<unsigned int>& vec);

template <typename T>
void print_vec(const Container<T>& vec) {
    if (vec.size() == 0) {
        std::cout << "Empty";
    }
    for (auto iter = vec.begin(); iter != vec.end(); iter++) {
        std::cout << *iter << ",";
    }
    std::cout << std::endl;
}

template <typename T>
void print_vec(const Container<T*>& vec) {
    if (vec.size() == 0) {
        std::cout << "Empty";
    }
    for (auto iter = vec.begin(); iter != vec.end(); iter++) {
        std::cout << **iter << ",";
    }
    std::cout << std::endl;
}
