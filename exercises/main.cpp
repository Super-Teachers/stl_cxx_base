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

bool isAllLowercase(const std::string& s) {
    return std::all_of(s.begin(), s.end(),
                       [](char c) { return c == ::tolower(c); });
}

void removeSomething(std::vector<std::string>& a) {
    const auto it = std::remove(a.begin(), a.end(), "Ala");
    a.erase(it, a.end());
}

int main(int argc, char** argv) {
    std::vector<std::string> v{"Ala", "bob", "Ala", "bob"};
    removeSomething(v);
    print(v);
}
