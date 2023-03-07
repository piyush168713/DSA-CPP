// Max Level Sum in Binary Tree

// Link - https://practice.geeksforgeeks.org/problems/4b7ff87c26ed23b3f63c25c611690213d44fb6aa/1

class Solution{
  public:
    /*You are required to complete below method */
    int maxLevelSum(Node* root) {
        // Your code here
        queue<Node*> q;
        q.push(root);
        int maxSum = INT_MIN;
        
        while(!q.empty()){
            int size = q.size();
            int levelSum = 0;
            
            for(int i = 0; i < size; i++){
                Node* temp = q.front();
                q.pop();
                
                levelSum += temp->data;
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            maxSum = max(maxSum, levelSum);
        }
        return maxSum;
    }
};
