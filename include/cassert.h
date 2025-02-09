#ifndef _CASSERT_H_
#define _CASSERT_H_


namespace my {
    #define cassert(x) if (!(x)) { \
        printf("Assertion failed at %s:%d\n", __FILE__, __LINE__); \
        exit(1); \
    }
}


#endif // _CASSERT_H_