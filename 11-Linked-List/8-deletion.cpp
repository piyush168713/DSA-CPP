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


int deletion(Node *p, int index)
{
    Node *q=NULL;
    int x=-1;

    if(index < 1 || index > countNode(p))
    return -1;
    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        delete q;
        return x;
    }
    else
    {
        p = first;
        q = NULL;
        for (int i = 0; i < index-1; i++)
        {
            q=p;
            p=p->next;
        }
        if(p != NULL)
        {
            q->next = p->next;
            x=p->data;
            delete p;
            return x;
        }
        
    }
    
}

int main(){

    int A[] = {3,5,7,10,13,15};

    create(A, 6);

    cout<<"\nDeleted element is: "<<deletion(first, 1)<<endl;

    display(first);

    return 0;
}