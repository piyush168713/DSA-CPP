#include<iostream>
using namespace std;

class Node {
    public:
    Node *next;
    int data;
    Node *prev;
}*Head;

void create(int arr[], int n)
{
    Node *t, *last;
    Head = new Node;
    Head->data = arr[0];
    Head->prev = Head;
    Head->next = Head;
    last = Head;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = arr[i];
        t->prev = Head;
        t->next = Head;
        last->next = t;
        last = t;
    }
    Head->prev = last;
}

int length(Node *p)
{
    int len = 0;
    if(p == NULL)
    {
        return len;
    }
    do
    {
        len++;
        p = p->next;
    } while (p != Head);
    return len;
}

void display(Node *p)
{
    do
    {
        cout<<p->data<<" -> ";
        p = p->next;
    } while (p != Head);
}

void push(Node *p, int index, int x)          // push a data at a certain index
{
    Node *t;
    // if(index < 0 || index > length(p))
    // return;
    if(index == 0)
    {
        t = new Node;
        t->data = x;
        if(Head == NULL)
        {
            t->next = t;
            t->prev = t;
            Head = t;
        }
        else
        {
            // while(p->next != Head)
            // p = p->next;

            // p->next = t;
            // t->prev = p;

            t->prev = Head->prev;
            Head->prev->next = t;

            t->next = Head;
            Head->prev = t;            

            Head = t;
        }
    }
    else
    {
        t = new Node;
        t->data = x;

        for (int i = 0; i < index-1; i++)
        {
            p = p->next;
        }

        t->next = p->next;
        t->prev = p;

        if(p->next != NULL)
        p->next->prev = t;

        p->next = t;
        
    }
}

int deletion(Node *p, int pos)
{
    int x=-1;
    if(pos < 0 || pos > length(p))
    return -1;

    if(pos == 1)      // For deleting 1st Node
    {
        p = Head;
        x = p->data;

        p = p->next;      // moving p to its next

        if(p == Head)        // if there is only one node in Linked List 
        {
            delete p;
            Head = NULL;
        }
        else
        {
            p->prev = Head->prev;         // make p point on last node
            Head->prev->next = p;         // make last node points on p
            delete Head;
            Head = p;               // make p as Head
        }
        
    }
    else
    {
        p = Head;
        Node *q = new Node;
        for (int i = 0; i < pos-1; i++)
        {
            q = p;
            p = p->next;
        }
        x = p->data;
        q->next = p->next;
        p->next->prev = q;
        
        delete p;
        
    }
    return x;
}

void append(Node *p, int x)       // push a data at last node
{
    Node *last = new Node;
    if(Head == NULL)
    {
        Head->data = x;
        Head->next = Head;
        Head->prev = Head;
        last = Head;
    }
    else
    {
        last = Head->prev;
        Node *t = new Node;
        t->data = x;
        t->next = Head;
        t->prev = last;
        last->next = t;
        last = t;
        Head->prev = last;
    }
}

void sortedInsertion(Node *p, int x)          // push a data at a sorted position
{
    Node *t = new Node;
    t->data = x;

    // check if linked list is empty or not
    if(Head == NULL)
    {
        t->next = t;
        t->prev = t;
        Head = t;
    }

    // checking this condtition
    // because if  length is one 
    // then p->next == head always and this will
    // false main condition and didn't 
    // insert element at last or begin
    // so we handle this situation differently
    else if(length(Head) == 1)
    {
        t->next = p;
        t->prev = p;
        p->prev = t;
        p->next = t;
        if(p->data > x)
        Head = t;
    }
    else
    {
        Node *q = NULL;
        while (p->data < x && p->next != Head)
        {
            q = p;
            p = p->next;
        }

        // this condition when element is inserted at last
        if(p->data < x)
        {
            t->next = p->next;
            t->prev = p;
            p->next = t;
            t->next->prev = t;
        }

        // condition if element is inserted at the beginning
        else if(q == NULL)
        {
            t->next = p;
            t->prev = p->prev;
            p->prev = t;
            t->prev->next = t;
            Head = t;
        }

        // condition when element is inserted at any 
        // position, neither at last nor at begin
        else
        {
            t->next = p;
            t->prev = q;
            p->prev = t;
            q->next = t;
        }
    }
}

int main(){

    // int A[] = {5,7,9,11,15};
    // create(A,5);
    // display(Head);
    // cout<<"\nTotal no. of Node: "<<length(Head)<<endl;

    // cout<<endl;
    // push(Head, 0, 100);
    // display(Head);
    
    // push(Head,0,5);
    // push(Head,1,9);
    // push(Head,2,11);
    // push(Head,3,15);
    // push(Head,4,20);
    // display(Head);

    // cout<<endl;
    // cout<<"Deleted Element is: "<<deletion(Head, 1)<<endl;
    // display(Head);

    // cout<<endl;
    // append(Head, 100);
    // display(Head);

    // cout<<endl;
    // sortedInsertion(Head, 2);
    // display(Head);


    sortedInsertion(Head,99);
    sortedInsertion(Head,13);
    sortedInsertion(Head,23);
    sortedInsertion(Head,9);
    sortedInsertion(Head,12);
    display(Head);

    return 0;
}
