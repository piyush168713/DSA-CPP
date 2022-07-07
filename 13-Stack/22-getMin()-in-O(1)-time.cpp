/*

Design a stack that supports getMin() in O(1) time and O(1) extra space

Problem Link: https://www.codingninjas.com/codestudio/problems/design-a-stack-that-supports-getmin-in-o-1-time-and-o-1-extra-space_842465

Problem Statement

Implement a SpecialStack Data Structure that supports getMin() in O(1) time and O(1) extra space along with push(), pop(), top(), isEmpty(), isFull() in O(1). To implement SpecialStack, you should only use inbuilt Stack data structure.
Implement The Following Public Functions :
1. push(data) :
This function should take one argument of type integer. It pushes the element into the stack and returns nothing.

2. pop() :
It pops the element from the top of the stack and, in turn, returns the element being popped or deleted. In case the stack is empty, it returns -1.

3. top() :
It returns the element being kept at the top of the stack. In case the stack is empty, it returns -1.

4. isEmpty() :
It returns a boolean value indicating whether the stack is empty or not.

5. getMin() :
It returns the smallest element present in the stack. In case the stack is empty, it returns -1.

Operations Performed On The Stack:
Query-1(Denoted by an integer 1): Pushes integer data to the stack. (push function)

Query-2(Denoted by an integer 2): Pops the data kept at the top of the stack and returns it to the caller. (pop function)

Query-3(Denoted by an integer 3): Fetches and returns the data being kept at the top of the stack but doesn't remove it, unlike the pop function. (top function)

Query-4(Denoted by an integer 4): Returns a boolean value denoting whether the stack is empty or not. (isEmpty function)

Query-5(Denoted by an integer 5): Returns the smallest element present in the stack. (getMin() function)

Input Format:
The first line contains an integer 'Q’, which denotes the number of queries to be run against each operation in the stack. 
The next 'Q' lines represent an operation that needs to be performed.
For the push operation, the input line will contain two integers separated by a single space, representing the type of the operation in the integer and the integer data being pushed into the stack.
For the rest of the operations on the stack, the input line will contain only one integer value, representing the query being performed on the stack.

Output Format:
For Query-1, you do not need to return anything.
For Query-2, prints the data being popped from the stack.
For Query-3, print the data kept on the top of the stack.
For Query-4, print 'TRUE' or 'FALSE'(without quotes).
For Query-5, print the smallest element present in the stack.
Output for every query will be printed in a separate line.

Note:
You are not required to print anything explicitly. It has already been taken care of. Just implement the function.

Sample Input 1:
6
1 13
1 47
5
4
2
3

Sample Output 1:
13
false
47
13
Explanation Of Input 1:
Here we have six queries in total.

Query 1: Integer 1 represents the push function. Hence we push element ‘13’ onto the stack.

Query 2: Integer 1 represents the push function. Hence we push element ‘47’ onto the stack.

Query 3: Integer 5 represents the getMin function. Hence we print the minimum element present in the stack that is 13.

Query 4: Integer 4 represents the isEmpty function. Hence here, we print false because the stack is not empty.

Query 5: Integer 2 represents the pop function. The stack contains element ‘47’ at the top. We remove/pop ‘47’ from the stack and print ‘47’ on the new line.

Query 6: Integer 3 represents the top function. Because we have element ‘13’ at the top of the stack, we print ‘13’ on the new line.

*/

#include<stack>
#include<limits.h>
class SpecialStack {
    stack<int> s;
    int mini = INT_MAX;
    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
        
    void push(int data) {
        // Implement the push() function.
        if(s.empty())
        {
            s.push(data);
            mini = data;
        }
        else
        {
            if(data < mini)
            {
                int val = 2*data - mini;
                s.push(val);
                mini = data;
            }
            else
            {
                s.push(data);
            }
        }
    }

    int pop() {
        // Implement the pop() function.
        if(s.empty())
            return -1;
        
        int curr = s.top();
        s.pop();
        if(curr > mini)
        {
            return curr;
        }
        else
        {
            int prevMin = mini;
            int val = 2*mini - curr;
            mini = val;
            return prevMin;
        }
    }

    int top() {
        // Implement the top() function.
        if(s.empty())
            return -1;
        
        int curr = s.top();
        if(curr < mini)
        {
            return mini;
        }
        else
        {
            return curr;
        }
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return s.empty();
    }

    int getMin() {
        // Implement the getMin() function.
        if(s.empty())
            return -1;
        return mini;
    }  
};
