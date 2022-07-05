/*

Sum of minimum and maximum elements of all subarrays of size “K”

Problem Statement

You are given an array consisting of N integers, and an integer, K. Your task is to determine the total sum of the minimum element and the maximum element of all subarrays of size K.

Note :
The array may contain duplicate elements.
The array can also contain negative integers.
The size of the array is at least 2.
There exists at least one such subarray of size k.

Input Format :
The first line of the input contains an integer T denoting the number of test cases.
The first line of each test case contains two space-separated integers N and K, denoting the number of elements in the array and the size of the subarray to be considered.
The second line of each test case contains N space-separated integers, representing the elements of the array.

Output Format :
For each test case print in a new line, an integer denoting the total sum of minimum and maximum element in all subarrays of size K.

Note :
You do not need to print anything, it has already been taken care of. Just implement the given function.

Constraints :
1 <= T <= 10
1 <= N <= 10^5
1 <= K <= N
1 <= arr[i] <= 10^9

Time Limit: 1sec

Sample Input 1 :
1
5 3
1 2 3 4 5

Sample Output 1 :
18

Explanation For Sample Input 1 :
For the subarray starting from the 0th index and ending at the 2nd index, its minimum element is 1 and the maximum element is 3.
Similarly, for the next subarray starting at the 1st index and ending at the 3rd index, the minimum value is 2 and the maximum is 4. 
And, for the last subarray, the minimum value is 3 and the maximum is 5. So, the total sum will be 1 + 3 + 2 + 4 + 3 + 5 = 18.

*/

#include<iostream>
#include<deque>
using namespace std;

int solve(int* arr, int n, int k)
{
    deque<int> maxi(k);
    deque<int> mini(k);

    // addition of first k size window
    for (int i = 0; i < k; i++)
    {
        // removes smaller element that are useless
        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        // removes larger elementk
        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }
    
   
    int ans = 0;
    for (int i = k; i < n; i++)
    {
        ans += arr[maxi.front()] + arr[mini.front()];

        // next window

        // removal
        while(!maxi.empty() && i - maxi.front() >= k)
        {
            maxi.pop_front();
        }

        while(!mini.empty() && i - mini.front() >= k)
        {
            mini.pop_front();
        }

        // Addition
        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        // removes larger element
        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);

    }
    // for last window
    ans += arr[maxi.front()] + arr[mini.front()];

    return ans;
}

int main(){
    
    int arr[7] = {2,5,-1,7,-3,-1,-2};
    int k = 4;
    cout<<solve(arr,7, k);

    return 0;
}
