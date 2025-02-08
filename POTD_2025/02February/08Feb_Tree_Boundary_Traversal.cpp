class Solution {
    public:
      void left(Node *root,vector<int>&ans){
          if(!root) return;
          if(root->left){
              ans.push_back(root->data);
              left(root->left,ans);
          }
          else if(root->right){
              ans.push_back(root->data);
              left(root->right,ans);
          }
      }
      
      void bottom(Node *root,vector<int>&ans){
          if(!root) return ;
          if(root->left==NULL && root->right==NULL){
              ans.push_back(root->data);
              return;
              
          }
          if(root->left) bottom (root->left,ans);
          if(root->right) bottom (root->right,ans);
      }
      void right(Node *root,vector<int>&ans){
          if(!root) return;
          if(root->right){
              right(root->right,ans);
              ans.push_back(root->data);
              
          }
          else if(root->left){
              
              right(root->left,ans);
              ans.push_back(root->data);
          }
      }
      vector<int> boundaryTraversal(Node *root) {

          vector<int>ans;
          if(!root) return ans;
          ans.push_back(root->data);
          left(root->left,ans);
          bottom(root->left,ans);
          bottom(root->right,ans);
          right(root->right,ans);
          return ans;
      }
};