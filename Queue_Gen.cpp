// Generic Queue using LinkedList

#include<iostream>
using namespace std;

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

int main()
{
    cout<<"-------------------------------------------------------------\n";
    cout<<"\t\t Queue using LinkedList \n";
    cout<<"-------------------------------------------------------------\n";

    // Queue of integer
    cout<<"-------------- Queue of Integers --------------\n";

    Queue<int> *iobj = new Queue<int>();
    int iRet = 0;

    iobj->EnQueue(10);
    iobj->EnQueue(20);
    iobj->EnQueue(30);
    iobj->EnQueue(40);

    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elements in the Queue are : "<<iRet<<"\n";
    
    cout<<"Removed element is : "<<(iobj->DeQueue())<<"\n";
    cout<<"Removed element is : "<<(iobj->DeQueue())<<"\n";
    
    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elements in the Queue are : "<<iRet<<"\n";

    iobj->EnQueue(50);
    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elements in the Queue are : "<<iRet<<"\n";


    // Queue of characters
    cout<<"-------------- Queue of Characters --------------\n";

    Queue<char> *cobj = new Queue<char>();

    cobj->EnQueue('A');
    cobj->EnQueue('B');
    cobj->EnQueue('C');
    cobj->EnQueue('D');

    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of elements in the Queue are : "<<iRet<<"\n";
    
    cout<<"Removed element is : "<<(cobj->DeQueue())<<"\n";
    cout<<"Removed element is : "<<(cobj->DeQueue())<<"\n";
    
    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of elements in the Queue are : "<<iRet<<"\n";

    cobj->EnQueue('E');
    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of elements in the Queue are : "<<iRet<<"\n";


    // Queue of floats
    cout<<"-------------- Queue of Floats --------------\n";

    Queue<float> *fobj = new Queue<float>();

    fobj->EnQueue(11.1f);
    fobj->EnQueue(21.1f);
    fobj->EnQueue(31.1f);
    fobj->EnQueue(41.1f);

    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of elements in the Queue are : "<<iRet<<"\n";
    
    cout<<"Removed element is : "<<(fobj->DeQueue())<<"\n";
    cout<<"Removed element is : "<<(fobj->DeQueue())<<"\n";
    
    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of elements in the Queue are : "<<iRet<<"\n";

    fobj->EnQueue(51.1f);
    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of elements in the Queue are : "<<iRet<<"\n";


    // Queue of doubles
    cout<<"-------------- Queue of Doubles --------------\n";

    Queue<double> *dobj = new Queue<double>();

    dobj->EnQueue(11.1586);
    dobj->EnQueue(21.5846);
    dobj->EnQueue(31.7895);
    dobj->EnQueue(41.4765);

    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of elements in the Queue are : "<<iRet<<"\n";
    
    cout<<"Removed element is : "<<(dobj->DeQueue())<<"\n";
    cout<<"Removed element is : "<<(dobj->DeQueue())<<"\n";
    
    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of elements in the Queue are : "<<iRet<<"\n";

    dobj->EnQueue(51.1586);
    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of elements in the Queue are : "<<iRet<<"\n";
    
    return 0;
}