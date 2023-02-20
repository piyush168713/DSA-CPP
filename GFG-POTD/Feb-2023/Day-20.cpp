// Count Cyclic Path

// Link - https://practice.geeksforgeeks.org/problems/aa0000a5f710ce8d41366b714341eef644ec7b82/1

class Solution{   
public:
    const int mod = 1e9+7;
    int countPaths(int N){
        // code here 
        long long int ans = 0;
        for(int i = 1; i < N; i++){
            ans = ((ans%mod)*3)%mod;
            if(i%2 == 1)
                ans = (ans+3)%mod;
            else
                ans = ans-3;
        }
        return ans%mod;
    }
};
