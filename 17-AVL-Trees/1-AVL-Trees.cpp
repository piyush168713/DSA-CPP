#include<iostream>
using namespace std;

class Node{
    public:
        Node* left;
        int data;
        int height;
        Node* right;
}*root = NULL;

int nodeHeight(Node* p){
    int hl, hr;
    hl = p && p->left?p->left->height:0;
    hr = p && p->right?p->right->height:0;
        
    return hl>hr?hl+1:hr+1;
}

int balanceFactor(Node* p){
    int hl, hr;
    hl = p && p->left?p->left->height:0;
    hr = p && p->right?p->right->height:0;

    return hl-hr;
}

Node* LLRotation(Node* p)
{
    Node* pl = p->left;
    Node* plr = pl->right;

    pl->right = p;
    p->left = plr;

    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);

    if(root == p){
        root = pl;
    }
    return pl;
}

Node* LRRotation(Node* p)
{
    Node* pl = p->left;
    Node* plr = pl->right;

    pl->right = plr->left;
    p->left = plr->right;

    plr->left = pl;
    plr->right = p;
    
    pl->height = nodeHeight(pl);
    p->height = nodeHeight(p);
    plr->height = nodeHeight(plr);

    if(root == p){
        root = plr;
    }
    return plr;
}

Node* RRRotation(Node* p)
{
    Node* pr = p->right;
    Node* prl = pr->left;

    p->left = pr;
    prl->right = pr;

    p->height = nodeHeight(p);
    prl->height = nodeHeight(prl);

    if(root == p){
        root = pr;
    }
    return pr;
}

Node* RLRotation(Node* p)
{
    Node* pr = p->right;
    Node* prl = pr->left;

    p->right = prl->left;
    pr->left = prl->right;

    prl->left = p;
    prl->right = pr;

    pr->height = nodeHeight(pr);
    p->height = nodeHeight(p);
    prl->height = nodeHeight(prl);

    if(root == p){
        root = prl;
    }
    return prl;
}

Node* Insert(Node* p, int key){
    Node* t = NULL;
    if(root == NULL){
        t = new Node;
        t->data = key;
        t->height = 1;
        t->left = t->right = NULL;
        return t;
    }
    if(key < p->data){
        p->left = Insert(p->left, key);
    }
    else if(key > p->data){
        p->right = Insert(p->right, key);
    }
    p->height = nodeHeight(p);

    if(balanceFactor(p) == 2 && balanceFactor(p->left) == 1){
        return LLRotation(p);
    }
    else if(balanceFactor(p) == 2 && balanceFactor(p->left) == -1){
        return LRRotation(p);
    }
    else if(balanceFactor(p) == -2 && balanceFactor(p->right) == -1){
        return RRRotation(p);
    }
    else if(balanceFactor(p) == -2 && balanceFactor(p->right) == 1){
        return RLRotation(p);
    }

    return p;
}

int main(){

    root = Insert(root, 50);
    Insert(root, 10);
    Insert(root, 20);
    
    return 0;
}
