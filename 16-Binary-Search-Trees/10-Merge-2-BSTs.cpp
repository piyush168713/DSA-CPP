// Problem Statement

// Merge Two BSTs - Codestudio

// Link - https://www.codingninjas.com/codestudio/problems/h_920474

// Approach 1 - By using Arrsys

void inorder(TreeNode<int> *root, vector<int> &in)
{
    if(root == NULL)
        return;
    
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

vector<int> mergeArrays(vector<int> &a, vector<int> &b)
{
    vector<int> ans(a.size() + b.size());
    int i = 0, j = 0;
    int k = 0;
    
    while(i < a.size() && j < b.size()){
        if(a[i] < b[j]){
            ans[k++] = a[i];
            i++;
        }
        else{
            ans[k++] = b[j];
            j++;
        }
    }
    
    while(i < a.size()){
        ans[k++] = a[i];
        i++;
    }
    
    while(j < b.size()){
        ans[k++] = b[j];
        j++;
    }
    return ans;
}

TreeNode<int>* inorderToBst(int s, int e, vector<int> in)
{
    // base case
    if(s > e)
        return NULL;
    
    int mid = (s+e)/2;
    TreeNode<int>* root = new TreeNode<int>(in[mid]);
    root->left = inorderToBst(s, mid-1, in);
    root->right = inorderToBst(mid+1, e, in);
    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    
    // step 1: store inorder
    vector<int> bst1, bst2;
    inorder(root1, bst1);   // m size
    inorder(root2, bst2);   // n size
    
    // step 2: Merge 2 sorted arrays
    vector<int> mergeArray = mergeArrays(bst1, bst2);
    
    // step 3: inorderToBst() -- Use inorder arrays to build BST
    int s = 0, e = mergeArray.size()-1;
    return inorderToBst(s, e, mergeArray);
    
    // T.C - O(m+n)
    // S.C - O(m+n)
}




// Approach 2 - By using Linked List

/*
void changeIntoSortedLL(TreeNode<int>* root, TreeNode<int>* &head)
{
    if(root == NULL)
        return;
    
    changeIntoSortedLL(root->right, head);
    root->right = head;
    if(head != NULL)
        head->left = root;
    head = root;
    
    changeIntoSortedLL(root->left, head);
}

TreeNode<int>* mergeLinkedList(TreeNode<int>* head1, TreeNode<int>* head2)
{
    TreeNode<int>* head = NULL;
    TreeNode<int>* tail = NULL;
    
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data < head2->data)
        {
            if(head == NULL)
            {
                head = head1;
                tail = head1; 
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if(head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    // checks for remaining element
    while(head1 != NULL){
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    
    while(head2 != NULL){
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head1 = head2->right;
    }
    return head;
}

int countNode(TreeNode<int>* head){
    int count = 0;
    TreeNode<int>* temp = head;
    while(temp != NULL){
        count++;
        temp = temp->right;
    }
    return count;
}

TreeNode<int>* sortedLLToBst(TreeNode<int>* &head, int n)
{
    // base case
    if(n <= 0 || head == NULL){
        return NULL;
    }
    TreeNode<int>* left = sortedLLToBst(head, n/2);
    TreeNode<int>* root = head;
    root->left = left;
    head = head-> right;
    root->right = sortedLLToBst(head, n - n/2 - 1);
    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    
    // step 1: change into sorted LL
    TreeNode<int>* head1 = NULL;
    changeIntoSortedLL(root1, head1);
    head1->left = NULL;
    
    TreeNode<int>* head2 = NULL;
    changeIntoSortedLL(root2, head2);
    head2->left = NULL;
    
    // step 2: Merge 2 sorted LL
    TreeNode<int>* head = mergeLinkedList(head1, head2);
    
    // step 3: change sorted LL to BST
    return sortedLLToBst(head, countNode(head));
}
*/
