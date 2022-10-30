// Earthquake and the paint shop

// link - https://practice.geeksforgeeks.org/problems/earthquake-and-the-paint-shop4518/1

struct alphanumeric {
    string name;
    int count;
};
class Solution {
  public:
    vector<alphanumeric> sortedStrings(int N, vector<string> A) {
        // code here
        map<string, int> mp;
        vector<alphanumeric> ans;
        
        for(auto it : A){
            mp[it]++;
        }
        
        for(auto it : mp){
            ans.push_back({it.first, it.second});
        }
        return ans;
    }
};
