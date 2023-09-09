class Solution
{
    public:
    int kthLargest(Node *root, int K)
    {
       Node* ans = morris(root, K);
        return (ans != nullptr) ? ans->data : -1;
    }

    Node* morris(Node* curr, int k) {
        while (curr != nullptr) {
            if (curr->right == nullptr) {
                if (k == 1)
                    return curr;
                k--;
                curr = curr->left;
            } else {
                Node* prev = curr->right;
                while (prev->left != nullptr && prev->left != curr)
                    prev = prev->left;

                if (prev->left == nullptr) {
                    prev->left = curr; 
                    curr = curr->right;
                } else {
                    prev->left = nullptr; 
                    if (k == 1)
                        return curr;
                    k--;
                    curr = curr->left;
                }
            }
        }
        return nullptr;
    }
};