#09/10/2020
I actually went ahead and removed the file that held my main function. 
This is actually a project for ICS45C at UCI.  I haven't taken
the class nor will I take the class (I tested out), but I do not want another student to
copy the work for their own assignment.  
The difficult part of the project was deciding on how best 
handle up to a billion objects.  This is the part that would likely
be taken.
My Object files for input and the Location object, as well as implementing 
Haversine are all very straightforwards, so I've left them up in my public repo.  If you have to copy that as a CS student 
at UCI or any school for that matter, you shouldn't be there. 


#09/09/2020
This is a small project for a distance calculator.
It takes in a latitude, longitude, and a Location name/description
and creates a Location object.
I then use Haversine algorthim to calculate the distance in miles.

In the 'projectOne.cpp' file you will find my main function.
This initiates a sequence that takes input in this format: 
lat/N long/E Description, where /N and /E are the appropriate cardinal directions for your input.
Example: 32.7157/N 117.1611/W San Diego
The second line takes in a number of total locations.
After that, it asks for locations data n times.
It determines which location is closest and prints it to the system output.

