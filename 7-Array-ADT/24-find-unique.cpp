// codestudio

#include<iostream>
using namespace std;

void findUnique(int arr[], int n, int h){

    int H[5] = {0,0,0,0,0};

    for (int i = 0; i < n; i++)
    {
        H[arr[i]]++;
    }

    for (int j = 0; j <= h; j++)
    {
        if(H[j] == 1){
            cout<<"Unique no. is: "<<j<<endl;
        }
    }
}

int findUnique_1(int arr[], int size){
    int ans=0;

    for (int i = 0; i < size; i++)
    {
        ans = ans^arr[i];
    }
    return ans;
    
}


// int findUnique_2(int arr[], int n, int h){

//     int H[5] = {0,0,0,0,0};

//     for (int i = 0; i < n; i++)
//     {
//         H[arr[i]]++;
//     }

//     for (int j = 0; j <= h; j++)
//     {
//         if(H[j] == 1)
//             return true;
//         return false;
//     }
// }

int main(){
    int nums[] = {1,4,3,1,3};

    findUnique(nums,5, 4);
    cout<<"Unique no. using XOR is: "<<findUnique_1(nums,5);

    // cout<<endl<<findUnique_2(nums,5,4)<<endl;

    return 0;
}


