#include<iostream>
using namespace std;

// T.C - O(n^2)
void bubbleSort(int arr[], int n)
{
    int flag;

    for (int i = 0; i < n-1; i++)
    {
        flag = 0;
        for (int j = 0; j < n-1-i; j++)
        {
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                flag = 1;
            }
        }
        if(flag == 0)
            break;
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

    bubbleSort(A, n);
    cout<<"Sorting using Bubble sort: ";
    display(A, n);

    return 0;
}
