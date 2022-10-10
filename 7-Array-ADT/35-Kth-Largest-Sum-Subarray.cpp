#include<algorithm>
#include<queue>
int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.    
    // S.C - O(K)
    int n = arr.size();
    // creating min heap using priority queue (Min Heap)
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
