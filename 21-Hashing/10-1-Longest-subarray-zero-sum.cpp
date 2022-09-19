// Longest Subarray Zero Sum - codestudio/gfg

// Link - 
// codestudio - https://www.codingninjas.com/codestudio/problems/longest-subset-zero-sum_920321
// gfg - 

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
    unordered_map<int, int> s;
    int pref_sum = 0;
    int maxi = 0;

    for(int i = 0; i < arr.size(); i++)
    {
        pref_sum += arr[i];
        
        if(pref_sum == 0){
            maxi = i+1;
        }
        else{
            if(s.find(pref_sum) != s.end()){
                maxi = max(maxi, i-s[pref_sum]);
            }else{
                s[pref_sum] = i;
            }
        }
    }
    return maxi;
}
