class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {

        int n=mat.size(),maxsum=0,operations=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                sum+=mat[i][j];
            }
            maxsum=max(maxsum,sum);
        }
        for(int j=0;j<n;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=mat[i][j];
            }
            maxsum=max(maxsum,sum);
        }
        for(int i=0;i<n;i++){
            int rowsum=0;
            for(int j=0;j<n;j++){
                rowsum+=mat[i][j];
            }
            operations+=maxsum-rowsum;
        }
        return operations;
    }
};