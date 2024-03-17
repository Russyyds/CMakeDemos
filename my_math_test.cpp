#include <vector>
#include <fmt/ranges.h>
#ifdef MY_MATH
#include "my_math.h"
#else
#include <numeric>
#endif

int main() {
    std::vector<int> arr = {1, 3, 5, 7, 9};
#ifdef MY_MATH
    int sum = vec_reduce_sum(arr);
    fmt::print("Using my_math lib.\n");
#else
    int sum = std::accumulate(arr.begin(), arr.end(), 0);
    fmt::print("Using STL lib.\n");
#endif
    fmt::print("arr:{}\n", arr);
    fmt::print("sum:{}\n", sum);
    return 0;
}
