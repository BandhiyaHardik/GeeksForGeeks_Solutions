class Solution
{
public:
    int absolute_diff(Node *root)
    {
        int minDiff = INT_MAX;
        int prevValue = -1;
        inorderTraversal(root, prevValue, minDiff);
        return minDiff;
    }

    void inorderTraversal(Node *root, int &prevValue, int &minDiff)
    {
        if (root == NULL)
            return;
        inorderTraversal(root->left, prevValue, minDiff);
        if (prevValue != -1)
            minDiff = min(minDiff, abs(root->data - prevValue));
        prevValue = root->data;
        inorderTraversal(root->right, prevValue, minDiff);
    }
};