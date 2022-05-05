#include<iostream>
// #include<bits/stdc++.h>
using namespace std;

class Array{
    public:
    int A[10];
    int size;
    int length;
};



int LinearSearch(Array arr, int key){
    for (int i = 0; i < arr.length; i++)
    {
        if(key == arr.A[i])
        return i;
                   
    }
    return -1;
    
}

void Display(Array arr){
    cout<<"Elements are: ";
    for (int i = 0; i < arr.length; i++)
    {
        cout<<arr.A[i]<<" ";
    }
}



int main(){

    Array arr = {{8,9,4,7,6,3,10,5,14,2}, 10, 10};

    cout<<endl<<LinearSearch(arr,5)<<endl;

    Display(arr);
    
    
    return 0;
}