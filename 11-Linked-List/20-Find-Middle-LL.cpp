#include<iostream>
#include<cmath>
#include<stack>
using namespace std;

class Node
{
    public:
    Node *next;
    int data;
}*head;

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

void display(Node *p)
{
    while (p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
}


void middleNode1(Node *p)
{
    int len = 0;
    while(p != NULL)
    {
        len++;
        p = p->next;
    }

    int index = (int)ceil(len/2.0);
    Node *q = head;
    for (int i = 0; i < index-1; i++)
    {
        q = q->next;
    }
    cout<<"\nMiddle Element (Mtd-1): "<<q->data<<endl;
    
}

void middleNode2(Node *p)
{
    Node *q = p;
    while(q != NULL)
    {
        q = q->next;
        if(q != NULL)
        {
            q = q->next;
        }
        if(q != NULL)
        {
            p = p->next;
        }
    }
    cout<<"\nMiddle Element (Mtd-2): "<<p->data<<endl;
}


void middleNode3(Node *p)
{
    stack<Node*> s;
    while(p != NULL)
    {
        s.push(p);
        p = p->next;
    }

    int length = s.size();
    int popLength = (int)(floor(length/2.0));
    while(popLength)
    {
        s.pop();
        popLength--;
    }
    cout<<"\nMiddle Element (Mtd-3): "<<s.top()->data<<endl;
}


int main(){
    int A[] = {5,6,7,8,9};

    create(A, sizeof(A)/sizeof(A[0]));

    display(head);

    middleNode1(head);

    middleNode2(head);

    middleNode3(head);
    
    return 0;
}
