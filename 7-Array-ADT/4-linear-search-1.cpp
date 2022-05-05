#include<iostream>
using namespace std;

class Array{
    public:
    int A[10];
    int size;
    int length;
};

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int LinearSearch(Array *arr, int key){
    for (int i = 0; i < arr->length; i++)
    {
        if(key == arr->A[i]){
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
                   
    }
    return -1;
    
}

void Display(Array arr){
    cout<<"Elements are: ";
    for (int i = 0; i < arr.length; i++)
    {
        cout<<arr.A[i]<<" ";
    }
}



int main(){

    Array arr = {{8,9,4,7,6,3,10,5,14,2}, 10, 10};

    Display(arr);
    cout<<endl<<LinearSearch(&arr,5)<<endl;

    Display(arr);
    
    
    return 0;
}