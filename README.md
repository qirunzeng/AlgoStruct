## Basic Structures for algorithm

### vector

### fenwick tree
    
> pay attention that `pos, l, r, n` is not the index of the array, which is 1-based. So if you want to use it, you should add 1 to the index. `T` can be `int, short, long long, unsigned int, unsigned short, unsigned long long, float, double` and so on.
    
- [x] range sum query `T getSum(size_t l, size_t r)` or `T getSum(size_t n)`

- [x] point modify `void update(size_t pos, const T val)`

- [x] append new element `void push_back(T val)`

### segment tree

> pay attention that `pos, l, r, n` is not the index of the array, which is 1-based. So if you want to use it, you should add 1 to the index. 

- [x] range sum query `int getSum(size_t l, size_t r)` or `int getSum(size_t n)`

- [x] point modify `void set(size_t pos, const int val)`

- [x] range modify `add(size_t l, size_t r, const int val)` and `mul(size_t l, size_t r, const int val)`