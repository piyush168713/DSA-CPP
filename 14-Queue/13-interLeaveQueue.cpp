/*

Interleave The First Half Of The Queue With The Second Half

Problem Statement

You have been given a queue of integers. You need to rearrange the elements of the queue by interleaving the elements of the first half of the queue with the second half.
Note :
The given queue will always be of even length.

For Example :
If N= 10
and Q = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
then the output will be
 Q = [10, 60, 20, 70, 30, 80, 40, 90, 50, 100]

Input :  1 2 3 4
Output : 1 3 2 4

Input : 11 12 13 14 15 16 17 18 19 20
Output : 11 16 12 17 13 18 14 19 15 20

*/

#include<stack>
void interLeaveQueue(queue < int > & q) {
    // Write your code here.
    stack<int> s;
    int n = q.size()/2;
    
    // queue to stack
    for(int i=0; i<n; i++)
    {
        s.push(q.front());
        q.pop();
    }
    
    // stack to queue
    while(!s.empty())
    {
        q.push(s.top()); 
        s.pop();    
    }
    // 1st half of queue pop and push back
    for(int i=0; i<n; i++)
    {
        q.push(q.front());
        q.pop();
    }
    
    // push 1st half in stack again
    for(int i=0; i<n; i++)
    {
        s.push(q.front());
        q.pop();
    }
    
    // stack to queue and pop element of queue and push back
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
        
        q.push(q.front());
        q.pop();
    }
    return;
    
}
