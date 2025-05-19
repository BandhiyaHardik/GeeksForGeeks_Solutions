class Solution {
public:
    void findPreSucHelper(Node* root, Node*& pre, Node*& suc, int key) {
        if (!root) return;

        if (root->data == key) {
            if (root->left) {
                Node* temp = root->left;
                while (temp->right)
                    temp = temp->right;
                pre = temp;
            }
            if (root->right) {
                Node* temp = root->right;
                while (temp->left)
                    temp = temp->left;
                suc = temp;
            }
        } else if (key < root->data) {
            suc = root;
            findPreSucHelper(root->left, pre, suc, key);
        } else {
            pre = root;
            findPreSucHelper(root->right, pre, suc, key);
        }
    }

    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = NULL;
        Node* suc = NULL;
        findPreSucHelper(root, pre, suc, key);
        return {pre, suc};
    }
};
