class Solution {
  public:
    void dfs(int u, int parent, vector<int> adj[], vector<int>& disc,
             vector<int>& low, vector<bool>& visited, vector<bool>& isAP, int& time) {
        
        visited[u] = true;
        disc[u] = low[u] = time++;
        int children = 0;

        for (int v : adj[u]) {
            if (!visited[v]) {
                children++;
                dfs(v, u, adj, disc, low, visited, isAP, time);
                low[u] = min(low[u], low[v]);

                if (parent == -1 && children > 1)
                    isAP[u] = true;

                if (parent != -1 && low[v] >= disc[u])
                    isAP[u] = true;
            }
            else if (v != parent) {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> disc(V, -1), low(V, -1);
        vector<bool> visited(V, false), isAP(V, false);
        int time = 0;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                dfs(i, -1, adj, disc, low, visited, isAP, time);
            }
        }

        vector<int> result;
        for (int i = 0; i < V; ++i) {
            if (isAP[i])
                result.push_back(i);
        }

        if (result.empty()) return {-1};
        return result;
    }
};
