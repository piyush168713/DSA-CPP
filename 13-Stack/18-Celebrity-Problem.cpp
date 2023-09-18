/*

The Celebrity Problem

Problem Link: https://www.codingninjas.com/codestudio/problems/the-celebrity-problem_982769

Problem Statement:

A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
Note: Follow 0 based indexing.

Example 1:

Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity. 

*/

class Solution 
{
    private:
    bool knows(vector<vector<int> >& M, int a, int b)
    {
        if(M[a][b] == 1)
        return true;
        else
        return false;
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> s;
        
        // here, n = 3(0, 1, 2)
        for(int i = 0; i<n; i++)
        {
            s.push(i);
        }
        
        // pop only 2 elements from stack & check conditions for both elements
        while(s.size() > 1)
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            
            if(knows(M,a,b))
            {
                s.push(b);
            }
            else
            {
                s.push(a);
            }
        }
        
        // ;astly, single element(ans) is left in stack, then verify it whether it is celebrity or not.
        int ans = s.top();
        
        int zeroCount = 0;
        
        for(int i = 0; i<n; i++)
        {
            if(M[ans][i] == 0)
            zeroCount++;
        }
        
        if(zeroCount != n)
        return -1;
        
        int oneCount = 0;
        for(int i = 0; i<n; i++)
        {
            if(M[i][ans] == 1)
            oneCount++;
        }
        
        if(oneCount != n-1)
        return -1;
        
        return ans;
    }
};




// OR


#include<stack>

bool knows(vector<vector<int> >& M, int a, int b)
    {
        if(M[a][b] == 1)
        return true;
        else
        return false;
    }

int findCelebrity(int n) {
 	// Write your code here.
    
    stack<int> s;
    
    for(int i=0; i<n; i++){
        s.push(i);
    }
    
    while(s.size() > 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        
        if(knows(a,b))
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }
    int ans = s.top();
    
    if(s.empty()){
        return -1;
    }
    
    for(int i = 0; i<n; i++)
    {
        if(i != ans && !knows(i,ans))
        {
            return -1;
        }
    }
    
    for(int i = 0; i<n; i++)
    {
        if(knows(ans,i))
        {
            return -1;
        }
    }
    return ans;
}
