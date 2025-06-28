#pragma once
#include "SortElem.hpp"

class SortNode : public SortElem {
   private:
    const SortElem* higher;
    const SortElem* lower;

   public:
    SortNode(const SortElem* a, const SortElem* b);
    // SortNode(const SortElem& other);
    // SortElem& operator=(const SortElem& other);
    unsigned int get_value() const;
    const SortElem* get_higher() const;
    const SortElem* get_lower() const;
};
