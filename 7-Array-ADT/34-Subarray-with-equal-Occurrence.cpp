#include <bits/stdc++.h> 
int subarrays(vector<int>& arr, int n)
{
    // Write your code here.
    for(int i = 0; i < n; i++){
        if(arr[i] == 0)
            arr[i] = -1;
    }
    
    unordered_map<int, int> mp;
    int sum = 0, count = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        
        if(mp.find(sum) != mp.end()){
            count += mp[sum];
        }
        mp[sum]++;
    }
    return count;
}
