class Solution {
  public:
    int maxRectSum(vector<vector<int>> &mat) {

        int n=mat.size(),m=mat[0].size(),finalmaxi=INT_MIN;
        for(int s=0;s<m;s++){
            vector<int>temp(n,0);
            for(int e=s;e<m;e++){
                for(int i=0;i<n;i++) temp[i]+=mat[i][e];
                
                int sum=0,maxi=INT_MIN;
                for(int i=0;i<n;i++){
                    sum+=temp[i];
                    maxi=max(maxi,sum);
                    if(sum<0) sum=0;
                }
                finalmaxi=max(finalmaxi,maxi);
            }
        }
        return finalmaxi;
    }
};