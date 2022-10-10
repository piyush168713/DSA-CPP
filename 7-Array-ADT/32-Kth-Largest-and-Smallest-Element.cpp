// Kth Smallest and Largest Element of Array

// https://www.codingninjas.com/codestudio/problems/kth-smallest-and-largest-element-of-array_1115488

#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// Write your code here.
    sort(arr.begin(), arr.end());
    vector<int> nums;
    nums.push_back(arr[k-1]);
    nums.push_back(arr[n-k-1]);
    
    return nums;
}
