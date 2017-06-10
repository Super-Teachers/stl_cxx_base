
#include <gtest/gtest.h>
#include <numeric>
#include <utility>

struct Accumulator {
    typedef std::tuple<std::string, int, double> MyTuple;

    void add(const std::string &s, int i, double d) {
        auto t = std::make_tuple(s, i, d);
        _vector.push_back(t);
    }

    MyTuple sum() const {
        std::tuple<std::string, int, double> temp;
        std::get<0>(temp) = std::get<0>(_vector[0]);

        temp = std::accumulate(
            _vector.begin() + 1, _vector.end(), temp,
            [](auto tup, auto tup2) -> MyTuple {
                return std::make_tuple(
                    std::get<0>(tup) + "+" + std::get<0>(tup2), 0, 0.0f);
            });

        // first version
        // for (const auto i : _vector) {
        // if (std::get<0>(temp).empty()) {
        // std::get<0>(temp) = std::get<0>(i);
        //} else {
        // std::get<0>(temp) = std::get<0>(temp) + "+" + std::get<0>(i);
        //}

        // std::get<1>(temp) = std::get<1>(temp) + std::get<1>(i);
        // std::get<2>(temp) = std::get<2>(temp) + std::get<2>(i);
        //}

        return temp;
    }

   private:
    std::vector<MyTuple> _vector;
};

TEST(Accumulator, one) {
    Accumulator acc;
    acc.add("test", 10, 0.4f);
    auto result = std::make_tuple("test", 10, 0.4);
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
