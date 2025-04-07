class Solution {
  public:
    bool dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&currvis){
        vis[node]=1;
        currvis[node]=1;
        for(auto it: adj[node]){
            if(vis[it]==0){
            if (dfs(it,adj,vis,currvis)) return true;}
            else if(currvis[it]==1) return true;
        }
        currvis[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {

        vector<int>adj[V];
        vector<int>vis(V,0);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        for(int i=0;i<V;i++){
                vector<int>currvis(V,0);
                if(dfs(i,adj,vis,currvis)) return true;
         }
         return false;
    }
};