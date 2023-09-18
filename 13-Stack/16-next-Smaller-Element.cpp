/*

Next Smaller Element

Problem Statement

You are given an array 'ARR' of integers of length N. Your task is to find the next smaller element for each of the array elements.
Next Smaller Element for an array element is the first element to the right of that element which has a value strictly smaller than that element.
If for any array element the next smaller element does not exist, you should print -1 for that array element.

For Example:
If the given array is [ 2, 3, 1], we need to return [1, 1, -1]. Because for  2, 1 is the Next Smaller element. For 3, 1 is the Next Smaller element and for 1, there is no next smaller element hence the answer for this element is -1.

Input Format:
The first line of input contains an integer ‘T’ which contains the number of test cases.
The first line of each test case contains an integer 'N' denoting the number of elements in the array 'ARR'.
The second line of each test case contains 'N' space-separated integers denoting the array 'ARR'. 

Output Format:
For each test case, print a single line containing 'N' space-separated integers denoting the value of Next Smaller Element for each of the 'N' array elements.
The output for each test case will be printed in a separate line.

Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.

Constraints:
1 <= T <= 10
1 <= N <= 10 ^ 5
0 <= ARR [i] <= 10 ^ 9

Time Limit: 1sec.

Sample Input 1:
2
4
2 1 4 3
3
1 3 2

Sample Output 1:
1 -1 3 -1
-1 2 -1

Explanation For Sample Input 1:

For the first test case : 
1) For ARR [1] = 2 ,  the next smaller element is 1. 
2) For ARR [2] = 1 ,  the next smaller element is -1 as no element in the array has value smaller than 1.
3) For ARR [3] = 4 ,  the next smaller element is 3.
4) For ARR [4] = 3 ,  the next smaller element is -1 as no element exists in the right of it.
Hence, we will return the array [ 1, -1, 3, -1] in this case.

For the second test case :
1) For ARR [1] = 1 ,  the next smaller element is -1 as no element in the array has value smaller than 1.
2) For ARR [2] = 3 ,  the next smaller element is 2.
3) For ARR [3] = 2 ,  the next smaller element is -1 as no element exists in the right of it.
Hence we will return the array [ -1, 2, -1 ] in this case.

*/

#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> s;
    s.push(-1);
    // answer array
    vector<int> ans(n);
    
    for(int i = n-1; i>=0; i--)
    {
        int curr = arr[i];
        while(s.top() >= curr)
        {
            s.pop();
        }
        // if you get out from while loop, means ans is s.top()
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}
