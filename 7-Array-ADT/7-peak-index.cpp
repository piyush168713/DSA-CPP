#include<iostream>
using namespace std;

int peakIndex(int arr[], int n){
    int s=0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<e){

        if(arr[mid] < arr[mid+1])
        s=mid+1;
        else{
            e=mid;
        }
        mid = s + (e-s)/2;
    }
        return e;      // here s, e are become same at last step
}

int main(){

    int even[4] = {3,4,5,1};
    // int even[4] = {3,5,4,1};
    cout<<"Peak Index in a mountain Array is: "<<peakIndex(even,4);
    
    return 0;
}