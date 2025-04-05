class Solution {
  public:
    int n,m;
    vector<vector<int>> dir{{1,0},{-1,0},{0,-1},{0,1},{1,1},{-1,-1},{1,-1},{-1,1}};
    void solve(vector<vector<char>>& grid,int i,int j){

        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='W') return;
        grid[i][j]='W';
        for(auto &it:dir){
            int newi=i+it[0];
            int newj=j+it[1];
            solve(grid,newi,newj);
        }
        
    }
    int countIslands(vector<vector<char>>& grid) {

        n=grid.size();
        m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='L'){
                    solve(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};