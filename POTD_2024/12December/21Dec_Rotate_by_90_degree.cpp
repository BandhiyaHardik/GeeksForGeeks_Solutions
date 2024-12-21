class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {

        int n=mat.size();
        for(int i=0;i<n;i++){
            reverse(mat[i].begin(), mat[i].end());
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
        return ;
    }
};