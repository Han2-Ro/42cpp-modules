#include <cstdlib>
#include <iostream>
#include <deque>

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    std::vector<unsigned int> vec;
    for (int i = 1; i < argc; i++) {
        unsigned int n = std::strtoul(argv[i], NULL, 10);
        vec.push_back(n);
    }
    std::deque<unsigned int> dq;
    for (int i = 1; i < argc; i++) {
        unsigned int n = std::strtoul(argv[i], NULL, 10);
        dq.push_back(n);
    }
    comparasions_counter = 0;
    print_vec(dq);
    dq = sort_deque(dq);
    print_vec(dq);
    std::cout << "comparisions: " << comparasions_counter << std::endl;
}