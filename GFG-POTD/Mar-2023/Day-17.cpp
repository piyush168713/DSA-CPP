// Number of Subarrays of 0's

// Link - https://practice.geeksforgeeks.org/problems/0960a833f70b09c59444ea487f99729929fc8910/1

long long int no_of_subarrays(int n, vector<int> &arr) {
    // Write your code here.
    long long int ans = 0;
    long long sum = 0;
    
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == 1){
            sum = 0;
        }
        else{
            sum += 1;
        }
        ans += sum;
    }
    return ans;
}
