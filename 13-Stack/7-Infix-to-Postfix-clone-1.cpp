#include<iostream>
#include<stack>
using namespace std;

int outPriority(char infix)
{
    if(infix == '+' || infix == '-')
    return 1;

    if(infix == '*' || infix == '/')
    return 3;

    if(infix == '^')
    return 6;

    if(infix == '(')
    return 7;

    if(infix == ')')
    return 0;

    return -1;
}

int inPriority(char infix)
{
    if(infix == '+' || infix == '-')
    return 2;

    if(infix == '*' || infix == '/')
    return 4;

    if(infix == '^')
    return 5;

    if(infix == '(')
    return 0;

    return 0;
}

string convert(string infix)
{
    int i = 0, j=0;
    string postfix = "";

    // using inbuilt stack<>
    stack<char> stk;

    while(infix[i] != '\0')
    {
        if(infix[i]>='a' && infix[i]<='z'|| infix[i]>='A'&& infix[i]<='Z')          
        {
            postfix += infix[i];
            i++;
        }
        else if(infix[i]=='(')
        {
            stk.push(infix[i]);
            i++;
        }
        else if(infix[i]==')')
        {
            while(stk.top() != '('){
                postfix += stk.top();
                stk.pop();
            }
            stk.pop();
            i++;
        }
        else            
        {
            while (!stk.empty() && outPriority(infix[i]) <= inPriority(stk.top())){
                postfix += stk.top();
                stk.pop();
            }
            stk.push(infix[i]);
            i++;
        }
    }    

    while(!stk.empty()){
        postfix += stk.top();
        stk.pop();
    }

    cout << "Postfix is : " << postfix; 
    return postfix;
}


int main(){

    string infix = "((a+(b*c))-d)";
    string infix1 = "a+b*c-d/e";
    string infix2 = "(a+b)*c-d^e^f";
    string postfix;
    postfix = convert(infix2);
    return 0;
}
