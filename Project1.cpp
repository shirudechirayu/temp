#include<iostream>
using namespace std;

/////////////////////////////////////////
// Code of Singly Linear
/////////////////////////////////////////
template<class T>
struct NodeSL
{
    T data;
    struct NodeSL *next;
};

template<class T>
class SinglyLL
{
    public:
        struct NodeSL<T> * first;
        int iCount;

        SinglyLL();

        void display();
        int count();

        void insertFirst(T no);
        void insertLast(T no);
        void insertAtPos(T no, int iPos);

        void deleteFirst();
        void deleteLast();
        void deleteAtPos(int iPos);
};

template<class T>
SinglyLL<T> :: SinglyLL()
{
    cout << "Inside constructor\n";
    first = NULL;
    iCount = 0;
}

template<class T>
void SinglyLL<T> :: display()
{
    struct NodeSL<T> * temp = first;

    while(temp != NULL)
    {
        cout << "| " << temp->data << " | -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

template<class T>
int SinglyLL<T> :: count()
{
    return iCount;
}

template<class T>
void SinglyLL<T> :: insertFirst(T no)
{
    struct NodeSL<T> * newn = NULL;

    newn = new struct NodeSL<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }

    iCount++;
}

template<class T>
void SinglyLL<T> :: insertLast(T no)
{
    struct NodeSL<T> * newn = NULL;
    struct NodeSL<T> * temp = NULL;

    newn = new struct NodeSL<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }

    iCount++;
}

template<class T>
void SinglyLL<T> :: insertAtPos(T no, int iPos)
{
    int i = 0;
    struct NodeSL<T> * temp = first;
    struct NodeSL<T> * newn = NULL;

    if(iPos < 1 || iPos > iCount + 1)
    {
        cout << "Invalid position" << endl;
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
        newn = new struct NodeSL<T>;

        newn->data = no;
        newn->next = NULL;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template<class T>
void SinglyLL<T> :: deleteFirst()
{
    struct NodeSL<T> * temp = first;

    if(first == NULL)
    {
        cout << "LL is empty" << endl;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        first = first->next;
        delete temp;
    }

    iCount--;
}

template<class T>
void SinglyLL<T> :: deleteLast()
{
    struct NodeSL<T> * temp = first;

    if(first == NULL)
    {
        cout << "LL is empty" << endl;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    iCount--;
}

template<class T>
void SinglyLL<T> :: deleteAtPos(int iPos)
{
    int i = 0;
    struct NodeSL<T> * temp1 = NULL;
    struct NodeSL<T> * temp2 = NULL;

    if(iPos < 1 || iPos > iCount)
    {
        cout << "Invalid position" << endl;
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
        temp1 = first;

        for(i = 1; i < iPos - 1; i++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;
        temp1->next = temp1->next->next;
        delete temp2;

        iCount--;
    }
}

//////////////////////////////////////////
// Code of Doubly Circular
//////////////////////////////////////////
template<class T>
struct NodeDC
{
    T data;
    struct NodeDC *next;
    struct NodeDC *prev;
};

template<class T>
class DoublyCL
{
    private:
        struct NodeDC<T> * first;
        struct NodeDC<T> * last;
        int iCount;

    public:
        DoublyCL();

        void display();
        int count();

        void insertFirst(T no);
        void insertLast(T no);
        void insertAtPos(T no, int iPos);

        void deleteFirst();
        void deleteLast();
        void deleteAtPos(int iPos);
};

template<class T>
DoublyCL<T> :: DoublyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

template<class T>
void DoublyCL<T> :: display()
{
    if(first == NULL && last == NULL)
    {
        cout << "LL is empty";
        return;
    }

    cout << "<=> ";
    do
    {
        cout << "| " << first->data << " | <=> ";
        first = first->next;
    }
    while(first != last->next);
    cout << endl;
}

template<class T>
int DoublyCL<T> :: count()
{
    return iCount;
}

template<class T>
void DoublyCL<T> :: insertFirst(T no)
{
    struct NodeDC<T> * newn = NULL;

    newn = new struct NodeDC<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }

    last->next = first;
    first->prev = last;

    iCount++;
}

template<class T>
void DoublyCL<T> :: insertLast(T no)
{
    struct NodeDC<T> * newn = NULL;

    newn = new struct NodeDC<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)
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

    last->next = first;
    first->prev = last;

    iCount++;
}

template<class T>
void DoublyCL<T> :: insertAtPos(T no,int iPos)
{
    struct NodeDC<T> * temp = first;
    struct NodeDC<T> * newn = NULL;
    int i = 0;

    if(iPos < 1 || iPos > iCount + 1)
    {
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
        newn = new struct NodeDC<T>;
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

template<class T>
void DoublyCL<T> :: deleteFirst()
{
    if(first == NULL && last == NULL)
    {
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
        first = first->next;
        delete last->next;
        last->next = first;
        first->prev = last;
    }

    iCount--;
}

template<class T>
void DoublyCL<T> :: deleteLast()
{
    if(first == NULL && last == NULL)
    {
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

template<class T>
void DoublyCL<T> :: deleteAtPos(int iPos)
{
    struct NodeDC<T> * temp = first;
    int i = 0;

    if(iPos < 1 || iPos > iCount)
    {
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

//////////////////////////////////////////
// Code of Singly Circular Linked List
//////////////////////////////////////////

template<class T>
class SinglyCL
{
    public:
        struct NodeSL<T> * first;
        struct NodeSL<T> * last;
        int iCount;

        SinglyCL();

        void display();
        int count();

        void insertFirst(T no);
        void insertLast(T no);
        void insertAtPos(T no, int iPos);

        void deleteFirst();
        void deleteLast();
        void deleteAtPos(int iPos);
};

template<class T>
SinglyCL<T> :: SinglyCL()
{
    cout << "Inside constructor\n";
    first = NULL;
    last = NULL;
    iCount = 0;
}

template<class T>
void SinglyCL<T> :: display()
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    do
    {
        cout << " -> | " << first->data << " |";
        first = first->next;
    } while (first != last->next);
    cout << " ->" << endl;
}

template<class T>
int SinglyCL<T> :: count()
{
    return iCount;
}

template<class T>
void SinglyCL<T> :: insertFirst(T no)
{
    struct NodeSL<T> * newn = NULL;

    newn = new struct NodeSL<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    last->next = first;

    iCount++;
}

template<class T>
void SinglyCL<T> :: insertLast(T no)
{
    struct NodeSL<T> * newn = NULL;

    newn = new struct NodeSL<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        last = newn;
    }
    last->next = first;

    iCount++;
}

template<class T>
void SinglyCL<T> :: insertAtPos(T no, int iPos)
{
    int i = 0;
    struct NodeSL<T> * temp = first;
    struct NodeSL<T> * newn = NULL;

    if(iPos < 1 || iPos > iCount + 1)
    {
        cout << "Invalid position" << endl;
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
        newn = new struct NodeSL<T>;

        newn->data = no;
        newn->next = NULL;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template<class T>
void SinglyCL<T> :: deleteFirst()
{
    if(first == NULL && last == NULL)
    {
        cout << "LL is empty" << endl;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;
        last->next = first;
    }

    iCount--;
}

template<class T>
void SinglyCL<T> :: deleteLast()
{
    struct NodeSL<T> * temp = first;

    if(first == NULL)
    {
        cout << "LL is empty" << endl;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        last = temp;
        last->next = first;
    }

    iCount--;
}

template<class T>
void SinglyCL<T> :: deleteAtPos(int iPos)
{
    int i = 0;
    struct NodeSL<T> * temp1 = NULL;
    struct NodeSL<T> * temp2 = NULL;

    if(iPos < 1 || iPos > iCount)
    {
        cout << "Invalid position" << endl;
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
        temp1 = first;

        for(i = 1; i < iPos - 1; i++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;
        temp1->next = temp1->next->next;
        delete temp2;

        iCount--;
    }
}

//////////////////////////////////////////
// Code of Doubly Linear Linked List
//////////////////////////////////////////

template<class T>
class DoublyLL
{
    public:
        struct NodeDC<T> * first;
        int iCount;

        DoublyLL();

        void display();
        int count();

        void insertFirst(T no);
        void insertLast(T no);
        void insertAtPos(T no, int iPos);

        void deleteFirst();
        void deleteLast();
        void deleteAtPos(int iPos);
};

template<class T>
DoublyLL<T> :: DoublyLL()
{
    cout << "Inside constructor\n";
    first = NULL;
    iCount = 0;
}

template<class T>
void DoublyLL<T> :: display()
{
    struct NodeDC<T> * temp = first;

    if(first == NULL)
    {
        return;
    }

    cout << "NULL";
    while(temp != NULL)
    {
        cout << " <=> | " << temp->data << " |";
        temp = temp->next;
    }
    cout << " <=> NULL\n";
}

template<class T>
int DoublyLL<T> :: count()
{
    return iCount;
}

template<class T>
void DoublyLL<T> :: insertFirst(T no)
{
    struct NodeDC<T> * newn = NULL;

    newn = new struct NodeDC<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }

    iCount++;
}

template<class T>
void DoublyLL<T> :: insertLast(T no)
{
    struct NodeDC<T> * newn = NULL;
    struct NodeDC<T> * temp = NULL;

    newn = new struct NodeDC<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }

    iCount++;
}

template<class T>
void DoublyLL<T> :: insertAtPos(T no, int iPos)
{
    int i = 0;
    struct NodeDC<T> * temp = first;
    struct NodeDC<T> * newn = NULL;

    if(iPos < 1 || iPos > iCount + 1)
    {
        cout << "Invalid position" << endl;
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
        newn = new struct NodeDC<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;

        iCount++;
    }
}

template<class T>
void DoublyLL<T> :: deleteFirst()
{
    if(first == NULL)
    {
        cout << "LL is empty" << endl;
    }
    else
    {
        first = first->next;
        delete first->prev;
        first->prev = NULL;
    }

    iCount--;
}

template<class T>
void DoublyLL<T> :: deleteLast()
{
    struct NodeDC<T> * temp = first;

    if(first == NULL)
    {
        cout << "LL is empty" << endl;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    iCount--;
}

template<class T>
void DoublyLL<T> :: deleteAtPos(int iPos)
{
    int i = 0;
    struct NodeDC<T> * temp = NULL;

    if(iPos < 1 || iPos > iCount)
    {
        cout << "Invalid position" << endl;
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
        temp = first;

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

/////////////////////////////////////////
//// Code for Stack
/////////////////////////////////////////

template<class T>
struct NodeST
{
    T data;
    struct NodeST *next;
};

template<class T>
class Stack
{
    private:
        struct NodeST<T> * first;
        int iCount;

    public:
        Stack();
        void display();
        int count();
        void push(T no);  // insertFirst(T no)
        T pop();          // deleteFirst()
};

template<class T>
Stack<T> :: Stack()
{
    first = NULL;
    iCount = 0;
}

template<class T>
void Stack<T> :: display()
{
    cout << "Elements of stack are: " << endl;
    struct NodeST<T> * temp = first;

    while(temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl;
}

template<class T>
int Stack<T> :: count()
{
    return iCount;
}

template<class T>
void Stack<T> :: push(T no)
{
    struct NodeST<T> * newn = NULL;

    newn = new struct NodeST<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }

    iCount++;
}

template<class T>
T Stack<T> :: pop()
{
    int iValue = 0;
    struct NodeST<T> * temp = NULL;

    if(first == NULL)
    {
        cout << "Unable to pop the element as stack is empty" << endl;
        return -1;
    }
    else
    {
        temp = first;

        iValue = first->data;
        first = first->next;
        delete temp;

        iCount--;
    }

    return iValue;
}

/////////////////////////////////////////
//// Code for Queue
/////////////////////////////////////////

template<class T>
struct NODEQ
{
    T data;
    struct NODEQ *next;
};

template<class T>
class Queue
{
    private:
        struct NODEQ<T> * first;
        int iCount;

    public:
        Queue();
        void display();
        int count();
        void enqueue(T no);  // insertLast(T no)
        T dequeue();          // deleteFirst()
};

template<class T>
Queue<T> :: Queue()
{
    first = NULL;
    iCount = 0;
}

template<class T>
void Queue<T> :: display()
{
    cout << "Elements of Queue are: " << endl;
    struct NODEQ<T> * temp = first;

    while(temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << endl;
}

template<class T>
int Queue<T> :: count()
{
    return iCount;
}

template<class T>
void Queue<T> :: enqueue(T no)
{
    struct NODEQ<T> * newn = NULL;
    struct NODEQ<T> * temp = NULL;

    newn = new struct NODEQ<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }

    iCount++;
}

template<class T>
T Queue<T> :: dequeue()
{
    int iValue = 0;
    struct NODEQ<T> * temp = NULL;

    if(first == NULL)
    {
        cout << "Unable to dequeue as Queue is empty" << endl;
        return -1;
    }
    else
    {
        temp = first;

        iValue = first->data;
        first = first->next;
        delete temp;

        iCount--;
    }

    return iValue;
}


int main()
{
    /////////////////////////////////////////
    //// Code for Singly Linear Linked List
    /////////////////////////////////////////

    // Singly Linear Linked List for integer
    SinglyLL<int> *iobj = new SinglyLL<int>();

    cout << "\n-----Singly Linear Linked List for integer-----\n";

    int iRet = 0;

    iobj->insertFirst(51);
    iobj->insertFirst(21);
    iobj->insertFirst(11);

    iRet = iobj->count();
    cout << "Number of elements are: " << iRet << endl;

    iobj->display();

    iobj->insertLast(101);
    iobj->insertLast(111);
    iobj->insertLast(121);

    iobj->insertAtPos(105,5);

    iRet = iobj->count();
    cout << "Number of elements are: " << iRet << endl;

    iobj->display();

    iobj->deleteAtPos(5);

    iRet = iobj->count();
    cout << "Number of elements are: " << iRet << endl;

    iobj->display();

    cout << "--------------------------\n";

    // Singly Linear Linked List for character
    SinglyLL<char> *cobj = new SinglyLL<char>();

    cout << "\n-----Singly Linear Linked List for character-----\n";

    cobj->insertFirst('a');
    cobj->insertFirst('b');
    cobj->insertFirst('c');

    iRet = cobj->count();
    cout << "Number of elements are: " << iRet << endl;

    cobj->display();

    cobj->insertLast('d');
    cobj->insertLast('e');
    cobj->insertLast('f');

    cobj->insertAtPos('g',5);

    iRet = cobj->count();
    cout << "Number of elements are: " << iRet << endl;

    cobj->display();

    cobj->deleteAtPos(5);

    iRet = cobj->count();
    cout << "Number of elements are: " << iRet << endl;

    cobj->display();

    cout << "--------------------------\n";

    // Singly Linear Linked List for float
    SinglyLL<float> *fobj = new SinglyLL<float>();

    cout << "\n-----Singly Linear Linked List for float-----\n";

    fobj->insertFirst(10.346f);
    fobj->insertFirst(14.76f);
    fobj->insertFirst(75.456f);

    iRet = fobj->count();
    cout << "Number of elements are: " << iRet << endl;

    fobj->display();

    fobj->insertLast(87.453f);
    fobj->insertLast(45.765f);
    fobj->insertLast(23.65f);

    fobj->insertAtPos(56.453f,5);

    iRet = fobj->count();
    cout << "Number of elements are: " << iRet << endl;

    fobj->display();

    fobj->deleteAtPos(5);

    iRet = fobj->count();
    cout << "Number of elements are: " << iRet << endl;

    fobj->display();

    cout << "--------------------------\n";

    // Singly Linear Linked List for double
    SinglyLL<double> *dobj = new SinglyLL<double>();

    cout << "\n-----Singly Linear Linked List for double-----\n";

    dobj->insertFirst(10.34653675723);
    dobj->insertFirst(14.7623747);
    dobj->insertFirst(75.45689384);

    iRet = dobj->count();
    cout << "Number of elements are: " << iRet << endl;

    dobj->display();

    dobj->insertLast(87.453734);
    dobj->insertLast(45.765756);
    dobj->insertLast(23.65452);

    dobj->insertAtPos(56.453453,5);

    iRet = dobj->count();
    cout << "Number of elements are: " << iRet << endl;

    dobj->display();

    dobj->deleteAtPos(5);

    iRet = dobj->count();
    cout << "Number of elements are: " << iRet << endl;

    dobj->display();

    cout << "--------------------------\n";

    /////////////////////////////////////////
    //// Code for Doubly Circular Linked List
    /////////////////////////////////////////

    // Doubly Circular Linked List for integer
    DoublyCL<int> *idcobj = new DoublyCL<int>();
    
    cout << "\n-----Doubly Circular Linked List for integer-----\n";

    idcobj->insertFirst(51);
    idcobj->insertFirst(21);
    idcobj->insertFirst(11);

    idcobj->insertLast(101);
    idcobj->insertLast(111);
    idcobj->insertLast(121);

    idcobj->insertAtPos(105,5);
    idcobj->deleteAtPos(5);

    idcobj->display();

    iRet = idcobj->count();

    cout << "Number of elements are: " << iRet << endl << "--------------------------"<< endl;

    // Doubly Circular Linked List for character
    DoublyCL<char> *cdcobj = new DoublyCL<char>();

    cout << "\n-----Doubly Circular Linked List for character-----\n";

    cdcobj->insertFirst('a');
    cdcobj->insertFirst('b');
    cdcobj->insertFirst('c');

    cdcobj->insertLast('d');
    cdcobj->insertLast('e');
    cdcobj->insertLast('f');

    cdcobj->insertAtPos('g',5);
    cdcobj->deleteAtPos(5);

    cdcobj->display();

    iRet = cdcobj->count();

    cout << "Number of elements are: " << iRet << endl << "--------------------------"<< endl;

    // Doubly Circular Linked List for float
    DoublyCL<float> *fdcobj = new DoublyCL<float>();

    cout << "\n-----Doubly Circular Linked List for float-----\n";

    fdcobj->insertFirst(10.34f);
    fdcobj->insertFirst(56.54f);
    fdcobj->insertFirst(65.78f);

    fdcobj->insertLast(12.43f);
    fdcobj->insertLast(65.76f);
    fdcobj->insertLast(45.34f);

    fdcobj->insertAtPos(34.56f,5);
    fdcobj->deleteAtPos(5);

    fdcobj->display();

    iRet = fdcobj->count();

    cout << "Number of elements are: " << iRet << endl << "--------------------------"<< endl;

    // Doubly Circular Linked List for double
    DoublyCL<double> *ddcobj = new DoublyCL<double>();

    cout << "\n-----Doubly Circular Linked List for double-----\n";

    ddcobj->insertFirst(10.3423);
    ddcobj->insertFirst(56.5423);
    ddcobj->insertFirst(65.7854);

    ddcobj->insertLast(12.4365);
    ddcobj->insertLast(65.7665);
    ddcobj->insertLast(45.3443);

    ddcobj->insertAtPos(34.5646,5);
    ddcobj->deleteAtPos(5);

    ddcobj->display();

    iRet = ddcobj->count();

    cout << "Number of elements are: " << iRet << endl << "--------------------------"<< endl;

    /////////////////////////////////////////
    //// Code for Singly Circular Linked List
    /////////////////////////////////////////

    // Singly Circular Linked List for integer
    SinglyCL<int> *iclobj = new SinglyCL<int>();

    cout << "\n-----Singly Circular Linked List for integer-----\n";

    iRet = 0;

    iclobj->insertFirst(51);
    iclobj->insertFirst(21);
    iclobj->insertFirst(11);

    iRet = iclobj->count();
    cout << "Number of elements are: " << iRet << endl;

    iclobj->display();

    iclobj->insertLast(101);
    iclobj->insertLast(111);
    iclobj->insertLast(121);

    iclobj->insertAtPos(105,5);

    iRet = iclobj->count();
    cout << "Number of elements are: " << iRet << endl;

    iclobj->display();

    iclobj->deleteAtPos(5);

    iRet = iclobj->count();
    cout << "Number of elements are: " << iRet << endl;

    iclobj->display();

    cout << "--------------------------\n"; 

    // Singly Circular Linked List for character
    SinglyCL<char> *cclobj = new SinglyCL<char>();

    cout << "\n-----Singly Circular Linked List for character-----\n";

    cclobj->insertFirst('a');
    cclobj->insertFirst('b');
    cclobj->insertFirst('c');

    iRet = cclobj->count();
    cout << "Number of elements are: " << iRet << endl;

    cclobj->display();

    cclobj->insertLast('d');
    cclobj->insertLast('e');
    cclobj->insertLast('f');

    cclobj->insertAtPos('g',5);

    iRet = cobj->count();
    cout << "Number of elements are: " << iRet << endl;

    cclobj->display();

    cclobj->deleteAtPos(5);

    iRet = cclobj->count();
    cout << "Number of elements are: " << iRet << endl;

    cclobj->display();

    cout << "--------------------------\n"; 

    // Singly Circular Linked List for float
    SinglyCL<float> *fclobj = new SinglyCL<float>();

    cout << "\n-----Singly Circular Linked List for float-----\n";

    fclobj->insertFirst(10.346f);
    fclobj->insertFirst(14.76f);
    fclobj->insertFirst(75.456f);

    iRet = fclobj->count();
    cout << "Number of elements are: " << iRet << endl;

    fclobj->display();

    fclobj->insertLast(87.453f);
    fclobj->insertLast(45.765f);
    fclobj->insertLast(23.65f);

    fclobj->insertAtPos(56.453f,5);

    iRet = fclobj->count();
    cout << "Number of elements are: " << iRet << endl;

    fclobj->display();

    fclobj->deleteAtPos(5);

    iRet = fclobj->count();
    cout << "Number of elements are: " << iRet << endl;

    fclobj->display();

    cout << "--------------------------\n"; 

    // Singly Circular Linked List for double
    SinglyCL<double> *dclobj = new SinglyCL<double>();

    cout << "\n-----Singly Circular Linked List for double-----\n";

    dclobj->insertFirst(10.34653675723);
    dclobj->insertFirst(14.7623747);
    dclobj->insertFirst(75.45689384);

    iRet = dclobj->count();
    cout << "Number of elements are: " << iRet << endl;

    dclobj->display();

    dclobj->insertLast(87.453734);
    dclobj->insertLast(45.765756);
    dclobj->insertLast(23.65452);

    dclobj->insertAtPos(56.453453,5);

    iRet = dclobj->count();
    cout << "Number of elements are: " << iRet << endl;

    dclobj->display();

    dclobj->deleteAtPos(5);

    iRet = dclobj->count();
    cout << "Number of elements are: " << iRet << endl;

    dclobj->display();

    cout << "--------------------------\n"; 

    /////////////////////////////////////////
    //// Code for Doubly Linear Linked List
    /////////////////////////////////////////

    // Doubly Linear Linked List for integer
    DoublyLL<int> *idlobj = new DoublyLL<int>();

    cout << "\n-----Doubly Linear Linked List for integer-----\n";

    iRet = 0;

    idlobj->insertFirst(51);
    idlobj->insertFirst(21);
    idlobj->insertFirst(11);

    iRet = idlobj->count();
    cout << "Number of elements are: " << iRet << endl;

    idlobj->display();

    idlobj->insertLast(101);
    idlobj->insertLast(111);
    idlobj->insertLast(121);

    iclobj->insertAtPos(105,5);

    iRet = idlobj->count();
    cout << "Number of elements are: " << iRet << endl;

    idlobj->display();

    idlobj->deleteAtPos(5);

    iRet = idlobj->count();
    cout << "Number of elements are: " << iRet << endl;

    idlobj->display();

    cout << "--------------------------\n"; 

    // Doubly Linear Linked List for character
    DoublyLL<char> *cdlobj = new DoublyLL<char>();

    cout << "\n-----Doubly Linear Linked List for character-----\n";

    cdlobj->insertFirst('a');
    cdlobj->insertFirst('b');
    cdlobj->insertFirst('c');

    iRet = cdlobj->count();
    cout << "Number of elements are: " << iRet << endl;

    cdlobj->display();

    cdlobj->insertLast('d');
    cdlobj->insertLast('e');
    cdlobj->insertLast('f');

    cdlobj->insertAtPos('g',5);

    iRet = cobj->count();
    cout << "Number of elements are: " << iRet << endl;

    cdlobj->display();

    cdlobj->deleteAtPos(5);

    iRet = cdlobj->count();
    cout << "Number of elements are: " << iRet << endl;

    cdlobj->display();

    cout << "--------------------------\n"; 

    // Doubly Linear Linked List for float
    DoublyLL<float> *fdlobj = new DoublyLL<float>();

    cout << "\n-----Doubly Linear Linked List for float-----\n";

    fdlobj->insertFirst(10.346f);
    fdlobj->insertFirst(14.76f);
    fdlobj->insertFirst(75.456f);

    iRet = fdlobj->count();
    cout << "Number of elements are: " << iRet << endl;

    fdlobj->display();

    fdlobj->insertLast(87.453f);
    fdlobj->insertLast(45.765f);
    fdlobj->insertLast(23.65f);

    fdlobj->insertAtPos(56.453f,5);

    iRet = fdlobj->count();
    cout << "Number of elements are: " << iRet << endl;

    fdlobj->display();

    fdlobj->deleteAtPos(5);

    iRet = fdlobj->count();
    cout << "Number of elements are: " << iRet << endl;

    fdlobj->display();

    cout << "--------------------------\n"; 

    // Doubly Linear Linked List for double
    DoublyLL<double> *ddlobj = new DoublyLL<double>();

    cout << "\n-----Doubly Linear Linked List for double-----\n";

    ddlobj->insertFirst(10.34653675723);
    ddlobj->insertFirst(14.7623747);
    ddlobj->insertFirst(75.45689384);

    iRet = ddlobj->count();
    cout << "Number of elements are: " << iRet << endl;

    ddlobj->display();

    ddlobj->insertLast(87.453734);
    ddlobj->insertLast(45.765756);
    ddlobj->insertLast(23.65452);

    ddlobj->insertAtPos(56.453453,5);

    iRet = ddlobj->count();
    cout << "Number of elements are: " << iRet << endl;

    ddlobj->display();

    ddlobj->deleteAtPos(5);

    iRet = ddlobj->count();
    cout << "Number of elements are: " << iRet << endl;

    ddlobj->display();

    cout << "--------------------------\n"; 

    /////////////////////////////////////////
    //// Code for Stack
    /////////////////////////////////////////

    // Stack for integer
    Stack<int> *siobj  = new Stack<int>();

    cout << "\n-----Stack for integer-----\n";

    iRet = 0;

    siobj->push(10);
    siobj->push(20);
    siobj->push(30);
    siobj->push(40);

    siobj->display();

    iRet = siobj->count();

    cout << "Number of elements in the Stack are: " << iRet << endl;

    iRet = siobj->pop();

    cout << "Popped element is: " << iRet << endl;

    iRet = siobj->pop();

    cout << "Popped element is: " << iRet << endl;

    siobj->display();

    iRet = siobj->count();

    cout << "Number of elements in the stack are: " << iRet << endl;

    siobj->push(50);

    siobj->display();

    iRet = siobj->count();

    cout << "Number of elements in the stack are: " << iRet << endl << "--------------------------" << endl;

    // Stack for character
    Stack<char> *scobj  = new Stack<char>();

    cout << "\n-----Stack for character-----\n";

    iRet = 0;
    char cRet = '\0';

    scobj->push('a');
    scobj->push('b');
    scobj->push('c');
    scobj->push('d');

    scobj->display();

    iRet = scobj->count();

    cout << "Number of elements in the Stack are: " << iRet << endl;

    cRet = scobj->pop();

    cout << "Popped element is: " << cRet << endl;

    cRet = scobj->pop();

    cout << "Popped element is: " << cRet << endl;

    scobj->display();

    iRet = scobj->count();

    cout << "Number of elements in the stack are: " << iRet << endl;

    scobj->push('e');

    scobj->display();

    iRet = scobj->count();

    cout << "Number of elements in the stack are: " << iRet << endl << "--------------------------" << endl;

    // Stack for float
    Stack<float> *sfobj  = new Stack<float>();

    cout << "\n-----Stack for float-----\n";

    iRet = 0;
    float fRet = 0.0f;

    sfobj->push(10.23f);
    sfobj->push(45.45f);
    sfobj->push(34.87f);
    sfobj->push(56.13f);

    sfobj->display();

    iRet = sfobj->count();

    cout << "Number of elements in the Stack are: " << iRet << endl;

    fRet = sfobj->pop();

    cout << "Popped element is: " << fRet << endl;

    fRet = sfobj->pop();

    cout << "Popped element is: " << fRet << endl;

    sfobj->display();

    iRet = sfobj->count();

    cout << "Number of elements in the stack are: " << iRet << endl;

    sfobj->push(98.48f);

    sfobj->display();

    iRet = sfobj->count();

    cout << "Number of elements in the stack are: " << iRet << endl << "--------------------------" << endl;

    // Stack for double
    Stack<double> *sdobj  = new Stack<double>();

    cout << "\n-----Stack for double-----\n";

    iRet = 0;
    float dRet = 0.0;

    sdobj->push(10.2343);
    sdobj->push(45.4551);
    sdobj->push(34.8799);
    sdobj->push(56.1330);

    sdobj->display();

    iRet = sdobj->count();

    cout << "Number of elements in the Stack are: " << iRet << endl;

    dRet = sdobj->pop();

    cout << "Popped element is: " << dRet << endl;

    dRet = sdobj->pop();

    cout << "Popped element is: " << dRet << endl;

    sdobj->display();

    iRet = sdobj->count();

    cout << "Number of elements in the stack are: " << iRet << endl;

    sdobj->push(98.4816);

    sdobj->display();

    iRet = sdobj->count();

    cout << "Number of elements in the stack are: " << iRet << endl << "--------------------------" << endl;

    /////////////////////////////////////////
    //// Code for Queue
    /////////////////////////////////////////

    // Queue for integer
    Queue<int> *qiobj = new Queue<int>();

    cout << "\n-----Queue for integer-----\n";

    iRet = 0;

    qiobj->enqueue(10);
    qiobj->enqueue(20);
    qiobj->enqueue(30);
    qiobj->enqueue(40);

    qiobj->display();

    iRet = qiobj->count();

    cout << "Number of elements in the Queue are: " << iRet << endl;

    iRet = qiobj->dequeue();

    cout << "Removed element is: " << iRet << endl;

    iRet = qiobj->dequeue();

    cout << "Removed element is: " << iRet << endl;

    qiobj->display();

    iRet = qiobj->count();

    cout << "Number of elements in the Queue are: " << iRet << endl;

    qiobj->enqueue(50);

    qiobj->display();

    iRet = qiobj->count();

    cout << "Number of elements in the Queue are: " << iRet << endl << "--------------------------" << endl;

    // Queue for character
    Queue<char> *qcobj = new Queue<char>();

    cout << "\n-----Queue for character-----\n";

    iRet = 0;

    qcobj->enqueue('a');
    qcobj->enqueue('b');
    qcobj->enqueue('c');
    qcobj->enqueue('d');

    qcobj->display();

    iRet = qcobj->count();

    cout << "Number of elements in the Queue are: " << iRet << endl;

    cRet = qcobj->dequeue();

    cout << "Removed element is: " << cRet << endl;

    cRet = qcobj->dequeue();

    cout << "Removed element is: " << cRet << endl;

    qcobj->display();

    iRet = qcobj->count();

    cout << "Number of elements in the Queue are: " << iRet << endl;

    qcobj->enqueue('e');

    qcobj->display();

    iRet = qcobj->count();

    cout << "Number of elements in the Queue are: " << iRet << endl << "--------------------------" << endl;

    // Queue for float
    Queue<float> *qfobj = new Queue<float>();

    cout << "\n-----Queue for float-----\n";

    iRet = 0;

    qfobj->enqueue(10.25f);
    qfobj->enqueue(43.27f);
    qfobj->enqueue(76.39f);
    qfobj->enqueue(65.48f);

    qfobj->display();

    iRet = qfobj->count();

    cout << "Number of elements in the Queue are: " << iRet << endl;

    fRet = qfobj->dequeue();

    cout << "Removed element is: " << fRet << endl;

    fRet = qfobj->dequeue();

    cout << "Removed element is: " << fRet << endl;

    qfobj->display();

    iRet = qfobj->count();

    cout << "Number of elements in the Queue are: " << iRet << endl;

    qfobj->enqueue(23.43f);

    qfobj->display();

    iRet = qfobj->count();

    cout << "Number of elements in the Queue are: " << iRet << endl << "--------------------------" << endl;



    // Queue for double
    Queue<double> *qdobj = new Queue<double>();

    cout << "\n-----Queue for double-----\n";

    iRet = 0;

    qdobj->enqueue(11.2364);
    qdobj->enqueue(67.3275);
    qdobj->enqueue(11.2468);
    qdobj->enqueue(19.5623);

    qdobj->display();

    iRet = qdobj->count();

    cout << "Number of elements in the Queue are: " << iRet << endl;

    dRet = qdobj->dequeue();

    cout << "Removed element is: " << dRet << endl;

    dRet = qdobj->dequeue();

    cout << "Removed element is: " << dRet << endl;

    qdobj->display();

    iRet = qdobj->count();

    cout << "Number of elements in the Queue are: " << iRet << endl;

    qdobj->enqueue(98.2461);

    qdobj->display();

    iRet = qdobj->count();

    cout << "Number of elements in the Queue are: " << iRet << endl << "--------------------------" << endl;

    return 0;
}