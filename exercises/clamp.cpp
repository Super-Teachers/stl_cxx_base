
#include <gtest/gtest.h>
#include <vector>

enum class ClampType { Clear = 0, Replace, Append };

template <typename T>
void clamp(const T& original, T& expected, typename T::value_type hi,
           ClampType type) {
    switch (type) {
        case ClampType::Clear:
            expected.clear();
        case ClampType::Append:
            for (const auto& value : original) {
                if (value < hi) {
                    expected.push_back(value);
                }
            }
            break;
        case ClampType::Replace:
            auto numberOfClampedValue = [](const std::vector<int> v, int hi) {
                return std::count_if(v.begin(), v.end(),
                                     [&hi](auto value) { return value < hi; });
            };

            auto newCount = numberOfClampedValue(original, hi);
            expected.resize(newCount > expected.size() ? newCount
                                                       : expected.size());
            auto it = expected.begin();
            for (const auto& value : original) {
                if (value < hi) {
                    *it = value;
                    ++it;
                }
            }
            break;
    }
}

TEST(clamp, clear) {
    std::vector<int> original{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> clamped{0, 0, 0, 0};

    clamp(original, clamped, 4, ClampType::Clear);

    std::vector<int> expected{0, 1, 2, 3};
    EXPECT_EQ(clamped, expected);
}
TEST(clamp, replace) {
    std::vector<int> original{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> clamped{0, 0, 0, 5};

    clamp(original, clamped, 4, ClampType::Replace);

    std::vector<int> expected{0, 1, 2, 3};
    EXPECT_EQ(clamped, expected);
}

TEST(clamp, append) {
    std::vector<int> original{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> clamped{0, 0, 0, 5};

    clamp(original, clamped, 4, ClampType::Append);

    std::vector<int> expected{0, 0, 0, 5, 0, 1, 2, 3};
    EXPECT_EQ(clamped, expected);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
