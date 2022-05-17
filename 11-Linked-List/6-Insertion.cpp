#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
}
*first = NULL;

void create(int arr[], int n){
    int i;
    Node *t, *last;
    first = new Node;    // creates a new node and first will be pointing on that one
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    
}

void display(Node *p)
{
    while (p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
}

int countNode(Node *p)
{
    int c=0;
    while(p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}

void insert(Node *p, int index, int x)
{
    Node *t;
    if(index < 0 || index > countNode(p))       // checking index vlid or not
    return;
    t = new Node;        // creating new node in heap
    t->data = x;         // assign some value to the new node

    if(index == 0)
    {
        t->next = first;
        first = t;
    }
    else if(index > 0)
    {
        p = first;           // for searching node from first index, we assign p first
        for (int i = 0; i < index-1; i++)      // moving to that node where we want to insert node
        {
            p = p->next;
        }
        if (p)
        {
            t->next = p->next;
            p->next = t;
        }
        
    }
}

int main(){

    // int A[] = {3,5,7,10,13,15};

    // create(A, 6);

    // cout<<"Normal Call: ";
    // display(first);
    // cout<<"\n";

    insert(first, 0,9);
    insert(first, 1,13);
    insert(first, 2,22);
    insert(first, 3,30);
    insert(first, 4,35);

    display(first);

    return 0;
}