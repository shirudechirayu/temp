#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
    int data;
    struct node* prev;
    struct node* next;
}NODE, *PNODE, **PPNODE;

void display(PNODE first,PNODE last)
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    printf("<=> ");
    do
    {
        printf("| %d | <=> ",first->data);
        first = first->next;
    }
    while(first != last->next);
    printf("\n");
}

int count(PNODE first,PNODE last)
{
    int iCnt = 0;

    if(first != NULL && last != NULL)
    {
        do
        {
            iCnt++;
            first = first->next;
        }
        while(first != last->next);
    }

    return iCnt;
}

void insertFirst(PPNODE first,PPNODE last,int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        newn->next = *first;
        newn->prev = *last;
        *first = newn;
    }

    (*first)->prev = *last;
    (*last)->next = *first;
}

void insertLast(PPNODE first,PPNODE last,int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        (*last)->next = newn;
        newn->prev = *last;
        *last = newn;
    }

    (*first)->prev = *last;
    (*last)->next = *first;
}

void insertAtPos(PPNODE first,PPNODE last,int no,int iPos)
{
    PNODE temp = *first;
    PNODE newn = NULL;
    int i = 0, iCount = 0;

    iCount = count(*first,*last);

    if(iPos < 1 || iPos > iCount + 1)
    {
        printf("Invalid position\n");
        return;
    }
    else if(iPos == 1)
    {
        insertFirst(first,last,no);
    }
    else if(iPos == iCount + 1)
    {
        insertLast(first,last,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
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
    }
}

void deleteFirst(PPNODE first,PPNODE last)
{
    if(*first == NULL && *last == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        (*last)->next = (*first)->next;
        (*first)->next->prev = *last;
        free(*first);

        *first = (*last)->next;
    }
}

void deleteLast(PPNODE first,PPNODE last)
{
    if(*first == NULL && *last == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        *last = (*last)->prev;
        free((*first)->prev);
        (*last)->next = *first;
        (*first)->prev = *last;
    }
}

void deleteAtPos(PPNODE first,PPNODE last,int iPos)
{
    PNODE temp = *first;
    int i = 0, iCount = 0;

    iCount = count(*first,*last);

    if(iPos < 1 || iPos > iCount)
    {
        printf("Invalid position\n");
        return;
    }
    else if(iPos == 1)
    {
        deleteFirst(first,last);
    }
    else if(iPos == iCount)
    {
        deleteLast(first,last);
    }
    else
    {
        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
    }
}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;
    int iRet = 0;

    insertFirst(&head,&tail,51);
    insertFirst(&head,&tail,21);
    insertFirst(&head,&tail,11);
    
    insertLast(&head,&tail,101);
    insertLast(&head,&tail,111);
    insertLast(&head,&tail,121);

    insertAtPos(&head,&tail,105,5);

    deleteFirst(&head,&tail);
    deleteLast(&head,&tail);
    deleteAtPos(&head,&tail,4);

    display(head,tail);
    iRet = count(head,tail);

    printf("Number of elements in list are: %d",iRet);

    return 0;
}