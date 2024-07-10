class Solution {
public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        vector<int> componentSize;
        vector<vector<int>> componentId(n, vector<int>(n, -1));
        int compIdx = 0;

        vector<int> dir = {0, 1, 0, -1, 0};

        function<int(int, int)> dfs = [&](int x, int y) {
            visited[x][y] = 1;
            componentId[x][y] = compIdx;
            int size = 1;
            for (int d = 0; d < 4; ++d) {
                int nx = x + dir[d];
                int ny = y + dir[d + 1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 1 && !visited[nx][ny]) {
                    size += dfs(nx, ny);
                }
            }
            return size;
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int size = dfs(i, j);
                    componentSize.push_back(size);
                    compIdx++;
                }
            }
        }

        int maxConnected = componentSize.empty() ? 0 : *max_element(componentSize.begin(), componentSize.end());

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> connectedComponents;
                    int newSize = 1; 
                    for (int d = 0; d < 4; ++d) {
                        int nx = i + dir[d];
                        int ny = j + dir[d + 1];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                            int compId = componentId[nx][ny];
                            if (connectedComponents.find(compId) == connectedComponents.end()) {
                                newSize += componentSize[compId];
                                connectedComponents.insert(compId);
                            }
                        }
                    }
                    maxConnected = max(maxConnected, newSize);
                }
            }
        }

        return maxConnected;
    }
};
