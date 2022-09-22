// Problem Statement

// Detect Cycle In A Directed Graph - CodeStudio

// Link - https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626

#include<unordered_map>
#include<queue>
#include<list>


// DFS
bool cycleCheckDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    dfsVisited[node] = true;
    
    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            bool cycleDetected = cycleCheckDFS(neighbour, visited, dfsVisited, adj);
            if(cycleDetected)
                return true;
        }
        else if(dfsVisited[neighbour]){
            return true;            
        }
    }
    dfsVisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // make adj list
    unordered_map<int, list<int>> adj;
    
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].push_back(v);
    }
    
    // call dfs for all components
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            bool cycleFound = cycleCheckDFS(i, visited, dfsVisited, adj);
            if(cycleFound)
                return true;
        }
    }
    return false;
}
