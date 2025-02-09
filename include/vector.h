/*
 * Author: Qirun Zeng
 * Date Created: 2025-02-04 21:36:45
 * Last Modified: 2025-02-09 14:06:44
 * Description:
 */


#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "cassert.h"
// #include "algorithm.h"
#include "utility.h"
#include <memory>     // for std::unique_ptr
#include <initializer_list>

namespace my {
    template <typename T>
    class vector {
    private:
        std::unique_ptr<T[]> data;
        size_t cur_size;
        size_t max_size;

        void Init() {
            max_size = cur_size = 0;
            data = nullptr;
        }

        void clear() {}

        void reserve(size_t n) {
            if (max_size >= n) {
                return ;
            }
            if (max_size == 0) {
                max_size = 1;
            }
            while (max_size < n) {
                max_size <<= 1;
            }
            std::unique_ptr<T[]> temp(new T[static_cast<size_t>(max_size)]);
            for (size_t i = 0; i < cur_size; ++i) {
                temp[i] = data[i];
            }
            data = move(temp);
        }
    public:
        vector() {
            Init();
        }

        vector(size_t n, const T& val) {
            // my_assert(n >= 0);
            if (n == 0) {
                Init();
            }
            max_size = 1;
            while (max_size < n) {
                max_size <<= 1;
            }
            data = new T[max_size];
            cur_size = n;
            for (size_t i = 0; i < cur_size; ++i) {
                data[i] = val;
            }
        }

        vector(const vector& arr) {
            max_size  = arr.max_size;
            cur_size = arr.size();
            data.reset(new T[max_size]);
            for (size_t i = 0; i < cur_size; ++i) {
                data[i] = arr.data[i];
            }
        }

        vector(std::initializer_list<T> list) {
            max_size = cur_size = list.size();
            data.reset(new T[max_size]);
            size_t i = 0;
            for (auto &val : list) {
                data[i++] = val;
            }
        }

        ~vector() {}

        size_t size() const {
            return cur_size;
        }

        T& operator[](size_t idx) {
            my_assert(idx < cur_size);
            return data[idx];
        }

        const T& operator[](size_t idx) const {
            my_assert(idx < cur_size);
            return data[idx];
        }

        void push_back(const T& val) {
            reserve(cur_size+1);
            data[cur_size++] = val;
        }

        void pop_back() {
            cur_size--;
        }

        void shrink_to_fit() {
            if (cur_size == 0) {
                max_size = 0;
                data.reset();
                return ;
            }
            while (max_size >= (cur_size<<1)) {
                max_size >>= 1;
            }
            std::unique_ptr<T[]> pTemp(new T[static_cast<size_t>(max_size)]);
            for (size_t i = 0; i < cur_size; ++i) {
                pTemp[i] = data[i];
            }
            data = move(pTemp);
        }

        bool empty() {
            return cur_size == 0;
        }

        void delete_at(size_t idx) {
            my_assert(idx < cur_size);
            cur_size--;
            for (size_t i = idx; i < cur_size; ++i) {
                data[i] = data[i+1];
            }
        }

        void insert(size_t idx, const T& val) {
            my_assert(idx <= cur_size);
            reserve(cur_size+1);
            for (size_t i = cur_size; i > idx; --i) {
                data[i] = data[i-1];
            }
            data[idx] = val;
        }

        vector& operator = (const vector& arr) {
            if (this == &arr) {
                return *this;
            }
            max_size = arr.max_size;
            cur_size = arr.size;
            data.reset(new T[max_size]);
            for (size_t i = 0; i < cur_size; ++i) {
                data[i] = arr.data[i];
            }
            return *this;
        }

        void resize(size_t n, int val = 0) {
            reserve(n);
            while (cur_size < n) {
                data[cur_size++] = val;
            }
        }
    };
}

#endif // _VECTOR_H_
