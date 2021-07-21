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
        Recipe getRecipeAtIndex(int n);
        std::vector<Recipe> getListOfRandomRecipes(int n);
        void PrintAllRecipesInList();

   private:
        std::vector<Recipe> recipes;
        std::vector<Recipe> getListOfRecipes(int n);

};

RecipeList::RecipeList(const RecipeList& list)
{
    if(this != &list)
        recipes = list.recipes;
     
}

RecipeList::RecipeList(RecipeList&& list) noexcept
{
    if(this != &list)
        recipes.swap(list.recipes);

}

RecipeList::RecipeList(const std::vector<Recipe>& list) : recipes{}
{
    if(&recipes != &list)
         recipes = list;
}

RecipeList::RecipeList(std::vector<Recipe>&& list) noexcept : recipes{}
{
    if(&recipes != &list)
        recipes.swap(list);
}

Recipe RecipeList::getRecipeAtIndex(int n)
{
    return recipes.at(n);
}

std::vector<Recipe> RecipeList::getListOfRecipes(int n)
{
    unsigned int count = 0;
    std::vector<Recipe> v;
    while(count < n)
    {
        v.push_back(recipes.at(n));
    }

    return v;
}

std::vector<Recipe> RecipeList::getListOfRandomRecipes(int n)
{
    std::random_device device;
    auto engine = std::default_random_engine(device());
    std::vector<Recipe> list = getListOfRecipes(n);
    std::shuffle(std::begin(list), std::end(list), engine);

    return list;

}

#endif
