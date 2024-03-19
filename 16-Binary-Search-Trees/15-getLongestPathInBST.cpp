#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

TreeNode* insertNode(TreeNode* root, int val){
    if(root == NULL){
        return new TreeNode(val);
    }

    if(root->data > val){
        root->left = insertNode(root->left, val);
    }
    else if(root->data < val){
        root->right = insertNode(root->right, val);
    }
    return root;
}

TreeNode* makeTreeFromArray(vector<int> &arr, int n){
    if(n <= 0)
        return NULL;
    
    TreeNode* root = new TreeNode(arr[0]);

    for(int i = 1; i < n; i++){
        insertNode(root, arr[i]);
    }
    return root;
}

void findLongestPath(TreeNode* root, vector<int> &path, vector<int> &longestPath){
    if(root == NULL)
        return;

    path.push_back(root->data);

    if(root->left == NULL && root->right == NULL && path.size() > longestPath.size())
        longestPath = path;
    
    findLongestPath(root->left, path, longestPath);
    findLongestPath(root->right, path, longestPath);

    path.pop_back();
}

void printLongestPath(vector<int> &longestPath){
    for(int val : longestPath){
        cout << val << " ";
    }
    cout<<endl;
}

void inorder(TreeNode* root){
    if(root == NULL)
        return;
    
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(TreeNode* root){
    if(root == NULL)
        return;
    
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    vector<int> arr = {10, 4, 2, 13, 7, 14, 11, 5, 6};
    int n = arr.size();

    TreeNode* root = makeTreeFromArray(arr, n);

    vector<int> path, longestPath;
    findLongestPath(root, path, longestPath);

    printLongestPath(longestPath);

    // cout << "Inorder: ";
    // inorder(root);
    // cout<<endl;
    // cout << "Preorder: ";
    // preorder(root);
    
    return 0;
}