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
        p=p->next;
    }
}

void recursiveDisplay(Node *p)
{
    if (p != NULL)
    {
        cout<<p->data<<" ";
        recursiveDisplay(p->next);
        // cout<<p->data<<" ";
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

int add(Node *p)
{
    int sum=0;
    while(p != NULL)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}

int recursiveAdd(Node *p)
{
    if (p == NULL)
    return 0;
    else 
    return recursiveAdd(p->next) + p->data;
}


int main(){

    int A[] = {3,5,7,10,13,15};

    create(A, 6);

    cout<<"Normal Call: ";
    display(first);

    cout<<"\nRecursive Call: ";
    recursiveDisplay(first);

    cout<<endl<<"Total Nodes: "<<countNode(first);


    cout<<endl<<"Total Sum: "<<add(first);


    cout<<endl<<"Total Sum (Recursive): "<<recursiveAdd(first);


    
    return 0;
}