// Subarray-with-sum-0 - gfg

// Link - https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1

bool subArrayExists(int arr[], int n)
    {
        //Your code here
        unordered_set<int> s;
        
        int pref_sum = 0;
        
        for(int i = 0; i < n; i++){
            pref_sum += arr[i];
            
            if(pref_sum == 0)
                return true;
                
            if(s.find(pref_sum) != s.end())
                return true;
            
            s.insert(pref_sum);
        }
        return false;
    }
