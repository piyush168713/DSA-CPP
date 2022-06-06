#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
}
*first = NULL;

void create(int arr[], int n){
    int i;
    Node *t, *last;
    first = new Node;    // creates a new node and first will be pointing on that one
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    
}

void display(Node *p)
{
    while (p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
}

Node* detectLoop(Node *head)
{

    if(head == NULL)
    return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if(slow == fast){
            // cout<<"\nPresent at: "<<slow->next->data<<endl;
            return slow;
        }
    }
    return NULL;
}

Node* getStartingNode(Node *head)
{
    if(head == NULL)
    return NULL;

    Node* intersection = detectLoop(first);

    if(intersection == NULL)
        return NULL;

    Node* slow = head;

    while(slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;

}

Node* removeLoop(Node *head)
{
    if(head == NULL)
    return NULL;

    Node* startOfLoop = getStartingNode(first);
    if(startOfLoop == NULL)
        return NULL;
    Node* temp = startOfLoop;

    while(temp->next != startOfLoop)
    {
        temp = temp->next;
    }
    
    temp->next = NULL;
    return head;
}

int main(){

    Node *t1, *t2;

    int A[] = {10,20,30,40,50};
    create(A, 6);

    // creating a loop in Linked List
    t1 = first->next->next;         // points on 30
    t2 = first->next->next->next->next;         // points on 50
    t2->next = t1;           // 50 points on 30


    // cout<<detectLoop(first);

    if(detectLoop(first) != NULL){
        cout<<"\nLoop is Present.";
    }
    else
    {
        cout<<"\nNo Loop";
    }

    Node* loop = getStartingNode(first);
    cout<<"\nLoop starts at: "<<loop->data<<endl;

    removeLoop(first);
    display(first);
    
    return 0;
}
