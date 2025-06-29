#pragma once
#include <iostream>
#include <vector>

#include "SortElem.hpp"
#include "SortNode.hpp"
#include "SortValue.hpp"

extern unsigned int       comparasions_counter;
std::vector<unsigned int> sort_merge_insert(std::vector<unsigned int>& vec);

template <typename T>
void print_vec(const std::vector<T>& vec) {
    if (vec.size() == 0) {
        std::cout << "Empty";
    }
    for (typename std::vector<T>::const_iterator iter = vec.begin(); iter != vec.end(); iter++) {
        std::cout << *iter << ",";
    }
    std::cout << std::endl;
}

template <typename T>
void print_vec(const std::vector<T*>& vec) {
    if (vec.size() == 0) {
        std::cout << "Empty";
    }
    for (typename std::vector<T*>::const_iterator iter = vec.begin(); iter != vec.end(); iter++) {
        std::cout << **iter << ",";
    }
    std::cout << std::endl;
}
