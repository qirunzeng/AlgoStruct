#ifndef _UTILITY_H_
#define _UTILITY_H_

namespace my {
    template <typename T>
    T &&move(T &a) {
        return static_cast<T &&>(a);
    }
}

#endif // _UTILITY_H_