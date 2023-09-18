/*

Reverse First K elements of Queue

Problem Statement

You are given a QUEUE containing ‘N’ integers and an integer ‘K’. You need to reverse the order of the first ‘K’ elements of the queue, leaving the other elements in the same relative order.

You can only use the standard operations of the QUEUE STL:
1. enqueue(x) : Adds an item x to rear of the queue
2. dequeue() : Removes an item from front of the queue
3. size() : Returns number of elements in the queue.
4. front() : Finds the front element.

For Example:

Let the given queue be { 1, 2, 3, 4, 5 } and K be 3.
You need to reverse the first K integers of Queue which are 1, 2, and 3.
Thus, the final response will be { 3, 2, 1, 4, 5 }.

Input Format:
The first line of input contains an integer ‘T’ denoting the number of queries or test cases. 
The first line of each input consists of 2 space-separated integers ‘N’ and ‘K’ denoting the size of the queue and the number of elements to be reversed from the front.
The second line of each input consists of ‘N’ space-separated integers denoting the elements of the queue.

Output Format:
For each test case, print the elements of the queue after reversing the order of first ‘K’ elements in a separate line.

Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.

Sample Input 1:
2
5 3
1 2 3 4 5
4 2
6 2 4 1

Sample Output 1:
3 2 1 4 5
2 6 4 1

Explanation:

For test case 1: Refer to the example explained above.
 
*/

#include<stack>
queue<int> reverseElements(queue<int> q, int k)
{
    // Write your code here.
    stack<int> s;
    
    // step 1: pop first k elements from q and push into stack s
    for(int i = 0; i < k; i++)
    {
        int element = q.front();
        q.pop();
        s.push(element);
    }
    
    // step 2: fetch from stack and push back to q
    while(!s.empty())
    {
        int element = s.top();
        s.pop();
        q.push(element);
    }
    
    // fetch first (n-k) elements from q and push back
    int t = q.size() - k;
    
    while(t--)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
}
