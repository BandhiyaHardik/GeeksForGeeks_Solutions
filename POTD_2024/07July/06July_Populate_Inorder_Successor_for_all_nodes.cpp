class Solution {
  public:

    Node *nxt=NULL;
    void populateNext(Node *root) {

        if(!root)return;
        populateNext(root->right);
        root->next=nxt;
        nxt=root;
        populateNext(root->left);
    }
};