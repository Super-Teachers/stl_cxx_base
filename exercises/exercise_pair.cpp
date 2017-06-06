#include <gtest/gtest.h>
#include <utility>

TEST(atoi, incorrect_atoi) {
    //auto result = my_std::atoi("not a number");
    //EXPECT_EQ(result.second, false);
    EXPECT_TRUE(false);
}

TEST(atoi, correct_atoi) {
    //std::pair<int, bool> result = my_std::atoi("10");
    //EXPECT_TRUE(result.second);
    //EXPECT_EQ(result.first, 10);
    EXPECT_TRUE(false);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
