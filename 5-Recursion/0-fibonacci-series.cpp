// 1. Using Recursion
#include<bits/stdc++.h>
using namespace std;

// recursion
int fib(int n){
    if (n <= 1)
        return n;
    else
        return fib(n-2) + fib(n-1);
}

// memoization
// T.C - 0(n)
// S.C - o(n) + o(n)
int fib2(int n, vector<int> &dp){
    if(n <= 1)
        return n;
    
    if(dp[n] != -1)
        return dp[n];

    return dp[n] = fib2(n-1, dp) + fib2(n-2, dp);
}

// tabulation
// T.C - 0(n)
// S.C - o(n)
int fib3(int n, vector<int> &dp){
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// tabulation + space optimization
// T.C - O(n)
// S.C - O(1)
void fib1(int n){
    int n1 = 0, n2 = 1, n3;
    cout<<n1<<" "<<n2<< " ";

    for(int i = 2; i < n; i++){
        n3 = n1 + n2;
        cout<<n3<<" ";
        n1 = n2;
        n2 = n3;
    }
}

int main(){
    
    int n;
    cout<<"Enter the no. of terms for the series: ";
    cin>>n;

    cout<<"\nFibonacci Series: ";
    // for(int i = 0; i < x; i++){
    //     cout<<fib(i)<<" ";
    // }

    // fib1(n);

    vector<int> dp(n+1, -1);
    // cout<<fib2(n, dp);
    for(int i = 0; i < n; i++){
        // cout<<fib2(i, dp)<<" ";
        cout<<fib3(i, dp)<<" ";
    }


    cout<<endl;
    
    return 0;
}