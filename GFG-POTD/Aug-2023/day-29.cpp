// Delete nodes having greater value on right

class Solution
{
    /*
    Node* reverse(Node* &head){
       Node* pre = NULL;
       Node* curr = head;
       Node* forw = NULL;
       while(curr){
           forw = curr -> next;
           curr -> next = pre;
           pre = curr;
           curr = forw;
           head = pre;
        }
        return head;
    }
    
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        reverse(head);
        Node* prev = head;
        Node* curr = head->next;
        
        while(curr){
            if(prev->data > curr->data){
                prev->next = curr->next;
                curr = prev->next;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        reverse(head);
        return head;
    }
    */
    
    public:
    Node *compute(Node *head){
        Node* temp = head;
        
        while(temp->next != NULL){
            if(temp->next->data > temp->data){
                temp->data = temp->next->data;
                Node* curr = temp->next;
                temp->next = temp->next->next;
                delete(curr);
                temp = head;
            }
            else{
                temp = temp->next;
            }
        }
        return head;
    }
};
