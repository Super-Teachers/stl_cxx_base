#include <gtest/gtest.h>
#include <functional>
#include <numeric>
#include <thread>
#include <utility>
#include <vector>
#include <future>

int fun_async(const std::vector<int>& v) {
    std::this_thread::sleep_for(std::chrono::seconds(4));
    return std::accumulate(v.begin(), v.end(), 0);
}

TEST(async_accumulate_with_function, correct) {
    std::vector<int> values{100};
    std::iota(values.begin(), values.end(), 0);
    // define std::future, std::async
    auto f = std::async(std::launch::async, fun_async, values);
    EXPECT_EQ(f.get(), std::accumulate(values.begin(), values.end(), 0));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
