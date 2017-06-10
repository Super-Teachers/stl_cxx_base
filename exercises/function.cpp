#include <gtest/gtest.h>
#include <functional>

//void find_bigger_than ( const std::vector<int>& v, int N, 
        //std::function....)
//{
//}

TEST(only_if, correct) {

    bool bValueSet = false;
    auto fn = [&bValueSet]() {bValueSet = true;};
    std::vector<int> vec;
    vec.push_back(10);

    // find_bigger_than(v,5,  fn);
    EXPECT_TRUE(bValueSet);
}
TEST(only_if, incorrect) {

    bool bValueSet = false;
    auto fn = [&bValueSet]() {bValueSet = true;};
    std::vector<int> vec;
    vec.push_back(0);

    // find_bigger_than(v,5,  fn);
    EXPECT_FALSE(bValueSet);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
