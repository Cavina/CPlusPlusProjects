//RecipeList.hpp
//
#ifndef RECIPELIST_hpp
#define RECIPELIST_hpp

#include <vector>
#include <algorithm>
#include <random>
#include "../core/Recipe.hpp"


class RecipeList
{
    public:
        RecipeList() = default;
        RecipeList(const RecipeList& list);
        RecipeList(RecipeList&& list) noexcept;
        RecipeList(const std::vector<Recipe>& list);
        RecipeList(std::vector<Recipe>&& list) noexcept;
        void addRecipeToList(const Recipe& recipe);
        Recipe getRecipeAtIndex(int n);
        std::vector<Recipe> getListOfRandomRecipes(int n);
        unsigned int size();

   private:
        std::vector<Recipe> recipes;
        std::vector<Recipe> getListOfRecipes(int n);
        std::random_device device;

};


#endif
