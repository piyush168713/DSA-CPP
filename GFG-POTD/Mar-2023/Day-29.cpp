// Count the Substrings

// Link - https://practice.geeksforgeeks.org/problems/839d6ba2c2e4c669ba9d9d9f32ad20118937284e/1

class Solution
{
    public:
    int countSubstring(string S)
    {
        // code here
        unordered_map<int, int> mp;
        // mp[0] = 1;
        int sum = 0;
        int ans = 0;
        
        for(char it : S){
            int val;
            if(isupper(it)){
                val = 1;
            }
            else{
                val = -1;
            }
            
            sum += val;
            
            if(sum == 0){
                ans++;
            }
            
            if(mp.find(sum) != mp.end()){
                ans += mp[sum];
            }
            mp[sum]++;
        }
        return ans;
    }
};
