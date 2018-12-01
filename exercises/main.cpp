#include <gtest/gtest.h>
#include <algorithm>
#include <iterator>
#include <list>
#include <vector>

std::size_t odds(const std::vector<int>& v) {
    return std::count_if(v.begin(), v.end(), [](int v) { return v % 2 != 0; });
}

int main(int argc, char** argv) { std::cout << odds({1, 2, 3, 4, 5}) << "\n"; }
