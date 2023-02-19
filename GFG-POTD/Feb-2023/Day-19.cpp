// Fixing Two swapped nodes of a BST

// Link - https://practice.geeksforgeeks.org/problems/6c4053871794c5e7a0817d7eaf88d71c4bb4c2bc/1

class Solution {
    /*
    void fixBst(Node* root, Node* &a, Node* &b, Node* &c){
        if(root == NULL){
            return;
        }
        fixBst(root->left, a, b, c);
        if(a != NULL && root->data < a->data){
            if(b == NULL){
                b = a;
            }
            c = root;
        }
        a = root;
        fixBst(root->right, a, b, c);
    }
    
  public:
    struct Node *correctBST(struct Node *root) {
        // code here
        Node *prev = NULL, *first = NULL, *second = NULL;
        fixBst(root, prev, first, second);
        swap(first->data, second->data);
        return root;
    }
    */
    
    
    
    void inorder(Node *root, vector<int> &v){
        if(!root)
            return;
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
    
    void get(Node* root, vector<int> &v, int &i){
        if(!root)
            return;
        get(root->left, v, i);
        root->data = v[i];
        i++;
        get(root->right, v, i);
    }
    
  public:
    struct Node *correctBST(struct Node *root){
        vector<int> v;
        inorder(root, v);
        
        int i = 0;
        sort(v.begin(), v.end());
        get(root, v, i);
        return root;
    }
    
};
