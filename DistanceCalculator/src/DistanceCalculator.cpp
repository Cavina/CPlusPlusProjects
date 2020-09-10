#include "DistanceCalculator.h"
#include <cmath>

double calculateDistance(const locationnamespace::Location& start,
        const locationnamespace::Location& end){
    

    double startLatRad = start.getLatitude() * (M_PI/180.0);
    double endLatRad = end.getLatitude() * (M_PI/180.0);
    double latDiff = (end.getLatitude() - start.getLatitude())*(M_PI/180.0);
    double lngDiff = (end.getLongitude() - start.getLongitude())*(M_PI/180.0);
    double a = pow(sin(latDiff/2), 2) + pow(sin(lngDiff/2), 2)*cos(startLatRad)*cos(endLatRad);

    double c = 2*atan2(sqrt(a), sqrt(1-a));
    double earthRadius = 3959.9;

    return earthRadius*c;

}


bool isCloser(locationnamespace::Location& start, 
        locationnamespace::Location& end, 
        locationnamespace::Location& closest){
    if (&end == &closest)
        return true;
    if (calculateDistance(start, end) < calculateDistance(start, closest))
        return true;
    return false;
}


bool isFarther(locationnamespace::Location& start, 
        locationnamespace::Location& end, 
        locationnamespace::Location& farthest){
    if (calculateDistance(start, end) > calculateDistance(start, farthest))
        return true;
    return false;
}
