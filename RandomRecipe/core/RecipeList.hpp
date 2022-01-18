//RecipeList.hpp
//
#ifndef RECIPELIST_hpp
#define RECIPELIST_hpp

#include <vector>
#include <algorithm>
#include <random>
#include "../core/Recipe.hpp"

/*A custom defined list to hold Recipe objects.
The list consists of a std::vector that holds Recipes.
*/
class RecipeList
{
    public:
	//Default constructor for a RecipeList
        RecipeList() = default;
	//Default copy constructor for a RecipeList
        RecipeList(const RecipeList& list) = default;
	//Move constructor
        RecipeList(RecipeList&& list) noexcept;
	//Constructors a RecipeList from a std:::vector of recipes
        RecipeList(const std::vector<Recipe>& list);
	//Constructs a Recipelist from a std::vector by moving the std::vector's contents to the vector in the new RecipeList
        RecipeList(std::vector<Recipe>&& list) noexcept;
	//Adds a Recipe to the RecipeList.
        void addRecipeToList(const Recipe& recipe);
	//Returns a recipe at the passed index
        Recipe getRecipeAtIndex(int n);
	//Returns a randomized vector of a specific amount of recipes.
        std::vector<Recipe> getListOfRandomRecipes(int n, std::default_random_engine engine);
	//Returns a Recipelist consisting only of Vegetarian Recipes
        RecipeList getVegetarianRecipes();
	//Returns a Recipelist of only Meat Recipes.
        RecipeList getMeatRecipes();
	//Returns the size of the RecipeList
        unsigned int size();

   private:
	//A vector to hold the recipes
        std::vector<Recipe> recipes;
	//Returns a vector of Recipes of the specified amount in order. 
        std::vector<Recipe> getListOfRecipes(int n);

};


#endif
