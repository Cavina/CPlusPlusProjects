//RecipeTests.cpp
//
#include <gtest/gtest.h>
#include "../core/Recipe.hpp"
#include <typeinfo>

TEST(RecipeTests, canCreateRecipe)
{
    Recipe meatMeal{"Spaghetti with Meatballs", "https://www.google.com", true};

    Recipe veggieMeal{"Spaghetti", "https://www.google.com/veggie", false};

}


TEST(RecipeTests, canCheckTypeWithTypeIDForMeat)
{
    std::string m = "Spaghetti with Meatballs";
    std::string a = "https://www.google.com";
    Recipe meatMeal{m,a, true};
    EXPECT_EQ(meatMeal.name, m);
    EXPECT_EQ(meatMeal.location, a);
    EXPECT_EQ(meatMeal.hasMeat, true);
    
}

TEST(RecipeTests, canCheckTypeWithTypeIDForVeggie)
{
    std::string m = "Spaghetti";
    std::string a = "https://www.google.com/veggie";
    Recipe veggieMeal{m,a, false};
    EXPECT_EQ(veggieMeal.name, m);
    EXPECT_EQ(veggieMeal.location, a);
    EXPECT_EQ(veggieMeal.hasMeat, false);

}
