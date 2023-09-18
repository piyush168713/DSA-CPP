// Equal Left and Right Subarray Sum

// Link - https://practice.geeksforgeeks.org/problems/78a6854c8a2915e05f236aa407dfaa1bbc8ae7d3/1

class Solution {
  public:
    int equalSum(int N, vector<int> &A) {
        // code here
        int sum = 0;
        for(int i = 0; i < N; i++){
            sum += A[i];
        }
        
        int lsum = 0;
        for(int i = 0; i < N; i++){
            sum -= A[i];
            if(lsum == sum)
                return i+1;
            else
                lsum += A[i];
        }
        return -1;
    }
};
