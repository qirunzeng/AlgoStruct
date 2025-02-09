## Basic Structures for algorithm

- [ ] vector
- [x] fenwick tree
    - pay attention that `pos, l, r, n` is not the index of the array, which is 1-based. So if you want to use it, you should add 1 to the index.
    - [x] range sum query `int getSum(size_t l, size_t r)` or `int getSum(size_t n)`
    - [x] point add `void add(size_t pos, int val)`
    - [x] point multiply `void multiply(size_t pos, int val)`
    - [x] append new element `void push_back(int val)`