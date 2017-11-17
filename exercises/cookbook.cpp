#include <gtest/gtest.h>
#include <string>
#include <vector>

using keywords = std::vector<std::string>;
struct Ingredient {
    std::string name;
    enum { Litre, Gram } type;
    double quantity;
};

struct Recipe {
    std::string title;
};

struct Cookbook {
    void addRecipe(const Recipe& recipe, const keywords& keys) {}

    Recipe find(const std::string& tile) { return Recipe{}; }
    Recipe find(const keywords& keys) { return Recipe{}; }
};

TEST(Cookbook, asd) {}

int main(int argc, char* argv[]) { return 0; }
