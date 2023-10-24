class Solution{
    vector<int> dp;

public:
    int palindromicPartition(string str)
    {
         int n = str.length();
        dp.resize(n, -1);

        return helper(str, 0, n) - 1;
    }
    int helper(std::string str, int i, int n) {
        if (i == n) return 0;

        if (dp[i] != -1) return dp[i];
        int res = INT_MAX;
        for (int j = i; j < n; j++) {
            if (isPalin(str, i, j)) {
                int cost = 1 + helper(str, j + 1, n);
                res = std::min(res, cost);
            }
        }
        return dp[i] = res;
    }
     bool isPalin(std::string str, int i, int j) {
        while (i < j) {
            if (str[i] == str[j]) {
                i++;
                j--;
            } else {
                return false;
            }
        }
        return true;
    }
};