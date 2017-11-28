#include <gtest/gtest.h>
#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

#include "cookbook.hpp"

TEST(Cookbook, different_version_of_recipe) {

    /*
    Cookbook cb;
    Recipe budyn { "Budyn "};
    budyn.ingreds = { {"mleko", "50" }, {"masło", "100"} };
    cb.addRecipe(budyn);

    budyn.ingreds.push_back( {"czekolada", "100"} );
    cb.addRecipe(budyn, {"czekolada"});

    EXPECT_EQ(cb.findRecipe("budyn").size(), 2);
    EXPECT_EQ(cb.findByKeywords("czekolada").size(), 1);
     */
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
