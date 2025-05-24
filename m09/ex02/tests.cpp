#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>

#include "DequeContainer.hpp"
#include "PmergeMe.hpp"
#include "VectorContainer.hpp"

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

VectorContainer<unsigned int> random_vec(std::size_t length) {
    VectorContainer<unsigned int> vec;
    for (unsigned int i = 0; i < length; i++) {
        vec.push_back(i);
    }
    std::random_device rd;
    std::mt19937       g(rd());
    std::shuffle(vec.begin(), vec.end(), g);
    return vec;
}

bool is_sorted(VectorContainer<unsigned int> vec) {
    for (auto iter = vec.begin(); iter + 1 < vec.end(); iter++) {
        if (*iter > *(iter + 1)) {
            return false;
        }
    }
    return true;
}

void test_is_sorted() {
    {
        VectorContainer<unsigned int> vec;
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
        VectorContainer<unsigned int> vec;
        vec.push_back(45);
        vec.push_back(1);
        assert(!is_sorted(vec));
        vec.push_back(100);
        vec.push_back(101);
        assert(!is_sorted(vec));
    }
    std::cout << "Completed " << __func__ << std::endl;
}

void test_sort_vec(VectorContainer<unsigned int> input) {
    comparasions_counter = 0;
    std::cout << "input: ";
    if (input.size() < 100) {
        print_vec(input);
    } else {
        std::cout << "length: " << input.size() << std::endl;
    }
    auto result = sort_merge_insert(input);
    std::cout << "output: ";
    if (input.size() < 100) {
        print_vec(result);
    } else {
        std::cout << "length: " << input.size() << std::endl;
    }
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

void test_containers() {
    VectorContainer<int> vec;
    DequeContainer<int>  deq;

    // Test push_back and access
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    deq.push_back(1);
    deq.push_back(2);
    deq.push_back(3);

    // Test at()
    assert(vec.at(0) == 1);
    assert(vec.at(1) == 2);
    assert(vec.at(2) == 3);

    assert(deq.at(0) == 1);
    assert(deq.at(1) == 2);
    assert(deq.at(2) == 3);

    // Test front() and back()
    assert(vec.front() == 1);
    assert(vec.back() == 3);

    assert(deq.front() == 1);
    assert(deq.back() == 3);

    // Test iterators
    int sum_vec = 0;
    for (int* it = vec.begin(); it != vec.end(); ++it) {
        sum_vec += *it;
    }
    assert(sum_vec == 6);

    int sum_deq = 0;
    for (int* it = deq.begin(); it != deq.end(); ++it) {
        sum_deq += *it;
    }
    assert(sum_deq == 6);

    // Test insert
    vec.insert(vec.begin() + 1, 5);
    assert(vec.at(0) == 1);
    assert(vec.at(1) == 5);
    assert(vec.at(2) == 2);
    assert(vec.at(3) == 3);

    deq.insert(deq.begin() + 1, 5);
    assert(deq.at(0) == 1);
    assert(deq.at(1) == 5);
    assert(deq.at(2) == 2);
    assert(deq.at(3) == 3);

    std::cout << "All container tests passed!" << std::endl;
}

void run_tests() {
    test_is_sorted();
    test_containers();
    for (std::size_t i = 0; i < max_comparisions_merge_insert.size(); i++) {
        test_sort_vec(random_vec(i));
    }
    test_sort_vec(random_vec(3000));
    std::cout << "======= Finished Tests ======= " << std::endl;
}

int main() {
    run_tests();
}
