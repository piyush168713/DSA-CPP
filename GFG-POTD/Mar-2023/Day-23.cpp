// BST Maximum Difference

// Link - https://practice.geeksforgeeks.org/problems/e841e10213ddf839d51c2909f1808632a19ae0bf/1

class Solution{
public:
    int solve(Node* root){
        if(root == NULL){
            return 0;
        }
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        if(!root->left){
            return root->data + right;
        }
        
        else if(!root->right){
            return root->data + left;
        }
        
        return root->data + min(left, right);
    }

    int maxDifferenceBST(Node *root,int target){
        // Code here
        Node* temp = root;
        int sum = 0;
        
        while(temp){
            if(temp->data == target){
                int mini = solve(temp) - target;
                return sum - mini;
            }
            else if(temp->data < target){
                sum += temp->data;
                temp = temp->right;
            }
            else{
                sum += temp->data;
                temp = temp->left;
            }
        }
        return -1;
    }
};
