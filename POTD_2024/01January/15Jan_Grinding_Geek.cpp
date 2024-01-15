class Solution{
    public:
    int max_courses(int n, int total, vector<int> &cost)
    {
        vector<vector<int>> dp(n + 1, vector<int> (total + 1, 0));
        
        for(int i = n - 1; i > -1; i--){
            for(int j = 0; j < total + 1; j++){
                int take = 0, notake = 0;
                
                notake = dp[i + 1][j];
                
                if(cost[i] <= j){
                    int rem = j - cost[i] + (cost[i] * 9) / 10;
                    take = 1 + dp[i + 1][rem];
                }
                
                dp[i][j] = max(take, notake);
            }
        }
        
        return dp[0][total];
    }
};