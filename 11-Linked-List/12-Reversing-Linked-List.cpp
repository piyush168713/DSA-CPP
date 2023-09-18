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

void reverseByCreatingArray(Node *p)      // here, p is pointing to first Node
{
    int *A, i = 0;
    Node *q;    // q is taken for triverse a linked list
    A = new int[countNode(p)];

    while (q != NULL)
    {
        A[i] = q->data;
        q=q->next;
        i++;
    }
    q=p;     // Assign q to p(first)
    i--;
    while(q != NULL)
    {
        q->data = A[i];
        q=q->next;
        i--;
    }    
}

void reverseBySlidingPointers(Node *p)
{
    Node *q=NULL, *r=NULL;
    while(p != NULL)
    {
        r=q;   // more r to q
        q=p;   // move q to p
        p=p->next;     // move p to thier next
        q->next=r;     // here, q will always make pointing to r
    }
    first = q;     // assign first to q
}

void reverseByRecursion(Node *q, Node *p)
{
    if(p != NULL)
    {
        reverseByRecursion(p, p->next);
        p->next = q;      // this step executes on returning time
    }
    else
    first = q;     // assign first to q
}


int main(){

    int A[] = {3,5,7,10,13,15};

    create(A, 6);
  
    // reverseByCreatingArray(first);

    // reverseBySlidingPointers(first);

    reverseByRecursion(NULL, first);

    display(first);

    return 0;
}
