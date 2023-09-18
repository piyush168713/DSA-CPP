#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
}
*first = NULL, *second=NULL, *third=NULL;

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

void create2(int arr[], int n){
    int i;
    Node *t, *last;
    second = new Node;    // creates a new node and first will be pointing on that one
    second->data = arr[0];
    second->next = NULL;
    last = second;

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

void concat(Node *p, Node *q)
{
    third = p;
    while (p->next != NULL)
    {
        p=p->next;
    }
    p->next = q;
    second = NULL;
    
}

int main(){

    int A[] = {3,5,7,10,13,15};
    int B[] = {20,30,40,50,60};

    create(A, 6);
    create2(B,5);

    cout<<"\nFirst: ";
    display(first);

    cout<<"\n\nSecond: ";
    display(second);

    cout<<"\n\nNew Linked List (Concatinated): ";
    concat(first, second);
    display(third);

    return 0;
}
