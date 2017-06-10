#include <gtest/gtest.h>
#include <algorithm>
#include <memory>
#include <vector>

int accumulate() { return 0; }

TEST(Accumulate, simple) {
    std::vector<int> vec;
    //std::vector<std::unique_ptr<int>> result = convert(vec);
    // std::generate_n(std::back_inserter(vec), 10, []() -> std::unique_ptr<int>
    // {
    //// implement me
    //});

    EXPECT_EQ(accumulate(), 55);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
