// Distinct Difference

// Link - https://practice.geeksforgeeks.org/problems/c670bf260ea9dce6c5910dedc165aa403f6e951d/1

class Solution {
  public:
    vector<int> getDistinctDifference(int n, vector<int> &arr) {
        // code here
        unordered_set<int> st;
        
        vector<int> left(n,0);
        vector<int> right(n,0);
        
        for(int i = 0; i < n; i++){
            left[i] = st.size();
            st.insert(arr[i]);
        }
        
        st.clear();
        
        for(int i = n-1; i >= 0; i--){
            right[i] = st.size();
            st.insert(arr[i]);
        }
        
        vector<int> ans;
        
        for(int i = 0; i < n; i++){
            ans.push_back(left[i] - right[i]);
        }
        return ans;
    }
};
