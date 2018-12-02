#include <gtest/gtest.h>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <list>
#include <vector>

template <typename T>
void print(T&& t, std::ostream& os = std::cout) {
    std::cout << "[";
    std::for_each(std::begin(t), std::end(t) - 1,
                  [&os](auto v) { os << v << ", "; });

    std::cout << *(std::end(t) - 1);
    std::cout << "]\n";
}

template <typename T1, typename T2>
std::vector<typename T1::value_type> convert(T1&& t1, T2&& t2) {
    std::vector<typename T1::value_type> asd;

    std::transform(std::begin(t1), std::end(t1), std::begin(t2),
                   std::back_inserter(asd),
                   [](auto n, auto k) {
                       return std::pow(n, k);
                   });

    return asd;
}

int main(int argc, char** argv) {
    const auto strs =
        convert(std::vector<int>{1, 2, 3}, std::list<int>{1, 2, 3});
    print(strs);
}
