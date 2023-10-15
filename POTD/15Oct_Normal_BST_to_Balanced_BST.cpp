class Solution{
    vector<Node*> al;
    public:
    // Your are required to complete this function
    // function should return root of the modified BST
    Node* buildBalancedTree(Node* root)
    {
        inOrder(root);
        return toBalance(0, al.size() - 1);
    }
    Node* toBalance(int l, int r) 
    {
        if (l > r) return nullptr;

        int m = (l + r) / 2;
        Node* root = al[m];

        root->left = toBalance(l, m - 1);
        root->right = toBalance(m + 1, r);

        return root;
    }

    void inOrder(Node* root) 
    {
        if (root != nullptr) 
        {
            inOrder(root->left);
            al.push_back(root);
            inOrder(root->right);
        }
    }
};
