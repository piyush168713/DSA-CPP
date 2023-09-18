// Problem Statement

// Bridges In A Graph - CodeStudio

// Link - https://www.codingninjas.com/codestudio/problems/bridges-in-graph_893026

/*
  Bridges in a Graph:-
    A bridge in any graph is defined as an edge which, when removed, 
    makes the graph disconnected. & no. of components will increase.

*/

#include<bits/stdc++.h>

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<vector<int>> &result, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis)
{
    vis[node] = true;
    disc[node] = low[node] = timer++;
    
    for(auto nbr : adj[node]){
        if(nbr == parent)
            continue;
        else if(!vis[nbr]){
            dfs(nbr, node, timer, disc, low, result, adj, vis);
            low[node] = min(low[node], low[nbr]);
            // check if it a bridge or not
            if(low[nbr] > disc[node]){
                // vector<int> ans;
                // ans.push_back(node);
                // ans.push_back(nbr);
                // result.push_back(ans);
                result.push_back({node,nbr});
            }
        }
        // it is visited but it is not parent (i.e. Back edge)
        else{
            low[node] = min(low[node], disc[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
    // make adj list
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int timer = 0;
    vector<int> disc(v);
    vector<int> low(v);
    int parent = -1;
    unordered_map<int, bool> vis;
    
    for(int i = 0; i < v; i++){
        disc[i] = -1;
        low[i] = -1;
    }
    
    vector<vector<int>> result;
    // dfs
    for(int i = 0; i < v; i++){
        if(!vis[i]){
            dfs(i, parent, timer, disc, low, result, adj, vis);
        }
    }
    return result;
}
