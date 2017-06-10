
#include <gtest/gtest.h>
#include <numeric>
#include <utility>

struct Accumulator {
    typedef std::tuple<std::string, int, double> MyTuple;

    void add(const std::string &s, int i, double d) {
        std::get<0>(_result) = std::get<0>(_result) + "+" + s;
        std::get<1>(_result) = std::get<1>(_result) + i;
        std::get<2>(_result) = std::get<2>(_result) + i;
    }

    auto sum() const {
        return _result;
    }

   private:
    MyTuple _result;
};

TEST(Accumulator, one) {
    Accumulator acc;
    acc.add("test", 10, 0.4f);
    Accumulator::MyTuple result = std::make_tuple("test", 10, 0.4);
    EXPECT_EQ(std::get<0>(acc.sum()), std::get<0>(result));
}
TEST(Accumulator, two) {
    Accumulator acc;
    acc.add("test", 10, 0.4f);
    acc.add("test", 10, 0.4f);
    auto result = std::make_tuple("test+test", 10, 0.4);
    EXPECT_EQ(std::get<0>(acc.sum()), std::get<0>(result));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
