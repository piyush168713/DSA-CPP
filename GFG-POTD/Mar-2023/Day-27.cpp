// Divide in Incremental Groups

// Link - https://practice.geeksforgeeks.org/problems/c239059f6d110e6778cc2f2a1ab58ffd0a3d64ca/1

class Solution {
  public:
    int countWaystoDivide(int N, int K) {
        // Code here
        vector<vector<int>> dp(N+1,vector<int>(K+1));
        for(int i=1;i<=N;i++){
            for(int j=1;j<=K;j++){
                if(i<j) dp[i][j]=0;
                else if(j==1) dp[i][j]=1;
                else dp[i][j]=dp[i-1][j-1] + dp[i-j][j];
            }
        }
        
        return dp[N][K];
    }
};
