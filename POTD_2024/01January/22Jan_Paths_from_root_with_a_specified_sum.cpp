class Solution
{
    public:
    vector<vector<int>> printPaths(Node *root, int sum)
    {
        vector<vector<int>> ans;
        vector<int> path;
        
        function<void(Node *, int)> dfs = [&](Node * node, int cur_sum) {
            if(!node)
                return;
            
            cur_sum += node -> key;
            path.push_back(node -> key);
            
            if(cur_sum == sum)
                ans.push_back(path);
            
            dfs(node -> left, cur_sum);
            dfs(node -> right, cur_sum);
            
            cur_sum -= node -> key;
            path.pop_back();
        };
        
        dfs(root, 0);
        
        return ans;
        
    }
};
