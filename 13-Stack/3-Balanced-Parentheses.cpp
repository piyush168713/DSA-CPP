#include<iostream>
using namespace std;

class Node
{
    public:
    char data;
    Node* next;
};

class stack
{
    private:
    Node* top;
    public:
    stack(){top=NULL;}
    void display();
    void push(char x);
    char pop();
    int isBalanced(char* exp);
    int isBalancedParantheses(char *exp);
    bool arePair(char opening, char closing);
};

void stack :: display()
{
    Node* p = top;
    cout<<"Stack is: ";
    while(p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

void stack :: push(char x)
{
    Node* t = new Node();
    if(t == NULL)
    {
        cout<<"Stack is Full\n";
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

char stack :: pop()
{
    char x = -1;
    if(top == NULL)
    {
        cout<<"Stack is Empty\n";
    }
    else
    {
        Node* t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

int stack :: isBalanced(char* exp)
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(')
        push(exp[i]);
        else if(exp[i] == ')')
        {
        if(top == NULL)
        return 0;
        pop();
        }
    }
    if(top == NULL)
    return 1;
    else
    return 0;
}

bool stack :: arePair(char opening, char closing)
{
    if(opening == '(' && closing == ')') return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
	return false;
}


int stack :: isBalancedParantheses(char *exp)
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        push(exp[i]);
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(top == NULL)
            // if(top == NULL || !arePair(top, exp[i]))
            return 0;
            pop();
        }
    }
    if(top == NULL)
    return 1;
    else
    return 0;
}


int main(){
    stack stk;

    char* exp = "((a+b) * (c-d))";
    // char* exp1 = "{([a+b] * [c-d])/2}";

    if(stk.isBalanced(exp))
        cout<<"Balanced";
    else
        cout<<"Unbalanced";

    // if(stk.isBalancedParantheses(exp1))
    // cout<<"Balanced";
    // else 
    // cout<<"Unbalanced";
    

    return 0;
}
