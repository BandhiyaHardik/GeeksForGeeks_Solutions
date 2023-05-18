int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

class Solution {
    public:
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        vector<vector<bool>> vis(N, vector<bool> (M, 0));
        
        auto valid = [&](int x, int y) -> bool {
            if(x < 1 or x >= N - 1 or y < 1 or y >= M - 1)
                return 0;
                
            if(vis[x][y] or !matrix[x][y])
                return 0;
                
            return 1;
        };
        
        auto closed = [&](int x, int y) -> bool {
            if(x == 0 or x == N - 1 or y == 0 or y == M - 1)
                if(matrix[x][y])
                    return 0;
                    
            return 1;
        };
        
        function<bool(int, int)> dfs = [&](int x, int y) -> bool {
            vis[x][y] = 1;
            
            bool ok = 1;
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(!closed(nx, ny)){
                    ok = 0;
                }
                
                if(valid(nx, ny)){
                    ok &= dfs(nx, ny);
                }
            }
            
            return ok;
        };
            
        int ans = 0;
        for(int i = 1; i < N - 1; i++){
            for(int j = 1; j < M - 1; j++){
                if(valid(i, j)){
                    ans += dfs(i, j);
                }
            }
        }
        
        return ans;
    }
};