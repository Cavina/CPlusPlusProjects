//RecipeList.cpp
//
//
#include "../core/RecipeList.hpp"


RecipeList::RecipeList(const RecipeList& list)
{
    if(this != &list)
    {
        recipes = list.recipes;
    }
     
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

void RecipeList::addRecipeToList(const Recipe& recipe)
{
    recipes.push_back(recipe);
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
        v.push_back(recipes.at(count));
        ++count;
    }

    return v;
}

std::vector<Recipe> RecipeList::getListOfRandomRecipes(int n)
{
    std::default_random_engine engine(device());
    std::vector<Recipe> list = getListOfRecipes(n);
    std::shuffle(std::begin(list), std::end(list), engine);
     
    return list;

}

unsigned int RecipeList::size()
{
    return recipes.size();
}
