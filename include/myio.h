#ifndef MY_IO_H_
#define MY_IO_H_


#include <cstdio>

namespace my {
    class myCout {
    public:
        myCout& operator<<(const char* str) {
            printf("%s", str);
            return *this;
        }

        myCout& operator<<(int value) {
            printf("%d", value);
            return *this;
        }

        myCout& operator<<(double value) {
            printf("%f", value);
            return *this;
        }

        myCout& operator<<(myCout& (*manip)(myCout&)) {
            return manip(*this);
        }
    };

    myCout& endl(myCout& os) {
        os << "\n";
        return os;
    }


    class myCin {
    public:
        myCin& operator>>(int& value) {
            scanf("%d", &value);
            return *this;
        }

        myCin& operator>>(double& value) {
            scanf("%lf", &value);
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