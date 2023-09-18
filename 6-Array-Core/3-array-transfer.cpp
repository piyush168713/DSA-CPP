// Transfer of array

#include<iostream>
using namespace std;

int main(){
    
    int *p, *q;
    p = new int[5];

    p[0]=1;
    p[1]=2;
    p[2]=3;
    p[3]=4;
    p[4]=5;

    q = new int[10];
    for (int i = 0; i < 10; i++)
    q[i] = p[i];     // copying elements of p in q
    delete []p;      // delete the array p 
    p=q;      // making p pointing to q
    q=NULL;     // Now q do not points anywhere
    

    for (int i = 0; i < 5; i++)
    {
        cout<<p[i]<<" ";
    }

    return 0;
}
