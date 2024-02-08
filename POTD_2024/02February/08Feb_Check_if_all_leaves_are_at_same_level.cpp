class Solution{
  public:
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        set<int> values;
        
        function<void(Node *, int)> dfs = [&](Node * node, int d) {
            if(!node)
                return;
                
            dfs(node -> left, d + 1);
            dfs(node -> right, d + 1);
            
            if(!(node -> left) and !(node -> right))
                values.insert(d);
        };
        
        dfs(root, 0);
        
        return values.size() == 1;
    }
};
