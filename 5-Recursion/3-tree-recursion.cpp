#include<iostream>
using namespace std;

void fun(int n){
    if (n>0){
        cout<<n;
        fun(n-1);
        fun(n-1);
    }
}

int main(){

    fun(3);        // breakpoint
    return 0;
}


// you can debug and check