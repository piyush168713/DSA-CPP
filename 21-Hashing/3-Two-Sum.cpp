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
