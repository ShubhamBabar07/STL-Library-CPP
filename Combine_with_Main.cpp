// Combine Generic SinglyLL & SinglyCL & DoublyLL & DoublyCL & Stack & Queue

#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////
//
// Code of Singly Linear
//
/////////////////////////////////////////////////////////////
template <class T>
struct nodeSL
{
    T data;
    struct nodeSL *next;
};

template <class T>
class SinglyLL
{
    private:
        struct nodeSL<T> * First;
        int iCount;

    public:
        SinglyLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::Display()
{
    struct nodeSL<T> * temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct nodeSL<T> * newn = NULL;

    newn = new nodeSL<T>; 

    newn->data = No;
    newn->next = NULL;

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
}

template <class T>
void SinglyLL<T>::InsertLast(T No)
{
    struct nodeSL<T> * newn = NULL;
    struct nodeSL<T> * temp = First;

    newn = new nodeSL<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) 
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeSL<T> * newn = NULL;
    int i = 0;
    struct nodeSL<T> * temp;

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else 
    {
        temp = First;
        
        newn = new nodeSL<T>;
        newn->data = No;
        newn->next = NULL;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp -> next = newn;
        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First -> next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp ->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeSL<T> * temp1;
    struct nodeSL<T> * temp2;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else 
    {
        temp1 = First;

        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }    
}


/////////////////////////////////////////////////////////////
//
// Code of Singly Circular
//
/////////////////////////////////////////////////////////////
template <class T>
struct nodeSC
{
    T data;
    struct nodeSC *next;
};

template <class T>
class SinglyCL
{
    private:
        struct nodeSC<T> * First;
        struct nodeSC<T> * Last;
        int iCount;

    public:
        SinglyCL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
SinglyCL<T>::SinglyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void SinglyCL<T>::Display()
{
    if((First == NULL) && (Last == NULL))
    {
        cout<<"Linked list is Empty"<<endl;
        return;
    }

    cout<<"->";
    do
    {
        cout<<"| "<<First->data<<" |->";
        First = First->next;
    }while(First != Last->next);

    cout<<"\n";
}

template <class T>
int SinglyCL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyCL<T>::InsertFirst(T No)
{
    struct nodeSC<T> * newn = NULL;

    newn = new nodeSC<T>;

    newn->data = No;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    Last->next = First;

    iCount++;
}

template <class T>
void SinglyCL<T>::InsertLast(T No)
{
    struct nodeSC<T> * newn = NULL;

    newn = new nodeSC<T>;

    newn->data = No;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        Last = newn;
    }
    Last->next = First;

    iCount++;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T No, int iPos)
{
    int i = 0;
    struct nodeSC<T> * temp = NULL;
    struct nodeSC<T> * newn = NULL;

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        temp = First;
        
        newn = new nodeSC<T>;
        newn->data = No;
        newn->next = NULL;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if((First == NULL) && (Last == NULL)) 
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First == Last)  
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    
    {
        First = First -> next;
        delete Last->next;
        Last -> next = First;
    }

    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
    struct nodeSC<T> * temp = NULL;

    if((First == NULL) && (Last == NULL)) 
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First == Last)   
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    
    {
        temp = First;

        while(temp->next != Last)
        {
            temp = temp->next;
        }

        delete Last;
        Last = temp;
        Last->next = First;
    }

    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeSC<T> * temp1 = NULL;
    struct nodeSC<T> * temp2 = NULL;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1->next;

        temp1 -> next = temp2->next;
        delete temp2;

        iCount--;
    }
}


/////////////////////////////////////////////////////////////
//
// Code of Doubly Linear
//
/////////////////////////////////////////////////////////////
template <class T>
struct nodeDL
{
    T data;
    struct nodeDL *next;
    struct nodeDL *prev;
};

template <class T>
class DoublyLL
{
    private:
        struct nodeDL<T> * First;
        int iCount;

    public:
        DoublyLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);        
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
DoublyLL<T>::DoublyLL()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T>::Display()
{
    struct nodeDL<T> * temp = First;

    cout<<"NULL<=>";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T>::InsertFirst(T No)
{
    struct nodeDL<T> * newn = NULL;

    newn = new nodeDL<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        First->prev = newn;
        newn->next = First;
        First = newn;
    }

    iCount++;
}

template <class T>
void DoublyLL<T>::InsertLast(T No)
{
    struct nodeDL<T> * newn = NULL;
    struct nodeDL<T> * temp = First;

    newn = new nodeDL<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }

    iCount++;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDL<T> * newn = NULL;
    struct nodeDL<T> * temp = NULL;
    int i = 0;

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else 
    {
        newn = new nodeDL<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;
        
        for(i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }

        temp->next->prev = newn;
        newn->next = temp->next;
        temp->next = newn;
        newn->prev = temp;
        
        iCount++;
    }
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First -> next;
        delete First->prev;
        First->prev = NULL;
    }

    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    struct nodeDL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp ->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    struct nodeDL<T> * temp = First;
    int i = 0;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else 
    {
        for(i = 1; i < iPos-1; i++)
        {
            temp = temp -> next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        
        iCount--;
    }
}


/////////////////////////////////////////////////////////////
//
// Code of Doubly Circular
//
/////////////////////////////////////////////////////////////
template <class T>
struct nodeDC
{
    T data;
    struct nodeDC *next;
    struct nodeDC *prev;
};

template <class T>
class DoublyCL
{
    private:
        struct nodeDC<T> * First;
        struct nodeDC<T> * Last;
        int iCount;

    public:
        DoublyCL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
DoublyCL<T>:: DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T>::Display()
{
    if(First == NULL && Last == NULL)
    {
        cout<<"Linked List is emprty\n";
        return;
    }

    cout<<"<=>";
    do
    {
        cout<<"| "<<First->data <<" |<=>";
        First = First -> next;
    }while(Last->next != First);

    cout<<"\n";
}

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::InsertFirst(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;
}

template <class T>
void DoublyCL<T>::InsertLast(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last ->next = newn;
        newn->prev = Last;
        Last = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;    
}

template <class T>
void DoublyCL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDC<T> * temp = NULL;
    struct nodeDC<T> * newn = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid postion\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeDC<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if(First == NULL && Last == NULL) 
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First == Last) 
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else  
    {
        First = First -> next;
        delete Last->next;
        First -> prev = Last;
        Last -> next = First;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if(First == NULL && Last == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First == Last)  
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else 
    {
        Last = Last -> prev;
        delete First -> prev;

        Last -> next = First;
        First -> prev = Last;
    }
    iCount--;    
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    struct nodeDC<T> * temp = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid postion\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }    
}


/////////////////////////////////////////////////////////////
//
// Code of Stack
//
/////////////////////////////////////////////////////////////
template <class T>
struct nodeST
{
    T data;
    struct nodeST *next;
};

template <class T>
class Stack
{
    private:
        struct nodeST<T> * First;
        int iCount;

    public:
        Stack();
        void Display();
        int Count();
        void Push(T No);      // InsertFirst()
        T Pop();              // DeleteFirst()
};

template <class T>
Stack<T>::Stack()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void Stack<T>::Display()
{
    cout<<"Elements of Stack are : \n";
    struct nodeST<T> * temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<"\n";
        temp = temp->next;
    }
}

template <class T>
int Stack<T>::Count()
{
    return iCount;
}

template <class T>
void Stack<T>::Push(T No) 
{
    struct nodeST<T> * newn = NULL;

    newn = new nodeST<T>;

    newn->data = No;
    newn->next = NULL;

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
}

template <class T>
T Stack<T>::Pop()
{
    T iValue = 0;
    struct nodeST<T> * temp = NULL;

    if(First == NULL)
    {
        cout<<"Unable to Pop the element as stack is empty\n";
        return -1;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        temp = First;

        iValue = First->data;
        First = First->next;
        delete temp; 
    }
    iCount--;
    return iValue;
}


/////////////////////////////////////////////////////////////
//
// Code of Queue
//
/////////////////////////////////////////////////////////////
template <class T>
struct nodeQU
{
    T data;
    struct nodeQU *next;
};

template <class T>
class Queue
{
    private:
        struct nodeQU<T> * First;
        int iCount;

   public:
        Queue();
        void Display();
        int Count();
        void EnQueue(T No);       // InsertLast()
        T DeQueue();              // DeleteFirst()
};

template <class T>
Queue<T>::Queue()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void Queue<T>::Display()
{
    cout<<"Elements of Queue are : \n";
    struct nodeQU<T> * temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp->next;
    }
    cout<<"\n";
}

template <class T>
int Queue<T>::Count()
{
    return iCount;
}

template <class T>
void Queue<T>::EnQueue(T No) 
{
    struct nodeQU<T> * temp = First;
    struct nodeQU<T> * newn = new nodeQU<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        while(temp ->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
T Queue<T>::DeQueue()
{
    T iValue = 0;
    struct nodeQU<T> * temp = NULL;

    if(First == NULL)
    {
        cout<<"Unable to remove the element as Queue is empty\n";
        return -1;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        temp = First;

        iValue = First->data;
        First = First->next;
        delete temp; 
    }
    iCount--;
    return iValue;
}


/////////////////////////////////////////////////////////////
//
// Main Function
//
/////////////////////////////////////////////////////////////
int main()
{
    int iRet = 0;

    /////////////////////////////////////////////////////////////
    //
    // Call of Singly Linear
    //
    /////////////////////////////////////////////////////////////
    cout<<"-------------------------------------------------------------\n";
    cout<<"\t\t Singly Linear LinkedList \n";
    cout<<"-------------------------------------------------------------\n";

    // LL of integer
    cout<<"-------------- LinkdList of Integers --------------\n";

    SinglyLL<int> *iSLobj = new SinglyLL<int>();

    iSLobj->InsertFirst(51);
    iSLobj->InsertFirst(21);
    iSLobj->InsertFirst(11);

    iSLobj->InsertLast(101);
    iSLobj->InsertLast(111);
    iSLobj->InsertLast(121);
    
    iSLobj->Display();
    iRet = iSLobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    iSLobj->InsertAtPos(105,5);
    iSLobj->Display();
    iRet = iSLobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    iSLobj->DeleteAtPos(5);
    iSLobj->Display();
    iRet = iSLobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;


    // LL of character
    cout<<"-------------- LinkdList of Chracters --------------\n";

    SinglyLL<char> *cSLobj = new SinglyLL<char>();

    cSLobj->InsertFirst('D');
    cSLobj->InsertFirst('F');
    cSLobj->InsertFirst('R');

    cSLobj->InsertLast('E');
    cSLobj->InsertLast('Y');
    cSLobj->InsertLast('U');
    
    cSLobj->Display();
    iRet = cSLobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    cSLobj->InsertAtPos('W',5);
    cSLobj->Display();
    iRet = cSLobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    cSLobj->DeleteAtPos(5);
    cSLobj->Display();
    iRet = cSLobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;


    // LL of float
    cout<<"-------------- LinkdList of Floats --------------\n";

    SinglyLL<float> *fSLobj = new SinglyLL<float>();

    fSLobj->InsertFirst(90.78f);
    fSLobj->InsertFirst(78.99f);
    fSLobj->InsertFirst(67.99f);

    fSLobj->InsertLast(45.67f);
    fSLobj->InsertLast(54.78f);
    fSLobj->InsertLast(77.89f);
    
    fSLobj->Display();
    iRet = fSLobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    fSLobj->InsertAtPos(88.56,5);
    fSLobj->Display();
    iRet = fSLobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    fSLobj->DeleteAtPos(5);
    fSLobj->Display();
    iRet = fSLobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;


    // LL of double
    cout<<"-------------- LinkdList of Doubles --------------\n";

    SinglyLL<double> *dSLobj = new SinglyLL<double>();

    dSLobj->InsertFirst(90.78978);
    dSLobj->InsertFirst(78.99645);
    dSLobj->InsertFirst(67.9934);

    dSLobj->InsertLast(45.67867);
    dSLobj->InsertLast(54.78534);
    dSLobj->InsertLast(77.89324);
    
    dSLobj->Display();
    iRet = dSLobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dSLobj->InsertAtPos(88.56987,5);
    dSLobj->Display();
    iRet = dSLobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dSLobj->DeleteAtPos(5);
    dSLobj->Display();
    iRet = dSLobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;


    /////////////////////////////////////////////////////////////
    //
    // Call of Singly Circular
    //
    /////////////////////////////////////////////////////////////
    cout<<"-------------------------------------------------------------\n";
    cout<<"\t\t Singly Circular LinkedList \n";
    cout<<"-------------------------------------------------------------\n";

    // LL of integer
    cout<<"-------------- LinkdList of Integers --------------\n";

    SinglyCL<int> *iSCobj = new SinglyCL<int>();

    iSCobj->InsertFirst(51);
    iSCobj->InsertFirst(21);
    iSCobj->InsertFirst(11);

    iSCobj->InsertLast(101);
    iSCobj->InsertLast(111);
    iSCobj->InsertLast(121);
    
    iSCobj->Display();
    iRet = iSCobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    iSCobj->InsertAtPos(105,5);
    iSCobj->Display();
    iRet = iSCobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    iSCobj->DeleteAtPos(5);
    iSCobj->Display();
    iRet = iSCobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;


    // LL of character
    cout<<"-------------- LinkdList of Chracters --------------\n";

    SinglyCL<char> *cSCobj = new SinglyCL<char>();

    cSCobj->InsertFirst('D');
    cSCobj->InsertFirst('F');
    cSCobj->InsertFirst('R');

    cSCobj->InsertLast('E');
    cSCobj->InsertLast('Y');
    cSCobj->InsertLast('U');
    
    cSCobj->Display();
    iRet = cSCobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    cSCobj->InsertAtPos('W',5);
    cSCobj->Display();
    iRet = cSCobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    cSCobj->DeleteAtPos(5);
    cSCobj->Display();
    iRet = cSCobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;


    // LL of float
    cout<<"-------------- LinkdList of Floats --------------\n";

    SinglyCL<float> *fSCobj = new SinglyCL<float>();

    fSCobj->InsertFirst(90.78f);
    fSCobj->InsertFirst(78.99f);
    fSCobj->InsertFirst(67.99f);

    fSCobj->InsertLast(45.67f);
    fSCobj->InsertLast(54.78f);
    fSCobj->InsertLast(77.89f);
    
    fSCobj->Display();
    iRet = fSCobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    fSCobj->InsertAtPos(88.56,5);
    fSCobj->Display();
    iRet = fSCobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    fSCobj->DeleteAtPos(5);
    fSCobj->Display();
    iRet = fSCobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;


    // LL of double
    cout<<"-------------- LinkdList of Doubles --------------\n";

    SinglyCL<double> *dSCobj = new SinglyCL<double>();

    dSCobj->InsertFirst(90.78978);
    dSCobj->InsertFirst(78.99645);
    dSCobj->InsertFirst(67.9934);

    dSCobj->InsertLast(45.67867);
    dSCobj->InsertLast(54.78534);
    dSCobj->InsertLast(77.89324);
    
    dSCobj->Display();
    iRet = dSCobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dSCobj->InsertAtPos(88.56987,5);
    dSCobj->Display();
    iRet = dSCobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dSCobj->DeleteAtPos(5);
    dSCobj->Display();
    iRet = dSCobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;


    /////////////////////////////////////////////////////////////
    //
    // Call of Doubly Linear
    //
    /////////////////////////////////////////////////////////////
    cout<<"-------------------------------------------------------------\n";
    cout<<"\t\t Doubly Linear LinkedList \n";
    cout<<"-------------------------------------------------------------\n";

    // LL of integer
    cout<<"-------------- LinkdList of Integers --------------\n";

    DoublyLL<int> *iDLobj = new DoublyLL<int>();

    iDLobj->InsertFirst(51);
    iDLobj->InsertFirst(21);
    iDLobj->InsertFirst(11);

    iDLobj->InsertLast(101);
    iDLobj->InsertLast(111);
    iDLobj->InsertLast(121);
    
    iDLobj->Display();
    iRet = iDLobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    iDLobj->InsertAtPos(105,5);
    iDLobj->Display();
    iRet = iDLobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    iDLobj->DeleteAtPos(5);
    iDLobj->Display();
    iRet = iDLobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;


    // LL of character
    cout<<"-------------- LinkdList of Chracters --------------\n";

    DoublyLL<char> *cDLobj = new DoublyLL<char>();

    cDLobj->InsertFirst('D');
    cDLobj->InsertFirst('F');
    cDLobj->InsertFirst('R');

    cDLobj->InsertLast('E');
    cDLobj->InsertLast('Y');
    cDLobj->InsertLast('U');
    
    cDLobj->Display();
    iRet = cDLobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    cDLobj->InsertAtPos('W',5);
    cDLobj->Display();
    iRet = cDLobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    cDLobj->DeleteAtPos(5);
    cDLobj->Display();
    iRet = cDLobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;


    // LL of float
    cout<<"-------------- LinkdList of Floats --------------\n";

    DoublyLL<float> *fDLobj = new DoublyLL<float>();

    fDLobj->InsertFirst(90.78f);
    fDLobj->InsertFirst(78.99f);
    fDLobj->InsertFirst(67.99f);

    fDLobj->InsertLast(45.67f);
    fDLobj->InsertLast(54.78f);
    fDLobj->InsertLast(77.89f);
    
    fDLobj->Display();
    iRet = fDLobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    fDLobj->InsertAtPos(88.56,5);
    fDLobj->Display();
    iRet = fDLobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    fDLobj->DeleteAtPos(5);
    fDLobj->Display();
    iRet = fDLobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;


    // LL of double
    cout<<"-------------- LinkdList of Doubles --------------\n";

    DoublyLL<double> *dDLobj = new DoublyLL<double>();

    dDLobj->InsertFirst(90.78978);
    dDLobj->InsertFirst(78.99645);
    dDLobj->InsertFirst(67.9934);

    dDLobj->InsertLast(45.67867);
    dDLobj->InsertLast(54.78534);
    dDLobj->InsertLast(77.89324);
    
    dDLobj->Display();
    iRet = dDLobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dDLobj->InsertAtPos(88.56987,5);
    dDLobj->Display();
    iRet = dDLobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dDLobj->DeleteAtPos(5);
    dDLobj->Display();
    iRet = dDLobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;


    /////////////////////////////////////////////////////////////
    //
    // Call of Doubly Circular
    //
    /////////////////////////////////////////////////////////////
    cout<<"-------------------------------------------------------------\n";
    cout<<"\t\t Doubly Circular LinkedList \n";
    cout<<"-------------------------------------------------------------\n";

    // LL of integer
    cout<<"-------------- LinkdList of Integers --------------\n";

    DoublyCL<int> *iDCobj = new DoublyCL<int>();

    iDCobj->InsertFirst(51);
    iDCobj->InsertFirst(21);
    iDCobj->InsertFirst(11);

    iDCobj->InsertLast(101);
    iDCobj->InsertLast(111);
    iDCobj->InsertLast(121);
    
    iDCobj->Display();
    iRet = iDCobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    iDCobj->InsertAtPos(105,5);
    iDCobj->Display();
    iRet = iDCobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    iDCobj->DeleteAtPos(5);
    iDCobj->Display();
    iRet = iDCobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;


    // LL of character
    cout<<"-------------- LinkdList of Chracters --------------\n";

    DoublyCL<char> *cDCobj = new DoublyCL<char>();

    cDCobj->InsertFirst('D');
    cDCobj->InsertFirst('F');
    cDCobj->InsertFirst('R');

    cDCobj->InsertLast('E');
    cDCobj->InsertLast('Y');
    cDCobj->InsertLast('U');
    
    cDCobj->Display();
    iRet = cDCobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    cDCobj->InsertAtPos('W',5);
    cDCobj->Display();
    iRet = cDCobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    cDCobj->DeleteAtPos(5);
    cDCobj->Display();
    iRet = cDCobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;


    // LL of float
    cout<<"-------------- LinkdList of Floats --------------\n";

    DoublyCL<float> *fDCobj = new DoublyCL<float>();

    fDCobj->InsertFirst(90.78f);
    fDCobj->InsertFirst(78.99f);
    fDCobj->InsertFirst(67.99f);

    fDCobj->InsertLast(45.67f);
    fDCobj->InsertLast(54.78f);
    fDCobj->InsertLast(77.89f);
    
    fDCobj->Display();
    iRet = fDCobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    fDCobj->InsertAtPos(88.56,5);
    fDCobj->Display();
    iRet = fDCobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    fDCobj->DeleteAtPos(5);
    fDCobj->Display();
    iRet = fDCobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;


    // LL of double
    cout<<"-------------- LinkdList of Doubles --------------\n";

    DoublyCL<double> *dDCobj = new DoublyCL<double>();

    dDCobj->InsertFirst(90.78978);
    dDCobj->InsertFirst(78.99645);
    dDCobj->InsertFirst(67.9934);

    dDCobj->InsertLast(45.67867);
    dDCobj->InsertLast(54.78534);
    dDCobj->InsertLast(77.89324);
    
    dDCobj->Display();
    iRet = dDCobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dDCobj->InsertAtPos(88.56987,5);
    dDCobj->Display();
    iRet = dDCobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dDCobj->DeleteAtPos(5);
    dDCobj->Display();
    iRet = dDCobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;


    /////////////////////////////////////////////////////////////
    //
    // Call of Stack
    //
    /////////////////////////////////////////////////////////////
    cout<<"-------------------------------------------------------------\n";
    cout<<"\t\t Stack using LinkedList \n";
    cout<<"-------------------------------------------------------------\n";

    // Stack of integer
    cout<<"-------------- Stack of Integers --------------\n";

    Stack<int> *iSTobj = new Stack<int>();

    iSTobj->Push(10);
    iSTobj->Push(20);
    iSTobj->Push(30);
    iSTobj->Push(40);

    iSTobj->Display();
    iRet = iSTobj->Count();
    cout<<"Number of elements in the stack are : "<<iRet<<"\n";
    
    cout<<"Poped element is : "<<(iSTobj->Pop())<<"\n";
    cout<<"Poped element is : "<<(iSTobj->Pop())<<"\n";
    
    iSTobj->Display();
    iRet = iSTobj->Count();
    cout<<"Number of elements in the stack are : "<<iRet<<"\n";

    iSTobj->Push(50);
    iSTobj->Display();
    iRet = iSTobj->Count();
    cout<<"Number of elements in the stack are : "<<iRet<<"\n";


    // Stack of characters
    cout<<"-------------- Stack of Characters --------------\n";

    Stack<char> *cSTobj = new Stack<char>();

    cSTobj->Push('A');
    cSTobj->Push('B');
    cSTobj->Push('C');
    cSTobj->Push('D');

    cSTobj->Display();
    iRet = cSTobj->Count();
    cout<<"Number of elements in the stack are : "<<iRet<<"\n";
    
    cout<<"Poped element is : "<<(cSTobj->Pop())<<"\n";
    cout<<"Poped element is : "<<(cSTobj->Pop())<<"\n";
    
    cSTobj->Display();
    iRet = cSTobj->Count();
    cout<<"Number of elements in the stack are : "<<iRet<<"\n";

    cSTobj->Push('E');
    cSTobj->Display();
    iRet = cSTobj->Count();
    cout<<"Number of elements in the stack are : "<<iRet<<"\n";


    // Stack of floats
    cout<<"-------------- Stack of Floats --------------\n";

    Stack<float> *fSTobj = new Stack<float>();

    fSTobj->Push(11.1f);
    fSTobj->Push(21.1f);
    fSTobj->Push(31.1f);
    fSTobj->Push(41.1f);

    fSTobj->Display();
    iRet = fSTobj->Count();
    cout<<"Number of elements in the stack are : "<<iRet<<"\n";
    
    cout<<"Poped element is : "<<(fSTobj->Pop())<<"\n";
    cout<<"Poped element is : "<<(fSTobj->Pop())<<"\n";
    
    fSTobj->Display();
    iRet = fSTobj->Count();
    cout<<"Number of elements in the stack are : "<<iRet<<"\n";

    fSTobj->Push(51.1f);
    fSTobj->Display();
    iRet = fSTobj->Count();
    cout<<"Number of elements in the stack are : "<<iRet<<"\n";


    // Stack of doubles
    cout<<"-------------- Stack of Doubles --------------\n";

    Stack<double> *dSTobj = new Stack<double>();

    dSTobj->Push(11.1586);
    dSTobj->Push(21.5846);
    dSTobj->Push(31.7895);
    dSTobj->Push(41.4765);

    dSTobj->Display();
    iRet = dSTobj->Count();
    cout<<"Number of elements in the stack are : "<<iRet<<"\n";
    
    cout<<"Poped element is : "<<(dSTobj->Pop())<<"\n";
    cout<<"Poped element is : "<<(dSTobj->Pop())<<"\n";
    
    dSTobj->Display();
    iRet = dSTobj->Count();
    cout<<"Number of elements in the stack are : "<<iRet<<"\n";

    dSTobj->Push(51.1586);
    dSTobj->Display();
    iRet = dSTobj->Count();
    cout<<"Number of elements in the stack are : "<<iRet<<"\n";


    /////////////////////////////////////////////////////////////
    //
    // Call of Queue
    //
    /////////////////////////////////////////////////////////////
    cout<<"-------------------------------------------------------------\n";
    cout<<"\t\t Queue using LinkedList \n";
    cout<<"-------------------------------------------------------------\n";

    // Queue of integer
    cout<<"-------------- Queue of Integers --------------\n";

    Queue<int> *iQUobj = new Queue<int>();

    iQUobj->EnQueue(10);
    iQUobj->EnQueue(20);
    iQUobj->EnQueue(30);
    iQUobj->EnQueue(40);

    iQUobj->Display();
    iRet = iQUobj->Count();
    cout<<"Number of elements in the Queue are : "<<iRet<<"\n";
    
    cout<<"Removed element is : "<<(iQUobj->DeQueue())<<"\n";
    cout<<"Removed element is : "<<(iQUobj->DeQueue())<<"\n";
    
    iQUobj->Display();
    iRet = iQUobj->Count();
    cout<<"Number of elements in the Queue are : "<<iRet<<"\n";

    iQUobj->EnQueue(50);
    iQUobj->Display();
    iRet = iQUobj->Count();
    cout<<"Number of elements in the Queue are : "<<iRet<<"\n";


    // Queue of characters
    cout<<"-------------- Queue of Characters --------------\n";

    Queue<char> *cQUobj = new Queue<char>();

    cQUobj->EnQueue('A');
    cQUobj->EnQueue('B');
    cQUobj->EnQueue('C');
    cQUobj->EnQueue('D');

    cQUobj->Display();
    iRet = cQUobj->Count();
    cout<<"Number of elements in the Queue are : "<<iRet<<"\n";
    
    cout<<"Removed element is : "<<(cQUobj->DeQueue())<<"\n";
    cout<<"Removed element is : "<<(cQUobj->DeQueue())<<"\n";
    
    cQUobj->Display();
    iRet = cQUobj->Count();
    cout<<"Number of elements in the Queue are : "<<iRet<<"\n";

    cQUobj->EnQueue('E');
    cQUobj->Display();
    iRet = cQUobj->Count();
    cout<<"Number of elements in the Queue are : "<<iRet<<"\n";


    // Queue of floats
    cout<<"-------------- Queue of Floats --------------\n";

    Queue<float> *fQUobj = new Queue<float>();

    fQUobj->EnQueue(11.1f);
    fQUobj->EnQueue(21.1f);
    fQUobj->EnQueue(31.1f);
    fQUobj->EnQueue(41.1f);

    fQUobj->Display();
    iRet = fQUobj->Count();
    cout<<"Number of elements in the Queue are : "<<iRet<<"\n";
    
    cout<<"Removed element is : "<<(fQUobj->DeQueue())<<"\n";
    cout<<"Removed element is : "<<(fQUobj->DeQueue())<<"\n";
    
    fQUobj->Display();
    iRet = fQUobj->Count();
    cout<<"Number of elements in the Queue are : "<<iRet<<"\n";

    fQUobj->EnQueue(51.1f);
    fQUobj->Display();
    iRet = fQUobj->Count();
    cout<<"Number of elements in the Queue are : "<<iRet<<"\n";


    // Queue of doubles
    cout<<"-------------- Queue of Doubles --------------\n";

    Queue<double> *dQUobj = new Queue<double>();

    dQUobj->EnQueue(11.1586);
    dQUobj->EnQueue(21.5846);
    dQUobj->EnQueue(31.7895);
    dQUobj->EnQueue(41.4765);

    dQUobj->Display();
    iRet = dQUobj->Count();
    cout<<"Number of elements in the Queue are : "<<iRet<<"\n";
    
    cout<<"Removed element is : "<<(dQUobj->DeQueue())<<"\n";
    cout<<"Removed element is : "<<(dQUobj->DeQueue())<<"\n";
    
    dQUobj->Display();
    iRet = dQUobj->Count();
    cout<<"Number of elements in the Queue are : "<<iRet<<"\n";

    dQUobj->EnQueue(51.1586);
    dQUobj->Display();
    iRet = dQUobj->Count();
    cout<<"Number of elements in the Queue are : "<<iRet<<"\n";


    return 0;
}