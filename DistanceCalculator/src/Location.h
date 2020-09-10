#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include <string>

namespace locationnamespace { 
class Location
{
    private:
         
        double lat = 0;
        double longitude = 0;
        std::string descript;
        
       

    public:
        Location(const std::string& lt, const std::string& lng, const std::string& s);
        Location(const Location& p2);
        Location();
        void setLatitude(double l);
        void setLongitude(double l);
//        void setLatitude(std::string l);
//        void setLongitude(std::string l);
        void setDescription(std::string s);
        double getLatitude() const;
        double getLongitude() const;
        std::string getDescription() const;
        std::string toString();
};
}


#endif
