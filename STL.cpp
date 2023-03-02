// This File Contains All the Functions That Are Required to Use the Data Structure Facilities.
#include <iostream>
using namespace std;

// ################################################################################################
//SLL-Start

//////////////////////// Structure For Singly Linked List //////////////////////

// #pragma pack(1)
template <class T>
struct  nodeS 
{
    T data;
    struct nodeS *next;
};

///////////////////////// Structure For Doubly Linked List /////////////////////

// #pragma pack(1)
template <class T>
struct nodeD
{
    T data;
    struct nodeD <T> *next;
    struct nodeD <T> *prev;  
};

//-----------------------------------------------------------------------------//
template <class T>
class SinglyLL
{
    public:
        struct nodeS <T> * First;

        SinglyLL();
        void InsertFirst(T No);
        void InsertLast(T No);
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPosition(T No, int iPos);
        void DeleteAtPosition(int iPos);
        void Display();
        int Count();

};

template <class T>
SinglyLL <T> :: SinglyLL()
{
    First = NULL;
}

//Function To InsertFirst Node In the Linked List.
template <class T>
void SinglyLL <T> :: InsertFirst(T No)
{
    nodeS <T> * newn = new nodeS <T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) //If Linked List is Empty.
    {
        First = newn;
    }
    else  //If Linked list Contains One or More Nodes.
    {
        newn->next = First;
        First = newn;
    }
}

//Function To Insert Last Node In the Linked List.
template <class T>
void SinglyLL <T> :: InsertLast(T No)
{
    struct nodeS <T> * newn = new struct nodeS <T>;

    newn->next = NULL;
    newn->data = No;

    if(First == NULL) //If Linked List is Empty.
    {
        First = newn;
    }
    else if(First->next == NULL) //if There is only single node in the linked list
    {
        First->next = newn;
    }
    else
    {
        struct nodeS <T>* temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

//Function To Delete First Node From the Linked List.
template <class T>
void SinglyLL <T> :: DeleteFirst()
{
    if(First == NULL)
    {
        cout<<"Linked List is Empty\n";
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct nodeS <T> *temp = First;
        First = First->next;
        delete temp;
    }
}

//Function To Delete Last Node From the Linked List.
template <class T>
void SinglyLL <T> :: DeleteLast()
{
    if(First == NULL)
    {
        cout<<"Linked List is Empty\n";
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct nodeS <T> *temp = First;
        
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
}

//Function To Insert the Node At Specific Position in the Linked List.
template <class T>
void SinglyLL <T> :: InsertAtPosition(T No, int iPos)
{   
    int iCount = Count();

    if(iPos < 1 || iPos > (iCount + 1))
    {
        cout<<"Invalid Position.\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == (iCount + 1))
    {
        InsertLast(No);
    }
    else
    {
        struct nodeS <T> *newn = new struct nodeS<T>;
        struct nodeS <T> *temp = First;

        newn->next = NULL;
        newn->data = No;

        for(int iCnt = 1;iCnt < (iPos - 1);iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

//Function To Delete the Node At Specific Position From the Linked List.
template <class T>
void SinglyLL <T> :: DeleteAtPosition(int iPos)
{
    int iCount = Count();

    if(iPos < 1 || iPos > (iCount))
    {
        cout<<"Invalid Position.\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == (iCount))
    {
        DeleteLast();
    }
    else
    {
        struct nodeS <T> *temp1 = First;
        struct nodeS <T> *temp2 = NULL;

        for(int iCnt = 1;iCnt < (iPos - 1);iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
    }
}

//Function To Display the Node's Inserted In the Linked List.
template <class T>
void SinglyLL <T> :: Display()
{
   nodeS <T> * temp = First;

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

//Function to count the Number Of Nodes inside the Linked List.
template <class T>
int SinglyLL <T> :: Count()
{
    nodeS <T> * temp = First;
    int iCnt = 0;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }

    return iCnt;
}

//SLL-End
// ################################################################################################
//SCLL-Start

template <class T>
class SinglyCLL
{
    public:
        struct nodeS <T> *First;
        struct nodeS <T> *Last;


        SinglyCLL();
        void InsertFirst(T No);
        void InsertLast(T No);
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPosition(T No, int iPos);
        void DeleteAtPosition(int iPos);
        void Display();
        int Count();
        
};

template <class T>
SinglyCLL <T> :: SinglyCLL()
{
    First = NULL;
    Last = NULL;
}

template <class T>
void SinglyCLL <T> :: InsertFirst(T No)
{
    struct nodeS <T>*newn = new struct nodeS<T>;

    newn->next = NULL;
    newn->data = No;

    if(First == NULL && Last == NULL)
    {
        First = Last = newn;
        newn->next = First;
    }
    else
    {
        newn->next = First;
        First = newn;
        Last->next = First;
    }
}

template <class T>
void SinglyCLL <T> :: InsertLast(T No)
{
    struct nodeS <T>*newn = new struct nodeS<T>;

    newn->next = NULL;
    newn->data = No;

    if(First == NULL && Last == NULL)
    {
        First = Last = newn;
        newn->next = First;
    }
    else
    {
        struct nodeS <T> *temp = First;
        do
        {
            temp = temp->next;
        } while (temp->next != Last->next);

        temp->next = newn;
        Last = newn;
        Last->next = First;
    }
}

template <class T>
void SinglyCLL <T> :: DeleteFirst()
{
    if(First == NULL && Last == NULL) //Linked List is Empty
    {
        cout<<"Linked List is Empty";
        return;
    }
    else if(First == Last) //LL contains Only one node
    {
        delete First;
        First = Last = NULL;
    }
    else //LL Contains more than one nodes.
    {
        First = First->next;
        delete Last->next;
        Last->next = First;
    }
}

template <class T>
void SinglyCLL <T> :: DeleteLast()
{
    if(First == NULL && Last == NULL) //Linked List is Empty
    {
        cout<<"Linked List is Empty";
        return;
    }
    else if(First == Last) //LL contains Only one node
    {
        delete First;
        First = Last = NULL;
    }
    else //LL Contains more than one nodes.
    {
        struct nodeS <T> *temp = First;
        do
        {
            temp = temp->next;
        } while (temp->next->next != Last->next);
        delete temp->next;
        Last = temp;
        Last->next = First;
    }
}

template <class T>
void SinglyCLL <T> :: InsertAtPosition(T No, int iPos)
{
    int iCount = Count();

    if(iPos < 1 || iPos > (iCount + 1))
    {
        cout<<"Invalid Position.\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == (iCount + 1))
    {
        InsertLast(No);
    }
    else
    {
        struct nodeS <T> *newn = new struct nodeS<T>;
        struct nodeS <T> *temp = First;

        newn->next = NULL;
        newn->data = No;

        for(int iCnt = 1;iCnt < (iPos - 1);iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

template <class T>
void SinglyCLL <T> :: DeleteAtPosition(int iPos)
{
    int iCount = Count();

    if(iPos < 1 || iPos > (iCount))
    {
        cout<<"Invalid Position.\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == (iCount))
    {
        DeleteLast();
    }
    else
    {
        struct nodeS <T> *temp1 = First;
        struct nodeS <T> *temp2 = NULL;

        for(int iCnt = 1;iCnt < (iPos - 1);iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
    }
}

template <class T>
void SinglyCLL <T> :: Display()
{
    struct nodeS <T> * temp = First;
    do
    {   
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }while(temp != Last->next);
    cout<<"\n";
}

template <class T>
int SinglyCLL <T> :: Count()
{
    struct nodeS <T> * temp = First;
    int iCnt = 0;
    do
    {   
        iCnt++;
        temp = temp->next;
    }while(temp != Last->next);

    return iCnt;
}

//SCLL-End
// ################################################################################################
//DLL-Start

template <class T>
class DoublyLL
{
    public:
        struct nodeD <T> *First;

        DoublyLL();
        void InsertFirst(T Data);
        void InsertLast(T Data);
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPosition(T Data, int iPos);
        void DeleteAtPosition(int iPos);
        void Display();
        int Count();
};

template <class T>
DoublyLL <T> :: DoublyLL()
{
    First = NULL;
}

template <class T>
void DoublyLL <T> :: InsertFirst(T Data)
{
    struct nodeD <T> * newn = new struct nodeD<T>;

    newn->next = NULL;
    newn->prev = NULL;
    newn->data = Data;

    if(First == NULL)  //LL is Empty
    {
        First = newn;
    }
    else //LL contains one or more nodes
    {   
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
}

template <class T>
void DoublyLL <T> :: InsertLast(T Data)
{
    struct nodeD <T> * newn = new struct nodeD<T>;

    newn->next = NULL;
    newn->prev = NULL;
    newn->data = Data;

    if(First == NULL)  //LL is Empty
    {
        First = newn;
    }
    else if(First->next == NULL)//LL contains single Node.
    {   
        newn->prev = First;
        First->next = newn;
    }
    else //LL contains more than one Node.
    {
        struct nodeD <T> *temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        newn->prev = temp;
        temp->next = newn;
    }
}

template <class T>
void DoublyLL <T> :: DeleteFirst()
{
    if(First == NULL) //LL is empty
    {
        cout<<"Linked List is Empty";
        return;
    }
    else if(First->next == NULL) //LL contains single node
    {
        delete First;
        First = NULL;
    }
    else  //LL contains more than one node's
    {
        First = First->next;
        delete First->prev;
        First->prev = NULL;
    }
}

template <class T>
void DoublyLL <T> :: DeleteLast()
{
    if(First == NULL)  //LL is empty
    {
        cout<<"Linked List is Empty";
        return;
    } 
    else if(First->next == NULL)  //LL contains single node
    {
        delete First;
        First = NULL;
    }
    else  //LL contains more than one node's.
    {
        struct nodeD <T> *temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
}

template <class T>
void DoublyLL <T> :: InsertAtPosition(T Data, int iPos)
{
    int iCount = Count();

    if(iPos < 1 || iPos > (iCount + 1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(Data);
    }
    else if(iPos == (iCount + 1))
    {
        InsertLast(Data);
    }
    else
    {
        struct nodeD <T> *newn = new struct nodeD <T>;
        struct nodeD <T> *temp = First;
        newn->next = NULL;
        newn->prev = NULL;
        newn->data = Data;

        for(int iCnt = 1;iCnt < (iPos - 1);iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        newn->prev = temp;
    }
}

template <class T>
void DoublyLL <T> :: DeleteAtPosition(int iPos)
{
    int iCount = Count();

    if(iPos < 1 || iPos > (iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == (iCount))
    {
        DeleteLast();
    }
    else
    {
        struct nodeD <T> *temp1 = First;
        struct nodeD <T> *temp2 = NULL;

        for(int iCnt = 1;iCnt < (iPos - 1);iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
        temp2->prev = temp1;
    }   
}

template <class T>
void DoublyLL <T> :: Display()
{
    struct nodeD <T> * temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template <class T>
int DoublyLL <T> :: Count()
{
    struct nodeD <T> * temp = First;
    int iCnt = 0;
    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }

    return iCnt;
}

//DLL-End
// ################################################################################################
//DCLL-Start

template <class T>
class DoublyCLL
{
    public:
        struct nodeD <T> *First;
        struct nodeD <T> *Last;

        DoublyCLL();
        void InsertFirst(T Data);
        void InsertLast(T Data);
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPosition(T Data, int iPos);
        void DeleteAtPosition(int iPos);
        void Display();
        int Count();
};

template <class T>
DoublyCLL <T> :: DoublyCLL()
{
    First = Last = NULL;
}

template <class T>
void DoublyCLL <T> :: InsertFirst(T Data)
{
    struct nodeD <T> * newn = new struct nodeD<T>;

    newn->next = NULL;
    newn->prev = NULL;
    newn->data = Data;

    if(First == NULL && Last == NULL)  //LL is Empty
    {
        First = Last = newn;
    }
    else //LL contains one or more Node's
    {       
        newn->next = First;
        First = newn;
        Last->next = First;
        First->prev = Last;
    }
    
}

template <class T>
void DoublyCLL <T> :: InsertLast(T Data)
{
    struct nodeD <T> * newn = new struct nodeD<T>;

    newn->next = NULL;
    newn->prev = NULL;
    newn->data = Data;

    if(First == NULL && Last == NULL)  //LL is Empty
    {
        First = Last = newn;
    }
    else if(First == Last)//LL contains single Node.
    {   
        First->next = newn;
        newn->prev = First;
        Last = newn;
        Last->next = First;
        First->prev = Last;
    }
    else //LL contains more than one Node.
    {
        struct nodeD <T> *temp = First;

        do
        {
            temp = temp->next;
        }while (temp->next != First);

        newn->prev = temp;
        temp->next = newn;
        Last = newn;
        Last->next = First;
        First->prev = Last;
    }
}

template <class T>
void DoublyCLL <T> :: DeleteFirst()
{
    if(First == NULL && Last == NULL) //LL is empty
    {
        cout<<"Linked List is Empty";
        return;
    }
    else if(First == Last) //LL contains single node
    {
        delete First;
        First = Last = NULL;
    }
    else  //LL contains more than one node's
    {
        First = First->next;
        delete Last->next;
        Last->next = First;
        First->prev = Last;
    }
}

template <class T>
void DoublyCLL <T> :: DeleteLast()
{
    if(First == NULL)  //LL is empty
    {
        cout<<"Linked List is Empty";
        return;
    } 
    else if(First->next == NULL)  //LL contains single node
    {
        delete First;
        First = NULL;
    }
    else  //LL contains more than one node's.
    {
        struct nodeD <T> *temp = First;

        do
        {
            temp = temp->next;
        }while(temp->next->next != First);
        delete temp->next;
        Last = temp;
        Last->next = First;
        First->prev = Last;
    }
}

template <class T>
void DoublyCLL <T> :: InsertAtPosition(T Data, int iPos)
{
    int iCount = Count();

    if(iPos < 1 || iPos > (iCount + 1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(Data);
    }
    else if(iPos == (iCount + 1))
    {
        InsertLast(Data);
    }
    else
    {
        struct nodeD <T> *newn = new struct nodeD <T>;
        struct nodeD <T> *temp = First;
        newn->next = NULL;
        newn->prev = NULL;
        newn->data = Data;

        for(int iCnt = 1;iCnt < (iPos - 1);iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        newn->prev = temp;
    }
}

template <class T>
void DoublyCLL <T> :: DeleteAtPosition(int iPos)
{
    int iCount = Count();

    if(iPos < 1 || iPos > (iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == (iCount))
    {
        DeleteLast();
    }
    else
    {
        struct nodeD <T> *temp1 = First;
        struct nodeD <T> *temp2 = NULL;

        for(int iCnt = 1;iCnt < (iPos - 1);iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
        temp2->prev = temp1;
    }   
}

template <class T>
void DoublyCLL <T> :: Display()
{
    struct nodeD <T> * temp = First;

    do
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    }while(temp != Last->next);
    cout<<"NULL\n";
}

template <class T>
int DoublyCLL <T> :: Count()
{
    struct nodeD <T> * temp = First;
    int iCnt = 0;
    do
    {
        iCnt++;
        temp = temp->next;
    }while(temp != Last->next);

    return iCnt;
}

// DCLL-End
// ################################################################################################
//Stack -Start

template <class T>
class Stack
{
    public:
        struct nodeS <T> *First;
        int iCount;

        Stack();

        bool IsStackEmpty();
        void Push(T No); 
        T Pop();  
        void Display();        
};

template <class T>
Stack <T>:: Stack()
{
    First = NULL;
    iCount = 0;

}

template <class T>
bool Stack <T> :: IsStackEmpty()
{
    if(iCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
void Stack <T> :: Push(T No)
{
    struct nodeS <T> *newn = new nodeS <T>;
    
    newn->next = NULL;
    newn->data = No;

    if(First == NULL) 
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
    cout<<No<<" gets pushed in the stack successfully"<<"\n";
}

template <class T>
T Stack <T> :: Pop() 
{
    if(First == NULL)
    {
        cout<<"Unable to po the element as stack is empty."<<"\n";
        return -1;
    }
    else
    {
        T value = First->data;
        struct nodeS <T> *temp = First;

        First = First->next;
        delete temp;

        iCount--;

        return value;
    }
}

template <class T>
void Stack <T> :: Display()
{
    if(First == NULL)
    {
        cout<<"Stack is Empty.\n";
    }
    else
    {
        cout<<"Elements of the stack are : \n";
        
        struct nodeS <T> *temp = First;
        while(temp != NULL)
        {
            cout<<"| "<<temp->data<<" |->";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
}

//Stack- End
// ################################################################################################
//Queue -Start

template <class T>
class Queue
{
    public:
        struct nodeS <T> *First;
        int iCount;

        Queue();

        bool IsQueueEmpty();
        void EnQueue(T No);  
        T DeQueue();  
        void Display();         
};

template <class T>
Queue <T>:: Queue()
{
    First = NULL;
    iCount = 0;

}

template <class T>
bool Queue <T> :: IsQueueEmpty()
{
    if(iCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
void Queue <T> :: EnQueue(T No) 
{
    struct nodeS <T> *newn = new nodeS <T>;
    
    newn->next = NULL;
    newn->data = No;

    if(First == NULL) 
    {
        First = newn;
    }
    else
    {
        struct nodeS <T> *temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    
    iCount++;
    cout<<No<<" gets pushed in the Queue successfully"<<"\n";
}

template <class T>
T Queue <T> :: DeQueue() //DeleteFirst
{
    if(First == NULL)
    {
        cout<<"Unable to po the element as Queue is empty."<<"\n";
        return -1;
    }
    else
    {
        T value = First->data;
        struct nodeS <T> *temp = First;

        First = First->next;
        delete temp;

        iCount--;

        return value;
    }
}

template <class T>
void Queue <T> :: Display()
{
    if(First == NULL)
    {
        cout<<"Queue is Empty.\n";
    }
    else
    {
        cout<<"Elements of the Queue are : \n";
        
        struct nodeS <T> *temp = First;
        while(temp != NULL)
        {
            cout<<"| "<<temp->data<<" |->";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
}

//Queue-End

// ################################################################################################
// To Creat the Shared Library Files on Diff Platforms :

// Windows -> DLL (Dynamic Link Library)
// Linux -> SO (Shared Object)
// macOS -> DYLIB (Dynamic Library)

// int main()
// {
//     SinglyLL <int>obj1;
//     SinglyCLL <int>obj2;
//     DoublyLL <int>obj3;
//     DoublyCLL <int>obj4;
//     Stack <int>obj5;
//     Queue<int>obj6;

//     return 0;
// }