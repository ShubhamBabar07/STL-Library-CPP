// Generic Stack using LinkedList

#include<iostream>
using namespace std;

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

int main()
{
    cout<<"-------------------------------------------------------------\n";
    cout<<"\t\t Stack using LinkedList \n";
    cout<<"-------------------------------------------------------------\n";

    // Stack of integer
    cout<<"-------------- Stack of Integers --------------\n";

    Stack<int> *iobj = new Stack<int>();
    int iRet = 0;

    iobj->Push(10);
    iobj->Push(20);
    iobj->Push(30);
    iobj->Push(40);

    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elements in the stack are : "<<iRet<<"\n";
    
    cout<<"Poped element is : "<<(iobj->Pop())<<"\n";
    cout<<"Poped element is : "<<(iobj->Pop())<<"\n";
    
    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elements in the stack are : "<<iRet<<"\n";

    iobj->Push(50);
    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elements in the stack are : "<<iRet<<"\n";


    // Stack of characters
    cout<<"-------------- Stack of Characters --------------\n";

    Stack<char> *cobj = new Stack<char>();

    cobj->Push('A');
    cobj->Push('B');
    cobj->Push('C');
    cobj->Push('D');

    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of elements in the stack are : "<<iRet<<"\n";
    
    cout<<"Poped element is : "<<(cobj->Pop())<<"\n";
    cout<<"Poped element is : "<<(cobj->Pop())<<"\n";
    
    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of elements in the stack are : "<<iRet<<"\n";

    cobj->Push('E');
    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of elements in the stack are : "<<iRet<<"\n";


    // Stack of floats
    cout<<"-------------- Stack of Floats --------------\n";

    Stack<float> *fobj = new Stack<float>();

    fobj->Push(11.1f);
    fobj->Push(21.1f);
    fobj->Push(31.1f);
    fobj->Push(41.1f);

    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of elements in the stack are : "<<iRet<<"\n";
    
    cout<<"Poped element is : "<<(fobj->Pop())<<"\n";
    cout<<"Poped element is : "<<(fobj->Pop())<<"\n";
    
    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of elements in the stack are : "<<iRet<<"\n";

    fobj->Push(51.1f);
    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of elements in the stack are : "<<iRet<<"\n";


    // Stack of doubles
    cout<<"-------------- Stack of Doubles --------------\n";

    Stack<double> *dobj = new Stack<double>();

    dobj->Push(11.1586);
    dobj->Push(21.5846);
    dobj->Push(31.7895);
    dobj->Push(41.4765);

    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of elements in the stack are : "<<iRet<<"\n";
    
    cout<<"Poped element is : "<<(dobj->Pop())<<"\n";
    cout<<"Poped element is : "<<(dobj->Pop())<<"\n";
    
    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of elements in the stack are : "<<iRet<<"\n";

    dobj->Push(51.1586);
    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of elements in the stack are : "<<iRet<<"\n";
    
    return 0;
}