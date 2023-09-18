// Rod Cutting

// Link - https://practice.geeksforgeeks.org/problems/rod-cutting0840/1

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        int dp[n];
        for(int i=0; i<n; i++){
            dp[i] = price[i];
            for(int j=0; j<i; j++)
                dp[i] = max(dp[i], dp[i-j-1]+price[j]);
        }
        return dp[n-1];
    }
};
