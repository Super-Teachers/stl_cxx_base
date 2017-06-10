#include <gtest/gtest.h>
#include <utility>
#include <thread>
#include <vector>
#include <numeric>
#include <functional>

TEST(async_accumulate_with_function, correct) {
    std::vector<int> values { 100};
    std::iota(values.begin(), values.end(), 0);
    // define std::future, std::async
    int result = 100; // async

    EXPECT_EQ(result, std::accumulate(values.begin(), values.end(), 0));
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
