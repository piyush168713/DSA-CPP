#include<unordered_map>

void solve(int arr[], int s, int e, int x, int &ans){
    if(s > e)
        return;
    int mid = s + (e-s)/2;
    if(arr[mid] == x){
        ans++;
    }
    solve(arr, mid+1, e, x, ans);
    solve(arr, s, mid, x, ans);
    return;
}

int countOccurences(int arr[], int n, int X)
{
	//Write your code here    
    int ans = 0;
    solve(arr, 0, n-1, X, ans);
    return ans;
}
