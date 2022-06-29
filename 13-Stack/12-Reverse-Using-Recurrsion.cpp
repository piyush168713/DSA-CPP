// Reverse Stack Using Recursion

/*
Problem Statement

Reverse a given stack of integers using recursion.

Note:
You are not allowed to use any extra space other than the internal stack space used due to recursion.
You are not allowed to use the loop constructs of any sort available as handy. For example: for, for-each, while, etc. 
The only inbuilt stack methods allowed are:
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.

Input Format :
The first line of input contains an integer value N, denoting the size of the input Stack.

The second line contains N single space-separated integers, denoting the stack elements, where the last (Nth) element is the TOP most element of Stack.    

Constraints :
0 <= N <= 10^3

Where 'N' is the number of elements in the given stack.

Output Format :
N single space-separated integers in a single line, where the first integer denotes the TOP element of the reversed stack.

Sample Input 1 :
3
2 1 3

Sample Output 1 :
2 1 3

Explanation To Sample Input 1 :
First-line contains an integer 3 denotes the size of the input stack i.e N = 3.
Second-line contains 3 single space-separated integers i.e the elements of the stack.

*/

void insertAtBottom(stack<int> &s, int x)
{
    if(s.empty())
    {
        s.push(x);
        return;
    }
    
    int num = s.top();
    s.pop();
    
    insertAtBottom(s,x);
    s.push(num);
}

void reverseStack(stack<int> &stack) {
    // Write your code here
    if(stack.empty())
    {
        return;
    }
    
    int num = stack.top();
    stack.pop();
    
    // Recursive call
    reverseStack(stack);
    
    insertAtBottom(stack, num);
}
