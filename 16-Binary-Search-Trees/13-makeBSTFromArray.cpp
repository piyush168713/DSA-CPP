// It makes a bst using a normal array and the first element is the root and then element of array will be added sequentially to bst
#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) {
        return new TreeNode(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }

    return root;
}

TreeNode* arrayToBST(vector<int> &arr, int n) {
    if (n <= 0) {
        return NULL;
    }

    TreeNode* root = new TreeNode(arr[0]);

    for (int i = 1; i < n; i++) {
        insert(root, arr[i]);
    }

    return root;
}

void inorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
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
    vector<int> arr = {4, 2, 6, 1, 3, 5, 7};
    int n = arr.size();

    TreeNode* root = arrayToBST(arr, n);

    std::cout << "Inorder:  ";
    inorder(root);
    std::cout << std::endl;

    std::cout << "PreOrder: ";
    preorder(root);
    std::cout << std::endl;

    return 0;
}
