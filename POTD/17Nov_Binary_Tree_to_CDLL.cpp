class Solution
{
  public:
    //Function to convert binary tree into circular doubly linked list.
   Node *head=NULL, *prev=NULL;
    Node *bTreeToCList(Node *root)
    {
    inorder (root); 

    head->left=prev; prev->right=head;
    return head;
    }
    void inorder(Node* curr)
    {
        if(curr==NULL)
        return;
        
        inorder (curr->left);
        
        if (head==NULL)
        head=prev=curr;
        
        else{
        prev->right=curr;
        curr->left=prev;
        }
        prev=curr;
        inorder (curr->right);
    }
};