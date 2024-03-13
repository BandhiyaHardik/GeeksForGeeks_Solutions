class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {

         vector<int>ans;
         int row=0, col=0;
         int n=mat.size();
         
        while(ans.size()<n*n){

            while(row>=0 && col<n){
                if(row>=0 && col>=0 && row<n && col<n){
                    ans.push_back(mat[row][col]);
                    mat[row][col]=1e9;
                }
                row--;
                col++;
            }
            if(ans.size()==n*n){
                break;
            }
            
            row=max(row, 0);
            col=min(col, n-1);
            
            while(mat[row][col]==1e9){
                row++;
            }
            
            while(col>=0 && row<n){
                if(row>=0 && col>=0 && row<n && col<n){
                    ans.push_back(mat[row][col]);
                    mat[row][col]=1e9;
                }
                row++;
                col--;
            }
            if(ans.size()==n*n){
                break;
            }
            
            row=min(row, n-1);
            col=max(col, 0);
            
            while(mat[row][col]==1e9){
                col++;
            }
            
            
        }
        return ans;
    }
};