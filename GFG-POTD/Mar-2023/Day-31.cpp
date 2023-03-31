// Even Swap

// Link - https://practice.geeksforgeeks.org/problems/even-swap/1

class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
            // Code here
            int i = 0; 
            while(i < n){
                int j = i+1;
                while(j < n && a[j]%2 == a[j-1]%2){
                    j++;
                }
                sort(a.begin()+i, a.begin()+j, greater<int>());
                i = j;
            }
            return a;
        }
};
