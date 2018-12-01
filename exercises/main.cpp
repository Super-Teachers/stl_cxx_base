#include <gtest/gtest.h>
#include <algorithm>
#include <iterator>
#include <list>
#include <vector>

void print(const std::vector<int>& v) {
    std::for_each(v.begin(), v.end(), [](int val) { std::cout << val; });
    std::cout << "\n";
}
void print2(const std::vector<int>& v) {
    std::cout << "[";
    std::for_each(v.begin(), v.end() - 1, [](int v) { std::cout << v << ","; });
    std::cout << *(v.end() - 1);
    std::cout << "]";
    std::cout << "\n";
}

template <typename T>
void print3(T&& t, std::ostream& os = std::cout) {
    if (std::begin(t) == std::end(t)) {
        std::cout << "[]";
        return;
    }

    std::cout << "[";

    auto en = std::end(t);
    std::advance(en, -1);
    std::for_each(std::begin(t), en, [](int v) { std::cout << v << ","; });
    std::cout << *(en);
    std::cout << "]";
    std::cout << "\n";
}

int main(int argc, char** argv) {
    std::vector<int> v{1, 2, 3, 4, 5};
    print(v);
    print2(v);

    int arr[] = {1, 2, 3};

    print3(arr, std::cout);
    print3(std::list<int>{});
}
