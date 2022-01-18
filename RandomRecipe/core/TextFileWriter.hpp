//TextFileWriter.hpp
//
#ifndef TEXTFILEWRITER_HPP
#define TEXTFILEWRITER_HPP

#include <iostream>
#include <fstream>

class TextFileWriter
{
    public:
         TextFileWriter() = default;
	 //Constructor accepts a reference to a string for the filepath.
	 TextFileWriter(const std::string& filepath);
	 //Closes the current open file
         void closeFile();
	 //Destructor
	 ~TextFileWriter();
	 //Writes a line to the file
	 void writeLineToFile(const std::string& line);
    private:
	 //An ofstream to hold the textfile's data.
	 std::ofstream textFile;
};

#endif
