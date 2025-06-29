#include "PmergeMe.hpp"

unsigned int comparasions_counter = 0;

std::vector<unsigned int> sort_merge_insert(std::vector<unsigned int>& input) {
    std::vector<const SortElem*> vec_to_sort;
    for (std::vector<unsigned int>::iterator iter = input.begin(); iter != input.end(); iter++) {
        vec_to_sort.push_back(new SortValue(*iter));
    }
    std::vector<const SortElem*> sorted_vector = sort_merge_insert_algo(vec_to_sort);
    std::vector<unsigned int>    restult;
    for (std::vector<const SortElem*>::iterator iter = sorted_vector.begin(); iter != sorted_vector.end(); iter++) {
        restult.push_back((*iter)->get_value());
    }
    for (std::vector<const SortElem*>::iterator iter = vec_to_sort.begin(); iter != vec_to_sort.end(); iter++) {
        delete *iter;
    }
    return restult;
}