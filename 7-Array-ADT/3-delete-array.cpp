#include<iostream>
using namespace std;

class Array{
    public:
    int A[20];
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

int Delete(Array *arr, int index){
    int x=0;
    if(index>=0 && index<arr->length){
        x = arr->A[index];
        for (int i = index; i < arr->length-1; i++)
        {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return 0;
        
}

int main(){

    Array arr = {{2,3,4,5,6}, 20, 5};

    Display(arr); 
    cout<<Delete(&arr, 2);
    Display(arr);  
    
    return 0;
}