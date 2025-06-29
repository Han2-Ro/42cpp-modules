#include <cstdlib>
#include <iostream>
#include <deque>

#include "PmergeMe.hpp"

template <typename Container>
bool is_sorted(Container vec) {
    for (typename Container::iterator iter = vec.begin(); iter + 1 < vec.end(); iter++) {
        if (*iter > *(iter + 1)) {
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv) {
    std::vector<unsigned int> input;
    for (int i = 1; i < argc; i++) {
        unsigned int n = std::strtoul(argv[i], NULL, 10);
        input.push_back(n);
    }
    std::vector<unsigned int> result = sort_vector(input);
    if (!is_sorted(result)){
        return 1;
    }

    std::deque<unsigned int> dq;
    for (int i = 1; i < argc; i++) {
        unsigned int n = std::strtoul(argv[i], NULL, 10);
        dq.push_back(n);
    }
    dq = sort_deque(dq);
    if (!is_sorted(dq)){
        return 1;
    }
    std::cout << "Before: ";
    print_vec(input);
    std::cout << "After: ";
    print_vec(result);
}