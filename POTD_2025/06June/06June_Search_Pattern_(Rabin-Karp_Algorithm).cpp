class Solution {
public:
    bool isMatch(string& txt, string& pat, int idx) {
        for (int i = 0; i < pat.size(); i++) {
            if (txt[idx + i] != pat[i]) {
                return false;
            }
        }
        return true;
    }
    vector<int> search(string& pat, string& txt) {
        int m = pat.size();
        int n = txt.size();

        int base = 26;
        int mod  = 101;

        vector<int> result;
        int         patHash = 0;
        int         txtHash = 0;
        int         power   = 1;

        for (int i = m - 1; i >= 0; i--) {
            int patVal = pat[i] - 'a' + 1;
            int txtVal = txt[i] - 'a' + 1;

            patHash = (patHash + patVal * power) % mod;
            txtHash = (txtHash + txtVal * power) % mod;
            power   = (power * base) % mod;
        }

        if (txtHash == patHash && isMatch(txt, pat, 0)) {
            result.push_back(1);
        }

        int highestPower = 1;
        for (int i = 1; i < m; i++) {
            highestPower = (highestPower * base) % mod;
        }

        for (int i = 1; i <= n - m; i++) {
            int leftVal = txt[i - 1] - 'a' + 1;

            txtHash = (txtHash - (leftVal * highestPower) % mod + mod) % mod;
            txtHash = (txtHash * base) % mod;

            int newVal = txt[i + m - 1] - 'a' + 1;
            txtHash = (txtHash + newVal) % mod;

            if (txtHash == patHash && isMatch(txt, pat, i)) {
                result.push_back(i + 1);
            }
        }

        return result;
    }
};