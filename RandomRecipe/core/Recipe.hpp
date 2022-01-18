//Recipe.hpp
//
#ifndef RECIPE_hpp
#define RECIPE_hpp

#include <string>

/*A structure that defines a Recipe object.
 Holds the name, location (url) of the recipe.
 It also contains a boolean to flag if the meal is vegetarian or not.
*/

struct Recipe{

    std::string name;
    std::string location;
    bool vegetarian = false;
};


#endif
