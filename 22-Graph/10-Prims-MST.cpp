// Problem Statement

// Prim's MST - CodeStudio

// Link - https://www.codingninjas.com/codestudio/problems/prim-s-mst_1095633

#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // create adj list
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i = 0; i < g.size(); i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    
    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);
    
    for(int i = 0; i <= n; i++){
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }
    
    // algo start
    key[1] = 0;    // here, src node is 1
    
    for(int i = 1; i < n; i++){
        int mini = INT_MAX;
        int u;
        
        // find min value bali node
        for(int v = 1; v <= n; v++){
            if(mst[v] == false && key[v] < mini){
                // min value taken out from key[] for traverse adj node
                u = v;   // index
                mini = key[v];    // value
            }
        }
        // mark min node as true
        mst[u] = true;
        
        // check its adj node
        for(auto it : adj[u]){
            int v = it.first;
            int w = it.second;
            if(mst[v] == false && w < key[v]){
                // update parent value with u and key with weight
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    
    vector<pair<pair<int, int>, int>> ans;
    for(int i = 2; i <= n; i++){
        ans.push_back({{parent[i], i}, key[i]});
    }
    return ans;
}
