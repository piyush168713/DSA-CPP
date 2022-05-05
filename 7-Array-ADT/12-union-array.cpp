#include<iostream>
using namespace std;

void unionOfArrays(int arr1[], int arr2[], int n1, int n2){
    int i =0, j=0;

    while (i < n1 && j < n2){
        if (arr1[i] < arr2[j])
        cout<< arr1[i++] << " ";   // printing and increasing

        else if(arr2[j] < arr1[i])
        cout<< arr2[j++] << " ";   // printing and increasing

        else{
        cout<< arr2[j++] << " ";   // printing and increasing
        i++;     // increasing without printing
        }
    }

    // store remaining elements
    while (i < n1)
    cout<< arr1[i++] << " ";

    while (j < n2)
    cout<< arr2[j++] << " ";

}

int main(){

    int arr1[] = {1,3,5,7,9};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2,3,6,9};
    int n2 = sizeof(arr2) / sizeof(arr1[0]);

    unionOfArrays(arr1, arr2, n1, n2);

    
    return 0;
}