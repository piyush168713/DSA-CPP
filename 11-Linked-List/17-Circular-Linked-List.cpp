#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
}*Head;

void create(int arr[], int n)
{
    Node *t, *last;
    Head = new Node;
    Head->data = arr[0];
    Head->next = Head;
    last = Head;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = arr[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

int countNode(Node *p)
{
    int c=0;
    do
    {
        c++;
        p = p->next;
    } while (p != Head);
    return c;
}

// Using do-while Loop
// Head will always points the first element.
// we use do-while loop because to ignore the first of step of loop that on returning it will check if p != Head 
// then the loop will false and then loop stops.
// if we use while loop then on the first step, on starting (p != Head) statement will false and loop stops at beginning.
void display(Node *p)
{
    do
    {
        cout<<p->data<<" ";
        p=p->next;
    } while (p != Head);
}  

// Using Recursion
void display1(Node *p)
{
    static int flag = 0;
    if (p != Head || flag == 0)
    {
        flag = 1;
        cout<<p->data<<" ";
        display1(p->next);
    }
    flag = 0;
}

void push(Node *p, int index, int x)
{
    Node *t;
    // if(index < 0 || index > countNode(p))
    // return;

    p = Head;
    if (index == 0)       // For Insert before Head
    {
        t = new Node;
        t->data = x;
        if(Head == NULL)       // if there is no any node/element/LL or if you have to push element/node from starting
        {
            Head = t;
            Head->next = Head;
        }
        else
        {
            while(p->next != Head)
            p=p->next;          // goes to last node... see line 88

            p->next = t;      // last node points on First Node t or Head to mantain Circular linked list 
            t->next = Head;    // t points on first node
            Head = t;          // t becomes Head.... here t and Head comes on same position
        }
    }
    else if(index > 0)          // For insert at any position
    {
        p = Head;
        for (int i = 0; i < index-1; i++)
        {
            p = p->next;
        }

        t = new Node;
        t->data = x;

        if(p)
        {
            t->next = p->next;
            p->next = t;
        }   
    }
}

int deletion(Node *p, int pos)
{
    Node *q;
    if(pos < 0 || pos > countNode(p))
    return -1;
    int x=-1;
    if (pos == 1)           // For Delete Head node
    {
        p = Head;
        while (p->next != Head)
        p = p->next;

        x = Head->data;

        if (p == Head)      // if there is only one node in Linked List
        {
            delete Head;
            Head = NULL;
        }
        else{
            p->next = Head->next;
            delete Head;
            Head = p->next;
        }
        return x;
    }
    else               // For delete any node at given position
    {
        p = Head;
        for (int i = 0; i < pos -2; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x=q->data;
        delete q;
        return x;
    }
    
}


int main(){

    int A[] = {5,7,9,11,15};
    create(A,5);
    display(Head);
    cout<<"\nTotal no. of Nodes: "<<countNode(Head)<<"\n\n";

    // push(Head, 0, 10);
    // display(Head);
    
    // cout<<endl;
    // push(Head,0,4);
    // push(Head,1,8);
    // push(Head,2,10);
    // push(Head,3,15);
    // push(Head,4,20);

    // display(Head);
    // cout<<endl;
    // push(Head, 0, 99);
    // display(Head);


    cout<<"\nDeleted element is: "<<deletion(Head, 3);
    cout<<endl;
    display(Head);
    
    return 0;
}
