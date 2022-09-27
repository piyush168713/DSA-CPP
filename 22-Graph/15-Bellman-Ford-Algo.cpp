// Problem Statement

// Bellman Ford - CodeStudio

// Link - https://www.codingninjas.com/codestudio/problems/bellmon-ford_2041977

/*
  Bellman Ford Algo is used to find:
    - -ve cycle in the graph
    - Shortest path of -ve & +ve weight but the Graph doesn't contain -ve cycle
    - Dijkstra's Algo is not able to find the shortest path of -ve weight.
*/

#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> dist(n+1, 1e9);
    dist[src] = 0;
    
    // n-1 times
    for(int i = 1; i <= n; i++){
        // traverse on edge list
        for(int j = 0; j < m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            
            if(dist[u] != 1e9 && ((dist[u] + wt) < dist[v])){
                dist[v] = dist[u] + wt;
            }
        }
    }
    return dist[dest];
    
    // check for negative cycle
    /*
    bool flag = 0;
    for(int j = 0; j < m; j++){
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];
            
        if(dist[u] != 1e9 && ((dist[u] + wt) < dist[v])){
            flag = 1;
        }
    }
    if(flag == 0){
        return dist[dest];
    }
    else{
        return -1;
    }
    */
}
