#include <gtest/gtest.h>
#include <list>
#include <map>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

#include "cookbook.hpp"

double cost(const cooking::RecipeList& recipes) {
    auto value = std::accumulate(
        recipes.begin(), recipes.end(), 0.0,
        [](double init, const auto& recipe) -> double {
            return init + std::accumulate(recipe._ingreds.begin(),
                                          recipe._ingreds.end(), 0.0,
                                          [](double innerInit, const auto& i) {
                                              return innerInit + i._quantity;
                                          });
        });

    return value;
}

TEST(Cookbook, add_recipe) {
    using cooking::Recipe;
    using cooking::v1::Cookbook;
    Cookbook cb;
    Recipe budyn{"Budyn"};
    budyn._ingreds = {{"mleko", 50}, {"masło", 100}};
    cb.addRecipe(budyn, {"deser"});
    ASSERT_EQ(cb.findRecipes("Budyn").size(), 1);
    EXPECT_EQ(cost(cb.findRecipes("Budyn")), 150);

    EXPECT_EQ(cb.findByKeywords({"deser"}).size(), 1);
}

TEST(Cookbook, different_version_of_recipe) {
    using cooking::Recipe;
    using cooking::v1::Cookbook;
    Cookbook cb;
    Recipe budyn{"Budyn"};
    budyn._ingreds = {{"mleko", 50}, {"masło", 100}};
    cb.addRecipe(budyn);

    budyn._ingreds.push_back({"czekolada", 100});
    cb.addRecipe(budyn, {"czekolada"});

    EXPECT_EQ(cb.findRecipes("Budyn").size(), 2);
    EXPECT_EQ(cb.findByKeywords({"czekolada"}).size(), 1);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
