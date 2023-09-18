// Pairs with Positive Negative values - gfg

// Link - https://practice.geeksforgeeks.org/problems/pairs-with-positive-negative-values3719/1

vector<int> PosNegPair(int a[], int n) {
        
        vector<int> v, ans;
        map<int, int> m;
        
        for(int i = 0; i < n; i++){
            if(a[i] < 0)
                v.push_back(a[i]);
            else
                m[a[i]]++;
        }
        
        sort(v.begin(), v.end());
        
        for(int i = (int)v.size()-1; i >= 0; i--){
            int data = abs(v[i]);
            
            if(m[data] > 0){     // if(data of v present(count > 0) in map)
                ans.push_back(v[i]);   // -ve
                ans.push_back(data);   // +ve
                m[data] -= 1;
            }
        }
        return ans;
    }
