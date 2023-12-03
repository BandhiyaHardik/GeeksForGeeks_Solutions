class Solution
{
public:
    int countPairs(Node* root1, Node* root2, int x)
    {
        unordered_map<int, int> f;
        int ans = 0;
        
        function<void(Node*)> dfs1 = [&](Node * node) {
            if(!node)
                return;
                
            ++f[node -> data];
            
            dfs1(node -> left);
            dfs1(node -> right);
        };
        
        dfs1(root1);
        
        function<void(Node *)> dfs2 = [&](Node * node) {
            if(!node)
                return;
                
            if(f.count(x - (node -> data)))
                ans += f[x - (node -> data)];
                
            dfs2(node -> left);
            dfs2(node -> right);
        };
        
        dfs2(root2);
        
        return ans;
    }
};