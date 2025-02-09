/**
 * Author: Qirun Zeng
 * Date Created: 2025-02-04 20:33:29
 * Last Modified: 2025-02-09 14:05:50
 * Description:
 */

#ifndef _FENWICK_H_
#define _FENWICK_H_

#include "vector.h"
#include <memory>
#include <initializer_list>

namespace my {

    class fenwick {
    private:
        vector<int> nodes;
        vector<int> nums;
        size_t size;

        void makeTree() {
            std::unique_ptr<int[]> prefix(new int[size+1]);
            prefix[0] = 0;
            for (int i = 1; i <= size; ++i) {
                prefix[i] = prefix[i-1] + nums[i];
            }
            for (int i = 1; i <= size; ++i) {
                nodes[i] = prefix[i] - prefix[i & (i-1)];
            }
        }

        // return the lowest bit of size
        size_t lowbit(size_t size) {
            return size & -size;
        }

    public:

        fenwick() : size(0) {}

        fenwick(int *arr, const size_t n) : size(n) {
            nodes.resize(n+1);
            nums.resize(n+1);
            nodes[0] = nums[0] = 0;
            for (size_t i = 0; i < n; ++i) {
                nums[i+1] = arr[i];
            }
            makeTree();
        }

        fenwick(vector<int> arr) : size(arr.size()) {
            nodes.resize(size+1);
            nums.resize(size+1);
            nodes[0] = nums[0] = 0;
            for (size_t i = 0; i < size; ++i) {
                nums[i+1] = arr[i];
            }
            makeTree();
        }

        fenwick(std::initializer_list<int> arr) : size(arr.size()) {
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

        /*
         * return: sum(nums[1, n])
         */ 
        int getSum(size_t n) {
            if (n > size) {
                return -1;
            }
            int ret = 0;
            while (n) {
                ret += nodes[n];
                n &= n-1;
            }
            return ret;
        }

        /*
         * return sum(nums[l, r])
         */
        int getSum(const size_t l, const size_t r) {
            return getSum(r) - getSum(l-1);
        }


        bool add(size_t pos, const int val) {
            if (pos > size) {
                return false;
            }
            const int diff = val - nums[pos];
            nums[pos] = val;
            while (pos <= size) {
                nodes[pos] += diff;
                pos += lowbit(pos); // parent node
            }
            return true;
        }

        bool multiply(size_t pos, const int val) {
            if (pos > size) {
                return false;
            }
            const int diff = nums[pos] * val - nums[pos];
            nums[pos] *= val;
            while (pos <= size) {
                nodes[pos] += diff;
                pos += lowbit(pos);
            }
            return true;
        }

        void push_back(const int val) {
            size++;
            nums.push_back(val);
            nodes.push_back(val + getSum((size & size-1) + 1, size - 1));
        }
    }; // class fenwick

} // namespace my

#endif // _FENWICK_H_
