#include<iostream>
using namespace std;

class Array{
    public:
    int A[10];
    int size;
    int length;
};

void Display(Array arr){
    cout<<"Elements are: ";
    for (int i = 0; i < arr.length; i++)
    {
        cout<<arr.A[i]<<" ";
    }
}

void Append(Array *arr, int x){
    if(arr->length < arr->size)
    arr->A[arr->length++] = x;
}

void Insert(Array *arr, int index, int x){
    if(index > 0 && index < arr->length)
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int main(){

    Array arr = {{2,3,4,5,6}, 10, 5};

    Display(arr);   
    Append(&arr,9);
    Display(arr);
    Insert(&arr, 4,15);
    Display(arr);
    
    return 0;
}