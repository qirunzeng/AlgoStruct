#include "vector.h"
#include "algorithm.h"
#include "treeVector.h"

#include "myio.h"

int main() {
    my::vector<int> v({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    my::treeVector tree(v);
    tree.modify(2, 10); // nums = {1, 10, 3, 4, 5, 6, 7, 8, 9, 10}
    my::cout << tree.getSum(2, 8) << my::endl;
    return 0;
}