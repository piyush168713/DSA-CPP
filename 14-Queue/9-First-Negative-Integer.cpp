/*

First Negative Integer In Every Window Of Size K

Problem Statement

You have been given an array of integers 'ARR' and an integer ‘K’. You need to find the first negative integer in each window of size ‘K’.

Note :
If a window does not contain a negative integer, then print 0 for that window.

For Example :
If N = 9, arr[ ] = {-10, 20, -30, -40, 50, 60, -70, 80, 90} and K = 3
then the output will be
{-10 -30 -30 -40 -70 -70 -70}

Input Format:
The first line contains an integer 'T' which denotes the number of test cases or queries to be run. Then the test cases are as follows.
The first line of each test case contains an integer ‘N’ which denotes the size of the array.
The second line of each test case contains elements of the array. The line consists of values of elements of the array separated by a single space.
The third line of each test case contains an integer ‘K’ which denotes the window size.  

Output Format:
For each test case, print the first negative integer in each window of size ‘K’ separated by a space.

Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.

Sample Input 1:
1
9
-10 20 -30 -40 50 60 -70 80 90
3

Sample Output 1:
-10 -30 -30 -40 -70 -70 -70

Explanation For Sample Input 1:
Here the first negative integer in the window  of size K = 3 is [-10, -30, -30, -40, -70, -70, -70]

*/

#include<deque>
vector<int> firstNegativeInteger(vector<int> &arr, int k, int n)
{
    //Write your code here
    deque<int> dq;
    vector<int> ans;
    
    // process for 1st window
    for(int i = 0; i<k; i++)
    {
        if(arr[i] < 0)
        {
            dq.push_back(i);
        }
    }
    
    // store the ans
    if(dq.size() > 0)
    {
        ans.push_back(arr[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }
    
    // process for remaining window
    for(int i = k; i<n; i++)
    {
        // removal
        if(!dq.empty() && (i-dq.front() >= k))
        {
            dq.pop_front();
        }
        
        // addition
        if(arr[i] < 0)
        {
            dq.push_back(i);
        }
        
        // store the ans
        if(dq.size() > 0)
        {
            ans.push_back(arr[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}
