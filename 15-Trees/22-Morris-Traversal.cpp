/*

Problem Statement

Flatten binary tree to linked list - GFG
Solving this problem using Morris Traversal

Given a binary tree, flatten it into linked list in-place. Usage of auxiliary data structure is not allowed. After flattening, left of each node should point to NULL and right should contain next node in preorder.

Example 1:

Input : 
          1
        /   \
       2     5
      / \     \
     3   4     6
Output :
1 2 3 4 5 6 
Explanation: 
After flattening, the tree looks 
like this
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6 
Here, left of each node points 
to NULL and right contains the 
next node in preorder.The inorder 
traversal of this flattened tree 
is 1 2 3 4 5 6.
Example 2:

Input :
        1
       / \
      3   4
         /
        2
         \
          5 
Output : 
1 3 4 2 5  
Explanation : 
After flattening, the tree looks 
like this 
     1
      \
       3
        \
         4
          \
           2
            \ 
             5 
Here, left of each node points 
to NULL and right contains the 
next node in preorder.The inorder 
traversal of this flattened tree 
is 1 3 4 2 5.
Your task:
You don't have to read input or print anything. Your task is to complete the function flatten() which takes 
the root of the tree and flattens the tree into a linkes list without using any auxiliary space.
Note : The driver code prints the inorder traversal of the flattened binary tree.
 
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)
 
Constraints :
1<=n<=10^5

*/

void flatten(Node *root)
    {
        //code here
        Node* curr = root;
        while(curr != NULL)
        {
            if(curr->left)
            {
                Node* pred = curr->left;
                while(pred->right)
                    pred = pred->right;
            
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
        
    }
