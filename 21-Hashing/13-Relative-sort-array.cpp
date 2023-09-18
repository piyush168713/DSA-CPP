// Relative Sort Array - gfg/codestudio/leetcode
// Relative Sorting

// Link - https://www.codingninjas.com/codestudio/problems/medium_982932

#include<bits/stdc++.h>
vector<int> relativeSorting(vector<int> &arr, vector<int> &brr, int n, int m)
{
    // Write your code here.
    map<int, int> mp;
    vector<int> ans;
    
    for(int i = 0; i < n; i++){
        mp[arr[i]]++;
    }
    
    for(int i = 0; i < m; i++){
        if(mp.count(brr[i]) == 0){
            continue;
        } else {
            while(mp[brr[i]] != 0){
                ans.push_back(brr[i]);
                mp[brr[i]]--;
            }
            mp.erase(brr[i]);
        }
    }
    
    // traverse for remaining element of map
    vector<int> rem;
    for(auto x : mp){
        while(x.second != 0){
            rem.push_back(x.first);
            x.second--;
        }
    }
    ans.insert(ans.end(), rem.begin(), rem.end());
    return ans;
}
