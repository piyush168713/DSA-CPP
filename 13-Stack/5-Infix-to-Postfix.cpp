#include<iostream>
#include<string>
using namespace std;

int Stack[100];

int size;
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
    if(top == size-1)
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
    if(top == size-1)
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


int pre(char x)
{
    if(x == '+' || x == '-')
    return 1;
    else if(x == '*' || x == '/')
    return 2;
    return 0;
}

int isOperand(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/')
    return 0;
    else 
    return 1;
}

char *infixToPostfix(char *infix)
{
    int i=0, j=0;
    char* postfix = new char[100];
    // postfix = new char[infix.length()+2];
    while(infix[i] != '\0')
    {
        if(isOperand(infix[i]))
        postfix[j++] = infix[i++];
        else
        {
            if(pre(infix[i]) > pre(stackTop()))
            push(infix[i++]);
            else
            postfix[j++] = pop();
        }
    }
    while(!isEmpty())
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}


int main(){

    cout<<"Enter the size of stack: ";
    cin>>size;

    char* infix = "a+b*c";
    char* infix1 = "a+b*c-d/e";
    // push(1);

    char* postfix = infixToPostfix(infix1);

    cout<<postfix;


    
    return 0;
}
