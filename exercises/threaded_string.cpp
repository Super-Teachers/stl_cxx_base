
#include <gtest/gtest.h>
#include <thread>
#include <utility>

// std::thread fun(const std::vector<std::string>& str, [> std::function <]) {
std::thread fun(const std::vector<std::string>& str) { return std::thread{}; }

TEST(test, threaded_str) {
    std::size_t result = 0;
    auto t = fun({{""}});
    ASSERT_TRUE(t.joinable());

    t.join();
}

TEST(Accumulator, two) {}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
