#include "SortValue.hpp"

SortValue::SortValue(unsigned int value) : value(value) {}
// SortValue(const SortElem& other);
// SortElem& operator=(const SortElem& other);
unsigned int SortValue::get_value() const {
    return value;
}
const SortElem* SortValue::get_higher() const {
    return this;
}
const SortElem* SortValue::get_lower() const {
    return this;
}