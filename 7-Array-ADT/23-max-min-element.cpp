// unsorted + sorted
// no duplicate

#include<iostream>
using namespace std;

void maxMinElement(int arr[], int n){

    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if(arr[i] < min)
        min = arr[i];

        else if(arr[i] > max)
        max = arr[i];
    }
    cout<<"Minimum element is: "<<min<<endl;
    cout<<"Maximum element is: "<<max<<endl;
    
}

int main(){
    
    int nums[] = {5,8,3,9,6,2,10,7,-1,4};

    maxMinElement(nums, 10);

    return 0;
}