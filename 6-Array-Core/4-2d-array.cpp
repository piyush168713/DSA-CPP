#include<iostream>
using namespace std;

int main(){
    
    int A[3][4] = {{1,2,3,4}, {3, 4, 5, 6}, {7, 8, 9, 6}};        // created in stack

    int *B[3];
    int **C;     // ** is for pointing twice

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout<<A[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    

    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout<<B[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    C = new int*[3];           // created in heap      // * means pointing once
    C[0] = new int[4];
    C[1] = new int[4];
    C[2] = new int[4];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
