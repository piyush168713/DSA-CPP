// Yet another query problem

// Link - https://practice.geeksforgeeks.org/problems/ad6699d4aaf84c74b119fac3b65e9ceb3fc8ef14/1

class Solution {
  public:
    vector<int> solveQueries(int N, int num, vector<int> &A, vector<vector<int>> &Q) {
        // code here
        unordered_map<int, int> mp;
        vector<int> freq(N, 0);
        
        for(int i = N-1; i >= 0; i--){
            mp[A[i]]++;
            freq[i] = mp[A[i]];
        }
        
        vector<int> ans;
        
        for(auto it : Q){
            int l = it[0];
            int r = it[1];
            int k = it[2];
            int count = 0;
            
            for(int i = l; i <= r; i++){
                if(freq[i] == k){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
