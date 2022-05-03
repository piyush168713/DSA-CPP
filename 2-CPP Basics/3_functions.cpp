// #include<bits/stdc++.h>

// int add(int a, int b){
//     int c=a+b;
//     return c;
// }

// int main(){
    
//     int num1=10, num2=20, sum;

//     sum = add(num1, num2);
//     std::cout<<sum;

//     return 0;
// }





// #include<bits/stdc++.h>

// void swap(int a, int b){         // in swapping pass by value doesn't work
//     int temp = a;
//     a=b;                 // call by value
//     b=temp;
// }

// int main(){
//     int m,n;
//     m=12;
//     n=21;
//     swap(m,n);
//     std::cout<<m<<n;
//     return 0;
// }




// #include<bits/stdc++.h>

// void swap(int &a, int &b){         
//     int temp = a;
//     a=b;                 // call by address
//     b=temp;
// }

// int main(){
//     int m,n;
//     m=12;
//     n=21;
//     swap(m,n);
//     std::cout<<m<<n;
//     return 0;
// }


#include<bits/stdc++.h>

void swap(int *a, int *b){         
    int temp = *a;
    *a=*b;                 // call by reference
    *b=temp;
}

int main(){
    int m,n;
    m=12;
    n=21;
    swap(&m,&n);
    std::cout<<m<<n;
    return 0;
}