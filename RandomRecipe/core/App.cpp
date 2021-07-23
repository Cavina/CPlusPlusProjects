//App.cpp
//
#include "../core/App.hpp"


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

void App::loadData()
{
     TextFileReader filereader{"current.txt"};
     while(!filereader.endOfFile())
     {
        std::string s = filereader.getCurrentLine();
        char delimiter = '$'; 
        std::string name;
        std::string location;

        std::string::iterator it;
        for(it = s.begin(); it != s.end(); ++it)
        {
            if(*it == delimiter)
            {
               ++it;
               while(it != s.end())
               {
                   location += (*it);
                   ++it;
               }
            }

            if(it != s.end())
                name+=(*it);
        }
        Recipe r{name, location}; 
        list.addRecipeToList(r);

     }

}
