#include <gtest/gtest.h>
#include <algorithm>
#include <iterator>
#include <list>
#include <vector>

#include <benchmark/benchmark.h>

template <typename T1, typename T2>
bool areSame(T1&& t1, T2&& t2) {
    // return std::equal(std::begin(t1), std::end(t1), std::begin(t2));
    //
    // p = std::pair < iterator, iterator>
    //const std::pair<typename T1::iterator, typename T2::iterator> p =
        //std::mismatch(std::begin(t1), std::end(t1), std::begin(t2));
    const auto p =
        std::mismatch(std::begin(t1), std::end(t1), std::begin(t2));
    return p.first == std::end(t1) && p.second == std::end(t2);

    typename T1::iterator it;
}

bool isPalindrome ( const std::string& s)
{
}


BENCHMARK()

int main(int argc, char** argv) {
    std::cout << std::boolalpha
              << areSame(std::vector<int>{1, 2, 3}, std::list<int>{1, 2, 3})
              << "\n";
    std::cout << std::boolalpha
              << areSame(std::vector<int>{1, 2, 4}, std::list<int>{1, 2, 3})
              << "\n";
}
