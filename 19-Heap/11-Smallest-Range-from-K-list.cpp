// Problem Statement

// Smallest Range From K Sorted list - CodeStudio

// Link - https://www.codingninjas.com/codestudio/problems/smallest-range-from-k-sorted-list_1069356

#include<limits.h>
#include<queue>

class node{
  public:
    int data;
    int row;
    int col;
    
    node(int d, int r, int c){
        data = d;
        row = r;
        col = c;
    }
};

class compare{
  public:
    bool operator()(node* a, node *b){
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    // Write your code here.
    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue<node*, vector<node*>, compare> minHeap;
    
    // push first k elements of each array in minHeap
    for(int i = 0; i < k; i++){
        int element = a[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new node(element, i, 0));
    }
    
    int start = mini, end = maxi;
    
    while(!minHeap.empty()){
        node* temp = minHeap.top();    // stored min element
        minHeap.pop();
        
        mini = temp->data;
        
        // update start and end if range difference is less
        if(maxi-mini < end-start){   
            start = mini;
            end = maxi;
        }
        // check if next element exists and update the max value and push to heap
        if(temp->col + 1 < n){
            maxi = max(maxi, a[temp->row][temp->col + 1]);
            minHeap.push(new node(a[temp->row][temp->col + 1], temp->row, temp->col + 1));
        }
        else{
            // next element does not exists
            break;
        }
    }
    // returning the difference of range
    return (end - start + 1);
}
