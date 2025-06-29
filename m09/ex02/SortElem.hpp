#pragma once

class SortElem {
   public:
    SortElem();
    SortElem(const SortElem& other);
    virtual ~SortElem();
    virtual SortElem& operator=(const SortElem& other);
    virtual unsigned int get_value() const = 0;
    const virtual SortElem* get_higher() const = 0;
    const virtual SortElem* get_lower() const = 0;
};

bool operator<(const SortElem& l, const SortElem& r);