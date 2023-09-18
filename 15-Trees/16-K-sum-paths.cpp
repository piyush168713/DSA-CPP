/*

Problem statement

K Sum Paths - GFG

Given a binary tree and an integer K. Find the number of paths in the tree which have their sum equal to K.
A path may start from any node and end at any node in the downward direction.


Example 1:

Input:      
Tree = 
          1                               
        /   \                          
       2     3
K = 3
Output: 2
Explanation:
Path 1 : 1 + 2 = 3
Path 2 : only leaf node 3
Example 2:

Input: 
Tree = 
           1
        /     \
      3        -1
    /   \     /   \
   2     1   4     5                        
        /   / \     \                    
       1   1   2     6    
K = 5                    
Output: 8
Explanation:
The following paths sum to K.  
3 2 
3 1 1 
1 3 1 
4 1 
1 -1 4 1 
-1 4 2 
5 
1 -1 5 

Your Task:  
You don't need to read input or print anything. Complete the function sumK() which takes root node and integer K as input 
parameters and returns the number of paths that have sum K. Since the answer may be very large, compute it modulo 109+7.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(Height of Tree)


Constraints:
1 ≤ N ≤ 105
-10^5 ≤ Node Value ≤ 10^5
-10^9 ≤ k ≤ 10^9

*/

void solve(Node* root, int k, int &count, vector<int> path)
    {
        if(root == NULL){
            return;
        }
        
        path.push_back(root->data);
        // left
        solve(root->left, k, count, path);
        // right
        solve(root->right, k, count, path);
        // check for k sum
        int size = path.size();
        int sum = 0;
        for(int i = size-1; i>=0; i--){
            sum += path[i];
            if(sum == k){
                count++;
            }
        }
        // we are passing path as pass by value, so at returning time added value gets automagically removed...
        // path.pop_back();   
    }
  
    int sumK(Node *root,int k)
    {
        vector<int> path;
        int count = 0;
        solve(root, k, count, path);
        return count;
    }
