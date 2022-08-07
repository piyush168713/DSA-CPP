// udemy

#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
};

class BST{
    private:
    Node* root;

    public:
    BST(){
        root = NULL;
    }

    Node* getRoot(){
        return root;
    }

    void insert(int key);     // iterative
    Node* Rinsert(Node* root, int key);   // recursive
    void inorder(Node* p);
    void preorder(Node* p);
    void levelOrderTraversal(Node* root);
    Node* search(int key);    
    Node* minVal(Node* root);
    Node* maxVal(Node* root);
    Node* RDelete(Node* root, int key);
    int Height(Node* root);
    Node* InPred(Node* root);
    Node* InSucc(Node* root);
};

void BST :: insert(int key)
    {
        Node* t = root;
        Node *r, *p;

        // root is empty
        if(root == NULL){
            p = new Node;
            p->data = key;
            p->left = p->right = NULL;
            root = p;
            return;
        }
        // find the location where it can be insert
        while(t != NULL){
            r = t;
            if(key < t->data)
            t = t->left;
            else if(key > t->data)
            t = t->right;
            else
            return;
        }
        // create a node for insert
        // Now t points at NULL and r points at insert location
        p = new Node;
        p->data = key;
        p->left = p->right = NULL;

        if(key < r->data)
        r->left = p;
        else
        r->right = p;
    }

    Node* Rinsert(Node* root, int key)
    {
        Node* t = NULL;
        if(root == NULL){
            t = new Node;
            t->data = key;
            t->left = t->right = NULL;
            return t;
        }
        if(key < root->data){
            root->left = Rinsert(root->left, key);
        }
        else if(key > root->data){
            root->right = Rinsert(root->right, key);
        }
        return root;
    }

    void BST :: inorder(Node* p)
    {
        if(p)
        {
            inorder(p->left);
            cout<<p->data<<" ";
            inorder(p->right);
        }
    }

    void BST :: preorder(Node* p){
        if(p){
        cout<<p->data<<" ";
        preorder(p->left);
        preorder(p->right);
        }
    }   

    void BST :: levelOrderTraversal(Node* root)
    {
        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();

            if(temp == NULL)
            {
                // old level is completely traverse
                cout<<endl;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else
            {
                cout<<temp->data<<" ";
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
    }

    Node* BST :: search(int key)
    {
        Node* t = root;
        while(t != NULL){
            if(key == t->data){
                return t;
            }
            else if(key < t->data){
                return t->left;
            } else {
                return t->right;
            }
        }
        return NULL;
    }

    Node* BST :: minVal(Node* root)
    {
        Node* t = root;
        while(t->left != NULL){
            t = t->left;
        }
        return t;
    }

    Node* BST :: maxVal(Node* root)
    {
        Node* t = root;
        while(t->right != NULL){
            t = t->right;
        }
        return t;
    }

    int BST :: Height(Node* root){
        int x, y;
        if(root == NULL){
            return 0;
        }
        x = Height(root->left);
        y = Height(root->right);
        return x>y?x+1:y+1;
    }

    Node* BST :: InPred(Node* root)
    {
        while(root && root->right != NULL){
            root = root->right;
            return root;
        }
    }

    Node* BST :: InSucc(Node* root)
    {
        while(root && root->left != NULL){
            root = root->left;
            return root;
        }
    }

    Node* BST :: RDelete(Node* root, int key)
    {
        if(root == NULL){
            return NULL;
        }
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        Node* q = NULL;
        if(key < root->data){
            root->left = RDelete(root->left, key);
        }
        else if(key > root->data){
            root->right = RDelete(root->right, key);
        }
        else{
            if(Height(root->left) > Height(root->right)){
                q = InPred(root->left);    // find predecessor of root(right child of left subtree)
                root->data = q->data;    // copy the value of right most child of left subtree in root->data
                root->left = RDelete(root->left, q->data);    // now delete recursively the right most child of left subtree
            }
            else
            {
                q = InSucc(root->right);          // find successor of root(left child of right subtree)
                root->data = q->data;         // copy the value of left most child of right subtree in root->data
                root->right = RDelete(root->right, q->data);    // now delete recursively the left most child of right subtree
            }
        }
        return root;
    }

int main(){
    
    BST bst;
    Node* root = NULL;

    // Iterative Insert
    bst.insert(10);
    bst.insert(5);
    bst.insert(20);
    bst.insert(8);
    bst.insert(30);

    // Recursive Insert
    // root = bst.Rinsert(root,10);
    // bst.Rinsert(root, 5);
    // bst.Rinsert(root, 20);
    // bst.Rinsert(root, 8);
    // bst.Rinsert(root, 30);

    // Level order Traversal
    cout<<"Level Order Traversal: "<<endl;
    bst.levelOrderTraversal(bst.getRoot());

    // Inorder Traversal
    cout<<"\nInorder: ";
    bst.inorder(bst.getRoot());

    // bst.RDelete(bst.getRoot(), 20);

    cout<<"\nPreorder: ";
    bst.preorder(bst.getRoot());
    cout<<endl;

    cout<<"\nMinimum Value is: "<<bst.minVal(bst.getRoot())->data<<endl;
    cout<<"Maximum Value is: "<<bst.maxVal(bst.getRoot())->data<<endl;

    Node* temp = bst.search(31);

    // if(temp != NULL){
    //     cout<<temp->data<<endl;
    // }
    // else{
    //     cout<<"Element not found";
    // }
    
    return 0;
}
