// Problem Statement

// BFS in Graph - CodeStudio

// Link - https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002?leftPanelTab=0

#include<unordered_map>
#include<queue>
#include<list>
#include<set>

void prepareAdjList(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> &edges)
{
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    
    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);
        
        for(auto i : adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // using set coz it gives in sorted order
    unordered_map<int, set<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;
    
    prepareAdjList(adjList, edges);
    
    for(int i = 0; i < vertex; i++){
        if(!visited[i]){
            bfs(adjList, visited, ans, i);
        }
    }
    return ans;
}
