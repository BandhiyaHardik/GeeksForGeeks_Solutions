class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        vector<vector<int>> g(n);
        vector<int> in(n, 0);
        
        for(int i = 0; i < m; i++){
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);
            ++in[prerequisites[i][0]];
        }
        
        queue<int> q;
        vector<int> ans;
        
        for(int i = 0; i < n; i++){
            if(in[i] == 0){
                q.push(i);
                ans.push_back(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto child : g[node]){
                --in[child];
                
                if(in[child] == 0){
                    q.push(child);
                    ans.push_back(child);
                }
            }
        }
        
        if(ans.size() < n)
            ans.clear();
            
        return ans;
    }
};