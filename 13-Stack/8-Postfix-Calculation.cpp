#include<iostream>
#include <cmath>
#include<stack>
using namespace std;

int isOperand(int x)       // checks whether any int value is passed or not
{
    if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
    return 0;     // if operator is passed, return false
    else 
    return 1;     // if operand/int value is passed, return true
}

int postfixEval(char* postfix)
{
    stack<char> stk;
    int i, x1, x2, r;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        if(isOperand(postfix[i]))     // if there is any int value then store else pop int values.
        stk.push(postfix[i] - '0');   // we used - '0' because the value is stored in stack are ASCII value so we subtract by 0 to get actual int value.
        else
        {
            x2 = stk.top();    
            stk.pop();     // store and pop
            x1 = stk.top();
            stk.pop();     // store and pop

            switch (postfix[i])
            {
            case '+': 
                r=x1+x2; 
                break;
            case '-': 
                r=x1-x2; 
                break;
            case '*': 
                r=x1*x2; 
                break;
            case '/': 
                r=x1/x2; 
                break;
            case '^':
                r=pow(x1,x2);
                break;
            }
            stk.push(r);
        }
    }
    return stk.top();
}

int main(){

    char *infix = "35*62/+4-";
    char *infix1 = "65+34*+";

    cout<<"\nResult is: "<<postfixEval(infix1);
    
    return 0;
}




// Here typecasting isn't work so, we change ASCII value to numeric/integer value by subtracting '0' in our numeric/integer value. 
// then after pushing into stack both int values changes into ASCII value and after subtracting it gives actual int value.
// i.e. Integer value = '3' - '0' = 3
//      ASCII value = 51 - 48 = 3
