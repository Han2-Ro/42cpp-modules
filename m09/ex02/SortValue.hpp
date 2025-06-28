#pragma once
#include "SortElem.hpp"

class SortValue : public SortElem {
   private:
    const unsigned int value;

   public:
    SortValue(unsigned int value);
    SortValue(const SortValue& other);
    SortValue& operator=(const SortValue& other);
    unsigned int get_value() const;
    const SortElem* get_higher() const;
    const SortElem* get_lower() const;
};