#include<iostream>
using namespace std;

class Node{
    public:
    int col;
    int val;
    Node *next;
};

class sparse
{
    private:
    int trow;
    int tcol;
    Node **a;     // take this as a double pointer

    public:
    sparse(int r, int c)
    {
        trow = r;
        tcol = c;
        Node *t, *last;
        a = new Node*[r];      // create a array in heap
        
        int x;
        for (int i = 0; i < r; i++)
        {
            a[i] = NULL;
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout<<"Enter the element at row: "<<i<<" and column: "<<j<<endl;
                cin>>x;
                if(x != 0)
                {
                    if(a[i] == NULL)
                    {
                        t = new Node;
                        t->col = j;
                        t->val = x;
                        t->next = NULL;
                        a[i] = t;
                        last = t;
                    }
                    else
                    {
                        t = new Node;
                        t->col = j;
                        t->val = x;
                        t->next = NULL;
                        last->next = t;
                        last = t;
                    }
                }
            }
            cout<<endl;
        }
    }

    void display()
    {
        int i,j;
        Node *p;
        for (int i = 0; i < trow; i++)
        {
            p = a[i];
            for (int j = 0; j < tcol; j++)
            {
                if (p != NULL && j == p->col)
                {
                    cout<<p->val<<" ";
                    p = p->next;
                }
                else
                {
                    cout<<"0 ";
                }
            }
            cout<<endl;
        }       
    }
};

int main(){

    sparse a(3,3);
    a.display();
    
    return 0;
}
