// Problem Statement

// First Missing Positive - CodeStudio

// Link - https://www.codingninjas.com/codestudio/problems/first-missing-positive_699946

#include<unordered_map>
int firstMissing(int arr[], int n)
{
    // Write your code here.
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(m.count(i)==0){
            return i;
        }
    }
    return n+1;
}
