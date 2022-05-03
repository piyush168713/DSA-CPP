#include<iostream>
using namespace std;

// n = no. of disk
// A = Tower 1
// B = Tower 2
// C = Tower 3

void ToH(int n, int A, int B, int C){
    if(n>0)
    {
        ToH(n-1, A, C, B);
        cout<<"Move disk "<<n<<" from Tower "<<A<<" to "<<C<<endl;
        ToH(n-1, B, A, C);
    }
}

int main(){

    ToH(3,1,2,3);
    // ToH(4,1,2,3);
    
    return 0;
}