// call by value

// #include<iostream>
// using namespace std;

// class rectangle{
//     public:
//     int length;
//     int breadth;
// };

// // function takes class as parameter
// // in call by value, if any changes make here then changes are only occurs in this function not in main() function

// void fun(rectangle rec){
//     rec.length = 20;
//     cout<<"Length: "<<rec.length<<"\nBreadth: "<<rec.breadth<<endl;
// }

// int main(){
//     rectangle r={10,5};
//     cout<<"Length: "<<r.length<<"\nBreadth: "<<r.breadth<<endl;

//     fun(r);

//     return 0;
// }

// call by address

// #include<iostream>
// using namespace std;

// class rectangle{
//     public:
//     int length;
//     int breadth;

// // function takes class as parameter
// // in call by value, if any changes make here then changes are occurs in both this function and in main() function

//     void fun(){       // this is type of pointer rectangle
//         length = 20;
//         cout<<"Length: "<<length<<"\nBreadth: "<<breadth<<endl;
//     }
// };

// int main(){
//     rectangle r={10,5};
//     r.fun();
//     cout<<"Length: "<<r.length<<"\nBreadth: "<<r.breadth<<endl;

//     return 0;
// }

// variable of type structure heap and returns its address

#include<iostream>
using namespace std;

class rectangle{
    public:
    int length;
    int breadth;
};

rectangle *fun(){
    rectangle *p;        // create object of type rectangle using pointer
    new rectangle;       // creating an object on a heap

    p->length = 15;
    p->breadth = 7;

    return p;       // return the address of structure
}

int main(){

    rectangle *ptr = fun();
    std::cout<<"Length: "<<ptr->length<<"\nBreadth: "<<ptr->breadth;

    return 0;
}
















// #include<iostream>
// using namespace std;

// class Rectangle{
//     private:
//     int length, breadth;

//     public:
//     int area(int m, int n){
//         return m*n;
//     }

//     public:
//     int peri(int x, int y){
//         return 2*(x+y);
//     }
// };

// int main(){

//     Rectangle r;

//     // cout<<r.area(3,4);
//     // cout<<r.peri(3,4);

//     int l,b;
//     cout<<"Enter length: ";
//     cin>>l;
//     cout<<"Enter breadth: ";
//     cin>>b;

//     cout<<"Area of Rectangle: "<<r.area(l,b);
//     cout<<"\nPerimeter of Rectangle: "<<r.peri(l,b);


    
//     return 0;
// }





