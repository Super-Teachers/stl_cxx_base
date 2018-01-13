#include <algorithm>
#include <iostream>
#include <list>
#include <numeric>
#include <vector>

template <typename T>
void print(T &&t) {
    std::cout << "[";
    auto endIt = std::end(t);
    if (endIt == std::begin(t)) {
        std::cout << "]" << std::endl;
        return;
    }
    std::advance(endIt, -1);
    std::for_each(std::begin(t), endIt,
                  [](auto val) { std::cout << val << ","; });
    std::cout << *(endIt);
    std::cout << "]";

    std::cout << std::endl;
}

template <>
void print(std::string &&s) {
    std::cout << s << std::endl;
}

template <typename T>
std::list<T> copy_vec(const std::vector<T> &t) {
    std::list<T> toRet;
    std::copy_if(std::begin(t), std::end(t), std::back_inserter(toRet),
                 [](const auto &arg) { return arg % 2 == 0; });
    return toRet;
}

std::vector<int> replace(const std::vector<int> &v) {
    std::vector<int> toRet;
    std::transform(std::begin(v), v.end(), std::back_inserter(toRet),
                   [](const auto &v) { return std::abs(v); });
    return toRet;
}

using strings = std::vector<std::string>;
using ints = std::vector<int>;

bool islower(const std::string &literal) {
    return std::all_of(literal.begin(), literal.end(),
                       [](char c) { return std::islower(c); });
}

template <typename T>
using ArrayType =
    typename std::remove_pointer<typename std::decay<T>::type>::type;

template <typename Container, typename Iterator>
typename std::enable_if<std::is_array<Container>::value,
                        std::vector<ArrayType<Container>>>::type
erase_impl(Container &c, Iterator &&it) {
    std::cout << "array" << std::endl;
    std::vector<ArrayType<Container>> ret;
    auto itBegin = std::begin(c);
    while (itBegin != it) {
        ret.push_back(*itBegin);
        itBegin++;
    }

    return ret;
}

template <typename Container, typename Iterator>
typename std::enable_if<!std::is_array<Container>::value, Container>::type
erase_impl(Container &c, Iterator &&it) {
    c.erase(it, c.end());
    return c;
}

template <typename T>
typename std::conditional<std::is_array<T>::value, std::vector<ArrayType<T>>,
                          T>::type
remove_from_anything(T &ss) {
    auto it = std::remove(std::begin(ss), std::end(ss), -1);
    return erase_impl(ss, it);
}

bool has_number(const std::string &s) {
    return std::any_of(s.begin(), s.end(),
                       [](char c) { return std::isdigit(c); });
}

void foo(strings &s) {
    const auto it = std::remove_if(s.begin(), s.end(),
                                   [](const auto &s) { return has_number(s); });
    s.erase(it, s.end());
}

std::string bar(const std::string &input) {
    std::string ret;
    std::remove_copy_if(input.begin(), input.end(), std::back_inserter(ret),
                        [](const char &c) { return std::isspace(c); });
    return ret;
}

std::size_t howManyRotates(ints a, ints b) {
    auto counter = 0u;
    while (a != b) {
        std::rotate(a.begin(), a.begin() + 3, a.end());
        counter++;
    }

    return counter;
}

std::size_t numberOfPermutations(const std::string &str) {
    auto counter = 1u;

    std::string b{str};
    std::sort(b.begin(), b.end());
    print(b);

    std::cout << "Size = " << str.size() << std::endl;

    while (std::next_permutation(b.begin(), b.end())) {
        print(b);
        counter++;
    }

    return counter;
}

std::pair<int, int> smallest(const ints &vec) {
    auto g{vec};
    print(g);
    std::sort(g.begin(), g.end());
    auto iter = std::stable_partition(g.begin(), g.end(),
                                      [](auto v) { return v % 2 == 0; });

    print(g);
    return std::make_pair(*iter, *g.begin());
}

bool ssort(const strings &input) {
    auto v{input};
    print(v);

    std::sort(v.rbegin(), v.rend(), [](const auto &l, const auto &r) {
        return l.size() < r.size();
    });
    print(v);
    return true;
}

int main(int argc, char *argv[]) {
    std::vector<int> v{4, 2, 3, 1, 6};
    std::vector<int> t{v};

    // auto p = smallest(v);
    // std::cout << "odd = " << p.first << " even = " << p.second <<
    // std::endl;
    //
    ssort(
        {"aa", "cc", "ddd", "zzz", "ff", "g", "hhh", "arx", "bb", "1", "wer"});

    return 0;
}
