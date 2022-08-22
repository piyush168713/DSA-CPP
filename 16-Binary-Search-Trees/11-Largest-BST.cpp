// Problem Statement

// Size of Largest BST in Binary Tree - CodeStudio

// Link - https://www.codingninjas.com/codestudio/problems/largest-bst-subtree_893103

class info{
    public:
        int maxi;
        int mini;
        bool isValidBst;
        int size;
};

info solve(TreeNode<int>* root, int &ans)
{
    // base case
    if(root == NULL){
        return {INT_MIN, INT_MAX, true, 0};
    }
    
    info left = solve(root->left, ans);
    info right = solve(root->right, ans);
    
    info currNode;
    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);
    
    if(left.isValidBst && right.isValidBst && (root->data > left.maxi && root->data < right.mini)) {
        currNode.isValidBst = true;
    }
    else {
        currNode.isValidBst = false;
    }
    
    // update answer
    if(currNode.isValidBst){
        ans = max(ans, currNode.size);
    }
    return currNode;
}

int largestBST(TreeNode<int>* root) 
{
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}
