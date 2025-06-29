#include <cstdlib>
#include <iostream>

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    std::vector<unsigned int> vec;
    for (int i = 1; i < argc; i++) {
        unsigned int n = std::strtoul(argv[i], NULL, 10);
        vec.push_back(n);
    }
    comparasions_counter = 0;
    vec = sort_merge_insert(vec);
    print_vec(vec);
    std::cout << "comparisions: " << comparasions_counter << std::endl;
}