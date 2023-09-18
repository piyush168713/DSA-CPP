// Reverse both parts

// Link - https://practice.geeksforgeeks.org/problems/bae68b4d6a2a77fb6bd459cf7447240919ebfbf5/1

class Solution
{
  public:
   
    Node *reverse(Node *head, int k)
    {
        // code here
        if(!head || !head->next) return head;
        
        Node *prev=NULL,*cur=head,*nxt;
        
        while(k-- && cur!=NULL)
        {
            nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
            // nxt=nxt->next;
        }
        
        Node*prev2=NULL;
        Node* hd=head;
       
        while(cur!=NULL)
        {
             nxt=cur->next;
            cur->next=prev2;
            prev2=cur;
            cur=nxt;  
        }
        
        hd->next=prev2;
        
        return prev;
    }
};
