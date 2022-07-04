/*

Circular Queue (CodeStudio)

Problem Statement:

You will be given ‘Q’ queries. You need to implement a circular queue according to those queries. Each query will belong to one of these two types:

1 ‘X’: Enqueue element ‘X’ into the end of the nth queue. Returns true if the element is enqueued, otherwise false.

2: Dequeue the element at the front of the nth queue. Returns -1 if the queue is empty, otherwise, returns the dequeued element.

Note:
Enqueue means adding an element to the end of the queue, while Dequeue means removing the element from the front of the queue.

Input Format:
The first line of input contains two space-separated integers ‘N’ and ‘Q’ denoting the size of queue and number of queries, respectively. 

The next ‘Q’ lines specify the type of operation/query to be performed on the data structure.

Each query contains an integer ‘P’ denoting the type of query.

For query of type 1, the integer ‘P’ is equal to 1 and it is followed by one integer ‘X’ denoting the element on which operation is to be performed.

For query of type 2, the integer ‘P’ is equal to 2 which dequeues the element.

Output Format:
For each query, return the output returned after performing the corresponding operation on the data structure. 

Print the output of each test case in a separate line.

Note:
You don’t need to print anything. It has already been taken care of. You just have to complete the given functions.

Constraints:
1 <= N <= 1000
1 <= Q <= 10^5 
1 <= P <= 2
1 <= X <= 10^5

Time limit: 1 sec
Sample Input 1:
3 7
1 2 
1 3 
2 
1 4 
1 6 
1 7 
2

Sample Output 1:
True 
True
2
True
True
False
3

*/



class CircularQueue{
    int* arr;
    int front;
    int rear;
    int size;
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1)))
        //if((front == 0 && rear == size-1) ||  ((rear+1)%(size-1) == front))
        {
            //cout<<"Queue is Full";
            return false;
        }
        else if(front == -1)  // first element to push
        {
            front = rear = 0;
            arr[rear] = value;
        }
        else if(rear == size-1 && front != 0)
        {
            rear = 0;
            arr[rear] = value;
        }
        else 
        {
            rear++;
            arr[rear] = value;
        }
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(front == -1)
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
};
