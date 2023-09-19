#include <iostream>  
using namespace std;  

inline int add(int a, int b)  
{  
    return(a+b);  
}  

int main()  
{  
    cout<<"Addition of 'a' and 'b' is: " << add(2,3) << endl;
    return 0;  
}  