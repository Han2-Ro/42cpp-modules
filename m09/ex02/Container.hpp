#pragma once

#include <cstddef>

template<typename T>
class Container {
public:
    virtual ~Container() {}
    
    virtual T& at(size_t pos) = 0;
    virtual const T& at(size_t pos) const = 0;
    
    virtual T* begin() = 0;
    virtual const T* begin() const = 0;
    
    virtual T* end() = 0;
    virtual const T* end() const = 0;
    
    virtual T& front() = 0;
    virtual const T& front() const = 0;
    
    virtual T& back() = 0;
    virtual const T& back() const = 0;
    
    virtual void push_back(const T& value) = 0;
    virtual size_t size() const = 0;
    virtual void insert(T* pos, const T& value) = 0;
};
