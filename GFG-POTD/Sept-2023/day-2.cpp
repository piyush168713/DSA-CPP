// Leaf under budget

class Solution
{
public:
    int getCount(Node *root, int k)
    {
        //code here
        queue<pair<Node*, int>> q;
        q.push({root,1});
        int cnt = 0;
        
        while(!q.empty()){
            Node* node = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if(node->left)
                q.push({node->left, level+1});
            
            if(node->right)
                q.push({node->right, level+1});
            
            if(node->left == NULL && node->right == NULL && k >= level){
                k -= level;
                cnt++;
            }
        }
        return cnt;
    }
};
