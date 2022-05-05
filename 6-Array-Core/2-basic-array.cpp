#include<iostream>
using namespace std;

int main(){
    
    int A[5] = {2,3,4,5,6};
    int *P;
    P = new int[5];    // memory alloacted in heap      // can't access directly

    P[0] = 4;
    P[1] = 5;
    P[2] = 6;
    P[3] = 7;
    P[4] = 8;

    for (int i = 0; i < 5; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<P[i]<<" ";
    }
    

    // delete []P;

    return 0;
}

