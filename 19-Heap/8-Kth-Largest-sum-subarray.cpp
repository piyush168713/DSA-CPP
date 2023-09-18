// K-th Largest Sum Subarray - CodeStudio

// Link - https://www.codingninjas.com/codestudio/problems/k-th-largest-sum-contiguous-subarray_920398

#include<algorithm>
#include<queue>
int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
    /*
    // T.C - O(n^2logn)
    // S.C - O(n^2)
    vector<int> sumStore;
    int n = arr.size();
    
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += arr[j];
            sumStore.push_back(sum);
        }
    }
    
    // sort the array
    sort(sumStore.begin(), sumStore.end());
    
    return sumStore[sumStore.size() - k];
    */
    
    
    // S.C - O(K)
    int n = arr.size();
    // creating min heap using priority queue
    priority_queue<int, vector<int>, greater<int>> mini;
    
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += arr[j];
            
            if(mini.size() < k)
            {
                mini.push(sum);
            }
            else
            {
                if(sum > mini.top())
                {
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }
    return mini.top();
}
