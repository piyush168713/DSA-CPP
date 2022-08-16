// Problem Statement

// LCA of Two Nodes In A BST - CodeStudio

// Link - https://www.codingninjas.com/codestudio/problems/lca-in-a-bst_981280

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	// Write your code here
    if(root == NULL){
        return NULL;
    }
    
    if(root->data < P->data && root->data < Q->data){
        return LCAinaBST(root->right, P, Q);
    }
    if(root->data > P->data && root->data > Q->data){
        return LCAinaBST(root->left, P, Q);
    }
    return root;
}
