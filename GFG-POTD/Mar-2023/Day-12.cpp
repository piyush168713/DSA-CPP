// Binary matrix having maximum number of 1s

// Link - https://practice.geeksforgeeks.org/problems/77e1c3e12cd148f835d53eb168d4472b2ff539fa/1

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        //code here
        int i = 0, j = N-1;
        int cnt = 0, pos = 0;
        while(i < N && j >= 0){
            if(mat[i][j] == 1){
                cnt++;
                --j;
                pos = i;
            }
            else
                ++i;
        }
        return {pos, cnt};
    }
};
