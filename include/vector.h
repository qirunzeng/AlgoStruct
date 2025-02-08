#ifndef _VECTOR_H_
#define _VECTOR_H_
#include "structure.h"

#include <iostream>

template <typename T>
class my::vector {
private:
	std::unique_ptr<T[]> data;
	int size;
	int max_size;

	void Init() {
        max_size = size = 0;
        data = nullptr;
    }

	void clear() {
        max_size = size = 0;
    }

	void reserve(int nSize) {
        if (max_size >= nSize)
            return ;
        if (max_size == 0) max_size = 1;
        while (max_size < nSize)
            max_size <<= 1;
        std::unique_ptr<T[]> pTemp(new T[static_cast<size_t>(max_size)]);
        for (int i = 0; i < size; ++i) {
            pTemp[i] = data[i];
        }
        data = move(pTemp);
    }
public:
	vector() {
        Init();
    }
    
	vector(int nSize, const T& dValue) {
        assert(nSize >= 0);
        if (nSize == 0) {
            Init();
        }
        max_size = 1;
        while (max_size < nSize) {
            max_size <<= 1;
        }
        data = new T[max_size];
        size = nSize;
        for (int i = 0; i < size; ++i) {
            data[i] = dValue;
        }
    } 

	vector(const vector& arr) {
        max_size  = arr.max_size;
        size = arr.size;
        data.reset(new T[max_size]);
        for (int i = 0; i < size; ++i) {
            data[i] = arr.data[i];
        }
    }

	~vector() {}

	int size() const {
        return size;
    }

	void set_size(const int nSize) {
        assert(nSize >= 0);
        if (nSize <= max_size) {
            for (int i = size; i < nSize; ++i) {
                data[i] = 0;
            }
            size = nSize;
        }
        else {
            reserve(nSize);
        }
    }

	T& operator[](int nIndex) {
        assert(nIndex >= 0 && nIndex < size);
        return data[nIndex];
    }

	const T& operator[](int nIndex) const {
        assert(nIndex >= 0 && nIndex < size);
        return data[nIndex];
    }

	void push_back(const T& dValue) {
        reserve(size+1);
        data[size++] = dValue;
    }

    void pop_back() {
        size--;
    }

    void shrink_to_fit() {
        if (size == 0) {
            max_size = 0;
            data.reset();
            return ;
        }
        while (max_size >= (size<<1)) {
            max_size >>= 1;
        }
        std::unique_ptr<T[]> pTemp(new T[static_cast<size_t>(max_size)]);
        for (int i = 0; i < size; ++i) {
            pTemp[i] = data[i];
        }
        data = move(pTemp);
    }

    bool empty() {
        return size == 0;
    }

	void delete_at(int nIndex) {
        assert(nIndex >= 0 && nIndex < size);
        size--;
        for (int i = nIndex; i < size; ++i) {
            data[i] = data[i+1];
        }
    }

	void insert(int nIndex, const T& dValue) {
        assert(nIndex >= 0 && nIndex <= size);
        reserve(size+1);
        for (int i = size; i > nIndex; --i) {
            data[i] = data[i-1];
        }
        data[nIndex] = dValue;
    }

	vector& operator = (const vector& arr) {
        if (this == &arr) {
            return *this;
        }
        max_size  = arr.max_size;
        size = arr.size;
        data.reset(new T[max_size]);
        for (int i = 0; i < size; ++i) {
            data[i] = arr.data[i];
        }
        return *this;
    }
};

#endif // _VECTOR_H_