/**
 * Author: Qirun Zeng
 * Date Created: 2025-02-08 22:37:54
 * Last Modified: 2025-02-09 14:06:01
 * Description:
 */


#ifndef MY_IO_H_
#define MY_IO_H_


#include <cstdio>

#include "myLimits.h"

namespace my {
    class myCout {
    public:
        myCout& operator<<(char value) {
            printf("%c", value);
            return *this;
        }

        myCout& operator<<(int value) {
            printf("%d", value);
            return *this;
        }

        myCout& operator<<(int64 value) {
            printf("%lld", value);
            return *this;
        }

        myCout& operator<<(double value) {
            printf("%f", value);
            return *this;
        }

        myCout& operator<<(const char* str) {
            printf("%s", str);
            return *this;
        }

        // do nothing
        myCout& operator<<(const myCout& os) {
            return *this;
        }

        // for my::endl
        myCout& operator<<(myCout& (*manip)(myCout&)) {
            return manip(*this);
        }
    };

    myCout& endl(myCout& os) {
        os << "\n";
        fflush(stdout);
        return os;
    }

    class myCin {
    public:
        myCin& operator>>(char& value) {
            scanf("%c", &value);
            return *this;
        }

        myCin& operator>>(int& value) {
            scanf("%d", &value);
            return *this;
        }


        myCin& operator>>(int64& value) {
            scanf("%lld", &value);
            return *this;
        }

        myCin& operator>>(double& value) {
            scanf("%lf", &value);
            return *this;
        }


        myCin& operator>>(float& value) {
            scanf("%f", &value);
            return *this;
        }

        myCin& operator>>(char* str) {
            scanf("%s", str);
            return *this;
        }
    };

    myCin cin;
    myCout cout;
}


#endif // MY_IO_H_
