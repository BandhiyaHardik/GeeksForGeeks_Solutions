class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
        function<int(Node *)> dfs = [&](Node * node) -> int {
            if(!node or (!(node -> left) and !(node -> right)))
                return 1;
                
            int left = dfs(node -> left);
            int right = dfs(node -> right);
            
            int sum = (node -> left ? node -> left -> data : 0) + (node -> right ? node -> right -> data : 0);
            
            return left and right and (node -> data == sum);
        };
        
        return dfs(root);
    }
};