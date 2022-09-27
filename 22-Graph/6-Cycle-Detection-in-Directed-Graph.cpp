// Problem Statement

// Detect Cycle In A Directed Graph - CodeStudio

// Link - https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626



// BFS - using kahn's Algo / using algo of topological sort

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges){
    // create adj List
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].first-1;
        int v = edges[i].second-1;
        
        adj[u].push_back(v);
    }
    
    // find all indegree
    vector<int> indegree(n);
    for(auto i : adj){
        for(auto j : i.second){
            indegree[j]++;
        }
    }
    
    // push the elements in the queue whose indegree is 0
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(indegree[i] == 0)
            q.push(i);
    }
    
    // do bfs
    int count = 0;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        // increament count
        count++;
        
        // neighbour indegree update
        for(auto neighbour : adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }
    
    // if it is valid topological sort(no of node = count)
    if(count == n)
        return false;
    // invalid topological sort (cycle is present in Directed Graph)
    else
        return true;
}
