class Solution {
public:
    // Function to find the largest number after k swaps.
    void findMax(string s, int k, string &maxStr, int index) {
        if (k == 0)
            return;

        int n = s.length();
        char maxDigit = s[index];

        for (int i = index + 1; i < n; i++) {
            if (s[i] > maxDigit) {
                maxDigit = s[i];
            }
        }

        if (maxDigit != s[index])
            k--;

        for (int i = index; i < n; i++) {
            if (s[i] == maxDigit) {
                if (i != index) {
                    swap(s[i], s[index]);

                    if (s.compare(maxStr) > 0)
                        maxStr = s;

                    findMax(s, k, maxStr, index + 1);

                    swap(s[i], s[index]);
                } else {
                    findMax(s, k, maxStr, index + 1);
                }
            }
        }
    }

    string findMaximumNum(string &s, int k) {
        string maxStr = s;
        findMax(s, k, maxStr, 0);
        return maxStr;
    }
};