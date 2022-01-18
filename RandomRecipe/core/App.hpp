//App.hpp

#ifndef APP_hpp
#define APP_hpp

#include <string>
#include "../core/RecipeList.hpp"
#include "../core/TextFileReader.hpp"
#include "../core/TextFileWriter.hpp"

/*This class runs and controls the Random Recipe Application.
It allows the user to run the application and run the Main menu
for the application using a nested private class.
*/

class App{
    public:
	//Calls the default constructor for the application.
        App() = default;
	//Calls the default destructor for the application/
        ~App() = default;
	//Runs an instance of the application which calls the Main Menu.
	//Returns void
        void runApplication();


    private:
	//A private class for the main menu. The menu is displayed in terminal by calling mainmenu() and it is returned as a constant reference
	//to the MainMenu.
        class MainMenu{
            public:
		//A standard string in the public domain of MainMenu to display the menu.
                std::string menu = "Main Menu\n1. New Recipe Selection\n2. Get Previous Recipe Selections\n"; 
                std::string make_selection = "Please make a selection from the above choices:\n";
		//Calls the default constructor for the Main menu.
                MainMenu() = default;

        };

	//A RecipeList object to hold the list of Recipes.
        RecipeList list;
	//Declaration of the MainMenu object.
        MainMenu menu;

	//The Main menu is returned as a constant reference to a MainMenu object.
        const MainMenu& mainmenu();
	//Loads the data from the text file into the RecipeList.
        void loadData();
	//Prints the welcome message to the terminal. Throws no exceptions.
        void printWelcomeMessage() noexcept;
	//Prints the Menu
        void displayMenu();
	//Gets the total meals needed to accomodate for the user.
	//The default for the total amount of vegetarian meals is 0, leaving the standard
	//as omnivorous meals.  The number of vegetarian meals must be explicitly passed to the function.
        unsigned int getTotalMealsFromUser(bool veggie = 0);
	//Prints the Recipe List
        void printRecipeList();
	//Prints the Recipe list in a random order.
	//Passes a const default random engine for to develop entropy.
        void printRandomRecipeList(const std::default_random_engine& engine);

};

#endif
