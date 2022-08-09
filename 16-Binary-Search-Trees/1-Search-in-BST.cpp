// Problem Statement

// Search In BST - Codestudio


bool searchInBST(BinaryTreeNode<int> *root, int x) {
  
    // Write your code here.
  
    /*
    if(root == NULL){
        return NULL;
    }
    
    if(root->data == x){
        return true;
    }
    if(root->data > x){
        return searchInBST(root->left, x);
    }
    else{
        return searchInBST(root->right, x);
    } 
    */
    
    BinaryTreeNode<int>* t = root;
    while(t != NULL){
        if(x == t->data){
            return true;
        }
        else if(x > t->data){
            t = t->right;
        }
        else{
            t = t->left;
        }
    }
    return false;
}
