#pragma once

#include <iostream>
#include <vector>
#include <cstddef>
#include <bitset>


struct MyPool {
    const size_t object_size;
    std::vector<std::byte> data;
    std::vector<bool> used_map;
    static inline size_t max_pos = static_cast<size_t>(SIZE_MAX);

    MyPool(const size_t object_size, const size_t object_count)
            : object_size(object_size), data(object_size * object_count), used_map(object_count) {
    }

    size_t find_first_empty_space(size_t n) {
        size_t right_t = 0;
        size_t len = 0;
        if (n > used_map.size()) throw std::bad_alloc();
        while (right_t < used_map.size()) {
            if (!used_map[right_t]) {
                ++right_t;
                ++len;
            } else {
                ++right_t;
                len = 0;
            }
            if (len == n) {
                return right_t - n;
            }
        }

        throw std::bad_alloc();
    }

    void *allocate(size_t n) {
        size_t free_pos = find_first_empty_space(n);
        if (free_pos != max_pos) {
            for (size_t i = free_pos; i < free_pos + n; ++i) {
                used_map[i] = true;
            }
            return &data[free_pos * object_size];
        }
        throw std::bad_alloc();
    }

    void deallocate(const void *pointer, size_t n) {
        const auto *byte_ptr = static_cast<const std::byte *>(pointer);
        const std::byte *begin_ptr = &data[0];
        if ((byte_ptr - begin_ptr) % object_size != 0) throw std::logic_error("Invalid pointer");
        const size_t clean_index = (byte_ptr - begin_ptr) / object_size;
        if (clean_index + n - 1 < used_map.size()) {
            for (size_t i = clean_index; i < clean_index + n; ++i) {
                used_map[i] = false;
            }
        }
    }

    ~MyPool() {
    }
};
