//FileReaderTests.cpp
//A set of tests for the file reader

#include <gtest/gtest.h>
#include "../core/TextFileReader.hpp"

TEST(FileReaderTests, canOpenFile)
{
    TextFileReader fr{"input.txt"};

}

TEST(FileReaderTests, GoodStateIfCantReadFile)
{
     TextFileReader fr{"nofile.txt"};
}

TEST(FileReaderTests, returnsEmptyStringIfNoFile)
{
     TextFileReader fr{"nofile.txt"};

     EXPECT_EQ(fr.getCurrentLine(), "");
}


TEST(FileReaderTests, canReadLine)
{
     TextFileReader fr{"input.txt"};
     EXPECT_EQ(fr.getCurrentLine(), "This is a test");
}

TEST(FileReaderTests, isNotEndOfFile)
{
     TextFileReader fr{"input.txt"};
     EXPECT_EQ(fr.getCurrentLine(), "This is a test");
     fr.advanceToNextLine();
     EXPECT_EQ(fr.endOfFile(), false);
}

TEST(FileReaderTests, isEndOfFile)
{
     TextFileReader fr{"input.txt"};
     while(fr.getCurrentLine() != "")
     {
          fr.advanceToNextLine();
     }

     EXPECT_EQ(fr.endOfFile(), true);
}
