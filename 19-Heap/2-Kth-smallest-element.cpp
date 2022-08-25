// Problem Statement

// Kth smallest element - CodeStudio

// Link - https://www.codingninjas.com/codestudio/problems/kth-smallest-element_893056

#include<queue>
int kthSmallest(vector<int> input, int k)
{
    int n = input.size()-1;
    
    priority_queue<int> pq;
    
    // step 1
    for(int i = 0; i < k; i++){
        pq.push(input[i]);
    }
    
    // step 2
    for(int i = k; i <= n; i++){
        if(input[i] < pq.top()){
            pq.pop();
            pq.push(input[i]);
        }
    }
                
    int ans = pq.top();
    return ans;
}
