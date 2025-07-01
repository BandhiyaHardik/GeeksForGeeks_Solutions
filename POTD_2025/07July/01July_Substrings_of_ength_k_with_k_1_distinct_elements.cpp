class Solution {
public:
    int substrCount(string& s, int k) {
        int n      = s.length();
        int result = 0;

        for (int i = 0; i <= n - k; i++) {
            vector<int> freq(26, 0);

            for (int j = i; j < i + k; j++) {
                freq[s[j] - 'a']++;
            }

            int count = 0;
            for (int l = 0; l < 26; l++) {
                if (freq[l] > 0) {
                    count++;
                }
            }

            if (count == k - 1) {
                result++;
            }
        }

        return result;
    }
};