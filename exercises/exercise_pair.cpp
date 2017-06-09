#include <gtest/gtest.h>
#include <utility>

/*
namespace my_std {
?? my_std::atoi(??)
}
 */

TEST(atoi, incorrect_atoi) {
    //auto result = my_std::atoi("not a number");
    //EXPECT_EQ(this has to be a bad value);
    EXPECT_TRUE(false);
}

TEST(atoi, correct_atoi) {
    //std::pair<int, bool> result = my_std::atoi("10");
    // this has to be a good value
    EXPECT_TRUE(false);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
