#include<iostream>
using namespace std;


// For Single Missing Element
void singleMissingElement(int arr[], int l, int n){
    // lower bound
    // n = total no. of elements
    int diff = l-0;

    for (int i = 0; i < n; i++)
    {
        if(arr[i]-i != diff){
            cout<<"1. Missing Element is: "<<i+diff<<endl;
            break;
        }
    }
}

// For Multiple Missing Element
void multipleMissingElement(int arr[], int l, int n){
    // lower bound i.e. l=6
    // total no. of elements i.e. n=11
    int diff = l-0;

    for (int i = 0; i < n; i++)
    {
        if(arr[i] - i != diff){
            while (diff < arr[i]-i)
            {
                cout<<"2. Missing Element is: "<<i+diff<<endl;
                diff++;
            }
            
        }
    }
}


// Finding missing element using Hash Table in unsorted array
void missingElement_1(int arr[], int l, int h, int n){
    int H[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    for (int i = 0; i < n; i++)
    {
        H[arr[i]]++;
    }
    for (int i = l; i <= h; i++)
    {
        if(H[i] == 0)
        cout<<"Missing Element is: "<<i<<endl;
    }
    
    
}

int main(){

    int num[] = {6,7,8,9,10,11,12,14,15,16,17};

    // singleMissingElement(num, 6, 11);

    int num1[] = {6,7,8,9,11,12,15,16,17,18,19};

    // multipleMissingElement(num1, 6, 11);

    int num2[] = {3,7,4,9,12,6,1,11,2,10};

    missingElement_1(num2, 1, 12, 10);

    return 0;
}