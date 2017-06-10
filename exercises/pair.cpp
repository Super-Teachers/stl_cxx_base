#include <gtest/gtest.h>
#include <utility>

namespace my_std {
std::pair<int, bool> atoi(const std::string& a) {
    auto val = std::atoi(a.c_str());

    if (val == 0 && a == "0") return std::make_pair(val, true);
    return std::make_pair(val, val == 0 ? false : true);
}
}

TEST(atoi, incorrect_atoi) {
    auto result = my_std::atoi("not a number");
    EXPECT_FALSE(result.second);
}

TEST(atoi, correct_atoi) {
    std::pair<int, bool> result = my_std::atoi("10");
    EXPECT_TRUE(result.second);
    EXPECT_EQ(result.first, 10);
}

TEST(atoi, zero) {
    std::pair<int, bool> result = my_std::atoi("0");
    EXPECT_TRUE(result.second);
    EXPECT_EQ(result.first, 0);
}
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
