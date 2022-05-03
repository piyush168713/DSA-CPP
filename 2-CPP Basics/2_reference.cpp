#include<bits/stdc++.h>

int main(){
    
    int a=10;
    int &r = a;         // r is reference to a      // reference is constant pointer
   
    int b=30;
    r=b;           // here r isn't reference to b      // it means value 30(b) is stored in r

    std::cout<<a<<" "<<r;

    return 0;
}