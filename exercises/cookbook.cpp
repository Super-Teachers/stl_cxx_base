#include <gtest/gtest.h>
#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using keywords = std::set<std::string>;
struct Ingredient {
    std::string name;
    enum class Type { Litre = 0, Gram } type;
    double quantity;
};

bool operator==(const Ingredient& lhs, const Ingredient& rhs) {
    return lhs.name == rhs.name;
}

struct Recipe {
    using Ingredients_t = std::vector<Ingredient>;
    std::string title;
    Ingredients_t ingredients;
    keywords keyz;
};

bool operator==(const Recipe& lhs, const Recipe& rhs) {
    return lhs.title == rhs.title && lhs.ingredients == rhs.ingredients;
}

struct Cookbook {
    using Recipes_t = std::list<Recipe>;
    using RecipePtr_t = Recipes_t::iterator;
    using MultiMap_t = std::unordered_multimap<std::string, RecipePtr_t>;
    void addRecipe(const Recipe& recipe) {
        auto it = std::find(_data.begin(), _data.end(), recipe);
        if (it != _data.end()) {
        } else {
            _data.push_back({recipe});
            auto it = _data.end();
            _titles.insert(MultiMap_t::value_type(recipe.title, --it));
        }
    }

    std::vector<Recipe> find(const std::string& title) {
        auto its = _titles.equal_range(title);
        std::vector<Recipe> ret;
        ret.reserve(std::distance(its.first, its.second));

        std::transform(
            its.first, its.second, std::back_inserter(ret),
            [](const MultiMap_t::value_type& it) { return *it.second; });
        return ret;
    }

    Recipes_t find(const keywords& keyz) { return Recipes_t{}; }

    std::size_t size() const noexcept { return _data.size(); }

   private:
    Recipes_t _data;

    // titles
    std::unordered_multimap<std::string, RecipePtr_t> _titles;
};

TEST(Cookbook, insert_recipe) {
    Cookbook cb;
    cb.addRecipe(
        Recipe{"cake", {Ingredient{"butter", Ingredient::Type::Gram, 0.4}}});

    EXPECT_EQ(cb.size(), 1);

    cb.addRecipe(
        Recipe{"cake", {Ingredient{"sugar", Ingredient::Type::Gram, 0.4}}});

    EXPECT_EQ(cb.size(), 2);
    EXPECT_EQ(cb.find("cake").size(), 2);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
