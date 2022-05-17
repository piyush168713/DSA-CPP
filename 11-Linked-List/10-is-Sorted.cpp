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


int isSorted(Node *p)
{
    int x = -32745;

    while(p!=NULL)
    {
        if (p->data < x)
        return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}



int main(){

    int A[] = {3,5,7,10,13,15};

    create(A, 6);

    cout<<isSorted(first)<<endl;


    if(isSorted(first))
    {
        cout<<"Sorted: ";
    }
    else{
        cout<<"Not Sorted: ";
    }


    display(first);

    return 0;
}