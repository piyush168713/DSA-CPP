#include<iostream>
using namespace std;

class Node
{
    public:
    Node *prev;
    int data;
    Node *next;
}*first;

void create(int arr[], int n)
{
    Node *t, *last;
    first = new Node;
    first->prev = NULL;
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = arr[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void display(Node *p)
{
    while(p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
}

int length(Node *p)
{
    int len = 0;
    while(p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

void push(Node *p, int index, int x)
{
    Node *t;
    // if(index < 0 || index > length(p))
    // return;
    if(index == 0)        // if insert before first node
    {
        t = new Node;
        t->data = x;
        if(first == NULL)    // if there is no any node/element/LL or if you have to push element/node from starting
        {
            first = t;
            first->next = NULL;
            first->prev = NULL;
        }
        else
        {
            t->prev = NULL;
            t->next = first;
            first->prev = t;
            first = t;
        }
    }
    else           // For insert at any given index
    {
        t = new Node;
        t->data = x;
        for (int i = 0; i < index-1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        t->prev = p;

        if(p->next != NULL)    // if next node is available then go ahead
        p->next->prev = t;     // right previous node of new node points on new node

        p->next = t;           // left next node of new node points on new node
    }
}

int deletion(Node *p, int pos)
{
    int x=-1;
    if(pos < 0 || pos > length(p))
    return -1;
    if (pos == 1)
    {
        p = first;
        first = first->next;       // move to 2nd node
        if(first != NULL)          // check first(2nd) node is null or not, if null then the previous node never be null
        first->prev = NULL;
        x = p->data;
        delete p;
        return x;
    }
    else
    {
        p = first;
        for (int i = 0; i < pos-1; i++)
        {
            p = p->next;         // p goes to that position which we want to delete
        }
        p->prev->next = p->next;        // previous left node points on right node
        if(p->next != NULL)             // check whether next node is null, if null then it never points on any node
        p->next->prev = p->prev;        // Right previous node points on left node
        x = p->data;
        delete p;
        return x;
    }
}

void Reverse(Node *p)
{
    p = first;
    Node *temp;
    while (p != NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if(p!=NULL && p->next == NULL)
        {
            first = p;
        }
    }
}

int main(){

    int A[] = {6,7,8,9,10};

    create(A,5);
    display(first);
    cout<<"\nTotal no. of Nodes: "<<length(first);

    // cout<<endl;
    // push(first, 0,99);
    // display(first);

    // push(first, 0, 5);
    // push(first, 1, 9);
    // push(first, 2, 11);
    // push(first, 3, 17);
    // push(first, 4, 20);
    // push(first, 5, 24);

    // cout<<"\nTotal no. of Nodes: "<<length(first)<<endl;
    // display(first);

    // cout<<"\nDeleted Node is: "<<deletion(first, 5)<<endl;
    // display(first);

    cout<<endl;
    Reverse(first);
    display(first);
    
    return 0;
}
