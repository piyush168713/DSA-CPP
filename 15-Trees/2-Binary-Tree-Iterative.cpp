#include<iostream>
#include<queue>
#include<stack>
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

void inorder(Node* root){
    stack<Node*> s;
    Node* temp = root;

    while(temp != NULL || !s.empty())
    {
        while(temp != NULL){
            s.push(temp);
            temp = temp->left;
        }

        temp = s.top();
        s.pop();

        cout<<temp->data<<" ";

        temp = temp->right;
    }
}

void preorder(Node* root)
{
    if(root == NULL){
        return;
    }

    stack<Node*> s;

    s.push(root);

    while(!s.empty())
    {
        Node* temp = s.top();
        cout<<temp->data<<" ";
        s.pop();
        if(temp->right)
        s.push(temp->right);
        if(temp->left)
        s.push(temp->left);
    }
}

void postorder(Node* root){
    if(root == NULL){
        return;
    }

    // create an empty stack and push the root node
    stack<Node*> s;
    s.push(root);

    // create another stack to store postorder traversal
    stack<int> st;

    // pop a node from the stack and push the data into the output stack
    while(!s.empty())
    {
        Node* temp = s.top();
        s.pop();

        st.push(temp->data);
        
        // push the left and right child of the popped node into the stack
        if(temp->left)
        s.push(temp->left);

        if(temp->right)
        s.push(temp->right);
        
    }

    // print postorder traversal
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main(){

    Node* root = NULL;

    // creating a tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //         1
    //    3        5
    //  7   11  17   -1
    root = buildTree(root);

    cout<<"\nInorder traversal is: ";
    inorder(root);

    cout<<"\nPreorder traversal is: ";
    preorder(root);

    cout<<"\nPostorder traversal is: ";
    postorder(root);

    return 0;
}
