// Find Total Time Taken

// Link - https://practice.geeksforgeeks.org/problems/5ae4f296db3e6bb74641c4087d587b6f89d9d135/1

class Solution {
  public:
    int totalTime(int n, vector<int> &arr, vector<int> &time) {
        // code here
        int count = -1;
        unordered_map<int, int> mp;
        
        for(int i = 0; i < n; i++){
            if(mp.find(arr[i]) == mp.end()){
                mp[arr[i]] = count;
            }
            else{
                count = max(count, mp[arr[i]] + time[arr[i]-1]);
                mp[arr[i]] = count;
            }
            count++;
        }
        return count;
    }
};
