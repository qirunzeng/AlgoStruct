#ifndef _MEMORY_H_
#define _MEMORY_H_

#include <utility.h>

namespace my {
    template <typename T>
    class unique_ptr {
    private:
        T *ptr;

    public:
        unique_ptr() : ptr(nullptr) {}
        
        unique_ptr(T *p) : ptr(p) {}
        
        ~unique_ptr() {
            delete [] ptr;
        }
    };
}


#endif // _MEMORY_H_