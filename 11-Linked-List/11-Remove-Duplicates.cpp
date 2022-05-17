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

void removeDuplicates(Node *p)
{
    Node *q = p->next;

    while(q != NULL)
    {
        if(p->data != q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next = q->next; 
            delete q;
            q=p->next;     // make q point on next node of p
        }
    }

}



int main(){

    int A[] = {3,5,5,8,8,8};

    create(A, 6);

    removeDuplicates(first);

    display(first);

    return 0;
}