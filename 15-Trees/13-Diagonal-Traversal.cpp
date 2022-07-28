/*

Problem Statement

Diagonal Traversal of Binary Tree - GFG

Given a Binary Tree, print the diagonal traversal of the binary tree.

Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.

Example 1:

Input :
            8
         /     \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4     7 13
Output : 8 10 14 3 6 7 13 1 4

Explanation:
link - https://contribute.geeksforgeeks.org/wp-content/uploads/diagonal.jpg

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
Here N is number of nodes.

Constraints:
1 <= Number of nodes<= 10^5
1 <= Data of a node<= 10^5

*/

vector<int> diagonal(Node *root)
{
   // your code here
   vector<int> ans;
   if(root == NULL){
       return ans;
   }
   
   queue<Node*> q;
   q.push(root);
   
   while(!q.empty())
   {
       Node* temp = q.front();
       q.pop();
       ans.push_back(temp->data);
       while(!temp == NULL){
           if(temp->left != NULL){
               q.push(temp->left);
           }
           
           temp = temp->right;
           
           if(temp != NULL){
               ans.push_back(temp->data);
           }
       }
   }
   return ans;
}
