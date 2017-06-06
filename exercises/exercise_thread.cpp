#include <gtest/gtest.h>
#include <utility>
#include <thread>
#include <vector>
#include <numeric>

TEST(threaded_accumulate, correct) {
    int result = 0;
    std::vector<int> values { 100};
    std::iota(values.begin(), values.end(), 0);
    std::thread t { /* .. accumulate_function */ };

    t.join();
    EXPECT_EQ(result, std::accumulate(values.begin(), values.end(), 0));
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
