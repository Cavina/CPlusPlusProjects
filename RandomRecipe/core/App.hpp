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
        void runApplication();
        void printWelcomeMessage() noexcept;
        void displayMenu();
        void printRecipeList();

    private:
        RecipeList list;
        struct Menu;
        void loadData();





};

#endif
