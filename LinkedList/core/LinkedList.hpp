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
        
        //Move Constructor
        LinkedList(LinkedList&& list) noexcept;
        //
        
        //Destructor
        ~LinkedList() noexcept;
        //
        
        //Assignment copy
        LinkedList& operator=(const LinkedList& list);
        //
        
        //Assignment move
        LinkedList& operator=(LinkedList&& list) noexcept;
        
        
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
        const ValueType& first() const;
        //
        //return value at end of list
        const ValueType& last() const;
        
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


};


template <typename ValueType>
LinkedList<ValueType>::LinkedList() noexcept : head(nullptr), tail(nullptr){}

template <typename ValueType>
LinkedList<ValueType>::LinkedList(const LinkedList& list)
{
     if(this != &list)
     {
         head = copyAll(list); 
         tail = list.tail;
     }
}

template <typename ValueType>
LinkedList<ValueType>::LinkedList(LinkedList&& list) noexcept
{
    if(this != &list)
    {
        this->head = list.head;
        list.head = nullptr;
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

     return newHead;
}

template <typename ValueType>
LinkedList<ValueType>& LinkedList<ValueType>::operator=(LinkedList&& list) noexcept
{
     if(this != &list)
     {
         destroyAll();
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
LinkedList<ValueType>::~LinkedList() noexcept
{
    if(head != nullptr)
    {
        destroyAll();
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
