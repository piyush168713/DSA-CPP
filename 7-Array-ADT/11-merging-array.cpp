#include<iostream>
using namespace std;

void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[] ){
    int i =0, j=0, k=0;

    while (i < n1 && j < n2){
        if (arr1[i] < arr2[j])
        arr3[k++] = arr1[i++];

        else
        arr3[k++] = arr2[j++];
    }

    // store remaining elements
    while (i < n1)
    arr3[k++] = arr1[i++];

    while (j < n2)
    arr3[k++] = arr2[j++];

}


// merging arrays without creating a new array
void mergeArrays_1(int arr1[], int arr2[], int n1, int n2 ){
    int i =0, j=0;

    while (i < n1 && j < n2){
        if (arr1[i] < arr2[j])
        cout<<arr1[i++]<< " ";

        else
        cout<<arr2[j++]<<" ";
    }

    // store remaining elements
    while (i < n1)
    cout<<arr1[i++]<<" ";

    while (j < n2)
    cout<<arr2[j++]<< " ";

}

int main(){
    
    int arr1[] = {1,3,5,7,9};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2,3,6,7,10};
    int n2 = sizeof(arr2) / sizeof(arr1[0]);

    int arr3[n1+n2];

    // mergeArrays(arr1, arr2, n1, n2, arr3);
    // cout<<"Array after merging: "<<endl;
    // for (int a = 0; a < n1+n2; a++)
    // {
    //     cout<<arr3[a]<<" ";
    // }


    mergeArrays_1(arr1, arr2, n1, n2);
    

    return 0;
}
