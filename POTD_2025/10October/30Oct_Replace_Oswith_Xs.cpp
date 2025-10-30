class Solution {
  public:
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis, int n, int m) {
        vis[i][j] = 1;
        int di[] = {-1, 0, 1, 0};
        int dj[] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (ni >= 0 && nj >= 0 && ni < n && nj < m && !vis[ni][nj] && grid[ni][nj] == 'O')
                dfs(ni, nj, grid, vis, n, m);
        }
    }

    void fill(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 'O' && !vis[0][j]) dfs(0, j, grid, vis, n, m);
            if (grid[n - 1][j] == 'O' && !vis[n - 1][j]) dfs(n - 1, j, grid, vis, n, m);
        }
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 'O' && !vis[i][0]) dfs(i, 0, grid, vis, n, m);
            if (grid[i][m - 1] == 'O' && !vis[i][m - 1]) dfs(i, m - 1, grid, vis, n, m);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 'O') grid[i][j] = 'X';
            }
        }
    }
};