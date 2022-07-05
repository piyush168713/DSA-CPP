/*

N Queue using Array

Problem Statement
You will be given ‘N’ queries. You need to implement ‘N’ queues using an array according to those queries. Each query will belong to one of these two types:
1 ‘X’ N: Enqueue element ‘X’  into the end of the nth queue. Returns true if the element is enqueued, otherwise false.

2 N: Dequeue the element at the front of the nth queue. Returns -1 if the queue is empty, otherwise, returns the dequeued element.
Note:
Please note that Enqueue means adding an element to the end of the queue, while Dequeue means removing the element from the front of the queue.
Input Format:
The first line of input contains three space-separated integers ‘N’, ‘S’ and ‘Q’ denoting the number of queues, the size of the array and number of queries, respectively. 

The next ‘Q’ lines specify the type of operation/query to be performed on the data structure.

Each query contains an integer ‘P’ denoting the type of query.

For query of type 1, the integer ‘P’ is equal to 1 and it is followed by two space-separated integers ‘X’ and ‘M’ denoting the element and queue on which operation is to be performed, respectively.

For query of type 2, the integer ‘P’ is equal to 2 and it is followed by a single integer ‘M’ denoting the queue on which operation is to be performed.
Output Format:
For each query, return the output returned after performing the corresponding operation on the data structure. 

Print the output of each test case in a separate line.

*/

#include<iostream>
using namespace std;

class kQueue{
    public:
        int n;
        int k;
        int* front;
        int* rear;
        int* arr;
        int freespot;
        int* next;

    public:
        kQueue(int n, int k)
        {
            this->n = n;
            this->k = k;
            front = new int[k];
            rear = new int[k];
            for (int i = 0; i < k; i++)
            {
                front[i] = -1;
                rear[i] = -1;
            }
            
            next = new int[n];
            for (int i = 0; i < n; i++)
            {
                next[i] = i+1;
            }
            next[n-1] = -1;
            
            arr = new int[n];
            freespot = 0;
        }

        void enqueue(int data, int qn)
        {
            // overflow condition
            if(freespot == -1)
            {
                cout<<"No Empty space is Present\n";
                return;
            }

            // find first free index
            int index = freespot;

            // update freespot
            freespot = next[index];

            // check if first element is being pushed
            if(front[qn-1] == -1)
            {
                front[qn-1] = index;
            }
            else
            {
                // link new element to the previous element
                next[rear[qn-1]] = index;
            }

            // update next
            next[index] = -1;

            // update rear
            rear[qn-1] = index;

            // push element
            arr[index] = data;
        }

        int dequeue(int qn)
        {
            // underflow condition
            if(front[qn-1] == -1)
            {
                cout<<"Queue Underflow\n";
                return -1;
            }

            // find index to pop
            int index = front[qn-1];

            // go next to front
            front[qn-1] = next[index];

            // manage the freeslot
            next[index] = freespot;
            freespot = index;
            return arr[index];
        }
};

int main(){

    kQueue k(10, 3);
    k.enqueue(10,1);
    k.enqueue(15,1);
    k.enqueue(20,2);
    k.enqueue(25,1);

    cout<<k.dequeue(1)<<endl;
    cout<<k.dequeue(2)<<endl;
    cout<<k.dequeue(1)<<endl;
    cout<<k.dequeue(1)<<endl;
    cout<<k.dequeue(1)<<endl;
    
    return 0;
}
