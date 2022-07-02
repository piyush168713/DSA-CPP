#include<iostream>
using namespace std;

class Queue{
private:
    int size;
    int front;
    int rear;
    int *Q;
public:
    Queue(){
        front = rear = -1;
        size=5;
        Q = new int[size];
    }

    Queue(int size)
    {
        front = rear = -1;
        this->size=size;
        Q = new int[this->size];
    }

    void enqueue(int x);
    int dequeue();
    void display();
    int isFull();
    int isEmpty();
};

void Queue :: enqueue(int x)
{
    if(rear == size-1)
        cout<<"Queue is Full\n";
    else
    {
        rear++;
        Q[rear] = x;
    }
}

int Queue :: dequeue()
{
    int x = -1;
        if(front == rear)
        cout<<"Queue is Empty";
        else
        {
            front++;
            x = Q[front];
        }
        return x;
}

void Queue::display()
{
    for (int i = front+1; i <= rear; i++)
    {
        cout<<Q[i]<<" ";
    }
    cout<<endl;
}

int Queue :: isFull()
{
    if(rear == size-1)
    return 1;
    else 
    return 0;
}

int Queue :: isEmpty()
{
    if(front == rear)
    return 1;
    else
    return 0;
}

int main(){

    Queue qu;

    qu.enqueue(5);
    qu.enqueue(10);
    qu.enqueue(15);
    qu.enqueue(20);
    qu.enqueue(25);

    qu.display();

    // if(qu.isFull())
    // cout<<"Queue is Full"<<endl;
    // else
    // cout<<"Queue is not Full"<<endl;

    // if(qu.isEmpty())
    // cout<<"Queue is Empty"<<endl;
    // else
    // cout<<"Queue is not Empty"<<endl;

    cout<<"Deleted Element is: "<<qu.dequeue()<<endl;

    qu.display();

    qu.enqueue(300);
    qu.display();

    
    return 0;
}


/*

-> Drawbacks of queue using array
   
  - we can't use the space of deleted element.
  - Every location can be used once and can't reuse again.
  
-> Solution:
  - You can use location/space of deleted element by resetting the pointers. i.e. set again rear = front = -1
  - See 2-circular-queue-array.cpp

*/
