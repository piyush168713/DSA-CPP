#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
}*front=NULL, *rear = NULL;

void enqueue(int x)
{
    Node* t = new Node();
    if(t == NULL)
    cout<<"Queue is Full\n";
    else
    {
        t->data = x;
        t->next = NULL;
        if(front == NULL)      // i.e it is on first node
        front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    int x = -1;
    Node* t;

    if(front == NULL)
    cout<<"Queue is Empty"<<endl;
    else
    {
        x = front->data;
        t = front;
        front = front->next;
        delete t;
    }
    return x;
}

void display()
{
    Node* p = front;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main(){

    enqueue(10);
    enqueue(15);
    enqueue(20);
    enqueue(25);
    enqueue(30);

    display();

    cout<<"Deleted Element is: "<<dequeue()<<endl;
    display();
    
    return 0;
}
