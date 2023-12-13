class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    vector<vector<ll>> dp(n + 1, vector<ll> (2, 0));
	    const ll mod = 1e9 + 7;
	    dp[n][0] = dp[n][1] = 1;
	    
	    for(int i = n - 1; i > -1; i--){
	        dp[i][1] = dp[i + 1][0];
	        
	        dp[i][0] = (dp[i + 1][1] + dp[i + 1][0]) % mod;
	    }
	    
	    return dp[0][0];
	}
};
