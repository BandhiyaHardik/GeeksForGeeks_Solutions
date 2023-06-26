class Solution{
public:
    int nCr(int n, int r){
        
    int dp[r+1];
        for(int i=0;i<=r; i++)
        dp[i]=0;
        
        dp[0] = 1;
        
        if (r > n)
            return 0;
        if (r == 0 || r == n)
            return 1;
        
        if (r > n-r)
            r = n-r;
        int mod = 1000000007;
        
        for (int i = 0; i <= n; i++) {
            for (int j = min(i, r); j > 0; j--) {
                dp[j] = (dp[j]%mod + dp[j-1]%mod) % mod;
            }
        }
        
        return dp[r];
    }
};