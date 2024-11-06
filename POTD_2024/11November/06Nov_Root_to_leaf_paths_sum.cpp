class Solution {
  public:
    int treePathsSum(Node *root) {
        return treePathsSumHelper(root, 0);
    }

  private:
    int treePathsSumHelper(Node *node, int currentSum) {

        if (!node) return 0;

        currentSum = currentSum * 10 + node->data;

        if (!node->left && !node->right) return currentSum;

        int leftSum = treePathsSumHelper(node->left, currentSum);
        int rightSum = treePathsSumHelper(node->right, currentSum);

        return leftSum + rightSum;
    }
};
