//TextFileReader.hpp
//Reads from an input file 
//If no file is loaded, then an empty string is output.
//
#ifndef TEXTFILEREADER_hpp
#define TEXTFILEREADER_hpp

#include <fstream>
#include <string>

class TextFileReader
{
    public:
         TextFileReader() = default;
	    TextFileReader(const std::string& filepath);
         ~TextFileReader();
	    void advanceToNextLine();
	    std::string getCurrentLine();
	    bool endOfFile() const;
    private:
	    std::ifstream textFile;
	    bool eof;
	    std::string line;




};

#endif
