class Solution {
public:

    int dfs(int u, int dest, vector<vector<int> >& adj, vector<int>& dp) {

        if (u == dest) {
            return 1;
        }

        if (dp[u] != -1) {
            return dp[u];
        }

        int count = 0;

        for (int v : adj[u]) {
            count += dfs(v, dest, adj, dp);
        }

        return dp[u] = count;
    }
    int countPaths(vector<vector<int> >& edges, int V, int src, int dest) {

        vector<vector<int> > adj(V);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }

        vector<int> dp(1001, -1);

        return dfs(src, dest, adj, dp);
    }
};