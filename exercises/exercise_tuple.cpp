
#include <gtest/gtest.h>
#include <utility>

struct Accumulator {
    void add(const std::string &, int, double) {
        // TODO: Implement me
    }

    std::string sum() {
        // TODO: Implement me
        return "";
    }

   private:
    // std::vector<std::tuple<...>> _vector;
};

TEST(Accumulator, one) {
    Accumulator acc;
    acc.add("test", 10, 0.4f);
    // EXPECT_EQ(acc.sum(), std::make_tuple("test", 10, 0.4));
    EXPECT_FALSE(true);
}
TEST(Accumulator, two) {
    Accumulator acc;
    acc.add("test", 10, 0.4f);
    acc.add("test", 10, 0.4f);
    // EXPECT_EQ(acc.sum(), std::make_tuple("test+test", 20, 0.8));
    EXPECT_FALSE(true);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
