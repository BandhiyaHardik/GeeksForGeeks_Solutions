class Node {
public:
    int v;
    int w;

    Node(int v, int w) : v(v), w(w) {}
};
class Solution {
  public:
     vector<int> shortestPath(int V,int M, vector<vector<int>>& edges){
          vector<vector<Node>> adj(V + 1);

        for (int i = 0; i <= V; i++) {
            adj[i] = vector<Node>();
        }

        for (vector<int>& arr : edges) {
            adj[arr[0]].push_back(Node(arr[1], arr[2]));
        }

        // Topo sort
        vector<bool> vis(V, false);
        stack<int> st;
        for (int u = 0; u < V; u++) {
            if (!vis[u])
                dfs(adj, u, st, vis);
        }

        vector<int> dist(V, INT_MAX);
        dist[0] = 0;

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            if (dist[u] != INT_MAX) {
                for (Node& curr : adj[u]) {
                    if (dist[curr.v] >= dist[u] + curr.w) {
                        dist[curr.v] = dist[u] + curr.w;
                    }
                }
            }
        }

        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }

        return dist;
    }

    void dfs(vector<vector<Node>>& adj, int u, stack<int>& st, vector<bool>& vis) {
        vis[u] = true;
        for (Node& nei : adj[u]) {
            if (!vis[nei.v])
                dfs(adj, nei.v, st, vis);
        }
        st.push(u);
    }
};