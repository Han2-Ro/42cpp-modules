#include <algorithm>
#include <cassert>
#include <cmath>
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
const std::vector<unsigned int> max_comparisions_merge_insert{
    0,  0,  1,  3,  5,  7,  10, 13, 16, 19, 22, 26,  30,  34,  38,  42,  46,
    50, 54, 58, 62, 66, 71, 76, 81, 86, 91, 91, 101, 106, 111, 116, 121, 126,
};

class SortElem {
   public:
    virtual unsigned int get_value() const = 0;
    SortElem() {}
    // virtual SortElem& operator=(const SortElem& other) = 0;
};

class SortNode : public SortElem {
   public:
    SortElem* higher;
    SortElem* lower;
    SortNode(SortElem* a, SortElem* b) : higher(a), lower(b) {
        comparasions_counter++;
        // std::cout << "a: " << a.get_value() << " b: " << b.get_value();
        // std::cout << " a < b: " << (a.get_value() < b.get_value());
        if (a->get_value() < b->get_value()) {
            lower = a;
            higher = b;
        }
    }
    // SortNode(const SortElem& other);
    // SortElem& operator=(const SortElem& other);
    unsigned int get_value() const {
        return higher->get_value();
    }
};

class SortValue : public SortElem {
    const unsigned int value;

   public:
    SortValue(unsigned int value) : value(value) {}
    // SortValue(const SortElem& other);
    // SortElem& operator=(const SortElem& other);
    unsigned int get_value() const {
        return value;
    }
};

bool operator<(const SortElem& l, const SortElem& r) {
    return l.get_value() < r.get_value();
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& pair) {
    os << "(" << pair.first << ", " << pair.second << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const SortElem& elem) {
    const SortNode* node = dynamic_cast<const SortNode*>(&elem);
    if (node) {
        os << "(" << *(node->higher) << "," << *(node->lower) << ")";
    } else {
        os << elem.get_value();
    }
    return os;
}

template <typename T>
void print_vec(const std::vector<T>& vec) {
    if (vec.size() == 0) {
        std::cout << "Empty";
    }
    for (auto iter = vec.begin(); iter != vec.end(); iter++) {
        std::cout << *iter << ",";
    }
    std::cout << std::endl;
}

template <typename T>
void print_vec(const std::vector<T*>& vec) {
    if (vec.size() == 0) {
        std::cout << "Empty";
    }
    for (auto iter = vec.begin(); iter != vec.end(); iter++) {
        std::cout << **iter << ",";
    }
    std::cout << std::endl;
}

// Begin and end are exclusive
void binary_insert(std::vector<SortElem*>& vec, SortElem* item, std::size_t begin, std::size_t end) {
    // std::cout << "Inserting: " << item->get_value() << std::endl;
    if (end > vec.size()) {
        end = vec.size();
    }
    std::size_t middle = 0;
    while (end - begin > 1) {
        middle = (begin + end) / 2;
        comparasions_counter++;
        if (*item < *vec.at(middle)) {
            end = middle;
        } else {
            begin = middle;
        }
    }
    vec.insert(vec.begin() + end, item);
}

void binary_insert(std::vector<SortElem*>& vec, SortElem* item) {
    binary_insert(vec, item, -1, vec.size());
}

std::vector<SortElem*> sort_merge_insert(std::vector<SortElem*>& input) {
    std::cout << "sorting: ";
    print_vec(input);
    if (input.size() <= 1) {
        return input;
    }

    std::vector<SortElem*> pairs;
    for (auto iter = input.begin(); (iter + 1) < input.end(); iter += 2) {
        SortNode* node = new SortNode(*iter, *(iter + 1));
        pairs.push_back(node);
    }

    const std::vector<SortElem*> sorted_pairs = sort_merge_insert(pairs);

    std::vector<SortElem*> result;
    for (auto iter = sorted_pairs.begin(); iter < sorted_pairs.end(); iter++) {
        result.push_back(dynamic_cast<SortNode*>(*iter)->higher);
    }
    unsigned long t = 1;
    unsigned long previous_t = 0;
    std::cout << "Inserting: ";
    for (unsigned int k = 1; t <= sorted_pairs.size(); k++) {
        t = std::pow(2, k) - t;
        std::cout << "t:" << t << ", ";
        for (unsigned long i = t; i > previous_t; i--) {
            if (i > sorted_pairs.size()) {
                i = sorted_pairs.size();
            }
            if (i <= previous_t) {
                break;
            }
            std::cout << i << ", ";
            binary_insert(result, dynamic_cast<SortNode*>(sorted_pairs.at(i - 1))->lower, -1, std::pow(2, k) - 1);
        }
        previous_t = t;
    }
    if (input.size() % 2 == 1) {
        binary_insert(result, input.back());
    }
    std::cout << std::endl;
    std::cout << "result: ";
    print_vec(result);
    return result;
}

std::vector<unsigned int> sort_merge_insert(std::vector<unsigned int>& vec) {
    std::vector<SortElem*> sort_vec;
    for (unsigned int n : vec) {
        sort_vec.push_back(new SortValue(n));
    }
    sort_vec = sort_merge_insert(sort_vec);
    std::vector<unsigned int> restult;
    for (auto iter = sort_vec.begin(); iter != sort_vec.end(); iter++) {
        restult.push_back((*iter)->get_value());
    }
    return restult;
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

// void test_binary_insert() {
//     std::vector<unsigned int> vec;
//     vec.push_back(45);
//     vec.push_back(832);
//     binary_insert(vec, 400);
//     print_vec(vec);
//     assert(is_sorted(vec));
//     std::cout << "Completed " << __func__ << std::endl;
// }

void test_sort_rand_vec(std::size_t length) {
    comparasions_counter = 0;
    auto rand_vec = random_vec(length);
    std::cout << "input: ";
    print_vec(rand_vec);
    auto result = sort_merge_insert(rand_vec);
    std::cout << "output: ";
    print_vec(result);
    assert(result.size() == length);
    assert(is_sorted(result));
    std::cout << "comparasions: " << comparasions_counter << "/" << max_comparisions_merge_insert.at(length) << std::endl;
    // assert(comparasions_counter <= max_comparisions_merge_insert.at(length));
    std::cout << "Completed " << __func__ << " length: " << length << std::endl;
}

void run_tests() {
    test_is_sorted();
    // test_binary_insert();
    for (std::size_t i = 0; i < max_comparisions_merge_insert.size(); i++) {
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
    vec = sort_merge_insert(vec);
    print_vec(vec);
    std::cout << "comparisions: " << comparasions_counter << std::endl;
}