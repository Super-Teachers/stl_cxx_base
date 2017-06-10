#include <gtest/gtest.h>
#include <algorithm>
#include <memory>
#include <numeric>
#include <vector>

std::vector<std::unique_ptr<int>> convert(const std::vector<int>& v) {
    std::vector<std::unique_ptr<int>> result;
    for (const auto& i : v) result.push_back(std::make_unique<int>(i));
    return result;
}

double mean(const std::vector<std::unique_ptr<int>>& v) {
    int (*(*foo)(void ))[3];
    double res;
    auto sum =
        std::accumulate(v.begin(), v.end(), 0,
                        [](int p, const auto& s) -> int { return p + *s; });

    return static_cast<double>(sum) / static_cast<double>(v.size());
}

TEST(Accumulate, simple) {
    std::vector<int> vec;

    std::generate_n(std::back_inserter(vec), 10, [] { return rand() % 10; });
    auto r = convert(vec);

    EXPECT_EQ(vec.size(), r.size());
    EXPECT_EQ(vec.at(0), *(r.at(0)));

    EXPECT_NE(mean(r), 0.0f);

    // std::vector<std::unique_ptr<int>> result = convert(vec);
    // std::generate_n(std::back_inserter(vec), 10, []() -> std::unique_ptr<int>
    // {
    //// implement me
    //});
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
