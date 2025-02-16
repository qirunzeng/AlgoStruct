#include "segTree.h"
#include "fenwick.h"

#include <iostream>


int main() {
    my::segTree st({10, 11, 17, 13, 14});

    st.add(1, 3, 1); // 11, 12, 18, 13, 14
    st.mul(2, 4, 2); // 11, 24, 36, 26, 14
    std::cout << st.getSum(1, 3) << std::endl; // 71



    return 0;
}