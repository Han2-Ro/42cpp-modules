#include "PmergeMe.hpp"

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& pair) {
    os << "(" << pair.first << ", " << pair.second << ")";
    return os;
}

// Begin and end are exclusive
template <typename Container>
void binary_insert(Container& vec, const SortElem* item, long begin, long end) {
    if (end > static_cast<long>(vec.size())) {
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

template <typename Container>
void binary_insert(Container& vec, const SortElem* item) {
    binary_insert(vec, item, -1, vec.size());
}

template <typename Container>
Container sort_merge_insert(Container& input) {
    if (input.size() <= 1) {
        return input;
    }

    Container pairs;
    for (typename Container::iterator iter = input.begin(); (iter + 1) < input.end(); iter += 2) {
        SortNode* node = new SortNode(*iter, *(iter + 1));
        pairs.push_back(node);
    }

    Container sorted_pairs = sort_merge_insert(pairs);

    Container result;
    for (typename Container::iterator iter = sorted_pairs.begin(); iter < sorted_pairs.end(); iter++) {
        result.push_back((*iter)->get_higher());
    }
    Container lower_elems;
    for (typename Container::iterator iter = sorted_pairs.begin(); iter < sorted_pairs.end(); iter++) {
        lower_elems.push_back((*iter)->get_lower());
    }
    if (input.size() % 2 == 1) {
        lower_elems.push_back(input.back());
    }
    result.insert(result.begin(), lower_elems.front());
    unsigned long t = 1;
    unsigned long previous_t = 1;
    for (unsigned int k = 2; t <= lower_elems.size(); k++) {
        t = std::pow(2, k) - t;
        for (unsigned long i = t; i > previous_t; i--) {
            if (i > lower_elems.size()) {
                i = lower_elems.size();
            }
            if (i <= previous_t) {
                break;
            }
            // the formulas work for index 1 being the first index so I do -1 here,
            // because vector has 0 as first index
            binary_insert(result, lower_elems.at(i - 1), -1, std::pow(2, k) - 1);
        }
        previous_t = t;
    }
    for (typename Container::iterator iter = pairs.begin(); iter < pairs.end(); iter++) {
        delete *iter;
    }
    return result;
}
