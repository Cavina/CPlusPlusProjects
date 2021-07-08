// MyLinkedListTests.cpp
//
// This is a set of tests for a linked list.
// Attempting to make all tests before implementing the linked list.


#include "../core/LinkedList.hpp"
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
TEST(MyLinkedListTests, copyListSizeZero)
{
     LinkedList<int> myList{};
     LinkedList<int> mySecondList{myList};

     EXPECT_EQ(myList.size(), mySecondList.size());
}

TEST(MyLinkedListTests, firstListStillIntactWhenCopy)
{
    //initiliaze list with data
     LinkedList<int> myList{};
     //copy data to another list
     LinkedList<int> mySecondList{myList};
     //change some data in second list
     mySecondList.addToStart(5);

     //check first list is still intact with original
     //data
     EXPECT_EQ(0, myList.size());
}

TEST(MyLinkedListTests, MoveConstructorWorks)
{
    LinkedList<int> list1{};
    list1.addToStart(5);
    LinkedList<int> list2(std::move(list1));

    EXPECT_EQ(5, list2.first());
    list1.addToStart(6);

    EXPECT_EQ(5, list2.first());
    EXPECT_EQ(6, list1.first());
}

TEST(MyLinkedListTests, canCopyAssign)
{
     LinkedList<int> list1{};
     list1.addToStart(5);
     LinkedList<int> list2{};

     list2 = list1;
     list1.addToStart(6);

     EXPECT_EQ(5, list2.first());
     EXPECT_EQ(6, list1.first());
}

TEST(MyLinkedListTests, canMoveAssign)
{
     LinkedList<int> list1{};
     list1.addToStart(5);

     LinkedList<int> list2{};
     
     list2 = std::move(list1);

     list1.addToStart(6);

     EXPECT_EQ(5, list2.first());



}

TEST(MyLinkedListTests, canAddToStartOfNewList)
{
     LinkedList<int> myList{};
     myList.addToStart(5);

     EXPECT_EQ(1, myList.size());
}

TEST(MyLinkedListTests, canAddToStartOfExistingList)
{
     LinkedList<int> myList{};
     myList.addToStart(5);
     myList.addToStart(6);

     EXPECT_EQ(2, myList.size());
}

TEST(MyLinkedListTests, canGetFirstValue)
{
     LinkedList<int> list{};
     list.addToStart(5);
     EXPECT_EQ(5, list.first());
     list.addToStart(6);
     EXPECT_EQ(6, list.first());
}

TEST(MyLinkedListTests, canGetLastValue)
{
     LinkedList<int> list{};
     list.addToStart(5);

     EXPECT_EQ(5, list.last());

     list.addToStart(6);

     EXPECT_EQ(6, list.first());
     EXPECT_EQ(5, list.last());
}

TEST(MyLinkedListTests, canAddToEndOfNewList)
{
     LinkedList<int> list{};

     list.addToEnd(5);

     EXPECT_EQ(1, list.size());
}

TEST(MyLinkedListTests, canAddToEndOfExistingList)
{
     LinkedList<int> list{};
     list.addToEnd(5);
     list.addToEnd(6);

     EXPECT_EQ(2, list.size());
     EXPECT_EQ(6, list.last());
}

TEST(MyLinkedListTests, canRemoveFromStartEmptyList)
{    
    LinkedList<int> list{};

    list.removeFromStart();

    EXPECT_EQ(0, list.size());
}

TEST(MyLinkedListTests, canRemoveFromStartExistingList)
{    
    LinkedList<int> list{};
    list.addToStart(5);
    list.removeFromStart();
    EXPECT_EQ(0, list.size());
    
    list.addToStart(5);
    list.addToStart(6);
    list.addToEnd(4);

    list.removeFromStart();
   

    EXPECT_EQ(5, list.first());
}


TEST(MyLinkedListTests, canRemoveFromEndEmptyList)
{
    LinkedList<int> list{};
    list.removeFromEnd(); 

    EXPECT_EQ(0, list.size());
}

TEST(MyLinkedListTests, canRemoveFromEndExistingList)
{
    LinkedList<int> list{};

    list.addToStart(5);
    list.removeFromEnd(); 
    EXPECT_EQ(0, list.size());

    list.addToStart(5);
    list.addToStart(6);

    list.removeFromEnd();

    EXPECT_EQ(6, list.last());
}

