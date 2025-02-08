#ifndef _MYVECTOR_H_
#define _MYVECTOR_H_
#include "structure.h"
#include <cassert>
#include <iostream>

template <typename T>
class my::vector {
private:
	std::unique_ptr<T[]> m_pData; // the pointer to the array memory
	int m_nSize; // the size of the array
	int m_nMax;

	void Init() {
        m_nMax = m_nSize = 0;
        m_pData = nullptr;
    }

	void Free() {
        m_nMax = m_nSize = 0;
    }

	void reserve(int nSize) {
        if (m_nMax >= nSize)
            return ;
        if (m_nMax == 0) m_nMax = 1;
        while (m_nMax < nSize)
            m_nMax <<= 1;
        std::unique_ptr<T[]> pTemp(new T[static_cast<size_t>(m_nMax)]);
        for (int i = 0; i < m_nSize; ++i) {
            pTemp[i] = m_pData[i];
        }
        m_pData = move(pTemp);
    }
public:
    // default constructor
	vector() {
        Init();
    }
    
    // set an array with default values
	vector(int nSize, const T& dValue) {
        assert(nSize >= 0);
        if (nSize == 0) {
            Init();
        }
        m_nMax = 1;
        while (m_nMax < nSize) {
            m_nMax <<= 1;
        }
        m_pData = new T[m_nMax];
        m_nSize = nSize;
        for (int i = 0; i < m_nSize; ++i) {
            m_pData[i] = dValue;
        }
    } 

    // copy constructor
	vector(const vector& arr) {
        m_nMax  = arr.m_nMax;
        m_nSize = arr.m_nSize;
        m_pData = new T[m_nSize];
        for (int i = 0; i < m_nSize; ++i) {
            m_pData[i] = arr.m_pData[i];
        }
    }   

    // deconstructor
	~vector() {
        Free();
    }

    // print the elements of the array
	void print() const {
        std::cout << "Array: ";
        for (int i = 0; i < m_nSize; ++i) {
            std::cout << m_pData[i] << " ";
        }
        std::cout << std::endl;
    } 

    // get the size of the array
	int get_size() const {
        return m_nSize;
    }

	void set_size(const int nSize) {
        assert(nSize >= 0);
        if (nSize <= m_nMax) {
            for (int i = m_nSize; i < nSize; ++i) {
                m_pData[i] = 0;
            }
            m_nSize = nSize;
        }
        else {
            reserve(nSize);
        }
    }

    // get an element at an index
	const T& get_at(const int nIndex) const {
        assert(nIndex >= 0 && nIndex < m_nSize);
        return m_pData[nIndex];
    } 

	void set_at(int nIndex, const T& dValue) {
        assert(nIndex >= 0 && nIndex < m_nSize);
        m_pData[nIndex] = dValue;
    }

    // overload operator '[]'
	T& operator[](int nIndex) {
        assert(nIndex >= 0 && nIndex < m_nSize);
        return m_pData[nIndex];
    }

	const T& operator[](int nIndex) const {
        assert(nIndex >= 0 && nIndex < m_nSize);
        return m_pData[nIndex];
    }

	void push_back(const T& dValue) {
        reserve(m_nSize+1);
        m_pData[m_nSize++] = dValue;
    }


	void delete_at(int nIndex) {
        assert(nIndex >= 0 && nIndex < m_nSize);
        m_nSize--;
        for (int i = nIndex; i < m_nSize; ++i) {
            m_pData[i] = m_pData[i+1];
        }
    }

	void insert_at(int nIndex, const T& dValue) {
        assert(nIndex >= 0 && nIndex <= m_nSize);
        reserve(m_nSize+1);
        for (int i = m_nSize; i > nIndex; --i) {
            m_pData[i] = m_pData[i-1];
        }
        m_pData[nIndex] = dValue;
    }

	vector& operator = (const vector& arr) {
        if (this == &arr) {
            return *this;
        }
        Free();
        m_nMax  = arr.m_nMax;
        m_nSize = arr.m_nSize;
        m_pData = new T[m_nMax];
        for (int i = 0; i < m_nSize; ++i) {
            m_pData[i] = arr.m_pData[i];
        }
        return *this;
    }

};

#endif // _MYVECTOR_H_