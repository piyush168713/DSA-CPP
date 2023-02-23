// Unique Paths in a Grid

// Link - https://practice.geeksforgeeks.org/problems/96161dfced02d544fc70c71d09b7a616fe726085/1

class Solution {
  public:
    int solve(vector<vector<int>> &grid, int i, int j, int n, int m, vector<vector<int>> &dp){
        if(i < 0 || i >= n || j < 0 || j >= m)
            return 0;
        if(!grid[i][j])
            return 0;
        if(i == n-1 && j == m-1)
            return 1;
        if(dp[i][j] != -1)
            return dp[i][j];
        int mod = 1e9+7;
        return dp[i][j] = (solve(grid, i+1, j, n, m, dp)%mod + solve(grid, i, j+1, n, m, dp)%mod)%mod;
    }
  
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        // code here
        vector<vector<int>> dp(n, vector<int> (m, -1));
        int mod = 1e9+7;
        return solve(grid, 0, 0, n, m, dp)%mod;
    }
};
