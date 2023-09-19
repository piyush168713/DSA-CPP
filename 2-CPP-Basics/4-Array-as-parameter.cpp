// #include<bits/stdc++.h>

// // void fun(int A[], int n){         
// void fun(int *A, int n){         
//     int i;
//     for (i = 0; i < n; i++)
//     {
//         std::cout<<A[i]<<" ";
//     }
    
// }

// int main(){

//     int B[] = {2,3,4,5};
//     fun(B,4);
    
//     return 0;
// } 




#include<bits/stdc++.h>

// void fun(int A[], int n){         
int * fun(int size){       // returns pointer

    int *p;
    p = new int[size];            // array is created in heap

    for(int i=0;i=5;i++)
    p[i] + i+1;

    return p;
    
}

int main(){

    int *ptr, sz=7;

    ptr = fun(sz);     // calling fun() it will return the address that i will taken in ptr

    for (int i = 0; i < sz; i++)
    std::cout<<ptr[i]<<"\n";
    
    return 0;
} 