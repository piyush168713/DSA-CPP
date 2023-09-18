// Problem Statement

// Minimum Cost of Ropes - GFG

// Link - https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        
        // creating min heap using priority queue
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        // push the elements in priority queue
        for(int i = 0; i < n; i++){
            pq.push(arr[i]);
        }
        
        long long cost = 0;
        
        while(pq.size() > 1){
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            long long sum = a+b;
            cost += sum;
            pq.push(sum);
        }
        return cost;
    }
};
