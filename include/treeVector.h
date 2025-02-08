/*
 * Author: Qirun Zeng
 * Date Created: 2025-02-04 20:33:29
 * Last Modified: 2025-02-04 20:33:30
 * Description:
 */

#ifndef _TREEVECTOR_H_
#define _TREEVECTOR_H_

/**
 * 树状数组
 */
namespace my {
    class treeVector {
    private:
        int *sums;
        int *nums;
        int  size;

        // return sums(a[1 .. x])
        int getSum(int n) {
            int ret = 0;
            while (n) {
                ret += sums[n];
                n &= n-1;
            }
            return ret;
        }

        void makeTree() {
            for (int i = 1; i <= size; ++i) {
                sums[i] = nums[i-1] + getSum(i-1);
            }
        }

    public:
        treeVector() : size(0) {}

        treeVector(int *arr, const int n) : size(n) {
            sums  = new int[n+1];
            nums = new int[n+1];
            sums[0] = nums[0] = 0;
            for (int i = 0; i < n; ++i) {
                nums[i+1] = arr[i];
            }
            makeTree();
        }
    };
}

#endif // _TREEVECTOR_H_
