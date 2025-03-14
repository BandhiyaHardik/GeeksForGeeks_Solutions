class Solution {
  public:
    int dp[1001][1001];
    int solve(vector<int>& coins, int sum,int i){
        if(sum<0) return 0;
        if(sum==0) return 1;
        if(i==coins.size()) return 0;
        
        if(dp[i][sum]!=-1) return dp[i][sum];
        int pick=solve(coins,sum-coins[i],i);
        int nopick=solve(coins,sum,i+1);
        return dp[i][sum]= pick+nopick;
    }
    int count(vector<int>& coins, int sum) {

        memset(dp,-1,sizeof(dp));
        return solve(coins,sum,0);
    }
};