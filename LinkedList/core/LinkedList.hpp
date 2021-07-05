//LinkedList.hpp
//
//A generic LinkedList
#ifndef LINKEDLIST_hpp
#define LINKEDLIST_hpp


template <typename ValueType>
class LinkedList
{
        
    private:
        struct Node;

    public:
        //Default Constructor
        LinkedList() noexcept;
        
        
        //Copy Constructor
        LinkedList(const LinkedList& list);
        //
        /*
        //Move Constructor
        LinkedList(const LinkedList&& list);
        //
        */
        //Destructor
        ~LinkedList();
        //
        /*
        //Assignment copy
        LinkedList& operator=(const LinkedList& list);
        //
        //Assignment move
        LinkedList& operator=(const LinkedList&& list);
        //
        //Add To Start of List
        void addToStart(const ValueType& value);
        //
        //Add to End of List
        void addToEnd(const ValueType& value);
        //
        //remove From start of list
        void removeFromStart();
        //
        //remove from end of list
        void removeFromEnd();
        //
        //return value at front of list
        const ValueType& getFirst() const;
        //
        //return value at end of list
        const ValueType& getEnd() const;
        */
        //
        //return if list is empty
        bool isEmpty() const noexcept;
        //
        //return size of list
        unsigned int size() const noexcept;

    private:
        Node* copyAll(const LinkedList& s);
        void destroyAll() noexcept;



    private:
        struct Node
        {
            ValueType value;
            Node* next;
        };

        Node* head;
        Node* tail;
        unsigned int length;


};


template <typename ValueType>
LinkedList<ValueType>::LinkedList() noexcept : head(nullptr), tail(nullptr), length(){}

template <typename ValueType>
LinkedList<ValueType>::LinkedList(const LinkedList& list)
{
     if(this != &list)
     {
         head = copyAll(list); 
     }
}

template <typename ValueType>
typename LinkedList<ValueType>::Node* LinkedList<ValueType>::copyAll(const LinkedList& list)
{
    Node* curr = list.head;
    Node* newHead = nullptr;

    //Initializes the newHead with the value, AFTER setting next to nullptr.
    
    while(curr != nullptr)
    {
        newHead = new Node{curr->value, newHead};
        curr = curr->next;
    }


}

template <typename ValueType>
void LinkedList<ValueType>::destroyAll() noexcept
{
     Node* curr = this->head;

     while (curr != nullptr)
     {
          Node* temp = curr;
          curr = curr->next;
          delete temp;
     }
}

template <typename ValueType>
unsigned int LinkedList<ValueType>::size() const noexcept
{
     Node* curr = head;
     unsigned int count = 0;

     while(curr != nullptr)
     {
          ++count;
          curr = curr->next;
     }

     return count;
}

template <typename ValueType>
bool LinkedList<ValueType>::isEmpty() const noexcept
{
     return (size() == 0);
}

template <typename ValueType>
LinkedList<ValueType>::~LinkedList()
{
     destroyAll();
     head = nullptr;
}
#endif
