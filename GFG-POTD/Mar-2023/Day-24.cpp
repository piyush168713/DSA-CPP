// Remove and Reverse

// Link - https://practice.geeksforgeeks.org/problems/1e2f365be6114b671b915e145ec7dbcfdc432910/1

class Solution {
  public:
    string removeReverse(string S) {
        // code here
        int n = S.size();
        unordered_map<char, int> mp;
        
        for(int i = 0; i < n; i++){
            mp[S[i]]++;
        }
        
        int st = 0;
        int end = n-1;
        
        int dir = 0;
        
        while(st <= end){
            if(dir == 0){
                if(mp[S[st]] == 1){
                    st++;
                }
                else{
                    mp[S[st]]--;
                    S[st] = '@';
                    st++;
                    dir = 1;
                }
            }
            else{
                if(mp[S[end]] == 1){
                    end--;
                }
                else{
                    mp[S[end]]--;
                    S[end] = '@';
                    end--;
                    dir = 0;
                }
            }
        }
        
        string ans;
        for(int i = 0; i < n; i++){
            if(S[i] != '@'){
                ans.push_back(S[i]);
            }
        }
        
        if(dir == 1){
            reverse(ans.begin(), ans.end());
        }
        
        return ans;
    }
};
