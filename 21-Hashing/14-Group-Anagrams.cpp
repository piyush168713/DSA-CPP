// Group Anagrams - gfg/codestudio/leetcode

// Link - https://www.codingninjas.com/codestudio/problems/group-anagrams_800285

#include<unordered_map>
vector<vector<string>> getGroupedAnagrams(vector<string> &inputStr, int n)
{
    // Write your code here.
    unordered_map<string, vector<string>> umap;
        vector<vector<string>> ans;
        
        for(auto x : inputStr){
            string temp = x;
            sort(x.begin(), x.end());
            umap[x].push_back(temp);
        }
        
        for(auto x : umap){
            ans.push_back(x.second);
        }
        return ans;
}
