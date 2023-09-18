// BST to Max Heap - GFG

// Link - https://practice.geeksforgeeks.org/problems/bst-to-max-heap/1

class Solution{
  public:
    void inorder(Node* root, vector<int> &in){
        if(root == NULL)
        return;
        
        inorder(root->left, in);
        in.push_back(root->data);
        inorder(root->right, in);
    }
    
  // postorder - LRN
    void BSTToMaxHeap(Node* root, vector<int> &arr, int &i)
    {
        if(root == NULL){
            return;
        }
        
        BSTToMaxHeap(root->left, arr, i);
        BSTToMaxHeap(root->right, arr, i);
        root->data = arr[i++];
    }
  
  
    void convertToMaxHeapUtil(Node* root)
    {
        vector<int> arr;
        inorder(root, arr);
        
        int i = 0;
        BSTToMaxHeap(root, arr, i);
        
    }    
};
