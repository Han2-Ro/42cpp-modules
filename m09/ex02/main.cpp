#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <random>
#include <utility>
#include <vector>

#include "PmergeMe.hpp"
unsigned int                    comparasions_counter = 0;
const std::vector<unsigned int> max_comparisions_bin_insert{
    0, 0, 1, 3, 5, 8, 11, 14, 17, 21, 25, 29, 33, 37, 41, 45, 49, 54,
};

class SortElem {
   public:
    virtual unsigned int get_value() const = 0;
    SortElem() {}
    virtual SortElem& operator=(const SortElem& other) = 0;
};

class SortNode : SortElem {
   public:
    SortElem& higher;
    SortElem& lower;
    SortNode(SortElem& a, SortElem& b): higher(a), lower(b) {
        comparasions_counter++;
        if (a.get_value() < b.get_value()) {
            lower = a;
            higher = b;
        }
    }
    SortNode(const SortElem& other);
    SortElem& operator=(const SortElem& other);
    unsigned int get_value() const {
        return higher.get_value();
    }
};

class SortValue : SortElem {
    const unsigned int value;

   public:
    SortValue(unsigned int value) : value(value) {}
    SortValue(const SortElem& other);
    SortElem& operator=(const SortElem& other);
    unsigned int get_value() const {
        return value;
    }
};

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& pair) {
    os << "(" << pair.first << ", " << pair.second << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const SortElem& elem) {
    os << elem.get_value();
}

template <typename T>
void print_vec(const std::vector<T>& vec) {
    std::cout << "length: " << vec.size() << std::endl;
    for (auto iter = vec.begin(); iter != vec.end(); iter++) {
        std::cout << *iter << ",";
    }
    std::cout << std::endl;
}

void binary_insert(std::vector<unsigned int>& vec, unsigned int n) {
    // exclusive
    std::size_t begin = -1;
    // exclusive
    std::size_t end = vec.size();
    std::size_t middle = 0;
    while (end - begin > 1) {
        middle = (begin + end) / 2;
        comparasions_counter++;
        if (n < vec.at(middle)) {
            end = middle;
        } else {
            begin = middle;
        }
    }
    vec.insert(vec.begin() + end, n);
}

std::vector<unsigned int> sort_bin_insert(std::vector<unsigned int> vec) {
    std::vector<unsigned int> result;
    for (std::size_t i = 0; i < vec.size(); i++) {
        binary_insert(result, vec.at(i));
    }
    return result;
}

std::vector<SortElem> sort_merge_insert(const std::vector<SortElem>& vec) {
    std::vector<SortElem> splitted_vec;
    for (auto iter = vec.begin(); (iter + 1) < vec.end(); iter += 2) {
        std::pair<unsigned int, sort_elem> pair;
        if (*iter < *(iter + 1)) {
            pair.first = *(iter + 1).;
            pair.second = *(iter + 1);
        }
        pair.first = *iter;
        pair.second = *(iter + 1);
        comparasions_counter++;
        if (pair.first < pair.second) {
            std::swap(pair.first, pair.second);
        }
        splitted_vec.push_back(pair);
    }
    print_vec(splitted_vec);
    if (splitted_vec.size() > 1) {
        sort_merge_insert(splitted_vec);
    }
    return vec;
}

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

void test_binary_insert() {
    std::vector<unsigned int> vec;
    vec.push_back(45);
    vec.push_back(832);
    binary_insert(vec, 400);
    print_vec(vec);
    assert(is_sorted(vec));
    std::cout << "Completed " << __func__ << std::endl;
}

void test_sort_rand_vec(std::size_t length) {
    comparasions_counter = 0;
    auto rand_vec = random_vec(length);
    // std::cout << "input: ";
    // print_vec(rand_vec);
    auto result = sort_bin_insert(rand_vec);
    // std::cout << "output: ";
    // print_vec(result);
    assert(is_sorted(result));
    // std::cout << "comparasions: " << comparasions_counter << "/" << max_comparisions_bin_insert.at(length) <<
    // std::endl;
    assert(comparasions_counter <= max_comparisions_bin_insert.at(length));
    std::cout << "Completed " << __func__ << " length: " << length << std::endl;
}

void run_tests() {
    test_is_sorted();
    test_binary_insert();
    for (std::size_t i = 0; i < max_comparisions_bin_insert.size(); i++) {
        test_sort_rand_vec(i);
        test_sort_rand_vec(i);
    }
    std::cout << "======= Finished Tests ======= " << std::endl;
}

int main(int argc, char** argv) {
    run_tests();
    std::vector<unsigned int> vec;
    for (int i = 1; i < argc; i++) {
        unsigned int n = std::strtoul(argv[i], nullptr, 10);
        vec.push_back(n);
    }
    comparasions_counter = 0;
    sort_merge_insert(vec);
    print_vec(vec);
    std::cout << "comparisions: " << comparasions_counter << std::endl;
}