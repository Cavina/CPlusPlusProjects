//LinkedList.hpp
//
//A generic Singly LinkedList
#ifndef LINKEDLIST_hpp
#define LINKEDLIST_hpp


template <typename ValueType>
class LinkedList
{
        
    private:
        struct Node;

    public:
        //Default Constructor
        //Constructs an empty list
        LinkedList() noexcept;
        
        
        //Copy Constructor
        //This list becomes a copy of the argument.
        LinkedList(const LinkedList& list);
        
        //Move Constructor
        //Constructs this list with the contents of an expiring one.
        LinkedList(LinkedList&& list) noexcept;
        
        //Destructor
        ~LinkedList() noexcept;
        
        //Assignment copy
        //Copies and assigns a list to this one.
        LinkedList& operator=(const LinkedList& list);
        
        //Assignment move
        //Moves the contents of an expiring list to this one.
        LinkedList& operator=(LinkedList&& list) noexcept;
        
        //Add To Start of List
        //Adds a value to the start of the list
        void addToStart(const ValueType& value);
        
        //Add to End of List
        //Adds a value to the end of the list
        void addToEnd(const ValueType& value);
        
        //remove From start of list
        //Removes a node from the beginning of the list
        void removeFromStart();

        //remove from end of list
        //Removes a node from the end of the list
        void removeFromEnd();
       
        //return value at front of list
        //returns the value stored at the front of the list 
        const ValueType& first() const;

        //return value at end of list
        //returns the value stored at the end of the list
        const ValueType& last() const;
        
        //return if list is empty
        //returns true if the list is empty
        bool isEmpty() const noexcept;

        //return size of list
        unsigned int size() const noexcept;

    private:

        //Copies all nodes of a passed linkedlist and returns a pointer to the head node.
        Node* copyAll(const LinkedList& s);

        //Destroys all nodes of the list.
        //Is guaranteed to throw no exceptions.
        void destroyAll(Node* h) noexcept;



    private:
        struct Node
        {
            ValueType value;
            Node* next;
        };

        Node* head;


};


template <typename ValueType>
LinkedList<ValueType>::LinkedList() noexcept : head(nullptr){}


template <typename ValueType>
LinkedList<ValueType>::LinkedList(const LinkedList& list) : head(nullptr)
{
     if(this != &list)
     {
         try{
             head = copyAll(list); 
         }catch(...)
         {
             throw;
         }
     }
}

template <typename ValueType>
LinkedList<ValueType>::LinkedList(LinkedList&& list) noexcept : head(nullptr)
{
    if(this != &list)
    {
        this->head = list.head;
        list.head = nullptr;
    }
}


//Sets curr to the head of the to-be-copied list
//sets newHead to nullptr
//
//Create a new node and copy the old data into it.
//If an error occurs during creation, we destroy all the previously copied and head, and we 
//reset the head to null.  This provides a strong exception guarantee.
template <typename ValueType>
typename LinkedList<ValueType>::Node* LinkedList<ValueType>::copyAll(const LinkedList& list)
{
    Node* curr = list.head;
    Node* newHead = nullptr;

    try{
        while(curr != nullptr)
          {
             newHead = new Node{curr->value, newHead};
             curr = curr->next;
          }
          
          return newHead;
        }
        catch(...)
        {
            destroyAll(newHead);
            newHead = nullptr;
            throw;
        }
}


template <typename ValueType>
LinkedList<ValueType>& LinkedList<ValueType>::operator=(LinkedList&& list) noexcept
{
     if(this != &list)
     {
         destroyAll(this->head);
         this->head = list.head;
         list.head = nullptr;
     }
     return *this;
}

template <typename ValueType>
LinkedList<ValueType>& LinkedList<ValueType>::operator=(const LinkedList& list)
{
    if(this != &list)
    {
        Node* temp = nullptr;
        try{
            temp = copyAll(list);
            this->head = temp;
        }catch(...)
        {
            throw;
        }
          
    }
    return *this;
}

template <typename ValueType>
void LinkedList<ValueType>::destroyAll(Node* n) noexcept
{
     Node* curr = n;

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
LinkedList<ValueType>::~LinkedList() noexcept
{
    if(head != nullptr)
    {
        destroyAll(head);
        head = nullptr;
    }
}

template <typename ValueType>
void LinkedList<ValueType>::addToStart(const ValueType& value)
{
    Node* temp = nullptr;
    if(head != nullptr)
    {
        temp = head;
        try{
          head = new Node{value, temp};
        }catch(...)
        {
           throw;
        }
    }
    else
    {
        try{
         head = new Node{value, nullptr};
        }catch(...)
        {
            throw;
        }
    }

}

template <typename ValueType>
const ValueType& LinkedList<ValueType>::first() const
{
    return head->value;
}

template <typename ValueType>
const ValueType& LinkedList<ValueType>::last() const
{
    Node* curr = head;
    while(curr != nullptr)
    {
        if(curr->next == nullptr)
        {
             return curr->value;
        }

        curr = curr->next;
    }

    return head->value;

}

template <typename ValueType>
void LinkedList<ValueType>::addToEnd(const ValueType& value)
{
     Node* curr = head;
     if(curr == nullptr)
         try{
         head = new Node{value, nullptr};
         }catch(...)
     {
         throw;
     }


     while(curr != nullptr)
     {
         if(curr->next == nullptr)
         {
             try{
             curr->next = new Node{value, nullptr};
             break;
             }catch(...)
             {
                 throw;
             }
         
         }
         curr = curr->next;
     }

}

template <typename ValueType>
void LinkedList<ValueType>::removeFromStart()
{
    if(head != nullptr)
    {
         Node* temp = head;
         head = head->next;
         delete temp;
    }

}

template <typename ValueType>
void LinkedList<ValueType>::removeFromEnd()
{
    //TODO fix this
    Node* curr = head;
    if(curr == nullptr)
        return;
    while(curr != nullptr)
    {
       if(curr->next == nullptr && curr==head)
       {
           delete head;
           curr = nullptr;
           head = nullptr;
       }
       else if(curr->next == nullptr)
       {
           if(curr == head->next)
               head->next = nullptr;
           delete curr;
           curr = nullptr;
       }
       else
       {
           curr = curr->next;
       }

    }
     
}

#endif
