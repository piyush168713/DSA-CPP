// Problem Statement

// is Binary Tree Heap - GFG, CodeStudio

// GFG - https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1

// CodeStudio - https://www.codingninjas.com/codestudio/problems/is-binary-heap-tree_893136?leftPanelTab=0

class Solution {
  private:
    int countNodes(Node* root){
        if(root == NULL){
            return 0;
        }
        
        int ans = 1 + countNodes(root->left) + countNodes(root->right);
        return ans;
    }    
    
    bool isCBT(Node* root, int index, int cnt)
    {
        if(root == NULL){
            return true;
        }
        
        if(index > cnt){
            return false;
        }
        else
        {
            bool left = isCBT(root->left, 2*index+1, cnt);
            bool right = isCBT(root->right, 2*index+2, cnt);
            return left && right;
        }
    }
    
    bool isMaxOrder(Node* root)
    {
        // leaf Node
        if(root->left == NULL && root->right == NULL){
            return true;
        }
        if(root->right == NULL){
            return (root->data > root->left->data);
        }
        else
        {
            bool left = isMaxOrder(root->left);
            bool right = isMaxOrder(root->right);
        }
        
        return (left && right && (root->data > root->left->data && root->data > root->right->data));
    }
    
  public:
    bool isHeap(struct Node* tree) {
        // code here
        int index = 0;
        
        int totalCount = countNodes(tree);
        
        if(isCBT(tree, index, totalCount) && isMaxOrder(tree)){
            return true;
        }
        else
        {
            return false;
        }
    }
};
