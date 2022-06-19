#include<iostream>
using namespace std;

int Stack[100];

int n, x;
// n = size of stack
int top = -1;

void display()
{
    cout<<"\nElements in the Stack are: ";
    for (int i = top; i >= 0; i--)
    {
        cout<<Stack[i]<<" ";
    }
    cout<<endl;
}

void push(int x)
{
    if(top == n-1)
    {
        cout<<"Stack Overflow\n";
    }
    else
    {
        top++;
        Stack[top] = x;
    }
}

int pop()
{
    int x=-1;
    if(top == -1)
    {
        cout<<"Stack Underflow\n";
    }
    else
    {
        x = Stack[top--];
    }
    return x;
}

int peek(int index)
{
    int x=-1;
    if(top-index+1 < 0)
    {
        cout<<"Invalid Position\n";
    }
    else
    {
        cout<<"Element at position "<<index<<" from peak is: ";
        x = Stack[top-index+1];
    }
    return x;
}

int isFull()
{
    if(top == n-1)
    return 1;
    else
    return 0;
}

int isEmpty()
{
    if(top == -1)
    return 1;
    else
    return 0;
}

int stackTop()
{
    if(top == -1)
    {
        return -1;
    }
    else
    {
        return Stack[top];
    }
}


int main(){

    cout<<"Enter the size of stack: ";
    cin>>n;

    push(3);
    push(5);
    push(6);

    display();

    // cout<<pop();
    // display();
    // cout<<pop();
    // display();
    // cout<<pop();
    // display();
    // cout<<pop();

    cout<<peek(1)<<endl;

    cout<<"Is Full: "<<isFull()<<endl;
    cout<<"Is Empty: "<<isEmpty()<<endl;
    cout<<"Element at top: "<<stackTop()<<endl;


    
    return 0;
}
