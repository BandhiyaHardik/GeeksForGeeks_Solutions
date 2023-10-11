class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
       return checkBalance(root) != -1;
    }


    int checkBalance(Node* root) {
        if (root == nullptr) {
            return 0;
        }

        int lht = checkBalance(root->left);
        if (lht == -1) {
            return -1;
        }

        int rht = checkBalance(root->right);
        if (rht == -1) {
            return -1; 
        }

        int heightDiff = abs(lht - rht);
        if (heightDiff > 1) {
            return -1; 
        }

        return 1 + max(lht, rht); 
    }
};