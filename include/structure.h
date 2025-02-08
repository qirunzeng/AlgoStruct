# ifndef _STRUCTURE_H_
# define _STRUCTURE_H_

#include <cassert>

namespace my {

    #define INT_MAX     0x7fffffff
    #define UINT_MAX    0xffffffffU
    #define INT64_MAX   0x7fffffffffffffffLL
    #define UINT64_MAX  0xffffffffffffffffLL

    template <typename T>
    void swap(T &a, T &b) {
        T temp = a;
        a = b;
        b = temp;
    }

    int myPow(const int base, const int exp, const int mod = INT_MAX) {
        assert(exp >= 0);
        auto _pow = [&mod] (auto&& self, const int base, const int exp) -> int {
            if ((exp & ~1) == 0) {
                return exp ? base : 1;
            }
            const int half = self(self, base, exp>>1);
            return static_cast<int> (1LL * half * half * ((exp&1) ? base : 1) % mod);
        };
        return _pow(_pow, base, exp);
    }

    int64_t myPow(const int64_t base, const int64_t exp, const int64_t mod = INT64_MAX) {
        assert(exp >= 0);
        auto _pow = [&mod] (auto&& self, const int64_t base, const int64_t exp) -> int64_t {
            if ((exp & ~1) == 0) {
                return exp ? base : 1;
            }
            const int half = self(self, base, exp>>1);
            return static_cast<int64_t> (static_cast<__int128_t> (half) * half * ((exp&1) ? base : 1) % mod);
        };
        return _pow(_pow, base, exp);
    }
    
    template <typename T>
    T &&move(T &a) {
        return static_cast<T &&>(a);
    }

    template <typename T1, typename T2>
    struct pair {
        T1 first;
        T2 second;
        pair(T1 &a, T2 &b) : first(a), second(b) {}
    };

    template <typename T>
    class vector;

    class treeVector;
} // namespace my

#endif // _STRUCTURE_H_