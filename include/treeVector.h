/*
 * Author: Qirun Zeng
 * Date Created: 2025-02-04 20:33:29
 * Last Modified: 2025-02-09 14:05:50
 * Description:
 */

#ifndef _TREEVECTOR_H_
#define _TREEVECTOR_H_

#include "vector.h"
#include <memory>

/**
 * 树状数组
 */
namespace my {

    class treeVector {
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

        // 返回 x 的最后一位 1
        size_t lowbit(size_t size) {
            return size & -size;
        }

    public:

        treeVector() : size(0) {}

        treeVector(int *arr, const size_t n) : size(n) {
            nodes.resize(n+1);
            nums.resize(n+1);
            nodes[0] = nums[0] = 0;
            for (size_t i = 0; i < n; ++i) {
                nums[i+1] = arr[i];
            }
            makeTree();
        }

        treeVector(vector<int> arr) : size(arr.size()) {
            nodes.resize(size+1);
            nums.resize(size+1);
            nodes[0] = nums[0] = 0;
            for (size_t i = 0; i < size; ++i) {
                nums[i+1] = arr[i];
            }
            makeTree();
        }

        /*
         * 查询前 n 个元素的和
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
         * 查询区间 [l, r] 的和
         */
        int getSum(const size_t l, const size_t r) {
            return getSum(r) - getSum(l-1);
        }


        bool modify(size_t pos, const int val) {
            // idx++;
            if (pos > size) {
                return false;
            }
            int diff = val - nums[pos];
            nums[pos] = val;
            while (pos <= size) {
                nodes[pos] += diff;
                pos += lowbit(pos); // 找父节点
            }
            return true;
        }
    }; // class treeVector
} // namespace my

#endif // _TREEVECTOR_H_
