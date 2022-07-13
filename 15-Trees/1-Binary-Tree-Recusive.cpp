// Binary Tree and all traversals implementation 

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

// Building tree using Recursive way
Node* buildTree(Node* root){

    cout<<"Building tree using Recursive way\n";
    cout<<"Enter the data: ";
    int data;
    cin>>data;

    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for inserting in left: "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right: "<< data<<endl;
    root->right = buildTree(root->right);
    return root;

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

// Building tree using level order traversal
Node* buildTreeFromLevelOrder(Node* &root)
{
    queue<Node*> q;
    cout<<"Building tree using level order traversal:-\n";
    cout<<"Enter data for root: ";
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        cout<<"Enter left node for: "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for: "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData != -1){
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

int main(){
    Node* root = NULL;

    // creating a tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //         1
    //    3        5
    //  7   11  17   -1
    // root = buildTree(root);

    // creating a tree
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    buildTreeFromLevelOrder(root);

    // level order
    cout<<"\nPrinting the level order traversal: "<<endl;
    levelOrderTraversal(root);

    // cout<<"Inorder Traversal is: ";
    // inorder(root);

    // cout<<"\nPreorder Traversal is: ";
    // preorder(root);
    
    // cout<<"\nPostorder Traversal is: ";
    // postorder(root);
    
    return 0;
}
