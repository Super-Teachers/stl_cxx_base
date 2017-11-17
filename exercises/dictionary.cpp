#include <gtest/gtest.h>
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

struct Dictionary {
    using word = std::string;
    void addWord(const word& w) { _data.insert(lower(w)); }
    void remove(const word& w) { _data.erase(lower(w)); }

    bool spell(const word& w) { return _data.find(lower(w)) != _data.end(); }

   private:
    std::set<std::string> _data;
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

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
