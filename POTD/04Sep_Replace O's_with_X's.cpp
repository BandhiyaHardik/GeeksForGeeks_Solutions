class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> a)
    {
        for (int i = 0; i < n; i++) {
            if (a[i][0] == 'O') 
                dfs(a, i, 0, 'O', '-', n, m);

            if (a[i][m - 1] == 'O') 
                dfs(a, i, m - 1, 'O', '-', n, m);
        }

        for (int i = 0; i < m; i++) {
            if (a[0][i] == 'O') 
                dfs(a, 0, i, 'O', '-', n, m);
            if (a[n - 1][i] == 'O') 
                dfs(a, n - 1, i, 'O', '-', n, m);
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (a[i][j] == 'O')
                    a[i][j] = 'X';
                    
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (a[i][j] == '-')
                    a[i][j] = 'O';

        return a;
    }
      void dfs(std::vector<std::vector<char>>& a, int x, int y,
                    char prevC, char newC, int N, int M) {
        if (x < 0 || x >= N || y < 0 || y >= M)
            return;
        if (a[x][y] != prevC)
            return;

        a[x][y] = newC;
        dfs(a, x + 1, y, prevC, newC, N, M);
        dfs(a, x - 1, y, prevC, newC, N, M);
        dfs(a, x, y + 1, prevC, newC, N, M);
        dfs(a, x, y - 1, prevC, newC, N, M);
    }
};