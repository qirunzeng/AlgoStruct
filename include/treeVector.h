/*
 * Author: Qirun Zeng
 * Date Created: 2025-02-04 20:33:29
 * Last Modified: 2025-02-04 20:33:30
 * Description:
 */

#ifndef _TREEVECTOR_H_
#define _TREEVECTOR_H_

#include "myVector.h"


/**
 * 树状数组
 */
class my::treeVector {
private:
    int *sum;
    int *nums;
    int n;

    // return sum(a[1 .. x])
    int getSum(int n) {
        int ret = 0;
        while (n) {
            ret += sum[n];
            n &= n-1;
        }
        return ret;
    }

    void makeTree() {
        for (int i = 1; i <= n; ++i) {
            sum[i] = nums[i-1] + getSum(i-1);
        }
    }

public:
    treeVector() {
        
    }

    treeVector(int *arr, const int n) : n(n) {
        sum  = new int[n+1];
        nums = new int[n+1];
        nums[0] = 0;
        for (int i = 0; i < n; ++i) {
            nums[i+1] = arr[i];
        }
        makeTree();
    }
};


#endif // _TREEVECTOR_H_

