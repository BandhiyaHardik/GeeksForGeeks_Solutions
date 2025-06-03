class Solution {
public:
    int countSubstr(string& s, int k) {
        int n      = s.length();
        int result = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            int         distinctCnt = 0;

            for (int j = i; j < n; j++) {
                if (freq[s[j] - 'a'] == 0) {
                    distinctCnt++;
                }
                freq[s[j] - 'a']++;

                if (distinctCnt == k) {
                    result++;
                } else if (distinctCnt > k) {
                    break;
                }
            }
        }
        return result;
    }
};