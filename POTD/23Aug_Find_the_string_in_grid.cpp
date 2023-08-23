class Solution {
public:

	   vector<vector<int>> searchWord(vector<vector<char>>& grid, string word) {
        int n = grid.size();
        int m = grid[0].size();
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == word[0]) {
                    for (int k = 0; k < 8; k++) {
                        if (dfs(grid, n, m, word, 0, i, j, dx[k], dy[k])) {
                            vector<int> position = {i, j};
                            ans.push_back(position);
                            break;
                        }
                    }
                }
            }
        }

        return ans;
    }

    bool dfs(vector<vector<char>>& grid, int n, int m, string word, int idx, int x, int y, int nei_x, int nei_y) {
        if (idx == word.length()) {
            return true;
        }

        if (x >= 0 && x < n && y >= 0 && y < m && word[idx] == grid[x][y]) {
            return dfs(grid, n, m, word, idx + 1, x + nei_x, y + nei_y, nei_x, nei_y);
        }

        return false;
    }
};