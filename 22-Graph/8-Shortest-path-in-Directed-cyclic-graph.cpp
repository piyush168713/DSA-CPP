// Shortest Path in Directed Cyclic Graph

#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int weight)
    {
        pair<int, int> p = make_pair(v,weight);
        adj[u].push_back(p);
    }

    // print adj list
    void printAdj()
    {
        for(auto i : adj){
            cout<<i.first<<" -> ";
            for(auto j : i.second){
                cout<<"("<<j.first<<","<<j.second<<")";
            }
            cout<<endl;
        }
    }

    // Topological sort
    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &s)
    {
        visited[node] = 1;
        for(auto nbr : adj[node]){
            if(!visited[nbr.first]){
                dfs(nbr.first, visited, s);
            }
        }
        s.push(node);
    }

    // make distance vector in which distance from src will be stored
    void getShortestPath(int src, vector<int> &dist, stack<int> &st)
    {
        dist[src] = 0;
        while(!st.empty()){
            int top = st.top();
            st.pop();

            if(dist[top] != INT_MAX){
                for(auto i : adj[top]){
                    if(dist[top] + i.second < dist[i.first]){
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }
    }


};


int main(){

    Graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    g.printAdj();
    int n = 6;

    // topological sort
    unordered_map<int, bool> visited;
    stack<int> s;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            g.dfs(i, visited, s);
        }
    }

    int src = 1;
    vector<int> dist(n);

    for(int i = 0; i < n; i++){
        dist[i] = INT_MAX;
    }

    g.getShortestPath(src, dist, s);

    cout<<"\nAnswer is: "<<endl;

    for(int i = 0; i < dist.size(); i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
