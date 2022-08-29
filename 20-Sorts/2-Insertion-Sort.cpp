#include<iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    int i, j, x;
    for (int i = 1; i < n; i++)
    {
        j = i-1;
        x = arr[i];
        while(j > -1 && arr[j] > x){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = x;
    }
}


void display(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

    int A[] = {3,7,9,10,6,5,12,4,11,2};
    int n = 10;

    insertionSort(A, n);
    cout<<"Sorting using Insertion sort: ";
    display(A, n);
    
    return 0;
}
