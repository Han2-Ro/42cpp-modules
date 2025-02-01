#pragma once

#include <cstddef>

template <typename T, typename F>
void iter(T* arr, size_t size, void (*f)(F&)) {
    for (size_t i = 0; i < size; i++) {
        f(arr[i]);
    }
}