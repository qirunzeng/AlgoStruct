#ifndef MY_UTILITY_H_
#define MY_UTILITY_H_

namespace my {
    template <typename T>
    T &&move(T &a) {
        return static_cast<T &&>(a);
    }
}

#endif // MY_UTILITY_H_