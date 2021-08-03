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

TEST(RecipeListsTests, canRandomizeRecipes)
{
    std::string m = "Spaghetti with MeatBalls";
    std::string l = "https://www.google.com";
    Recipe r1{m, l};

    std::string m2 = "Eggs and Bacon";
    std::string l2 = "https://www.wherever.com";
    Recipe r2{m2, l2};

    std::string m3 = "Rice and Salmon";
    std::string l3 = "https://www.wherever.com";
    Recipe r3{m3, l3, false};
    


    std::vector<Recipe> recipes{r1, r2, r3};

    RecipeList rlist{recipes};

    std::random_device device;
    std::default_random_engine engine(device());

    std::vector<Recipe> randomlist = rlist.getListOfRandomRecipes(3, engine);

    int flag = 0;
    for(unsigned int count = 0; count < recipes.size(); ++count)
    {
        flag = 0;
        auto it = std::find_if(randomlist.begin(), randomlist.end(), [&](Recipe const& r){
            return ((r.hasMeat == recipes.at(count).hasMeat) && (r.location == recipes.at(count).location)
                    &&(r.name == recipes.at(count).name));
            });
        if(it != randomlist.end())
            flag = 1;

    }


    EXPECT_EQ(flag, 1);
}



