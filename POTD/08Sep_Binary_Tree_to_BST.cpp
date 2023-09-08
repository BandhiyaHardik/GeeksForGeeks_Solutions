class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
   int idx;
    
    Node* binaryTreeToBST(Node* root) {
        if (root == nullptr)
            return nullptr;
        
        vector<int> al;
        order(al, root);
        sort(al.begin(), al.end());
        
        idx = 0;
        replace(al, root);
        
        return root;
    }
    
    void order(vector<int>& a, Node* r) {
        if (r == nullptr)
            return;
        else {
            order(a, r->left);
            a.push_back(r->data);
            order(a, r->right);
        }
    }
    
    void replace(vector<int>& a, Node* root) {
        if (root == nullptr)
            return;
        
        replace(a, root->left);
        
        root->data = a[idx++];
        
        replace(a, root->right);
    }
};
