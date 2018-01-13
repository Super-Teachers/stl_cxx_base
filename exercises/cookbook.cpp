#include <gtest/gtest.h>
#include <algorithm>
#include <list>

std::list<int> foo() {
    std::list<int> retObj;
    int counter = -5;
    std::generate_n(std::back_inserter(retObj), 10,
                    [&counter]() { return ++counter; });
    retObj.push_back(0);
    return retObj;
}

template <typename T>
void print(T&& t) {
    std::cout << "[";
    auto endIt = std::end(t);
    std::advance(endIt, -1);
    std::for_each(std::begin(t), endIt,
                  [](auto val) { std::cout << val << ","; });
    std::cout << *(endIt);
    std::cout << "]";

    std::cout << std::endl;
}

template <typename T>
auto closeZero(T&& t) {
    if (t.empty()) throw std::runtime_error("");
    return *(std::min_element(t.begin(), t.end(), [](auto lhs, auto rhs) {
        return std::abs(lhs) < std::abs(rhs);
    }));
}

std::vector<std::size_t> find_indexes(const std::list<int>& v, int value) {
    std::vector<std::size_t> ret;
    if (v.empty()) return ret;

    auto it = std::find(v.begin(), v.end(), value);

    while (it != v.end()) {
        ret.push_back(std::distance(v.begin(), it));
        it++;
        it = std::find(it, v.end(), value);
    }

    return ret;
}

int main(int argc, char** argv) {
    // print(foo());
    // std::vector<std::string> aa{"a", "b", "c"};
    // print(aa);
    int tab[] = {0, 1, 2};
    print(tab);

    // std::cout << closeZero(foo()) << std::endl;
    auto f = foo();
    print(f);
    print(find_indexes(f, 0));
    return 0;
}
