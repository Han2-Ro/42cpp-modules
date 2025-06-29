#include <cstdlib>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>

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

    clock_t                   start_time = clock();
    std::vector<unsigned int> result = sort_vector(input);
    clock_t                   end_time = clock();
    double                    vector_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000000;

    if (!is_sorted(result)) {
        return 1;
    }

    std::deque<unsigned int> dq;
    for (int i = 1; i < argc; i++) {
        unsigned int n = std::strtoul(argv[i], NULL, 10);
        dq.push_back(n);
    }

    start_time = clock();
    dq = sort_deque(dq);
    end_time = clock();
    double deque_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000000;

    if (!is_sorted(dq)) {
        return 1;
    }

    std::cout << "Before: ";
    print_vec(input);
    std::cout << "After: ";
    print_vec(result);

    std::cout << "Time to process a range of " << input.size() << " elements with std::vector : " << std::fixed
              << vector_time << " us" << std::endl;
    std::cout << "Time to process a range of " << input.size() << " elements with std::deque : " << std::fixed
              << deque_time << " us" << std::endl;
}