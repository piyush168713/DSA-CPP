// Problem Statement

// Two Sum - CodeStudio

// Link - https://www.codingninjas.com/codestudio/problems/two-sum_839653

#include<unordered_map>
vector<pair<int,int>> twoSum(vector<int>& arr, int target, int n)
{
	// Write your code here. 
    vector<pair<int, int>> ans;
    unordered_map<int, int> map;
    
    for(int i = 0; i < arr.size(); i++){
        int y = target - arr[i];
        
        if(map[y]>0){
         if(map.find(y) != map.end()){
              ans.push_back({y,arr[i]});
              map[y]--;
          }
      }
      else{
          map[arr[i]]++;
      }
  } 
      
  if(ans.empty()){
      ans.push_back({-1,-1});
    }
    return ans;
}


// Leetcode

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;                  
        unordered_map<int,int>m;
        
        for(int i=0;i<nums.size();i++)    
        {
            int val = target-nums[i];
            if(m.find(val)!=m.end()) 
            {
                ans.push_back(m.find(val)->second);
                ans.push_back(i);
                break;
            }
            m.insert(pair<int,int>(nums[i],i)); 
        }
        return ans;
    }
};
