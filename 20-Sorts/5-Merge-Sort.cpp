// codehelp

#include<iostream>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = (s + (e-s)/2);
    int len1 = mid-s+1;
    int len2 = e-mid;

    // dynamic memory allocation
    int *first = new int[len1];
    int *second = new int[len2];

    // copy values
    int mainArrayIndex = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }

    // merge 2 sorted arrays
    int a = 0, b = 0;
    mainArrayIndex = s;
    while(a < len1 && b < len2)
    {
        if(first[a] < second[b]){
            arr[mainArrayIndex++] = first[a++];
        }
        else{
            arr[mainArrayIndex++] = second[b++];
        }
    }
    
    while(a < len1){
        arr[mainArrayIndex++] = first[a++];
    }

    while(b < len2){
        arr[mainArrayIndex++] = second[b++];
    }

    // delete the memory which is dynamically allocated
    delete[] first;
    delete[] second;
    
}

void mergeSort(int *arr, int s, int e)
{
    // base case
    if(s >= e)
    return;

    int mid = (s + (e-s)/2);

    // sort left part
    mergeSort(arr, 0, mid);

    // sort right part
    mergeSort(arr, mid+1, e);

    // merge
    merge(arr, s, e);
}


void display(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

    // int arr[5] = {2,5,1,6,9};
    int arr[15] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    int n = 15;

    cout<<"Sorting using Merge Sort: ";
    mergeSort(arr, 0, n-1);

    display(arr, n);
    
    return 0;
}
