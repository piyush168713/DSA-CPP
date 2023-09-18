// Make the array beautiful

// Link - https://practice.geeksforgeeks.org/problems/badefd58bace4f2ca25267ccfe0c9dc844415e90/1

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        vector<int> ans;
        if(arr.size() == 0)
            return ans;
            
        stack<int> st;
        
        /*
        for(int i = 0; i < arr.size(); i++){
            if(st.size() == 0)
                st.push(arr[i]);
            else if((st.top() < 0 && arr[i] >= 0) || (st.top() >= 0 && arr[i] < 0)){
                st.pop();
            }
            else
                st.push(arr[i]);
        }
        */
      
        for(auto x : arr){
            if(st.empty())
                st.push(x);
            else if((st.top() < 0 ^ x < 0))
                st.pop();
            else
                st.push(x);
        }
      
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
