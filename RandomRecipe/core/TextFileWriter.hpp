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
	    TextFileWriter(const std::string& filepath);
         void closeFile();
	    ~TextFileWriter();
	    void writeLineToFile(const std::string& line);
    private:
	    std::ofstream textFile;
};

#endif
