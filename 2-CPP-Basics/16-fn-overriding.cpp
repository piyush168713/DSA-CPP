#include<iostream>
using namespace std;

class parent{
    public:
    void print(){
        cout<<"Parent Class"<<endl;
    }
};

class child : public parent {
    public:
    void print(){
        cout<<"Child Class"<<endl;
    }
};

int main(){
    child c1;
    c1.print();
    
    return 0;
}