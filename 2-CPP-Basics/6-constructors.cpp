#include<iostream>
using namespace std;

class Rectangle{
    private:
    int length, breadth;

    public:
    Rectangle(){
        length = breadth = 1;
    }

    public:
    Rectangle(int l, int b);

    void show(){cout<<"length: "<<length<<"\nBreadth: "<<breadth<<"\n";}

    int area(int l, int b){
    return l*b;
    }

    int perimeter(int l, int b){
        return 2*(l+b);
    }

    int getLength(){
        return length;
    }

    int setLength(int l){
        length =l;
    }

    int getBreadth(){
        return breadth;
    }

    int setBreadth(int b){
        breadth = b;
    }


};

Rectangle :: Rectangle(int l, int b){
    length = l;
    breadth = b;
}



int main(){

    Rectangle r;

    Rectangle r2;
    r2.show();
    Rectangle r1(3,4);
    r1.show();

    cout<<"Area: "<<r.area(2,3)<<"\n";
    cout<<"Perimeter: "<<r.perimeter(2,3);

    r.setLength(20);
    cout<<"\nNew Length: "<<r.getLength();

    r.setBreadth(10);
    cout<<"\nNew Breadth: "<<r.getBreadth();
    
    
    return 0;
}