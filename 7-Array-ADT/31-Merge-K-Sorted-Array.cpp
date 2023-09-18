// Problem statement

// Merge K Sorted Array - Codestudio

// Link - https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379

// Solved using Heap

#include<queue>
class node{
    public:
    int data;
    int i;
    int j;
    node(int data, int row, int col){
        this->data = data;
        i = row;
        j = col;
    }
};

class compare{
     public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here.
    priority_queue<node*, vector<node*>, compare> minHeap;
    
    // step 1: insert first elements of first k array
    for(int i = 0; i < k; i++){
        node* temp = new node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }
    
    vector<int> ans;
    
    // step 2
    while(minHeap.size() > 0){
        node* temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();
        int i = temp->i;
        int j = temp->j;
        
        if(j+1 < kArrays[i].size()){
            node* next = new node(kArrays[i][j+1], i, j+1);
            minHeap.push(next);
        }
    }
    return ans;
}
