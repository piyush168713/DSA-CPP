#include<iostream>
using namespace std;

int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    
    int count = 0;
    for (int i = start+1; i <= end; i++)
    {
        if(arr[i] <= pivot)
        count++;
    }
    
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;    
}

void quickSort(int A[], int start, int end)
{
    // base case
    if (start >= end)
        return;

    if(start < end){
        // do partititon
        int j = partition(A, start, end);

        // recursive call for left side
        quickSort(A, start, j-1);
        
        // recursive call for right side
        quickSort(A, j+1, end);
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

    int A[] = {11,13,7,12,16,9,24,5,10,3};
    int n = 10;

    quickSort(A, 0, n-1);
    cout<<"Sorting using Quick sort: ";
    display(A, n);
    
    return 0;
}
