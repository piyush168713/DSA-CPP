#include<iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    int i, j, k;

    for (i = 0; i < n-1; i++)
    {
        for (j = k = i; j < n; j++)
        {
            if(arr[j] < arr[k])
            k = j;
        }
        swap(arr[i], arr[k]);
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

    int A[] = {3,7,9,10,6,5,12,4,24,2};
    int n = 10;

    selectionSort(A, n);
    cout<<"Sorting using Selection sort: ";
    display(A, n);
    
    return 0;
}
