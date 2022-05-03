// Lecture 30

#include<iostream>
using namespace std;

template <class T>
class Arithmetic{
    private:
    T a;
    T b;

    public:
    Arithmetic(T a, T b){
        this->a = a;
        this->b = b;
    }

    T add(){
        return a+b;
    }

    T sub(){
        return a-b;
    }

};

int main(){

    Arithmetic<int> ar(10,5);

    cout<<ar.add()<<endl;
    cout<<ar.sub();
    
    return 0;
}






// #include<iostream>
// using namespace std;

// template <class T>
// class Arithmetic{
//     private:
//     T a;
//     T b;

//     public:
//     Arithmetic(T a, T b);
//     T add();
//     T sub();

// };

//     template <class T>
//     Arithmetic<T>::Arithmetic(T a, T b){
//         this->a = a;
//         this->b = b;
//     }

//     template <class T>
//     T  Arithmetic<T>::add(){
//         return a+b;
//     }

//     template <class T>
//     T Arithmetic<T>::sub(){
//         return a-b;
//     }



// int main(){

//     Arithmetic<int> ar(10,5);
//     Arithmetic<float> ar1(10.99,5.68);

//     cout<<ar.add()<<endl;
//     cout<<ar.sub()<<endl;

//     cout<<ar1.add()<<endl;
//     cout<<ar1.sub()<<endl;
    
//     return 0;
// }