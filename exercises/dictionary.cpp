#include <gtest/gtest.h>
#include <string>

struct Dictionary {
    using word = std::string;
    void addWord(const word& w) {}
    void remove(const word& w) {}

    bool spell(const word& w) { return false;}
};

TEST(Dictionary, add_word) {
    Dictionary d;
    d.addWord("bartek");
    EXPECT_TRUE(d.spell("Bartek"));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
