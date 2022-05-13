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
    first = new Node;    // craetes a new node and first will be pointing on that one
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

int max(Node *p)
{
    int m = -34567;
    while(p != NULL)
    {
        if(p->data > m)
        m = p->data;
        p = p->next;
    }
    return m;
}

int recursiveMax(Node *p)
{
    int x=0;
    if (p==0)
    return -1;
    else 
    x = recursiveMax(p->next);
    if (x > p->data)
    return x;
    else 
    return p->data;
}

int recursiveMax1(Node *p)
{
    int x=0;
    if(p==0)
    return -1;
    x=recursiveMax1(p->next);
    return x>p->data ? x:p->data;
}

int main(){

    int A[] = {3,5,7,10,13,15};

    create(A, 6);

    cout<<"Normal Call: ";
    display(first);
    cout<<"\n";

    
    cout<<"Max. Element is: "<<max(first);
    cout<<"\nMax. Element is: (Recursion) "<<recursiveMax(first);
    cout<<"\nMax. Element is: (Recursion)1 "<<recursiveMax1(first);
    
    return 0;
}