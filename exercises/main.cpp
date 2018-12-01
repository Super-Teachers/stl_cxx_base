#include <gtest/gtest.h>
#include <algorithm>
#include <iterator>
#include <list>
#include <vector>

float closest(const std::vector<float>& v) {
    auto it =
        std::min_element(v.begin(), v.end(), [](auto dzidek, auto babcia) {
            return std::abs(current) < std::abs(smallest);
        });

    return *it;
}

int main(int argc, char** argv) {
    std::cout << closest(std::vector<float>{-1.f, -0.9, 1.f}) << "\n";
}
