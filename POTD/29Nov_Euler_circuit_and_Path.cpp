class Solution {
public:
  vector<int> vis;
	int isEulerCircuit(int V, vector<int>adj[]){
        vis = vector<int>(V + 1, 0);
        dfs(0, adj);

        for (int i = 0; i < V; i++) {
            if (vis[i] == 0 && adj[i].size() > 0)
                return 0; 
        }

        int cnt = 0;
        for (int i = 0; i < V; i++) {
            if ((adj[i].size() % 2) == 1)
                cnt++;
        }

        if (cnt > 2)
            return 0;

        else if (cnt == 2)
            return 1;
        else
            return 2; 
    }

    void dfs(int u, vector<int> adj[]) {
        vis[u] = 1;
        for (int v : adj[u]) {
            if (vis[v] == 0)
                dfs(v, adj);
        }
    }
};