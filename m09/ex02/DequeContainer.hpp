#pragma once

#include "Container.hpp"
#include <deque>

template<typename T>
class DequeContainer : public Container<T> {
private:
    std::deque<T> data;

public:
    DequeContainer() {}
    virtual ~DequeContainer() {}

    T& at(size_t pos) override { return data.at(pos); }
    const T& at(size_t pos) const override { return data.at(pos); }

    T* begin() override { return &data[0]; }
    const T* begin() const override { return &data[0]; }

    T* end() override { return &data[0] + data.size(); }
    const T* end() const override { return &data[0] + data.size(); }

    T& front() override { return data.front(); }
    const T& front() const override { return data.front(); }

    T& back() override { return data.back(); }
    const T& back() const override { return data.back(); }

    void push_back(const T& value) override { data.push_back(value); }
    size_t size() const override { return data.size(); }
    void insert(T* pos, const T& value) override { 
        data.insert(data.begin() + (pos - begin()), value);
    }
};
