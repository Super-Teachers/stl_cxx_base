#include <gtest/gtest.h>
#include <functional>
#include <numeric>
#include <thread>
#include <utility>
#include <vector>

void test_fn(const std::vector<int>& v, const std::function<void(int)>& cb) {
    cb(std::accumulate(v.begin(), v.end(), 0));
}

TEST(threaded_accumulate_with_function, correct) {
    int result = 0;

    std::function<void(int)> fn{[&result](int v) { result = v; }};
    std::vector<int> values{100};
    std::iota(values.begin(), values.end(), 0);
    std::thread t{test_fn, values, fn};

    t.join();
    EXPECT_EQ(result, std::accumulate(values.begin(), values.end(), 0));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
