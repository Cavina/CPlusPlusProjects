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
        RecipeList(const RecipeList& list) = default;
        RecipeList(RecipeList&& list) noexcept;
        RecipeList(const std::vector<Recipe>& list);
        RecipeList(std::vector<Recipe>&& list) noexcept;
        void addRecipeToList(const Recipe& recipe);
        Recipe getRecipeAtIndex(int n);
        std::vector<Recipe> getListOfRandomRecipes(int n, std::default_random_engine engine);
        RecipeList getVegetarianRecipes();
        RecipeList getMeatRecipes();
        unsigned int size();

   private:
        std::vector<Recipe> recipes;
        std::vector<Recipe> getListOfRecipes(int n);

};


#endif
