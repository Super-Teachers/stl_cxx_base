#include <gtest/gtest.h>
#include <map>

std::int64_t hash(const std::string& d) { return std::hash<std::string>{}(d); }

struct Dictonary {
    void insert(const std::string& word) { _dict.emplace(hash(word), word); }
    bool find(const std::string& word) const {
        return _dict.find(hash(word)) != _dict.end();
    }

    bool empty() const { return _dict.empty(); }

   private:
    std::map<int, std::string> _dict;
};

TEST(Dictonary, insert) {
    Dictonary dict;
    EXPECT_TRUE(dict.empty());

    dict.insert("zlo");
    EXPECT_FALSE(dict.empty());
    EXPECT_TRUE(dict.find("zlo"));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
