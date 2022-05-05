#include<iostream>
using namespace std;

int pivotIndex(int arr[], int n){

    int s=0;
    int e=n-1;
    int mid = s + (e-s)/2;

    while(s<e){

        if(arr[mid] >= arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int binarySearch(int arr[], int s, int e, int key){

    int start = s;
    int end = e;
    int mid = (start + ((end-start)/2));

    while(start <= end){

        if(arr[mid] == key){
            return mid;
        }

        if(arr[mid] > key){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
        
        mid = (start + ((end-start)/2));

    }
    return -1;
}

int main(){

    // int nums[6] = {1,7,3,6,5,6};
    // int odd[3] = {2,1,-1};
    // int num[5] = {3,8,10,17,1};

    // cout<<"Pivot Index is: "<<pivotIndex(nums,6);
    // cout<<"\nPivot Index is: "<<pivotIndex(odd,3);
    // cout<<"\nPivot Index is: "<<pivotIndex(num,3);


    int pivot = pivotIndex(arr, n);

    if(key >= arr[pivot] && key <= arr[n-1])
    {
        return binarySearch(arr, pivot, n-1, key);    // binary search on II line
    }
    else if{
        return binarySearch(arr, 0, pivot-1, key);    // binary search on I line
    }
    
    return 0;
}