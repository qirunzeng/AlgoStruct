/**
 * Author: Qirun Zeng
 * Date Created: 2025-02-09 14:03:34
 * Last Modified: 2025-02-09 14:05:03
 * Description:
 */


#ifndef _SEGTREE_H_ 
#define _SEGTREE_H_

#include "vector.h"

namespace my {
    class segTree {
    private:

    struct node {
        int num;
        int mul;
        int add;

        node() : num(0), mul(1), add(0) {}

        node(int n, int m, int a) : num(n), mul(m), add(a) {}
    };

    vector<node> nodes;
    vector<int> nums;
    size_t size;

    void makeTree(int l, int r, int p) {
        if (l == r) {
            nodes[p] = {nums[l], 0, 0};
            return ;
        }
        int mid = l + ((r-l)>>1);
        makeTree(l, mid, p<<1);
        makeTree(mid+1, r, p<<1|1);
        nodes[p] = {nodes[p<<1].num + nodes[p<<1|1].num, 0, 0};
    }

    public:
        segTree() : size(0) {}

        segTree(int *arr, int n) : size(n) {
            nodes.resize(n<<2);
            nums.resize(n+1);
            for (int i = 0; i < n; ++i) {
                nums[i+1] = arr[i];
            }
            makeTree(1, n, 1);
        }

        segTree(vector<int> arr) : size(arr.size()) {
            nodes.resize(size<<2);
            nums.resize(size+1);
            for (int i = 0; i < size; ++i) {
                nums[i+1] = arr[i];
            }
            makeTree(1, size, 1);
        }
    };
}


#endif // _SEGTREE_H_
