/*

Problem Statement

Boundary Traversal of binary tree - GFG

Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Example 1:

Input:
        1 
      /   \
     2     3  
    / \   / \ 
   4   5 6   7
      / \
     8   9
   
Output: 1 2 4 8 9 6 7 3
Explanation:
see image for explanation
https://media.geeksforgeeks.org/wp-content/uploads/20211103204119/graph4-300x300.png

Expected Time Complexity: O(N). 
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 105

*/

class Solution {
public:

    void traverseLeft(Node* root, vector<int> &ans)
    {
        if((root == NULL) || (root->left == NULL && root->right == NULL))
        {
            return;
        }
        
        ans.push_back(root->data);
        
        if(root->left){
            traverseLeft(root->left, ans);
        }
        else{
            traverseLeft(root->right, ans);
        }
    }
    
    void traverseLeaf(Node* root, vector<int> &ans)
    {
        // base condition
        if(root == NULL){
            return;
        }
        
        if(root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
            return;
        }
        
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }

    void traverseRight(Node* root, vector<int> &ans)
    {
        if((root == NULL) || (root->left == NULL && root->right == NULL))
        {
            return;
        }
        
        if(root->right){
            traverseRight(root->right, ans);
        }
        else{
            traverseRight(root->left, ans);
        }
        
        // print data on returning time
        ans.push_back(root->data);
    }


    vector <int> boundary(Node *root)
    {
        //Your code here
        
        vector<int> ans;
        if(root == NULL)
        return ans;
        
        ans.push_back(root->data);
        
        // traverse left part
        traverseLeft(root->left, ans);
        
        // traverse Leaf Nodes
        
        // left subtree
        traverseLeaf(root->left, ans);
        // right subtree
        traverseLeaf(root->right, ans);
        
        // traverse right part
        traverseRight(root->right, ans);
        
        return ans;
    }
};
