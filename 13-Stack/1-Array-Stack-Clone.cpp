#include<iostream>
using namespace std;

class stack{
    public:
    int *arr;
    int size;
    int top;

    stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void display()
    {
        cout<<"\nElements in the Stack are: ";
        for (int i = top; i >= 0; i--)
        {
            cout<<arr[i]<<" ";
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
            arr[top] = x;
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
            x = arr[top--];
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
            x = arr[top-index+1];
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
            return arr[top];
        }
    }

};


int main(){

    stack stk(5);

    stk.push(3);
    stk.push(5);
    stk.push(6);
    stk.push(8);
    stk.push(9);

    stk.display();

    // cout<<stk.pop();
    // stk.display();
    // cout<<stk.pop();
    // stk.display();
    // cout<<stk.pop();
    // stk.display();
    // cout<<stk.pop();

    cout<<stk.peek(1)<<endl;

    cout<<"Is Full: "<<stk.isFull()<<endl;
    cout<<"Is Empty: "<<stk.isEmpty()<<endl;
    cout<<"Element at top: "<<stk.stackTop()<<endl;


    
    return 0;
}
