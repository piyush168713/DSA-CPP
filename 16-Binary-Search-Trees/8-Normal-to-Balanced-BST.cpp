// Problem Statement

// Normal BST To Balanced BST - CodeStudio

// Problem Link - https://www.codingninjas.com/codestudio/problems/normal-bst-to-balanced-bst_920472

void inorder(TreeNode<int>* root, vector<int> &in)
{
    if(root == NULL)
        return;
    
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

TreeNode<int>* inorderToBst(int s, int e, vector<int> in)
{
    if(s>e)
        return NULL;
    
    int mid = (s+e)/2;
    TreeNode<int>* root = new TreeNode<int>(in[mid]);
    root->left = inorderToBst(s, mid-1, in);
    root->right = inorderToBst(mid+1, e, in);
    return root;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Write your code here.
    vector<int> inorderVal;
    // store inorder -> sorted value
    inorder(root, inorderVal);
    
    return inorderToBst(0, inorderVal.size()-1, inorderVal);
}
