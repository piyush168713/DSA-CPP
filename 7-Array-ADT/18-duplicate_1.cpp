#include <bits/stdc++.h>

using namespace std;

int main()
{

    int A[10] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    int length = 10;
    int count;

    for (int i = 0; i < length - 1; i++)
    {
        count = 1;
        while (A[i] == A[i + 1])
        {
            count++;
            i++;
        }
        if (count > 1)
        {
            cout<<A[i]<<" is printing "<<count<<" times"<<endl;
        }
    }
}