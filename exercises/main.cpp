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

