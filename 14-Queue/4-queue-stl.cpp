#include<iostream>
#include<queue>
using namespace std;

int main(){

    queue<int> q;

    q.push(5);
    cout<<"Front of Queue is: "<<q.front()<<endl;
    q.push(10);
    cout<<"Front of Queue is: "<<q.front()<<endl;
    q.push(15);
    q.push(20);
    cout<<"Size of queue is: "<<q.size()<<endl;

    q.pop();
    cout<<"Size of queue is: "<<q.size()<<endl;

    if(q.empty())
    cout<<"Queue is Empty"<<endl;
    else
    cout<<"Queue is not empty"<<endl;
    
    return 0;
} 
