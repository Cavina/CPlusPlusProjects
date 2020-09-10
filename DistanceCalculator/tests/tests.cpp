//tests.cpp
#include "../src/Location.h"
#include "gtest/gtest.h"

TEST(LocationTest, HandlesDirections){

    
    std::string lat = "23.456/S";
    std::string lng = "46.731/W";
    std::string d = "Sao Paolo-Guaraulhos International Airport";
    locationnamespace::Location SWLocation(lat, lng, d);
    EXPECT_EQ(SWLocation.getLatitude(), -23.456);
    EXPECT_EQ(SWLocation.getLongitude(), -46.731);
    ASSERT_EQ(SWLocation.getDescription(), "Sao Paolo-Guaraulhos International Airport");
    
    locationnamespace::Location NWLocation("33.9425/N", "118.4081/W", "LAAirport");
    EXPECT_EQ(NWLocation.getLatitude(), 33.9425);
    EXPECT_EQ(NWLocation.getLongitude(), -118.4081);
    ASSERT_EQ(NWLocation.getDescription(), "LAAirport");

    locationnamespace::Location SWCopyLoc = SWLocation; 
    EXPECT_DOUBLE_EQ(SWLocation.getLatitude(), -23.456);
    EXPECT_DOUBLE_EQ(SWLocation.getLongitude(), -46.731);
    
    ASSERT_EQ(SWLocation.getDescription(), "Sao Paolo-Guaraulhos International Airport");
    
    }

    



int main(int argc, char**argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
