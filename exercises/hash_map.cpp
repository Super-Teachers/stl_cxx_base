#include <gtest/gtest.h>
#include <map>

std::int64_t hash(const std::string& d) { return std::hash<std::string>{}(d); }

struct Hash {
    friend bool operator<(const Hash&, const Hash&);
    friend class HashCompare;
    Hash(const std::string& word) : _value(hash(word)) {}

   private:
    const int _value;
};

struct HashCompare {
    bool operator()(const Hash& lhs, const Hash& rhs) const {
        return lhs._value < rhs._value;
    }
};

struct Dictonary {
    void insert(const std::string& word) { _dict[Hash{word}] = word; };
    bool find(const std::string& word) const {
        return _dict.find(Hash{word}) != _dict.end();
    }

    bool empty() const { return _dict.empty(); }

   private:
    std::map<Hash, std::string, HashCompare> _dict;
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
