class Solution {
  public:
    vector<int> postOrder(Node* root) {
        vector<int> ans;
        if (!root) return ans;
        stack<Node*> st1, st2;
        st1.push(root);
        while (!st1.empty()) {
            Node* curr = st1.top();
            st1.pop();
            st2.push(curr);
            if (curr->left) st1.push(curr->left);
            if (curr->right) st1.push(curr->right);
        }
        while (!st2.empty()) {
            ans.push_back(st2.top()->data);
            st2.pop();
        }
        return ans;
    }
};
