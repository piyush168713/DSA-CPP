// Filling Bucket

// link - https://practice.geeksforgeeks.org/problems/filling-bucket0529/1

class Solution {
  public:
  int mod = 1e8;
    int fillingBucket(int N) {
        // code here
        if(N == 0 && N == 1 && N ==2)
            return N;
        int pre = 0;
        int next = 1;
        long sum = 0;
        
        while(N--){
            sum = (pre+next)%mod;
            pre = next;
            next = sum;
        }
        return sum;
    }
};
