// Problem Statement

// Merge 2 sorted array  - CodeStudio

// Link - https://www.codingninjas.com/codestudio/problems/ninja-and-sorted-arrays_121462

#include <bits/stdc++.h> 
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, 
                                     int m, int n) {
	// Write your code here.
    vector<int> ans;
    int i = 0, j = 0;
    while(i < m && j < n)
    {
        if(arr1[i] < arr2[j]){
            ans.push_back(arr1[i++]);
        }
        else{
            ans.push_back(arr2[j++]);
        }
    }
    
    while(i < m){
        ans.push_back(arr1[i++]);
    }
    while(j < n){
        ans.push_back(arr2[j++]);
    }
    return ans;
}
