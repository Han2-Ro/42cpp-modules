#include "SortNode.hpp"
#include "PmergeMe.hpp"

SortNode::SortNode(const SortElem* a, const SortElem* b) : higher(a), lower(b) {
    comparasions_counter++;
    // std::cout << "comp: " << a->get_value() << ", " << b->get_value() << std::endl;
    if (a->get_value() < b->get_value()) {
        lower = a;
        higher = b;
    }
}
SortNode::SortNode(const SortNode& other): higher(other.higher), lower(other.lower) {}
SortNode& SortNode::operator=(const SortNode& other) {
    (void) other;
    return *this;
}
unsigned int SortNode::get_value() const {
    return higher->get_value();
}
const SortElem* SortNode::get_higher() const {
    return this->higher;
}
const SortElem* SortNode::get_lower() const {
    return this->lower;
}
