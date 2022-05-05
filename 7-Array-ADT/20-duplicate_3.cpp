// Find Duplicate in unsorted array


#include<iostream>
using namespace std;

void findDuplicate(int arr[], int n){

    for (int i = 0; i < n-1; i++)
    {
        int count = 1;
        if(arr[i] != -1)
        {
        
            for (int j = i+1; j < n; j++)
            {
                if(arr[i] == arr[j])
                {
                    count++;
                    arr[j] = -1;
                }
            }
            if(count > 1)
            cout<<arr[i]<<" is printing "<<count<<" times"<<endl;
        }
    }
    
}


void hashDuplicate(int arr[], int n, int h){

    int Hash[9] = {0,0,0,0,0,0,0,0,0};

    for (int i = 0; i < n; i++)
    {
        Hash[arr[i]]++;
    }

    for (int j = 0; j <= h; j++)
    {
        if(Hash[j]>1)
        cout<<j<<" is printing "<<Hash[j]<<" times"<<endl;
    }
    
    
}


int main(){

    int nums[] = {8,3,6,4,6,5,6,8,2,7,2};

    // findDuplicate(nums, 11);

    hashDuplicate(nums, 11, 8);
    
    return 0;
}