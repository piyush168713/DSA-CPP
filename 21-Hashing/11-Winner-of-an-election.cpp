// Winner of an Election - gfg

// Libk - https://practice.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1

vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        unordered_map<string, int> map;
        for(int i = 0; i < n; i++)
        {
            map[arr[i]]++;
        }
        
        string name = "";
        int max_vote = 0;
        
        for(auto itr = map.begin(); itr != map.end(); itr++){
            string key = itr->first;
            int val = itr->second;
            
            // updation of pair
            if(val > max_vote){
                name = key;
                max_vote = val;
            }
            
            // search for less string size if vote is same
            else if(val == max_vote){
                if(key < name){
                    name = key;
                }
            }
        }
        
        vector<string> ans;
        
        ans.push_back(name);
        string temp = to_string(max_vote);   // int to string
        ans.push_back(temp);
        return ans;
    }
