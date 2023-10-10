class Solution
{
private:

public:

    vector <int> KDistanceNodes(Node* root, int tar , int k)
    {
        Node* target = findTarget(root, tar);
        unordered_map<Node*, Node*> parent;
        markParent(root, parent);

        vector<int> res = fun(parent, target, k);

        return res;
    }

      void markParent(Node* root, unordered_map<Node*, Node*>& parent) {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr->left != nullptr) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right != nullptr) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

     vector<int> fun(unordered_map<Node*, Node*>& parent, Node* target, int k) {
        queue<Node*> q; 
        unordered_set<Node*> vis; 

        q.push(target);
        vis.insert(target);
        int count = 0;
        while (!q.empty()) {
            int size = q.size();

            if (count == k) break;
            count++;

            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();
                if (curr->left != nullptr && vis.find(curr->left) == vis.end()) {
                    q.push(curr->left);
                    vis.insert(curr->left);
                }

                if (curr->right != nullptr && vis.find(curr->right) == vis.end()) {
                    q.push(curr->right);
                    vis.insert(curr->right);
                }

                if (parent.find(curr) != parent.end() && vis.find(parent[curr]) == vis.end()) {
                    q.push(parent[curr]);
                    vis.insert(parent[curr]);
                }
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            ans.push_back(curr->data);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
     Node* findTarget(Node* root, int target) {
        if (root == nullptr || root->data == target)
            return root;

        Node* left = findTarget(root->left, target);
        Node* right = findTarget(root->right, target);

        if (left != nullptr)
            return left;

        return right;
    }
};