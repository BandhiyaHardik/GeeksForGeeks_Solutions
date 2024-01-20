class Solution
{
    public:
    int distributeCandy(Node* root)
    {
        map<Node *, int> subtree, candies;
        int ans = 0;
        
        function<void(Node *)> dfs1 = [&](Node * node) {
            if(!node)
                return;
                
            subtree[node] = 1;
            candies[node] = node -> key;
            
            dfs1(node -> left);
            dfs1(node -> right);
            
            subtree[node] += subtree[node -> left] + subtree[node -> right];
            candies[node] += candies[node -> left] + candies[node -> right];
        };
        
        dfs1(root);
        
        function<void(Node *)> dfs2 = [&](Node * node) {
            if(!node)
                return;
            
            int leftextra = candies[node -> left] - subtree[node -> left];
            
            int rightextra = candies[node -> right] - subtree[node -> right];
            
            ans += abs(leftextra) + abs(rightextra);
            
            dfs2(node -> left);
            dfs2(node -> right);
        };
        
        dfs2(root);
        
        return ans;
    }
};