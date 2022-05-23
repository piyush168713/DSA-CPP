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

int isLoop(Node *f)
{
    Node *p, *q;
    p = q = f;

    do
    {
        p=p->next;
        q=q->next;
        q = q != NULL ? q->next:NULL;       // similar as line 49-52
        // if(q != NULL)
        // q=q->next;
        // else
        // q=NULL;
    } while (p && q && p!=q);

    if(p == q)
    return true;      // returns 1 if there is Loop
    else
    return false;     // returns 0 if there is no Loop or it is Linear
    
}


int main(){
    Node *t1, *t2;

    int A[] = {10,20,30,40,50};
    create(A, 6);

    // creating a loop in Linked List
    t1 = first->next->next;         // points on 30
    t2 = first->next->next->next->next;         // points on 50
    t2->next = t1;           // 50 points on 30


    cout<<isLoop(first);

    return 0;
}
