#include "PmergeMe.hpp"

#include <cmath>
#include <algorithm>

unsigned int              comparasions_counter = 0;

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
