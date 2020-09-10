#include "Location.h"
#include "UserInput.h"
#include "DistanceCalculator.h"

int main()
{
    locationnamespace::Location farthest, closest;
    locationnamespace::Location startLocation = getLocationInput();
    int totalLocations = getTotalLocations();


    for (int i = 0; i < totalLocations; i++){
        locationnamespace::Location endLocation = getLocationInput();
        std::cout << endLocation.toString();
        if (i==0){
            closest = endLocation;
            farthest = endLocation;
        }
        if(isCloser(startLocation, endLocation, closest)){
            closest = endLocation;
        }

    }

    std::cout << "Closest: " << closest.toString();

    return 0;
}


