#include<iostream>
using namespace std;

typedef struct node 
{
    int data;
    struct node* prev;
    struct node* next;
}NODE, *PNODE;

class DoublyCLL
{
    private:

        int iCount;
        PNODE first;
        PNODE last;

    public:

        DoublyCLL();

        void display();
        int count();

        void insertFirst(int no);
        void insertLast(int no);
        void insertAtPos(int no, int iPos);

        void deleteFirst();
        void deleteLast();
        void deleteAtPos(int iPos);
};

DoublyCLL :: DoublyCLL()
{
    iCount = 0;
    first = NULL;
    last = NULL;
}

void DoublyCLL :: display()
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    cout << "<=> ";
    do
    {
        cout << "| " << first->data <<" | <=> ";
        first = first->next;
    }
    while(first != last->next);

    cout << endl;
}

int DoublyCLL :: count()
{
    return iCount;
}

void DoublyCLL :: insertFirst(int no)
{
    PNODE newn = NULL;
    newn = new NODE;
    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        newn->prev = last;
        first = newn;
    }

    first->prev = last;
    last->next = first;
    iCount++;
}

void DoublyCLL :: insertLast(int no)
{
    PNODE newn = NULL;
    newn = new NODE;
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        newn->prev = last;
        last = newn;
    }

    first->prev = last;
    last->next = first;
    iCount++;
}

void DoublyCLL :: insertAtPos(int no,int iPos)
{
    PNODE temp = first;
    PNODE newn = NULL;
    int i = 0;

    if(iPos < 1 || iPos > iCount + 1)
    {
        cout << "Invalid position\n";
        return;
    }
    else if(iPos == 1)
    {
        insertFirst(no);
    }
    else if(iPos == iCount + 1)
    {
        insertLast(no);
    }
    else
    {
        newn = new NODE;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->prev = temp;
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;

        iCount++;
    }
}

void DoublyCLL :: deleteFirst()
{
    if(first == NULL && last == NULL)
    {
        cout << "List is empty\n";
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        last->next = first->next;
        first->next->prev = last;
        delete first;

        first = last->next;
    }

    iCount--;
}

void DoublyCLL :: deleteLast()
{
    if(first == NULL && last == NULL)
    {
        cout << "List is empty\n";
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        last = last->prev;
        delete first->prev;
        last->next = first;
        first->prev = last;
    }

    iCount--;
}

void DoublyCLL :: deleteAtPos(int iPos)
{
    PNODE temp = first;

    if(iPos < 1 || iPos > iCount)
    {
        cout << "Invalid position\n";
        return;
    }
    else if(iPos == 1)
    {
        deleteFirst();
    }
    else if(iPos == iCount)
    {
        deleteLast();
    }
    else
    {

        int i = 0;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

int main()
{
    DoublyCLL obj;

    obj.insertFirst(51);
    obj.insertFirst(21);
    obj.insertFirst(11);
    
    obj.insertLast(101);
    obj.insertLast(111);
    obj.insertLast(121);

    obj.insertAtPos(105,5);

    obj.deleteFirst();
    obj.deleteLast();
    obj.deleteAtPos(4);

    obj.display();
    cout << "Number of elements in LL are: " << obj.count() << endl;

    return 0;
}