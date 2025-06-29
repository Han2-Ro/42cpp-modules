#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

#include "SortElem.hpp"
#include "SortNode.hpp"
#include "SortValue.hpp"

extern unsigned int       comparasions_counter;
std::vector<unsigned int> sort_vector(std::vector<unsigned int>& vec);
std::deque<unsigned int> sort_deque(std::deque<unsigned int>& vec);

template <typename Container>
void print_vec(const Container& vec) {
    if (vec.size() == 0) {
        std::cout << "Empty";
    }
    for (typename Container::const_iterator iter = vec.begin(); iter != vec.end(); iter++) {
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

#include "PmergeMe.tpp"
