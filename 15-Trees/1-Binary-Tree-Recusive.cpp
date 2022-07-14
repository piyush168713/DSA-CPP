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

    // cout<<"Building tree using Recursive way\n";
    cout<<"Enter the data: ";
    int data;
    cin>>data;

    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right of "<< data<<endl;
    root->right = buildTree(root->right);
    return root;
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

int countTotalNode(Node* root)
{
    int x = 0, y = 0;

    if(root != NULL){
        x = countTotalNode(root->left);
        y = countTotalNode(root->right);
        return x+y+1;
    }
}

void countLeafNodeOfDegreeZero(Node* root, int &count)   // passing the reference of count.
{
    if(root == NULL){
        return;
    }
    countLeafNodeOfDegreeZero(root->left, count);
    if(root->left == NULL && root->right == NULL){
        count++;
    }
    countLeafNodeOfDegreeZero(root->right, count);
}

void countLeafNodeOfDegreeOne(Node* root, int &cnt)   // passing the reference of cnt.
{
    if(root == NULL){
        return;
    }

    countLeafNodeOfDegreeOne(root->left, cnt);
    // Both are the same statement....  ^ is exclusive OR symbol
    // if(root->left == NULL && root->right != NULL || root->left != NULL && root->right == NULL){
    if(root->left != NULL ^ root->right != NULL){
        cnt++;
    }   
    countLeafNodeOfDegreeOne(root->right, cnt); 
}

void countLeafNodeOfDegreeTwo(Node* root, int &total)   // passing the reference of total.
{
    if(root == NULL){
        return;
    }

    countLeafNodeOfDegreeTwo(root->left, total);
    if(root->left != NULL && root->right != NULL){
        total++;
    }   
    countLeafNodeOfDegreeTwo(root->right, total); 
}

int heightOfTree(Node* root)
{
    int x = 0, y = 0;
    if(root == NULL){
        return 0;
    }

    x = heightOfTree(root->left);
    y = heightOfTree(root->right);

    if(x>y)
    return x+1;
    else
    return y+1;
}

int main(){
    Node* root = NULL;

    // creating a tree using Recursion
    // Test case 1
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // OR
    //         1
    //    3        5
    //  7   11  17   -1
    //
    // Test Case 2
    // 8 3 12 -1 4 9 -1 -1 7 -1 -1 -1 5 10 -1 -1 6 2 -1 -1 -1
    root = buildTree(root);

    // creating a tree using level order
    // Test case 1
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    //
    // Test Case 2
    // 8 3 5 12 -1 10 6 -1 4 -1 -1 2 -1 9 7 -1 -1 -1 -1 -1 -1
    // buildTreeFromLevelOrder(root);

    // Presenting Tree in level order 
    cout<<"\nPrinting the level order traversal: "<<endl;
    levelOrderTraversal(root);

    cout<<"Inorder Traversal is: ";
    inorder(root);

    cout<<"\nPreorder Traversal is: ";
    preorder(root);
    
    cout<<"\nPostorder Traversal is: ";
    postorder(root);

    cout<<"\nTotal no. of Node is: "<<countTotalNode(root);
    
    int count = 0;
    countLeafNodeOfDegreeZero(root,count);
    cout<<"\nTotal no. of zero leaf Node: "<< count;

    int cnt = 0;
    countLeafNodeOfDegreeOne(root,cnt);
    cout<<"\nTotal no. of one leaf Node: "<< cnt;

    int total = 0;
    countLeafNodeOfDegreeTwo(root,total);
    cout<<"\nTotal no. of two leaf Node: "<< total;
    
    cout<<"\nHeight of Tree is: "<<heightOfTree(root);
    
    return 0;
}
