
#include <gtest/gtest.h>
#include <cmath>
#include <iostream>

template <typename T>
std::vector<T> fn(const std::vector<T>& orig, T number) {
    std::vector<T> v { orig.begin(), orig.end() };
    v.reserve(orig.size());
    auto it2 = v.begin();
    for (auto it = orig.begin(); it != orig.end(); ++it) {
        *it2 = std::pow(*it, number);
        it2++;
    }

    return v;
}

TEST(FN, simple) {
    std::vector<int> v{1, 2, 3, 4, 5};
    auto result = fn(v, 2);

    std::vector<int> expected{1, 4, 9, 16, 25};
    EXPECT_EQ(result, expected);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
