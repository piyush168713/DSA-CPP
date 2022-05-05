// // Reverse an Array

// #include<iostream>
// using namespace std;

// void reverseArray(int arr[], int s, int e){

//     while(s<e)
//     {
//         int temp = arr[s];
//         arr[s] = arr[e];
//         arr[e] = temp;
//         s++;
//         e--;
//     }
// }


// void printArray(int arr[], int size){
//     for (int i = 0; i < size; i++)
//     {
//         cout<<arr[i];
//     }
//     cout<<endl;
    
// }
 
// int main(){

//     int num[20] = {1,2,3,4,5};
//     int length = 6;

//     int n = sizeof(num) / sizeof(num[0]);

//     cout<<"Original array: ";
//     printArray(num, 5);

//     reverseArray(num, 0, n-1);

//     cout<<"Reversed array: ";
//     printArray(num, 5);

    
    
//     return 0;
// }






// Inserting in element in a sorted array



// #include <iostream>
// using namespace std;
  

// int insertSorted(int arr[], int n, int key, int capacity){
//     if (n >= capacity)
//     return n;

//     int i;
//     for (i = n-1; (i>=0 && arr[i]>key); i--)
//         arr[i+1] = arr[i];
//     arr[i+1] = key;
//     return n+1;
// }

// int main()
// {
//     int arr[20] = { 12, 16, 20, 40, 50, 70 };
//     int capacity = sizeof(arr) / sizeof(arr[0]);
//     int n = 6;
//     int i, key = 55;
  
//     cout<< "\nBefore Insertion: ";
//     for (i = 0; i < n; i++)
//         cout << arr[i] << " ";
  
//     n = insertSorted(arr, n, key, capacity);
  
//     cout << "\nAfter Insertion: ";
//     for (i = 0; i < n; i++)
//         cout << arr[i]<< " ";
  
//     return 0;
// }




// ------      isSorted       -------//

// int isSorted(int arr[], int n){
//     int i;
//     for ( i = 0; i < n-1; i++)
//     {
//         if(arr[i]>arr[i+1])
//         return -1;
//     }
//     return 1;
    
// }






// -----------  Rearrange an Array  ------------- //

#include<iostream>
using namespace std;

void Rearrange(int arr[], int length){
    int i = 0;
    int j = length-1;

    while(i<j)
    {
        while(arr[i]<0) 
        i++;
        while(arr[i]>=0) 
        j--;
        if(i<j)
        swap(arr[i], arr[j]);
    }

}

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i];
    }
    cout<<endl;
    
}

int main(){

    int num[6] = {2,3,-4,5,-6,7};

    Rearrange(num, 6);

    printArray(num,6);
    
    return 0;
}
