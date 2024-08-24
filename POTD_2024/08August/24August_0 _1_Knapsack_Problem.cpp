class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int help(int n,int w,vector<int> &wt,vector<int> &val,int index,vector<vector<int>> &dp){
        if(index==n)return 0;
        if(dp[index][w]!=-1)return dp[index][w];
        int nonPick = 0, pick = 0;
        nonPick = help(n,w,wt,val,index+1,dp);
        if(w>=wt[index]){
            pick = val[index]+help(n,w-wt[index],wt,val,index+1,dp);
        }
        return dp[index][w] = max(nonPick,pick);
    }
    int knapSack(int W, vector<int>& wt, vector<int>& val) {

        int n = wt.size();
        vector<vector<int>> dp(n,vector<int>(W+1,-1));
        return help(n,W,wt,val,0,dp);
    }
};