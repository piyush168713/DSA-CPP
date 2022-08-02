/*

Problem Statement

Construct Tree from Inorder & Preorder - GFG


Given 2 Arrays of Inorder and preorder traversal. Construct a tree and print the Postorder traversal. 

Example 1:

Input:
N = 4
inorder[] = {1 6 8 7}
preorder[] = {1 6 7 8}
Output: 8 7 6 1
Example 2:

Input:
N = 6
inorder[] = {3 1 4 0 5 2}
preorder[] = {0 1 3 4 2 5}
Output: 3 4 1 5 2 0
Explanation: The tree will look like
       0
    /     \
   1       2
 /   \    /
3    4   5
Your Task:
Your task is to complete the function buildTree() which takes 3 arguments(inorder traversal array, preorder traversal array, 
and size of tree n) and returns the root node to the tree constructed. You are not required to print anything and a new line is added 
automatically (The post order of the returned tree is printed by the driver's code.)

Expected Time Complexity: O(N*N).
Expected Auxiliary Space: O(N).

Constraints:
1<=Number of Nodes<=1000

*/

    int findPosition(int in[], int element, int n)
    {
        for(int i = 0; i < n; i++){
            if(in[i] == element)
            return i;
        }
        return -1;
    }
    
    Node* solve(int in[], int pre[], int &index, int inOrderStart, int inOrderEnd, int n)
    {
        // base case
        if(index >= n || inOrderStart > inOrderEnd){
            return NULL;
        }
        
        int element = pre[index++];
        Node* root = new Node(element);
        int position = findPosition(in, element, n);
        
        // recursive calls
        root->left = solve(in, pre, index, inOrderStart, position-1, n);
        root->right = solve(in, pre, index, position+1, inOrderEnd, n);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preOrderIndex = 0;
        Node* ans = solve(in, pre, preOrderIndex, 0, n-1, n);
        // here 0 -> index of inOrder start
        // n-1 -> index of inorder end
        return ans;
    }
