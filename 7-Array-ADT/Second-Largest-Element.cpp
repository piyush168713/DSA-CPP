#include <bits/stdc++.h> 
int findSecondLargest(int n, vector<int> &arr)
{
    // Write your code here.
    int firstLar =INT_MIN;
    int secondLar = INT_MIN;
    
    for(int i = 0; i < n; i++){
        if(arr[i] > firstLar){
            secondLar = firstLar;
            firstLar = arr[i];
        }
        else if(arr[i] >= secondLar && arr[i] != firstLar){
            secondLar = arr[i];
        }
    }
    
    if(secondLar == INT_MIN){
        return -1;
    }
    else{
        return secondLar;
    }
}
