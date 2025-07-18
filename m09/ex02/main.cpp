#include <cerrno>
#include <cstdlib>
#include <cstring>
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

template <typename Container>
Container argv_to_container(int argc, char** argv) {
    char* endptr;
    Container result;

    for (int i = 1; i < argc; i++) {
        if (std::strchr(argv[i], '-') != NULL) {
            std::cerr << "Error: negative numbers not allowed: '" << argv[i] << "'" << std::endl;
            throw 1;
        }
        unsigned int n = std::strtoul(argv[i], &endptr, 10);
        if (errno == ERANGE) {
            std::cerr << "Error: number out of range: '" << argv[i] << "'" << std::endl;
            throw 1;
        }
        if (*endptr != '\0' || argv[i][0] == '\0') {
            std::cerr << "Error: failed to convert to unsigned long: '" << argv[i] << "'" << std::endl;
            throw 1;
        }
        result.push_back(n);
    }
    return result;
}

int main(int argc, char** argv) {
    // sort with vector
    std::vector<unsigned int> vec;
    try {
        vec = argv_to_container<std::vector<unsigned int> >(argc, argv);
    }
    catch (int error_code) {
        return (error_code);
    } catch (std::bad_alloc e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::vector<unsigned int> result;
    clock_t                   start_time = clock();
    try {
        result = sort_vector(vec);
    } catch (std::bad_alloc e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    clock_t                   end_time = clock();
    double                    vector_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000000;

    if (!is_sorted(result)) {
        return 1;
    }

    // sort with deque
    std::deque<unsigned int> dq;
    try {
        dq = argv_to_container<std::deque<unsigned int> >(argc, argv);
    }
    catch (int error_code) {
        return (error_code);
    } catch (std::bad_alloc e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    start_time = clock();
    try {
        dq = sort_deque(dq);
    } catch (std::bad_alloc e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    end_time = clock();
    double deque_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000000;

    if (!is_sorted(dq)) {
        return 1;
    }

    // print results
    std::cout << "Before: ";
    print_vec(vec);
    std::cout << "After:  ";
    print_vec(result);

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << std::fixed
              << vector_time << " us" << std::endl;
    std::cout << "Time to process a range of " << vec.size() << " elements with std::deque: " << std::fixed
              << deque_time << " us" << std::endl;
}