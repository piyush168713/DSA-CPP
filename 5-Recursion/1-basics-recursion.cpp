// #include<iostream>
// using namespace std;

// void fun1(int x){
//     if (x>0){
//         // cout<<x;
//         fun1(x-1);
//         cout<<x;
//     }
// }

// int main(){

//     fun1(5);
    
//     return 0;
// }






// #include<iostream>
// using namespace std;

// int fun(int n){
//     if(n>0){
//         return fun(n-1) + n;
//     }
//     return 0;
// }

// int main(){
//     int r = fun(5);
//     cout<<r;
    
//     return 0;
// }


// static

#include<iostream>
using namespace std;


// int x=0;           // global variable
int fun(int n){
    static int x=0;       // static variable
    if(n>0){
        x++;
        return fun(n-1) + x;
    }
    return 0;
}

int main(){
    int r = fun(5);
    cout<<r;
    return 0;
}
