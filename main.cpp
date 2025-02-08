#include "myVector.h"

int main() {
    my::vector<int> v;
    v.push_back(0);
    v.print();
    std::cout << my::myPow(2, 10) << std::endl;
    return 0;
}