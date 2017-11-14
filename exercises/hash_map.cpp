#include <gtest/gtest.h>
#include <functional>
#include <map>
#include <string>

template <typename HashType>
struct Hash {
    using Int = HashType;
    template <typename V>
    Hash(V&& v) {
        auto h = std::hash<typename std::decay<V>::type>{};
        _value = h(std::forward<V>(v));
    }

    Int _value;
};

struct Greater {
    template <typename T>
    bool operator()(const Hash<T>& lhs, const Hash<T>& rhs) {
        return lhs._value < rhs._value;
    }
};

template <typename Data>
using MyMap = std::map<Hash<std::int64_t>, Data, Greater>;

template <typename Data>
struct HashMap {
    void put(const std::string& key, Data&& d) {
        auto h = Hash<std::int64_t>{key};
        _map[h] = std::forward<Data>(d);
    }

    bool empty() const { return _map.empty(); }
    std::size_t size() const noexcept { return _map.size(); }

    bool check(Data&& d) {
        auto h = Hash<std::int64_t>{std::forward<Data>(d)};
        return _map.find(h) != _map.end();
    }

    MyMap<Data> _map;
};

TEST(MyMap, map_empty) {
    MyMap<int> asd;
    EXPECT_TRUE(asd.empty());
}

TEST(MyMap, adding_elements) {
    MyMap<int> asd;
    int value = 55;
    Hash<std::int64_t> hh{55};
    asd[hh] = value;
    EXPECT_FALSE(asd.empty());
}

TEST(HashMap, simple) {
    HashMap<std::string> hm;
    EXPECT_TRUE(hm.empty());
}

TEST(HashMap, insert_and_check) {
    HashMap<std::string> hm;
    hm.put("icon", "test data");
    EXPECT_EQ(hm.size(), 1);

    EXPECT_TRUE(hm.check("icon"));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
