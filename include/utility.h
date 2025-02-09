/*
 * Author: Qirun Zeng
 * Date Created: 2025-02-08 22:36:45
 * Last Modified: 2025-02-09 14:05:15
 * Description:
 */


#ifndef MY_UTILITY_H_
#define MY_UTILITY_H_

namespace my {

    template <typename T>
    T &&move(T &a) {
        return static_cast<T &&>(a);
    }
}

#endif // MY_UTILITY_H_
