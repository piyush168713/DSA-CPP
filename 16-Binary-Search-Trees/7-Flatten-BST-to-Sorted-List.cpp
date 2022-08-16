// Problem Statement

// Flatten BST To A Sorted List - CodeStudio

// Link - https://www.codingninjas.com/codestudio/problems/flatten-bst-to-a-sorted-list_1169459

void inorder(TreeNode<int>* root, vector<int> &in)
{
    if(root == NULL)
        return;
    
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    vector<int> inorderVal;
    // store inorder -> sorted value
    inorder(root, inorderVal);
    
    int n = inorderVal.size();
    
    // create a new node/root
    TreeNode<int>* newRoot = new TreeNode<int>(inorderVal[0]);
    
    // create a pointer
    TreeNode<int>* curr = newRoot;
    
    // 2nd step
    for(int i = 1; i < n; i++){
        TreeNode<int>* temp = new TreeNode<int>(inorderVal[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    
    // 3rd step
    curr->left = NULL;
    curr->right = NULL;
    
    return newRoot;
}
