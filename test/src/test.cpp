#include "gtest/gtest.h"
#include <vector>
#include "my_math.h"

TEST(MyMathTest, vector_sum) {
    std::vector<int> arr = {2, 4, 6, 8, 10};
    ASSERT_EQ(vec_reduce_sum(arr), 30);
}
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}