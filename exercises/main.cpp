#include <gtest/gtest.h>
#include <algorithm>
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
void copy(T1&& t1, T2&& t2) {
    std::copy_if(std::begin(t1), std::end(t1), std::back_inserter(t2),
                 [](auto v) { return v % 2 == 0; });
}

int main(int argc, char** argv) {
    std::vector<int> one{1, 2, 3};
    std::vector<int> two;

    copy(one, two);
    print(two);
}
