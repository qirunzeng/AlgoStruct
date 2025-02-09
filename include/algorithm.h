#ifndef MY_ALGORITHM_H_
#define MY_ALGORITHM_H_

#include "cassert.h"
#include "myLimits.h"

namespace my {
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

    inline int pow(const int base, const int exp, const int mod = _INT_MAX_) {
        my_assert(exp >= 0);
        auto _pow = [&mod] (auto&& self, const int _base, const int _exp) -> int {
            if ((_exp & ~1) == 0) {
                return _exp ? _base : 1;
            }
            const int half = self(self, _base, _exp>>1);
            return static_cast<int> (1LL * half * half * ((_exp&1) ? _base : 1) % mod);
        };
        return _pow(_pow, base, exp);
    }

    inline int64 pow(const int64 base, const int64 exp, const int64 mod = _INT64_MAX_) {
        my_assert(exp >= 0);
        auto _pow = [&mod] (auto&& self, const int64 base, const int64 exp) -> int64 {
            if ((exp & ~1) == 0) {
                return exp ? base : 1;
            }
            const int half = self(self, base, exp>>1);
            return static_cast<int64> (static_cast<__int128_t> (half) * half * ((exp&1) ? base : 1) % mod);
        };
        return _pow(_pow, base, exp);
    }
    
}

#endif // MY_ALGORITHM_H_