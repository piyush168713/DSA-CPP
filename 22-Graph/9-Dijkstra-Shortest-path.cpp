// Problem Statement

// Dijkstra's shortest path - CodeStudio

// Link - https://www.codingninjas.com/codestudio/problems/dijkstra-s-shortest-path_920469

#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // make adj list
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i = 0; i < edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];     // weight
        
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    
    // make distance vector and initialize with infinity
    vector<int> dist(vertices);
    for(int i = 0; i < vertices; i++)
        dist[i] = INT_MAX;
    
    set<pair<int, int>> st;
    // initialize distance and set with source node
    dist[source] = 0;
    st.insert(make_pair(0, source));    // (dist, node) pair
    
    while(!st.empty()){
        // fetch top record or take node whose distance is minimum &
        // make that node - topNode and pop/remove from set
        auto top = *(st.begin());
        
        int nodeDistance = top.first;
        int topNode = top.second;
        
        // erase record from set
        st.erase(st.begin());
        
        // traverse on neighbour
        for(auto neighbour : adj[topNode]){
            if(nodeDistance + neighbour.second < dist[neighbour.first])
            {
                // find record from set...if present then erase nd update and 
                // if not present then insert record in set
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                // if record found then erase it
                if(record != st.end()){
                    st.erase(record);
                }
                
                // distance vector update
                dist[neighbour.first] = nodeDistance + neighbour.second;
                // record insert in set
                st.insert(make_pair(dist[neighbour.first], neighbour.first));    // (dist, node)
            }
        }
    }
    return dist;
}
