// Binary Search Qn
// First & Last Position(Occurrence) of an element in sorted array

#include<iostream>
using namespace std;

int firstOcc(int arr[], int n, int key)
{
    int s = 0, e = n-1;
    int mid = (s + ((e-s)/2));
    int ans = -1;

    while(s<=e){

        if(arr[mid] == key){
            ans = mid;
            e = mid-1;
        }

        else if(arr[mid] < key){
            s = mid+1;
        }

        else if(arr[mid] > key){
            e=mid-1;
        }

        mid = (s + ((e-s)/2));

    }
    return ans;
}

int lastOcc(int arr[], int n, int key)
{
    int s = 0, e = n-1;
    int mid = (s + ((e-s)/2));
    int ans = -1;

    while(s<=e){

        if(arr[mid] == key){
            ans = mid;
            s=mid+1;
        }

        else if(key > arr[mid]){
            s = mid+1;
        }

        else if(key < arr[mid]){
            e=mid-1;
        }
        mid = (s + ((e-s)/2));

    }
    return ans;
}

int main(){

    int odd[11] = {1,2,3,3,3,3,3,3,3,3,5};

    cout<<"First Occurrence of 3 is at Index: "<<firstOcc(odd, 11, 3)<<endl;
    cout<<"Last Occurrence of 3 is at Index: "<<lastOcc(odd, 11, 3)<<endl;
    cout<<"Total no. of Occurrence: "<< lastOcc(odd, 11, 3) -firstOcc(odd, 11, 3) +1;
    
    return 0;
}