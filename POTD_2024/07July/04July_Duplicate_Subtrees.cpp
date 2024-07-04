class Solution {
  public:
    string help(Node *root,vector<Node*> &ans,unordered_map<string,int> &mm){
        if(!root)return "#";
        string temp = to_string(root->data)+' '+help(root->left,ans,mm)+' '+help(root->right,ans,mm);
        if(mm[temp]==1)ans.push_back(root);
        mm[temp]++;
        return temp;
        
    }
    vector<Node*> printAllDups(Node* root) {

        vector<Node*> ans;
        unordered_map<string,int> mm;
        help(root,ans,mm);
        return ans;
    }
};