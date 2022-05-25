#include<iostream>
#include<cmath>
#include<stack>
using namespace std;

class Node
{
    public:
    Node *next;
    int data;
};

Node *head = new Node;
Node *second = new Node;

void create(int arr[], int n)
{
    Node *t, *last;
    head = new Node;
    head->data = arr[0];
    head->next = NULL;
    last = head;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void createSecond(Node *p, int arr[], int n)
{
    Node *t, *last;

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
    last->next = p;
}


void display(Node *p)
{
    while (p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
}

void findIntersection(Node *p, Node *q)
{
    // populate first stack
    stack<Node*> stk1;
    while(p != NULL)
    {
        stk1.push(p);
        p = p->next;
    }

    // populate second stack
    stack<Node*> stk2;
    while(p != NULL)
    {
        stk2.push(p);
        q = q->next;
    }

    Node *r;
    while(stk1.top() == stk2.top())
    {
        r = stk1.top();
        stk1.pop();
        stk2.pop();
    }
    cout<<"\nIntersecting Node is "<<r->data<<endl;
}

int main(){
    // create First Linked List
    int A[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
    create(A, sizeof(A)/sizeof(A[0]));

    // create Second Linked List
    Node *t = head;
    int i = 5;
    while(i>0)
    {
        t = t->next;
        i--;
    }
    cout<<t->data<<endl;
    
    int B[] = {2,4,6,8,10};
    createSecond(second, B, sizeof(B)/sizeof(B[0]));

    // Find Intersection
    findIntersection(head, second);
    
    return 0;
}
