// Find a pair with sum k (a+b=k)
// unsorted
// no duplicates

#include<iostream>
using namespace std;

void pairSum(int arr[], int n, int k){  

    // n = no. of elements
    // k = total sum (10)

    int key=0;

    for (int i = 0; i < n; i++)
    {
        key = arr[i];

        for (int j = i+1; j < n; j++)
        {
            if ((key + arr[j]) == k)
            {
                cout<<"a: "<<key<<" b: "<<arr[j]<<" Sum is: "<<k<<endl;
            }
        }
        
    }
}

void hashPairSum(int arr[], int n, int k){

    int Hash[17] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    for (int i = 0; i < n; i++)
    {
        if( Hash[k-arr[i]] != 0)
        {
            cout<<"a: "<<arr[i]<<" b: "<<k-arr[i]<<" sum: "<<k<<endl;
        }
        Hash[arr[i]]++;
    }
}


int main(){
    
    int nums[] = {6,3,8,10,16,7,5,2,9,14};

    // pairSum(nums, 10, 10);

    hashPairSum(nums, 10, 10);


    return 0;
}