// pointer

// #include<bits/stdc++.h>

// int main(){
    
// //     int A[5] = {1,2,3,4,5};         // stored in stack
// //     int *p;
// //     p = A;

// // for (int i = 0; i < 5; i++)
// // {
// //     std::cout<<p[i];
// // }

//     int *p;
//     p = new int[5];       // stored in heap
//     p[0] = 1; p[1]=3;p[2]=5;p[3]=7;p[4]=9;

// for (int i = 0; i < 5; i++)
// {
//     std::cout<<p[i];
// }
// delete [ ] p;
    
//     return 0;
// }



// accessing class using pointer

#include<bits/stdc++.h>

class rectangle{
    public:
    int length;
    int breadth;
};

int main(){

    // rectangle r = {10,5};

    // // r.length = 10;
    // // std::cout<<r.length;
    // // (*p).length = 20;

    // rectangle *p = &r;           // pointer to class
    // std::cout<<(*p).length;




// dynamic memory allocation
    rectangle *p;
    p = new rectangle;     // data stored in heap
    p->length = 20;
    (*p).breadth = 10;

    std::cout<<p->length<<"\n";
    std::cout<<(*p).breadth;

    return 0;
}
