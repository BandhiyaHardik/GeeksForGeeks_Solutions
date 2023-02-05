class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int sum(Node *node){
        if(node==NULL)
            return 0;
        int d=node->data;
        node->data=sum(node->left)+sum(node->right);
        return node->data+d;
    }
    void toSumTree(Node *node)
    {
        // Your code here
        sum(node);
    }
};

