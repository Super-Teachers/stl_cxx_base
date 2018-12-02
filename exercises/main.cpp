#include <gtest/gtest.h>
#include <algorithm>
#include <iterator>
#include <list>
#include <vector>

bool isPalindrom(const std::string& s) {
    return std::equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
}

int main(int argc, char** argv) {
    std::cout << std::boolalpha << isPalindrom("kajak") << "\n";
    std::cout << std::boolalpha << isPalindrom("zlo") << "\n";
}
