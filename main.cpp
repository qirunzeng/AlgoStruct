#include "vector.h"
#include "algorithm.h"
#include "fenwick.h"
#include "myio.h"

#include <iostream>

int main() {
    my::vector<int> v({1, 2, 3, 4, 5});
    my::fenwick fw(v);
    fw.push_back(6);
    my::cout << fw.getSum(6) << my::endl;

    my::pair<int, char> p({1, 'a'});
    my::cout << p.first << " " << p.second << my::endl;
    return 0;
}