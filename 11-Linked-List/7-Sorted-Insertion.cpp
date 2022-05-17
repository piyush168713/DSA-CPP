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


void sortedInsert(Node *p, int x)
{
    Node *q = NULL;
    Node *t;
    t = new Node;
    t->data = x;
    t->next = NULL;

    if(first == NULL)
    first = t;
    else
    {
        while(p!=NULL && p->data < x)
        {
            q=p;
            p=p->next;
        }
        if(p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int main(){

    // int A[] = {3,5,7,10,13,15};

    // create(A, 6);

    sortedInsert(first, 9);
    sortedInsert(first, 13);
    sortedInsert(first, 22);
    sortedInsert(first, 30);
    sortedInsert(first, 11);

    display(first);

    return 0;
}