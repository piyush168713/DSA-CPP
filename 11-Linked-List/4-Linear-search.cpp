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

Node* search(Node *p, int key)   // return type is pointer/Address of element
{
    while(p != NULL)
    {
        if (key == p->data)
        return p;
        p=p->next;
    }
    return NULL;
}

Node* recursiveSearch(Node *p, int key)
{
    if (p == 0)
    return NULL;
    if(key == p->data)
    return p;
    return recursiveSearch(p->next, key);
}

int main(){

    int A[] = {3,5,7,10,13,15};

    create(A, 6);

    cout<<"Normal Call: ";
    display(first);
    cout<<"\n";

    Node *temp;


    // cout<<"\nElement 10 is present at Address: "<<search(first, 10);

    temp = recursiveSearch(first, 13);
    if (temp != NULL)
    cout<<"Key is Found: "<<temp->data<<endl;
    else
    cout<<"Key not found\n";



    cout<<"\nElement 13 is present at Address: (Recursive)"<<recursiveSearch(first, 13);

    
    return 0;
}