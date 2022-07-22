/*

Problem Statement

ZigZag Tree Traversal - GFG

Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.


Example 1:

Input:
        3
      /   \
     2     1
Output:
3 1 2
Example 2:

Input:
           7
        /     \
       9       7
     /  \     /   
    8    8   6     
   /  \
  10   9 
Output:
7 7 9 8 8 6 9 10 
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function zigZagTraversal() which takes the 
root node of the Binary Tree as its input and returns a list containing the node values as they appear in the Zig-Zag Level-Order Traversal of the Tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

 
Constraints:
1 <= N <= 104

*/

vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int> result;
    	
    	if(root == NULL){
    	    return result;
    	}
    	
    	queue<Node*> q;
    	q.push(root);
    	
    	bool leftToRight = true;
    	
    	while(!q.empty())
    	{
    	    int size = q.size();
    	    vector<int> ans(size);
    	    
    	    // level process
    	    for(int i = 0; i < size; i++){
    	        Node* frontNode = q.front();
    	        q.pop();
    	        
    	        // normal insert or reverse insert
    	        int index = leftToRight ? i : size-i-1;
    	        ans[index] = frontNode->data;
    	        
    	        if(frontNode->left)
    	        q.push(frontNode->left);
    	        
    	        if(frontNode->right)
    	        q.push(frontNode->right);
    	    }
    	    
    	    // change the direction
    	    leftToRight = !leftToRight;
    	    
    	    for(auto i : ans){
    	        result.push_back(i);
    	    }
    	}
    	return result;
    }
