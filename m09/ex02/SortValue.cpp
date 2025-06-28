#include "SortValue.hpp"

SortValue::SortValue(unsigned int value) : value(value) {}
SortValue::SortValue(const SortValue& other) : value(other.value) {}
SortValue& SortValue::operator=(const SortValue& other) {
    (void) other;
    return *this;
}
unsigned int SortValue::get_value() const {
    return value;
}
const SortElem* SortValue::get_higher() const {
    return this;
}
const SortElem* SortValue::get_lower() const {
    return this;
}