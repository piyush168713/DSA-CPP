#include<iostream>
#include<cmath>
using namespace std;

class Node
{
    public:
    int coeff;
    int exp;
    Node *next;
}*poly = NULL;

void create()
{
    Node *t, *last = NULL;
    int num;
    
    cout<<"\nEnter no. of terms: ";
    cin>>num;

    cout<<"\nEnter each term with coeff and exp\n";

    for (int i = 0; i < num; i++)
    {
        t = new Node;
        cin>>t->coeff>>t->exp;
        t->next = NULL;
        if (poly == NULL)
        {
            poly = last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
    
}

void display(Node *p)
{
    while(p != NULL)
    {
        cout<<p->coeff<<"x^"<<p->exp<<" + ";
        p = p->next;
    }
}

long eval(Node *p, int x)
{
    long sum = 0;
    
    while(p != NULL)
    {
        sum += p->coeff * pow(x, p->exp);
        p = p->next;
    }
    return sum;
}

int main(){

    create();
    cout<<endl;
    display(poly);
    cout<<"\n\nTotal sum is: "<<eval(poly, 1);
    
    return 0;
}
