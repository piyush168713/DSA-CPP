// Duplicates in Sorted Array

#include<iostream>
using namespace std;

// CodeStudio (Find Duplicate in array)
int findFirstDuplicate(int arr[], int n){
    int key;
    for (int i = 0; i < n; i++)
    {
        key = arr[i];
        for (int j = i; j < n; j++)
        {
            if(key == arr[j+1])
            {
                return arr[j+1];
            }
        }
        
    }  
}



void findDuplicate(int arr[], int n){
    int lastDuplicate = -1;   
    
    
    for (int i = 0; i < n-1; i++)
    {
        if(arr[i] == arr[i+1] && arr[i] != lastDuplicate){
            cout<<"\nDuplicate Element is: "<<arr[i]<<endl;
            lastDuplicate = arr[i];
        }
    }
    
}


void findDuplicates(int arr[], int n){
    int j;
    
    for (int i = 0; i < n-1; i++)
    {
        if(arr[i] == arr[i+1])
        {
            j=i+1;
            while(arr[j] == arr[i])
            j++;
            cout<<"Element "<<arr[i]<<" is printing "<<j-i<<" times"<<endl;
            i=j-1;
        }
    }
}



int main(){

    int num[] = {3,6,8,8,10,12,15,15,15,20};
    int num1[] = {3,6,8,8,10};
    // cout<<"First Duplicate element is: "<<findFirstDuplicate(num, 10);

    findDuplicates(num, 10);

    return 0;
}

