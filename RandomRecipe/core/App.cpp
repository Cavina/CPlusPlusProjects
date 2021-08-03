//App.cpp
//
#include "../core/App.hpp"
#include <iostream>

 

void App::runApplication()
{
    //print welcome message
    printWelcomeMessage();
    //load data
    loadData();
    std::random_device device;
    std::default_random_engine engine(device());
    if(list.size() == 0)
        std::cout << "NO recipes in file or wrong file" << std::endl;
    std::cout << mainmenu().menu;
    std::cout << mainmenu().make_selection;
    int input = 0;
    while(input != 1)
    {
        std::cin >> input; 
        if(input != 1)
            std::cout << "Not a selection." << std::endl;
    }
        
    if(input == 1)
    {
        unsigned int no_of_meat = getTotalMealsFromUser();
        unsigned int no_of_veget = getTotalMealsFromUser(1);

        std::vector<Recipe> vList = list.getVegetarianRecipes().getListOfRandomRecipes(no_of_veget, engine);
        std::vector<Recipe> mList = list.getMeatRecipes().getListOfRandomRecipes(no_of_meat, engine);

        RecipeList fullList{vList};

        auto it = mList.begin();
        while(it != mList.end())
        {
            fullList.addRecipeToList(*it);
            ++it;
        }

        std::vector<Recipe> v = fullList.getListOfRandomRecipes(fullList.size(), engine);  

       TextFileWriter writer("current.txt");
       for(auto elem : v)
       {
           writer.writeLineToFile(elem.name + "$" + elem.location + "$" + elem.vegetarian);
               }
       else if(input == 2)
       {


       }




          

        //filter veggie meals
        
        
        


    }
    
    //display the menu

}

const App::MainMenu& App::mainmenu()
{
    return menu;
}

void App::printWelcomeMessage() noexcept
{
    std::string message = "Welcome to the Recipe Randomizer!";
    std::string loadmsg = "Loading recipes...";

    std::cout << message << std::endl;
    std::cout << loadmsg << std::endl;
}

unsigned int App::getTotalMealsFromUser(bool veggie)
{
    std::string msg = "Please enter how many " + std::string((veggie == 0) ? "Non-Vegetarian " : "Vegetarian ")
        + "meals you would like";  
    unsigned int meals = 0;

    std::cout << msg << std::endl;
    std::cin >> meals;

    return meals;
}

void App::printRecipeList()
{
    for(unsigned int i = 0; i < list.size(); ++i)
    {
        Recipe r = list.getRecipeAtIndex(i);
        std::cout << r.name << std::endl;
        std::cout << r.location << std::endl;
    }
}

void App::printRandomRecipeList(const std::default_random_engine& engine)
{
    std::vector<Recipe> randomList = list.getListOfRandomRecipes(list.size(), engine); 
    for(unsigned int i = 0; i < randomList.size(); ++i)
    {
        Recipe r = randomList.at(i);
        std::cout << r.name << std::endl;
        std::cout << r.location << std::endl;
    }
}

void App::loadData(std::string filename)
{
     TextFileReader filereader{"master.txt"};
     std::string delimiter = "$"; 
     std::string token;
     std::string name;
     std::string location;
     std::string veggie;
     while(!filereader.endOfFile())
     {
        std::string s = filereader.getCurrentLine();
        size_t pos = 0;

        while((pos = s.find(delimiter)) != std::string::npos)
        {
            token = s.substr(0, pos);
            name = token;
            s.erase(0, pos + delimiter.length());
            auto pos_two = s.find(delimiter);
            token = s.substr(0, pos_two);
            location = token;
            s.erase(0, pos_two+delimiter.length());
            veggie = s;

        }

        Recipe r{name, location, (veggie == "1")}; 
        list.addRecipeToList(r);
        filereader.advanceToNextLine();
     }

}


