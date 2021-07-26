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
    if(list.size() == 0)
        std::cout << "NO recipes in file or wrong file" << std::endl;
    //display the menu

}

void App::printWelcomeMessage() noexcept
{
    std::string message = "Welcome to the Recipe Randomizer!";
    std::string loadmsg = "Loading recipes...";

    std::cout << message << std::endl;
    std::cout << loadmsg << std::endl;

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

void App::printRandomRecipeList()
{
    std::vector<Recipe> randomList = list.getListOfRandomRecipes(list.size()); 
    for(unsigned int i = 0; i < randomList.size(); ++i)
    {
        Recipe r = randomList.at(i);
        std::cout << r.name << std::endl;
        std::cout << r.location << std::endl;
    }
}

void App::loadData()
{
     TextFileReader filereader{"current.txt"};
     std::string delimiter = "$"; 
     std::string token;
     std::string name;
     std::string location;
     while(!filereader.endOfFile())
     {
        std::string s = filereader.getCurrentLine();
        size_t pos = 0;

        while((pos = s.find(delimiter)) != std::string::npos)
        {
            token = s.substr(0, pos);
            name = token;
            s.erase(0, pos + delimiter.length());
            location = s;
        }

        Recipe r{name, location}; 
        list.addRecipeToList(r);
        filereader.advanceToNextLine();

     }

}
