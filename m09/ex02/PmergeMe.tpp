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
Container sort_merge_insert_algo(Container& input) {
    if (input.size() <= 1) {
        return input;
    }

    Container pairs;
    for (typename Container::iterator iter = input.begin(); (iter + 1) < input.end(); iter += 2) {
        SortNode* node = new SortNode(*iter, *(iter + 1));
        pairs.push_back(node);
    }

    Container sorted_pairs = sort_merge_insert_algo(pairs);

    Container result;
    for (typename Container::iterator iter = sorted_pairs.begin(); iter < sorted_pairs.end(); iter++) {
        result.push_back((*iter)->get_higher());
    }
    if (input.size() % 2 == 1) {
        sorted_pairs.push_back(input.back());
    }
    result.insert(result.begin(), sorted_pairs.front()->get_lower());
    unsigned long t = 1;
    unsigned long previous_t = 1;
    for (unsigned int k = 2; t <= sorted_pairs.size(); k++) {
        t = std::pow(2, k) - t;
        for (unsigned long i = t; i > previous_t; i--) {
            if (i > sorted_pairs.size()) {
                i = sorted_pairs.size();
            }
            if (i <= previous_t) {
                break;
            }
            // the formulas work for index 1 being the first index so I do -1 here,
            // because vector has 0 as first index
            binary_insert(result, sorted_pairs.at(i - 1)->get_lower(), -1, std::pow(2, k) - 1);
        }
        previous_t = t;
    }
    for (typename Container::iterator iter = pairs.begin(); iter < pairs.end(); iter++) {
        delete *iter;
    }
    return result;
}

template <typename Container>
Container sort_merge_insert(Container& input) {
    Container vec_to_sort;
    for (typename Container::iterator iter = input.begin(); iter != input.end(); iter++) {
        vec_to_sort.push_back(new SortValue(*iter));
    }
    Container sorted_vector = sort_merge_insert_algo(vec_to_sort);
    Container restult;
    for (typename Container::iterator iter = sorted_vector.begin(); iter != sorted_vector.end(); iter++) {
        restult.push_back((*iter)->get_value());
    }
    for (typename Container::iterator iter = vec_to_sort.begin(); iter != vec_to_sort.end(); iter++) {
        delete *iter;
    }
    return restult;
}
