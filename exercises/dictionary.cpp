#include <gtest/gtest.h>
#include <iostream>
#include <list>
#include <set>
#include <string>

namespace {
auto lower(const std::string& str) {
    std::string lowered = str;
    for (auto& v : lowered) {
        v = std::tolower(v);
    }
    return lowered;
}
}  // namespace

struct Gen {
    int operator()() { return std::rand(); }
    int _counter{1};
};
struct Dictionary {
    using word = std::string;
    void addWord(const word& w) noexcept { _data.insert(lower(w)); }
    void remove(const word& w) noexcept { _data.erase(lower(w)); }

    bool spell(const word& w) const noexcept {
        return _data.find(lower(w)) != _data.end();
    }

   private:
    using Dictionary_t = std::set<word>;
    Dictionary_t _data;
};

TEST(Dictionary, add_word) {
    Dictionary d;
    d.addWord("bartek");
    EXPECT_TRUE(d.spell("Bartek"));
}

TEST(Dictionary, remove_word) {
    Dictionary d;
    d.addWord("bartek");
    ASSERT_TRUE(d.spell("Bartek"));
    d.remove("BARTek");
    EXPECT_FALSE(d.spell("Bartek"));
}

std::ostream& operator<<(std::ostream& os, const std::list<int>& l) {
    for (const auto element : l) {
        os << element << " ";
    }
    return os;
}

template <typename T>
void print(const T& v) {
    std::for_each(std::begin(v), std::end(v),
                  [](auto& a) { std::cout << a << " "; });
}

bool compare(const std::vector<int>& v, const std::list<int>& l) {
    return std::equal(v.begin(), v.end(), l.begin());
}

bool palindrom(const std::string& pali) {
    return std::equal(pali.begin(), pali.end(), pali.rbegin());
}

int main() {
    std::vector<int> v2{-3, -2, 4, 1, 6, 10, 11, 12};
    std::list<int> l2{-3, -2, 4, 1, 6, 10, 11};
    std::cout << std::boolalpha << compare(v2, l2) << std::endl;

}
