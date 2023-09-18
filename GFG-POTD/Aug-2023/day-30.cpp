// Delete a Node in Single Linked List

Node* deleteNode(Node *head,int x)
{
    //Your code here
    if(x == 1)
        return head->next;
    
    Node* temp = head;
    
    while(x-- > 2){
        temp = temp->next;
    }
    
    temp->next = temp->next->next;
    return head;
}
