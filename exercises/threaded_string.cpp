
#include <gtest/gtest.h>
#include <functional>
#include <memory>
#include <thread>
#include <utility>

std::ostream& operator<<(std::ostream& os, const std::vector<std::string>& v) {
    for (auto i : v) os << i << " ";
    return os;
}

bool lowercase(const std::string& lower) {
    return std::any_of(lower.begin(), lower.end(),
                       [](char c) { return std::islower(c); });
}

// std::thread fun(const std::vector<std::string>& str, [> std::function <]) {
std::thread fun(const std::vector<std::string>& str,
                const std::function<void()>& cb) {
    std::cout << str << std::endl;
    std::vector<std::string> lowerCases;
    std::copy_if(str.begin(), str.end(), std::back_inserter(lowerCases),
                 [](const auto& i) { return lowercase(i); });

    std::cout << lowerCases << std::endl;

    auto sharedVector = std::make_shared<std::vector<std::string>>(lowerCases);
    std::thread fn{[sharedVector, &cb]() {
        std::for_each(
            sharedVector->begin(), sharedVector->end(), [&cb](const auto& str) {
                if (str.size() % 2 == 0) {
                    cb();
                }
            });
    }};

    return fn;
}

TEST(test, threaded_str) {
    int counter = 0;
    std::vector<std::string> data{{"asda"}, {"TADA"}, {"aaa"}};
    auto fn = [&counter]() {
        counter++;
    };

    auto t = fun(data, fn);
    ASSERT_TRUE(t.joinable());
    t.join();
    EXPECT_EQ(counter, 1);
}

TEST(Accumulator, two) {}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
