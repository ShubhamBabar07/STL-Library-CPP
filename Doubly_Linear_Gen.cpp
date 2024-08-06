// Generic Doubly Linear LinkedList

#include<iostream>
using namespace std;

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

int main()
{
    cout<<"-------------------------------------------------------------\n";
    cout<<"\t\t Doubly Linear LinkedList \n";
    cout<<"-------------------------------------------------------------\n";

    // LL of integer
    cout<<"-------------- LinkdList of Integers --------------\n";

    DoublyLL<int> *iobj = new DoublyLL<int>();
    int iRet = 0;

    iobj->InsertFirst(51);
    iobj->InsertFirst(21);
    iobj->InsertFirst(11);

    iobj->InsertLast(101);
    iobj->InsertLast(111);
    iobj->InsertLast(121);
    
    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    iobj->InsertAtPos(105,5);
    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    iobj->DeleteAtPos(5);
    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;


    // LL of character
    cout<<"-------------- LinkdList of Chracters --------------\n";

    DoublyLL<char> *cobj = new DoublyLL<char>();

    cobj->InsertFirst('D');
    cobj->InsertFirst('F');
    cobj->InsertFirst('R');

    cobj->InsertLast('E');
    cobj->InsertLast('Y');
    cobj->InsertLast('U');
    
    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    cobj->InsertAtPos('W',5);
    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    cobj->DeleteAtPos(5);
    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;


    // LL of float
    cout<<"-------------- LinkdList of Floats --------------\n";

    DoublyLL<float> *fobj = new DoublyLL<float>();

    fobj->InsertFirst(90.78f);
    fobj->InsertFirst(78.99f);
    fobj->InsertFirst(67.99f);

    fobj->InsertLast(45.67f);
    fobj->InsertLast(54.78f);
    fobj->InsertLast(77.89f);
    
    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    fobj->InsertAtPos(88.56,5);
    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    fobj->DeleteAtPos(5);
    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;


    // LL of double
    cout<<"-------------- LinkdList of Doubles --------------\n";

    DoublyLL<double> *dobj = new DoublyLL<double>();

    dobj->InsertFirst(90.78978);
    dobj->InsertFirst(78.99645);
    dobj->InsertFirst(67.9934);

    dobj->InsertLast(45.67867);
    dobj->InsertLast(54.78534);
    dobj->InsertLast(77.89324);
    
    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dobj->InsertAtPos(88.56987,5);
    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dobj->DeleteAtPos(5);
    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    return 0;
}