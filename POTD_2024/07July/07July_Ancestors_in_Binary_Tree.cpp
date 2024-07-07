class Solution {
  public:
    vector<int> ans;
    void help(Node *root,int target,vector<int> &temp){
        if(!root)return;
        if(root->data==target){
            ans=temp;
            return;
        }
        temp.push_back(root->data);
        help(root->left,target,temp);
        help(root->right,target,temp);
        temp.pop_back();
    }
    // Function should return all the ancestor of the target node
    vector<int> Ancestors(struct Node *root, int target) {

        vector<int> temp;
        help(root,target,temp);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};