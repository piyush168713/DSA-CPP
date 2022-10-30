// Maximum of subarrays of size k

// link - https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        // Deque using Sliding Window
        // T.C - O(n), S.C - O(k)
        
        vector<int> ans;
        int i = 0, j = 0;
        deque<int> q;
        
        while(j < n){
            
            // check for back element
            while(q.size() > 0 && q.back() < arr[j])
                q.pop_back();
            
            // push new element
            q.push_back(arr[j]);
            
            // check size
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
                ans.push_back(q.front());
                
                // remove front element for next window
                if(q.front() == arr[i])
                    q.pop_front();
                    
                i++;
                j++;
            }
        }
        return ans;
    }
};
