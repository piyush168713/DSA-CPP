// codehelp

#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void inorder(Node* root){
    if (root == NULL){
        return ;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

// Presenting tree in Level order
void levelOrderTraversal(Node* root)
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

Node* insertIntoBST(Node* root, int d)
{
    // base case
    if(root == NULL){
        root = new Node(d);
        return root; 
    }

    if(d > root->data){
        root->right = insertIntoBST(root->right, d);
    }
    else{
        root->left = insertIntoBST(root->left, d);
    }
}

Node* minVal(Node* root)
{
    Node* t = root;
    while(t->left != NULL){
        t = t->left;
    }
    return t;
}

Node* maxVal(Node* root)
{
    Node* t = root;
    while(t->right != NULL){
        t = t->right;
    }
    return t;
}

int Height(Node* root){
        int x, y;
        if(root == NULL){
            return 0;
        }
        x = Height(root->left);
        y = Height(root->right);
        return x>y?x+1:y+1;
    }

Node* deleteFromBst(Node* root, int val)
{
    // base case
    if(root == NULL){
        return root;
    }

    if(root->data == val){
        // 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
      
        // 2 child + 1 child
        if((root->left != NULL && root->right != NULL) || (root->left != NULL ^ root->right != NULL)){
            if(Height(root->left) > Height(root->right)){
                int maxi = maxVal(root->left)->data;    // find predecessor of root(right child of left subtree)
                root->data = maxi;    // copy the value of right most child of left subtree in root->data
                root->left = deleteFromBst(root->left, maxi);    // now delete recursively the right most child of left subtree
            }
            else
            {
                int mini = minVal(root->right)->data;          // find successor of root(left child of right subtree)
                root->data = mini;         // copy the value of left most child of right subtree in root->data
                root->right = deleteFromBst(root->right, mini);    // now delete recursively the left most child of right subtree
            }
        }

    }
    else if(root->data > val){
        root->left = deleteFromBst(root->left, val);
    }
    else{
        root->right = deleteFromBst(root->right, val);
    }
}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root, data);
        cin>>data;
    }
}

int main(){

    Node* root = NULL;

    cout<<"Enter data to create BST: ";
    // i/p - 50 20 70 10 30 90 110 -1
    // i/p - 30 20 40 10 25 35 45 -1
    // i/p - 30 80 40 50 -1

    takeInput(root);

    cout<<"Printing the BST(level order): "<<endl;
    levelOrderTraversal(root);

    cout<<"\nPrinting the BST(inorder): "<<endl;
    inorder(root);

    cout<<"\nPrinting the BST(preorder): "<<endl;
    preorder(root);

    cout<<"\nPrinting the BST(postorder): "<<endl;
    postorder(root);

    cout<<"\nMinimum Value is: "<<minVal(root)->data<<endl;
    cout<<"Maximum Value is: "<<maxVal(root)->data<<endl;

    // Deletion
    root = deleteFromBst(root, 10);

    cout<<"Printing the BST(level order): "<<endl;
    levelOrderTraversal(root);

    cout<<"\nPrinting the BST(inorder): "<<endl;
    inorder(root);

    cout<<"\nPrinting the BST(preorder): "<<endl;
    preorder(root);

    cout<<"\nPrinting the BST(postorder): "<<endl;
    postorder(root);

    cout<<"\nMinimum Value is: "<<minVal(root)->data<<endl;
    cout<<"Maximum Value is: "<<maxVal(root)->data<<endl;
    
    return 0;
}
