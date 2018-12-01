#include <gtest/gtest.h>
#include <algorithm>
#include <iterator>
#include <list>
#include <vector>

std::string toUpper(const std::string& s) {
    std::string tmp = s;
    std::for_each(tmp.begin(), tmp.end(),
                  [](char& chr) { chr = ::toupper(static_cast<int>(chr)); });

    return tmp;
}
std::string toUpper2(const std::string& s) {
    std::string tmp;
    std::for_each(s.begin(), s.end(),
                  [&tmp](char chr) { tmp += ::tolower(chr); });

    return tmp;
}

std::string toUpper3(const std::string& s) {
    std::string tmp;
    auto predicate = [](char c) { return ::tolower(c); };
    std::transform(s.begin(), s.end(), std::back_inserter(tmp), predicate);
    return tmp;
}

int main(int argc, char** argv) {
    std::cout << toUpper3(std::string{"aa"}) << "\n";
}
