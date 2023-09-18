// it makes a bst from the array and the output inorder array will be same as input array

#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

/*
// Function to insert a node into the BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }

    return root;
}
*/

// Function to create a BST from an array
TreeNode* arrayToBST(vector<int> &arr, int start, int end) {
    if (start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;
    TreeNode* root = new TreeNode(arr[mid]);

    root->left = arrayToBST(arr, start, mid - 1);
    root->right = arrayToBST(arr, mid + 1, end);

    return root;
}

// Function to perform an in-order traversal of the BST
void inorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    std::cout << root->data << " ";
    inorderTraversal(root->right);
}

void preorder(TreeNode* root){
    if(root == NULL){
        return;
    }

    std::cout << root->data <<" ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    vector<int> arr = {1,5,7,10,40,50};
    
    // Create a BST from the array
    TreeNode* root = arrayToBST(arr, 0, arr.size());

    // Perform an in-order traversal to verify the BST
    std::cout << "Inorder: ";
    inorderTraversal(root);
    std::cout << std::endl;
    std::cout << "Preorder: ";
    preorder(root);
    std::cout << std::endl;

    return 0;
}
