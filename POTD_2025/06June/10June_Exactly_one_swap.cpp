class Solution {
public:
    int countStrings(string& s) {
        int n = s.length();

        vector<int> mp(26, 0);
        int         result = 0;

        for (int i = 0; i < n; i++) {
            result += (i - mp[s[i] - 'a']);
            mp[s[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (mp[i] > 1) {
                result++;
                break;
            }
        }

        return result;
    }
};