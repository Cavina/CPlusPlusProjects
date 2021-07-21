//FileWriterTests.cpp
//
#include <gtest/gtest.h>
#include "../core/TextFileWriter.hpp"
#include "../core/TextFileReader.hpp"


TEST(TextFileWriterTests, canConstruct)
{
     TextFileWriter writer{"write.txt"};
}

TEST(TextFileWriterTests, canWriteToFile)
{
    TextFileWriter writer{"write.txt"};

    std::string s = "We are adding this string to the file";

    writer.writeLineToFile(s);
    writer.closeFile();

    TextFileReader reader{"write.txt"};
    
    EXPECT_EQ(reader.getCurrentLine(), s);   

}


