// Remove duplicate element from sorted Linked List

Node *removeDuplicates(Node *head)
{
    // your code goes here
    if(head == NULL){
        return NULL;
    }
    
    Node* temp = head;
    while(temp->next != NULL){
        if(temp->data != temp->next->data){
            temp = temp->next;
        }
        else if(temp->data == temp->next->data){
            Node* temp1 = temp->next;
            temp->next = temp->next->next;
            delete temp1;
        }
    }
    return head;
}
