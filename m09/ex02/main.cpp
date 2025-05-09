#include <cassert>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "PmergeMe.hpp"

void binary_insert(std::vector<unsigned int>& vec, unsigned int n) {
    std::size_t begin = 0;
    std::size_t end = vec.size();
    std::size_t middle = 0;
    int comparasions_counter = 0;
    while (end - begin > 1) {
        middle = (begin + end) / 2;
        comparasions_counter++;
        if (n < vec.at(middle)) {
            end = middle;
        } else {
            begin = middle;
        }
    }
    comparasions_counter++;
    if (vec.size() == 0 || n < vec.at(begin)) {
        vec.insert(vec.begin() + begin, n);
    } else {
        vec.insert(vec.begin() + end, n);
    }
    std::cout << comparasions_counter << std::endl;
}

void print_vec(std::vector<unsigned int>& vec) {
    for (auto iter = vec.begin(); iter != vec.end(); iter++) {
        std::cout << *iter << ",";
    }
    std::cout << std::endl;
}

bool is_sorted(std::vector<unsigned int> vec) {
    for (auto iter = vec.begin(); iter + 1 < vec.end(); iter++) {
        if (*iter > *(iter + 1)) {
            return false;
        }
    }
    return true;
}

void test_is_sorted() {
    {
        std::vector<unsigned int> vec;
        assert(is_sorted(vec));
        vec.push_back(45);
        assert(is_sorted(vec));
        vec.push_back(100);
        assert(is_sorted(vec));
        vec.push_back(101);
        vec.push_back(101);
        assert(is_sorted(vec));
        vec.push_back(1);
        assert(!is_sorted(vec));
    }
    { std::vector<unsigned int> vec; 
        vec.push_back(45);
        vec.push_back(1);
        assert(!is_sorted(vec));
        vec.push_back(100);
        vec.push_back(101);
        assert(!is_sorted(vec));
    }
    std::cout << "Completed " << __func__ << std::endl;
}

void test_binary_insert() {
    std::vector<unsigned int> vec;
    vec.push_back(45);
    vec.push_back(832);
    binary_insert(vec, 400);
    print_vec(vec);
    assert(is_sorted(vec));
    std::cout << "Completed " << __func__ << std::endl;
}

void run_tests() {
    test_is_sorted();
    test_binary_insert();
    std::cout << "======= Finished Tests ======= " << std::endl;
}

int main(int argc, char** argv) {
    run_tests();
    std::vector<unsigned int> vec;
    for (int i = 1; i < argc; i++) {
        unsigned int n = std::strtoul(argv[i], nullptr, 10);
        binary_insert(vec, n);
        print_vec(vec);
    }
}