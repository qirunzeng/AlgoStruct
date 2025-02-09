/*
 * Author: Qirun Zeng
 * Date Created: 2025-02-08 22:36:45
 * Last Modified: 2025-02-09 14:05:15
 * Description:
 */


#ifndef MY_UTILITY_H_
#define MY_UTILITY_H_

#include <initializer_list>
#include <forward_list>

namespace my {
    template <typename T1, typename T2>
    struct pair {
        T1 first;
        T2 second;

        pair() : first(T1()), second(T2()) {}

        pair(T1&& a, T2&& b) : first(std::forward<T1>(a)), second(std::forward<T2>(b)) {}

        pair(const T1& a, const T2& b) : first(a), second(b) {}
    };

    template <typename T>
    T &&move(T &a) {
        return static_cast<T &&>(a);
    }
}

#endif // MY_UTILITY_H_
