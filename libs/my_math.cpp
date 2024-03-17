#include <vector>
#include "my_math.h"
int vec_reduce_sum(const std::vector<int>& arr) {
    int n = arr.size();
    int sum = 0;
    if (n == 1) {
        return arr[0];
    }
    for (auto it : arr) {
        sum += it;
    }
    return sum;
}

