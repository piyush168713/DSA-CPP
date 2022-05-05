#include<iostream>
using namespace std;

void intersectionMergeArrays(int arr1[], int arr2[], int n1, int n2){
    int i =0, j=0;

    while (i < n1 && j < n2){
        if (arr1[i] < arr2[j])
        i++;                       // increasing without printing

        else if(arr2[j] < arr1[i])
        j++;                       // increasing without printing

        else{
        cout<< arr2[j++] << " ";   // printing and increasing
        i++;                       // increasing without printing
        }
    }

}

int main(){

    int arr1[] = {1,3,5,7,10, 12};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2,3,5,8, 10, 11, 12};
    int n2 = sizeof(arr2) / sizeof(arr1[0]);


    intersectionMergeArrays(arr1, arr2, n1, n2);

    
    return 0;
}