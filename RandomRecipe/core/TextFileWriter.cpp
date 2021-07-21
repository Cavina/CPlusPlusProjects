//TextFileWriter.cpp
//
#include "../core/TextFileWriter.hpp"


TextFileWriter::TextFileWriter(const std::string& filepath) : textFile{filepath}
{
}

void TextFileWriter::writeLineToFile(const std::string& line)
{
    if(line != "")
    {
	    textFile.write(line.c_str(), line.size());
    }
}

void TextFileWriter::closeFile()
{
     textFile.close();
}

TextFileWriter::~TextFileWriter()
{
    if(textFile.is_open())
        textFile.close();
}
