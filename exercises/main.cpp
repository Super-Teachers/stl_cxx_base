#include <gtest/gtest.h>
#include <algorithm>
#include <list>

struct Gen {
    void operator() () {}
};

std::list<int> foo() {
    std::list<int> retObj;
    std::generate(retObj.begin(), retObj.end(), Gen{});
    return retObj;
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
