#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>

#include "PmergeMe.hpp"

const std::vector<unsigned int> max_comparisions_bin_insert{
    0, 0, 1, 3, 5, 8, 11, 14, 17, 21, 25, 29, 33, 37, 41, 45, 49, 54,
};
const std::vector<unsigned int> max_comparisions_merge_insert{
    0,   0,   1,   3,   5,   7,   10,  13,  16,  19,  22,  26,  30,  34,  38,  42,  46,  50,  54,  58,  62,
    66,  71,  76,  81,  86,  91,  96,  101, 106, 111, 116, 121, 126, 131, 136, 141, 146, 151, 156, 161, 166,
    171, 177, 183, 189, 195, 201, 207, 213, 219, 225, 231, 237, 243, 249, 255, 261, 267, 273, 279, 285, 291,
    297, 303, 309, 315, 321, 327, 333, 339, 345, 351, 357, 363, 369, 375, 381, 387, 393, 399, 405, 411, 417,
    423, 429, 436, 443, 450, 457, 464, 471, 478, 485, 492, 499, 506, 513, 520, 527, 534,
};

std::vector<unsigned int> random_vec(std::size_t length) {
    std::vector<unsigned int> vec;
    for (unsigned int i = 0; i < length; i++) {
        vec.push_back(i);
    }
    std::random_device rd;
    std::mt19937       g(rd());
    std::shuffle(vec.begin(), vec.end(), g);
    return vec;
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
    {
        std::vector<unsigned int> vec;
        vec.push_back(45);
        vec.push_back(1);
        assert(!is_sorted(vec));
        vec.push_back(100);
        vec.push_back(101);
        assert(!is_sorted(vec));
    }
    std::cout << "Completed " << __func__ << std::endl;
}

void test_sort_vec(std::vector<unsigned int> input) {
    comparasions_counter = 0;
    std::cout << "input: ";
    print_vec(input);
    auto result = sort_merge_insert(input);
    std::cout << "output: ";
    print_vec(result);
    assert(result.size() == input.size());
    assert(is_sorted(result));
    if (input.size() < max_comparisions_merge_insert.size()) {
        std::cout << "comparasions: " << comparasions_counter << "/" << max_comparisions_merge_insert.at(input.size())
                  << std::endl;
        assert(comparasions_counter <= max_comparisions_merge_insert.at(input.size()));
    } else {
        std::cout << "comparasions: " << comparasions_counter << std::endl;
    }
    std::cout << "====== Completed " << __func__ << " length: " << input.size() << " ======" << std::endl;
}

void run_tests() {
    test_is_sorted();
    for (std::size_t i = 0; i < max_comparisions_merge_insert.size(); i++) {
        test_sort_vec(random_vec(i));
    }
    test_sort_vec(random_vec(3000));
    std::cout << "======= Finished Tests ======= " << std::endl;
}

int main() {
    run_tests();
}
