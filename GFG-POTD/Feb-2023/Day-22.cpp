// Connect Nodes at Same Level

// Link - https://practice.geeksforgeeks.org/problems/95423710beef46bd66f8dbb48c510b2c320dab05/1

class Solution{
    public:
    void connect(Node *root)
    {
        if(root == NULL)
            return;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        Node* prev = NULL;
        
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            
            if(curr == NULL && !q.empty()){
                q.push(NULL);
            }
            
            if(prev != NULL)
                prev->nextRight = curr;
            if(curr != NULL){
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            prev = curr;
        }
    }    
};
