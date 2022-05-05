// Find Duplicate using Hash in sorted array

#include<iostream>
using namespace std;

void hashDuplicate(int arr[], int n, int l, int h){
    int Hash[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    for (int i = 0; i < n; i++)
    {
        Hash[arr[i]]++;
    }
    for (int i = l; i <= h; i++)        // h = higher element in array num i.e. 20
    {
        if(Hash[i] > 1)
        cout<<i<<" is printing "<<Hash[i]<<" times"<<endl;
    }  
}


int main(){

    int num[] = {3,6,8,8,10,12,15,15,15,20,20,20};

    hashDuplicate(num, 12, 3, 20);
    
    return 0;
}