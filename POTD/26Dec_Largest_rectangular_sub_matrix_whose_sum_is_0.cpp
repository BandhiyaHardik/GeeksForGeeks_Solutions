class Solution{
  public:
  vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
        int n = a.size();
        int m = a[0].size();
        
        vector<vector<int>> rowPrefix(n + 1, vector<int> (m + 1, 0));
        
        for(int i = 1; i < n + 1; i++){
          for(int j = 1; j < m + 1; j++)
            rowPrefix[i][j] += rowPrefix[i][j - 1] + a[i - 1][j - 1];
        }
        
        int best = 0;
        int sx, sy, ex, ey;
        
        for(int i = 1; i < m + 1; i++){
            
          for(int j = i; j < m + 1; j++){
              map<int,int> pre;
              pre[0] = 0;
              
              int csum = 0;
              
              for(int k = 1; k < n + 1; k++){
                  csum += rowPrefix[k][j] - rowPrefix[k][i - 1];
                  
                  if(pre.count(csum)){
                      int area = (j - i + 1) * (k - pre[csum]);
                      
                      if(area > best){
                          best = area;
                          
                          sx = pre[csum] + 1;
                          sy = i;
                          
                          ex = k;
                          ey = j;
                      }
                  }
                  else{
                      pre[csum] = k;
                  }
              }
          }
        }
      
        vector<vector<int>> ans;
      
        if(best == 0)
            return ans;
        
        for(int i = sx; i < ex + 1; i++){
            vector<int> curRow;
            
            for(int j = sy; j < ey + 1; j++)
                curRow.push_back(a[i - 1][j - 1]);
            
            ans.emplace_back(curRow);
        }
        
        return ans;
  }
};
