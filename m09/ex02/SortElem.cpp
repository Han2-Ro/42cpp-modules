#include "SortElem.hpp"

SortElem::SortElem() {}
SortElem::SortElem(const SortElem& other) {
    (void) other;
}
SortElem::~SortElem() {}
SortElem& SortElem::operator=(const SortElem& other) {
    (void) other;
    return *this;
}

bool operator<(const SortElem& l, const SortElem& r) {
    return l.get_value() < r.get_value();
}
