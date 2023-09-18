// Problem Statement

// Find K-th smallest Element in BST - CodeStudio

// Link - https://www.codingninjas.com/codestudio/problems/find-k-th-smallest-element-in-bst_1069333

int solve(BinaryTreeNode<int>* root, int& i, int k)
{
    if(root == NULL){
        return -1;
    }
    // L
    int left = solve(root->left, i, k);
    if(left != -1){
        return left;
    }
    // N
    i++;
    if(i == k){
        return root->data;
    }
    // R
    return solve(root->right, i, k);
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here.
    int i;
    int ans = solve(root, i, k);
    return ans;
}
