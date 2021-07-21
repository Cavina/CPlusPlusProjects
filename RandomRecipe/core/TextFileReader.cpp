//TextFileReader.cpp
//
//

#include "TextFileReader.hpp"

TextFileReader::TextFileReader(const std::string& filepath) : textFile{filepath}, eof{false}, line{}
{
    if(!textFile.fail())
    {
         advanceToNextLine();
    }

}	

void TextFileReader::advanceToNextLine()
{
	if(!std::getline(textFile, line))
	{
	    eof = true;
         line = "";
	}
}

std::string TextFileReader::getCurrentLine()
{
	return line;
}

TextFileReader::~TextFileReader()
{
     textFile.close();
}

bool TextFileReader::endOfFile() const
{
     return eof;
}

