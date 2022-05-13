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

Node *improvedSearchMoveToHead(Node *p, int key)
{
    Node *q = NULL;
    while(p != NULL)
    {
        if(key == p->data)
        {
            if(p == first)
            return p;
            else
            {
                q->next = p->next;
                p->next = first;
                first = p;       // giving the address of p to first
            }
            return p;
        }
        q=p;      // moving p & q for search elements
        p=p->next;
    }
    return NULL;
}


int main(){

    int A[] = {3,5,7,10,13,15};

    create(A, 6);

    cout<<"Normal Call: ";
    display(first);
    cout<<"\n";

    Node *temp;
    temp = improvedSearchMoveToHead(first, 10);
    if (temp != NULL)
    cout<<"Key is Found: "<<temp->data<<endl;
    else
    cout<<"Key not found\n";

    display(first);


    // cout<<"\nElement 10 is present at Address: "<<improvedSearch(first, 12);
    
    return 0;
}