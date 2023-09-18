// Minimum Integer

// Link - https://practice.geeksforgeeks.org/problems/1ccf56f107bcb24242469ea45c02f852165a2184/1

class Solution {
  public:
    int minimumInteger(int n, vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        long long sum = 0;
        
        for(int i = 0; i < n; i++){
            sum += arr[i];
        }
        
        for(int i = 0; i < n; i++){
            if(sum <= (long long)n * (long long) arr[i]){
                return arr[i];
            }
        }
        return -1;
    }
};
