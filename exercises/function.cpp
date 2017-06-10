#include <gtest/gtest.h>
#include <functional>

void find_bigger_than(const std::vector<int>& v, int N,
                      const std::function<void(std::size_t)>& fn) {
    auto it = std::find_if(v.begin(), v.end(), [&N](auto i) { return i > N; });

    if (it != v.end()) {
        fn(std::distance(v.begin(), it));
    }
}

TEST(only_if, correct) {
    bool bValueSet = false;
    std::size_t in;
    auto fn = [&bValueSet, &in](std::size_t index) {
        bValueSet = true;
        in = index;
    };
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(15);

    find_bigger_than(vec, 11, fn);
    EXPECT_EQ(in, 1);
    EXPECT_TRUE(bValueSet);
}

TEST(only_if, incorrect) {
    bool bValueSet = false;
    auto fn = [&bValueSet](std::size_t) { bValueSet = true; };
    std::vector<int> vec;
    vec.push_back(0);

    find_bigger_than(vec, 5, fn);
    EXPECT_FALSE(bValueSet);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
