/**
 * Author: Qirun Zeng
 * Date Created: 2025-02-09 14:03:34
 * Last Modified: 2025-02-09 14:05:03
 * Description:
 */

#ifndef _SEGTREE_H_ 
#define _SEGTREE_H_

#include <vector>

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

    std::vector<node> nodes;
    std::vector<int> nums;
    size_t size;

    void makeTree(size_t l, size_t r, size_t p) {
        if (l == r) {
            nodes[p] = {nums[l], 1, 0};
            return ;
        }
        size_t mid = l + ((r-l)>>1);
        makeTree(l, mid, p<<1);
        makeTree(mid+1, r, p<<1|1);
        nodes[p] = {nodes[p<<1].num + nodes[p<<1|1].num, 1, 0};
    }

    int getSum(size_t l, size_t r, size_t p, size_t L, size_t R) {
        if (l <= L && r >= R) {
            return nodes[p].num;
        }
        int mid = L + ((R-L)>>1);
        size_t res = 0;

        nodes[p<<1].num = nodes[p<<1].num * nodes[p].mul + nodes[p].add * (mid-L+1);
        nodes[p<<1|1].num = nodes[p<<1|1].num * nodes[p].mul + nodes[p].add * (R-mid);
        nodes[p<<1].mul *= nodes[p].mul;
        nodes[p<<1|1].mul *= nodes[p].mul;
        nodes[p<<1].add = nodes[p<<1].add * nodes[p].mul + nodes[p].add;
        nodes[p<<1|1].add = nodes[p<<1|1].add * nodes[p].mul + nodes[p].add;
        nodes[p].mul = 1;
        nodes[p].add = 0;

        if (l <= mid) {
            res += getSum(l, r, p<<1, L, mid);
        }
        if (r > mid) {
            res += getSum(l, r, p<<1|1, mid+1, R);
        }
        return res;
    }

    void add(size_t l, size_t r, const int incr, size_t p, size_t L, size_t R) {
        if (l <= L && r >= R) {
            nodes[p].num += incr * (R-L+1);
            nodes[p].add += incr;
            return ;
        }
        int mid = L + ((R-L)>>1);
        nodes[p<<1].num = nodes[p<<1].num * nodes[p].mul + nodes[p].add * (mid-L+1);
        nodes[p<<1|1].num = nodes[p<<1|1].num * nodes[p].mul + nodes[p].add * (R-mid);
        nodes[p<<1].mul *= nodes[p].mul;
        nodes[p<<1|1].mul *= nodes[p].mul;
        nodes[p<<1].add = nodes[p<<1].add * nodes[p].mul + nodes[p].add;
        nodes[p<<1|1].add = nodes[p<<1|1].add * nodes[p].mul + nodes[p].add;
        nodes[p].mul = 1;
        nodes[p].add = 0;

        if (l <= mid) {
            add(l, r, incr, p<<1, L, mid);
        }
        if (r > mid) {
            add(l, r, incr, p<<1|1, mid+1, R);
        }
        nodes[p].num = nodes[p<<1].num + nodes[p<<1|1].num;
    }

    void mul(size_t l, size_t r, const int times, size_t p, size_t L, size_t R) {
        if (l <= L && r >= R) {
            nodes[p].num *= times;
            nodes[p].mul *= times;
            nodes[p].add *= times;
            return ;
        }
        int mid = L + ((R-L)>>1);
        nodes[p<<1].num = nodes[p<<1].num * nodes[p].mul + nodes[p].add * (mid-L+1);
        nodes[p<<1|1].num = nodes[p<<1|1].num * nodes[p].mul + nodes[p].add * (R-mid);
        nodes[p<<1].mul *= nodes[p].mul;
        nodes[p<<1|1].mul *= nodes[p].mul;
        nodes[p<<1].add = nodes[p<<1].add * nodes[p].mul + nodes[p].add;
        nodes[p<<1|1].add = nodes[p<<1|1].add * nodes[p].mul + nodes[p].add;
        nodes[p].mul = 1;
        nodes[p].add = 0;

        if (l <= mid) {
            mul(l, r, times, p<<1, L, mid);
        }
        if (r > mid) {
            mul(l, r, times, p<<1|1, mid+1, R);
        }
        nodes[p].num = nodes[p<<1].num + nodes[p<<1|1].num;
    }

    public:
        segTree() : size(0) {}

        segTree(int *arr, size_t n) : size(n) {
            nodes.resize(n<<2);
            nums.resize(n+1);
            for (int i = 0; i < n; ++i) {
                nums[i+1] = arr[i];
            }
            makeTree(1, n, 1);
        }

        segTree(std::vector<int> arr) : size(arr.size()) {
            nodes.resize(size<<2);
            nums.resize(size+1);
            for (int i = 0; i < size; ++i) {
                nums[i+1] = arr[i];
            }
            makeTree(1, size, 1);
        }

        int getSum(size_t l, size_t r) {
            return getSum(l, r, 1, 1, size);
        }

        void add(size_t l, size_t r, const int incr) {
            add(l, r, incr, 1, 1, size);
        }

        void mul(size_t l, size_t r, const int times) {
            mul(l, r, times, 1, 1, size);
        }

        void set(size_t pos, const int val) {
            add(pos, pos, val - nums[pos]);
        }
    };
}

#endif // _SEGTREE_H_