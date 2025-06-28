#pragma once
#include "SortElem.hpp"

class SortValue : public SortElem {
   private:
    const unsigned int value;

   public:
    SortValue(unsigned int value);
    // SortValue(const SortElem& other);
    // SortElem& operator=(const SortElem& other);
    unsigned int get_value() const;
    const SortElem* get_higher() const;
    const SortElem* get_lower() const;
};