//RecipeListsTests.cpp
//
#include <gtest/gtest.h>
#include "../core/RecipeList.hpp"

TEST(RecipeListsTests, canConstruct)
{
    RecipeList rlist{};
}

TEST(RecipeListsTests, canAddToList)
{
    std::string m = "Spaghetti with MeatBalls";
    std::string l = "https:www.google.com";
    Recipe r1{m, l};

    std::vector<Recipe> recipes{r1};
    
    RecipeList rlist{recipes};

    EXPECT_EQ(rlist.getRecipeAtIndex(0).name, r1.name);
    EXPECT_EQ(rlist.getRecipeAtIndex(0).location, r1.location); 
    

}



