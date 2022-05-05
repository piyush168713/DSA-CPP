// Find a pair with sum k (a+b=k)
// Sorted
// no duplicates

#include<iostream>
using namespace std;

void pairSum(int arr[], int n, int k){
    int i=0;
    int j=n-1;

    while(i<j){
        if (arr[i] + arr[j] == k){
            cout<<"a: "<<arr[i]<<" b: "<<arr[j]<<" Sum is: "<<k<<endl;
            i++;
            j--;
        }

        else if(arr[i] + arr[j] < k){
            i++;
        }
        else
        j--;
    }
    
}

int main(){
    
    int nums[] = {1,3,4,5,6,8,9,10,12,14};

    pairSum(nums, 10, 10);

    return 0;
}