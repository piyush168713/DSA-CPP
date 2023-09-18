// Doubly Ended Queue using STL

#include<iostream>
#include<queue>
using namespace std;

int main(){

    deque<int> d;

    d.push_front(10);
    d.push_back(15);

    cout<<d.front()<<endl;   // if you see from front side ....10 will be displayed
    cout<<d.back()<<endl;    // same, if you see from back side ....15 will be displayed

    d.pop_front();

    cout<<d.front()<<endl;
    cout<<d.back()<<endl;

    d.pop_back();

    if(d.empty())
    cout<<"Queue is Empty\n";
    else
    cout<<"Queue is not Empty\n";
    
    return 0;
}
