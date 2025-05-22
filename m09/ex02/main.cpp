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
    0,   0,   1,   3,   5,   7,   10,  13,  16,  19,  22,  26,  30,  34,  38,  42,  46,  50,  54,  58,  62,
    66,  71,  76,  81,  86,  91,  96,  101, 106, 111, 116, 121, 126, 131, 136, 141, 146, 151, 156, 161, 166,
    171, 177, 183, 189, 195, 201, 207, 213, 219, 225, 231, 237, 243, 249, 255, 261, 267, 273, 279, 285, 291,
    297, 303, 309, 315, 321, 327, 333, 339, 345, 351, 357, 363, 369, 375, 381, 387, 393, 399, 405, 411, 417,
    423, 429, 436, 443, 450, 457, 464, 471, 478, 485, 492, 499, 506, 513, 520, 527, 534,
};

class SortElem {
   public:
    virtual unsigned int get_value() const = 0;
    SortElem() {}
    // virtual SortElem& operator=(const SortElem& other) = 0;
    const virtual SortElem* get_higher() const = 0;
    const virtual SortElem* get_lower() const = 0;
};

class SortNode : public SortElem {
   private:
    const SortElem* higher;
    const SortElem* lower;

   public:
    SortNode(const SortElem* a, const SortElem* b) : higher(a), lower(b) {
        comparasions_counter++;
        // std::cout << "comp: " << a->get_value() << ", " << b->get_value() << std::endl;
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
    const SortElem* get_higher() const {
        return this->higher;
    }
    const SortElem* get_lower() const {
        return this->lower;
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
    const SortElem* get_higher() const {
        return this;
    }
    const SortElem* get_lower() const {
        return this;
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
        os << "(" << *(node->get_higher()) << "," << *(node->get_lower()) << ")";
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
void binary_insert(std::vector<const SortElem*>& vec, const SortElem* item, long begin, long end) {
    // std::cout << "Bin Inserting: begin:" << begin << " end: " << end << std::endl;
    if (end > static_cast<long>(vec.size())) {
        end = vec.size();
    }
    std::size_t middle = 0;
    while (end - begin > 1) {
        middle = (begin + end) / 2;
        comparasions_counter++;
        // std::cout << "comp: " << item->get_value() << ", " << vec.at(middle)->get_value() << std::endl;
        if (*item < *vec.at(middle)) {
            end = middle;
        } else {
            begin = middle;
        }
    }
    vec.insert(vec.begin() + end, item);
}

void binary_insert(std::vector<const SortElem*>& vec, const SortElem* item) {
    binary_insert(vec, item, -1, vec.size());
}

std::vector<const SortElem*> sort_merge_insert(std::vector<const SortElem*>& input) {
    // std::cout << "sorting: ";
    // print_vec(input);
    if (input.size() <= 1) {
        return input;
    }

    std::vector<const SortElem*> pairs;
    for (auto iter = input.begin(); (iter + 1) < input.end(); iter += 2) {
        SortNode* node = new SortNode(*iter, *(iter + 1));
        pairs.push_back(node);
    }

    std::vector<const SortElem*> sorted_pairs = sort_merge_insert(pairs);

    std::vector<const SortElem*> result;
    for (auto iter = sorted_pairs.begin(); iter < sorted_pairs.end(); iter++) {
        result.push_back((*iter)->get_higher());
    }
    if (input.size() % 2 == 1) {
        sorted_pairs.push_back(input.back());
    }
    result.insert(result.begin(), sorted_pairs.front()->get_lower());
    unsigned long t = 1;
    unsigned long previous_t = 1;
    // std::cout << "Inserting: ";
    for (unsigned int k = 2; t <= sorted_pairs.size(); k++) {
        t = std::pow(2, k) - t;
        // std::cout << "t:" << t << ", ";
        for (unsigned long i = t; i > previous_t; i--) {
            if (i > sorted_pairs.size()) {
                i = sorted_pairs.size();
            }
            if (i <= previous_t) {
                break;
            }
            // std::cout << i << ", ";
            // the formulas work for index 1 being the first index so I do -1 here, because vector has 0 as first index
            binary_insert(result, sorted_pairs.at(i - 1)->get_lower(), -1, std::pow(2, k) - 1);
        }
        previous_t = t;
    }
    // std::cout << std::endl;
    // std::cout << "result: ";
    // print_vec(result);
    return result;
}

std::vector<unsigned int> sort_merge_insert(std::vector<unsigned int>& vec) {
    std::vector<const SortElem*> sort_vec;
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
    if (length < max_comparisions_merge_insert.size()) {
        std::cout << "comparasions: " << comparasions_counter << "/" << max_comparisions_merge_insert.at(length)
                  << std::endl;
        assert(comparasions_counter <= max_comparisions_merge_insert.at(length));
    } else {
        std::cout << "comparasions: " << comparasions_counter << std::endl;
    }
    std::cout << "====== Completed " << __func__ << " length: " << length << " ======" << std::endl;
}

void run_tests() {
    test_is_sorted();
    // test_binary_insert();
    for (std::size_t i = 0; i < max_comparisions_merge_insert.size(); i++) {
        test_sort_rand_vec(i);
    }
    test_sort_rand_vec(3000);
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