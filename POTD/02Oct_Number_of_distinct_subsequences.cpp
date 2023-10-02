class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	     unordered_map<char, int> map;
        int mod = 1000000007;
        int n = s.length();
        int dp[n + 1];
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            dp[i] = (2 * dp[i - 1]) % mod;

            char curr = s[i - 1];

            if (map.find(curr) != map.end())
                dp[i] = (dp[i] - dp[map[curr] - 1] + mod) % mod;

            map[curr] = i;
        }

        return dp[n];
	}
};