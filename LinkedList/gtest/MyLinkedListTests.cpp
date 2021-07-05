// MyLinkedListTests.cpp
//
// This is a set of tests for a linked list.
// Attempting to make all tests before implementing the linked list.


#include "LinkedList.hpp"
#include <gtest/gtest.h>

//The constructor is empty when default constructed
TEST(MyLinkedListTests, emptyWhenDefaultConstructed)
{
     LinkedList<int> myList{};

     EXPECT_TRUE(myList.isEmpty());
}

//The length of the list is zero when default constructed
TEST(MyLinkedListTests, lengthIsZeroWhenDefaultConstructed)
{
     LinkedList<int> myList{};
     
     EXPECT_EQ(0, myList.size());
}

//Copy constructor
