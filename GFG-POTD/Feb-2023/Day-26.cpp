// Number of Good Components

// Link - https://practice.geeksforgeeks.org/problems/1a4b617b70f0142a5c2b454e6fbe1b9a69ce7861/1

class Solution {
  public:
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        // code here
        vector<bool> vis(V+1,false);
        queue<int> bfsq;
        int ans = 0;
        
        for(int i = 1; i < V + 1; i++){
            if(vis[i])
            continue;
            
            int nv = 1;
            int deg = adj[i].size();
            bfsq.push(i);
            vis[i] = true;
            
            while(!bfsq.empty()){
                int cur_node = bfsq.front();
                bfsq.pop();
                for(auto x : adj[cur_node]){
                    if(!vis[x]){
                        vis[x] = true;
                        bfsq.push(x);
                        nv++;
                        deg += adj[x].size();
                    }
                }
            }
            if(deg/2 == (nv * (nv-1))/2)
            ans++;
        }
        return ans;
    }
};
