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

int heightOfTree(Node* root)
{
    int x = 0, y = 0;
    if(root == NULL){
        return 0;
    }

    x = heightOfTree(root->left);
    y = heightOfTree(root->right);

    int ans = max(x,y) + 1;
    return ans;
}

int diameterOfTree(Node* root)   // TC - O(n^2)
{
    if(root == NULL){
        return 0;
    }

    int x = diameterOfTree(root->left);
    int y = diameterOfTree(root->right);
    int z = heightOfTree(root->left) + heightOfTree(root->right) + 1;

    int ans = max(x, max(y,z));
    return ans;
}

pair<int, int> diameterFast(Node* root)   // TC - O(n)
{
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    // left part contains diameter (first) & right part contains height (second)

    pair<int,int> left = diameterFast(root->left);
    pair<int,int> right = diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int,int> ans;
    ans.first = max(op1, max(op2,op3));
    ans.second = max(left.second, right.second) + 1;

    return ans;

    // ans.first gives diameter
    // ans.second gives height
}

int main(){
    Node* root = NULL;

    // creating a tree using Recursion
    // Test case 1
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //         1
    //    3        5
    //  7   11  17   -1
    //
    // Test case 2
    // 8 3 12 -1 4 9 -1 -1 7 -1 -1 -1 5 10 -1 -1 6 2 -1 -1 -1
    root = buildTree(root);

    // Presenting Tree in level order 
    cout<<"\nPrinting the level order traversal: "<<endl;
    levelOrderTraversal(root);

    cout<<"\nHeight of Tree is: "<<heightOfTree(root);

    cout<<"\n(1) Diameter of Tree is: "<<diameterOfTree(root);

    cout<<"\n(2) Diameter of the Tree is: "<<diameterFast(root).first << endl;

}
