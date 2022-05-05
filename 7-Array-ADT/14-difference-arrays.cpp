#include<iostream>
using namespace std;

void differenceArrays(int arr1[], int arr2[], int n1, int n2){
    int i =0, j=0;

    while (i < n1 && j < n2){

        if (arr1[i] < arr2[j])
        cout<<arr1[i++]<< " ";

        else if(arr2[j] < arr1[i])
        j++;         // not print the element of 2nd array

        else{        // if the elements are matching, don't print (A-B), Only increament
            i++;
            j++;
        }
    }

    // store remaining elements
    while (i < n1)
    cout<<arr1[i++];   

    while (j < n2)
    j++;    // not print the element of 2nd array

}

int main(){

    int arr1[] = {1,3,5,7,9};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2,3,6,7,10};
    int n2 = sizeof(arr2) / sizeof(arr1[0]);


    differenceArrays(arr1, arr2, n1, n2);
    
    return 0;
}