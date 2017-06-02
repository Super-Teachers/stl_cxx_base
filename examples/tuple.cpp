#include <gtest/gtest.h>
#include <utility>

TEST(atoi, incorrect_atoi) {
    // auto result = my_std::atoi("not a number");
    // EXPECT_FALSE(get_second_argument(result), false);
}

TEST(atoi, correct_atoi) {
    // std::tuple<int, bool> result = my_std::atoi("10");
    // EXPECT_TRUE(get_second_arg(result));
    // EXPECT_EQ(get_first_argument(result), 10);
}

constexpr auto cast_to_all(int value)
    -> decltype(std::make_tuple(int(), double(), float())) {
    return std::make_tuple(value, static_cast<double>(value),
                           static_cast<float>(value));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
