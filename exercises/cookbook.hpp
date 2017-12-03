#ifndef COOKBOOK_HPP_QBXUGV7S
#define COOKBOOK_HPP_QBXUGV7S

#include <map>
#include <string>
#include <vector>

namespace cooking {

struct Ingredient;
struct Recipe;
using Ingredients = std::vector<Ingredient>;
using RecipeList = std::vector<Recipe>;
using Keywords = std::vector<std::string>;

struct Ingredient {
    std::string _name;
    double _quantity;
};

struct Recipe {
    std::string _title;
    Ingredients _ingreds;
    std::string _text;
};

namespace v1 {
struct Cookbook {
    void addRecipe(const Recipe& r, const Keywords& keywords = Keywords{}) {
        auto it = _data.insert(std::make_pair(r._title, r));

        if (!keywords.empty()) {
            _keywords.insert(std::make_pair(keywords.at(0), it));
        }
    }

    //! Fast O(logN) lookup
    RecipeList findByKeywords(const Keywords& k) {
        auto its = _keywords.equal_range(k.at(0));
        RecipeList ret;
        auto it = its.first;
        while (it != its.second) {
            ret.push_back(it->second->second);
            std::advance(it, 1);
        }
        return ret;
    }

    //! Search all recipes that can be created with a given recipes
    RecipeList search(const Ingredients& ingreds) { return RecipeList{}; }

    //! fast O(logN) lookup
    RecipeList findRecipes(const std::string& title) {
        auto its = _data.equal_range(title);
        RecipeList ret;
        auto it = its.first;
        while (it != its.second) {
            ret.push_back(it->second);
            std::advance(it, 1);
        }
        return ret;
    }

   private:
    //                              title,      Recipe
    using Recipes = std::multimap<std::string, Recipe>;
    Recipes _data;
    //               keyword    Recipe
    std::multimap<std::string, Recipes::const_iterator> _keywords;
};

}  // namespace v1
}  // namespace cooking

#endif /* end of include guard: COOKBOOK_HPP_QBXUGV7S */
