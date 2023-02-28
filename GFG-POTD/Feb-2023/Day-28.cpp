// Optimal Array

// Link - https://practice.geeksforgeeks.org/problems/d4aeef538e6dd3280dda5f8ed7964727fdc7075f/1

class Solution{
public:
    vector<int> optimalArray(int n,vector<int> &a){
        // Code here
        vector<int> ans(n,0);
        
        for(int i = 1; i < n; i++){
            int x = abs(a[i] - a[i/2]);
            ans[i] = ans[i-1] + x;
        }
        return ans;
    }
};
