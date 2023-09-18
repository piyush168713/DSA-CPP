#include<iostream>
#include<stack>
using namespace std;

int main(){

    string str = "piyush";

    stack<char> stk;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        stk.push(ch);     // pushed in stack
    }

    string ans = "";

    while(!stk.empty())
    {
        char ch = stk.top();
        ans.push_back(ch);

        stk.pop();
    }

    cout<<"Reversed String is: "<<ans;
        
    return 0;
}
