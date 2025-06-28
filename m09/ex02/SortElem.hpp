#pragma once

class SortElem {
   public:
    virtual unsigned int get_value() const = 0;
    SortElem() {}
    virtual ~SortElem() {}
    // virtual SortElem& operator=(const SortElem& other) = 0;
    const virtual SortElem* get_higher() const = 0;
    const virtual SortElem* get_lower() const = 0;
};
