class Solution {
  public:
    // Return the Kth smallest element in the given BST
    void inorder(Node* root,int &k,int &ans){
        if(!root)return ;
        inorder(root->left,k,ans);
        k--;
        if(k==0){
            ans=root->data;
            return ;
        }
        inorder(root->right,k,ans);
    }
    int kthSmallest(Node *root, int k) {

        int ans=-1;
        inorder(root,k,ans);
        return ans;
      
    }
};