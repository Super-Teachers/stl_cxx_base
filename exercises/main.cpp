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

void replaceAll(std::vector<std::string>& strs) {
    std::replace_if(strs.begin(), strs.end(), isAllLowercase,
                    std::string{"bummer"});
}

int main(int argc, char** argv) {
    std::vector<std::string> v{"Ala", "bob", "AA"};
    replaceAll(v);
    print(v);
}
