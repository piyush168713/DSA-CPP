/*

Implement Deque (CodeStudio)

Problem Statement:

Design a data structure to implement deque of size ‘N’. It should support the following operations:

    pushFront(X): Inserts an element X in the front of the deque. Returns true if the element is inserted, otherwise false.
    pushRear(X): Inserts an element X in the back of the deque. Returns true if the element is inserted, otherwise false.
    popFront(): Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    popRear(): Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    getFront(): Returns the first element of the deque. If the deque is empty, it returns -1.
    getRear(): Returns the last element of the deque. If the deque is empty, it returns -1.
    isEmpty(): Returns true if the deque is empty, otherwise false.
    isFull(): Returns true if the deque is full, otherwise false.

Following types of queries denote these operations:

    Type 1: for pushFront(X) operation.
    Type 2: for pushRear(X) operation.
    Type 3: for popFront() operation.
    Type 4: for popRear() operation.
    Type 5: for getFront() operation.
    Type 6: for getRear() operation.
    Type 7: for isEmpty() operation.
    Type 8: for isFull() operation.

Input Format:
    The first line of input contains two space-separated integers ‘N’ and ‘Q’ denoting the size of the deque and the number of queries to be performed, respectively. 

    The next ‘Q’ lines specify the type of operation/query to be performed on the data structure.

    Each query contains an integer ‘P’ denoting the type of query.

    For the query of type 1 and 2, the integer ‘P’ is followed by a single integer ‘X’ denoting the element on which operation is to be performed.

    For the queries of type 3 to 8, a single integer ‘P’ is given, denoting the type of query.

Output Format:
    For each query, print the output returned after performing the corresponding operation on the data structure. 

Sample Input 1:
    5 7
    7
    1 10
    1 20
    2 30
    5
    4
    4

Sample Output 1:
    True 
    True 
    True
    True
    20
    30
    10

*/



class Deque
{
    int* arr;
    int front;
    int rear;
    int size;
public:
    // Initialize your data structure.
    Deque(int n)
    {
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        if(isFull())
        {
            return false;
        }
        else if(isEmpty())
        {
            front = rear = 0;
        }
        else if(front == 0 && rear != size-1)   // for maintain cyclic nature
        {
            front = size-1;
        }
        else
        {
            front--;
        }
        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if(isFull())
        {
            return false;
        }
        else if(isEmpty())
        {
            front = rear = 0;
        }
        else if(rear == size-1 && front != 0)   // for maintain cyclic nature
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if(isEmpty())
        {
            return -1;
        }
        
        int ans = arr[front];
        arr[front] = -1;
        
        if(front == rear)   // for single element is present
        {
            front = rear = -1;
        }
        else if(front == size-1)   // front present at last position
        {
            front = 0;   // to maintain cyclic nature
        }
        else
        {
            front++;
        }
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if(isEmpty())
        {
            return -1;
        }
        
        int ans = arr[rear];
        arr[rear] = -1;
        
        if(front == rear)   // for single element is present
        {
            front = rear = -1;
        }
        else if(rear == 0)   // rear present at first position
        {
            rear = size-1;   // to maintain cyclic nature
        }
        else
        {
            rear--;
        }
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(isEmpty())
        {
            return -1;
        }
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if(isEmpty())
        {
            return -1;
        }
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if(front == -1)
            return true;
        else
            return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if((front == 0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1)))
        {
            return true;
        }
        else
        {
             return false;
        }
    }
};
