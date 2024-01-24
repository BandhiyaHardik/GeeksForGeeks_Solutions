class Solution {
public:
    bool isTree(int n, int m, vector<vector<int>>& edges) {
        if (m != n - 1)
            return false;

        vector<bool> vis(n, false);
        vector<vector<int>> adj(n, vector<int>());

        for (int i = 0; i < m; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        int cnt = 1;
        int st = 0;
        queue<int> q;
        vis[st] = true;
        q.push(st);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int nei : adj[curr]) {
                if (!vis[nei]) {
                    vis[nei] = true;
                    cnt++;
                    q.push(nei);
                }
            }
        }

        return cnt == n;
    }
};