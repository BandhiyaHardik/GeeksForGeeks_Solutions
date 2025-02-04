class Solution {
  public:
    int height(Node* root,int &ans){
        if(!root) return 0;
        int LH=height(root->left,ans);
        int RH=height(root->right,ans);
        ans=max(ans,LH+RH);
        return max(LH,RH)+1;
        }
    int diameter(Node* root) {

        int ans=0;
        height(root,ans);
        return ans;
    }
};