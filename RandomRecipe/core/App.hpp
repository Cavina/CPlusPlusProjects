//App.hpp
//
#ifndef APP_hpp
#define APP_hpp
#include <string>
#include "../core/RecipeList.hpp"
#include "../core/TextFileReader.hpp"
#include "../core/TextFileWriter.hpp"


class App{
    public:
        App() = default;
        ~App() = default;
        void runApplication();


    private:
        class MainMenu{
            public:
                std::string menu = "Main Menu\n1. New Recipe Selection\n2. Get Previous Recipe Selections\n"; 
                std::string make_selection = "Please make a selection from the above choices:\n";

                MainMenu() = default;

        };

    private:
        RecipeList list;
        MainMenu menu;

    private:
        const MainMenu& mainmenu();
        void loadData();
        void printWelcomeMessage() noexcept;
        void displayMenu();
        unsigned int getTotalMealsFromUser(bool veggie = 0);
        void printRecipeList();
        void printRandomRecipeList(const std::default_random_engine& engine);

};

#endif
