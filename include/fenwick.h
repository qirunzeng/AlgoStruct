/**
 * Author: Qirun Zeng
 * Date Created: 2025-02-04 20:33:29
 * Last Modified: 2025-02-09 14:05:50
 * Description:
 */

#ifndef _FENWICK_H_
#define _FENWICK_H_

// #include "vector.h"
#include <vector>
#include <memory>
#include <initializer_list>
#include "myLimits.h"

namespace my {
    template <typename T>
    class fenwick {
    private:
        std::vector<T> nodes;
        std::vector<T> nums;
        size_t size;

        size_t lowbit(size_t size) {
            return size & -size;
        }

        void makeTree() {
            for (size_t i = 1; i <= size; ++i) {
                nodes[i] += nums[i];
                const size_t p = i + lowbit(i);
                if (p <= size) {
                    nodes[p] += nodes[i];
                }
            }
        }

    public:
        fenwick() : size(0) {}

        fenwick(T *arr, const size_t n) : size(n) {
            nodes.resize(n+1);
            nums.resize(n+1);
            nodes[0] = nums[0] = 0;
            for (size_t i = 0; i < n; ++i) {
                nums[i+1] = arr[i];
            }
            makeTree();
        }

        fenwick(std::vector<T> arr) : size(arr.size()) {
            nodes.resize(size+1);
            nums.resize(size+1);
            nodes[0] = nums[0] = 0;
            for (size_t i = 0; i < size; ++i) {
                nums[i+1] = arr[i];
            }
            makeTree();
        }

        fenwick(std::initializer_list<T> arr) : size(arr.size()) {
            nodes.resize(size+1);
            nums.resize(size+1);
            nodes[0] = nums[0] = 0;
            size_t i = 1;
            for (auto it = arr.begin(); it != arr.end(); ++it) {
                nums[i++] = *it;
            }
            makeTree();
        }

        ~fenwick() {}

        // sum(nums[1, n])
        T getSum(size_t n) {
            if (n > size) {
                return -1;
            }
            T ret = 0;
            while (n) {
                ret += nodes[n];
                n &= n-1;
            }
            return ret;
        }

        // sum(nums[l, r])
        int getSum(const size_t l, const size_t r) {
            return getSum(r) - getSum(l-1);
        }

        bool update(size_t pos, const T val) {
            if (pos > size) {
                return false;
            }
            // 判断 T 是不是 double 类型
            if (typeid(T) == typeid(double) || typeid(T) == typeid(float)) {
                const double diff = val - nums[pos];
                nums[pos] = val;
                while (pos <= size) {
                    nodes[pos] += diff;
                    pos += lowbit(pos); // parent node
                }
                return true;
            }
            const int64 diff = val - nums[pos];
            nums[pos] = val;
            while (pos <= size) {
                nodes[pos] += diff;
                pos += lowbit(pos); // parent node
            }
            return true;
        }

        void push_back(const T val) {
            size++;
            nums.push_back(val);
            nodes.push_back(val + getSum((size & size-1) + 1, size - 1));
        }
    };
}

#endif // _FENWICK_H_
