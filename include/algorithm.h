#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include "cassert.h"

namespace my {

    #define _INT_MAX_     0x7fffffff
    #define _UINT_MAX_    0xffffffffU
    #define _INT64_MAX_   0x7fffffffffffffffLL
    #define _UINT64_MAX_  0xffffffffffffffffLL

    template <typename T>
    void swap(T &a, T &b) {
        T temp = a;
        a = b;
        b = temp;
    }


    template <typename T1, typename T2>
    struct pair {
        T1 first;
        T2 second;
        pair(T1 &a, T2 &b) : first(a), second(b) {}
    };

    int pow(const int base, const int exp, const int mod = _INT_MAX_) {
        cassert(exp >= 0);
        auto _pow = [&mod] (auto&& self, const int base, const int exp) -> int {
            if ((exp & ~1) == 0) {
                return exp ? base : 1;
            }
            const int half = self(self, base, exp>>1);
            return static_cast<int> (1LL * half * half * ((exp&1) ? base : 1) % mod);
        };
        return _pow(_pow, base, exp);
    }

    int64_t pow(const int64_t base, const int64_t exp, const int64_t mod = _INT64_MAX_) {
        cassert(exp >= 0);
        auto _pow = [&mod] (auto&& self, const int64_t base, const int64_t exp) -> int64_t {
            if ((exp & ~1) == 0) {
                return exp ? base : 1;
            }
            const int half = self(self, base, exp>>1);
            return static_cast<int64_t> (static_cast<__int128_t> (half) * half * ((exp&1) ? base : 1) % mod);
        };
        return _pow(_pow, base, exp);
    }
    
}

#endif // _ALGORITHM_H_