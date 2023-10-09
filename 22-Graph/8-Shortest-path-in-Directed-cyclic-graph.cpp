// Shortest Path in Directed Cyclic Weighted Graph

#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
    unordered_map<int, list<pair<int, int>>> adj;

    // make adj list
    void addEdge(int u, int v, int wt)
    {
        adj[u].push_back({v,wt});
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
    void topoSort(int node, unordered_map<int, bool> &visited, stack<int> &st)
    {
        visited[node] = 1;
        for(auto it : adj[node]){
            if(!visited[it.first]){
                topoSort(it.first, visited, st);
            }
        }
        st.push(node);
    }

    // make distance vector in which distance from src will be stored
    void getShortestPath(int src, vector<int> &dist, stack<int> &st)
    {
        dist[src] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();

            if(dist[node] != INT_MAX){
                for(auto i : adj[node]){
                    int v = i.first;
                    int wt = i.second;
                    if(dist[node] + wt < dist[v]){
                        dist[v] = dist[node] + wt;
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
    stack<int> st;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            g.topoSort(i, visited, st);
        }
    }

    int src = 0;
    vector<int> dist(n);

    for(int i = 0; i < n; i++){
        dist[i] = INT_MAX;
    }

    g.getShortestPath(src, dist, st);

    cout<<"\nAnswer is: "<<endl;

    for(int i = 0; i < dist.size(); i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
