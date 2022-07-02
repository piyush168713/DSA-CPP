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
        front = rear = 0;
        size=5;
        Q = new int[size];
    }

    Queue(int size)
    {
        front = rear = 0;
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
    if((rear+1)%size == front)      
        cout<<"Queue is Full\n";
    else
    {
        rear = (rear+1)%size;       // i.e rear++;
        // rear++;
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
            // front++;
            front = (front+1)%size;     // i.e. front++;
            x = Q[front];
        }
        return x;
}

void Queue::display()
{
    int i = front+1;

    do
    {
        cout<<Q[i]<<" ";
        i = (i+1)%size;
    } while (i != (rear+1)%size);
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
    // qu.enqueue(25);
    // qu.enqueue(20);

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

    cout<<"Deleted Element is: "<<qu.dequeue()<<endl;
    qu.enqueue(30);

    qu.display();
    
    return 0;
}

// you can use location/space of deleted element in this program.
