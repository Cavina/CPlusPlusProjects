#include "UserInput.h"
#include <limits>


locationnamespace::Location getLocationInput(){
    std::string lat, lng, descr, input;
    getline(std::cin, input);
    std::stringstream ss(input);
    ss >> lat >> lng;
    int pos = ss.tellg();
    ss.seekg(pos+1);
    getline(ss, descr);      
    ss.str(std::string());
    ss.clear();


    locationnamespace::Location(lat, lng, descr);

    return locationnamespace::Location(lat, lng, descr);
}


int getTotalLocations(){
    int total;
    std::cin >> total;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    return total;
}



