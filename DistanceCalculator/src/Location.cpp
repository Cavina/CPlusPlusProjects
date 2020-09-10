#include "Location.h"

namespace locationnamespace { 
    Location::Location(){ lat = 0; longitude = 0; descript = "";}
    Location::Location(const std::string& lt, const std::string& lng, const std::string& s)
{
    //TODO Fix the the redundancy
    std::size_t pos = lt.find('/');
    std::string temp = lt.substr(0, pos);

    if (lt.find('S') != std::string::npos){
        lat = -std::stod(temp);
        }
    else{
    lat = std::stod(temp);
    }


    std::string tempTwo = "";
    std::size_t posTwo = lng.find('/');
    tempTwo = lng.substr(0, posTwo);
    if (lng.find('W') != std::string::npos){
        longitude= -std::stod(tempTwo);
         }
    else{
    longitude = std::stod(tempTwo);

    }
    
    descript = s;
}


void Location::setLatitude(double l)
{
    lat = l;
}

void Location::setLongitude(double l)
{
    longitude = l;
}

void Location::setDescription(std::string s)
{
    descript = s;
}

double Location::getLatitude() const
{
    return lat;
}

double Location::getLongitude() const
{
    return longitude;
}

std::string Location::getDescription() const
{
    return descript;
}

std::string Location::toString() 
{
    std::string s = "Lat: " + std::to_string(lat) +
    "\nLong: " + std::to_string(longitude) +  
    "\nDescription: " + descript + "\n";
     return s; 
}
Location::Location(const Location& p2)
{
    lat = p2.getLatitude();
    longitude = p2.getLongitude();
    descript = p2.getDescription();
}

}
