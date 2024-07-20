class Solution {
  public:
    Node *RemoveHalfNodes(Node *root) {

        if(!root)return NULL;
        root->left = RemoveHalfNodes(root->left);
        root->right = RemoveHalfNodes(root->right);
        if(!root->left and root->right)return root->right;
        if(root->left and !root->right)return root->left;
        return root;
    }
};