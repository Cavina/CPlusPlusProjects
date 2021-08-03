//RecipeList.cpp
//
//
#include "../core/RecipeList.hpp"
#include <random>



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

std::vector<Recipe> RecipeList::getListOfRandomRecipes(int n, std::default_random_engine engine)
{
    std::shuffle(std::begin(recipes), std::end(recipes), engine);
    return getListOfRecipes(n);
}

RecipeList RecipeList::getVegetarianRecipes()
{
    RecipeList l;
    for(auto recipe:recipes)
    {
        if(recipe.vegetarian == true)
            l.addRecipeToList(recipe);
    }
    return l;
}


RecipeList RecipeList::getMeatRecipes()
{
    RecipeList l;
    for(auto recipe:recipes)
    {
        if(recipe.vegetarian == false)
            l.addRecipeToList(recipe);
    }
    return l;
}

unsigned int RecipeList::size()
{
    return recipes.size();
}
