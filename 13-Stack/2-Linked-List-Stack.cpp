#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

class stack
{
    private:
    Node* top;
    public:
    stack(){top=NULL;}
    void display();
    void push(int x);
    int pop();
    int peak(int pos);
    int stackTop();
    int isEmpty();
    int isFull();
};

void stack :: display()
{
    Node* p = top;
    cout<<"Stack is: ";
    while(p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

void stack :: push(int x)
{
    Node* t = new Node();
    if(t == NULL)
    {
        cout<<"Stack is Full\n";
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int stack :: pop()
{
    int x = -1;
    if(top == NULL)
    {
        cout<<"Stack is Empty\n";
    }
    else
    {
        Node* t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

int stack :: peak(int pos)
{
    int x = -1;
    Node* p = top;
    cout<<"Element at Position "<<pos<<" is: ";
    for (int i = 0; i < pos-1 && p != NULL; i++)
    {
        p = p->next;
    }
    if(p != NULL)
    return p->data;
    else 
    return -1;
    
}

int stack :: stackTop()
{
    if(top != NULL)
    {
        return top->data;
    }
    else
    return -1;
}

int stack :: isEmpty()
{
    return top ? 0 : 1;
}

int stack :: isFull()
{
    Node* t = new Node;
    int r = t ? 1 : 0;
    delete t;
    return r;
}

int main(){

    stack stk;

    stk.push(5);
    stk.push(7);
    stk.push(9);

    stk.display();
    
    // cout<<"Popped element is: "<<stk.pop()<<endl;
    // stk.display();

    cout<<stk.peak(2)<<endl;

    cout<<"Element at top of stack is: "<<stk.stackTop()<<endl;

    cout<<stk.isEmpty()<<endl;

    cout<<stk.isFull()<<endl;

    return 0;
}
