#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int key){

    int start = 0;
    int end = size-1;
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
    
    int even[6] = {2,4,6,8,10,12};
    int odd[5]= {7, 9, 11, 23, 45};

    int index1 = binarySearch(even, 6, 10);
    int index2 = binarySearch(odd, 5, 9);

    cout<<"Index of 10 is "<<index1;
    cout<<"\nIndex of 9 is  "<<index2;


    return 0;
}