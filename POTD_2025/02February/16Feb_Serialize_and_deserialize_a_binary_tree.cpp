class Solution {
  public:
    // Function to serialize a tree and return a list containing nodes of tree.
    void preorder(Node *root,vector<int>&ans){
        if(!root){
            ans.push_back(-1);
            return;
        }
        ans.push_back(root->data);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    vector<int> serialize(Node *root) {
        vector<int>ans;
        preorder(root,ans);
        return ans;
    }
    int i=0;
    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &arr) {

        int val=arr[i];
        i++;
        if(val==-1) return NULL;
        Node *nn=new Node(val);
        nn->left=deSerialize(arr);
        nn->right=deSerialize(arr);
        return nn;
    }
};