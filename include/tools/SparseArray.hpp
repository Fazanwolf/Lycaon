#pragma once

#include <vector>

#define DEFAULT_SPARSE_ARRAY_SIZE 1000

template <typename T, size_t N = DEFAULT_SPARSE_ARRAY_SIZE>
class SparseArray {
    public:
        SparseArray() : _array{}
        {
            _array.reserve(N);
        }

        void add(const T &elem)
        {
            if (_array.size() + 1 >= N) return;
            _array.push_back(elem);
        }

        void remove(size_t idx)
        {
            if (idx >= _array.size()) return;
            if (idx != _array.size() - 1) {
                _array[idx] = _array.back();
            }
            _array.pop_back();
        }

        T &operator[](size_t idx)
        {
            return _array[idx];
        }

        const T &operator[](size_t idx) const
        {
            return _array[idx];
        }

        size_t size() const
        {
            return _array.size();
        }

        T begin()
        {
            _array.begin();
        }

        T end()
        {
            _array.end();
        }

        void clear()
        {
            _array.clear();
        }

        const T &operator!=(const SparseArray &other) const
        {
            return _array != other._array;
        }

    private:
        std::vector<T> _array;
};
