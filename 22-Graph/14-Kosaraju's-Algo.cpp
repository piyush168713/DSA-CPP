// Problem Statement

// Count Strongly Connected Components (Kosaraju’s Algorithm) - CodeStudio

// Link - https://www.codingninjas.com/codestudio/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151

/*
  Kosaraju's Algo (Strongly Connected component):-
    A directed graph is said to be strongly connected if every
    vertex is reachable from every other vertex.
*/

#include<bits/stdc++.h>

void topo(int node, unordered_map<int, bool> &vis, stack<int> &st, unordered_map<int, list<int>> &adj)
{
    vis[node] = true;
    
    for(auto nbr : adj[node]){
        if(!vis[nbr]){
            topo(nbr, vis, st, adj);
        }
    }
    st.push(node);
}

void dfs(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &transpose)
{
    vis[node] = true;
    
    for(auto nbr : transpose[node]){
        if(!vis[nbr]){
            dfs(nbr, vis, transpose);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// make adj list
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
    }
    
    // step 1: topo sort
    stack<int> st;
    unordered_map<int, bool> vis;
    for(int i = 0; i < v; i++){
        if(!vis[i]){
            topo(i, vis, st, adj);
        }
    }
    
    // step 2: Transpose
    unordered_map<int, list<int>> transpose;
    for(int i = 0; i < v; i++){
        vis[i] = 0;
        for(auto nbr: adj[i]){
            transpose[nbr].push_back(i);
        }
    }
    
    // step 3: dfs call suing above ordering
    int count = 0;
    while(!st.empty()){
        int top = st.top();
        st.pop();
        if(!vis[top]){
            count++;
            dfs(top, vis, transpose);
        }
    }
    return count;
}
