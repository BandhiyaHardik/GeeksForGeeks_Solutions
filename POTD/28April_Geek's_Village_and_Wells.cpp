int dx[] = { -1 , 1 ,  0  , 0 , -1  , -1  ,  1  , 1  };
int dy[] = { 0  , 0 , -1  , 1 , -1  ,  1  , -1  , 1  };
//         { U  , D ,  L  , R , UL  , UR  , DL  , DR }


class Solution{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        queue<pair<int,int>> q;
        vector<vector<int>> ans(n, vector<int>(m, 1e9));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(c[i][j] == 'W')
                    q.push({i, j}), ans[i][j] = 0;
            }
        }      
        
        auto valid = [&](int x, int y) -> bool {
            if(x < 0 or x >= n or y < 0 or y >= m)
                return 0;
                
            if(c[x][y] == 'N')
                return 0;
                
            return 1;
        };
        
        while(!q.empty()){
            int x, y;
            tie(x, y) = q.front();
            
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(valid(nx, ny)){
                    if(ans[nx][ny] > ans[x][y] + 2){
                        ans[nx][ny] = ans[x][y] + 2;
                        q.push({nx, ny});
                    }
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(c[i][j] == 'N' or c[i][j] == 'W' or c[i][j] == '.')
                    ans[i][j] = 0;
                    
                ans[i][j] = (ans[i][j] == 1e9) ? -1 : ans[i][j];
            }
        }
        
        return ans;
    }
};