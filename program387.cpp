// Singly Circular Linked List

#include<iostream>
using namespace std;

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
    if(First == NULL && Last == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }

    do
    {
        cout<<"| "<<First->data<<" | ->";
        First = First->next;  
    }while(First != Last->next);

    cout<<"\n";
}

template <class T>
int SinglyCL<T>::Count()
{
    int iCount = 0;

    if(First == NULL && Last == NULL)
    {
        return 0;
    }

    do
    {
        iCount++;
        First = First->next;  
    }while(First != Last->next);

    return iCount;
}

template <class T>
void SinglyCL<T>::InsertFirst(T No)
{
    struct nodeSC<T> * newn = NULL;

    newn = new nodeSC<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL && Last == NULL)
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
}

template <class T>
void SinglyCL<T>::InsertLast(T No)
{
    struct nodeSC<T> * newn = NULL;

    newn = new nodeSC<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL && Last == NULL)
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
}

template <class T>
void SinglyCL<T>::InsertAtPos(T No, int iPos)
{
    int i = 0;
    int iLength = 0;
    struct nodeSC<T> * temp = NULL;
    struct nodeSC<T> * newn = NULL;

    iLength = Count();

    if((iPos < 1) || (iPos > iLength+1))
    {
        printf("Invalid Position\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iLength+1)
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
            temp = temp -> next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if(First == NULL && Last == NULL)
    {
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
        First = First->next;
        delete(Last->next);
        Last->next = First;
    }
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
    struct nodeSC<T> * temp = First;

    if(First == NULL && Last == NULL)
    {
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
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    int iLength = 0;
    struct nodeSC<T> * temp1 = NULL;
    struct nodeSC<T> * temp2 = NULL;

    iLength = Count();

    if((iPos < 1) || (iPos > iLength))
    {
        printf("Invalid Position\n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iLength)
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
    }
}

int main()
{
    SinglyCL<int> *sobj = new SinglyCL<int>();
    int iRet = 0;

    sobj->InsertFirst(51);
    sobj->InsertFirst(21);
    sobj->InsertFirst(11);

    sobj->InsertLast(151);
    sobj->InsertLast(121);
    sobj->InsertLast(111);

    sobj->Display();
    iRet = sobj->Count();
    cout<<"Number of elements are : "<<iRet<<endl;

    sobj->DeleteFirst();

    sobj->Display();
    iRet = sobj->Count();
    cout<<"Number of elements are : "<<iRet<<endl;

    sobj->DeleteLast();

    sobj->Display();
    iRet = sobj->Count();
    cout<<"Number of elements are : "<<iRet<<endl;

    sobj->InsertAtPos(105,5);

    sobj->Display();
    iRet = sobj->Count();
    cout<<"Number of elements are : "<<iRet<<endl;

    sobj->DeleteAtPos(5);

    sobj->Display();
    iRet = sobj->Count();
    cout<<"Number of elements are : "<<iRet<<endl;


    return 0;
}
