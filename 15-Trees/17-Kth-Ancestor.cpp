/*

Problem Statement

Kth Ancestor in a Tree - GFG

Given a binary tree of size  N, a node and a positive integer k., Your task is to complete the function kthAncestor(), 
the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.

Example 1:
link - https://contribute.geeksforgeeks.org/wp-content/uploads/reverse.jpg

Input:
     K = 2
     Node = 4
Output: 1
Explanation:
Since, K is 2 and node is 4, so we
first need to locate the node and
look k times its ancestors.
Here in this Case node 4 has 1 as his
2nd Ancestor aka the Root of the tree.
 

Example 2:

Input:
k=1 
node=3
      1
    /   \
    2     3

Output:
1
Explanation:
K=1 and node=3 ,Kth ancestor of node 3 is 1.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

 

Constraints:
1<=N<=10^4
1<= K <= 100

*/

Node* solve(Node* root, int &k, int node)
{
    if(root == NULL){
        return NULL;
    }
    
    if(root->data == node){
        return root;
    }
    
    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);
    
    if(leftAns != NULL && rightAns == NULL)
    {
        k--;
        if(k <= 0){
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    
    if(leftAns == NULL && rightAns != NULL)
    {
        k--;
        if(k <= 0){
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}

int kthAncestor(Node *root, int k, int node)
{
    // Code here
    Node* ans = solve(root, k, node);
    if(ans == NULL || ans->data == node)
        return -1;
    else
        return ans->data;
}
