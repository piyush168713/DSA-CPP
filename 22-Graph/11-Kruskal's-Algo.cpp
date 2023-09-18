// Problem Statement

// Minimum Spanning Tree - CodeStudio

// Link - https://www.codingninjas.com/codestudio/problems/minimum-spanning-tree_631769


#include<bits/stdc++.h>

bool cmp(vector<int>&a, vector<int>&b){
   return a[2]<b[2];
}

void makePair(vector<int> &parent, vector<int> &rank, int n)
{
    for(int i = 0; i < n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node)
{
    if(parent[node] == node){
        return node;
    }
    // path compression
    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(parent, u);
    v = findParent(parent, v);
    
    if(rank[u] < rank[v]){
        parent[u] = v;
    }
    else if(rank[v] < rank[u]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}


int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    sort(edges.begin(),edges.end(),cmp);
    vector<int> parent(n);
    vector<int> rank(n);
    makePair(parent, rank, n);
    int minWeight=0;
    for(int i=0;i<edges.size();i++)
    {
        int u=findParent(parent,edges[i][0]);
        int v=findParent(parent,edges[i][1]);
        int wt=edges[i][2];
        if(u!=v) //same hoti toh ignore krte h
        {
            minWeight+= wt;
            unionSet(u,v,parent,rank);
        }
    }
    return minWeight;
}
