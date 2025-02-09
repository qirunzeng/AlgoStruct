/*
 * Author: Qirun Zeng
 * Date Created: 2025-02-08 22:37:15
 * Last Modified: 2025-02-09 14:06:11
 * Description:
 */


#ifndef MY_ASSERT_H_
#define MY_ASSERT_H_

// #include <exception>

namespace my {

    #define my_assert(x) if (!(x)) { \
        throw("Assertion failed at %s:%d\n", __FILE__, __LINE__); \
        exit(1); \
    }
}


#endif // MY_ASSERT_H_
