// Key Pair - gfg

// Link - https://practice.geeksforgeeks.org/problems/key-pair5616/1

class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
	    unordered_map<int, int> map;
	    
	    for(int i = 0; i < n; i++){
	        map[arr[i]]++;
	    }
	   
        for(auto itr = map.begin(); itr != map.end(); itr++)
        {
            int key = itr->first;
            int val = itr->second;
            
            int pair = x - key;
            
            if(pair == key){
                if(val > 1)    // if same value is present more than 1 time then return true
                    return true;
            }
            else{
                // otherwise find the pair in map
                if(map.find(pair) != map.end()){   
                    return true;
                }
            }
        }
        return false;
	}
};
