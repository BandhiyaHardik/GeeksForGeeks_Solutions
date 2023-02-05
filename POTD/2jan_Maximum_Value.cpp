class Solution {
  public:
    vector<int> maximumValue(Node* root) {
    // result vector to store the maximum value at each level
    vector<int> result;

    // base case: empty tree
    if (!root) {
        return result;
    }

    // queue to store nodes at each level
    queue<Node*> q;
    q.push(root);

    // continue BFS until queue is empty
    while (!q.empty()) {
        // number of nodes at current level
        int size = q.size();
        // maximum value at current level
        int maximumVal = INT_MIN;

        // traverse all nodes at current level
        for (int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();
            maximumVal = max(maximumVal, node->data);
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }

        // add maximum value at current level to result
        result.push_back(maximumVal);
    }

    return result;
}

};