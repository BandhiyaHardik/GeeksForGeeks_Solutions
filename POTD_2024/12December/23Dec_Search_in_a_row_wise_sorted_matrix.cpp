class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {

        int n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++){
            if (x < mat[i][0] || x > mat[i][m - 1])continue;
            int low=0,high=m-1,mid=0;
            while(low<=high){
                mid=(low+high)/2;
                int temp = mat[i][mid];
                if(temp==x)return true;
                else if(temp<x)low=mid+1;
                else high=mid-1;
            }
        }
        return false;
    }
};