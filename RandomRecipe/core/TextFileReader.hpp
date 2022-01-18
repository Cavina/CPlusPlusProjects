//TextFileReader.hpp
//Reads from an input file 
//If no file is loaded, then an empty string is output.

#ifndef TEXTFILEREADER_hpp
#define TEXTFILEREADER_hpp

#include <fstream>
#include <string>

class TextFileReader
{
    public:
	 //Default constructor 
         TextFileReader() = default;
	 //Constructor accepts a reference to a string as the filepath.
	 TextFileReader(const std::string& filepath);
	 //Destructor
         ~TextFileReader();
	 //Advances to the next line of the file
	 void advanceToNextLine();
	 //Returns the current line as a string
	 std::string getCurrentLine();
	 //Returns true if the end of the file is reached.
	 bool endOfFile() const;
    private:
	 //ifstream to hold the textfile in a stream
	 std::ifstream textFile;
	 //boolean value to signify end of file
	 bool eof;
	 //a string that holds a line.
	 std::string line;




};

#endif
