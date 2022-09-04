// Convert BST to min Heap - CodeStudio

// Link - https://www.codingninjas.com/codestudio/problems/convert-bst-to-min-heap_920498

void inorder(BinaryTreeNode* root, vector<int> &in)
{
    if(root == NULL){
        return;
    }
    
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

// Preorder - Insertion of elements based on N L R format - Min Heap Creation
void BSTToMinHeap(BinaryTreeNode* root, vector<int> &arr, int &i)
{
    if (root == NULL)
        return;
 
    root->data = arr[i++];
    BSTToMinHeap(root->left, arr, i);
    BSTToMinHeap(root->right, arr, i);
}

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
    // Write your code here.
    vector<int> arr;
    inorder(root, arr);
    
    int i = 0;
    
    BSTToMinHeap(root, arr, i);
    return root;
}
