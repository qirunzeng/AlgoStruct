#include "vector.h"
#include "algorithm.h"
#include "treeVector.h"

#include "myio.h"

#include <iostream>

int main() {
    my::vector<int> v({1, 2, 3, 4, 5, 6, 7});
    v.resize(10);
    my::treeVector tree(v);
    tree.modify(2, 10);
    my::cout << tree.getSum(2, 8) << my::endl;

    my::pair<int, char> p({1, 'a'});
    my::cout << p.first << " " << p.second << my::endl;
    return 0;
}