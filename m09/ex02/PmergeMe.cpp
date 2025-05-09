
#include "PmergeMe.hpp"

#include <iostream>

PmergeMe::PmergeMe() {
    std::cout << "PmergeMe: Default constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& other) {
    std::cout << "PmergeMe: Copy constructor called" << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    std::cout << "PmergeMe: Copy assignment operator called" << std::endl;
}

PmergeMe::~PmergeMe() {
    std::cout << "PmergeMe: Destructor called" << std::endl;
}

