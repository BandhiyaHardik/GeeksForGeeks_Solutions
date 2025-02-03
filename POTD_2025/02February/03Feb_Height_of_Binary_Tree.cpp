class Solution {
  public:
    // Function to find the height of a binary tree.
    int height(Node* node) {

        if(!node) return -1;
        return max(height(node ->left),height(node ->right)) + 1;
        
    }
};